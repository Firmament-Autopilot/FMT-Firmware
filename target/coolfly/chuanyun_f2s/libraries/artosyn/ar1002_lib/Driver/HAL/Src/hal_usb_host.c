/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_usb.c
Description: The external HAL APIs to use the USB Host.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/22
History: 
        0.0.1    2016/12/21    The initial version of hal_usb_host.c
*****************************************************************************/
#include "hal_usb_host.h"
#include "usbh_def.h"
#include "usbh_core.h"
#include "usbh_uvc.h"
#include "usbh_msc.h"
#include "usbh_cdc.h"
#include "usbh_mtp.h"
#include "interrupt.h"
#include "hal_nvic.h"
#include "debuglog.h"
#include "hal_dma.h"
#include "cpu_info.h"
#include "drv_systick.h"
#include "hal.h"
#include "hal_sram_sky.h"
// #include "sram_ground.h"
#include "sram_sky.h"
#include "dma.h"

static ENUM_HAL_USB_HOST_STATE   s_eUSBHostAppState[HAL_USB_PORT_NUM];
USBH_HandleTypeDef               hUSBHost[USBH_PORT_NUM];
static uint8_t                   g_u8UVCHeader[12];
static USBH_AppHandler           g_usbhAppHandler[HAL_USB_PORT_NUM];
static USBH_AppHandler           g_usbhAppRegister[HAL_USB_HOST_CLASS_MAX];


/**
* @brief  Set the USB Host State for Application use.
* @param  e_usbHostAppState             indicate the usb host state
* @retval   void
* @note  
*/
void HAL_USB_SetHostAppState(ENUM_HAL_USB_HOST_STATE e_usbHostAppState, uint8_t port_id)
{
    s_eUSBHostAppState[port_id] = e_usbHostAppState;
}


/**
* @brief  Get the USB Host State for Application use.
* @param  void
* @retval   HAL_USB_STATE_IDLE                indicate the usb is IDLE
*               HAL_USB_STATE_READY             indicate the usb is READY
*               HAL_USB_STATE_DISCONNECT   indicate the usb is DISCONNECT
* @note  
*/
ENUM_HAL_USB_HOST_STATE HAL_USB_GetHostAppState(uint8_t port_id)
{
    return s_eUSBHostAppState[port_id];
}


/**
* @brief  polling the usb state-machine 
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_HostProcess(uint8_t u8_portId)
{
    if (u8_portId >= USBH_PORT_NUM)
    {
        DLOG_Error("invalid usb port id");

        return;
    }

    USBH_Process(&hUSBHost[u8_portId]);

    if (g_usbhAppHandler[u8_portId])
    {
        g_usbhAppHandler[u8_portId](u8_portId);
    }
}


static void HAL_USB_SetHostUserApp(USBH_HandleTypeDef *phost)
{
    if (phost->id >= HAL_USB_PORT_NUM)
    {
        DLOG_Error("invalid usb port");

        return;
    }

    switch (phost->pActiveClass->ClassCode)
    {
    case USB_MSC_CLASS:
        g_usbhAppHandler[phost->id] = g_usbhAppRegister[HAL_USB_HOST_CLASS_MSC];
        break;

    case UVC_CLASS:
        g_usbhAppHandler[phost->id] = g_usbhAppRegister[HAL_USB_HOST_CLASS_UVC];
        break;

    default:
        break;
    }
}


void HAL_USB_RegisterHostUserHandler(ENUM_HAL_USB_HOST_CLASS e_hostClassType,
                                  USBH_AppHandler usbhAppHandler)
{
    uint8_t                 u8_classCode;
    uint8_t                 i;
    USBH_HandleTypeDef      *phost;

    if (e_hostClassType < HAL_USB_HOST_CLASS_MAX)
    {
        /* register the USER APP */
        g_usbhAppRegister[e_hostClassType] = usbhAppHandler;

        switch (e_hostClassType)
        {
        case HAL_USB_HOST_CLASS_UVC:
            u8_classCode = UVC_CLASS;
            break;

        case HAL_USB_HOST_CLASS_MSC:
            u8_classCode = USB_MSC_CLASS;
            break;

        default:
            return;
        }

        /* if the usb has connected, link the registered handler immediately  */
        for (i = 0; i < USBH_PORT_NUM; i++)
        {
            phost = &hUSBHost[i];

            if (phost->pActiveClass != NULL)
            {
                if (phost->pActiveClass->ClassCode == u8_classCode)
                {
                    g_usbhAppHandler[i] = g_usbhAppRegister[e_hostClassType];
                }
            }
        }
    }
    else
    {
        DLOG_Error("USB Class Type is not supported");
    }
}


