/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 12 May 2021                                                                        */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SysTick_interface.h"

#include "LEDMTRX_interface.h"
#include "LEDMTRX_private.h"
#include "LEDMTRX_config.h"

void HLEDMTRX_voidInit(void)
{

    /* Set Rows as OUPUTS 50 Mhz */
    MGPIO_voidSetPinDirection (LEDMTRX_ROW0_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_ROW1_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_ROW2_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_ROW3_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_ROW4_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_ROW5_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_ROW6_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_ROW7_PIN,OUTPUT_GP_PP_50MHz);

    /* Set Rows as OUPUTS 50 Mhz */	
    MGPIO_voidSetPinDirection (LEDMTRX_COL0_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_COL1_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_COL2_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_COL3_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_COL4_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_COL5_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_COL6_PIN,OUTPUT_GP_PP_50MHz);
	MGPIO_voidSetPinDirection (LEDMTRX_COL7_PIN,OUTPUT_GP_PP_50MHz);

}

void HLEDMTRX_voidDisplay(u8 * copy_u8Data)
{
    /* COL 0 */
    DisableAllColumns();
    /*Display Data on ROWs*/
    SetRowValues(copy_u8Data[0]);
    /* Enable Column 0 */   
    MGPIO_voidSetPinValue (LEDMTRX_COL0_PIN,0);
    /* Set Delay */
    MSTK_voidSetBusyWait(2500);  //2.5 mSec. 

    /* COL 1 */
    DisableAllColumns();
    /*Display Data on ROWs*/
    SetRowValues(copy_u8Data[1]);
    /* Enable Column 1 */   
    MGPIO_voidSetPinValue (LEDMTRX_COL1_PIN,0);
    /* Set Delay */
    MSTK_voidSetBusyWait(2500);  //2.5 mSec. 

    /* COL 2 */
    DisableAllColumns();
    /*Display Data on ROWs*/
    SetRowValues(copy_u8Data[2]);
    /* Enable Column 2 */   
    MGPIO_voidSetPinValue (LEDMTRX_COL2_PIN,0);
    /* Set Delay */
    MSTK_voidSetBusyWait(2500);  //2.5 mSec. 

    /* COL 3 */
    DisableAllColumns();
    /*Display Data on ROWs*/
    SetRowValues(copy_u8Data[3]);
    /* Enable Column 3 */   
    MGPIO_voidSetPinValue (LEDMTRX_COL3_PIN,0);
    /* Set Delay */
    MSTK_voidSetBusyWait(2500);  //2.5 mSec. 

    /* COL 4 */
    DisableAllColumns();
    /*Display Data on ROWs*/
    SetRowValues(copy_u8Data[4]);
    /* Enable Column 4 */   
    MGPIO_voidSetPinValue (LEDMTRX_COL4_PIN,0);
    /* Set Delay */
    MSTK_voidSetBusyWait(2500);  //2.5 mSec. 

    /* COL 5 */
    DisableAllColumns();
    /*Display Data on ROWs*/
    SetRowValues(copy_u8Data[5]);
    /* Enable Column 5 */   
    MGPIO_voidSetPinValue (LEDMTRX_COL5_PIN,0);
    /* Set Delay */
    MSTK_voidSetBusyWait(2500);  //2.5 mSec. 

    /* COL 6 */
    DisableAllColumns();
    /*Display Data on ROWs*/
    SetRowValues(copy_u8Data[6]);
    /* Enable Column 6 */   
    MGPIO_voidSetPinValue (LEDMTRX_COL6_PIN,0);
    /* Set Delay */
    MSTK_voidSetBusyWait(2500);  //2.5 mSec. 

    /* COL 7 */
    DisableAllColumns();
    /*Display Data on ROWs*/
    SetRowValues(copy_u8Data[7]);
    /* Enable Column 7 */   
    MGPIO_voidSetPinValue (LEDMTRX_COL7_PIN,0);
    /* Set Delay */
    MSTK_voidSetBusyWait(2500);  //2.5 mSec. 
    

}
static void DisableAllColumns()
{
    MGPIO_voidSetPinValue (LEDMTRX_COL0_PIN,1);
	MGPIO_voidSetPinValue (LEDMTRX_COL1_PIN,1);
	MGPIO_voidSetPinValue (LEDMTRX_COL2_PIN,1);
	MGPIO_voidSetPinValue (LEDMTRX_COL3_PIN,1);
	MGPIO_voidSetPinValue (LEDMTRX_COL4_PIN,1);
	MGPIO_voidSetPinValue (LEDMTRX_COL5_PIN,1);
	MGPIO_voidSetPinValue (LEDMTRX_COL6_PIN,1);
	MGPIO_voidSetPinValue (LEDMTRX_COL7_PIN,1);

}

static void SetRowValues(u8 copy_u8Data)
{
    u8 LOCAL_u8BIT =0;
    /* SET ROW with the byte 0 */
    LOCAL_u8BIT = GET_BIT(copy_u8Data,0);
    MGPIO_voidSetPinValue (LEDMTRX_ROW0_PIN,LOCAL_u8BIT);
    LOCAL_u8BIT = GET_BIT(copy_u8Data,1);
    MGPIO_voidSetPinValue (LEDMTRX_ROW1_PIN,LOCAL_u8BIT);
    LOCAL_u8BIT = GET_BIT(copy_u8Data,2);
    MGPIO_voidSetPinValue (LEDMTRX_ROW2_PIN,LOCAL_u8BIT);
    LOCAL_u8BIT = GET_BIT(copy_u8Data,3);
    MGPIO_voidSetPinValue (LEDMTRX_ROW3_PIN,LOCAL_u8BIT);
    LOCAL_u8BIT = GET_BIT(copy_u8Data,4);
    MGPIO_voidSetPinValue (LEDMTRX_ROW4_PIN,LOCAL_u8BIT);
    LOCAL_u8BIT = GET_BIT(copy_u8Data,5);
    MGPIO_voidSetPinValue (LEDMTRX_ROW5_PIN,LOCAL_u8BIT);
    LOCAL_u8BIT = GET_BIT(copy_u8Data,6);
    MGPIO_voidSetPinValue (LEDMTRX_ROW6_PIN,LOCAL_u8BIT);
    LOCAL_u8BIT = GET_BIT(copy_u8Data,7);
    MGPIO_voidSetPinValue (LEDMTRX_ROW7_PIN,LOCAL_u8BIT);
}