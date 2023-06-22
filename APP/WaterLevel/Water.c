/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: WaterSensor											  */
/*								 Layer  : App													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "CLCD_interface.h"

#include <util/delay.h>


void WaterSen_vidInit(void)
{
	ADC_vidInit();
	ADC_vidEnable();
	CLCD_vidInitCLCD();	
	
	DIO_u8SetPinDirection(DIO_PORTC , DIO_PIN6 , DIOI_OUTPUT);
}



void WaterSen_vidRun(void)
{
	u16 Local_u8Reading ;
	u8 WaterLevel[16]="Water level is ";
	u8 NO_WATER[9]="No water";
	
	while(1)
	{
		Local_u8Reading = ADC_u8ReadChannel(ADC_u8_ADC_CHANNEL_0);
		Local_u8Reading=(Local_u8Reading*5000UL)/1023;
		_delay_ms(1000);
		
		if (Local_u8Reading <= 3000 )
		{
			CLCD_vidGotoXY(0,0);
			CLCD_vidWriteString(NO_WATER);
			DIO_u8SetPortDirection(DIO_PORTC < DIO_PIN6 ,DIO_LOW);
		}
		else if (Local_u8Reading <= 4750 )
		{
			CLCD_vidGotoXY(0,0);
			CLCD_vidWriteString(WaterLevel);
			CLCD_vidSendData('1');
			DIO_u8SetPortDirection(DIO_PORTC < DIO_PIN6 ,DIO_LOW);
		}
		else if (Local_u8Reading <= 4800)
		{
			CLCD_vidGotoXY(0,0);
			CLCD_vidWriteString(WaterLevel);
			CLCD_vidSendData('2');
			DIO_u8SetPortDirection(DIO_PORTC < DIO_PIN6 ,DIO_LOW);
		}
		else if (Local_u8Reading <= 4900)
		{
			CLCD_vidGotoXY(0,0);
			CLCD_vidWriteString(WaterLevel);
			CLCD_vidSendData('4');
			DIO_u8SetPortDirection(DIO_PORTC < DIO_PIN6 ,DIO_LOW);
		}
		else if (Local_u8Reading <= 4950)
		{
			CLCD_vidGotoXY(0,0);
			CLCD_vidWriteString(WaterLevel);
			CLCD_vidSendData('5');
			DIO_u8SetPortDirection(DIO_PORTC < DIO_PIN6 ,DIO_HIGH);
		}
	}
	
}