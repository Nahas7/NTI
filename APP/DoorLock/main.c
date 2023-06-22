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
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "lab.h"
#include "SSD_interface.h"
int main(void)
{		
	CLCD_vidInitCLCD();
	KPD_vidInit();
	/**************************************************************************/
	/**************************************************************************/
	Password_vidFunc();
	
	while(1)
    {
		
 	}
		
}