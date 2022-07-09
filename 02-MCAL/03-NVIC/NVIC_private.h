/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 09 April 2021                                                                      */
/* Version      : V01                                                                                */
/*****************************************************************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS 0xE000E100

#define NVIC_ISER0        (* (u32 *) (NVIC_BASE_ADDRESS + 0x00) )      /*Enable External Interrupt from 0 : 32  */ 
#define NVIC_ISER1        (* (u32 *) (NVIC_BASE_ADDRESS + 0x04) )      /*Enable External Interrupt from 33 : 64 */

#define NVIC_ICER0        (* (u32 *) (NVIC_BASE_ADDRESS + 0x80) )      /*Disable External Interrupt from 0 : 32  */ 
#define NVIC_ICER1        (* (u32 *) (NVIC_BASE_ADDRESS + 0x84) )      /*Disable External Interrupt from 33 : 64 */

#define NVIC_ISPR0        (* (u32 *) (NVIC_BASE_ADDRESS + 0x100) )      /*Set The Pending Flag for interrupt 0 : 32  */ 
#define NVIC_ISPR1        (* (u32 *) (NVIC_BASE_ADDRESS + 0x104) )      /*Set The Pending Flag for interrupt 33 : 64 */

#define NVIC_ICPR0        (* (u32 *) (NVIC_BASE_ADDRESS + 0x180) )      /*Clear The Pending Flag for interrupt 0 : 32  */ 
#define NVIC_ICPR1        (* (u32 *) (NVIC_BASE_ADDRESS + 0x184) )      /*Clear The Pending Flag for interrupt 33 : 64 */

/* Voltaile becuase its read only register , the compiler think its not changing why you access it in the code it will make it read once only 
   Then use this result for the rest of the code */
#define NVIC_IABR0        (* (volatile u32 *) (NVIC_BASE_ADDRESS + 0x200) )      /*Get active flag bit (1-> interrupt is excuiting) 00 : 32 */ 
#define NVIC_IABR1        (* (volatile u32 *) (NVIC_BASE_ADDRESS + 0x204) )      /*Get active flag bit (1-> interrupt is excuiting) 33 : 64 */

#define NVIC_IPR          ( (volatile u8 *) (NVIC_BASE_ADDRESS + 0x300) )      /*Byte Accessable Register , I will Access it as array , the array operation will dereferance*/

/*Options for Proirity_Grouping*/
#define GRPOUP_16_SUB_0     0x05FA0300          /* 16 Groups (4 bits ) and 0 sub groups (0 bits )*/
#define GRPOUP_8_SUB_2      0x05FA0400          /* 8 Groups  (3 bits ) and 0 sub groups (1 bits )*/
#define GRPOUP_4_SUB_4      0x05FA0500          /* 4 Groups  (2 bits ) and 0 sub groups (2 bits )*/
#define GRPOUP_2_SUB_8      0x05FA0600          /* 2 Groups  (1 bits ) and 0 sub groups (3 bits )*/
#define GRPOUP_0_SUB_16     0x05FA0700          /* 0 Groups  (0 bits ) and 0 sub groups (4 bits )*/

 /*Should Write 0x5FA to bits from 31-16 to allow the writing process*/
 /*Bit 10:8 determines the split of group priority from subpriority*/
#define SCB_AIRCR        (* ( u32 *) (NVIC_BASE_ADDRESS + 0x0C) )      /*Application interrupt and reset control register */


#endif
