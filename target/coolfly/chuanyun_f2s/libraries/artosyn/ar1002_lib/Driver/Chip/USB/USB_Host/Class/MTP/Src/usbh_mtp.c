/**
  ******************************************************************************
  * @file    usbh_mtp.c
  * @author  MCD Application Team
  * @version V3.2.2
  * @date    07-July-2015
  * @brief   This file is the MTP Layer Handlers for USB Host MTP class.
  *
  * @verbatim
  *
  *          ===================================================================
  *                                MTP Class  Description
  *          ===================================================================
  *           This module manages the MTP class following the
  *           "Media Transfer Protocol (MTP) specification Version 1.11 April 6th, 2011".
  *           the implmentation is compatible with the PTP model as an extension
  *           of the existing Picture Transfer Protocol defined by the ISO 15740 specification
  *
  *  @endverbatim
  *
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
#include "usbh_mtp.h"
#include "debuglog.h"
#include "drv_systick.h"
// #include "sram_ground.h"
// #include "cmsis_os.h"
// #include "task.h"
#include "sys_event.h"


/** @addtogroup USBH_LIB
* @{
*/

/** @addtogroup USBH_CLASS
* @{
*/

/** @addtogroup USBH_MTP_CLASS
* @{
*/

/** @defgroup USBH_MTP_CORE
* @brief    This file includes MTP Layer Handlers for USB Host MTP class.
* @{
*/

/** @defgroup USBH_MTP_CORE_Private_TypesDefinitions
* @{
*/
/**
* @}
*/


/** @defgroup USBH_MTP_CORE_Private_Defines
* @{
*/
/**
* @}
*/


/** @defgroup USBH_MTP_CORE_Private_Macros
* @{
*/
/**
* @}
*/


/** @defgroup USBH_MTP_CORE_Private_Variables
* @{
*/
/**
* @}
*/


/** @defgroup USBH_MTP_CORE_Private_FunctionPrototypes
* @{
*/

static USBH_StatusTypeDef USBH_MTP_InterfaceInit  (USBH_HandleTypeDef *phost);

static USBH_StatusTypeDef USBH_MTP_InterfaceDeInit  (USBH_HandleTypeDef *phost);

static USBH_StatusTypeDef USBH_MTP_Process(USBH_HandleTypeDef *phost);

static USBH_StatusTypeDef USBH_MTP_ClassRequest (USBH_HandleTypeDef *phost);

static uint8_t MTP_FindCtlEndpoint(USBH_HandleTypeDef *phost, uint8_t interface);

static uint8_t MTP_FindDataOutEndpoint(USBH_HandleTypeDef *phost, uint8_t interface);

static uint8_t MTP_FindDataInEndpoint(USBH_HandleTypeDef *phost, uint8_t interface);

static USBH_StatusTypeDef USBH_MTP_SOFProcess (USBH_HandleTypeDef *phost);

static USBH_StatusTypeDef USBH_MTP_Events (USBH_HandleTypeDef *phost);

static void MTP_DecodeEvent (USBH_HandleTypeDef *phost);

static void USBH_SetPrtSusp(USBH_HandleTypeDef *phost);


extern void SRAM_Ready0Confirm(void);
extern void SRAM_Ready1Confirm(void);
extern volatile uint32_t sramReady0;
extern volatile uint32_t sramReady1;

USB_ROLE_TypeDef g_usb_role =
{
	.e_usbPort = HAL_USB_PORT_NUM,
	.dev_type  = USB_DEVICE_UNKNOWN
};

static ENUM_USB_DEVICE_TYPE USBH_CheckDeviceType(void);

extern uint8_t usb_dev_info[];

extern uint8_t g_u8CurrentHost;

static int exec_time = 0;

#define USB_OTG1_HPRT_REG_ADDR      ((uint32_t)0x43100440)
#define TO4TIMES(value) ((((value) + 3) / 4)*4)

USBH_ClassTypeDef  MTP_Class =
{
  "MTP",
  USB_MTP_CLASS,
  USBH_MTP_InterfaceInit,
  USBH_MTP_InterfaceDeInit,
  USBH_MTP_ClassRequest,
  USBH_MTP_Process,
  USBH_MTP_SOFProcess,
  NULL,
};
/**
* @}
*/
#define                     ACC_STRING_SIZE             256
#define                     MAX_PACKET_SIZE             512
#define                     DATA_BUF_DEPTH              20

uint8_t                     buffer_mtp_recv[512];
volatile uint8_t            send_mtp                    = 0;
volatile uint8_t            mtp_send_video_enable       = 1;
volatile uint8_t            receive_mtp                 = 0;
volatile uint8_t            g_mtp_enable                = 0;
MTP_HandleTypeDef           g_stMTPHandle;
uint8_t                   * g_mtp_video_buffer[2];
volatile uint32_t           g_mtp_video_size[2];
extern volatile uint32_t    sramReady0;
extern volatile uint32_t    sramReady1;

uint8_t                     g_mtpSendBuffer[DATA_BUF_DEPTH + 1][MAX_PACKET_SIZE];   // add one for osd data
uint32_t                    g_mtpSendSize[DATA_BUF_DEPTH + 1];                      // add one for osd data len
volatile uint8_t            g_mtpSendRdIndex            = 0;
volatile uint8_t            g_mtpSendWrIndex            = 0;

volatile uint8_t            g_mtp_send_lock             = 0;
volatile uint8_t            g_mtp_recv_enable           = 0;

void set_mtp_video_enable(uint8_t enable)
{
	if (enable == 0)
		mtp_send_video_enable = 0;
	else
		mtp_send_video_enable = 1;
}

/** @defgroup USBH_MTP_CORE_Private_Functions
* @{
*/

/**
  * @brief  USBH_MTP_InterfaceInit
  *         The function init the MTP class.
  * @param  phost: Host handle
  * @retval USBH Status
  */
