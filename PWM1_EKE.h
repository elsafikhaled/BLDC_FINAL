/*
 * PWM1_EKE.h
 *
 *  Created on: ??�/??�/????
 *      Author: El-safi
 */

#ifndef PWM1_EKE_H_
#define PWM1_EKE_H_


#include"std_data_types_EKE.h"



void PWM1_EKE_init(void);
/* ************************************** system initialization *******************************************
 *
 * FUNCTION    :: void PWM1_EKE_init(void);
 *
 * Parameters  :: void
 *
 * Description :: Timer1 initialization for FAST PWM AND non  INVERTING MODE, 16 Bits, 1024 prescaler
 *
 * Return      :: void
 *
 * *******************************************************************************************************/


void PWM1_EKE_duty(U16_t duty);
/* ************************************** system initialization *******************************************
 *
 * FUNCTION    :: void PWM1_EKE_duty(U16_t duty);
 *
 * Parameters  :: unsigned integer variable --> duty
 *
 * Description :: Timer1 OCR1B register  for FAST PWM AND  non INVERTING MODE, 16 Bits
 *
 * Return      :: void
 *
 * *******************************************************************************************************/

void PWM1_EKE_start(void);
/* ************************************** system initialization *******************************************
 *
 * FUNCTION    :: void PWM1_EKE_start(void);
 *
 * Parameters  :: void
 *
 * Description :: Timer1 start
 *
 * Return      :: void
 *
 * *******************************************************************************************************/
void PWM1_EKE_stop(void);
/* ************************************** system initialization *******************************************
 *
 * FUNCTION    :: void PWM1_EKE_stop(void);
 *
 * Parameters  :: void
 *
 * Description :: Timer1  stop
 *
 * Return      :: void
 *
 * *******************************************************************************************************/
void PWM_MAP_ADC(U8_t channel);
/* ************************************** system initialization *******************************************
 *
 * FUNCTION    :: void PWM_MAP_ADC(U8_t channel);
 *
 * Parameters  :: void
 *
 * Description :: vary register value according ADC 10bit  value.
 *
 * Return      :: void
 *
 * *******************************************************************************************************/




#endif /* PWM1_EKE_H_ */
