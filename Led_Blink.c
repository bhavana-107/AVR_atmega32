//To toggle the Leds connected in port B

#include <avr/io.h>
#include<util/delay.h>      //for delay
#define F_CPU 8000000UL
void main(void) {
    DDRB=0xFF;
    while(1){
        PORTB=~PORTB;        //toggle entire port
        _delay_ms(2000);
//        PORTB|=1<<0;       //toggle PB0 only
//        _delay_ms(2000);
//        PORTB&=~(1<<0);
//        _delay_ms(2000);
//        for(int i=0;i<8;i++){    //Led blinking by shifting 
//            PORTB|=1<<i;
//            _delay_ms(2000);
//            PORTB=0;
//            _delay_ms(2000);
//        }
//        PORTB|=(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);    //Toggle entire port
//        _delay_ms(2000);
//        PORTB&=~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
//        _delay_ms(2000);
        
        
    }
    return;
}
