//generate a 1 sec waveform

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>

void main(void) {
    DDRD=0xFF;
    OCR1A=7812;             //65535-57723  Compare register
    TCCR1A=0x40;
    TCCR1B=0x05;
    while(1){
        if(TIFR&(1<<4)){
            TCNT1=0;
            TIFR|=1<<4;
        }
    }
    return;
}
