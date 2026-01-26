/**
  ******************************************************************************
  * @file    py32e407_hal_rng.c
  * @author  MCU Application Team
  * @brief   RNG HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Random Number Generator (RNG) peripheral:
  *           + Initialization and configuration functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
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

#if defined (RNG)

/** @addtogroup RNG
  * @brief RNG HAL module driver.
  * @{
  */

#ifdef HAL_RNG_MODULE_ENABLED

/* Private types -------------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup RNG_Private_Constants RNG Private Constants
  * @{
  */
#define RNG_TIMEOUT_VALUE     2U
/**
  * @}
  */
/* Private macros ------------------------------------------------------------*/
/* Private functions prototypes ----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup RNG_Exported_Functions
  * @{
  */

/** @addtogroup RNG_Exported_Functions_Group1
  *  @brief   Initialization and configuration functions
  *
@verbatim
 ===============================================================================
          ##### Initialization and configuration functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Initialize the RNG according to the specified parameters
          in the RNG_InitTypeDef and create the associated handle
      (+) DeInitialize the RNG peripheral
      (+) Initialize the RNG MSP
      (+) DeInitialize RNG MSP

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the RNG peripheral and creates the associated handle.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RNG_Init(RNG_HandleTypeDef *hrng)
{
  /* Check the RNG handle allocation */
  if (hrng == NULL)
  {
    return HAL_ERROR;
  }
  /* Check the parameters */
  assert_param(IS_RNG_ALL_INSTANCE(hrng->Instance));
  assert_param(IS_RNG_RANDOM_SRC0(hrng->Init.RandomSrc0));
  assert_param(IS_RNG_RANDOM_SRC1(hrng->Init.RandomSrc1));

#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
  if (hrng->State == HAL_RNG_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hrng->Lock = HAL_UNLOCKED;

    hrng->ReadyDataCallback  = HAL_RNG_ReadyDataCallback;  /* Legacy weak ReadyDataCallback  */

    if (hrng->MspInitCallback == NULL)
    {
      hrng->MspInitCallback = HAL_RNG_MspInit; /* Legacy weak MspInit  */
    }

    /* Init the low level hardware */
    hrng->MspInitCallback(hrng);
  }
#else
  if (hrng->State == HAL_RNG_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hrng->Lock = HAL_UNLOCKED;

    /* Init the low level hardware */
    HAL_RNG_MspInit(hrng);
  }
#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */

  /* Change RNG peripheral state */
  hrng->State = HAL_RNG_STATE_BUSY;

  /*  Random Source Configuration */
  MODIFY_REG(hrng->Instance->CR, (RNG_CR_RBG0_EN | RNG_CR_RBG1_EN), (hrng->Init.RandomSrc0 | hrng->Init.RandomSrc1));

  /* Initialize the RNG state */
  hrng->State = HAL_RNG_STATE_READY;

  /* Initialise the error code */
  hrng->ErrorCode = HAL_RNG_ERROR_NONE;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  DeInitializes the RNG peripheral.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RNG_DeInit(RNG_HandleTypeDef *hrng)
{
  __IO uint32_t tmpreg = 0;
  
  /* Check the RNG handle allocation */
  if (hrng == NULL)
  {
    return HAL_ERROR;
  }
  
  hrng->Instance->CR = 0x0;
  
  hrng->Instance->LFSR = 0x0;
  
  tmpreg = hrng->Instance->DR;
  UNUSED(tmpreg);

#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
  if (hrng->MspDeInitCallback == NULL)
  {
    hrng->MspDeInitCallback = HAL_RNG_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware */
  hrng->MspDeInitCallback(hrng);
#else
  /* DeInit the low level hardware */
  HAL_RNG_MspDeInit(hrng);
#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */

  /* Update the RNG state */
  hrng->State = HAL_RNG_STATE_RESET;

  /* Initialise the error code */
  hrng->ErrorCode = HAL_RNG_ERROR_NONE;

  /* Release Lock */
  __HAL_UNLOCK(hrng);

  /* Return the function status */
  return HAL_OK;
}

/**
  * @brief  Initializes the RNG MSP.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @retval None
  */
__weak void HAL_RNG_MspInit(RNG_HandleTypeDef *hrng)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrng);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_RNG_MspInit must be implemented in the user file.
   */
}

/**
  * @brief  DeInitializes the RNG MSP.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @retval None
  */
__weak void HAL_RNG_MspDeInit(RNG_HandleTypeDef *hrng)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrng);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_RNG_MspDeInit must be implemented in the user file.
   */
}

