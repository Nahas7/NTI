/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: TIMER0												  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_



void Timer0_vidInit(void);

void Timer0_vidStart(void);

void Timer0_vidStop(void);

void Timer0_vidEnableInterrupt(void);

void Timer0_vidDisableInterrupt(void);

void Timer0_vidCallback(void(*ptr)(void));



/*
	arguments : Copy_u8Dut ((range : 0 -----> 100)
*/
void Timer0_vidSetFastPWM(u8 Copy_u8Duty);


#endif