
/**
 * @author Denis Vashchuk
 * @copyright BSUIR 2013
 *
 */

/*! \mainpage Common Information
 *
 * \section intro_sec Introduction
 *
 * <p>NetDroid neuraxis developed by Denis Vashchuk (firmware + partly hardware) and Alex Lapuka (hardware)</p>
 * <p>Hardware: <a href="http://www.st.com/web/en/catalog/mmc/FM141/SC1169/SS1031/LN1565/PF164476">STM32F103C8T6</a> (ARM Cortex-M3 64K Flash and 20K SRAM MCU) based board.</p>
 * <p>Firmware: Written fully on C with help STM StdPeriphery Library</p>
 *
 *
 * \section build_sec Building firmware
 *
 *  What you need for build firmware:
 *  <ul>
 *  <li>Build system based on GNU Make. Tested on ArchLinux x86_64. Also, you can use Windows.</li>
 *  <li>Toolchain CodeSourcery Lite 2010q ARM (http://www.mentor.com/embedded-software/sourcery-tools/sourcery-codebench/editions/lite-edition/)</li>
 *  <li>Doxygen for genrating documentation</li>
 *  <li>Clear brain and cup of coffee.</li>
 *	</ul>
 *
 *	<h2>Building:</h2>
 *	<ol>
 *	<li>$ cd ./firmware</li>
 *	<li>change TOOLS_PATH in project.inc file to arm toolchain path (see above) using you favorite text editor (such as vim or emacs )</li>
 *	<li>$ make firmware #Firmware image will be placed to ./bin/netdroid.bin</li>
 *	<li>$ make documentation #Documentation generated by doxygen will be placed to ./doxygen</li>
 *	</ol>
 *
 * \section install_sec Flashing
 *
 * <h2>Using STM system bootloader via USART1</h2>
 * For flash MCU via USART:
 * <ol>
 * <li>Connect CMOS Level USART to PC via USB(For example).</li>
 * <li>Connect USART RX/TX to Neuraxis board USART1 connector.</li>
 * <li>Remove BOOT0 jumper and put BOOT1 jumper</li>
 * <li>Power ON MCU</li>
 * <li>run commands
 * <ol> <li>$ cd ./firmware</li>
 * 		<li>$ make install</li>
 * 	</ol>
 * 	</li>
 * 	<li>Put BOOT0 jumper back</li>
 * 	<li>Reset Neuraxis board to run new firmware image</li>
 * </ol>
 *
 * <h2>Using STLink</h2>
 * You can use stlink debugger for flash firmware to MCU. Before flashing remove jumper from BOOT0, because if
 * firmware is loaded, SWD disabled/remaped for using PA15 GPIO.
 *
 * <ul>
 * <li><a href="https://github.com/texane/stlink">GNU Linux</a></li>
 * <li><a href="http://www.st.com/web/catalog/tools/FM146/CL1984/SC724/SS1677/PF251168">Windows</a></li>
 * </ul>
 *
 * \section development Development Environment
 * I used Eclipse IDE with CDT and EmbSys Registers plugins. You can also use pure text editor and build firmware using make.
 * <p>Windows user can also use IAR and CooCOX IDE</p>
 *
 * @section circuit Circuit Revision 1.1
 * Designed in KiCAD, source files you can find in newschem folder
 *
 * @image html neuraxis_circuit.svg
 *
 * @section pcb PCB Revision 1.1
 * Designed in KiCAD, source files you can find in newschem folder
 * @image html neuraxis_pcb.svg
 * <p>Bugs: Second pin of reset pins must be connected to GND</p>
 * <p>FIXED: PA15 is free, disable SWD not required now.</p>
 * PCB design by Alex Lapuka
 *
 * Sorry for my English =)
 *
 */

#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include "shell.h"
#include "enginectl.h"
#include "servoctl.h"
#include "led.h"

/**
 * Sleep function. Active wait.
 * @para ms sleep time in ms
 */
void delay(uint32_t ms)
{
    volatile uint32_t nCount;
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq (&RCC_Clocks);

    nCount=(RCC_Clocks.HCLK_Frequency/10000)*ms;
    for (; nCount!=0; nCount--)
        __NOP;
}


static void init_clock()
{
    //set low speed internal closk as a system clock
    RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
}

int main()
{
	init_clock();

	//Power ON self test =)
	led_init();
	led_blink(3, 100);

    engine_init();
    shell_init();
    shell_run();
}