#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User RNG Callback
  *         To be used instead of the weak predefined callback
  * @param  hrng RNG handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_RNG_MSPINIT_CB_ID MspInit callback ID
  *          @arg @ref HAL_RNG_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RNG_RegisterCallback(RNG_HandleTypeDef *hrng, HAL_RNG_CallbackIDTypeDef CallbackID,
                                           pRNG_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hrng->ErrorCode = HAL_RNG_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hrng);

  if (HAL_RNG_STATE_READY == hrng->State || HAL_RNG_STATE_RESET == hrng->State)
  {
    switch (CallbackID)
    {
      case HAL_RNG_MSPINIT_CB_ID :
        hrng->MspInitCallback = pCallback;
        break;

      case HAL_RNG_MSPDEINIT_CB_ID :
        hrng->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hrng->ErrorCode = HAL_RNG_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hrng->ErrorCode = HAL_RNG_ERROR_INVALID_CALLBACK;
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hrng);
  return status;
}

/**
  * @brief  Unregister an RNG Callback
  *         RNG callabck is redirected to the weak predefined callback
  * @param  hrng RNG handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_RNG_MSPINIT_CB_ID MspInit callback ID
  *          @arg @ref HAL_RNG_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RNG_UnRegisterCallback(RNG_HandleTypeDef *hrng, HAL_RNG_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hrng);

  if (HAL_RNG_STATE_READY == hrng->State || HAL_RNG_STATE_RESET == hrng->State)
  {
    switch (CallbackID)
    {
      case HAL_RNG_MSPINIT_CB_ID :
        hrng->MspInitCallback = HAL_RNG_MspInit;              /* Legacy weak MspInit  */
        break;

      case HAL_RNG_MSPDEINIT_CB_ID :
        hrng->MspDeInitCallback = HAL_RNG_MspDeInit;          /* Legacy weak MspDeInit  */
        break;

      default :
        /* Update the error code */
        hrng->ErrorCode = HAL_RNG_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hrng->ErrorCode = HAL_RNG_ERROR_INVALID_CALLBACK;
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hrng);
  return status;
}

/**
  * @brief  Register Data Ready RNG Callback
  *         To be used instead of the weak HAL_RNG_ReadyDataCallback() predefined callback
  * @param  hrng RNG handle
  * @param  pCallback pointer to the Data Ready Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RNG_RegisterReadyDataCallback(RNG_HandleTypeDef *hrng, pRNG_ReadyDataCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hrng->ErrorCode = HAL_RNG_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hrng);

  if (HAL_RNG_STATE_READY == hrng->State)
  {
    hrng->ReadyDataCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hrng->ErrorCode = HAL_RNG_ERROR_INVALID_CALLBACK;
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hrng);
  return status;
}

/**
  * @brief  UnRegister the Data Ready RNG Callback
  *         Data Ready RNG Callback is redirected to the weak HAL_RNG_ReadyDataCallback() predefined callback
  * @param  hrng RNG handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RNG_UnRegisterReadyDataCallback(RNG_HandleTypeDef *hrng)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hrng);

  if (HAL_RNG_STATE_READY == hrng->State)
  {
    hrng->ReadyDataCallback = HAL_RNG_ReadyDataCallback; /* Legacy weak ReadyDataCallback  */
  }
  else
  {
    /* Update the error code */
    hrng->ErrorCode = HAL_RNG_ERROR_INVALID_CALLBACK;
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hrng);
  return status;
}

#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup RNG_Exported_Functions_Group2
  *  @brief   Peripheral Control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Get the 32 bit Random number
      (+) Get the 32 bit Random number with interrupt enabled
      (+) Handle RNG interrupt request

