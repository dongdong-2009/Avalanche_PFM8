/**
  ******************************************************************************
  * @file    drv_uart.c 
  * @author  MMY Application Team
  * @version V1.1
  * @date    15/03/2011
  * @brief   This file provides  a set of firmaware functions to manages UART communications
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "drv_uart.h"
#include "hw_config.h"
#include "stm32f10x_usart.h"
#include "miscellaneous.h"
#include "usb_type.h"
extern bool CR95HF_TimeOut;

/** @addtogroup Drivers
 * 	@{
 */

/** @addtogroup UART
 * 	@{
 */

/** @defgroup UART_Functions
 *  @{
 */

/**
 * @brief  Send one byte over UART
 * @param  USARTx : where x can be 1, 2, 3 to select the USART peripheral
 * @param  data 	: data to send
 * @return None 
 */
void UART_SendByte(USART_TypeDef* USARTx, uint8_t data) 
{	
	/* Wait for USART Tx buffer empty */
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);

	/* Send byte through the UART peripheral */
	USART_SendData(USARTx, data);	
}

/**
 * @brief  Receive one byte over UART
 * @param  USARTx : where x can be 1, 2, 3 to select the USART peripheral
 * @return None 
 */
uint8_t UART_ReceiveByte( USART_TypeDef* USARTx ) 
{	
	StartTimeOut(300);
	/* Wait for UART data reception	*/
	while(USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == RESET && CR95HF_TimeOut != TRUE);
	StopTimeOut( );
	/* Read & return UART received data	*/
	return USART_ReceiveData(USARTx);
}

/**
 * @brief  Send a byte array over UART
 * @param  USARTx : where x can be 1, 2, 3 to select the USART peripheral
 * @param  pData  : buffer to send
 * @param  length : number of bytes to send
 * @return None 
 */
void UART_SendBuffer(USART_TypeDef* USARTx, uc8 *pCommand, uint8_t length) 
{
	uint8_t i;

	for(i=0; i<length; i++)
	{
		UART_SendByte(USARTx, pCommand[i]);
	}
}

/**
 * @brief  Send a byte array over UART
 * @param  USARTx 	 : where x can be 1, 2, 3 to select the USART peripheral
 * @param  pResponse : pointer on the buffer response
 * @param  length 	 : number of bytes to read
 * @return None 
 */
void UART_ReceiveBuffer(USART_TypeDef* USARTx, uint8_t *pResponse, uint8_t length) 
{
uint8_t i;

	// the buffer size is limited to SPI_RESPONSEBUFFER_SIZE
	length = MIN (UART_RESPONSEBUFFER_SIZE,length);
	for(i=0; i<length; i++)
		pResponse[i] = UART_ReceiveByte(USARTx);
	
}

/**
 * @}
 */ 

/**
*  @}
*/ 

/**
*  @}
*/
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
