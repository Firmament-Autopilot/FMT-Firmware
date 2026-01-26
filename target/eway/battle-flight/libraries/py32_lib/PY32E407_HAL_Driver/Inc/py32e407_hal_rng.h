/**
  ******************************************************************************
  * @file    py32e407_hal_rng.h
  * @author  MCU Application Team
  * @brief   Header file of RNG HAL module.
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
#ifndef PY32E407_HAL_RNG_H
#define PY32E407_HAL_RNG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

#if defined (RNG)

/** @defgroup RNG RNG
  * @brief RNG HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup RNG_Exported_Types RNG Exported Types
  * @{
  */

/** @defgroup RNG_Exported_Types_Group1 RNG Init Structure definition
  * @{
  */
typedef struct
{
  uint32_t                    RandomSrc0; /*!< Specifies whether to enable Random Source 0.
                                               This parameter can be a value of @ref RNG_Random_Source_0 */
  
  uint32_t                    RandomSrc1; /*!< Specifies whether to enable Random Source 1.
                                               This parameter can be a value of @ref RNG_Random_Source_1 */
} RNG_InitTypeDef;

/**
  * @}
  */

/** @defgroup RNG_Exported_Types_Group2 RNG State Structure definition
  * @{
  */
typedef enum
{
  HAL_RNG_STATE_RESET     = 0x00U,  /*!< RNG not yet initialized or disabled */
  HAL_RNG_STATE_READY     = 0x01U,  /*!< RNG initialized and ready for use   */
  HAL_RNG_STATE_BUSY      = 0x02U,  /*!< RNG internal process is ongoing     */
  HAL_RNG_STATE_TIMEOUT   = 0x03U,  /*!< RNG timeout state                   */
  HAL_RNG_STATE_ERROR     = 0x04U   /*!< RNG error state                     */

} HAL_RNG_StateTypeDef;

/**
  * @}
  */

/** @defgroup RNG_Exported_Types_Group3 RNG Handle Structure definition
  * @{
  */
#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
typedef struct  __RNG_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */
{
  RNG_TypeDef                 *Instance;    /*!< Register base address   */

  RNG_InitTypeDef             Init;         /*!< RNG configuration parameters */

  HAL_LockTypeDef             Lock;         /*!< RNG locking object      */

  __IO HAL_RNG_StateTypeDef   State;        /*!< RNG communication state */

  __IO  uint32_t              ErrorCode;    /*!< RNG Error code          */

  uint32_t                    RandomNumber; /*!< Last Generated RNG Data */

#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
  void (* ReadyDataCallback)(struct __RNG_HandleTypeDef *hrng, uint32_t random32bit);  /*!< RNG Data Ready Callback    */

  void (* MspInitCallback)(struct __RNG_HandleTypeDef *hrng);                          /*!< RNG Msp Init callback      */
  void (* MspDeInitCallback)(struct __RNG_HandleTypeDef *hrng);                        /*!< RNG Msp DeInit callback    */
#endif  /* USE_HAL_RNG_REGISTER_CALLBACKS */

} RNG_HandleTypeDef;

#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL RNG Callback ID enumeration definition
  */
typedef enum
{
  HAL_RNG_MSPINIT_CB_ID                 = 0x00U,     /*!< RNG MspInit callback ID        */
  HAL_RNG_MSPDEINIT_CB_ID               = 0x01U      /*!< RNG MspDeInit callback ID      */

} HAL_RNG_CallbackIDTypeDef;

/**
  * @brief  HAL RNG Callback pointer definition
  */
typedef  void (*pRNG_CallbackTypeDef)(RNG_HandleTypeDef *hrng);                                  /*!< pointer to a common RNG callback function */
typedef  void (*pRNG_ReadyDataCallbackTypeDef)(RNG_HandleTypeDef *hrng, uint32_t random32bit);   /*!< pointer to an RNG Data Ready specific callback function */

#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */

/**
  * @}
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RNG_Exported_Constants RNG Exported Constants
  * @{
  */

/** @defgroup RNG_Error_Definition   RNG Error Definition
  * @{
  */
