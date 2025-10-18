#include <avr/io.h>
#include <gpio.h>
/*
 *Dedico esse codigo primeiramente ao saudoso Eric Souza do Senai-SG
 *
 *-Guilherme Sodre
 */


//Torna um pino como output.
//Tal qual o PinMode no ArduinoIDE.
void gpio_output(char port, unsigned int pin){
  switch(port){
    case 'B':
     DDRB |= (pin << 1);
    case 'C':
     DDRB |= (pin << 1);
    case 'D':
     DDRD |= (pin << 1);
  } 
}

//Da um valor para uma porta especifica
//Tal qual como o DigitalWrite ou AnalogWrite no ArduinoIDE.
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

//Flipa o valor do pino.
//Uns(1) viram zeros e zeros viram uns.
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
