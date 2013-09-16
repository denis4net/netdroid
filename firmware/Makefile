include project.inc

TOOLS_PATH:=/home/denis/dev/arm/arm-2010q1/bin
TOOLS_PREFIX:=arm-none-eabi-

OUTFILE:=$(TARGET).elf
BINFILE:=$(TARGET).bin
LAYOUT:=$(TARGET).ld

INCLUDES += .
INCLUDES += $(CMSIS_DIR)
INCLUDES += $(STDPERIPH_DIR)/inc

CFLAGS:=-mcpu=cortex-m3 -Wall $(INCLUDE) $(addprefix -D, $(DEFINES)) \
	$(addprefix -I, $(INCLUDES)) -fno-common -O0 -mthumb --std=gnu99 \
	"-Dassert_param(expr) ((void)0);"
	
ASFLAGS:= -ahls -mapcs-32

CC:=$(TOOLS_PATH)/$(TOOLS_PREFIX)gcc
AS:=$(TOOLS_PATH)/$(TOOLS_PREFIX)as
LD:=$(TOOLS_PATH)/$(TOOLS_PREFIX)ld
OBJCOPY:=$(TOOLS_PATH)/$(TOOLS_PREFIX)objcopy

OBJS += $(patsubst %.c,%.o, $(wildcard cmsis/*.c))
OBJS += $(patsubst %,%.o, $(addprefix $(STDPERIPH_DIR)/src/, $(DRIVER)))
OBJS += $(patsubst %.c,%.o, $(wildcard src/*.c))
OBJS += $(patsubst %.s, %.o, $(STARTUP))

.PHONY: clean

$(BINFILE): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.s
	$(AS) $(ASLAGS) -o $@ $<

clean:
	rm -f $(OBJS) *.elf *.bin

$(OUTFILE): $(OBJS)
	$(CC) -T $(LAYOUT) -nostartfiles -nostdlib $(OBJS) -o bin/$@ 

$(BINFILE): $(OUTFILE)
	$(OBJCOPY) -Obinary bin/$(OUTFILE) bin/$(BINFILE)
	
install: $(BINFILE)
	 stm32flash -w bin/lab1.bin -g 0x0 /dev/ttyUSB0
