/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas & ibrahim shokry					  */
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
		u8 Team[16]="Nahas & Shokry";
		CLCD_vidGotoXY(0,8);
		CLCD_vidWriteString(HELLO);
		CLCD_vidGotoXY(1,1);
		CLCD_vidWriteString(Simple_calc);
		CLCD_vidGotoXY(2,6);
		CLCD_vidWriteString(Project);
		CLCD_vidGotoXY(3,2);
		CLCD_vidWriteString(Team);
		_delay_ms(5000);
		CLCD_vidSendCommand(0x01);
		CLCD_vidGotoXY(0,0);
}

/*Calc_uint32Power Calculate 10 power of Exponent*/
u32 Calc_u32Power(u8 Exponent)
{
	u32 Result=1;
	u8 i;
	for(i=0;i<Exponent;i++)
	{
		Result*=10;
	}
	return Result;
}

u8 CALC_u8ReadFromUser(f32* Ptr_Operand, u8* DigitCounter)
{
	u8 Digits=0;
	*DigitCounter=0;
	while(Digits>=0&&Digits<=9)
	{
		do{
			Digits=KPD_u8GetButtonPressed();
		}while(Digits==0xFF);
		if(Digits>=0&&Digits<=9)
		{
			*Ptr_Operand=(*Ptr_Operand*10)+Digits;
			CLCD_vidWriteNumber(Digits);
			*DigitCounter=(*DigitCounter)+1;
		}
	}
	return Digits;
}


