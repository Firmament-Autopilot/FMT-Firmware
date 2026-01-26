/**
  ******************************************************************************
  * @file    py32e407_hal_lpuart_ex.h
  * @author  MCU Application Team
  * @brief   Header file of LPUART HAL module.
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
#ifndef __PY32E407_HAL_LPUART_EX_H
#define __PY32E407_HAL_LPUART_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"
#include "py32e407_hal_lpuart.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup LPUARTEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup LPUARTEx_Exported_Types LPUARTEx Exported Types
  * @{
  */

/**
  * @brief  LPUART wake up from stop mode parameters
  */
typedef struct
{
  uint32_t WakeUpEvent;        /*!< Specifies which event will activate the Wakeup from Stop mode flag (WUF).
                                    This parameter can be a value of @ref LPUART_WakeUp_from_Stop_Selection.
                                    If set to LPUART_WAKEUP_ON_ADDRESS, the two other fields below must
                                    be filled up. */

  uint16_t AddressLength;      /*!< Specifies whether the address is 4 or 7-bit long.
                                    This parameter can be a value of @ref LPUARTEx_WakeUp_Address_Length.  */

  uint8_t Address;             /*!< LPUART node address (7-bit long max). */
} LPUART_WakeUpTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup LPUARTEx_Exported_Constants LPUARTEx Exported Constants
  * @{
  */

/** @defgroup LPUARTEx_Word_Length LPUARTEx Word Length
  * @{
  */
#define LPUART_WORDLENGTH_7B          LPUART_CR1_M1   /*!< 7-bit long LPUART frame */
#define LPUART_WORDLENGTH_8B          0x00000000U     /*!< 8-bit long LPUART frame */
#define LPUART_WORDLENGTH_9B          LPUART_CR1_M0   /*!< 9-bit long LPUART frame */
/**
  * @}
  */

/** @defgroup LPUARTEx_WakeUp_Address_Length LPUARTEx WakeUp Address Length
  * @{
  */
#define LPUART_ADDRESS_DETECT_4B      0x00000000U        /*!< 4-bit long wake-up address */
#define LPUART_ADDRESS_DETECT_7B      LPUART_CR2_ADDM7   /*!< 7-bit long wake-up address */
/**
  * @}
  */

/** @defgroup LPUARTEx_FIFO_mode LPUARTEx FIFO mode
  * @brief    LPUART FIFO mode
  * @{
  */
#define LPUART_FIFOMODE_DISABLE       0x00000000U        /*!< FIFO mode disable */
#define LPUART_FIFOMODE_ENABLE        LPUART_CR1_FIFOEN  /*!< FIFO mode enable  */
/**
  * @}
  */

/** @defgroup LPUARTEx_TXFIFO_threshold_level LPUARTEx TXFIFO threshold level
  * @brief    LPUART TXFIFO threshold level
  * @{
  */
#define LPUART_TXFIFO_THRESHOLD_1_8   0x00000000U                                   /*!< TXFIFO reaches 1/8 of its depth */
#define LPUART_TXFIFO_THRESHOLD_1_4   LPUART_CR3_TXFTCFG_0                          /*!< TXFIFO reaches 1/4 of its depth */
#define LPUART_TXFIFO_THRESHOLD_1_2   (LPUART_CR3_TXFTCFG_2 | LPUART_CR3_TXFTCFG_1) /*!< TXFIFO reaches 1/2 of its depth */
#define LPUART_TXFIFO_THRESHOLD_3_4   (LPUART_CR3_TXFTCFG_0 | LPUART_CR3_TXFTCFG_1) /*!< TXFIFO reaches 3/4 of its depth */
#define LPUART_TXFIFO_THRESHOLD_7_8   LPUART_CR3_TXFTCFG_2                          /*!< TXFIFO reaches 7/8 of its depth */
#define LPUART_TXFIFO_THRESHOLD_8_8   (LPUART_CR3_TXFTCFG_2 | LPUART_CR3_TXFTCFG_0) /*!< TXFIFO becomes empty            */
/**
  * @}
  */

/** @defgroup LPUARTEx_RXFIFO_threshold_level LPUARTEx RXFIFO threshold level
  * @brief    LPUART RXFIFO threshold level
  * @{
  */
#define LPUART_RXFIFO_THRESHOLD_1_8   0x00000000U                                   /*!< RXFIFO FIFO reaches 1/8 of its depth */
#define LPUART_RXFIFO_THRESHOLD_1_4   LPUART_CR3_RXFTCFG_0                          /*!< RXFIFO FIFO reaches 1/4 of its depth */
#define LPUART_RXFIFO_THRESHOLD_1_2   (LPUART_CR3_RXFTCFG_2 | LPUART_CR3_RXFTCFG_1) /*!< RXFIFO FIFO reaches 1/2 of its depth */
#define LPUART_RXFIFO_THRESHOLD_3_4   (LPUART_CR3_RXFTCFG_0 | LPUART_CR3_RXFTCFG_1) /*!< RXFIFO FIFO reaches 3/4 of its depth */
#define LPUART_RXFIFO_THRESHOLD_7_8   LPUART_CR3_RXFTCFG_2                          /*!< RXFIFO FIFO reaches 7/8 of its depth */
#define LPUART_RXFIFO_THRESHOLD_8_8   (LPUART_CR3_RXFTCFG_2 | LPUART_CR3_RXFTCFG_0) /*!< RXFIFO FIFO becomes full             */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup LPUARTEx_Exported_Functions
  * @{
  */

/** @addtogroup LPUARTEx_Exported_Functions_Group1
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
HAL_StatusTypeDef HAL_RS485Ex_Init(LPUART_HandleTypeDef *hlpuart, uint32_t Polarity, uint32_t AssertionTime,
                                   uint32_t DeassertionTime);

/**
  * @}
  */

/** @addtogroup LPUARTEx_Exported_Functions_Group2
  * @{
  */

void HAL_LPUARTEx_WakeupCallback(LPUART_HandleTypeDef *hlpuart);

void HAL_LPUARTEx_RxFifoFullCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUARTEx_TxFifoEmptyCallback(LPUART_HandleTypeDef *hlpuart);

/**
  * @}
  */

/** @addtogroup LPUARTEx_Exported_Functions_Group3
  * @{
  */

/* Peripheral Control functions  **********************************************/
HAL_StatusTypeDef HAL_LPUARTEx_StopModeWakeUpSourceConfig(LPUART_HandleTypeDef *hlpuart, LPUART_WakeUpTypeDef WakeUpSelection);
HAL_StatusTypeDef HAL_LPUARTEx_EnableStopMode(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUARTEx_DisableStopMode(LPUART_HandleTypeDef *hlpuart);

HAL_StatusTypeDef HAL_MultiProcessorEx_AddressLength_Set(LPUART_HandleTypeDef *hlpuart, uint32_t AddressLength);

HAL_StatusTypeDef HAL_LPUARTEx_EnableFifoMode(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUARTEx_DisableFifoMode(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUARTEx_SetTxFifoThreshold(LPUART_HandleTypeDef *hlpuart, uint32_t Threshold);
HAL_StatusTypeDef HAL_LPUARTEx_SetRxFifoThreshold(LPUART_HandleTypeDef *hlpuart, uint32_t Threshold);

/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup LPUARTEx_Private_Macros LPUARTEx Private Macros
  * @{
  */

/** @brief  Report the LPUART clock source.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __CLOCKSOURCE__ output variable.
  * @retval LPUART clocking source, written in __CLOCKSOURCE__.
  */
#define LPUART_GETCLOCKSOURCE(__HANDLE__,__CLOCKSOURCE__)       \
  do {                                                        \
    if((__HANDLE__)->Instance == LPUART)                \
    {                                                         \
      switch(__HAL_RCC_GET_LPUART1_SOURCE())                  \
      {                                                       \
        case RCC_LPUART1CLKSOURCE_PCLK1:                      \
          (__CLOCKSOURCE__) = LPUART_CLOCKSOURCE_PCLK1;         \
          break;                                              \
        case RCC_LPUART1CLKSOURCE_HSI:                        \
          (__CLOCKSOURCE__) = LPUART_CLOCKSOURCE_HSI;           \
          break;                                              \
        case RCC_LPUART1CLKSOURCE_SYSCLK:                     \
          (__CLOCKSOURCE__) = LPUART_CLOCKSOURCE_SYSCLK;        \
          break;                                              \
        case RCC_LPUART1CLKSOURCE_LSE:                        \
          (__CLOCKSOURCE__) = LPUART_CLOCKSOURCE_LSE;           \
          break;                                              \
        default:                                              \
          (__CLOCKSOURCE__) = LPUART_CLOCKSOURCE_UNDEFINED;     \
          break;                                              \
      }                                                       \
    }                                                         \
    else                                                      \
    {                                                         \
      (__CLOCKSOURCE__) = LPUART_CLOCKSOURCE_UNDEFINED;         \
    }                                                         \
  } while(0U)

/** @brief  Report the LPUART mask to apply to retrieve the received data
  *         according to the word length and to the parity bits activation.
  * @note   If PCE = 1, the parity bit is not included in the data extracted
  *         by the reception API().
  *         This masking operation is not carried out in the case of
  *         DMA transfers.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None, the mask to apply to LPUART RDR register is stored in (__HANDLE__)->Mask field.
  */
#define LPUART_MASK_COMPUTATION(__HANDLE__)                           \
  do {                                                                \
    if ((__HANDLE__)->Init.WordLength == LPUART_WORDLENGTH_9B)        \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == LPUART_PARITY_NONE)            \
      {                                                               \
        (__HANDLE__)->Mask = 0x01FFU ;                                \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x00FFU ;                                \
      }                                                               \
    }                                                                 \
    else if ((__HANDLE__)->Init.WordLength == LPUART_WORDLENGTH_8B)   \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == LPUART_PARITY_NONE)            \
      {                                                               \
        (__HANDLE__)->Mask = 0x00FFU ;                                \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x007FU ;                                \
      }                                                               \
    }                                                                 \
    else if ((__HANDLE__)->Init.WordLength == LPUART_WORDLENGTH_7B)   \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == LPUART_PARITY_NONE)            \
      {                                                               \
        (__HANDLE__)->Mask = 0x007FU ;                                \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x003FU ;                                \
      }                                                               \
    }                                                                 \
    else                                                              \
    {                                                                 \
      (__HANDLE__)->Mask = 0x0000U;                                   \
    }                                                                 \
  } while(0U)

