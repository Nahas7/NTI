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

#include "DIO_interface.h"

#include <util/delay.h>
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

void KPD_vidInit(void)
{
	u8 Local_u8Index = 0;
	for(Local_u8Index = 0 ;Local_u8Index<4 ;Local_u8Index++)
	{
			DIO_u8SetPinDirection(Col_ports[Local_u8Index],Col_Pins[Local_u8Index],DIOI_OUTPUT);
			DIO_u8SetPinValue(Col_ports[Local_u8Index],Col_Pins[Local_u8Index],DIO_HIGH);
			
			DIO_u8SetPinDirection(Row_ports[Local_u8Index],Row_Pins[Local_u8Index],DIO_INPUT);
			DIO_u8SetPinValue(Row_ports[Local_u8Index],Row_Pins[Local_u8Index],DIO_HIGH);
	}
	
}



u8 KPD_u8GetButtonPressed(void)
{
	u8 Local_u8PinState ;
	u8 Local_u8KeyPressed = KPD_NO_PRESSED_KEY ;
	u8 Local_u8CoulmnIndex , Local_u8RowIndex; 
	static u8 Local_u8KPDArr[4][4] = KPD_ARR_VAL ;


	for (Local_u8CoulmnIndex = 0 ; Local_u8CoulmnIndex < COULM_NUM ; Local_u8CoulmnIndex++ )
	{
			/*Activate current column*/
			DIO_u8SetPinValue(Col_ports[Local_u8CoulmnIndex] , Col_Pins[Local_u8CoulmnIndex] , DIO_LOW);
			for(Local_u8RowIndex = 0;Local_u8RowIndex<ROW_NUM ; Local_u8RowIndex++)
			{
				/*Get Pin Value of each row pin*/
				 DIO_u8GetPinValue(Row_ports[Local_u8RowIndex],Row_Pins[Local_u8RowIndex] , &Local_u8PinState);
				/*check if low , so this key is pressed*/
				if (Local_u8PinState == DIO_LOW)
				{
					DIO_u8GetPinValue(Row_ports[Local_u8RowIndex],Row_Pins[Local_u8RowIndex] , &Local_u8PinState);
					while(Local_u8PinState == DIO_LOW)
					{
						DIO_u8GetPinValue(Row_ports[Local_u8RowIndex],Row_Pins[Local_u8RowIndex] , &Local_u8PinState);
					}
					Local_u8KeyPressed = Local_u8KPDArr[Local_u8RowIndex][Local_u8CoulmnIndex];
					return Local_u8KeyPressed ;
				}
			}
			/*deactivate the current column*/
			DIO_u8SetPinValue(Col_ports[Local_u8CoulmnIndex] , Col_Pins[Local_u8CoulmnIndex] , DIO_HIGH);
	}
	return Local_u8KeyPressed ;
}