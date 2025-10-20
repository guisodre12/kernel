# Compiler and tools
CC = avr-gcc
OBJCOPY = avr-objcopy
MCU = atmega328p
F_CPU = 16000000UL
BAUD = 9600

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Files
TARGET = main
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
HEX = $(BUILD_DIR)/$(TARGET).hex

# Flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -I$(INC_DIR)
LDFLAGS = -mmcu=$(MCU)

# Default target
all: $(BUILD_DIR) $(HEX)

# Build rules
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

$(HEX): $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Flash to Arduino
flash: $(HEX)
	sudo avrdude -F -V -c arduino -p $(MCU) -P /dev/ttyUSB0 -b 115200 -U flash:w:$(HEX):i

# Clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all flash clean