static USBH_StatusTypeDef USBH_MTP_InterfaceInit (USBH_HandleTypeDef *phost)
{
  USBH_StatusTypeDef status = USBH_OK ;
  uint8_t interface, endpoint;

  MTP_HandleTypeDef *MTP_Handle;

  g_usb_role.e_usbPort = phost->id;
  g_usb_role.dev_type = USBH_CheckDeviceType();

  if(g_usb_role.dev_type == USB_APPLE_DEVICE)
    return status;

  interface = USBH_FindInterface(phost,
                                 0xFF,
                                 0xFF,
                                 0);

  if(interface == 0xFF) /* No Valid Interface */
  {
    status = USBH_FAIL;
    DLOG_Error("Cannot Find the interface for Still Image Class.");
  }
  else
  {
    USBH_SelectInterface (phost, interface);

    DLOG_Critical("interface num: %d ", interface);

    endpoint = MTP_FindCtlEndpoint(phost, interface);

    if (endpoint < USBH_MAX_NUM_ENDPOINTS)
    {
      phost->pActiveClass->pData = &g_stMTPHandle;
      MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

      /*Collect the control endpoint address and length*/
      MTP_Handle->NotificationEp = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[endpoint].bEndpointAddress;
      MTP_Handle->NotificationEpSize  = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[endpoint].wMaxPacketSize;
      MTP_Handle->NotificationPipe = USBH_AllocPipe(phost, MTP_Handle->NotificationEp);
      MTP_Handle->events.poll = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[endpoint].bInterval;

      /* Open pipe for Notification endpoint */
      USBH_OpenPipe  (phost,
                      MTP_Handle->NotificationPipe,
                      MTP_Handle->NotificationEp,
                      phost->device.address,
                      phost->device.speed,
                      USB_EP_TYPE_INTR,
                      MTP_Handle->NotificationEpSize);
      DLOG_Critical("Notify ep: %02x, size: %d, pipe: %d", MTP_Handle->NotificationEp, MTP_Handle->NotificationEpSize, MTP_Handle->NotificationPipe);
      USBH_LL_SetToggle (phost, MTP_Handle->NotificationPipe, 0);
    }
    else
    {
        phost->pActiveClass->pData = &g_stMTPHandle;
        MTP_Handle->NotificationPipe = 0;
    }

    endpoint = MTP_FindDataInEndpoint(phost, interface);

    if (endpoint < USBH_MAX_NUM_ENDPOINTS)
    {
      /*Collect the control endpoint address and length*/
      MTP_Handle->DataInEp = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[endpoint].bEndpointAddress;
      MTP_Handle->DataInEpSize  = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[endpoint].wMaxPacketSize;
      MTP_Handle->DataInPipe = USBH_AllocPipe(phost, MTP_Handle->DataInEp);

      /* Open pipe for DATA IN endpoint */
      USBH_OpenPipe  (phost,
                      MTP_Handle->DataInPipe,
                      MTP_Handle->DataInEp,
                      phost->device.address,
                      phost->device.speed,
                      USB_EP_TYPE_BULK,
                      MTP_Handle->DataInEpSize);

      DLOG_Critical("Data in ep: %02x, size: %d, pipe: %d", MTP_Handle->DataInEp, MTP_Handle->DataInEpSize, MTP_Handle->DataInPipe);
      USBH_LL_SetToggle (phost, MTP_Handle->DataInPipe, 0);
    }

    endpoint = MTP_FindDataOutEndpoint(phost, interface);

    if (endpoint < USBH_MAX_NUM_ENDPOINTS)
    {
      /*Collect the DATA OUT endpoint address and length*/
      MTP_Handle->DataOutEp = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[endpoint].bEndpointAddress;
      MTP_Handle->DataOutEpSize  = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[endpoint].wMaxPacketSize;
      MTP_Handle->DataOutPipe = USBH_AllocPipe(phost, MTP_Handle->DataOutEp);

      /* Open pipe for DATA OUT endpoint */
      USBH_OpenPipe  (phost,
                      MTP_Handle->DataOutPipe,
                      MTP_Handle->DataOutEp,
                      phost->device.address,
                      phost->device.speed,
                      USB_EP_TYPE_BULK,
                      MTP_Handle->DataOutEpSize);

      DLOG_Critical("Data out ep: %02x, size: %d, pipe: %d", MTP_Handle->DataOutEp, MTP_Handle->DataOutEpSize, MTP_Handle->DataOutPipe);
      USBH_LL_SetToggle (phost, MTP_Handle->DataOutPipe, 0);
    }
  }

  MTP_Handle->mtp_send_timeout = 0;
  MTP_Handle->mtp_send_timeout_times = 0;
  MTP_Handle->mtp_send_size = 0;
  MTP_Handle->mtp_send_total_size = 0;

  send_mtp = 0;
  receive_mtp = 0;
  g_mtp_enable = 0;
  g_mtp_video_buffer[0] = NULL;
  g_mtp_video_size[0] = 0;
  g_mtp_video_buffer[1] = NULL;
  g_mtp_video_size[1] = 0;

  if (sramReady0)
  {
    SRAM_Ready0Confirm();
  }

  if (sramReady1)
  {
    SRAM_Ready1Confirm();
  }

  USBH_SetLittleEndian(phost);

  g_mtpSendRdIndex = 0;
  g_mtpSendWrIndex = 0;

  MTP_Handle->state = MTP_IDLE;

  phost->recvCallback[MTP_Handle->DataInPipe] = USBH_MTP_RecvData;

  return status;
}

/**
  * @brief  Find MTP Ctl interface
  * @param  phost: Host handle
  * @retval USBH Status
  */
static uint8_t MTP_FindCtlEndpoint(USBH_HandleTypeDef *phost, uint8_t interface)
{
  uint8_t i;

  for (i = 0; i < USBH_MAX_NUM_ENDPOINTS; i++ )
  {
    if((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress & 0x80)&&
       (phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].wMaxPacketSize > 0)&&
      ((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bmAttributes & USBH_EP_INTERRUPT) == USBH_EP_INTERRUPT))
    {
      return i;
    }
  }

  return 0xFF; /* Invalid Endpoint */
}


/**
  * @brief  Find MTP DATA OUT interface
  * @param  phost: Host handle
  * @retval USBH Status
  */
static uint8_t MTP_FindDataOutEndpoint(USBH_HandleTypeDef *phost, uint8_t interface)
{
  uint8_t i;

  for (i = 0; i < USBH_MAX_NUM_ENDPOINTS; i++ )
  {
    if(((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress & 0x80) == 0)&&
        (phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].wMaxPacketSize > 0)&&
       ((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bmAttributes & USBH_EP_BULK) == USBH_EP_BULK))
    {
      return i;
    }
  }

  return 0xFF; /* Invalid Endpoint */
}

/**
  * @brief  Find MTP DATA IN interface
  * @param  phost: Host handle
  * @retval USBH Status
  */
static uint8_t MTP_FindDataInEndpoint(USBH_HandleTypeDef *phost, uint8_t interface)
{
  uint8_t i;

  for (i = 0; i < USBH_MAX_NUM_ENDPOINTS; i++)
  {
    if((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress & 0x80)&&
       (phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].wMaxPacketSize > 0)&&
       ((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bmAttributes & USBH_EP_BULK) == USBH_EP_BULK))
    {
      return i;
    }
  }

  return 0xFF; /* Invalid Endpoint */
}


/**
  * @brief  USBH_MTP_InterfaceDeInit
  *         The function DeInit the Pipes used for the MTP class.
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_InterfaceDeInit (USBH_HandleTypeDef *phost)
{
  if(g_usb_role.dev_type == USB_APPLE_DEVICE)
    return USBH_OK;


  if (phost->device.DevDesc.idVendor == 0x18D1)       //Android AOA vendor ID
  {
    STRU_SysEvent_USB_PlugEvent st_usb_plug;
    st_usb_plug.plug_event = 0;
    st_usb_plug.usb_port_id = phost->id;
    st_usb_plug.dev_type = USB_ANDROID_DEVICE;

    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USB_PLUG_EVENT, (void *)&st_usb_plug);
  }


  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

  DLOG_Critical("DeInit =========================");

  if (MTP_Handle->DataOutPipe)
  {
    USBH_ClosePipe(phost, MTP_Handle->DataOutPipe);
    USBH_FreePipe(phost, MTP_Handle->DataOutPipe);
    MTP_Handle->DataOutPipe = 0;     /* Reset the Channel as Free */
  }

  if (MTP_Handle->DataInPipe)
  {
    USBH_ClosePipe(phost, MTP_Handle->DataInPipe);
    USBH_FreePipe(phost, MTP_Handle->DataInPipe);
    MTP_Handle->DataInPipe = 0;     /* Reset the Channel as Free */
  }

  if (MTP_Handle->NotificationPipe)
  {
    USBH_ClosePipe(phost, MTP_Handle->NotificationPipe);
    USBH_FreePipe(phost, MTP_Handle->NotificationPipe);
    MTP_Handle->NotificationPipe = 0;     /* Reset the Channel as Free */
  }

  send_mtp = 0;
  receive_mtp = 0;
  g_mtp_enable = 0;
  g_mtp_video_buffer[0] = NULL;
  g_mtp_video_size[0] = 0;
  g_mtp_video_buffer[1] = NULL;
  g_mtp_video_size[1] = 0;

  MTP_Handle->mtp_send_timeout = 0;
  MTP_Handle->mtp_send_timeout_times = 0;
  MTP_Handle->mtp_send_size = 0;
  MTP_Handle->mtp_send_total_size = 0;

  if (sramReady0)
  {
    SRAM_Ready0Confirm();
  }

  if (sramReady1)
  {
    SRAM_Ready1Confirm();
  }

  g_mtpSendRdIndex = 0;
  g_mtpSendWrIndex = 0;

  MTP_Handle->state = MTP_IDLE;

  USBH_SetLittleEndian(phost);

  g_mtp_recv_enable = 0;

  return USBH_OK;
}

