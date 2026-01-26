/**
  ******************************************************************************
  * @file    py32e407_hal_usbh.c
  * @author  MCU Application Team
  * @brief   USBHOST HAL module driver.
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
    (#)Declare a USBHOST_HandleTypeDef handle structure, for example:
       USBHOST_HandleTypeDef  husbh;

    (#)Fill parameters of Init structure in USBHOST handle

    (#)Call HAL_USBHOST_Init() API to initialize the USBHOST peripheral (Core, Host core, ...)

    (#)Initialize the USBHOST low level resources through the HAL_USBHOST_MspInit() API:
        (##) Enable the USBHOST Low Level interface clock using the following macros
             (+++) __HAL_RCC_USB1_CLK_ENABLE();
             (+++) __HAL_RCC_USB2_CLK_ENABLE();
        (##) Initialize the related GPIO clocks
        (##) Configure USBHOST pin-out
        (##) Configure USBHOST NVIC interrupt

    (#)Associate the Upper USB Host stack to the HAL USBHOST Driver:
        (##) husbh.pData = phost;

    (#)Enable USBHOST transmission and reception:
        (##) HAL_USBHOST_Start();

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

#ifdef HAL_USBH_MODULE_ENABLED

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)

/** @defgroup USBHOST USBHOST
  * @brief USBHOST HAL module driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup USBHOST_Private_Functions USBHOST Private Functions
  * @{
  */
static void USBHOST_HC_IN_IRQHandler(USBHOST_HandleTypeDef *husbh, uint8_t chnum);
static void USBHOST_HC_OUT_IRQHandler(USBHOST_HandleTypeDef *husbh, uint8_t chnum);
static void USBHOST_RXQLVL_IRQHandler(USBHOST_HandleTypeDef *husbh);
static void USBHOST_Port_IRQHandler(USBHOST_HandleTypeDef *husbh);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup USBHOST_Exported_Functions USBHOST Exported Functions
  * @{
  */

/** @defgroup USBHOST_Exported_Functions_Group1 Initialization and de-initialization functions
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
  * @brief  Initialize the host driver.
  * @param  husbh USBHOST handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_Init(USBHOST_HandleTypeDef *husbh)
{
  USB_OTG_GlobalTypeDef *USBx;

  /* Check the USBHOST handle allocation */
  if (husbh == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_USBHOST_ALL_INSTANCE(husbh->Instance));

  USBx = husbh->Instance;

  if (husbh->State == HAL_USBHOST_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    husbh->Lock = HAL_UNLOCKED;

#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
    husbh->SOFCallback = HAL_USBHOST_SOF_Callback;
    husbh->ConnectCallback = HAL_USBHOST_Connect_Callback;
    husbh->DisconnectCallback = HAL_USBHOST_Disconnect_Callback;
    husbh->PortEnabledCallback = HAL_USBHOST_PortEnabled_Callback;
    husbh->PortDisabledCallback = HAL_USBHOST_PortDisabled_Callback;
    husbh->HC_NotifyURBChangeCallback = HAL_USBHOST_HC_NotifyURBChange_Callback;

    if (husbh->MspInitCallback == NULL)
    {
      husbh->MspInitCallback = HAL_USBHOST_MspInit;
    }

    /* Init the low level hardware */
    husbh->MspInitCallback(husbh);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC... */
    HAL_USBHOST_MspInit(husbh);
#endif /* (USE_HAL_USBHOST_REGISTER_CALLBACKS) */
  }

  husbh->State = HAL_USBHOST_STATE_BUSY;

  /* Disable DMA mode for FS instance */
  if ((USBx->CID & (0x1U << 8)) == 0U)
  {
    husbh->Init.dma_enable = 0U;
  }

  /* Disable the Interrupts */
  __HAL_USBHOST_DISABLE(husbh);

  /* Init the Core (common init.) */
  (void)USB_CoreInit(husbh->Instance, husbh->Init);

  /* Force Host Mode*/
  (void)USB_SetCurrentMode(husbh->Instance, USB_HOST_MODE);

  /* Init Host */
  (void)USB_HostInit(husbh->Instance, husbh->Init);

  husbh->State = HAL_USBHOST_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Initialize a host channel.
  * @param  husbh USBHOST handle
  * @param  ch_num Channel number.
  *         This parameter can be a value from 1 to 15
  * @param  epnum Endpoint number.
  *          This parameter can be a value from 1 to 15
  * @param  dev_address Current device address
  *          This parameter can be a value from 0 to 255
  * @param  speed Current device speed.
  *          This parameter can be one of these values:
  *            USBHOST_SPEED_FULL: Full speed mode,
  *            USBHOST_SPEED_LOW: Low speed mode
  * @param  ep_type Endpoint Type.
  *          This parameter can be one of these values:
  *            EP_TYPE_CTRL: Control type,
  *            EP_TYPE_ISOC: Isochronous type,
  *            EP_TYPE_BULK: Bulk type,
  *            EP_TYPE_INTR: Interrupt type
  * @param  mps Max Packet Size.
  *          This parameter can be a value from 0 to32K
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_HC_Init(USBHOST_HandleTypeDef *husbh,
                                      uint8_t ch_num,
                                      uint8_t epnum,
                                      uint8_t dev_address,
                                      uint8_t speed,
                                      uint8_t ep_type,
                                      uint16_t mps)
{
  HAL_StatusTypeDef status;

  __HAL_LOCK(husbh);
  husbh->hc[ch_num].do_ping = 0U;
  husbh->hc[ch_num].dev_addr = dev_address;
  husbh->hc[ch_num].max_packet = mps;
  husbh->hc[ch_num].ch_num = ch_num;
  husbh->hc[ch_num].ep_type = ep_type;
  husbh->hc[ch_num].ep_num = epnum & 0x7FU;

  if ((epnum & 0x80U) == 0x80U)
  {
    husbh->hc[ch_num].ep_is_in = 1U;
  }
  else
  {
    husbh->hc[ch_num].ep_is_in = 0U;
  }

  husbh->hc[ch_num].speed = speed;

  status =  USB_HC_Init(husbh->Instance,
                        ch_num,
                        epnum,
                        dev_address,
                        speed,
                        ep_type,
                        mps);
  __HAL_UNLOCK(husbh);

  return status;
}

/**
  * @brief  Halt a host channel.
  * @param  husbh USBHOST handle
  * @param  ch_num Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_HC_Halt(USBHOST_HandleTypeDef *husbh, uint8_t ch_num)
{
  HAL_StatusTypeDef status = HAL_OK;

  __HAL_LOCK(husbh);
  (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
  __HAL_UNLOCK(husbh);

  return status;
}

/**
  * @brief  DeInitialize the host driver.
  * @param  husbh USBHOST handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_DeInit(USBHOST_HandleTypeDef *husbh)
{
  /* Check the USBHOST handle allocation */
  if (husbh == NULL)
  {
    return HAL_ERROR;
  }

  husbh->State = HAL_USBHOST_STATE_BUSY;

#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
  if (husbh->MspDeInitCallback == NULL)
  {
    husbh->MspDeInitCallback = HAL_USBHOST_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware */
  husbh->MspDeInitCallback(husbh);
#else
  /* DeInit the low level hardware: CLOCK, NVIC.*/
  HAL_USBHOST_MspDeInit(husbh);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */

  __HAL_USBHOST_DISABLE(husbh);

  husbh->State = HAL_USBHOST_STATE_RESET;

  return HAL_OK;
}

/**
  * @brief  Initialize the USBHOST MSP.
  * @param  husbh USBHOST handle
  * @retval None
  */
__weak void  HAL_USBHOST_MspInit(USBHOST_HandleTypeDef *husbh)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbh);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBHOST_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the USBHOST MSP.
  * @param  husbh USBHOST handle
  * @retval None
  */
