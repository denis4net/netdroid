/**
 * @author Denis Vashchuk
 * @brief Implementation of shell function, uart2 initialization, command handeling
 * @copyright BSUIR 2013
 */
#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_usart.h>
#include <string.h>
#include "shell.h"
#include "uart.h"

static int (*cmd_handler)(const char* cmd);

int shell_init(int  (*handler)(const char*))
{
    cmd_handler = handler; //set local cmd handler
    usart_init();
}

void  USART2_IRQHandler()
{
    static uint8_t buffer[CMD_SIZE];
    static uint16_t char_number;
    static uint8_t received_byte;


    if(  USART2->SR & USART_IT_RXNE  ) { //check irq source, data received
        received_byte = USART2->DR;
        usart_send_byte(received_byte);
        buffer[char_number] = received_byte;

        if( (char)received_byte == '\b') {
            char_number--;
        } else if( (char) received_byte == '\r' ) {
            usart_send_str("\n\r>");
            buffer[char_number]='\0'; //set end of null terminated string
            cmd_handler(buffer);
            char_number=0;
        } else {
            char_number++;
        }

        USART_ClearITPendingBit(USART2, USART_IT_RXNE);
        GPIO_ResetBits(GPIOB, GPIO_Pin_0);
    }

    if( USART1->SR & USART_SR_TXE ) {
            USART_ClearITPendingBit(USART2, USART_IT_TXE);
    }
    
    if( USART1->SR & USART_SR_TC ) {
        USART_ClearITPendingBit(USART2, USART_IT_TC);
    }

}

