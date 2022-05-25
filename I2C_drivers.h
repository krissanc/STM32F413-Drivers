/*
 * I2C_drivers.h
 *
 *  Created on: 24 may 2022
 *      Author: Kristian
 */

#ifndef I2C_DRIVERS_H_
#define I2C_DRIVERS_H_


#include "STM32F413ZHT6_specific.h"

typedef struct
{
	uint32_t I2C_CR1;
	uint32_t I2C_CR2;
	uint32_t I2C_OAR1;
	uint32_t I2C_OAR2;
	uint32_t I2C_DR;
	uint32_t I2C_SR1;
	uint32_t I2C_SR2;
	uint32_t I2C_CCR;
	uint32_t I2C_TRISE;
	uint32_t I2C_FLTR;

}I2C_REG_DEF_t;

typedef struct
{
	uint32_t I2C_Mode;
	uint32_t I2C_SCL_Config;
	uint32_t I2C_Device_Address;
	uint32_t I2C_Set_Ack;
	uint32_t I2C_Config_Rise_Time;

}I2C_CONFIG_t;

typedef struct
{
	I2C_REG_DEF_t *pI2C_Registers;
	I2C_CONFIG_t I2C_Config;

}I2C_HANDLE_t;


/********
 * REGISTER MACROS *
 ********/

// CR1 REGISTER
#define		I2C_CR1_PE			0
#define		I2C_CR1_SMBUS		1


// CCR REGISTER
#define		I2C_CCR_CCR			0
#define		I2C_CCR_DUTY		14
#define		I2C_CCR_FS			15

/********
 * MODE MACROS *
 ********/

#define		I2C_SM		0
#define		I2C_FM		1



void I2C_Clock_Enable(I2C_REG_DEF_t *pI2C);
void I2C_Clock_Disable(I2C_REG_DEF_t *pI2C);


#endif /* I2C_DRIVERS_H_ */
