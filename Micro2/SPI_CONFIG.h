/*
 * SPI_CONFIG.h
 *
 * Created: 12/20/2020 9:51:43 AM
 *  Author: karim
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "CPU_CONFIGURATION.h"

/************************************** SPI-Registers*************************************************/
/*
#define SPCR (*(volatile Uint8t* )(0x2D))
#define SPSR (*(volatile Uint8t* )(0x2E))
#define SPDR (*(volatile Uint8t* )(0x2F))
*/

#define MASTER 0
#define SLAVE  1

#define SPI_MODE SLAVE

#define MOSI 5
#define MISO 6
#define SCK  7
#define SS   4

#endif /* SPI_CONFIG_H_ */