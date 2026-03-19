//Counter using Timer1 counts from 0 to 65535 

#define F_CPU 8000000UL        
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void display(unsigned char*);
char buffer[10];

void main(void) {
    DDRB=0x00;
    TCCR1A=0x00;
    TCCR1B=0x07;
    
    DDRD=0x02;
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRL=51;
    DDRB=0x00;

    while(1){
        int i=TCNT1;
        while(PINB&0x02);        //To check button state in T1(PB1) pin
        while(!(PINB&0x02));
        sprintf(buffer,"%d\n\r",i);
        display(buffer);
    }
    
    return;
}
void display(unsigned char *ptr){
    while(*ptr){
        while(!(UCSRA&(1<<5)));
        UDR=*ptr++;
        
    }
}
