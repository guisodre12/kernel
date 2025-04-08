#include <avr/io.h>
#include <util/delay.h>

void uart_init(uint16_t ubrr) {
    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;
    UCSR0B = (1 << TXEN0);  // Enable TX only
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  // 8N1
}

void uart_send(char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void uart_send_string(const char* str) {
    while (*str) {
        uart_send(*str++);
    }
}

int main(void) {
    uart_init(103);  // 9600 baud @ 16MHz

    while (1) {
        uart_send_string("papagoiabazzzzz\n");
        _delay_ms(1000);
    }
}
