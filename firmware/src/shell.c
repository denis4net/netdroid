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

extern int sscanf(const char *str, const char *fmt, ...);
extern int sprintf(char **out, const char *format, ...);

static int (*cmd_handler)(const char* cmd);
static queue_t command_queue;

int shell_init()
{
    usart_init();
}

void  USART2_IRQHandler()
{
    static uint8_t buffer[CMD_SIZE];
    static uint16_t char_number;
    static uint8_t received_byte;

    if(  USART2->SR & USART_IT_RXNE  ) { //check irq source, data received
        GPIO_SetBits(GPIOB, GPIO_Pin_0);
        received_byte = USART2->DR;
        usart_send_byte(received_byte);
        buffer[char_number] = received_byte;

        if(  ( char_number+1 )> ( CMD_SIZE-2 ) ) {
            char_number=0;
            usart_send_str("Exceed command line limit (63 chars)\r\n>");
        } else {

            if( (char)received_byte == '\b') {
                char_number--;
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
        GPIO_ResetBits(GPIOB, GPIO_Pin_0);
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
	queue_init(&command_queue);
	shell_init();
	usart_send_str(">");

	while(1) {
		if( !queue_is_empty(&command_queue) ) {
			strcpy(local_command, queue_dequeue(&command_queue));
			cmd_run(local_command);
		}
		else
			__NOP();
	}
}

