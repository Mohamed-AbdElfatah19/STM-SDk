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
volatile u16 TickCounts = 0 ; 


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Periodicity , void (*ptr) (void) , u8 Copy_u8FirstDelay)
{
  
  OS_Tasks[Copy_u8ID].periodicity = Copy_u16Periodicity ;
  OS_Tasks[Copy_u8ID].Fptr = ptr  ;
  OS_Tasks[Copy_u8ID].firstDelay = Copy_u8FirstDelay ;
  
  
}
void SOS_voidStart (void)   
{
  /* initialization */
  MSTK_voidInit();
  /* Tick => 1msec , STK operates on 8MHz/8 => 1 microsecond , 1000micro = 1milli  */
  MSTK_voidSetIntervalPeriodic(1000  , Scheduler );
}


/* control order of execution of Tasks */
static void Scheduler(void)
{
  for(u8 i =0 ; i< NUMBER_OF_TASKS ; i++)
  {
    if(TickCounts % OS_Tasks[i].periodicity == 0)
    {
        OS_Tasks.Fptr() ;
    }
  }
  TickCounts++ ;
  
  
}
void SOS_voidSuspendTask (u8 Copy_u8ID) 

void SOS_voidResumeTask  (u8 Copy_u8ID) ;

void SOS_voidDeleteTask (u8 Copy_u8ID)  ;  

u8 SOS_u8GetTaskstate (u8 Copy_u8ID)   ;
