/*
 * ATmega32_Registers.h
 *
 * Created: 12/11/2021 7:04:18 PM
 *  Author: khaled
 */ 


#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

#include "STD.h"

						/***********************DIO_REGISTER*******************/
						
#define DDRA  (*(volatile uint8*)(0X3A))
#define PORTA (*(volatile uint8*)(0X3B))
#define PINA  (*(volatile uint8*)(0X39))

#define DDRB  (*(volatile uint8*)(0X37))
#define PORTB (*(volatile uint8*)(0X38))
#define PINB  (*(volatile uint8*)(0X36))

#define DDRC  (*(volatile uint8*)(0X34))
#define PORTC (*(volatile uint8*)(0X35))
#define PINC  (*(volatile uint8*)(0X33))

#define DDRD  (*(volatile uint8*)(0X31))
#define PORTD (*(volatile uint8*)(0X32))
#define PIND  (*(volatile uint8*)(0X30))



#endif /* ATMEGA32_REGISTERS_H_ */