/**
 * @file SPI_program.c
 * @author Mohamed Alaa (MohamedAlaaSultan7@Gmail.com)
 * @brief
 * @version 0.2
 * @date 2022-07-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI1_voidInit(void)
{

    /* Enable Clock for Port A contains SPI Pins  */
    RCC_voidEnableClock(RCC_APB2, IOPA_EN);
    /* Enable SPI Clock */
    RCC_voidEnableClock(RCC_APB2, SPI1_EN);

    /** initialize SPI Pins
        PA5     ------> SPI1_SCK
        PA6     ------> SPI1_MISO
        PA7     ------> SPI1_MOSI
    */
	MGPIO_voidSetPinDirection(GPIOA, 5, OUTPUT_AF_PP_50MHz	);	//SPI CLK
	MGPIO_voidSetPinDirection(GPIOA, 7, OUTPUT_AF_PP_50MHz	);	//MOSI
	MGPIO_voidSetPinDirection(GPIOA, 6, INPUT_FLOATING		);	//MISO

    /* LSB First of MSB first */
#if   (SPI_FRAME == SPI_FRAME_MSB_FIRST)
    SPI1->CR1.LSBFIRST = 0;
#elif (SPI_FRAME == SPI_FRAME_LSB_FIRST)
    SPI1->CR1.LSBFIRST = 1;
#endif


    /*  Clock Freq select
        0: fPCLK/2
        1: fPCLK/4
        2: fPCLK/8
        3: fPCLK/16
        4: fPCLK/32
        5: fPCLK/64
        6: fPCLK/128
        7: fPCLK/256  */
    SPI1->CR1.BR = 6;

    /* Select the operation Mode Slave, Master */
#if  (SPI_MODE == SPI_SLAVE_MODE)
    SPI1->CR1.MSTR = 0;
    /* Set the slave select to input */
    MGPIO_voidSetPinDirection(SPI_SS_PIN,INPUT_FLOATING);
#elif (SPI_MODE == SPI_MASTER_MODE)
    SPI1->CR1.MSTR = 1;
    /* Set the slave select master */
    MGPIO_voidSetPinDirection(SPI_SS_PIN,OUTPUT_GP_PP_50MHz);
#endif

    SPI1->CR1.SSI =1;           //Software Slave management
    SPI1->CR1.SSM =1;           //Set Slave Select pin to 1

    /* Enable SPI peripheral */
    SPI1->CR1.SPE = 1;


}

void MSPI1_voidTransmitReceiveAsync(u8 copy_u8TransmitData, void (*fptr_ReciveCallback)(u8))
{

}

void MSPI1_voidTransmitReceiveSync(u8 copy_u8TransmitData, u8 * ptr_ReceiveData)
{
    /* Master Mode only, Slave Select to LOW (Selected) */
    MGPIO_voidSetPinValue(SPI_SS_PIN,LOW);

    /* Send the Data */
    SPI1->DR = (u32)copy_u8TransmitData;

    /* Wait for transmission to finish (busy flag) */
    while ((SPI1->SR.BSY) == 1);

    /* Get received Data */
    * ptr_ReceiveData = SPI1->DR;
    /* Master Mode only, Slave Select to HIGH (Un-Selected) */
    MGPIO_voidSetPinValue(SPI_SS_PIN,HIGH);
}

void MSPI1_u8ReceiveSync(u8 * ptr_ReceiveData)
{
    /* Wait for receiver to get data( Rx Not Empty flag) */
    while ((SPI1->SR.RXNE) == 0);
    /* Get received Data */
    * ptr_ReceiveData = SPI1->DR;
}


//TODO: Add Slave response functions
// at callback from receive complete , to send
