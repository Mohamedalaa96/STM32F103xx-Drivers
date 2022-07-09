/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 19 April 2021                                                                      */
/* Version      : V03                                                                                */
/*****************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"


static void (*MSTK_Callback) (void);    //Pointer to function
static u8 MSTK_intervalMode = 0 ;    //variable to indicate its priodic or not

void MSTK_voidInit(void){
    
    #if     MSYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV_8
        STK -> CTRL = 0x00000000;
    #elif   MSYSTICK_CLOCK_SOURCE == SYSTICK_AHB
        STK -> CRTL = 0x00000040;
    #else
			#error"Wrong Choice Prescaller!"
	#endif
    
}

//Delay and hold the CPU for few cycles.
void MSTK_voidSetBusyWait(u32 copy_u32Ticks)
{
    #if copy_u32Ticks > 0x00FFFFFF
        #error "MAX TICKS in MSTK_voidSetBusyWait exceeded max is 0x00FFFFFF "
    #else 
        STK->LOAD = copy_u32Ticks;
        SET_BIT(STK->CTRL,MSTK_ENABLE_BIT);   //Enable Counter
        while (GET_BIT(STK->CTRL,16) == 0 ){ asm("NOP"); }  //Pooling on the Count flag
        CLR_BIT(STK->CTRL,MSTK_ENABLE_BIT);   //Disable Counter
        STK->LOAD =0;
        STK->VAL  =0;
    #endif
}
/* Set single interval , after done call the function provided */           
void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*copy_ptr)(void))
{
     #if copy_u32Ticks > 0x00FFFFFF
        #error "MAX TICKS in MSTK_voidSetBusyWait exceeded max is 0x00FFFFFF "
    #else 
        MSTK_intervalMode = MSTK_SINGLE_INTERVAL ;    //Non Priodic
        STK->LOAD = copy_u32Ticks;
        SET_BIT(STK->CTRL,MSTK_ENABLE_BIT);         //Enable Counter      
        MSTK_Callback = copy_ptr;
 
        SET_BIT(STK->CTRL,MSTK_TICK_INT_BIT);       //Enable Interrupt.   
        
    #endif
    
}
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr)(void))
{
      #if copy_u32Ticks > 0x00FFFFFF
        #error "MAX TICKS in MSTK_voidSetBusyWait exceeded max is 0x00FFFFFF "
    #else 
        MSTK_intervalMode = MSTK_PERIOD_INTERVAL ;    //Non Priodic
        STK->LOAD = copy_u32Ticks;
        SET_BIT(STK->CTRL,MSTK_ENABLE_BIT);         //Enable Counter   
        MSTK_Callback = copy_ptr;    
        SET_BIT(STK->CTRL,MSTK_TICK_INT_BIT);       //Enable Interrupt.   
        
    #endif
}
void MSTK_voidStopInterval(void)
{
   
    CLR_BIT(STK->CTRL,MSTK_ENABLE_BIT);         //Disable Counter       
    CLR_BIT(STK->CTRL,MSTK_TICK_INT_BIT);       //Disable Interrupt.   
    STK->LOAD   = 0;     
    STK->VAL    = 0;     
}  
u32  MSTK_u32GetElapsedTicks(void)
{
    u32 LOCAL_u32ElapsedTicks = 0;
    LOCAL_u32ElapsedTicks = (STK->LOAD - STK->VAL );
    return LOCAL_u32ElapsedTicks;
}
u32  MSTK_u32GetRemainingTicks(void)
{
    u32 LOCAL_u32RemainingTick=0;
    LOCAL_u32RemainingTick =STK->VAL;
    return LOCAL_u32RemainingTick;
}
void SysTick_Handler(void)
{
    	u8 Local_u8Temp = 0;

   if (MSTK_intervalMode == MSTK_SINGLE_INTERVAL){
      
      CLR_BIT(STK->CTRL,MSTK_TICK_INT_BIT);       //Disable Interrupt.   
      CLR_BIT(STK->CTRL,MSTK_ENABLE_BIT);         //Stop Counting.   

      STK->LOAD = 0;
      STK->VAL = 0;
      }
    MSTK_Callback();
    /*	Clear	interrupt Flag					*/
	Local_u8Temp = GET_BIT(STK -> CTRL , 16);
}
