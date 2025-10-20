#include <avr/io.h>
#include "uart.h"

#define F_CPU 16000000UL  // 16 MHz
#define BAUD 9600
#define UBRR_VALUE ((F_CPU/16/BAUD)-1)

void uart_init(void) {
    // Set baud rate
    UBRR0H = (UBRR_VALUE >> 8);
    UBRR0L = UBRR_VALUE;

    // Enable transmitter and receiver
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    // Set frame format: 8 data bits, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send_char(char c) {
    // Wait until data register is empty
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

void uart_send_string(const char* str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

char uart_receive_char(void) {
    // Wait until data is received
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

