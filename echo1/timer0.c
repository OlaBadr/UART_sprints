/******************************************************************************
 *
 * Module: Timer atmega32
 *
 * File Name: timer0.c
 *
 * Description: Source file for timer0 in AVR driver
 *
 *******************************************************************************/

#include "std_types.h"
#include "timer0.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use Timers Registers */
#include <avr/interrupt.h> /* For Timer ISR */
#include "gpio.h" /*to setup direction*/

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g0_callBackPtr)(void) = NULL_PTR; /*Timer0*/


/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/


ISR(TIMER0_OVF_vect)
{
	if(g0_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g0_callBackPtr)();
	}

	TIFR |= (1<<TOV0); /*Clear Flag*/
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void Timer0_init(void)
{
	TCNT0 = 0; // Set Timer0 initial value to 0

	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);


}

/*==========================CALL BACK FUNCTIONS=================================*/
void Timer0_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g0_callBackPtr = a_ptr;
}



/*==========================DeInit FUNCTIONS=================================*/

void Timer0_DeInit(void)
{
	TIMSK &= ~(1<<TOIE0) & ~(1<<OCIE0); /*Disable Interrupts of Timer0 Bits0:1*/
	TCCR0 = 0;

}