#define  HAL_RNG_ERROR_NONE             0x00000000U    /*!< No error          */
#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
#define  HAL_RNG_ERROR_INVALID_CALLBACK 0x00000001U    /*!< Invalid Callback error  */
#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */
#define  HAL_RNG_ERROR_TIMEOUT          0x00000002U    /*!< Timeout error     */
#define  HAL_RNG_ERROR_BUSY             0x00000004U    /*!< Busy error        */
/**
  * @}
  */

/** @defgroup RNG_Random_Source_0 RNG Random Source 0
  * @{
  */
#define RNG_RANDOM_SRC0_DISABLE     0x00000000U      /*!<  Random Source 0 is not enabled   */
#define RNG_RANDOM_SRC0_ENABLE      RNG_CR_RBG0_EN   /*!<  Random Source 0 is enabled   */
/**
  * @}
  */

/** @defgroup RNG_Random_Source_1 RNG Random Source 1
  * @{
  */
#define RNG_RANDOM_SRC1_DISABLE     0x00000000U      /*!<  Random Source 1 is not enabled   */
#define RNG_RANDOM_SRC1_ENABLE      RNG_CR_RBG1_EN   /*!<  Random Source 1 is enabled   */
/**
  * @}
  */

/** @defgroup RNG_Flag_definition RNG Flag definition
  * @{
  */
#define RNG_FLAG_DATA_RDY   RNG_SR_DATA_RDY  /*!< Data ready                 */
/**
  * @}
  */

/** @defgroup RNG_Interrupt_definition RNG Interrupt definition
  * @{
  */
#define RNG_IT_DATA_RDY     RNG_CR_IE       /*!< Data Ready interrupt  */
/**
  * @}
  */

/**
  * @}
  */
/* Exported macros -----------------------------------------------------------*/
/** @defgroup RNG_Exported_Macros RNG Exported Macros
  * @{
  */

/** @brief Reset RNG handle state
  * @param  __HANDLE__ RNG Handle
  * @retval None
  */
#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
#define __HAL_RNG_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->State = HAL_RNG_STATE_RESET;       \
                                                       (__HANDLE__)->MspInitCallback = NULL;            \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                    } while(0U)
#else
#define __HAL_RNG_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_RNG_STATE_RESET)
#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */

/**
  * @brief  Enables Random Source 0.
  * @param  __HANDLE__ RNG Handle
  * @retval None
  */
#define __HAL_RNG_ENABLE_RANDOM_SRC0(__HANDLE__) SET_BIT((__HANDLE__)->Instance->CR , RNG_CR_RBG0_EN)

/**
  * @brief  Disables Random Source 0.
  * @param  __HANDLE__ RNG Handle
  * @retval None
  */
#define __HAL_RNG_DISABLE_RANDOM_SRC0(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->CR , RNG_CR_RBG0_EN)

/**
  * @brief  Enables Random Source 1.
  * @param  __HANDLE__ RNG Handle
  * @retval None
  */
#define __HAL_RNG_ENABLE_RANDOM_SRC1(__HANDLE__) SET_BIT((__HANDLE__)->Instance->CR , RNG_CR_RBG1_EN)

/**
  * @brief  Disables Random Source 1.
  * @param  __HANDLE__ RNG Handle
  * @retval None
  */
#define __HAL_RNG_DISABLE_RANDOM_SRC1(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->CR , RNG_CR_RBG1_EN)

/**
  * @brief  Enables the RNG interrupts.
  * @param  __HANDLE__ RNG Handle
  * @param  __INTERRUPT__  specifies the interrupt to enable.
  *         This parameter can be one of the following values:
  *            @arg RNG_IT_DATA_RDY: Data ready interrupt
  * @retval None
  */
#define __HAL_RNG_ENABLE_IT(__HANDLE__, __INTERRUPT__) SET_BIT((__HANDLE__)->Instance->CR , (__INTERRUPT__))

/**
  * @brief  Disables the RNG interrupts.
  * @param  __HANDLE__ RNG Handle
  * @param  __INTERRUPT__  specifies the interrupt to disable.
  *         This parameter can be one of the following values:
  *            @arg RNG_IT_DATA_RDY: Data ready interrupt
  * @retval None
  */
#define __HAL_RNG_DISABLE_IT(__HANDLE__, __INTERRUPT__) CLEAR_BIT((__HANDLE__)->Instance->CR , (__INTERRUPT__))

