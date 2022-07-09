/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 20 April 2021                                                                      */
/* Version      : V02                                                                                */
/*****************************************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Signal Latching Modes    */
/*  MEXTI_RAISING                */
/*  MEXTI_FALLING                */
/*  MEXTI_ON_CHANGE              */
#define MEXTI_EXTLINE0        0
#define MEXTI_EXTLINE1        1
#define MEXTI_EXTLINE2        2
#define MEXTI_EXTLINE3        3
#define MEXTI_EXTLINE4        4
#define MEXTI_EXTLINE5        5
#define MEXTI_EXTLINE6        6
#define MEXTI_EXTLINE7        7
#define MEXTI_EXTLINE8        8
#define MEXTI_EXTLINE9        9
#define MEXTI_EXTLINE10       10
#define MEXTI_EXTLINE11       11
#define MEXTI_EXTLINE12       12
#define MEXTI_EXTLINE13       13
#define MEXTI_EXTLINE14       14
#define MEXTI_EXTLINE15       15

#define MEXTI_FALLING      0
#define MEXTI_RAISING      1
#define MEXTI_ON_CAHNGE    2
/* Interrupt Line 0:15 */
void MEXTI_voidInit();
void MEXTI_voidSetSignalLatch(u8 copy_u8InterruptLine,u8 copy_u8SignalLatchMode);
void MEXTI_voidDisableInterrupt(u8 copy_u8InterruptLine);
void MEXTI_voidSoftwareTrigger(u8 copy_u8InterruptLine);
void MEXTI_voidSetCallback(u8 copy_u8InterruptLine,void (*copy_voidPtr)(void));


#endif
