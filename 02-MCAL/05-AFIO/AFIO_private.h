/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 10 April 2021                                                                      */
/* Version      : V01                                                                                */
/*****************************************************************************************************/


#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H


typedef struct 
{
     u32 AFIO_EVCR;
     u32 AFIO_MAPR_LMH;      //LOW Medium High density
     u32 AFIO_MAPR_CONN;     // Connectivity line devices
     u32 AFIO_MAPR;
     u32 EXTICR[4]; // EXTICR1,2,3,4
     u32 AFIO_MAPR2;

}AFIO_t;

#define AFIO ( (AFIO_t *) 0x40010000 )  

#endif