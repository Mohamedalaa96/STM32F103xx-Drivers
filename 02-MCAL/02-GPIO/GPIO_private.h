/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 31 Auguest 2020                                                                    */
/* Version      : V01                                                                                */
/*****************************************************************************************************/


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define HIGH                    1
#define LOW                     0



                /*    Register Definition       */
#define GPIOA_BASE                  0x40010800U
#define GPIOB_BASE                  0x40010C00U
#define GPIOC_BASE                  0x40011000U
#define GPIOD_BASE                  0x40011400U

                /*  PORT A Register Adresses    */
#define GPIOA_CRL                    (* ( u32*) (GPIOA_BASE + 0x00U ) )
#define GPIOA_CRH                    (* ( u32*) (GPIOA_BASE + 0x04U ) )
#define GPIOA_IDR                    (* ( u32*) (GPIOA_BASE + 0x08U ) )
#define GPIOA_ODR                    (* ( u32*) (GPIOA_BASE + 0x0CU ) )
#define GPIOA_BSR                    (* ( u32*) (GPIOA_BASE + 0x10U ) )
#define GPIOA_BRR                    (* ( u32*) (GPIOA_BASE + 0x14U ) )
#define GPIOA_LCK                    (* ( u32*) (GPIOA_BASE + 0x18U ) )

                /*  PORT B Register Adresses    */
#define GPIOB_CRL                    (* ( u32*) (GPIOB_BASE + 0x00U ) )
#define GPIOB_CRH                    (* ( u32*) (GPIOB_BASE + 0x04U ) )
#define GPIOB_IDR                    (* ( u32*) (GPIOB_BASE + 0x08U ) )
#define GPIOB_ODR                    (* ( u32*) (GPIOB_BASE + 0x0CU ) )
#define GPIOB_BSR                    (* ( u32*) (GPIOB_BASE + 0x10U ) )
#define GPIOB_BRR                    (* ( u32*) (GPIOB_BASE + 0x14U ) )
#define GPIOB_LCK                    (* ( u32*) (GPIOB_BASE + 0x18U ) )
                /*  PORT C Register Adresses    */
#define GPIOC_CRL                    (* ( u32*) (GPIOC_BASE + 0x00U ) )     //Control Register LOW 
#define GPIOC_CRH                    (* ( u32*) (GPIOC_BASE + 0x04U ) )     //Control Register HIGH
#define GPIOC_IDR                    (* ( u32*) (GPIOC_BASE + 0x08U ) )     //Input Data Register
#define GPIOC_ODR                    (* ( u32*) (GPIOC_BASE + 0x0CU ) )     //Output Data Register
#define GPIOC_BSR                    (* ( u32*) (GPIOC_BASE + 0x10U ) )     //Bit Set Reset Register 
#define GPIOC_BRR                    (* ( u32*) (GPIOC_BASE + 0x14U ) )     //Bit Reset Register 
#define GPIOC_LCK                    (* ( u32*) (GPIOC_BASE + 0x18U ) )     //Bit Lock Register 



#endif