void HAL_USB_UnRegisterHostUserApp(ENUM_HAL_USB_HOST_CLASS e_hostClassType,
                                 USBH_AppHandler usbhAppHandler)
{
    uint8_t                 u8_classCode;
    uint8_t                 i;
    USBH_HandleTypeDef      *phost;

    if (e_hostClassType < HAL_USB_HOST_CLASS_MAX)
    {
        /* remove handler from registered array */
        if (usbhAppHandler == g_usbhAppRegister[e_hostClassType])
        {
            g_usbhAppRegister[e_hostClassType] = NULL;
        }

        switch (e_hostClassType)
        {
        case HAL_USB_HOST_CLASS_UVC:
            u8_classCode = UVC_CLASS;
            break;

        case HAL_USB_HOST_CLASS_MSC:
            u8_classCode = USB_MSC_CLASS;
            break;
        
        default:
            return;
        }

        /* remove handler from handler array  */
        for (i = 0; i < USBH_PORT_NUM; i++)
        {
            phost = &hUSBHost[USBH_PORT_NUM];

            if (phost->pActiveClass != NULL)
            {
                if ((phost->pActiveClass->ClassCode == u8_classCode)&&
                    (usbhAppHandler == g_usbhAppHandler[i]))
                {
                    g_usbhAppHandler[i] = NULL;
                }
            }
        }
    }
    else
    {
        DLOG_Error("USB Class Type is not supported");
    }
}


/**
* @brief  the entrance of usb state change, called when state change happened
* @param  phost       the handler of usb host
*               id            the usb host state
* @retval   void
* @note  
*/
static void USB_HostAppState(USBH_HandleTypeDef *phost, uint8_t id)
{
    switch(id)
    {
        case HOST_USER_CLASS_SELECTED:
            HAL_USB_SetHostUserApp(phost);
            break;

        case HOST_USER_SELECT_CONFIGURATION:
            break;

        case HOST_USER_DISCONNECTION:
            HAL_USB_SetHostAppState(HAL_USB_HOST_STATE_DISCONNECT, phost->id);
            break;

        case HOST_USER_CLASS_ACTIVE:
            HAL_USB_SetHostAppState(HAL_USB_HOST_STATE_READY, phost->id);
            break;

        case HOST_USER_CONNECTION:
            break;

        default:
            break;
    }

}


/**
* @brief  config the usb as host controller
* @param  e_usbPort            usb port number: 0 or 1
*               e_usbHostClass    usb class, MSC or UVC
* @retval   void
* @note  
*/
void HAL_USB_InitHost(ENUM_HAL_USB_PORT e_usbPort, uint8_t u8_HostMode)
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

    hUSBHost[e_usbPort].u8_HostMode = u8_HostMode;

    // USBH_Init(&hUSBHost[e_usbPort], USB_HostAppState, (uint8_t)e_usbPort);

    //support MSC
    // USBH_RegisterClass(&hUSBHost[e_usbPort], USBH_MSC_CLASS);

    //support UVC
    // USBH_RegisterClass(&hUSBHost[e_usbPort], USBH_UVC_CLASS);

    //support CDC
    // USBH_RegisterClass(&hUSBHost[e_usbPort], USBH_CDC_CLASS);

    //support MTP
    // USBH_RegisterClass(&hUSBHost[e_usbPort], USBH_MTP_CLASS);

    // USBH_Start(&hUSBHost[e_usbPort]);
}


