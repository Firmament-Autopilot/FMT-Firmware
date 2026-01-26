/**
  ******************************************************************************
  * @file    py32e407_hal_usbd.c
  * @author  MCU Application Team
  * @brief   USBDEV HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the USB Peripheral Controller:
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
      The USBDEV HAL driver can be used as follows:

     (#) Declare a USBDEV_HandleTypeDef handle structure, for example:
         USBDEV_HandleTypeDef  husbd;

     (#) Fill parameters of Init structure in USBHOST handle

     (#) Call HAL_USBDEV_Init() API to initialize the USBDEV peripheral (Core, Device core, ...)

     (#) Initialize the USBDEV low level resources through the HAL_USBDEV_MspInit() API:
         (##) Enable the USBDEV/USB Low Level interface clock using
              (+++) __HAL_RCC_USB_CLK_ENABLE(); For USB Device only FS peripheral

         (##) Initialize the related GPIO clocks
         (##) Configure USBDEV pin-out
         (##) Configure USBDEV NVIC interrupt

     (#)Associate the Upper USB device stack to the HAL USBDEV Driver:
         (##) husbd.pData = pdev;

     (#)Enable USBDEV transmission and reception:
         (##) HAL_USBDEV_Start();

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

/** @defgroup USBDEV USBDEV
  * @brief USBDEV HAL module driver
  * @{
  */

