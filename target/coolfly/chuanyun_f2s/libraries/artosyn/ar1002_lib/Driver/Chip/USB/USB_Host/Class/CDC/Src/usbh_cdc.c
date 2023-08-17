/**
  ******************************************************************************
  * @file    usbh_cdc.c
  * @author  MCD Application Team
  * @version V3.2.2
  * @date    07-July-2015
  * @brief   This file is the CDC Layer Handlers for USB Host CDC class.
  *           
  *  @verbatim
  *      
  *          ===================================================================      
  *                                CDC Class Driver Description
  *          =================================================================== 
  *           This driver manages the "Universal Serial Bus Class Definitions for Communications Devices
  *           Revision 1.2 November 16, 2007" and the sub-protocol specification of "Universal Serial Bus 
  *           Communications Class Subclass Specification for PSTN Devices Revision 1.2 February 9, 2007"
  *           This driver implements the following aspects of the specification:
  *             - Device descriptor management
  *             - Configuration descriptor management
  *             - Enumeration as CDC device with 2 data endpoints (IN and OUT) and 1 command endpoint (IN)
  *             - Requests management (as described in section 6.2 in specification)
  *             - Abstract Control Model compliant
  *             - Union Functional collection (using 1 IN endpoint for control)
  *             - Data interface class
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
#include "usbh_cdc.h"
#include "debuglog.h"
#include "r8152.h"
#include "hal.h"
#include "sram_sky.h"
// #include "sram_ground.h"
#include "drv_systick.h"
#include "sys_event.h"
#include "usbh_core.h"

typedef void (*usb_recv_handler_callback)(void *, uint32_t);

static USBH_StatusTypeDef USBH_CDC_InterfaceInit  (USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_CDC_InterfaceDeInit  (USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_CDC_Process(USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_CDC_SOFProcess(USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_CDC_ClassRequest (USBH_HandleTypeDef *phost);
static void CDC_ProcessTransmission(USBH_HandleTypeDef *phost);
static void CDC_ProcessReception(USBH_HandleTypeDef *phost);
extern uint8_t GetRTSPBufferIndex(uint8_t index);
extern void SetRTSPRestart();
void CDC_Transfer(USBH_HandleTypeDef *phost);
void USBH_CDC_RecvData(USBH_HandleTypeDef *phost);
void USBH_CDC_RecvACK(USBH_HandleTypeDef *phost);


USBH_ClassTypeDef  CDC_Class = 
{
    "CDC",
    USB_CDC_CLASS,
    USBH_CDC_InterfaceInit,
    USBH_CDC_InterfaceDeInit,
    USBH_CDC_ClassRequest,
    USBH_CDC_Process,
    USBH_CDC_SOFProcess,
    NULL,
};
/**
* @}
*/ 

uint8_t                     g_cdcPortId = 0;
volatile uint8_t            g_netcardSendBufferWrIndex;
volatile uint8_t            g_netcardSendBufferRdIndex;
NETCARD_SEND_BUFFER_STRU    g_netcardSendBuffer[CDC_SEND_BUFFER_MAX_SIZE];
uint8_t                     g_IPCameraMACaddr[6];
volatile uint32_t           g_setIPCameraMACaddr  = 0;
volatile uint32_t           g_PortCardMode[2] = {0xff, 0xff};
usb_recv_handler_callback   usb_recv_handler = NULL;
//volatile uint8_t            g_usb_send_recv = 0; //0:send 1:recv
volatile uint8_t            g_CDC_Restart_RX;
extern volatile uint8_t     g_RTSP_Restart;

volatile uint32_t           g_rxreq_send_num = 0;
volatile uint32_t           g_rxreq_recv_num = 0;
volatile uint32_t           g_rxreq_lost_num = 0;
volatile uint32_t           g_rxreq_time_out = 0;

/** @defgroup USBH_CDC_CORE_Private_Functions
* @{
*/ 

/**
  * @brief  USBH_CDC_InterfaceInit 
  *         The function init the CDC class.
  * @param  phost: Host handle
  * @retval USBH Status
  */
