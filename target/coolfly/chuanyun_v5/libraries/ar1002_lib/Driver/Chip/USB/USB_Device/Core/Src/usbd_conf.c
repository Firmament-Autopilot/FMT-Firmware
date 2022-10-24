/**
  ******************************************************************************
  * @file    usbd_conf_template.c
  * @author  MCD Application Team
  * @version V2.4.2
  * @date    11-December-2015
  * @brief   USB Device configuration and interface file
  *          This template should be copied to the user folder, renamed and customized
  *          following user needs.  
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
#include "usbd_core.h"
#include "debuglog.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

PCD_HandleTypeDef hpcd[2];



/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Initializes the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Init(USBD_HandleTypeDef *pdev)
{
    uint8_t                 usbId = 0;
    PCD_HandleTypeDef      *pPcdHandle;

    usbId               = pdev->id;

    if (usbId > 1)
    {
        DLOG_Error("usbId should not exceed 1!\n");

        return USBD_FAIL;
    }

    pPcdHandle          = &hpcd[usbId];

    if (0 == usbId)
    {
        pPcdHandle->Instance = USB_OTG0_HS;
    }
    else
    {
        pPcdHandle->Instance = USB_OTG1_HS;
    }

    pPcdHandle->Init.dev_endpoints = 6;
    pPcdHandle->Init.use_dedicated_ep1 = 0;
    pPcdHandle->Init.ep0_mps = 0x40;
    pPcdHandle->Init.dma_enable = 1;
    pPcdHandle->Init.low_power_enable = 0;
    pPcdHandle->Init.lpm_enable = 0;
    pPcdHandle->Init.phy_itface = PCD_PHY_ULPI;
    pPcdHandle->Init.Sof_enable = 0;
    pPcdHandle->Init.speed = PCD_SPEED_HIGH;
    pPcdHandle->Init.vbus_sensing_enable = 1;
    pPcdHandle->Init.use_external_vbus = 1;
    pPcdHandle->pData = pdev;
    pdev->pData = pPcdHandle;

    pdev->u8_connState = 0;
    
    /* Initialize LL Driver */
    HAL_PCD_Init(pPcdHandle, pdev->u8_DeviceMode);

    HAL_PCDEx_SetRxFiFo(pPcdHandle, 0x200);
    HAL_PCDEx_SetTxFiFo(pPcdHandle, 0, 0x80);
    HAL_PCDEx_SetTxFiFo(pPcdHandle, 1, 0x174);

    /* set little endian */
    USB_OTG_SetLittleEndian(pdev);

    return USBD_OK;
}

/**
  * @brief  De-Initializes the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_DeInit(USBD_HandleTypeDef *pdev)
{
  HAL_PCD_DeInit(pdev->pData);

  return USBD_OK;
}

/**
  * @brief  Starts the Low Level portion of the Device driver. 
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Start(USBD_HandleTypeDef *pdev)
{
  HAL_PCD_Start(pdev->pData);

  return USBD_OK;
}

/**
  * @brief  Stops the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Stop(USBD_HandleTypeDef *pdev)
{
  HAL_PCD_Stop(pdev->pData);

  return USBD_OK;
}

/**
  * @brief  Opens an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  ep_type: Endpoint Type
  * @param  ep_mps: Endpoint Max Packet Size
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_OpenEP(USBD_HandleTypeDef *pdev,
                                  uint8_t ep_addr,
                                  uint8_t ep_type,
                                  uint16_t ep_mps)
{
  HAL_PCD_EP_Open(pdev->pData,
                  ep_addr,
                  ep_mps,
                  ep_type);
  
  return USBD_OK;
}

/**
  * @brief  Closes an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_CloseEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
  HAL_PCD_EP_Close(pdev->pData, ep_addr);

  return USBD_OK;
}

/**
  * @brief  Flushes an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_FlushEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
  HAL_PCD_EP_Flush(pdev->pData, ep_addr);

  return USBD_OK;
}

/**
  * @brief  Sets a Stall condition on an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_StallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
  HAL_PCD_EP_SetStall(pdev->pData, ep_addr);

  return USBD_OK;
}

/**
  * @brief  Clears a Stall condition on an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_ClearStallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
  HAL_PCD_EP_ClrStall(pdev->pData, ep_addr);

  return USBD_OK; 
}

/**
  * @brief  Returns Stall condition.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval Stall (1: Yes, 0: No)
  */
uint8_t USBD_LL_IsStallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
  PCD_HandleTypeDef *hpcd = pdev->pData;
  
  if((ep_addr & 0x80) == 0x80)
  {
    return hpcd->IN_ep[ep_addr & 0x7F].is_stall;
  }
  else
  {
    return hpcd->OUT_ep[ep_addr & 0x7F].is_stall;
  }
}

/**
  * @brief  Assigns a USB address to the device.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_SetUSBAddress(USBD_HandleTypeDef *pdev, uint8_t dev_addr)
{
  HAL_PCD_SetAddress(pdev->pData, dev_addr);

  return USBD_OK; 
}

/**
  * @brief  Transmits data over an endpoint.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  pbuf: Pointer to data to be sent
  * @param  size: Data size    
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Transmit(USBD_HandleTypeDef *pdev, 
                                    uint8_t ep_addr,
                                    uint8_t *pbuf,
                                    uint16_t size)
{
  if (HAL_USB_OK != HAL_PCD_EP_Transmit(pdev->pData, ep_addr, pbuf, size))
  {
    return USBD_BUSY;
  }

  return USBD_OK;
}

/**
  * @brief  Prepares an endpoint for reception.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  pbuf: Pointer to data to be received
  * @param  size: Data size
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_PrepareReceive(USBD_HandleTypeDef *pdev, 
                                          uint8_t ep_addr,
                                          uint8_t *pbuf,
                                          uint16_t size)
{
  HAL_PCD_EP_Receive(pdev->pData, ep_addr, pbuf, size);

  return USBD_OK;
}

/**
  * @brief  Returns the last transferred packet size.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval Recived Data Size
  */
uint32_t USBD_LL_GetRxDataSize(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
  return HAL_PCD_EP_GetRxCount(pdev->pData, ep_addr);
}


void USBD_LL_EnterTestMode(USBD_HandleTypeDef *pdev)
{
  return HAL_PCD_EnterTestMode(pdev->pData, pdev->dev_test_mode);
}


void USB_OTG_SetBigEndian(USBD_HandleTypeDef *pdev)
{
    if (pdev->id == 0)
    {
        USB_OTG_ENDIAN = (USB_OTG_ENDIAN | 0x00000002);
    }
    else if (pdev->id == 1)
    {
        USB_OTG_ENDIAN = (USB_OTG_ENDIAN | 0x00000004);
    }

    pdev->u8_bigEndianFlag  = 1;

    return;
}


void USB_OTG_SetLittleEndian(USBD_HandleTypeDef *pdev)
{
    if (pdev->id == 0)
    {
        USB_OTG_ENDIAN = (USB_OTG_ENDIAN & 0xFFFFFFFD);
    }
    else if (pdev->id == 1)
    {
        USB_OTG_ENDIAN = (USB_OTG_ENDIAN & 0xFFFFFFFB);
    }

    pdev->u8_bigEndianFlag  = 0;

    return;
}


uint8_t USB_OTG_IsBigEndian(USBD_HandleTypeDef *pdev)
{
    return pdev->u8_bigEndianFlag;
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

