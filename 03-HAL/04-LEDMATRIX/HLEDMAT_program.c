
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

/* init corresponding gpio of rows and cols : set direction & configure each pin as output push-pull 2 MHZ */ 
void HLEDMRX_voidInit (void) 
{
                 /* configure rows */
   MGPIO_voidSetPinDirection( HLEDMAT_ROW_0 , 0b0010 );
   MGPIO_voidSetPinDirection( HLEDMAT_ROW_1 , 0b0010 );
   MGPIO_voidSetPinDirection( HLEDMAT_ROW_2 , 0b0010 );
   MGPIO_voidSetPinDirection( HLEDMAT_ROW_3 , 0b0010 );
   MGPIO_voidSetPinDirection( HLEDMAT_ROW_4 , 0b0010 );
   MGPIO_voidSetPinDirection( HLEDMAT_ROW_5 , 0b0010 );
   MGPIO_voidSetPinDirection( HLEDMAT_ROW_6 , 0b0010 );
   MGPIO_voidSetPinDirection( HLEDMAT_ROW_7 , 0b0010 );
 
           /* configure cols */ 
  MGPIO_voidSetPinDirection( HLEDMAT_COL_0 , 0b0010 );
  MGPIO_voidSetPinDirection( HLEDMAT_COL_1 , 0b0010 );
  MGPIO_voidSetPinDirection( HLEDMAT_COL_2 , 0b0010 );
  MGPIO_voidSetPinDirection( HLEDMAT_COL_3 , 0b0010 );
  MGPIO_voidSetPinDirection( HLEDMAT_COL_4 , 0b0010 );
  MGPIO_voidSetPinDirection( HLEDMAT_COL_5 , 0b0010 );
  MGPIO_voidSetPinDirection( HLEDMAT_COL_6 , 0b0010 );
  MGPIO_voidSetPinDirection( HLEDMAT_COL_7 , 0b0010 );  
}


void HLEDMRX_voidDisplay ( u8 *Copy_u8Data )
{      
      /* disable all cols */
      DisableAllCols() ;
      /* enable col 0 and get bit by bit for every row  */
      SetRowValues(Copy_u8Data[0]) ;
      MGPIO_voidSetPinValue( HLEDMAT_COL_0 , LOW ) ;
      MSTK_voidSetBusyWait(2500) ; // delay for 25 msec
  
     DisableAllCols() ;
      /* enable col 0 and get bit by bit for every row  */
      SetRowValues(Copy_u8Data[0]) ;
      MGPIO_voidSetPinValue( HLEDMAT_COL_0 , LOW ) ;
      MSTK_voidSetBusyWait(2500) ; // delay for 25 msec
  
    DisableAllCols() ;
      /* enable col 0 and get bit by bit for every row  */
      SetRowValues(Copy_u8Data[0]) ;
      MGPIO_voidSetPinValue( HLEDMAT_COL_0 , LOW ) ;
      MSTK_voidSetBusyWait(2500) ; // delay for 25 msec
          
}


static void DisableAllCols (void)
{
  /* disable all cols */
  MGPIO_voidSetPinValue( HLEDMAT_COL_0 , HIGH ) ;
  MGPIO_voidSetPinValue( HLEDMAT_COL_1 , HIGH ) ;
  MGPIO_voidSetPinValue( HLEDMAT_COL_2 , HIGH ) ;
  MGPIO_voidSetPinValue( HLEDMAT_COL_3 , HIGH ) ;
  MGPIO_voidSetPinValue( HLEDMAT_COL_4 , HIGH ) ;
  MGPIO_voidSetPinValue( HLEDMAT_COL_5 , HIGH ) ;
  MGPIO_voidSetPinValue( HLEDMAT_COL_6 , HIGH ) ;
  MGPIO_voidSetPinValue( HLEDMAT_COL_7 , HIGH ) ;
}

static void SetRowValues ( u8 *Copy_u8Data )
{
    u8 Local_u8Bit ;
  
    Local_u8Bit = GET_BIT( Copy_u8Data , 0 )  ;
    MGPIO_voidSetPinValue( HLEDMAT_ROW_0 , Local_u8Bit ) ;
  
   Local_u8Bit = GET_BIT( Copy_u8Data , 1 )  ;
    MGPIO_voidSetPinValue( HLEDMAT_ROW_1 , Local_u8Bit ) ;
  
   Local_u8Bit = GET_BIT( Copy_u8Data , 2)  ;
    MGPIO_voidSetPinValue( HLEDMAT_ROW_2 , Local_u8Bit ) ;
  
   Local_u8Bit = GET_BIT( Copy_u8Data , 3 )  ;
    MGPIO_voidSetPinValue( HLEDMAT_ROW_3 , Local_u8Bit ) ;
  
   Local_u8Bit = GET_BIT( Copy_u8Data , 4 )  ;
    MGPIO_voidSetPinValue( HLEDMAT_ROW_4 , Local_u8Bit ) ;
  
   Local_u8Bit = GET_BIT( Copy_u8Data , 5 )  ;
    MGPIO_voidSetPinValue( HLEDMAT_ROW_5 , Local_u8Bit ) ;
  
   Local_u8Bit = GET_BIT( Copy_u8Data , 6 )  ;
    MGPIO_voidSetPinValue( HLEDMAT_ROW_6 , Local_u8Bit ) ;
  
    Local_u8Bit = GET_BIT( Copy_u8Data , 7 )  ;
    MGPIO_voidSetPinValue( HLEDMAT_ROW_7 , Local_u8Bit ) ;
}
