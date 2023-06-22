/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: Alarm												  */
/*								 Layer  : APP													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI0_interface.h"
#include "EXTI2_interface.h"

#include "CLCD_interface.h"
#include "KPD_interface.h"
#include <util/delay.h>


 u8 Alarm = 0;
void EXTI0_ISR(void);
void EXTI2_ISR(void);

u8 Welcome[]="Adjust Alarm";

u8 SystemState=0 ;
u8 Reading = 0xFF;


void alarm_init(void)
{
		/*LCD control*/
		DIO_u8SetPinDirection(DIO_PORTA , DIO_PIN5 , DIOI_OUTPUT);
		DIO_u8SetPinValue(DIO_PORTA , DIO_PIN5 , DIO_LOW);
		
		/*Buzzer*/
		DIO_u8SetPinDirection(DIO_PORTC , DIO_PIN6 , DIOI_OUTPUT);
		DIO_u8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_LOW);
		
		DIO_u8SetPinDirection(DIO_PORTD , DIO_PIN2 , DIO_INPUT);
		DIO_u8SetPinValue(DIO_PORTD , DIO_PIN2 , DIO_HIGH);
		
		CLCD_vidInitCLCD();
		KPD_vidInit();
		
		EXTINT0_voidSetCallBack(&EXTI0_ISR);
		EXTINT0_voidEnable(EXTINT_FALLING_EDGE);
		
		
		EXTINT2_voidSetCallBack(&EXTI2_ISR);
		EXTINT2_voidEnable(EXTINT_FALLING_EDGE);
		
		GIE_voidGlobalInterruptEnable();
}


void alarm_run(void)
{

	
	  while(1)
	  {
		  while(Reading != 'f')
		  {
			  do
			  {
				  Reading = KPD_u8GetButtonPressed();
			  }while (Reading == 0xFF);
			  CLCD_vidWriteNumber(Reading);
			  if (Reading != 'f')
				Alarm = (Alarm*10) + Reading ;
		  }
		  CLCD_vidSendCommand(0x01);
		  while(Alarm !=0 && SystemState == 1)
		  {
			  Alarm-- ;
			  _delay_ms(1000);
			  CLCD_vidSendCommand(0x01);
			  CLCD_vidWriteNumber(Alarm);
		  }
		  while (Alarm == 0 && SystemState == 1 )
		  {
			  DIO_u8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_HIGH);
		  }
		    

	  }
}




void EXTI0_ISR(void)
{
	u8 static flag = 1 ;
	if (flag == 1)
	{
		DIO_u8SetPinValue(DIO_PORTA , DIO_PIN5 , DIO_HIGH);
		flag = 0;
		CLCD_vidSendCommand(0x01);
		CLCD_vidGotoXY(0,0);
		CLCD_vidWriteString(Welcome);
		CLCD_vidGotoXY(1,0);
		SystemState = 1;
		Alarm = 0;
	}
	else if(flag == 0)
	{
		CLCD_vidSendCommand(0x01);
		DIO_u8SetPinValue(DIO_PORTA , DIO_PIN5 , DIO_LOW);
		flag = 1;
		DIO_u8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_LOW);
		SystemState = 0;
		Reading = 0xFF;
	}	
}

void EXTI2_ISR(void)
{
	TOG_BIT(SystemState , 0);
	
}