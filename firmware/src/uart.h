#ifndef UART_H
#define UART_H
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_usart.h>

void usart_send_byte(uint8_t byte);
void usart_send_str(const char* str);
void usart_init();

#endif