#ifdef HAL_USBD_MODULE_ENABLED

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup USBDEV_Private_Macros USBDEV Private Macros
  * @{
  */
#define USBDEV_MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define USBDEV_MAX(a, b)  (((a) > (b)) ? (a) : (b))
/**
  * @}
  */

/* Private functions prototypes ----------------------------------------------*/
/** @defgroup USBDEV_Private_Functions USBDEV Private Functions
  * @{
  */
#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
static HAL_StatusTypeDef USBDEV_WriteEmptyTxFifo(USBDEV_HandleTypeDef *husbd, uint32_t epnum);
static HAL_StatusTypeDef USBDEV_EP_OutXfrComplete_int(USBDEV_HandleTypeDef *husbd, uint32_t epnum);
static HAL_StatusTypeDef USBDEV_EP_OutSetupPacket_int(USBDEV_HandleTypeDef *husbd, uint32_t epnum);
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup USBDEV_Exported_Functions USBDEV Exported Functions
  * @{
  */

/** @defgroup USBDEV_Exported_Functions_Group1 Initialization and de-initialization functions
 *  @brief    Initialization and Configuration functions
 *
@verbatim
 ===============================================================================
            ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the USBDEV according to the specified
  *         parameters in the USBDEV_InitTypeDef and initialize the associated handle.
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_Init(USBDEV_HandleTypeDef *husbd)
{
#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
  USB_OTG_GlobalTypeDef *USBx;
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */
  uint8_t i;

  /* Check the USBDEV handle allocation */
  if (husbd == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_USBDEV_ALL_INSTANCE(husbd->Instance));

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
  USBx = husbd->Instance;
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */

  if (husbd->State == HAL_USBDEV_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    husbd->Lock = HAL_UNLOCKED;

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
    husbd->SOFCallback = HAL_USBDEV_SOFCallback;
    husbd->SetupStageCallback = HAL_USBDEV_SetupStageCallback;
    husbd->ResetCallback = HAL_USBDEV_ResetCallback;
    husbd->SuspendCallback = HAL_USBDEV_SuspendCallback;
    husbd->ResumeCallback = HAL_USBDEV_ResumeCallback;
    husbd->ConnectCallback = HAL_USBDEV_ConnectCallback;
    husbd->DisconnectCallback = HAL_USBDEV_DisconnectCallback;
    husbd->DataOutStageCallback = HAL_USBDEV_DataOutStageCallback;
    husbd->DataInStageCallback = HAL_USBDEV_DataInStageCallback;
    husbd->ISOOUTIncompleteCallback = HAL_USBDEV_ISOOUTIncompleteCallback;
    husbd->ISOINIncompleteCallback = HAL_USBDEV_ISOINIncompleteCallback;

    if (husbd->MspInitCallback == NULL)
    {
      husbd->MspInitCallback = HAL_USBDEV_MspInit;
    }

    /* Init the low level hardware */
    husbd->MspInitCallback(husbd);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC... */
    HAL_USBDEV_MspInit(husbd);
#endif /* (USE_HAL_USBDEV_REGISTER_CALLBACKS) */
  }

  husbd->State = HAL_USBDEV_STATE_BUSY;

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
  /* Disable DMA mode for FS instance */
  if ((USBx->CID & (0x1U << 8)) == 0U)
  {
    husbd->Init.dma_enable = 0U;
  }
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */

  /* Disable the Interrupts */
  __HAL_USBDEV_DISABLE(husbd);

  /* Init the Core (common init.) */
  if (USB_CoreInit(husbd->Instance, husbd->Init) != HAL_OK)
  {
    husbd->State = HAL_USBDEV_STATE_ERROR;
    return HAL_ERROR;
  }

  /* Force Device Mode*/
  (void)USB_SetCurrentMode(husbd->Instance, USB_DEVICE_MODE);

  /* Init endpoints structures */
  for (i = 0U; i < husbd->Init.dev_endpoints; i++)
  {
    /* Init ep structure */
    husbd->IN_ep[i].is_in = 1U;
    husbd->IN_ep[i].num = i;
    husbd->IN_ep[i].tx_fifo_num = i;
    /* Control until ep is activated */
    husbd->IN_ep[i].type = EP_TYPE_CTRL;
    husbd->IN_ep[i].maxpacket = 0U;
    husbd->IN_ep[i].xfer_buff = 0U;
    husbd->IN_ep[i].xfer_len = 0U;
  }

  for (i = 0U; i < husbd->Init.dev_endpoints; i++)
  {
    husbd->OUT_ep[i].is_in = 0U;
    husbd->OUT_ep[i].num = i;
    /* Control until ep is activated */
    husbd->OUT_ep[i].type = EP_TYPE_CTRL;
    husbd->OUT_ep[i].maxpacket = 0U;
    husbd->OUT_ep[i].xfer_buff = 0U;
    husbd->OUT_ep[i].xfer_len = 0U;
  }

  /* Init Device */
  if (USB_DevInit(husbd->Instance, husbd->Init) != HAL_OK)
  {
    husbd->State = HAL_USBDEV_STATE_ERROR;
    return HAL_ERROR;
  }

  husbd->USB_Address = 0U;
  husbd->State = HAL_USBDEV_STATE_READY;
  (void)USB_DevDisconnect(husbd->Instance);

  return HAL_OK;
}

/**
  * @brief  DeInitializes the USBDEV peripheral.
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_DeInit(USBDEV_HandleTypeDef *husbd)
{
  /* Check the USBDEV handle allocation */
  if (husbd == NULL)
  {
    return HAL_ERROR;
  }

  husbd->State = HAL_USBDEV_STATE_BUSY;

  /* Stop Device */
  (void)HAL_USBDEV_Stop(husbd);

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
  if (husbd->MspDeInitCallback == NULL)
  {
    husbd->MspDeInitCallback = HAL_USBDEV_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware */
  husbd->MspDeInitCallback(husbd);
#else
  /* DeInit the low level hardware: CLOCK, NVIC.*/
  HAL_USBDEV_MspDeInit(husbd);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

  husbd->State = HAL_USBDEV_STATE_RESET;

  return HAL_OK;
}

/**
  * @brief  Initializes the USBDEV MSP.
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_MspInit(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes USBDEV MSP.
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_MspDeInit(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_MspDeInit could be implemented in the user file
   */
}

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
/**
  * @brief  Register a User USB USBDEV Callback
  *         To be used instead of the weak predefined callback
  * @param  husbd USB USBDEV handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_USBDEV_SOF_CB_ID USB USBDEV SOF callback ID
  *          @arg @ref HAL_USBDEV_SETUPSTAGE_CB_ID USB USBDEV Setup callback ID
  *          @arg @ref HAL_USBDEV_RESET_CB_ID USB USBDEV Reset callback ID
  *          @arg @ref HAL_USBDEV_SUSPEND_CB_ID USB USBDEV Suspend callback ID
  *          @arg @ref HAL_USBDEV_RESUME_CB_ID USB USBDEV Resume callback ID
  *          @arg @ref HAL_USBDEV_CONNECT_CB_ID USB USBDEV Connect callback ID
  *          @arg @ref HAL_USBDEV_DISCONNECT_CB_ID OTG USBDEV Disconnect callback ID
  *          @arg @ref HAL_USBDEV_MSPINIT_CB_ID MspDeInit callback ID
  *          @arg @ref HAL_USBDEV_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_RegisterCallback(USBDEV_HandleTypeDef *husbd, HAL_USBDEV_CallbackIDTypeDef CallbackID, pUSBDEV_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_USBDEV_SOF_CB_ID :
        husbd->SOFCallback = pCallback;
        break;

      case HAL_USBDEV_SETUPSTAGE_CB_ID :
        husbd->SetupStageCallback = pCallback;
        break;

      case HAL_USBDEV_RESET_CB_ID :
        husbd->ResetCallback = pCallback;
        break;

      case HAL_USBDEV_SUSPEND_CB_ID :
        husbd->SuspendCallback = pCallback;
        break;

      case HAL_USBDEV_RESUME_CB_ID :
        husbd->ResumeCallback = pCallback;
        break;

      case HAL_USBDEV_CONNECT_CB_ID :
        husbd->ConnectCallback = pCallback;
        break;

      case HAL_USBDEV_DISCONNECT_CB_ID :
        husbd->DisconnectCallback = pCallback;
        break;

      case HAL_USBDEV_MSPINIT_CB_ID :
        husbd->MspInitCallback = pCallback;
        break;

      case HAL_USBDEV_MSPDEINIT_CB_ID :
        husbd->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (husbd->State == HAL_USBDEV_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_USBDEV_MSPINIT_CB_ID :
        husbd->MspInitCallback = pCallback;
        break;

      case HAL_USBDEV_MSPDEINIT_CB_ID :
        husbd->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);
  return status;
}

/**
  * @brief  Unregister an USB USBDEV Callback
  *         USB USBDEV callabck is redirected to the weak predefined callback
  * @param  husbd USB USBDEV handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_USBDEV_SOF_CB_ID USB USBDEV SOF callback ID
  *          @arg @ref HAL_USBDEV_SETUPSTAGE_CB_ID USB USBDEV Setup callback ID
  *          @arg @ref HAL_USBDEV_RESET_CB_ID USB USBDEV Reset callback ID
  *          @arg @ref HAL_USBDEV_SUSPEND_CB_ID USB USBDEV Suspend callback ID
  *          @arg @ref HAL_USBDEV_RESUME_CB_ID USB USBDEV Resume callback ID
  *          @arg @ref HAL_USBDEV_CONNECT_CB_ID USB USBDEV Connect callback ID
  *          @arg @ref HAL_USBDEV_DISCONNECT_CB_ID OTG USBDEV Disconnect callback ID
  *          @arg @ref HAL_USBDEV_MSPINIT_CB_ID MspDeInit callback ID
  *          @arg @ref HAL_USBDEV_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_UnRegisterCallback(USBDEV_HandleTypeDef *husbd, HAL_USBDEV_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(husbd);

  /* Setup Legacy weak Callbacks  */
  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_USBDEV_SOF_CB_ID :
        husbd->SOFCallback = HAL_USBDEV_SOFCallback;
        break;

      case HAL_USBDEV_SETUPSTAGE_CB_ID :
        husbd->SetupStageCallback = HAL_USBDEV_SetupStageCallback;
        break;

      case HAL_USBDEV_RESET_CB_ID :
        husbd->ResetCallback = HAL_USBDEV_ResetCallback;
        break;

      case HAL_USBDEV_SUSPEND_CB_ID :
        husbd->SuspendCallback = HAL_USBDEV_SuspendCallback;
        break;

      case HAL_USBDEV_RESUME_CB_ID :
        husbd->ResumeCallback = HAL_USBDEV_ResumeCallback;
        break;

      case HAL_USBDEV_CONNECT_CB_ID :
        husbd->ConnectCallback = HAL_USBDEV_ConnectCallback;
        break;

      case HAL_USBDEV_DISCONNECT_CB_ID :
        husbd->DisconnectCallback = HAL_USBDEV_DisconnectCallback;
        break;

      case HAL_USBDEV_MSPINIT_CB_ID :
        husbd->MspInitCallback = HAL_USBDEV_MspInit;
        break;

      case HAL_USBDEV_MSPDEINIT_CB_ID :
        husbd->MspDeInitCallback = HAL_USBDEV_MspDeInit;
        break;

      default :
        /* Update the error code */
        husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (husbd->State == HAL_USBDEV_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_USBDEV_MSPINIT_CB_ID :
        husbd->MspInitCallback = HAL_USBDEV_MspInit;
        break;

      case HAL_USBDEV_MSPDEINIT_CB_ID :
        husbd->MspDeInitCallback = HAL_USBDEV_MspDeInit;
        break;

      default :
        /* Update the error code */
        husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);
  return status;
}

