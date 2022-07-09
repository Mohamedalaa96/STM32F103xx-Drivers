/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 31 Auguest 2020                                                                    */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

//************************** user configurable pramitters **************************//

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/* Options:     RCC_HSE_CRYSTAL
                RCC_HSE_RC
                RCC_HSI
                RCC_PLL         */

#define RCC_CLOCK_TYPE      RCC_PLL




/* Note : Select only if PLL is selected as clock source */
#if RCC_CLOCK_TYPE == RCC_PLL 
    /*Options:      RCC_PLL_IN_HSI_DEV_2
                    RCC_PLL_IN_HSE_DEV_2
                    RCC_PLL_IN_HSE      */
    #define RCC_PLL_INPUT   RCC_PLL_IN_HSE_DEV_2
    
    /*Options :     
                2 to 16             */
    #define RCC_MUL_VAL     2

#endif

#endif
