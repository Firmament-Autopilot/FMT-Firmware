#include "usbh_uvc.h"
#include "debuglog.h"
#include "drv_systick.h"
#include "dma.h"
#include "cpu_info.h"
#include "sram_sky.h"
#include "memory_itcm.h"
#include "memory.h"

USBH_ClassTypeDef  UVC_Class = 
{
  "UVC",
  UVC_CLASS,  
  USBH_UVC_InterfaceInit,
  USBH_UVC_InterfaceDeInit,
  USBH_UVC_ClassRequest,
  USBH_UVC_Process,
  USBH_UVC_SOFProcess,
  NULL,
};

UVC_HandleTypeDef                    g_stUVCHandle;
USBH_UVCFrameBufferTypeDef          *g_UVCVideoBuffer = NULL;
volatile UVC_BuffStateTypeDef        g_enumUVCBuffState[UVC_VIDEO_BUFF_FRAME_NUM];
uint32_t                             g_u32UVCVideoBuffSizePerFrame;

USBH_UVCUserInterface                       g_stUVCUserInterface = {0};
USBH_UVCFormatUncompressedTypeDef           g_stUVCFormatUncomp = {0};
USBH_UVCFrameUncompressedTypeDef            g_stUVCFrameUncomp[USB_UVC_MAX_FRAME_FORMATS_NUM] = {0};
USBH_UVCFormatFrameBasedTypeDef             g_stUVCFormatFrameBased = {0};
USBH_UVCFrameFrameBasedTypeDef              g_stUVCFrameFrameBased[USB_UVC_MAX_FRAME_FRAME_BASED_NUM] = {0};
USBH_VCProcessingUnitInterfaceDescriptor    g_stProcessingUnitDesc;
USBH_VCExtensionUnitInterfaceDescriptor     g_stExtensionUnitDesc;
USBH_InterfaceDescTypeDef                   g_stVideoStreamingDesc[USBH_MAX_NUM_ENDPOINT_INTERFACES];
USBH_UVCInterfaceDescriptor                 g_stUVCSupportedFormatInterface[UVC_SUPPORTED_FORMAT_NUM];

uint8_t                 g_cur_mem[28];
uint8_t                 g_max_mem[28];
uint8_t                 g_min_mem[28];
uint8_t                 g_u8UVCPortId;


USBH_UVCAttrCtrl        g_stUVCAttrCtrl[USB_UVC_PARAM_MAX_NUM] =
{
 /* cur  min  max  res  info  def  length  selector*/
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_BRIGHTNESS_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_CONTRAST_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_HUE_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_SATURATION_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_SHARPNESS_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_GAMMA_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_WHITE_BALANCE_TEMP_CONTROL},
    {1,  1,  1,  1,  1,  1,  4,  USB_UVC_PU_WHITE_BALANCE_COMP_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_BACKLIGHT_COMPENSATION_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_GAIN_CONTROL},
    {1,  0,  0,  0,  1,  1,  1,  USB_UVC_PU_POWER_LINE_FREQUENCY_CONTROL},
    {1,  0,  0,  0,  1,  1,  1,  USB_UVC_PU_HUE_AUTO_CONTROL},
    {1,  0,  0,  0,  1,  1,  1,  USB_UVC_PU_WHITE_BALANCE_TEMP_AUTO_CONTROL},
    {1,  0,  0,  0,  1,  1,  1,  USB_UVC_PU_WHITE_BALANCE_COMP_AUTO_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_DIGITAL_MULTIPLIER_CONTROL},
    {1,  1,  1,  1,  1,  1,  2,  USB_UVC_PU_DIGITAL_MULTIPLIER_LIMIT_CONTROL}
};


static USBH_StatusTypeDef USBH_UVC_InterfaceInit (USBH_HandleTypeDef *phost)
{
    USBH_StatusTypeDef      status = USBH_FAIL ;
    UVC_HandleTypeDef      *UVC_Handle;
    uint8_t                 interface;
    uint8_t                 i;
    uint8_t                 j;

    // ctrl interface
    interface = USBH_FindInterface(phost, 14, 1, 0);

    if(interface == 0xFF) /* Not Valid Interface */
    {
        DLOG_Warning("Cannot Find the interface for %s class.", phost->pActiveClass->Name);

        status = USBH_FAIL;
    }
    else
    {
        USBH_SelectInterface(phost, interface);

        phost->pActiveClass->pData = &g_stUVCHandle;
        UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;
        USBH_memset(UVC_Handle, 0, sizeof(UVC_HandleTypeDef));

        UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

        UVC_Handle->CtrlEp      = (phost->device.CfgDesc.Itf_Desc[phost->device.current_interface].Ep_Desc[0].bEndpointAddress);
        UVC_Handle->CtrlEpSize  = phost->device.CfgDesc.Itf_Desc[phost->device.current_interface].Ep_Desc[0].wMaxPacketSize;

        UVC_Handle->CtrlPipe    = USBH_AllocPipe(phost, UVC_Handle->CtrlEp);

        /* Open the new channels */
        USBH_OpenPipe(phost,
                      UVC_Handle->CtrlPipe,
                      UVC_Handle->CtrlEp,
                      phost->device.address,
                      phost->device.speed,
                      USB_EP_TYPE_INTR,
                      UVC_Handle->CtrlEpSize);

        USBH_LL_SetToggle(phost, UVC_Handle->CtrlPipe, 0);

        // video interface
        USBH_UVC_GetVideoFormatList(phost);

        for (i = 0; i < UVC_SUPPORTED_FORMAT_NUM; i++)
        {
            if (UVC_Handle->u8_formatSupported[i])
            {
                UVC_Handle->VideoEp[i]      = USBH_UVC_GetVideoEpAddr((UVC_SupportedFormatsDef)i);

                /* check whether this endpoint has been alloced */
                for (j = 0; j < i; j++)
                {
                    if (UVC_Handle->VideoEp[i] == UVC_Handle->VideoEp[j])
                    {
                        UVC_Handle->VideoEpSize[i]  = UVC_Handle->VideoEpSize[j];
                        UVC_Handle->VideoPipe[i]    = UVC_Handle->VideoPipe[j];

                        break;
                    }
                }
                /* this is a new endpoint */
                if (j >= i)
                {
                    UVC_Handle->VideoEpSize[i]  = UVC_VIDEO_EP_MAX_SIZE;
                    UVC_Handle->VideoPipe[i]    = USBH_AllocPipe(phost, UVC_Handle->VideoEp[i]);

                    USBH_OpenPipe(phost,
                                  UVC_Handle->VideoPipe[i],
                                  UVC_Handle->VideoEp[i],
                                  phost->device.address,
                                  phost->device.speed,
                                  USB_EP_TYPE_ISOC,
                                  UVC_Handle->VideoEpSize[i]);

                    DLOG_Info("open pipe: %d, 0x%02x, %d", i, UVC_Handle->VideoEp[i], UVC_Handle->VideoPipe[i]);

                    USBH_LL_SetToggle(phost, UVC_Handle->VideoPipe[i], 0);
                }
            }
        }

        phost->isocURBDone  = USBH_UVC_UrbDone;

        g_u8UVCPortId       = phost->id;

        status = USBH_OK;
    }

    return status;
}


