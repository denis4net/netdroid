TOOLS_PATH:=/mnt/laptop-home/dev/arm/toolchains/gcc-arm-none-eabi-4_6-2012q4/bin

TARGET := neuraxis

DEFINES += STM32F10X_MD
DEFINES += USE_SRDPERIPH_DRIVER
DEFINES += VECT_TABLE_FLASH
DEBUG	:= -gdwarf-2
STARTUP	:=	startup_stm32f10x_md.s

DRIVER	+=	stm32f10x_gpio
DRIVER	+=	stm32f10x_rcc
DRIVER	+=	stm32f10x_usart
DRIVER 	+= 	stm32f10x_tim
DRIVER 	+= 	misc

SRC_DIR 	:= 		src
CMSIS_DIR 	:= 	cmsis
STDPERIPH_DIR := stm32_periph
