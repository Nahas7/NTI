/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: NVIC													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"

void NVIC_vidInit(void);

void NVIC_vidSetInterruptPeri(u8 Copy_u8INTId , u8 Copy_u8Periority );

void NVIC_vidEnablePer(u8 Copy_u8PerId);

void NVIC_vidDisablePer(u8 Copy_u8PerId);

void NVIC_vidSetPendingFlag(u8 Copy_u8PerId);

void NVIC_vidClrPendingFlag(u8 Copy_u8PerId);

u8 NVIC_u8GetActiveFlag(u8 Copy_u8PerId);

#endif