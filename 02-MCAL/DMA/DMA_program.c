#include"TYPES.h"
#include"MACROS.h"

#include"DMA_INTERFACE.h"
#include"DMA_REG.h"

void ( *DMA_CallBackChannel1 )( void );

void MDMA_VidInit(u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8Mode , u8 Copy_U8Pinc , u8 Copy_u8Minc , u8 Copy_u8MemorySize , u8 Copy_u8PeripheralSize , u8 Copy_u8ChannelPrio ) 
{
   // Disable DMA 
   CLR_BIT(MDMA->channel[Copy_u8Channel].CCR , 0 ) ;
   
	// Wait Until DMA Disable
	while( GET_BIT( MDMA->channel[ Copy_u8Channel ].CCR , 0 ) == 1 );
  
  
  
  
  
}
