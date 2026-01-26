/**
  ******************************************************************************
  * @file    py32e407_hal_sci_ex.h
  * @author  MCU Application Team
  * @brief   Header file of SCI HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
  
  
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PY32E407_HAL_SCI_EX_H
#define __PY32E407_HAL_SCI_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup SCIEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup SCIEx_Exported_Types SCIEx Exported Types
  * @{
  */

/**
  * @brief  SCI wake up from stop mode parameters
  */
typedef struct
{
  uint16_t AddressLength;      /*!< Specifies whether the address is 4 or 7-bit long.
                                    This parameter can be a value of @ref SCIEx_WakeUp_Address_Length.  */

  uint8_t Address;             /*!< SCI node address (7-bit long max). */
} SCI_WakeUpTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup SCIEx_Exported_Constants SCIEx Exported Constants
  * @{
  */

/** @defgroup SCIEx_Word_Length SCIEx Word Length
  * @{
  */
#define SCI_WORDLENGTH_7B          USART_CR1_M1   /*!< 7-bit long SCI frame */
#define SCI_WORDLENGTH_8B          0x00000000U    /*!< 8-bit long SCI frame */
#define SCI_WORDLENGTH_9B          USART_CR1_M0   /*!< 9-bit long SCI frame */
/**
  * @}
  */

/** @defgroup SCIEx_WakeUp_Address_Length SCIEx WakeUp Address Length
  * @{
  */
#define SCI_ADDRESS_DETECT_4B      0x00000000U      /*!< 4-bit long wake-up address */
#define SCI_ADDRESS_DETECT_7B      USART_CR1_ADDM7  /*!< 7-bit long wake-up address */
/**
  * @}
  */

/** @defgroup SCIEx_FIFO_mode SCIEx FIFO  mode
  * @brief    SCI FIFO  mode
  * @{
  */
#define SCI_FIFOMODE_DISABLE        0x00000000U                   /*!< FIFO mode disable */
#define SCI_FIFOMODE_ENABLE         USART_CR1_FIFOEN              /*!< FIFO mode enable  */
/**
  * @}
  */

/** @defgroup SCIEx_TXFIFO_threshold_level SCIEx TXFIFO threshold level
  * @brief    SCI TXFIFO level
  * @{
  */
#define SCI_TXFIFO_THRESHOLD_1_8   0x00000000U                               /*!< TXFIFO reaches 1/8 of its depth */
#define SCI_TXFIFO_THRESHOLD_1_4   USART_CR1_TXFTCFG_0                       /*!< TXFIFO reaches 1/4 of its depth */
#define SCI_TXFIFO_THRESHOLD_1_2   USART_CR1_TXFTCFG_1                       /*!< TXFIFO reaches 1/2 of its depth */
#define SCI_TXFIFO_THRESHOLD_3_4   (USART_CR1_TXFTCFG_0|USART_CR1_TXFTCFG_1) /*!< TXFIFO reaches 3/4 of its depth */
#define SCI_TXFIFO_THRESHOLD_7_8   USART_CR1_TXFTCFG_2                       /*!< TXFIFO reaches 7/8 of its depth */
#define SCI_TXFIFO_THRESHOLD_8_8   (USART_CR1_TXFTCFG_2|USART_CR1_TXFTCFG_0) /*!< TXFIFO becomes empty            */
/**
  * @}
  */

/** @defgroup SCIEx_RXFIFO_threshold_level SCIEx RXFIFO threshold level
  * @brief    SCI RXFIFO level
  * @{
  */
#define SCI_RXFIFO_THRESHOLD_1_8   0x00000000U                               /*!< RXFIFO FIFO reaches 1/8 of its depth */
#define SCI_RXFIFO_THRESHOLD_1_4   USART_CR1_RXFTCFG_0                       /*!< RXFIFO FIFO reaches 1/4 of its depth */
#define SCI_RXFIFO_THRESHOLD_1_2   USART_CR1_RXFTCFG_1                       /*!< RXFIFO FIFO reaches 1/2 of its depth */
#define SCI_RXFIFO_THRESHOLD_3_4   (USART_CR1_RXFTCFG_0|USART_CR1_RXFTCFG_1) /*!< RXFIFO FIFO reaches 3/4 of its depth */
#define SCI_RXFIFO_THRESHOLD_7_8   USART_CR1_RXFTCFG_2                       /*!< RXFIFO FIFO reaches 7/8 of its depth */
#define SCI_RXFIFO_THRESHOLD_8_8   (USART_CR1_RXFTCFG_2|USART_CR1_RXFTCFG_0) /*!< RXFIFO FIFO becomes full             */
/**
  * @}
  */

/**
  * @}
  */
 
/* Exported macros -----------------------------------------------------------*/
/** @defgroup SCIEx_Exported_Macros SCIEx Exported Macros
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
HAL_StatusTypeDef HAL_SCI_RS485Ex_Init(SCI_HandleTypeDef *hsci, uint32_t Polarity, uint32_t AssertionTime,
                                   uint32_t DeassertionTime);

/**
  * @}
  */

/** @addtogroup SCIEx_Exported_Functions_Group2
  * @{
  */
void HAL_SCIEx_WakeupCallback(SCI_HandleTypeDef *hsci);
void HAL_SCIEx_RxFifoFullCallback(SCI_HandleTypeDef *hsci);
void HAL_SCIEx_TxFifoEmptyCallback(SCI_HandleTypeDef *hsci);

/**
  * @}
  */

/** @addtogroup SCIEx_Exported_Functions
  * @{
  */

/* Peripheral Control functions  **********************************************/

HAL_StatusTypeDef HAL_SCI_MultiProcessorEx_AddressLength_Set(SCI_HandleTypeDef *hsci, uint32_t AddressLength);

HAL_StatusTypeDef HAL_SCIEx_EnableFifoMode(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCIEx_DisableFifoMode(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCIEx_SetTxFifoThreshold(SCI_HandleTypeDef *hsci, uint32_t Threshold);
HAL_StatusTypeDef HAL_SCIEx_SetRxFifoThreshold(SCI_HandleTypeDef *hsci, uint32_t Threshold);

HAL_StatusTypeDef HAL_SCIEx_ReceiveToIdle(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size, uint16_t *RxLen, \
                                           uint32_t Timeout);
HAL_StatusTypeDef HAL_SCIEx_ReceiveToIdle_IT(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_SCIEx_ReceiveToIdle_DMA(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size);

HAL_SCI_RxEventTypeTypeDef HAL_SCIEx_GetRxEventType(const SCI_HandleTypeDef *hsci);


/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup SCIEx_Private_Macros SCIEx Private Macros
  * @{
  */

/** @brief  Compute the SCI mask to apply to retrieve the received data
  *         according to the word length and to the parity bits activation.
  * @note   If PCE = 1, the parity bit is not included in the data extracted
  *         by the reception API().
  *         This masking operation is not carried out in the case of
  *         DMA transfers.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @retval None, the mask to apply to SCI RDR register is stored in (__HANDLE__)->Mask field.
  */
#define SCI_MASK_COMPUTATION(__HANDLE__)                              \
  do {                                                                \
    if ((__HANDLE__)->Init.WordLength == SCI_WORDLENGTH_9B)           \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == SCI_PARITY_NONE)               \
      {                                                               \
        (__HANDLE__)->Mask = 0x01FFU;                                 \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x00FFU;                                 \
      }                                                               \
    }                                                                 \
    else if ((__HANDLE__)->Init.WordLength == SCI_WORDLENGTH_8B)      \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == SCI_PARITY_NONE)               \
      {                                                               \
        (__HANDLE__)->Mask = 0x00FFU;                                 \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x007FU;                                 \
      }                                                               \
    }                                                                 \
    else if ((__HANDLE__)->Init.WordLength == SCI_WORDLENGTH_7B)      \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == SCI_PARITY_NONE)               \
      {                                                               \
        (__HANDLE__)->Mask = 0x007FU;                                 \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x003FU;                                 \
      }                                                               \
    }                                                                 \
    else                                                              \
    {                                                                 \
      (__HANDLE__)->Mask = 0x0000U;                                   \
    }                                                                 \
  } while(0U)

