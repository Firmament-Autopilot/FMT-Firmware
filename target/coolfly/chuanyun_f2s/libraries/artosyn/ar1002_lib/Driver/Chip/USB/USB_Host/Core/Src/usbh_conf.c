/**
  ******************************************************************************
  * @file    usb_bsp.c
  * @author  MCD Application Team
  * @version V3.2.2
  * @date    07-July-2015
  * @brief   This file implements the board support package for the USB host library
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "usbh_core.h"
#include "debuglog.h"
#include "stm32f7xx_hal_conf.h"
#include "drv_systick.h"

HCD_HandleTypeDef hhcd[2];

/**
  * @brief  USBH_LL_Init 
  *         Initialize the Low Level portion of the Host driver.
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_LL_Init(USBH_HandleTypeDef *phost)
{
    uint8_t                 usbId;
    HCD_HandleTypeDef      *pHcdHandle;

    usbId               = phost->id;

    if (usbId > 1)
    {
        DLOG_Error("usb ID should not exceed 1!\n");

        return USBH_FAIL;
    }

    pHcdHandle          = &hhcd[usbId];

    if (0 == usbId)
    {
        pHcdHandle->Instance = USB_OTG0_HS;
    }
    else
    {
        pHcdHandle->Instance = USB_OTG1_HS;
    }

    pHcdHandle->Init.Host_channels = 6; 
    pHcdHandle->Init.dma_enable = 1;
    pHcdHandle->Init.low_power_enable = 0;
    pHcdHandle->Init.phy_itface = HCD_PHY_ULPI;
    pHcdHandle->Init.Sof_enable = 0;
    pHcdHandle->Init.speed = HCD_SPEED_HIGH;
    pHcdHandle->Init.vbus_sensing_enable = 1;
    pHcdHandle->Init.use_external_vbus = 1;
    pHcdHandle->Init.lpm_enable = 0;
    
    /* Link the driver to the stack */
    pHcdHandle->pData   = phost;
    phost->pData        = pHcdHandle;
    
    /* Initialize the LL driver */
    HAL_HCD_Init(pHcdHandle, phost->u8_HostMode);

    USBH_LL_SetTimer(phost, HAL_HCD_GetCurrentFrame(pHcdHandle));

    return USBH_OK;
}

/**
  * @brief  USBH_LL_DeInit 
  *         De-Initialize the Low Level portion of the Host driver.
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_LL_DeInit (USBH_HandleTypeDef *phost)
{
  HAL_HCD_DeInit(phost->pData);

  return USBH_OK; 
}

/**
  * @brief  USBH_LL_Start 
  *         Start the Low Level portion of the Host driver.
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_LL_Start(USBH_HandleTypeDef *phost)
{
  HAL_HCD_Start(phost->pData);

  return USBH_OK; 
}

/**
  * @brief  USBH_LL_Stop 
  *         Stop the Low Level portion of the Host driver.
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_LL_Stop (USBH_HandleTypeDef *phost)
{
  HAL_HCD_Stop(phost->pData);

  return USBH_OK; 
}

/**
  * @brief  USBH_LL_GetSpeed 
  *         Return the USB Host Speed from the Low Level Driver.
  * @param  phost: Host handle
  * @retval USBH Speeds
  */
USBH_SpeedTypeDef USBH_LL_GetSpeed  (USBH_HandleTypeDef *phost)
{
  USBH_SpeedTypeDef speed = USBH_SPEED_FULL;
  
  switch (HAL_HCD_GetCurrentSpeed(phost->pData))
  {
  case 0: 
    speed = USBH_SPEED_HIGH;
    break;
    
  case 1: 
    speed = USBH_SPEED_FULL;
    break;
    
  case 2: 
    speed = USBH_SPEED_LOW;
    break;
    
  default:
    speed = USBH_SPEED_FULL;
    break;
  }    

  return  speed;
}

/**
  * @brief  USBH_LL_ResetPort 
  *         Reset the Host Port of the Low Level Driver.
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_LL_ResetPort (USBH_HandleTypeDef *phost) 
{
  HAL_HCD_ResetPort(phost->pData);

  return USBH_OK; 
}

/**
  * @brief  USBH_LL_GetLastXferSize 
  *         Return the last transferred packet size.
  * @param  phost: Host handle
  * @param  pipe: Pipe index   
  * @retval Packet Size
  */
uint32_t USBH_LL_GetLastXferSize  (USBH_HandleTypeDef *phost, uint8_t pipe)  
{
   return HAL_HCD_HC_GetXferCount(phost->pData, pipe);
}

/**
  * @brief  USBH_LL_OpenPipe 
  *         Open a pipe of the Low Level Driver.
  * @param  phost: Host handle
  * @param  pipe_num: Pipe index
  * @param  epnum: Endpoint Number
  * @param  dev_address: Device USB address
  * @param  speed: Device Speed 
  * @param  ep_type: Endpoint Type
  * @param  mps: Endpoint Max Packet Size                 
  * @retval USBH Status
  */
USBH_StatusTypeDef   USBH_LL_OpenPipe (USBH_HandleTypeDef *phost, 
                                      uint8_t pipe_num,
                                      uint8_t epnum,                                      
                                      uint8_t dev_address,
                                      uint8_t speed,
                                      uint8_t ep_type,
                                      uint16_t mps)
{
  HAL_HCD_HC_Init(phost->pData,
                  pipe_num,
                  epnum,
                  dev_address,
                  speed,
                  ep_type,
                  mps);

  return USBH_OK; 
}

/**
  * @brief  USBH_LL_ClosePipe 
  *         Close a pipe of the Low Level Driver.
  * @param  phost: Host handle
  * @param  pipe_num: Pipe index               
  * @retval USBH Status
  */
