//Controlling 2 motors through a single switch

#define F_CPU 8000000UL        
#include <avr/io.h>
#include<util/delay.h>   

void main(void) {
    DDRC=0x0F;
    int c=0;
    while(1){
        while(PINC&0x10);
        while((PINC&0x10)==0);
        if(c==0){
           PORTC=0x01;
           c++;
        }
        else{
            PORTC=0x04;
            c=0;
        }
    }
    return;
}
