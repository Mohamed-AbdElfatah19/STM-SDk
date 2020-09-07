/*****************************************/
/* Author  :  mohamed abd elfatah        */
/* Version :  V01                        */
/* Date    :  4 sep 2020             */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL (void *)0

static TASK OS_Tasks[NUMBER_OF_TASKS] = {NULL};


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Periodicity , void (*ptr) (void) )
{
  
  OS_Tasks[Copy_u8ID].periodicity = Copy_u16Periodicity ;
  OS_Tasks[Copy_u8ID].Fptr = ptr  ;
  
  
}
void SOS_voidStart (void)   
{
  
  
  
  
}