/**
  * @brief Ensure that SCI wake-up address length is valid.
  * @param __ADDRESS__ SCI wake-up address length.
  * @retval SET (__ADDRESS__ is valid) or RESET (__ADDRESS__ is invalid)
  */
#define IS_SCI_ADDRESSLENGTH_DETECT(__ADDRESS__)  (((__ADDRESS__) == SCI_ADDRESS_DETECT_4B) || \
                                                   ((__ADDRESS__) == SCI_ADDRESS_DETECT_7B))

/**
  * @brief Ensure that SCI LINK frame length is valid.
  * @param __LENGTH__ SCI LINK frame length.
  * @retval SET (__LENGTH__ is valid) or RESET (__LENGTH__ is invalid)
  */
#define IS_SCI_LIN_WORD_LENGTH(__LENGTH__) (((__LENGTH__) == SCI_WORDLENGTH_8B))
/**
  * @brief Ensure that SCI FIFO mode is valid.
  * @param __STATE__ SCI FIFO mode.
  * @retval SET (__STATE__ is valid) or RESET (__STATE__ is invalid)
  */
#define IS_SCI_FIFO_MODE_STATE(__STATE__)  (((__STATE__) == SCI_FIFOMODE_DISABLE) || \
                                            ((__STATE__) == SCI_FIFOMODE_ENABLE))

