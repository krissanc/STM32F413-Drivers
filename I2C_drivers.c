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


void I2C_Setup_Config(I2C_HANDLE_t *pI2C, uint8_t mode, uint8_t scl_Speed, uint8_t dev_Addr, uint8_t ack_En_Dis, uint8_t riseTime)
{
	// Set PE bit in the CR1 register to 0 to begin configuring the I2C peripheral
	pI2C->pI2C_Registers->I2C_CR1 &= ~( 1 << I2C_CR1_PE);

	// Choose mode: Standard Mode, or Fast mode
	if( mode == I2C_SM )
	{
		pI2C->pI2C_Registers->I2C_CCR &= ~( 1 << I2C_CCR_FS );
	}
	else if( mode == I2C_FM )
	{
		pI2C->pI2C_Registers->I2C_CCR |= ( 1 << I2C_CCR_FS );
	}






	// Set PE bit in the CR1 register to 1 at the end after configuring the I2C peripheral
	pI2C->pI2C_Registers->I2C_CR1 |= ( 1 << I2C_CR1_PE);


}
