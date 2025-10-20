#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "uart.h"

int main (void){
  gpio_output('B',5);
  uart_init();

  uart_send_string("Ola, mundo!");

  while(1){
    char caractere = uart_receive_char();
    uart_send_char(caractere);
  }
  return 0;
}
