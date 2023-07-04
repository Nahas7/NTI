/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: DIO													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"



u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction) 
{
	u8 Local_u8ErrorStatus = 0 ;
	
	/*if the parameter passed is in the valid range*/
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=7)
	{
		/*if the pin is selected as output*/
		if (Copy_u8Direction == DIOI_OUTPUT)
		{
			switch(Copy_u8Port)
			{
				case DIO_PORTA : SET_BIT(DDRA , Copy_u8Pin);	break;		/*set the disered pin of port A*/
				case DIO_PORTB : SET_BIT(DDRB , Copy_u8Pin);	break;		/*set the disered pin of port B*/		
				case DIO_PORTC : SET_BIT(DDRC , Copy_u8Pin);	break;      /*set the disered pin of port C*/
				case DIO_PORTD : SET_BIT(DDRD , Copy_u8Pin);	break;      /*set the disered pin of port D*/
				default 	   : Local_u8ErrorStatus = 1 ;		break;      /*the port parameter is invalid*/
			}
		}
		/*if the pin is selected as input*/
		else if (Copy_u8Direction == DIO_INPUT)
		{
			switch(Copy_u8Port)
			{                                                               /*Clear the disered pin of port A*/
				case DIO_PORTA : CLR_BIT(DDRA , Copy_u8Pin);	break;      /*Clear the disered pin of port B*/
				case DIO_PORTB : CLR_BIT(DDRB , Copy_u8Pin);	break;		/*Clear the disered pin of port C*/		
				case DIO_PORTC : CLR_BIT(DDRC , Copy_u8Pin);	break;      /*Clear the disered pin of port D*/
				case DIO_PORTD : CLR_BIT(DDRD , Copy_u8Pin);	break;      /*the port parameter is invalid*/
				default 	   : Local_u8ErrorStatus = 1 ; 		break;
			}
		}
		/*if the parameter invalid*/
		else
		{
				Local_u8ErrorStatus = 1 ;
		}
	}
	/*if the parameter invalid*/
	else
	{
		Local_u8ErrorStatus = 1 ;
	}
	
	return Local_u8ErrorStatus ;
}




u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value) 
{
u8 Local_u8ErrorStatus = 0 ;
	
	/*if the parameter passed is in the valid range*/
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=7)
	{
		/*if the pin is selected as high*/
		if (Copy_u8Value == DIO_HIGH)
		{
			switch(Copy_u8Port)
			{
				case DIO_PORTA : SET_BIT(PORTA , Copy_u8Pin);	break;		/*set the disered pin of port A*/
				case DIO_PORTB : SET_BIT(PORTB , Copy_u8Pin);	break;		/*set the disered pin of port B*/		
				case DIO_PORTC : SET_BIT(PORTC , Copy_u8Pin);	break;      /*set the disered pin of port C*/
				case DIO_PORTD : SET_BIT(PORTD , Copy_u8Pin);	break;      /*set the disered pin of port D*/
				default 	   : Local_u8ErrorStatus = 1 ;		break;      /*the port parameter is invalid*/
			}
		}
		/*if the pin is selected as low*/
		else if (Copy_u8Value == DIO_LOW)
		{
			switch(Copy_u8Port)
			{                                                               /*Clear the disered pin of port A*/
				case DIO_PORTA : CLR_BIT(PORTA , Copy_u8Pin);	break;      /*Clear the disered pin of port B*/
				case DIO_PORTB : CLR_BIT(PORTB , Copy_u8Pin);	break;		/*Clear the disered pin of port C*/		
				case DIO_PORTC : CLR_BIT(PORTC , Copy_u8Pin);	break;      /*Clear the disered pin of port D*/
				case DIO_PORTD : CLR_BIT(PORTD , Copy_u8Pin);	break;      /*the port parameter is invalid*/
				default 	   : Local_u8ErrorStatus = 1 ; 		break;
			}
		}
		/*if the parameter invalid*/
		else
		{
				Local_u8ErrorStatus = 1 ;
		}
	}
	/*if the parameter invalid*/
	else
	{
		Local_u8ErrorStatus = 1 ;
	}

	return Local_u8ErrorStatus ;
}





