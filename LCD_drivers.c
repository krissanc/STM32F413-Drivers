/*
 * LCD_drivers.c
 *
 *  Created on: 11 maj 2022
 *      Author: krcur
 */


#include "LCD_drivers.h"




void lcd_TEST(LCD_PINOUT_t *pLCD)
{

	// RS

	// RW

	// EN

	// D4

	// D5

	// D6

	// D7



	GPIOx_Pin_Config(GPIOA, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, 5 );


}

void LCD_TEST2()
{



}


/*** LCD Initialization Function ***/
// example: LCD_Init(PA4, PA5, PA6, PC5, PC6, PC7, PC8)
// - so 1st parameter initializes desired MCU pin to the connected RS pin, and so forth
void LCD_Init(LCD_PINOUT_t *pLCD, uint8_t RS, uint8_t RW, uint8_t EN, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7)
{
	// take the pins that are connected to the MCU: (#1 RS), (#2 Read/Write), (#3 Enable), (#4 D4), (#5 D5), (#6 D6), (#7 D7)
	// and initialize them



/********** RS config ***********/
	// pins PA0 - PA15
	if(RS >= PA0 && RS <= PA15 ){
		pLCD->LCD_RS.port = PORTA;
		pLCD->LCD_RS.pin = RS;
		GPIOx_Pin_Config(GPIOA, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RS );
	} // pins PB0 - PB15
	else if(RS >= PB0 && RS <= PB15 ){
		pLCD->LCD_RS.port = PORTB;
		pLCD->LCD_RS.pin = RS%16;
		GPIOx_Pin_Config(GPIOB, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RS%16 );
	} // pins PC0 - PC15
	else if(RS >= PC0 && RS <= PC15 ){
		pLCD->LCD_RS.port = PORTC;
		pLCD->LCD_RS.pin = RS%32;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RS%32 );
	} // pins PD0 - PD15
	else if(RS >= PD0 && RS <= PD15 ){
		pLCD->LCD_RS.port = PORTD;
		pLCD->LCD_RS.pin = RS%48;
		GPIOx_Pin_Config(GPIOD, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RS%48 );
	} // pins PE0 - PE15
	else if(RS >= PE0 && RS <= PE15 ){
		pLCD->LCD_RS.port = PORTE;
		pLCD->LCD_RS.pin = RS%64;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RS%64 );
	} // pins PF0 - PF15
	else if(RS >= PF0 && RS <= PF15 ){
		pLCD->LCD_RS.port = PORTF;
		pLCD->LCD_RS.pin = RS%80;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RS%80 );
	} // pins PG0 - PG15
	else if(RS >= PG0 && RS <= PG15 ){
		pLCD->LCD_RS.port = PORTG;
		pLCD->LCD_RS.pin = RS%96;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RS%96 );
	} // pins PH0 - PH15
	else if(RS >= PH0 && RS <= PH15 ){
		pLCD->LCD_RS.port = PORTH;
		pLCD->LCD_RS.pin = RS%112;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RS%112 );
	}

/********** RW config ***********/
	// pins PA0 - PA15
	if(RW >= PA0 && RW <= PA15 ){
		pLCD->LCD_RW.port = PORTA;
		pLCD->LCD_RW.pin = RW;
		GPIOx_Pin_Config(GPIOA, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RW );
	} // pins PB0 - PB15
	else if(RW >= PB0 && RW <= PB15 ){
		pLCD->LCD_RW.port = PORTB;
		pLCD->LCD_RW.pin = RW%16;
		GPIOx_Pin_Config(GPIOB, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RW%16 );
	} // pins PC0 - PC15
	else if(RW >= PC0 && RW <= PC15 ){
		pLCD->LCD_RW.port = PORTC;
		pLCD->LCD_RW.pin = RW%32;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RW%32 );
	} // pins PD0 - PD15
	else if(RW >= PD0 && RW <= PD15 ){
		pLCD->LCD_RW.port = PORTD;
		pLCD->LCD_RW.pin = RW%48;
		GPIOx_Pin_Config(GPIOD, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RW%48 );
	} // pins PE0 - PE15
	else if(RW >= PE0 && RW <= PE15 ){
		pLCD->LCD_RW.port = PORTE;
		pLCD->LCD_RW.pin = RW%64;
		GPIOx_Pin_Config(GPIOE, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RW%64 );
	} // pins PF0 - PF15
	else if(RW >= PF0 && RW <= PF15 ){
		pLCD->LCD_RW.port = PORTF;
		pLCD->LCD_RW.pin = RW%80;
		GPIOx_Pin_Config(GPIOF, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RW%80 );
	} // pins PG0 - PG15
	else if(RW >= PG0 && RW <= PG15 ){
		pLCD->LCD_RW.port = PORTG;
		pLCD->LCD_RW.pin = RW%96;
		GPIOx_Pin_Config(GPIOG, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RW%96 );
	} // pins PH0 - PH15
	else if(RW >= PH0 && RW <= PH15 ){
		pLCD->LCD_RW.port = PORTH;
		pLCD->LCD_RW.pin = RW%112;
		GPIOx_Pin_Config(GPIOH, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, RW%112 );
	}

