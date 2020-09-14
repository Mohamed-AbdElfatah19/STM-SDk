
void MDMA_voidChannelInit (void) 
{
  #if CHANNEL_ID == 1 
    DMA_BASE_ADDRESS->channel[CHANNEL_ID].CCR = ;
  
}

 void MDMA_voidChannelStart(u8 Copy_u8ChannelId ,u32 * Copy_Pu32SourceAddress , u32 * Copy_Pu32DestinationAddress , u16 Copy_u16BlockLength) 
 {
   /* make sure channel is disabled */
   CLR_BIT(DMA_BASE_ADDRESS->channel[Copy_u8ChannelId].CCR , 0)                    ;
   /* write the address */
   DMA_BASE_ADDRESS->channel[Copy_u8ChannelId].CPAR = Copy_Pu32SourceAddress       ;
   DMA_BASE_ADDRESS->channel[Copy_u8ChannelId].CMAR = Copy_Pu32DestinationAddress  ;
   /* write block length */
   DMA_BASE_ADDRESS->channel[Copy_u8ChannelId].CNDTR = Copy_u16BlockLength         ;
   /*enable channel */
   SET_BIT(DMA_BASE_ADDRESS->channel[Copy_u8ChannelId].CCR , 0)                    ;
 }
