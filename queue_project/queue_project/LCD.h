/*
 * LCD.h
 *
 * Created: 12/14/2021 1:46:10 PM
 *  Author: khaled
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CFG.h"
#define F_CPU 16000000
#include <util/delay.h>

void LCD_INIT(void);

void LCD_Write_CMND(uint8 cmd);

void LCD_Write_Char(uint8 data);

void LCD_Write_String(uint8 *data);

void LCD_Goto(uint8 row,uint8 col);

void LCD_Clear(void);

void LCD_Write_INT(int32 intgr);



#endif /* LCD_H_ */