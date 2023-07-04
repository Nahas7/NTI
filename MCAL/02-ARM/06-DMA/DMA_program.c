/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: DMA													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

void DMA_vidInit(void)
{
	/*Disable Channel*/
	
	
	/*	Memory to memory
		channel 0 
		PINC & MINC active
		periority very high
	*/
	DMA->Channels[0].SCR = 0x00035690;
}

void DMA_vidTransfer(u32* Copy_u32SourceAdd , u32* Copy_u32DistAdd , u16 Copy_u16Num)
{
	/*Disable the channel*/
	CLR_BIT(DMA->Channels[0].SCR , 0);
	
	/*set source */
	DMA->channels[0].SM0AR = Copy_u32SourceAdd ;
	/*set dist.*/
	DMA->Channels[0].SM1AR = Copy_u32DistAdd ;
	
	/*Enable the channel*/
	SET_BIT(DMA->Channels[0].SCR , 0);

}