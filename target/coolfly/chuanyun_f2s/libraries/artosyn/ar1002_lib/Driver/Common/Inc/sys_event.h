#ifndef SYS_EVENT_H
#define SYS_EVENT_H

#ifdef  __cplusplus
extern "C"
{
#endif


#include <stdint.h>
#include "bb_types.h"

typedef void (*SYS_Event_Handler)(void *);

#define SYS_EVENT_HANDLER_PARAMETER_LENGTH    16
#define SYS_EVENT_LEVEL_HIGH_MASK             0x10000000
#define SYS_EVENT_LEVEL_MIDIUM_MASK           0x20000000
#define SYS_EVENT_LEVEL_LOW_MASK              0x40000000
#define SYS_EVENT_INTER_CORE_MASK             0x80000000

typedef enum
{
    INTER_CORE_CPU0_ID = 1,
    INTER_CORE_CPU1_ID = 2,
    INTER_CORE_CPU2_ID = 4,
}INTER_CORE_CPU_ID;

typedef uint32_t INTER_CORE_MSG_ID;

// Registered system event handler list

typedef struct _RegisteredSysEventHandler_Node
{
    SYS_Event_Handler handler;
    struct _RegisteredSysEventHandler_Node* prev;
    struct _RegisteredSysEventHandler_Node* next;
} STRU_RegisteredSysEventHandler_Node;

typedef STRU_RegisteredSysEventHandler_Node* STRU_RegisteredSysEventHandler_List;

// Registered system event list

typedef struct _RegisteredSysEvent_Node
{
    uint32_t event_id;
    STRU_RegisteredSysEventHandler_List handler_list;
    STRU_RegisteredSysEventHandler_Node* handler_list_tail;
    struct _RegisteredSysEvent_Node* prev;
    struct _RegisteredSysEvent_Node* next;
} STRU_RegisteredSysEvent_Node;

typedef STRU_RegisteredSysEvent_Node* STRU_RegisteredSysEvent_List;

// Notified system event list

typedef struct _NotifiedSysEvent_Node
{
    uint32_t event_id;
    uint8_t parameter[SYS_EVENT_HANDLER_PARAMETER_LENGTH];
    struct _NotifiedSysEvent_Node* prev;
    struct _NotifiedSysEvent_Node* next;
} STRU_NotifiedSysEvent_Node;

typedef STRU_NotifiedSysEvent_Node* STRU_NotifiedSysEvent_List;

// Test event

typedef struct _SysEvent_TestParameter
{
    uint8_t  p1;
    uint16_t p2;
    uint32_t p3;
    uint8_t  reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 7];
} STRU_SysEvent_TestParameter;

#define SYS_EVENT_ID_TEST (SYS_EVENT_LEVEL_HIGH_MASK | 0x8000)

// APIs

uint8_t SYS_EVENT_RegisterHandler(uint32_t event_id, SYS_Event_Handler event_handler);
uint8_t SYS_EVENT_UnRegisterHandler(uint32_t event_id, SYS_Event_Handler event_handler);
uint8_t SYS_EVENT_NotifyLocal(uint32_t event_id, void* parameter);
uint8_t SYS_EVENT_NotifyInterCore(uint32_t event_id, void* parameter);
uint8_t SYS_EVENT_NotifyRemote(uint32_t event_id, void* parameter);
void SYS_EVENT_Notify_From_ISR(uint32_t event_id, void* parameter);
uint8_t SYS_EVENT_Process(void);
void SYS_EVENT_DumpAllListNodes(void);
void SYS_EVENT_MallocFreeCntCheck(void);


// Idle event

#define SYS_EVENT_ID_IDLE (SYS_EVENT_LEVEL_LOW_MASK | 0x8000)

// Misc driver event

#define SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE         (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0001)
#define SYS_EVENT_ID_BB_SUPPORT_BR_CHANGE             (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0002)
#define SYS_EVENT_ID_BB_EVENT                         (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0003)
#define SYS_EVENT_ID_USER_CFG_CHANGE                  (SYS_EVENT_LEVEL_HIGH_MASK   | 0x0004)
#define SYS_EVENT_ID_USB_PLUG_OUT                     (SYS_EVENT_LEVEL_HIGH_MASK   | 0x0005)
#define SYS_EVENT_ID_NV_MSG                           (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0006)
#define SYS_EVENT_ID_USB_SWITCH_HOST_DEVICE           (SYS_EVENT_LEVEL_HIGH_MASK   | 0x0007)


