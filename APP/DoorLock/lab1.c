/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: KeyPad												  */
/*								 Layer  : HAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "lab.h"

#include "DIO_interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "SSD_interface.h"

void Password_vidFunc(void)
{
	u8 tries = 0;
	u8 Local_u8Entry[11] = "Enter Pass" ;
	u8 Index = 0;
	u8 Local_u8Key = 0xFF ;
	u16 PassUser = 0;
	
	DIO_u8SetPinDirection(DIO_PORTC , DIO_PIN6 , DIOI_OUTPUT);

	while( tries <3 && PassUser != PASSWORD)
	{
		CLCD_vidWriteString(Local_u8Entry);
		CLCD_vidGotoXY(1,0);
		
		for(Index =0 ;Index<4;Index++)
		{
			do
			{
				Local_u8Key = KPD_u8GetButtonPressed() ;
			} while (Local_u8Key == 0xFF);
			CLCD_vidSendData('*');
			PassUser = (PassUser*10)+Local_u8Key ;
		}
		tries++ ;
		CLCD_vidSendCommand(0x01);
	}
	
	if(PassUser == PASSWORD)
	{
		CLCD_vidSendCommand(0x01);
		CLCD_vidGotoXY(0,5);
		u8 hello[6]="hello";
		CLCD_vidWriteString(hello);
	}
	else if (tries>=3)
	{
		CLCD_vidSendCommand(0x01);
		CLCD_vidGotoXY(0,4);
		u8 wrong[7]="Wrong!";
		CLCD_vidWriteString(wrong);
		DIO_u8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_HIGH);
	}

}

