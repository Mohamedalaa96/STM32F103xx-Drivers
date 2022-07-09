/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 09 April 2021                                                                      */
/* Version      : V01                                                                                */
/*****************************************************************************************************/


#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H


/*Options for Proirity_Grouping

    GRPOUP_16_SUB_0               /* 16 Groups (4 bits ) and 0 sub groups (0 bits )
    GRPOUP_8_SUB_2                /* 8 Groups  (3 bits ) and 0 sub groups (1 bits )
    GRPOUP_4_SUB_4                /* 4 Groups  (2 bits ) and 0 sub groups (2 bits )
    GRPOUP_2_SUB_8                /* 2 Groups  (1 bits ) and 0 sub groups (3 bits )
    GRPOUP_0_SUB_16               /* 0 Groups  (0 bits ) and 0 sub groups (4 bits )
                                                                                    */

#define MNVIC_Proirity_Grouping GRPOUP_4_SUB_4 




#endif
