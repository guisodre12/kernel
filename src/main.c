#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "uart.h"
#include "shell.h"

int main (void){
  gpio_output('B',5);
  uart_init();
  
  uart_send_string("user[~]$:");
  while(1){
    shellLoop();
  }
  return 0;
}