/**
  * @brief  Register USB USBDEV Data OUT Stage Callback
  *         To be used instead of the weak HAL_USBDEV_DataOutStageCallback() predefined callback
  * @param  husbd USBDEV handle
  * @param  pCallback pointer to the USB USBDEV Data OUT Stage Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_RegisterDataOutStageCallback(USBDEV_HandleTypeDef *husbd, pUSBDEV_DataOutStageCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    husbd->DataOutStageCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);

  return status;
}

/**
  * @brief  UnRegister the USB USBDEV Data OUT Stage Callback
  *         USB USBDEV Data OUT Stage Callback is redirected to the weak HAL_USBDEV_DataOutStageCallback() predefined callback
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_UnRegisterDataOutStageCallback(USBDEV_HandleTypeDef *husbd)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    husbd->DataOutStageCallback = HAL_USBDEV_DataOutStageCallback; /* Legacy weak DataOutStageCallback  */
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);

  return status;
}

/**
  * @brief  Register USB USBDEV Data IN Stage Callback
  *         To be used instead of the weak HAL_USBDEV_DataInStageCallback() predefined callback
  * @param  husbd USBDEV handle
  * @param  pCallback pointer to the USB USBDEV Data IN Stage Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_RegisterDataInStageCallback(USBDEV_HandleTypeDef *husbd, pUSBDEV_DataInStageCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    husbd->DataInStageCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);

  return status;
}

/**
  * @brief  UnRegister the USB USBDEV Data IN Stage Callback
  *         USB USBDEV Data OUT Stage Callback is redirected to the weak HAL_USBDEV_DataInStageCallback() predefined callback
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_UnRegisterDataInStageCallback(USBDEV_HandleTypeDef *husbd)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    husbd->DataInStageCallback = HAL_USBDEV_DataInStageCallback; /* Legacy weak DataInStageCallback  */
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);

  return status;
}

/**
  * @brief  Register USB USBDEV Iso OUT incomplete Callback
  *         To be used instead of the weak HAL_USBDEV_ISOOUTIncompleteCallback() predefined callback
  * @param  husbd USBDEV handle
  * @param  pCallback pointer to the USB USBDEV Iso OUT incomplete Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_RegisterIsoOutIncpltCallback(USBDEV_HandleTypeDef *husbd, pUSBDEV_IsoOutIncpltCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    husbd->ISOOUTIncompleteCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);

  return status;
}

/**
  * @brief  UnRegister the USB USBDEV Iso OUT incomplete Callback
  *         USB USBDEV Iso OUT incomplete Callback is redirected to the weak HAL_USBDEV_ISOOUTIncompleteCallback() predefined callback
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_UnRegisterIsoOutIncpltCallback(USBDEV_HandleTypeDef *husbd)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    husbd->ISOOUTIncompleteCallback = HAL_USBDEV_ISOOUTIncompleteCallback; /* Legacy weak ISOOUTIncompleteCallback  */
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);

  return status;
}

/**
  * @brief  Register USB USBDEV Iso IN incomplete Callback
  *         To be used instead of the weak HAL_USBDEV_ISOINIncompleteCallback() predefined callback
  * @param  husbd USBDEV handle
  * @param  pCallback pointer to the USB USBDEV Iso IN incomplete Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_RegisterIsoInIncpltCallback(USBDEV_HandleTypeDef *husbd, pUSBDEV_IsoInIncpltCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    husbd->ISOINIncompleteCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);

  return status;
}

/**
  * @brief  UnRegister the USB USBDEV Iso IN incomplete Callback
  *         USB USBDEV Iso IN incomplete Callback is redirected to the weak HAL_USBDEV_ISOINIncompleteCallback() predefined callback
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_UnRegisterIsoInIncpltCallback(USBDEV_HandleTypeDef *husbd)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(husbd);

  if (husbd->State == HAL_USBDEV_STATE_READY)
  {
    husbd->ISOINIncompleteCallback = HAL_USBDEV_ISOINIncompleteCallback; /* Legacy weak ISOINIncompleteCallback  */
  }
  else
  {
    /* Update the error code */
    husbd->ErrorCode |= HAL_USBDEV_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbd);

  return status;
}

