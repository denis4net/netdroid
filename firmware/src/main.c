
/**
 * @author Denis Vashchuk
 * @brief BSUIR web droid neuraxis
 * @copyright BSUIR 2013
 */

#include <stm32f10x.h>
#include <stdint.h>
#include "shell.h"
#include "enginectl.h"
#include "servoctl.h"
#include "test.h"


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
    /* init engines */
    engine_init();
    /* init servo drives */
    servo_init();
    /* test init */
    test_init();
    /* run shell loop */
    shell_run();
}
