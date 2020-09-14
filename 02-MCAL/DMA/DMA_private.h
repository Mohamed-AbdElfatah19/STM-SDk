*****************************************/
/* Author  :  mohamed abd elfatah           */
/* Version :  V01                          */
/* Date    : 12 Sep 2020                   */
/*****************************************/

  
  #ifndef DMA_PRIVATE_H
  #define DMA_PRIVATE_H
  
  /* definations for Registers */
  
  typedef struct {
   volatile u32 CCR   ;
   volatile u32 CNDTR ;
   volatile u32 CPAR  ;
   volatile u32 CMAR  ;
   volatile u32 Reserved ;
  }DMA_channel ;
  

  typedef struct {
   volatile u32 ISR          ;  
   volatile u32 IFCR         ;
   DMA_channel channel[7]    ;
  }DMA_t ;
  
#define DMA_BASE_ADDRESS ((volatile DMA_t*)0x40020000)


#define CHANNEL_PRIORITY  0

#define 8_BIT_ELEMENT  0
#define 16IT_ELEMENT   1
#define 32IT_ELEMENT   2

#define MEMEORY_TO_MEMORY_MODE    0
#define CIRCULAR_MODE             0
#define MEMORY_INCREMENT_MODE     0
#define PERIPHERAL_INCREMENT_MODE 0

#define TRAN_ERROR_INTERRUPT_ENABLE  1
#define TRAN_ERROR_INTERRUPT_DISABLE 0

#define HALF_TRANS_INTERRUPT_ENABLE  1
#define HALF_TRANS_INTERRUPT_DISABLE 0

#define TRAN_COMPLETE_INTERRUPT_ENABLE  1
#define TRAN_COMPLETE_INTERRUPT_DISABLE 0
 
#define CHANNEL_ENABLE 1
#define CHANNEL_ENABLE 0

#endif 
