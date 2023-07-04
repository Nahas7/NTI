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

#include "EXTI1_interface.h"
#include "EXTI1_private.h"
#include "EXTI1_config.h"

static void (*EXTINT_ApfuncEXTINT1)(void);


void EXTINT1_voidEnable(u8 Copy_u8EdgeIntSource)
{
	/*Select the sense control*/
	switch (Copy_u8EdgeIntSource)
	{
		case EXTINT_FALLING_EDGE :		 SET_BIT(MCUCR,MCUCR_ISC11);
										 CLR_BIT(MCUCR,MCUCR_ISC10);
										 break;
		
		case EXTINT_RAISING_EDGE :		 SET_BIT(MCUCR,MCUCR_ISC11); 
										 SET_BIT(MCUCR,MCUCR_ISC10); 
										 break; 
		
		case EXTINT_LOW_LEVEL:			 CLR_BIT(MCUCR,MCUCR_ISC11);
										 CLR_BIT(MCUCR,MCUCR_ISC10);
										 break;
		
		
		case EXTINT_ANY_LOGICAL_CHANGE:	 CLR_BIT(MCUCR,MCUCR_ISC11);
										 SET_BIT(MCUCR,MCUCR_ISC10);
										 break;	 
										 
		default: break;
	}
	
	/*Enable interrupt 1*/
	SET_BIT(GICR,GICR_INT1);
}


void EXTINT1_voidDisable(void)
{
	/*Disable interrupt 1*/
	CLR_BIT(GICR,GICR_INT1);
}


void EXTINT1_voidSetCallBack(void(*Copy_pfun)(void))
{
	EXTINT_ApfuncEXTINT1 = Copy_pfun ;
}

void __vector_2(void)  __attribute__((signal,used));
void __vector_2(void)
{
	EXTINT_ApfuncEXTINT1();
}
