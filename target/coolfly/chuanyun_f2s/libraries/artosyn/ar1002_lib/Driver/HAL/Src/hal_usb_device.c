/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_usb.c
Description: The external HAL APIs to use the USB Device.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/22
History: 
        0.0.1    2016/12/21    The initial version of hal_usb_device.c
*****************************************************************************/
#include "hal_usb_device.h"
#include "usbd_def.h"
#include "usbd_core.h"
#include "usbd_hid.h"
#include "usbd_hid_desc.h"
// #include "sram_ground.h"
#include "sys_event.h"
#include "interrupt.h"
#include "hal_nvic.h"
#include "debuglog.h"
#include "hal.h"
#include "cpu_info.h"
// // #include "cmsis_os.h"
// #include "task.h"
// #include "cmsis_os.h"

extern uint8_t g_u8CurrentHost;
extern USB_ROLE_TypeDef g_usb_role;

// static osSemaphoreId Mutex_id = NULL;
#define TO4TIMES(value) ((((value) + 3) / 4)*4)



USBD_HandleTypeDef          USBD_Device[USBD_PORT_NUM];
USBD_HID_ItfTypeDef         g_stUsbdHidItf;

volatile uint8_t g_usbUserBuffer[2][512] __attribute__ ((aligned (4)));
volatile uint8_t            g_usbTaskBuffer[512] __attribute__ ((aligned (4)));

/**
* @brief  config the usb as device controller
* @param  e_usbPort         usb port number: 0 or 1
* @retval   void
* @note  
*/
void HAL_USB_InitDevice(ENUM_HAL_USB_PORT e_usbPort, uint8_t u8_DeviceMode)
{
    if (HAL_USB_PORT_0 == e_usbPort)
    {
        reg_IrqHandle(OTG_INTR0_VECTOR_NUM, USB_LL_OTG0_IRQHandler, NULL);
        NVIC_SetPriority(OTG_INTR0_VECTOR_NUM,NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_OTG_INITR0,0));
    }
    else if (HAL_USB_PORT_1 == e_usbPort)
    {
        reg_IrqHandle(OTG_INTR1_VECTOR_NUM, USB_LL_OTG1_IRQHandler, NULL);
        NVIC_SetPriority(OTG_INTR1_VECTOR_NUM,NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_OTG_INITR1,0));
    }
    else
    {
        DLOG_Error("invalid USB Port Num: %d", e_usbPort);
    }

    SYS_EVENT_RegisterHandler(SYS_EVENT_ID_USB_PLUG_OUT, HAL_USB_ResetDevice);

    USBD_Device[e_usbPort].u8_DeviceMode = u8_DeviceMode;

    USBD_Init(&USBD_Device[e_usbPort], &HID_Desc, (uint8_t)e_usbPort);

    USBD_RegisterClass(&USBD_Device[e_usbPort], USBD_HID_CLASS);

    // if(g_usb_dev_type != USB_APPLE_DEVICE)
    USBD_Start(&USBD_Device[e_usbPort]);

    return;
}


void HAL_USB_DeInitDevice(ENUM_HAL_USB_PORT e_usbPort)
{
    USBD_DeInit(&USBD_Device[e_usbPort]);
}


/**
* @brief  reset the usb device controller for usb device hotplug
* @param  void * p         for sys event call-back
* @retval   void
* @note  
*/
void HAL_USB_ResetDevice(void * p)
{
    STRU_SysEvent_DEV_PLUG_OUT  *stDevPlugOut;
    uint8_t                      u8_portId;

    if (p == NULL)
    {
        DLOG_Error("NULL Pointer");

        return;
    }

    stDevPlugOut    = (STRU_SysEvent_DEV_PLUG_OUT *)p;

    u8_portId       = stDevPlugOut->otg_port_id;

    if (u8_portId > HAL_USB_PORT_NUM)
    {
        DLOG_Error("Invalid USB PORT Number");
    }

    DLOG_Info("reset USB%d", u8_portId);

    USBD_LL_Init(&USBD_Device[u8_portId]);
    USBD_LL_Start(&USBD_Device[u8_portId]);

    // if (sramReady0 == 1)
    // {
    //     SRAM_Ready0Confirm();
    // }
    // if (sramReady1 == 1)
    // {
    //     SRAM_Ready1Confirm();
    // }

    return;
}

