/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas & ibrahim shokry					  */
/*								 SWC	: Calculator											  */
/*								 Layer  : APP													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#ifndef CALCULATOR_INTERFACE_H_
#define CALCULATOR_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void CALC_voidInit(void);

void CALC_voidWelcome(void);

u32 Calc_u32Power(u8 Exponent);

u8 CALC_u8ReadFromUser(f32* Ptr_Operand, u8* DigitCounter);

void CALC_voidCalculate(void);




#endif /* CALCULATOR_INTERFACE_H_ */