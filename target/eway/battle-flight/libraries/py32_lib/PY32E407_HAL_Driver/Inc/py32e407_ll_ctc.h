/**
  ******************************************************************************
  * @file    py32e407_ll_ctc.h
  * @author  MCU Application Team
  * @brief   Header file of CTC LL module.
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
#ifndef __PY32E407_LL_CTC_H
#define __PY32E407_LL_CTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"
/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (CTC)

/** @defgroup CTC_LL CTC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup CTC_LL_ES_INIT CTC Exported Init structure
  * @{
  */

/**
  * @brief  CTC Init structures definition
  */
typedef struct
{
  uint32_t           AutoTrim;        /*!< CTC Auto Trim Mode 
                                           This parameter can be a value of @ref CTC_LL_EC_AUTO_TRIM */

  uint32_t           LimitValue;      /*!< Base time limit for clock calibration 
                                           This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF */
  
  uint32_t           ReloadValue;     /*!< CTC counter overload value 
                                           This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
  
  uint32_t           RefCLKSource;    /*!< CTC Input Reference Clock 
                                           This parameter can be a value of @ref CTC_LL_EC_Ref_Clock_Source */

  uint32_t           RefCLKDivider;   /*!< The Reference Clock divider 
                                           This parameter can be a value of @ref CTC_LL_EC_Ref_Clock_Divider */

  uint32_t           RefCLKPolarity;  /*!< The Reference Clock steady state 
                                           This parameter can be a value of @ref CTC_LL_EC_Ref_Clock_Polarity */
} LL_CTC_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup CTC_LL_Exported_Constants CTC Exported Constants
  * @{
  */

/** @defgroup CTC_LL_EC_AUTO_TRIM CTC Trim Mode Defines
  * @{
  */
#define LL_CTC_AUTO_TRIM_DISABLE            0x00000000U                 /*!< hardware automatically trim mode disable*/
#define LL_CTC_AUTO_TRIM_ENABLE             CTC_CTL0_AUTOTRIM           /*!< hardware automatically trim mode enable*/
/**
  * @}
  */

/** @defgroup CTC_LL_EC_Ref_Clock_Source CTC Input Reference Clock 
  * @{
  */
#define LL_CTC_REF_CLOCK_SOURCE_GPIO               0x00000000U                 /*!< GPIO is selected */
#define LL_CTC_REF_CLOCK_SOURCE_LSE                CTC_CTL1_REFSEL_0           /*!< LSE is selected */
#define LL_CTC_REF_CLOCK_SOURCE_USBD_SOF           CTC_CTL1_REFSEL_1           /*!< USBD_SOF is selected */
/**
  * @}
  */

/** @defgroup CTC_LL_EC_Ref_Clock_Divider CTC Input Reference Clock divider
  * @{
  */
#define LL_CTC_REF_CLOCK_DIV1               0x00000000U                                                  /*!< reference clock not divided */
#define LL_CTC_REF_CLOCK_DIV2               (CTC_CTL1_REFPSC_0)                                          /*!< reference clock divided by 2 */
#define LL_CTC_REF_CLOCK_DIV4               (CTC_CTL1_REFPSC_1)                                          /*!< reference clock divided by 4 */
#define LL_CTC_REF_CLOCK_DIV8               (CTC_CTL1_REFPSC_0 | CTC_CTL1_REFPSC_1)                      /*!< reference clock divided by 8 */
#define LL_CTC_REF_CLOCK_DIV16              (CTC_CTL1_REFPSC_2)                                          /*!< reference clock divided by 16 */
#define LL_CTC_REF_CLOCK_DIV32              (CTC_CTL1_REFPSC_0 | CTC_CTL1_REFPSC_2)                      /*!< reference clock divided by 32 */
#define LL_CTC_REF_CLOCK_DIV64              (CTC_CTL1_REFPSC_1 | CTC_CTL1_REFPSC_2)                      /*!< reference clock divided by 64 */
#define LL_CTC_REF_CLOCK_DIV128             (CTC_CTL1_REFPSC_0 |CTC_CTL1_REFPSC_1 | CTC_CTL1_REFPSC_2)   /*!< reference clock divided by 128 */
/**
  * @}
  */

/** @defgroup CTC_LL_EC_Ref_Clock_Polarity CTC Reference Clock Polarity
  * @{
  */
#define LL_CTC_REF_CLOCK_POLARITY_RISING            0x00000000U                  /*!< reference clock source polarity is rising edge */
#define LL_CTC_REF_CLOCK_POLARITY_FALLING           CTC_CTL1_REFPOL              /*!< reference clock source polarity is falling edge */
/**
  * @}
  */

/** @defgroup CTC_LL_EC_Counter_Direction CTC counter direction
  * @{
  */
#define LL_CTC_CNT_DIRECTION_UP             0x00000000U                /*!< CTC trim count up */
#define LL_CTC_CNT_DIRECTION_DOWN           CTC_SR_REFDIR              /*!< CTC trim count down */
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup CTC_LL_Exported_Functions CTC Exported Functions
  * @{
  */

/**
  * @brief  Enable clock calibration completion interrupt.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_EnableIT_CKOK(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->CTL0, CTC_CTL0_CKOKIE);
}

/**
  * @brief  Disable clock calibration completion interrupt.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_DisableIT_CKOK(CTC_TypeDef *CTCx)
{
  CLEAR_BIT(CTCx->CTL0, CTC_CTL0_CKOKIE);
}

/**
  * @brief  Check if clock calibration completion interrupt is enabled.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsEnabledIT_CKOK(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->CTL0, CTC_CTL0_CKOKIE) == (CTC_CTL0_CKOKIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable clock calibration warning interrupt.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_EnableIT_CKWARN(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->CTL0, CTC_CTL0_CKWARNIE);
}

/**
  * @brief  Disable clock calibration warning interrupt.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_DisableIT_CKWARN(CTC_TypeDef *CTCx)
{
  CLEAR_BIT(CTCx->CTL0, CTC_CTL0_CKWARNIE);
}

/**
  * @brief  Check if clock calibration warning interrupt is enabled.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsEnabledIT_CKWARN(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->CTL0, CTC_CTL0_CKWARNIE) == (CTC_CTL0_CKWARNIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable error interrupt.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_EnableIT_ERR(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->CTL0, CTC_CTL0_ERRIE);
}

/**
  * @brief  Disable error interrupt.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_DisableIT_ERR(CTC_TypeDef *CTCx)
{
  CLEAR_BIT(CTCx->CTL0, CTC_CTL0_ERRIE);
}

/**
  * @brief  Check if error interrupt is enabled.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsEnabledIT_ERR(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->CTL0, CTC_CTL0_ERRIE) == (CTC_CTL0_ERRIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable expected reference signal interrupt.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_EnableIT_EREF(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->CTL0, CTC_CTL0_EREFIE);
}

/**
  * @brief  Disable expected reference signal interrupt.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_DisableIT_EREF(CTC_TypeDef *CTCx)
{
  CLEAR_BIT(CTCx->CTL0, CTC_CTL0_EREFIE);
}

/**
  * @brief  Check if expected reference signal interrupt is enabled.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsEnabledIT_EREF(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->CTL0, CTC_CTL0_EREFIE) == (CTC_CTL0_EREFIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable CTC counter.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_EnableCount(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->CTL0, CTC_CTL0_CNTEN);
}

/**
  * @brief  Disable CTC counter.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_DisableCount(CTC_TypeDef *CTCx)
{
  CLEAR_BIT(CTCx->CTL0, CTC_CTL0_CNTEN);
}

/**
  * @brief  Check if CTC counter is enabled.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsEnabledCount(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->CTL0, CTC_CTL0_CNTEN) == (CTC_CTL0_CNTEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set CTC hardware automatically trim mode.
  * @param  CTCx CTC Instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_CTC_AUTO_TRIM_DISABLE
  *         @arg @ref LL_CTC_AUTO_TRIM_ENABLE
  * @retval None
  */
__STATIC_INLINE void LL_CTC_SetAutoTrimMode(CTC_TypeDef *CTCx, uint32_t Mode)
{
  MODIFY_REG(CTCx->CTL0, CTC_CTL0_AUTOTRIM, Mode);
}

/**
  * @brief  Get CTC hardware automatically trim mode.
  * @param  CTCx CTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_CTC_AUTO_TRIM_DISABLE
  *         @arg @ref LL_CTC_AUTO_TRIM_ENABLE
  */
__STATIC_INLINE uint32_t LL_CTC_GetAutoTrimMode(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->CTL0, CTC_CTL0_AUTOTRIM));
}

