/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: AVOMETER												  */
/*								 Layer  : APP													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "DIO_interface.h"
#include "ADC_interface.h"

#include "CLCD_interface.h"
#include "KPD_interface.h"

void AVO_vidInit(void)
{
	ADC_vidInit();
	ADC_vidEnable();
	
	CLCD_vidInitCLCD();
	KPD_vidInit();
	
	u8 Selection[15]="Select system";
	u8 Volt[10]= "1-Volt";
	u8 Ohm[10] = "2-ohm";
	
	/*First choose your system ( VOLTMETER - OHMETER ) */
	CLCD_vidWriteString(Selection);
	CLCD_vidGotoXY(1,0);
	CLCD_vidWriteString(Volt);
	CLCD_vidGotoXY(2,0);
	CLCD_vidWriteString(Ohm);
}


void AVO_vidRun(void)
{
	u8 VoltString[20]="Volt is in mv";
	u8 OhmString[20]="Ohm is in Ohm";
	u16 Voltage = 0 ;
	u16 Ohm = 0;
	u8 Local_u8Reading = 0xFF;
	do 
	{
		Local_u8Reading = KPD_u8GetButtonPressed();
	} while (Local_u8Reading == 0xFF);
	
	switch(Local_u8Reading)
	{
		
		/*Voltage range from 0 to 5000 mV */
		case 1 : CLCD_vidSendCommand(0x01);
				 while(1)
				 {
					Voltage = ADC_u8ReadChannel(ADC_u8_ADC_CHANNEL_0);
					Voltage = (Voltage * 5000UL)/1023;
					_delay_ms(2500);
					CLCD_vidSendCommand(0x01);
					CLCD_vidGotoXY(0,0);
					CLCD_vidWriteString(VoltString);
					CLCD_vidGotoXY(1,0);
					CLCD_vidWriteNumber(Voltage);

				 }
					break;
		/*Resistance range from 0 to 10000 ohm where sink current =40 mA*/		 
		case 2 : CLCD_vidSendCommand(0x01);
				while(1)
				{
					Ohm = ADC_u8ReadChannel(ADC_u8_ADC_CHANNEL_0);
					Ohm = (Ohm * 5000UL)/1023;
					Ohm /= 40;
					_delay_ms(2500);
					CLCD_vidSendCommand(0x01);
					CLCD_vidGotoXY(0,0);
					CLCD_vidWriteString(OhmString);
					CLCD_vidGotoXY(1,0);
					CLCD_vidWriteNumber(Ohm);
				}
					break;
				 
		default : break;	
	}
	
}
