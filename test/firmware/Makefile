#
# @author Denis Vashchuk
#
include project.inc

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
SIZE:=$(TOOLS_PATH)/$(TOOLS_PREFIX)size
AS:=$(TOOLS_PATH)/$(TOOLS_PREFIX)as
LD:=$(TOOLS_PATH)/$(TOOLS_PREFIX)ld
OBJCOPY:=$(TOOLS_PATH)/$(TOOLS_PREFIX)objcopy

OBJS += $(patsubst %.c,%.o, $(wildcard cmsis/*.c))
OBJS += $(patsubst %,%.o, $(addprefix $(STDPERIPH_DIR)/src/, $(DRIVER)))
OBJS += $(patsubst %.c,%.o, $(wildcard src/*.c))
OBJS += $(patsubst %.c,%.o, $(wildcard stdlib/*.c))
OBJS += $(patsubst %.s, %.o, $(STARTUP))

.PHONY: clean

$(BINFILE): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.s
	$(AS) $(ASLAGS) -o $@ $<

clean:
	rm -f $(OBJS) bin/*.elf bin/*.bin

$(OUTFILE): $(OBJS)
	$(CC) -T $(LAYOUT) -nostartfiles -nostdlib -nodefaultlibs $(OBJS) -o bin/$@ -Wl,-Map=webdroid.map
	$(SIZE)  -B bin/$@ 

$(BINFILE): $(OUTFILE)
	$(OBJCOPY) -Obinary bin/$(OUTFILE) bin/$(BINFILE)

firmware: $(BINFILE)	
	
install: $(BINFILE)
	 stm32flash -w bin/webdroid.bin -g 0x0 /dev/ttyUSB0

all: rebuild

rebuild: clean firmware
