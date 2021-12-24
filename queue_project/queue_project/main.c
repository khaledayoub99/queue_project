/*
 * queue_project.c
 *
 * Created: 12/15/2021 5:46:53 PM
 * Author : khaled
 */ 

#include "LCD.h"
#include "KayPad.h"
#include "queue.h"

int main(void)
{
    LCD_INIT();
	KayPad_Init();
	uint8 num = 'E' ;
	uint8 i = 0 ;
	uint8 kind = ' ' ;
	
	float arrival_rate = 0.0 ;
	float service_rate = 0.0 ;
	uint8 init_cus = 0 ;
	uint8 time = 0 ;
	uint8 customer = 0 ;
	uint8 nt = 0 ;
	uint8 wq = 0 ;
	uint8 capacity = 0 ;
	uint8 num_ser = 0 ;
	uint8 M_Res[4] ;
	LCD_Write_String("Queueing Theory ");
	LCD_Goto(1,0);
	LCD_Write_String("    PROJECT");
	_delay_ms(5000);
	LCD_Clear();
	LCD_Goto(0,0);
	LCD_Write_String("Kendall Notati..:");
	LCD_Goto(1,0);
	
    while (1) 
    {
					//** GET Kendall Notation **//
		while(i<7)
		{
			num=KayPad_GetVal();
			if (num != 'E')
			{
				i++;
				if (i==1)
				{
					kind = num;
				}
				if (i==5)
				{
					num_ser = num;
				}
				if (i==7)
				{
					capacity = num + 1;
				}
				if (num>=0&&num<10)
				{
					num = num + 48 ;
				}
				LCD_Write_Char(num);
			}
			if (i == 7)
			{
				_delay_ms(2000);
				LCD_Clear();
				LCD_Goto(0,0);
				LCD_Write_String("arrival rate:");
			}
					
		}
					//**  GET arrival rate	**//
		while(num != '*' )
		{
			num=KayPad_GetVal();
			if (num != 'E')
			{
				if (num != '*' && num != '/')
				{
					arrival_rate = (arrival_rate*10) + (float) num ;
					LCD_Write_Char(num+48);
				}
				if (num == '/')
				{
					LCD_Write_Char(num);
					while(1)
					{
						num=KayPad_GetVal();
						if (num != 'E')
						{
							LCD_Write_Char(num+48);
							arrival_rate = arrival_rate / (float) num ;
							break;
						}	
					}
				}
			}
			//_delay_ms(2000);
			if (num == '*')
			{
			LCD_Goto(1,0);
			LCD_Write_String("service rate:");
			}
		}
		
		num ='E';
		
					//**  GET Service Rate	**//
		while(num != '*' )
		{
			num=KayPad_GetVal();
			if (num != 'E')
			{
				if (num != '*' && num != '/')
				{
					service_rate =service_rate*10 + (float) num ;
					LCD_Write_Char(num+48);
				}
				if (num == '/')
				{
					LCD_Write_Char(num);
					while(1)
					{
						num=KayPad_GetVal();
						if (num != 'E')
						{
							LCD_Write_Char(num+48);
							service_rate = service_rate / (float) num ;
							break;
						}
					}
				}
			}
			if (num == '*' && kind == 'D')
			{
				LCD_Clear();
				LCD_Goto(0,0);
				LCD_Write_String("TIME:");
			}
			
		}
		
		num ='E';
				
					//**  GET TIME	**//
					
		while(num != '*' && kind == 'D')
		{
			num=KayPad_GetVal();
			if (num != 'E' && num != '*')
			{
				
					time =time*10 + num ;
					LCD_Write_Char(num+48);
				
			}
		
			if (num == '*')
			{
				LCD_Goto(1,0);
				LCD_Write_String("customer:");
			}
		}
		
		
		num='E';
					//**  GET Num of customer	**//
		while(num != '*' && kind == 'D')
		{
			num=KayPad_GetVal();
			if (num != 'E' && num != '*')
			{
				
				customer =customer*10 + num ;
				LCD_Write_Char(num+48);
				
				
			}
			
			if (num == '*')
			{
				LCD_Clear();
			}
		}
		
		num='E';
		
						//**  GET inital customer	**//
		if (arrival_rate<=service_rate && kind == 'D' )
		{
			LCD_Clear();
			LCD_Goto(0,0);
			LCD_Write_String("init cust:");
			while(num != '*')
			{
				
				num=KayPad_GetVal();
				
				if (num != 'E' && num != '*')
				{
					
					init_cus =init_cus*10 + num ;
					LCD_Write_Char(num+48);
					
				}
				
				if (num == '*')
				{
					LCD_Clear();
				}
			}
		}
		
		
		switch (kind)
		{
			case  'D':
			wq = Deterministic (arrival_rate, service_rate,init_cus,capacity,time,customer,&nt);
			LCD_Clear();
			LCD_Goto(0,0);
			if (nt == '&')
			{
				if(arrival_rate>service_rate)
				{
					LCD_Write_String("n(t):");
					LCD_Write_Char(capacity - 1 + 48);
					LCD_Write_String(" or ");
					LCD_Write_Char(capacity - 2 + 48);
				}
				else
				{
					
					LCD_Write_String("n(t):");
					LCD_Write_Char('0');
					LCD_Write_String(" or ");
					LCD_Write_Char('1');
				}
			}
			
			else
			{
				
				LCD_Write_String("n(t):");
				LCD_Write_Char(nt+48);
			}
			
			
			if (wq == '&')
			{
				LCD_Goto(1,0);
				LCD_Write_String("wq(n):");
				LCD_Write_INT(wq);
			}
			else{
				LCD_Goto(1,0);
				LCD_Write_String("wq(n):");
				if (wq == 0)
				{
					LCD_Write_Char('0');
				}
				if (wq!=0)
				{
					LCD_Write_INT(wq);
				}
				
			}
			
			break;
			
			case 'M':
			
			if (capacity ='-' && num_ser==1)
			{
				M_M_1 (arrival_rate, service_rate,&M_Res[0]);
				LCD_Clear();
				LCD_Goto(0,0);
				LCD_Write_String("L:");
				LCD_Write_INT(M_Res[0]);
				LCD_Write_String(" , Lq:");
				LCD_Write_INT(M_Res[1]);
				LCD_Goto(1,0);
				LCD_Write_String("W:");
				LCD_Write_INT(M_Res[2]);
				LCD_Write_String("  , Wq:");
				LCD_Write_INT(M_Res[3]);
			}
			else if(capacity !='-' && num_ser==1)
			{
				M_M_1_K (arrival_rate, service_rate,capacity,&M_Res[0]);
		
			}
			
			break;
			
			default:
			break;
		}
	
		
		
	while(1){}
		
    }		//while(1)
}			//Main





