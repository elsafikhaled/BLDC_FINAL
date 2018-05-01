/*
 * TbUartCfg.h
 *
 *  Created on: ٢٤‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */
#ifndef TBUARTCFG_H_
#define TBUARTCFG_H_

#define BAUDRATE       ((U8_t)51)
#define ENABLE_TX      (1<<TXEN)
#define ENABLE_RX      (1<<RXEN)
#define NO_PARITY      (1<<UPM1)|(1<<UPM0)
#define STOPBITS       (1<<USBS)
#define FRAMBITS       (1<<UCSZ0)|(1<<UCSZ1)





#endif/*END of config */

