/*
 * Timer0_delay.c
 *
 * Created: 06-02-2026 00:43:17
 * Author : sunil
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

void delay_1ms()
{
	
	for(int i=0;i<61;i++)//repeating the process 61time
	{
		
	while (!(TIFR0&(1<<TOV0))); //wait until TOV0=1.
	TIFR0 |=(1<<TOV0);// writing 1 to TOV0 bit to make it 0.
   
    }

}

int main(void)
{
	TCNT0=0;// Initial value of TCNTO =0
    
	//Configuring Timer0 for normal mode
	TCCR0A&=~(1<<WGM00);
	TCCR0A&=~(1<<WGM01);
	
	//Configuring Timer0  for 1024 prescalar condition
	TCCR0B |=(1<<CS00);
	TCCR0B &=~(1<<CS01);
	TCCR0B |=(1<<CS02);
	
	//Configuring A pin for LED
	DDRB |=(1<<PB5);// Configuring pin 5 as output
    while (1) 
    {PORTB|=(1<<PB5); //PB5 is on
		delay_1ms();
		PORTB &=~(1<<PB5); //PB5 is off
		delay_1ms();
		
    }
}

