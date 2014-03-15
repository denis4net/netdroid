/**
 * @author Denis Vashchuk
 * @brief Implementation of uart functions for shell
 * @copyright BSUIR 2013
 */


#include <stm32f10x.h>
#include "uart.h"
#include <stm32f10x_usart.h>
#include <misc.h>

/**
 * Send byte via USART2.
 * @param byte byte for send
 */
void usart_send_byte(uint8_t byte)
{
    while( ! ( USART2->SR & USART_SR_TC ));
    USART2->DR=byte;
}

/**
 * Send string via USAERT2
 * @param str null terminated string for send
 */
void usart_send_str(const char* str)
{
    for(int i=0; str[i]; i++) {
        usart_send_byte(str[i]);
    }
}

/**
 * Init USART2 periphery
 */
void usart_init_2()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    /* using USART2 (PA2, PA3)  for communicating with Control device */
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);
    /* TX: выход push-pull */
    gpio.GPIO_Speed = GPIO_Speed_10MHz;
    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIOA, &gpio);

    /* RX: высокоимпендансный вход */
    gpio.GPIO_Speed = GPIO_Speed_10MHz;
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOA, &gpio);

    USART_Cmd(USART2, ENABLE);

    /* USART*/
    USART_InitTypeDef usart;
    USART_StructInit(&usart);
    usart.USART_BaudRate=115200;
    USART_Init(USART2, &usart);
    //enable interrupt on data receive
    USART_ITConfig(USART2,  USART_IT_RXNE, ENABLE);
    //disable interrupt on transmission register empty
    USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
    USART_ITConfig(USART2, USART_IT_TC, DISABLE);
    USART_ITConfig(USART2, USART_IT_IDLE, DISABLE);
    USART_ITConfig(USART2, USART_IT_CTS, DISABLE);

    /* NVIC */
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_EnableIRQ(USART2_IRQn);
}

/**
 * Init USART periphery.
 * Needed for case, if we need init more than one USART for communication.
 */
void usart_init()
{
    usart_init_2();
}
