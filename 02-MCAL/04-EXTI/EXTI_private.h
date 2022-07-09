/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 10 April 2021                                                                      */
/* Version      : V01                                                                                */
/*****************************************************************************************************/


#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


typedef struct {
     volatile u32 IMR    ; /* Interrupt Mask Register (1 Enabled)*/
     volatile u32 EMR    ; /* Event Mask Register (1 Enabled)    */
     volatile u32 RTSR   ; /* Raising Trigger Selection Register */
     volatile u32 FTSR   ; /* Faling Trigger Selection Register  */
     volatile u32 SWIER  ; /* Software interrupt event register  */
     volatile u32 PR     ; /* Pending register                   */
}EXTI_t; //EXTI_t t for type

#define EXTI   ((volatile EXTI_t * ) 0x40010400 )

#define MEXTI_EXTLINE0        0    
#define MEXTI_EXTLINE1        1    
#define MEXTI_EXTLINE2        2    
#define MEXTI_EXTLINE3        3    
#define MEXTI_EXTLINE4        4    
#define MEXTI_EXTLINE5        5    
#define MEXTI_EXTLINE6        6    
#define MEXTI_EXTLINE7        7    
#define MEXTI_EXTLINE8        8    
#define MEXTI_EXTLINE9        9    
#define MEXTI_EXTLINE10       10    
#define MEXTI_EXTLINE11       11   
#define MEXTI_EXTLINE12       12    
#define MEXTI_EXTLINE13       13    
#define MEXTI_EXTLINE14       14    
#define MEXTI_EXTLINE15       15    

#define MEXTI_FALLING      0
#define MEXTI_RAISING      1
#define MEXTI_ON_CAHNGE    2

#endif