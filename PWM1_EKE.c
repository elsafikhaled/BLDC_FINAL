/*
 * PWM1_EKE.c
 *
 *  Created on: ??�/??�/????
 *      Author: El-safi
 */
#include "PWM1_EKE.h"
#include "ADC.h"
#include <avr/io.h>


void PWM1_EKE_init(void)
{
//inverting mode.
  TCCR1A=(1<<COM1B1)|(1<<COM1B0)|(1<<WGM11);//inverting mode
  TCCR1A&=~(1<<FOC1B);
  TCCR1B=(1<<WGM12)|(1<<WGM13)|(1<<CS11);//prescaler 8
  TCNT1=0;
  ICR1=50;//frequency 10khz--50


}


void PWM1_EKE_duty(U16_t duty)
{

  OCR1B=(50-duty);


}



void PWM1_EKE_start(void)
{

	OCR1B=0;

}

void PWM1_EKE_stop(void)
{

  TCCR1B=0;

}

void PWM_MAP_ADC(U8_t channel){
	U16_t digital=0;
	digital=ADC_Read(channel);
	if(digital<=205){//leakage from accelerator about 1v=1000mv,1mv=205 digital
		digital=0;
	}
	digital=(U16_t)((float)digital/20.46);
	OCR1B =50-digital ;

}
