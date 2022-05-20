/*
 * STM32F413ZHT6_specific.h
 *
 *
 *	****** MCU SPECIFIC HEADER FILE ******
 *
 *
 *
 *  Created on: May 5, 2022
 *      Author: krcur
 */

/** Compiler directive ***/
#ifndef STM32F413ZHT6_SPECIFIC_H_
#define STM32F413ZHT6_SPECIFIC_H_



/********************************************************************************
******** Includes ***************************************************************
*********************************************************************************/


/*** Standard libraries ***/
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>





/********************************************************************************
******** Register Structs ***************************************************************
*********************************************************************************/

/**** RCC REGISTER DEFINITION STRUCT *****/
typedef struct{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_AHB2RSTR;
    volatile uint32_t RCC_AHB3RSTR;
    volatile uint32_t RCC_RESERVED;
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t RCC_RESERVED2;
    volatile uint32_t RCC_RESERVED3;
    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_AHB2ENR;
    volatile uint32_t RCC_AHB3ENR;
    volatile uint32_t RCC_RESERVED4;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RCC_RESERVED5;
    volatile uint32_t RCC_RESERVED6;
    volatile uint32_t RCC_AHB1LPENR;
    volatile uint32_t RCC_AHB2LPENR;
    volatile uint32_t RCC_AHB3LPENR;
    volatile uint32_t RCC_RESERVED7;
    volatile uint32_t RCC_APB1LPENR;
    volatile uint32_t RCC_APB2LPENR;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile uint32_t RCC_SSCGR;
    volatile uint32_t RCC_PLLI2SCFGR;
    volatile uint32_t RCC_DCKCFGR;
    volatile uint32_t CKGATENR;
    volatile uint32_t RCC_DCKCFGR2;

}RCC_REG_DEF_t;

/***** EXTI REGISTER DEFINITION STRUCTURE *****/
typedef struct{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;

}EXTI_REG_DEF_t;


/***** SYSCFG REGISTER DEFINITION STRUCTURE *****/
typedef struct{
	volatile uint32_t SYSCFG_MEMRMP;
	volatile uint32_t SYSCFG_PMC;
	volatile uint32_t SYSCFG_EXTICR1;
	volatile uint32_t SYSCFG_EXTICR2;
	volatile uint32_t SYSCFG_EXTICR3;
	volatile uint32_t SYSCFG_EXTICR4;
	volatile uint32_t SYSCFG_RESERVED0;
	volatile uint32_t SYSCFG_CFGR2;
	volatile uint32_t SYSCFG_CMPCR;
	volatile uint32_t SYSCFG_RESERVED1;
	volatile uint32_t SYSCFG_RESERVED2;
	volatile uint32_t SYSCFG_MCHDLYCR;

}SYSCFG_REG_DEF_t;

/***** NVIC ISER REGISTER DEFINITION STRUCTURE *****/
typedef struct{
	volatile uint32_t NVIC_ISER0;
	volatile uint32_t NVIC_ISER1;
	volatile uint32_t NVIC_ISER2;
	volatile uint32_t NVIC_ISER3;
	volatile uint32_t NVIC_ISER4;
	volatile uint32_t NVIC_ISER5;
	volatile uint32_t NVIC_ISER6;
	volatile uint32_t NVIC_ISER7;

}NVIC_ISER_REG_DEF_t;

/***** NVIC ICER REGISTER DEFINITION STRUCTURE *****/
typedef struct{
	volatile uint32_t NVIC_ISER0;
	volatile uint32_t NVIC_ISER1;
	volatile uint32_t NVIC_ISER2;
	volatile uint32_t NVIC_ISER3;
	volatile uint32_t NVIC_ISER4;
	volatile uint32_t NVIC_ISER5;
	volatile uint32_t NVIC_ISER6;
	volatile uint32_t NVIC_ISER7;

}NVIC_ICER_REG_DEF_t;



/****************************************************************************************
*** Memory Addresses ********************************************************************
*****************************************************************************************/

/**
**** Bus Lines *****************************
**/

#define APB1    0x40000000U
#define APB2    0x40010000U
#define AHB1    0x40020000U
#define AHB2    0x50000000U
#define AHB3    0x60000000U

/**
**** AHB2 Bus *****************************
**/

/**** GPIO ****/

#define GPIOA   ((GPIOx_REG_DEF_t*)0x40020000U)
#define GPIOB   ((GPIOx_REG_DEF_t*)0x40020400U)
#define GPIOC   ((GPIOx_REG_DEF_t*)0x40020800U)
#define GPIOD   ((GPIOx_REG_DEF_t*)0x40020C00U)
#define GPIOE   ((GPIOx_REG_DEF_t*)0x40021000U)
#define GPIOF   ((GPIOx_REG_DEF_t*)0x40021400U)
#define GPIOG   ((GPIOx_REG_DEF_t*)0x40021800U)
#define GPIOH   ((GPIOx_REG_DEF_t*)0x40021C00U)