/**
  * @brief  Software generates synchronous reference signal pulses.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_GenerateSoftRefClk(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->CTL0, CTC_CTL0_SWREFPUL);
}

/**
  * @brief  Set CTC trim value.
  * @param  CTCx CTC Instance
  * @param  Value This parameter must be a number between Min_Data = 0x0 and Max_Data = 0x7F
  * @retval None
  */
__STATIC_INLINE void LL_CTC_SetTrimValue(CTC_TypeDef *CTCx, uint32_t Value)
{
  MODIFY_REG(CTCx->CTL0, CTC_CTL0_TRIMVALUE, (Value << CTC_CTL0_TRIMVALUE_Pos));
}

/**
  * @brief  Get CTC trim value.
  * @param  CTCx CTC Instance
  * @retval Returned value is a number between Min_Data = 0x0 and Max_Data = 0x7F
  */
__STATIC_INLINE uint32_t LL_CTC_GetTrimValue(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->CTL0, CTC_CTL0_TRIMVALUE) >> CTC_CTL0_TRIMVALUE_Pos);
}

/**
  * @brief  Set CTC counter reload value.
  * @param  CTCx CTC Instance
  * @param  Value This parameter must be a number between Min_Data = 0 and Max_Data = 0xFFFF
  * @retval None
  */
