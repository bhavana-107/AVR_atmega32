//Toggle the led based on the interrupts

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>
#include <avr/interrupt.h>
ISR(INT0_vect){
    PORTC^=1<<0;
}
ISR(INT1_vect){
    PORTC^=1<<1;
}

void main(void) {
    DDRD=0x00;
    DDRC=0x0F;
    MCUCR=0x0E;
    MCUCSR=0x00;
    GICR=0xC0;
    sei();           //or SREG|=1<<7   Global Interrupt Enable bit must be set for the interrupts to be enabled
    while(1);
    return;
}
