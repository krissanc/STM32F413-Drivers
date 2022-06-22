/*
 * LCD_drivers.h
 *
 *  Created on: 11 maj 2022
 *      Author: krcur
 */

#ifndef LCD_DRIVERS_H_
#define LCD_DRIVERS_H_

#include "STM32F413ZHT6_specific.h"




typedef struct
{
	uint32_t port;
	uint8_t pin;

}LCD_SUB_PINOUT_t;

typedef struct
{
	LCD_SUB_PINOUT_t LCD_RS;
	LCD_SUB_PINOUT_t LCD_RW;
	LCD_SUB_PINOUT_t LCD_EN;
	LCD_SUB_PINOUT_t LCD_D4;
	LCD_SUB_PINOUT_t LCD_D5;
	LCD_SUB_PINOUT_t LCD_D6;
	LCD_SUB_PINOUT_t LCD_D7;
}LCD_PINOUT_t;




// Function Prototypes

void LCD_Init(LCD_PINOUT_t *pLCD);
void LCD_Write(uint8_t data);

















#endif /* LCD_DRIVERS_H_ */