/**
* @brief  start the USB Video for Application use
* @param  void
* @retval   void
* @note  
*/
HAL_RET_T HAL_USB_StartUVC(STRU_UVC_VIDEO_FRAME_FORMAT *stFrameFormat,
                           uint32_t *u32_frameSize,
                           uint8_t u8_uvcPortId)
{
    HAL_RET_T           u8_ret = HAL_OK;
    uint8_t             u8_frameIndex;
    uint8_t             u8_formatIndex;
    uint8_t             i;
    UVC_SupportedFormatsDef uvc_format;
    uint8_t             u8_frameNum;

    if (u8_uvcPortId > HAL_USB_PORT_NUM)
    {
        DLOG_Error("invalid usb port number");

        return HAL_USB_ERR_USBH_UVC_INVALID_PARAM;
    }

    if ((stFrameFormat->u16_width == 0)||(stFrameFormat->u16_height == 0))
    {
        DLOG_Error("width or height can not be ZERO");

        return HAL_USB_ERR_USBH_UVC_INVALID_PARAM;
    }

    if (stFrameFormat->e_dataType == ENUM_UVC_DATA_H264)
    {
        uvc_format = UVC_SUPPORTED_FORMAT_FRAME_BASED;

        u8_frameNum = USBH_UVC_GetFrameFrameNum(&hUSBHost[u8_uvcPortId]);
    }
    else
    {
        uvc_format = UVC_SUPPORTED_FORMAT_UNCOMPRESSED;

        u8_frameNum = USBH_UVC_GetFrameUncompNum(&hUSBHost[u8_uvcPortId]);
    }

    for (i = 0; i < u8_frameNum; i++)
    {
        if ((stFrameFormat->u16_width == USBH_UVC_GetFrameWidth(i, uvc_format))&&
            (stFrameFormat->u16_height == USBH_UVC_GetFrameHeight(i, uvc_format)))
        {
            break;
        }
    }

    if (i < u8_frameNum)
    {
        u8_frameIndex       = USBH_UVC_GetFrameIndex(i, uvc_format);
        u8_formatIndex      = USBH_UVC_GetFormatIndex(uvc_format);

        if (uvc_format == UVC_SUPPORTED_FORMAT_UNCOMPRESSED)
        {
            *u32_frameSize      = USBH_UVC_GetFrameSize(u8_frameIndex);
        }

        DLOG_Error("u8_frameIndex, u8_formatIndex: %d, %d", u8_frameIndex, u8_formatIndex);

        if (0 == USBH_UVC_StartView(&hUSBHost[u8_uvcPortId], u8_frameIndex, u8_formatIndex, uvc_format))
        {
            DLOG_Error("START UVC OK");
        }
        else
        {
            DLOG_Error("START UVC FAIL");

            u8_ret          = HAL_USB_ERR_USBH_UVC_START_ERROR;
        }
    }
    else
    {
        DLOG_Error("no appropriate format found");

        u8_ret              = HAL_USB_ERR_USBH_UVC_FORMAT_ERROR;
    }

    DMA_init();

    return u8_ret;
}


/**
* @brief  get the latest frame buffer
* @param  uint8_t  *u8_buff    the dest buffer to storage the video frame
* @retval   HAL_USB_ERR_BUFF_IS_EMPTY   : means the buffer pool is empty
*               HAL_OK                                      : means successfully get one video frame
* @note  
*/
HAL_RET_T HAL_USB_UVCGetVideoFrame(uint8_t *u8_buff)
{
    HAL_RET_T                   ret = HAL_USB_ERR_UVC_LAST_FRAME_PREPARING;

    if (g_stUVCUserInterface.u8_userWaiting != UVC_USER_GET_FRAME_IDLE)
    {
        return ret;
    }

    g_stUVCUserInterface.u8_userWaiting = UVC_USER_GET_FRAME_WAITING;
    g_stUVCUserInterface.u8_userBuffer  = u8_buff;

    ret = HAL_OK;

    return ret;
}