/********* RCC *********/

#define RCC     ((RCC_REG_DEF_t*)0x40023800UL)
#define CRC     (0x40023000UL)



/**
**** AHB2 Bus *****************************
**/


/**
**** AHB3 Bus *****************************
**/

/**
**** APB1 Bus *****************************
**/

/********* USART *********/
#define USART2      (0x40004400UL)
#define USART3      (0x40004800UL)
#define UART4       (0x40004C00UL)
#define UART5       (0x40005000UL)
#define UART7       (0x40007800UL)
#define UART8       (0x40007C00UL)

/**
**** APB2 Bus *****************************
**/

/********* USART *********/
#define USART1     (0x40011000UL)
#define USART6     (0x40011400UL)
#define UART9      (0x40011800UL)
#define UART10     (0x40011C00UL)

/********* EXTI *********/
#define		EXTI	((EXTI_REG_DEF_t*)(0x40013C00UL))
#define		SYSCFG	((SYSCFG_REG_DEF_t*)(0x40013800UL))

/********* NVIC **********/
#define		NVIC_ICTR			((uint32_t*)(0xE000E004UL))
#define		NVIC_ISER			((NVIC_ISER_REG_DEF_t*)(0xE000E100UL))

#define		NVIC_ICER			((NVIC_ICER_REG_DEF_t*)(0xE000E180UL))

/********* SPI **********/
#define		SPI1				((SPIx_REG_DEF_t*)0x40013000UL)




/***************************************************************************************
**** GENERIC MACROS ********************************************************************
****************************************************************************************/

/**** Clock enable macros ****/
#define     GPIOA_CLK_EN()      (RCC->RCC_AHB1ENR |= ( 1 << 0 ))
#define     GPIOB_CLK_EN()      (RCC->RCC_AHB1ENR |= ( 1 << 1 ))
#define     GPIOC_CLK_EN()      (RCC->RCC_AHB1ENR |= ( 1 << 2 ))
#define     GPIOD_CLK_EN()      (RCC->RCC_AHB1ENR |= ( 1 << 3 ))
#define     GPIOE_CLK_EN()      (RCC->RCC_AHB1ENR |= ( 1 << 4 ))
#define     GPIOF_CLK_EN()      (RCC->RCC_AHB1ENR |= ( 1 << 5 ))
#define     GPIOG_CLK_EN()      (RCC->RCC_AHB1ENR |= ( 1 << 6 ))
#define     GPIOH_CLK_EN()      (RCC->RCC_AHB1ENR |= ( 1 << 7 ))

#define 	SYSCFG_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 14 ))
#define		EXTI_T_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 15 ))

#define		SPI1_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 12 ))
#define		SPI2_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 14 ))
#define		SPI3_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 15 ))
#define		SPI4_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 13 ))
#define		SPI5_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 20 ))


/**** Clock disable macros ****/
#define     GPIOA_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 0 ))
#define     GPIOB_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 1 ))
#define     GPIOC_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 2 ))
#define     GPIOD_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 3 ))
#define     GPIOE_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 4 ))
#define     GPIOF_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 5 ))
#define     GPIOG_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 6 ))
#define     GPIOH_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 7 ))

#define 	SYSCFG_CLK_DIS()		(RCC->RCC_APB2ENR &= ~( 1 << 14 ))
#define		EXTI_T_CLK_DIS()		(RCC->RCC_APB2ENR &= ~( 1 << 15 ))

#define		SPI1_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 12 ))
#define		SPI2_CLK_DIS()			(RCC->RCC_APB1ENR &= ~( 1 << 14 ))
#define		SPI3_CLK_DIS()			(RCC->RCC_APB1ENR &= ~( 1 << 15 ))
#define		SPI4_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 13 ))
#define		SPI5_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 20 ))




/**** Enable / Disable ****/
#define     ENABLE      1
#define     DISABLE     0

/**** Set / Reset ****/
#define     SET         1
#define     RESET       0

/**** High / Low ****/
#define     HIGH        1
#define     LOW       	0

/**** Pin Function ****/
#define     INPUT       0
#define     OUTPUT      1
#define		ALT_FUNC	2
#define		ANALOG		3

/**** Push-Pull / Open-Drain ****/
#define		PUSHPULL	0
#define		OPENDRAIN	1

/**** Pin Speed ****/
#define 	LOW_SPEED		0
#define 	MEDIUM_SPEED	1
#define		FAST_SPEED		2
#define		HIGH_SPEED		3

/**** Pull-up , Pull-down ****/
#define		NOPUPD			0
#define 	PULLUP			1
#define 	PULLDOWN		2

/**** EXTI Lines ****/
#define		EXTI0		0
#define		EXTI1		1
#define		EXTI2		2
#define		EXTI3		3
#define		EXTI4		4
#define		EXTI5		5
#define		EXTI6		6
#define		EXTI7		7
#define		EXTI8		8
#define		EXTI9		9
#define		EXTI10		10
#define		EXTI11		11
#define		EXTI12		12
#define		EXTI13		13
#define		EXTI14		14
#define		EXTI15		15

