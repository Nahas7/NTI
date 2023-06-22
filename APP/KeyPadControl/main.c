/*
 * main.c
 *
 * Created: 6/11/2023 8:31:41 PM
 *  Author: user
 */ 

#include <xc.h>
#define F_CPU	16000000UL

#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "lab.h"
#include "SSD_interface.h"
int main(void)
{		
	KPD_vidInit();
	
	
	/**************************************************************************/
	
	
	
	while(1)
    {
		SSD_vidFunc();
		
	/**************************************************************************/

 	}
		
		
}