/*
 * pullup resistor.c
 *
 * Created: 05-02-2026 17:55:47
 * Author : sunil
 */ 

 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
DDRD&=~(1<<DDD4); // Configuring Pin D4 as input
DDRB|=(1<<DDB5); // Configuring Pin B5 as output
PORTD|=(1<<PD4);// Activating internal pull up for PD4
    while (1) 
    {
		if(PIND&(1<<PD4)) // Checking if PD4 pin is released
		{
			
			PORTB&=~(1<<PB5); // turning PB5 Pin low
		}
		else
		{
			PORTB|=(1<<PB5); // turning PB5 pin high
		}
		
    }
}