static USBH_StatusTypeDef USBH_CDC_InterfaceInit (USBH_HandleTypeDef *phost)
{
    USBH_StatusTypeDef  status = USBH_FAIL ;
    uint8_t             interface;
    CDC_HandleTypeDef  *CDC_Handle;
    uint32_t            i;

    interface = USBH_FindInterface(phost, 
                                   VENDOR_SPECIFIC, 
                                   VENDOR_SPECIFIC, 
                                   NO_CLASS_SPECIFIC_PROTOCOL_CODE);

    if(interface == 0xFF) /* No Valid Interface */
    {
        DLOG_Error("Cannot Find the interface for Communication Interface Class.", phost->pActiveClass->Name);         
    }
    else
    {
        USBH_SelectInterface (phost, interface);
        phost->pActiveClass->pData = (CDC_HandleTypeDef *)USBH_malloc (sizeof(CDC_HandleTypeDef));
        CDC_Handle =  (CDC_HandleTypeDef*) phost->pActiveClass->pData; 

        CDC_Handle->pNetDevice  = (void *)&g_stR8152;

        /*Collect the notification endpoint address and length*/
        for (i = 0; i < phost->device.CfgDesc.Itf_Desc[interface].bNumEndpoints; i++)
        {
            if ((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress & 0x80)&&
                (phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bmAttributes == USB_EP_TYPE_INTR))
            {
                CDC_Handle->CommItf.NotifEp = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress;
                CDC_Handle->CommItf.NotifEpSize  = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].wMaxPacketSize;
                CDC_Handle->CommItf.NotifInterval = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bInterval;

                break;
            }
        }

        if (i >= phost->device.CfgDesc.Itf_Desc[interface].bNumEndpoints)
        {
            DLOG_Error("no interrupt endpoint found");

            return USBH_NOT_SUPPORTED;
        }
    }

    /*Allocate the length for host channel number in*/
    CDC_Handle->CommItf.NotifPipe = USBH_AllocPipe(phost, CDC_Handle->CommItf.NotifEp);

    /* Open pipe for Notification endpoint */
    USBH_OpenPipe  (phost,
                    CDC_Handle->CommItf.NotifPipe,
                    CDC_Handle->CommItf.NotifEp,
                    phost->device.address,
                    phost->device.speed,
                    USB_EP_TYPE_INTR,
                    CDC_Handle->CommItf.NotifEpSize);

    USBH_LL_SetToggle(phost, CDC_Handle->CommItf.NotifPipe, 0);

    interface = USBH_FindInterface(phost,
                                   VENDOR_SPECIFIC,
                                   VENDOR_SPECIFIC,
                                   NO_CLASS_SPECIFIC_PROTOCOL_CODE);

    if(interface == 0xFF) /* No Valid Interface */
    {
        DLOG_Error("Cannot Find the interface for Data Interface Class.", phost->pActiveClass->Name);
    }
    else
    {
        for (i = 0; i < phost->device.CfgDesc.Itf_Desc[interface].bNumEndpoints; i++)
        {
            /*Collect the class specific endpoint address and length*/
            if ((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress & 0x80)&&
                (phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bmAttributes == USB_EP_TYPE_BULK))
            {
                CDC_Handle->DataItf.InEp = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress;
                CDC_Handle->DataItf.InEpSize  = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].wMaxPacketSize;
            }
            else if (((phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress & 0x80) == 0)&&
                     (phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bmAttributes == USB_EP_TYPE_BULK))
            {
                CDC_Handle->DataItf.OutEp = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].bEndpointAddress;
                CDC_Handle->DataItf.OutEpSize  = phost->device.CfgDesc.Itf_Desc[interface].Ep_Desc[i].wMaxPacketSize;
            }
        }

        /*Allocate the length for host channel number out*/
        CDC_Handle->DataItf.OutPipe = USBH_AllocPipe(phost, CDC_Handle->DataItf.OutEp);
        phost->recvCallback[CDC_Handle->DataItf.OutPipe] = USBH_CDC_RecvACK;

        /*Allocate the length for host channel number in*/
        CDC_Handle->DataItf.InPipe = USBH_AllocPipe(phost, CDC_Handle->DataItf.InEp);
        phost->recvCallback[CDC_Handle->DataItf.InPipe] = USBH_CDC_RecvData;

        /* Open channel for OUT endpoint */
        USBH_OpenPipe(phost,
                      CDC_Handle->DataItf.OutPipe,
                      CDC_Handle->DataItf.OutEp,
                      phost->device.address,
                      phost->device.speed,
                      USB_EP_TYPE_BULK,
                      CDC_Handle->DataItf.OutEpSize);

        /* Open channel for IN endpoint */
        USBH_OpenPipe(phost,
                      CDC_Handle->DataItf.InPipe,
                      CDC_Handle->DataItf.InEp,
                      phost->device.address,
                      phost->device.speed,
                      USB_EP_TYPE_BULK,
                      CDC_Handle->DataItf.InEpSize);

        USBH_LL_SetToggle(phost, CDC_Handle->DataItf.OutPipe, 0);
        USBH_LL_SetToggle(phost, CDC_Handle->DataItf.InPipe, 0);

        CDC_Handle->state               = CDC_DEVICE_PROBE;
        CDC_Handle->netcard_busy        = 0;
        CDC_Handle->net_line_connect    = 0;
        CDC_Handle->data_tx_state       = CDC_IDLE;
        CDC_Handle->data_rx_state       = CDC_IDLE;
        CDC_Handle->data_state          = CDC_IDLE;

        SYS_EVENT_RegisterHandler(SYS_EVENT_ID_NETLINE_PLUG_EVENT, USBH_CDC_NetlinePlugEventHandler);

        USBH_InterruptReceiveData(phost,
                                  CDC_Handle->CommItf.buff,
                                  CDC_Handle->CommItf.NotifEpSize,
                                  CDC_Handle->CommItf.NotifPipe);

        g_cdcPortId                 = phost->id;

        status = USBH_OK;
    }

    return status;
}