/********** EN config ***********/
	// pins PA0 - PA15
	if(EN >= PA0 && EN <= PA15 ){
		pLCD->LCD_EN.port = PORTA;
		pLCD->LCD_EN.pin = EN;
		GPIOx_Pin_Config(GPIOA, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, EN );
	} // pins PB0 - PB15
	else if(EN >= PB0 && EN <= PB15 ){
		pLCD->LCD_EN.port = PORTB;
		pLCD->LCD_EN.pin = EN%16;
		GPIOx_Pin_Config(GPIOB, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, EN%16 );
	} // pins PC0 - PC15
	else if(EN >= PC0 && EN <= PC15 ){
		pLCD->LCD_EN.port = PORTC;
		pLCD->LCD_EN.pin = EN%32;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, EN%32 );
	} // pins PD0 - PD15
	else if(EN >= PD0 && EN <= PD15 ){
		pLCD->LCD_EN.port = PORTD;
		pLCD->LCD_EN.pin = EN%48;
		GPIOx_Pin_Config(GPIOD, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, EN%48 );
	} // pins PE0 - PE15
	else if(EN >= PE0 && EN <= PE15 ){
		pLCD->LCD_EN.port = PORTE;
		pLCD->LCD_EN.pin = EN%64;
		GPIOx_Pin_Config(GPIOE, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, EN%64 );
	} // pins PF0 - PF15
	else if(EN >= PF0 && EN <= PF15 ){
		pLCD->LCD_EN.port = PORTF;
		pLCD->LCD_EN.pin = EN%80;
		GPIOx_Pin_Config(GPIOF, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, EN%80 );
	} // pins PG0 - PG15
	else if(EN >= PG0 && EN <= PG15 ){
		pLCD->LCD_EN.port = PORTG;
		pLCD->LCD_EN.pin = EN%96;
		GPIOx_Pin_Config(GPIOG, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, EN%96 );
	} // pins PH0 - PH15
	else if(EN >= PH0 && EN <= PH15 ){
		pLCD->LCD_EN.port = PORTH;
		pLCD->LCD_EN.pin = EN%112;
		GPIOx_Pin_Config(GPIOH, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, EN%112 );
	}

