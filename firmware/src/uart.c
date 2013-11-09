/**
 * @author Denis Vashchuk
 * @brief Implementation of uart functions for shell
 * @copyright BSUIR 2013
 */


#include <stm32f10x.h>
#include "uart.h"
#include <stm32f10x_usart.h>
#include <misc.h>

void usart_send_byte(uint8_t byte)
{
    while( ! ( USART2->SR & USART_SR_TC ));
    USART2->DR=byte;
}

void usart_send_str(const char* str)
{
    for(int i=0; str[i]; i++) {
        usart_send_byte(str[i]);
    }
}


void usart_init_2()
{
    /* using USART2 (PA2, PA3)  for communicating with Control device */
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);
    /* TX: выход push-pull */
    gpio.GPIO_Speed = GPIO_Speed_2MHz;
    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIOA, &gpio);

    /* RX: высокоимпендансный вход */
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOA, &gpio);

    /* USART*/
    USART_InitTypeDef usart;
    USART_StructInit(&usart);
    usart.USART_BaudRate=115200;
    USART_Init(USART2, &usart);
    USART_ITConfig(USART2,  USART_IT_RXNE, ENABLE);
    USART_ITConfig(USART2, USART_IT_TC, DISABLE);
    USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
    USART_Cmd(USART2, ENABLE);

    /* NVIC */
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    NVIC_EnableIRQ(USART2_IRQn);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
}

void usart_init()
{
    usart_init_2();
}
