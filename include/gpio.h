#ifndef GPIO_H
#define GPIO_H

void gpio_output(char port, unsigned int pin);
void gpio_write(char port, unsigned int pin, unsigned int value);
void gpio_toggle(char port, unsigned int pin);

#endif
