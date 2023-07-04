/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: DIO													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef DIO_INTERFAC_H
#define DIO_INTERFAC_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


/*PORTS*/
#define DIO_PORTA		1
#define DIO_PORTB		2
#define DIO_PORTC		3
#define DIO_PORTD		4


/*PINS*/
#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7


/*DIRECTIONS*/
#define DIO_INPUT 		0
#define DIOI_OUTPUT		1


/*LEVELS*/
#define DIO_HIGH		1
#define DIO_LOW			0



u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction) ;

u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value) ;

u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction) ;

u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value) ;

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_u8Result);

u8 DIO_u8GetPortValue(u8 Copy_u8Port , u8* Copy_u8Result);

#endif