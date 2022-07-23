/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 16 April 2021                                                                      */
/* Version      : V02.1                                                                                */
/*****************************************************************************************************/


#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#ifndef SYS_FREQ
    #define SYS_FQ                  8000000             /// Defualt 8 MHz
#endif


#define mS_TO_TICK(x)           ((x/1000)*(SYS_FQ /8))      /// AHB / 8 by defualt
#define uS_TO_TICK(x)           ((x)*(SYS_FQ /8))           /// AHB / 8 by defualt

void MSTK_voidInit(void);
//Delay and hold the CPU for few cycles.
void MSTK_voidSetBusyWait(u32 copy_u32Ticks);
/* Set single interval , after done call the function provided */           
void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*copy_ptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr)(void));
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTicks(void);
u32  MSTK_u32GetRemainingTicks(void);

#endif