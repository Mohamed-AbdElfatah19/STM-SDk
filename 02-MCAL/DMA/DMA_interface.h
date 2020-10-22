*****************************************/
/* Author  :  mohamed abd elfatah           */
/* Version :  V01                          */
/* Date    : 12 Sep 2020                   */
/*****************************************/
  
  
  #ifndef DMA_INTERFACE_H
  #define DMA_INTERFACE_H
  
  ////////////////  DMA channels ///////////////
  #define CHANNEL1 0
  #define CHANNEL2 1
  #define CHANNEL3 2
  #define CHANNEL4 3
  #define CHANNEL5 4
  #define CHANNEL6 5
  #define CHANNEL7 6
  
  //////////////// DMA Enable //////////////////
  #define DMA_DISABLE 0
  #define DMA_ENABLE  1
  
  //////////////// DMA Direction ////////////////
  #deinfe MEM_TO_MEM  0
  #define MEM_TO_PERI 1
  #define PERI_TO_MEM 2
  
  //////////////  DMA SIZE /////////////////
  #define BYTE      0
  #define HALF_WORD 1
  #define WORD      2
  
  /////////// DMA Circular Mode //////////////////
  #define CIRCULAR_MODE_DISABLE 0
  #define CIRCULAR_MODE_ENABLE  1
  
  ///////////// Peripheral increment ////////////////
#define PERIPHERAL_INCREMENT_ENABLE  0
#define PERIPHERAL_INCREMENT_DISABLE 1
  
///////////// Memory increment ////////////////
#define MEM_INCREMENT_ENABLE  0
#define MEM_INCREMENT_DISABLE 1
  
///////Channel Priority ///////////////////////////////
#define LOW         0
#define MEDIUM      1
#define HIGH        2
#define VERY_HIGH   3

 
////////////////////////////////////////////////////////////////////////// Interfaces ProtoTypes /////////////////////////////////////////////////////////////////////////////
  void MDMA_VidInit(u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8Mode , u8 Copy_U8Pinc , u8 Copy_u8Minc , u8 Copy_u8MemorySize , u8 Copy_u8PeripheralSize , u8 Copy_u8ChannelPrio ) ;
  
  #endif 
