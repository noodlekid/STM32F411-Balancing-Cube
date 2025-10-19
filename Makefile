TARGET = stm32f411_proj


DEBUG = 1
OPT = -Og


BUILD_DIR = build

C_SOURCES = \
			core/src/main.c \
			core/src/gpio.c \
			core/src/spi.c \
			core/src/led.c \
			lib/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c \
			startup/startup_stm32f411xe.c


ASM_SOURCES = 

PREFIX = arm-none-eabi-

CC = $(PREFIX)gcc
AS = $(PREFIX)as
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size

HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S


# CFlags
CPU = -mcpu=cortex-m4

FPU = -mfpu=fpv4-sp-d16

FLOAT-ABI = -mfloat-abi=hard

MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

C_DEFS = \
		 -DSTM32F411xE \
		 -DUSE_FULL_LL_DRIVER

C_INCLUDES = \
			 -Icore/inc \
			 -Ilib/CMSIS/Include \
			 -Ilib/CMSIS/Device/ST/STM32F4xx/Include

ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
	CFLAGS += -g -gdwarf-2
endif

CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


LDSCRIPT = STM32F411CEUx_FLASH.ld

LIBS = -lc -lm -lnosys
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections


all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

# List of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# Clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)

#######################################
# Flash
#######################################
flash: all
	st-flash erase
	st-flash write $(BUILD_DIR)/$(TARGET).bin 0x8000000
	st-flash reset

#######################################
# Dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)


