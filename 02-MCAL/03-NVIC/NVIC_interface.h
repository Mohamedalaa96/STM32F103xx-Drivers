/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 09 April 2021                                                                      */
/* Version      : V01                                                                                */
/*****************************************************************************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H



/* Options for Interrupt Number */
#define NVIC_WWDG 		00
#define NVIC_PVD 		01
#define NVIC_TAMPER 	02
#define NVIC_RTC 		03
#define NVIC_FLASH		04
#define NVIC_RCC	 	05
#define NVIC_EXTI0 		06
#define NVIC_EXTI1 		07
#define NVIC_EXTI2 		08
#define NVIC_EXTI3 		09
#define NVIC_EXTI4 		10

/*Options for Priority*/
#define GRPOUP_16_SUB_0     0x05FA0300          /* 16 Groups (4 bits ) and 0 sub groups (0 bits )*/
#define GRPOUP_8_SUB_2      0x05FA0400          /* 8 Groups  (3 bits ) and 0 sub groups (1 bits )*/
#define GRPOUP_4_SUB_4      0x05FA0500          /* 4 Groups  (2 bits ) and 0 sub groups (2 bits )*/
#define GRPOUP_2_SUB_8      0x05FA0600          /* 2 Groups  (1 bits ) and 0 sub groups (3 bits )*/
#define GRPOUP_0_SUB_16     0x05FA0700          /* 0 Groups  (0 bits ) and 0 sub groups (4 bits )*/

void MNVIC_voidInit(void);

void MNVIC_voidEnableInterrupt(u8 copy_u8InterruptNumber);
void MNVIC_voidDisableInterrupt(u8 copy_u8InterruptNumber);

void MNVIC_voidSetPendingFlag(u8 copy_u8InterruptNumber);
void MNVIC_voidClearPendingFlag(u8 copy_u8InterruptNumber);

u8 MNVIC_u8GetActiveFlag(u8 copy_u8InterruptNumber);

void MNVIC_voidSetPriority(u8 copy_u8InterruptNumber, u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority);



#endif