/** @brief  Checks if RNG interrupt source is enabled or disabled.
  * @param  __HANDLE__ specifies the RNG Handle.
  * @param  __INTERRUPT__  specifies the interrupt to check.
  *         This parameter can be one of the following values:
  *            @arg RNG_IT_DATA_RDY: Data ready interrupt
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  */
#define __HAL_RNG_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) (READ_BIT((__HANDLE__)->Instance->CR , (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief  Set RNG linear feedback shift register value.
  * @param  __HANDLE__ specifies the RNG Handle.
  * @param  __LFSR__ specifies RNG linear feedback shift register value.
  * @retval None
  */
#define __HAL_RNG_SET_LFSR(__HANDLE__, __LFSR__) WRITE_REG((__HANDLE__)->Instance->LFSR, __LFSR__)

/** @brief  Get RNG linear feedback shift register value.
  * @param  __HANDLE__ specifies the RNG Handle.
  * @retval RNG linear feedback shift register value.
  */
#define __HAL_RNG_GET_LFSR(__HANDLE__) READ_REG((__HANDLE__)->Instance->LFSR)

/**
  * @brief  Check whether the specified RNG flag is set or not.
  * @param  __HANDLE__ RNG Handle
  * @param  __FLAG__ RNG flag
  *          This parameter can be one of the following values:
  *            @arg RNG_FLAG_DATA_RDY:  Data ready
  * @retval The new state of __FLAG__ (SET or RESET).
  */
#define __HAL_RNG_GET_FLAG(__HANDLE__, __FLAG__)  (READ_BIT((__HANDLE__)->Instance->SR , (__FLAG__)) == (__FLAG__))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RNG_Exported_Functions RNG Exported Functions
  * @{
  */

/** @defgroup RNG_Exported_Functions_Group1 Initialization and configuration functions
  * @{
  */
HAL_StatusTypeDef HAL_RNG_Init(RNG_HandleTypeDef *hrng);
HAL_StatusTypeDef HAL_RNG_DeInit(RNG_HandleTypeDef *hrng);
void HAL_RNG_MspInit(RNG_HandleTypeDef *hrng);
void HAL_RNG_MspDeInit(RNG_HandleTypeDef *hrng);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_RNG_RegisterCallback(RNG_HandleTypeDef *hrng, HAL_RNG_CallbackIDTypeDef CallbackID,
                                           pRNG_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_RNG_UnRegisterCallback(RNG_HandleTypeDef *hrng, HAL_RNG_CallbackIDTypeDef CallbackID);

HAL_StatusTypeDef HAL_RNG_RegisterReadyDataCallback(RNG_HandleTypeDef *hrng, pRNG_ReadyDataCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_RNG_UnRegisterReadyDataCallback(RNG_HandleTypeDef *hrng);
#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup RNG_Exported_Functions_Group2 Peripheral Control functions
  * @{
  */
HAL_StatusTypeDef HAL_RNG_GenerateRandomNumber(RNG_HandleTypeDef *hrng, uint32_t *random32bit);
HAL_StatusTypeDef HAL_RNG_GenerateRandomNumber_IT(RNG_HandleTypeDef *hrng);
uint32_t HAL_RNG_ReadLastRandomNumber(RNG_HandleTypeDef *hrng);

void HAL_RNG_IRQHandler(RNG_HandleTypeDef *hrng);
void HAL_RNG_ReadyDataCallback(RNG_HandleTypeDef *hrng, uint32_t random32bit);

/**
  * @}
  */

/** @defgroup RNG_Exported_Functions_Group3 Peripheral State functions
  * @{
  */
HAL_RNG_StateTypeDef HAL_RNG_GetState(RNG_HandleTypeDef *hrng);
uint32_t             HAL_RNG_GetError(RNG_HandleTypeDef *hrng);
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup RNG_Private_Macros RNG Private Macros
  * @{
  */
#define IS_RNG_RANDOM_SRC0(SRC) (((SRC) == RNG_RANDOM_SRC0_DISABLE) || \
                                 ((SRC) == RNG_RANDOM_SRC0_ENABLE))

#define IS_RNG_RANDOM_SRC1(SRC) (((SRC) == RNG_RANDOM_SRC1_DISABLE) || \
                                 ((SRC) == RNG_RANDOM_SRC1_ENABLE))

/**
  * @}
  */


/**
  * @}
  */

#endif /* RNG */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif


#endif /* PY32E407_HAL_RNG_H */

