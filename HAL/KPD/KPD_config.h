/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: Keypad												  */
/*								 Layer  : HAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H
	
#define KPD_R1_PORT		DIO_PORTC
#define KPD_R1_PIN		DIO_PIN5
				
#define KPD_R2_PORT		DIO_PORTC
#define KPD_R2_PIN		DIO_PIN4

#define KPD_R3_PORT		DIO_PORTC
#define KPD_R3_PIN		DIO_PIN3

#define KPD_R4_PORT		DIO_PORTC
#define KPD_R4_PIN		DIO_PIN2


#define KPD_C1_PORT		DIO_PORTD
#define KPD_C1_PIN		DIO_PIN7

#define KPD_C2_PORT		DIO_PORTD
#define KPD_C2_PIN		DIO_PIN6

#define KPD_C3_PORT		DIO_PORTD
#define KPD_C3_PIN		DIO_PIN5

#define KPD_C4_PORT		DIO_PORTD
#define KPD_C4_PIN		DIO_PIN3


#define	ROW_ARR_PORTS	{DIO_PORTC , DIO_PORTC ,DIO_PORTC , DIO_PORTC}
#define ROW_ARR_PINS	{DIO_PIN5 , DIO_PIN4 ,DIO_PIN3 , DIO_PIN2}

#define COL_ARR_PORTS	{DIO_PORTD , DIO_PORTD ,DIO_PORTD , DIO_PORTD}
#define COL_ARR_PINS	{DIO_PIN7 , DIO_PIN6 ,DIO_PIN5 , DIO_PIN3}

#define KPD_ARR_VAL		 {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}} 






#endif