__weak void  HAL_USBHOST_MspDeInit(USBHOST_HandleTypeDef *husbh)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbh);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBHOST_MspDeInit could be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup USBHOST_Exported_Functions_Group2 Input and Output operation functions
  *  @brief   USBHOST IO operation functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
 [..] This subsection provides a set of functions allowing to manage the USB Host Data
    Transfer

@endverbatim
  * @{
  */

/**
  * @brief  Submit a new URB for processing.
  * @param  husbh USBHOST handle
  * @param  ch_num Channel number.
  *         This parameter can be a value from 1 to 15
  * @param  direction Channel number.
  *          This parameter can be one of these values:
  *           0 : Output / 1 : Input
  * @param  ep_type Endpoint Type.
  *          This parameter can be one of these values:
  *            EP_TYPE_CTRL: Control type/
  *            EP_TYPE_ISOC: Isochronous type/
  *            EP_TYPE_BULK: Bulk type/
  *            EP_TYPE_INTR: Interrupt type/
  * @param  token Endpoint Type.
  *          This parameter can be one of these values:
  *            0: HC_PID_SETUP / 1: HC_PID_DATA1
  * @param  pbuff pointer to URB data
  * @param  length Length of URB data
  * @param  do_ping activate do ping protocol (for high speed only).
  *          This parameter can be one of these values:
  *           0 : do ping inactive / 1 : do ping active
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_HC_SubmitRequest(USBHOST_HandleTypeDef *husbh,
                                           uint8_t ch_num,
                                           uint8_t direction,
                                           uint8_t ep_type,
                                           uint8_t token,
                                           uint8_t *pbuff,
                                           uint16_t length,
                                           uint8_t do_ping)
{
  husbh->hc[ch_num].ep_is_in = direction;
  husbh->hc[ch_num].ep_type  = ep_type;

  if (token == 0U)
  {
    husbh->hc[ch_num].data_pid = HC_PID_SETUP;
    husbh->hc[ch_num].do_ping = do_ping;
  }
  else
  {
    husbh->hc[ch_num].data_pid = HC_PID_DATA1;
  }

  /* Manage Data Toggle */
  switch (ep_type)
  {
    case EP_TYPE_CTRL:
      if ((token == 1U) && (direction == 0U)) /*send data */
      {
        if (length == 0U)
        {
          /* For Status OUT stage, Length==0, Status Out PID = 1 */
          husbh->hc[ch_num].toggle_out = 1U;
        }

        /* Set the Data Toggle bit as per the Flag */
        if (husbh->hc[ch_num].toggle_out == 0U)
        {
          /* Put the PID 0 */
          husbh->hc[ch_num].data_pid = HC_PID_DATA0;
        }
        else
        {
          /* Put the PID 1 */
          husbh->hc[ch_num].data_pid = HC_PID_DATA1;
        }
      }
      break;

    case EP_TYPE_BULK:
      if (direction == 0U)
      {
        /* Set the Data Toggle bit as per the Flag */
        if (husbh->hc[ch_num].toggle_out == 0U)
        {
          /* Put the PID 0 */
          husbh->hc[ch_num].data_pid = HC_PID_DATA0;
        }
        else
        {
          /* Put the PID 1 */
          husbh->hc[ch_num].data_pid = HC_PID_DATA1;
        }
      }
      else
      {
        if (husbh->hc[ch_num].toggle_in == 0U)
        {
          husbh->hc[ch_num].data_pid = HC_PID_DATA0;
        }
        else
        {
          husbh->hc[ch_num].data_pid = HC_PID_DATA1;
        }
      }

      break;
    case EP_TYPE_INTR:
      if (direction == 0U)
      {
        /* Set the Data Toggle bit as per the Flag */
        if (husbh->hc[ch_num].toggle_out == 0U)
        {
          /* Put the PID 0 */
          husbh->hc[ch_num].data_pid = HC_PID_DATA0;
        }
        else
        {
          /* Put the PID 1 */
          husbh->hc[ch_num].data_pid = HC_PID_DATA1;
        }
      }
      else
      {
        if (husbh->hc[ch_num].toggle_in == 0U)
        {
          husbh->hc[ch_num].data_pid = HC_PID_DATA0;
        }
        else
        {
          husbh->hc[ch_num].data_pid = HC_PID_DATA1;
        }
      }
      break;

    case EP_TYPE_ISOC:
      husbh->hc[ch_num].data_pid = HC_PID_DATA0;
      break;

    default:
      break;
  }

  husbh->hc[ch_num].xfer_buff = pbuff;
  husbh->hc[ch_num].xfer_len  = length;
  husbh->hc[ch_num].urb_state = URB_IDLE;
  husbh->hc[ch_num].xfer_count = 0U;
  husbh->hc[ch_num].ch_num = ch_num;
  husbh->hc[ch_num].state = HC_IDLE;

  return USB_HC_StartXfer(husbh->Instance, &husbh->hc[ch_num]);
}

