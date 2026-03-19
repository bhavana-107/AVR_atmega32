//LCD normal method

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>


char buffer[10];
void lcd_ini();
void command(unsigned char);
void display(unsigned char*);
void data(unsigned char);

void main(void) {
    DDRC=0x0F;          //
    DDRD=0xFF;
    int i=0;
    lcd_ini();
    
    while(1){ 
       command(0x80); 
       sprintf(buffer,"%d",i++);
       display(buffer);
       _delay_ms(500);
       
      // command(0x14);
       //display("hi");
    }
    return;
}
void lcd_ini(){
    command(0x38);
    command(0x0C);
    command(0x06);
    command(0x01);
    //command(0x80);
}
void command(unsigned char c){
    PORTC&=~(1<<0);
    PORTC&=~(1<<1);
    PORTD=c;
    PORTC|=1<<2;
    _delay_ms(5);
    PORTC&=~(1<<2);
}
void display(unsigned char *ptr){
    while(*ptr){
        data(*ptr++);
    }
}
void data(unsigned char ch)
{
    PORTC|=1<<0;
    PORTC&=~(1<<1);
    PORTD=ch;
    PORTC|=1<<2;
    _delay_ms(5);
    PORTC&=~(1<<2);
}