/**
* @brief  get the latest frame buffer
* @param      *u32_frameNum      frame number in the frame series
*                   *u32_frameSize      data size of an frame
* @retval       HAL_RET_T             whether the frame is ready to use
* @note  
*/
HAL_RET_T HAL_USB_UVCCheckFrameReady(uint32_t *u32_frameNum,
                                     uint32_t *u32_frameSize)
{
    if (g_stUVCUserInterface.u8_userWaiting == UVC_USER_GET_FRAME_FINISHED)
    {
        *u32_frameNum       = g_stUVCUserInterface.u32_frameIndex;
        *u32_frameSize      = g_stUVCUserInterface.u32_frameLen;

        g_stUVCUserInterface.u8_userWaiting = UVC_USER_GET_FRAME_IDLE;

        return HAL_OK;
    }
    else
    {
        return HAL_USB_ERR_USBH_UVC_FRAME_NOT_READY;
    }
}


/**
* @brief  get formats the camera support
* @param  STRU_UVC_VIDEO_FRAME_FORMAT *stVideoFrameFormat
* @retval   void
* @note  
*/
void HAL_USB_UVCGetVideoFormats(STRU_UVC_SUPPORT_FORMAT_LIST *stVideoFrameFormat)
{
    uint8_t         i;
    uint8_t         j;
    uint8_t         u8_uvcPortId;
    uint8_t         u8_frameNum = 0;

    u8_uvcPortId    = HAL_USB_GetUVCPortId();

    if (u8_uvcPortId > HAL_USB_PORT_NUM)
    {
        DLOG_Error("invalid usb port number");

        return;
    }

    u8_frameNum = USBH_UVC_GetFrameUncompNum(&hUSBHost[u8_uvcPortId]);

    if (u8_frameNum > 0)
    {
        DLOG_Info("YUV Formats:");

        for (i = 0; i < u8_frameNum; i++)
        {
            stVideoFrameFormat->st_uvcFrameFormat[i].u16_height = USBH_UVC_GetFrameHeight(i, UVC_SUPPORTED_FORMAT_UNCOMPRESSED);
            stVideoFrameFormat->st_uvcFrameFormat[i].u16_width  = USBH_UVC_GetFrameWidth(i, UVC_SUPPORTED_FORMAT_UNCOMPRESSED);
            stVideoFrameFormat->st_uvcFrameFormat[i].e_dataType = ENUM_UVC_DATA_YUV;

            (stVideoFrameFormat->u16_frameNum)++;

            if (stVideoFrameFormat->u16_frameNum >= HAL_USB_UVC_MAX_FRAME_FORMATS_NUM)
            {
                DLOG_Error("exceed the max number for frame formats");

                return;
            }

            DLOG_Info("i: %d, width: %d, height: %d",
                      i,
                      stVideoFrameFormat->st_uvcFrameFormat[i].u16_width,
                      stVideoFrameFormat->st_uvcFrameFormat[i].u16_height);
        }
    }

    u8_frameNum = USBH_UVC_GetFrameFrameNum(&hUSBHost[u8_uvcPortId]);

    if (u8_frameNum > 0)
    {
        DLOG_Info("H264 Formats:");

        for (j = 0; j < u8_frameNum; j++)
        {
            stVideoFrameFormat->st_uvcFrameFormat[j+i].u16_height = USBH_UVC_GetFrameHeight(j, UVC_SUPPORTED_FORMAT_FRAME_BASED);
            stVideoFrameFormat->st_uvcFrameFormat[j+i].u16_width  = USBH_UVC_GetFrameWidth(j, UVC_SUPPORTED_FORMAT_FRAME_BASED);
            stVideoFrameFormat->st_uvcFrameFormat[j+i].e_dataType = ENUM_UVC_DATA_H264;

            (stVideoFrameFormat->u16_frameNum)++;

            if (stVideoFrameFormat->u16_frameNum >= HAL_USB_UVC_MAX_FRAME_FORMATS_NUM)
            {
                DLOG_Error("exceed the max number for frame formats");

                return;
            }

            DLOG_Info("i: %d, width: %d, height: %d",
                      i,
                      stVideoFrameFormat->st_uvcFrameFormat[j+i].u16_width,
                      stVideoFrameFormat->st_uvcFrameFormat[j+i].u16_height);
        }
    }
}


