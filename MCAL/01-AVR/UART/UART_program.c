/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: UART 													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_private.h"
#include "UART_interface.h"
#include "UART_config.h"

void UART_vidInit(void)
{
	u8 Local_u8UART_UCSRC ;
	
	/********  set configuration of the frame  *********/
	/*Enable URSEL*/
	SET_BIT(Local_u8UART_UCSRC , 7);
	
	/*Select mode Asynchrouns*/
	CLR_BIT(Local_u8UART_UCSRC , 6);
	
	/*Disable parity bit*/
	CLR_BIT(Local_u8UART_UCSRC , 5);
	CLR_BIT(Local_u8UART_UCSRC , 4);
	
	/*Set stop bit (1-bit)*/
	CLR_BIT(Local_u8UART_UCSRC , 3);
	
	/*Select bits as 8 bits*/
	SET_BIT(Local_u8UART_UCSRC , 2);
	SET_BIT(Local_u8UART_UCSRC , 1);
	
	UCSRC = Local_u8UART_UCSRC ;
	
	/********  set baud rate  *********/
	/*set baud rate as 9600 bps/16MHZ*/
	UBRRL = 130;
	
	/******** Enable TX & RX *********/
	UCSRB = 0x18;
}

void UART_vidSendChar(u8 Copy_u8data)
{
	while ((UCSRA & 0x20) == 0);
	UDR_T = data ;
}

u8 UART_u8GetChar(void)
{
	u8 Local_u8Result;
	
	while((UCSRA & 0x80) == 0);
	
	Local_u8Result = UDR_R ;
	
	/*Clear the flag*/
	SET_BIT(UCSRA , 7);

	return Local_u8Result ;
}

void UART_vidSendString(u8 *Copy_u8data)
{
	u8 Local_u8Counter = 0;
	
	while(Copy_u8data[Local_u8Counter] != '\0')
	{
			UART_vidSendChar(Copy_u8data[Local_u8Counter]);
			Local_u8Counter++;
	}
}

void UART_vidGetString(u8 * Copy_u8data , u8 Copy_u8Size)
{
	u8 Local_u8Counter = 0;
	u8 Local_u8Index = 0;
	for ( Local_u8Counter =0 ; Local_u8Counter<Copy_u8Size ; Local_u8Counter++)
	{
		while((UCSRA & 0x80) == 0);
		Copy_u8data[Local_u8Index] = UART_u8GetChar();
		Local_u8Index++;
	}
}