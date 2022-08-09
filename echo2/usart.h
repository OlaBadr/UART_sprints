 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 *******************************************************************************/

#ifndef USART_H_
#define USART_H_

#include "std_types.h"


/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate);

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data);

 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data);


#endif /* USART_H_ */
