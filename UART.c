//Single character Transmission

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void main(void) {
    DDRD=0x02;
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRL=51;
    
    while(1){
        while(!(UCSRA&(1<<5)));
        UDR='a;
        _delay_ms(1000);      
    }
    return;
}



//Transmission and Reception

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void main(void) {
    DDRD=0x02;
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRL=51;
    char c;
    
    while(1){
       while(!(UCSRA&0x80));      
       c=UDR;
        while(!(UCSRA&(1<<5)));
        UDR=c;
    }
    return;
}



//String transmission

#define F_CPU 8000000UL      
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void display(unsigned char*);

void main(void) {
    DDRD=0x02;
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRL=51;
    char c;
    
    while(1){

       char c[15]="bhavana\r\n";
       display(c);
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
