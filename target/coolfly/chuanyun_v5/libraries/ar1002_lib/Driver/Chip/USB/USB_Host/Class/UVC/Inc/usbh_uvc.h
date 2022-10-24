#ifndef __USBH_UVC_H
#define __USBH_UVC_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "usbh_core.h"


#define UVC_CLASS                   14


extern USBH_ClassTypeDef            UVC_Class;
#define USBH_UVC_CLASS             &UVC_Class


#define UVC_SET_CUR                         0x01
#define UVC_GET_CUR                         0x81
#define UVC_GET_MIN                         0x82
#define UVC_GET_MAX                         0x83
#define UVC_GET_RES                         0x84
#define UVC_GET_LEN                         0x85
#define UVC_GET_INFO                        0x86
#define UVC_GET_DEF                         0x87


#define UVC_VIDEO_EP                        0x81
#define UVC_VIDEO_EP_MAX_SIZE               0x400
#define UVC_CTRL_EP                         0x83

#define UVC_VIDEO_MAX_SIZE_PER_SOF          0xC00

#define UVC_VIDEO_BUFF_FRAME_NUM            0x2
//#define UVC_VIDEO_BUFF_FRAME_SIZE           76800
#define UVC_VIDEO_BUFF_FRAME_SIZE           153600

#define UVC_FRAME_BASED_RECV_SIZE           3072
#define UVC_FRAME_BASED_BUFF_SIZE           51200


//#define UVC_VIDEO_BUFF_SIZE_PER_FRAME       38400   // 160 * 120 * 2

#define UVC_SOF_NUM_PER_FRAME               60

#define UVC_HEADER_SPECIAL_CHAR             0xC
#define UVC_HEADER_SIZE                     0xC

#define UVC_HEADER_FRAME_START              0x01
#define UVC_HEADER_FRAME_END                0x02

#define USB_DESC_TYPE_CS_INTERFACE          0x24
#define USB_DESC_TYPE_EP                    0x05

#define USB_UVC_FORMAT_UNCOMPRESSED         0x04
#define USB_UVC_FRAME_UNCOMPRESSED          0x05
#define USB_UVC_FORMAT_FRAME_BASED          0x10
#define USB_UVC_FRAME_FRAME_BASED           0x11


#define USB_UVC_PROCESSING_UNIT             0x05
#define USB_UVC_EXTENSION_UNIT              0x06


#define USB_UVC_SUBCLASS_VIDEO_CONTROL      0x01
#define USB_UVC_SUBCLASS_VIDEO_STREAMING    0x02


#define USB_UVC_MAX_FRAME_FORMATS_NUM       10
#define USB_UVC_MAX_FRAME_FRAME_BASED_NUM   20

#define USB_UVC_RECV_BUFFER_ADDR            0x21000000
#define USB_UVC_VIDEO_BUFFER_ADDR           0x21000800

#define USB_UVC_STARTED                     0x01
#define USB_UVC_SWITCH_PIXEL                0x02


#define USB_UVC_PU_CONTROL_UNDEFINED                0x00
#define USB_UVC_PU_BACKLIGHT_COMPENSATION_CONTROL   0x01
#define USB_UVC_PU_BRIGHTNESS_CONTROL               0x02
#define USB_UVC_PU_CONTRAST_CONTROL                 0x03
#define USB_UVC_PU_GAIN_CONTROL                     0x04
#define USB_UVC_PU_POWER_LINE_FREQUENCY_CONTROL     0x05
#define USB_UVC_PU_HUE_CONTROL                      0x06
#define USB_UVC_PU_SATURATION_CONTROL               0x07
#define USB_UVC_PU_SHARPNESS_CONTROL                0x08
#define USB_UVC_PU_GAMMA_CONTROL                    0x09
#define USB_UVC_PU_WHITE_BALANCE_TEMP_CONTROL       0x0A
#define USB_UVC_PU_WHITE_BALANCE_TEMP_AUTO_CONTROL  0x0B
#define USB_UVC_PU_WHITE_BALANCE_COMP_CONTROL       0x0C
#define USB_UVC_PU_WHITE_BALANCE_COMP_AUTO_CONTROL  0x0D
#define USB_UVC_PU_DIGITAL_MULTIPLIER_CONTROL       0x0E
#define USB_UVC_PU_DIGITAL_MULTIPLIER_LIMIT_CONTROL 0x0F
#define USB_UVC_PU_HUE_AUTO_CONTROL                 0x10


