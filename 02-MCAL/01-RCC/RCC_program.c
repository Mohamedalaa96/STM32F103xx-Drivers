/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 31 Auguest 2020                                                                    */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

/* Include Required files from Library Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include files from Lower levels */
/* Include Driver own files */

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


//03-00-00

void RCC_voidInitSysClock(void){
    #if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        RCC_CFGR =  0x0000001; 
        RCC_CR   = 0x00010000;                                /*  Enable HSE , clear clock bypass */ 
    #elif   RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CFGR =  0x0000001;
        RCC_CR = 0x00050000;                                /*  Enable HSE , set clock bypass*/
    #elif   RCC_CLOCK_TYPE == RCC_HSI
        RCC_CFGR =  0x0000000;
        RCC_CR = 0x00000081;                                /*  Enable HSI + trimming value (default 10000)  */
    #elif   RCC_CLOCK_TYPE == RCC_PLL
        #if RCC_PLL_INPUT == RCC_PLL_IN_HSE
            RCC_CFGR = RCC_MUL_VAL << (18 + 0x00010001);      /* PLLSRC = 1 HSE + RCC_MUL_VAL + SW =1 (HSE)*/
            RCC_CR   = 0x01010000;                          /*  Enable HSE, PLL*/
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DEV_2 
            RCC_CFGR = RCC_MUL_VAL << (18 + 0x00030001);      /* PLLSRC = 1 HSE + PLLXTPRE = 1 (HSE/2)+ RCC_MUL_VAL + SW=1 (HSE)*/
            RCC_CR   = 0x01010000;                          /*  Enable HSE, PLL*/
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSI_DEV_2 
            RCC_CFGR = RCC_MUL_VAL << (18 + 0x00000000);       /* PLLSRC = 1 HSE + PLLXTPRE = 1 (HSE/2)+ RCC_MUL_VAL*/
            RCC_CR   = 0x01000001;                          /*  Enable HSI, PLL*/
        #endif
    #else 
        #error ("you choosed wrong clock type") //build error 
    
    #endif


}

void RCC_voidEnableClock(u8 Copy_u8BusId ,u8 Copy_u8PeripheralId){
    //Argument Validation.
    if (Copy_u8PeripheralId <= 31 ){        // every register is 32 bit , 0-31 otherwise error.

        switch (Copy_u8BusId)
        {
        case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PeripheralId); break;
            
        case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PeripheralId); break;

            /* code */
        case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PeripheralId); break;

        //default       :   /*Return Error */               break;
            
        }

    }
    else {

        //return error 
    }
    
}

void RCC_voidDisableClock(u8 Copy_u8BusId ,u8 Copy_u8PeripheralId){   /*#hello   */
    if (Copy_u8PeripheralId <= 31 ){ 

        switch (Copy_u8BusId)
        {
        case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PeripheralId); break;
            
        case RCC_APB1 : CLR_BIT(RCC_AHBENR,Copy_u8PeripheralId); break;

            /* code */
        case RCC_APB2 : CLR_BIT(RCC_AHBENR,Copy_u8PeripheralId); break;

        //default       :   /*Return Error */               break;
            
        }

    }
    else {

        //return error 
    }
    
}