/**
  * @brief  Handle USBHOST interrupt request.
  * @param  husbh USBHOST handle
  * @retval None
  */
void HAL_USBHOST_IRQHandler(USBHOST_HandleTypeDef *husbh)
{
  USB_OTG_GlobalTypeDef *USBx = husbh->Instance;
  uint32_t USBx_BASE = (uint32_t)USBx;
  uint32_t i, interrupt;

  /* Ensure that we are in host mode */
  if (USB_GetMode(husbh->Instance) == USB_OTG_MODE_HOST)
  {
    /* Avoid spurious interrupt */
    if (__HAL_USBHOST_IS_INVALID_INTERRUPT(husbh))
    {
      return;
    }

    if (__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_IPXFR_INCOMPISOOUT))
    {
      /* Incorrect mode, acknowledge the interrupt */
      __HAL_USBHOST_CLEAR_FLAG(husbh, USB_OTG_GINTSTS_IPXFR_INCOMPISOOUT);
    }

    if (__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_IISOIXFR))
    {
      /* Incorrect mode, acknowledge the interrupt */
      __HAL_USBHOST_CLEAR_FLAG(husbh, USB_OTG_GINTSTS_IISOIXFR);
    }

    if (__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_PTXFE))
    {
      /* Incorrect mode, acknowledge the interrupt */
      __HAL_USBHOST_CLEAR_FLAG(husbh, USB_OTG_GINTSTS_PTXFE);
    }

    if (__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_MMIS))
    {
      /* Incorrect mode, acknowledge the interrupt */
      __HAL_USBHOST_CLEAR_FLAG(husbh, USB_OTG_GINTSTS_MMIS);
    }

    /* Handle Host Disconnect Interrupts */
    if (__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_DISCINT))
    {
      __HAL_USBHOST_CLEAR_FLAG(husbh, USB_OTG_GINTSTS_DISCINT);

      if ((USBx_HPRT0 & USB_OTG_HPRT_PCSTS) == 0U)
      {
        /* Handle Host Port Disconnect Interrupt */
#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
        husbh->DisconnectCallback(husbh);
#else
        HAL_USBHOST_Disconnect_Callback(husbh);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */

        (void)USB_InitFSLSPClkSel(husbh->Instance, HCFG_48_MHZ);
      }
    }

    /* Handle Host Port Interrupts */
    if (__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_HPRTINT))
    {
      USBHOST_Port_IRQHandler(husbh);
    }

    /* Handle Host SOF Interrupt */
    if (__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_SOF))
    {
#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
      husbh->SOFCallback(husbh);
#else
      HAL_USBHOST_SOF_Callback(husbh);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */

      __HAL_USBHOST_CLEAR_FLAG(husbh, USB_OTG_GINTSTS_SOF);
    }

    /* Handle Host channel Interrupt */
    if (__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_HCINT))
    {
      interrupt = USB_HC_ReadInterrupt(husbh->Instance);
      for (i = 0U; i < husbh->Init.Host_channels; i++)
      {
        if ((interrupt & (1UL << (i & 0xFU))) != 0U)
        {
          if ((USBx_HC(i)->HCCHAR & USB_OTG_HCCHAR_EPDIR) == USB_OTG_HCCHAR_EPDIR)
          {
            USBHOST_HC_IN_IRQHandler(husbh, (uint8_t)i);
          }
          else
          {
            USBHOST_HC_OUT_IRQHandler(husbh, (uint8_t)i);
          }
        }
      }
      __HAL_USBHOST_CLEAR_FLAG(husbh, USB_OTG_GINTSTS_HCINT);
    }

    /* Handle Rx Queue Level Interrupts */
    if ((__HAL_USBHOST_GET_FLAG(husbh, USB_OTG_GINTSTS_RXFLVL)) != 0U)
    {
      USB_MASK_INTERRUPT(husbh->Instance, USB_OTG_GINTSTS_RXFLVL);

      USBHOST_RXQLVL_IRQHandler(husbh);

      USB_UNMASK_INTERRUPT(husbh->Instance, USB_OTG_GINTSTS_RXFLVL);
    }
  }
}

