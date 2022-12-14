/******************************************************************************
 *
 * Module: MC2
 *
 * File Name: echo2.c
 *
 * Description: echo application MC2 (Echo Back)
 *
 * Author: Ola Badr
 *
 *******************************************************************************/
#include <stdio.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"
#include "avr/io.h" /* To use the IO Ports Registers */
#include "usart.h"



int main ()
{
	SWUART_init(9600);
	/*add delay before starting the communication*/
	_delay_ms(500);

	uint8_t recieved_data;
	uint8_t sent_data;

	while(1)
	{
		SWUART_recieve(&recieved_data);
		_delay_ms(100);
		sent_data = recieved_data;
		SWUART_send(recieved_data);

	}

	return 0;
}


