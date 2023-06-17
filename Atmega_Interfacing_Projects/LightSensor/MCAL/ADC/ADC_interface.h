/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: ADC													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef ADC_INTERFAC_H
#define ADC_INTERFAC_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define ADC_u8_ADC_CHANNEL_0            0
#define ADC_u8_ADC_CHANNEL_1            1
#define ADC_u8_ADC_CHANNEL_2            2
#define ADC_u8_ADC_CHANNEL_3            3
#define ADC_u8_ADC_CHANNEL_4            4
#define ADC_u8_ADC_CHANNEL_5            5
#define ADC_u8_ADC_CHANNEL_6            6
#define ADC_u8_ADC_CHANNEL_7            7




void ADC_vidInit(void);

void ADC_vidEnable(void);

void ADC_vidDisable(void);

void ADC_vidEnableInterrupt(void);

void ADC_vidDisableInterrupt(void);

u8 ADC_u8ReadChannel(u8 Copy_u8Channel);

void ADC_vidStartConvAsync(u8 Copy_u8Channel);

void ADC_vidCallBack(void(*ptr)(void));

void ADC_vidSelectTriggerSource(u8 Copy_u8Source);

u8 ADC_u8ReadAutoTriggering(void);



#endif