#define SYS_EVENT_ID_UART_DATA_RCV_SESSION0           (SYS_EVENT_LEVEL_HIGH_MASK   | 0x0008)
#define SYS_EVENT_ID_UART_DATA_RCV_SESSION1           (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0009)
#define SYS_EVENT_ID_UART_DATA_RCV_SESSION2           (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x000A)
#define SYS_EVENT_ID_UART_DATA_RCV_SESSION3           (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x000B)
#define SYS_EVENT_ID_UART_DATA_RCV_SESSION4           (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x000C)

#define SYS_EVENT_ID_AUDIO_INPUT_CHANGE               (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x000D)
#define SYS_EVENT_ID_SD_CARD_CHANGE                   (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x000E)
#define SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE_ARCAST  (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x000F)

#define SYS_EVENT_ID_REMOTE_EVENT                     (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0010)

#define SYS_EVENT_ID_VIDEO_EVENT                      (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0011)
#define SYS_EVENT_ID_AUDIO_EVENT                      (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0012)

#define SYS_EVENT_ID_WIRELESS_UPGRADE                 (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0014)

#define SYS_EVENT_ID_FLUSH_UDISK_BUFFER               (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0015)

#define SYS_EVENT_ID_TO_APP                           (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0016)

#define SYS_EVENT_ID_FACTORY_DATA                     (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0017)

#define SYS_EVENT_ID_IAP2_MSG_EVENT                   (SYS_EVENT_LEVEL_HIGH_MASK | 0x0018)

#define SYS_EVENT_ID_NETLINE_PLUG_EVENT               (SYS_EVENT_LEVEL_HIGH_MASK | 0x0019)

#define SYS_EVENT_ID_SPI_DATA_TRANS                   (SYS_EVENT_LEVEL_HIGH_MASK   | 0x001A)

#define SYS_EVENT_ID_ENCODER_CMD                      (SYS_EVENT_LEVEL_MIDIUM_MASK   | 0x001B)

#define SYS_EVENT_ID_CPU0_INTO_UPGRADE                (SYS_EVENT_LEVEL_MIDIUM_MASK   | 0x001C)

#define SYS_EVENT_ID_USB_DEVICE_TYPE                  (SYS_EVENT_LEVEL_MIDIUM_MASK   | 0x001D)

#define SYS_EVENT_ID_USER_DEFINE                      (SYS_EVENT_LEVEL_MIDIUM_MASK   | 0x001E)

#define SYS_EVENT_ID_USB_ID_STS                       (SYS_EVENT_LEVEL_HIGH_MASK   | 0x001F)

#define SYS_EVENT_ID_USB_DEVICE_IDENTITY              (SYS_EVENT_LEVEL_MIDIUM_MASK   | 0x0020)

#define SYS_EVENT_ID_H264_RPT_EVENT					  (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0021)
#define SYS_EVENT_ID_HDMI_RESET_EVENT                 (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0022)

#define SYS_EVENT_ID_USB_HOST_ERR_MSG                 (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0023)

#define SYS_EVENT_USB_SUPPORT_USR_DEFINE              (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x0024)

#define SYS_EVENT_ID_USB_PLUG_EVENT                   (SYS_EVENT_LEVEL_HIGH_MASK   | 0x0025)

#define SYS_EVENT_ID_UPGRADE_STATE_EVENT              (SYS_EVENT_LEVEL_HIGH_MASK   | 0x0026)


#define SYS_EVENT_ID_PERFORMACE_TEST                  (SYS_EVENT_LEVEL_MIDIUM_MASK | 0x00EF)




typedef enum
{
    ENCODER_INPUT_SRC_HDMI_0 = 1,
    ENCODER_INPUT_SRC_HDMI_1,
    ENCODER_INPUT_SRC_DVP_0,
    ENCODER_INPUT_SRC_DVP_1,
    ENCODER_INPUT_SRC_MIPI,
} ENUM_ENCODER_INPUT_SRC;

typedef struct _SysEvent_H264InputFormatChangeParameter
{
    uint8_t  index;
    uint16_t width;
    uint16_t hight;
    uint8_t  framerate;
    uint8_t  vic;
    ENUM_ENCODER_INPUT_SRC  e_h264InputSrc;
    uint8_t  reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 9];
} STRU_SysEvent_H264InputFormatChangeParameter;


typedef struct _SysEvent_H264RptParameter
{
    uint16_t v0_width;
    uint16_t v0_hight;
	uint16_t v1_width;
	uint16_t v1_hight;
    uint8_t  reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 8];
} STRU_SysEvent_H264RptParameter;


