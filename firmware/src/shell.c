/**
 * @author Denis Vashchuk
 * @brief Implementation of shell function, uart2 initialization, command handling
 * @copyright BSUIR 2013
 */

#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_usart.h>
#include <string.h>
#include "shell.h"
#include "uart.h"
#include "queue.h"
#include "cmd.h"
#include "led.h"

extern void delay(const int);
static queue_t command_queue;

/**
 * Shell init function.
 * Init uart: init gpio, uart periphery, enable RX interrupt.
 */
int shell_init()
{
	usart_init();
	return 0;
}

/**
 * UART2 Receive hander.
 * Shell implementation. This function (handler) fill command queue by new valid command received
 * from UART2.
 */
void  USART2_IRQHandler()
{
	static char buffer[CMD_SIZE];
	static uint16_t char_number;
	static uint8_t received_byte;

	received_byte = USART2->DR;
	USART2->DR = USART2->DR;

	if(  ( char_number+1 )> ( CMD_SIZE-2 ) ) {
		char_number=0;
		usart_send_str("Exceed command line limit (63 chars)\r\n>");
		usart_send_str("\n\r>");
	} else {
		buffer[char_number] = received_byte;
		if( (char)received_byte == '\b') {
			if(char_number-1>-1)
				char_number--;
			else
				usart_send_byte((uint8_t)'>');

		} else if( (char) received_byte == '\n' ) {
			buffer[char_number]='\0'; //set end of null terminated string

			if (!cmd_check(buffer))
				usart_send_str("\n\rUndefined command\n\r");
			else {
				usart_send_str("\n\rCommand enqueued\n\r");
				queue_enqueue(&command_queue, buffer);
			}

			usart_send_str("\n\r>");
			char_number=0;
		} else {
			char_number++;
		}
	}
	USART_ClearITPendingBit(USART2, USART_IT_RXNE);
}

/**
 * @brief Shell loop.
 * Wait for commands in command_queue, run it, report command run status via usart tty.
 */
void shell_run()
{
	char local_command[CMD_SIZE];
	queue_init(&command_queue);

	usart_send_str("************************************\r\n");
	usart_send_str("Welcome to Neuraxis shell\r\n");
	usart_send_str("************************************\r\n>");

	while(1) {
		if( !queue_is_empty(&command_queue) ) {
			strcpy(local_command, queue_dequeue(&command_queue));
			cmd_status_t status = cmd_run(local_command);
			if(status == CMD_SUCCESSFUL ) {
				usart_send_str("Command '");
				usart_send_str(local_command);
				usart_send_str("' successfully executed\r\n");
			}
			else
			{
				usart_send_str("Command '");
				usart_send_str(local_command);
				usart_send_str("' can't be executed\r\n");
			}

			usart_send_byte((uint8_t) '>');
		}
		else {
			__WFI();
		}
	}

}

