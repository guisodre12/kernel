#include <avr/io.h>
#include <stdio.h>
#include <string.h>

#include "gpio.h"
#include "uart.h"
#include "shell.h"

#define TAMANHO_BUFFER 32
static char buffer[TAMANHO_BUFFER];
static uint8_t index = 0;
int num = 1;

void shellLoop(){
  char c = uart_receive_char();  
    if (c == '\r' || c == '\n') {
      buffer[index] = '\0';
      uart_send_string("\r\n");

      if(strcmp(buffer, "write") == 0){
        uart_send_string("pegou papai \r\n");
      }
      if(strcmp(buffer, "arduino-led") == 0){
        gpio_toggle('B', 5);
        num = num + 1;
        
        if(num % 2 == 0){
          uart_send_string("O LED interno esta LIGADO! \r\n");
        }
        else{
          uart_send_string("O LED interno esta DESLIGADO! \r\n");
        }
        //uart_send_string("normal");
      }
      index = 0;
      uart_send_string("user[~]$:");
    }

    else if (c == 8 || c == 127) {
        if (index > 0) {
            index--;
            uart_send_string("\b \b");
        }
    }  

    else if (index < TAMANHO_BUFFER - 1) {
        buffer[index++] = c;
        uart_send_char(c); // echo 
    }
}