typedef struct _SysEvent_BB_ModulationChange
{
    uint8_t  encoder_brcidx;
    uint8_t  u8_bbCh; // 
    uint8_t  bw;
    uint8_t  reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 2];
} STRU_SysEvent_BB_ModulationChange;

typedef struct _SysEvent_BB_DATA_BUFFER_FULL_RATIO_Change
{
    uint8_t  BB_Data_Full_Ratio; // 0x00 - 0x80 
    uint8_t  reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 1];
} STRU_SysEvent_BB_DATA_BUFFER_FULL_RATIO_Change;

typedef struct _SysEvent_AudioInputChangeParameter
{
    uint8_t  u8_audioSampleRate;
    uint8_t  reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 1];
} STRU_SysEvent_AudioInputChangeParameter;

// data struct used between cpu communication
typedef enum
{
    NV_NUM_RCID = 1,
    NV_NUM_CHIPID,
    NV_NUM_NOTICE = 0xFF,
} ENUM_NV_NUM;

typedef struct
{
    uint8_t u8_nvSrc  : 4;
    uint8_t u8_nvDst  : 4;
    ENUM_NV_NUM e_nvNum;
    uint8_t u8_nvPar[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 2];
} STRU_SysEvent_NvMsg;

typedef struct _SysEvent_BB_NET_DATA_RECV
{
    uint32_t  u32_dataLen;
    uint8_t   reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 4];
} STRU_SysEvent_BB_NET_DATA_RECV;

typedef struct _SysEvent_OTG_HOST_DEV_SWITCH
{
    uint8_t  otg_port_id;
    uint8_t  otg_state;        // 0:device    1:host
    uint8_t  reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 2];
} STRU_SysEvent_OTG_HOST_DEV_SWITCH;

typedef struct _SysEvent_DEV_PLUG_OUT
{
    uint8_t  otg_port_id;
    uint8_t  reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 1];
} STRU_SysEvent_DEV_PLUG_OUT;

typedef struct _SysEvent_DEV_BB_STATUS
{
    uint8_t  pid;   //
    union
    {
        uint8_t  lockstatus;    //1: lock  0: unlock
        uint8_t  rcid[RC_ID_SIZE];
    };
    uint8_t  agc1;
    uint8_t  agc2;
    union
    {
        ENUM_GRD_SEARCH_STATES e_grd_searchState;
        ENUM_SKY_SEARCH_STATE  e_sky_searchState;
    };

    uint8_t  vtid[VT_ID_SIZE];
} STRU_SysEvent_DEV_BB_STATUS;

typedef struct _SysEvent_FLUSH_UDISK_BUFFER
{
    uint32_t    data_address;
    uint32_t    data_index;
    uint16_t    data_length;
    uint8_t     reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 10];
} STRU_SysEvent_FLUSH_UDISK_BUFFER;

typedef struct _SysEvent_FACTORY_DATA
{
    uint8_t     usb_id;         // assign the usb id to report factory data
    uint8_t     direction;      // set factory data: 0    get factory data: 1
    uint8_t     reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 2];
} STRU_SysEvent_FACTORY_DATA;


typedef struct _SysEvent_MFI_MSG
{
    uint32_t    usb_dev;
    uint32_t    msg_len;
    uint32_t    msg_buf;
    uint8_t     reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 12];
} STRU_SysEvent_MFI_MSG;


typedef struct _SysEventNetlinePlugEvent
{
    uint8_t     plugEvent;    // 0: plugout 1: plugin
    uint32_t    usb_dev;
    uint8_t     reserve[SYS_EVENT_HANDLER_PARAMETER_LENGTH - 1];
} STRU_SysEvent_NetlinePlug;

typedef struct _SysEvent_USB_ID_STS
{
    uint8_t     usb_port_id;
    uint8_t     usb_id_state;
}  STRU_SysEvent_USB_ID_STS;

typedef struct _SysEvent_USB_PlugEvent
{
    uint8_t     plug_event;    // 0: plugout 1: plugin
    uint8_t     usb_port_id;
    uint8_t     dev_type;
} STRU_SysEvent_USB_PlugEvent;

typedef struct _SysEvent_UPGRADE_RecMSG
{
    uint8_t     state;    // 0:init state ; 1 :trans orgdata state ;2:trans lostdata state ;3::trans orgdata data finished  
    uint8_t 	result;	  //0:begin;1:trans data;2:success;3:fail
	uint16_t    received_num;//receive data num
	uint16_t	lost_num;//lost data number
    uint16_t    total_num;//all num of data will to be sent
} STRU_SysEvent_UPGRADE_RecMSG;


#ifdef  __cplusplus
}
#endif


#endif
