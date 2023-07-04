/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: EXTI													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH."


#define EXTI_BASE_ADDRESS		(u32)0x40013C00


#define EXTI_IMR				*((volatile u32*)(EXTI_BASE_ADDRESS+0x00))
#define EXTI_EMR				*((volatile u32*)(EXTI_BASE_ADDRESS+0x04))
#define EXTI_RTSR				*((volatile u32*)(EXTI_BASE_ADDRESS+0x08))
#define EXTI_FTSR				*((volatile u32*)(EXTI_BASE_ADDRESS+0x0C))
#define EXTI_SWIER				*((volatile u32*)(EXTI_BASE_ADDRESS+0x10))
#define EXTI_PR					*((volatile u32*)(EXTI_BASE_ADDRESS+0x14))


#define	EXTI_FALLING_EDGE		0
#define EXTI_RISING_EDGE		1
#define EXTI_TRIGGER			2 

#endif
