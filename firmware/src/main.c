/**
 * @author Denis Vashchuk
 * @brief BSUIR web droid neuraxis
 * @copyright BSUIR 2013
 */

#include <stm32f10x.h>
#include "shell.h"
#include "uart.h"
#include "enginectl.h"
#include "servoctl.h"

void delay()
{
  volatile int j;
    for(j=0; j<1600000; j++)
      __NOP();
}

int command_handler(const char* cmd)
{
  #ifdef DEBUG
    usart_send_str(cmd);
  #endif
  return 0;
}

int main()
{ 
  /* init and run shell in background, run on iterrupts */
  shell_init(command_handler);
  /* init engines */
  engine_init();
  /* init servo drives */
  servo_init();
  //TODO: led blinking
  
  while (1) 
  {
    GPIO_SetBits(GPIOB, GPIO_Pin_0);
    delay();
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);
    delay();
  }
}
