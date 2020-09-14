*****************************************/
/* Author  :  mohamed abd elfatah           */
/* Version :  V01                          */
/* Date    : 12 Sep 2020                   */
/*****************************************/
  
  
  #ifndef DMA_INTERFACE_H
  #define DMA_INTERFACE_H
  
 void MDMA_voidChannelInit (void) ;

 void MDMA_voidChannelStart(u32 * Copy_Pu32SourceAddress , u32 * Copy_Pu32DestinationAddress , u16 Copy_u16BlockLength) ;  
  
  #endif 
