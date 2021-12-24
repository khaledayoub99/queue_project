/*
 * KayPad_CFG.h
 *
 * Created: 12/14/2021 6:16:52 PM
 *  Author: khaled
 */ 


#ifndef KAYPAD_CFG_H_
#define KAYPAD_CFG_H_

#include "DIO.h"

#define		KAYPAD_PORT			 DIO_PORTD

#define		KayPad_Colum0		 DIO_PIN0	
#define		KayPad_Colum1		 DIO_PIN1	
#define		KayPad_Colum2		 DIO_PIN2	
#define		KayPad_Colum3		 DIO_PIN3

	
#define		KayPad_Row0			 DIO_PIN4
#define		KayPad_Row1			 DIO_PIN5
#define		KayPad_Row2			 DIO_PIN6
#define		KayPad_Row3			 DIO_PIN7

#define COL_INIT		0
#define COL_Final		3

#define Row_INIT		4
#define Row_Final		7

#define Not_Pressed		0


#endif /* KAYPAD_CFG_H_ */