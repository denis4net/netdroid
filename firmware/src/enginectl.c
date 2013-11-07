/**
 * @author Denis Vashchuk
 * @brief Implementation of engines control
 * @copyright BSUIR 2013
 */


#include "enginectl.h"


void engine_init()
{
  /* Enable gpio pins for engine */
   GPIO_InitTypeDef gpio_a;
  gpio_a.GPIO_Mode = GPIO_Mode_Out_PP;
  gpio_a.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  gpio_a.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &gpio_a);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 
  GPIO_InitTypeDef gpio_b;
  gpio_b.GPIO_Mode = GPIO_Mode_Out_PP;
  gpio_b.GPIO_Pin = GPIO_Pin_6 |GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
  gpio_b.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOB, &gpio_b);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
}