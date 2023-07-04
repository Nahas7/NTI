/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: EXTI0													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#ifndef EXTINT0_INTERFACE_H_
#define EXTINT0_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define EXTINT_INT0         1

#define EXTINT_FALLING_EDGE       1
#define EXTINT_RAISING_EDGE       2
#define EXTINT_ANY_LOGICAL_CHANGE 3
#define EXTINT_LOW_LEVEL          4


void EXTINT0_voidEnable(u8 Copy_u8EdgeIntSource);

void EXTINT0_voidDisable(void);

void EXTINT0_voidSetCallBack(void(*Copy_pfun)(void));











#endif