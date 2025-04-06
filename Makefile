# Nome do projeto (output final)
TARGET = main

MCU = atmega328p

# Frequência do clock em Hz
F_CPU = 16000000UL

# Porta serial usada para programar o Arduino
PORT = /dev/ttyUSB0

# Baudrate usado para programação via avrdude
BAUD = 115200

# Compilador e flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -Os -DF_CPU=$(F_CPU) -Iinclude
OBJCPY = avr-objcopy

# AVRDude config
AVRDUDE = avrdude
PROGRAMMER = arduino

# Arquivos fonte
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

# Alvos
all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p m328p -P $(PORT) -b $(BAUD) -U flash:w:$(TARGET).hex

clean:
	rm -f $(TARGET).elf $(TARGET).hex $(OBJ)
