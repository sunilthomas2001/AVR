/*
 * adc_lm35interfacing.c
 *
 * Created: 10-03-2026 21:49:45
 * Author : Sunil Thomas
 */


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "lcd.h"

void adc_init(void)
{
	ADMUX|=(1<<REFS0);
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//ENABLING ADC AND SETTING PRESCALAR TO 128
}

uint16_t adc_read(uint8_t channel)
{
	channel&=0x07;//limiting the channel to max 7
	ADMUX  =( ADMUX&0XF8)|channel;//selecting the correct channel
	ADCSRA |=(1<<ADSC); //START CONVERSION
	while(ADCSRA &(1<<ADSC)); //WAIT UNTIL THE CONVERSION FINISHES
	uint16_t value =ADC;
	return ADC;
}

int main (void)
{
	lcd_init();
	adc_init();
	lcd_clear();
	lcd_set_cursor(0,0);
	lcd_print("Temperature:");
	
	while(1)
	{
		uint16_t  value = adc_read(0);
		float temperature = (value*0.488);
		lcd_set_cursor(1,0);
		lcd_print_float(temperature);
		_delay_ms(1000);
	}
}



