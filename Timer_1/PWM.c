//PWM using Timer1

#define F_CPU 8000000UL        
#include <avr/io.h>
#include<util/delay.h>

void main(void) {
    DDRD=0x20;
    TCCR1A=0x83;
    TCCR1B=0x0D;
    while(1){
        for(int i=0;i<1024;i++){
            OCR1A=i;
            _delay_ms(3);
        }
        for(int i=1023;i>=0;i--){
            OCR1A=i;
            _delay_ms(3);
        }
    }
    return;
}
