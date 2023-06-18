/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: LCD													  */
/*								 Layer  : HAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H



#include "STD_TYPES.h"
#include "BIT_MATH.h"


void CLCD_vidSendCommand(u8 Copy_u8Data);

void CLCD_vidSendData(u8 Copy_u8Data);

void CLCD_vidInitCLCD(void);

void CLCD_vidGotoXY(u8 Copy_u8Xpositiion , u8 Copy_u8YPosition);

void CLCD_vidWriteNumber(u32 Copy_u32Number);

void CLCD_vidWriteString (u8* pu8StringCpy);

#endif