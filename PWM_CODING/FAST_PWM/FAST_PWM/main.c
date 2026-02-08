/*
 * FAST_PWM.c
 *
 * Created: 08-02-2026 19:27:44
 * Author : SUNIL
  */

#include <avr/io.h>
#define F_CPU 16000000UL

int main(void)
{
	DDRD|=(1<<DDD6);//CONFIGURING THE PIN D6 AS OUTPUT PIN
	
    TCCR0A|=(1<<WGM01)|(1<<WGM00);// FAST PWM MODE
	
	TCCR0A|=(1<<COM0A1)|(1<<COM0A0);// CONFIGURING INVERTING PWM
	
	// PRESCALAR AS 8 FOR 8KHZ FREQUENCY
	TCCR0B|=(1<<CS01);
	TCCR0B&=~(1<<CS00); 
	
	OCR0A=102;// FOR 60% DUTY CYCLE
	
    while (1) 
    {
    }
}