u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorStatus = 0 ;
	
	/*if the port is selected as output*/
	if (Copy_u8Direction == 0xFF)
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : DDRA = 0xFF ;				break;		/*set port A*/
			case DIO_PORTB : DDRB = 0xFF ;				break;		/*set port B*/		
			case DIO_PORTC : DDRC = 0xFF ;				break;      /*set port C*/
			case DIO_PORTD : DDRD = 0xFF ;				break;      /*set port D*/
			default 	   : Local_u8ErrorStatus = 1 ;	break;      /*the port parameter is invalid*/
		}
	}
	/*if the port is selected as input*/
	else if (Copy_u8Direction == 0x00)
	{
		switch(Copy_u8Port)
		{                                                               /*Clear port A*/
			case DIO_PORTA : DDRA = 0x00 ;					break;      /*Clear port B*/
			case DIO_PORTB : DDRB = 0x00 ;					break;		/*Clear port C*/		
			case DIO_PORTC : DDRC = 0x00 ;					break;      /*Clear port D*/
			case DIO_PORTD : DDRD = 0x00 ;					break;      /*the port parameter is invalid*/
			default 	   : Local_u8ErrorStatus = 1 ; 		break;
		}
	}
	/*if the parameter invalid*/
	else
	{
			Local_u8ErrorStatus = 1 ;
	}
	return Local_u8ErrorStatus ;
}




u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value) 
{
	u8 Local_u8ErrorStatus = 0 ;

	switch(Copy_u8Port)
		{
			case DIO_PORTA : DDRA = Copy_u8Value ;		break;		/*set the value to the port A*/
			case DIO_PORTB : DDRB = Copy_u8Value ;		break;		/*set the value to the port B*/		
			case DIO_PORTC : DDRC = Copy_u8Value ;		break;      /*set the value to the port C*/
			case DIO_PORTD : DDRD = Copy_u8Value ;		break;      /*set the value to the port D*/
			default 	   : Local_u8ErrorStatus = 1 ;	break;      /*the port parameter is invalid*/
		}
	return Local_u8ErrorStatus ;
}




u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_u8Result)
{
	u8 Local_u8ErrorStatus;
	/*if the parameter passed is in the valid range*/
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=7)
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : *Copy_u8Result = GET_BIT(PINA , Copy_u8Pin);	break;		/*read the disered pin of port A*/
			case DIO_PORTB : *Copy_u8Result = GET_BIT(PINB , Copy_u8Pin);	break;		/*read the disered pin of port B*/		
			case DIO_PORTC : *Copy_u8Result = GET_BIT(PINC , Copy_u8Pin);	break;      /*read the disered pin of port C*/
			case DIO_PORTD : *Copy_u8Result = GET_BIT(PIND , Copy_u8Pin);	break;      /*read the disered pin of port D*/
			default 	   : Local_u8ErrorStatus = 1 ;						break;      /*the port parameter is invalid*/
		}
	}
	/*if the parameter invalid*/
	else
	{
		Local_u8ErrorStatus = 1 ;
	}
	return Local_u8ErrorStatus ;
}




u8 DIO_u8GetPortValue(u8 Copy_u8Port , u8* Copy_u8Result)
{
	
	u8 Local_u8ErrorStatus = 0 ;
	
	switch(Copy_u8Port)
		{
			case DIO_PORTA : *Copy_u8Result = PINA ;	break;		/*read the value to the port A*/
			case DIO_PORTB : *Copy_u8Result = PINB ;	break;		/*read the value to the port B*/		
			case DIO_PORTC : *Copy_u8Result = PINC ;	break;      /*read the value to the port C*/
			case DIO_PORTD : *Copy_u8Result = PIND ;	break;      /*read the value to the port D*/
			default 	   : Local_u8ErrorStatus = 1 ;	break;      /*the port parameter is invalid*/
		}
	return Local_u8ErrorStatus ;
}