USBH_StatusTypeDef USBH_UVC_InterfaceDeInit (USBH_HandleTypeDef *phost)
{
    uint8_t                     i;
    UVC_HandleTypeDef          *UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    USBH_ClosePipe(phost, UVC_Handle->CtrlPipe);
    USBH_FreePipe(phost, UVC_Handle->CtrlPipe);
    UVC_Handle->CtrlPipe = 0;

    for (i = UVC_SUPPORTED_FORMAT_UNCOMPRESSED;
         i < UVC_SUPPORTED_FORMAT_NUM;
         i++)
    {
        if (UVC_Handle->VideoPipe[i] != 0)
        {
            USBH_ClosePipe(phost, UVC_Handle->VideoPipe[i]);
            USBH_FreePipe(phost, UVC_Handle->VideoPipe[i]);
            UVC_Handle->VideoPipe[i] = 0;
        }
    }

    USBH_memset((void *)UVC_Handle, 0, sizeof(UVC_HandleTypeDef));
    phost->pActiveClass->pData = 0;

    if (g_UVCVideoBuffer != NULL)
    {
        if (NULL != g_UVCVideoBuffer->u8_rawData)
        {
            free_itcm_safe((g_UVCVideoBuffer->u8_rawData));

            g_UVCVideoBuffer->u8_rawData = NULL;

            DLOG_Error("free raw data");
        }

        if (NULL != g_UVCVideoBuffer->u8_frameBasedRecvBuff)
        {
            rt_free(g_UVCVideoBuffer->u8_frameBasedRecvBuff);

            g_UVCVideoBuffer->u8_frameBasedRecvBuff = NULL;

            DLOG_Error("free h264 data");
        }

        rt_free(g_UVCVideoBuffer);

        g_UVCVideoBuffer = NULL;
    }

    SRAM_SKY_DisableBypassVideoConfig(0);

    return USBH_OK;
}


static USBH_StatusTypeDef USBH_UVC_ClassRequest(USBH_HandleTypeDef *phost)
{
    uint8_t                     i = 0;
    UVC_HandleTypeDef          *UVC_Handle =  (UVC_HandleTypeDef *)phost->pActiveClass->pData;

    while (USBH_BUSY == USBH_SetInterface(phost, 1, 0));

    UVC_Handle->u32_uvcAttributeMask    = USBH_UVC_GetUVCAttributionMask();

    while ((((1<<i)&(UVC_Handle->u32_uvcAttributeMask)) == (1<<i))&&
            (i < USB_UVC_PARAM_MAX_NUM))
    {
        USBH_UVC_GetUVCAttribution(phost, i);

        i++;
    }

    phost->pUser(phost, HOST_USER_CLASS_ACTIVE);

    return USBH_OK;
}


static USBH_StatusTypeDef USBH_UVC_Process (USBH_HandleTypeDef *phost)
{
    UVC_HandleTypeDef        *UVC_Handle;

    UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    if (UVC_Handle->u8_setAttrFlag == 1)
    {
        USBH_UVC_SetUVCAttribution(phost);

        UVC_Handle->u8_setAttrFlag = 0;
    }

    return USBH_OK;
}


static USBH_StatusTypeDef USBH_UVC_SOFProcess (USBH_HandleTypeDef *phost)
{
    return USBH_OK;
}


static void USBH_UVC_Probe(USBH_HandleTypeDef *phost)
{
    UVC_HandleTypeDef        *UVC_Handle =  (UVC_HandleTypeDef *)phost->pActiveClass->pData;
    // USBH_StatusTypeDef        status = USBH_BUSY;
    uint32_t                  default_interval = 0;

    phost->Control.setup.b.wValue.w = 0x0100;
    phost->Control.setup.b.wLength.w = 0x001A;
    phost->Control.setup.b.wIndex.w = 
                    g_stUVCSupportedFormatInterface[UVC_Handle->uvc_format].bInterfaceNumber;

    phost->Control.setup.b.bRequest = UVC_GET_CUR;
    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)g_cur_mem, 26));

    phost->Control.setup.b.bRequest = UVC_GET_MAX;
    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_max_mem) , 26))

    phost->Control.setup.b.bRequest = UVC_GET_MIN;
    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_min_mem) , 26));

    phost->Control.setup.b.bRequest = UVC_SET_CUR;
    phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;

    default_interval = USBH_GetFrameDefaultInterval(UVC_Handle->u8_selFrameIndex,
                                                    UVC_Handle->uvc_format);
    g_cur_mem[2]  = UVC_Handle->u8_selFormatIndex;
    g_cur_mem[3]  = UVC_Handle->u8_selFrameIndex;
    g_cur_mem[4]  = (uint8_t)default_interval;
    g_cur_mem[5]  = (uint8_t)(default_interval>>8);
    g_cur_mem[6]  = (uint8_t)(default_interval>>16);
    g_cur_mem[7]  = (uint8_t)(default_interval>>24);
    g_cur_mem[22] = 0;
    g_cur_mem[23] = 0;
    g_cur_mem[24] = 0;
    g_cur_mem[25] = 0;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_cur_mem) , 26));

    phost->Control.setup.b.bRequest = UVC_GET_CUR;
    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;
    
    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)g_cur_mem, 26));

    phost->Control.setup.b.bRequest = UVC_GET_MAX;
    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_max_mem) , 26));

    phost->Control.setup.b.bRequest = UVC_GET_MIN;
    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_min_mem) , 26));
}


static void USBH_UVC_Commit(USBH_HandleTypeDef *phost)
{
    UVC_HandleTypeDef           *UVC_Handle =  (UVC_HandleTypeDef *)phost->pActiveClass->pData;
    uint8_t                     *u8_recvBuff = NULL;
    uint32_t                     u32_epSize = 0;

    phost->Control.setup.b.bRequest = UVC_GET_CUR;
    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;
    phost->Control.setup.b.wValue.w = 0x0100;
    phost->Control.setup.b.wIndex.w = 
                    g_stUVCSupportedFormatInterface[UVC_Handle->uvc_format].bInterfaceNumber;
    phost->Control.setup.b.wLength.w = 0x001A;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_cur_mem) , 26));

    phost->Control.setup.b.bRequest = UVC_SET_CUR;
    phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;
    phost->Control.setup.b.wValue.w = 0x0100;
    phost->Control.setup.b.wIndex.w = 
                    g_stUVCSupportedFormatInterface[UVC_Handle->uvc_format].bInterfaceNumber;
    phost->Control.setup.b.wLength.w = 0x001A;

    g_cur_mem[22] = 0;
    g_cur_mem[23] = 0;
    g_cur_mem[24] = 0;
    g_cur_mem[25] = 0;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_cur_mem) , 26));

    phost->Control.setup.b.bRequest = UVC_GET_CUR;
    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;
    phost->Control.setup.b.wValue.w = 0x0100;
    phost->Control.setup.b.wIndex.w = 
                    g_stUVCSupportedFormatInterface[UVC_Handle->uvc_format].bInterfaceNumber;
    phost->Control.setup.b.wLength.w = 0x001A;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_cur_mem) , 26));

    u32_epSize  = g_cur_mem[22]+
                  (g_cur_mem[23]<<8)+
                  (g_cur_mem[24]<<16)+
                  (g_cur_mem[25]<<24);

    UVC_Handle->u8_selAltInterface = USBH_SelAltInterfaceForCommit(u32_epSize, phost);

    phost->Control.setup.b.bRequest = UVC_SET_CUR;
    phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;
    phost->Control.setup.b.wValue.w = 0x0200;
    phost->Control.setup.b.wIndex.w = 
                    g_stUVCSupportedFormatInterface[UVC_Handle->uvc_format].bInterfaceNumber;
    phost->Control.setup.b.wLength.w = 0x001A;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(g_cur_mem) , 26));

    while (USBH_BUSY == USBH_SetInterface(phost,
                                          UVC_Handle->u8_selInterface,
                                          UVC_Handle->u8_selAltInterface))
    {
        // ar_osDelay(1);
        HAL_Delay(1);
    }

    u8_recvBuff         = USBH_GetRecvBuffer(phost);

    if (NULL != u8_recvBuff)
    {
        USBH_IsocReceiveData(phost, u8_recvBuff, UVC_VIDEO_MAX_SIZE_PER_SOF, UVC_Handle->VideoPipe[UVC_Handle->uvc_format]);
    }
}


