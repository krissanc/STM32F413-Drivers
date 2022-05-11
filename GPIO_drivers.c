/*
 * GPIO_drivers.c
 *
 *  Created on: 6 maj 2022
 *      Author: krcur
 */


#include "GPIO_drivers.h"


/*** Port Clock Enable Function ***/
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

/*** Port Clock Disable Function ***/
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
void GPIOx_Pin_Reset(void)
{

}



/**** Pin Write ****/
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

/**** Pin Toggle ****/
void GPIOx_Pin_Toggle(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t pinNumber)
{
	// toggle pin
	pGPIOx_Address->GPIOx_ODR ^= ( 1 << pinNumber );

}

/**** Pin Read ****/
uint8_t GPIOx_Pin_Read(GPIOx_REG_DEF_t *pGPIOx_Address, uint8_t pinNumber)
{

	// declare a temporary variable and set it equal to the input data register (shifted to the right) and typecast to 8-bit register
	uint8_t read_Data = (uint8_t)(pGPIOx_Address->GPIOx_IDR >> pinNumber);

	// set the temporary variable to the value at the IDR register at the selected pin
	read_Data &= 1;

	if( read_Data == 1 ){
		return read_Data;
	}
	else if ( read_Data == 0 ){
		return read_Data;
	}

	return 0;
}





// parameters: #1 EXTI line, #2 which port,
// example: interrupt_Config(EXTI, SYSCFG, EXTI0, PORTB, RTFT)
void interrupt_Config(SYSCFG_REG_DEF_t *pSYSCFG, EXTI_REG_DEF_t *pEXTI, uint8_t EXTI_Line, uint8_t portX, uint8_t edge)
{

	// enable the interrupt mask for the selected line
	pEXTI->EXTI_IMR |= ( 1 << EXTI_Line );


	/**** EXTI LINE & PORT SELECTOR ****/
	/**** EXTI LINE & PORT SELECTOR ****/
	/**** EXTI LINE & PORT SELECTOR ****/
	// select which EXTI line the pin is configured to... and enable the selected port
	// this is done in the SYSCFG EXTICR registers
	// and enable the IRQ number in the NVIC
	if(EXTI_Line == EXTI0 ){
		pSYSCFG->SYSCFG_EXTICR1 |= ( portX << 0 );
		// also enable the IRQ number in the NVIC
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 6 );

	}else if(EXTI_Line == EXTI1 ){
		pSYSCFG->SYSCFG_EXTICR1 |= ( portX << 4 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 7 );

	}else if(EXTI_Line == EXTI2 ){
		pSYSCFG->SYSCFG_EXTICR1 |= ( portX << 8 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 8 );

	}else if(EXTI_Line == EXTI3 ){
		pSYSCFG->SYSCFG_EXTICR1 |= ( portX << 12 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 9 );

	}else if(EXTI_Line == EXTI4 ){
		pSYSCFG->SYSCFG_EXTICR2 |= ( portX << 0 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 10 );

	}else if(EXTI_Line == EXTI5 ){
		pSYSCFG->SYSCFG_EXTICR2 |= ( portX << 4 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 23 );

	}else if(EXTI_Line == EXTI6 ){
		pSYSCFG->SYSCFG_EXTICR2 |= ( portX << 8 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 23 );

	}else if(EXTI_Line == EXTI7 ){
		pSYSCFG->SYSCFG_EXTICR2 |= ( portX << 12 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 23 );

	}else if(EXTI_Line == EXTI8 ){
		pSYSCFG->SYSCFG_EXTICR3 |= ( portX << 0 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 23 );

	}else if(EXTI_Line == EXTI9 ){
		pSYSCFG->SYSCFG_EXTICR3 |= ( portX << 4 );
		NVIC_ISER->NVIC_ISER0 |= ( 1 << 23 );

	}else if(EXTI_Line == EXTI10 ){
		pSYSCFG->SYSCFG_EXTICR3 |= ( portX << 8 );
		NVIC_ISER->NVIC_ISER1 |= ( 1 << (40%32) );

	}else if(EXTI_Line == EXTI11 ){
		pSYSCFG->SYSCFG_EXTICR3 |= ( portX << 12 );
		NVIC_ISER->NVIC_ISER1 |= ( 1 << (40%32) );

	}else if(EXTI_Line == EXTI12 ){
		pSYSCFG->SYSCFG_EXTICR4 |= ( portX << 0 );
		NVIC_ISER->NVIC_ISER1 |= ( 1 << (40%32) );

	}else if(EXTI_Line == EXTI13 ){
		pSYSCFG->SYSCFG_EXTICR4 |= ( portX << 4 );
		NVIC_ISER->NVIC_ISER1 |= ( 1 << (40%32) );

	}else if(EXTI_Line == EXTI14 ){
		pSYSCFG->SYSCFG_EXTICR4 |= ( portX << 8 );
		NVIC_ISER->NVIC_ISER1 |= ( 1 << (40%32) );

	}else if(EXTI_Line == EXTI15 ){
		pSYSCFG->SYSCFG_EXTICR4 |= ( portX << 12 );
		NVIC_ISER->NVIC_ISER1 |= ( 1 << (40%32) );

	}


	/**** TRIGGER SELECTOR ****/
	/**** TRIGGER SELECTOR ****/
	/**** TRIGGER SELECTOR ****/
	// set the pin to rising edge, falling edge, or both
	// this is done in the EXTI register
	if(edge == RT)
	{
		pEXTI->EXTI_RTSR |= ( 1 << EXTI_Line);
		pEXTI->EXTI_FTSR &= ~( 1 << EXTI_Line);

	}else if (edge == FT)
	{
		pEXTI->EXTI_FTSR |= ( 1 << EXTI_Line);
		pEXTI->EXTI_RTSR &= ~( 1 << EXTI_Line);

	}else if (edge == RTFT)
	{
		// enable both
		pEXTI->EXTI_RTSR |= ( 1 << EXTI_Line);
		pEXTI->EXTI_FTSR |= ( 1 << EXTI_Line);
	}

}

// IRQ Handler
void GPIO_IRQ_Handler(uint8_t pinNumber)
{
	if(EXTI->EXTI_PR & ( 1 << pinNumber )){
		EXTI->EXTI_PR |= ( 1 << pinNumber );
	}
}


