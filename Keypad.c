//4*4 keypad

#define F_CPU 8000000UL         //for delay
#include <avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void lcd_ini();
void command(unsigned char);
void data(unsigned char);

void main(void) {
    DDRC=0x0F;
    DDRD=0xFF;
    DDRB=0x0F;
    lcd_ini();
    command(0x80);
    while(1){
        PORTB=0x0E;
        if(!(PINB&0x10)){
            data('1');
        }
        if(!(PINB&0x20)){
            data('2');
        }
        if(!(PINB&0x40)){
            data('3');
        }
        if(!(PINB&0x80)){
            data('A');
        }
        PORTB=0x0D;
        if(!(PINB&0x10)){
            data('4');
        }
        if(!(PINB&0x20)){
            data('5');
        }
        if(!(PINB&0x40)){
            data('6');
        }
        if(!(PINB&0x80)){
            data('B');
        }
        PORTB=0x0B;
        if(!(PINB&0x10)){
            data('7');
        }
        if(!(PINB&0x20)){
            data('8');
        }
        if(!(PINB&0x40)){
            data('9');
        }
        if(!(PINB&0x80)){
            data('C');
        }
        PORTB=0x07;
        if(!(PINB&0x10)){
            data('*');
        }
        if(!(PINB&0x20)){
            data('0');
        }
        if(!(PINB&0x40)){
            data('#');
        }
        if(!(PINB&0x80)){
            data('D');
        }
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
void data(unsigned char ch)
{
    PORTC|=1<<0;
    PORTC&=~(1<<1);
    PORTD=ch;
    PORTC|=1<<2;
    _delay_ms(5);
    PORTC&=~(1<<2);
    while((PINB&0x10)==0);
    while((PINB&0x20)==0);
    while((PINB&0x40)==0);
    while((PINB&0x80)==0);
    
}


