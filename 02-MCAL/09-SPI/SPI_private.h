/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_private.h
* Author                :   Mohamed abd elfatah
* Origin Date           :   16/09/2020
* Version               :   1.0.0
*****************************************************************************/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct 
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
}SPI_t;

#define MPI_1_BASE_ADDRESS  0X40013000
#define MSPI_1 ((volatile SPI_t*)SPI_1_BASE_ADDRESS))

//SPI2
/*#define MSPI_2_BASE_ADDRESS   0X40005800
#define MSPI2                ((volatile SPI_t * const)(SPI_2_BASE_ADDRESS))*/

//Bits Definition
//CR1 REG
#define CPHA       0
#define CPOL       1
#define MSTR       2
#define BR0        3
#define SPE        6
#define LSBFIRST   7
#define SSI        8
#define SSM        9
#define RXONLY     10
#define DFF        11
#define CRCNEXT    12
#define CRCEN      13
#define BIDIOE     14
#define BIDIMODE   15
//CR2 REG
#define RXDMAEN    0
#define TXDMAEN    1
#define SSOE       2
#define ERRIE      5
#define RXNEIE     6
#define TXEIE      7
//SR REG
#define RXNE       0
#define TXE        1
#define CHSIDE     2
#define UDR        3
#define CRCERR     4
#define MODF       5
#define OVR        6
#define BSY        7

#endif 
