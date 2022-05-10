/*
 * GPIO_drivers.h
 *
 *  Created on: May 5, 2022
 *      Author: krcur
 *
 *      *** GPIO SETTINGS:
 *	******* Use the GPIOx_Port_Enable(GPIOX) function with a port argument (GPIOA, GPIOB, ..., etc. )
 *	******* Then call the GPIOx_Pin_Config() function, which requires the following parameters:
 *	*******	GPIOX, input / output, push-pull / open-drain, the speed, pull-up / pull-down, and finally the pin number
 *	******* Example -> GPIOx_Pin_Config(GPIOE, OUTPUT, PUSHPULL, FAST_SPEED, NOPUPD, 7)
 *	******* This would set the pin
 *
 */



/** Compiler directive ***/
#ifndef GPIO_DRIVERS_H_
#define GPIO_DRIVERS_H_

/*** Includes ***/
#include "STM32F413ZHT6_specific.h"




/***************************************************************************************
**** STRUCT DEFINITIONS ****************************************************************
****************************************************************************************/

/***** GPIO Register Definition Struct *****/

typedef struct{

    volatile uint32_t GPIOx_MODER;
    volatile uint32_t GPIOx_OTYPER;
    volatile uint32_t GPIOx_OSPEEDR;
    volatile uint32_t GPIOx_PUPDR;
    volatile uint32_t GPIOx_IDR;
    volatile uint32_t GPIOx_ODR;
    volatile uint32_t GPIOx_BSRR;
    volatile uint32_t GPIOx_LCKR;
    volatile uint32_t GPIOx_AFRL;
    volatile uint32_t GPIOx_AFRH;

}GPIOx_REG_DEF_t;


/**** GPIOx Pin Configuration struct ****/
typedef struct{
    uint8_t pinNumber;
    uint8_t PinMode;
    uint8_t pinSpeed;
    uint8_t pullUpPullDown;
    uint8_t OutputType;
    uint8_t AlternateFuncMode;

}GPIOx_PIN_CONFIG_t;


/***** GPIOx Handle Struct ****/
typedef struct{

    GPIOx_REG_DEF_t *pGPIOx_Addr;
    GPIOx_PIN_CONFIG_t GPIOx_Pin_Config;

}GPIOx_HANDLE_t;

/***************************************************************************************
**** FUNCTION PROTOTYPES ***************************************************************
****************************************************************************************/

// ENABLE GPIO PORT
void GPIOx_Port_Enable(GPIOx_REG_DEF_t *pGPIOx_Address);

// DISABLE GPIO PORT
void GPIOx_Port_Disable(GPIOx_REG_DEF_t *pGPIOx_Address);

// PIN CONFIGURATION ( TAKES 6 PARAMETERS )
// *1 PORT ADDRESS --- *2 INPUT/OUTPUT MODE --- *3 OUTPUT TYPE --- *4 SPEED --- *5 Pull-up/Pull-down --- *6 Pin number
void GPIOx_Pin_Config(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t in_out_mode,
		uint8_t outputType, uint8_t speed, uint8_t pupd, uint8_t pinNumber);

// PIN WRITE
void GPIOx_Pin_Write(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t pinNumber, uint8_t High_or_Low);

// PIN TOGGLE
void GPIOx_Pin_Toggle(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t pinNumber);

// PIN READ
uint8_t GPIOx_Pin_Read(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t pinNumber);





/***** GPIOx Reading & Writing ****/
void GPIO_Read_From_Input_Pin(void);
void GPIO_Read_From_Input_Port(void);
void GPIO_Write_To_Output_Pin(void);
void GPIO_Write_To_Output_Port(void);
void GPIO_Toggle_Output_Pin(void);

/***** GPIOx IRQ & Interrupt handling ****/
void GPIO_IRQ_Config(void);
void GPIO_IRQ_Handler(void);







/** End of Compiler directive ***/
#endif /* GPIO_DRIVERS_H_ */
