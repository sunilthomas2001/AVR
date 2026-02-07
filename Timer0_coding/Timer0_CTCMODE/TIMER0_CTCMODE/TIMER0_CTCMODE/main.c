/*
 * TIMER0_CTCMODE.c
 *
 * Created: 07-02-2026 16:06:48
 * Author : SUNIL
 */


#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	for(int i=0;i<78;i++) //repeating the process 78 times
	{
		while (!(TIFR0&(1<<OCF0A))); //wait until ocf0a =1
		TIFR0|=(1<<OCF0A); //writing 1 to OCF0A bit to make it 0
	}
}

int main(void)
{
	TCNT0= 0; // initial value of TCNT0 =0
	
	//CONFIGURING TIMER 0 CTC MODE
	TCCR0A &=~(1<<WGM00);
	TCCR0A |=(1<<WGM01);
	
	//CONFIGURING TIMER0 FOR 1024 PRESCALAR 
	TCCR0B|=(1<<CS00)|(1<<CS02);
	TCCR0B&=~(1<<CS01);
	OCR0A=200;
	
	DDRB|=(1<<PB5); //CONFIGURING PB5 AS PIN FOR LED
	
	while(1)
	{
		PORTB|=(1<<PB5); //PB5 IS ON 
		delay_1s();
		PORTB&=~(1<<PB5);//PB5 IS OFF 
		delay_1s();
		
	}
}

