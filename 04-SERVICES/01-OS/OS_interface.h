/*****************************************/
/* Author  :  mohamed abd elfatah        */
/* Version :  V01                        */
/* Date    :  4 sep 2020             */
/*****************************************/


#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Periodicity , void (*ptr) (void)  , u8 Copy_u8FirstDelay);

void SOS_voidStart (void)   ;

void SOS_voidSuspendTask (u8 Copy_u8ID) ;

void SOS_voidResumeTask  (u8 Copy_u8ID) ;

void SOS_voidDeleteTask (u8 Copy_u8ID)  ;  

u8 SOS_u8GetTaskstate (u8 Copy_u8ID)   ;



#endif
