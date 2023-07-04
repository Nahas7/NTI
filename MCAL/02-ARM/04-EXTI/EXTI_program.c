/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: EXTI													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"


static void(*PTR_F[23])(void) ;

void EXTI_vidEnableEXTIx(u8 Copy_u8EXTI_Id , u8 Copy_u8EXTI_Sense)
{
	/*Range Check*/
	if (Copy_u8EXTI_Id >= 0 && Copy_u8EXTI_Id <= 15)
	{
		switch(Copy_u8EXTI_Sense)
		{
			case EXTI_FALLING_EDGE : SET_BIT(EXTI_FTSR , Copy_u8EXTI_Id);
									 SET_BIT(EXTI_IMR , Copy_u8EXTI_Id);
									 break;
			
			case EXTI_RISING_EDGE :  SET_BIT(EXTI_RTSR , Copy_u8EXTI_Id);
									 SET_BIT(EXTI_IMR , Copy_u8EXTI_Id);
									 break;
									 
			case EXTI_TRIGGER 	  :  SET_BIT(EXTI_RTSR , Copy_u8EXTI_Id);
									 SET_BIT(EXTI_FTSR , Copy_u8EXTI_Id);
									 SET_BIT(EXTI_IMR , Copy_u8EXTI_Id);
									 break;
			
			default :				 break; 
		}
	}
}


void EXTI_vidDisableEXTIx(u8 Copy_u8EXTI_Id )
{
	CLR_BIT(EXTI_IMR , Copy_u8EXTI_Id);
}


void EXTI_vidSetCallBack(void ptr*(void) , u8 Copy_u8Index)
{
	
	PTR_F[Copy_u8Index] = ptr;
	
}

EXTI0_IRQHandler()
{
	PTR_F[0]();
	SET_BIT(EXTI_PR , 0);
	NVIC_vidClrPendingFlag(6);
}

EXTI1_IRQHandler()
{
	PTR_F[1]();
	SET_BIT(EXTI_PR , 1);
	NVIC_vidClrPendingFlag(7);
}

EXTI2_IRQHandler()
{
	PTR_F[2]();
	SET_BIT(EXTI_PR , 2);
	NVIC_vidClrPendingFlag(8);
}

EXTI3_IRQHandler()
{
	PTR_F[3]();
	SET_BIT(EXTI_PR , 3);
	NVIC_vidClrPendingFlag(8);
}


EXTI13_IRQHandler()
{
	PTR_F[13]();
	SET_BIT(EXTI_PR , 13);
	NVIC_vidClrPendingFlag(40);
}




