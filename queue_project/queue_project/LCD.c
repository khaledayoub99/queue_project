/*
 * LCD.c
 *
 * Created: 12/14/2021 2:15:13 PM
 *  Author: khaled
 */ 

#include "LCD.h"

void LCD_INIT(void){
	
	#if LCD_Mode == 8
	
	DIO_SetPinDir(LCD_8BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
	DIO_SetPortDir(LCD_8BIT_Data_PORT,DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	LCD_Write_CMND(0X38);
	LCD_Write_CMND(0X0E);
	LCD_Write_CMND(0X01);
	_delay_ms(20);
	LCD_Write_CMND(0X06);
	_delay_ms(5);
	
	#elif LCD_Mode == 4
	
	DIO_SetPinDir(LCD_4BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_Data_PORT,LCD_DATA_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_Data_PORT,LCD_DATA_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_Data_PORT,LCD_DATA_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_Data_PORT,LCD_DATA_PIN7,DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	
	LCD_Write_CMND(0X33);
	LCD_Write_CMND(0X32);
	LCD_Write_CMND(0X28);
	
	LCD_Write_CMND(0X0C);
	LCD_Write_CMND(0X01);
	_delay_ms(20);
	LCD_Write_CMND(0X06);
	LCD_Write_CMND(0X02);
	_delay_ms(5);
	
	#endif
}

void LCD_Write_CMND(uint8 cmd){
	
	#if LCD_Mode == 8
	
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	DIO_WritePort(LCD_8BIT_Data_PORT,cmd);
	
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	_delay_ms(5);
	
	
	#elif LCD_Mode == 4
	
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	PORTA =  ( cmd & 0XF0 ) |( PORTA & 0X0F ) ;
	
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	PORTA =   (   cmd <<4  ) |( PORTA & 0X0F ) ;
	
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#endif
	
}

void LCD_Write_Char(uint8 data){
	
	#if LCD_Mode == 8
	
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	DIO_WritePort(LCD_8BIT_Data_PORT,data);
	
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	_delay_ms(5);
	
	
	#elif LCD_Mode == 4
	
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	PORTA =  ( data & 0XF0 )|( PORTA & 0X0F )  ;
	
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	PORTA =  ( data <<4 ) | ( PORTA & 0X0F )  ;
	
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#endif
}

void LCD_Write_String(uint8 *data){
	uint8 i =0 ;
	while(data[i] != '\0')
	{
		LCD_Write_Char(data[i]);
		i++;
	}
}

void LCD_Goto(uint8 row,uint8 col)
{
	uint8 pos[]={0X80,0XC0};
	LCD_Write_CMND(pos[row]+col);
}

void LCD_Clear(void)
{
	LCD_Write_CMND(0x01);
}

void LCD_Write_INT(int32 intgr)
{

		int32 y = 1;

		if(intgr < 0)
		{
			LCD_Write_Char('-');
			intgr *= -1;
		}

		while(intgr > 0)
		{
			y = ((y*10) + (intgr%10));
			intgr /= 10;
		}

		while( y > 1 )
		{
			LCD_Write_Char(((y%10)+48));
			y /= 10;
		}

}