USBH_StatusTypeDef   USBH_LL_ClosePipe   (USBH_HandleTypeDef *phost, uint8_t pipe)   
{
  HAL_HCD_HC_Halt(phost->pData, pipe);

  return USBH_OK; 
}

/**
  * @brief  USBH_LL_SubmitURB 
  *         Submit a new URB to the low level driver.
  * @param  phost: Host handle
  * @param  pipe: Pipe index    
  *         This parameter can be a value from 1 to 15
  * @param  direction : Channel number
  *          This parameter can be one of the these values:
  *           0 : Output 
  *           1 : Input
  * @param  ep_type : Endpoint Type
  *          This parameter can be one of the these values:
  *            @arg EP_TYPE_CTRL: Control type
  *            @arg EP_TYPE_ISOC: Isochronous type
  *            @arg EP_TYPE_BULK: Bulk type
  *            @arg EP_TYPE_INTR: Interrupt type
  * @param  token : Endpoint Type
  *          This parameter can be one of the these values:
  *            @arg 0: PID_SETUP
  *            @arg 1: PID_DATA
  * @param  pbuff : pointer to URB data
  * @param  length : Length of URB data
  * @param  do_ping : activate do ping protocol (for high speed only)
  *          This parameter can be one of the these values:
  *           0 : do ping inactive 
  *           1 : do ping active 
  * @retval Status
  */

USBH_StatusTypeDef   USBH_LL_SubmitURB  (USBH_HandleTypeDef *phost, 
                                            uint8_t pipe, 
                                            uint8_t direction ,
                                            uint8_t ep_type,  
                                            uint8_t token, 
                                            uint8_t* pbuff, 
                                            uint16_t length,
                                            uint8_t do_ping ) 
{
  HAL_HCD_HC_SubmitRequest(phost->pData,
                           pipe, 
                           direction,
                           ep_type,  
                           token, 
                           pbuff, 
                           length,
                           do_ping);

  return USBH_OK;   
}

/**
  * @brief  USBH_LL_GetURBState 
  *         Get a URB state from the low level driver.
  * @param  phost: Host handle
  * @param  pipe: Pipe index
  *         This parameter can be a value from 1 to 15
  * @retval URB state
  *          This parameter can be one of the these values:
  *            @arg URB_IDLE
  *            @arg URB_DONE
  *            @arg URB_NOTREADY
  *            @arg URB_NYET 
  *            @arg URB_ERROR  
  *            @arg URB_STALL      
  */
USBH_URBStateTypeDef  USBH_LL_GetURBState (USBH_HandleTypeDef *phost, uint8_t pipe) 
{
  return (USBH_URBStateTypeDef)HAL_HCD_HC_GetURBState (phost->pData, pipe);
}

/**
  * @brief  USBH_LL_SetToggle 
  *         Set toggle for a pipe.
  * @param  phost: Host handle
  * @param  pipe: Pipe index
  * @param  pipe_num: Pipe index     
  * @param  toggle: toggle (0/1)
  * @retval Status
  */
USBH_StatusTypeDef   USBH_LL_SetToggle   (USBH_HandleTypeDef *phost, uint8_t pipe, uint8_t toggle)   
{
    uint8_t                 usbId;
    HCD_HandleTypeDef      *pHcdHandle;

    usbId                   = phost->id;
    pHcdHandle              = &hhcd[usbId];

    if(pHcdHandle->hc[pipe].ep_is_in)
    {
        pHcdHandle->hc[pipe].toggle_in  = toggle;
    }
    else
    {
        pHcdHandle->hc[pipe].toggle_out = toggle;
    }

  return USBH_OK; 
}

/**
  * @brief  USBH_LL_GetToggle 
  *         Return the current toggle of a pipe.
  * @param  phost: Host handle
  * @param  pipe: Pipe index
  * @retval toggle (0/1)
  */
uint8_t  USBH_LL_GetToggle   (USBH_HandleTypeDef *phost, uint8_t pipe)   
{
    uint8_t                 toggle;
    uint8_t                 usbId;
    HCD_HandleTypeDef      *pHcdHandle;

    toggle          = 0;
    usbId           = phost->id;
    pHcdHandle      = &hhcd[usbId];

    if(pHcdHandle->hc[pipe].ep_is_in)
    {
        toggle = pHcdHandle->hc[pipe].toggle_in;
    }
    else
    {
        toggle = pHcdHandle->hc[pipe].toggle_out;
    }  

    return toggle; 
}
/**
  * @brief  USBH_Delay 
  *         Delay routine for the USB Host Library
  * @param  Delay: Delay in ms
  * @retval None
  */
void  USBH_Delay (uint32_t Delay)
{
  //SysTicks_DelayMS(Delay);
  ar_osDelay(Delay);
}

void USBH_SetBigEndian(USBH_HandleTypeDef *phost)
{
    if (phost->id == 0)
    {
        USB_OTG_ENDIAN = (USB_OTG_ENDIAN | 0x00000002);
    }
    else if (phost->id == 1)
    {
        USB_OTG_ENDIAN = (USB_OTG_ENDIAN | 0x00000004);
    }

    phost->u8_bigEndianFlag  = 1;

    return;
}

void USBH_SetLittleEndian(USBH_HandleTypeDef *phost)
{
    if (phost->id == 0)
    {
        USB_OTG_ENDIAN = (USB_OTG_ENDIAN & 0xFFFFFFFD);
    }
    else if (phost->id == 1)
    {
        USB_OTG_ENDIAN = (USB_OTG_ENDIAN & 0xFFFFFFFB);
    }

    phost->u8_bigEndianFlag  = 0;

    return;
}

uint8_t USBH_IsBigEndian(USBH_HandleTypeDef *phost)
{
    return phost->u8_bigEndianFlag;
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
