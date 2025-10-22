#include <avr/io.h>
#include "uart.h"

#define F_CPU 16000000UL  // 16 MHz
#define BAUD 9600
#define UBRR_VALUE ((F_CPU/16/BAUD)-1)

void uart_init(void) {
    //  baud rate
    UBRR0H = (UBRR_VALUE >> 8);
    UBRR0L = UBRR_VALUE;

    // transmitter and receiver
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send_char(char c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

void uart_send_string(const char* str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

char uart_receive_char(void) {
    // receber
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

