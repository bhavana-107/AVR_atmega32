//Clear timer on compare match using timer0

#define F_CPU 8000000UL       
#include <avr/io.h>
#include<util/delay.h>

void main(void) {
    TCCR0=0x1D;
    DDRB=0x0B;
    OCR0=190;
    while(1);
    return;
}
