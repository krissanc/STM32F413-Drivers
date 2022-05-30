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
#define		I2C_CR1_PE				0
#define		I2C_CR1_SMBUS			1
#define		I2C_CR1_RES1			2
#define		I2C_CR1_SMBTYPE			3
#define		I2C_CR1_ENARP			4
#define		I2C_CR1_ENPEC			5
#define		I2C_CR1_ENGC			6
#define		I2C_CR1_NOSTRETCH		7
#define		I2C_CR1_START			8
#define		I2C_CR1_STOP			9
#define		I2C_CR1_ACK				10
#define		I2C_CR1_POS				11
#define		I2C_CR1_PEC				12
#define		I2C_CR1_ALERT			13
#define		I2C_CR1_RES2			14
#define		I2C_CR1_SWRST			15

// CR2 REGISTER
#define		I2C_CR2_FREQ				0
#define		I2C_CR2_ITERREN				8
#define		I2C_CR2_ITEVTEN				9
#define		I2C_CR2_ITBUFEN				10
#define		I2C_CR2_DMAEN				11
#define		I2C_CR2_LAST				12

// CCR REGISTER
#define		I2C_CCR_CCR			0
#define		I2C_CCR_DUTY		14
#define		I2C_CCR_FS			15

// SR1 REGISTER
#define		I2C_SR1_SB				0
#define		I2C_SR1_ADDR			1
#define		I2C_SR1_BTF				2
#define		I2C_SR1_ADD10			3
#define		I2C_SR1_STOPF			4
#define		I2C_SR1_RES1			5
#define		I2C_SR1_RxNE			6
#define		I2C_SR1_TxE				7
#define		I2C_SR1_BERR			8
#define		I2C_SR1_ARLO			9
#define		I2C_SR1_AF				10
#define		I2C_SR1_OVR				11
#define		I2C_SR1_PECERR			12
#define		I2C_SR1_RES2			13
#define		I2C_SR1_TIMEOUT			14
#define		I2C_SR1_SMBALERT		15


/********
 * MODE MACROS *
 ********/

#define		I2C_SM		0
#define		I2C_FM		1

#define		I2C_16_9	1
#define		I2C_2		0





void I2C_Clock_Enable(I2C_REG_DEF_t *pI2C);
void I2C_Clock_Disable(I2C_REG_DEF_t *pI2C);

void I2C_Setup_Config(I2C_REG_DEF_t *pI2Cx, uint8_t mode, uint16_t scl_Speed, uint8_t duty, uint8_t dev_Addr, uint8_t riseTime);

void I2CMasterSendData(I2C_REG_DEF_t *pI2Cx, uint8_t *pTxBuffer, uint32_t len, uint8_t slaveAddr);
void I2CMasterReceiveData(I2C_REG_DEF_t *pI2Cx, uint8_t *pRxBuffer, uint32_t len, uint8_t slaveAddr);

#endif /* I2C_DRIVERS_H_ */