#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup USBDEV_Exported_Functions_Group2 Input and Output operation functions
 *  @brief   Data transfers functions
 *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to manage the USBDEV data
    transfers.

@endverbatim
  * @{
  */

/**
  * @brief  Start the USB device
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_Start(USBDEV_HandleTypeDef *husbd)
{
  __HAL_LOCK(husbd);
  (void)USB_DevConnect(husbd->Instance);
  __HAL_USBDEV_ENABLE(husbd);
  __HAL_UNLOCK(husbd);
  return HAL_OK;
}

/**
  * @brief  Stop the USB device.
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_Stop(USBDEV_HandleTypeDef *husbd)
{
  __HAL_LOCK(husbd);
  __HAL_USBDEV_DISABLE(husbd);

  if (USB_StopDevice(husbd->Instance) != HAL_OK)
  {
    __HAL_UNLOCK(husbd);
    return HAL_ERROR;
  }

  (void)USB_DevDisconnect(husbd->Instance);
  __HAL_UNLOCK(husbd);

  return HAL_OK;
}
#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
/**
  * @brief  Handles USBDEV interrupt request.
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
void HAL_USBDEV_IRQHandler(USBDEV_HandleTypeDef *husbd)
{
  USB_OTG_GlobalTypeDef *USBx = husbd->Instance;
  uint32_t USBx_BASE = (uint32_t)USBx;
  uint32_t i, ep_intr, epint, epnum;
  uint32_t fifoemptymsk, temp;
  USB_OTG_EPTypeDef *ep;

  /* ensure that we are in device mode */
  if (USB_GetMode(husbd->Instance) == USB_OTG_MODE_DEVICE)
  {
    /* avoid spurious interrupt */
    if (__HAL_USBDEV_IS_INVALID_INTERRUPT(husbd))
    {
      return;
    }

    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_MMIS))
    {
      /* incorrect mode, acknowledge the interrupt */
      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_MMIS);
    }

    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_OEPINT))
    {
      epnum = 0U;

      /* Read in the device interrupt bits */
      ep_intr = USB_ReadDevAllOutEpInterrupt(husbd->Instance);

      while (ep_intr != 0U)
      {
        if ((ep_intr & 0x1U) != 0U)
        {
          epint = USB_ReadDevOutEPInterrupt(husbd->Instance, (uint8_t)epnum);

          /* Handler OUT transfer completed interrupt */
          if ((epint & USB_OTG_DOEPINT_XFRC) == USB_OTG_DOEPINT_XFRC)
          {
            CLEAR_OUT_EP_INTR(epnum, USB_OTG_DOEPINT_XFRC);
            (void)USBDEV_EP_OutXfrComplete_int(husbd, epnum);
          }

          /* Clear EP disabled interrupt */
          if ((epint & USB_OTG_DOEPINT_EPDISD) == USB_OTG_DOEPINT_EPDISD)
          {
            CLEAR_OUT_EP_INTR(epnum, USB_OTG_DOEPINT_EPDISD);
          }

          if ((epint & USB_OTG_DOEPINT_STUP) == USB_OTG_DOEPINT_STUP)
          {
            /* Class B setup phase done for previous decoded setup */
            (void)USBDEV_EP_OutSetupPacket_int(husbd, epnum);
            CLEAR_OUT_EP_INTR(epnum, USB_OTG_DOEPINT_STUP);
          }

          /* Clear OUT token received when endpoint disabled interrupt */
          if ((epint & USB_OTG_DOEPINT_OTEPDIS) == USB_OTG_DOEPINT_OTEPDIS)
          {
            CLEAR_OUT_EP_INTR(epnum, USB_OTG_DOEPINT_OTEPDIS);
          }

          /* Clear Status Phase Received interrupt */
          if ((epint & USB_OTG_DOEPINT_STSPHSRX) == USB_OTG_DOEPINT_STSPHSRX)
          {
            CLEAR_OUT_EP_INTR(epnum, USB_OTG_DOEPINT_STSPHSRX);
          }

          /* Clear OUT NAK interrupt */
          if ((epint & USB_OTG_DOEPINT_NAK) == USB_OTG_DOEPINT_NAK)
          {
            CLEAR_OUT_EP_INTR(epnum, USB_OTG_DOEPINT_NAK);
          }

        }
        epnum++;
        ep_intr >>= 1U;
      }
    }

    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_IEPINT))
    {
      /* Read in the device interrupt bits */
      ep_intr = USB_ReadDevAllInEpInterrupt(husbd->Instance);

      epnum = 0U;

      while (ep_intr != 0U)
      {
        if ((ep_intr & 0x1U) != 0U) /* In ITR */
        {
          epint = USB_ReadDevInEPInterrupt(husbd->Instance, (uint8_t)epnum);

          /* Handle IN transmit complete interrupt */
          if ((epint & USB_OTG_DIEPINT_XFRC) == USB_OTG_DIEPINT_XFRC)
          {
            /* Disable EP fifo empty interrupt */
            fifoemptymsk = (uint32_t)(0x1UL << (epnum & EP_ADDR_MSK));
            USBx_DEVICE->DIEPEMPMSK &= ~fifoemptymsk;

            CLEAR_IN_EP_INTR(epnum, USB_OTG_DIEPINT_XFRC);

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
            husbd->DataInStageCallback(husbd, (uint8_t)epnum);
#else
            HAL_USBDEV_DataInStageCallback(husbd, (uint8_t)epnum);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */
          }

          /* Clear timeout condition interrupt */
          if ((epint & USB_OTG_DIEPINT_TOC) == USB_OTG_DIEPINT_TOC)
          {
            CLEAR_IN_EP_INTR(epnum, USB_OTG_DIEPINT_TOC);
          }

          /* Clear IN token received when TxFIFO is empty interrupt */
          if ((epint & USB_OTG_DIEPINT_ITTXFE) == USB_OTG_DIEPINT_ITTXFE)
          {
            CLEAR_IN_EP_INTR(epnum, USB_OTG_DIEPINT_ITTXFE);
          }

          /* Clear IN endpoint NAK effective interrupt */
          if ((epint & USB_OTG_DIEPINT_INEPNE) == USB_OTG_DIEPINT_INEPNE)
          {
            CLEAR_IN_EP_INTR(epnum, USB_OTG_DIEPINT_INEPNE);
          }

          /* Clear IN endpoint disable interrupt */
          if ((epint & USB_OTG_DIEPINT_EPDISD) == USB_OTG_DIEPINT_EPDISD)
          {
            CLEAR_IN_EP_INTR(epnum, USB_OTG_DIEPINT_EPDISD);
          }

          /* Handle TX fifo empty interrupt */
          if ((epint & USB_OTG_DIEPINT_TXFE) == USB_OTG_DIEPINT_TXFE)
          {
            (void)USBDEV_WriteEmptyTxFifo(husbd, epnum);
          }
        }
        epnum++;
        ep_intr >>= 1U;
      }
    }

    /* Handle Resume Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_WKUPINT))
    {
      /* Clear the Remote Wake-up Signaling */
      USBx_DEVICE->DCTL &= ~USB_OTG_DCTL_RWUSIG;

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
      husbd->ResumeCallback(husbd);
