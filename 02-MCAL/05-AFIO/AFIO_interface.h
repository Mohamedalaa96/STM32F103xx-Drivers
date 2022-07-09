/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 14 April 2021                                                                      */
/* Version      : V01                                                                                */
/*****************************************************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/* Line 0:15 */
/* PORT options*/
#define AFIO_PA 0 
#define AFIO_PB 1 
#define AFIO_PC 2 
#define AFIO_PD 3 
#define AFIO_PE 4 
#define AFIO_PF 5 
#define AFIO_PG 6

void MAFIO_voidSetEXTConfig(u8 copy_u8EXTILine, u8 copy_u8Port);

#endif