/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: TIMER0												  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMER0_private.h"


void(*PTR)(void) ;

void Timer0_vidInit(void)
{
	/*Select Timer Mode*/
	#if TIMER0_MODE == NORMAL_MODE 
		TCCR0->WGM01 = 0;
		TCCR0->WGM00 = 0;
	#elif TIMER0_MODE == FAST_NON_INVERTING_PWM
		TCCR0->WGM01 = 1;
		TCCR0->WGM00 = 1;
		/*Select the mode*/
		TCCR0->COM00_COM01 = NON_INVERTING ;
	#endif
}

void Timer0_vidStart(void)
{
	/*Select Pre-load*/
	TCNT0 = PRE_LOAD_VALUE ;
	
	/*Select the Clock that operate the timer*/
	TCCR0->CS00_CS02 = TIMER0_CLK ;
}

void Timer0_vidStop(void)
{
	/*stop the Clock that operate the timer*/
	TCCR0->CS00_CS02 = STOP_TIMER ;
}

void Timer0_vidEnableInterrupt(void)
{
	#if TIMER0_MODE == NORMAL_MODE
		/*Enable the interrupt*/
		TIMSK->TOIE0 = 1;
	#elif TIMER0_MODE == CMP_MODE
		/*Enable the interrupt*/
		TIMSK->OCIE0 = 1;
	#endif
}

void Timer0_vidDisableInterrupt(void)
{	
	#if TIMER0_MODE == NORMAL_MODE
		/*Disable the interrupt*/
		TIMSK->TOIE0 = 0;
	#elif TIMER0_MODE == CMP_MODE
		/*Enable the interrupt*/
		TIMSK->OCIE0 = 0;
	#endif
	
}

void Timer0_vidSetFastPWM(u8 Copy_u8Duty)
{
	/* Convert duty cycle to its real value */
	/*
		Copy_u8Duty /= 100 ;
	*/
	
	/*Calculate the value of OCR0 (no. of ticks) */
	/*		
			no. of ticks = Duty * reslution 
	*/
	OCR0 = (((f32)Copy_u8Duty/100)*256)-1 ;
}

void Timer0_vidCallback(void(*ptr)(void))
{

	PTR = ptr ;
}

void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	PTR();
}