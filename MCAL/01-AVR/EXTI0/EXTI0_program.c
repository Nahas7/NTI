/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: EXTI0													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI0_interface.h"
#include "EXTI0_private.h"
#include "EXTI0_config.h"

static void (*EXTINT_ApfuncEXTINT0)(void);


void EXTINT0_voidEnable(u8 Copy_u8EdgeIntSource)
{
	/*Select the sense control*/
	switch (Copy_u8EdgeIntSource)
	{
		case EXTINT_FALLING_EDGE :		 SET_BIT(MCUCR,MCUCR_ISC01);
										 CLR_BIT(MCUCR,MCUCR_ISC00);
										 break;
										 
		case EXTINT_RAISING_EDGE :		 SET_BIT(MCUCR,MCUCR_ISC01);
										 SET_BIT(MCUCR,MCUCR_ISC00);
										 break;	
		
		case EXTINT_LOW_LEVEL:			 CLR_BIT(MCUCR,MCUCR_ISC01);
										 CLR_BIT(MCUCR,MCUCR_ISC00);
										 break;
								   
								   
		case EXTINT_ANY_LOGICAL_CHANGE:	 CLR_BIT(MCUCR,MCUCR_ISC01);
										 SET_BIT(MCUCR,MCUCR_ISC00);
										 break;
		
		default: break;
	}							   
	
	/*Enable interrupt 0*/
	SET_BIT(GICR,GICR_INT0);
}


void EXTINT0_voidDisable(void)
{
	/*Disable interrupt 0*/
	CLR_BIT(GICR,GICR_INT0);
}


void EXTINT0_voidSetCallBack(void(*Copy_pfun)(void))
{
	EXTINT_ApfuncEXTINT0 = Copy_pfun ;
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	EXTINT_ApfuncEXTINT0();
}