/**
* @brief  get the control items supported by Processing Unit, such as white balance, hue, and so on
* @param  void
* @retval   uint32_t, bit maps
* @note  
*/
uint32_t HAL_USB_GetUVCProcUnitControls(void)
{
    uint32_t        ret;

    ret = USBH_UVC_GetProcUnitControls();

    return ret;
}


/**
* @brief  get the control items supported by Extension Unit
* @param  void
* @retval   uint32_t, bit maps
* @note  
*/
uint32_t HAL_USB_GetUVCExtUnitControls(void)
{
    uint32_t        ret;

    ret = USBH_UVC_GetExtUnitControls();

    return ret;
}


/**
* @brief  get the UVC Header Info, used for PAD to recognize a new FRAME
* @param  STRU_UVC_VIDEO_FRAME_FORMAT *stFrameFormat, frame format info
*               uint32_t *header_size  get the size of header
* @retval   uint8_t *  header address
* @note  
*/
uint8_t *HAL_USB_GetUVCHeader(STRU_UVC_VIDEO_FRAME_FORMAT *stFrameFormat, uint32_t *header_size)
{
    // set header of image
    // header format:
    // byte0 byte1 byte2 byte3 byte4 byte5 byte6 byte7 byte8   byte9   byte10 byte11
    // 0x00  0x00  0x00  0x00  0xFF  0xFF  0xFF  0xFF  format  pixel     reserved
    // format:  1: YUV       2: Y only
    // pixel:   1: 160*120   2: 320*240
    g_u8UVCHeader[0]            = 0x00;
    g_u8UVCHeader[1]            = 0x00;
    g_u8UVCHeader[2]            = 0x00;
    g_u8UVCHeader[3]            = 0x00;
    g_u8UVCHeader[4]            = 0xFF;
    g_u8UVCHeader[5]            = 0xFF;
    g_u8UVCHeader[6]            = 0xFF;

    if (stFrameFormat->e_dataType == ENUM_UVC_DATA_Y)
    {
        g_u8UVCHeader[7]        = 0x02;
    }
    else
    {
        g_u8UVCHeader[7]        = 0x01;
    }

    g_u8UVCHeader[8]            = (uint8_t)stFrameFormat->u16_width;
    g_u8UVCHeader[9]            = (uint8_t)(stFrameFormat->u16_width >> 8);

    g_u8UVCHeader[10]           = (uint8_t)stFrameFormat->u16_height;
    g_u8UVCHeader[11]           = (uint8_t)(stFrameFormat->u16_height >> 8);

    *header_size                = sizeof(g_u8UVCHeader);

    return g_u8UVCHeader;
}


/**
* @brief    configure the USB Controller to enter into TEST MODE
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_EnterUSBHostTestMode(void)
{
    USB_LL_EnterHostTestMode(USB_OTG0_HS);
}


/*
 * @brief    transfer UVC Data To Ground
 * @param  *buff                    UVC Data Buffer
                  dataLen                data size of a UVC frame
                  width                    frame width
                  height                   frame height
                  e_UVCDataType     YUV or Y only
 * @retval   void
 * @note  
 */
void HAL_USB_TransferUVCToGrd(uint8_t *buff,
                             uint32_t dataLen,
                             STRU_UVC_VIDEO_FRAME_FORMAT *stFrameFormat)
{
    uint8_t                *u8_header;
    uint32_t                u32_headerSize;
    uint32_t                u32_bufferLevel;
    uint32_t                i;

    u32_bufferLevel = HAL_SRAM_GetBypassBufferLevel(1);
    /* convert word unit to byte unit */

    if (u32_bufferLevel <= (dataLen >> 1))
    {
        u8_header = HAL_USB_GetUVCHeader(stFrameFormat, &u32_headerSize);

        memcpy((void *)VIDEO_BYPASS_CHANNEL_1_DEST_ADDR, (void *)u8_header, u32_headerSize);

        memcpy((void *)(VIDEO_BYPASS_CHANNEL_1_DEST_ADDR + u32_headerSize), (void *)buff, dataLen);
    }

    return;
}


