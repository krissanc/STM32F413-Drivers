/*
 * I2C_drivers.h
 *
 *  Created on: 24 maj 2022
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









#endif /* I2C_DRIVERS_H_ */
