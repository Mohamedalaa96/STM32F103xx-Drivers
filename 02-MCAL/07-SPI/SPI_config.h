/**
 * @file SPI_config.h
 * @author Mohamed Alaa (MohamedAlaaSultan7@Gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/**
 * @brief Select frame formate MSB first or LSB first
 * @Options SPI_FRAME_MSB_FIRST SPI_FRAME_LSB_FIRST
 * 
 */
#define SPI_FRAME_MSB_FIRST 	0
#define SPI_FRAME_LSB_FIRST		1

#define SPI_FRAME   SPI_FRAME_MSB_FIRST

/**
 * @brief Select SPI Mode, Master or Slave
 * @Options SPI_MASTER_MODE SPI_SLAVE_MODE
 * 
 */
#define SPI_MASTER_MODE 		0
#define SPI_SLAVE_MODE			1

#define SPI_MODE    SPI_MASTER_MODE

/**
 * @brief Select the Slave pin
 * 
 */
#define SPI_SS_PIN  GPIOB,12

#endif
