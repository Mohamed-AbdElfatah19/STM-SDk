/*****************************************/
/* Author  :  mohamed abd elfatah        */
/* Version :  V01                        */
/* Date    :  4 sep 2020             */
/*****************************************/


#ifndef OS_PRIVATE_H
#def OS_PRIVATE_H

typedef struct {
 u16 periodicity ;
  void (*Fptr) (void) ;
}Task ;


#endif
