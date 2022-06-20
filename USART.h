/*
 * USART.h
 *
 *  Created on: 20 juni 2022
 *      Author: krcur
 */

#ifndef USART_H_
#define USART_H_



/*** Includes ***/
#include "STM32F413ZHT6_specific.h"








/***************************************
 ************* STRUCTS *****************
 ***************************************/

//**Register Definition
typedef struct
{

	uint32_t USART_SR;
	uint32_t USART_DR;
	uint32_t USART_BRR;
	uint32_t USART_CR1;
	uint32_t USART_CR2;
	uint32_t USART_CR3;
	uint32_t USART_GTPR;

}USART_REG_DEF_t;


//**Configuration Structure
typedef struct
{
	uint8_t USART_Mode;
	uint8_t USART_Baud;
	uint8_t USART_NoOfStopBits;
	uint8_t USART_WordLength;
	uint8_t USART_ParityControl;
	uint8_t USART_HWFlowControl;

}USART_CONFIG_t;


//**Handle Structure
typedef struct
{
	USART_REG_DEF_t *pUSARTRegDef;
	USART_CONFIG_t USARTConfig;

}USART_HANDLE_t;


/***************************************
 ************* DEFINITIONS *************
 ***************************************/

/***********	MODE	*************/
#define		USART_MODE_TX		0
#define		USART_MODE_RX		1
#define		USART_MODE_RXTX		2
#define		USART_MODE_TXRX		2

/***********	BAUD	*************/
#define		USART_BAUD_1200		1200
#define		USART_BAUD_2400		2400
#define		USART_BAUD_9600		9600
#define		USART_BAUD_19200	19200
#define		USART_BAUD_38400	38400
#define		USART_BAUD_57600	57600
#define		USART_BAUD_115200	115200
#define		USART_BAUD_230400	230400
#define		USART_BAUD_460800	460800
#define		USART_BAUD_921600	921600
#define		USART_BAUD_2M		2000000
#define		USART_BAUD_3M		3000000

/***********	Parity	*************/
#define		USART_PARITY_EN_ODD		2
#define		USART_PARITY_EN_EVEN	1
#define		USART_PARITY_DISABLE	0

/***********	Word Length	*************/
#define		USART_WORD_LENGTH_8BITS		0
#define		USART_WORD_LENGTH_9BITS		1

/***********	# of Stop Bits	*************/
#define		USART_STOPBITS_1		0
#define		USART_STOPBITS_05		1
#define		USART_STOPBITS_2		2
#define		USART_STOPBITS_15		3

/***********	Hardware Flow Control	*************/
#define		USART_HWFC_NONE		0
#define		USART_HWFC_CTS		1
#define		USART_HWFC_RTS		2
#define		USART_HWFC_CTS_RTS	3
#define		USART_HWFC_RTS_CTS	3





#endif /* USART_H_ */
