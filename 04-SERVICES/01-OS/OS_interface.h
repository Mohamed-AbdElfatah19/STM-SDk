/*****************************************/
/* Author  :  mohamed abd elfatah        */
/* Version :  V01                        */
/* Date    :  4 sep 2020             */
/*****************************************/


#ifndef OS_INTERFACE_H
#def OS_INTERFACE_H


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Periodicity , void (*ptr) (void) );

void SOS_voidStart (void)   ;



#endif
