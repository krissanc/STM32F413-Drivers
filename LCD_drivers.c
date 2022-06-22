/*
 * LCD_drivers.c
 *
 *  Created on: 11 maj 2022
 *      Author: krcur
 */


#include "LCD_drivers.h"







/*** LCD Initialization Function ***/
// example: LCD_Init(PA4, PA5, PA6, PC5, PC6, PC7, PC8)
// - so 1st parameter initializes desired MCU pin to the connected RS pin, and so forth

void LCD_Pin_Init(LCD_PINOUT_t *pLCD)
{
	// take the pins that are connected to the MCU: (#1 RS), (#2 Read/Write), (#3 Enable), (#4 D4), (#5 D5), (#6 D6), (#7 D7)
	// and initialize them



/********** RS config ***********/

	// Enable the peripheral clock
	GPIOx_Port_Enable((GPIOx_REG_DEF_t*)pLCD->LCD_RS.port);
	// Enable the GPIO configuration of the designated pinout
	GPIOx_Pin_Config((GPIOx_REG_DEF_t*)pLCD->LCD_RS.port, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, pLCD->LCD_RS.pin);


/********** RW config ***********/

	// Enable the peripheral clock
	GPIOx_Port_Enable((GPIOx_REG_DEF_t*)pLCD->LCD_RW.port);
	// Enable the GPIO configuration of the designated pinout
	GPIOx_Pin_Config((GPIOx_REG_DEF_t*)pLCD->LCD_RW.port, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, pLCD->LCD_RW.pin);


/********** EN config ***********/

	// Enable the peripheral clock
	GPIOx_Port_Enable((GPIOx_REG_DEF_t*)pLCD->LCD_EN.port);
	// Enable the GPIO configuration of the designated pinout
	GPIOx_Pin_Config((GPIOx_REG_DEF_t*)pLCD->LCD_EN.port, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, pLCD->LCD_EN.pin);


/********** D4 config ***********/

	// Enable the peripheral clock
	GPIOx_Port_Enable((GPIOx_REG_DEF_t*)pLCD->LCD_D4.port);
	// Enable the GPIO configuration of the designated pinout
	GPIOx_Pin_Config((GPIOx_REG_DEF_t*)pLCD->LCD_D4.port, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, pLCD->LCD_D4.pin);


/********** D5 config ***********/

	// Enable the peripheral clock
	GPIOx_Port_Enable((GPIOx_REG_DEF_t*)pLCD->LCD_D5.port);
	// Enable the GPIO configuration of the designated pinout
	GPIOx_Pin_Config((GPIOx_REG_DEF_t*)pLCD->LCD_D5.port, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, pLCD->LCD_D5.pin);


/********** D6 config ***********/

	// Enable the peripheral clock
	GPIOx_Port_Enable((GPIOx_REG_DEF_t*)pLCD->LCD_D6.port);
	// Enable the GPIO configuration of the designated pinout
	GPIOx_Pin_Config((GPIOx_REG_DEF_t*)pLCD->LCD_D6.port, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, pLCD->LCD_D6.pin);


/********** D7 config ***********/

	// Enable the peripheral clock
	GPIOx_Port_Enable((GPIOx_REG_DEF_t*)pLCD->LCD_D7.port);
	// Enable the GPIO configuration of the designated pinout
	GPIOx_Pin_Config((GPIOx_REG_DEF_t*)pLCD->LCD_D7.port, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, pLCD->LCD_D7.pin);


} /*** End of LCD Initialization function ***/


void LCD_SetCursor(LCD_PINOUT_t *pLCD)
{



}

void LCD_Write(uint8_t data)
{



}

