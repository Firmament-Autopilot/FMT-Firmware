/**
  ******************************************************************************
  * @file    py32e407_ll_opa.c
  * @author  MCU Application Team
  * @brief   OPA LL module driver
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
#include "py32e407_ll_opa.h"

#ifdef  USE_FULL_ASSERT
#include "py32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (OPA1) || defined (OPA2) || defined (OPA3) 

/** @addtogroup OPA_LL OPA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup OPA_LL_Private_Macros
  * @{
  */

/* Check of parameters for configuration of OPA hierarchical scope:         */
/* OPA instance.                                                            */


#define IS_LL_OPA_FUNCTIONAL_MODE(__FUNCTIONAL_MODE__)                       \
  (   ((__FUNCTIONAL_MODE__) == LL_OPA_MODE_STANDALONE)                      \
   || ((__FUNCTIONAL_MODE__) == LL_OPA_MODE_PGA)                             \
   || ((__FUNCTIONAL_MODE__) == LL_OPA_MODE_PGA_IO0)                         \
   || ((__FUNCTIONAL_MODE__) == LL_OPA_MODE_PGA_IO0_BIAS)                    \
   || ((__FUNCTIONAL_MODE__) == LL_OPA_MODE_PGA_IO0_IO1_BIAS)                \
  )

#define IS_LL_OPA_INPUT_NONINVERTING(__INPUT_NONINVERTING__)                 \
  (   ((__INPUT_NONINVERTING__) == LL_OPA_INPUT_NONINVERT_IO0)               \
   || ((__INPUT_NONINVERTING__) == LL_OPA_INPUT_NONINVERT_IO1)               \
   || ((__INPUT_NONINVERTING__) == LL_OPA_INPUT_NONINVERT_IO2)               \
   || ((__INPUT_NONINVERTING__) == LL_OPA_INPUT_NONINVERT_IO3)               \
   || ((__INPUT_NONINVERTING__) == LL_OPA_INPUT_NONINVERT_DAC)               \
  )

#define IS_LL_OPA_INPUT_INVERTING(__INPUT_INVERTING__)                       \
  (   ((__INPUT_INVERTING__) == LL_OPA_INPUT_INVERT_IO0)                     \
   || ((__INPUT_INVERTING__) == LL_OPA_INPUT_INVERT_IO1)                     \
   || ((__INPUT_INVERTING__) == LL_OPA_INPUT_INVERT_CONNECT_NO)              \
  )

/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup OPA_LL_Exported_Functions
  * @{
  */

/** @addtogroup OPA_LL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize registers of the selected OPA instance
  *         to their default reset values.
  * @note   If comparator is locked, de-initialization by software is
  *         not possible.
  *         The only way to unlock the comparator is a device hardware reset.
  * @param  OPAx OPA instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: OPA registers are de-initialized
  *          - ERROR: OPA registers are not de-initialized
  */
ErrorStatus LL_OPA_DeInit(OPA_TypeDef *OPAx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_OPA_ALL_INSTANCE(OPAx));

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       OPA instance must not be locked.                                 */
  if (LL_OPA_IsLocked(OPAx) == 0UL)
  {
    LL_OPA_WriteReg(OPAx, CSR, 0x00000000UL);
  }
  else
  {
    /* OPA instance is locked: de-initialization by software is              */
    /* not possible.                                                           */
    /* The only way to unlock the OPA is a device hardware reset.            */
    status = ERROR;
  }

  /* Timer controlled mux mode register reset                                  */
  if (LL_OPA_IsTimerMuxLocked(OPAx) == 0UL)
  {
    LL_OPA_WriteReg(OPAx, TCMR, 0x00000000UL);
  }
  else if (LL_OPA_ReadReg(OPAx, TCMR) != 0x80000000UL)
  {
    /* OPA instance timer controlled mux is locked configured, deinit error  */
    /* The only way to unlock the OPA is a device hardware reset.            */
    status = ERROR;
  }
  else
  {
    /* OPA instance timer controlled mux is locked unconfigured, deinit OK */
  }

  return status;
}

/**
  * @brief  Initialize some features of OPA instance.
  * @note   This function reset bit of calibration mode to ensure
  *         to be in functional mode, in order to have OPA parameters
  *         (inputs selection, ...) set with the corresponding OPA mode
  *         to be effective.
  * @param  OPAx OPA instance
  * @param  OPA_InitStruct Pointer to a @ref LL_OPA_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: OPA registers are initialized
  *          - ERROR: OPA registers are not initialized
  */
ErrorStatus LL_OPA_Init(OPA_TypeDef *OPAx, LL_OPA_InitTypeDef *OPA_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_OPA_ALL_INSTANCE(OPAx));
  assert_param(IS_LL_OPA_FUNCTIONAL_MODE(OPA_InitStruct->FunctionalMode));
  assert_param(IS_LL_OPA_INPUT_NONINVERTING(OPA_InitStruct->InputNonInverting));

  /* Note: OPA inverting input can be used with OPA in mode standalone    */
  /*       or PGA with external capacitors for filtering circuit.             */
  /*       Otherwise (OPA in mode follower), OPA inverting input is       */
  /*       not used (not connected to GPIO pin).                              */
  assert_param(IS_LL_OPA_INPUT_INVERTING(OPA_InitStruct->InputInverting));
 

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       OPA instance must not be locked.                                 */
  if (LL_OPA_IsLocked(OPAx) == 0U)
  {
    /* Configuration of OPA instance :                                      */
    /*  - Functional mode                                                     */
    /*  - Input non-inverting                                                 */
    /*  - Input inverting                                                     */
    /* Note: Bit OPA_CSR_CALON reset to ensure to be in functional mode.    */

      MODIFY_REG(OPAx->CSR,
                   OPA_CSR_VM_SEL
                 | OPA_CSR_VP_SEL
                 | OPA_CSR_PGA_GAIN_4 | OPA_CSR_PGA_GAIN_3
                 ,
                   OPA_InitStruct->FunctionalMode
                 | OPA_InitStruct->InputNonInverting
                 | OPA_InitStruct->InputInverting
                );

  }
  else
  {
    /* Initialization error: OPA instance is locked.                        */
    status = ERROR;
  }

  return status;
}

/**
  * @brief Set each @ref LL_OPA_InitTypeDef field to default value.
  * @param OPA_InitStruct pointer to a @ref LL_OPA_InitTypeDef structure
  *                         whose fields will be set to default values.
  * @retval None
  */
void LL_OPA_StructInit(LL_OPA_InitTypeDef *OPA_InitStruct)
{
  /* Set OPA_InitStruct fields to default values */
  OPA_InitStruct->FunctionalMode    = LL_OPA_MODE_STANDALONE;
  OPA_InitStruct->InputNonInverting = LL_OPA_INPUT_NONINVERT_IO0;
  OPA_InitStruct->InputInverting    = LL_OPA_INPUT_INVERT_CONNECT_NO;
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

#endif /* OPA1 || OPA2 || OPA3 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