/**
  * @brief  USBH_MTP_ClassRequest
  *         The function is responsible for handling Standard requests
  *         for MTP class.
  * @param  phost: Host handle
  * @retval USBH Status
  */
uint8_t g_vendor[ACC_STRING_SIZE]  = {'A','R','T','O','S','Y','N','\0'};
uint8_t g_model[ACC_STRING_SIZE]   = {'A','R','8','0','2','0','\0','\0'};
uint8_t g_product[ACC_STRING_SIZE] = {'r','c','\0','\0','\0','\0','\0','\0'};
uint8_t g_version[ACC_STRING_SIZE] = {'0','.','0','.','0','.','1','\0'};
uint8_t g_uri[ACC_STRING_SIZE]     = {0};
uint8_t g_serial[ACC_STRING_SIZE]  = {"FFFFFFFF"};

static USBH_StatusTypeDef USBH_MTP_ClassRequest (USBH_HandleTypeDef *phost)
{
    USBH_StatusTypeDef  result = USBH_BUSY;
#if (USBH_USE_OS == 1)
        osMessagePut ( phost->os_event, USBH_STATE_CHANGED_EVENT, 0);
#endif
    USBH_LL_NotifyUSBHStateChange(phost);

    switch((MTP_REQStateTypeDef)phost->ClassRequestState)
    {
        case MTP_REQ_START:
            if (g_usb_role.dev_type == USB_APPLE_DEVICE)
            {
                DLOG_Critical("It's Apple Device");
                phost->Control.setup.b.bmRequestType = USB_H2D | 0x40;
                phost->Control.setup.b.bRequest = 0x51;
                phost->Control.setup.b.wValue.w = 0;
                phost->Control.setup.b.wIndex.w = 0;
                phost->Control.setup.b.wLength.w = 0;

                if (USBH_BUSY == USBH_CtlReq(phost, 0, phost->Control.setup.b.wLength.w))
                {
                    phost->timeout_count++;
                    DLOG_Critical("USB Device CtlReq");
                    if (phost->timeout_count >= 250)
                    {
                        g_usb_role.dev_type = USB_DEVICE_UNKNOWN;
						g_usb_role.e_usbPort = HAL_USB_PORT_NUM;
                        return USBH_NOT_SUPPORTED;
                    }
                    break;
                }
                else
                {
                    phost->timeout_count = 0;
                    exec_time = 0;
                    g_u8CurrentHost = 1;
//                  USBH_SetPrtSusp(phost);
                    phost->ClassRequestState = MTP_REQ_END;

                    return USBH_OK;
                }
            }

            phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_TYPE_VENDOR;
            phost->Control.setup.b.bRequest = 0x33;
            phost->Control.setup.b.wValue.w = 0x0000;
            phost->Control.setup.b.wIndex.w = 0x0000;
            phost->Control.setup.b.wLength.w = 0x0002;

            if (USBH_BUSY == USBH_CtlReq(phost, 0, phost->Control.setup.b.wLength.w))
            {
                phost->timeout_count++;
                if (phost->timeout_count >= 20)
                {
                    DLOG_Error("Setup send failed!");
                    return USBH_FAIL;
                }
                break;
            }
            else
            {
                phost->ClassRequestState = MTP_REQ_VENDOR;
                phost->timeout_count = 0;
            }

        case MTP_REQ_VENDOR:
            phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_TYPE_VENDOR;
            phost->Control.setup.b.bRequest = 0x34;
            phost->Control.setup.b.wValue.w = 0x0000;
            phost->Control.setup.b.wIndex.w = 0x0000;
            phost->Control.setup.b.wLength.w = strlen((char *)g_vendor) + 1;

            if (USBH_BUSY == USBH_CtlReq(phost, g_vendor, phost->Control.setup.b.wLength.w))
            {
                phost->timeout_count++;
                if (phost->timeout_count >= 20)
                {
                    DLOG_Error("g_vendor send failed!");
                    return USBH_FAIL;
                }
                break;
            }
            else
            {
                phost->ClassRequestState = MTP_REQ_MODEL;
                phost->timeout_count = 0;
            }

        case MTP_REQ_MODEL:
            phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_TYPE_VENDOR;
            phost->Control.setup.b.bRequest = 0x34;
            phost->Control.setup.b.wValue.w = 0x0000;
            phost->Control.setup.b.wIndex.w = 0x0001;
            phost->Control.setup.b.wLength.w = strlen((char *)g_model) + 1;


            if (USBH_BUSY == USBH_CtlReq(phost, g_model, phost->Control.setup.b.wLength.w))
            {
                phost->timeout_count++;
                if (phost->timeout_count >= 20)
                {
                    DLOG_Error("g_model send failed!");
                    return USBH_FAIL;
                }
                break;
            }
            else
            {
                phost->ClassRequestState = MTP_REQ_PRODUCT;
                phost->timeout_count = 0;
            }

        case MTP_REQ_PRODUCT:
            phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_TYPE_VENDOR;
            phost->Control.setup.b.bRequest = 0x34;
            phost->Control.setup.b.wValue.w = 0x0000;
            phost->Control.setup.b.wIndex.w = 0x0002;
            phost->Control.setup.b.wLength.w = strlen((char *)g_product) + 1;


            if (USBH_BUSY == USBH_CtlReq(phost, g_product, phost->Control.setup.b.wLength.w))
            {
                phost->timeout_count++;
                if (phost->timeout_count >= 20)
                {
                    DLOG_Error("g_product send failed!");
                    return USBH_FAIL;
                }
                break;
            }
            else
            {
                phost->ClassRequestState = MTP_REQ_VERSION;
                phost->timeout_count = 0;
            }

        case MTP_REQ_VERSION:
            phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_TYPE_VENDOR;
            phost->Control.setup.b.bRequest = 0x34;
            phost->Control.setup.b.wValue.w = 0x0000;
            phost->Control.setup.b.wIndex.w = 0x0003;
            phost->Control.setup.b.wLength.w = strlen((char *)g_version) + 1;


            if (USBH_BUSY == USBH_CtlReq(phost, g_version, phost->Control.setup.b.wLength.w))
            {
                phost->timeout_count++;
                if (phost->timeout_count >= 20)
                {
                    DLOG_Error("g_version send failed!");
                    return USBH_FAIL;
                }
                break;
            }
            else
            {
                if (strlen((char *)g_uri) > 0)
                {
                    phost->ClassRequestState = MTP_REQ_URI;
                    phost->timeout_count = 0;
                }
                else
                {
                    phost->ClassRequestState = MTP_REQ_END;
                    phost->timeout_count = 0;
                }
            }

        case MTP_REQ_URI:
            phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_TYPE_VENDOR;
            phost->Control.setup.b.bRequest = 0x34;
            phost->Control.setup.b.wValue.w = 0x0000;
            phost->Control.setup.b.wIndex.w = 0x0004;
            phost->Control.setup.b.wLength.w = strlen((char *)g_uri) + 1;   //30


            if (USBH_BUSY == USBH_CtlReq(phost, g_uri, phost->Control.setup.b.wLength.w))
            {
                phost->timeout_count++;
                if (phost->timeout_count >= 20)
                {
                    DLOG_Error("g_version send failed!");
                    return USBH_FAIL;
                }
                break;
            }
            else
            {
/*
                phost->ClassRequestState = MTP_REQ_SERIAL;
                phost->timeout_count = 0;
**/

                phost->ClassRequestState = MTP_REQ_END;
                phost->timeout_count = 0;
            }

        case MTP_REQ_SERIAL:
            phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_TYPE_VENDOR;
            phost->Control.setup.b.bRequest = 0x34;
            phost->Control.setup.b.wValue.w = 0x0000;
            phost->Control.setup.b.wIndex.w = 0x0005;
            phost->Control.setup.b.wLength.w = strlen((char *)g_serial) + 1;   //30


            if (USBH_BUSY == USBH_CtlReq(phost, g_serial, phost->Control.setup.b.wLength.w))
            {
                phost->timeout_count++;
                if (phost->timeout_count >= 20)
                {
                    DLOG_Error("g_version send failed!");
                    return USBH_FAIL;
                }
                break;
            }
            else
            {
                phost->ClassRequestState = MTP_REQ_END;
                phost->timeout_count = 0;
            }

        case MTP_REQ_END:
            if(g_usb_role.dev_type == USB_APPLE_DEVICE)
            {
                phost->ClassRequestState = MTP_REQ_START;
                phost->timeout_count = 0;
                result = USBH_OK;
                return USBH_OK;
            }

            phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_TYPE_VENDOR;
            phost->Control.setup.b.bRequest = 0x35;
            phost->Control.setup.b.wValue.w = 0x0000;
            phost->Control.setup.b.wIndex.w = 0x0000;
            phost->Control.setup.b.wLength.w = 0x0000;


            if (USBH_BUSY == USBH_CtlReq(phost, 0, phost->Control.setup.b.wLength.w))
            {
                phost->timeout_count++;
                if (phost->timeout_count >= 20)
                {
                    DLOG_Error("Setup end send failed!");
                    return USBH_FAIL;
                }
                break;
            }
            else
            {
                phost->ClassRequestState = MTP_REQ_START;

                g_mtp_enable = 1;
                phost->timeout_count = 0;
                result = USBH_OK;

                if (phost->device.DevDesc.idVendor == 0x18D1)       //Android AOA vendor ID
                {
                    STRU_SysEvent_USB_PlugEvent st_usb_plug;

                    st_usb_plug.plug_event = 1;
                    st_usb_plug.usb_port_id = phost->id;
                    st_usb_plug.dev_type = USB_ANDROID_DEVICE;

                    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USB_PLUG_EVENT, (void *)&st_usb_plug);
                }
                
                DLOG_Critical("mtp enable");
            }
    }

    return result;
}

