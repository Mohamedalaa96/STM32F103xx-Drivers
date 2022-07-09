/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 10 April 2021                                                                      */
/* Version      : V01                                                                                */
/*****************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTConfig(u8 copy_u8EXTILine, u8 copy_u8Port)
{
    u8 Local_u8Index= copy_u8EXTILine/4;
    AFIO->EXTICR[Local_u8Index] &=    ~(0b1111 << ((copy_u8EXTILine%4) *4));    //Clear the location.
    AFIO->EXTICR[Local_u8Index] |=  copy_u8Port << ((copy_u8EXTILine%4) *4);


}
