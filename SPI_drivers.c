/*
 * SPI_drivers.c
 *
 *  Created on: 13 maj 2022
 *      Author: krcur
 */


#include "SPI_drivers.h"

// a function which sets the SPI settings
void SPIx_Init(SPIx_REG_DEF_t *pSPIx, uint8_t deviceMode, uint8_t busConfig, uint8_t SPI_Speed, uint8_t clkPol, uint8_t clkPha){

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

	// set the speed
	if( SPI_Speed == SPI_SPEED_DIV2 ){
		// set BR bitfield = SPI_SPEED_DIV_2
		pSPIx->SPI_CR1 |= ( SPI_SPEED_DIV2 << SPI_CR1_BR );
	}
	else if( SPI_Speed == SPI_SPEED_DIV4 ){
		// set BR bitfield = SPI_SPEED_DIV_4
		pSPIx->SPI_CR1 |= ( SPI_SPEED_DIV4 << SPI_CR1_BR );
	}
	else if( SPI_Speed == SPI_SPEED_DIV8 ){
		// set BR bitfield = SPI_SPEED_DIV_8
		pSPIx->SPI_CR1 |= ( SPI_SPEED_DIV8 << SPI_CR1_BR );
	}
	else if( SPI_Speed == SPI_SPEED_DIV16 ){
		// set BR bitfield = SPI_SPEED_DIV_16
		pSPIx->SPI_CR1 |= ( SPI_SPEED_DIV16 << SPI_CR1_BR );
	}
	else if( SPI_Speed == SPI_SPEED_DIV32 ){
		// set BR bitfield = SPI_SPEED_DIV_32
		pSPIx->SPI_CR1 |= ( SPI_SPEED_DIV32 << SPI_CR1_BR );
	}
	else if( SPI_Speed == SPI_SPEED_DIV64 ){
		// set BR bitfield = SPI_SPEED_DIV_64
		pSPIx->SPI_CR1 |= ( SPI_SPEED_DIV64 << SPI_CR1_BR );
	}
	else if( SPI_Speed == SPI_SPEED_DIV128 ){
		// set BR bitfield = SPI_SPEED_DIV_128
		pSPIx->SPI_CR1 |= ( SPI_SPEED_DIV128 << SPI_CR1_BR );
	}
	else if( SPI_Speed == SPI_SPEED_DIV256 ){
		// set BR bitfield = SPI_SPEED_DIV_256
		pSPIx->SPI_CR1 |= ( SPI_SPEED_DIV256 << SPI_CR1_BR );
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

void SPIx_SendData(SPIx_REG_DEF_t* pSPIx, uint8_t *pTxBuffer, uint32_t len)
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

void SPIx_ReceiveData(SPIx_REG_DEF_t* pSPIx, uint8_t *pRxBuffer, uint32_t len)
{
	while( len > 0 )
	{
		// 1. check if RXNE flag is 0 (Then it is empty)
		while( (pSPIx->SPI_SR & ( 1 << SPI_SR_RXNE)) );

		// 2. check the data frame format (DFF)
		if ((pSPIx->SPI_CR1 & 1 << SPI_CR1_DFF) == 0)
		{	// this is 8-bit format********************************************
			*pRxBuffer = pSPIx->SPI_DR;
			pRxBuffer++;
			len--;
		}
		else if ((pSPIx->SPI_CR1 & 1 << SPI_CR1_DFF) == 1)
		{	// this is 16-bit format ******************************************
			*(uint16_t*)pRxBuffer = pSPIx->SPI_DR;
			(uint16_t*)pRxBuffer++;
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


// function to set CR2 bitfields
void set_SPI_CR2(SPIx_REG_DEF_t *pSPIx, uint8_t bit_Field, uint8_t set_reset )
{
	// sets the SSM bit (1 is software slave management enabled)
	if( set_reset == SET )
	{
		(pSPIx->SPI_CR2 |= 1 << bit_Field);
	}
	else if ( set_reset == RESET )
	{
		(pSPIx->SPI_CR2 &= ~(1 << bit_Field));
	}

}