@endverbatim
  * @{
  */

/**
  * @brief  Generates a 32-bit random number.
  * @note   This function checks value of RNG_FLAG_DRDY flag to know if valid
  *         random number is available in the DR register (RNG_FLAG_DRDY flag set
  *         whenever a random number is available through the RNG_DR register).
  *         After transitioning from 0 to 1 (random number available),
  *         RNG_FLAG_DRDY flag remains high until output buffer becomes empty after reading
  *         four words from the RNG_DR register, i.e. further function calls
  *         will immediately return a new u32 random number (additional words are
  *         available and can be read by the application, till RNG_FLAG_DRDY flag remains high).
  * @note   When no more random number data is available in DR register, RNG_FLAG_DRDY
  *         flag is automatically cleared.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @param  random32bit pointer to generated random number variable if successful.
  * @retval HAL status
  */

HAL_StatusTypeDef HAL_RNG_GenerateRandomNumber(RNG_HandleTypeDef *hrng, uint32_t *random32bit)
{
  uint32_t tickstart;
  HAL_StatusTypeDef status = HAL_OK;

  /* Process Locked */
  __HAL_LOCK(hrng);

  /* Check RNG peripheral state */
  if (hrng->State == HAL_RNG_STATE_READY)
  {
    /* Change RNG peripheral state */
    hrng->State = HAL_RNG_STATE_BUSY;

    /* Get tick */
    tickstart = HAL_GetTick();

    /* Check if data register contains valid random data */
    while (__HAL_RNG_GET_FLAG(hrng, RNG_FLAG_DATA_RDY) == RESET)
    {
      if ((HAL_GetTick() - tickstart) > RNG_TIMEOUT_VALUE)
      {
        /* New check to avoid false timeout detection in case of preemption */
        if (__HAL_RNG_GET_FLAG(hrng, RNG_FLAG_DATA_RDY) == RESET)
        {
          hrng->State = HAL_RNG_STATE_READY;
          hrng->ErrorCode = HAL_RNG_ERROR_TIMEOUT;
          /* Process Unlocked */
          __HAL_UNLOCK(hrng);
          return HAL_ERROR;
        }
      }
    }

    /* Get a 32bit Random number */
    hrng->RandomNumber = hrng->Instance->DR;
    *random32bit = hrng->RandomNumber;

    hrng->State = HAL_RNG_STATE_READY;
  }
  else
  {
    hrng->ErrorCode = HAL_RNG_ERROR_BUSY;
    status = HAL_ERROR;
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hrng);

  return status;
}

/**
  * @brief  Generates a 32-bit random number in interrupt mode.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RNG_GenerateRandomNumber_IT(RNG_HandleTypeDef *hrng)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process Locked */
  __HAL_LOCK(hrng);

  /* Check RNG peripheral state */
  if (hrng->State == HAL_RNG_STATE_READY)
  {
    /* Change RNG peripheral state */
    hrng->State = HAL_RNG_STATE_BUSY;

    /* Enable the RNG Interrupts */
    __HAL_RNG_ENABLE_IT(hrng, RNG_IT_DATA_RDY);
  }
  else
  {
    /* Process Unlocked */
    __HAL_UNLOCK(hrng);

    hrng->ErrorCode = HAL_RNG_ERROR_BUSY;
    status = HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Handles RNG interrupt request.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @retval None

  */
void HAL_RNG_IRQHandler(RNG_HandleTypeDef *hrng)
{
  /* Check RNG data ready interrupt occurred */
  if ((__HAL_RNG_GET_FLAG(hrng, RNG_FLAG_DATA_RDY) != RESET) && (__HAL_RNG_GET_IT_SOURCE(hrng, RNG_IT_DATA_RDY) != RESET))
  {
    /* Generate random number once, so disable the IT */
    __HAL_RNG_DISABLE_IT(hrng, RNG_IT_DATA_RDY);

    /* Get the 32bit Random number (DRDY flag automatically cleared) */
    hrng->RandomNumber = hrng->Instance->DR;

    if (hrng->State != HAL_RNG_STATE_ERROR)
    {
      /* Change RNG peripheral state */
      hrng->State = HAL_RNG_STATE_READY;
      /* Process Unlocked */
      __HAL_UNLOCK(hrng);

#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
      /* Call registered Data Ready callback */
      hrng->ReadyDataCallback(hrng, hrng->RandomNumber);
#else
      /* Call legacy weak Data Ready callback */
      HAL_RNG_ReadyDataCallback(hrng, hrng->RandomNumber);
#endif /* USE_HAL_RNG_REGISTER_CALLBACKS */
    }
  }
}

/**
  * @brief  Read latest generated random number.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @retval random value
  */
uint32_t HAL_RNG_ReadLastRandomNumber(RNG_HandleTypeDef *hrng)
{
  return (hrng->RandomNumber);
}

/**
  * @brief  Data Ready callback in non-blocking mode.
  * @note   When RNG_FLAG_DRDY flag value is set, first random number has been read
  *         from DR register in IRQ Handler and is provided as callback parameter.
  *         Depending on valid data available in the conditioning output buffer,
  *         additional words can be read by the application from DR register till
  *         DRDY bit remains high.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @param  random32bit generated random number.
  * @retval None
  */
__weak void HAL_RNG_ReadyDataCallback(RNG_HandleTypeDef *hrng, uint32_t random32bit)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrng);
  UNUSED(random32bit);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_RNG_ReadyDataCallback must be implemented in the user file.
   */
}


/** @addtogroup RNG_Exported_Functions_Group3
  *  @brief   Peripheral State functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State functions #####
 ===============================================================================
    [..]
    This subsection permits to get in run-time the status of the peripheral
    and the data flow.

@endverbatim
  * @{
  */

/**
  * @brief  Returns the RNG state.
  * @param  hrng pointer to a RNG_HandleTypeDef structure that contains
  *                the configuration information for RNG.
  * @retval HAL state
  */
HAL_RNG_StateTypeDef HAL_RNG_GetState(RNG_HandleTypeDef *hrng)
{
  return hrng->State;
}

/**
  * @brief  Return the RNG handle error code.
  * @param  hrng: pointer to a RNG_HandleTypeDef structure.
  * @retval RNG Error Code
  */
uint32_t HAL_RNG_GetError(RNG_HandleTypeDef *hrng)
{
  /* Return RNG Error Code */
  return hrng->ErrorCode;
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

#endif /* HAL_RNG_MODULE_ENABLED */
/**
  * @}
  */

#endif /* RNG */

/**
  * @}
  */

