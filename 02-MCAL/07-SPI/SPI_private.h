/**
 * @file SPI_private.h
 * @author Mohamed Alaa (MohamedAlaaSultan7@Gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* APB2 Bus */

/**
 * @brief SPI control register 1 
 * 
 */
typedef struct
{
    u32 CPHA:1     ;       /**< \brief  [0 :1] Clock phase */
    u32 CPOL:1     ;       /**< \brief  [1 :1] Clock polarity */
    u32 MSTR:1     ;       /**< \brief  [2 :1] Master selection */
    u32 BR:3       ;       /**< \brief  [3 :3] Baud rate control */
    u32 SPE:1      ;       /**< \brief  [6 :1] SPI enable */
    u32 LSBFIRST:1 ;       /**< \brief  [7 :1] Frame format */
    u32 SSI:1      ;       /**< \brief  [8 :1] Internal slave select */
    u32 SSM:1      ;       /**< \brief  [9 :1] Software slave management */
    u32 RXONLY:1   ;       /**< \brief  [10:1] Receive only */
    u32 DFF:1      ;       /**< \brief  [11:1] Data frame format */
    u32 CRCNEXT:1  ;       /**< \brief  [12:1] CRC transfer next */
    u32 CRCEN:1    ;       /**< \brief  [13:1] Hardware CRC calculation enable */
    u32 BIDIOE:1   ;       /**< \brief  [14:1] Output enable in bidirectional mode */
    u32 BIDIMODE:1 ;       /**< \brief  [15:1] Bidirectional data mode enable */
}CR1_t;

/**
 * @brief SPI control register 2 
 * 
 */
typedef struct
{
    u32 RXDMAEN:1  ;       /**< \brief  Rx buffer DMA enable */
    u32 TXDMAEN:1  ;       /**< \brief  Tx buffer DMA enable  */
    u32 SSOE:1     ;       /**< \brief  SS output enable */
    u32 RESERVED:2 ;       /**< \brief  ReServed bits */
    u32 ERRIE:3    ;       /**< \brief  Error interrupt enable */
    u32 RXNEIE:1   ;       /**< \brief  RX buffer not empty interrupt enable */
    u32 TXEIE:1    ;       /**< \brief  Tx buffer empty interrupt enable */
 }CR2_t;

/**
 * @brief SPI status register 
 * 
 */
typedef struct
{
    u32 RXNE:1     ;       /**< \brief  Receive buffer not empty */
    u32 TXE:1      ;       /**< \brief  Transmit buffer empty */
    u32 CHSIDE:1   ;       /**< \brief  Channel side */
    u32 UDR:1      ;       /**< \brief  Underrun flag */
    u32 CRCERR:1   ;       /**< \brief  CRC error flag */
    u32 MODF:1     ;       /**< \brief  Mode fault */
    u32 OVR:1      ;       /**< \brief  Overrun flag */
    u32 BSY:1      ;       /**< \brief  Busy flag */
   
 }SR_t;

/**
 * @brief SPI Registers 
 * 
 */
typedef struct 
{
    volatile CR1_t CR1      ;   /**< \brief  SPI control register 1 */
    volatile CR2_t CR2      ;   /**< \brief  SPI control register 2 */
    volatile SR_t SR        ;   /**< \brief  SPI status register */
    volatile u32 DR         ;   /**< \brief  SPI Data Register*/
    volatile u32 CRCPR      ;
    volatile u32 RXCRCR     ;
    volatile u32 I2SCFGR    ;
    volatile u32 I2SPR      ;
}MSPI_Register;

#define SPI1   ((MSPI_Register *) 0x40013000)       /**< \breif SPI Registers */


#endif