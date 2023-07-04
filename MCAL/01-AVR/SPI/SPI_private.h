/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: SPI 													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR   *((volatile u8*)0x2D)
#define SPCR_SPIE                   7
#define SPCR_SPE                    6
#define SPCR_DORD                   5
#define SPCR_MSTR                   4
#define SPCR_CPOL                   3
#define SPCR_CPHA                   2
#define SPCR_SPR1                   1
#define SPCR_SPR0                   0


#define SPSR   *((volatile u8*)0x2E)
#define SPSR_SPIF                   7
#define SPSR_WCOL                   6
#define SPSR_SPI2X                  0


#define SPDR   *((volatile u8*)0x2F)






/*		config file definations		*/

/********	interrupt	***********/
#define SPI_INTERRUPT_ENABLE		1
#define SPI_INTERRUPT_DISABLE		2

/********	mode	***********/
#define SPI_MASTER					1
#define SPI_SLAVE					2

/********	clock	***********/
#define SPI_CLK_OVER_4				1
#define SPI_CLK_OVER_16				2
#define SPI_CLK_OVER_64				3
#define SPI_CLK_OVER_128			4
#define SPI_HCLK_OVER_2				5
#define SPI_HCLK_OVER_8				6
#define SPI_HCLK_OVER_32			7
#define SPI_HCLK_OVER_64			8

/*****	clock plarity	****/
#define SPI_POL_RISING				1
#define SPI_POL_FALLING				2

/*****	clock phase		****/
#define SPI_LEADING_SETUP			1
#define SPI_LEADING_SAMPLE			2

#endif