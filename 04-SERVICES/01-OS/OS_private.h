/*****************************************/
/* Author  :  mohamed abd elfatah        */
/* Version :  V01                        */
/* Date    :  4 sep 2020             */
/*****************************************/


#ifndef OS_PRIVATE_H
#def OS_PRIVATE_H

typedef enum states{
 READY ,
 SUSPEND ,
 RUNNING 
}Task_States_t;

typedef struct {
 u16 periodicity ;
  void (*Fptr) (void) ;
 u8 firstDelay ;
 Task_States_t State ;
}Task ;


#endif
