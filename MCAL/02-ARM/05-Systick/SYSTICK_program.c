/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: SYSTICK												  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_private.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"


#ifndef NULL
	#define NULL  (void*)0
#endif


static u8 Mode ;		/*SW falg */
static void (*STK_PF)(void) = NULL ;


void STK_vidInit(void)
{
	/* Systick is enabled and no interrupt & its clock AHB/8 */
	STK->CTRL = 0x00000001 ;
}


void STK_vidBusyWaiting(u32 Copy_u32Ticks)
{
	/*Disable Timer*/
	CLR_BIT(STK->CTRL , 0);
	
	/*Load ticks */
	STK->LOAD = Copy_u32Ticks ; 
	
	/*Enable Timer*/
	SET_BIT(STK->CTRL , 0);
	
	/*Waiting on the flag*/
	while ( (GET_BIT(STK->CTRL , 16) == 0) )
	{
		asm("NOP");
	}
	
	/*Disable Timer and clear flag by writing in VAL register*/
	CLR_BIT(STK->CTRL , 0);
	STK->LOAD = 0 ;
	STK->VAL = 0;
}

void STK_vidSingleInterval(u32 Copy_u32Ticks , void(*ptr)(void))
{
	/*Disable Timer*/
	CLR_BIT(STK->CTRL , 0);
	
	/*Load ticks */
	STK->LOAD = Copy_u32Ticks ; 
	
	/*Set the mode of the interrupt */
	Mode = SINGLE_INTERVAL ;
	
	/*Assign call back*/
	STK_PF = ptr ;
	
	/*Enable Interrupt PIE*/
	SET_BIT(STK->CTRL , 1);
	
	/*Enable Timer*/
	SET_BIT(STK->CTRL , 0);
}



void STK_vidPeriodicInterval(u32 Copy_u32Ticks , void(*ptr)(void))
{
	/*Disable Timer*/
	CLR_BIT(STK->CTRL , 0);
	
	/*Load ticks */
	STK->LOAD = Copy_u32Ticks ; 
	
	/*Set the mode of the interrupt */
	Mode = PERIOD_INTERVAL ;
	
	/*Assign call back*/
	STK_PF = ptr ;
	
	/*Enable Interrupt PIE*/
	SET_BIT(STK->CTRL , 1);

	/*Enable Timer*/
	SET_BIT(STK->CTRL , 0);
}


void STK-vidStopTimer(void)
{
	/*Disable Timer*/
	CLR_BIT(STK->CTRL , 0);
	
	STK->LOAD = 0 ;
	STK->VAL = 0;	
}


void SysTick_Handler()
{
	u8 Local_u8Temp = 0 ;
	if(Mode == SINGLE_INTERVAL)
	{
		/*Disable interrupt */
		CLR_BIT(STK->CTRL , 1);
		
		/*Disable Timer*/
		CLR_BIT(STK->CTRL , 0);
		STK->LOAD = 0 ;
		STK->VAL = 0;
	}
	STK_PF();
	
	/*Clear interrupt flag */
	Local_u8Temp = GET_BIT(STK->CTRL , 16);
}