/**
  * @brief  SOF callback.
  * @param  husbh USBHOST handle
  * @retval None
  */
__weak void HAL_USBHOST_SOF_Callback(USBHOST_HandleTypeDef *husbh)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbh);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBHOST_SOF_Callback could be implemented in the user file
   */
}

/**
  * @brief Connection Event callback.
  * @param  husbh USBHOST handle
  * @retval None
  */
__weak void HAL_USBHOST_Connect_Callback(USBHOST_HandleTypeDef *husbh)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbh);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBHOST_Connect_Callback could be implemented in the user file
   */
}

/**
  * @brief  Disconnection Event callback.
  * @param  husbh USBHOST handle
  * @retval None
  */
__weak void HAL_USBHOST_Disconnect_Callback(USBHOST_HandleTypeDef *husbh)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbh);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBHOST_Disconnect_Callback could be implemented in the user file
   */
}

/**
  * @brief  Port Enabled  Event callback.
  * @param  husbh USBHOST handle
  * @retval None
  */
__weak void HAL_USBHOST_PortEnabled_Callback(USBHOST_HandleTypeDef *husbh)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbh);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBHOST_Disconnect_Callback could be implemented in the user file
   */
}

/**
  * @brief  Port Disabled  Event callback.
  * @param  husbh USBHOST handle
  * @retval None
  */
__weak void HAL_USBHOST_PortDisabled_Callback(USBHOST_HandleTypeDef *husbh)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbh);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBHOST_Disconnect_Callback could be implemented in the user file
   */
}

/**
  * @brief  Notify URB state change callback.
  * @param  husbh USBHOST handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @param  urb_state:
  *          This parameter can be one of these values:
  *            URB_IDLE/
  *            URB_DONE/
  *            URB_NOTREADY/
  *            URB_NYET/
  *            URB_ERROR/
  *            URB_STALL/
  * @retval None
  */
__weak void HAL_USBHOST_HC_NotifyURBChange_Callback(USBHOST_HandleTypeDef *husbh, uint8_t chnum, USBHOST_URBStateTypeDef urb_state)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbh);
  UNUSED(chnum);
  UNUSED(urb_state);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBHOST_HC_NotifyURBChange_Callback could be implemented in the user file
   */
}

#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
/**
  * @brief  Register a User USB USBHOST Callback
  *         To be used instead of the weak predefined callback
  * @param  husbh USB USBHOST handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_USBHOST_SOF_CB_ID USB USBHOST SOF callback ID
  *          @arg @ref HAL_USBHOST_CONNECT_CB_ID USB USBHOST Connect callback ID
  *          @arg @ref HAL_USBHOST_DISCONNECT_CB_ID OTG USBHOST Disconnect callback ID
  *          @arg @ref HAL_USBHOST_PORT_ENABLED_CB_ID USB USBHOST Port Enable callback ID
  *          @arg @ref HAL_USBHOST_PORT_DISABLED_CB_ID USB USBHOST Port Disable callback ID
  *          @arg @ref HAL_USBHOST_MSPINIT_CB_ID MspDeInit callback ID
  *          @arg @ref HAL_USBHOST_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_RegisterCallback(USBHOST_HandleTypeDef *husbh, HAL_USBHOST_CallbackIDTypeDef CallbackID, pUSBHOST_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(husbh);

  if (husbh->State == HAL_USBHOST_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_USBHOST_SOF_CB_ID :
        husbh->SOFCallback = pCallback;
        break;

      case HAL_USBHOST_CONNECT_CB_ID :
        husbh->ConnectCallback = pCallback;
        break;

      case HAL_USBHOST_DISCONNECT_CB_ID :
        husbh->DisconnectCallback = pCallback;
        break;

      case HAL_USBHOST_PORT_ENABLED_CB_ID :
        husbh->PortEnabledCallback = pCallback;
        break;

      case HAL_USBHOST_PORT_DISABLED_CB_ID :
        husbh->PortDisabledCallback = pCallback;
        break;

      case HAL_USBHOST_MSPINIT_CB_ID :
        husbh->MspInitCallback = pCallback;
        break;

      case HAL_USBHOST_MSPDEINIT_CB_ID :
        husbh->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (husbh->State == HAL_USBHOST_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_USBHOST_MSPINIT_CB_ID :
        husbh->MspInitCallback = pCallback;
        break;

      case HAL_USBHOST_MSPDEINIT_CB_ID :
        husbh->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbh);
  return status;
}

/**
  * @brief  Unregister an USB USBHOST Callback
  *         USB USBHOST callabck is redirected to the weak predefined callback
  * @param  husbh USB USBHOST handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_USBHOST_SOF_CB_ID USB USBHOST SOF callback ID
  *          @arg @ref HAL_USBHOST_CONNECT_CB_ID USB USBHOST Connect callback ID
  *          @arg @ref HAL_USBHOST_DISCONNECT_CB_ID OTG USBHOST Disconnect callback ID
  *          @arg @ref HAL_USBHOST_PORT_ENABLED_CB_ID USB USBHOST Port Enabled callback ID
  *          @arg @ref HAL_USBHOST_PORT_DISABLED_CB_ID USB USBHOST Port Disabled callback ID
  *          @arg @ref HAL_USBHOST_MSPINIT_CB_ID MspDeInit callback ID
  *          @arg @ref HAL_USBHOST_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_UnRegisterCallback(USBHOST_HandleTypeDef *husbh, HAL_USBHOST_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(husbh);

  /* Setup Legacy weak Callbacks  */
  if (husbh->State == HAL_USBHOST_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_USBHOST_SOF_CB_ID :
        husbh->SOFCallback = HAL_USBHOST_SOF_Callback;
        break;

      case HAL_USBHOST_CONNECT_CB_ID :
        husbh->ConnectCallback = HAL_USBHOST_Connect_Callback;
        break;

      case HAL_USBHOST_DISCONNECT_CB_ID :
        husbh->DisconnectCallback = HAL_USBHOST_Disconnect_Callback;
        break;

      case HAL_USBHOST_PORT_ENABLED_CB_ID :
        husbh->PortEnabledCallback = HAL_USBHOST_PortEnabled_Callback;
        break;

      case HAL_USBHOST_PORT_DISABLED_CB_ID :
        husbh->PortDisabledCallback = HAL_USBHOST_PortDisabled_Callback;
        break;

      case HAL_USBHOST_MSPINIT_CB_ID :
        husbh->MspInitCallback = HAL_USBHOST_MspInit;
        break;

      case HAL_USBHOST_MSPDEINIT_CB_ID :
        husbh->MspDeInitCallback = HAL_USBHOST_MspDeInit;
        break;

      default :
        /* Update the error code */
        husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (husbh->State == HAL_USBHOST_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_USBHOST_MSPINIT_CB_ID :
        husbh->MspInitCallback = HAL_USBHOST_MspInit;
        break;

      case HAL_USBHOST_MSPDEINIT_CB_ID :
        husbh->MspDeInitCallback = HAL_USBHOST_MspDeInit;
        break;

      default :
        /* Update the error code */
        husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbh);
  return status;
}

