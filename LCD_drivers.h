/*
 * LCD_drivers.h
 *
 *  Created on: 11 maj 2022
 *      Author: krcur
 */

#ifndef LCD_DRIVERS_H_
#define LCD_DRIVERS_H_

#include "STM32F413ZHT6_specific.h"





void LCD_Init(uint8_t RS, uint8_t RW, uint8_t EN, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);
void LCD_Write(uint8_t data);

















#endif /* LCD_DRIVERS_H_ */
