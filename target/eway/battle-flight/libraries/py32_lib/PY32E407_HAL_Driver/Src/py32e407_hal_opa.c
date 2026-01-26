/**
  ******************************************************************************
  * @file    py32e407_hal_opa.c
  * @author  MCU Application Team
  * @brief   OPA HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the operational amplifiers peripheral:
  *           + Initialization/de-initialization functions
  *           + I/O operation functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *
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

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx_hal.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

#ifdef HAL_OPA_MODULE_ENABLED

/** @defgroup OPA OPA
  * @brief OPA HAL module driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup OPA_Private_Define OPA Private Define
  * @{
  */
/* CSR register reset value */
#define OPA_CSR_RESET_VALUE             (0x00000000UL)

/* CSR init register Mask */
#define OPA_CSR_UPDATE_PARAMETERS_INIT_MASK (OPA_CSR_OPAHSM | OPA_CSR_OPAINTOEN \
                                               | OPA_CSR_PGA_GAIN | OPA_CSR_VP_SEL \
                                               | OPA_CSR_VM_SEL)
/* TCMR init register Mask */
#define OPA_TCMR_UPDATE_PARAMETERS_INIT_MASK (OPA_TCMR_T8CM_EN \
                                                | OPA_TCMR_T1CM_EN | OPA_TCMR_VPS_SEL \
                                                | OPA_TCMR_VMS_SEL)
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions ---------------------------------------------------------*/

/** @defgroup OPA_Exported_Functions OPA Exported Functions
  * @{
  */

