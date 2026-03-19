//Clear timer on compare match using timer1

#define F_CPU 8000000UL         //for delay
#include <avr/io.h>
#include<util/delay.h>

void main(void) {
    DDRD=0x20;
    TCCR1A=0x40;
    TCCR1B=0x0D;
    OCR1A=7812;
    while(1);
    return;
}
