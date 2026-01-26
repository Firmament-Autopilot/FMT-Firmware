/**
  ******************************************************************************
  * @file    py32e407_ll_ctc.c
  * @author  MCU Application Team
  * @brief   CTC LL module driver.
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
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "py32e407_ll_ctc.h"
#include "py32e407_ll_bus.h"
#ifdef  USE_FULL_ASSERT
  #include "py32_assert.h"
#else
  #define assert_param(expr) ((void)0U)
#endif

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (CTC)

/** @addtogroup CTC_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/** @defgroup CTC_LL_Private_Macros CTC Private Macros
  * @{
  */

#define IS_CTC_AUTO_TRIM(VALUE)          (((VALUE) == LL_CTC_AUTO_TRIM_DISABLE) || \
                                          ((VALUE) == LL_CTC_AUTO_TRIM_ENABLE))

#define IS_CTC_REF_CLOCK(VALUE)          (((VALUE) == LL_CTC_REF_CLOCK_SOURCE_GPIO) || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_SOURCE_LSE) || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_SOURCE_USBD_SOF))

#define IS_CTC_REF_CLOCK_DIV(VALUE)      (((VALUE) == LL_CTC_REF_CLOCK_DIV1)  || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_DIV2)  || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_DIV4)  || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_DIV8)  || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_DIV16) || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_DIV32) || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_DIV64) || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_DIV128))

#define IS_CTC_REF_CLOCK_POLARITY(VALUE) (((VALUE) == LL_CTC_REF_CLOCK_POLARITY_RISING) || \
                                          ((VALUE) == LL_CTC_REF_CLOCK_POLARITY_FALLING))

#define IS_CTC_RELOAD_VALUE(VALUE)       ((VALUE) <= 0xFFFF)

#define IS_CTC_LIMIT_VALUE(VALUE)        ((VALUE) <= 0xFF)

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup CTC_LL_Exported_Functions
  * @{
  */
  
/** @addtogroup CTC_LL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize the CTC registers to their default reset values.
  * @param  CTCx CTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: CTC registers are de-initialized
  *          - ERROR: CTC registers are not de-initialized
  */
ErrorStatus LL_CTC_DeInit(CTC_TypeDef *CTCx)
{
  ErrorStatus status = ERROR;

  /* Check the parameters */
  assert_param(IS_CTC_ALL_INSTANCE(CTCx));

  if (CTCx == CTC)
  {
    /* Force reset of CTC clock */
    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_CTC);

    /* Release reset of CTC clock */
    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_CTC);

    status = SUCCESS;
  }

  return status;
}

/**
  * @brief  Initialize the CTC registers according to the specified parameters in CTC_InitStruct.
  * @param  CTCx CTC Instance
  * @param  CTC_InitStruct pointer to a @ref LL_CTC_InitTypeDef structure
  * @retval An ErrorStatus enumeration value. (Return always SUCCESS)
  */
ErrorStatus LL_CTC_Init(CTC_TypeDef *CTCx, LL_CTC_InitTypeDef *CTC_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the CTC Instance CTCx*/
  assert_param(IS_CTC_ALL_INSTANCE(CTCx));

  /* Check the CTC parameters from CTC_InitStruct*/
  assert_param(IS_CTC_AUTO_TRIM(CTC_InitStruct->AutoTrim));
  assert_param(IS_CTC_REF_CLOCK(CTC_InitStruct->RefCLKSource));
  assert_param(IS_CTC_REF_CLOCK_DIV(CTC_InitStruct->RefCLKDivider));
  assert_param(IS_CTC_REF_CLOCK_POLARITY(CTC_InitStruct->RefCLKPolarity));
  assert_param(IS_CTC_RELOAD_VALUE(CTC_InitStruct->ReloadValue));
  assert_param(IS_CTC_LIMIT_VALUE(CTC_InitStruct->LimitValue));
  
  /* CTCx CTL0 and CTL1 Configuration */
  MODIFY_REG(CTCx->CTL0, CTC_CTL0_AUTOTRIM, CTC_InitStruct->AutoTrim);
  MODIFY_REG(CTCx->CTL1, (CTC_CTL1_REFSEL  | \
                          CTC_CTL1_REFPSC  | \
                          CTC_CTL1_REFPOL  | \
                          CTC_CTL1_RLVALUE | \
                          CTC_CTL1_CKLIM), \
                                   ((CTC_InitStruct->RefCLKSource)   | \
                                    (CTC_InitStruct->RefCLKDivider)  | \
                                    (CTC_InitStruct->RefCLKPolarity) | \
                                    ((CTC_InitStruct->ReloadValue) << CTC_CTL1_RLVALUE_Pos) | \
                                    ((CTC_InitStruct->LimitValue) << CTC_CTL1_CKLIM_Pos)));
  return status;
}

/**
  * @brief  Set each @ref LL_CTC_InitTypeDef field to default value.
  * @param  CTC_InitStruct pointer to a @ref LL_CTC_InitTypeDef structure
  * whose fields will be set to default values.
  * @retval None
  */
void LL_CTC_StructInit(LL_CTC_InitTypeDef *CTC_InitStruct)
{
  /* Set CTC_InitStruct fields to default values */
  CTC_InitStruct->AutoTrim       = LL_CTC_AUTO_TRIM_DISABLE;
  CTC_InitStruct->LimitValue     = 0x22U;
  CTC_InitStruct->ReloadValue    = 0xBB7FU;
  CTC_InitStruct->RefCLKSource   = LL_CTC_REF_CLOCK_SOURCE_USBD_SOF;
  CTC_InitStruct->RefCLKDivider  = LL_CTC_REF_CLOCK_DIV1;
  CTC_InitStruct->RefCLKPolarity = LL_CTC_REF_CLOCK_POLARITY_RISING;
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#endif /* defined (CTC) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT Puya Semiconductor *****END OF FILE****/