/**** Rising/Falling Trigger ****/
#define		RT			0
#define		FT			1
#define		RTFT		2
#define		FTRT		2

/**** SPI Macros ****/





/**** GPIO PORTS ****/
#define		PORTA		0
#define		PORTB		1
#define		PORTC		2
#define		PORTD		3
#define		PORTE		4
#define		PORTF		5
#define		PORTG		6
#define		PORTH		7

/**** GPIOA PINS ****/
#define		PA0			0
#define		PA1			1
#define		PA2			2
#define		PA3			3
#define		PA4			4
#define		PA5			5
#define		PA6			6
#define		PA7			7
#define		PA8			8
#define		PA9			9
#define		PA10		10
#define		PA11		11
#define		PA12		12
#define		PA13		13
#define		PA14		14
#define		PA15		15

/**** GPIOB PINS ****/
#define		PB0			16
#define		PB1			17
#define		PB2			18
#define		PB3			19
#define		PB4			20
#define		PB5			21
#define		PB6			22
#define		PB7			23
#define		PB8			24
#define		PB9			25
#define		PB10		26
#define		PB11		27
#define		PB12		28
#define		PB13		29
#define		PB14		30
#define		PB15		31

/**** GPIOC PINS ****/
#define		PC0			32
#define		PC1			33
#define		PC2			34
#define		PC3			35
#define		PC4			36
#define		PC5			37
#define		PC6			38
#define		PC7			39
#define		PC8			40
#define		PC9			41
#define		PC10		42
#define		PC11		43
#define		PC12		44
#define		PC13		45
#define		PC14		46
#define		PC15		47

/**** GPIOD PINS ****/
#define		PD0			48
#define		PD1			49
#define		PD2			50
#define		PD3			51
#define		PD4			52
#define		PD5			53
#define		PD6			54
#define		PD7			55
#define		PD8			56
#define		PD9			57
#define		PD10		58
#define		PD11		59
#define		PD12		60
#define		PD13		61
#define		PD14		62
#define		PD15		63

/**** GPIOE PINS ****/
#define		PE0			64
#define		PE1			65
#define		PE2			66
#define		PE3			67
#define		PE4			68
#define		PE5			69
#define		PE6			70
#define		PE7			71
#define		PE8			72
#define		PE9			73
#define		PE10		74
#define		PE11		75
#define		PE12		76
#define		PE13		77
#define		PE14		78
#define		PE15		79

/**** GPIOF PINS ****/
#define		PF0			80
#define		PF1			81
#define		PF2			82
#define		PF3			83
#define		PF4			84
#define		PF5			85
#define		PF6			86
#define		PF7			87
#define		PF8			88
#define		PF9			89
#define		PF10		90
#define		PF11		91
#define		PF12		92
#define		PF13		93
#define		PF14		94
#define		PF15		95

/**** GPIOG PINS ****/
#define		PG0			96
#define		PG1			97
#define		PG2			98
#define		PG3			99
#define		PG4			100
#define		PG5			101
#define		PG6			102
#define		PG7			103
#define		PG8			104
#define		PG9			105
#define		PG10		106
#define		PG11		107
#define		PG12		108
#define		PG13		109
#define		PG14		110
#define		PG15		111

/**** GPIOH PINS ****/
#define		PH0			112
#define		PH1			113
#define		PH2			114
#define		PH3			115
#define		PH4			116
#define		PH5			118
#define		PH6			119
#define		PH7			120
#define		PH8			121
#define		PH9			122
#define		PH10		123
#define		PH11		124
#define		PH12		125
#define		PH13		126
#define		PH14		127
#define		PH15		128

/*** Alternate Functions ***/
#define		AF0			0
#define		AF1			1
#define		AF2			2
#define		AF3			3
#define		AF4			4
#define		AF5			5
#define		AF6			6
#define		AF7			7
#define		AF8			8
#define		AF9			9
#define		AF10		10
#define		AF11		11
#define		AF12		12
#define		AF13		13
#define		AF14		14
#define		AF15		15

/*** ARFL ***/
#define		AFRL0			0
#define		AFRL1			4
#define		AFRL2			8
#define		AFRL3			12
#define		AFRL4			16
#define		AFRL5			20
#define		AFRL6			24
#define		AFRL7			28

/*** ARFH ***/
#define		AFRH8			0
#define		AFRH9			4
#define		AFRH10			8
#define		AFRH11			12
#define		AFRH12			16
#define		AFRH13			20
#define		AFRH14			24
#define		AFRH15			28


/********************************************************************************
******** Includes ***************************************************************
*********************************************************************************/

/*** Header files ***/
#include "GPIO_drivers.h"
#include "LCD_drivers.h"
#include "SPI_drivers.h"

/** End of Compiler directive ***/
#endif /* STM32F413ZHT6_SPECIFIC_H_ */


