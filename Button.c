//Led with button

#include <avr/io.h>
#include<util/delay.h>      //for delay
#define F_CPU 8000000UL

void main(void){
    DDRB=0x01;    //led connected to PB0
    while(1){
        if(PINB&0x02){      //button is in pull down configuration
            PORTB|=(1<<0);
        }
        else{
            PORTB=0;
        }
    }
    return;
}
