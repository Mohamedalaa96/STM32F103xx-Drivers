/**
 * @file SPI_interface.h
 * @author Mohamed Alaa (MohamedAlaaSultan7@Gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/**
 * @brief Initialize the SPI1 interface with config from #SPI_config.h file
 * 
 */
void MSPI1_voidInit(void);

/**
 * @brief Transmit data Async. when receive call the callback
 * 
 * @param copy_u8TransmitData byte to be transmitted
 * @param fptr_ReciveCallback Call back function when receive data void f(u8)
 */
void MSPI1_voidTransmitReceiveAsync(u8 copy_u8TransmitData, void (*fptr_ReciveCallback)(u8));

/**
 * @brief Transmit and Receive byte Sych.
 * 
 * @param copy_u8TransmitData byte to be transmitted
 * @param ptr_ReceiveData  Pointer to u8 to put the received data
 */
void MSPI1_voidTransmitReceiveSync(u8 copy_u8TransmitData, u8 * ptr_ReceiveData);


#endif