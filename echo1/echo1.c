/******************************************************************************
 *
 * Module: MC1
 *
 * File Name: echo1.c
 *
 * Description: echo application MC1
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
	uint8_t sent_data = 16;
	uint8_t recieved_data;

	while(1)
	{
		SWUART_send(sent_data); //echo
		_delay_ms(100);
		SWUART_recieve(&recieved_data); //echo back
		_delay_ms(100);

		if (sent_data == recieved_data)
			continue;

		else
			break;
	}

	return 0;
}


