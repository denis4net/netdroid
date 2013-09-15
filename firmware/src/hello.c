#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_usart.h>


/************************************************************************/
void delay()
{
  volatile int i, j;
    for(j=0; j<1600000; j++)
      __NOP();
}

void led_init()
{
    /* Включаем тактирование порта C */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

  GPIO_InitTypeDef gpio;
  gpio.GPIO_Mode = GPIO_Mode_Out_PP;
  gpio.GPIO_Pin = GPIO_Pin_0;
  gpio.GPIO_Speed = GPIO_Speed_2MHz;
  
  /* Инициализируем GPIO на порту C */
  GPIO_Init(GPIOB, &gpio);
}

void usart_send_byte(uint8_t byte)
{
  while( !( USART1->SR & USART_SR_TC ) );
  USART1->DR = byte;
}

void usart_send_str(const char* str)
{
  for(int i=0; str[i]; i++)
  {
     usart_send_byte(str[i]);
  }
}

void usart_init()
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitTypeDef gpio;
  GPIO_StructInit(&gpio);

  /* TX: выход push-pull */
  gpio.GPIO_Mode = GPIO_Mode_AF_PP;
  gpio.GPIO_Pin = GPIO_Pin_9;
  GPIO_Init(GPIOA, &gpio);

  /* RX: высокоимпендансный вход */
  gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  gpio.GPIO_Pin = GPIO_Pin_10;
  GPIO_Init(GPIOA, &gpio);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  USART_InitTypeDef usart;
  /* Параметры по умолчанию: 9600 бод, 8 бит данных, 1 стоп-бит */
  USART_StructInit(&usart);
  USART_Init(USART1, &usart);
  USART_Cmd(USART1, ENABLE);
}

/*************************************************************************/

int compute_c(int a, int b, int c)
{
  // 4 - 1 / 1 + 1 
  return  ( a + b - ( a * c ) ) / ( a +  ( c*c ) );
}

int compute(int a, int b, int c)
{
    int volatile out, out2;
    asm volatile(
        "mov r0, %[a]" "\n\t"
        "mov r1, %[b]" "\n\t"
        "mov r2, %[c]" "\n\t"
        "mul r3, r0, r2" "\n\t"
        "add r4, r0, r1" "\n\t"
        "sub r5, r4, r3" "\n\t"
	"mov %[out], r5" "\n\t"
        "mov r4, r2" "\n\t"
        "mul r3, r2, r4" "\n\t"
        "add r4, r3, r0" "\n\t"
//      "sdiv r1, r5, r4" "\n\t"
	"mov %[out2], r4"
        :[out]"+r"(out), [out2]"+r"(out2)
        :[a]"r"(a), [b]"r"(b), [c]"r"(c)
	:"r0", "r1", "r2", "r3", "r4", "r5", "r6"
        );
      
    usart_send_byte(out);
    usart_send_byte(out2);
    usart_send_byte(out/out2);
    return 0;
}

void print_result(int result)
{
  usart_send_byte(result);  
}

int main()
{ 
  led_init();
  usart_init();
  
  while (1) 
  {
    GPIO_SetBits(GPIOB, GPIO_Pin_0);
    delay();
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);
    delay();
    compute(2, 4, 1);
  }
}