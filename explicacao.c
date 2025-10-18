#include <avr/io.h>

//Essa func permite transformar um pino em OUTPUT
//Isso aqui nada mais é do que eu reescrevendo do zero pinMode()
int gpio_output(char port, int pin){ //recebe a porta, e o pino.
    
    //vamos por partes.
    //Qual foi a das letras? No chip ATmega328p(O que to usando)
    //As saidas do processador sao dividas por letras.
    //Porta B: Pinos 8-13
    //Porta C: Pinos analogicos
    //Porta D: Pinos de 0-7
    if(port == 'B'){ //Se a porta for B faça:
         DDRB |= (1 << pin); //DDR é uma variavel do processador que carrega a info se é input, ou output. Como estamos usando uma porta B, o comando vira DDR + port = DDRB.
         //|= faz o trabalho de inserir esse valor pra gente.
         // em (1 << pin); o pino recebe o valor de 1(True), virando output.
    }
    else if(port == 'C') DDRC |= (1 << pin);
    else if(port == 'D') DDRD |= (1 << pin);
     
}

//Essa func liga ou desliga. Nada mais é do que reescrever digitalWrite().(HIGH ou LOW).
int gpio_write(char port, unsigned int pin, unsigned int value){
    switch(port){
        case 'B':
            if(value) PORTB |= (1 << pin);
            else PORTB &= ~(1 << pin);
            break;
            
            //Com a explicação acima, nao tem muito misterio. Funciona bem parecido, so usa PORTB que é outra variavel do processador, relacionado ao read/write.
        case 'C':
            if(value) PORTC |= (1 << pin);
            else PORTC &= ~(1 << pin);
        case 'D':
            if(value) PORTD |= (1 << pin);
            else PORTC &= ~(1 << pin);
    }
}

//Bem legal, inverte o valor do pino.
//Se ta low, vira high, se ta high, vira low.
int gpio_toggle(char port, unsigned int pin){
    switch(port){
        case 'B':
            PORTB ^= (1 << pin); break;
        case 'C':
            PORTC ^= (1 << pin); break;
        case 'D':
            PORTD ^= (1 << pin); break;
        
    }
}
