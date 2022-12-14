/******************************************************************************
 *
 * Module: Timer atmega32
 *
 * File Name: timer0.h
 *
 * Description: Header file for timer0 in AVR driver
 *
 *******************************************************************************/

#ifndef TIMER0_H_
#define TIMER0_H_



/*Description:
 * initializing timer0 in overflow mode with 1024 pre-scaler
 * */
void Timer0_init(void);

/*Description:
 * set the function to be called when an interrupt occurs
 */
void Timer0_setCallBack(void(*a_ptr)(void));

/*Description:
 * Stop timer
 */
void Timer0_DeInit(void);


#endif /* TIMER0_H_ */
