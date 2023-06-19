/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */
/*								 SWC	: TIMER0												  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#ifndef TIMER0_PRIVTAE_H_
#define TIMER0_PRIVTAE_H_



/*TIMER 0*/

typedef struct
{
	u8 CS00_CS02	: 3 ;
	u8 WGM01		: 1 ;
	u8 COM00_COM01	: 2 ;
	u8 WGM00		: 1 ;
	u8 FOC0			: 1 ;
}TCCR0_Bits ;

#define TCCR0					((volatile TCCR0_Bits*)0x53)
/*
#define TCCR0_FOC0              7
#define TCCR0_WGM00             6
#define TCCR0_COM01             5
#define TCCR0_COM00             4
#define TCCR0_WGM01             3
#define TCCR0_CS02              2
#define TCCR0_CS01				1
#define TCCR0_CS00				0
*/


#define TCNT0					*((volatile u8 *)0x52)


typedef struct
{
	u8 TOIE0		: 1 ;
	u8 OCIE0		: 1 ;
}TIMSK_Bits ;

#define TIMSK					((volatile TIMSK_Bits*)0x59)
/*
#define TIMSK_TOIE0				0
#define TIMSK_OCIE0				1
#define TIMSK_TOIE1				2
#define TIMSK_OCIE1B			3
#define TIMSK_OCIE1A			4
#define TIMSK_TICIE				5
*/

#define OCR0					*((volatile u8 *)0x5C)


/*TIMER 1*/
/*#define TCCR1A					*((volatile u8 *)(0x4F))
#define TCCR1A_COM1A1           7
#define TCCR1A_COM1A0           6
#define TCCR1A_COM1B1           5
#define TCCR1A_COM1B0           4
#define TCCR1A_FOC1A            3
#define TCCR1A_FOC1B            2
#define TCCR1A_WGM11			1
#define TCCR1A_WGM10			0

#define TCCR1B					*((volatile u8 *)(0x4E))

#define TCNT1H					*((volatile u8 *)(0x4D))

#define TCNT1L					*((volatile u8 *)(0x4C))

#define TCNT1					*((volatile u16 *)(0x4C))

#define ICR1H					*((volatile u8 *)(0x47))

#define ICR1L					*((volatile u8 *)(0x46))

#define ICR1					*((volatile u16 *)(0x46))

#define OCR1AL					*((volatile u8 *)(0x4A))

#define OCR1AH					*((volatile u8 *)(0x4B))

#define OCR1A					*((volatile u16 *)(0x4A))

#define OCR1BL					*((volatile u8 *)(0x48))

#define OCR1BH					*((volatile u8 *)(0x49))

#define OCR1B					*((volatile u16 *)(0x48))
*/

/******************************************************************************************************/

/*Clock selection*/

#define STOP_TIMER					0b000
#define NO_DEV						0b001
#define DEV_BY_8					0b010
#define DEV_BY_64					0b011
#define DEV_BY_256					0b100
#define DEV_BY_1024					0b101

/*Mode selection*/
#define NORMAL_MODE					1
#define CMP_MODE					2
#define FAST_NON_INVERTING_PWM		3

/*Mode of PWM*/
#define NON_INVERTING				0b10

#endif