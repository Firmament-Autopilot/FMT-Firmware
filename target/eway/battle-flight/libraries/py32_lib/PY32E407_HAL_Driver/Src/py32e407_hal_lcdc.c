/**
  ******************************************************************************
  * @file    py32e407_hal_lcdc.c
  * @author  MCU Application Team
  * @brief   LCDC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Serial Peripheral Interface (LCDC) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *
  @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================
    [..]
      The LCDC HAL driver can be used as follows:

      (#) Declare a LCDC_HandleTypeDef handle structure, for example:
          LCDC_HandleTypeDef  hlcdc;

      (#)Initialize the LCDC low level resources by implementing the HAL_LCDC_MspInit() API:
          (##) Enable the LCDCx interface clock
          (##) LCDC pins configuration
              (+++) Enable the clock for the LCDC GPIOs
              (+++) Configure these LCDC pins as alternate function push-pull
          (##) DMA Configuration if you need to use DMA process
              (+++) Declare a DMA_HandleTypeDef handle structure for the transmit Stream/Channel
              (+++) Enable the DMAx clock
              (+++) Configure the DMA handle parameters
              (+++) Configure the DMA Tx Stream/Channel
              (+++) Associate the initialized hdma_tx handle to the hlcdc DMA Tx handle
              (+++) Configure the priority and enable the NVIC for the transfer complete interrupt on the DMA Tx Stream/Channel

      (#) Program the Interface mode, write ADDSET time, DATAST time, DATAHLD time and 
          read ADDSET time, DATAST time, DATAHLD time in the hlcdc Init structure.

      (#) Initialize the LCDC registers by calling the HAL_LCDC_Init() API:
          (++) This API configures also the low level Hardware GPIO, CLOCK, CORTEX...etc)
              by calling the customized HAL_LCDC_MspInit() API.
     [..]
       Callback registration:

      (#) The compilation flag USE_HAL_LCDC_REGISTER_CALLBACKS when set to 1U
          allows the user to configure dynamically the driver callbacks.
          Use Functions HAL_LCDC_RegisterCallback() to register an interrupt callback.

          Function HAL_LCDC_RegisterCallback() allows to register following callbacks:
            (++) ErrorCallback         : LCDC Error callback
            (++) WriteCpltCallback     : LCDC Write completed callback
            (++) MspInitCallback       : LCDC Msp Init callback
            (++) MspDeInitCallback     : LCDC Msp DeInit callback
          This function takes as parameters the HAL peripheral handle, the Callback ID
          and a pointer to the user callback function.


      (#) Use function HAL_LCDC_UnRegisterCallback to reset a callback to the default
          weak function.
          HAL_LCDC_UnRegisterCallback takes as parameters the HAL peripheral handle,
          and the Callback ID.
          This function allows to reset following callbacks:
            (++) ErrorCallback         : LCDC Error callback
            (++) WriteCpltCallback     : LCDC Write completed callback
            (++) MspInitCallback       : LCDC Msp Init callback
            (++) MspDeInitCallback     : LCDC Msp DeInit callback

       [..]
       By default, after the HAL_LCDC_Init() and when the state is HAL_LCDC_STATE_RESET
       all callbacks are set to the corresponding weak functions.
       Exception done for MspInit and MspDeInit functions that are
       reset to the legacy weak functions in the HAL_LCDC_Init()/ HAL_LCDC_DeInit() only when
       these callbacks are null (not registered beforehand).
       If MspInit or MspDeInit are not null, the HAL_LCDC_Init()/ HAL_LCDC_DeInit()
       keep and use the user MspInit/MspDeInit callbacks (registered beforehand) whatever the state.

       [..]
       Callbacks can be registered/unregistered in HAL_LCDC_STATE_READY state only.
       Exception done MspInit/MspDeInit functions that can be registered/unregistered
       in HAL_LCDC_STATE_READY or HAL_LCDC_STATE_RESET state,
       thus registered (user) MspInit/DeInit callbacks can be used during the Init/DeInit.
       Then, the user first registers the MspInit/MspDeInit user callbacks
       using HAL_LCDC_RegisterCallback() before calling HAL_LCDC_DeInit()
       or HAL_LCDC_Init() function.

       [..]
       When the compilation define USE_HAL_PPP_REGISTER_CALLBACKS is set to 0 or
       not defined, the callback registering feature is not available
       and weak (surcharged) callbacks are used.

  @endverbatim
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

/** @defgroup LCDC LCDC
  * @brief LCDC HAL module driver
  * @{
  */