/********** D4 config ***********/
		// pins PA0 - PA15
	if(D4 >= PA0 && D4 <= PA15 ){
		pLCD->LCD_D4.port = PORTA;
		pLCD->LCD_D4.pin = D4;
		GPIOx_Pin_Config(GPIOA, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D4 );
	} // pins PB0 - PB15
	else if(D4 >= PB0 && D4 <= PB15 ){
		pLCD->LCD_D4.port = PORTB;
		pLCD->LCD_D4.pin = D4%16;
		GPIOx_Pin_Config(GPIOB, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D4%16 );
	} // pins PC0 - PC15
	else if(D4 >= PC0 && D4 <= PC15 ){
		pLCD->LCD_D4.port = PORTC;
		pLCD->LCD_D4.pin = D4%32;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D4%32 );
	} // pins PD0 - PD15
	else if(D4 >= PD0 && D4 <= PD15 ){
		pLCD->LCD_D4.port = PORTD;
		pLCD->LCD_D4.pin = D4%48;
		GPIOx_Pin_Config(GPIOD, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D4%48 );
	} // pins PE0 - PE15
	else if(D4 >= PE0 && D4 <= PE15 ){
		pLCD->LCD_D4.port = PORTE;
		pLCD->LCD_D4.pin = D4%64;
		GPIOx_Pin_Config(GPIOE, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D4%64 );
	} // pins PF0 - PF15
	else if(D4 >= PF0 && D4 <= PF15 ){
		pLCD->LCD_D4.port = PORTF;
		pLCD->LCD_D4.pin = D4%80;
		GPIOx_Pin_Config(GPIOF, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D4%80 );
	} // pins PG0 - PG15
	else if(D4 >= PG0 && D4 <= PG15 ){
		pLCD->LCD_D4.port = PORTG;
		pLCD->LCD_D4.pin = D4%96;
		GPIOx_Pin_Config(GPIOG, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D4%96 );
	} // pins PH0 - PH15
	else if(D4 >= PH0 && D4 <= PH15 ){
		pLCD->LCD_D4.port = PORTH;
		pLCD->LCD_D4.pin = D4%112;
		GPIOx_Pin_Config(GPIOH, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D4%112 );
	}

/********** D5 config ***********/
	// pins PA0 - PA15
	if(D5 >= PA0 && D5 <= PA15 ){
		pLCD->LCD_D5.port = PORTA;
		pLCD->LCD_D5.pin = D5;
		GPIOx_Pin_Config(GPIOA, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D5 );
	} // pins PB0 - PB15
	else if(D5 >= PB0 && D5 <= PB15 ){
		pLCD->LCD_D5.port = PORTB;
		pLCD->LCD_D5.pin = D5%16;
		GPIOx_Pin_Config(GPIOB, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D5%16 );
	} // pins PC0 - PC15
	else if(D5 >= PC0 && D5 <= PC15 ){
		pLCD->LCD_D5.port = PORTC;
		pLCD->LCD_D5.pin = D5%32;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D5%32 );
	} // pins PD0 - PD15
	else if(D5 >= PD0 && D5 <= PD15 ){
		pLCD->LCD_D5.port = PORTD;
		pLCD->LCD_D5.pin = D5%48;
		GPIOx_Pin_Config(GPIOD, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D5%48 );
	} // pins PE0 - PE15
	else if(D5 >= PE0 && D5 <= PE15 ){
		pLCD->LCD_D5.port = PORTE;
		pLCD->LCD_D5.pin = D5%64;
		GPIOx_Pin_Config(GPIOE, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D5%64 );
	} // pins PF0 - PF15
	else if(D5 >= PF0 && D5 <= PF15 ){
		pLCD->LCD_D5.port = PORTF;
		pLCD->LCD_D5.pin = D5%80;
		GPIOx_Pin_Config(GPIOF, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D5%80 );
	} // pins PG0 - PG15
	else if(D5 >= PG0 && D5 <= PG15 ){
		pLCD->LCD_D5.port = PORTG;
		pLCD->LCD_D5.pin = D5%96;
		GPIOx_Pin_Config(GPIOG, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D5%96 );
	} // pins PH0 - PH15
	else if(D5 >= PH0 && D5 <= PH15 ){
		pLCD->LCD_D5.port = PORTH;
		pLCD->LCD_D5.pin = D5%112;
		GPIOx_Pin_Config(GPIOH, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D5%112 );
	}