/**
  * @brief  USBH_CDC_InterfaceDeInit 
  *         The function DeInit the Pipes used for the CDC class.
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_CDC_InterfaceDeInit (USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef *CDC_Handle =  (CDC_HandleTypeDef*) phost->pActiveClass->pData;

    if ( CDC_Handle->CommItf.NotifPipe)
    {
        USBH_ClosePipe(phost, CDC_Handle->CommItf.NotifPipe);
        USBH_FreePipe  (phost, CDC_Handle->CommItf.NotifPipe);
        CDC_Handle->CommItf.NotifPipe = 0;     /* Reset the Channel as Free */
    }

    if ( CDC_Handle->DataItf.InPipe)
    {
        USBH_ClosePipe(phost, CDC_Handle->DataItf.InPipe);
        USBH_FreePipe  (phost, CDC_Handle->DataItf.InPipe);
        CDC_Handle->DataItf.InPipe = 0;     /* Reset the Channel as Free */
    }

    if ( CDC_Handle->DataItf.OutPipe)
    {
        USBH_ClosePipe(phost, CDC_Handle->DataItf.OutPipe);
        USBH_FreePipe  (phost, CDC_Handle->DataItf.OutPipe);
        CDC_Handle->DataItf.OutPipe = 0;     /* Reset the Channel as Free */
    } 

    if(phost->pActiveClass->pData)
    {
        USBH_free(phost->pActiveClass->pData);
        phost->pActiveClass->pData = 0;
    }

    CDC_Handle->state           = CDC_IDLE_STATE;
    CDC_Handle->data_state          = CDC_IDLE;

    return USBH_OK;
}


/**
  * @brief  USBH_CDC_ClassRequest 
  *         The function is responsible for handling Standard requests
  *         for CDC class.
  * @param  phost: Host handle
  * @retval USBH Status
  */
static USBH_StatusTypeDef USBH_CDC_ClassRequest (USBH_HandleTypeDef *phost)
{
    // USBH_StatusTypeDef  ret = USBH_BUSY;
    CDC_HandleTypeDef   *CDC_Handle = (CDC_HandleTypeDef*) phost->pActiveClass->pData;

    if (CDC_DEVICE_PROBE == CDC_Handle->state)
    {
        r8152_eth_probe(phost);

        CDC_Handle->pTxData      = r8152_get_tx_buff();
        if (NULL == CDC_Handle->pTxData)
        {
            DLOG_Error("TX BUFFER is NULL");
        }

        CDC_Handle->pRxData      = r8152_get_rx_buff();
        if (NULL == CDC_Handle->pRxData)
        {
            DLOG_Error("RX BUFFER is NULL");
        }

        CDC_Handle->RxDataLength = 0;
        CDC_Handle->TxDataLength = 0;

        phost->pUser(phost, HOST_USER_CLASS_ACTIVE);

        CDC_Handle->state = CDC_DEVICE_PROBE_FINISHED;

        if(g_PortCardMode[phost->id] != 0xff)
        {
            USBH_CDC_DeviceUp(phost, g_PortCardMode[phost->id]);
        }

        if(usb_recv_handler != NULL)
        {
            /* register the callback function for receive data */
            CDC_Handle->HandleCdcRecvCallBack = usb_recv_handler;
        }

        DLOG_Error("r8152 probe ok");
    }

    return USBH_OK;
}


/**
  * @brief  USBH_CDC_Process 
  *         The function is for managing state machine for CDC data transfers 
  * @param  phost: Host handle
  * @retval USBH Status
  */
static USBH_StatusTypeDef USBH_CDC_Process (USBH_HandleTypeDef *phost)
{
    USBH_StatusTypeDef status = USBH_BUSY;

    return status;
}


/**
  * @brief  USBH_CDC_SOFProcess 
  *         The function is for managing SOF callback 
  * @param  phost: Host handle
  * @retval USBH Status
  */
