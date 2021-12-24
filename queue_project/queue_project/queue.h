/*
 * queue.h
 *
 * Created: 12/16/2021 2:15:08 PM
 *  Author: khaled
 */ 


#ifndef QUEUE_H_
#define QUEUE_H_

#include "STD.h"

uint8 Deterministic (float arr_rate, float ser_rate,uint8 init_cus,uint8 k,uint8 time,uint8 num_cus,uint8* nt);

void M_M_1 (float arr_rate, float ser_rate,uint8* res);

void M_M_1_K (float arr_rate, float ser_rate,uint8 K,uint8* res);


#endif /* QUEUE_H_ */