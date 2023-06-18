/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: LCD													  */
/*								 Layer  : HAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"


void CLCD_vidSendCommand(u8 Copy_u8Data)
{
	/*Clear RS PIN to send command*/
	DIO_u8SetPinValue(CLCD_RS_PORT , CLCD_RS_PIN , DIO_LOW);
	
	Data CMD ;
	CMD.Byte = Copy_u8Data ;
	
	 /**********************	First stage ***************/
	
	/*Clear RW PIN to write */
	/*DIO_u8SetPinValue(CLCD_RW_PORT , CLCD_RW_PIN , DIO_LOW);*/
	
	/*Send the most data bits*/
	DIO_u8SetPinValue(CLCD_DATA7_PORT , CLCD_DATA7_PIN , CMD.Bit.Bit7);
	DIO_u8SetPinValue(CLCD_DATA6_PORT , CLCD_DATA6_PIN , CMD.Bit.Bit6);
	DIO_u8SetPinValue(CLCD_DATA5_PORT , CLCD_DATA5_PIN , CMD.Bit.Bit5);
	DIO_u8SetPinValue(CLCD_DATA4_PORT , CLCD_DATA4_PIN , CMD.Bit.Bit4);
	
	/*Trigger Enable */
	DIO_u8SetPinValue(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIO_HIGH);
	_delay_ms(30);
	DIO_u8SetPinValue(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIO_LOW);
	_delay_ms(30);
	
	/**********************	Second stage ***************/
	/*Send the least data bits*/
	DIO_u8SetPinValue(CLCD_DATA7_PORT , CLCD_DATA7_PIN , CMD.Bit.Bit3);
	DIO_u8SetPinValue(CLCD_DATA6_PORT , CLCD_DATA6_PIN , CMD.Bit.Bit2);
	DIO_u8SetPinValue(CLCD_DATA5_PORT , CLCD_DATA5_PIN , CMD.Bit.Bit1);
	DIO_u8SetPinValue(CLCD_DATA4_PORT , CLCD_DATA4_PIN , CMD.Bit.Bit0);
	
	/*Trigger Enable */
	DIO_u8SetPinValue(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIO_HIGH);
	_delay_ms(30);
	DIO_u8SetPinValue(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIO_LOW);
	_delay_ms(30);
}




void CLCD_vidSendData(u8 Copy_u8Data)
{
	Data CMD ;
	CMD.Byte = Copy_u8Data ;
	
	/**********************	First stage ***************/
	/*Clear RS PIN to send command*/
	DIO_u8SetPinValue(CLCD_RS_PORT , CLCD_RS_PIN , DIO_HIGH);
	
	/*Clear RW PIN to write */
	/*DIO_u8SetPinValue(CLCD_RW_PORT , CLCD_RW_PIN , DIO_LOW);*/
	
	/*Send the most data bits*/
	DIO_u8SetPinValue(CLCD_DATA7_PORT , CLCD_DATA7_PIN , CMD.Bit.Bit7);
	DIO_u8SetPinValue(CLCD_DATA6_PORT , CLCD_DATA6_PIN , CMD.Bit.Bit6);
	DIO_u8SetPinValue(CLCD_DATA5_PORT , CLCD_DATA5_PIN , CMD.Bit.Bit5);
	DIO_u8SetPinValue(CLCD_DATA4_PORT , CLCD_DATA4_PIN , CMD.Bit.Bit4);
	
	/*Trigger Enable */
	DIO_u8SetPinValue(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIO_HIGH);
	_delay_ms(30);
	DIO_u8SetPinValue(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIO_LOW);
	_delay_ms(30);
	
	/**********************	Second stage ***************/
	/*Send the most data bits*/
	DIO_u8SetPinValue(CLCD_DATA7_PORT , CLCD_DATA7_PIN , CMD.Bit.Bit3);
	DIO_u8SetPinValue(CLCD_DATA6_PORT , CLCD_DATA6_PIN , CMD.Bit.Bit2);
	DIO_u8SetPinValue(CLCD_DATA5_PORT , CLCD_DATA5_PIN , CMD.Bit.Bit1);
	DIO_u8SetPinValue(CLCD_DATA4_PORT , CLCD_DATA4_PIN , CMD.Bit.Bit0);
	
	/*Trigger Enable */
	DIO_u8SetPinValue(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIO_HIGH);
	_delay_ms(30);
	DIO_u8SetPinValue(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIO_LOW);
	_delay_ms(30);
}



void CLCD_vidInitCLCD(void)
{
	
	DIO_u8SetPinDirection(CLCD_DATA7_PORT , CLCD_DATA7_PIN , DIOI_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA6_PORT , CLCD_DATA6_PIN , DIOI_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA5_PORT , CLCD_DATA5_PIN , DIOI_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA4_PORT , CLCD_DATA4_PIN , DIOI_OUTPUT);
	
	DIO_u8SetPinDirection(CLCD_RS_PORT , CLCD_RS_PIN , DIOI_OUTPUT);
	DIO_u8SetPinDirection(CLCD_ENABLE_PORT , CLCD_ENABLE_PIN , DIOI_OUTPUT);
	
	/*delay until LCD power on*/
	_delay_ms(35);
	
	/*Return home*/
	CLCD_vidSendCommand(0x02);
	_delay_ms(2);
	
	/*Send function set commands*/
	CLCD_vidSendCommand(0b00101000);	/*Set DL 4-bit & Set 2 lines & small font*/	
	_delay_ms(1);
	
	/*Display On/Off control*/
	CLCD_vidSendCommand(0b00001100);	
	_delay_ms(1);	

	/*Display Clear*/
	CLCD_vidSendCommand(0x01);
	_delay_ms(2);
	
	/*Entry Mode*/
	CLCD_vidSendCommand(0x06);
	_delay_ms(1);
}


void CLCD_vidGotoXY(u8 Copy_u8Xpositiion , u8 Copy_u8YPosition)
{
	switch(Copy_u8Xpositiion)
	{
		case 0 : CLCD_vidSendCommand(0x80+0x00+Copy_u8YPosition); break;
		case 1 : CLCD_vidSendCommand(0x80+0x40+Copy_u8YPosition); break;
		case 2 : CLCD_vidSendCommand(0x80+0x14+Copy_u8YPosition); break;
		case 3 : CLCD_vidSendCommand(0x80+0x54+Copy_u8YPosition); break;
		default: break;
	}
}


void CLCD_vidWriteNumber(u32 Copy_u32Number)
{
	u32 Local_uint32Data = Copy_u32Number ;
	u32 local_arruint8Data[10];
	int i=0;
	do
	{
		local_arruint8Data[i] = (Local_uint32Data%10)+'0';
		Local_uint32Data/=10;
		i++;
	}
	while (Local_uint32Data);
	i--;
	
	for (;i>=0;i--)
	{
		CLCD_vidSendData(local_arruint8Data[i]);
	}
	
}

void CLCD_vidWriteString(u8* pu8StringCpy)
{
	u8 u8Index = 0;
	while (pu8StringCpy[u8Index] != 0)
	{
		CLCD_vidSendData(pu8StringCpy[u8Index]);
		u8Index++;
	}
}