/*
 * main.c
 *
 *  Created on: ١٣‏/١٢‏/٢٠١٧
 *      Author: El-safi
 *      version : 0.1
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "TbUart.h"
#include "PWM1_EKE.h"
#include "ADC.h"

//ACtive main Communication System.
#define UART_ACTIVATION_RX 1
#define OPENED 1
#define CLOSED 0

//PWM-VALUE global variable for interrupt.
volatile unsigned char PWM=0;
U8_t LOCK=OPENED;
//voltage -current sensors.
U16_t Cdigital=0;
double voltage=0;
U16_t mCurrent =0;




int main(void)
{

//! MOSFETS control. ON/OFF
	volatile unsigned char value=0;
//!setup GPIO A-B-D.
	DDRA |=0b01111110;//ADC and switching MOSFETS.
	DDRA&=~(1<<PA7)|(1<<PA0);
    DDRB =0x00;
    DDRD|=(1<<PD4);
    PORTA=0b00000000;
    PORTD|=(1<<PD4);
//!open global interrupt paths.
#if(UART_ACTIVATION_RX==1)
      sei();
//!System initialization.
    //setup UART RX interrupt.
      TbUart_init();
#endif
    //setup Timer1 at PWM mode.
      PWM1_EKE_init();
      PWM1_EKE_start();
    //ADC SETUP
      ADC_Init();

	while(1)
	{
	  //read 3 Hall sensors A/B/C
        value=PINB;
        _delay_us(3);
      //check value for switching demanded MOSFETS.
         switch(value){//start switch
             case 5:
            	 PORTA=0b01100000;break;
             case 1:
            	 PORTA=0b01000010;break;
             case 3:
            	 PORTA=0b00010010;break;
             case 2:
            	 PORTA=0b00011000;break;
             case 6:
            	 PORTA=0b00001100;break;
             case 4:
            	 PORTA=0b00100100;break;
             default:
            	 PORTA=0b00000000;break;
                      }//switch

     //get voltage miliVoltage. mV
  	   Cdigital=ADC_Read(0);
       voltage=(Cdigital*4.88);
     //neglect offset 2500 mV but by tested at no load it was 2627
       voltage=voltage-2500;
       if(voltage<0)voltage=0;
     //get current mA:: 66mV=1A
       mCurrent=(voltage*15.15)/2;
       voltage=0;
     //CHECK LOCK.
       if(mCurrent>10000){//LOCK.
    	   LOCK=CLOSED;
    	   mCurrent=0;
    	   //brake motor (50-0=50).
    	   PWM1_EKE_duty(0);
       }//LOCK.
       else{
    	   LOCK=OPENED;
       }

     //Access motor speed 30% from UART channel.
       if(LOCK==OPENED){
           PWM1_EKE_duty(PWM);

       }//PWM

	}//while
	      return 0;
}//End of main function.


ISR(USART_RXC_vect){//start the service routine for RX interrupt.
//get PWM from UART channel.
	PWM=0;
   PWM=UDR;
}//End of UART RX ISR.


