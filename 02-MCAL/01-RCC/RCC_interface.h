/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 31 Auguest 2020                                                                    */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

//******************* Prototype of public functions & Respective Paramitters *******************//

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/* Bus ID defentions */

#define RCC_AHB             0x00
#define RCC_APB1            0x01
#define RCC_APB2            0x02

/*Peripheral ID defentions */

//************* APB2 Options ****************//

#define AFIO_EN				00
#define IOPA_EN				02
#define IOPB_EN				03
#define IOPC_EN				04
#define IOPD_EN				05
#define IOPE_EN				06
#define IOPF_EN				07
#define AFIG_EN				08
#define ADC1_EN				09
#define ADC2_EN				10
#define TIM1_EN				11
#define SPI1_EN				12
#define TIM8_EN				13
#define USART1_EN			14
#define ADC3_EN				15
#define TIM9_EN				19
#define TIM10_EN			20
#define TIM11_EN			21


//************* APB1 Options ****************//
#define TIM2_EN				00
#define TIM3_EN				01
#define TIM4_EN				02
#define TIM5_EN				03
#define TIM6_EN				04
#define TIM7_EN				05
#define TIM12_EN			06
#define TIM13_EN			07
#define TIM14_EN			08
#define WWD_GEN				11
#define SPI2_EN				14
#define SPI3_EN				15
#define USART2_EN			17
#define USART3_EN			18
#define USART4_EN			19
#define USART5_EN			20
#define I2C1_EN				21
#define I2C2_EN				22
#define USB_EN				23
#define CAN_EN				25
#define BKP_EN				27
#define PWR_EN				28
#define DAC_EN				29

//************* AHB Options ****************//

#define DMA1_EN             00
#define DMA2_EN             01
#define SRAM_EN             02
#define FLITF_EN            04
#define CRC_EN              06
#define FSMC_EN             08
#define SDIO                10

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId ,u8 Copy_u8PeripheralId);
void RCC_voidDisableClock(u8 Copy_u8BusId ,u8 Copy_u8PeripheralId);



#endif
