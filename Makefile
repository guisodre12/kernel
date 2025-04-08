MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
PORT = /dev/ttyUSB0     
BAUD = 115200

# Paths and flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=c11 -Isrc -Iinclude
LDFLAGS = -mmcu=$(MCU)

# Source files
//SRC = src/main.c src/gpio.c src/uart.c
SRC = src/test.c
OBJ = $(SRC:.c=.o)
TARGET = main.elf

# Build rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

flash: $(TARGET)
	avrdude -v -patmega328p -carduino -P$(PORT) -b$(BAUD) -D -Uflash:w:$(TARGET):e

clean:
	rm -f src/*.o *.elf
