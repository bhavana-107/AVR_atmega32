//ADC

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void display(unsigned char *ptr);
char buffer[10];

void main(void) {
    DDRD=0x02;
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRL=51;
    DDRA=0x00;
    ADCSRA=0x87;
    int adc_value;
    while(1){
        ADCSRA|=0x40;       //or ADCSRA|=1<<6    bit 6(ADSC bit) is set to start each conversion
        while(ADCSRA&0x40);    // when adc conversion is done bit becomes zero
        adc_value=ADCL;
        adc_value|=(ADCH<<8);
       // while(!(UCSRA&0x80));
        sprintf(buffer,"%d\n\r",adc_value);
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
