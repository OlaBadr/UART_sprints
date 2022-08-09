 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver
 *
 *******************************************************************************/

#include "usart.h"

#include "avr/io.h" /* To use the UART Registers */
#include "common_macros.h" /* To use the macros like SET_BIT */



/*
 * baud rate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate)
 {

	 /* Set baud rate */
	 UBRRH = (unsigned char)(baudrate>>8);
	 UBRRL = (unsigned char)baudrate;
	 /* Enable receiver and transmitter */
	 UCSRB = (1<<RXEN)|(1<<TXEN);
	 /*Asynchronous operation - Set frame format: 8data, 2stop bit , even parity */
	 UCSRC = (1<<URSEL)| (1<<UPM1) |(1<<USBS)|(3<<UCSZ0);

 }


void SWUART_send(uint8_t data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );

	/* Put data into buffer, sends the data */
	UDR = data;
}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
void SWUART_recieve(uint8_t *data)
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	*data = UDR;
}