#else
      HAL_USBDEV_ResumeCallback(husbd);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_WKUPINT);
    }

    /* Handle Suspend Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_USBSUSP))
    {
      if ((USBx_DEVICE->DSTS & USB_OTG_DSTS_SUSPSTS) == USB_OTG_DSTS_SUSPSTS)
      {
#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
        husbd->SuspendCallback(husbd);
#else
        HAL_USBDEV_SuspendCallback(husbd);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */
      }
      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_USBSUSP);
    }
    /* Handle Reset Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_USBRST))
    {
      USBx_DEVICE->DCTL &= ~USB_OTG_DCTL_RWUSIG;

      (void)USB_FlushTxFifo(husbd->Instance, 0x10U);

      for (i = 0U; i < husbd->Init.dev_endpoints; i++)
      {
        /* Clear all interrupt flag */
        USBx_INEP(i)->DIEPINT = 0xFB7FU;
        USBx_INEP(i)->DIEPCTL &= ~USB_OTG_DIEPCTL_STALL;
        USBx_OUTEP(i)->DOEPINT = 0xFB7FU;
        USBx_OUTEP(i)->DOEPCTL &= ~USB_OTG_DOEPCTL_STALL;
      }
      /* Enable EP0 interrupt */
      USBx_DEVICE->DAINTMSK |= 0x10001U;

      USBx_DEVICE->DOEPMSK |= USB_OTG_DOEPMSK_STUPM |
                              USB_OTG_DOEPMSK_XFRCM |
                              USB_OTG_DOEPMSK_EPDM  |
                              USB_OTG_DOEPMSK_STSPHSRXM |
                              USB_OTG_DOEPMSK_NAKM;

      USBx_DEVICE->DIEPMSK |= USB_OTG_DIEPMSK_TOM |
                              USB_OTG_DIEPMSK_XFRCM |
                              USB_OTG_DIEPMSK_EPDM;
      

      /* Set Default Address to 0 */
      USBx_DEVICE->DCFG &= ~USB_OTG_DCFG_DAD;

      /* setup EP0 to receive SETUP packets */
      (void)USB_EP0_OutStart(husbd->Instance, (uint8_t *)husbd->Setup);

      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_USBRST);
    }

    /* Handle Enumeration done Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_ENUMDNE))
    {
      (void)USB_ActivateSetup(husbd->Instance);
      husbd->Init.speed = USB_GetDevSpeed(husbd->Instance);

      /* Set USB Turnaround time */
      (void)USB_SetTurnaroundTime(husbd->Instance);

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
      husbd->ResetCallback(husbd);