__STATIC_INLINE void LL_CTC_SetReloadValue(CTC_TypeDef *CTCx, uint32_t Value)
{
  MODIFY_REG(CTCx->CTL1, CTC_CTL1_RLVALUE, (Value << CTC_CTL1_RLVALUE_Pos));
}

/**
  * @brief  Get CTC counter reload value.
  * @param  CTCx CTC Instance
  * @retval Returned value is a number between Min_Data = 0 and Max_Data = 0xFFFF
  */
__STATIC_INLINE uint32_t LL_CTC_GetReloadValue(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->CTL1, CTC_CTL1_RLVALUE) >> CTC_CTL1_RLVALUE_Pos);
}

/**
  * @brief  Set clock calibration time base limit.
  * @param  CTCx CTC Instance
  * @param  Value This parameter must be a number between Min_Data = 0 and Max_Data = 0xFF
  * @retval None
  */
__STATIC_INLINE void LL_CTC_SetClkCalLimit(CTC_TypeDef *CTCx, uint32_t Value)
{
  MODIFY_REG(CTCx->CTL1, CTC_CTL1_CKLIM, (Value << CTC_CTL1_CKLIM_Pos));
}

/**
  * @brief  Get clock calibration time base limit.
  * @param  CTCx CTC Instance
  * @retval Returned value is a number between Min_Data = 0 and Max_Data = 0xFF
  */
__STATIC_INLINE uint32_t LL_CTC_GetClkCalLimit(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->CTL1, CTC_CTL1_CKLIM) >> CTC_CTL1_CKLIM_Pos);
}

/**
  * @brief  Set CTC Input Reference Clock divider.
  * @param  CTCx CTC Instance
  * @param  Divider This parameter can be one of the following values:
  *         @arg @ref LL_CTC_REF_CLOCK_DIV1  
  *         @arg @ref LL_CTC_REF_CLOCK_DIV2  
  *         @arg @ref LL_CTC_REF_CLOCK_DIV4  
  *         @arg @ref LL_CTC_REF_CLOCK_DIV8  
  *         @arg @ref LL_CTC_REF_CLOCK_DIV16 
  *         @arg @ref LL_CTC_REF_CLOCK_DIV32 
  *         @arg @ref LL_CTC_REF_CLOCK_DIV64 
  *         @arg @ref LL_CTC_REF_CLOCK_DIV128
  * @retval None
  */
__STATIC_INLINE void LL_CTC_SetRefClkDiv(CTC_TypeDef *CTCx, uint32_t Divider)
{
  MODIFY_REG(CTCx->CTL1, CTC_CTL1_REFPSC, Divider);
}

/**
  * @brief  Get CTC Input Reference Clock divider.
  * @param  CTCx CTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_CTC_REF_CLOCK_DIV1  
  *         @arg @ref LL_CTC_REF_CLOCK_DIV2  
  *         @arg @ref LL_CTC_REF_CLOCK_DIV4  
  *         @arg @ref LL_CTC_REF_CLOCK_DIV8  
  *         @arg @ref LL_CTC_REF_CLOCK_DIV16 
  *         @arg @ref LL_CTC_REF_CLOCK_DIV32 
  *         @arg @ref LL_CTC_REF_CLOCK_DIV64 
  *         @arg @ref LL_CTC_REF_CLOCK_DIV128
  */
__STATIC_INLINE uint32_t LL_CTC_GetRefClkDiv(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->CTL1, CTC_CTL1_REFPSC));
}

/**
  * @brief  Set CTC input reference clock.
  * @param  CTCx CTC Instance
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_CTC_REF_CLOCK_SOURCE_GPIO
  *         @arg @ref LL_CTC_REF_CLOCK_SOURCE_LSE
  *         @arg @ref LL_CTC_REF_CLOCK_SOURCE_USBD_SOF
  * @retval None
  */
__STATIC_INLINE void LL_CTC_SetRefClkSrc(CTC_TypeDef *CTCx, uint32_t Source)
{
  MODIFY_REG(CTCx->CTL1, CTC_CTL1_REFSEL, Source);
}

