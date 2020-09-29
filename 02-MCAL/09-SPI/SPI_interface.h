/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_interface.h
* Author                :   Mohamed abd elfatah 
* Origin Date           :   16/09/2020
* Version               :   1.0.0
*****************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/******************************************************************************
* Function Prototypes
*******************************************************************************/

void MSPI_voidInit(void);

u16  MSPI1_voidSendReceiveSync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit);
void MSPI1_voidSendReceiveAsync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit, void (*CallBack)(u8 Copy_u8DataToReceive));

u16  MSPI2_voidSendReceiveSync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit);
void MSPI2_voidSendReceiveAsync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit, void (*CallBack)(u8 Copy_u8DataToReceive));

#endif 
