/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: NVIC													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


void NVIC_vidInit(void)
{
	#ifndef SCB_AIRCR
		#define SCB_AIRCR		*((volatile u32 *)(0x0C + 0xE000ED00))
	#endif
	
	SCB_AIRCR = NUM_OF_GROUPS ;
}

void NVIC_vidSetInterruptPeri(u8 Copy_u8INTId , u8 Copy_u8Periority )
{
	NVIC_IPR[Copy_u8INTId] = (Copy_u8Periority<<4);
}

void NVIC_vidEnablePer(u8 Copy_u8PerId)
{
	/*Range Check*/
	if (Copy_u8PerId < 32)
	{
		NVIC_ISER0 = (1<<Copy_u8PerId) ;
	}
	else if (Copy_u8PerId < 64)
	{
		Copy_u8PerId -= 32 ;
		NVIC_ISER1 = (1<<Copy_u8PerId) ;	
	}
	else if (Copy_u8PerId < 84)
	{
		Copy_u8PerId -= 64 ;
		NVIC_ISER2 = (1<<Copy_u8PerId) ;	
	}
}

void NVIC_vidDisablePer(u8 Copy_u8PerId)
{
	/*Range Check*/
	if (Copy_u8PerId < 32)
	{
		NVIC_ICER0 = (1<<Copy_u8PerId) ;
	}
	else if (Copy_u8PerId < 64)
	{
		Copy_u8PerId -= 32 ;
		NVIC_ICER1 = (1<<Copy_u8PerId) ;	
	}
	else if (Copy_u8PerId < 84)
	{
		Copy_u8PerId -= 64 ;
		NVIC_ICER2 = (1<<Copy_u8PerId) ;	
	}
}


void NVIC_vidSetPendingFlag(u8 Copy_u8PerId)
{
	/*Range Check*/
	if (Copy_u8PerId < 32)
	{
		NVIC_ISPR0 = (1<<Copy_u8PerId) ;
	}
	else if (Copy_u8PerId < 64)
	{
		Copy_u8PerId -= 32 ;
		NVIC_ISPR1 = (1<<Copy_u8PerId) ;	
	}
	else if (Copy_u8PerId < 84)
	{
		Copy_u8PerId -= 64 ;
		NVIC_ISPR2 = (1<<Copy_u8PerId) ;	
	}
}

void NVIC_vidClrPendingFlag(u8 Copy_u8PerId)
{
	/*Range Check*/
	if (Copy_u8PerId < 32)
	{
		NVIC_ICPR0 = (1<<Copy_u8PerId) ;
	}
	else if (Copy_u8PerId < 64)
	{
		Copy_u8PerId -= 32 ;
		NVIC_ICPR1 = (1<<Copy_u8PerId) ;	
	}
	else if (Copy_u8PerId < 84)
	{
		Copy_u8PerId -= 64 ;
		NVIC_ICPR2 = (1<<Copy_u8PerId) ;	
	}	
}


u8 NVIC_u8GetActiveFlag(u8 Copy_u8PerId)
{
	u8 Local_u8Flag = 0xAA ;
	/*Range Check*/
	if (Copy_u8PerId < 32)
	{
		Local_u8Flag = GET_BIT(NVIC_IABR0 , Copy_u8PerId);
	}
	else if (Copy_u8PerId < 64)
	{
		Copy_u8PerId -= 32 ;
		Local_u8Flag = GET_BIT(NVIC_IABR1 , Copy_u8PerId);
	}
	else if (Copy_u8PerId < 84)
	{
		Copy_u8PerId -= 64 ;
		NLocal_u8Flag = GET_BIT(NVIC_IABR2 , Copy_u8PerId);
	}	
	return Local_u8Flag ;
}