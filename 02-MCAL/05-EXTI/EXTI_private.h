/****************************************************/
/* Author    :  mohamed abd elfatah                */
/* Date      :   29 August 2020                        */
/* version   :  V01                                */
/* Description : EXTI Register                     */
/****************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H
/* DEFINE registers of EXTI  */
typedef struct{
 volatile u32 IMR ; 
 volatile u32 EMR ;
 volatile	u32		RTSR;
 volatile	u32		FTSR;
 volatile	u32		SWIER;
 volatile	u32		PR;
}EXTI_Type ;

/* define base adress of EXTI registers  */
#define	EXTI		(( EXTI_Type * )0X40010400) 

#endif