uint8_t     reset_count = 0;
uint8_t     interrupt_frequence = 0;
static USBH_StatusTypeDef USBH_CDC_SOFProcess (USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef          *CDC_Handle;
    // USBH_StatusTypeDef          status = USBH_BUSY;
    STRU_SysEvent_NetlinePlug   msg;

    CDC_Handle =  (CDC_HandleTypeDef*) phost->pActiveClass->pData;

    if(interrupt_frequence >= 127)
    {
        interrupt_frequence = 0;
        USBH_InterruptReceiveData(phost,
                                  CDC_Handle->CommItf.buff,
                                  CDC_Handle->CommItf.NotifEpSize,
                                  CDC_Handle->CommItf.NotifPipe);

        if ((CDC_Handle->CommItf.buff[0] & 0x0C) == 0x0C)
        {
            if (CDC_Handle->net_line_connect == 0)
            {
                if ((CDC_Handle->data_tx_state != CDC_IDLE)&&
                    (CDC_Handle->data_rx_state != CDC_IDLE))
                {
                    DLOG_Critical("net line plugin: %d, %d",
                                    CDC_Handle->data_tx_state,
                                    CDC_Handle->data_rx_state);

                    msg.plugEvent = 1;
                    msg.usb_dev   = (uint32_t)phost;

                    SYS_EVENT_Notify_From_ISR(SYS_EVENT_ID_NETLINE_PLUG_EVENT & (~SYS_EVENT_INTER_CORE_MASK), &msg);
                }

                CDC_Handle->net_line_connect = 1;
            }
        }
        else
        {
            if (CDC_Handle->net_line_connect == 1)
            {
                if ((CDC_Handle->data_tx_state != CDC_IDLE)&&
                    (CDC_Handle->data_rx_state != CDC_IDLE))
                {
                    DLOG_Critical("net line plugout: %d, %d",
                                    CDC_Handle->data_tx_state,
                                    CDC_Handle->data_rx_state);

                    msg.plugEvent = 0;
                    msg.usb_dev   = (uint32_t)phost;

                    SYS_EVENT_Notify_From_ISR(SYS_EVENT_ID_NETLINE_PLUG_EVENT & (~SYS_EVENT_INTER_CORE_MASK), &msg);
                }

                CDC_Handle->net_line_connect = 0;
            }

            return USBH_OK;
        }
    }
    else
    {
        ++interrupt_frequence;
    }

    if(0 == CDC_Handle->net_line_connect)
    {
        return USBH_OK;
    }

    switch (CDC_Handle->state)
    {
    case CDC_IDLE_STATE:

        // status = USBH_OK;

        break;

    case CDC_TRANSFER_DATA:

        CDC_Transfer(phost);

        if(g_rxreq_send_num <= g_rxreq_recv_num + g_rxreq_lost_num)
        {
            if(CDC_Handle->RxDataLength + CDC_Handle->DataItf.InEpSize <= RTL8152_AGG_BUF_SZ)
            {
                USBH_BulkReceiveData(phost,
                                     CDC_Handle->pRxData + CDC_Handle->RxDataLength,
                                     CDC_Handle->DataItf.InEpSize,
                                     CDC_Handle->DataItf.InPipe);
            }
            else
            {
                DLOG_Error("packet too long");
                CDC_Handle->RxDataLength = 0;
                USBH_BulkReceiveData(phost,
                                     CDC_Handle->pRxData + CDC_Handle->RxDataLength,
                                     CDC_Handle->DataItf.InEpSize,
                                     CDC_Handle->DataItf.InPipe);
            }
            ++g_rxreq_send_num;
            g_rxreq_time_out = 0;
        }
        else
        {
            ++g_rxreq_time_out;
            if(g_rxreq_time_out > 128)
            {
                //DLOG_Error("rx timeout: %d %d %d %d", g_rxreq_send_num, g_rxreq_recv_num, 
                //            g_rxreq_lost_num, g_rxreq_time_out);

                ++g_rxreq_lost_num;
                g_rxreq_time_out = 0;
            }
        }

#if 0
        CDC_ProcessTransmission(phost);
        CDC_ProcessReception(phost);
#endif

        break;

    default:
        break;
    }

    return USBH_OK;
}


/**
  * @brief  USBH_CDC_Stop 
  *         Stop current CDC Transmission 
  * @param  phost: Host handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_CDC_Stop(USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef *CDC_Handle =  (CDC_HandleTypeDef*) phost->pActiveClass->pData;

    if(phost->gState == HOST_CLASS)
    {
        CDC_Handle->state = CDC_IDLE_STATE;

        USBH_ClosePipe(phost, CDC_Handle->CommItf.NotifPipe);
        USBH_ClosePipe(phost, CDC_Handle->DataItf.InPipe);
        USBH_ClosePipe(phost, CDC_Handle->DataItf.OutPipe);
    }

    return USBH_OK;
}


/**
  * @brief  This function return last received data size
  * @param  None
  * @retval None
  */
uint16_t USBH_CDC_GetLastReceivedDataSize(USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef *CDC_Handle = (CDC_HandleTypeDef*)phost->pActiveClass->pData; 

    if(phost->gState == HOST_CLASS)
    {
        return USBH_LL_GetLastXferSize(phost, CDC_Handle->DataItf.InPipe);;
    }
    else
    {
        return 0;
    }
}


void USBH_CDC_RecvData(USBH_HandleTypeDef *phost)
{
    uint32_t                length;
    CDC_HandleTypeDef      *CDC_Handle  = (CDC_HandleTypeDef*) phost->pActiveClass->pData;

    if (USBH_URB_DONE == USBH_LL_GetURBState(phost, CDC_Handle->DataItf.InPipe))
    {
        length = USBH_LL_GetLastXferSize(phost, CDC_Handle->DataItf.InPipe);

        if (length > 0)
        {
            DLOG_Info("RX %d", length);
            USBH_CDC_ReceiveCallback(phost, length);
        }
        else
        {
            //DLOG_Error("RX len error len:%d", length);
        }
    }
    /*else if(USBH_URB_IDLE != USBH_LL_GetURBState(phost, CDC_Handle->DataItf.InPipe))
    {
        g_usb_send_recv = 0;
    }
    else if(HC_IDLE != HAL_HCD_HC_GetState((HCD_HandleTypeDef *)(phost->pData), CDC_Handle->DataItf.InPipe))
    {
        g_usb_send_recv = 0;
    }*/
    else
    {
        DLOG_Error("RX status error %d", USBH_LL_GetURBState(phost, CDC_Handle->DataItf.InPipe));
    }
    ++g_rxreq_recv_num;
}