uint8_t USBH_UVC_StartView(USBH_HandleTypeDef *phost,
                          uint8_t u8_frameIndex,
                          uint8_t u8_formatIndex,
                          UVC_SupportedFormatsDef uvc_format)
{
    UVC_HandleTypeDef          *UVC_Handle =  (UVC_HandleTypeDef *)phost->pActiveClass->pData;
    // uint8_t                    *u8_recvBuff = NULL;

    UVC_Handle->u8_selFrameIndex        = u8_frameIndex;
    UVC_Handle->u8_selFormatIndex       = u8_formatIndex;
    UVC_Handle->uvc_format              = uvc_format;
    UVC_Handle->u8_selInterface         = g_stUVCSupportedFormatInterface[uvc_format].bInterfaceNumber;

    if (UVC_Handle->u8_startUVCFlag == USB_UVC_STARTED)
    {
        UVC_Handle->u8_startUVCFlag = USB_UVC_SWITCH_PIXEL;

        return 1;
    }
    else
    {
        if (UVC_Handle->u8_startUVCFlag == USB_UVC_SWITCH_PIXEL)
        {
            while (USBH_BUSY == USBH_SetInterface(phost, 1, 0));
        }

        UVC_Handle->u8_startUVCFlag = USB_UVC_STARTED;
    }

    if (g_UVCVideoBuffer == NULL)
    {
        g_UVCVideoBuffer = (USBH_UVCFrameBufferTypeDef *)rt_malloc(sizeof(USBH_UVCFrameBufferTypeDef));

        if (NULL == g_UVCVideoBuffer)
        {
            DLOG_Error("malloc error");

            return 1;
        }

        memset((void *)g_UVCVideoBuffer, 0, sizeof(USBH_UVCFrameBufferTypeDef));
    }

    if (uvc_format == UVC_SUPPORTED_FORMAT_UNCOMPRESSED)
    {
        g_u32UVCVideoBuffSizePerFrame   = USBH_UVC_GetFrameSize(u8_frameIndex);

        if (NULL == g_UVCVideoBuffer->u8_rawData)
        {
            g_UVCVideoBuffer->u8_rawData = (uint8_t *)malloc_itcm_safe(g_u32UVCVideoBuffSizePerFrame + 4096);

            if (NULL == g_UVCVideoBuffer->u8_rawData)
            {
                DLOG_Error("error to malloc memory in ITCM for YUV");

                rt_free(g_UVCVideoBuffer);

                g_UVCVideoBuffer = NULL;

                return 1;
            }
        }
        else
        {
            free_itcm_safe(g_UVCVideoBuffer->u8_rawData);

            g_UVCVideoBuffer->u8_rawData = NULL;

            g_UVCVideoBuffer->u8_rawData = (uint8_t *)malloc_itcm_safe(g_u32UVCVideoBuffSizePerFrame + 4096);

            if (NULL == g_UVCVideoBuffer->u8_rawData)
            {
                DLOG_Error("remalloc memory in ITCM error");

                return 1;
            }
        }
    }
    else
    {
        if (NULL == g_UVCVideoBuffer->u8_frameBasedRecvBuff)
        {
            g_UVCVideoBuffer->u8_frameBasedRecvBuff = (uint8_t *)rt_malloc(UVC_FRAME_BASED_RECV_SIZE);

            if (NULL == g_UVCVideoBuffer->u8_frameBasedRecvBuff)
            {
                DLOG_Error("error to malloc memory in ITCM for H264 recv buffer");

                return 1;
            }
        }

        if (NULL == g_UVCVideoBuffer->u8_rawData)
        {
            g_UVCVideoBuffer->u8_rawData = (uint8_t *)malloc_itcm_safe(UVC_FRAME_BASED_BUFF_SIZE);

            if (NULL == g_UVCVideoBuffer->u8_rawData)
            {
                DLOG_Error("error to malloc memory in ITCM for H264 rawData");

                if (g_UVCVideoBuffer->u8_frameBasedRecvBuff != NULL)
                {
                    rt_free(g_UVCVideoBuffer->u8_frameBasedRecvBuff);

                    g_UVCVideoBuffer->u8_frameBasedRecvBuff = NULL;
                }

                return 1;
            }
        }

        SRAM_SKY_EnableBypassVideoConfig(0);
    }

    g_UVCVideoBuffer->u32_rawDataLen       = 0;

    g_stUVCUserInterface.u32_frameIndex    = 0;
    g_stUVCUserInterface.u32_frameLen      = 0;
    g_stUVCUserInterface.u8_userBuffer     = NULL;
    g_stUVCUserInterface.u8_userWaiting    = UVC_USER_GET_FRAME_IDLE;

    USBH_UVC_Probe(phost);

    USBH_UVC_Commit(phost);

    return 0;
}

