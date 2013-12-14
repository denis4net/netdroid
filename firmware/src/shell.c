/**
 * @author Denis Vashchuk
 * @brief Implementation of shell function, uart2 initialization, command handeling
 * @copyright BSUIR 2013
 */
#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_usart.h>
#include "shell.h"
#include "uart.h"
#include "queue.h"
#include "cmd.h"

static queue_t command_queue;

int shell_init()
{
	usart_init();
}

void  USART2_IRQHandler()
{
	static uint8_t buffer[CMD_SIZE];
	static uint8_t last_command[CMD_SIZE];
	static int have_last_command;

	static uint16_t char_number;
	static uint8_t received_byte;

	if(  USART2->SR & USART_IT_RXNE  ) { //check irq source, data received
		received_byte = USART2->DR;
		usart_send_byte(received_byte);

		//TODO: last command in shell support
		if(  ( char_number+1 )> ( CMD_SIZE-2 ) ) {
			char_number=0;
			usart_send_str("Exceed command line limit (63 chars)\r\n>");
		} else {
			buffer[char_number] = received_byte;
			if( (char)received_byte == '\b') {
				if(char_number-1>-1)
					char_number--;
				else
					usart_send_str('>');

			} else if( (char) received_byte == '\r' ) {
				buffer[char_number]='\0'; //set end of null terminated string
				if( !cmd_check(buffer))
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

	else if( USART1->SR & USART_SR_TXE ) {
		USART_ClearITPendingBit(USART2, USART_IT_TXE);
	}

	else if( USART1->SR & USART_SR_TC ) {
		USART_ClearITPendingBit(USART2, USART_IT_TC);
	}

}

void shell_run()
{
	char local_command[CMD_SIZE];
	int pwm_value=0;

	queue_init(&command_queue);
	shell_init();
	usart_send_str(">");


	while(1) {

		if( !queue_is_empty(&command_queue) ) {
			strcpy(local_command, queue_dequeue(&command_queue));
			cmd_status_t status = cmd_run(local_command);
			if(status == CMD_SUCCESSFUL ) {
				usart_send_str("Command '");
				usart_send_str(local_command);
				usart_send_str("' successfully executed\n\r");
			}
		}
		else {
			test(pwm_value++);
			if(pwm_value==100) {
				pwm_value=0;
				//usart_send_str("Sheel poll loop\r\n");
			}
			delay(10);
		}
	}
}

