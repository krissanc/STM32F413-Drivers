/*
 * GPIO_drivers.c
 *
 *  Created on: 6 maj 2022
 *      Author: krcur
 */


#include "GPIO_drivers.h"


/*** Port Enable Function ***/
void GPIOx_Port_Enable(GPIOx_REG_DEF_t *pGPIOx_Address)
{

	// take the address of the port
	// then enable the clock for that port
	if(pGPIOx_Address == GPIOA)
	{
		GPIOA_CLK_EN();
	}
	else if(pGPIOx_Address == GPIOB)
	{
		GPIOB_CLK_EN();
	}
	else if(pGPIOx_Address == GPIOC)
	{
		GPIOC_CLK_EN();
	}
	else if(pGPIOx_Address == GPIOD)
	{
		GPIOD_CLK_EN();
	}
	else if(pGPIOx_Address == GPIOE)
	{
		GPIOE_CLK_EN();
	}
	else if(pGPIOx_Address == GPIOF)
	{
		GPIOF_CLK_EN();
	}
	else if(pGPIOx_Address == GPIOG)
	{
		GPIOG_CLK_EN();
	}
	else if(pGPIOx_Address == GPIOH)
	{
		GPIOH_CLK_EN();
	}


}

/*** Port Disable Function ***/
void GPIOx_Port_Disable(GPIOx_REG_DEF_t *pGPIOx_Address)
{

	// take the address of the port
	// then disable the clock for that port
	if(pGPIOx_Address == GPIOA)
	{
		GPIOA_CLK_DIS();
	}
	else if(pGPIOx_Address == GPIOB)
	{
		GPIOB_CLK_DIS();
	}
	else if(pGPIOx_Address == GPIOC)
	{
		GPIOC_CLK_DIS();
	}
	else if(pGPIOx_Address == GPIOD)
	{
		GPIOD_CLK_DIS();
	}
	else if(pGPIOx_Address == GPIOE)
	{
		GPIOE_CLK_DIS();
	}
	else if(pGPIOx_Address == GPIOF)
	{
		GPIOF_CLK_DIS();
	}
	else if(pGPIOx_Address == GPIOG)
	{
		GPIOG_CLK_DIS();
	}
	else if(pGPIOx_Address == GPIOH)
	{
		GPIOH_CLK_DIS();
	}


}

/*** Pin Configuration Function ***/
void GPIOx_Pin_Config(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t in_out_mode,
		uint8_t outputType, uint8_t speed, uint8_t pupd, uint8_t pinNumber)
{
	/***** SET THE MODER REGISTER *****/
	if( in_out_mode == INPUT )		// if input
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_MODER &= ~( 3 << 2*pinNumber );
		// set the register to input ( it is 00 by default, so clearing the register slot is enough)


	}else if( in_out_mode == OUTPUT )		// if output
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_MODER &= ~( 3 << 2*pinNumber );

		// Set the register slot to output mode
		pGPIOx_Address->GPIOx_MODER |= ( 1 << 2*pinNumber );


	}else if( in_out_mode == ALT_FUNC )		// if alternate function
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_MODER &= ~( 3 << 2*pinNumber );

		// Set the register slot to alternate function mode
		pGPIOx_Address->GPIOx_MODER |= ( 2 << 2*pinNumber );


	}else if( in_out_mode == ANALOG )		// if analog mode
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_MODER &= ~( 3 << 2*pinNumber );

		// Set the register slot to analog mode
		pGPIOx_Address->GPIOx_MODER |= ( 3 << 2*pinNumber );

	}
	/***** END OF MODER REGISTER SET *****/

/***********************************************************************************************/

	/***** SET THE OTYPER REGISTER *****/
	if( outputType == PUSHPULL )
	{
		// Clear the register slot first
		pGPIOx_Address->GPIOx_OTYPER &= ~( 1 << pinNumber );
		// set the register to Push-Pull ( it is 00 by default, so clearing the register slot is enough )


	}else if( outputType == OPENDRAIN )
	{
		// Clear the register slot first
		pGPIOx_Address->GPIOx_OTYPER &= ~( 1 << pinNumber );

		// Set the register slot to output mode
		pGPIOx_Address->GPIOx_OTYPER |= ( 1 << pinNumber );

	}
	/***** END OF OTYPER REGISTER SET *****/

/***********************************************************************************************/

	/***** SET THE OSPEEDR REGISTER *****/
	if( speed == LOW_SPEED )
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_OSPEEDR &= ~( 3 << 2*pinNumber );
		// set the register to input ( it is 00 by default, so clearing the register slot is enough)


	}else if( speed == MEDIUM_SPEED )
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_OSPEEDR &= ~( 3 << 2*pinNumber );

		// Set the register slot to medium speed
		pGPIOx_Address->GPIOx_OSPEEDR |= ( 1 << 2*pinNumber );


	}else if( speed == FAST_SPEED )
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_OSPEEDR &= ~( 3 << 2*pinNumber );

		// Set the register slot to fast speed
		pGPIOx_Address->GPIOx_OSPEEDR |= ( 2 << 2*pinNumber );


	}else if( speed == HIGH_SPEED )
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_OSPEEDR &= ~( 3 << 2*pinNumber );

		// Set the register slot to high speed
		pGPIOx_Address->GPIOx_OSPEEDR |= ( 3 << 2*pinNumber );


	}

	/***** END OF OSPEEDR REGISTER SET *****/

/***********************************************************************************************/

	/***** SET THE PUPDR REGISTER *****/
	if( pupd == NOPUPD )
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_PUPDR &= ~( 3 << 2*pinNumber );
		// set the register to input ( it is 00 by default, so clearing the register slot is enough )


	}else if( pupd == PULLUP )
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_PUPDR &= ~( 3 << 2*pinNumber );

		// Set the register slot to medium speed
		pGPIOx_Address->GPIOx_PUPDR |= ( 1 << 2*pinNumber );


	}else if( pupd == PULLDOWN )
	{
		// Clear the register slots first
		pGPIOx_Address->GPIOx_PUPDR &= ~( 3 << 2*pinNumber );

		// Set the register slot to fast speed
		pGPIOx_Address->GPIOx_PUPDR |= ( 2 << 2*pinNumber );

	}

	/***** END OF PUPDR REGISTER SET *****/

}

/*** Pin Configuration Reset Function ***/

/**** Pin Write - Toggle pin HIGH or LOW ****/
void GPIOx_Pin_Write(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t pinNumber, uint8_t High_or_Low)
{
	// clear register slot
	pGPIOx_Address->GPIOx_ODR &= ~( 1 << pinNumber);

	// toggle pin OFF

	// toggle pin ON
	if( High_or_Low == HIGH){
		pGPIOx_Address->GPIOx_ODR |= ( 1 << pinNumber);
	}

}

/**** Pin Read ****/
uint8_t GPIOx_Pin_Read(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t pinNumber)
{

	// declare a temporary variable
	uint8_t read_Data = pGPIOx_Address->GPIOx_IDR >> pinNumber;

	// set the temporary variable to the value at the IDR register at the selected pin
	read_Data &= 1;

	if( read_Data == 1){
		return read_Data;
	}
	else if ( read_Data == 0){
		return read_Data;
	}

}



/*
void GPIOx_Pin_Config();

void GPIOx_Pin_Write(GPIOx_REG_DEF_t *pGPIOx_Address, )
{
	// Take the port enable function and enable the clock
	GPIOx_Port_Enable(pGPIOx_Address);




}
*/



