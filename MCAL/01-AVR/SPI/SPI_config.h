/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: SPI 													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_




/*	options : SPI_INTERRUPT_ENABLE
			  SPI_INTERRUPT_DISABLE
*/
#define SPI_INTERRUPT 		SPI_INTERRUPT_ENABLE




/*	options : SPI_MASTER
			  SPI_SLAVE
*/
#define SPI_MODE			SPI_MASTER




/*	options : SPI_CLK_OVER_4
              SPI_CLK_OVER_16
              SPI_CLK_OVER_64
              SPI_CLK_OVER_128
              SPI_HCLK_OVER_2
              SPI_HCLK_OVER_8
              SPI_HCLK_OVER_32
              SPI_HCLK_OVER_64			 
*/
#define SPI_u8_CLK_RATE		SPI_CLK_OVER_64



/*	options : SPI_POL_RISING
			  SPI_POL_FALLING
*/
#define SPI_CLK_POL			SPI_POL_RISING


/*	options : SPI_LEADING_SETUP
			  SPI_LEADING_SAMPLE
*/
#define SPI_LEADING			SPI_LEADING_SETUP


#endif