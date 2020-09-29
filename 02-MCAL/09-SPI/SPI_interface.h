/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_interface.h
* Author                :   Mohamed abd elfatah 
* Origin Date           :   16/09/2020
* Version               :   1.0.0
*****************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define MSPI_1_MOSI_PIN        PINA7
#define MSPI_1_MISO_PIN        PINA6
#define MSPI_1_CLK_PIN         PINA5
#define MSPI_1_NSS_PIN         PINA4

/******************************************************************************
* Function Prototypes
*******************************************************************************/

void MSPI_voidInit(void);

void  MSPI1_voidSendReceiveSync(u8 Copy_u16DataToTransimit , u8 Copy_u16DataToReceive );
void  MSPI1_voidSendReceiveAsync(u8 Copy_u16DataToTransimit , u8 Copy_u16DataToReceive);

void MSPI2_voidSendReceiveSync(u8 Copy_u16DataToTransimit , u8 Copy_u16DataToReceive);
void MSPI2_voidSendReceiveAsync(u8 Copy_u16DataToTransimit , u8 Copy_u16DataToReceive);

#endif 