typedef enum
{
    USB_UVC_PARAM_BRIGHTNESS                = 0,
    USB_UVC_PARAM_CONTRAST                  = 1,
    USB_UVC_PARAM_HUE                       = 2,
    USB_UVC_PARAM_SATURATION                = 3,
    USB_UVC_PARAM_SHARPNESS                 = 4,
    USB_UVC_PARAM_GAMMA                     = 5,
    USB_UVC_PARAM_WHITE_BALANCE_TEMP        = 6,
    USB_UVC_PARAM_WHITE_BALANCE_COMP        = 7,
    USB_UVC_PARAM_BACKLIGHT_COMP            = 8,
    USB_UVC_PARAM_GAIN                      = 9,
    USB_UVC_PARAM_PWR_LINE_FREQ             = 10,
    USB_UVC_PARAM_HUE_AUTO                  = 11,
    USB_UVC_PARAM_WHITE_BALANCE_TEMP_AUTO   = 12,
    USB_UVC_PARAM_WHITE_BALANCE_COMP_AUTO   = 13,
    USB_UVC_PARAM_DIGITAL_MULTI             = 14,
    USB_UVC_PARAM_DIGITAL_MULTI_LIMIT       = 15,
    USB_UVC_PARAM_MAX_NUM                   = 16,
} USB_UVC_PARAM_MASK_INDEX;


typedef enum
{
    UVC_SUPPORTED_FORMAT_UNCOMPRESSED  = 0,
    UVC_SUPPORTED_FORMAT_FRAME_BASED = 1,
    UVC_SUPPORTED_FORMAT_NUM,
} UVC_SupportedFormatsDef;

typedef enum
{
    UVC_STATE_SET_INTERFACE = 0,
    UVC_STATE_GET_ATTR,
    UVC_STATE_SET_ATTR,
    UVC_STATE_PROBE,
    UVC_STATE_COMMIT,
    UVC_STATE_VIDEO_PLAY,
    UVC_STATE_DEFAULT,
    UVC_PROBE_STATE_GET_CUR,
    UVC_PROBE_STATE_GET_MAX,
    UVC_PROBE_STATE_GET_MIN,
    UVC_PROBE_STATE_SET_CUR,
    UVC_PROBE_STATE_GET_CUR_COMMIT,
    UVC_PROBE_STATE_SET_CUR_COMMIT,
}
UVC_StateTypeDef;

typedef enum
{
    UVC_PARAM_TYPE_NON       = 0,
    UVC_PARAM_TYPE_GET_CUR   = 0x81,
    UVC_PARAM_TYPE_GET_MIN   = 0x82,
    UVC_PARAM_TYPE_GET_MAX   = 0x83,
    UVC_PARAM_TYPE_GET_RES   = 0x84,
    UVC_PARAM_TYPE_GET_LEN   = 0x85,
    UVC_PARAM_TYPE_GET_INFO  = 0x86,
    UVC_PARAM_TYPE_GET_DEF   = 0x87,
} UVC_GetParamTypeDef;



typedef enum
{
    UVC_VIDEO_BUFF_EMPTY = 0,
    UVC_VIDEO_BUFF_VALID,
    UVC_VIDEO_BUFF_IN_USING,
}
UVC_BuffStateTypeDef;



typedef struct _UVC_Process
{
    uint8_t                     CtrlPipe;
    uint8_t                     CtrlEp;
    uint16_t                    CtrlEpSize;
    uint8_t                     VideoPipe[UVC_SUPPORTED_FORMAT_NUM];
    uint8_t                     VideoEp[UVC_SUPPORTED_FORMAT_NUM];
    uint16_t                    VideoEpSize[UVC_SUPPORTED_FORMAT_NUM];
    uint8_t                     interface;
    uint8_t                     u8_selFormatIndex;
    uint8_t                     u8_selFrameIndex;
    uint8_t                     u8_selInterface;
    uint8_t                     u8_selAltInterface;
    volatile uint8_t            u8_startUVCFlag;
    UVC_SupportedFormatsDef     uvc_format;
    uint8_t                     u8_formatSupported[UVC_SUPPORTED_FORMAT_NUM];
    uint8_t                     u8_frameNum[UVC_SUPPORTED_FORMAT_NUM];
    uint32_t                    u32_uvcAttributeMask;
    uint8_t                     u8_setAttrIndex;
    uint8_t                     u8_setAttrFlag;
}
UVC_HandleTypeDef;


typedef struct _UVCInterfaceAssociation
{
    uint8_t  bLength;
    uint8_t  bDescriptorType;
    uint8_t  bFirstInterface;
    uint8_t  bInterfaceCount;
    uint8_t  bFunctionClass;
    uint8_t  bFunctionSubClass;
    uint8_t  bFunctionProtocol;
    uint8_t  iFunction;
} USBH_UVCInterfaceAssociationDescriptor;


