/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: SPI 													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_vidInit(void)
{
	/* 1- Data order
	 * 2- Master or slave mode
	 * 3- Clk polarity
	 * 4- Clk Phase
	 * 5- Enable SPI*/

	/******************* 	 interrupt	 	*****************/
	#if SPI_INTERRUPT == SPI_INTERRUPT_ENABLE
		CLR_BIT(SPCR,SPCR_SPIE);
	#elif SPI_INTERRUPT == SPI_INTERRUPT_DISABLE
		CLR_BIT(SPCR,SPCR_SPIE);
	#endif 
	
	/******************* 	 Master/slave	 *****************/
	#if SPI_MODE == SPI_MASTER
		SET_BIT(SPCR , SPCR_MSTR);
		/*Select frequency */
		#if SPI_u8_CLK_RATE  == SPI_CLK_OVER_4
			CLR_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
		#elif SPI_u8_CLK_RATE  == SPI_CLK_OVER_16
			CLR_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
		#elif SPI_u8_CLK_RATE  == SPI_CLK_OVER_64
			CLR_BIT(SPCR,SPCR_SPR0);
			SET_BIT(SPCR,SPCR_SPR1);
		#elif SPI_u8_CLK_RATE  == SPI_CLK_OVER_128
			SET_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
		#elif SPI_u8_CLK_RATE  == SPI_HCLK_OVER_2
			CLR_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
			SET_BIT(SPSR,SPSR_SPI2X);
		#elif SPI_u8_CLK_RATE  == SPI_HCLK_OVER_8
			CLR_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
			SET_BIT(SPSR,SPSR_SPI2X);
		#elif SPI_u8_CLK_RATE  == SPI_HCLK_OVER_32
			SET_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
			SET_BIT(SPSR,SPSR_SPI2X);
		#elif SPI_u8_CLK_RATE  == SPI_HCLK_OVER_64
			SET_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
			SET_BIT(SPSR,SPSR_SPI2X);
		#endif
	#elif SPI_MODE == SPI_SLAVE 
		CLR_BIT(SPCR , SPCR_MSTR);
	#endif

	/************* 	 clk phase and clk polarity	 **************/
	/*select clock polarity */
	#if SPI_CLK_POL == SPI_POL_RISING
		CLR_BIT(SPCR , SPCR_CPOL);
	#elif SPI_CLK_POL == SPI_POL_FALLING
		SET_BIT(SPCR , SPCR_CPOL);
	#endif 

	/*select clock phase*/
	#if SPI_LEADING == SPI_LEADING_SETUP
		CLR_BIT(SPCR , SPCR_CPHA);
	#elif SPI_LEADING == SPI_LEADING_SAMPLE
		SET_BIT(SPCR , SPCR_CPHA);
	#endif
	
	
	/******************* 	 SPI Enable	 	*****************/
	SET_BIT(SPCR , SPCR_SPE);
}


void SPI_vidSendRecieveByte(u8 Copy_u8SendData , u8* Copy_u8RecievedData)
{
	/*Send data*/
	SPDR = Copy_u8SendData ; 
	
	/*polling until transmit finished*/
	while ( GET_BIT(SPSR , SPSR_SPIF) == 0);
	
	/*read the data from the slave*/
	*Copy_u8RecievedData = SPDR ;
}

void SPI_vidReadSlaveRegister(u8 * Copy_u8ReadData)
{
	/*read the data from the slave*/
	*Copy_u8ReadData = SPDR ;
}
