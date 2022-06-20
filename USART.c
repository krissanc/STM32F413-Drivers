/*
 * USART.c
 *
 *  Created on: 20 juni 2022
 *      Author: krcur
 */


#include 	"USART.h"

// USART Peripheral Control
void USART_Clk_Cntrl(USART_REG_DEF_t *pUSART, uint8_t control)
{
	if(control == ENABLE)
	{
		if(pUSART == USART1)
		{
			USART1_CLK_EN();
		}

		else if (pUSART == USART2)
		{
			USART2_CLK_EN();
		}

		else if (pUSART == USART3)
		{
			USART3_CLK_EN();
		}

		else if (pUSART == UART4)
		{
			UART4_CLK_EN();
		}

		else if (pUSART == UART5)
		{
			UART5_CLK_EN();
		}

		else if (pUSART == USART6)
		{
			USART6_CLK_EN();
		}

		else if (pUSART == UART7)
		{
			UART7_CLK_EN();
		}

		else if (pUSART == UART8)
		{
			UART8_CLK_EN();
		}

		else if (pUSART == UART9)
		{
			UART9_CLK_EN();
		}

		else if (pUSART == UART10)
		{
			UART10_CLK_EN();
		}

	}

	else if (control == DISABLE)
	{
		if(pUSART == USART1)
		{
			USART1_CLK_DIS();
		}

		else if (pUSART == USART2)
		{
			USART2_CLK_DIS();
		}

		else if (pUSART == USART3)
		{
			USART3_CLK_DIS();
		}

		else if (pUSART == UART4)
		{
			UART4_CLK_DIS();
		}

		else if (pUSART == UART5)
		{
			UART5_CLK_DIS();
		}

		else if (pUSART == USART6)
		{
			USART6_CLK_DIS();
		}

		else if (pUSART == UART7)
		{
			UART7_CLK_DIS();
		}

		else if (pUSART == UART8)
		{
			UART8_CLK_DIS();
		}

		else if (pUSART == UART9)
		{
			UART9_CLK_DIS();
		}

		else if (pUSART == UART10)
		{
			UART10_CLK_DIS();
		}
	}

}


void USART_Init(USART_HANDLE_t *pUSART)
{


}