#else
      HAL_USBDEV_ResetCallback(husbd);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_ENUMDNE);
    }

    /* Handle RxQLevel Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_RXFLVL))
    {
      USB_MASK_INTERRUPT(husbd->Instance, USB_OTG_GINTSTS_RXFLVL);

      temp = USBx->GRXSTSP;

      ep = &husbd->OUT_ep[temp & USB_OTG_GRXSTSP_EPNUM];

      if (((temp & USB_OTG_GRXSTSP_PKTSTS) >> 17) ==  STS_DATA_UPDT)
      {
        if ((temp & USB_OTG_GRXSTSP_BCNT) != 0U)
        {
          (void)USB_ReadPacket(USBx, ep->xfer_buff,
                               (uint16_t)((temp & USB_OTG_GRXSTSP_BCNT) >> 4));

          ep->xfer_buff += (temp & USB_OTG_GRXSTSP_BCNT) >> 4;
          ep->xfer_count += (temp & USB_OTG_GRXSTSP_BCNT) >> 4;
        }
      }
      else if (((temp & USB_OTG_GRXSTSP_PKTSTS) >> 17) ==  STS_SETUP_UPDT)
      {
        (void)USB_ReadPacket(USBx, (uint8_t *)husbd->Setup, 8U);
        ep->xfer_count += (temp & USB_OTG_GRXSTSP_BCNT) >> 4;
      }
      else
      {
        /* ... */
      }
      USB_UNMASK_INTERRUPT(husbd->Instance, USB_OTG_GINTSTS_RXFLVL);
    }

    /* Handle SOF Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_SOF))
    {
#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
      husbd->SOFCallback(husbd);
#else
      HAL_USBDEV_SOFCallback(husbd);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_SOF);
    }

    /* Handle Incomplete ISO IN Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_IISOIXFR))
    {
      /* Keep application checking the corresponding Iso IN endpoint
      causing the incomplete Interrupt */
      epnum = 0U;

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
      husbd->ISOINIncompleteCallback(husbd, (uint8_t)epnum);
#else
      HAL_USBDEV_ISOINIncompleteCallback(husbd, (uint8_t)epnum);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_IISOIXFR);
    }

    /* Handle Incomplete ISO OUT Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_IPXFR_INCOMPISOOUT))
    {
      /* Keep application checking the corresponding Iso OUT endpoint
      causing the incomplete Interrupt */
      epnum = 0U;

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
      husbd->ISOOUTIncompleteCallback(husbd, (uint8_t)epnum);
#else
      HAL_USBDEV_ISOOUTIncompleteCallback(husbd, (uint8_t)epnum);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_IPXFR_INCOMPISOOUT);
    }

    /* Handle Connection event Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_SRQINT))
    {
#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
      husbd->ConnectCallback(husbd);
#else
      HAL_USBDEV_ConnectCallback(husbd);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

      __HAL_USBDEV_CLEAR_FLAG(husbd, USB_OTG_GINTSTS_SRQINT);
    }

    /* Handle Disconnection event Interrupt */
    if (__HAL_USBDEV_GET_FLAG(husbd, USB_OTG_GINTSTS_OTGINT))
    {
      temp = husbd->Instance->GOTGINT;

      if ((temp & USB_OTG_GOTGINT_SEDET) == USB_OTG_GOTGINT_SEDET)
      {
#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
        husbd->DisconnectCallback(husbd);
#else
        HAL_USBDEV_DisconnectCallback(husbd);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */
      }
      husbd->Instance->GOTGINT |= temp;
    }
  }
}
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */


/**
  * @brief  Data OUT stage callback.
  * @param  husbd USBDEV handle
  * @param  epnum endpoint number
  * @retval None
  */
__weak void HAL_USBDEV_DataOutStageCallback(USBDEV_HandleTypeDef *husbd, uint8_t epnum)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_DataOutStageCallback could be implemented in the user file
   */
}

/**
  * @brief  Data IN stage callback
  * @param  husbd USBDEV handle
  * @param  epnum endpoint number
  * @retval None
  */
__weak void HAL_USBDEV_DataInStageCallback(USBDEV_HandleTypeDef *husbd, uint8_t epnum)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_DataInStageCallback could be implemented in the user file
   */
}
/**
  * @brief  Setup stage callback
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_SetupStageCallback(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_SetupStageCallback could be implemented in the user file
   */
}

/**
  * @brief  USB Start Of Frame callback.
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_SOFCallback(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_SOFCallback could be implemented in the user file
   */
}

/**
  * @brief  USB Reset callback.
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_ResetCallback(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_ResetCallback could be implemented in the user file
   */
}

/**
  * @brief  Suspend event callback.
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_SuspendCallback(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_SuspendCallback could be implemented in the user file
   */
}

/**
  * @brief  Resume event callback.
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_ResumeCallback(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_ResumeCallback could be implemented in the user file
   */
}

/**
  * @brief  Incomplete ISO OUT callback.
  * @param  husbd USBDEV handle
  * @param  epnum endpoint number
  * @retval None
  */
__weak void HAL_USBDEV_ISOOUTIncompleteCallback(USBDEV_HandleTypeDef *husbd, uint8_t epnum)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_ISOOUTIncompleteCallback could be implemented in the user file
   */
}

/**
  * @brief  Incomplete ISO IN callback.
  * @param  husbd USBDEV handle
  * @param  epnum endpoint number
  * @retval None
  */
__weak void HAL_USBDEV_ISOINIncompleteCallback(USBDEV_HandleTypeDef *husbd, uint8_t epnum)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_ISOINIncompleteCallback could be implemented in the user file
   */
}

/**
  * @brief  Connection event callback.
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_ConnectCallback(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_ConnectCallback could be implemented in the user file
   */
}

/**
  * @brief  Disconnection event callback.
  * @param  husbd USBDEV handle
  * @retval None
  */