/**
  * @brief  Register USB USBHOST Host Channel Notify URB Change Callback
  *         To be used instead of the weak HAL_USBHOST_HC_NotifyURBChange_Callback() predefined callback
  * @param  husbh USBHOST handle
  * @param  pCallback pointer to the USB USBHOST Host Channel Notify URB Change Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_RegisterHC_NotifyURBChangeCallback(USBHOST_HandleTypeDef *husbh, pUSBHOST_HC_NotifyURBChangeCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(husbh);

  if (husbh->State == HAL_USBHOST_STATE_READY)
  {
    husbh->HC_NotifyURBChangeCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbh);

  return status;
}

/**
  * @brief  UnRegister the USB USBHOST Host Channel Notify URB Change Callback
  *         USB USBHOST Host Channel Notify URB Change Callback is redirected to the weak HAL_USBHOST_HC_NotifyURBChange_Callback() predefined callback
  * @param  husbh USBHOST handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_UnRegisterHC_NotifyURBChangeCallback(USBHOST_HandleTypeDef *husbh)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(husbh);

  if (husbh->State == HAL_USBHOST_STATE_READY)
  {
    husbh->HC_NotifyURBChangeCallback = HAL_USBHOST_HC_NotifyURBChange_Callback; /* Legacy weak DataOutStageCallback  */
  }
  else
  {
    /* Update the error code */
    husbh->ErrorCode |= HAL_USBHOST_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husbh);

  return status;
}
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup USBHOST_Exported_Functions_Group3 Peripheral Control functions
 *  @brief   Management functions
 *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the USBHOST data
    transfers.