uint8_t                         g_repeat_time;
volatile MTP_StateTypeDef       mtp_last_status;
static void USBH_MTP_PreSendProcess(USBH_HandleTypeDef *phost);
static void USBH_MTP_RecvProcess(USBH_HandleTypeDef *phost);

/**
  * @brief  USBH_MTP_Process
  *         The function is for managing state machine for MTP data transfers
  * @param  phost: Host handle
  * @retval USBH Status
  */
static USBH_StatusTypeDef USBH_MTP_Process (USBH_HandleTypeDef *phost)
{
    USBH_StatusTypeDef  status = USBH_BUSY;

    return status;
}



static void USBH_MTP_PreSendProcess(USBH_HandleTypeDef *phost)
{
    MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

    if (MTP_Handle->mtp_send_total_size >= 512)
    {
        MTP_Handle->mtp_send_size = 512;
    }
    else
    {
        MTP_Handle->mtp_send_size = MTP_Handle->mtp_send_total_size;
    }

    USBH_BulkSendData(phost,
                      MTP_Handle->mtp_send_buffer,
                      MTP_Handle->mtp_send_size,
                      MTP_Handle->DataOutPipe,
                      1);

    MTP_Handle->mtp_send_total_size -= MTP_Handle->mtp_send_size;
    MTP_Handle->mtp_send_buffer += MTP_Handle->mtp_send_size;
}