#ifdef HAL_LCDC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/** @defgroup LCDC_Private_Constants LCDC Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup LCDC_Private_Functions LCDC Private Functions
  * @{
  */
static void LCDC_DMAWriteCplt(DMA_HandleTypeDef *hdma);
static void LCDC_DMAError(DMA_HandleTypeDef *hdma);
static HAL_StatusTypeDef LCDC_WaitOnFlagUntilTimeout(LCDC_HandleTypeDef *hlcdc, 
                                                     uint32_t Flag, 
                                                     FlagStatus Status,
                                                     uint32_t Timeout, 
                                                     uint32_t Tickstart);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup LCDC_Exported_Functions LCDC Exported Functions
  * @{
  */

/** @defgroup LCDC_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This subsection provides a set of functions allowing to initialize and
          de-initialize the LCDCx peripheral:

      (+) User must implement HAL_LCDC_MspInit() function in which he configures
          all related peripherals resources (CLOCK, GPIO, DMA).

      (+) Call the function HAL_LCDC_Init() to configure the selected device with
          the selected configuration:
        (++) Interface Mode
        (++) Write access timing: ADDSET time
        (++) Write access timing: DATAST time
        (++) Write access timing: DATAHLD time
        (++) Read access timing: ADDSET time
        (++) Read access timing: DATAST time
        (++) Read access timing: DATAHLD time

      (+) Call the function HAL_LCDC_DeInit() to restore the default configuration
          of the selected LCDCx peripheral.

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the LCDC according to the specified parameters
  *         in the LCDC_InitTypeDef and initialize the associated handle.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_Init(LCDC_HandleTypeDef *hlcdc)
{

  /* Check the LCDC handle allocation */
  if (hlcdc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_LCDC_ALL_INSTANCE(hlcdc->Instance));
  assert_param(IS_LCDC_MODE(hlcdc->Init.Mode));
  assert_param(IS_LCDC_ADDSET(hlcdc->Init.Write.AddSet));
  assert_param(IS_LCDC_DATAST(hlcdc->Init.Write.DataSt));
  assert_param(IS_LCDC_DATAHOLD(hlcdc->Init.Write.DataHold));
  assert_param(IS_LCDC_ADDSET(hlcdc->Init.Read.AddSet));
  assert_param(IS_LCDC_DATAST(hlcdc->Init.Read.DataSt));
  assert_param(IS_LCDC_DATAHOLD(hlcdc->Init.Read.DataHold));

  if (hlcdc->State == HAL_LCDC_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hlcdc->Lock = HAL_UNLOCKED;

#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
    /* Init the LCDC Callback settings */
    hlcdc->WriteCpltCallback   = HAL_LCDC_WriteCpltCallback;   /* Legacy weak WriteCpltCallback   */
    hlcdc->ErrorCallback       = HAL_LCDC_ErrorCallback;       /* Legacy weak ErrorCallback       */

    if (hlcdc->MspInitCallback == NULL)
    {
      hlcdc->MspInitCallback = HAL_LCDC_MspInit; /* Legacy weak MspInit  */
    }

    /* Init the low level hardware : GPIO, CLOCK... */
    hlcdc->MspInitCallback(hlcdc);
#else
    /* Init the low level hardware : GPIO, CLOCK... */
    HAL_LCDC_MspInit(hlcdc);
#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */
  }

  hlcdc->State = HAL_LCDC_STATE_BUSY;

  if(hlcdc->Instance == LCDC0)
  {
    /* Disable the selected LCDC peripheral */
    CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_EN0);

    /* Configure LCDC0 mode */
    MODIFY_REG(LCDC0123_COMMON->CSR, LCDC_CSR_MODE0, hlcdc->Init.Mode << LCDC_CSR_MODE0_Pos); 
  }
  else if(hlcdc->Instance == LCDC1)
  {
    /* Disable the selected LCDC peripheral */
    CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_EN1);

    /* Configure LCDC1 mode */
    MODIFY_REG(LCDC0123_COMMON->CSR, LCDC_CSR_MODE1, hlcdc->Init.Mode << LCDC_CSR_MODE1_Pos); 
  }
  else if(hlcdc->Instance == LCDC2)
  {
    /* Disable the selected LCDC peripheral */
    CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_EN2);

    /* Configure LCDC2 mode */
    MODIFY_REG(LCDC0123_COMMON->CSR, LCDC_CSR_MODE2, hlcdc->Init.Mode << LCDC_CSR_MODE2_Pos); 
  }
  else if(hlcdc->Instance == LCDC3)
  {
    /* Disable the selected LCDC peripheral */
    CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_EN3);

    /* Configure LCDC3 mode */
    MODIFY_REG(LCDC0123_COMMON->CSR, LCDC_CSR_MODE3, hlcdc->Init.Mode << LCDC_CSR_MODE3_Pos); 
  }
  else
  {
    hlcdc->State = HAL_LCDC_STATE_RESET;
    return HAL_ERROR;
  }

  /*----------------------- LCDCx WCFGR & RCFGR Configuration ---------------------*/
  /* Configure : address setup time , data-phase duration and data hold time for write
     access */
  WRITE_REG(hlcdc->Instance->WCFGR, ((hlcdc->Init.Write.AddSet & LCDC_WCFGR_ADDSET) |
                                     ((hlcdc->Init.Write.DataSt << LCDC_WCFGR_DATAST_Pos) & LCDC_WCFGR_DATAST) |
                                     ((hlcdc->Init.Write.DataHold << LCDC_WCFGR_DATAHLD_Pos) & LCDC_WCFGR_DATAHLD)));
  
  /* Configure : address setup time , data-phase duration and data hold time for read
     access */
  WRITE_REG(hlcdc->Instance->RCFGR, ((hlcdc->Init.Read.AddSet & LCDC_RCFGR_ADDSET) |
                                     ((hlcdc->Init.Read.DataSt << LCDC_RCFGR_DATAST_Pos) & LCDC_RCFGR_DATAST) |
                                     ((hlcdc->Init.Read.DataHold << LCDC_RCFGR_DATAHLD_Pos) & LCDC_RCFGR_DATAHLD)));

  hlcdc->ErrorCode = HAL_LCDC_ERROR_NONE;
  hlcdc->State     = HAL_LCDC_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  De-Initialize the LCDC peripheral.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_DeInit(LCDC_HandleTypeDef *hlcdc)
{
  /* Check the LCDC handle allocation */
  if (hlcdc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check LCDC Instance parameter */
  assert_param(IS_LCDC_ALL_INSTANCE(hlcdc->Instance));

  hlcdc->State = HAL_LCDC_STATE_BUSY;

  /* Disable the selected LCDC peripheral */
   __HAL_LCDC_DISABLE(hlcdc);


#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
  if (hlcdc->MspDeInitCallback == NULL)
  {
    hlcdc->MspDeInitCallback = HAL_LCDC_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware: GPIO, CLOCK... */
  hlcdc->MspDeInitCallback(hlcdc);
#else
  /* DeInit the low level hardware: GPIO, CLOCK... */
  HAL_LCDC_MspDeInit(hlcdc);
#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */

  hlcdc->ErrorCode = HAL_LCDC_ERROR_NONE;
  hlcdc->State = HAL_LCDC_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hlcdc);

  return HAL_OK;
}

/**
  * @brief  Initialize the LCDC MSP.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @retval None
  */
__weak void HAL_LCDC_MspInit(LCDC_HandleTypeDef *hlcdc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcdc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LCDC_MspInit should be implemented in the user file
   */
}

/**
  * @brief  De-Initialize the LCDC MSP.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @retval None
  */
__weak void HAL_LCDC_MspDeInit(LCDC_HandleTypeDef *hlcdc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcdc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LCDC_MspDeInit should be implemented in the user file
   */
}

#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
/**
  * @brief  Register a User LCDC Callback
  *         To be used instead of the weak predefined callback
  * @param  hlcdc Pointer to a LCDC_HandleTypeDef structure that contains
  *                the configuration information for the specified LCDC.
  * @param  CallbackID ID of the callback to be registered
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_RegisterCallback(LCDC_HandleTypeDef *hlcdc, HAL_LCDC_CallbackIDTypeDef CallbackID,
                                           pLCDC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hlcdc->ErrorCode |= HAL_LCDC_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hlcdc);

  if (HAL_LCDC_STATE_READY == hlcdc->State)
  {
    switch (CallbackID)
    {
      case HAL_LCDC_WRITECPLT_CB_ID :
        hlcdc->WriteCpltCallback = pCallback;
        break;

      case HAL_LCDC_ERROR_CB_ID :
        hlcdc->ErrorCallback = pCallback;
        break;

      case HAL_LCDC_MSPINIT_CB_ID :
        hlcdc->MspInitCallback = pCallback;
        break;

      case HAL_LCDC_MSPDEINIT_CB_ID :
        hlcdc->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        SET_BIT(hlcdc->ErrorCode, HAL_LCDC_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_LCDC_STATE_RESET == hlcdc->State)
  {
    switch (CallbackID)
    {
      case HAL_LCDC_MSPINIT_CB_ID :
        hlcdc->MspInitCallback = pCallback;
        break;

      case HAL_LCDC_MSPDEINIT_CB_ID :
        hlcdc->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        SET_BIT(hlcdc->ErrorCode, HAL_LCDC_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    SET_BIT(hlcdc->ErrorCode, HAL_LCDC_ERROR_INVALID_CALLBACK);

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hlcdc);
  return status;
}

/**
  * @brief  Unregister an LCDC Callback
  *         LCDC callback is redirected to the weak predefined callback
  * @param  hlcdc Pointer to a LCDC_HandleTypeDef structure that contains
  *                the configuration information for the specified LCDC.
  * @param  CallbackID ID of the callback to be unregistered
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_UnRegisterCallback(LCDC_HandleTypeDef *hlcdc, HAL_LCDC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hlcdc);

  if (HAL_LCDC_STATE_READY == hlcdc->State)
  {
    switch (CallbackID)
    {
      case HAL_LCDC_WRITECPLT_CB_ID :
        hlcdc->WriteCpltCallback = HAL_LCDC_WriteCpltCallback;       /* Legacy weak WriteCpltCallback    */
        break;

      case HAL_LCDC_ERROR_CB_ID :
        hlcdc->ErrorCallback = HAL_LCDC_ErrorCallback;               /* Legacy weak ErrorCallback        */
        break;

      case HAL_LCDC_MSPINIT_CB_ID :
        hlcdc->MspInitCallback = HAL_LCDC_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_LCDC_MSPDEINIT_CB_ID :
        hlcdc->MspDeInitCallback = HAL_LCDC_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        SET_BIT(hlcdc->ErrorCode, HAL_LCDC_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_LCDC_STATE_RESET == hlcdc->State)
  {
    switch (CallbackID)
    {
      case HAL_LCDC_MSPINIT_CB_ID :
        hlcdc->MspInitCallback = HAL_LCDC_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_LCDC_MSPDEINIT_CB_ID :
        hlcdc->MspDeInitCallback = HAL_LCDC_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        SET_BIT(hlcdc->ErrorCode, HAL_LCDC_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    SET_BIT(hlcdc->ErrorCode, HAL_LCDC_ERROR_INVALID_CALLBACK);

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hlcdc);
  return status;
}
#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup LCDC_Exported_Functions_Group2 IO operation functions
  *  @brief   Data transfers functions
  *
@verbatim
  ==============================================================================
                      ##### IO operation functions #####
 ===============================================================================
 [..]
    This subsection provides a set of functions allowing to manage the LCDC
    data transfers.

    [..] The LCDC supports 8080 and 6800 mode :

    (#) There are two modes of transfer:
       (++) Blocking mode: The communication is performed in polling mode.
            The HAL status of all data processing is returned by the same function
            after finishing transfer.
       (++) No-Blocking mode: The communication is performed using DMA, 
            These APIs return the HAL status.
            The end of the data processing will be indicated through 
            the DMA IRQ when using DMA mode.
            The HAL_LCDC_ErrorCallback()user callback will be executed when a communication error is detected

@endverbatim
  * @{
  */

/**
  * @brief  Write an amount of data in blocking mode.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_WriteData(LCDC_HandleTypeDef *hlcdc, uint8_t *pData, uint32_t Size, uint32_t Timeout)
{
  uint32_t tickstart;

  if (hlcdc->State == HAL_LCDC_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    /* Check DataSize parameter */
    assert_param(IS_LCDC_DATASIZE(hlcdc->Init.DataSize));

    /* Process Locked */
    __HAL_LOCK(hlcdc);

    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

    /* Set the transaction information */
    hlcdc->State       = HAL_LCDC_STATE_BUSY_WRITE_DATA;
    hlcdc->ErrorCode   = HAL_LCDC_ERROR_NONE;
    hlcdc->pBuffPtr    = (uint8_t *)pData;
    hlcdc->XferSize    = Size;
    hlcdc->XferCount   = Size;
    
    /* Enable LCDC */
    __HAL_LCDC_ENABLE(hlcdc);

    while(hlcdc->XferCount > 0U)
    {
      /* Wait until BUSY flag is clear */
      if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }

      switch (hlcdc->Init.DataSize)
      {
        case LCDC_DATASIZE_8BIT:
          *((__IO uint8_t *)&hlcdc->Instance->DR) = (*(uint8_t*)hlcdc->pBuffPtr) & 0xFFU;
          hlcdc->pBuffPtr++;
        break;

        case LCDC_DATASIZE_9BIT:
          *((__IO uint16_t *)&hlcdc->Instance->DR) = (*(uint16_t*)hlcdc->pBuffPtr) & 0x1FFU;
          hlcdc->pBuffPtr += 2;
        break;

        case LCDC_DATASIZE_16BIT:
          *((__IO uint16_t *)&hlcdc->Instance->DR) = (*(uint16_t*)hlcdc->pBuffPtr) & 0xFFFFU;
          hlcdc->pBuffPtr += 2;
        break;

        case LCDC_DATASIZE_18BIT:
          *((__IO uint32_t *)&hlcdc->Instance->DR) = (*(uint32_t*)hlcdc->pBuffPtr) & 0x3FFFFU;
          hlcdc->pBuffPtr += 4;
        break;

        default:
        break;
      }

      hlcdc->XferCount--;
    }

    /* Wait until BUSY flag is clear */
    if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }
    
    /* Disable LCDC */
    __HAL_LCDC_DISABLE(hlcdc);

    hlcdc->State = HAL_LCDC_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hlcdc);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Read an amount of data in blocking mode.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be read
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_ReadData(LCDC_HandleTypeDef *hlcdc, uint8_t *pData, uint32_t Size, uint32_t Timeout)
{ 
  uint32_t tickstart;

  if (hlcdc->State == HAL_LCDC_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    /* Check DataSize parameter */
    assert_param(IS_LCDC_DATASIZE(hlcdc->Init.DataSize));

    /* Process Locked */
    __HAL_LOCK(hlcdc);

    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

    /* Set the transaction information */
    hlcdc->State       = HAL_LCDC_STATE_BUSY_READ_DATA;
    hlcdc->ErrorCode   = HAL_LCDC_ERROR_NONE;
    hlcdc->pBuffPtr    = (uint8_t *)pData;
    hlcdc->XferSize    = Size;
    hlcdc->XferCount   = Size;

    /* Enable LCDC */
    __HAL_LCDC_ENABLE(hlcdc);
    
    while(hlcdc->XferCount > 0U)
    {
      /* Wait until BUSY flag is clear */
      if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }

      switch (hlcdc->Init.DataSize)
      {
        case LCDC_DATASIZE_8BIT:
          *((uint8_t *)hlcdc->pBuffPtr) = ( uint8_t )(hlcdc->Instance->DR & 0xFFU);
          hlcdc->pBuffPtr++;
        break;

        case LCDC_DATASIZE_9BIT:
          *((uint16_t *)hlcdc->pBuffPtr) = ( uint16_t )(hlcdc->Instance->DR & 0x1FFU);
          hlcdc->pBuffPtr += 2;
        break;

        case LCDC_DATASIZE_16BIT:
          *((uint16_t *)hlcdc->pBuffPtr) = ( uint16_t )(hlcdc->Instance->DR & 0xFFFFU);
          hlcdc->pBuffPtr += 2;
        break;

        case LCDC_DATASIZE_18BIT:
          *((uint32_t *)hlcdc->pBuffPtr) = ( uint32_t )(hlcdc->Instance->DR & 0x3FFFFU);
          hlcdc->pBuffPtr += 4;
        break;

        default:
        break;
      }

      hlcdc->XferCount--;
    }

    /* Wait until BUSY flag is clear */
    if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }
    
    /* Disable LCDC */
    __HAL_LCDC_DISABLE(hlcdc);

    hlcdc->State = HAL_LCDC_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hlcdc);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Write an amount of data in no-blocking mode with DMA.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_WriteData_DMA(LCDC_HandleTypeDef *hlcdc, uint8_t *pData, uint32_t Size)
{
  uint32_t status;

  if (hlcdc->State == HAL_LCDC_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    /* Check DataSize parameter */
    assert_param(IS_LCDC_DATASIZE(hlcdc->Init.DataSize));
    
    /* Only 8bit and 16bit formats are supported */
    if ((hlcdc->hdmatx->Init.DstWidth != DMA_DST_WIDTH_HALFWORD) && (hlcdc->hdmatx->Init.DstWidth != DMA_DST_WIDTH_BYTE))
    {
      return  HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(hlcdc);

    /* Set the transaction information */
    hlcdc->State       = HAL_LCDC_STATE_BUSY_WRITE_DATA;
    hlcdc->ErrorCode   = HAL_LCDC_ERROR_NONE;
    hlcdc->pBuffPtr    = (uint8_t *)pData;
    hlcdc->XferSize    = Size;
    hlcdc->XferCount   = Size;

    if(hlcdc->hdmatx != NULL)
    {
      /* Set the LCDC DMA transfer complete callback */
      hlcdc->hdmatx->XferCpltCallback = LCDC_DMAWriteCplt;

      /* Set the DMA error callback */
      hlcdc->hdmatx->XferErrorCallback = LCDC_DMAError;

      /* Enable the LCDC DMA channel */
      status = HAL_DMA_Start_IT(hlcdc->hdmatx, (uint32_t)pData, (uint32_t)&hlcdc->Instance->DR, Size);
    }

    if (status == HAL_OK)
    {
      /* Process Unlocked */
      __HAL_UNLOCK(hlcdc);

      /* Enable the DMA transfer for transmit request by setting the DMAEN bit
         in the LCDC COMMON register */
      SET_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_DMAEN);
      
      /* Enable LCDC */
      __HAL_LCDC_ENABLE(hlcdc);

      return HAL_OK;
    }
    else
    {
      /* Set error code to DMA */
      hlcdc->ErrorCode = HAL_LCDC_ERROR_DMA;

      /* Process Unlocked */
      __HAL_UNLOCK(hlcdc);

      /* Restore hlcdc->State to ready */
      hlcdc->State = HAL_LCDC_STATE_READY;

      return HAL_ERROR;
    }
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Write an amount of cmd in blocking mode.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @param  pCmd pointer to Cmd buffer
  * @param  Size amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_WriteCmd(LCDC_HandleTypeDef *hlcdc, uint8_t *pCmd, uint32_t Size, uint32_t Timeout)
{
  uint32_t tickstart;

  if (hlcdc->State == HAL_LCDC_STATE_READY)
  {
    if ((pCmd == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    /* Check DataSize parameter */
    assert_param(IS_LCDC_DATASIZE(hlcdc->Init.CmdSize));

    /* Process Locked */
    __HAL_LOCK(hlcdc);

    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

    /* Set the transaction information */
    hlcdc->State       = HAL_LCDC_STATE_BUSY_WRITE_CMD;
    hlcdc->ErrorCode   = HAL_LCDC_ERROR_NONE;
    hlcdc->pBuffPtr    = (uint8_t *)pCmd;
    hlcdc->XferSize    = Size;
    hlcdc->XferCount   = Size;
    
    /* Enable LCDC */
    __HAL_LCDC_ENABLE(hlcdc);

    while(hlcdc->XferCount > 0U)
    {
      /* Wait until BUSY flag is clear */
      if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }

      switch (hlcdc->Init.CmdSize)
      {
        case LCDC_CMDSIZE_8BIT:
          *((__IO uint8_t *)&hlcdc->Instance->CMDR) = (*(hlcdc->pBuffPtr) & 0xFFU);
          hlcdc->pBuffPtr++;
        break;

        case LCDC_CMDSIZE_9BIT:
          *((__IO uint16_t *)&hlcdc->Instance->CMDR) = (*(uint16_t*)hlcdc->pBuffPtr) & 0x1FFU;
          hlcdc->pBuffPtr += 2;
        break;

        case LCDC_CMDSIZE_16BIT:
          *((__IO uint16_t *)&hlcdc->Instance->CMDR) = (*(uint16_t*)hlcdc->pBuffPtr) & 0xFFFFU;
          hlcdc->pBuffPtr += 2;
        break;

        case LCDC_CMDSIZE_18BIT:
          *((__IO uint32_t *)&hlcdc->Instance->CMDR) = (*(uint32_t*)hlcdc->pBuffPtr) & 0x3FFFFU;
          hlcdc->pBuffPtr += 4;
        break;

        default:
        break;
      }

      hlcdc->XferCount--;
    }

    /* Wait until BUSY flag is clear */
    if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    /* Disable LCDC */
    __HAL_LCDC_DISABLE(hlcdc);
    
    hlcdc->State = HAL_LCDC_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hlcdc);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Read an amount of data in blocking mode.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @param  pCmd pointer to data buffer
  * @param  Size amount of data to be read
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_ReadCmd(LCDC_HandleTypeDef *hlcdc, uint8_t *pCmd, uint32_t Size, uint32_t Timeout)
{ 
  uint32_t tickstart;

  if (hlcdc->State == HAL_LCDC_STATE_READY)
  {
    if ((pCmd == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    /* Check DataSize parameter */
    assert_param(IS_LCDC_DATASIZE(hlcdc->Init.DataSize));

    /* Process Locked */
    __HAL_LOCK(hlcdc);

    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

    /* Set the transaction information */
    hlcdc->State       = HAL_LCDC_STATE_BUSY_READ_CMD;
    hlcdc->ErrorCode   = HAL_LCDC_ERROR_NONE;
    hlcdc->pBuffPtr    = (uint8_t *)pCmd;
    hlcdc->XferSize    = Size;
    hlcdc->XferCount   = Size;
    
    /* Enable LCDC */
    __HAL_LCDC_ENABLE(hlcdc);

    while(hlcdc->XferCount > 0U)
    {
      /* Wait until BUSY flag is clear */
      if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }

      switch (hlcdc->Init.DataSize)
      {
        case LCDC_DATASIZE_8BIT:
          *((uint8_t *)hlcdc->pBuffPtr) = ( uint8_t )(hlcdc->Instance->CMDR & 0xFFU);
          hlcdc->pBuffPtr++;
        break;

        case LCDC_DATASIZE_9BIT:
          *((uint16_t *)hlcdc->pBuffPtr) = ( uint16_t )(hlcdc->Instance->CMDR & 0x1FFU);
          hlcdc->pBuffPtr += 2;
        break;

        case LCDC_DATASIZE_16BIT:
          *((uint16_t *)hlcdc->pBuffPtr) = ( uint16_t )(hlcdc->Instance->CMDR & 0xFFFFU);
          hlcdc->pBuffPtr += 2;
        break;

        case LCDC_DATASIZE_18BIT:
          *((uint32_t *)hlcdc->pBuffPtr) = ( uint32_t )(hlcdc->Instance->CMDR & 0x3FFFFU);
          hlcdc->pBuffPtr += 4;
        break;

        default:
        break;
      }

      hlcdc->XferCount--;
    }

    /* Wait until BUSY flag is clear */
    if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }
    
    /* Disable LCDC */
    __HAL_LCDC_DISABLE(hlcdc);

    hlcdc->State = HAL_LCDC_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hlcdc);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Abort ongoing transfer (blocking mode).
  * @param  hlcdc LCDC handle.
  * @note   This procedure could be used for aborting any ongoing transfer,
  *         started in DMA mode.
  *         This procedure performs following operations :
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LCDC_Abort(LCDC_HandleTypeDef *hlcdc)
{
  uint32_t tickstart;

  /* Abort the LCDC DMA channel if enabled */
  if (HAL_IS_BIT_SET(LCDC0123_COMMON->CSR, LCDC_CSR_DMAEN))
  {
    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

    /* Abort the LCDC DMA Tx Stream/Channel : use blocking DMA Abort API (no callback) */
    if (hlcdc->hdmatx != NULL)
    {
      /* Set the LCDC DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hlcdc->hdmatx->XferAbortCallback = NULL;

      /* Abort DMA Tx Handle linked to LCDC Peripheral */
      if (HAL_DMA_Abort(hlcdc->hdmatx) != HAL_OK)
      {
        hlcdc->ErrorCode = HAL_LCDC_ERROR_ABORT;
        return HAL_ERROR;
      }
      
      /* Disable the LCDC DMA request if enabled */
      CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_DMAEN);

      /* Wait until BUSY flag is clear */
      if (LCDC_WaitOnFlagUntilTimeout(hlcdc, LCDC_FLAG_BUSY, SET, 1000, tickstart) != HAL_OK)
      {
        hlcdc->ErrorCode = HAL_LCDC_ERROR_ABORT;
        return HAL_ERROR;
      }
    }
  }

  /* Reset transfer counters */
  hlcdc->XferCount = 0U;

  /* Reset errorCode */
  hlcdc->ErrorCode = HAL_LCDC_ERROR_NONE;
 
  /* Restore hlcdc->state to ready */
  hlcdc->State = HAL_LCDC_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Write completed callback.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @retval None
  */
__weak void HAL_LCDC_WriteCpltCallback(LCDC_HandleTypeDef *hlcdc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcdc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LCDC_WriteCpltCallback should be implemented in the user file
   */
}

/**
  * @brief  Error callback.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @retval None
  */
__weak void HAL_LCDC_ErrorCallback(LCDC_HandleTypeDef *hlcdc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlcdc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LCDC_ErrorCallback should be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup LCDC_Exported_Functions_Group3 Peripheral State and Errors functions
  * @brief   LCDC control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State and Errors functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the LCDC.
     (+) HAL_LCDC_GetState() API can be helpful to check in run-time the state of the LCDC peripheral
     (+) HAL_LCDC_GetError() check in run-time Errors occurring during communication
@endverbatim
  * @{
  */

/**
  * @brief  Return the LCDC handle state.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @retval LCDC state
  */
HAL_LCDC_StateTypeDef HAL_LCDC_GetState(LCDC_HandleTypeDef *hlcdc)
{
  /* Return LCDC handle state */
  return hlcdc->State;
}

/**
  * @brief  Return the LCDC error code.
  * @param  hlcdc pointer to a LCDC_HandleTypeDef structure that contains
  *               the configuration information for LCDC module.
  * @retval LCDC error code in bitmap format
  */
uint32_t HAL_LCDC_GetError(LCDC_HandleTypeDef *hlcdc)
{
  /* Return LCDC ErrorCode */
  return hlcdc->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup LCDC_Private_Functions
  * @brief   Private functions
  * @{
  */

/**
  * @brief  This function handles LCDC Communication Timeout. It waits
  *                until a flag is no longer in the specified status.
  * @param  hlcdc Pointer to a LCDC_HandleTypeDef structure that contains
  *                the configuration information for the specified LCDC.
  * @param  Flag Specifies the LCDC flag to check.
  * @param  Status The actual Flag status (SET or RESET).
  * @param  Timeout Timeout duration
  * @param  Tickstart Tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef LCDC_WaitOnFlagUntilTimeout(LCDC_HandleTypeDef *hlcdc, uint32_t Flag, FlagStatus Status,
                                                     uint32_t Timeout, uint32_t Tickstart)
{
  while (__HAL_LCDC_GET_FLAG(LCDC0123_COMMON, Flag) == Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
      {
        if ((__HAL_LCDC_GET_FLAG(LCDC0123_COMMON, Flag) == Status))
        {
          /* Disable LCDC */
          __HAL_LCDC_DISABLE(hlcdc);
          
          hlcdc->ErrorCode |= HAL_LCDC_ERROR_TIMEOUT;
          hlcdc->State = HAL_LCDC_STATE_READY;

          /* Process Unlocked */
          __HAL_UNLOCK(hlcdc);
          return HAL_ERROR;
        }
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  DMA LCDC write process complete callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA module.
  * @retval None
  */
static void LCDC_DMAWriteCplt(DMA_HandleTypeDef *hdma)
{
  LCDC_HandleTypeDef *hlcdc = (LCDC_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */

  /* DMA Normal Mode */
  if (hdma->Init.Mode == DMA_NORMAL)
  {
    /* Disable DMA Request */
    CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_DMAEN);
    
    /* Disable LCDC */
    __HAL_LCDC_DISABLE(hlcdc);

    hlcdc->XferCount = 0U;
    hlcdc->State = HAL_LCDC_STATE_READY;

  }
  /* Call user write complete callback */
#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
  hlcdc->WriteCpltCallback(hlcdc);
#else
  HAL_LCDC_WriteCpltCallback(hlcdc);
#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA LCDC error callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA module.
  * @retval None
  */
static void LCDC_DMAError(DMA_HandleTypeDef *hdma)
{
  LCDC_HandleTypeDef *hlcdc = (LCDC_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */

  /* Disable DMA Request */
  CLEAR_BIT(LCDC0123_COMMON->CSR, LCDC_CSR_DMAEN);
  
  /* Disable LCDC */
    __HAL_LCDC_DISABLE(hlcdc);

  SET_BIT(hlcdc->ErrorCode, HAL_LCDC_ERROR_DMA);
  hlcdc->State = HAL_LCDC_STATE_READY;

  /* Call user error callback */
#if (USE_HAL_LCDC_REGISTER_CALLBACKS == 1U)
  hlcdc->ErrorCallback(hlcdc);
#else
  HAL_LCDC_ErrorCallback(hlcdc);
#endif /* USE_HAL_LCDC_REGISTER_CALLBACKS */
}

/**
  * @}
  */

#endif /* HAL_LCDC_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
