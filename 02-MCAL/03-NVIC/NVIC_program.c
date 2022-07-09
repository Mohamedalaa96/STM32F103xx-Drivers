/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 09 April 2021                                                                      */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void)
{
    /* Distribute the Grouping Bits */
    
    SCB_AIRCR = MNVIC_Proirity_Grouping;  /* SET Priority Grouping Option */


}

void MNVIC_voidEnableInterrupt(u8 copy_u8InterruptNumber){
    if (copy_u8InterruptNumber <= 31)
    {
        NVIC_ISER0 = (1<< copy_u8InterruptNumber);
    }
    else if (copy_u8InterruptNumber <= 59)  /*MAX is 59 in ST Controllers*/
    {
        copy_u8InterruptNumber-=32;
        NVIC_ISER1= (1 << copy_u8InterruptNumber);
    }
   

}


void MNVIC_voidDisableInterrupt(u8 copy_u8InterruptNumber){
    if (copy_u8InterruptNumber <= 31)
    {
        NVIC_ICER0 = 1<< copy_u8InterruptNumber;
    }
    else if (copy_u8InterruptNumber <= 59)  /*MAX is 59 in ST Controllers*/
    { 
        copy_u8InterruptNumber-=32;
        NVIC_ICER1= (1 << copy_u8InterruptNumber);
    }
   

}


void MNVIC_voidSetPendingFlag(u8 copy_u8InterruptNumber){
    if (copy_u8InterruptNumber <= 31)
    {
        NVIC_ISPR0 = (1<< copy_u8InterruptNumber);
    }
    else if (copy_u8InterruptNumber <= 59)  /*MAX is 59 in ST Controllers*/
    {
        copy_u8InterruptNumber-=32;
        NVIC_ISPR1= 1<< (copy_u8InterruptNumber);
    }
   

}



void MNVIC_voidClearPendingFlag(u8 copy_u8InterruptNumber){
    if (copy_u8InterruptNumber <= 31)
    {
        NVIC_ICPR0 = 1<< copy_u8InterruptNumber;
    }
    else if (copy_u8InterruptNumber <= 59)  /*MAX is 59 in ST Controllers*/
    {
        copy_u8InterruptNumber-=32;
        NVIC_ICPR1= 1<< (copy_u8InterruptNumber);
    }
   

}

u8 MNVIC_u8GetActiveFlag(u8 copy_u8InterruptNumber) /*Read Only Register*/
{
    u8 Local_u8rResult = 0;
    if (copy_u8InterruptNumber <= 31)
    {
        Local_u8rResult = GET_BIT(NVIC_IABR0,copy_u8InterruptNumber);
    }
    else if (copy_u8InterruptNumber <= 59)  /*MAX is 59 in ST Controllers*/
    {
        copy_u8InterruptNumber-=32;
        Local_u8rResult = GET_BIT(NVIC_IABR1,copy_u8InterruptNumber);
    }
    
    return Local_u8rResult;
}

void MNVIC_voidSetPriority(u8 copy_u8InterruptNumber, u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority)
{   
    //Grouping value from SCB_AIRCR register - 0x05FA0300 [base address for 4bit group, 0bit sub] = no of sub  bits >> 8 to remove the two zeros in front(or divide by 8). 
    // group bits << no of sub  bits (to empty the location of sub bits that we calculated the number of it from privious step) then or the sub bits . 
    u32 Local_u32Priority = ( (Copy_u8GroupPriority << ((MNVIC_Proirity_Grouping - 0x05FA0300) /0x100 ) ) | Copy_u8SubPriority);
   
    if (Copy_u8GroupPriority <= 15 && copy_u8InterruptNumber <= 59 )
    {
        NVIC_IPR[copy_u8InterruptNumber]= Local_u32Priority << 4; /* Uses MSB 4 bits only as the 4 priority bits from the 8 bits*/
   }
   


}