ENUM_HAL_USB_HOST_CLASS HAL_USB_CurUsbClassType(uint8_t port_id)
{
    USBH_ClassTypeDef           *activeClass = NULL;
    ENUM_HAL_USB_HOST_CLASS      enHostClass;

    activeClass            = hUSBHost[port_id].pActiveClass;

    if (NULL == activeClass)
    {
        DLOG_Error("active class is NULL");
        return enHostClass;
    }

    switch (activeClass->ClassCode)
    {
    case USB_MSC_CLASS:
        enHostClass        = HAL_USB_HOST_CLASS_MSC;
        break;

    case UVC_CLASS:
        enHostClass        = HAL_USB_HOST_CLASS_UVC;
        break;

    default:
        enHostClass        = HAL_USB_HOST_CLASS_MAX;
        break;
    }

    return enHostClass;
}


uint8_t HAL_USB_GetUVCPortId(void)
{
    USBH_ClassTypeDef      *activeClass = NULL;
    uint8_t                 u8_uvcPortId = HAL_USB_PORT_NUM;

    if (g_u8UVCPortId > HAL_USB_PORT_NUM)
    {
        return HAL_USB_PORT_NUM;
    }

    activeClass             = hUSBHost[g_u8UVCPortId].pActiveClass;

    if (activeClass != NULL)
    {
        if (activeClass->ClassCode == UVC_CLASS)
        {
            u8_uvcPortId = g_u8UVCPortId;
        }
    }

    return u8_uvcPortId;
}


uint8_t HAL_USB_GetMSCPort(void)
{
    return g_mscPortId;
}


HAL_RET_T HAL_USB_HOST_SetUVCAttr(ENUM_HAL_UVC_ATTRIBUTE_INDEX uvc_attr_index,
                                  int32_t uvc_attr_value)
{
    uint8_t     u8_uvcPortId = HAL_USB_PORT_0;

    u8_uvcPortId = HAL_USB_GetUVCPortId();

    if (u8_uvcPortId >= HAL_USB_PORT_NUM)
    {
        DLOG_Error("get uvc port error");

        return HAL_USB_ERR_PORT_INVALID;
    }

    if (0 != USBH_UVC_SetUVCAttrInterface(&hUSBHost[u8_uvcPortId], (uint8_t)uvc_attr_index, uvc_attr_value))
    {
        DLOG_Error("UVC Attribution not suppoprted");

        return HAL_USB_ERR_USBH_UVC_INVALID_PARAM;
    }

    return HAL_OK;
}


HAL_RET_T HAL_USB_HOST_GetUVCAttr(ENUM_HAL_UVC_ATTRIBUTE_INDEX uvc_attr_index,
                                ENUM_HAL_UVC_GET_ATTRIBUTE_TYPE uvc_attr_type,
                                int32_t *uvc_attr_value)
{
    uint8_t     u8_uvcPortId = HAL_USB_PORT_0;
    int8_t      ret;

    u8_uvcPortId = HAL_USB_GetUVCPortId();

    if (u8_uvcPortId >= HAL_USB_PORT_NUM)
    {
        DLOG_Error("get uvc port error");

        return HAL_USB_ERR_PORT_INVALID;
    }

    ret = USBH_UVC_GetUVCAttrInterface(&hUSBHost[u8_uvcPortId],
                                      (uint8_t)uvc_attr_index,
                                      (uint8_t)uvc_attr_type,
                                      uvc_attr_value);

    if (ret != 0)
    {
        DLOG_Error("UVC Attribution not suppoprted");

        return HAL_USB_ERR_USBH_UVC_INVALID_PARAM;
    }

    return HAL_OK;
}


ENUM_HAL_USB_NETCARD_STATE HAL_USB_NetDeviceGetState(void)
{
    CDC_StateTypeDef     state;

    state = USBH_CDC_GetDeviceState(&hUSBHost[g_cdcPortId]);

    if (state == CDC_IDLE_STATE)
    {
        return ENUM_USB_NETCARD_NOT_CONNECTED;
    }
    else if ((state == CDC_DEVICE_PROBE)||
        (state == CDC_DEVICE_PROBE_FINISHED)||
        (state == CDC_DEVICE_DOWN))
    {
        return ENUM_USB_NETCARD_NOT_ACTIVE;
    }
    else if ((state == CDC_TRANSFER_DATA)||
             (state == CDC_DEVICE_UP))
    {
        return ENUM_USB_NETCARD_ACTIVE;
    }
    else
    {
        return ENUM_USB_NETCARD_NOT_CONNECTED;
    }

}