HAL_RET_T HAL_USB_DeviceSendCtrl_From_Task(uint8_t *buff, uint32_t u32_len, uint8_t u8_portId)
{
    uint8_t                     ret;
    USBD_HID_HandleTypeDef     *hhid = (USBD_HID_HandleTypeDef*)USBD_Device[u8_portId].pClassData;

    //taskENTER_CRITICAL();
    if (hhid->state[4] != HID_IDLE)
    {
        return HAL_USB_ERR_DEVICE_BUSY;
    }

    memcpy((void *)g_usbTaskBuffer, buff, u32_len);

    ret = USBD_HID_SendReport(&USBD_Device[u8_portId], (uint8_t *)g_usbTaskBuffer, u32_len, HID_EPIN_CTRL_ADDR);
    //taskEXIT_CRITICAL();

    if (ret != USBD_OK)
    {
        if (USBD_BUSY == ret)
        {
            DLOG_Error("send ctrl busy, port: %d", u8_portId);

            return HAL_USB_ERR_DEVICE_BUSY;
        }
        else
        {
            DLOG_Error("send ctrl not configured, port: %d", u8_portId);

            return HAL_USB_ERR_DEVICE_NOT_CONGIURED;
        }
    }

    return HAL_OK;
}



/**
* @brief  send control data to the host
* @param  uint8_t    *buff                the buffer to send
*               uint32_t    u32_len          buffer length 
* @retval   void
* @note
*/
HAL_RET_T HAL_USB_DeviceSendCtrl(uint8_t *buff, uint32_t u32_len, uint8_t u8_portId)
{
    uint8_t                     ret;
    uint32_t                    factual_len;
    USBD_HID_HandleTypeDef     *hhid = (USBD_HID_HandleTypeDef*)USBD_Device[u8_portId].pClassData;

    ret = USBD_HID_PortActive(&USBD_Device[u8_portId], HID_EPIN_CTRL_ADDR);
    if (ret != USBD_OK) {
        return HAL_USB_ERR_DEVICE_NOT_CONGIURED;
    }

    // if(Mutex_id == NULL){
    	// osSemaphoreDef(Mutex);
    	// Mutex_id = osSemaphoreCreate(osSemaphore(Mutex),1);
    // }
    // osSemaphoreWait(Mutex_id, portMAX_DELAY);

    if (hhid->state[4] != HID_IDLE)
    {
        // osSemaphoreRelease(Mutex_id);
        return HAL_USB_ERR_DEVICE_BUSY;
    }

    factual_len = TO4TIMES(u32_len);
    for(int i=u32_len; i<factual_len; i++)
    {
        buff[i] = 0;
    }
     
    memcpy((void *)g_usbUserBuffer[0], buff, factual_len);
    
    ret = USBD_HID_SendReport(&USBD_Device[u8_portId], (uint8_t *)g_usbUserBuffer[0], factual_len, HID_EPIN_CTRL_ADDR);
    
    // osSemaphoreRelease(Mutex_id);
    if (ret != USBD_OK)
    {
        if (USBD_BUSY == ret)
        {
            DLOG_Error("send ctrl busy, port: %d", u8_portId);
    
            return HAL_USB_ERR_DEVICE_BUSY;
        }
        else
        {
            DLOG_Error("send ctrl not configured, port: %d", u8_portId);
    
            return HAL_USB_ERR_DEVICE_NOT_CONGIURED;
        }
    }
    

    
    	
    return HAL_OK;
}


/**
* @brief   register the user callback function to receive host data
* @param  void (*pUsrFunc)(void *)     user callback function
* @retval   void
* @note
*/
void HAL_USB_RegisterUserProcess(void (*pUsrFunc)(void *, uint8_t),
                               void (*pInitFunc)(void))
{
    g_stUsbdHidItf.dataOut  = pUsrFunc;
    g_stUsbdHidItf.userInit = pInitFunc;

    USBD_HID_RegisterInterface(&USBD_Device[HAL_USB_PORT_0], &g_stUsbdHidItf);
    USBD_HID_RegisterInterface(&USBD_Device[HAL_USB_PORT_1], &g_stUsbdHidItf);
}


HAL_RET_T HAL_USB_DeviceGetConnState(uint8_t u8_usbPortId)
{
    USBD_HandleTypeDef     *pdev;

    pdev                    = &USBD_Device[u8_usbPortId];

    if (pdev->u8_connState)
    {
        return HAL_OK;
    }
    else
    {
        return HAL_USB_ERR_DEVICE_NOT_CONGIURED;
    }
}


