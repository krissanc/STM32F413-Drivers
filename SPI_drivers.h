/*
 * SPI_drivers.h
 *
 *  Created on: 13 maj 2022
 *      Author: krcur
 */

#ifndef SPI_DRIVERS_H_
#define SPI_DRIVERS_H_

#include "STM32F413ZHT6_specific.h"
#include <string.h>

// typedef structs for all registers of interest
// then tie them all together with a handle struct

typedef struct{
	uint32_t SPI_CR1;
	uint32_t SPI_CR2;
	uint32_t SPI_SR;
	uint32_t SPI_DR;
	uint32_t SPI_CRCPR;
	uint32_t SPI_RXCRCR;
	uint32_t SPI_TXCRCR;
	uint32_t SPI_I2SCFGR;
	uint32_t SPI_I2SPR;

}SPIx_REG_DEF_t;

typedef struct{

	SPIx_REG_DEF_t 	*pSPIx;
	uint8_t 		*pTxBuffer;
	uint8_t 		*pRxBuffer;
	uint32_t 		txLen;
	uint32_t 		RxLen;
	uint8_t 		TxState;
	uint8_t 		RxState;

}SPI_HANDLE_t;



/*** SPI driver Macros ***/

/*** Slave / Master Mode ***/
#define 	SPI_MASTER_MODE			1
#define 	SPI_SLAVE_MODE			0

/*** for the CR1 register, bit-15 chooses full duplex or half duplex ***/
#define		SPI_DEVI_MODE_FD		0
#define		SPI_DEVI_MODE_HD		1

/*** for the baudrate (speed) ***/
#define		SPI_SPEED_DIV2			0
#define		SPI_SPEED_DIV4			1
#define		SPI_SPEED_DIV8			2
#define		SPI_SPEED_DIV16			3
#define		SPI_SPEED_DIV32			4
#define		SPI_SPEED_DIV64			5
#define		SPI_SPEED_DIV128		6
#define		SPI_SPEED_DIV256		7

/*** Clock idle state (polarity) ***/
#define		SPI_LOW_IDLE_CLK		0
#define		SPI_HIGH_IDLE_CLK		1

/*** Clock leading edge or trailing edge (phase) ***/
#define		SPI_LEADING_EDGE		0
#define		SPI_TRAILING_EDGE		1



/*** CR1 Register ***/
#define		SPI_CR1_CPHA			0
#define		SPI_CR1_CPOL			1
#define		SPI_CR1_MSTR			2
#define		SPI_CR1_BR				3
#define		SPI_CR1_SPE				6
#define		SPI_CR1_LSBFIRST		7
#define		SPI_CR1_SSI				8
#define		SPI_CR1_SSM				9
#define		SPI_CR1_RXONLY			10
#define		SPI_CR1_DFF				11
#define		SPI_CR1_CRCNEXT			12
#define		SPI_CR1_CRCEN			13
#define		SPI_CR1_BIDIOE			14
#define		SPI_CR1_BIDIMODE		15

/*** CR2 Register ***/
#define		SPI_CR2_RXDMAEN			0
#define		SPI_CR2_TXDMAEN			1
#define		SPI_CR2_SSOE			2



/*** SPI status register ***/
#define		SPI_SR_RXNE			0
#define		SPI_SR_TXE			1
#define		SPI_SR_CHSIDE		2
#define		SPI_SR_UDR			3
#define		SPI_SR_CRCERR		4
#define		SPI_SR_MODF			5
#define		SPI_SR_OVR			6
#define		SPI_SR_BSY			7
#define		SPI_SR_FRE			8



/*****
 * Function Prototypes *
 *****/

void SPIx_Init(SPIx_REG_DEF_t *pSPIx, uint8_t deviceMode, uint8_t busConfig, uint8_t SPI_Speed, uint8_t clkPol, uint8_t clkPha);

void SPIx_SendData(SPIx_REG_DEF_t* pSPIx, uint8_t *pTxBuffer, uint32_t len);

void SPIx_ReceiveData(SPIx_REG_DEF_t* pSPIx, uint8_t *pRxBuffer, uint32_t len);

void set_SPE(SPIx_REG_DEF_t *pSPIx, uint8_t set_reset);

void set_SSM_SSI(SPIx_REG_DEF_t *pSPIx, uint8_t set_SSM, uint8_t set_SSI );

void set_SPI_CR2(SPIx_REG_DEF_t *pSPIx, uint8_t bit_Field, uint8_t set_reset );








#endif /* SPI_DRIVERS_H_ */