typedef struct _UVCInterface
{
    uint8_t  bLength;
    uint8_t  bDescriptorType;
    uint8_t  bInterfaceNumber;
    uint8_t  bAlternateSetting;
    uint8_t  bNumEndpoints;
    uint8_t  bInterfaceClass;
    uint8_t  bInterfaceSubClass;
    uint8_t  bInterfaceProtocol;
    uint8_t  iInterface;
} USBH_UVCInterfaceDescriptor;


typedef struct _VCProcessingUnitInterface
{
    uint8_t    bLength;
    uint8_t    bDescriptorType;
    uint8_t    bDescriptorSubtype;
    uint8_t    bUnitID;
    uint8_t    bSourceID;
    uint16_t   wMaxMultiplier;
    uint8_t    bControlSize;
    uint8_t    bmControls[4];
    uint8_t    iProcessing;
    uint8_t    bmVideoStandards;
} USBH_VCProcessingUnitInterfaceDescriptor;


typedef struct _VCExtensionUnitInterface
{
    uint8_t    bLength;
    uint8_t    bDescriptorType;
    uint8_t    bDescriptorSubtype;
    uint8_t    bUnitID;
    uint8_t    guidExtensionCode[16];
    uint8_t    bNumControls;
    uint8_t    bNrInPins;
    uint8_t    baSourceID[4];
    uint8_t    bControlSize;
    uint8_t    bmControls[4];
    uint8_t    iExtension;
} USBH_VCExtensionUnitInterfaceDescriptor;


typedef struct _UVCFormatUncompressedTypeDef
{
    uint8_t  bLength;
    uint8_t  bDescriptorType;
    uint8_t  bDescriptorSubtype;
    uint8_t  bFormatIndex;
    uint8_t  bNumFrameDescriptors;
    uint8_t  guidFormat[16];
    uint8_t  bBitsPerPixel;
    uint8_t  bDefaultFrameIndex;
    uint8_t  bAspectRatioX;
    uint8_t  bAspectRatioY;
    uint8_t  bmInterlaceFlags;
    uint8_t  bCopyProtect;
} USBH_UVCFormatUncompressedTypeDef;


typedef struct _UVCFrameUncompressedTypeDef
{
    uint8_t   bLength;
    uint8_t   bDescriptorType;
    uint8_t   bDescriptorSubtype;
    uint8_t   bFrameIndex;
    uint8_t   bmCapabilities;
    uint16_t  wWidth;
    uint16_t  wHeight;
    uint32_t  dwMinBitRate;
    uint32_t  dwMaxBitRate;
    uint32_t  dwMaxVideoFrameBufferSize;
    uint32_t  dwDefaultFrameInterval;
    uint8_t   bFrameIntervalType;
    uint32_t  dwFrameInterval;
} USBH_UVCFrameUncompressedTypeDef;


typedef struct _UVCFormatFrameBasedTypeDef
{
    uint8_t     bLength;
    uint8_t     bDescriptorType;
    uint8_t     bDescriptorSubtype;
    uint8_t     bFormatIndex;
    uint8_t     bNumFrameDescriptors;
    uint8_t     guidFormat[16];
    uint8_t     bBitsPerPixel;
    uint8_t     bDefaultFrameIndex;
    uint8_t     bAspectRatioX;
    uint8_t     bAspectRatioY;
    uint8_t     bmInterlaceFlags;
    uint8_t     bCopyProtect;
    uint8_t     bVariableSize;
} USBH_UVCFormatFrameBasedTypeDef;


typedef struct _UVCFrameFrameBasedTypeDef
{
    uint8_t   bLength;
    uint8_t   bDescriptorType;
    uint8_t   bDescriptorSubtype;
    uint8_t   bFrameIndex;
    uint8_t   bmCapabilities;
    uint16_t  wWidth;
    uint16_t  wHeight;
    uint32_t  dwMinBitRate;
    uint32_t  dwMaxBitRate;
    uint32_t  dwDefaultFrameInterval;
    uint8_t   bFrameIntervalType;
    uint32_t  dwBytesPerLine;
    uint32_t  dwFrameInterval[7];
} USBH_UVCFrameFrameBasedTypeDef;


typedef struct _UVCFrameBuffer
{
    volatile uint32_t       u32_rawDataLen;
    uint8_t                 u8_backup[UVC_HEADER_SIZE];
    uint8_t                *u8_rawData;
    uint8_t                *u8_frameBasedRecvBuff;
} USBH_UVCFrameBufferTypeDef;


