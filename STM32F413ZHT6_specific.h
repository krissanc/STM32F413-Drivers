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

/*** Header files ***/
#include "GPIO_drivers.h"



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
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RCC_AHB1LPENR;
    volatile uint32_t RCC_AHB2LPENR;
    volatile uint32_t RCC_AHB3LPENR;
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

/**** Clock disable macros ****/
#define     GPIOA_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 0 ))
#define     GPIOB_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 1 ))
#define     GPIOC_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 2 ))
#define     GPIOD_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 3 ))
#define     GPIOE_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 4 ))
#define     GPIOF_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 5 ))
#define     GPIOG_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 6 ))
#define     GPIOH_CLK_DIS()      (RCC->RCC_AHB1ENR &= ~( 1 << 7 ))


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









/** End of Compiler directive ***/
#endif /* STM32F413ZHT6_SPECIFIC_H_ */