static void USBH_MTP_SendProcess(USBH_HandleTypeDef *phost)
{
    MTP_HandleTypeDef *     MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
    volatile uint8_t        flag = 1;

    mtp_last_status = MTP_Handle->state;

    while(flag)
    {
        switch(MTP_Handle->state)
        {
            case MTP_IDLE:

                MTP_Handle->state = MTP_READYCHL0;
                //no break;

            case MTP_READYCHL0:

                if(sramReady0 == 1 && g_mtp_video_size[0] && g_mtp_video_buffer[0])
                {
                    MTP_Handle->mtp_send_total_size = g_mtp_video_size[0];
                    MTP_Handle->mtp_send_buffer     = g_mtp_video_buffer[0];
                    g_mtp_video_size[0]             = 0;
                    g_mtp_video_buffer[0]           = NULL;
                    MTP_Handle->state               = MTP_SENDCHANNEL0;
                }
                else if(sramReady0 == 0 && g_mtp_video_size[0] && g_mtp_video_buffer[0])
                {
                    DLOG_Error("mtp_last_status: %u, sramReady0 == 0", mtp_last_status);
                }
                //no break;

            case MTP_SENDCHANNEL0:

                if(sramReady0 == 1 && MTP_Handle->mtp_send_total_size)
                {
                    if (USBH_IsBigEndian(phost) == 0)
                    {
                        USBH_SetBigEndian(phost);
                    }

                    USBH_MTP_PreSendProcess(phost);

                    MTP_Handle->state = MTP_RECVCHANNEL0ACK;

                    flag = 0;// break the while
                }
                else
                {
                    if(sramReady0 == 1 && 0 == MTP_Handle->mtp_send_total_size)
                    {
						if (mtp_send_video_enable == 1)
						{
							uint32_t dataLen = SRAM_DATA_VALID_LEN_0;
							dataLen = (dataLen << 2);

							DLOG_Error("g_mtp_video_size:%u, g_mtp_video_buffer:%p", \
											g_mtp_video_size[0], g_mtp_video_buffer[0]);

							g_mtp_video_size[0] = dataLen;
							g_mtp_video_buffer[0] = (uint8_t *)SRAM_BUFF_0_ADDRESS;

							DLOG_Error("g_mtp_video_size:%u, g_mtp_video_buffer:%p", \
											g_mtp_video_size[0], g_mtp_video_buffer[0]);
						}
                    }
                    MTP_Handle->state = MTP_READYCHL1;
                }

                break;

            case MTP_RECVCHANNEL0ACK:

                if (USBH_URB_DONE == USBH_LL_GetURBState(phost, MTP_Handle->DataOutPipe))
                {
                    if (MTP_Handle->mtp_send_total_size == 0)
                    {
                        SRAM_Ready0Confirm();
                        MTP_Handle->state = MTP_READYCHL1;
                    }
                    else
                    {
                        MTP_Handle->state = MTP_SENDCHANNEL0;
                    }
                }
                else
                {
                    // resend
                    if (sramReady0 == 1 && USBH_URB_IDLE != USBH_LL_GetURBState(phost, MTP_Handle->DataOutPipe))// sramReady0 == 1 &&  g_repeat_time < 3 &&
                    {
                        MTP_Handle->mtp_send_total_size += MTP_Handle->mtp_send_size;
                        MTP_Handle->mtp_send_buffer -= MTP_Handle->mtp_send_size;

                        MTP_Handle->state = MTP_SENDCHANNEL0;
                    }
                    else if(sramReady0 != 1)
                    {
                        MTP_Handle->state = MTP_READYCHL1;
                    }
                    else
                    {
                        DLOG_Error("USBH_URB_IDLE");
                        /*if(MTP_RECVCHANNEL0ACK == mtp_last_status)
                        {
                            MTP_Handle->state = MTP_READYCHL1;
                        }*/
                        flag = 0;// break the while
                    }
                }

                break;

            case MTP_READYCHL1:

                if(sramReady1 == 1 && g_mtp_video_size[1] && g_mtp_video_buffer[1])
                {
                    MTP_Handle->mtp_send_total_size = g_mtp_video_size[1];
                    MTP_Handle->mtp_send_buffer     = g_mtp_video_buffer[1];
                    g_mtp_video_size[1]             = 0;
                    g_mtp_video_buffer[1]           = NULL;
                    MTP_Handle->state               = MTP_SENDCHANNEL1;
                }
                else if(sramReady1 == 0 && g_mtp_video_size[1] && g_mtp_video_buffer[1])
                {
                    DLOG_Error("mtp_last_status: %u, sramReady1 == 0, g_mtp_video_size: %d, ", mtp_last_status, g_mtp_video_size[1]);
                }
                //no break;

            case MTP_SENDCHANNEL1:

                if(sramReady1 == 1 && MTP_Handle->mtp_send_total_size)
                {
                    if (USBH_IsBigEndian(phost) == 0)
                    {
                        USBH_SetBigEndian(phost);
                    }

                    USBH_MTP_PreSendProcess(phost);

                    MTP_Handle->state = MTP_RECVCHANNEL1ACK;

                    flag = 0;// break the while
                }
                else
                {
                    if(sramReady1 == 1 && 0 == MTP_Handle->mtp_send_total_size)
                    {
						if (mtp_send_video_enable == 1)
						{
							uint32_t dataLen = SRAM_DATA_VALID_LEN_1;
							dataLen = (dataLen << 2);

							DLOG_Error("g_mtp_video_size:%u, g_mtp_video_buffer:%p", \
							g_mtp_video_size[1], g_mtp_video_buffer[1]);

							g_mtp_video_size[1] = dataLen + SRAM_DATA_RESERVED_LEN;
							g_mtp_video_buffer[1] = (uint8_t *)SRAM_BUFF_1_ADDRESS;

							DLOG_Error("g_mtp_video_size:%u, g_mtp_video_buffer:%p", \
							g_mtp_video_size[1], g_mtp_video_buffer[1]);
						}
                    }
                    MTP_Handle->state = MTP_SENDDATA;

                }

                break;

            case MTP_RECVCHANNEL1ACK:

                if (USBH_URB_DONE == USBH_LL_GetURBState(phost, MTP_Handle->DataOutPipe))
                {

                    if (MTP_Handle->mtp_send_total_size == 0)
                    {
                        SRAM_Ready1Confirm();
                        MTP_Handle->state = MTP_SENDDATA;
                    }
                    else
                    {
                        MTP_Handle->state = MTP_SENDCHANNEL1;
                    }
                }
                else
                {
                    // resend
                    if (sramReady1 == 1 && USBH_URB_IDLE != USBH_LL_GetURBState(phost, MTP_Handle->DataOutPipe))//g_repeat_time < 3 &&
                    {
                        MTP_Handle->mtp_send_total_size += MTP_Handle->mtp_send_size;
                        MTP_Handle->mtp_send_buffer -= MTP_Handle->mtp_send_size;

                        MTP_Handle->state = MTP_SENDCHANNEL1;
                    }
                    else if (sramReady1 != 1)
                    {
                        MTP_Handle->state = MTP_SENDDATA;
                    }
                    else
                    {
                        DLOG_Error("USBH_URB_IDLE");
                        /*if(MTP_RECVCHANNEL1ACK == mtp_last_status)
                        {
                            MTP_Handle->state = MTP_SENDDATA;
                        }*/
                        flag = 0;// break the while
                    }
                }

                break;

            case MTP_SENDDATA:

                if (g_mtpSendRdIndex != g_mtpSendWrIndex)
                {
                    MTP_Handle->mtp_send_total_size = g_mtpSendSize[g_mtpSendRdIndex];
                    MTP_Handle->mtp_send_buffer     = g_mtpSendBuffer[g_mtpSendRdIndex];

                    if (USBH_IsBigEndian(phost) == 1)
                    {
                        USBH_SetLittleEndian(phost);
                    }

                    USBH_MTP_PreSendProcess(phost);

                    MTP_Handle->state = MTP_RECVDATAACK;

                    flag = 0;// break the while
                    break;
                }
                else
                {
                    MTP_Handle->state = MTP_SENDTASKDATA;//MTP_RECVDATA;//MTP_IDLE;//MTP_RECVDATA;
                    break;
                }

            case MTP_RECVDATAACK:

                if (g_repeat_time > 40 || USBH_URB_DONE == USBH_LL_GetURBState(phost, MTP_Handle->DataOutPipe))
                {
                    g_mtpSendSize[g_mtpSendRdIndex] = 0;
                    g_mtpSendRdIndex++;
                    if (g_mtpSendRdIndex >= 20)
                    {
                        g_mtpSendRdIndex = 0;
                    }

                    if (g_mtpSendRdIndex == g_mtpSendWrIndex)
                    {
                        MTP_Handle->state = MTP_SENDTASKDATA;//MTP_IDLE; //the last ack come to idle
                    }
                    else
                    {
                        MTP_Handle->state = MTP_SENDDATA;
                    }
                    g_repeat_time = 0;
                }
                else
                {
                    // resend
                    if (USBH_URB_IDLE != USBH_LL_GetURBState(phost, MTP_Handle->DataOutPipe))//g_repeat_time < 3 &&
                    {
                        MTP_Handle->state = MTP_SENDDATA;
                        ++g_repeat_time;
                    }
                    else
                    {
                        flag = 0;// break the while
                    }
                }

                break;

            case MTP_SENDTASKDATA:

                if (g_mtpSendSize[DATA_BUF_DEPTH])
                {
                    MTP_Handle->mtp_send_total_size = g_mtpSendSize[DATA_BUF_DEPTH];
                    MTP_Handle->mtp_send_buffer     = g_mtpSendBuffer[DATA_BUF_DEPTH];

                    if (USBH_IsBigEndian(phost) == 1)
                    {
                        USBH_SetLittleEndian(phost);
                    }

                    USBH_MTP_PreSendProcess(phost);

                    MTP_Handle->state = MTP_RECVTASKDATAACK;

                    flag = 0;// break the while
                    break;
                }
                else
                {
                    MTP_Handle->state = MTP_RECVDATA;
                    break;
                }

            case MTP_RECVTASKDATAACK:

                if (g_repeat_time > 3 || USBH_URB_DONE == USBH_LL_GetURBState(phost, MTP_Handle->DataOutPipe))
                {
                    g_repeat_time = 0;
                    g_mtpSendSize[DATA_BUF_DEPTH] = 0;
                    MTP_Handle->state = MTP_IDLE; //the last ack come to idle
                }
                else
                {
                    // resend
                    if (USBH_URB_IDLE != USBH_LL_GetURBState(phost, MTP_Handle->DataOutPipe))
                    {
                        MTP_Handle->state = MTP_SENDTASKDATA;
                        ++g_repeat_time;
                    }
                    else
                    {
                        flag = 0;// break the while
                    }
                }

                break;

            case MTP_RECVDATA:
            default:

                MTP_Handle->state = MTP_IDLE;
                g_repeat_time = 0;
                flag = 0;// break the while
                break;
        }

        //DLOG_Error("%d %d %d\n", g_repeat_time, (uint32_t)MTP_Handle->state, (uint32_t)g_last_status);
    }

}

