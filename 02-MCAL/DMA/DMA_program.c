
void MDMA_voidChannelInit (void) 
{
  #if CHANNEL_ID == 1 
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMEORY_TO_MEMORY_MODE<<14)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= ( CHANNEL_PRIORITY<<13)         ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMORY_ELEMENT_SIZE<<11)       ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (PERIPHERAL_ELEMENT_SIZE<<9)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMORY_INCREMENT_MODE<<7)      ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (PERIPHERAL_INCREMENT_MODE<<6)  ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (CIRCULAR_MODE<<5)              ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (DATA_TRANSFER_DIRECTION<<4)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (TRAN_ERROR_INTERRUPT<<3)       ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (HALF_TRANS_INTERRUPT <<2)      ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (TRAN_COMPLETE_INTERRUPT<<1)    ;
  #elif CHANNEL_ID == 2
     DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMEORY_TO_MEMORY_MODE<<14)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= ( CHANNEL_PRIORITY<<13)         ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMORY_ELEMENT_SIZE<<11)       ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (PERIPHERAL_ELEMENT_SIZE<<9)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMORY_INCREMENT_MODE<<7)      ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (PERIPHERAL_INCREMENT_MODE<<6)  ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (CIRCULAR_MODE<<5)              ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (DATA_TRANSFER_DIRECTION<<4)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (TRAN_ERROR_INTERRUPT<<3)       ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (HALF_TRANS_INTERRUPT <<2)      ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (TRAN_COMPLETE_INTERRUPT<<1)    ;
  #elif CHANNEL_ID == 3
     DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMEORY_TO_MEMORY_MODE<<14)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= ( CHANNEL_PRIORITY<<13)         ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMORY_ELEMENT_SIZE<<11)       ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (PERIPHERAL_ELEMENT_SIZE<<9)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (MEMORY_INCREMENT_MODE<<7)      ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (PERIPHERAL_INCREMENT_MODE<<6)  ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (CIRCULAR_MODE<<5)              ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (DATA_TRANSFER_DIRECTION<<4)    ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (TRAN_ERROR_INTERRUPT<<3)       ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (HALF_TRANS_INTERRUPT <<2)      ;
    DMA_BASE_ADDRESS->channel[CHANNEL_ID_1].CCR |= (TRAN_COMPLETE_INTERRUPT<<1)    ;
  #endif
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
