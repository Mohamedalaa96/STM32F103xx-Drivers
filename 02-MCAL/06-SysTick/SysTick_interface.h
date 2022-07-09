/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 16 April 2021                                                                      */
/* Version      : V02                                                                                */
/*****************************************************************************************************/


#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

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