/**
 * Led driver implementation
 * @author Denis Vashchuk
 */

#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>


extern void delay(int);

/**
 * Init GPIOA on GPIO_Pin_15
 */
void led_init() {
#if 1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	//enable GPIO_Pin_15 on GPIOA
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);

	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_15;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOA, &gpio);
#endif
}

/**
 * Led blink
 * @param count led blink count
 * @param delay_ms delay between blinks
 */
int led_blink(const int count, const int delay_ms) {

	for(int i=0; i<count; i++) {
		delay(delay_ms);
		GPIO_SetBits(GPIOA, GPIO_Pin_15);
		delay(delay_ms);
		GPIO_ResetBits(GPIOA, GPIO_Pin_15);
	}

	return 0;
}

/**
 * Similar to led_blink, but count parameter computing automatically
 */
int led_delay(const unsigned int delay_ms) {

	if( delay_ms < 100)
		delay(delay_ms);

	for(unsigned int i=0; i<delay_ms; i+=100) {
		delay(50);
		GPIO_SetBits(GPIOA, GPIO_Pin_15);
		delay(50);
		GPIO_ResetBits(GPIOA, GPIO_Pin_15);
	}
	return 0;
}


