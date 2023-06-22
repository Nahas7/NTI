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
	u16 Local_u16ReadingLM35 ;
	
	/*red led*/
	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN7 , DIOI_OUTPUT);
	
	/*green led*/
	DIO_u8SetPinDirection(DIO_PORTA , DIO_PIN4 , DIOI_OUTPUT);
	
	/*buzzer*/
	DIO_u8SetPinDirection(DIO_PORTC , DIO_PIN6 , DIOI_OUTPUT);
	
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
		
	u8 Local_u8Temp[17]="Temperature is :";
	
    while(1)
    {
		
        Local_u16ReadingLM35 = ADC_u8ReadChannel(ADC_u8_ADC_CHANNEL_1);
		Local_u16ReadingLM35 = (Local_u16ReadingLM35 * 5000UL)/1024;
		Local_u16ReadingLM35 /= 10 ;
		/*Temperature on LCD*/
		_delay_ms(500);
		CLCD_vidSendCommand(0x01);
		CLCD_vidGotoXY(0,0);
		CLCD_vidWriteString(Local_u8Temp);
		CLCD_vidGotoXY(1,0);
		CLCD_vidWriteNumber(Local_u16ReadingLM35);
		
		if(Local_u16ReadingLM35 > 33)
		{
			/*fire alarm*/
			DIO_u8SetPinValue(DIO_PORTA , DIO_PIN4 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTB , DIO_PIN7 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_HIGH);
		}
		else
		{
			/*safe mode*/
			DIO_u8SetPinValue(DIO_PORTA , DIO_PIN4 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTB , DIO_PIN7 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_LOW);	
		}	
    }
}