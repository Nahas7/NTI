/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: EXTI													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


void EXTI_vidEnableEXTIx(u8 Copy_u8EXTI_Id , u8 Copy_u8EXTI_Sense);

void EXTI_vidDisableEXTIx(u8 Copy_u8EXTI_Id );

void EXTI_vidSetCallBack(void ptr*(void) , u8 Copy_u8Index);

#endif