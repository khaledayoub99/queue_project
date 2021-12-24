/*
 * KayPad.c
 *
 * Created: 12/14/2021 6:16:17 PM
 *  Author: khaled
 */ 

#include "KayPad.h"
#define F_CPU 16000000
#include <util/delay.h>

const uint8 KeyPad_Val[4][4]={{ 1 , 4 , 7 ,'*'},
							  { 2 , 5 , 8 , 0 },
							  { 3 , 6 , 9 ,'/'},
							  {'M',' ','-','D'}};
void KayPad_Init(void)
{
	
	DIO_SetPinDir(	KAYPAD_PORT	,	KayPad_Colum0	,	 DIO_PIN_OUTPUT	);
	DIO_SetPinDir(	KAYPAD_PORT	,	KayPad_Colum1	,	 DIO_PIN_OUTPUT	);
	DIO_SetPinDir(	KAYPAD_PORT	,	KayPad_Colum2	,	 DIO_PIN_OUTPUT	);
	DIO_SetPinDir(	KAYPAD_PORT	,	KayPad_Colum3	,	 DIO_PIN_OUTPUT	);
	
	DIO_SetPinDir(	KAYPAD_PORT	,	KayPad_Row0	,	 DIO_PIN_INPUT		);
	DIO_SetPinDir(	KAYPAD_PORT	,	KayPad_Row1	,	 DIO_PIN_INPUT		);
	DIO_SetPinDir(	KAYPAD_PORT	,	KayPad_Row2	,	 DIO_PIN_INPUT		);
	DIO_SetPinDir(	KAYPAD_PORT	,	KayPad_Row3	,	 DIO_PIN_INPUT		);
	
	DIO_SetPullUp(	KAYPAD_PORT		,		KayPad_Row0		);
	DIO_SetPullUp(	KAYPAD_PORT		,		KayPad_Row1		);
	DIO_SetPullUp(	KAYPAD_PORT		,		KayPad_Row2		);
	DIO_SetPullUp(	KAYPAD_PORT		,		KayPad_Row3		);
	
	DIO_WritePin(	KAYPAD_PORT	,	KayPad_Colum0	,	 DIO_PIN_HIGH	);
	DIO_WritePin(	KAYPAD_PORT	,	KayPad_Colum1	,	 DIO_PIN_HIGH	);
	DIO_WritePin(	KAYPAD_PORT	,	KayPad_Colum2	,	 DIO_PIN_HIGH	);
	DIO_WritePin(	KAYPAD_PORT	,	KayPad_Colum3	,	 DIO_PIN_HIGH	);
	
	
	
}

uint8 KayPad_GetVal(void)
{
	uint8 Loc_Col =  0  ;
	uint8 Loc_row =  0  ;
	uint8 val	  = 'E' ;
	uint8 temp    =  0  ;
	
	for (	Loc_Col = COL_INIT	;	Loc_Col<=COL_Final	;	Loc_Col++	)
	{
		
		DIO_WritePin(	KAYPAD_PORT	,	Loc_Col		,	 DIO_PIN_LOW	);
		
		
		for (	Loc_row = Row_INIT	;	Loc_row <= Row_Final	;	Loc_row++	)
		{
			DIO_ReadPin(	KAYPAD_PORT	,	Loc_row	,	&temp	);
			if(	temp == 0 )
			{
				
				val = KeyPad_Val[Loc_row-Row_INIT][Loc_Col-COL_INIT];
				while( temp == 0 )
				{
					DIO_ReadPin(	KAYPAD_PORT	,	Loc_row	,	&temp	);
				}
				_delay_ms(10);
			}
		}
		DIO_WritePin(	KAYPAD_PORT	,	Loc_Col		,	 DIO_PIN_HIGH	);
	}
	return val;
}