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




void Timer0_init(void);

void Timer0_setCallBack(void(*a_ptr)(void));

void Timer0_DeInit(void);


#endif /* TIMER0_H_ */
