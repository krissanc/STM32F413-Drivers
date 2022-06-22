/*
 * LCD_drivers.c
 *
 *  Created on: 11 maj 2022
 *      Author: krcur
 */


#include "LCD_drivers.h"







/*** LCD Initialization Function ***/
// Example: LCD_Init(&LCD)
// It will fetch the values stored in the object, just pass its address

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


void LCD_Set4bits(LCD_PINOUT_t *pLCD, uint8_t data)
{
	// Let's say value of data is  0 0 1 1 (0x3)   then D5 will be  0 0 0 1   after the shift, ANDed with 1, and be set to HIGH

	/* D4 */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_D4.port, pLCD->LCD_D4.pin, ((data >> 0) & 0x1));
	/* D5 */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_D5.port, pLCD->LCD_D5.pin, ((data >> 1) & 0x1));
	/* D6 */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_D6.port, pLCD->LCD_D6.pin, ((data >> 2) & 0x1));
	/* D7 */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_D7.port, pLCD->LCD_D7.pin, ((data >> 3) & 0x1));

}

void LCD_Send_Command(LCD_PINOUT_t *pLCD, uint8_t data)
{

	// Sending 4 bits at a time (Higher nibble first)
	// Set Register Select (RS) to LOW
	/* RS */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_RS.port, pLCD->LCD_RS.pin, LOW);

	// Set Read / NOT Write to 0 to Write
	/* RW */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_RW.port, pLCD->LCD_RW.pin, LOW);

	// set Enable to HIGH
	/* EN */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_EN.port, pLCD->LCD_EN.pin, HIGH);

	// The LCD reads what is on the data lines at the EN transition from HIGH to LOW
	// Set D4-D7
	LCD_Set4bits(pLCD, (data >> 4));

	// Set EN to LOW to read what is on the lines
	/* EN */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_EN.port, pLCD->LCD_EN.pin, LOW);

	// Set EN to HIGH
	/* EN */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_EN.port, pLCD->LCD_EN.pin, HIGH);

	// Set D4-D7
	LCD_Set4bits(pLCD, data);

	// Set EN to LOW to read what is on the lines
	/* EN */ GPIOx_Pin_Write((GPIOx_REG_DEF_t*)pLCD->LCD_EN.port, pLCD->LCD_EN.pin, LOW);


}

void LCD_Display_Init(LCD_PINOUT_t *pLCD)
{





}


void LCD_SetCursor(LCD_PINOUT_t *pLCD)
{



}



