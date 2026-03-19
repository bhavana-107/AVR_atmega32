//Capturing the value at the timer register ad displaying via UART

#define F_CPU 8000000UL        
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void display(unsigned char*);
char buffer[10];

void main(void) {
    TCCR1A=0x00;
    TCCR1B=0xC5;
    DDRD=0xB2;
    
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRL=51;
    while(1){
        unsigned int i=ICR1;
        while(PIND&0x40);
        while(!(PIND&0x40));
        sprintf(buffer,"%u\n\r",i);
        display(buffer);
        _delay_ms(1000);
    }
    return;
}
void display(unsigned char *ptr){
    while(*ptr){
        while(!(UCSRA&(1<<5)));
        UDR=*ptr++;
        
    }
}
