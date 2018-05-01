/*
 * ADC.h
 *
 *  Created on: ٢٥‏/٠٢‏/٢٠١٨
 *      Author: El-safi
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_data_types_EKE.h"


/* ADC Initialization function */
void ADC_Init(void);

/**************************************
 * ADC Read function
 *  Retuen  :: 2 bytes
 *  channel :: 0 to 7
 *************************************/
U16_t ADC_Read(U8_t channel);

#endif /* ADC_H_ */
