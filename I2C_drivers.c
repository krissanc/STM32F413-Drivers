/*
 * I2C_drivers.c
 *
 *  Created on: 24 may 2022
 *      Author: Kristian
 */

#include "I2C_drivers.h"





void I2C_Clock_Enable(I2C_REG_DEF_t *pI2C)
{
		if(pI2C == I2C1)
		{
			I2C1_CLK_EN();
		}
		else if(pI2C == I2C2)
		{
			I2C2_CLK_EN();
		}
		else if(pI2C == I2C3)
		{
			I2C3_CLK_EN();
		}
}

void I2C_Clock_Disable(I2C_REG_DEF_t *pI2C)
{
		if(pI2C == I2C1)
		{
			I2C1_CLK_DIS();
		}
		else if(pI2C == I2C2)
		{
			I2C2_CLK_DIS();
		}
		else if(pI2C == I2C3)
		{
			I2C3_CLK_DIS();
		}
}





void I2C_Setup_Config(I2C_REG_DEF_t *pI2Cx, uint8_t mode, uint16_t scl_Speed, uint8_t duty, uint8_t dev_Addr, uint8_t riseTime)
{
	// variable declarations
	uint16_t value_CCR;

	// Set PE bit in the CR1 register to 0 to begin configuring the I2C peripheral
	pI2Cx->I2C_CR1 &= ~( 1 << I2C_CR1_PE);

	// Set the Ack bit in the CR1 register to enable Acking
	pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_ACK );

	// Program the Peripheral Clock Frequency into the CR2 FREQ register
	pI2Cx->I2C_CR2 |= (16U & 0x1F);


	// Choose mode: Standard Mode
	if( mode == I2C_SM )
	{
		pI2Cx->I2C_CCR &= ~( 1 << I2C_CCR_FS );
		value_CCR = ((16*1000)/2*scl_Speed) & 0xFFF;
		pI2Cx->I2C_CCR |= value_CCR;

	}

	// Fast Mode
	else if( mode == I2C_FM )
	{
		// Set the F/S bit in the CCR register
		pI2Cx->I2C_CCR |= ( 1 << I2C_CCR_FS );

		// Configure DUTY
		if( duty == I2C_2 )
		{
			pI2Cx->I2C_CCR &= ~( 1 << I2C_CCR_DUTY );
			value_CCR = ((16*1000)/3*scl_Speed) & 0xFFF;
			pI2Cx->I2C_CCR |= value_CCR;
		}
		else if( duty == I2C_16_9 )
		{
			pI2Cx->I2C_CCR |= ( 1 << I2C_CCR_DUTY );
			value_CCR = ((16*1000)/25*scl_Speed) & 0xFFF;
			pI2Cx->I2C_CCR |= value_CCR;
		}

	}





	// Set PE bit in the CR1 register to 1 at the end after configuring the I2C peripheral
	// Ack can only be set if PE = 1, which is required for communication
	pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_PE);


} // End of Setup Config Function


void I2CMasterSendData(I2C_REG_DEF_t *pI2Cx, uint8_t *pTxBuffer, uint32_t len, uint8_t slaveAddr)
{
	// Generate START condition
	pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_START);

	// check the SB flag ensuring START condition was generated
	while( !( pI2Cx->I2C_SR1 & (1 << I2C_SR1_SB) ) );

	// Send the address with r/nw bit = 0
	slaveAddr = slaveAddr << 1; 		// Shift address one step to the left
	slaveAddr &= ~( 1 << 0 );			// Set the LSB (1st-bit) to 0 (WRITE)
	pI2Cx->I2C_DR = slaveAddr;			// Set the Data Register to slaveAddr

	// Wait for the ADDR flag to set
	while( !( pI2Cx->I2C_SR1 & (1 << I2C_SR1_ADDR) ) );

	// Clear the ADDR flag by reading from SR1 register and SR2 register (use dummy variables)
	uint32_t dummyRead = pI2Cx->I2C_SR1;
	dummyRead = pI2Cx->I2C_SR2;

	// Send the data

	while(len > 0)
	{
		while( !(pI2Cx->I2C_SR1 & (1 << I2C_SR1_TxE)) );		// wait for TxE flag to set
		pI2Cx->I2C_DR = *pTxBuffer;								// write the element of the buffer array into the Data Register
		pTxBuffer++;											// increment the buffer address to point to next element
		len--;													// decrease the len by 1
	}

	// Wait for TxE = 1
	while( !( pI2Cx->I2C_SR1 & ( 1 << I2C_SR1_TxE) ) );
	// and BTF = 1
	while( !( pI2Cx->I2C_SR1 & ( 1 << I2C_SR1_BTF) ) );


	// Initiate the STOP condition
	pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_STOP );

}

void I2CMasterReceiveData(I2C_REG_DEF_t *pI2Cx, uint8_t *pRxBuffer, uint32_t len, uint8_t slaveAddr)
{
	// Generate START condition
	pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_START);

	// check the SB flag ensuring START condition was generated
	while( !( pI2Cx->I2C_SR1 & (1 << I2C_SR1_SB) ) );

	// Send the address with r/nw bit equal to 1 (READ)
	slaveAddr = slaveAddr << 1; 		// Shift address one step to the left
	slaveAddr |= ( 1 << 1 );			// Set the LSB (1st-bit) to 1 (READ)
	pI2Cx->I2C_DR = slaveAddr;			// Set the Data Register to slaveAddr

	// Wait for the ADDR flag to set
	while( !( pI2Cx->I2C_SR1 & (1 << I2C_SR1_ADDR) ) );

	// Reading 1-byte
	if( len == 1 )
	{
		// Disable Ack
		pI2Cx->I2C_CR1 &=  ~( 1 << I2C_CR1_ACK );

		// Initiate the STOP condition
		pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_STOP );

		// Clear the ADDR flag by reading from SR1 register and SR2 register (use dummy variables)
		uint32_t dummyRead = pI2Cx->I2C_SR1;
		dummyRead = pI2Cx->I2C_SR2;

		// Wait until RxNE flag becomes 1
		while( !(pI2Cx->I2C_SR1 & (1 << I2C_SR1_RxNE)) );

		// Read the data from the Data Register into the Rx Buffer
		*pRxBuffer = pI2Cx->I2C_DR;

	}	// End of reading 1 - byte


	if( len > 1 )
	{
		// Clear the ADDR flag by reading from SR1 register and SR2 register (use dummy variables)
		uint32_t dummyRead = pI2Cx->I2C_SR1;
		dummyRead = pI2Cx->I2C_SR2;

		//
		for( uint32_t i = len; i > 0; i--)
		{
			// Wait until RxNE flag becomes 1
			while( !(pI2Cx->I2C_SR1 & (1 << I2C_SR1_RxNE)) );

			if( i == 2 )
			{
				// Disable Ack
				pI2Cx->I2C_CR1 &=  ~( 1 << I2C_CR1_ACK );

				// Initiate the STOP condition
				pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_STOP );

			}

			// Read the data from the Data Register into the Rx Buffer
			*pRxBuffer = pI2Cx->I2C_DR;
			pRxBuffer++;

		}

		// Enable Ack again
		pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_ACK );

	} // End of reading multiple bytes




}

