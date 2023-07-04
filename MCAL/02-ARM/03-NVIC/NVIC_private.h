/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: NVIC													  */
/*								 Layer  : MCAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NVIC_BASE_ADD					((u32)(0xE000E100))

#define (NVIC_ISER0)					*((volatile u32*)(0x100 + NVIC_BASE_ADD))
#define (NVIC_ISER1)					*((volatile u32*)(0x104 + NVIC_BASE_ADD))
#define (NVIC_ISER2)					*((volatile u32*)(0x108 + NVIC_BASE_ADD))
#define (NVIC_ISER3)					*((volatile u32*)(0x10C + NVIC_BASE_ADD))
#define (NVIC_ISER4)					*((volatile u32*)(0x110 + NVIC_BASE_ADD))
#define (NVIC_ISER5)					*((volatile u32*)(0x114 + NVIC_BASE_ADD))
#define (NVIC_ISER6)					*((volatile u32*)(0x118 + NVIC_BASE_ADD))
#define (NVIC_ISER7)					*((volatile u32*)(0x11C + NVIC_BASE_ADD))

#define (NVIC_ICER0)					*((volatile u32*)(0x180 + NVIC_BASE_ADD))
#define (NVIC_ICER1)					*((volatile u32*)(0x184 + NVIC_BASE_ADD))
#define (NVIC_ICER2)					*((volatile u32*)(0x188 + NVIC_BASE_ADD))
#define (NVIC_ICER3)					*((volatile u32*)(0x18C + NVIC_BASE_ADD))
#define (NVIC_ICER4)					*((volatile u32*)(0x190 + NVIC_BASE_ADD))
#define (NVIC_ICER5)					*((volatile u32*)(0x194 + NVIC_BASE_ADD))
#define (NVIC_ICER6)					*((volatile u32*)(0x198 + NVIC_BASE_ADD))
#define (NVIC_ICER7)					*((volatile u32*)(0x19C + NVIC_BASE_ADD))

#define (NVIC_ISPR0)					*((volatile u32*)(0x200 + NVIC_BASE_ADD))
#define (NVIC_ISPR1)					*((volatile u32*)(0x204 + NVIC_BASE_ADD))
#define (NVIC_ISPR2)					*((volatile u32*)(0x208 + NVIC_BASE_ADD))
#define (NVIC_ISPR3)					*((volatile u32*)(0x20C + NVIC_BASE_ADD))
#define (NVIC_ISPR4)					*((volatile u32*)(0x210 + NVIC_BASE_ADD))
#define (NVIC_ISPR5)					*((volatile u32*)(0x214 + NVIC_BASE_ADD))
#define (NVIC_ISPR6)					*((volatile u32*)(0x218 + NVIC_BASE_ADD))
#define (NVIC_ISPR7)					*((volatile u32*)(0x21C + NVIC_BASE_ADD))

#define (NVIC_ICPR0)					*((volatile u32*)(0x280 + NVIC_BASE_ADD))
#define (NVIC_ICPR1)					*((volatile u32*)(0x284 + NVIC_BASE_ADD))
#define (NVIC_ICPR2)					*((volatile u32*)(0x288 + NVIC_BASE_ADD))
#define (NVIC_ICPR3)					*((volatile u32*)(0x28C + NVIC_BASE_ADD))
#define (NVIC_ICPR4)					*((volatile u32*)(0x290 + NVIC_BASE_ADD))
#define (NVIC_ICPR5)					*((volatile u32*)(0x294 + NVIC_BASE_ADD))
#define (NVIC_ICPR6)					*((volatile u32*)(0x298 + NVIC_BASE_ADD))
#define (NVIC_ICPR7)					*((volatile u32*)(0x29C + NVIC_BASE_ADD))

#define (NVIC_IABR0)					*((volatile u32*)(0x300 + NVIC_BASE_ADD))
#define (NVIC_IABR1)					*((volatile u32*)(0x304 + NVIC_BASE_ADD))
#define (NVIC_IABR2)					*((volatile u32*)(0x308 + NVIC_BASE_ADD))
#define (NVIC_IABR3)					*((volatile u32*)(0x30C + NVIC_BASE_ADD))
#define (NVIC_IABR4)					*((volatile u32*)(0x310 + NVIC_BASE_ADD))
#define (NVIC_IABR5)					*((volatile u32*)(0x314 + NVIC_BASE_ADD))
#define (NVIC_IABR6)					*((volatile u32*)(0x318 + NVIC_BASE_ADD))
#define (NVIC_IABR7)					*((volatile u32*)(0x31C + NVIC_BASE_ADD))



#define NVIC_IPR						((volatile u8*)(0x400 + NVIC_BASE_ADD))





#define GRP_16_SUB_0					((u32)0x5FA00300)
#define GRP_8_SUB_2						((u32)0x5FA00400)
#define GRP_8_SUB_0						((u32)0x5FA00400)
#define GRP_8_SUB_0						((u32)0x5FA00400)
#define GRP_8_SUB_0						((u32)0x5FA00400)

#define GRP_8_SUB_0						((u32)0x5FA00400)

#define GRP_4_SUB_4						((u32)0x5FA00500)


#endif