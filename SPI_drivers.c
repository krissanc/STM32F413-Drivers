/*
 * SPI_drivers.c
 *
 *  Created on: 13 maj 2022
 *      Author: krcur
 */


#include "SPI_drivers.h"

// a function which sets the SPI settings
void SPIx_Init(SPIx_REG_DEF_t *pSPIx, uint8_t deviceMode, uint8_t busConfig, uint8_t clkPol, uint8_t clkPha){

	// set the device mode SLAVE or MASTER
	if( deviceMode == SPI_MASTER_MODE ){	// master
		pSPIx->SPI_CR1 |= ( 1 << SPI_CR1_MSTR );

	}
	else if( deviceMode == SPI_SLAVE_MODE ){	// slave
		pSPIx->SPI_CR1 &= ~( 1 << SPI_CR1_MSTR );
	}

	// set the bus configuration (full duplex, half duplex)
	if( busConfig == SPI_DEVI_MODE_FD ){
		// set = 0
		pSPIx->SPI_CR1 &= ~( 1 << SPI_CR1_BIDIMODE );
	}
	else if( busConfig == SPI_DEVI_MODE_HD ){
		// set = 1
		pSPIx->SPI_CR1 |= ( 1 << SPI_CR1_BIDIMODE );
	}

	// set the idle clock level high or low
	if( clkPol == SPI_LOW_IDLE_CLK ){
		// set = 0
		pSPIx->SPI_CR1 &= ~( 1 << SPI_CR1_CPOL );
	}
	else if( clkPol == SPI_HIGH_IDLE_CLK ){
		// set = 1
		pSPIx->SPI_CR1 |= ( 1 << SPI_CR1_CPOL );
	}

	// set the phase; leading edge or trailing edge
	if( clkPha == SPI_LEADING_EDGE )
	{
		// set = 0
		pSPIx->SPI_CR1 &= ~( 1 << SPI_CR1_CPHA );
	}
	else if( clkPha == SPI_TRAILING_EDGE )
	{
		// set = 1
		pSPIx->SPI_CR1 |= ( 1 << SPI_CR1_CPHA );
	}



} // end of init function

void sendData(SPIx_REG_DEF_t* pSPIx, uint8_t *pTxBuffer, uint32_t len)
{
	while( len > 0 )
	{
		// 1. check if TXE flag is 1 (Then it is empty)
		while( !(pSPIx->SPI_SR & ( 1 << SPI_SR_TXE)) );

		// 2. check the data frame format (DFF)
		if ((pSPIx->SPI_CR1 & 1 << SPI_CR1_DFF) == 0)
		{	// this is 8-bit format********************************************
			pSPIx->SPI_DR = *((uint8_t*)pTxBuffer);
			pTxBuffer++;
			len--;
		}
		else if ((pSPIx->SPI_CR1 & 1 << SPI_CR1_DFF) == 1)
		{	// this is 16-bit format ******************************************
			pSPIx->SPI_DR = *((uint16_t*)pTxBuffer);
			(uint16_t*)pTxBuffer++;
			len--;
			len--;
		}

	}

}	// end of send data function

void set_SPE(SPIx_REG_DEF_t *pSPIx, uint8_t set_reset)
{
	if( set_reset == SET )
	{
		(pSPIx->SPI_CR1 |= 1 << SPI_CR1_SPE);
	}
	else if ( set_reset == RESET )
	{
		while( !(pSPIx->SPI_SR & 1 << SPI_SR_RXNE) );
		while( !(pSPIx->SPI_SR & 1 << SPI_SR_TXE) );
		while( pSPIx->SPI_SR & 1 << SPI_SR_BSY );
		(pSPIx->SPI_CR1 &= ~(1 << SPI_CR1_SPE));
	}

} // end of set SPE bit function

void set_SSM_SSI(SPIx_REG_DEF_t *pSPIx, uint8_t set_SSM, uint8_t set_SSI )
{
	// sets the SSM bit (1 is software slave management enabled)
	if( set_SSM == SET )
	{
		(pSPIx->SPI_CR1 |= 1 << SPI_CR1_SSM);
	}
	else if ( set_SSM == RESET )
	{

		(pSPIx->SPI_CR1 &= ~(1 << SPI_CR1_SSM));
	}

	// sets the SSI bit ( the value of this bit is forced onto the NSS pin when SSM is active )
	if( set_SSI == SET )
	{
		(pSPIx->SPI_CR1 |= 1 << SPI_CR1_SSI);
	}
	else if ( set_SSI == RESET )
	{

		(pSPIx->SPI_CR1 &= ~(1 << SPI_CR1_SSI));
	}



} // end of set SSM and SSI bit function
