/**
  ******************************************************************************
  * @file    drv_uart.h
  * @author  MMY Application Team
  * @version V1.1
  * @date    15/03/2011
  * @brief   This file provides 
  				- set of firmaware functions to manages UART communications
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

/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __UART_H
#define __UART_H

/* Includes ----------------------------------------------------------------- */
#include "stm32f10x.h"

#define UART_RESPONSEBUFFER_SIZE		255

/** @addtogroup Drivers
 * 	@{
 */

/** @addtogroup UART
 * 	@{
 */

/** @defgroup UART_Exported_Functions
 *  @{
 */

/* UART functions */
void 		UART_SendByte		(USART_TypeDef* USARTx, uint8_t data) ;
uint8_t 	UART_ReceiveByte	(USART_TypeDef* USARTx);
void 		UART_SendBuffer		(USART_TypeDef* USARTx, uc8 *pCommand, uint8_t length); 
void 		UART_ReceiveBuffer	(USART_TypeDef* USARTx, uint8_t *pResponse, uint8_t length);

/**
 * @}
 */ 

/**
* @}
*/ 

/**
* @}
*/ 

#endif /* __UART_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
