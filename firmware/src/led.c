#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

uint32_t i; 


int main()
 {
  //Конфигурация порта В
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; //Тактирование порта В
  GPIOB->CRL |= GPIO_CRL_MODE0_0; //Вывод PB0 порта В настроен как выход
  GPIOB->CRL &= ~GPIO_CRL_CNF0; //Режим Push-Pull для вывода PB0 порта В
  
  while(1)
  {
   GPIOB->BSRR |= GPIO_BSRR_BS0; //Устанавливаем в "1" PB0, зажгли светодиод
   for(i=0; i<0x0003FFFF; i++); //Задержка
   GPIOB->BSRR |= GPIO_BSRR_BR0; //Сбрасываем в "0" PB0, светодиод погасили
   for(i=0; i<0x0003FFFF; i++); //Задержка
  }
 }