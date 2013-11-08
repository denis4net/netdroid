#include "uart.h"

void  WWDG_IRQHandler()
{
	usart_send_str("WWDG\n\r");
	return;
}

void UsageFault_Handler()
{
	usart_send_str("UsageFault\n\r");
	return;
}

void MemManage_Handler()
{
	usart_send_str("MemManage fault\n\r");
}