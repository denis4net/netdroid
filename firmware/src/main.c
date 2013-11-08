
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
#include "cmd_runner.h"

void delay(uint32_t ms)
{
    volatile uint32_t nCount;
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq (&RCC_Clocks);

    nCount=(RCC_Clocks.HCLK_Frequency/10000)*ms;
    for (; nCount!=0; nCount--)
        __NOP;
}

void led_init()
{
    GPIO_InitTypeDef gpio_b;
    gpio_b.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_b.GPIO_Pin = GPIO_Pin_0;
    gpio_b.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOB, &gpio_b);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
}

int main()
{
    /* init engines */
    engine_init();
    /* init servo drives */
    servo_init();
    /* init led */
    led_init();
    /* run shell loop */
    shell_run();
}