/**
  * @brief Ensure that LPUART frame length is valid.
  * @param __LENGTH__ LPUART frame length.
  * @retval SET (__LENGTH__ is valid) or RESET (__LENGTH__ is invalid)
  */
#define IS_LPUART_WORD_LENGTH(__LENGTH__) (((__LENGTH__) == LPUART_WORDLENGTH_7B) || \
                                           ((__LENGTH__) == LPUART_WORDLENGTH_8B) || \
                                           ((__LENGTH__) == LPUART_WORDLENGTH_9B))

/**
  * @brief Ensure that LPUART wake-up address length is valid.
  * @param __ADDRESS__ LPUART wake-up address length.
  * @retval SET (__ADDRESS__ is valid) or RESET (__ADDRESS__ is invalid)
  */
#define IS_LPUART_ADDRESSLENGTH_DETECT(__ADDRESS__) (((__ADDRESS__) == LPUART_ADDRESS_DETECT_4B) || \
                                                     ((__ADDRESS__) == LPUART_ADDRESS_DETECT_7B))

/**
  * @brief Ensure that LPUART TXFIFO threshold level is valid.
  * @param __THRESHOLD__ LPUART TXFIFO threshold level.
  * @retval SET (__THRESHOLD__ is valid) or RESET (__THRESHOLD__ is invalid)
  */
