/*
 * modular_coding.c
 *
 * Created: 12-02-2026 19:34:36
 * Author :Sunil
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "Timer.h"


int main(void)
{ 
	TIMER_CONGIG();
	DELAY_VALUE();
	delay_1s();
	
	 while(1)
	{
		PORTB|=(1<<PB5); //PB5 IS ON 
		delay_1s();
		PORTB&=~(1<<PB5);//PB5 IS OFF 
		delay_1s();
		
	}
}
