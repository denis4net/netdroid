#include <stm32f10x.h>
#include "uart.h"
#include "gpio.h"

void delay()
{
  volatile int i, j;
    for(j=0; j<1600000; j++)
      __NOP();
}

int main()
{ 
  gpio_init();
  usart_init();
  
  while (1) 
  {
    GPIO_SetBits(GPIOB, GPIO_Pin_0);
    delay();
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);
    delay();
  }
}