extern void WIRELESS_ParseParamConfig(void *param, uint8_t id);

void USBH_MTP_RecvData(USBH_HandleTypeDef *phost)
{
    MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
    uint32_t           i;
    uint8_t            temp;
    uint32_t           u32_recvSize;

    if(0 == g_mtp_recv_enable)
    {
        return;
    }

    if (USBH_URB_DONE == USBH_LL_GetURBState(phost, MTP_Handle->DataInPipe))
    {
        u32_recvSize = USBH_LL_GetLastXferSize(phost, MTP_Handle->DataInPipe);

        DLOG_Info("Recv message, len:%u", u32_recvSize);

        if(0 == u32_recvSize)
        {
            receive_mtp = 0;
            return;
        }

        if (USBH_IsBigEndian(phost))
        {
            for (i = 0; i < u32_recvSize; i+=4)
            {
                temp = buffer_mtp_recv[i];
                buffer_mtp_recv[i]   = buffer_mtp_recv[i+3];
                buffer_mtp_recv[i+3] = temp;
                temp = buffer_mtp_recv[i+1];
                buffer_mtp_recv[i+1] = buffer_mtp_recv[i+2];
                buffer_mtp_recv[i+2] = temp;
            }
        }
        //Temp to fix bug that endian is not right issue
        if ((buffer_mtp_recv[0] == 0x00) && (buffer_mtp_recv[2] == 0x5A) && (buffer_mtp_recv[3] == 0xFF))
        {
            for (i = 0; i < u32_recvSize; i+=4)
            {
                temp = buffer_mtp_recv[i];
                buffer_mtp_recv[i]   = buffer_mtp_recv[i+3];
                buffer_mtp_recv[i+3] = temp;
                temp = buffer_mtp_recv[i+1];
                buffer_mtp_recv[i+1] = buffer_mtp_recv[i+2];
                buffer_mtp_recv[i+2] = temp;
            }
        }

        WIRELESS_ParseParamConfig((void *)buffer_mtp_recv, phost->id);
        receive_mtp = 0;
    }
    /*else if(USBH_URB_IDLE != USBH_LL_GetURBState(phost, MTP_Handle->DataInPipe))
    {
        receive_mtp = 0;
    }
    else if(HC_IDLE != HAL_HCD_HC_GetState((HCD_HandleTypeDef *)(phost->pData), MTP_Handle->DataInPipe))
    {
        receive_mtp = 0;
    }*/
    else
    {

    }


}


static void USBH_MTP_RecvProcess(USBH_HandleTypeDef *phost)
{
    MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

    USBH_BulkReceiveData(phost,
                         buffer_mtp_recv,
                         512,
                         MTP_Handle->DataInPipe);
#if 0
    if (receive_mtp == 0)
    {
        USBH_BulkReceiveData(phost,
                             buffer_mtp_recv,
                             512,
                             MTP_Handle->DataInPipe);

        receive_mtp = 1;
    }
    else
    {
        if (USBH_URB_DONE == USBH_LL_GetURBState(phost, MTP_Handle->DataInPipe))
        {
            u32_recvSize = USBH_LL_GetLastXferSize(phost, MTP_Handle->DataInPipe);

            DLOG_Error("Recv message, len:%u", u32_recvSize);

            if (USBH_IsBigEndian(phost))
            {
                for (i = 0; i < u32_recvSize; i+=4)
                {
                    temp = buffer_mtp_recv[i];
                    buffer_mtp_recv[i]   = buffer_mtp_recv[i+3];
                    buffer_mtp_recv[i+3] = temp;
                    temp = buffer_mtp_recv[i+1];
                    buffer_mtp_recv[i+1] = buffer_mtp_recv[i+2];
                    buffer_mtp_recv[i+2] = temp;
                }
            }

            WIRELESS_ParseParamConfig((void *)buffer_mtp_recv, 0);

            memset(buffer_mtp_recv, 0, 512);
        }

        receive_mtp = 0;
    }
#endif
}

uint8_t USBH_MTP_Send(uint8_t *buffer, uint32_t size);

/**
  * @brief  USBH_MTP_SOFProcess
  *         The function is for managing SOF callback
  * @param  phost: Host handle
  * @retval USBH Status
  */
//uint8_t CheckFeq = 0;
static USBH_StatusTypeDef USBH_MTP_SOFProcess (USBH_HandleTypeDef *phost)
{
    MTP_HandleTypeDef *MTP_Handle;

    if (g_usb_role.dev_type == USB_APPLE_DEVICE) {
        USBH_SetPrtSusp(phost);
        DLOG_Critical("USB Set Prt Suspend!");
        return USBH_OK;
    }

    MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

    g_mtp_recv_enable = 1;
    if(0 == receive_mtp)//CheckFeq > 50 ||
    {
        if(MTP_Handle->DataOutPipe != 0)
        {
            USBH_MTP_RecvProcess(phost);
        }

        receive_mtp = 1;
        //CheckFeq = 0;
    }

    if(MTP_Handle->DataOutPipe != 0)            //make sure it is not Ctrl endpoint
    {
        USBH_MTP_SendProcess(phost);
    }

    //++CheckFeq;

    return USBH_OK;
}

/**
  * @brief  USBH_MTP_IsReady
  *         Select the storage Unit to be used
  * @param  phost: Host handle
  * @retval USBH Status
  */
uint8_t USBH_MTP_IsReady (USBH_HandleTypeDef *phost)
{
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

  return (MTP_Handle->is_ready);
}