@endverbatim
  * @{
  */

/**
  * @brief  Start the host driver.
  * @param  husbh USBHOST handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_Start(USBHOST_HandleTypeDef *husbh)
{
  __HAL_LOCK(husbh);
  __HAL_USBHOST_ENABLE(husbh);
  (void)USB_DriveVbus(husbh->Instance, 1U);
  __HAL_UNLOCK(husbh);

  return HAL_OK;
}

/**
  * @brief  Stop the host driver.
  * @param  husbh USBHOST handle
  * @retval HAL status
  */

HAL_StatusTypeDef HAL_USBHOST_Stop(USBHOST_HandleTypeDef *husbh)
{
  __HAL_LOCK(husbh);
  (void)USB_StopHost(husbh->Instance);
  __HAL_UNLOCK(husbh);

  return HAL_OK;
}

/**
  * @brief  Reset the host port.
  * @param  husbh USBHOST handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBHOST_ResetPort(USBHOST_HandleTypeDef *husbh)
{
  return (USB_ResetPort(husbh->Instance));
}

/**
  * @}
  */

/** @defgroup USBHOST_Exported_Functions_Group4 Peripheral State functions
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
  * @brief  Return the USBHOST handle state.
  * @param  husbh USBHOST handle
  * @retval HAL state
  */
USBHOST_StateTypeDef HAL_USBHOST_GetState(USBHOST_HandleTypeDef *husbh)
{
  return husbh->State;
}

/**
  * @brief  Return  URB state for a channel.
  * @param  husbh USBHOST handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval URB state.
  *          This parameter can be one of these values:
  *            URB_IDLE/
  *            URB_DONE/
  *            URB_NOTREADY/
  *            URB_NYET/
  *            URB_ERROR/
  *            URB_STALL
  */
USBHOST_URBStateTypeDef HAL_USBHOST_HC_GetURBState(USBHOST_HandleTypeDef *husbh, uint8_t chnum)
{
  return husbh->hc[chnum].urb_state;
}


/**
  * @brief  Return the last host transfer size.
  * @param  husbh USBHOST handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval last transfer size in byte
  */
uint32_t HAL_USBHOST_HC_GetXferCount(USBHOST_HandleTypeDef *husbh, uint8_t chnum)
{
  return husbh->hc[chnum].xfer_count;
}

/**
  * @brief  Return the Host Channel state.
  * @param  husbh USBHOST handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval Host channel state
  *          This parameter can be one of these values:
  *            HC_IDLE/
  *            HC_XFRC/
  *            HC_HALTED/
  *            HC_NYET/
  *            HC_NAK/
  *            HC_STALL/
  *            HC_XACTERR/
  *            HC_BBLERR/
  *            HC_DATATGLERR
  */
USBHOST_HCStateTypeDef  HAL_USBHOST_HC_GetState(USBHOST_HandleTypeDef *husbh, uint8_t chnum)
{
  return husbh->hc[chnum].state;
}

/**
  * @brief  Return the current Host frame number.
  * @param  husbh USBHOST handle
  * @retval Current Host frame number
  */
uint32_t HAL_USBHOST_GetCurrentFrame(USBHOST_HandleTypeDef *husbh)
{
  return (USB_GetCurrentFrame(husbh->Instance));
}

/**
  * @brief  Return the Host enumeration speed.
  * @param  husbh USBHOST handle
  * @retval Enumeration speed
  */
uint32_t HAL_USBHOST_GetCurrentSpeed(USBHOST_HandleTypeDef *husbh)
{
  return (USB_GetHostSpeed(husbh->Instance));
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup USBHOST_Private_Functions
  * @{
  */
/**
  * @brief  Handle Host Channel IN interrupt requests.
  * @param  husbh USBHOST handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval none
  */
static void USBHOST_HC_IN_IRQHandler(USBHOST_HandleTypeDef *husbh, uint8_t chnum)
{
  USB_OTG_GlobalTypeDef *USBx = husbh->Instance;
  uint32_t USBx_BASE = (uint32_t)USBx;
  uint32_t ch_num = (uint32_t)chnum;

  uint32_t tmpreg;

  if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_ACK) == USB_OTG_HCINT_ACK)
  {
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_ACK);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_BBERR) == USB_OTG_HCINT_BBERR)
  {
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    husbh->hc[ch_num].state = HC_BBLERR;
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_BBERR);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_STALL) == USB_OTG_HCINT_STALL)
  {
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    husbh->hc[ch_num].state = HC_STALL;
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_STALL);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_DTERR) == USB_OTG_HCINT_DTERR)
  {
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
    husbh->hc[ch_num].state = HC_DATATGLERR;
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_DTERR);
  }
  else
  {
    /* ... */
  }

  if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_FRMOR) == USB_OTG_HCINT_FRMOR)
  {
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_FRMOR);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_XFRC) == USB_OTG_HCINT_XFRC)
  {
    husbh->hc[ch_num].state = HC_XFRC;
    husbh->hc[ch_num].ErrCnt = 0U;
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_XFRC);

    if ((husbh->hc[ch_num].ep_type == EP_TYPE_CTRL) ||
        (husbh->hc[ch_num].ep_type == EP_TYPE_BULK))
    {
      __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
      (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
      __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
    }
    else if (husbh->hc[ch_num].ep_type == EP_TYPE_INTR)
    {
      USBx_HC(ch_num)->HCCHAR |= USB_OTG_HCCHAR_ODDFRM;
      husbh->hc[ch_num].urb_state = URB_DONE;

#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
      husbh->HC_NotifyURBChangeCallback(husbh, (uint8_t)ch_num, husbh->hc[ch_num].urb_state);
#else
      HAL_USBHOST_HC_NotifyURBChange_Callback(husbh, (uint8_t)ch_num, husbh->hc[ch_num].urb_state);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */
    }
    else if (husbh->hc[ch_num].ep_type == EP_TYPE_ISOC)
    {
      husbh->hc[ch_num].urb_state = URB_DONE;

#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
      husbh->HC_NotifyURBChangeCallback(husbh, (uint8_t)ch_num, husbh->hc[ch_num].urb_state);
#else
      HAL_USBHOST_HC_NotifyURBChange_Callback(husbh, (uint8_t)ch_num, husbh->hc[ch_num].urb_state);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */
    }
    else
    {
      /* ... */
    }
    husbh->hc[ch_num].toggle_in ^= 1U;

  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_CHH) == USB_OTG_HCINT_CHH)
  {
    __HAL_USBHOST_MASK_HALT_HC_INT(ch_num);

    if (husbh->hc[ch_num].state == HC_XFRC)
    {
      husbh->hc[ch_num].urb_state  = URB_DONE;
    }
    else if (husbh->hc[ch_num].state == HC_STALL)
    {
      husbh->hc[ch_num].urb_state  = URB_STALL;
    }
    else if ((husbh->hc[ch_num].state == HC_XACTERR) ||
             (husbh->hc[ch_num].state == HC_DATATGLERR))
    {
      husbh->hc[ch_num].ErrCnt++;
      if (husbh->hc[ch_num].ErrCnt > 3U)
      {
        husbh->hc[ch_num].ErrCnt = 0U;
        husbh->hc[ch_num].urb_state = URB_ERROR;
      }
      else
      {
        husbh->hc[ch_num].urb_state = URB_NOTREADY;
      }

      /* re-activate the channel  */
      tmpreg = USBx_HC(ch_num)->HCCHAR;
      tmpreg &= ~USB_OTG_HCCHAR_CHDIS;
      tmpreg |= USB_OTG_HCCHAR_CHENA;
      USBx_HC(ch_num)->HCCHAR = tmpreg;
    }
    else if (husbh->hc[ch_num].state == HC_NAK)
    {
      husbh->hc[ch_num].urb_state  = URB_NOTREADY;
      /* re-activate the channel  */
      tmpreg = USBx_HC(ch_num)->HCCHAR;
      tmpreg &= ~USB_OTG_HCCHAR_CHDIS;
      tmpreg |= USB_OTG_HCCHAR_CHENA;
      USBx_HC(ch_num)->HCCHAR = tmpreg;
    }
    else
    {
      /* ... */
    }
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_CHH);
    HAL_USBHOST_HC_NotifyURBChange_Callback(husbh, (uint8_t)ch_num, husbh->hc[ch_num].urb_state);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_TXERR) == USB_OTG_HCINT_TXERR)
  {
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    husbh->hc[ch_num].ErrCnt++;
    husbh->hc[ch_num].state = HC_XACTERR;
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_TXERR);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_NAK) == USB_OTG_HCINT_NAK)
  {
    if (husbh->hc[ch_num].ep_type == EP_TYPE_INTR)
    {
      husbh->hc[ch_num].ErrCnt = 0U;
      __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
      (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    }
    else if ((husbh->hc[ch_num].ep_type == EP_TYPE_CTRL) ||
             (husbh->hc[ch_num].ep_type == EP_TYPE_BULK))
    {
      husbh->hc[ch_num].ErrCnt = 0U;
      husbh->hc[ch_num].state = HC_NAK;
      __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
      (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    }
    else
    {
      /* ... */
    }
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
  }
  else
  {
    /* ... */
  }
}

/**
  * @brief  Handle Host Channel OUT interrupt requests.
  * @param  husbh USBHOST handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval none
  */
static void USBHOST_HC_OUT_IRQHandler(USBHOST_HandleTypeDef *husbh, uint8_t chnum)
{
  USB_OTG_GlobalTypeDef *USBx = husbh->Instance;
  uint32_t USBx_BASE = (uint32_t)USBx;
  uint32_t ch_num = (uint32_t)chnum;
  uint32_t tmpreg;

  if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_ACK) == USB_OTG_HCINT_ACK)
  {
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_ACK);

    if (husbh->hc[ch_num].do_ping == 1U)
    {
      husbh->hc[ch_num].do_ping = 0U;
      husbh->hc[ch_num].urb_state  = URB_NOTREADY;
      __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
      (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    }
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_FRMOR) == USB_OTG_HCINT_FRMOR)
  {
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_FRMOR);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_XFRC) == USB_OTG_HCINT_XFRC)
  {
    husbh->hc[ch_num].ErrCnt = 0U;
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_XFRC);
    husbh->hc[ch_num].state = HC_XFRC;
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_STALL) == USB_OTG_HCINT_STALL)
  {
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_STALL);
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    husbh->hc[ch_num].state = HC_STALL;
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_NAK) == USB_OTG_HCINT_NAK)
  {
    husbh->hc[ch_num].ErrCnt = 0U;
    husbh->hc[ch_num].state = HC_NAK;

    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_TXERR) == USB_OTG_HCINT_TXERR)
  {
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    husbh->hc[ch_num].state = HC_XACTERR;
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_TXERR);
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_DTERR) == USB_OTG_HCINT_DTERR)
  {
    __HAL_USBHOST_UNMASK_HALT_HC_INT(ch_num);
    (void)USB_HC_Halt(husbh->Instance, (uint8_t)ch_num);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_DTERR);
    husbh->hc[ch_num].state = HC_DATATGLERR;
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_CHH) == USB_OTG_HCINT_CHH)
  {
    __HAL_USBHOST_MASK_HALT_HC_INT(ch_num);

    if (husbh->hc[ch_num].state == HC_XFRC)
    {
      husbh->hc[ch_num].urb_state  = URB_DONE;
      if ((husbh->hc[ch_num].ep_type == EP_TYPE_BULK) ||
          (husbh->hc[ch_num].ep_type == EP_TYPE_INTR))
      {
        husbh->hc[ch_num].toggle_out ^= 1U;
      }
    }
    else if (husbh->hc[ch_num].state == HC_NAK)
    {
      husbh->hc[ch_num].urb_state = URB_NOTREADY;
    }
    else if (husbh->hc[ch_num].state == HC_NYET)
    {
      husbh->hc[ch_num].urb_state  = URB_NOTREADY;
    }
    else if (husbh->hc[ch_num].state == HC_STALL)
    {
      husbh->hc[ch_num].urb_state  = URB_STALL;
    }
    else if ((husbh->hc[ch_num].state == HC_XACTERR) ||
             (husbh->hc[ch_num].state == HC_DATATGLERR))
    {
      husbh->hc[ch_num].ErrCnt++;
      if (husbh->hc[ch_num].ErrCnt > 3U)
      {
        husbh->hc[ch_num].ErrCnt = 0U;
        husbh->hc[ch_num].urb_state = URB_ERROR;
      }
      else
      {
        husbh->hc[ch_num].urb_state = URB_NOTREADY;
      }

      /* re-activate the channel  */
      tmpreg = USBx_HC(ch_num)->HCCHAR;
      tmpreg &= ~USB_OTG_HCCHAR_CHDIS;
      tmpreg |= USB_OTG_HCCHAR_CHENA;
      USBx_HC(ch_num)->HCCHAR = tmpreg;
    }
    else
    {
      /* ... */
    }

    __HAL_USBHOST_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_CHH);
    HAL_USBHOST_HC_NotifyURBChange_Callback(husbh, (uint8_t)ch_num, husbh->hc[ch_num].urb_state);
  }
  else
  {
    /* ... */
  }
}

