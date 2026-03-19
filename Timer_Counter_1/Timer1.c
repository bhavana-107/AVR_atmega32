//Timer1 creating a delay of 1sec

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>

void main(void) {
    DDRB=0xFF;
    TCCR1A=0x00;
    TCCR1B=0x05;
    TCNT1=57723;
    while(1){
        if(TIFR&0x04){
            TCNT1=57723;
            PORTB=~PORTB;
            TIFR|=0x04;
        }
    }
    return;
}
