/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: Electronic resoary									  */
/*								 Layer  : APP													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/



/*



				in the vedio of this application you will notify that there's a problem 
				and this because debouncing of the push button 
				abd the Interrupt recorded this debouncing as a press.


*/

#include <xc.h>

#include "STD_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "EXTI1_interface.h"
#include "EXTI0_interface.h"
#include "GIE_interface.h"
#include "SSD_interface.h"

u8 Ones = 0;
u8 Tens = 0;

void EXTI1_ISR(void);
void EXTI0_ISR(void);


int main(void)
{
	/*Set directions to EXTIs*/
	DIO_u8SetPinDirection(DIO_PORTD , DIO_PIN3 ,DIO_INPUT);
	DIO_u8SetPinValue(DIO_PORTD , DIO_PIN3 ,DIO_HIGH);
	
	/*Set directions to EXTIs*/
	DIO_u8SetPinDirection(DIO_PORTD , DIO_PIN2 ,DIO_INPUT);
	DIO_u8SetPinValue(DIO_PORTD , DIO_PIN2 ,DIO_HIGH);
	
	
	/*Declare SSD*/
	SSD_t_decoder SSD1 = {DIO_PORTB , {DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN4} , SSD_COM_CATHODE , DIO_PORTA , DIO_PIN3};
	SSD_t_decoder SSD2 = {DIO_PORTB , {DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN4} , SSD_COM_CATHODE , DIO_PORTA , DIO_PIN2};
	
	SSD_vidInitSSDDecoder(&SSD1);
	SSD_vidInitSSDDecoder(&SSD2);
	
	
	EXTINT1_voidSetCallBack(&EXTI1_ISR);
	EXTINT1_voidEnable(EXTINT_RAISING_EDGE);

	EXTINT0_voidSetCallBack(&EXTI0_ISR);
	EXTINT0_voidEnable(EXTINT_FALLING_EDGE);
	GIE_voidGlobalInterruptEnable();

	
	
    while(1)
    {
		SSD_vidDisplaySSDDecoder(&SSD1 , Ones);
		SSD_vidDisableSSDDecoder(&SSD2);
		_delay_ms(10);
		SSD_vidDisplaySSDDecoder(&SSD2 , Tens);
		SSD_vidDisableSSDDecoder(&SSD1);
		_delay_ms(10);
    }
}

void EXTI1_ISR(void)
{
	if(Ones < 9)
	{
		Ones++;
	}
	else if(Ones == 9)
	{
		Ones = 0 ;
		Tens++;
	}
	if(Tens > 9)
	{
		Ones = 0;
		Tens = 0;
	}
}

void EXTI0_ISR(void)
{
	Ones = 0;
	Tens = 0;
}