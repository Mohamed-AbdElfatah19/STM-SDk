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

/* array os tasks */
static TASK OS_Tasks[NUMBER_OF_TASKS] = {NULL};
/* variable to count number of ticks */
volatile u16 TickCounts = 0 ; 

/* Create New Task 
   parameters : u8 Copy_u8ID        => ID of Task represents its index in array
                Copy_u16Periodicity => Period of Task 
                ptr                 => Address of Fn of Task 
                Copy_u8FirstDelay   => initial Delay of task 
           
 return : void  
 */
void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Periodicity , void (*ptr) (void) , u8 Copy_u8FirstDelay)
{
  
  OS_Tasks[Copy_u8ID].periodicity = Copy_u16Periodicity ;
  OS_Tasks[Copy_u8ID].Fptr = ptr  ;
  OS_Tasks[Copy_u8ID].firstDelay = Copy_u8FirstDelay ;
  OS_Tasks[Copy_u8ID].State = READY ;
}

/* Initialize STK and calls Scheduler fn every Tick 
      parameters : void
      return : void
*/
void SOS_voidStart (void)   
{
  /* initialization */
  MSTK_voidInit();
  /* Tick => 1msec , STK operates on 8MHz/8 => 1 microsecond , 1000micro = 1milli  */
  MSTK_voidSetIntervalPeriodic(OS_TICK  , Scheduler );
}


/* control order of execution of Tasks */
static void Scheduler(void)
{
  for(u8 i = 0 ; i < NUMBER_OF_TASKS ; i++)
  {
  if( OS_Tasks[Copy_u8ID].Fptr != NULL && OS_Tasks[Copy_u8ID].State == READY )
  {
    if( OS_Tasks[Copy_u8ID].firstDelay == 0)
    {
      OS_Tasks[Copy_u8ID].firstDelay = OS_Tasks[Copy_u8ID].periodicity - 1 ;
      OS_Tasks[i].Fptr() ;
    }
    else
       OS_Tasks[Copy_u8ID].firstDelay-- ;
    }
  }  
}

/* Suspends a task 
     parameters : u8 Copy_u8ID        => ID of Task represents its index in array
     return : void 
 */
void SOS_voidSuspendTask (u8 Copy_u8ID) 
{
  OS_Tasks[Copy_u8ID].State =  SUSPEND ;
}


/* Resume a Task 
   parameters : u8 Copy_u8ID        => ID of Task represents its index in array
     return : void 
 */

void SOS_voidResume (u8 Copy_u8ID)
{
  OS_Tasks[Copy_u8ID].State = READY ; 
}


/* Delete a Task 
   parameters : u8 Copy_u8ID        => ID of Task represents its index in array
     return : void 
 */
void SOS_voidDeleteTask (u8 Copy_u8ID)  
{
   for(u8 i = Copy_u8ID ; i<NUMBER_OF_TASKS-1 ; i++)
    {
       
      OS_Tasks[i] = OS_Tasks[i+1] ;
    }
     OS_Tasks[i].Fptr = NULL ;
}


/* Get current State of Task 
    parameters : u8 Copy_u8ID        => ID of Task represents its index in array
     return : State 
     */
u8 SOS_u8GetTaskstate (u8 Copy_u8ID)   
{
   return  OS_Tasks[Copy_u8ID].State ;
}