HAL_RET_T HAL_USB_NetDeviceUp(ENUM_HAL_USB_NETCARD_MODE netcard_mode)
{
    USBH_StatusTypeDef      ret;

    if (USBH_OK != USBH_CDC_DeviceUp(&hUSBHost[g_cdcPortId], (uint8_t)netcard_mode))
    {
        return HAL_BUSY;
    }

    return HAL_OK;
}


void HAL_USB_NetDeviceDown(void)
{
    USBH_CDC_DeviceDown(&hUSBHost[g_cdcPortId]);
}


HAL_RET_T HAL_USB_NetDeviceSend(uint16_t data_len, uint8_t *data_buf)
{
    if (USBH_OK == USBH_CDC_SendData(&hUSBHost[g_cdcPortId], data_len, data_buf))
    {
        return HAL_OK;
    }
    else
    {
        DLOG_Error("usb net card is sending data");

        return HAL_USB_BUSY;
    }
}


void HAL_USB_NetDeviceRecv(void (*net_device_recv_handler)(void *, uint32_t))
{
    USBH_CDC_RegisterReceiveCallback(&hUSBHost[g_cdcPortId], net_device_recv_handler);
}


void HAL_USB_NetDeviceGetMacAddr(uint8_t *mac_address)
{
    memcpy((void *)mac_address,
           (void *)USBH_CDC_GetMacAddress(&hUSBHost[g_cdcPortId]),
           6);
}


void HAL_USB_NetDeviceSetMacAddr(uint8_t *mac_address)
{
    USBH_CDC_SetMacAddress(&hUSBHost[g_cdcPortId], mac_address);
}


HAL_RET_T HAL_USB_GetIPCameraMacAddress(uint8_t *ipcamera_mac_ddr)
{
    HAL_RET_T      ret;

    ret = USBH_CDC_GetIPCameraMacAddress(&hUSBHost[g_cdcPortId], ipcamera_mac_ddr);

    if (ret)
    {
        return HAL_OK;
    }
    else
    {
        return HAL_USB_ERR_DEVICE_TIMEOUT;
    }
}


void HAL_USB_SetIPCameraMacAddress(uint8_t *ipcamera_mac_ddr)
{
    USBH_CDC_SetIPCameraMacAddress(&hUSBHost[g_cdcPortId], ipcamera_mac_ddr);
}


HAL_RET_T HAL_USB_CheckNetLineConnect(void)
{
    if (1 == USBH_CDC_GetNetLineState(&hUSBHost[g_cdcPortId]))
    {
        return HAL_OK;
    }
    else
    {
        return HAL_USB_ERR_NET_LINE_DISCONNECT;
    }
}

HAL_RET_T HAL_USB_HostSendCtrl(uint8_t *buff, uint32_t u32_len, uint8_t u8_portId)
{
    // if(u8_portId >= HAL_USB_PORT_NUM)
    // {
        return HAL_USB_ERR_PORT_INVALID;
    // }

    // if(hUSBHost[u8_portId].pActiveClass != NULL)
    // {
    //     if(0 == strcmp(hUSBHost[u8_portId].pActiveClass->Name, "MTP"))
    //     {
    //         // if(0 == USBH_MTP_Send(buff, u32_len))
    //         // {
    //         //     return HAL_OK;
    //         // }
    //         // else
    //         // {
    //         //     return HAL_USB_ERR_DEVICE_NOT_CONGIURED;
    //         // }
    //     }
    //     else// only mtp now
    //     {
    //         return HAL_NOT_INITED;
    //     }
    // }
    // else
    // {
    //     return HAL_NOT_INITED;
    // }
}



HAL_RET_T HAL_USB_AOA_Set_String(ENUM_AOA_STRING_ID acc_id, uint8_t *string, int len)
{
	if (string == NULL || len <= 0)
		return HAL_NOT_INITED;

	USBH_AOA_Set_String(acc_id, string, len);

	return HAL_OK;
}