/**
* @brief  open the video output to PC or PAD.
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_OpenVideo(uint8_t u8_usbPortId)
{
    USBD_HandleTypeDef      *pdev;

    pdev                    = &USBD_Device[u8_usbPortId];

    USBD_HID_OpenVideoDisplay(pdev);
}


/**
* @brief  close the video output to PC or PAD.
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_CloseVideo(uint8_t u8_usbPortId)
{
    USBD_HandleTypeDef      *pdev;

    pdev                    = &USBD_Device[u8_usbPortId];

    USBD_HID_CloseVideoDisplay(pdev);
}


/**
* @brief  register customer's receive data function
* @param  void (*customerRecv)(void *)
* @retval   void
* @note  
*/
void HAL_USB_RegisterCustomerRecvData(void (*customerRecv)(void *, uint32_t, uint8_t))
{
    g_stUsbdHidItf.customerOut  = customerRecv;

    USBD_HID_RegisterInterface(&USBD_Device[HAL_USB_PORT_0], &g_stUsbdHidItf);
    USBD_HID_RegisterInterface(&USBD_Device[HAL_USB_PORT_1], &g_stUsbdHidItf);
}


/**
* @brief  Customer call this function to send data to host
* @param  uint8_t *buff             customer's data buffer to send
*               uint32_t u32_len       the length of buffer
* @retval   void
* @note  
*/
HAL_RET_T HAL_USB_CustomerSendData(uint8_t *buff,
                                   uint32_t u32_len,
                                   uint8_t u8_portId)
{
    uint8_t                     ret;
    USBD_HID_HandleTypeDef     *hhid = (USBD_HID_HandleTypeDef*)USBD_Device[u8_portId].pClassData;

    if (hhid->state[3] != HID_IDLE)
    {
        return HAL_USB_ERR_DEVICE_BUSY;
    }

    memcpy((void *)g_usbUserBuffer[1], buff, u32_len);

    ret = USBD_HID_SendReport(&USBD_Device[u8_portId], (uint8_t *)g_usbUserBuffer[1], u32_len, HID_CUSTOMER_IN_ADDR);

    if (ret != USBD_OK)
    {
        if (USBD_BUSY == ret)
        {
            DLOG_Error("CUSTOMER IN EP BUSY");

            return HAL_USB_ERR_DEVICE_BUSY;
        }
        else
        {
            DLOG_Error("CUSTOMER IN EP NOT CONFIGURED");

            return HAL_USB_ERR_DEVICE_NOT_CONGIURED;
        }
    }

    return HAL_OK;
}


HAL_RET_T HAL_USB_SendData(uint8_t *buff, uint32_t data_len, uint8_t portId, uint8_t ep)
{
    USBD_HID_HandleTypeDef     *hhid = (USBD_HID_HandleTypeDef*)USBD_Device[portId].pClassData;
    uint8_t                     ret;
    uint8_t                    *buff_dst;

    if ((ep != HID_EPIN_CTRL_ADDR)&&(ep != HID_CUSTOMER_IN_ADDR))
    {
        // DLOG_Critical("error ep = %02x", ep);
        return HAL_USB_ERR_ENDPOINT;
    }

    if ((data_len <= 3) || (data_len & 0x03) || (data_len > 512))
    {
        // DLOG_Critical("error size = %d", data_len);
        return HAL_USB_ERR_DATA_SIZE;
    }

    if (ep == HID_EPIN_CTRL_ADDR)
    {
        buff_dst = (uint8_t *)g_usbUserBuffer[0];
    }
    else
    {
        buff_dst = (uint8_t *)g_usbUserBuffer[1];
    }

    if (hhid->state[0x7F & ep] != HID_IDLE)
    {
        return HAL_USB_ERR_DEVICE_BUSY;
    }

    memcpy(buff_dst, buff, data_len);

    ret = USBD_HID_SendReport(&USBD_Device[portId], buff_dst, data_len, ep);

    if (ret != USBD_OK)
    {
        return HAL_USB_ERR_DEVICE_BUSY;
    }

    return HAL_OK;
}


/**
* @brief  register customer's receive data function
* @param  void (*customerRecv)(void *)
* @retval   void
* @note  
*/
void HAL_USB_RegisterEncoderBypassVideo(void (*VideoStreamRecv)(void *, uint32_t, uint8_t))
{
    g_stUsbdHidItf.recvVideoStream  = VideoStreamRecv;

    USBD_HID_RegisterInterface(&USBD_Device[HAL_USB_PORT_0], &g_stUsbdHidItf);
    USBD_HID_RegisterInterface(&USBD_Device[HAL_USB_PORT_1], &g_stUsbdHidItf);
}


