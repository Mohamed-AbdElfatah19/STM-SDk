***************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_config.h
* Author                :   Mohamed abd elfatah 
* Origin Date           :   16/09/2020
* Version               :   1.0.0
*****************************************************************************/
  
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"
  
static void (*SPI1CallBackFunction)(u8) = NULL ;  
void MSPI_voidInit(void)
{
 #if  MSPI_1_MODE == MSPI_MASTER_MODE
    MGPIO_voidSetPinMode(MSPI_1_MISO_PIN, GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(MSPI_1_NSS_1_PIN, GPIO_OUTPUT_10M_PULL_UP_DN);
    MGPIO_voidSetPinValue(MSPI_1_NSS_1_PIN, HIGH);
  #endif
  MSPI_1 ->CR1 = 0x00000000 ;
  MSPI_1 >CR2  = 0x00000000 ;
  MSPI_1->CR2 |= ((SPI1_TXEIE << TXEIE) | (SPI1_RXNEIE << RXNEIE) | (SPI1_ERRIE << ERRIE) | (SPI1_SSOE << SSOE) |
                  (SPI1_TXDMAEN << TXDMAEN) | (SPI1_RXDMAEN << RXDMAEN));

  MSPI_1->CR1 |= ((SPI1_BIDIMODE << BIDIMODE) | (SPI1_BIDIOE << BIDIOE) | (SPI1_CRCEN << CRCEN) | (SPI1_CRCNEXT << CRCNEXT) |
                  (SPI1_FRAME_FORMAT << DFF)  | (SPI1_RXONLY << RXONLY) | (SPI1_SSM << SSM)     | (SPI1_SSI  << SSI)        |
                  (SPI1_LSBFIRST << LSBFIRST) | (SPI1_BR < BR0)         | (SPI1_MSTR << MSTR)   | (SPI1_CPOL << CPOL)       |
                  (SPI1_CPHA << CPHA));
  MSPI_1->CR1 |=  (SPI1_SPE  << SPE);
  
}

void  MSPI1_voidSendReceiveSync(u8 Copy_u16DataToTransimit , u8 *Copy_u16DataToReceive )
{
   #if   MSPI_1_MODE == MSPI_MASTER_MODE
    MGPIO_voidSetPinValue(MSPI_1_NSS_1_PIN, LOW);
    MSPI1->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    MGPIO_voidSetPinValue(MSPI_1_NSS_1_PIN, HIGH);
    MSPI->DR = Copy_u16DataToTransimit ;
  #elif MSPI_1_MODE == MSPI_SLAVE_MODE
    *Copy_u16DataToReceive = MSPI->DR ;
    while(GET_BIT(SPI1->SR, BSY) == 1);
  #endif
}

void  MSPI1_voidSendReceiveAsync(u8 Copy_u16DataToTransimit , void (*ptr_user_fn)(u8 *Copy_u16DataToReceive))
{
  #if   MSPI_1_MODE == MSPI_MASTER_MODE
  SPI1CallBackFunction = ptr_user_fn ;
  MGPIO_voidSetPinValue(MSPI_1_NSS_1_PIN, LOW);
  MSPI->DR = Copy_u16DataToTransimit ;
 #elif MSPI_1_MODE == MSPI_SLAVE_MODE
  SPI1CallBackFunction = ptr_user_fn ;
  *Copy_u16DataToReceive = MSPI->DR ;
  #endif
}

void SPI1_IRQHandler(void)
{
    #if   SPI_1_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(MSPI_1_NSS_1_PIN, HIGH );
    SPI1CallBackFunction(SPI1->DR);
    #elif SPI_1_MODE == SPI_MODE_MASTER
    SPI1CallBackFunction(SPI1->DR);
    #endif
}
