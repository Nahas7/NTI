/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: LCD													  */
/*								 Layer  : HAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef CLCD_CONFIG_H
#define CLCD_CONFIG_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**************************************/
/*			DATA PINS				  */
#define CLCD_DATA7_PORT			DIO_PORTB
#define CLCD_DATA7_PIN			DIO_PIN4		

		
#define CLCD_DATA6_PORT			DIO_PORTB
#define CLCD_DATA6_PIN			DIO_PIN2		
		
#define CLCD_DATA5_PORT			DIO_PORTB		
#define CLCD_DATA5_PIN			DIO_PIN1		

#define CLCD_DATA4_PORT			DIO_PORTB		
#define CLCD_DATA4_PIN			DIO_PIN0		




/**************************************/
/*			CTRL PINS				  */
#define CLCD_RS_PORT			DIO_PORTA
#define CLCD_RS_PIN				DIO_PIN3
/*
#define CLCD_RW_PORT			DIO_PIN6
#define CLCD_RW_PIN				DIO_PIN6
*/
#define CLCD_ENABLE_PORT		DIO_PORTA
#define CLCD_ENABLE_PIN			DIO_PIN2


#endif