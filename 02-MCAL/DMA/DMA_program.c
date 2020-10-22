#include"TYPES.h"
#include"MACROS.h"

#include"DMA_INTERFACE.h"
#include"DMA_REG.h"

void ( *DMA_CallBackChannel1 )( void );

void MDMA_VidInit(u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8Mode , u8 Copy_U8Pinc , u8 Copy_u8Minc , u8 Copy_u8MemorySize, u8 Copy_u8PeripheralSize , u8 Copy_u8ChannelPrio ) 
{
    // Disable DMA 
  CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 0 ) ;
   // Wait Until DMA Disable
  while( GET_BIT( MDMA->channel[ Copy_u8Channel ].CCR , 0 ) == 1 );
	
   // set direction
  if(Copy_u8Direction == MEM_TO_MEM )
	  SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 14) ;
  else if (Copy_u8Direction == MEM_TO_PERI)\
	   SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 4) ;
  else if (Copy_u8Direction == PERI_TO_MEM )
	  CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 4)) ;
	
  // set mode
	if(Copy_u8Mode == CIRCULAR_MODE_ENABLE )
		SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 5) ;
	else if (Copy_u8Mode == CIRCULAR_MODE_DISABLE )
		CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 5) ;
	 
 // memory increnment
	if(Copy_U8Pinc == MEM_INCREMENT_ENABLE  )
		SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 7) ;
	else if (Copy_U8Pinc == MEM_INCREMENT_DISABLE )
		CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 7) ;
	// peripheral increment 
	if(Copy_U8Pinc == PERIPHERAL_INCREMENT_ENABLE )
		SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 6) ;
	else if (Copy_U8Pinc == PERIPHERAL_INCREMENT_DISABLE )
		CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 6) ;
	
	// set size for memory and peripheral 
	/**************** memory **************/ 
	if(Copy_u8MemorySize == BYTE ){
	   CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 10) ;
	   CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 11) ;
	}
	else if (Copy_u8MemorySize == HALF_WORD){
		SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 10) ;
	        CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 11) ;
	}
	else if(Copy_u8MemorySize == WORD ){
		CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 10) ;
	        SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 11) ;
	}
	/*************** peripheral ***********/
	if(Copy_u8PeripheralSize == BYTE ){
	   CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 8) ;
	   CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 9) ;
	}
	else if (Copy_u8MemorySize == HALF_WORD){
		SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 8) ;
	        CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 9) ;
	}
	else if(Copy_u8MemorySize == WORD ){
		CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 8) ;
	        SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 9) ;
	}

	// set channel priority 
    if(Copy_u8ChannelPrio == LOW ){
           CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 12) ;
	   CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 13) ;
    }
	else if (Copy_u8ChannelPrio ==MEDIUM ){
	   SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 12) ;
	   CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 13) ;
    }
	else if (Copy_u8ChannelPrio ==HIGH ){
	   CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 12) ;
	   SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 13) ;
    }
	else if (Copy_u8ChannelPrio ==VERY_HIGH ){
	   SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 12) ;
	   SET_BIT(MDMA->channel[Copy_u8Channel].CCR , 13) ;
    }
 
}

void MDMA_VidDMAEnable ((u8 Copy_u8Channel ) 
{ 
	if( Copy_u8Channel > 6 ) 
	{
           retun ; 
	}
	u8  ChannelNo  = Copy_u8Channel  * 4 ;
       CLR_BIT(MDMA->channel[Copy_u8Channel].IFCR ,  ChannelNo  + DMA_GIF)  ;
       CLR_BIT(MDMA->channel[Copy_u8Channel].IFCR ,  ChannelNo  + DMA_TCIF) ;
       CLR_BIT(MDMA->channel[Copy_u8Channel].IFCR , ChannelNo  + DMA_HTIF)   ;
       CLR_BIT(MDMA->channel[Copy_u8Channel].IFCR ,  ChannelNo  + DMA_TEIF) ;
	
	CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 0 ) ;
       
}
void MDMA_VidDMADisable ((u8 Copy_u8Channel ) 
{
  	CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 0 ) ;
}
			 
void MDMA_VidInerruptEnable( u8 Copy_u8Channel , u8 Copy_u8INTSource )
{
/////////////					
}
			 
void MDMA_VidSetAddresses (u8 Copy_u8Channel , u32 * PeripheralAddress , u32 * MemoryAddress , u16 Copy_u16NDT )
{
    MDMA->channel[Copy_u8Channel].CPAR = PeripheralAddress ;
    MDMA->channel[Copy_u8Channel].CMAR = MemoryAddress ;
    MDMA->channel[ Copy_u8Channel ].CNDTR =  Copy_u16NDT ;
}
void MDMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	DMA_CallBackChannel1 = Ptr ;

}

void DMA1_Channel1_IRQHandler(void){

	DMA_CallBackChannel1();
}
			 
			 
