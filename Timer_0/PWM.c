#define F_CPU 8000000UL       
#include <avr/io.h>
#include<util/delay.h>

void main(void) {
    DDRB=0xFF;
    TCCR0=0x6D;
    //OCR0=78;
    while(1){
        for(int i=0;i<256;i++){
            OCR0=i;
            _delay_ms(3);
        }
        for(int i=255;i>=0;i--){
            OCR0=i;
            _delay_ms(3);
        }
    }
    return;
}
