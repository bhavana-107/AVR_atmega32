//Two digit value

#define F_CPU 8000000UL         
#include <avr/io.h>
#include<util/delay.h>      

int arr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};

void main(void) {
    DDRC=0xFF;
    DDRD=0xFF;
    int n=0;
    while(1){
       
        for(int i=0;i<10;i++){
            
            for(int j=0;j<10;j++){
                while(n<40){
                    PORTC=arr[i];
                    PORTD=0x02;
                    _delay_ms(20);
                    PORTC=arr[j];
                    PORTD=0x01;
                    _delay_ms(20);

                    n++;
             }
             n=0;   
            }
            
        }
        
    }
    return;
}
