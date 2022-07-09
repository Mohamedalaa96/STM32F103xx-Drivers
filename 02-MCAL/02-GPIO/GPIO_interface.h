/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 17 April 2020                                                                      */
/* Version      : V02                                                                                */
/*****************************************************************************************************/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


#define HIGH 1
#define LOW 0
                /*    GPIO Selection Definition       */
#define GPIOA                       0
#define GPIOB                       1
#define GPIOC                       2
#define GPIOD                       3

                /*      OUTPUT Modes        */
#define OUTPUT_GP_PP_50MHz             0b0011       //General Purpose Push Pull
#define OUTPUT_GP_OD_50MHz             0b0111       //General Purpose Open Drain
#define OUTPUT_AF_PP_50MHz             0b1011       //Alternative Function Push Pull
#define OUTPUT_AF_OD_50MHz             0b1111       //Alternative Function Open Drain


#define OUTPUT_GP_PP_2MHz              0b0010       //General Purpose Push Pull
#define OUTPUT_GP_OD_2MHz              0b0110       //General Purpose Open Drain
#define OUTPUT_AF_PP_2MHz              0b1010       //Alternative Function Push Pull
#define OUTPUT_AF_OD_2MHz              0b1110       //Alternative Function Open Drain

#define OUTPUT_GP_PP_10MHz             0b0001       //General Purpose Push Pull
#define OUTPUT_GP_OD_10MHz             0b0101       //General Purpose Open Drain
#define OUTPUT_AF_PP_10MHz             0b1001       //Alternative Function Push Pull
#define OUTPUT_AF_OD_10MHz             0b1101       //Alternative Function Open Drain

                /*      INPUT Modes        */
#define INPUT_ANALOG                   0b0000       //Input Mode Analog
#define INPUT_FLOATING                 0b0100       //Input Floating
#define INPUT_PUPD                     0b1000       //Input pull-up pull-down


/**** Options : 
   
    *      OUTPUT Modes        *
        OUTPUT_GP_PP_50MHz            //General Purpose Push Pull 
        OUTPUT_GP_OD_50MHz            //General Purpose Open Drain
        OUTPUT_AF_PP_50MHz            //Alternative Function Push Pull
        OUTPUT_AF_PP_50MHz            //Alternative Function Open Drain


        OUTPUT_GP_PP_2MHz             //General Purpose Push Pull 
        OUTPUT_GP_OD_2MHz             //General Purpose Open Drain
        OUTPUT_AF_PP_2MHz             //Alternative Function Push Pull
        OUTPUT_AF_PP_2MHz             //Alternative Function Open Drain

        OUTPUT_GP_PP_10MHz            //General Purpose Push Pull 
        OUTPUT_GP_OD_10MHz            //General Purpose Open Drain
        OUTPUT_AF_PP_10MHz            //Alternative Function Push Pull
        OUTPUT_AF_PP_10MHz            //Alternative Function Open Drain

        *      INPUT Modes        *
        
        INPUT_ANALOG                  //Input Mode Analog 
        INPUT_FLOATING                //Input Floating 
        INPUT_PUPD                    //Input pull-up pull-down
    
    PORT    : 
        GPIOA , GPIOB, GPIOC , GPIOD
    Pins    : 
        0 -> 15
    Value   : 
        0 , 1 


*************************/

void MGPIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode);
void MGPIO_voidSetPinValue     (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value);
u8   MGPIO_u8GetPinValue       (u8 copy_u8PORT, u8 copy_u8PIN);
void MGPIO_voidTogglePin(u8 copy_u8PORT, u8 copy_u8PIN);

#endif
