
#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

/* determine number of channel 1....7 */
#define CHANNEL_ID  1

/* determine priority of channel : 0 LOW , 1 medium , 2 high , 3 very high  */
#define CHANNEL_PRIORITY           0

/* determine element size for one transfer for memory      : 0 1Byte , 1 2Byte , 3 4Byte */
#define MEMORY_ELEMENT_SIZE        0

/* determine element size for one transfer for peropheral : 0 1Byte , 1 2Byte , 3 4Byte */
#define PERIPHERAL_ELEMENT_SIZE    0


#define MEMEORY_TO_MEMORY_MODE    0
#define CIRCULAR_MODE             0
#define MEMORY_INCREMENT_MODE     0
#define PERIPHERAL_INCREMENT_MODE 0

#define TRAN_ERROR_INTERRUPT     0
#define HALF_TRANS_INTERRUPT     0
#define TRAN_COMPLETE_INTERRUPT  1

#define DATA_TRANSFER_DIRECTION



 


#endif
