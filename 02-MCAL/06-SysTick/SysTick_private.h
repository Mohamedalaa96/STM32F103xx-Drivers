/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 19 April 2021                                                                      */
/* Version      : V03                                                                                */
/*****************************************************************************************************/


#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define STK_BASE    0xE000E010

typedef struct 
{
    u32 CTRL ;
    u32 LOAD ;
    u32 VAL  ;
    u32 CALIB;
}STK_t;

#define STK ((volatile STK_t *) STK_BASE)

/* Control Bits Locations */
#define MSTK_ENABLE_BIT     0
#define MSTK_TICK_INT_BIT   1

/* CLOCK SOURCE OPTIONS */
#define SYSTICK_AHB_DIV_8   0
#define SYSTICK_AHB         1   

/* Underflow Interrupt OPTIONS */
#define SYSTICK_ENABLED    1
#define SYSTICK_DISABLED   0

 
/* 0 Single , 1 Periodic */
#define			MSTK_SINGLE_INTERVAL		0
#define			MSTK_PERIOD_INTERVAL		1

#endif