#include <avr/io.h>
#include "gpio.h"

void gpio_output(char port, unsigned int pin) {
  if(port == 'B') DDRB |= (1 << pin);
  else if(port == 'C') DDRC |= (1 << pin);
  else if(port == 'D') DDRD |= (1 << pin);
}

void gpio_write(char port, unsigned int pin, unsigned int value){
  switch(port){
    case 'B':
     if(value) PORTB |= (1 << pin);
     else PORTB &= ~(1 << pin);
    
    case 'C':
     if(value) PORTC |= (1 << pin);
     else PORTC &= ~(1 << pin);
    
    case 'D':
     if(value) PORTD |= (1 << pin);
     else PORTD &= ~(1 << pin);
  }
}

void gpio_toggle(char port, unsigned int pin){
  switch(port){
    case 'B':
     PORTB ^= (1 << pin); break;
    case 'C':
     PORTC ^= (1 << pin); break;
    case 'D':
     PORTD ^= (1 << pin); break;
  }
}
