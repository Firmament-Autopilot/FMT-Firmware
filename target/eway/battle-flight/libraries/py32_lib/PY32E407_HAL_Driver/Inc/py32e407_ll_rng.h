/**
  ******************************************************************************
  * @file    py32e407_ll_rng.h
  * @author  MCU Application Team
  * @brief   Header file of RNG LL module.
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
#ifndef PY32E407_LL_RNG_H
#define PY32E407_LL_RNG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (RNG)

/** @defgroup RNG_LL RNG
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup RNG_LL_Exported_Constants RNG Exported Constants
  * @{
  */


/** @defgroup RNG_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_RNG_ReadReg function
  * @{
  */
#define LL_RNG_SR_DRDY RNG_SR_DATA_RDY    /*!< Register contains valid random data */
/**
  * @}
  */

/** @defgroup RNG_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_RNG_ReadReg and  LL_RNG_WriteReg macros
  * @{
  */
#define LL_RNG_CR_IE   RNG_CR_IE      /*!< RNG Interrupt enable */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RNG_LL_Exported_Macros RNG Exported Macros
  * @{
  */

/** @defgroup RNG_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in RNG register
  * @param  __INSTANCE__ RNG Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_RNG_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in RNG register
  * @param  __INSTANCE__ RNG Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_RNG_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup RNG_LL_Exported_Functions RNG Exported Functions
  * @{
  */
/** @defgroup RNG_LL_EF_Configuration RNG Configuration functions
  * @{
  */

/**
  * @brief  Enable Random Number block 0 Generation
  * @rmtoll CR           RBG0_EN         LL_RNG_EnableBlockGeneration0
  * @param  RNGx RNG Instance
  * @retval None
  */
__STATIC_INLINE void LL_RNG_EnableBlockGeneration0(RNG_TypeDef *RNGx)
{
  SET_BIT(RNGx->CR, RNG_CR_RBG0_EN);
}

/**
  * @brief  Disable Random Number Block 0 Generation
  * @rmtoll CR           RBG0_EN         LL_RNG_DisableBlockGeneration0
  * @param  RNGx RNG Instance
  * @retval None
  */
__STATIC_INLINE void LL_RNG_DisableBlockGeneration0(RNG_TypeDef *RNGx)
{
  CLEAR_BIT(RNGx->CR, RNG_CR_RBG0_EN);
}

/**
  * @brief  Check if Random Number Block 0 Generator is enabled
  * @rmtoll CR           RBG0_EN         LL_RNG_Block_IsEnabledGeneration0
  * @param  RNGx RNG Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_Block_IsEnabledGeneration0(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_RBG0_EN) == (RNG_CR_RBG0_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Random Number Block 1 Generation
  * @rmtoll CR           RBG1_EN         LL_RNG_EnableBlockGeneration1
  * @param  RNGx RNG Instance
  * @retval None
  */
__STATIC_INLINE void LL_RNG_EnableBlockGeneration1(RNG_TypeDef *RNGx)
{
  SET_BIT(RNGx->CR, RNG_CR_RBG1_EN);
}

/**
  * @brief  Disable Random Number Block 1 Generation
  * @rmtoll CR           RBG1_EN         LL_RNG_DisableBlockGeneration1
  * @param  RNGx RNG Instance
  * @retval None
  */
__STATIC_INLINE void LL_RNG_DisableBlockGeneration1(RNG_TypeDef *RNGx)
{
  CLEAR_BIT(RNGx->CR, RNG_CR_RBG1_EN);
}

/**
  * @brief  Check if Random Number Block 1 Generator is enabled
  * @rmtoll CR           RBG1_EN         LL_RNG_IsEnabledBlockGeneration1
  * @param  RNGx RNG Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_IsEnabledBlockGeneration1(RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_RBG1_EN) == (RNG_CR_RBG1_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Set the data in the current linear feedback shift register
  * @rmtoll LFSR         RNG_LFSR        LL_RNG_SetLfsrRandData
  * @param  RNGx RNG Instance
  * @retval None
  */
__STATIC_INLINE void LL_RNG_SetLfsrRandData(RNG_TypeDef *RNGx)
{
  WRITE_REG(RNGx->LFSR, RNG_LFSR_RNG_LFSR);
}

/**
  * @brief  Get the data in the current linear feedback shift register
  * @rmtoll LFSR         RNG_LFSR      LL_RNG_GetLfsrRandData
  * @param  RNGx RNG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t LL_RNG_GetLfsrRandData(RNG_TypeDef *RNGx)
{
  return (uint32_t)(READ_REG(RNGx->LFSR));
}

/**
  * @}
  */

/** @defgroup RNG_LL_EF_FLAG_Management FLAG Management
  * @{
  */

/**
  * @brief  Indicate if the RNG Data ready Flag is set or not
  * @rmtoll SR           DATA_RDY          LL_RNG_IsActiveFlag_DRDY
  * @param  RNGx RNG Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_DRDY(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->SR, RNG_SR_DATA_RDY) == (RNG_SR_DATA_RDY)) ? 1UL : 0UL);
}

/**
  * @}
  */


/** @defgroup RNG_LL_EF_IT_Management IT Management
  * @{
  */

/**
  * @brief  Enable Random Number Generator Interrupt
  *         (applies for either Seed error, Clock Error or Data ready interrupts)
  * @rmtoll CR           IE            LL_RNG_EnableIT
  * @param  RNGx RNG Instance
  * @retval None
  */
__STATIC_INLINE void LL_RNG_EnableIT(RNG_TypeDef *RNGx)
{
  SET_BIT(RNGx->CR, RNG_CR_IE);
}

/**
  * @brief  Disable Random Number Generator Interrupt
  *         (applies for either Seed error, Clock Error or Data ready interrupts)
  * @rmtoll CR           IE            LL_RNG_DisableIT
  * @param  RNGx RNG Instance
  * @retval None
  */
__STATIC_INLINE void LL_RNG_DisableIT(RNG_TypeDef *RNGx)
{
  CLEAR_BIT(RNGx->CR, RNG_CR_IE);
}

/**
  * @brief  Check if Random Number Generator Interrupt is enabled
  *         (applies for either Seed error, Clock Error or Data ready interrupts)
  * @rmtoll CR           IE            LL_RNG_IsEnabledIT
  * @param  RNGx RNG Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_IsEnabledIT(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_IE) == (RNG_CR_IE)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup RNG_LL_EF_Data_Management Data Management
  * @{
  */

/**
  * @brief  Return 32-bit Random Number value
  * @rmtoll DR           RNDATA        LL_RNG_ReadRandData32
  * @param  RNGx RNG Instance
  * @retval Generated 32-bit random value
  */
__STATIC_INLINE uint32_t LL_RNG_ReadRandData32(const RNG_TypeDef *RNGx)
{
  return (uint32_t)(READ_REG(RNGx->DR));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RNG_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_RNG_DeInit(const RNG_TypeDef *RNGx);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

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

#endif /* __PY32E407_LL_RNG_H */