/**
  * @brief  USBH_MTP_GetNumStorage
  *         Select the storage Unit to be used
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetNumStorage (USBH_HandleTypeDef *phost, uint8_t *storage_num)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

  if(MTP_Handle->is_ready > 0)
  {
    *storage_num = MTP_Handle->info.storids.n;
    status  = USBH_OK;
  }

  return status;
}

/**
  * @brief  USBH_MTP_SelectStorage
  *         Select the storage Unit to be used
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_SelectStorage (USBH_HandleTypeDef *phost, uint8_t storage_idx)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

  if((storage_idx < MTP_Handle->info.storids.n) && (MTP_Handle->is_ready))
  {
      MTP_Handle->params.CurrentStorageId = MTP_Handle->info.storids.Storage[storage_idx];
      status  = USBH_OK;
  }

  return status;
}

/**
  * @brief  USBH_MTP_GetStorageInfo
  *         Get the storage Unit info
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetStorageInfo (USBH_HandleTypeDef *phost, uint8_t storage_idx, MTP_StorageInfoTypedef *info)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

  if((storage_idx < MTP_Handle->info.storids.n) && (MTP_Handle->is_ready))
  {
    *info = MTP_Handle->info.storinfo[storage_idx];
    status  = USBH_OK;
  }
  return status;
}

/**
  * @brief  USBH_MTP_GetStorageInfo
  *         Get the storage Unit info
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetNumObjects (USBH_HandleTypeDef *phost,
                                           uint32_t storage_idx,
                                           uint32_t objectformatcode,
                                           uint32_t associationOH,
                                           uint32_t* numobs)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;
  if((storage_idx < MTP_Handle->info.storids.n) && (MTP_Handle->is_ready))
  {
    while ((status = USBH_PTP_GetNumObjects (phost,
                                             MTP_Handle->info.storids.Storage[storage_idx],
                                             objectformatcode,
                                             associationOH,
                                             numobs)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >   5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}


/**
  * @brief  USBH_MTP_GetStorageInfo
  *         Get the storage Unit info
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetObjectHandles (USBH_HandleTypeDef *phost,
                                           uint32_t storage_idx,
                                           uint32_t objectformatcode,
                                           uint32_t associationOH,
                                           PTP_ObjectHandlesTypedef* objecthandles)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if((storage_idx < MTP_Handle->info.storids.n) && (MTP_Handle->is_ready))
  {
    while ((status = USBH_PTP_GetObjectHandles (phost,
                                                MTP_Handle->info.storids.Storage[storage_idx],
                                                objectformatcode,
                                                associationOH,
                                                objecthandles)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}

/**
  * @brief  USBH_PTP_GetObjectInfo
  *         Gets objert info
  * @param  phost: Host handle
  * @param  dev_info: Device info structure
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetObjectInfo (USBH_HandleTypeDef *phost,
                                           uint32_t handle,
                                           PTP_ObjectInfoTypedef* objectinfo)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_GetObjectInfo (phost, handle, objectinfo)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}
/**
  * @brief  USBH_MTP_DeleteObject
  *         Delete an object.
  * @param  phost: Host handle
  * @param  handle : Object Handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_DeleteObject (USBH_HandleTypeDef *phost,
                                          uint32_t handle,
                                          uint32_t objectformatcode)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_DeleteObject (phost, handle, objectformatcode)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}

/**
  * @brief  USBH_MTP_GetObject
  *         Gets object
  * @param  phost: Host handle
  * @param  dev_info: Device info structure
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetObject (USBH_HandleTypeDef *phost,
                                           uint32_t handle,
                                           uint8_t *object)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_GetObject (phost, handle, object)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}

/**
  * @brief  USBH_MTP_GetPartialObject
  *         Gets object
  * @param  phost: Host handle
  * @param  dev_info: Device info structure
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetPartialObject(USBH_HandleTypeDef *phost,
                                           uint32_t handle,
                                           uint32_t offset,
                                           uint32_t maxbytes,
                                           uint8_t *object,
                                           uint32_t *len)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_GetPartialObject(phost,
                                           handle,
                                           offset,
                                           maxbytes,
                                           object,
                                           len)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}

/**
  * @brief  USBH_MTP_GetObjectPropsSupported
  *         Gets object partially
  * @param  phost: Host handle
  * @param  dev_info: Device info structure
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetObjectPropsSupported (USBH_HandleTypeDef *phost,
                                                     uint16_t ofc,
                                                     uint32_t *propnum,
                                                     uint16_t *props)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_GetObjectPropsSupported (phost,
                                                     ofc,
                                                     propnum,
                                                     props)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}

/**
  * @brief  USBH_MTP_GetObjectPropDesc
  *         Gets object partially
  * @param  phost: Host handle
  * @param  dev_info: Device info structure
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetObjectPropDesc (USBH_HandleTypeDef *phost,
                                                uint16_t opc,
                                                uint16_t ofc,
                                                PTP_ObjectPropDescTypeDef *opd)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_GetObjectPropDesc (phost,
                                                opc,
                                                ofc,
                                                opd)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}

/**
  * @brief  USBH_MTP_GetObjectPropList
  *         Gets object partially
  * @param  phost: Host handle
  * @param  dev_info: Device info structure
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetObjectPropList (USBH_HandleTypeDef *phost,
                                                uint32_t handle,
                                                MTP_PropertiesTypedef *pprops,
                                                uint32_t *nrofprops)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_GetObjectPropList (phost,
                                                handle,
                                                pprops,
                                                nrofprops)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}

/**
  * @brief  USBH_MTP_SendObject
  *         Send an object
  * @param  phost: Host handle
  * @param  dev_info: Device info structure
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_SendObject (USBH_HandleTypeDef *phost,
                                           uint32_t handle,
                                           uint8_t *object,
                                           uint32_t size)
{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_SendObject (phost, handle, object, size)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}

 /**
  * @brief  Handle HID Control process
  * @param  phost: Host handle
  * @retval USBH Status
  */
static USBH_StatusTypeDef USBH_MTP_Events (USBH_HandleTypeDef *phost)
{
  USBH_StatusTypeDef status = USBH_BUSY ;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;


  switch(MTP_Handle->events.state)
  {
  case MTP_EVENTS_INIT:
    if((phost->Timer & 1) == 0)
    {
      MTP_Handle->events.timer = phost->Timer;
      USBH_InterruptReceiveData(phost,
                                (uint8_t *)&(MTP_Handle->events.container),
                                MTP_Handle->NotificationEpSize,
                                MTP_Handle->NotificationPipe);


     MTP_Handle->events.state = MTP_EVENTS_GETDATA ;
    }
    break;
  case MTP_EVENTS_GETDATA:
    if(USBH_LL_GetURBState(phost , MTP_Handle->NotificationPipe) == USBH_URB_DONE)
    {
      MTP_DecodeEvent(phost);
    }

    if(( phost->Timer - MTP_Handle->events.timer) >= MTP_Handle->events.poll)
    {
     MTP_Handle->events.timer = phost->Timer;

      USBH_InterruptReceiveData(phost,
                                (uint8_t *)&(MTP_Handle->events.container),
                                MTP_Handle->NotificationEpSize,
                                MTP_Handle->NotificationPipe);

    }
    break;

  default:
    break;
  }

  return status;
}

/**
  * @brief  MTP_DecodeEvent
  *         Decode device event sent by responder
  * @param  phost: Host handle
  * @retval None
  */
