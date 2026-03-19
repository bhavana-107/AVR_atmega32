//Outputs a 10ms waveform 

#define F_CPU 8000000UL        
#include <avr/io.h>
#include<util/delay.h>

void main(void){
    DDRB=0xFF;
    TCCR0=0x15;
    OCR0=78;
    while(1){
        if(TIFR&(1<<1)){
            TCNT0=0;
            TIFR|=1<<1;
        }
    }
    return;
}
