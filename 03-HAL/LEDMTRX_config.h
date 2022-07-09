/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 12 May 2021                                                                        */
/* Version      : V01                                                                                */
/*****************************************************************************************************/


#ifndef LEDMTRX_CONFIG_H
#define LEDMTRX_CONFIG_H

/* Please Write Pin Pair PORT,PIN */
#define LEDMTRX_ROW0_PIN    GPIOA,0
#define LEDMTRX_ROW1_PIN    GPIOA,1
#define LEDMTRX_ROW2_PIN    GPIOA,2
#define LEDMTRX_ROW3_PIN    GPIOA,3
#define LEDMTRX_ROW4_PIN    GPIOA,4
#define LEDMTRX_ROW5_PIN    GPIOA,5
#define LEDMTRX_ROW6_PIN    GPIOA,6
#define LEDMTRX_ROW7_PIN    GPIOA,7

#define LEDMTRX_COL0_PIN    GPIOB,0
#define LEDMTRX_COL1_PIN    GPIOB,1
#define LEDMTRX_COL2_PIN    GPIOB,5
#define LEDMTRX_COL3_PIN    GPIOB,6
#define LEDMTRX_COL4_PIN    GPIOB,7
#define LEDMTRX_COL5_PIN    GPIOB,8
#define LEDMTRX_COL6_PIN    GPIOB,9
#define LEDMTRX_COL7_PIN    GPIOB,10


#endif

MGPIO_voidSetPinValue (LEDMTRX_ROW0_PIN,1);
MGPIO_voidSetPinValue (LEDMTRX_ROW1_PIN,1);
MGPIO_voidSetPinValue (LEDMTRX_ROW2_PIN,1);
MGPIO_voidSetPinValue (LEDMTRX_ROW3_PIN,1);
MGPIO_voidSetPinValue (LEDMTRX_ROW4_PIN,1);
MGPIO_voidSetPinValue (LEDMTRX_ROW5_PIN,1);
MGPIO_voidSetPinValue (LEDMTRX_ROW6_PIN,1);
MGPIO_voidSetPinValue (LEDMTRX_ROW7_PIN,1);

MGPIO_voidSetPinValue (LEDMTRX_COL0_PIN,0);
MGPIO_voidSetPinValue (LEDMTRX_COL1_PIN,0);
MGPIO_voidSetPinValue (LEDMTRX_COL2_PIN,0);
MGPIO_voidSetPinValue (LEDMTRX_COL3_PIN,0);
MGPIO_voidSetPinValue (LEDMTRX_COL4_PIN,0);
MGPIO_voidSetPinValue (LEDMTRX_COL5_PIN,0);
MGPIO_voidSetPinValue (LEDMTRX_COL6_PIN,0);
MGPIO_voidSetPinValue (LEDMTRX_COL7_PIN,0);