static void USBH_UVC_UrbDone(USBH_HandleTypeDef *phost)
{
    UVC_HandleTypeDef           *UVC_Handle;
    uint32_t                     u32_recvSize;
    static uint32_t              u32_frameNumber = 0;
    uint8_t                     *u8_recvBuff = NULL;
    USBH_UVCFrameBufferTypeDef  *stUVCFrameBuffer = NULL;
    uint8_t                      i;
    uint8_t                      isLastPacket = 0;
    uint32_t                     srcAddr;
    uint32_t                     destAddr;
    static uint8_t              *bypass_address = (uint8_t *)0xB1000000;

    UVC_Handle          = (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    stUVCFrameBuffer    = USBH_GetFrameBuffer();

    if (NULL == stUVCFrameBuffer)
    {
        DLOG_Error("no frame buffer inintialated");

        return;
    }

    u8_recvBuff         = USBH_GetRecvBuffer(phost);

    if (NULL == u8_recvBuff)
    {
        return;
    }

    if (u8_recvBuff[0] != UVC_HEADER_SPECIAL_CHAR)
    {
        DLOG_Error("this is not UVC package: 0x%08x", u8_recvBuff);
    }
    else
    {
        u32_recvSize = USBH_LL_GetLastXferSize(phost, UVC_Handle->VideoPipe[UVC_Handle->uvc_format]);

        if (u32_recvSize > UVC_HEADER_SIZE)
        {
            u32_recvSize -= UVC_HEADER_SIZE;

            isLastPacket = u8_recvBuff[1];

            if (UVC_Handle->uvc_format == UVC_SUPPORTED_FORMAT_UNCOMPRESSED)
            {
                /* recover the last 12 bytes occupied by UVC header */
                if (stUVCFrameBuffer->u32_rawDataLen != 0)
                {
                    for (i = 0; i < UVC_HEADER_SIZE; i++)
                    {
                        u8_recvBuff[i] = stUVCFrameBuffer->u8_backup[i];
                    }
                }

                stUVCFrameBuffer->u32_rawDataLen += u32_recvSize;

                if (UVC_HEADER_FRAME_END != (UVC_HEADER_FRAME_END & isLastPacket))
                {
                    /* buffer size is overflow, refill this buffer */
                    if (stUVCFrameBuffer->u32_rawDataLen >= g_u32UVCVideoBuffSizePerFrame)
                    {
                        stUVCFrameBuffer->u32_rawDataLen        = 0;
                    }

                    for (i = 0; i < UVC_HEADER_SIZE; i++)
                    {
                        stUVCFrameBuffer->u8_backup[i]  = *((stUVCFrameBuffer->u8_rawData + stUVCFrameBuffer->u32_rawDataLen) + i);
                    }
                }
                else
                {
                    if (stUVCFrameBuffer->u32_rawDataLen == g_u32UVCVideoBuffSizePerFrame)
                    {
                        u32_frameNumber++;

                        if (((g_stUVCUserInterface.u8_userWaiting == UVC_USER_GET_FRAME_WAITING)&&(g_stUVCUserInterface.u8_userBuffer != NULL))||
                             (UVC_Handle->u8_setAttrFlag))
                        {
                            srcAddr     = (uint32_t)peripheralAddrConvert((uint32_t)(stUVCFrameBuffer->u8_rawData + UVC_HEADER_SIZE));
                            destAddr    = (uint32_t)peripheralAddrConvert((uint32_t)g_stUVCUserInterface.u8_userBuffer);

                            if (0 == DMA_forDriverTransfer(srcAddr,
                                                           destAddr,
                                                           stUVCFrameBuffer->u32_rawDataLen,
                                                           DMA_blocked,
                                                           0xFFFF))
                            {
                                CPUINFO_DCacheInvalidateByAddr((uint32_t *)g_stUVCUserInterface.u8_userBuffer,
                                                                stUVCFrameBuffer->u32_rawDataLen);

                                g_stUVCUserInterface.u8_userWaiting = UVC_USER_GET_FRAME_FINISHED;
                                g_stUVCUserInterface.u32_frameIndex = u32_frameNumber;
                                g_stUVCUserInterface.u32_frameLen   = stUVCFrameBuffer->u32_rawDataLen;

                                USBH_LL_NotifyUSBHStateChange(phost);
                            }
                        }
                    }

                    stUVCFrameBuffer->u32_rawDataLen = 0;
                }
            }
            else
            {
                memcpy((void *)(stUVCFrameBuffer->u8_rawData + stUVCFrameBuffer->u32_rawDataLen),
                       (void *)(u8_recvBuff + UVC_HEADER_SIZE),
                       u32_recvSize);

                stUVCFrameBuffer->u32_rawDataLen += u32_recvSize;

                if (UVC_HEADER_FRAME_END == (UVC_HEADER_FRAME_END & isLastPacket))
                {
                    if (UVC_Handle->u8_setAttrFlag)
                    {
                        USBH_LL_NotifyUSBHStateChange(phost);
                    }

                    memcpy((void *)bypass_address,
                           (void *)(stUVCFrameBuffer->u8_rawData),
                           stUVCFrameBuffer->u32_rawDataLen);

                    if (bypass_address >= (uint8_t *)0xB1600000)
                    {
                        bypass_address = (uint8_t *)0xB1000000;
                    }

                    stUVCFrameBuffer->u32_rawDataLen = 0;
                }
            }
        }
    }

    if (UVC_Handle->u8_startUVCFlag == USB_UVC_SWITCH_PIXEL)
    {
        DLOG_Error("switch pixel, do not configure receive");

        USBH_LL_NotifyUSBHStateChange(phost);
    }
    else
    {
        u8_recvBuff         = USBH_GetRecvBuffer(phost);

        if (NULL != u8_recvBuff)
        {
            USBH_IsocReceiveData(phost, u8_recvBuff, UVC_VIDEO_MAX_SIZE_PER_SOF, UVC_Handle->VideoPipe[UVC_Handle->uvc_format]);
        }
    }

    return;
}


uint8_t USBH_UVC_GetBuff(void)
{
    uint8_t             i;

    for (i = 0; i < UVC_VIDEO_BUFF_FRAME_NUM; i++)
    {
        if (UVC_VIDEO_BUFF_VALID == USBH_UVC_GetBuffState(i))
        {
            USBH_UVC_SetBuffState(i, UVC_VIDEO_BUFF_IN_USING);

            return i;
        }
    }

    return 0xFF;
}

void USBH_UVC_SetBuffState(uint8_t u8_buffIndex, UVC_BuffStateTypeDef e_buffState)
{
    g_enumUVCBuffState[u8_buffIndex] = e_buffState;
}

static UVC_BuffStateTypeDef USBH_UVC_GetBuffState(uint8_t u8_buffIndex)
{
    return g_enumUVCBuffState[u8_buffIndex];
}


static void  USBH_ParseFormatUncompDesc(uint8_t *buf)
{
    uint8_t                i;

    g_stUVCFormatUncomp.bLength               = *(uint8_t  *) (buf + 0);
    g_stUVCFormatUncomp.bDescriptorType       = *(uint8_t  *) (buf + 1);
    g_stUVCFormatUncomp.bDescriptorSubtype    = *(uint8_t  *) (buf + 2);
    g_stUVCFormatUncomp.bFormatIndex          = *(uint8_t  *) (buf + 3);
    g_stUVCFormatUncomp.bNumFrameDescriptors  = *(uint8_t  *) (buf + 4);

    for (i = 0; i < 16; i++)
    {
        g_stUVCFormatUncomp.guidFormat[i]     = *(uint8_t  *) (buf + (5 + i));
    }

    g_stUVCFormatUncomp.bBitsPerPixel         = *(uint8_t  *) (buf + 21);
    g_stUVCFormatUncomp.bDefaultFrameIndex    = *(uint8_t  *) (buf + 22);
    g_stUVCFormatUncomp.bAspectRatioX         = *(uint8_t  *) (buf + 23);
    g_stUVCFormatUncomp.bAspectRatioY         = *(uint8_t  *) (buf + 24);
    g_stUVCFormatUncomp.bmInterlaceFlags      = *(uint8_t  *) (buf + 25);
    g_stUVCFormatUncomp.bCopyProtect          = *(uint8_t  *) (buf + 26);

    return;
}

static void  USBH_ParseFrameUncompDesc(uint8_t *buf, uint8_t index)
{
    g_stUVCFrameUncomp[index].bLength                    = *(uint8_t  *) (buf + 0);
    g_stUVCFrameUncomp[index].bDescriptorType            = *(uint8_t  *) (buf + 1);
    g_stUVCFrameUncomp[index].bDescriptorSubtype         = *(uint8_t  *) (buf + 2);
    g_stUVCFrameUncomp[index].bFrameIndex                = *(uint8_t  *) (buf + 3);
    g_stUVCFrameUncomp[index].bmCapabilities             = *(uint8_t  *) (buf + 4);
    g_stUVCFrameUncomp[index].wWidth                     = LE16(buf + 5);
    g_stUVCFrameUncomp[index].wHeight                    = LE16(buf + 7);
    g_stUVCFrameUncomp[index].dwMinBitRate               = LE32(buf + 9);
    g_stUVCFrameUncomp[index].dwMaxBitRate               = LE32(buf + 13);
    g_stUVCFrameUncomp[index].dwMaxVideoFrameBufferSize  = LE32(buf + 17);
    g_stUVCFrameUncomp[index].dwDefaultFrameInterval     = LE32(buf + 21);
    g_stUVCFrameUncomp[index].bFrameIntervalType         = *(uint8_t  *) (buf + 25);
    g_stUVCFrameUncomp[index].dwFrameInterval            = LE32(buf + 26);

    return;
}

static void USBH_ParseFormatFrameBasedDesc(uint8_t *buf)
{
    uint8_t             i;

    g_stUVCFormatFrameBased.bLength               = *(uint8_t  *) (buf + 0);
    g_stUVCFormatFrameBased.bDescriptorType       = *(uint8_t  *) (buf + 1);
    g_stUVCFormatFrameBased.bDescriptorSubtype    = *(uint8_t  *) (buf + 2);
    g_stUVCFormatFrameBased.bFormatIndex          = *(uint8_t  *) (buf + 3);
    g_stUVCFormatFrameBased.bNumFrameDescriptors  = *(uint8_t  *) (buf + 4);

    for (i = 0; i < 16; i++)
    {
        g_stUVCFormatFrameBased.guidFormat[i]     = *(uint8_t  *) (buf + (5 + i));
    }

    g_stUVCFormatFrameBased.bBitsPerPixel         = *(uint8_t  *) (buf + 21);
    g_stUVCFormatFrameBased.bDefaultFrameIndex    = *(uint8_t  *) (buf + 22);
    g_stUVCFormatFrameBased.bAspectRatioX         = *(uint8_t  *) (buf + 23);
    g_stUVCFormatFrameBased.bAspectRatioY         = *(uint8_t  *) (buf + 24);
    g_stUVCFormatFrameBased.bmInterlaceFlags      = *(uint8_t  *) (buf + 25);
    g_stUVCFormatFrameBased.bCopyProtect          = *(uint8_t  *) (buf + 26);
    g_stUVCFormatFrameBased.bVariableSize         = *(uint8_t  *) (buf + 27);

    return;
}

static void USBH_ParseFrameFrameBasedDesc(uint8_t *buf, uint8_t index)
{
    g_stUVCFrameFrameBased[index].bLength                   = *(uint8_t  *) (buf + 0);
    g_stUVCFrameFrameBased[index].bDescriptorType           = *(uint8_t  *) (buf + 1);
    g_stUVCFrameFrameBased[index].bDescriptorSubtype        = *(uint8_t  *) (buf + 2);
    g_stUVCFrameFrameBased[index].bFrameIndex               = *(uint8_t  *) (buf + 3);
    g_stUVCFrameFrameBased[index].bmCapabilities            = *(uint8_t  *) (buf + 4);
    g_stUVCFrameFrameBased[index].wWidth                    = LE16(buf + 5);
    g_stUVCFrameFrameBased[index].wHeight                   = LE16(buf + 7);
    g_stUVCFrameFrameBased[index].dwMinBitRate              = LE32(buf + 9);
    g_stUVCFrameFrameBased[index].dwMaxBitRate              = LE32(buf + 13);
    g_stUVCFrameFrameBased[index].dwDefaultFrameInterval    = LE32(buf + 17);
    g_stUVCFrameFrameBased[index].bFrameIntervalType        = *(uint8_t  *) (buf + 21);
    g_stUVCFrameFrameBased[index].dwBytesPerLine            = LE32(buf + 22);
    g_stUVCFrameFrameBased[index].dwFrameInterval[0]        = LE32(buf + 26);
    g_stUVCFrameFrameBased[index].dwFrameInterval[1]        = LE32(buf + 30);
    g_stUVCFrameFrameBased[index].dwFrameInterval[2]        = LE32(buf + 34);
    g_stUVCFrameFrameBased[index].dwFrameInterval[3]        = LE32(buf + 38);
    g_stUVCFrameFrameBased[index].dwFrameInterval[4]        = LE32(buf + 42);
    g_stUVCFrameFrameBased[index].dwFrameInterval[5]        = LE32(buf + 46);
    g_stUVCFrameFrameBased[index].dwFrameInterval[6]        = LE32(buf + 50);

    return;
}

static void  USBH_ParseVideoStreamingDesc(uint8_t *buf, uint8_t index)
{
    g_stVideoStreamingDesc[index].bLength                   = *(uint8_t  *) (buf + 0);
    g_stVideoStreamingDesc[index].bDescriptorType           = *(uint8_t  *) (buf + 1);
    g_stVideoStreamingDesc[index].bInterfaceNumber          = *(uint8_t  *) (buf + 2);
    g_stVideoStreamingDesc[index].bAlternateSetting         = *(uint8_t  *) (buf + 3);
    g_stVideoStreamingDesc[index].bNumEndpoints             = *(uint8_t  *) (buf + 4);
    g_stVideoStreamingDesc[index].bInterfaceClass           = *(uint8_t  *) (buf + 5);
    g_stVideoStreamingDesc[index].bInterfaceSubClass        = *(uint8_t  *) (buf + 6);
    g_stVideoStreamingDesc[index].bInterfaceProtocol        = *(uint8_t  *) (buf + 7);
    g_stVideoStreamingDesc[index].iInterface                = *(uint8_t  *) (buf + 8);
    g_stVideoStreamingDesc[index].Ep_Desc[0].bLength           = *(uint8_t  *) (buf + 9);
    g_stVideoStreamingDesc[index].Ep_Desc[0].bDescriptorType   = *(uint8_t  *) (buf + 10);
    g_stVideoStreamingDesc[index].Ep_Desc[0].bEndpointAddress  = *(uint8_t  *) (buf + 11);
    g_stVideoStreamingDesc[index].Ep_Desc[0].bmAttributes      = *(uint8_t  *) (buf + 12);
    g_stVideoStreamingDesc[index].Ep_Desc[0].wMaxPacketSize    = LE16(buf + 13);
    g_stVideoStreamingDesc[index].Ep_Desc[0].bInterval         = *(uint8_t  *) (buf + 15);

    return;
}

uint8_t USBH_UVC_GetVideoEpAddr(UVC_SupportedFormatsDef uvc_format)
{
    uint8_t                 i;
    uint8_t                 u8_videoEp = 0x81;

    for (i = 0; i < USBH_MAX_NUM_ENDPOINT_INTERFACES; i++)
    {
        if (g_stUVCSupportedFormatInterface[uvc_format].bInterfaceNumber == g_stVideoStreamingDesc[i].bInterfaceNumber)
        {
            break;
        }
    }

    if (i < USBH_MAX_NUM_ENDPOINT_INTERFACES)
    {
        u8_videoEp = g_stVideoStreamingDesc[i].Ep_Desc[0].bEndpointAddress;
    }

    return u8_videoEp;
}

uint16_t USBH_UVC_GetFrameWidth(uint8_t index, UVC_SupportedFormatsDef uvc_format)
{
    if (uvc_format == UVC_SUPPORTED_FORMAT_FRAME_BASED)
    {
        return g_stUVCFrameFrameBased[index].wWidth;
    }
    else
    {
        return g_stUVCFrameUncomp[index].wWidth;
    }
}

uint16_t USBH_UVC_GetFrameHeight(uint8_t index, UVC_SupportedFormatsDef uvc_format)
{
    if (uvc_format == UVC_SUPPORTED_FORMAT_FRAME_BASED)
    {
        return g_stUVCFrameFrameBased[index].wHeight;
    }
    else
    {
        return g_stUVCFrameUncomp[index].wHeight;
    }
}

uint8_t USBH_UVC_GetFrameIndex(uint8_t index, UVC_SupportedFormatsDef uvc_format)
{
    if (uvc_format == UVC_SUPPORTED_FORMAT_FRAME_BASED)
    {
        return g_stUVCFrameFrameBased[index].bFrameIndex;
    }
    else
    {
        return g_stUVCFrameUncomp[index].bFrameIndex;
    }
}

uint8_t USBH_UVC_GetFormatIndex(UVC_SupportedFormatsDef uvc_format)
{
    if (uvc_format == UVC_SUPPORTED_FORMAT_FRAME_BASED)
    {
        return g_stUVCFormatFrameBased.bFormatIndex;
    }
    else
    {
        return g_stUVCFormatUncomp.bFormatIndex;
    }
}

uint32_t USBH_UVC_GetFrameSize(uint8_t frameIndex)
{
    uint8_t         i;
    uint32_t        frameSize;
    uint8_t         bytePerPixel;

    for (i = 0; i < USB_UVC_MAX_FRAME_FORMATS_NUM; i++)
    {
        if (frameIndex == g_stUVCFrameUncomp[i].bFrameIndex)
        {
            break;
        }
    }

    if (i >= USB_UVC_MAX_FRAME_FORMATS_NUM)
    {
        i = 0;
    }

    frameSize       = (g_stUVCFrameUncomp[i].wWidth * g_stUVCFrameUncomp[i].wHeight);

    bytePerPixel    = (g_stUVCFormatUncomp.bBitsPerPixel >> 3);

    if (bytePerPixel != 0)
    {
        frameSize   = (frameSize * bytePerPixel);
    }

    DLOG_Info("frameSize: %d", frameSize);

    return frameSize;
}


static uint32_t USBH_GetFrameDefaultInterval(uint8_t frameIndex, UVC_SupportedFormatsDef uvc_format)
{
    uint8_t         i;
    uint32_t        frameDefaultInterval = 0;

    if (uvc_format == UVC_SUPPORTED_FORMAT_FRAME_BASED)
    {
        for (i = 0; i < USB_UVC_MAX_FRAME_FORMATS_NUM; i++)
        {
            if (frameIndex == g_stUVCFrameFrameBased[i].bFrameIndex)
            {
                break;
            }
        }

        frameDefaultInterval = g_stUVCFrameFrameBased[i].dwDefaultFrameInterval;
    }
    else
    {
        for (i = 0; i < USB_UVC_MAX_FRAME_FORMATS_NUM; i++)
        {
            if (frameIndex == g_stUVCFrameUncomp[i].bFrameIndex)
            {
                break;
            }
        }

        frameDefaultInterval = g_stUVCFrameUncomp[i].dwDefaultFrameInterval;
    }

    if (i >= USB_UVC_MAX_FRAME_FORMATS_NUM)
    {
        i = 0;

        DLOG_Error("no this frameIndex");
    }

    return frameDefaultInterval;
}


static void USBH_ParseProcessingUnitDesc(uint8_t * buf)
{
    uint8_t                 i;

    g_stProcessingUnitDesc.bLength              = *(uint8_t  *) (buf + 0);
    g_stProcessingUnitDesc.bDescriptorType      = *(uint8_t  *) (buf + 1);
    g_stProcessingUnitDesc.bDescriptorSubtype   = *(uint8_t  *) (buf + 2);
    g_stProcessingUnitDesc.bUnitID              = *(uint8_t  *) (buf + 3);
    g_stProcessingUnitDesc.bSourceID            = *(uint8_t  *) (buf + 4);
    g_stProcessingUnitDesc.wMaxMultiplier       = LE16(buf + 5);
    g_stProcessingUnitDesc.bControlSize         = *(uint8_t  *) (buf + 7);

    for (i = 0; i < g_stProcessingUnitDesc.bControlSize; i++)
    {
        g_stProcessingUnitDesc.bmControls[i]    = *(uint8_t  *) (buf + (8 + i));
    }

    g_stProcessingUnitDesc.iProcessing          = *(uint8_t  *) (buf + (8 + i));
    g_stProcessingUnitDesc.bmVideoStandards     = *(uint8_t  *) (buf + (9 + i));
}


static void USBH_ParseExtensionUnitDesc(uint8_t * buf)
{
    uint8_t                 i;

    g_stExtensionUnitDesc.bLength              = *(uint8_t  *) (buf + 0);
    g_stExtensionUnitDesc.bDescriptorType      = *(uint8_t  *) (buf + 1);
    g_stExtensionUnitDesc.bDescriptorSubtype   = *(uint8_t  *) (buf + 2);
    g_stExtensionUnitDesc.bUnitID              = *(uint8_t  *) (buf + 3);

    for (i = 0; i < 16; i++)
    {
        g_stExtensionUnitDesc.guidExtensionCode[i]
                                               = *(uint8_t  *) (buf + (4 + i));
    }

    g_stExtensionUnitDesc.bNumControls         = *(uint8_t  *) (buf + 20);
    g_stExtensionUnitDesc.bNrInPins            = *(uint8_t  *) (buf + 21);

    for (i = 0; i < g_stExtensionUnitDesc.bNrInPins; i++)
    {
        g_stExtensionUnitDesc.baSourceID[i]    = *(uint8_t  *) (buf + (22 + i));
    }

    g_stExtensionUnitDesc.bControlSize         = *(uint8_t  *) (buf + (22 + g_stExtensionUnitDesc.bNrInPins));

    for (i = 0; i < g_stExtensionUnitDesc.bControlSize; i++)
    {
        g_stExtensionUnitDesc.bmControls[i]    = *(uint8_t  *) (buf + ((23 + g_stExtensionUnitDesc.bNrInPins) + i));
    }

    g_stExtensionUnitDesc.iExtension           = *(uint8_t  *) (buf + ((23 + g_stExtensionUnitDesc.bNrInPins) + g_stExtensionUnitDesc.bControlSize));
}


void USBH_UVC_GetVideoFormatList(USBH_HandleTypeDef *phost)
{
    USBH_DescHeader_t                 *pdesc;
    uint16_t                           ptr = 0;
    uint8_t                           *buff;
    uint8_t                            frameUncompIndex = 0;
    uint8_t                            frameFrameBasedIndex = 0;
    uint8_t                            videoStreamingIndex = 0;
    USBH_CfgDescTypeDef               *cfg_desc;
    USBH_UVCInterfaceDescriptor       *if_desc;
    UVC_HandleTypeDef                 *UVC_Handle;

    UVC_Handle                  = (UVC_HandleTypeDef *) phost->pActiveClass->pData;
    cfg_desc                    = &(phost->device.CfgDesc);
    pdesc                       = (USBH_DescHeader_t *)(&(phost->device.CfgDesc_Raw));

    while (ptr < cfg_desc->wTotalLength)
    {
        pdesc = USBH_GetNextDesc((uint8_t *)pdesc, &ptr);

        if (pdesc->bDescriptorType   == USB_DESC_TYPE_INTERFACE)
        {
            if_desc               = (USBH_UVCInterfaceDescriptor *)pdesc;
        }

        if (if_desc->bInterfaceSubClass == USB_UVC_SUBCLASS_VIDEO_STREAMING)
        {
            if (pdesc->bDescriptorType   == USB_DESC_TYPE_CS_INTERFACE)
            {
                buff    = (uint8_t *)pdesc;

                if (buff[2] == USB_UVC_FORMAT_UNCOMPRESSED)
                {
                    USBH_ParseFormatUncompDesc(buff);

                    UVC_Handle->u8_formatSupported[UVC_SUPPORTED_FORMAT_UNCOMPRESSED] = 1;

                    memcpy((void *)&g_stUVCSupportedFormatInterface[UVC_SUPPORTED_FORMAT_UNCOMPRESSED],
                           (void *)if_desc,
                           sizeof(USBH_UVCInterfaceDescriptor));
                }
                else if (buff[2] == USB_UVC_FRAME_UNCOMPRESSED)
                {
                    USBH_ParseFrameUncompDesc(buff, frameUncompIndex);

                    frameUncompIndex++;

                    UVC_Handle->u8_frameNum[UVC_SUPPORTED_FORMAT_UNCOMPRESSED] = frameUncompIndex;
                }
                else if (buff[2] == USB_UVC_FORMAT_FRAME_BASED)
                {
                    USBH_ParseFormatFrameBasedDesc(buff);

                    UVC_Handle->u8_formatSupported[UVC_SUPPORTED_FORMAT_FRAME_BASED] = 1;

                    memcpy((void *)&g_stUVCSupportedFormatInterface[UVC_SUPPORTED_FORMAT_FRAME_BASED],
                           (void *)if_desc,
                           sizeof(USBH_UVCInterfaceDescriptor));
                }
                else if (buff[2] == USB_UVC_FRAME_FRAME_BASED)
                {
                    USBH_ParseFrameFrameBasedDesc(buff, frameFrameBasedIndex);

                    frameFrameBasedIndex++;

                    UVC_Handle->u8_frameNum[UVC_SUPPORTED_FORMAT_FRAME_BASED] = frameFrameBasedIndex;
                }
            }
            else if (pdesc->bDescriptorType == USB_DESC_TYPE_EP)
            {
                buff    = (uint8_t *)if_desc;

                USBH_ParseVideoStreamingDesc(buff, videoStreamingIndex);

                videoStreamingIndex++;
            }
        }
        else if (if_desc->bInterfaceSubClass == USB_UVC_SUBCLASS_VIDEO_CONTROL)
        {
            if (pdesc->bDescriptorType   == USB_DESC_TYPE_CS_INTERFACE)
            {
                buff    = (uint8_t *)pdesc;

                if (buff[2] == USB_UVC_PROCESSING_UNIT)
                {
                    USBH_ParseProcessingUnitDesc(buff);
                }
                else if (buff[2] == USB_UVC_EXTENSION_UNIT)
                {
                    USBH_ParseExtensionUnitDesc(buff);
                }
            }
        }
    }
}


static uint8_t USBH_UVC_FindStreamingInterface(USBH_HandleTypeDef *phost)
{
    uint8_t                       i;
    USBH_CfgDescTypeDef          *cfg_desc;
    USBH_InterfaceDescTypeDef    *interface_desc;

    cfg_desc                      = &(phost->device.CfgDesc);

    for (i = 2; i < USBH_MAX_NUM_INTERFACES; i++)
    {
        interface_desc              = &cfg_desc->Itf_Desc[i];

        if ((interface_desc->bInterfaceClass == UVC_CLASS)&&
            (interface_desc->bInterfaceSubClass == USB_UVC_SUBCLASS_VIDEO_STREAMING)&&
            (interface_desc->bNumEndpoints > 0))
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return (i-1);
}


uint32_t USBH_UVC_GetProcUnitControls(void)
{
    uint32_t                u32_procUnitControls;

    u32_procUnitControls    = LE32(&g_stProcessingUnitDesc.bmControls[0]);

    DLOG_Info("u32_procUnitControls: %08x", u32_procUnitControls);

    return u32_procUnitControls;
}


uint32_t USBH_UVC_GetExtUnitControls(void)
{
    uint32_t                u32_extUnitControls;

    u32_extUnitControls     = LE32(&g_stExtensionUnitDesc.bmControls[0]);

    DLOG_Info("u32_extUnitControls: %08x", u32_extUnitControls);

    return u32_extUnitControls;
}


USBH_UVCFrameBufferTypeDef *USBH_GetFrameBuffer(void)
{
    return g_UVCVideoBuffer;
}


uint8_t *USBH_GetRecvBuffer(USBH_HandleTypeDef *phost)
{
    uint32_t                u32_offset;
    UVC_HandleTypeDef      *UVC_Handle;

    UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    if (UVC_Handle->uvc_format == UVC_SUPPORTED_FORMAT_UNCOMPRESSED)
    {
        u32_offset      = g_UVCVideoBuffer->u32_rawDataLen;

        return (g_UVCVideoBuffer->u8_rawData + u32_offset);
    }
    else
    {
        return g_UVCVideoBuffer->u8_frameBasedRecvBuff;
    }
}


/* modified from linux kernel, select the appropriate alter interface for video-in endpoint */
uint8_t USBH_SelAltInterfaceForCommit(uint32_t max_packet_size, USBH_HandleTypeDef *phost)
{
    uint8_t                 altInterface = 0;
    uint32_t                best_psize = 0xC00;
    uint32_t                psize;
    uint8_t                 i;
    UVC_HandleTypeDef      *UVC_Handle;

    UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    /* compare with all the candidate endpoints, select the most suitable one */
    for (i = 0; i < USBH_MAX_NUM_ENDPOINT_INTERFACES; i++)
    {
        psize           = g_stVideoStreamingDesc[i].Ep_Desc[0].wMaxPacketSize;

        psize           = (psize & 0x7FF) * (1 + ((psize >> 11) & 3));

        if ((psize >= max_packet_size)&&
            (psize <= best_psize))
        {
            altInterface = g_stVideoStreamingDesc[i].bAlternateSetting;

            break;
        }
    }

    if (i >= USBH_MAX_NUM_INTERFACES)
    {
        altInterface = UVC_Handle->u8_selAltInterface;
    }

    return altInterface;
}

uint8_t USBH_UVC_GetFrameUncompNum(USBH_HandleTypeDef *phost)
{
    UVC_HandleTypeDef        *UVC_Handle =  (UVC_HandleTypeDef *)phost->pActiveClass->pData;

    if (UVC_Handle->u8_formatSupported[UVC_SUPPORTED_FORMAT_UNCOMPRESSED] == 0)
    {
        return 0;
    }
    else 
    {
        return UVC_Handle->u8_frameNum[UVC_SUPPORTED_FORMAT_UNCOMPRESSED];
    }
}

uint8_t USBH_UVC_GetFrameFrameNum(USBH_HandleTypeDef *phost)
{
    UVC_HandleTypeDef        *UVC_Handle =  (UVC_HandleTypeDef *)phost->pActiveClass->pData;

    if (UVC_Handle->u8_formatSupported[UVC_SUPPORTED_FORMAT_FRAME_BASED] == 0)
    {
        return 0;
    }
    else 
    {
        return UVC_Handle->u8_frameNum[UVC_SUPPORTED_FORMAT_FRAME_BASED];
    }

}

uint32_t USBH_UVC_GetUVCAttributionMask(void)
{
    uint8_t         i;
    uint32_t        ret = 0;

    for (i = 0; i < g_stProcessingUnitDesc.bControlSize; i++)
    {
        ret += (g_stProcessingUnitDesc.bmControls[i] << (i << 3));
    }

    return ret;
}


static int32_t USBH_UVC_ExtractValidData(int32_t *data, uint8_t dataLen)
{
    // uint8_t         i;
    uint32_t        negtive_check = 0x80;
    int32_t         temp;

    if (dataLen > sizeof(int32_t))
    {
        dataLen = sizeof(int32_t);
    }

    negtive_check       <<= ((dataLen - 1) << 3);

    temp = *data;

    /* negtive value */
    if (temp &= negtive_check)
    {
        /* set high bits 1 */
        *data |= (0xFFFFFFFF - (negtive_check - 1));
    }
    /* positive value */
    else
    {
        /* set high bits 0 */
        *data &= (0xFFFFFFFF >> ((sizeof(int32_t) - dataLen) << 3));
    }

    return 0;
}


void USBH_UVC_GetUVCAttribution(USBH_HandleTypeDef *phost, uint8_t index)
{
    volatile UVC_HandleTypeDef        *UVC_Handle;

    UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;
    phost->Control.setup.b.wValue.w = (g_stUVCAttrCtrl[index].selector << 8);
    phost->Control.setup.b.wIndex.w = (g_stProcessingUnitDesc.bUnitID << 8);
    phost->Control.setup.b.wLength.w = g_stUVCAttrCtrl[index].len;

    if (g_stUVCAttrCtrl[index].info != 0)
    {
        phost->Control.setup.b.bRequest = UVC_GET_INFO;

        while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(&(g_stUVCAttrCtrl[index].info)) , phost->Control.setup.b.wLength.w));

        USBH_UVC_ExtractValidData(&(g_stUVCAttrCtrl[index].info), g_stUVCAttrCtrl[index].len);
    }

    if (g_stUVCAttrCtrl[index].min!= 0)
    {
        phost->Control.setup.b.bRequest = UVC_GET_MIN;

        while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(&(g_stUVCAttrCtrl[index].min)) , phost->Control.setup.b.wLength.w));

        USBH_UVC_ExtractValidData(&(g_stUVCAttrCtrl[index].min), g_stUVCAttrCtrl[index].len);
    }

    if (g_stUVCAttrCtrl[index].max!= 0)
    {
        phost->Control.setup.b.bRequest = UVC_GET_MAX;

        while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(&(g_stUVCAttrCtrl[index].max)) , phost->Control.setup.b.wLength.w));

        USBH_UVC_ExtractValidData(&(g_stUVCAttrCtrl[index].max), g_stUVCAttrCtrl[index].len);
    }

    if (g_stUVCAttrCtrl[index].res != 0)
    {
        phost->Control.setup.b.bRequest = UVC_GET_RES;

        while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(&(g_stUVCAttrCtrl[index].res)) , phost->Control.setup.b.wLength.w));

        USBH_UVC_ExtractValidData(&(g_stUVCAttrCtrl[index].res), g_stUVCAttrCtrl[index].len);
    }

    if (g_stUVCAttrCtrl[index].def!= 0)
    {
        phost->Control.setup.b.bRequest = UVC_GET_DEF;

        while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(&(g_stUVCAttrCtrl[index].def)) , phost->Control.setup.b.wLength.w));

        USBH_UVC_ExtractValidData(&(g_stUVCAttrCtrl[index].def), g_stUVCAttrCtrl[index].len);
    }
}


