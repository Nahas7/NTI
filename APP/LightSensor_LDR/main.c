/*
 * main.c
 *
 * Created: 6/17/2023 9:55:50 PM
 *  Author: user
 */ 

#include <xc.h>

#include "STD_TYPES.h"

#define F_CPU 16000000
#include <util/delay.h>


#include "DIO_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"

int main(void)
{
	u16 Local_u16ReadingLDR ;
	
	/*initialization to ADC*/
	ADC_vidInit();
	ADC_vidEnable();
	
	/*Welcome Screen for half second*/
	CLCD_vidInitCLCD();
	CLCD_vidGotoXY(1,5);
	u8 Local_u8Welcome[8]="Welcome";
	CLCD_vidWriteString(Local_u8Welcome);
	_delay_ms(1000);
	CLCD_vidSendCommand(0x01);
		
	
	
    while(1)
    {
		
        Local_u16ReadingLDR = ADC_u8ReadChannel(ADC_u8_ADC_CHANNEL_0);
		Local_u16ReadingLDR = (Local_u16ReadingLDR * 5000UL)/1024;
		/*Brightness on LCD*/
		_delay_ms(500);
		CLCD_vidSendCommand(0x01);
		CLCD_vidGotoXY(0,0);
		u8 Local_u8Bright[16]="Brightness is :";
		CLCD_vidWriteString(Local_u8Bright);
		CLCD_vidGotoXY(1,0);
		CLCD_vidWriteNumber(Local_u16ReadingLDR);
		
		if(Local_u16ReadingLDR > 1000)
		{
			/*Hamoksha Sleep*/
			LCD_vidWriteExtraChar(1,7);
			CLCD_vidSendData(0);			
		}
		else
		{
			/*Hamoksha wakeUp*/
			LCD_vidWriteExtraChar(1,7);
			CLCD_vidSendData(1);	
		}	
    }
}