/**
  * @brief Ensure that SCI TXFIFO threshold level is valid.
  * @param __THRESHOLD__ SCI TXFIFO threshold level.
  * @retval SET (__THRESHOLD__ is valid) or RESET (__THRESHOLD__ is invalid)
  */
#define IS_SCI_TXFIFO_THRESHOLD(__THRESHOLD__)    (((__THRESHOLD__) == SCI_TXFIFO_THRESHOLD_1_8)  || \
                                                   ((__THRESHOLD__) == SCI_TXFIFO_THRESHOLD_1_4)  || \
                                                   ((__THRESHOLD__) == SCI_TXFIFO_THRESHOLD_1_2)  || \
                                                   ((__THRESHOLD__) == SCI_TXFIFO_THRESHOLD_3_4)  || \
                                                   ((__THRESHOLD__) == SCI_TXFIFO_THRESHOLD_7_8)  || \
                                                   ((__THRESHOLD__) == SCI_TXFIFO_THRESHOLD_8_8))

/**
  * @brief Ensure that SCI RXFIFO threshold level is valid.
  * @param __THRESHOLD__ SCI RXFIFO threshold level.
  * @retval SET (__THRESHOLD__ is valid) or RESET (__THRESHOLD__ is invalid)
  */
#define IS_SCI_RXFIFO_THRESHOLD(__THRESHOLD__)    (((__THRESHOLD__) == SCI_RXFIFO_THRESHOLD_1_8)  || \
                                                   ((__THRESHOLD__) == SCI_RXFIFO_THRESHOLD_1_4)  || \
                                                   ((__THRESHOLD__) == SCI_RXFIFO_THRESHOLD_1_2)  || \
                                                   ((__THRESHOLD__) == SCI_RXFIFO_THRESHOLD_3_4)  || \
                                                   ((__THRESHOLD__) == SCI_RXFIFO_THRESHOLD_7_8)  || \
                                                   ((__THRESHOLD__) == SCI_RXFIFO_THRESHOLD_8_8))
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_HAL_SCI_H */
/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