/** @defgroup OPA_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization  functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the OPA according to the specified
  *         parameters in the OPA_InitTypeDef and initialize the associated handle.
  * @note   If the selected opa is locked, initialization can't be performed.
  *         To unlock the configuration, perform a system reset.
  * @param  hopa OPA handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_OPA_Init(OPA_HandleTypeDef *hopa)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the OPA handle allocation and lock status */
  /* Init not allowed if calibration is ongoing */
  if (hopa == NULL)
  {
    return HAL_ERROR;
  }
  else if (hopa->State == HAL_OPA_STATE_BUSYLOCKED)
  {
    return HAL_ERROR;
  }
  else if (hopa->State == HAL_OPA_STATE_CALIBBUSY)
  {
    return HAL_ERROR;
  }
  else
  {

    /* Check the parameter */
    assert_param(IS_OPA_ALL_INSTANCE(hopa->Instance));

    /* Set OPA parameters */
    assert_param(IS_OPA_POWERMODE(hopa->Init.PowerMode));
    assert_param(IS_OPA_FUNCTIONAL_NORMALMODE(hopa->Init.Mode));
    assert_param(IS_OPA_NONINVERTING_INPUT(hopa->Init.NonInvertingInput));

#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
    if (hopa->State == HAL_OPA_STATE_RESET)
    {
      if (hopa->MspInitCallback == NULL)
      {
        hopa->MspInitCallback               = HAL_OPA_MspInit;
      }
    }
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */

    if ((hopa->Init.Mode) == OPA_STANDALONE_MODE)
    {
      assert_param(IS_OPA_INVERTING_INPUT(hopa->Init.InvertingInput));
    }
    assert_param(IS_FUNCTIONAL_STATE(hopa->Init.InternalOutput));

    assert_param(IS_OPA_TIMERCONTROLLED_MUXMODE(hopa->Init.TimerControlledMuxmode));

    if ((hopa->Init.TimerControlledMuxmode) != OPA_TIMERCONTROLLEDMUXMODE_DISABLE)
    {
      assert_param(IS_OPA_SEC_NONINVERTING_INPUT(hopa->Init.NonInvertingInputSecondary));
      assert_param(IS_OPA_SEC_INVERTING_INPUT(hopa->Init.InvertingInputSecondary));
    }

    if ((hopa->Init.Mode) == OPA_PGA_MODE)
    {
      assert_param(IS_OPA_PGACONNECT(hopa->Init.PgaConnect));
      assert_param(IS_OPA_PGA_GAIN(hopa->Init.PgaGain));
    }

    /* Init SYSCFG and the low level hardware to access opa */
    __HAL_RCC_SYSCFG_CLK_ENABLE();

    if (hopa->State == HAL_OPA_STATE_RESET)
    {
      /* Allocate lock resource and initialize it */
      hopa->Lock = HAL_UNLOCKED;
    }

#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
    hopa->MspInitCallback(hopa);
#else
    /* Call MSP init function */
    HAL_OPA_MspInit(hopa);
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */

    /* Set OPA parameters */
    /*     Set  bits according to hopa->hopa->Init.Mode value                                 */
    /*     Set  bits according to hopa->hopa->Init.InvertingInput value                       */
    /*     Set  bits according to hopa->hopa->Init.NonInvertingInput value                    */
    /*     Set  bits according to hopa->hopa->Init.InternalOutput value                       */
    /*     Set  bits according to hopa->hopa->Init.TimerControlledMuxmode value               */
    /*     Set  bits according to hopa->hopa->Init.InvertingInputSecondary  value             */
    /*     Set  bits according to hopa->hopa->Init.NonInvertingInputSecondary value           */
    /*     Set  bits according to hopa->hopa->Init.PgaConnect value                           */
    /*     Set  bits according to hopa->hopa->Init.PgaGain value                              */
    /* check if OPA_PGA_MODE & in Follower mode */
    /*   - InvertingInput                         */
    /* is Not Applicable                          */

 /*   if ((hopa->Init.Mode == OPA_PGA_MODE) || (hopa->Init.Mode == OPA_FOLLOWER_MODE)) */

    if (hopa->Init.Mode == OPA_PGA_MODE)
    {
      MODIFY_REG(hopa->Instance->CSR,
                 OPA_CSR_UPDATE_PARAMETERS_INIT_MASK,
                 hopa->Init.PowerMode |
                 hopa->Init.Mode |
                 hopa->Init.NonInvertingInput |
                 ((hopa->Init.InternalOutput == ENABLE) ? OPA_CSR_OPAINTOEN : 0UL) |
                 hopa->Init.PgaConnect |
                 hopa->Init.PgaGain);
    }
    else /* OPA_STANDALONE_MODE or OPA_CURRENTSAMPLE_MODE */
    {
      MODIFY_REG(hopa->Instance->CSR,
                 OPA_CSR_UPDATE_PARAMETERS_INIT_MASK,
                 hopa->Init.PowerMode |
                 hopa->Init.Mode |
                 hopa->Init.InvertingInput    |
                 hopa->Init.NonInvertingInput |
                 ((hopa->Init.InternalOutput == ENABLE) ? OPA_CSR_OPAINTOEN : 0UL) |
                 hopa->Init.PgaConnect |
                 hopa->Init.PgaGain );
    }
    if(hopa->Init.Mode == OPA_CURRENTSAMPLE_MODE)
    {
      if(hopa->Init.VoltageBuildIn == OPA_VOLTAGEBUILDIN_DISABLE)
      {
        CLEAR_BIT(hopa->Instance->CSR,OPA_CSR_OPA_VBSEL);
      }
      else
      {
        SET_BIT(hopa->Instance->CSR,OPA_CSR_OPA_VBSEL);
        MODIFY_REG(OPA1->CSR,OPA_CSR_OPA_VBIAS, hopa->Init.VoltageBuildIn);
      }
    }

    if ((READ_BIT(hopa->Instance->TCMR, OPA_TCMR_LOCK)) == 0UL)
    {
      MODIFY_REG(hopa->Instance->TCMR,
                 OPA_TCMR_UPDATE_PARAMETERS_INIT_MASK,
                 hopa->Init.TimerControlledMuxmode |
                 hopa->Init.InvertingInputSecondary  |
                 hopa->Init.NonInvertingInputSecondary);
    }

    /* Update the OPA state*/
    if (hopa->State == HAL_OPA_STATE_RESET)
    {
      /* From RESET state to READY State */
      hopa->State = HAL_OPA_STATE_READY;
    }
    /* else: remain in READY or BUSY state (no update) */

    return status;
  }
}


/**
  * @brief  DeInitializes the OPA peripheral
  * @note   Deinitialization can't be performed if the OPA configuration is locked.
  *         To unlock the configuration, perform a system reset.
  * @param  hopa OPA handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_OPA_DeInit(OPA_HandleTypeDef *hopa)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the OPA handle allocation */
  /* DeInit not allowed if calibration is ongoing */
  if (hopa == NULL)
  {
    status = HAL_ERROR;
  }
  else if (hopa->State == HAL_OPA_STATE_CALIBBUSY)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameter */
    assert_param(IS_OPA_ALL_INSTANCE(hopa->Instance));

    /* Set OPA_CSR register to reset value */
    WRITE_REG(hopa->Instance->CSR, OPA_CSR_RESET_VALUE);

    /* DeInit the low level hardware: GPIO, CLOCK and NVIC */
    /* When OPA is locked, unlocking can be achieved thanks to */
    /* __HAL_RCC_SYSCFG_CLK_DISABLE() call within HAL_OPA_MspDeInit */
    /* Note that __HAL_RCC_SYSCFG_CLK_DISABLE() also disables comparator */

#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
    if (hopa->MspDeInitCallback == NULL)
    {
      hopa->MspDeInitCallback = HAL_OPA_MspDeInit;
    }
    /* DeInit the low level hardware */
    hopa->MspDeInitCallback(hopa);
