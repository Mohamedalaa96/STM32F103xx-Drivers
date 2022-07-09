/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 17 April 2020                                                                      */
/* Version      : V02                                                                                */
/*****************************************************************************************************/

/* Include Required files from Library Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include files from Lower levels */
/* Include Driver own files */

#include "GPIO_interface.h"
#include "GPIO_private.h"



void MGPIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode){

    switch (copy_u8PORT)
    {
    case GPIOA:
        if (copy_u8PIN <= 7){
            GPIOA_CRL &=  ~( 0x0000000F << (copy_u8PIN * 4));
            GPIOA_CRL |=  copy_u8Mode << (copy_u8PIN * 4);
        }
        else if (copy_u8PIN <= 15){
            GPIOA_CRH &=  ~( 0x0000000F << ((copy_u8PIN-8)* 4));
            GPIOA_CRH |=  copy_u8Mode << ((copy_u8PIN-8) * 4);
        }
        break;
    case GPIOB:
        if (copy_u8PIN <= 7){
            GPIOB_CRL &=  ~( 0x0000000F << (copy_u8PIN* 4));
            GPIOB_CRL |=  copy_u8Mode << (copy_u8PIN * 4);
        }
        else if (copy_u8PIN <= 15){
            GPIOB_CRH &=  ~( 0x0000000F << ((copy_u8PIN-8)* 4));
            GPIOB_CRH |=  copy_u8Mode << ((copy_u8PIN-8) * 4);
        }
        break;
    case GPIOC:
        if (copy_u8PIN <= 7){
            GPIOC_CRL &=  ~( 0x0000000F << (copy_u8PIN* 4));
            GPIOC_CRL |=  copy_u8Mode << (copy_u8PIN * 4);
        }
        else if (copy_u8PIN <= 15){
            GPIOC_CRH &=  ~( 0x0000000F << ((copy_u8PIN-8)* 4));
            GPIOC_CRH |=  copy_u8Mode << ((copy_u8PIN-8) * 4);
        }
        break;
    
    }

}
void MGPIO_voidSetPinValue     (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value){

	switch (copy_u8PORT)
    {
    case GPIOA:
        if (copy_u8Value == 0){
            SET_BIT(GPIOA_BRR,copy_u8PIN); //Change it to ODR in the rest
        }
        else {
            SET_BIT(GPIOA_BSR,copy_u8PIN);
        }
        break;
    case GPIOB:
        if (copy_u8Value == 0){
            SET_BIT(GPIOB_BRR,copy_u8PIN);
        }
        else {
            SET_BIT(GPIOB_BSR,copy_u8PIN);
        }
        break;
    case GPIOC:
        if (copy_u8Value == 0){
            SET_BIT(GPIOC_BRR,copy_u8PIN);
        }
        else {
            SET_BIT(GPIOC_BSR,copy_u8PIN);
        }
        break;
    }


}
u8  MGPIO_u8GetPinValue  (u8 copy_u8PORT, u8 copy_u8PIN){
	u8 LOC_u8Result =0;
	switch (copy_u8PORT)
        {
        case GPIOA:
        	LOC_u8Result = GET_BIT(GPIOA_IDR,copy_u8PIN);
            break;
        case GPIOB:
        	LOC_u8Result =  GET_BIT(GPIOB_IDR,copy_u8PIN);
            break;
        case GPIOC:
        	LOC_u8Result = GET_BIT(GPIOC_IDR,copy_u8PIN);
        }
	return LOC_u8Result;
    
}

void MGPIO_voidTogglePin     (u8 copy_u8PORT, u8 copy_u8PIN){

	switch (copy_u8PORT)
    {
    case GPIOA:
        TOG_BIT(GPIOA_ODR,copy_u8PIN); //Change it to ODR in the rest
        break;
    case GPIOB:
        TOG_BIT(GPIOA_ODR,copy_u8PIN);
        break;
    case GPIOC:
        TOG_BIT(GPIOA_ODR,copy_u8PIN);
        break;
    }


}