uint32_t    count = 0;
void USBH_CDC_RecvACK(USBH_HandleTypeDef *phost)
{
    USBH_URBStateTypeDef    URB_Status = USBH_URB_IDLE;
    CDC_HandleTypeDef      *CDC_Handle  = (CDC_HandleTypeDef*) phost->pActiveClass->pData;
    URB_Status = USBH_LL_GetURBState(phost, CDC_Handle->DataItf.OutPipe);

    if(CDC_Handle->data_state == CDC_SEND_DATA_WAIT)
    {
        if(USBH_URB_DONE == URB_Status)
        {
            if(CDC_Handle->TxDataLength > CDC_Handle->DataItf.OutEpSize)
            {
                CDC_Handle->TxDataLength -= CDC_Handle->DataItf.OutEpSize;
                CDC_Handle->pTxData      += CDC_Handle->DataItf.OutEpSize;
                CDC_Handle->data_state    = CDC_SEND_DATA;
            }
            else
            {
                CDC_Handle->TxDataLength  = 0;
                CDC_Handle->pTxData       = NULL;
                CDC_Handle->data_state    = CDC_IDLE;//CDC_RECEIVE_DATA;
            }
            count = 0;
        }
        else if(USBH_URB_IDLE != URB_Status)
        {
            ++count;
            if(count > 50)
            {
                SetRTSPRestart();
                USBH_CDC_DeviceDown(phost);
                r8152b_init(phost);
                USBH_CDC_DeviceUp(phost, CDC_Handle->netcard_mode);
                count = 0;
            }
            CDC_Handle->data_state = CDC_IDLE;
        }
        else
        {
            DLOG_Error("URB_Status: %d", URB_Status);
        }

    }
}

uint8_t wait_time = 0;
void CDC_Transfer(USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef      *CDC_Handle  = (CDC_HandleTypeDef*) phost->pActiveClass->pData;
    uint8_t                *data_buffer = NULL;
    uint32_t                data_size   = 0;
    // USBH_URBStateTypeDef    URB_Status = USBH_URB_IDLE;
    uint8_t                 flag = 1;

    while(flag)
    {
        switch(CDC_Handle->data_state)
        {
            case CDC_IDLE:

                if (CDC_Handle != NULL && CDC_Handle->TxDataLength == 0)
                {
                    data_buffer = USBH_CDC_GetSendBuffer(&data_size);

                    if ((data_buffer != NULL)&&(data_size > 0)&&(data_size <= 1600))
                    {
                        CDC_Handle->TxDataLength    = data_size;
                        CDC_Handle->pTxData         = data_buffer;
                        CDC_Handle->data_state      = CDC_SEND_DATA;
                        DLOG_Info("TX len:%d", data_size);
                    }
                    else
                    {
                        data_buffer = NULL;
                        data_size = 0;
                        CDC_Handle->TxDataLength = 0;
                        CDC_Handle->data_state = CDC_IDLE;//CDC_RECEIVE_DATA;
                        flag = 0;
                    }
                    wait_time = 0;
                }
                else
                {
                    CDC_Handle->data_state = CDC_SEND_DATA;
                }
                break;

            case CDC_SEND_DATA:

                if (CDC_Handle != NULL && CDC_Handle->TxDataLength > 0 && CDC_Handle->TxDataLength <= 1600)
                {
                    /* there is data to send */
                    if(CDC_Handle->TxDataLength > CDC_Handle->DataItf.OutEpSize)
                    {
                        USBH_BulkSendData(phost,
                                          CDC_Handle->pTxData,
                                          CDC_Handle->DataItf.OutEpSize,
                                          CDC_Handle->DataItf.OutPipe,
                                          1);
                    }
                    else
                    {
                        USBH_BulkSendData(phost,
                                          CDC_Handle->pTxData,
                                          CDC_Handle->TxDataLength,
                                          CDC_Handle->DataItf.OutPipe,
                                          1);
                    }
                    CDC_Handle->data_state = CDC_SEND_DATA_WAIT;
                    flag = 0;
                }
                break;

            case CDC_SEND_DATA_WAIT:

                ++wait_time;
                if(wait_time % 5 == 0)
                {
                    CDC_Handle->data_state = CDC_SEND_DATA;
                    DLOG_Info("Resend");
                }
                else if(wait_time > 50)
                {
                    SetRTSPRestart();
                    g_CDC_Restart_RX = 0;
                    data_buffer = NULL;
                    data_size = 0;
                    CDC_Handle->TxDataLength = 0;
                    CDC_Handle->pTxData = 0;
                    CDC_Handle->data_state = CDC_IDLE;
                    DLOG_Error("Reset FM");
                    wait_time = 0;
                }
                flag = 0;
                break;

            default:
                flag = 0;
                break;
        }

    }

}


