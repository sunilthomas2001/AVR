/*
 * dc_motor_using_atmega328.c
 * Created: 29-01-2026 18:03:59
 * Author : Sunil Thomas
 */





 #define F_CPU 16000000UL
 #include <avr/io.h>
 #include <util/delay.h>


 int main(void)
 {
 DDRB |= (1 << PB0) | (1 << PB1);
 
 while (1)
 {
 PORTB |= (1 << PB0);
 PORTB &= ~(1 << PB1);
 _delay_ms(2000);
 
 PORTB &= ~(1 << PB0);
 PORTB |= (1 << PB1);
 _delay_ms(1000);
 
 PORTB &= ~(1 << PB0);
 PORTB &= ~(1 << PB1);
 _delay_ms(2000);
 }
 }


