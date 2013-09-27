/**
 * @author Denis Vashchuk
 * @brief Implementation of engines control
 * @copyright BSUIR 2013
 */


#include "enginectl.h"


void engine_init()
{
    /* Включаем тактирование порта B */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  
  GPIO_InitTypeDef gpio;
  gpio.GPIO_Mode = GPIO_Mode_Out_PP;
  gpio.GPIO_Pin = GPIO_Pin_0;
  gpio.GPIO_Speed = GPIO_Speed_2MHz;
  
  /* Инициализируем GPIO на порту C */
  GPIO_Init(GPIOB, &gpio);
}