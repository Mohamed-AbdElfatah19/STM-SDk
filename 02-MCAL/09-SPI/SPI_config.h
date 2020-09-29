****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_config.h
* Author                :   Mohamed abd elfatah 
* Origin Date           :   16/09/2020
* Version               :   1.0.0
*****************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

  /* macro for enable or disable spi module */
#define MSPI_ENABLE  1
#define MSPI_DISABLE 0

  /* macro for determine master or slave */
#define MSPI_MASTER_MODE 
#define MSPI_SLAVE_MODE
  
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
  
  
#endif /*File_H_*/