void USBH_UVC_SetUVCAttribution(USBH_HandleTypeDef *phost)
{
    UVC_HandleTypeDef        *UVC_Handle;
    USBH_StatusTypeDef        status     = USBH_BUSY;

    UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_RECIPIENT_INTERFACE | USB_REQ_TYPE_CLASS;
    phost->Control.setup.b.bRequest = UVC_SET_CUR;
    phost->Control.setup.b.wValue.w = (g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].selector << 8);
    phost->Control.setup.b.wIndex.w = (g_stProcessingUnitDesc.bUnitID << 8);
    phost->Control.setup.b.wLength.w = g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].len;

    while (USBH_BUSY == USBH_CtlReq(phost, (uint8_t *)(&(g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].cur)) , phost->Control.setup.b.wLength.w))
    {
        // ar_osDelay(1);
        HAL_Delay(1);
    }
}


int8_t USBH_UVC_SetUVCAttrInterface(USBH_HandleTypeDef *phost, uint8_t attr_index, int32_t attr_value)
{
    UVC_HandleTypeDef      *UVC_Handle;
    // uint8_t                 i;

    UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    /* check whether support for this attribute */
    if (((1<<attr_index) & UVC_Handle->u32_uvcAttributeMask) == 0)
    {
        DLOG_Error("no support for this attrinute");

        return -1;
    }

    /* check value in the range from min to max */
    if (attr_value > g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].max)
    {
        DLOG_Error("exceed the max value: %d", g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].max);

        g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].cur = g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].max;
    }
    else if (attr_value < g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].min)
    {
        DLOG_Error("exceed the min value: %d", g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].min);

        g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].cur = g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].min;
    }
    else
    {
        g_stUVCAttrCtrl[UVC_Handle->u8_setAttrIndex].cur = attr_value;
    }

    UVC_Handle =  (UVC_HandleTypeDef *) phost->pActiveClass->pData;

    /* attribute set should be in the interval of two frames, so wait for a frame end */
    UVC_Handle->u8_setAttrIndex     = attr_index;
    UVC_Handle->u8_setAttrFlag      = 1;

    return 0;
}


