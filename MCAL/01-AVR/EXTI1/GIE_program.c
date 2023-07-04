/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "GIE_interface.h"

#define SREG    *((volatile u8*)0x5F)

void GIE_voidGlobalInterruptEnable(void)
{
	SET_BIT(SREG,7);
}

void GIE_voidGlobalInterruptDisable(void)
{
	CLR_BIT(SREG,7);
}
