
/**
 * @author Denis Vashchuk
 * @brief BSUIR web droid neuraxis
 * @copyright BSUIR 2013
 */

#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>


void delay(uint32_t ms)
{
    volatile uint32_t nCount;
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq (&RCC_Clocks);

    nCount=(RCC_Clocks.HCLK_Frequency/10000)*ms;
    for (; nCount!=0; nCount--)
        __NOP;
}


int main()
{
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_1;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &gpio);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	while(1) {
		delay(500);
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
		delay(500);
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}

}
