/*
 * External_Interrupt.c
 *
 * Created: 15-02-2026 20:34:33
 * Author : Sunil
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
uint8_t int_flag=0;


ISR (INT1_vect)// INTERRUPT VECTOR TABLE
{
	int_flag=1;
}


int main(void)
{
   DDRB|=(1<<PB5);// PB5 CONFIGURED TO OUTPUT
   DDRB|=(1<<PB4);// PB4 CONFIGURED TO INTERRUPT OUTPUT
   DDRD&=~(1<<PD3);//PD3 CONFIGURED TO INPUT(INI1)
   
   EIMSK|=(1<<INT1); //ENABLING INT1
   
   //CONFIGURED INTERRUPT ON FALLING EDGE
   EICRA|=(1<<ISC11); 
   EICRA&=~(1<<ISC10); 
   
   sei();// ENABLING GLOBAL INTERRUPT
   
   
    while (1) 
    {
		
	if (int_flag)
		{
			
				PORTB|=(1<<PB4);// INTERRUPT LED ON
				_delay_ms(1000); //1 SECOND DELAY
				PORTB&=~(1<<PB4);//INTERRUPT LED Off
				int_flag=0; //RESETTING FLAG
		} 
		
		PORTB|=(1<<PB5);// LED ON
		_delay_ms(1000); //1 SECOND DELAY
		PORTB&=~(1<<PB5);// LED OF
		_delay_ms(1000); //1 SECOND DELAY
		
    }
}
