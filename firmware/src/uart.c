/**
 * @author Denis Vashchuk
 * @brief Implementation of uart functions for shell
 * @copyright BSUIR 2013
 */


#include "uart.h"

void usart_send_byte(uint8_t byte)
{
  while( !( USART1->SR & USART_SR_TC ) );
  USART1->DR = byte;
}

void usart_send_str(const char* str)
{
  for(int i=0; str[i]; i++)
  {
     usart_send_byte(str[i]);
  }
}

void usart_init()
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitTypeDef gpio;
  GPIO_StructInit(&gpio);

  /* TX: выход push-pull */
  gpio.GPIO_Mode = GPIO_Mode_AF_PP;
  gpio.GPIO_Pin = GPIO_Pin_9;
  GPIO_Init(GPIOA, &gpio);

  /* RX: высокоимпендансный вход */
  gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  gpio.GPIO_Pin = GPIO_Pin_10;
  GPIO_Init(GPIOA, &gpio);

  RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
  USART_InitTypeDef usart;
  /* Параметры по умолчанию: 9600 бод, 8 бит данных, 1 стоп-бит */
  USART_StructInit(&usart);
  /* Установим скорост 115200 */
  usart.USART_BaudRate=115200;
  
  USART_Init(USART2, &usart);
  USART_Cmd(USART2, ENABLE);
}