int8_t USBH_UVC_GetUVCAttrInterface(USBH_HandleTypeDef *phost,
                                   uint8_t attr_index,
                                   uint8_t attr_type,
                                   int32_t *uvc_attr_value)
{
    UVC_HandleTypeDef      *UVC_Handle;

    UVC_Handle =  (UVC_HandleTypeDef *)phost->pActiveClass->pData;

    /* check whether support for this attribute */
    if (((1<<attr_index) & UVC_Handle->u32_uvcAttributeMask) == 0)
    {
        DLOG_Error("no support for this attrinute");

        return -1;
    }

    switch (attr_type)
    {
    case UVC_PARAM_TYPE_GET_CUR:
        *uvc_attr_value  = g_stUVCAttrCtrl[attr_index].cur;
        break;

    case UVC_PARAM_TYPE_GET_MIN:
        *uvc_attr_value  = g_stUVCAttrCtrl[attr_index].min;
        break;

    case UVC_PARAM_TYPE_GET_MAX:
        *uvc_attr_value  = g_stUVCAttrCtrl[attr_index].max;
        break;

    case UVC_PARAM_TYPE_GET_RES:
        *uvc_attr_value  = g_stUVCAttrCtrl[attr_index].res;
        break;

    case UVC_PARAM_TYPE_GET_LEN:
        *uvc_attr_value  = g_stUVCAttrCtrl[attr_index].len;
        break;

    case UVC_PARAM_TYPE_GET_INFO:
        *uvc_attr_value  = g_stUVCAttrCtrl[attr_index].info;
        break;

    case UVC_PARAM_TYPE_GET_DEF:
        *uvc_attr_value  = g_stUVCAttrCtrl[attr_index].def;
        break;

    default:
        break;
    }

    return 0;
}


