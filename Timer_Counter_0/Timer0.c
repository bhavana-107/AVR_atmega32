//Timer 0 creating a delay of 32ms

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>

void main(void) {
    DDRB=0xFF;
    TCCR0=0x05;

    while(1){
        if(TIFR&0x01){
            PORTB=~PORTB;
            TIFR|=0x01;
        }
    }
    return;
}


//timer 0 creating a delay of 10ms

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>

void main(void) {
    DDRB=0xFF;
    TCCR0=0x05;
    TCNT0=177;
    while(1){
        if(TIFR&0x01){
            TCNT0=177;
            PORTB=~PORTB;
            TIFR|=0x01;
        }
    }
    return;
}