typedef enum
{
    UVC_USER_GET_FRAME_IDLE        = 0,
    UVC_USER_GET_FRAME_WAITING     = 1,
    UVC_USER_GET_FRAME_FINISHED    = 2,
} UVC_USER_GET_FRAME_STATE;

typedef struct _UVCUserInterface
{
    uint32_t            u32_frameIndex;
    uint32_t            u32_frameLen;
    volatile UVC_USER_GET_FRAME_STATE   u8_userWaiting; //0:idle 1:waiting 2:finished
    uint8_t            *u8_userBuffer;
} USBH_UVCUserInterface;


typedef struct
{
    int32_t     cur;
    int32_t     min;
    int32_t     max;
    int32_t     res;
    int32_t     info;
    int32_t     def;
    uint16_t    len;
    uint16_t    selector;
} USBH_UVCAttrCtrl;



static USBH_StatusTypeDef USBH_UVC_InterfaceInit (USBH_HandleTypeDef *phost);
USBH_StatusTypeDef USBH_UVC_InterfaceDeInit (USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_UVC_ClassRequest(USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_UVC_Process (USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_UVC_SOFProcess (USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_UVC_GetCSParam(USBH_HandleTypeDef *phost);
static void USBH_UVC_Probe(USBH_HandleTypeDef *phost);
static void USBH_UVC_Commit(USBH_HandleTypeDef *phost);
uint8_t USBH_UVC_StartView(USBH_HandleTypeDef *phost,
                          uint8_t u8_frameIndex,
                          uint8_t u8_formatIndex,
                          UVC_SupportedFormatsDef uvc_format);
static void USBH_UVC_UrbDone(USBH_HandleTypeDef *phost);
uint8_t USBH_UVC_GetBuff(void);
void USBH_UVC_SetBuffState(uint8_t u8_buffIndex, UVC_BuffStateTypeDef e_buffState);
static UVC_BuffStateTypeDef USBH_UVC_GetBuffState(uint8_t u8_buffIndex);
static void USBH_ParseFormatUncompDesc(uint8_t *buf);
static void USBH_ParseFrameUncompDesc(uint8_t *buf, uint8_t index);
static void  USBH_ParseVideoStreamingDesc(uint8_t *buf, uint8_t index);
void USBH_UVC_GetVideoFormatList(USBH_HandleTypeDef *phost);
static uint8_t USBH_UVC_FindStreamingInterface(USBH_HandleTypeDef *phost);
uint16_t USBH_UVC_GetFrameWidth(uint8_t index, UVC_SupportedFormatsDef uvc_format);
uint16_t USBH_UVC_GetFrameHeight(uint8_t index, UVC_SupportedFormatsDef uvc_format);
uint8_t USBH_UVC_GetFrameIndex(uint8_t index, UVC_SupportedFormatsDef uvc_format);
uint8_t USBH_UVC_GetFormatIndex(UVC_SupportedFormatsDef uvc_format);
uint32_t USBH_UVC_GetFrameSize(uint8_t frameIndex);
static uint32_t USBH_GetFrameDefaultInterval(uint8_t frameIndex, UVC_SupportedFormatsDef uvc_format);
uint32_t USBH_UVC_GetProcUnitControls(void);
uint32_t USBH_UVC_GetExtUnitControls(void);
USBH_UVCFrameBufferTypeDef *USBH_GetFrameBuffer(void);
uint8_t *USBH_GetRecvBuffer(USBH_HandleTypeDef *phost);
uint8_t USBH_SelAltInterfaceForCommit(uint32_t max_packet_size, USBH_HandleTypeDef *phost);
uint8_t USBH_UVC_GetFrameUncompNum(USBH_HandleTypeDef *phost);
uint8_t USBH_UVC_GetFrameFrameNum(USBH_HandleTypeDef *phost);
uint8_t USBH_UVC_GetVideoEpAddr(UVC_SupportedFormatsDef uvc_format);
uint32_t USBH_UVC_GetUVCAttributionMask(void);
void USBH_UVC_GetUVCAttribution(USBH_HandleTypeDef *phost, uint8_t index);
void USBH_UVC_SetUVCAttribution(USBH_HandleTypeDef *phost);
int8_t USBH_UVC_SetUVCAttrInterface(USBH_HandleTypeDef *phost, uint8_t attr_index, int32_t attr_value);
int8_t USBH_UVC_GetUVCAttrInterface(USBH_HandleTypeDef *phost,
                                   uint8_t attr_index,
                                   uint8_t attr_type,
                                   int32_t *uvc_attr_value);

extern USBH_UVCUserInterface    g_stUVCUserInterface;
extern uint8_t                  g_u8UVCPortId;


#endif /* __USBH_AUDIO_H */

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