/**
  * @brief  Get CTC input reference clock.
  * @param  CTCx CTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_CTC_REF_CLOCK_SOURCE_GPIO
  *         @arg @ref LL_CTC_REF_CLOCK_SOURCE_LSE
  *         @arg @ref LL_CTC_REF_CLOCK_SOURCE_USBD_SOF
  */
__STATIC_INLINE uint32_t LL_CTC_GetRefClkSrc(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->CTL1, CTC_CTL1_REFSEL));
}

/**
  * @brief  Set CTC reference clock polarity.
  * @param  CTCx CTC Instance
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref LL_CTC_REF_CLOCK_POLARITY_RISING 
  *         @arg @ref LL_CTC_REF_CLOCK_POLARITY_FALLING
  * @retval None
  */
__STATIC_INLINE void LL_CTC_SetRefClkPol(CTC_TypeDef *CTCx, uint32_t Polarity)
{
  MODIFY_REG(CTCx->CTL1, CTC_CTL1_REFPOL, Polarity);
}

/**
  * @brief  Get CTC reference clock polarity.
  * @param  CTCx CTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_CTC_REF_CLOCK_POLARITY_RISING 
  *         @arg @ref LL_CTC_REF_CLOCK_POLARITY_FALLING
  */
__STATIC_INLINE uint32_t LL_CTC_GetRefClkPol(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->CTL1, CTC_CTL1_REFPOL));
}

/**
  * @brief  Check if clock calibration successful interrupt flag bit is set.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsActiveFlag_CKOK(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->SR, CTC_SR_CKOKIF) == (CTC_SR_CKOKIF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if clock calibration warning interrupt flag bit is set.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsActiveFlag_CKWARN(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->SR, CTC_SR_CKWARNIF) == (CTC_SR_CKWARNIF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if error interrupt flag bit is set.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsActiveFlag_ERR(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->SR, CTC_SR_ERRIF) == (CTC_SR_ERRIF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if expected reference interrupt flag bit is set.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsActiveFlag_EREF(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->SR, CTC_SR_EREFIF) == (CTC_SR_EREFIF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if clock calibration error flag bit is set.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsActiveFlag_CKERR(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->SR, CTC_SR_CKERR) == (CTC_SR_CKERR)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Loss of synchronous reference pulse signal flag is set.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsActiveFlag_REFMISS(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->SR, CTC_SR_REFMISS) == (CTC_SR_REFMISS)) ? 1UL : 0UL);
}

/**
  * @brief  Check if calibration value error flag is set.
  * @param  CTCx CTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CTC_IsActiveFlag_TRIMERR(CTC_TypeDef *CTCx)
{
  return ((READ_BIT(CTCx->SR, CTC_SR_TRIMERR) == (CTC_SR_TRIMERR)) ? 1UL : 0UL);
}

/**
  * @brief  Get CTC calibration clock counting direction.
  * @param  CTCx CTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_CTC_CNT_DIRECTION_UP
  *         @arg @ref LL_CTC_CNT_DIRECTION_DOWN
  */
__STATIC_INLINE uint32_t LL_CTC_GetCounterDir(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->SR, CTC_SR_REFDIR));
}

/**
  * @brief  Get CTC counter capture value.
  * @param  CTCx CTC Instance
  * @retval Returned value is a number between Min_Data = 0 and Max_Data = 0xFFFF
  */
__STATIC_INLINE uint32_t LL_CTC_GetCounterCapValue(CTC_TypeDef *CTCx)
{
  return (uint32_t)(READ_BIT(CTCx->SR, CTC_SR_REFCAP) >> CTC_SR_REFCAP_Pos);
}

/**
  * @brief  Clear clock calibration successful interrupt flag.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_ClearFlag_CKOK(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->INTC, CTC_INTC_CKOKIC);
}

/**
  * @brief  Clear clock calibration warning interrupt flag.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_ClearFlag_CKWARN(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->INTC, CTC_INTC_CKWARNIC);
}

/**
  * @brief  Clear error interrupt flag.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_ClearFlag_ERR(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->INTC, CTC_INTC_ERRIC);
}

/**
  * @brief  Clear expected reference interrupt flag.
  * @param  CTCx CTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_CTC_ClearFlag_EREF(CTC_TypeDef *CTCx)
{
  SET_BIT(CTCx->INTC, CTC_INTC_EREFIC);
}

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup CTC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_CTC_DeInit(CTC_TypeDef *CTCx);
ErrorStatus LL_CTC_Init(CTC_TypeDef *CTCx, LL_CTC_InitTypeDef *CTC_InitStruct);
void        LL_CTC_StructInit(LL_CTC_InitTypeDef *CTC_InitStruct);

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
#endif /* defined (CTC)*/
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_LL_CTC_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
