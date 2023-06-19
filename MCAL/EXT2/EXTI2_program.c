/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: EXTI2													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI2_interface.h"
#include "EXTI2_private.h"
#include "EXTI2_config.h"

static void (*EXTINT_ApfuncEXTINT2)(void);



void EXTINT2_voidEnable(u8 Copy_u8EdgeIntSource)
{
	/*Select the sense control*/
	switch (Copy_u8EdgeIntSource)
	{
		case EXTINT_FALLING_EDGE :		 CLR_BIT(MCUCSR,MCUCSR_ISC2);
										 break;
		
		case EXTINT_RAISING_EDGE :		 SET_BIT(MCUCSR,MCUCSR_ISC2);
										 break;
		
		default: break;
	}
	
	/*Enable interrupt 2*/
	SET_BIT(GICR,GICR_INT2);
}


void EXTINT2_voidDisable(void)
{
	/*Disable interrupt 2*/
	CLR_BIT(GICR,GICR_INT2);
}


void EXTINT2_voidSetCallBack(void(*Copy_pfun)(void))
{
	EXTINT_ApfuncEXTINT2 = Copy_pfun ;
}

void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	EXTINT_ApfuncEXTINT2();
}