static void MTP_DecodeEvent (USBH_HandleTypeDef *phost)
{
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;

  uint16_t code;
  uint32_t param1;

  /* Process the event */
  code = MTP_Handle->events.container.code;
  param1 = MTP_Handle->events.container.param1;

 switch(code)
 {
    case PTP_EC_Undefined:
      USBH_DbgLog("EVT: PTP_EC_Undefined in session %u", MTP_Handle->ptp.session_id);
      break;
    case PTP_EC_CancelTransaction:
      USBH_DbgLog("EVT: PTP_EC_CancelTransaction in session %u", MTP_Handle->ptp.session_id);
      break;
    case PTP_EC_ObjectAdded:
      USBH_DbgLog("EVT: PTP_EC_ObjectAdded in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_ObjectRemoved:
      USBH_DbgLog("EVT: PTP_EC_ObjectRemoved in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_StoreAdded:
      USBH_DbgLog("EVT: PTP_EC_StoreAdded in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_StoreRemoved:
      USBH_DbgLog("EVT: PTP_EC_StoreRemoved in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_DevicePropChanged:
      USBH_DbgLog("EVT: PTP_EC_DevicePropChanged in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_ObjectInfoChanged:
      USBH_DbgLog("EVT: PTP_EC_ObjectInfoChanged in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_DeviceInfoChanged:
      USBH_DbgLog("EVT: PTP_EC_DeviceInfoChanged in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_RequestObjectTransfer:
      USBH_DbgLog("EVT: PTP_EC_RequestObjectTransfer in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_StoreFull:
      USBH_DbgLog("EVT: PTP_EC_StoreFull in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_DeviceReset:
      USBH_DbgLog("EVT: PTP_EC_DeviceReset in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_StorageInfoChanged :
      USBH_DbgLog( "EVT: PTP_EC_StorageInfoChanged in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_CaptureComplete :
      USBH_DbgLog( "EVT: PTP_EC_CaptureComplete in session %u", MTP_Handle->ptp.session_id);
      break;

    case PTP_EC_UnreportedStatus :
      USBH_DbgLog( "EVT: PTP_EC_UnreportedStatus in session %u", MTP_Handle->ptp.session_id);
      break;

    default :
      USBH_DbgLog( "Received unknown event in session %u", MTP_Handle->ptp.session_id);
      break;
  }

 USBH_MTP_EventsCallback(phost, code, param1);
}

/**
  * @brief  USBH_MTP_GetDevicePropDesc
  *         Gets object partially
  * @param  phost: Host handle
  * @param  dev_info: Device info structure
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_MTP_GetDevicePropDesc (USBH_HandleTypeDef *phost,
                                                uint16_t propcode,
			                        PTP_DevicePropDescTypdef* devicepropertydesc)

{
  USBH_StatusTypeDef status = USBH_FAIL;
  MTP_HandleTypeDef *MTP_Handle =  (MTP_HandleTypeDef *)phost->pActiveClass->pData;
  uint32_t timeout = phost->Timer;

  if(MTP_Handle->is_ready)
  {
    while ((status = USBH_PTP_GetDevicePropDesc (phost, propcode, devicepropertydesc)) == USBH_BUSY)
    {
      if(((phost->Timer - timeout) >  5000) || (phost->device.is_connected == 0))
      {
        return USBH_FAIL;
      }
    }
  }
  return status;
}
/**
  * @brief  The function informs that host has received an event
  *  @param  pdev: Selected device
  * @retval None
  */
__weak void USBH_MTP_EventsCallback(USBH_HandleTypeDef *phost, uint32_t event, uint32_t param)
{

}


void USBH_MTP_SendVideoData(uint8_t *data_buffer, uint32_t data_size, uint32_t channel)
{
    g_mtp_video_buffer[channel] = data_buffer;
    g_mtp_video_size[channel]   = data_size;
}

uint8_t USBH_MTP_Send_From_Task(uint8_t *buffer, uint32_t size)
{
    // taskENTER_CRITICAL();
    if(size < MAX_PACKET_SIZE && 0 == g_mtpSendSize[DATA_BUF_DEPTH])
    {
        g_mtpSendSize[DATA_BUF_DEPTH] = size;
        // taskEXIT_CRITICAL();

        memcpy(g_mtpSendBuffer[DATA_BUF_DEPTH], buffer, size);

        return 0;
    }
    else if(0 != g_mtpSendSize[DATA_BUF_DEPTH])
    {
        // taskEXIT_CRITICAL();
        DLOG_Info("task send busy!");
        return 1;
    }
    else
    {
        // taskEXIT_CRITICAL();
        DLOG_Error("send data too long( > 512)!");
        g_mtpSendSize[DATA_BUF_DEPTH] = 0;
        return 1;
    }
}


// #define USBH_MTP_Getlock(x)           x = taskENTER_CRITICAL_FROM_ISR();++g_mtp_send_lock;taskEXIT_CRITICAL_FROM_ISR(x)
// #define USBH_MTP_Releaselock(x)       x = taskENTER_CRITICAL_FROM_ISR();--g_mtp_send_lock;taskEXIT_CRITICAL_FROM_ISR(x)

uint8_t USBH_MTP_Send(uint8_t *buffer, uint32_t size)
{
    uint32_t   i;
    uint32_t Savestatus;

    // USBH_MTP_Getlock(Savestatus);

    DLOG_Info("mtp send data: %d, %d", g_mtpSendRdIndex, g_mtpSendWrIndex);
    DLOG_Info("mtp send data: %02x, %02x, %02x, %02x, %02x, %02x, %02x, %02x",
                    buffer[0], buffer[1], buffer[2], buffer[3],
                    buffer[4], buffer[5], buffer[6], buffer[7]);

    if(1 != g_mtp_send_lock)
    {
        // USBH_MTP_Releaselock(Savestatus);
        DLOG_Error("mtp send busy");
        return 1;
    }

    if (((g_mtpSendWrIndex + 1) % DATA_BUF_DEPTH) == g_mtpSendRdIndex)
    {
        DLOG_Critical("mtp buffer is full");
        // USBH_MTP_Releaselock(Savestatus);
        return 1;
    }

    while(size > MAX_PACKET_SIZE)
    {
        memcpy(g_mtpSendBuffer[g_mtpSendWrIndex], buffer, MAX_PACKET_SIZE);
        g_mtpSendSize[g_mtpSendWrIndex] = MAX_PACKET_SIZE;
        g_mtpSendWrIndex = (++g_mtpSendWrIndex) % DATA_BUF_DEPTH;
        size -= MAX_PACKET_SIZE;

        if (((g_mtpSendWrIndex + 1) % DATA_BUF_DEPTH) == g_mtpSendRdIndex)
        {
            DLOG_Critical("mtp buffer is full");
            // USBH_MTP_Releaselock(Savestatus);
            return 1;
        }
    }

    for (i = 0; i < size; i++)
    {
        g_mtpSendBuffer[g_mtpSendWrIndex][i] = buffer[i];
    }

    size = TO4TIMES(size);
    while(size > i){
    	g_mtpSendBuffer[g_mtpSendWrIndex][i++] = 0;
    }

    g_mtpSendSize[g_mtpSendWrIndex] = size;

    g_mtpSendWrIndex++;

    if (g_mtpSendWrIndex >= DATA_BUF_DEPTH)
    {
        g_mtpSendWrIndex = 0;
    }

    // USBH_MTP_Releaselock(Savestatus);

    return 0;
}

static void USBH_SetPrtSusp(USBH_HandleTypeDef *phost)
{
//  uint32_t usb_base_addr = (uint32_t)(((HCD_HandleTypeDef *)phost->pData)->Instance);
//  uint32_t readAddress = USBx_HPRT0;
//
    USB_OTG_GlobalTypeDef *USBx  = ((HCD_HandleTypeDef *)phost->pData)->Instance;
    __IO uint32_t reg_value = USBx_HPRT0;

    DLOG_Critical("USB HPRT reg address is %08x, %08x", &USBx_HPRT0, (uint32_t)(((HCD_HandleTypeDef *)phost->pData)->Instance));

    phost->device.is_connected = 0;

    if (exec_time > 0)
        return;

    reg_value &= (~USB_OTG_HPRT_PENA);
    reg_value = (uint32_t)(reg_value | USB_OTG_HPRT_PSUSP);

    USBx_HPRT0 = reg_value;

    exec_time = 1;
}

static ENUM_USB_DEVICE_TYPE USBH_CheckDeviceType(void)
{
    uint8_t apple_device[] = "Apple Inc.";
    int i = 0;

    if ((usb_dev_info != NULL) && (strlen(usb_dev_info) >= 10))
    {
        DLOG_Critical("usb dev info: %s", usb_dev_info);
        if (strncmp(usb_dev_info, "Apple Inc.", 10) == 0)
            return USB_APPLE_DEVICE;
    }
    return USB_ANDROID_DEVICE;
}

uint8_t USBH_AOA_Set_String(ENUM_AOA_STRING_ID acc_id, uint8_t *string, int len)
{
    switch(acc_id)
    {
        case ENUM_AOA_MANUFACTURER:
            memset(g_vendor, 0x00, ACC_STRING_SIZE);
            memcpy(g_vendor, string, len);
            break;
        case ENUM_AOA_MODEL:
            memset(g_model, 0x00, ACC_STRING_SIZE);
            memcpy(g_model, string, len);
            break;
        case ENUM_AOA_DESCRIPTION:
            memset(g_product, 0x00, ACC_STRING_SIZE);
            memcpy(g_product, string, len);
            break;
        case ENUM_AOA_VERSION:
            memset(g_version, 0x00, ACC_STRING_SIZE);
            memcpy(g_version, string, len);
            break;
        case ENUM_AOA_URI:
            memset(g_uri, 0x00, ACC_STRING_SIZE);
            memcpy(g_uri, string, len);
            break;
        case ENUM_AOA_SERIAL:
            memset(g_serial, 0x00, ACC_STRING_SIZE);
            memcpy(g_serial, string, len);
            break;
        default:
            break;

    }
    return 0;
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


/**
* @}
*/


/**
* @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
