/**
 * @file enginectl.c
 * @author Denis Vashchuk
 * @brief Implementation of PWM engines control
 * @copyright BSUIR 2013
 *
 * <h2>Engines placement on a board.</h2>
 * @image html ../../images/neuraxis_pwm.png
 */

 /*
 * Channel (Forward)	|		Channel (Back)	|	Engine #	|	Description
 * _________________|_______________________|_______________|______________
 * TIM4_CH1 (PB6)	|	 	TIM4_CH2 (PB7)	|	 	ENG1	|	Front left
 * TIM4_CH3 (PB8)	|		TIM4_CH4 (PB9)	|		ENG2	|	Front right
 * TIM3_CH1 (PA6)	|		TIM3_CH2 (PA7)	|		ENG3	|	Back right
 * TIM3_CH3 (PB0)	|		TIM3_CH4 (PB1)	|		ENG4	|	Back left
 *
 */


#include "enginectl.h"
#include "led.h"
#include <stm32f10x_tim.h>

#define PWM_PERIOD 100
#define ENGINE_SPEED(x) (x-1)
#define ENGINE_STOP	0



extern void delay(uint32_t ms);

/**
 * @brief Init GPIO, PWM for engines control
 */
void engine_init()
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	/* Enable gpio pins for engine */
	GPIO_InitTypeDef gpio_a;
	gpio_a.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_a.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	gpio_a.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &gpio_a);

	GPIO_InitTypeDef gpio_b;
	gpio_b.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_b.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	gpio_b.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio_b);

	/* timers */
	TIM_TimeBaseInitTypeDef timer_config;
	timer_config.TIM_CounterMode=TIM_CounterMode_Up;
	timer_config.TIM_ClockDivision=0;
	timer_config.TIM_Prescaler = 0;
	timer_config.TIM_Period = PWM_PERIOD-1;

	TIM_TimeBaseInit(TIM3, &timer_config);
	TIM_TimeBaseInit(TIM4, &timer_config);

	TIM_OCInitTypeDef timer_oconfig;
	timer_oconfig.TIM_OCMode = TIM_OCMode_PWM1;
	timer_oconfig.TIM_OutputState = TIM_OutputState_Enable;
	timer_oconfig.TIM_Pulse = ENGINE_STOP;
	timer_oconfig.TIM_OCPolarity = TIM_OCPolarity_High;

	//Timer 3
	TIM_OC1Init(TIM3, &timer_oconfig);
	TIM_OC2Init(TIM3, &timer_oconfig);
	TIM_OC3Init(TIM3, &timer_oconfig);
	TIM_OC4Init(TIM3, &timer_oconfig);
	//Timer 4
	TIM_OC1Init(TIM4, &timer_oconfig);
	TIM_OC2Init(TIM4, &timer_oconfig);
	TIM_OC3Init(TIM4, &timer_oconfig);
	TIM_OC4Init(TIM4, &timer_oconfig);

	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM3, ENABLE);
	TIM_ARRPreloadConfig(TIM4, ENABLE);

	TIM_Cmd(TIM3, ENABLE);
	TIM_Cmd(TIM4, ENABLE);
}

/**
 * All function engine_go_* and engine_turn_* are blocking
 */

/**
 * @brief Power on engine to drive forward
 * @param time time in ms
 * @param speed_value max value PWM_PERIOD
 */
void engine_go_forward(int time_ms, int speed_value)
{
	TIM3->CCR1 = ENGINE_SPEED(speed_value);
	TIM3->CCR3 = ENGINE_SPEED(speed_value);
	TIM4->CCR1 = ENGINE_SPEED(speed_value);
	TIM4->CCR3 = ENGINE_SPEED(speed_value);

	led_delay(time_ms);

	engine_stop();
}


/**
 * @brief Power on engine to drive backward
 * @param time time in ms
 * @param speed_value max value PWM_PERIOD
 */
void engine_go_backward(int time_ms, int speed_value)
{
	TIM3->CCR2 = ENGINE_SPEED(speed_value);
	TIM3->CCR4 = ENGINE_SPEED(speed_value);
	TIM4->CCR2 = ENGINE_SPEED(speed_value);
	TIM4->CCR4 = ENGINE_SPEED(speed_value);
	led_delay(time_ms);

	engine_stop();
}


/**
 * @brief Power on engine to drive forward while command engine_stop not be executed
 * @param speed_value max value PWM_PERIOD
 */
void engine_go_forward_continuously(int speed_value)
{
	TIM3->CCR1 = ENGINE_SPEED(speed_value);
	TIM3->CCR3 = ENGINE_SPEED(speed_value);
	TIM4->CCR1 = ENGINE_SPEED(speed_value);
	TIM4->CCR3 = ENGINE_SPEED(speed_value);
}

/**
 * @brief Stop all engines
 */
void engine_stop()
{
	TIM3->CCR1 = ENGINE_STOP;
	TIM3->CCR2 = ENGINE_STOP;
	TIM3->CCR3 = ENGINE_STOP;
	TIM3->CCR4 = ENGINE_STOP;

	TIM4->CCR1 = ENGINE_STOP;
	TIM4->CCR2 = ENGINE_STOP;
	TIM4->CCR3 = ENGINE_STOP;
	TIM4->CCR4 = ENGINE_STOP;
}

/**
 * @brief Turn right (direction: forward)
 */
void engine_turn_right_forward(int angle)
{
	TIM3->CCR2 = ENGINE_SPEED(100);
	TIM4->CCR4 = ENGINE_SPEED(100);

	TIM3->CCR3 = ENGINE_SPEED(100);
	TIM4->CCR1 = ENGINE_SPEED(100);
	led_delay(angle);
	engine_stop();
}

/**
 * @brief Turn left (direction: forward)
 */
void engine_turn_left_forward(int angle)
{
	TIM3->CCR4 = ENGINE_SPEED(100);
	TIM4->CCR2 = ENGINE_SPEED(100);

	TIM3->CCR1 = ENGINE_SPEED(100);
	TIM4->CCR3 = ENGINE_SPEED(100);
	led_delay(angle);
	engine_stop();
}


/**
 * @brief Turn right (direction: backward)
 */
void engine_turn_right_backward(int angle)
{
	TIM3->CCR4 = ENGINE_SPEED(100);
	TIM4->CCR2 = ENGINE_SPEED(100);

	TIM3->CCR1 = ENGINE_SPEED(100);
	TIM4->CCR3 = ENGINE_SPEED(100);
	led_delay(angle);
	engine_stop();
}

/**
 * @brief Turn left (direction: backward)
 */
void engine_turn_left_backward(int angle)
{
	TIM3->CCR2 = ENGINE_SPEED(100);
	TIM4->CCR4 = ENGINE_SPEED(100);

	TIM3->CCR3 = ENGINE_SPEED(100);
	TIM4->CCR1 = ENGINE_SPEED(100);
	led_delay(angle);
	engine_stop();
}