#define IS_LPUART_TXFIFO_THRESHOLD(__THRESHOLD__) (((__THRESHOLD__) == LPUART_TXFIFO_THRESHOLD_1_8) || \
                                                   ((__THRESHOLD__) == LPUART_TXFIFO_THRESHOLD_1_4) || \
                                                   ((__THRESHOLD__) == LPUART_TXFIFO_THRESHOLD_1_2) || \
                                                   ((__THRESHOLD__) == LPUART_TXFIFO_THRESHOLD_3_4) || \
                                                   ((__THRESHOLD__) == LPUART_TXFIFO_THRESHOLD_7_8) || \
                                                   ((__THRESHOLD__) == LPUART_TXFIFO_THRESHOLD_8_8))

/**
  * @brief Ensure that LPUART RXFIFO threshold level is valid.
  * @param __THRESHOLD__ LPUART RXFIFO threshold level.
  * @retval SET (__THRESHOLD__ is valid) or RESET (__THRESHOLD__ is invalid)
  */
#define IS_LPUART_RXFIFO_THRESHOLD(__THRESHOLD__) (((__THRESHOLD__) == LPUART_RXFIFO_THRESHOLD_1_8) || \
                                                   ((__THRESHOLD__) == LPUART_RXFIFO_THRESHOLD_1_4) || \
                                                   ((__THRESHOLD__) == LPUART_RXFIFO_THRESHOLD_1_2) || \
                                                   ((__THRESHOLD__) == LPUART_RXFIFO_THRESHOLD_3_4) || \
                                                   ((__THRESHOLD__) == LPUART_RXFIFO_THRESHOLD_7_8) || \
                                                   ((__THRESHOLD__) == LPUART_RXFIFO_THRESHOLD_8_8))

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32E407_HAL_LPUART_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