/********** D6 config ***********/
	// pins PA0 - PA15
	if(D6 >= PA0 && D6 <= PA15 ){
		pLCD->LCD_D6.port = PORTA;
		pLCD->LCD_D6.pin = D6;
		GPIOx_Pin_Config(GPIOA, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D6 );
	} // pins PB0 - PB15
	else if(D6 >= PB0 && D6 <= PB15 ){
		pLCD->LCD_D6.port = PORTB;
		pLCD->LCD_D6.pin = D6%16;
		GPIOx_Pin_Config(GPIOB, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D6%16 );
	} // pins PC0 - PC15
	else if(D6 >= PC0 && D6 <= PC15 ){
		pLCD->LCD_D6.port = PORTC;
		pLCD->LCD_D6.pin = D6%32;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D6%32 );
	} // pins PD0 - PD15
	else if(D6 >= PD0 && D6 <= PD15 ){
		pLCD->LCD_D6.port = PORTD;
		pLCD->LCD_D6.pin = D6%48;
		GPIOx_Pin_Config(GPIOD, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D6%48 );
	} // pins PE0 - PE15
	else if(D6 >= PE0 && D6 <= PE15 ){
		pLCD->LCD_D6.port = PORTE;
		pLCD->LCD_D6.pin = D6%64;
		GPIOx_Pin_Config(GPIOE, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D6%64 );
	} // pins PF0 - PF15
	else if(D6 >= PF0 && D6 <= PF15 ){
		pLCD->LCD_D6.port = PORTF;
		pLCD->LCD_D6.pin = D6%80;
		GPIOx_Pin_Config(GPIOF, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D6%80 );
	} // pins PG0 - PG15
	else if(D6 >= PG0 && D6 <= PG15 ){
		pLCD->LCD_D6.port = PORTG;
		pLCD->LCD_D6.pin = D6%96;
		GPIOx_Pin_Config(GPIOG, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D6%96 );
	} // pins PH0 - PH15
	else if(D6 >= PH0 && D6 <= PH15 ){
		pLCD->LCD_D6.port = PORTH;
		pLCD->LCD_D6.pin = D6%112;
		GPIOx_Pin_Config(GPIOH, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D6%112 );
	}

/********** D7 config ***********/
	// pins PA0 - PA15
	if(D7 >= PA0 && D7 <= PA15 ){
		pLCD->LCD_D7.port = PORTA;
		pLCD->LCD_D7.pin = D7;
		GPIOx_Pin_Config(GPIOA, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D7 );
	} // pins PB0 - PB15
	else if(D7 >= PB0 && D7 <= PB15 ){
		pLCD->LCD_D7.port = PORTB;
		pLCD->LCD_D7.pin = D7%16;
		GPIOx_Pin_Config(GPIOB, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D7%16 );
	} // pins PC0 - PC15
	else if(D7 >= PC0 && D7 <= PC15 ){
		pLCD->LCD_D7.port = PORTC;
		pLCD->LCD_D7.pin = D7%32;
		GPIOx_Pin_Config(GPIOC, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D7%32 );
	} // pins PD0 - PD15
	else if(D7 >= PD0 && D7 <= PD15 ){
		pLCD->LCD_D7.port = PORTD;
		pLCD->LCD_D7.pin = D7%48;
		GPIOx_Pin_Config(GPIOD, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D7%48 );
	} // pins PE0 - PE15
	else if(D7 >= PE0 && D7 <= PE15 ){
		pLCD->LCD_D7.port = PORTE;
		pLCD->LCD_D7.pin = D7%64;
		GPIOx_Pin_Config(GPIOE, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D7%64 );
	} // pins PF0 - PF15
	else if(D7 >= PF0 && D7 <= PF15 ){
		pLCD->LCD_D7.port = PORTF;
		pLCD->LCD_D7.pin = D7%80;
		GPIOx_Pin_Config(GPIOF, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D7%80 );
	} // pins PG0 - PG15
	else if(D7 >= PG0 && D7 <= PG15 ){
		pLCD->LCD_D7.port = PORTG;
		pLCD->LCD_D7.pin = D7%96;
		GPIOx_Pin_Config(GPIOG, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D7%96 );
	} // pins PH0 - PH15
	else if(D7 >= PH0 && D7 <= PH15 ){
		pLCD->LCD_D7.port = PORTH;
		pLCD->LCD_D7.pin = D7%112;
		GPIOx_Pin_Config(GPIOH, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, D7%112 );
	}


} /*** End of LCD Initialization function ***/


void LCD_SetCursor(LCD_PINOUT_t *pLCD)
{



}

void LCD_Write(uint8_t data)
{



}