/**
  * @brief  Handle Rx Queue Level interrupt requests.
  * @param  husbh USBHOST handle
  * @retval none
  */
static void USBHOST_RXQLVL_IRQHandler(USBHOST_HandleTypeDef *husbh)
{
  USB_OTG_GlobalTypeDef *USBx = husbh->Instance;
  uint32_t USBx_BASE = (uint32_t)USBx;
  uint32_t pktsts;
  uint32_t pktcnt;
  uint32_t temp;
  uint32_t tmpreg;
  uint32_t ch_num;

  temp = husbh->Instance->GRXSTSP;
  ch_num = temp & USB_OTG_GRXSTSP_EPNUM;
  pktsts = (temp & USB_OTG_GRXSTSP_PKTSTS) >> 17;
  pktcnt = (temp & USB_OTG_GRXSTSP_BCNT) >> 4;

  switch (pktsts)
  {
    case GRXSTS_PKTSTS_IN:
      /* Read the data into the host buffer. */
      if ((pktcnt > 0U) && (husbh->hc[ch_num].xfer_buff != (void *)0))
      {
        (void)USB_ReadPacket(husbh->Instance, husbh->hc[ch_num].xfer_buff, (uint16_t)pktcnt);

        /*manage multiple Xfer */
        husbh->hc[ch_num].xfer_buff += pktcnt;
        husbh->hc[ch_num].xfer_count  += pktcnt;

        if ((USBx_HC(ch_num)->HCTSIZ & USB_OTG_HCTSIZ_PKTCNT) > 0U)
        {
          /* re-activate the channel when more packets are expected */
          tmpreg = USBx_HC(ch_num)->HCCHAR;
          tmpreg &= ~USB_OTG_HCCHAR_CHDIS;
          tmpreg |= USB_OTG_HCCHAR_CHENA;
          USBx_HC(ch_num)->HCCHAR = tmpreg;
          husbh->hc[ch_num].toggle_in ^= 1U;
        }
      }
      break;

    case GRXSTS_PKTSTS_DATA_TOGGLE_ERR:
      break;

    case GRXSTS_PKTSTS_IN_XFER_COMP:
    case GRXSTS_PKTSTS_CH_HALTED:
    default:
      break;
  }
}