__weak void HAL_USBDEV_DisconnectCallback(USBDEV_HandleTypeDef *husbd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEV_DisconnectCallback could be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup USBDEV_Exported_Functions_Group3 Peripheral Control functions
 *  @brief   management functions
 *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the USBDEV data
    transfers.

@endverbatim
  * @{
  */

/**
  * @brief  Connect the USB device
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_DevConnect(USBDEV_HandleTypeDef *husbd)
{
  __HAL_LOCK(husbd);
  (void)USB_DevConnect(husbd->Instance);
  __HAL_UNLOCK(husbd);
  return HAL_OK;
}

/**
  * @brief  Disconnect the USB device.
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_DevDisconnect(USBDEV_HandleTypeDef *husbd)
{
  __HAL_LOCK(husbd);
  (void)USB_DevDisconnect(husbd->Instance);
  __HAL_UNLOCK(husbd);
  return HAL_OK;
}

/**
  * @brief  Set the USB Device address.
  * @param  husbd USBDEV handle
  * @param  address new device address
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_SetAddress(USBDEV_HandleTypeDef *husbd, uint8_t address)
{
  __HAL_LOCK(husbd);
  husbd->USB_Address = address;
  (void)USB_SetDevAddress(husbd->Instance, address);
  __HAL_UNLOCK(husbd);
  return HAL_OK;
}
/**
  * @brief  Open and configure an endpoint.
  * @param  husbd USBDEV handle
  * @param  ep_addr endpoint address
  * @param  ep_mps endpoint max packet size
  * @param  ep_type endpoint type
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_EP_Open(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr, uint16_t ep_mps, uint8_t ep_type)
{
  HAL_StatusTypeDef  ret = HAL_OK;
  USBDEV_EPTypeDef *ep;

  if ((ep_addr & 0x80U) == 0x80U)
  {
    ep = &husbd->IN_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 1U;
  }
  else
  {
    ep = &husbd->OUT_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 0U;
  }

  ep->num = ep_addr & EP_ADDR_MSK;
  ep->maxpacket = ep_mps;
  ep->type = ep_type;

  if (ep->is_in != 0U)
  {
    /* Assign a Tx FIFO */
    ep->tx_fifo_num = ep->num;
  }
  /* Set initial data PID. */
  if (ep_type == EP_TYPE_BULK)
  {
    ep->data_pid_start = 0U;
  }

  __HAL_LOCK(husbd);
  (void)USB_ActivateEndpoint(husbd->Instance, ep);
  __HAL_UNLOCK(husbd);

  return ret;
}

/**
  * @brief  Deactivate an endpoint.
  * @param  husbd USBDEV handle
  * @param  ep_addr endpoint address
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_EP_Close(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr)
{
  USBDEV_EPTypeDef *ep;

  if ((ep_addr & 0x80U) == 0x80U)
  {
    ep = &husbd->IN_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 1U;
  }
  else
  {
    ep = &husbd->OUT_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 0U;
  }
  ep->num   = ep_addr & EP_ADDR_MSK;

  __HAL_LOCK(husbd);
  (void)USB_DeactivateEndpoint(husbd->Instance, ep);
  __HAL_UNLOCK(husbd);
  return HAL_OK;
}


/**
  * @brief  Receive an amount of data.
  * @param  husbd USBDEV handle
  * @param  ep_addr endpoint address
  * @param  pBuf pointer to the reception buffer
  * @param  len amount of data to be received
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_EP_Receive(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr, uint8_t *pBuf, uint32_t len)
{
  USBDEV_EPTypeDef *ep;

  ep = &husbd->OUT_ep[ep_addr & EP_ADDR_MSK];

  /*setup and start the Xfer */
  ep->xfer_buff = pBuf;
  ep->xfer_len = len;
  ep->xfer_count = 0U;
  ep->is_in = 0U;
  ep->num = ep_addr & EP_ADDR_MSK;

  if ((ep_addr & EP_ADDR_MSK) == 0U)
  {
    (void)USB_EP0StartXfer(husbd->Instance, ep);
  }
  else
  {
    (void)USB_EPStartXfer(husbd->Instance, ep);
  }

  return HAL_OK;
}

/**
  * @brief  Get Received Data Size
  * @param  husbd USBDEV handle
  * @param  ep_addr endpoint address
  * @retval Data Size
  */
uint32_t HAL_USBDEV_EP_GetRxCount(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr)
{
  return husbd->OUT_ep[ep_addr & EP_ADDR_MSK].xfer_count;
}
/**
  * @brief  Send an amount of data
  * @param  husbd USBDEV handle
  * @param  ep_addr endpoint address
  * @param  pBuf pointer to the transmission buffer
  * @param  len amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_EP_Transmit(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr, uint8_t *pBuf, uint32_t len)
{
  USBDEV_EPTypeDef *ep;

  ep = &husbd->IN_ep[ep_addr & EP_ADDR_MSK];

  /*setup and start the Xfer */
  ep->xfer_buff = pBuf;
  ep->xfer_len = len;
  ep->xfer_count = 0U;
  ep->is_in = 1U;
  ep->num = ep_addr & EP_ADDR_MSK;

  if ((ep_addr & EP_ADDR_MSK) == 0U)
  {
    (void)USB_EP0StartXfer(husbd->Instance, ep);
  }
  else
  {
    (void)USB_EPStartXfer(husbd->Instance, ep);
  }

  return HAL_OK;
}

