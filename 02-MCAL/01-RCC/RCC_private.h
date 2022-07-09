/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 31 Auguest 2020                                                                    */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

/************ Private is used for private functions & registers definitions**************************/


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/* Register Definition  */

#define RCC_BASE                0x40021000U
//************** AHB Peripheral Clock Enable Register **************//
#define RCC_CR                  (* ( u32*) (RCC_BASE + 0x00U ) )        //Clock Control Register 
#define RCC_CFGR                (* ( u32*) (RCC_BASE + 0x04U ) )        //Clock Configuration Register
#define RCC_CIR                 (* ( u32*) (RCC_BASE + 0x08U ) )        //Clock Interrupt Register 
#define RCC_APB2RSTR            (* ( u32*) (RCC_BASE + 0x0CU ) )        //APB2 Peripherial Reset Register
#define RCC_APB1RSTS            (* ( u32*) (RCC_BASE + 0x10U ) )        //APB1 Peripherial Reset Register
#define RCC_AHBENR              (* ( u32*) (RCC_BASE + 0x14U ) )        //AHB Peripheral Clock Enable Register
#define RCC_APB2ENR             (* ( u32*) (RCC_BASE + 0x18U ) )        //APB2 Peripheral Clock Enable Register
#define RCC_APB1ENR             (* ( u32*) (RCC_BASE + 0x1CU ) )        // APB1 Peripheral Clock Enable Register 
#define RCC_BDCR                (* ( u32*) (RCC_BASE + 0x20U ) )        //Backup Domain Control Register
#define RCC_CSR                 (* ( u32*) (RCC_BASE + 0x24U ) )        //Control / Status Register

/* Clock Types */
#define RCC_HSE_CRYSTAL         0
#define RCC_HSE_RC              1
#define RCC_HSI                 2
#define RCC_PLL                 3

/*PLL Options*/
#define RCC_PLL_IN_HSI_DEV_2    0
#define RCC_PLL_IN_HSE_DEV_2    1
#define RCC_PLL_IN_HSE          2

/*APB2 Pripherals*/
#define APB2_AFIO               0
#define APB2_PORTA              2
#define APB2_PORTB              3
#define APB2_PORTC              4
#define APB2_PORTD              5
#define APB2_PORTE              6
#define APB2_PORTF              7
#define APB2_PORTG              8
#define APB2_ADC1               9 
#define APB2_ADC2               10
#define APB2_TIM1               11
#define APB2_SPI1               12
#define APB2_TIM8               13
#define APB2_USART1             14
#define APB2_ADC3               15
#define APB2_TIM9               19 
#define APB2_TIM10              20 
#define APB2_TIM11              21


#endif