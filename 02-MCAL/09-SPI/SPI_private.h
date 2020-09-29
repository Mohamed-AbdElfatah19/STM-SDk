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


#endif 
