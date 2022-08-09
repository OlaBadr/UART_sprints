/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 *******************************************************************************/

#include "gpio.h"

#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */

#include "std_types.h"

/*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * direction: is an input argument that describes the data direction on a specific pin, IN or OUT
 */
void DIO_init(uint8_t pinNumber, uint8_t port, uint8_t direction)
{

	/* Setup the pin direction as required */
	switch(port)
	{
	case 'A':
		if(direction == OUT)
		{
			SET_BIT(DDRA,pinNumber);
		}
		else
		{
			CLEAR_BIT(DDRA,pinNumber);
		}
		break;
	case 'B':
		if(direction == OUT)
		{
			SET_BIT(DDRB,pinNumber);
		}
		else
		{
			CLEAR_BIT(DDRB,pinNumber);
		}
		break;
	case 'C':
		if(direction == OUT)
		{
			SET_BIT(DDRC,pinNumber);
		}
		else
		{
			CLEAR_BIT(DDRC,pinNumber);
		}
		break;
	case 'D':
		if(direction == OUT)
		{
			SET_BIT(DDRD,pinNumber);
		}
		else
		{
			CLEAR_BIT(DDRD,pinNumber);
		}
		break;
	}



}


/*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * value: is an input argument that describes the value on a specific pin, LOW or HIGH
 */
void DIO_write(uint8_t pinNumber, uint8_t port, uint8_t value)
{
	/* Write the pin value as required */
	switch(port)
	{
	case 'A':
		if(value == HIGH)
		{
			SET_BIT(PORTA,pinNumber);
		}
		else
		{
			CLEAR_BIT(PORTA,pinNumber);
		}
		break;
	case 'B':
		if(value == HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else
		{
			CLEAR_BIT(PORTB,pinNumber);
		}
		break;
	case 'C':
		if(value == HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else
		{
			CLEAR_BIT(PORTC,pinNumber);
		}
		break;
	case 'D':
		if(value == HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else
		{
			CLEAR_BIT(PORTD,pinNumber);
		}
		break;
	}

}




/*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * value: is an output argument that describes the value on a specific pin, LOW or HIGH
 */
void DIO_read(uint8_t pinNumber, uint8_t port, uint8_t *value)
{
	*value = LOW;


	/* Read the pin value as required */
	switch(port)
	{
	case 'A':
		if(BIT_IS_SET(PINA,pinNumber))
		{
			*value = HIGH;
		}
		else
		{
			*value = LOW;
		}
		break;
	case 'B':
		if(BIT_IS_SET(PINB,pinNumber))
		{
			*value = HIGH;
		}
		else
		{
			*value = LOW;
		}
		break;
	case 'C':
		if(BIT_IS_SET(PINC,pinNumber))
		{
			*value = HIGH;
		}
		else
		{
			*value = LOW;
		}
		break;
	case 'D':
		if(BIT_IS_SET(PIND,pinNumber))
		{
			*value = HIGH;
		}
		else
		{
			*value = LOW;
		}
		break;
	}

}