void USBH_CDC_NetlinePlugEventHandler(void *p)
{
    STRU_SysEvent_NetlinePlug   *msg;
    USBH_HandleTypeDef          *phost;
    CDC_HandleTypeDef           *CDC_Handle;
    // uint32_t                     i;

    msg = (STRU_SysEvent_NetlinePlug *)p;

    phost = (USBH_HandleTypeDef *)msg->usb_dev;

    CDC_Handle = (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    if (msg->plugEvent == 0)
    {
        SetRTSPRestart();
        g_CDC_Restart_RX = 0;
        CDC_Handle->TxDataLength = 0;
        CDC_Handle->RxDataLength = 0;
        CDC_Handle->data_state = CDC_IDLE;
    }
    else if (msg->plugEvent == 1)
    {
        USBH_CDC_DeviceDown(phost);
        r8152b_init(phost);
        USBH_CDC_DeviceUp(phost, CDC_Handle->netcard_mode);
    }
    else
    {
        DLOG_Critical("error of net line");
    }
}


CDC_StateTypeDef USBH_CDC_GetDeviceState(USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef *CDC_Handle =  (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    return CDC_Handle->state;
}


USBH_StatusTypeDef USBH_CDC_DeviceUp(USBH_HandleTypeDef *phost, uint8_t netcard_mode)
{
    CDC_HandleTypeDef *CDC_Handle =  (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    DLOG_Critical("ethernet device is ready1111111");

    if ((CDC_IDLE_STATE == CDC_Handle->state)||
        (CDC_DEVICE_PROBE == CDC_Handle->state)||
        //(CDC_DEVICE_DOWN == CDC_Handle->state)||
        (CDC_DEFAULT == CDC_Handle->state))
    {
        DLOG_Error("ethernet not ready ......");

        return USBH_FAIL;
    }
    else if ((CDC_DEVICE_UP == CDC_Handle->state)||
        (CDC_TRANSFER_DATA == CDC_Handle->state))
    {
        DLOG_Error("ethernet already activated ......");

        return USBH_BUSY;
    }

    /* enable usb-ethernet */
    CDC_Handle->state           = CDC_DEVICE_UP;
    CDC_Handle->netcard_mode    = netcard_mode;

    rtl8152_up(phost);

    r8152_init(phost);

    DLOG_Critical("ethernet device is ready");

    CDC_Handle->data_tx_state = CDC_SEND_DATA;
    CDC_Handle->data_rx_state = CDC_RECEIVE_DATA;

    CDC_Handle->state = CDC_TRANSFER_DATA;

    g_PortCardMode[phost->id] = netcard_mode;

    return USBH_OK;
}


void USBH_CDC_DeviceDown(USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef *CDC_Handle =  (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    /* disable usb-ethernet */
    CDC_Handle->state = CDC_DEVICE_DOWN;

    rtl8152_down(phost);
}


USBH_StatusTypeDef USBH_CDC_SendData(USBH_HandleTypeDef *phost, uint16_t data_len, uint8_t *data_buff)
{
    CDC_HandleTypeDef *CDC_Handle = (CDC_HandleTypeDef*)phost->pActiveClass->pData;
    uint8_t            tmpindex;

    if (CDC_Handle->net_line_connect == 0)
    {
        DLOG_Error("net line is not connected");

        return USBH_FAIL;
    }

    if (CDC_Handle->netcard_busy)
    {
        return USBH_FAIL;
    }

    if (g_netcardSendBufferWrIndex - g_netcardSendBufferRdIndex > CDC_SEND_BUFFER_MAX_SIZE - 1)
    {
        DLOG_Error("buffer is full: %d, %d", g_netcardSendBufferWrIndex, g_netcardSendBufferRdIndex);

        DLOG_Error("state: %d, %d", CDC_Handle->data_tx_state, CDC_Handle->data_rx_state);

        return USBH_FAIL;
    }

    CDC_Handle->netcard_busy = 1;

    tmpindex = GetRTSPBufferIndex(g_netcardSendBufferWrIndex);
    g_netcardSendBuffer[tmpindex].data_valid = 0;
    g_netcardSendBuffer[tmpindex].data_size  = data_len;
    g_netcardSendBuffer[tmpindex].data_size |= 0xC0000000;
    g_netcardSendBuffer[tmpindex].total_size = data_len + 8;
    g_netcardSendBuffer[tmpindex].zero_padding = 0;

    memcpy((void *)g_netcardSendBuffer[tmpindex].data,
           (void *)data_buff,
           data_len);

    uint8_t   old_index = tmpindex;

    if(1 == g_RTSP_Restart)
    {
        g_netcardSendBuffer[old_index].data_valid = 0;
        g_netcardSendBufferWrIndex = 0;
        g_RTSP_Restart = 0;
    }
    else
    {
        g_netcardSendBuffer[old_index].data_valid = 1;
        g_netcardSendBufferWrIndex++;
    }

    CDC_Handle->netcard_busy = 0;

    return USBH_OK;
}

//disable recv agg
void USBH_CDC_ReceiveCallback(USBH_HandleTypeDef *phost, uint32_t len)
{
    CDC_HandleTypeDef  *CDC_Handle;
    uint32_t            total_size   = 0;
    uint32_t            data_len = 0;
    uint32_t            i;
    uint8_t            *data_buff;
    uint32_t            header_size = 0;

    CDC_Handle  =  (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    if(CDC_Handle->RxDataLength > 0)// no frist packet
    {
        CDC_Handle->RxDataLength   += len;
        data_buff   = r8152_parse_header_no_agg(CDC_Handle->pRxData, &total_size, &data_len, &header_size);//get buf info

        if(data_buff == NULL || CDC_Handle->RxDataLength > RTL8152_AGG_BUF_SZ)//buf invalid
        {
            DLOG_Error("1:data_buff NULL RxDataLength: %d total_size: %d", CDC_Handle->RxDataLength, total_size);
            CDC_Handle->RxDataLength = 0;
            return;
        }
        else if(CDC_Handle->RxDataLength >= total_size)// get one complete packet
        {
            if (CDC_Handle->HandleCdcRecvCallBack)
            {
                CDC_Handle->HandleCdcRecvCallBack((void *)data_buff, data_len);
            }
            else
            {
                DLOG_Error("net receive callback not registered");
            }

            CDC_Handle->RxDataLength = 0;
        }
        else
        {
            //continue receive
        }
    }
    else// first packet
    {
        data_buff   = r8152_parse_header_no_agg(CDC_Handle->pRxData, &total_size, &data_len, &header_size);
        if(data_buff == NULL || total_size > RTL8152_AGG_BUF_SZ)
        {
            DLOG_Error("RxDataLength: %d total_size: %d len: %d", CDC_Handle->RxDataLength, total_size, len);
            CDC_Handle->RxDataLength = 0;
            return;
        }

        if(total_size > len)// header packet
        {
            CDC_Handle->RxDataLength   += len;
        }
        else
        {
            if (CDC_Handle->HandleCdcRecvCallBack)
            {
                CDC_Handle->HandleCdcRecvCallBack((void *)data_buff, data_len);
            }
            else
            {
                DLOG_Error("net receive callback not registered");
            }
            CDC_Handle->RxDataLength = 0;
        }
    }
}

//enable recv agg
#if 0
void USBH_CDC_ReceiveCallback(USBH_HandleTypeDef *phost, uint32_t len)
{
    CDC_HandleTypeDef  *CDC_Handle;
    uint32_t            total_size   = 0;
    uint32_t            data_len = 0;
    uint32_t            i;
    uint8_t            *data_buff;
    uint32_t            header_size = 0;

    CDC_Handle  =  (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    if(CDC_Handle->RxDataLength > 0)// no frist packet
    {
        CDC_Handle->RxDataLength   += len;
        data_buff   = r8152_parse_header(CDC_Handle->pRxData, &total_size, &data_len, &header_size);//get buf info

        if(data_buff == NULL || CDC_Handle->RxDataLength > RTL8152_AGG_BUF_SZ)//buf invalid
        {
            DLOG_Error("1:data_buff NULL RxDataLength: %d total_size: %d", CDC_Handle->RxDataLength, total_size);
            CDC_Handle->RxDataLength = 0;
            return;
        }
        else if(CDC_Handle->RxDataLength >= total_size)// get one complete packet
        {
            uint32_t tmp_len;
            if (CDC_Handle->HandleCdcRecvCallBack)
            {
                CDC_Handle->HandleCdcRecvCallBack((void *)data_buff, data_len);
            }
            else
            {
                DLOG_Error("net receive callback not registered");
            }

            tmp_len = CDC_Handle->RxDataLength - total_size;
            if (tmp_len >= header_size)// one more packet
            {
                for (i = 0; i < tmp_len; i++)
                {
                    CDC_Handle->pRxData[i] = CDC_Handle->pRxData[total_size + i];
                }
                CDC_Handle->RxDataLength = 0;

                USBH_CDC_ReceiveCallback(phost, tmp_len);
            }
            else// no packet
            {
                CDC_Handle->RxDataLength = 0;
            }
        }
        else
        {
            //continue receive
        }
    }
    else// first packet
    {
        data_buff   = r8152_parse_header(CDC_Handle->pRxData, &total_size, &data_len, &header_size);
        if(data_buff == NULL || total_size > RTL8152_AGG_BUF_SZ)
        {
            DLOG_Error("RxDataLength: %d total_size: %d", CDC_Handle->RxDataLength, total_size);
            CDC_Handle->RxDataLength = 0;
            return;
        }

        if(total_size > len)// header packet
        {
            CDC_Handle->RxDataLength   += len;
        }
        else
        {
            if (CDC_Handle->HandleCdcRecvCallBack)
            {
                CDC_Handle->HandleCdcRecvCallBack((void *)data_buff, data_len);
            }
            else
            {
                DLOG_Error("net receive callback not registered");
            }
            CDC_Handle->RxDataLength = 0;

            if(total_size < len)// one more packet
            {
                for (i = 0; i < len - total_size; i++)
                {
                    CDC_Handle->pRxData[i] = CDC_Handle->pRxData[total_size + i];
                }
                USBH_CDC_ReceiveCallback(phost, len - total_size);
            }
            else// one packet
            {
                //do nothing
            }
        }
    }
}
#endif

//old
#if 0
void USBH_CDC_ReceiveCallback(USBH_HandleTypeDef *phost, uint32_t len)
{
    CDC_HandleTypeDef  *CDC_Handle;
    uint32_t            total_size   = 0;
    uint32_t            data_len = 0;
    uint32_t            i;
    uint8_t            *data_buff;
    uint32_t            header_size = 0;

    CDC_Handle  =  (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    CDC_Handle->RxDataLength   += len;

    data_buff   = r8152_parse_header(CDC_Handle->pRxData, &total_size, &data_len, &header_size);

    while (CDC_Handle->RxDataLength >= total_size)
    {
        if (CDC_Handle->HandleCdcRecvCallBack)
        {
            CDC_Handle->HandleCdcRecvCallBack((void *)data_buff, data_len);
        }
        else
        {
            DLOG_Error("net receive callback not registered");
        }

        CDC_Handle->RxDataLength   -= total_size;

        for (i = 0; i < CDC_Handle->RxDataLength; i++)
        {
            CDC_Handle->pRxData[i] = CDC_Handle->pRxData[total_size + i];
        }

        if (CDC_Handle->RxDataLength >= header_size)
        {
            /* get rtl8152 header */
            data_buff   = r8152_parse_header(CDC_Handle->pRxData, &total_size, &data_len, &header_size);
        }
    }
}
#endif


void USBH_CDC_RegisterReceiveCallback(USBH_HandleTypeDef *phost, void (*recv_handler)(void *, uint32_t))
{
    CDC_HandleTypeDef *CDC_Handle;

    CDC_Handle  = (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    /* register the callback function for receive data */
    CDC_Handle->HandleCdcRecvCallBack = recv_handler;
    usb_recv_handler = recv_handler;
}


uint8_t *USBH_CDC_GetMacAddress(USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef *CDC_Handle;

    CDC_Handle  = (CDC_HandleTypeDef*)phost->pActiveClass->pData;

    return CDC_Handle->enetaddr;
}


void USBH_CDC_SetMacAddress(USBH_HandleTypeDef *phost, uint8_t *mac_addr)
{
    r8152_set_mac(phost,  (void *)mac_addr);
}


uint8_t USBH_CDC_GetIPCameraMacAddress(USBH_HandleTypeDef *phost, uint8_t *ipCameraMacAddr)
{
    if (g_setIPCameraMACaddr)
    {
        memcpy((void *)ipCameraMacAddr,
               (void *)g_IPCameraMACaddr,
               sizeof(g_IPCameraMACaddr));
    }

    return g_setIPCameraMACaddr;
}


void USBH_CDC_SetIPCameraMacAddress(USBH_HandleTypeDef *phost, uint8_t *ipCameraMacAddr)
{
    memcpy((void *)g_IPCameraMACaddr,
           (void *)ipCameraMacAddr,
           sizeof(g_IPCameraMACaddr));

    g_setIPCameraMACaddr = 1;
}


uint8_t *USBH_CDC_GetSendBuffer(uint32_t *data_size)
{
    uint8_t         *ret = NULL;
    uint8_t         tmpindex = GetRTSPBufferIndex(g_netcardSendBufferRdIndex);

    if (g_netcardSendBufferRdIndex == g_netcardSendBufferWrIndex)
    {
        *data_size = 0;

        return NULL;
    }

    if (g_netcardSendBuffer[tmpindex].data_valid != 1)
    {
        *data_size = 0;
    }
    else
    {
        *data_size  = g_netcardSendBuffer[tmpindex].total_size;
        ret         = (uint8_t *)&(g_netcardSendBuffer[tmpindex]);

    }

    if(1 == g_CDC_Restart_RX)
    {
        g_netcardSendBufferRdIndex = 0;
        g_CDC_Restart_RX = 0;
    }
    else
    {
        g_netcardSendBufferRdIndex++;
    }

    return ret;
}


uint8_t USBH_CDC_GetNetLineState(USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef *CDC_Handle;

    CDC_Handle  = (CDC_HandleTypeDef*)phost->pActiveClass->pData;
    if(CDC_Handle == NULL)
    {
        return 0;//fail
    }

    return CDC_Handle->net_line_connect;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
