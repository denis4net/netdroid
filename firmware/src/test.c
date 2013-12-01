#include "test.h"
#include <stm32f10x_gpio.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_rcc.h>

extern void delay(uint32_t ms);


/* testing TIM2 PWM on channel 2, CONN2 (ADC2) connector */

void test_init() {
	/* Enable gpio pins for engine */
	GPIO_InitTypeDef gpio_a;
	gpio_a.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_a.GPIO_Pin = GPIO_Pin_1;
	gpio_a.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &gpio_a);


	TIM_TimeBaseInitTypeDef timer_config;
	timer_config.TIM_CounterMode=TIM_CounterMode_Up;
	timer_config.TIM_ClockDivision=0;
	timer_config.TIM_Prescaler = 0;
	timer_config.TIM_Period = 100;

	TIM_TimeBaseInit(TIM2, &timer_config);

	TIM_OCInitTypeDef timer_oconfig;
	timer_oconfig.TIM_OCMode = TIM_OCMode_PWM1;
	timer_oconfig.TIM_OutputState = TIM_OutputState_Enable;
	timer_oconfig.TIM_Pulse = 0;
	timer_oconfig.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC2Init(TIM2, &timer_oconfig);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM2, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
}

int test(int value)
{
	TIM2->CCR2=value;
	return 0;

}