#else
    HAL_OPA_MspDeInit(hopa);
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */

    hopa->State = HAL_OPA_STATE_RESET;

    /* Process unlocked */
    __HAL_UNLOCK(hopa);
  }

  return status;
}

/**
  * @brief  Initialize the OPA MSP.
  * @param  hopa OPA handle
  * @retval None
  */
__weak void HAL_OPA_MspInit(OPA_HandleTypeDef *hopa)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hopa);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_OPA_MspInit could be implemented in the user file
   */

  /* Example */
}

/**
  * @brief  DeInitialize OPA MSP.
  * @param  hopa OPA handle
  * @retval None
  */
__weak void HAL_OPA_MspDeInit(OPA_HandleTypeDef *hopa)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hopa);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_OPA_MspDeInit could be implemented in the user file
   */

}

/**
  * @}
  */


/** @defgroup OPA_Exported_Functions_Group2 Input and Output operation functions
  *  @brief   Data transfers functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to manage the OPA data
    transfers.

@endverbatim
  * @{
  */

/**
  * @brief  Start the opa
  * @param  hopa OPA handle
  * @retval HAL status
  */

HAL_StatusTypeDef HAL_OPA_Start(OPA_HandleTypeDef *hopa)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the OPA handle allocation */
  /* Check if OPA locked */
  if (hopa == NULL)
  {
    status = HAL_ERROR;
  }
  else if (hopa->State == HAL_OPA_STATE_BUSYLOCKED)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameter */
    assert_param(IS_OPA_ALL_INSTANCE(hopa->Instance));

    if (hopa->State == HAL_OPA_STATE_READY)
    {
      /* Enable the selected opa */
      SET_BIT(hopa->Instance->CSR, OPA_CSR_OPAEN);

      /* Update the OPA state*/
      /* From HAL_OPA_STATE_READY to HAL_OPA_STATE_BUSY */
      hopa->State = HAL_OPA_STATE_BUSY;
    }
    else
    {
      status = HAL_ERROR;
    }


  }
  return status;
}

/**
  * @brief  Stop the opa
  * @param  hopa OPA handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_OPA_Stop(OPA_HandleTypeDef *hopa)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the OPA handle allocation */
  /* Check if OPA locked */
  /* Check if OPA calibration ongoing */
  if (hopa == NULL)
  {
    status = HAL_ERROR;
  }
  else if (hopa->State == HAL_OPA_STATE_BUSYLOCKED)
  {
    status = HAL_ERROR;
  }
  else if (hopa->State == HAL_OPA_STATE_CALIBBUSY)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameter */
    assert_param(IS_OPA_ALL_INSTANCE(hopa->Instance));

    if (hopa->State == HAL_OPA_STATE_BUSY)
    {
      /* Disable the selected opa */
      CLEAR_BIT(hopa->Instance->CSR, OPA_CSR_OPAEN);

      /* Update the OPA state*/
      /* From  HAL_OPA_STATE_BUSY to HAL_OPA_STATE_READY*/
      hopa->State = HAL_OPA_STATE_READY;
    }
    else
    {
      status = HAL_ERROR;
    }
  }
  return status;
}



/**
  * @}
  */

/** @defgroup OPA_Exported_Functions_Group3 Peripheral Control functions
  *  @brief   Peripheral Control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the OPA data
    transfers.



@endverbatim
  * @{
  */

/**
  * @brief  Lock the selected opa configuration.
  * @param  hopa OPA handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_OPA_Lock(OPA_HandleTypeDef *hopa)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the OPA handle allocation */
  /* Check if OPA locked */
  /* OPA can be locked when enabled and running in normal mode */
  /*   It is meaningless otherwise */
  if (hopa == NULL)
  {
    status = HAL_ERROR;
  }
  else if (hopa->State != HAL_OPA_STATE_BUSY)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameter */
    assert_param(IS_OPA_ALL_INSTANCE(hopa->Instance));

    /* Lock OPA */
    SET_BIT(hopa->Instance->CSR, OPA_CSR_LOCK);

    /* OPA state changed to locked */
    hopa->State = HAL_OPA_STATE_BUSYLOCKED;
  }
  return status;
}

/**
  * @}
  */

