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
******** Register Structs *******************************************************
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

/********* I2C *********/
#define		I2C1		((I2C_REG_DEF_t*)0x40005400UL)
#define		I2C2		((I2C_REG_DEF_t*)0x40005800UL)
#define		I2C3		((I2C_REG_DEF_t*)0x40005C00UL)


/********* USART *********/
#define USART2      ((USART_REG_DEF_t*)(0x40004400UL))
#define USART3      ((USART_REG_DEF_t*)(0x40004800UL))
#define UART4       ((USART_REG_DEF_t*)(0x40004C00UL))
#define UART5       ((USART_REG_DEF_t*)(0x40005000UL))
#define UART7       ((USART_REG_DEF_t*)(0x40007800UL))
#define UART8       ((USART_REG_DEF_t*)(0x40007C00UL))

/**
**** APB2 Bus *****************************
**/

/********* USART *********/
#define 	USART1     ((USART_REG_DEF_t*)(0x40011000UL))
#define 	USART6     ((USART_REG_DEF_t*)(0x40011400UL))
#define 	UART9      ((USART_REG_DEF_t*)(0x40011800UL))
#define 	UART10     ((USART_REG_DEF_t*)(0x40011C00UL))

/********* EXTI *********/
#define		EXTI		((EXTI_REG_DEF_t*)(0x40013C00UL))
#define		SYSCFG		((SYSCFG_REG_DEF_t*)(0x40013800UL))

/********* NVIC **********/
#define		NVIC_ICTR			((uint32_t*)(0xE000E004UL))
#define		NVIC_ISER			((NVIC_ISER_REG_DEF_t*)(0xE000E100UL))

#define		NVIC_ICER			((NVIC_ICER_REG_DEF_t*)(0xE000E180UL))

/********* SPI **********/
#define		SPI1				((SPIx_REG_DEF_t*)0x40013000UL)
#define		SPI4				((SPIx_REG_DEF_t*)0x40013400UL)






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

#define		I2C1_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 21 ))
#define		I2C2_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 22 ))
#define		I2C3_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 23 ))

#define		USART1_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 4 ))
#define		USART2_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 17 ))
#define		USART3_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 18 ))
#define		UART4_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 19 ))
#define		UART5_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 20 ))
#define		USART6_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 5 ))
#define		UART7_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 30 ))
#define		UART8_CLK_EN()		(RCC->RCC_APB1ENR |= ( 1 << 31 ))
#define		UART9_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 6 ))
#define		UART10_CLK_EN()		(RCC->RCC_APB2ENR |= ( 1 << 7 ))




/**** Clock disable macros ****/
#define     GPIOA_CLK_DIS()    	  	(RCC->RCC_AHB1ENR &= ~( 1 << 0 ))
#define     GPIOB_CLK_DIS()    	  	(RCC->RCC_AHB1ENR &= ~( 1 << 1 ))
#define     GPIOC_CLK_DIS()    	  	(RCC->RCC_AHB1ENR &= ~( 1 << 2 ))
#define     GPIOD_CLK_DIS()     	(RCC->RCC_AHB1ENR &= ~( 1 << 3 ))
#define     GPIOE_CLK_DIS()    	    (RCC->RCC_AHB1ENR &= ~( 1 << 4 ))
#define     GPIOF_CLK_DIS()    	    (RCC->RCC_AHB1ENR &= ~( 1 << 5 ))
#define     GPIOG_CLK_DIS()   	    (RCC->RCC_AHB1ENR &= ~( 1 << 6 ))
#define     GPIOH_CLK_DIS()   	    (RCC->RCC_AHB1ENR &= ~( 1 << 7 ))

#define 	SYSCFG_CLK_DIS()		(RCC->RCC_APB2ENR &= ~( 1 << 14 ))
#define		EXTI_T_CLK_DIS()		(RCC->RCC_APB2ENR &= ~( 1 << 15 ))

#define		SPI1_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 12 ))
#define		SPI2_CLK_DIS()			(RCC->RCC_APB1ENR &= ~( 1 << 14 ))
#define		SPI3_CLK_DIS()			(RCC->RCC_APB1ENR &= ~( 1 << 15 ))
#define		SPI4_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 13 ))
#define		SPI5_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 20 ))

#define		I2C1_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 21 ))
#define		I2C2_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 22 ))
#define		I2C3_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 23 ))

#define		USART1_CLK_DIS()		(RCC->RCC_APB2ENR &= ~( 1 << 4 ))
#define		USART2_CLK_DIS()		(RCC->RCC_APB1ENR &= ~( 1 << 17 ))
#define		USART3_CLK_DIS()		(RCC->RCC_APB1ENR &= ~( 1 << 18 ))
#define		UART4_CLK_DIS()			(RCC->RCC_APB1ENR &= ~( 1 << 19 ))
#define		UART5_CLK_DIS()			(RCC->RCC_APB1ENR &= ~( 1 << 20 ))
#define		USART6_CLK_DIS()		(RCC->RCC_APB2ENR &= ~( 1 << 5 ))
#define		UART7_CLK_DIS()			(RCC->RCC_APB1ENR &= ~( 1 << 30 ))
#define		UART8_CLK_DIS()			(RCC->RCC_APB1ENR &= ~( 1 << 31 ))
#define		UART9_CLK_DIS()			(RCC->RCC_APB2ENR &= ~( 1 << 6 ))
#define		UART10_CLK_DIS()		(RCC->RCC_APB2ENR &= ~( 1 << 7 ))


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

/**** Alternate Function ****/
#define			AF0			0
#define			AF1			1
#define			AF2			2
#define			AF3			3
#define			AF4			4
#define			AF5			5
#define			AF6			6
#define			AF7			7
#define			AF8			8
#define			AF9			9
#define			AF10		10
#define			AF11		11
#define			AF12		12
#define			AF13		13
#define			AF14		14
#define			AF15		15



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
#include 	"GPIO_drivers.h"
#include 	"LCD_drivers.h"
#include 	"SPI_drivers.h"
#include 	"I2C_drivers.h"
#include 	"USART.h"

/** End of Compiler directive ***/
#endif /* STM32F413ZHT6_SPECIFIC_H_ */


