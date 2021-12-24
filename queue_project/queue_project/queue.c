/*
 * queue.c
 *
 * Created: 12/16/2021 2:14:56 PM
 *  Author: khaled
 */ 

#include "queue.h"

uint8 Deterministic (float arr_rate, float ser_rate,uint8 init_cus,uint8 k,uint8 time,uint8 num_cus,uint8* nt)
{
	uint8 ti = 0 ;
	uint8 wq = 0 ;
	uint8 arr_time = 1  / arr_rate ;
	uint8 ser_time = 1  / ser_rate ;
	int compare =0 ;
	
	
	if(arr_rate>ser_rate)
	{
		ti =((k-(ser_rate/arr_rate))/(arr_rate-ser_rate));
		while(1)
		{
			ti=ti-(1/arr_rate);
			*nt=(int)(arr_rate*ti)-(int)((ser_rate*ti)-(ser_rate/arr_rate));
			if(k!=*nt)
			{
				ti=ti+(1/arr_rate);
				break;
			}
		}
									/* out N(t) */
		if(time<(1/arr_rate))
		{
			*nt = 0 ;
		}
		else if((1/arr_rate)<=(time)&&(time)<ti)
		{
			*nt=(uint8)(arr_rate*time)-(uint8)((ser_rate*time)-(ser_rate/arr_rate));
		}
		else
		{
			compare=ser_time%arr_time;
			if(compare==0)
			{
				*nt = k-1  ;
				
			}
			else
			{
				*nt = '&' ;
			}

		}
		
								/* out wq(n) */
					
		if(num_cus==0)
		{
			wq = 0 ;
			return wq ;
		}
		else if (num_cus>0 && num_cus<(arr_rate*ti))
		{
			wq = (ser_time-arr_time)*(num_cus-1);
			return wq ;
		}
		else 
		{
			wq = (ser_time-arr_time)*(arr_rate*ti-2);
			return wq ;
		}
		
		
	}
	else // ser_rate>=arr_rate
	{							/* out N(t) */
		if (arr_rate==ser_rate)
		{
			*nt = init_cus;
		}
		else
		{
			ti =init_cus/(ser_rate-arr_rate);
			while(1)
			{
				ti=ti-(1/arr_rate);
				*nt=init_cus+(int)(arr_rate*ti)-(int)(ser_rate*ti);
				if(k!=*nt)
				{
					ti=ti+(1/arr_rate);
					break;
				}
			}
			if(time<ti)
			{
				*nt = init_cus+(int)(arr_rate*time)-(int)(ser_rate*time);
			}
			else
			{
				*nt = '&' ;
			}
		}
									/* out wq(n) */
		if(num_cus==0)
		{
			wq = (init_cus - 1)/(2*ser_rate) ;
			return wq ;
		}
		
		else if(num_cus <= (arr_rate*ti))
		{
			wq = ((init_cus - 1 + num_cus)*(ser_time))-(num_cus*(arr_time)) ;
			return wq ;
		}
		else
		{
			wq = 0 ;
			return wq ;
		}
		
	}

	
	return 0 ;						
	 
}

void M_M_1 (float arr_rate, float ser_rate,uint8* Res)
{
	uint8 L , Lq, W, Wq ;
	L  =  arr_rate /(ser_rate-arr_rate) ;
	Lq =  (arr_rate*arr_rate) / ((ser_rate-arr_rate)*ser_rate) ; ;
	W  =(1/((ser_rate)-(arr_rate)))*60;
	Wq =(arr_rate/((ser_rate)*((ser_rate)-(arr_rate))))*60 ;
	Res[0]= L ;
	Res[1]= Lq ;
	Res[2]= W ;
	Res[3]= Wq ;
}

void M_M_1_K (float arr_rate, float ser_rate,uint8 K,uint8* res)
{
	
}