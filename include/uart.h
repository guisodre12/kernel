#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init(unsigned int baud);
void uart_transmit(uint8_t data);
void uart_print(const char *str);

#endif
