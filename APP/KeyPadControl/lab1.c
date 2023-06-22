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
#include "SSD_interface.h"



void SSD_vidFunc(void)
{
	u8 Local_u8KeyPressed ;
	
	/*Indecies*/
	static u8 Local_u8OnesIndex = 0 ;
	static u8 Local_u8TensIndex = 0 ;
	
	/*Declare SSD*/
	SSD_t_decoder SSD1 = {DIO_PORTB , {DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN4} , SSD_COM_CATHODE , DIO_PORTA , DIO_PIN3};
	SSD_t_decoder SSD2 = {DIO_PORTB , {DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN4} , SSD_COM_CATHODE , DIO_PORTA , DIO_PIN2};
		
	/*Initialization */
	DIO_u8SetPinDirection(LED_PORT , LED_PIN , DIOI_OUTPUT);
	DIO_u8SetPinDirection(BUZZ_PORT , BUZZ_PIN , DIOI_OUTPUT);
	SSD_vidInitSSDDecoder(&SSD1);
	SSD_vidInitSSDDecoder(&SSD2);
	KPD_vidInit();
	
	/*Flags*/
	static u8 Local_u8LedFlag = 0;
	static u8 Local_u8BuzzFlag =0;
	
	/********************* implementation	*************************/
	/*Get the Pressed Key*/
	do{
		SSD_vidDisplaySSDDecoder(&SSD1 , Local_u8OnesIndex ) ;
		SSD_vidDisableSSDDecoder(&SSD2);
		_delay_ms(5);
		SSD_vidDisplaySSDDecoder(&SSD2 , Local_u8TensIndex ) ;
		SSD_vidDisableSSDDecoder(&SSD1);
		_delay_ms(5);
		Local_u8KeyPressed = KPD_u8GetButtonPressed();
		}while(Local_u8KeyPressed == 0xFF);
		
	switch(Local_u8KeyPressed)
	{
		case 1 : if(Local_u8LedFlag == 0)
		 			{
		 				DIO_u8SetPinValue(LED_PORT , LED_PIN , DIO_HIGH);
		 				Local_u8LedFlag = 1;
		
		 			}
		 			else if(Local_u8LedFlag == 1)
		 			{
		 				DIO_u8SetPinValue(LED_PORT , LED_PIN , DIO_LOW);
		 				Local_u8LedFlag = 0;
		
		 			}
		 			break ;
		
		
		 			case 2 : if(Local_u8BuzzFlag == 0)
		 			{
		 				DIO_u8SetPinValue(BUZZ_PORT , BUZZ_PIN , DIO_HIGH);
		 				Local_u8BuzzFlag = 1;
		 			}
		 			else if(Local_u8BuzzFlag == 1)
		 			{
		 				DIO_u8SetPinValue(BUZZ_PORT , BUZZ_PIN , DIO_LOW);
		 				Local_u8BuzzFlag = 0;
		
		 			}
		 			break ;
		
		 			case 3 : if(Local_u8OnesIndex < 9)
		 			{
		 				Local_u8OnesIndex++;
		 			}
		 			else if(Local_u8OnesIndex == 9)
		 			{
		 				Local_u8OnesIndex = 0 ;
		 				Local_u8TensIndex++;
		 			}
		 			if(Local_u8TensIndex > 9)
		 			{
		 				Local_u8OnesIndex = 0;
		 				Local_u8TensIndex = 0;
		 			}
		 			break;
		
		 			case 4 : if(Local_u8OnesIndex > 0 )
		 			{
		 				Local_u8OnesIndex--;
		 			}
		 			else if(Local_u8OnesIndex <= 0)
		 			{
		 				Local_u8OnesIndex = 9 ;
		 				Local_u8TensIndex--;
		 			}
		 			if(Local_u8TensIndex == -1 && Local_u8OnesIndex == 9 )
		 			{
		 				Local_u8OnesIndex=9;
		 				Local_u8TensIndex=9;
		 			}
		 			break;
					 
			default: break;
	}

}
	