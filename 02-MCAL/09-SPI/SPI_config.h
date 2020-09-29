****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_config.h
* Author                :   Mohamed abd elfatah 
* Origin Date           :   16/09/2020
* Version               :   1.0.0
*****************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

  
#define MSPI_1_NSS_1_PIN         PINA2
  
  /* macro for enable or disable spi module */
#define MSPI_ENABLE  1
#define MSPI_DISABLE 0

  /* macro for determine master or slave */
#define MSPI_1_MODE MSPI_MASTER_MODE
#define MSPI_MASTER_MODE 1
#define MSPI_SLAVE_MODE  0
  
  /* macro for select which bit is sent first LSB or MSB */
#define MSPI_LSB_FIRST 1
#define MSPI_MSB_FIRST 0  

  /* macro for determine baud rate : flck/2 , fclk/4 , ... */ 
#define_FCLK_2    0
#define_FCLK_4    1
#define_FCLK_8    2
#define_FCLK_16   3
#define_FCLK_32   4
#define_FCLK_64   5
#define_FCLK_128  6
#define_FCLK_256  7

  
#define MSPI_8_BIT_DATA  0
#define MSPI_16_BIT_DATA 1
 
 /* macro for select clk when it's idle 0 or 1 */ 
#define MSPI_CLK_POLARITY_HIGH 1  // leading edge falling 
#define MSPI_CLK_POLARITY_LOW  0  // leading edge rising 

#define MSPI_CLK_PHASE_HIGH 1 // The second clock transition is the first data capture edge
#define MSPI_CLK_PHASE_LOW  0 // The first clock transition is the first data capture edge 

  
  /*REG CR1 Configuration*/
#define SPI1_BIDIMODE         0
#define SPI1_BIDIOE           0
#define SPI1_CRCEN            0
#define SPI1_CRCNEXT          0
#define SPI1_FRAME_FORMAT     1
#define SPI1_RXONLY           0
#define SPI1_SSM              0
#define SPI1_SSI              0
#define SPI1_LSBFIRST         1
#define SPI1_SPE              1
#define SPI1_BR               000
#define SPI1_MSTR             1
#define SPI1_CPOL             0
#define SPI1_CPHA             1
/*REG CR2 Configuration*/
#define SPI1_TXEIE            0
#define SPI1_RXNEIE           0
#define SPI1_ERRIE            0
#define SPI1_SSOE             0
#define SPI1_TXDMAEN          0
#define SPI1_RXDMAEN          0
  
#endif /*File_H_*/