/**
  * @brief  Handle Host Port interrupt requests.
  * @param  husbh USBHOST handle
  * @retval None
  */
static void USBHOST_Port_IRQHandler(USBHOST_HandleTypeDef *husbh)
{
  USB_OTG_GlobalTypeDef *USBx = husbh->Instance;
  uint32_t USBx_BASE = (uint32_t)USBx;
  __IO uint32_t hprt0, hprt0_dup;

  /* Handle Host Port Interrupts */
  hprt0 = USBx_HPRT0;
  hprt0_dup = USBx_HPRT0;

  hprt0_dup &= ~(USB_OTG_HPRT_PENA | USB_OTG_HPRT_PCDET | \
                 USB_OTG_HPRT_PENCHNG);

  /* Check whether Port Connect detected */
  if ((hprt0 & USB_OTG_HPRT_PCDET) == USB_OTG_HPRT_PCDET)
  {
    if ((hprt0 & USB_OTG_HPRT_PCSTS) == USB_OTG_HPRT_PCSTS)
    {
#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
      husbh->ConnectCallback(husbh);
#else
      HAL_USBHOST_Connect_Callback(husbh);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */
    }
    hprt0_dup  |= USB_OTG_HPRT_PCDET;
  }

  /* Check whether Port Enable Changed */
  if ((hprt0 & USB_OTG_HPRT_PENCHNG) == USB_OTG_HPRT_PENCHNG)
  {
    hprt0_dup |= USB_OTG_HPRT_PENCHNG;

    if ((hprt0 & USB_OTG_HPRT_PENA) == USB_OTG_HPRT_PENA)
    {
      if ((hprt0 & USB_OTG_HPRT_PSPD) == (HPRT0_PRTSPD_LOW_SPEED << 17))
      {
        (void)USB_InitFSLSPClkSel(husbh->Instance, HCFG_6_MHZ);
      }
      else
      {
        (void)USB_InitFSLSPClkSel(husbh->Instance, HCFG_48_MHZ);
      }
      
#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
      husbh->PortEnabledCallback(husbh);
#else
      HAL_USBHOST_PortEnabled_Callback(husbh);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */

    }
    else
    {
#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
      husbh->PortDisabledCallback(husbh);
#else
      HAL_USBHOST_PortDisabled_Callback(husbh);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */
    }
  }

  /* Clear Port Interrupts */
  USBx_HPRT0 = hprt0_dup;
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */
#endif /* HAL_USBH_MODULE_ENABLED */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
