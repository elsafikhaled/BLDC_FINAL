/*
 * ADC.c
 *
 *  Created on: ٢٥‏/٠٢‏/٢٠١٨
 *      Author: El-safi
 */
#include "ADC.h"
#include <avr/io.h>
#include <util/delay.h>

void ADC_Init(void){//!Start setup function.

	ADCSRA = 0x87;			// Enable ADC, with freq/128
	ADMUX = 0x40;			// Vref: Avcc, ADC channel: 0

}//! End of setup function.


U16_t ADC_Read(U8_t channel){//!Start Read function.


ADMUX = 0x40 | (channel & 0x07); // set input channel to read
ADCSRA |= (1<<ADSC);		     //Start ADC conversion
while (!(ADCSRA & (1<<ADIF)));	 // Wait until end of conversion
ADCSRA |= (1<<ADIF);		     // Clear interrupt flag
_delay_ms(1);			         // Wait a little bit
return ADC;			             // Return ADC word

}//! End of Read function.


