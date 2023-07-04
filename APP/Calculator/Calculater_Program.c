/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas									  */
/*								 SWC	: Calculator											  */
/*								 Layer  : APP													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "Calculator_interface.h"

void CALC_voidInit(void)
{
	CLCD_vidInitCLCD();
	KPD_vidInit();
}

void CALC_voidWelcome(void)
{
	
		u8 HELLO[6]= "HELLO";
		u8 Simple_calc[20]="Simple Calculator" ;
		u8 Project[8]="Project";
		u8 Team[16]="A.Nahas";
		CLCD_vidGotoXY(0,8);
		CLCD_vidWriteString(HELLO);
		CLCD_vidGotoXY(1,1);
		CLCD_vidWriteString(Simple_calc);
		CLCD_vidGotoXY(2,6);
		CLCD_vidWriteString(Project);
		CLCD_vidGotoXY(3,6);
		CLCD_vidWriteString(Team);
		_delay_ms(2500);
		CLCD_vidSendCommand(0x01);
		CLCD_vidGotoXY(0,0);
}


void CALC_vidRun(void)
{
	s16 Op1 = 0;		/*operand one*/
	f32 Ans = 0 ;	/*for store result*/
	s16 Ans_mul=1;	/*for multiplication process only*/
	s16 Op1_mul = 1;	/*for multiplication process only*/	
//  	u8 mulTimes = 0;		/*for multiplication times */
	u8 devTimes = 0;	/*for devision times */
	
	u8 wrong_dev[20]="Wrong dev !";
	u8 LastOperator ;	/*Last operator*/
	
	u8 result[7]="result";
	
	CLCD_vidGotoXY(0,0);
	//CLCD_vidSendFltNumber(0);
	u8 Local_u8Reading = 0 ;
	while (1)
	{
		while ((Local_u8Reading>=0) && (Local_u8Reading<=9))
		{
			do
			{
				Local_u8Reading = KPD_u8GetButtonPressed();
			}while (Local_u8Reading == 0xFF);
			
			if((Local_u8Reading>=0) && (Local_u8Reading<=9))
			{
				CLCD_vidWriteNumber(Local_u8Reading);
				Op1=(Op1*10)+Local_u8Reading;
			}
		}
		switch(Local_u8Reading)
		{
			case '=' : 
					   switch(LastOperator)
					   {
						   case '+' : Ans += Op1 ; 
									  CLCD_vidSendCommand(0x01);
									  CLCD_vidGotoXY(0,0);
									  CLCD_vidWriteString(result);
									  CLCD_vidGotoXY(1,0);
									  CLCD_vidWriteNumber(Ans);
									  Local_u8Reading =0;
									  LastOperator=0;
									  break;
									  
						   case '-' : Ans -= Op1 ;
									  CLCD_vidSendCommand(0x01);
									  CLCD_vidGotoXY(0,0);
									  CLCD_vidWriteString(result);
									  CLCD_vidGotoXY(1,0);
									  CLCD_vidWriteNumber(Ans);
									  Local_u8Reading =0;
									  LastOperator=0;
									  break;
									  
						   case '*' : if (Op1 == 0)
										Op1_mul = 1;
									 else 
										Op1_mul = Op1 ;
									  Ans_mul *= Op1_mul ;
									  Ans = Ans_mul ;
									  CLCD_vidSendCommand(0x01);
									  CLCD_vidGotoXY(0,0);
									  CLCD_vidWriteString(result);
									  CLCD_vidGotoXY(1,0);
									  CLCD_vidWriteNumber(Ans);
									  Local_u8Reading =0;
									  LastOperator=0;
									  break;
							
						  case '/'  : if (Op1 == 0)
									  {
										 CLCD_vidSendCommand(0x01);
										 CLCD_vidGotoXY(0,0);
										 CLCD_vidWriteString(wrong_dev);
									  }
									  else
									  {
										 Ans /= Op1 ;
										 CLCD_vidSendCommand(0x01);
										 CLCD_vidGotoXY(0,0);
										 CLCD_vidWriteString(result);
										 CLCD_vidGotoXY(1,0);
										 CLCD_vidSendFltNumber(Ans);
									  }
									  Local_u8Reading =0;
									  LastOperator=0;
									  break;
									  
							case 0 :  Ans = Op1 ;
									  CLCD_vidSendCommand(0x01);
									  CLCD_vidGotoXY(0,0);
									  CLCD_vidWriteString(result);
									  CLCD_vidGotoXY(1,0);
									  CLCD_vidWriteNumber(Ans);
									  Local_u8Reading =0;
									  break; 
							 }
							 Op1=0;
							 break;
							 
					  

			case '+' : CLCD_vidSendData('+');
					   Ans += Op1 ;
					   Op1=0;
					   LastOperator = Local_u8Reading ;
					   Local_u8Reading =0;
					  
					   break;
					   
			case '-' : CLCD_vidSendData('-');
					   Ans += Op1 ;
					   Op1=0;
					   LastOperator = Local_u8Reading ;
					   Local_u8Reading =0;
					   break;
					   
			case '*' : CLCD_vidSendData('*');
					 
					   if (Op1 == 0)
						  Op1_mul = 1;
					   else
						  Op1_mul = Op1 ;
					   Ans_mul *= Op1_mul ;
					   Ans = Ans_mul ;
					   Op1=0;
					   LastOperator = Local_u8Reading ;
					   Local_u8Reading =0;
					   break;
				
			case '/' : CLCD_vidSendData('/');
					   if (devTimes == 0)
					   {
							Ans += Op1 ;
							devTimes ++;
					   }
					   Op1=0;
					   LastOperator = Local_u8Reading ;
					   Local_u8Reading =0;
					   break;
		}
	}
	
}
