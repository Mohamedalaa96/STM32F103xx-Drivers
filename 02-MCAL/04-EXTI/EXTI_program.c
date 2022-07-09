/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 20 April 2021                                                                      */
/* Version      : V02                                                                                */
/*****************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/* GLobal Variable for the EXTI pointers to callbacks */
static void (*ptr_array[16])(void);

void MEXTI_voidInit()
{

}
void MEXTI_voidSetSignalLatch(u8 copy_u8InterruptLine,u8 copy_u8SignalLatchMode)
{
    #if copy_u8InterruptLine > 15
        #error "Line Interrupts from 0 : 15"
    #else
        switch (copy_u8SignalLatchMode)
        {
            case MEXTI_FALLING:     SET_BIT (EXTI->RTSR, copy_u8InterruptLine);      break;
            case MEXTI_RAISING:     SET_BIT (EXTI->FTSR, copy_u8InterruptLine);      break;
            case MEXTI_ON_CAHNGE:   SET_BIT (EXTI->RTSR, copy_u8InterruptLine);
                                    SET_BIT (EXTI->FTSR, copy_u8InterruptLine);      break;
        }

        SET_BIT (EXTI->IMR, copy_u8InterruptLine);  /* Enable the Interrupt , un mask the interrupt */
    #endif
}
void MEXTI_voidDisableInterrupt(u8 copy_u8InterruptLine)
{
    #if copy_u8InterruptLine > 15
        #error "Line Interrupts from 0 : 15"
    #else
        CLR_BIT(EXTI->IMR, copy_u8InterruptLine);  /* Disable the Interrupt , mask the interrupt */
    #endif


}
void MEXTI_voidSoftwareTrigger(u8 copy_u8InterruptLine)
{
    #if copy_u8InterruptLine > 15
        #error "Line Interrupts from 0 : 15"
    #else
        SET_BIT(EXTI->SWIER, copy_u8InterruptLine);
        //SET_BIT(EXTI->PR,copy_u8InterruptLine);     //Clear by writing 1.
    #endif
}
void MEXTI_voidSetCallback(u8 copy_u8InterruptLine,void (*copy_voidPtr)(void))
{
    #if copy_u8InterruptLine > 15
        #error "Line Interrupts from 0 : 15"
    #else
        ptr_array[copy_u8InterruptLine]= copy_voidPtr;
    #endif
}

void EXTI0_IRQHandler   (void)
{
    if (ptr_array[0] != 0 )
    {
    	SET_BIT(EXTI->PR,0);
        ptr_array[0]();
    }
}
void EXTI1_IRQHandler   (void)
{
    if (ptr_array[1] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,1);
        ptr_array[1]();
    }

}
void EXTI2_IRQHandler   (void)
{
         if (ptr_array[2] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,2);
        ptr_array[2]();
    }

}
void EXTI3_IRQHandler   (void)
{
         if (ptr_array[3] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,3);
        ptr_array[3]();
    }

}
void EXTI4_IRQHandler   (void)
{
 if (ptr_array[4] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,4);
        ptr_array[4]();
    }
}
void EXTI5_IRQHandler   (void)
{
 if (ptr_array[5] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,5);
        ptr_array[5]();
    }
}
void EXTI6_IRQHandler   (void)
{
 if (ptr_array[6] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,6);
        ptr_array[6]();
    }
}
void EXTI7_IRQHandler   (void)
{
 if (ptr_array[7] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,7);
        ptr_array[7]();
    }
}
void EXTI8_IRQHandler   (void)
{
 if (ptr_array[8] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,8);
        ptr_array[8]();
    }
}
void EXTI9_IRQHandler   (void)
{
 if (ptr_array[9] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,9);
        ptr_array[9]();
    }
}
void EXTI10_IRQHandler  (void)
{
 if (ptr_array[10] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,10);
        ptr_array[10]();
    }
}
void EXTI11_IRQHandler  (void)
{
 if (ptr_array[11] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,11);
        ptr_array[11]();
    }
}
void EXTI12_IRQHandler  (void)
{
 if (ptr_array[12] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,12);
        ptr_array[12]();
    }
}
void EXTI13_IRQHandler  (void)
{
 if (ptr_array[13] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,13);
        ptr_array[13]();
    }
}
void EXTI14_IRQHandler  (void)
{
 if (ptr_array[14] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,14);
        ptr_array[14]();
    }
}
void EXTI15_IRQHandler  (void)
{
 if (ptr_array[15] != 0 )
    {
        /* Clear Pending Flag , By Writing 1 */
    	SET_BIT(EXTI->PR,15);
        ptr_array[15]();
    }
}