/**
  * @brief  Lock the selected opa timer controlled mux configuration.
  * @param  hopa OPA handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_OPA_LockTimerMux(OPA_HandleTypeDef *hopa)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the OPA handle allocation                     */
  /* Check if OPA timer controlled mux is locked         */
  /* OPA timer controlled mux can be locked when enabled */
  /*   It is meaningless otherwise */
  if (hopa == NULL)
  {
    status = HAL_ERROR;
  }
  else if (hopa->State == HAL_OPA_STATE_RESET)
  {
    status = HAL_ERROR;
  }
  else if (READ_BIT(hopa->Instance->TCMR, OPA_TCMR_LOCK) == OPA_TCMR_LOCK)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameter */
    assert_param(IS_OPA_ALL_INSTANCE(hopa->Instance));

    /* Lock OPA */
    SET_BIT(hopa->Instance->TCMR, OPA_TCMR_LOCK);
  }
  return status;
}

/**
  * @}
  */

/** @defgroup OPA_Exported_Functions_Group4 Peripheral State functions
  *  @brief   Peripheral State functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State functions #####
 ===============================================================================
    [..]
    This subsection permit to get in run-time the status of the peripheral
    and the data flow.

@endverbatim
  * @{
  */

/**
  * @brief  Return the OPA state
  * @param  hopa OPA handle
  * @retval HAL state
  */
HAL_OPA_StateTypeDef HAL_OPA_GetState(OPA_HandleTypeDef *hopa)
{
  /* Check the OPA handle allocation */
  if (hopa == NULL)
  {
    return HAL_OPA_STATE_RESET;
  }

  /* Check the parameter */
  assert_param(IS_OPA_ALL_INSTANCE(hopa->Instance));

  return hopa->State;
}

/**
  * @}
  */

#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User OPA Callback
  *         To be used instead of the weak (surcharged) predefined callback
  * @param hopa : OPA handle
  * @param CallbackID : ID of the callback to be registered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_OPA_MSPINIT_CB_ID       OPA MspInit callback ID
  *          @arg @ref HAL_OPA_MSPDEINIT_CB_ID     OPA MspDeInit callback ID
  * @param pCallback : pointer to the Callback function
  * @retval status
  */
HAL_StatusTypeDef HAL_OPA_RegisterCallback(OPA_HandleTypeDef *hopa, HAL_OPA_CallbackIDTypeDef CallbackId,
                                             pOPA_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(hopa);

  if (hopa->State == HAL_OPA_STATE_READY)
  {
    switch (CallbackId)
    {
      case HAL_OPA_MSPINIT_CB_ID :
        hopa->MspInitCallback = pCallback;
        break;
      case HAL_OPA_MSPDEINIT_CB_ID :
        hopa->MspDeInitCallback = pCallback;
        break;
      default :
        /* update return status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (hopa->State == HAL_OPA_STATE_RESET)
  {
    switch (CallbackId)
    {
      case HAL_OPA_MSPINIT_CB_ID :
        hopa->MspInitCallback = pCallback;
        break;
      case HAL_OPA_MSPDEINIT_CB_ID :
        hopa->MspDeInitCallback = pCallback;
        break;
      default :
        /* update return status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hopa);
  return status;
}

/**
  * @brief  Unregister a User OPA Callback
  *         OPA Callback is redirected to the weak (surcharged) predefined callback
  * @param hopa : OPA handle
  * @param CallbackID : ID of the callback to be unregistered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_OPA_MSPINIT_CB_ID              OPA MSP Init Callback ID
  *          @arg @ref HAL_OPA_MSPDEINIT_CB_ID            OPA MSP DeInit Callback ID
  *          @arg @ref HAL_OPA_ALL_CB_ID                   OPA All Callbacks
  * @retval status
  */

HAL_StatusTypeDef HAL_OPA_UnRegisterCallback(OPA_HandleTypeDef *hopa, HAL_OPA_CallbackIDTypeDef CallbackId)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hopa);

  if (hopa->State == HAL_OPA_STATE_READY)
  {
    switch (CallbackId)
    {
      case HAL_OPA_MSPINIT_CB_ID :
        hopa->MspInitCallback = HAL_OPA_MspInit;
        break;
      case HAL_OPA_MSPDEINIT_CB_ID :
        hopa->MspDeInitCallback = HAL_OPA_MspDeInit;
        break;
      case HAL_OPA_ALL_CB_ID :
        hopa->MspInitCallback = HAL_OPA_MspInit;
        hopa->MspDeInitCallback = HAL_OPA_MspDeInit;
        break;
      default :
        /* update return status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (hopa->State == HAL_OPA_STATE_RESET)
  {
    switch (CallbackId)
    {
      case HAL_OPA_MSPINIT_CB_ID :
        hopa->MspInitCallback = HAL_OPA_MspInit;
        break;
      case HAL_OPA_MSPDEINIT_CB_ID :
        hopa->MspDeInitCallback = HAL_OPA_MspDeInit;
        break;
      default :
        /* update return status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hopa);
  return status;
}

#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_OPA_MODULE_ENABLED */
/**
  * @}
  */



