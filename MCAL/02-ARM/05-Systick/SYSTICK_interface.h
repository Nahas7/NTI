/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: SYSTICK												  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

#include "STD_TYPES.h"

void STK_vidInit(void);

void STK_vidBusyWaiting(u32 Copy_u32Ticks);

void STK_vidSingleInterval(u32 Copy_u32Ticks , void(*ptr)(void));

void STK_vidPeriodicInterval(u32 Copy_u32Ticks , void(*ptr)(void));

void STK-vidStopTimer(void);

/*	Get remaining time*/

/*	Get elapsed time  */

/**/












#endif