/**
  * @brief  Set a STALL condition over an endpoint
  * @param  husbd USBDEV handle
  * @param  ep_addr endpoint address
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_EP_SetStall(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr)
{
  USBDEV_EPTypeDef *ep;

  if (((uint32_t)ep_addr & EP_ADDR_MSK) > husbd->Init.dev_endpoints)
  {
    return HAL_ERROR;
  }

  if ((0x80U & ep_addr) == 0x80U)
  {
    ep = &husbd->IN_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 1U;
  }
  else
  {
    ep = &husbd->OUT_ep[ep_addr];
    ep->is_in = 0U;
  }

  ep->is_stall = 1U;
  ep->num = ep_addr & EP_ADDR_MSK;

  __HAL_LOCK(husbd);

  (void)USB_EPSetStall(husbd->Instance, ep);

  if ((ep_addr & EP_ADDR_MSK) == 0U)
  {
    (void)USB_EP0_OutStart(husbd->Instance, (uint8_t *)husbd->Setup);
  }
  __HAL_UNLOCK(husbd);

  return HAL_OK;
}

/**
  * @brief  Clear a STALL condition over in an endpoint
  * @param  husbd USBDEV handle
  * @param  ep_addr endpoint address
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_EP_ClrStall(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr)
{
  USBDEV_EPTypeDef *ep;

  if (((uint32_t)ep_addr & 0x0FU) > husbd->Init.dev_endpoints)
  {
    return HAL_ERROR;
  }

  if ((0x80U & ep_addr) == 0x80U)
  {
    ep = &husbd->IN_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 1U;
  }
  else
  {
    ep = &husbd->OUT_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 0U;
  }

  ep->is_stall = 0U;
  ep->num = ep_addr & EP_ADDR_MSK;

  __HAL_LOCK(husbd);
  (void)USB_EPClearStall(husbd->Instance, ep);
  __HAL_UNLOCK(husbd);

  return HAL_OK;
}

/**
  * @brief  Flush an endpoint
  * @param  husbd USBDEV handle
  * @param  ep_addr endpoint address
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_EP_Flush(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr)
{
  __HAL_LOCK(husbd);

  if ((ep_addr & 0x80U) == 0x80U)
  {
    (void)USB_FlushTxFifo(husbd->Instance, (uint32_t)ep_addr & EP_ADDR_MSK);
  }
  else
  {
    (void)USB_FlushRxFifo(husbd->Instance);
  }

  __HAL_UNLOCK(husbd);

  return HAL_OK;
}

/**
  * @brief  Activate remote wakeup signalling
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_ActivateRemoteWakeup(USBDEV_HandleTypeDef *husbd)
{
  return (USB_ActivateRemoteWakeup(husbd->Instance));
}

/**
  * @brief  De-activate remote wakeup signalling.
  * @param  husbd USBDEV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEV_DeActivateRemoteWakeup(USBDEV_HandleTypeDef *husbd)
{
  return (USB_DeActivateRemoteWakeup(husbd->Instance));
}

/**
  * @}
  */

/** @defgroup USBDEV_Exported_Functions_Group4 Peripheral State functions
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
  * @brief  Return the USBDEV handle state.
  * @param  husbd USBDEV handle
  * @retval HAL state
  */
USBDEV_StateTypeDef HAL_USBDEV_GetState(USBDEV_HandleTypeDef *husbd)
{
  return husbd->State;
}

/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @addtogroup USBDEV_Private_Functions
  * @{
  */
#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
/**
  * @brief  Check FIFO for the next packet to be loaded.
  * @param  husbd USBDEV handle
  * @param  epnum endpoint number
  * @retval HAL status
  */
static HAL_StatusTypeDef USBDEV_WriteEmptyTxFifo(USBDEV_HandleTypeDef *husbd, uint32_t epnum)
{
  USB_OTG_GlobalTypeDef *USBx = husbd->Instance;
  uint32_t USBx_BASE = (uint32_t)USBx;
  USB_OTG_EPTypeDef *ep;
  uint32_t len;
  uint32_t len32b;
  uint32_t fifoemptymsk;

  ep = &husbd->IN_ep[epnum];

  if (ep->xfer_count > ep->xfer_len)
  {
    return HAL_ERROR;
  }

  len = ep->xfer_len - ep->xfer_count;

  if (len > ep->maxpacket)
  {
    len = ep->maxpacket;
  }

  len32b = (len + 3U) / 4U;

  while (((USBx_INEP(epnum)->DTXFSTS & USB_OTG_DTXFSTS_INEPTFSAV) >= len32b) &&
         (ep->xfer_count < ep->xfer_len) && (ep->xfer_len != 0U))
  {
    /* Write the FIFO */
    len = ep->xfer_len - ep->xfer_count;

    if (len > ep->maxpacket)
    {
      len = ep->maxpacket;
    }
    len32b = (len + 3U) / 4U;

    (void)USB_WritePacket(USBx, ep->xfer_buff, (uint8_t)epnum, (uint16_t)len);

    ep->xfer_buff  += len;
    ep->xfer_count += len;
  }

  if (ep->xfer_len <= ep->xfer_count)
  {
    /* All data in fifo, diasble tx fifo empty interrupt for this EP */
    fifoemptymsk = (uint32_t)(0x1UL << (epnum & EP_ADDR_MSK));
    USBx_DEVICE->DIEPEMPMSK &= ~fifoemptymsk;
  }

  return HAL_OK;
}


/**
  * @brief  process EP OUT transfer complete interrupt.
  * @param  husbd USBDEV handle
  * @param  epnum endpoint number
  * @retval HAL status
  */
static HAL_StatusTypeDef USBDEV_EP_OutXfrComplete_int(USBDEV_HandleTypeDef *husbd, uint32_t epnum)
{

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
  husbd->DataOutStageCallback(husbd, (uint8_t)epnum);
#else
  HAL_USBDEV_DataOutStageCallback(husbd, (uint8_t)epnum);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

  return HAL_OK;
}


/**
  * @brief  process EP OUT setup packet received interrupt.
  * @param  husbd USBDEV handle
  * @param  epnum endpoint number
  * @retval HAL status
  */
static HAL_StatusTypeDef USBDEV_EP_OutSetupPacket_int(USBDEV_HandleTypeDef *husbd, uint32_t epnum)
{

  /* Inform the upper layer that a setup packet is available */
#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
  husbd->SetupStageCallback(husbd);
#else
  HAL_USBDEV_SetupStageCallback(husbd);
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

  return HAL_OK;
}
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */


/**
  * @}
  */
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */
#endif /* HAL_USBD_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
