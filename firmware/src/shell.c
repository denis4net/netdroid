/**
 * @author Denis Vashchuk
 * @brief Implementation of shell function, uart2 initialization, command handeling
 * @copyright BSUIR 2013
 */


#include <string.h>
#include "shell.h"
#include "uart.h"

static int (*cmd_handler)(const char* cmd);

int shell_init(int  (*handler)(const char*))
{
  cmd_handler = handler; //set local cmd handler
  
  usart_init();
    
  NVIC_EnableIRQ(USART2_IRQn);
  NVIC_SetPriority(USART2_IRQn, 0);
  USART2->CR1 |= USART_CR1_RXNEIE;
}

void usart_irq_handler()
{
  static uint8_t buffer[CMD_SIZE];
  static uint16_t char_number;
  uint8_t received_byte;
  
  if( USART2->SR | USART_SR_RXNE ) //check irq source, data received
  {
    received_byte = USART2->DR;
    USART2->DR=USART2->DR; 		// echo to console
    
    buffer[received_byte] = received_byte;
       
    if( (char)received_byte == '\b')
    {
      char_number--;
    }
    else if( (char) received_byte == '\r' )
    {
      usart_send_byte('\n');
      buffer[char_number]='\0'; //set end of null terminated string
      cmd_handler(buffer);
      received_byte=0;
    }
    else
    {
      char_number++;
    }
  }
}

