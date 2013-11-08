/**
 * @author Denis Vashchuk
 * @brief Implementation of PWM engines control
 * @copyright BSUIR 2013
 * 
 * Due to schematic: 
 * 	PB8 PB9 - left front engine ctl
 * 	PB0, PB1 - right front engine ctl
 * 	PB6, PB7 -  left back engine ctl
 * 	PA6, PA7 - right back engine ctl
 */


#include "enginectl.h"

/**
 * Init engine control GPIOs
 */
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
    gpio_b.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1  | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
    gpio_b.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOB, &gpio_b);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
}

/**
 * All function engine_go_* and engine_turn_* are blocking 
 */

void engine_go_forward(int time)
{
}

void engine_go_back(int time)
{
}

void engine_turn_right_forward(int angle)
{
}

void engine_turn_left_forward(int angle)
{
}

void engine_turn_right_back(int angle)
{
}

void engine_turn_left_back(int angle)
{
}