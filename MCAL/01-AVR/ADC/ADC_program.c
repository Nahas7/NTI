/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: ADC													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void(*ADC_ptrCallBack)(void);

void ADC_vidInit(void)
{
	/*Select Voltage reference*/		/*AVCC*/
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);	
	
	/*Select the adjustment*/			/*Right*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	
	/* Select The Pre-scaler value => 128 */
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	
}


void ADC_vidEnable(void)
{
	/*Enable ADC*/
	SET_BIT(ADCSRA , ADCSRA_ADEN);
}


void ADC_vidDisable(void)
{
	/*Disable ADC*/
	CLR_BIT(ADCSRA , ADCSRA_ADEN);
}


void ADC_vidEnableInterrupt(void)
{	
	/*Enable interrupt*/
	SET_BIT(ADCSRA , ADCSRA_ADIE);
}


void ADC_vidDisableInterrupt(void)
{
	/*Disable interrupt*/
	CLR_BIT(ADCSRA , ADCSRA_ADIE);
}


u8 ADC_u8ReadChannel(u8 Copy_u8Channel)
{
	/*Bit masking for channel bits*/
	ADMUX &= ADMUX_CHANNEL_NUM_MASK ;
	ADMUX |= (Copy_u8Channel);
	
	/*start conversion*/
	SET_BIT(ADCSRA , ADCSRA_ADSC);
	
	/*Polling until flag raised to make sure that conversion complete*/
	while( GET_BIT(ADCSRA , ADCSRA_ADIF) == 0);
	
	/*Clear flag*/
	SET_BIT(ADCSRA , ADCSRA_ADIF);
	
	/*read the value in ADCH*/
	return ADC ;
}



void ADC_vidStartConvAsync(u8 Copy_u8Channel)
{
	/*Bit masking for channel bits*/
	ADMUX &= ADMUX_CHANNEL_NUM_MASK ;
	ADMUX |= (Copy_u8Channel);
	
	/*start conversion*/
	SET_BIT(ADCSRA , ADCSRA_ADSC);
}


void ADC_vidCallBack(void(*ptr)(void))
{
	ADC_ptrCallBack = ptr ;
}



void ADC_vidSelectTriggerSource(u8 Copy_u8Source)
{
	/*Select the source to start conversion*/
	SFIOR &= SFIOR_SOURCE_TRIGG_MASK;
	SFIOR |= Copy_u8Source;
	/*Enable AutoTriggering*/
	SET_BIT(ADCSRA ,ADCSRA_ADATE);
}

u8 ADC_u8ReadAutoTriggering(void)
{
	/*Polling until flag raised to make sure that conversion complete*/
	while( GET_BIT(ADCSRA , ADCSRA_ADIF) == 0);
	
	/*Clear flag*/
	SET_BIT(ADCSRA , ADCSRA_ADIF);
	
	/*read the value in ADCH*/
	return ADC ;
}


void __vector_16 (void) __attribute((signal));
void __vector_16 (void)
{	
	ADC_ptrCallBack();
}
