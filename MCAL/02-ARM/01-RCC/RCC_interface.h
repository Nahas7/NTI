/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: RCC													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define RCC_AHB1			0
#define RCC_APB1			1
#define RCC_APB2			2


void RCC_vidSysClkInit(void);

void RCC_vidEnablePerClk(u8 Copy_u8BusId , u8 Copy_u8PerId);

void RCC_vidDisablePerClk(u8 Copy_u8BusId , u8 Copy_u8PerId);


#endif