void CALC_voidCalculate(void)
{
	
	u8 Result[8]="Result";
	u8 FALT[25]="Division by ZERO!";
	u8 Erorr[25]="Two Floating Point!";
	
	/*Integer part and Floating point part*/
	f32 Operand=0;
	f32 FloatPart=0;
	
	/*result*/
	static f32 FResult=0;
	u8 LastOprator;
	u8 Digits;
	
	/*FLags*/
	u8 DividebyZeroFlag=0;			//Raise when user Divide by zero
	u8 FirstOperationFlag=0;         //Raise After first operation entered
	u8 MultiSignFlag=0;				//Raise when user Enter two signs without Operand between them
	
	/*counter*/
	u8 floatcount=0;
	CLCD_vidSendCommand(0x01);
	CLCD_vidGotoXY(0,0);
	CLCD_vidWriteNumber(0);
	CLCD_vidGotoXY(0,0);
	while(1)
	{
		Digits=CALC_u8ReadFromUser(&Operand, &floatcount);
		if(Digits=='=')
		{
			if(FirstOperationFlag==0)
			{
				FResult=Operand;
				Operand=0;
				CLCD_vidSendCommand(0x01);
				CLCD_vidGotoXY(1,0);
				CLCD_vidSendFltNumber(FResult);
				CLCD_vidGotoXY(0,0);
				CLCD_vidWriteString(Result);
			}
			else
			{
				switch (LastOprator)
				{
				case '+':
					FResult=FResult+Operand;
					Operand=0;
					LastOprator=Digits;
					break;
				case '-':
					FResult=FResult-Operand;
					Operand=0;
					LastOprator=Digits;
					break;
				case '*':
					FResult=FResult*Operand;
					Operand=0;
					LastOprator=Digits;
					break;
				case '/':
					if(Operand==0)
					{
						CLCD_vidSendCommand(0x01);
						CLCD_vidWriteString(FALT);
						Operand=0;
						FloatPart=0;
						FResult=0;
						FirstOperationFlag=0;
						_delay_ms(2000);
						DividebyZeroFlag=1;

					}
					else
					{
						FResult=FResult/Operand;
						Operand=0;
						LastOprator=Digits;
					}
					break;
				 }
				CLCD_vidSendCommand(0x01);
				if(DividebyZeroFlag==0)
				{
					CLCD_vidGotoXY(1,0);
					CLCD_vidSendFltNumber(FResult);
					CLCD_vidGotoXY(0,0);
					CLCD_vidWriteString(Result);
					FirstOperationFlag=0;
				}
				else
				{
					DividebyZeroFlag=0;
					CLCD_vidGotoXY(0,0);
					CLCD_vidWriteNumber(FResult);
					CLCD_vidGotoXY(0,0);
				}
			}
			do{
				Digits=KPD_u8GetButtonPressed();
			}while(Digits==0xFF);
			if((Digits>=0&&Digits<=9))
			{

				FResult=0;
				Operand=Digits;
				FloatPart=0;
				CLCD_vidSendCommand(0x01);
				CLCD_vidSendFltNumber(Digits);
			}
			else if(Digits=='.')
			{
				FResult=0;
				Operand=0;
				FloatPart=0;
				CLCD_vidSendCommand(0x01);
				CLCD_vidGotoXY(0,0);
			}
			else
			{
				Operand=FResult;
			}
		}
		if(Digits=='.')
		{
			CLCD_vidSendCommand(0x01);
			if(FResult==0)
			{
				CLCD_vidGotoXY(0,0);
				CLCD_vidSendFltNumber(Operand);
				CLCD_vidSendData('.');
			}
			else
			{
				CLCD_vidGotoXY(1,0);
				CLCD_vidSendFltNumber(FResult);
				CLCD_vidGotoXY(0,0);
				CLCD_vidWriteString(Result);
				CLCD_vidSendData(LastOprator);
				CLCD_vidSendFltNumber(Operand);
				CLCD_vidSendData('.');
			}
			Digits=CALC_u8ReadFromUser(&FloatPart,&floatcount);
			if(Digits=='.')
			{
				CLCD_vidSendCommand(0x01);
				CLCD_vidWriteString(Erorr);
				Operand=0;
				FloatPart=0;
				FResult=0;
				FirstOperationFlag=0;
				_delay_ms(5000);
				CLCD_vidSendCommand(0x01);
				CLCD_vidGotoXY(0,0);
				CLCD_vidWriteNumber(0);
				CLCD_vidGotoXY(0,0);
			}
			else
			{
				FloatPart=FloatPart/Calc_u32Power(floatcount);
				Operand+=(FloatPart);
				FloatPart=0;

			}
		}
		if(Digits=='+'||Digits=='-'||Digits=='*'||Digits=='/')
		{
			CLCD_vidSendData(Digits);
			if(FirstOperationFlag==1)
			{
				switch (LastOprator)
				{
				case '+':
					if(floatcount==1)
					{
						if(Digits!='-')
						{
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendData(' ');
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendData(Digits);

						}
						LastOprator=Digits;
						MultiSignFlag=1;
					}
					else
					{
						FResult=FResult+Operand;
						Operand=0;
						LastOprator=Digits;
					}
					break;
				case '-':
					if(Operand==0)
					{
						if(Digits!='+')
						{
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendData(' ');
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendData(Digits);
						}
						MultiSignFlag=1;
					}
					else
					{
						FResult=FResult-Operand;
						Operand=0;
						LastOprator=Digits;
					}
					break;
				case '*':
					if(Operand==0)
					{
						MultiSignFlag=1;
						if(Digits=='-')
						{
							FResult*=-1;
						}
						else if (Digits=='+')
						{
							/*NoThing*/
						}
						else
						{
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendData(' ');
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendData(Digits);
							LastOprator=Digits;
						}
					}
					else
					{
						FResult=FResult*Operand;
						Operand=0;
						LastOprator=Digits;
					}

					break;
				case '/':
					if(floatcount==0)
					{
						MultiSignFlag=1;
						if(Digits=='-')
						{
							FResult*=-1;
						}
						else if (Digits=='+')
						{
							/*Nothing*/
						}
						else
						{
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendData(' ');
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendCommand(0x10);
							CLCD_vidSendData(Digits);
							LastOprator=Digits;
							LastOprator=Digits;
						}
					}
					else
					{
						if(Operand==0)
						{
							CLCD_vidSendCommand(0x01);
							CLCD_vidWriteString(FALT);
							Operand=0;
							FResult=0;
							FirstOperationFlag=0;
							_delay_ms(5000);
							DividebyZeroFlag=1;
						}
						else
						{
							FResult=FResult/Operand;
							Operand=0;
							LastOprator=Digits;
						}
					}

					break;
				}

				if(DividebyZeroFlag==0)
				{
					if(MultiSignFlag==0)
					{
						CLCD_vidSendCommand(0x01);
						CLCD_vidGotoXY(1,0);
						CLCD_vidSendFltNumber(FResult);
						CLCD_vidGotoXY(0,0);
						CLCD_vidWriteString(Result);
						CLCD_vidSendData(LastOprator);
					}
					else
					{
						MultiSignFlag=0;
					}

				}
				else
				{
					CLCD_vidSendCommand(0x01);
					DividebyZeroFlag=0;
					CLCD_vidGotoXY(0,0);
					CLCD_vidWriteNumber(FResult);
					CLCD_vidGotoXY(0,0);
				}
			}
			else
			{
				FResult=Operand;
				Operand=0;
				LastOprator=Digits;
				FirstOperationFlag=1;
			}
		}

	}
}
