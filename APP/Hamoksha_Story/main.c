
#include <xc.h>
#define F_CPU 16000000UL
#include "DIO_interface.h"
#include "CLCD_interface.h"

#include <util/delay.h>
u8  ExtraChar[40]=
{
	0x0E,	// hamoksha 0
	0x0E,
	0x04,
	0x0E,
	0x15,
	0x04,
	0x0A,
	0x11 ,	 
	0x00,	//hamoksha sleep 1
	0x00,
	0x10,
	0x0A,
	0x1F,
	0x02,
	0x00,
	0x0E,
 0x0E, // hamoksha run to right 2
 0x0E,
 0x14,
 0x14,
 0x0F,
 0x05,
 0x0C,
  0x13 ,
 0x0E,	// hamoksha run to left 3
 0x0E,
 0x05,
 0x05,
 0x1E,
 0x14,
 0x06,
 0x19 
 
 
	
};


int main(void)
{	
	u16 i = 0;
	
	u8 char1[20]="Hello, i'm hamoksha";
	u8 char2[20]="i like dancing";
	u8 char3[20]="look this show";
	u8 char4[20]="i sleep early";
	 
	CLCD_vidInitCLCD();
	CLCD_vidWriteExtraChar(0,0);
	
	while(1)
    {
		/*i'm hamoksha*/
		CLCD_vidWriteString(char1);
		CLCD_vidGotoXY(1,9);
		CLCD_vidSendData(0);
		_delay_ms(1000);
		CLCD_vidSendCommand(0x01);
		
		/*i like dancing*/
		for (i = 0 ; i<5 ; i++)
		{
			CLCD_vidGotoXY(0,0);
			CLCD_vidWriteString(char2);
			CLCD_vidGotoXY(1,9);
			CLCD_vidSendData(2);
			_delay_ms(500);
			CLCD_vidGotoXY(1,9);
			CLCD_vidSendData(3);
    		_delay_ms(500);
		}
		
		CLCD_vidSendCommand(0x01);
		
		/*look this show*/
		for (i = 0 ; i<19 ; i++)
		{
			CLCD_vidGotoXY(0,3);
			CLCD_vidWriteString(char3);
			CLCD_vidGotoXY(1,i);
			CLCD_vidSendData(2);
			_delay_ms(150);
			CLCD_vidSendCommand(0x01);
			CLCD_vidGotoXY(0,3);
			CLCD_vidWriteString(char3);
			CLCD_vidGotoXY(1,i+1);
			CLCD_vidSendData(3);
			_delay_ms(150);
			CLCD_vidSendCommand(0x01);

		}
		
		CLCD_vidSendCommand(0x01);
		
		/*i sleep early*/
		for (i = 0 ; i<100 ; i++)
		{
			CLCD_vidGotoXY(0,3);
			CLCD_vidWriteString(char4);
			CLCD_vidGotoXY(1,9);
			CLCD_vidSendData(1);
			_delay_ms(1000);
			
		}
	}
}