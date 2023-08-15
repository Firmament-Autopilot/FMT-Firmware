#include <string.h>
#include "wireless_interface.h"
#include "hal_usb_device.h"
#include "debuglog.h"
#include "hal_bb.h"
#include "hal_bb_debug.h"
#include "hal_sram_ground.h"
#include "bb_spi.h"
#include "bb_ctrl_internal.h"
#include "md5.h"
#include "nor_flash.h"
#include "hal.h"
// #include "rf_if.h"
#include "efuse.h"
#include "upgrade.h"
#include "reg_rw.h"
#include "sys_event.h"
#include "hal_norflash.h"

#include "image_struct.h"
#include "cpu_info.h"
#include "nor_flash.h"
#include "memory_config.h"

#include "factory.h"
#include "hal_nv.h"
#include "cpu_info.h"
#include "hal_sys_ctl.h"
#include "driver_mutex.h"
#include "driver_module_init.h"
#include "drv_systick.h"

#include "drv_systick.h"
// #include "cmsis_os.h"

STRU_WIRELESS_INFO_DISPLAY             *g_pstWirelessInfoDisplay;        //OSD Info in SRAM
STRU_WIRELESS_INFO_DISPLAY              g_stWirelessInfoSend;            //send OSD to PAD or PC
STRU_WIRELESS_MESSAGE_BUFF              g_stWirelessParamConfig;     //receive from PAD or PC
STRU_WIRELESS_MESSAGE_BUFF              g_stWirelessReply;           //send to PAD or PC

uint8_t eventFlag = 0;

volatile uint8_t                        g_u8OSDToggle = 0;
volatile uint8_t                        g_u8OSDEnable[HAL_USB_PORT_NUM] = {0, 0};
volatile uint8_t                        g_u8OSDOnce[HAL_USB_PORT_NUM] = {0, 0};

// extern volatile uint8_t 				g_mtp_enable;
extern volatile uint8_t                 u8_Boot_Upgrade_Flag;


// extern uint8_t USBH_MTP_Send(uint8_t *buffer, uint32_t size);
// extern uint8_t USBH_MTP_Send_From_Task(uint8_t *buffer, uint32_t size);

WIRELESS_CONFIG_HANDLER g_stWirelessMsgHandler[MAX_PID_NUM] =
{
    WIRELESS_INTERFACE_GET_VERSION_Handler,//0
    WIRELESS_INTERFACE_UPGRADE_Handler,////1
    WIRELESS_INTERFACE_ENTER_TEST_MODE_Handler,///2
    WIRELESS_INTERFACE_SYNCHRONIZE_FREQ_CHANNEL_Handler,///3
    WIRELESS_INTERFACE_AUTO_MODE_Handler,///4
    WIRELESS_INTERFACE_SELF_ADAPTION_MODE_Handler,///5
    WIRELESS_INTERFACE_SWITCH_TX_MODE_Handler,////6
    WIRELESS_INTERFACE_SWITCH_RX_MODE_Handler,///7
    WIRELESS_INTERFACE_SWITCH_USB1_MODE_Handler,///8
    WIRELESS_INTERFACE_SWITCH_USB2_MODE_Handler,///9
    WIRELESS_INTERFACE_ALL_RESET_Handler,////a
    WIRELESS_INTERFACE_RX_RESET_Handler,////b
    WIRELESS_INTERFACE_TX_RESET_Handler,////c
    WIRELESS_INTERFACE_MIMO_1T2R_Handler,/////d
    WIRELESS_INTERFACE_WRITE_BB_REG_Handler,////e
    WIRELESS_INTERFACE_READ_BB_REG_Handler,////f
    WIRELESS_INTERFACE_MIMO_2T2R_Handler,////10
    WIRELESS_INTERFACE_OSD_DISPLAY_Handler,////11
    WIRELESS_INTERFACE_BB_GET_CHIP_ID_Handler,/////12
    WIRELESS_INTERFACE_GET_ID_Handler,////13
    WIRELESS_INTERFACE_GET_GROUND_TX_PWR_Handler,////14
    WIRELESS_INTERFACE_GET_SKY_TX_PWR_Handler,/////15
    WIRELESS_INTERFACE_GET_RC_FREQ_CHANNEL_Handler,/////16
    WIRELESS_INTERFACE_GET_VIDEO_FREQ_CHANNEL_Handler,//////17
    WIRELESS_INTERFACE_GET_SOFTWARE_VERSION_Handler,/////18
    WIRELESS_INTERFACE_GET_DEV_INFO_Handler,///19
    WIRELESS_INTERFACE_SET_RC_FREQ_CHANNEL_MASK_Handler,////1a
    WIRELESS_INTERFACE_SET_VIDEO_FREQ_CHANNEL_MASK_Handler,///1b
    WIRELESS_INTERFACE_SELECT_VIDEO_FREQ_CHANNEL_Handler,/////1c
    WIRELESS_INTERFACE_SWITCH_QAM_MODE_Handler,////1d
    WIRELESS_INTERFACE_SET_RC_FREQ_CHANNEL_Handler,///1e
    WIRELESS_INTERFACE_SET_TX_PWR_Handler,///1f
    WIRELESS_INTERFACE_SET_VIDEO_TX_ID_Handler,////20
    WIRELESS_INTERFACE_SET_CTRL_ID_Handler,/////21
    WIRELESS_INTERFACE_SWITCH_WORKING_FREQ_BAND_Handler,////22
    WIRELESS_INTERFACE_RC_SCAN_ALL_BAND_Handler,////23
    WIRELESS_INTERFACE_RC_SCAN_WORKING_BAND_Handler,////24
    WIRELESS_INTERFACE_VIDEO_SCAN_ALL_BAND_Handler,////25
    WIRELESS_INTERFACE_VIDEO_SCAN_WORKING_BAND_Handler,////26
    WIRELESS_INTERFACE_RECOVER_TO_FACTORY_Handler,////27
    WIRELESS_INTERFACE_RC_HOPPING_Handler,////28
    WIRELESS_INTERFACE_SAVE_CONFIGURE_Handler,/////29
    WIRELESS_INTERFACE_READ_MCU_ID_Handler,////2a
    WIRELESS_INTERFACE_LOAD_SKY_REG_TABLE_Handler,////2b
    WIRELESS_INTERFACE_LOAD_GRD_REG_TABLE_Handler,/////2c
    WIRELESS_INTERFACE_SWITCH_BB_POWER_Handler,////2d
    WIRELESS_INTERFACE_SKY_ONLY_RX_Handler,////2e
    WIRELESS_INTERFACE_SWITCH_RF_PWR_0_Handler,///2f
    WIRELESS_INTERFACE_SWITCH_RF_PWR_1_Handler,////30
    WIRELESS_INTERFACE_EXT_ONEKEY_IT_Handler,///31
    WIRELESS_INTERFACE_SWITCH_IT_CHAN_Handler,////32
    WIRELESS_INTERFACE_SWITCH_RMT_CHAN_Handler,////33
    WIRELESS_INTERFACE_SET_PWR_CAL_0_Handler,////34
    WIRELESS_INTERFACE_SET_PWR_CAL_1_Handler,////35
    WIRELESS_INTERFACE_RST_MCU_Handler,////36
    WIRELESS_INTERFACE_RF_PWR_AUTO_Handler,////37
    WIRELESS_INTERFACE_SWITCH_DEBUG_MODE_Handler,////38
    WIRELESS_INTERFACE_READ_RF_REG_Handler,////39
    WIRELESS_INTERFACE_WRITE_RF_REG_Handler,///3a
    WIRELESS_INTERFACE_OPEN_ADAPTION_BIT_STREAM_Handler,///3b
    WIRELESS_INTERFACE_SWITCH_CH1_Handler,////3c
    WIRELESS_INTERFACE_SWITCH_CH2_Handler,///3d
    WIRELESS_INTERFACE_SET_CH1_BIT_RATE_Handler,///3e
    WIRELESS_INTERFACE_SET_CH2_BIT_RATE_Handler,////3f
    WIRELESS_INTERFACE_VIDEO_QAM_Handler,///40
    WIRELESS_INTERFACE_VIDEO_CODE_RATE_Handler,////41
    WIRELESS_INTERFACE_RC_QAM_Handler,/////42
    WIRELESS_INTERFACE_RC_CODE_RATE_Handler,////43
    WIRELESS_INTERFACE_OPEN_VIDEO_Handler,////44
    WIRELESS_INTERFACE_CLOSE_VIDEO_Handler,////45
    WIRELESS_INTERFACE_VIDEO_AUTO_HOPPING_Handler,////46
    WIRELESS_INTERFACE_VIDEO_BAND_WIDTH_Handler,////47
    WIRELESS_INTERFACE_BB_SOFT_RESET_Handler,///48
    WIRELESS_INTERFACE_OPERATE_REG_Handler,////49
    WIRELESS_INTERFACE_READ_RF9363_Handler,///4a
    WIRELESS_INTERFACE_WRITE_RF9363_Handler,///4b
    WIRELESS_INTERFACE_SET_PURE_VT_MODE_Handler,////4c
    WIRELESS_INTERFACE_RW_BB_RF_REG_Handler,///4d
    WIRELESS_INTERFACE_BB_SAVE_RC_ID_Handler,////4e
    WIRELESS_INTERFACE_BB_GET_RC_ID_Handler,////4f
    PAD_FREQUENCY_BAND_WIDTH_SELECT_Handler,////50
    PAD_FREQUENCY_BAND_OPERATION_MODE_Handler,////51
    PAD_FREQUENCY_BAND_SELECT_Handler,////52
    PAD_FREQUENCY_CHANNEL_OPERATION_MODE_Handler,///53
    NULL,
    PAD_MCS_OPERATION_MODE_Handler,/////////55
    PAD_MCS_MODULATION_MODE_Handler,/////56
    PAD_ENCODER_DYNAMIC_BITRATE_MODE_Handler,///////57
    PAD_ENCODER_DYNAMIC_BITRATE_SELECT_Handler,/////58
    PAD_WIRELESS_OSD_DISPLAY_Handler,/////59
    NULL,
    WIRELESS_INTERFACE_ENABLE_FREQUENCY_Handler,///////5b
    WIRELESS_INTERFACE_GET_FACTORY_DATA_Handler,//////5c
    WIRELESS_INTERFACE_SET_FACTORY_DATA_Handler,/////////5d
    NULL,
    NULL,
    NULL,
    WIRELESS_INTERFACE_SLEEP_MODE_SET_Handler,///////61
    WIRELESS_INTERFACE_SET_POWER_Handler,////////62
    WIRELESS_INTERFACE_CMD_SELECT_FILTER_Handler,////////63
	WIRELESS_INTERFACE_CMD_VT_SWEEP_Handler,//////////64
	WIRELESS_INTERFACE_SET_SWEEP_MODE_Handler,/////////65
	WIRELESS_INTERFACE_SET_CHIP_ID_Handler,///////66
	WIRELESS_INTERFACE_BB_SET_TMP_RC_VT_ID_Handler,//////////67
	WIRELESS_INTERFACE_GET_OSD_INFO_ONCE_Handler,///////////68
    WIRELESS_INTERFACE_FCT_RESET_Handler,/////////////////69
    WIRELESS_INTERFACE_TAKE_PICTURE_Handler,/////////6a
    WIRELESS_INTERFACE_PICTURE_QUALITY_SET_Handler,//////////6b
    WIRELESS_INTERFACE_SUB_BAND_SET_CH_Handler,//////////6c
    WIRELESS_INTERFACE_SINGLE_TONE_Handler,///////////6d
    NULL,
    WIRELESS_INTERFACE_SET_SKYorGRD_Handler,////////////6f
    WIRELESS_INTERFACE_GET_BESIDE_DEV_NUM_Handler,/////////70
    WIRELESS_INTERFACE_SET_GRD_SLAVE_MODE_Handler,////////////71
    WIRELESS_INTERFACE_SET_FIND_BESIDE_DEV_Handler,///////////////72
    WIRELESS_INTERFACE_RESET_Handler,///////////////73
    WIRELESS_INTERFACE_GET_PROJECT_NAME_Handler,////0x74
    WIRELESS_INTERFACE_SET_LNA_STATUS_Handler,///0X75
    WIRELESS_INTERFACE_SET_NON_LBT_STATUS_Handler,/////0X76
    WIRELESS_INTERFACE_SET_BANDEDGE_Handler, ///////0X77
    WIRELESS_INTERFACE_SET_PWR_OFFSET_Handler, ///////0X78
    WIRELESS_INTERFACE_GET_PWR_OFFSET_Handler, ///////0X79
    WIRELESS_INTERFACE_SET_PVT_INFO_Handler,   ///////0X7A
    WIRELESS_INTERFACE_GET_PVT_INFO_Handler,   ///////0X7B
    WIRELESS_INTERFACE_GET_BB_TX_FREEBUF_Handler,   ///////0X7C
    WIRELESS_INTERFACE_CLEAR_BB_TX_BUF_Handler,   ///////0X7D
    NULL
};


uint8_t      strVersion[128];
uint8_t WIRELESS_INTERFACE_GET_VERSION_Handler(void *param, uint8_t id)
{
    HAL_RET_T                      ret;
    STRU_WIRELESS_MSG_HEADER      *msg_header;
    uint16_t                       i;
    uint8_t                       *msg_content;

    msg_header  = (STRU_WIRELESS_MSG_HEADER *)strVersion;
    msg_content = strVersion + sizeof(STRU_WIRELESS_MSG_HEADER);

    msg_header->magic_header[0] = 0xFF;
    msg_header->magic_header[1] = 0x5A;
    msg_header->msg_id          = WIRELESS_INTERFACE_GET_VERSION;
    msg_header->packet_num      = 1;
    msg_header->packet_cur      = 0;
    msg_header->msg_len         = 63;
    msg_header->chk_sum         = 0;

    DLOG_Critical("head: %d, tail: %d", g_stWirelessParamConfig.u8_buffHead, g_stWirelessParamConfig.u8_buffTail);

    memcpy((void *)msg_content, WIRELESS_PROTOCAL_VERSION, 6);

    ret = HAL_GetVersion(msg_content + 6);

    for (i = 0; i < msg_header->msg_len; i++)
    {
        msg_header->chk_sum += msg_content[i];
    }

	// if (HAL_USB_Get_USB_DR_Mode(id) == HAL_USB_DR_MODE_HOST)
	// {
	// 	if(g_mtp_enable)
	// 		USBH_MTP_Send((uint8_t *)msg_header, 128);
	// }
    // else
    // {
    if (HAL_OK != HAL_USB_DeviceSendCtrl((uint8_t *)msg_header, 128, id))
    {
        DLOG_Critical("send version fail");
    }
//    }


    return 0;
}

uint8_t WIRELESS_INTERFACE_GET_PROJECT_NAME_Handler(void *param, uint8_t id)
{
    // HAL_RET_T                      ret;
    STRU_WIRELESS_MSG_HEADER      *msg_header;
    uint16_t                       i;
    uint8_t                       *msg_content;
    uint8_t                        prj_name[26];
    STRU_BOARD_RF_PARA *pstru_rf_boardcfg;

    pstru_rf_boardcfg  = CFGBIN_GetNodeData((STRU_cfgBin *)(SRAM_CONFIGURE_MEMORY_ST_ADDR), RF_BOARDCFG_PARA_ID);

    msg_header  = (STRU_WIRELESS_MSG_HEADER *)prj_name;
    msg_content = prj_name + sizeof(STRU_WIRELESS_MSG_HEADER);

    msg_header->magic_header[0] = 0xFF;
    msg_header->magic_header[1] = 0x5A;
    msg_header->msg_id          = WIRELESS_INTERFACE_GET_PROJECT_NAME;
    msg_header->packet_num      = 1;
    msg_header->packet_cur      = 0;
    msg_header->msg_len         = 16;
    msg_header->chk_sum         = 0;

    //DLOG_Critical("head: %d, tail: %d", g_stWirelessParamConfig.u8_buffHead, g_stWirelessParamConfig.u8_buffTail);
    memcpy((void *)msg_content, pstru_rf_boardcfg->boardCfgName, 16);
    
    for (i = 0; i < msg_header->msg_len; i++)
    {
        msg_header->chk_sum += msg_content[i];
    }

	// if (HAL_USB_Get_USB_DR_Mode(id) == HAL_USB_DR_MODE_HOST)
	// {
	// 	if(g_mtp_enable)
	// 		USBH_MTP_Send((uint8_t *)msg_header, 26);
	// }
    // else
    // {
        if (HAL_OK != HAL_USB_DeviceSendCtrl((uint8_t *)msg_header, 26, id))
        {
            DLOG_Error("send prj-name fail");
        }
    // }


    return 0;
}

uint8_t WIRELESS_IsInDebugMode(void)
{
    g_pstWirelessInfoDisplay  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;

    return g_pstWirelessInfoDisplay->in_debug;
}


/* get osd info from shared memory */
uint8_t WIRELESS_GetOSDInfo(void)
{
    g_pstWirelessInfoDisplay  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;

    /* if cpu2 update info, and the info is valid */
    if ((0x0 == g_pstWirelessInfoDisplay->head)
      &&(0xFF == g_pstWirelessInfoDisplay->tail)
      &&(0x0 == g_pstWirelessInfoDisplay->in_debug))
    {
        memcpy((void *)&g_stWirelessInfoSend, (void *)g_pstWirelessInfoDisplay, sizeof(STRU_WIRELESS_INFO_DISPLAY));

        return 0;
    }

    return 1;
}

/* Send to PAD or PC */
uint8_t WIRELESS_SendOSDInfo(uint8_t usbPortId)
{
    uint8_t               *u8_sendBuff;
    uint32_t               u32_sendLength;
    uint16_t               i;
    uint8_t               *msg_content;

    if (WIRELESS_GetOSDInfo())
    {
        DLOG_Info("osd info not ready");

        return 1;
    }

    u8_sendBuff                     = (uint8_t *)&g_stWirelessInfoSend;
    u32_sendLength                  = (uint32_t)(sizeof(STRU_WIRELESS_INFO_DISPLAY));

    g_stWirelessInfoSend.magic_header[0] = 0xFF;
    g_stWirelessInfoSend.magic_header[1] = 0x5A;
    g_stWirelessInfoSend.msg_id          = WIRELESS_INTERFACE_OSD_DISPLAY;
    g_stWirelessInfoSend.packet_num      = 1;
    g_stWirelessInfoSend.packet_cur      = 0;
    g_stWirelessInfoSend.msg_len         = sizeof(STRU_WIRELESS_INFO_DISPLAY) - sizeof(STRU_WIRELESS_MSG_HEADER);
    g_stWirelessInfoSend.msg_chksum      = 0;

    msg_content = (uint8_t *)g_stWirelessInfoSend.snr_vlaue;

    for (i = 0; i < g_stWirelessInfoSend.msg_len; i++)
    {
        g_stWirelessInfoSend.msg_chksum += msg_content[i];
    }

	// if (HAL_USB_Get_USB_DR_Mode(usbPortId) == HAL_USB_DR_MODE_HOST)
	// {
	// 	if(g_mtp_enable)
	// 		USBH_MTP_Send_From_Task(u8_sendBuff, u32_sendLength);
	// }
    // else
    // {
        if (HAL_OK != HAL_USB_DeviceSendCtrl(u8_sendBuff, u32_sendLength, usbPortId))
		{
			DLOG_Error("send osd info error");

			return 1;
		}
    // }

    return 0;
}

static volatile uint32_t    u32_WirelessInterfaceRecCount = 0;       // image size count
static volatile uint8_t     u8_WirelessInterfaceRecData[512] __attribute__ ((aligned (4)));
static volatile uint16_t    u16_WirelessInterfacerecDataLength = 0;
static volatile uint16_t    u16_WirelessInterfacerecPacketNum = 0;
static volatile uint8_t     u8_wirelessUpgradeRemoteFlag = 0;

static volatile uint8_t     u8_upgradeReply[256];
static volatile uint8_t     u8_upgradeUSBId;
static volatile uint8_t     u8_upgradeLastPacket = 0;

static int8_t               s_writeFlash = 0x10;

// osMessageQId upgrade_msg_queue_id = 0;
static uint16_t             s_u16_wirelessUpgradeTotalPacket = 0;

extern int8_t UPGRADE_WirelessGndSendInit(uint32_t u32_dataLen);

int8_t UPGRADE_GndAndSkyLock(void)
{
    HAL_RET_T ret;
    STRU_WIRELESS_INFO_DISPLAY p;
    STRU_WIRELESS_INFO_DISPLAY *pst_bb_info=(STRU_WIRELESS_INFO_DISPLAY *)&p;
    ret = HAL_BB_GetInfo(&pst_bb_info);
    if(ret != HAL_OK)
    {
        return 0;
    }
    uint8_t lock_status = pst_bb_info->lock_status;
    return (lock_status & 0x01);
}


#include "stdbool.h"

static uint32_t    tick = 0;
static uint32_t    tick_end = 0;




void WIRELESS_GndForSky(void const *argument)
{
    uint16_t                     u16_packetNum = 0xffff;
    uint8_t                     *msgContent;
    STRU_WIRELESS_MSG_HEADER    *msgHeader;
    uint16_t                     i;
    STRU_UPGRADE_STATUS          st_lostData;
    uint8_t                      u8_retime = 0;
    uint8_t                      retry_count = 0; 
    uint16_t			 last_lostpacket_index = 0xffff;


    static int wait_lock_time = 0;
    // while(upgrade_msg_queue_id == 0)
    while(1)
    {
        HAL_Delay(500);
    }
    
    // osMessageGet(upgrade_msg_queue_id, osWaitForever);

    // DLOG_Critical("enter WIRELESS_GndForSky %d", upgrade_msg_queue_id);

    msgHeader   = (STRU_WIRELESS_MSG_HEADER *)u8_upgradeReply;
    msgContent  = (uint8_t *)msgHeader + sizeof(STRU_WIRELESS_MSG_HEADER);


    UPGRADE_Start();
	
    while (0x01 != UPGRADE_GndAndSkyLock())
    {
        HAL_Delay(50);
	wait_lock_time += 50;
	if(wait_lock_time >= 60000){
	    DLOG_Error("wait lock timeout, ota upgrade over!!!");
	    // vTaskDelete(NULL);
	}
        DLOG_Warning("wait lock");
    }

    while(1 != UPGRADE_WirelessGndSendInit(s_u16_wirelessUpgradeTotalPacket))
    {
        DLOG_Warning("wait sky init");
        HAL_Delay(50);
    }

    while(1)
    {
        if(UpgradeGndStatus_Get(UPGRADE_ACK_FAIL))	
	    break;
	
        if (u16_WirelessInterfacerecDataLength != 0)
        {
            if (u16_packetNum != u16_WirelessInterfacerecPacketNum)
            {
                while (0 != UPGRADE_SendDataBlock(UPGRADE_DATA_DATA, (uint8_t *)u8_WirelessInterfaceRecData, u16_WirelessInterfacerecDataLength, u16_WirelessInterfacerecPacketNum))
                {
                    HAL_Delay(10);
                }
                u16_packetNum = u16_WirelessInterfacerecPacketNum;
            }
            else
            {
                DLOG_Critical("Error packet num %d %d", u16_packetNum, u16_WirelessInterfacerecPacketNum);
            }

            u16_WirelessInterfacerecDataLength = 0;
            if (u8_upgradeLastPacket == 0)
            {
                msgHeader->magic_header[0] = 0xFF;
                msgHeader->magic_header[1] = 0x5A;
                msgHeader->msg_id = WIRELESS_INTERFACE_UPGRADE;
                msgHeader->msg_len = 1;
                msgHeader->packet_cur = 0;
                msgHeader->packet_num = 1;
                msgHeader->chk_sum = 0;

                msgContent[0] = 1;
                for (i = 0; i < msgHeader->msg_len; i++)
                {
                    msgHeader->chk_sum += msgContent[i];
                }

                retry_count = 0;
                while(HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
                {
                    ++retry_count;
                    HAL_Delay(10);
                }

            }
            else
            {
                u8_upgradeLastPacket = 0;
                break;
            }
        }
        HAL_Delay(5);
    }

    DLOG_Critical("send data finish %d", i);

    while( 0 == UpgradeGndStatus_Get(UPGRADE_ACK_CHECK) )
    {
        if(UpgradeGndStatus_Get(UPGRADE_ACK_LOSTDATA))
        {
            uint16_t * lostData;
            UPGRADE_GetStatus(&st_lostData);
            DLOG_Critical("lost packet %d ", st_lostData.u16_lostDataBlockCount);
            u8_retime = 0;
            if (st_lostData.u16_lostDataBlockCount == 0)
            {
                DLOG_Critical("packet no error");
                break;
            }
            else if (st_lostData.u16_lostDataBlockCount > 100)
            {
                DLOG_Critical("lost packet rec error");
                break;
            }

            msgHeader->magic_header[0]  = 0xFF;
            msgHeader->magic_header[1]  = 0x5A;
            msgHeader->msg_id           = WIRELESS_INTERFACE_UPGRADE;
            msgHeader->packet_num       = 1;
            msgHeader->packet_cur       = 0;
            msgHeader->msg_len          = 4 + st_lostData.u16_lostDataBlockCount * 2;// uint8 change to uint16
            msgHeader->chk_sum          = 0;

            msgContent[0] = 2;
            msgContent[1] = 0;
            msgContent[2] = (uint8_t)st_lostData.u16_lostDataBlockCount;
            msgContent[3] = (uint8_t)(st_lostData.u16_lostDataBlockCount >> 8);

            lostData = (uint16_t *)&(msgContent[4]);
            for (i = 0; i < st_lostData.u16_lostDataBlockCount; i++)
            {
                lostData[i] = st_lostData.u16_lostDataBlockArray[i];
            }
	    last_lostpacket_index = lostData[st_lostData.u16_lostDataBlockCount - 1];

            for (i = 0; i < msgHeader->msg_len; i++)
            {
                msgHeader->chk_sum += msgContent[i];
            }

            retry_count = 0;
            while (HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId))  && retry_count < 10)
            {
                ++retry_count;
                HAL_Delay(10);
            }

            memset(&st_lostData, 0, sizeof(st_lostData));
	    tick = SysTicks_GetUsTickCount();
            while(1)
            {
                if (0 != u16_WirelessInterfacerecDataLength){
		    DLOG_Critical("packet_num %d,last_lost %d ",u16_WirelessInterfacerecPacketNum, last_lostpacket_index);
                    while (0 != UPGRADE_SendDataBlock(UPGRADE_LOSTBLOCK_DATA, (uint8_t *)u8_WirelessInterfaceRecData, u16_WirelessInterfacerecDataLength, u16_WirelessInterfacerecPacketNum))
                    {
                        HAL_Delay(10);
                    }
                    u16_WirelessInterfacerecDataLength = 0;
		    msgHeader->magic_header[0] = 0xFF;
                    msgHeader->magic_header[1] = 0x5A;
                    msgHeader->msg_id = WIRELESS_INTERFACE_UPGRADE;
                    msgHeader->msg_len = 1;
                    msgHeader->packet_cur = 0;
                    msgHeader->packet_num = 1;
                    msgHeader->chk_sum = 1;


                    for(i = 0 ; i< sizeof(u8_upgradeReply); i++)
                    {
                        *(msgContent + i )= 0;
                    }

		    msgContent[0] = 1;

                    retry_count = 0;
                    while(HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 3)
                    {
                        ++retry_count;
                        HAL_Delay(10);
                    }
		    if( last_lostpacket_index == u16_WirelessInterfacerecPacketNum ){
		        last_lostpacket_index = 0xffff;
		    	break;
		    }
		    tick = SysTicks_GetUsTickCount();
                }
	        else{
		    tick_end = SysTicks_GetUsTickCount();
                    if(tick && (tick_end - tick) > 2500000  ){
		    	DLOG_Critical("sys_tick 2 %ld, tick %ld ", tick_end, tick);
		        break;
                    }
		    
	        }
            }
        }

	if ( UpgradeGndStatus_Get(UPGRADE_ACK_FAIL) ){
	    DLOG_Error("ack fail, break");	
            break;
	}

        if(u8_retime++ > 10){		// if times > 10 indicate gnd can't connect to sky
            DLOG_Error("timeout, break");
            break;
        }

        DLOG_Critical("wait sky receive data finish ");
        while (0 != UPGRADE_GndSendEnd())
        {
            HAL_Delay(50);
        }
        //HAL_Delay(2000);
        HAL_Delay(1000);
    }

    // report PC sky receive complete
    msgHeader->magic_header[0]  = 0xFF;
    msgHeader->magic_header[1]  = 0x5A;
    msgHeader->msg_id           = WIRELESS_INTERFACE_UPGRADE;
    msgHeader->packet_num       = 1;
    msgHeader->packet_cur       = 0;
    msgHeader->msg_len          = 1;
    msgHeader->chk_sum          = 0;

    msgContent[0] = 2;// retransmit finish flag(no retransmit quence)

    for (i = 0; i < msgHeader->msg_len; i++)
    {
        msgHeader->chk_sum += msgContent[0];
    }

    retry_count = 0;
    while (HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
    {
        HAL_Delay(10);
    }

    DLOG_Critical("sky check data");

    HAL_Delay(100);

    msgHeader->magic_header[0]  = 0xFF;
    msgHeader->magic_header[1]  = 0x5A;
    msgHeader->msg_id           = WIRELESS_INTERFACE_UPGRADE;
    msgHeader->packet_num       = 1;
    msgHeader->packet_cur       = 0;
    msgHeader->msg_len          = 1;
    msgHeader->chk_sum          = 0;

    while(1)
    {
        if (UpgradeGndStatus_Get(UPGRADE_ACK_END))
        {
            msgContent[0] = 1;

            DLOG_Critical("upgrade ok");

            break;
        }
        else if (UpgradeGndStatus_Get(UPGRADE_ACK_FAIL) || u8_retime > 10)
        {
            msgContent[0] = 3;

            DLOG_Error("upgrade fail");

            break;
        }
        else if (UpgradeGndStatus_Get(UPGRADE_ACK_END_CF_SUCCESS))
        {
            msgContent[0] = 5;

            DLOG_Error("upgrade ok");

            break;
        }

        HAL_Delay(1000);
    }

    for (i = 0; i < msgHeader->msg_len; i++)
    {
        msgHeader->chk_sum += msgContent[0];
    }

    retry_count = 0;
    while (HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
    {
        ++retry_count;
        HAL_Delay(10);
    }

    // vTaskDelete(NULL);
}
// uint8_t singletone_flag;
// void Wireless_SetSingleTone(uint8_t sinWaveFreq)
// {
//     uint32_t freg_reg;

//     BB_SPI_curPageWriteByte(0x01,0x02);
//     //SysTicks_DelayUS(1000*100);

//     BB_SPI_WriteByteMask(PAGE0, 0x62, 0x02, 0x02);
//     BB_SPI_WriteByteMask(PAGE0, 0x64, 0x00, 0x02);
//     BB_SPI_WriteByteMask(PAGE0, 0x61, 0x0c, 0x0f);
//     BB_SPI_WriteByteMask(PAGE0, 0x60, 0x0a, 0x0e);
//     BB_SPI_WriteByte(PAGE0,0x67,0x00);
//     BB_SPI_WriteByte(PAGE0,0x68,0x00);
//     BB_SPI_WriteByte(PAGE0,0x69,0x00);
//     BB_SPI_WriteByte(PAGE0,0x6a,0x00);
//     BB_SPI_WriteByte(PAGE0,0x6b,0x00);
//     BB_SPI_WriteByte(PAGE0,0x6c,0x00);
//     BB_SPI_WriteByte(PAGE0,0x6e,0x00);
//     BB_SPI_WriteByte(PAGE0,0x6f,0x00);
//     BB_SPI_WriteByte(PAGE0,0x69,0xff);
//     BB_SPI_WriteByte(PAGE0,0x6d,0xff);

//     freg_reg = ((uint32_t)(((float)0xffffffff*((float)sinWaveFreq / 100.0))+ 0.5)) ;
//     DLOG_Warning("reg = %08lx",freg_reg);
//     BB_SPI_WriteByte(PAGE0,0x7b,freg_reg>>24);
//     BB_SPI_WriteByte(PAGE0,0x7a,freg_reg>>16);
//     BB_SPI_WriteByte(PAGE0,0x79,freg_reg>>8);
//     BB_SPI_WriteByte(PAGE0,0x78,freg_reg);

//     BB_WriteReg(PAGE1,0x90,0xff);
//     BB_WriteReg(PAGE1,0x91,0xff);

//     BB_SPI_WriteByteMask(PAGE0, 0x20, 0x08, 0x0b);

//     BB_SPI_WriteByteMask(PAGE0,0x00,0x01,0x01);
//     BB_SPI_WriteByteMask(PAGE0,0x00,0x00,0x01);

//     SysTicks_DelayUS(1000*500);

//     BB_SPI_curPageWriteByte(0x01,0x01);

//     singletone_flag = 1;

//     DLOG_Warning("enter singletone mode");
// }

uint8_t                     wait_flag = 0;
uint16_t                    packet_index = 0;
uint8_t                     g_u8_upgrade_type;

void IRELESS_INTERFACE_UPGRADE_HandlerCallbak(void *p)
{
    uint32_t                     result;
    uint8_t                     *msgContent;
    STRU_WIRELESS_MSG_HEADER    *msgHeader;
    uint16_t                     i;
    STRU_HAL_SYS_CTL_CONFIG     *pst_cfg;
     uint8_t                     retry_count = 0;

    HAL_SYS_CTL_GetConfig(&pst_cfg);

    result = 1;

    if (u8_upgradeLastPacket  && (0 == u8_wirelessUpgradeRemoteFlag))
    {
	u8_upgradeLastPacket = 0;
        // Send ACK for last packet
        msgHeader = (STRU_WIRELESS_MSG_HEADER *)u8_upgradeReply;
        msgHeader->magic_header[0] = 0xFF;
        msgHeader->magic_header[1] = 0x5A;
        msgHeader->msg_id = WIRELESS_INTERFACE_UPGRADE_RECV_COMPLETE;
        msgHeader->msg_len = 1;
        msgHeader->packet_cur = 0;
        msgHeader->packet_num = 1;
        msgHeader->chk_sum = 0;

        msgContent      = (uint8_t *)(u8_upgradeReply + sizeof(STRU_WIRELESS_MSG_HEADER));
        msgContent[0]   = result;

        for (i = 0; i < msgHeader->msg_len; i++)
        {
            msgHeader->chk_sum += msgContent[i];
        }

        retry_count = 0;
        while(HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
        {
            ++retry_count;
            HAL_Delay(10);
        }
        ////////////////////////////////////////////////////

        if (-1 != UPGRADE_MD5SUM(RECEIVE_ADDR, 1))
        {
            DLOG_Critical("received data ok %d",s_writeFlash);

            if (s_writeFlash == 0x10)
            {
                switch(g_u8_upgrade_type)
                {
                    case 2:// boot
                        DLOG_Critical("WARNING:Upgrading Boot");
                        NOR_FLASH_BootUpgradeEnable();
                        s_writeFlash = UPGRADE_ModifyBootInfo(FLASH_BASE_ADDR);
                        NOR_FLASH_BootUpgradeDisable();
                        break;

                    case 3:// upgrade
                        s_writeFlash = UPGRADE_ModifyBootInfo(BOOT_ADDR0);
                        break;

                    case 4:// upgrade backup
                        s_writeFlash = UPGRADE_ModifyBootInfo(BOOT_ADDR1);
                        break;

                    case 0:// app
                        s_writeFlash = UPGRADE_ModifyBootInfo(APPLICATION_IMAGE_START0);
                        
                        msgHeader = (STRU_WIRELESS_MSG_HEADER *)u8_upgradeReply;
                        msgHeader->magic_header[0] = 0xFF;
                        msgHeader->magic_header[1] = 0x5A;
                        msgHeader->msg_id = WIRELESS_INTERFACE_UPGRADE;
                        msgHeader->msg_len = 1;
                        msgHeader->packet_cur = 0;
                        msgHeader->packet_num = 1;
                        msgHeader->chk_sum = 0;

                        msgContent      = (uint8_t *)(u8_upgradeReply + sizeof(STRU_WIRELESS_MSG_HEADER));
                        msgContent[0]   = 0x05;

                        for (i = 0; i < msgHeader->msg_len; i++)
                        {
                            msgHeader->chk_sum += msgContent[i];
                        }

                        retry_count = 0;
                        while(HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
                        {
                            ++retry_count;
                            HAL_Delay(10);
                        }
                        DLOG_Critical("send1 ~ 05!!!!!!!!!!!!!!!!! %d",s_writeFlash);
                        retry_count = 0;
                        while(HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
                        {
                            ++retry_count;
                            HAL_Delay(10);
                        }
                        DLOG_Critical("send2 ~ 05!!!!!!!!!!!!!!!!! %d",s_writeFlash);
                        retry_count = 0;
                        while(HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
                        {
                            ++retry_count;
                            HAL_Delay(10);
                        }

                        DLOG_Critical("send3 ~ 05!!!!!!!!!!!!!!!!! %d",s_writeFlash);

                        break;

#ifndef UPGRADE_DUAL_APP_DESIGN_EN
                    case 5:// app backup
                        s_writeFlash = UPGRADE_ModifyBootInfo(APPLICATION_IMAGE_START1);
                        break;
#endif
                    default:
                        DLOG_Error("Not Support Type");
                }

            }

            if (-1 != s_writeFlash)
            {
                result = 1;
                DLOG_Critical("upgrade flash success %d",s_writeFlash);
            }
            else
            {
                result = 0;
                DLOG_Error("upgrade flash fail %d",s_writeFlash);
            }
        }
        else
        {
            result = 0;
            DLOG_Error("received data fail");
        }
    }

    if (1 != u8_wirelessUpgradeRemoteFlag)
    {
        msgHeader = (STRU_WIRELESS_MSG_HEADER *)u8_upgradeReply;
        msgHeader->magic_header[0] = 0xFF;
        msgHeader->magic_header[1] = 0x5A;
        msgHeader->msg_id = WIRELESS_INTERFACE_UPGRADE;
        msgHeader->msg_len = 1;
        msgHeader->packet_cur = 0;
        msgHeader->packet_num = 1;
        msgHeader->chk_sum = 0;

        msgContent      = (uint8_t *)(u8_upgradeReply + sizeof(STRU_WIRELESS_MSG_HEADER));
        msgContent[0]   = result;

        for (i = 0; i < msgHeader->msg_len; i++)
        {
            msgHeader->chk_sum += msgContent[i];
        }

        if(0 == pst_cfg->u8_workMode)
        {
            if(0 == packet_index && (0 == wait_flag || 1 == wait_flag))
            {
                if(0 == wait_flag)
                {
                    HAL_Delay(100);

                    Reg_Write32(0x40B00068, 0x01);
                    //bb modify sdram register,if ground use sdram to upgrade,sdram must be reset.
                    //reset sdrm
                    (*(volatile uint32_t *)0xA0030078) = 0;
                    (*(volatile uint32_t *)0xA0030078) = 1;
                    //check sdram init ok
                    while(!((*(volatile uint32_t *)0xA0030024)) & 0x01)
                    {
                        ;
                    }
                }

                ++wait_flag;
            }

            if(wait_flag > 1 || packet_index != 0)
            {
                wait_flag = 0;
                retry_count = 0;
                while(HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
                {
                    ++retry_count;
                    HAL_Delay(10);
                }
            }
        }
        else
        {
            retry_count = 0;
            while(HAL_OK != (HAL_USB_SendCtrl((uint8_t *)msgHeader, sizeof(u8_upgradeReply), u8_upgradeUSBId)) && retry_count < 10)
            {
                ++retry_count;
                HAL_Delay(10);
            }
        }
    }
}


uint8_t WIRELESS_INTERFACE_UPGRADE_Handler(void *param, uint8_t id)
{
    uint8_t                     *msgContent;
    STRU_WIRELESS_MSG_HEADER    *msgHeader;
    // uint16_t                     msgLen;
    // uint16_t                     i;
    uint16_t                     u16_packetLen;
    static uint32_t              u32_sdramAddr = RECEIVE_ADDR;
    // static uint32_t              u32_dataLength = 0;
    static uint16_t              su16_packetPosition = 0xFFFF;
    // uint32_t                     result = 0;
    uint16_t                     packet_total;
    uint8_t                      upgrade_type;
    STRU_SysEvent_H264InputFormatChangeParameter  st_formatChange1;
    STRU_SysEvent_H264InputFormatChangeParameter  st_formatChange2;
    STRU_SysEvent_H264InputFormatChangeParameter  st_formatChange3;
    STRU_HAL_SYS_CTL_CONFIG     *pst_cfg;


    msgContent              = (uint8_t *)param;

    msgHeader               = (STRU_WIRELESS_MSG_HEADER *)msgContent;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    packet_index            = (msgContent[2] + (msgContent[3] << 8));
    packet_total            = (msgContent[4] + (msgContent[5] << 8));
    upgrade_type            = msgContent[0];


	SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_CPU0_INTO_UPGRADE, (void *)NULL);

    if (packet_index == 0)
    {
        DLOG_Critical("packet_index == 0");
		
        u32_sdramAddr = RECEIVE_ADDR;
        // u32_dataLength = 0;
        su16_packetPosition = 0xFFFF;

        u8_upgradeLastPacket = 0;
        if(s_writeFlash != -1)
        {
            s_writeFlash = 0x10;
        }

        CPUINFO_DCacheInvalidate();
        CPUINFO_DCacheClean();

        //switch sky mode, local upgrade
        //0x00: local app,   0x02: local boot,   0x03: local upgrade,
        //0x04: local upgrade backup,   0x05: local app backup
        if (upgrade_type == 0x00 || upgrade_type == 0x02 || upgrade_type == 0x03 ||
            upgrade_type == 0x04 || upgrade_type == 0x05)
        {
            SYS_EVENT_RegisterHandler(SYS_EVENT_ID_WIRELESS_UPGRADE, IRELESS_INTERFACE_UPGRADE_HandlerCallbak);

            HAL_SYS_CTL_GetConfig(&pst_cfg);

            if(0 == pst_cfg->u8_workMode)
            {
                // close view 0
                st_formatChange1.index = 0;
                st_formatChange1.width = 0;
                st_formatChange1.hight = 0;
                st_formatChange1.framerate = 0;
                SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE, (void*)&st_formatChange1);

                // close view 1
                st_formatChange2.index = 1;
                st_formatChange2.width = 0;
                st_formatChange2.hight = 0;
                st_formatChange2.framerate = 0;
                SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE, (void*)&st_formatChange2);

                // disable all SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE
                st_formatChange3.reserve[0] = 0x5A;
                st_formatChange3.reserve[1] = 0xA5;
                SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE, (void*)&st_formatChange3);
            }
            else
            {
                Reg_Write32(0x40B00068, 0x01);
                //bb modify sdram register,if ground use sdram to upgrade,sdram must be reset.
                //reset sdrm
                (*(volatile uint32_t *)0xA0030078) = 0;
                (*(volatile uint32_t *)0xA0030078) = 1;
                //check sdram init ok
                while(!((*(volatile uint32_t *)0xA0030024)) & 0x01)
                {
                    ;
                }
            }

            if(s_writeFlash != -1)
            {
                g_u8_upgrade_type = upgrade_type;
            }
            else if(g_u8_upgrade_type == upgrade_type)
            {
                s_writeFlash = 0x10;
            }

            DLOG_Critical("enter sky mode");
        }
        else if(upgrade_type == 0x01)// remate app
        {
            DLOG_Critical("upgrade_type == 1");

            // osMessagePut(upgrade_msg_queue_id, 0, 0);
            u8_wirelessUpgradeRemoteFlag = 1;

	    if(s_writeFlash != -1)
            {
                g_u8_upgrade_type = upgrade_type;
            }
            else if(g_u8_upgrade_type == upgrade_type)
            {
                s_writeFlash = 0x10;
            }
        }
        else
        {
            DLOG_Error("Not support upgrade type");
            return 0;
        }
    }

    if(g_u8_upgrade_type != upgrade_type)
    {
        return 0;
    }

    u16_packetLen = (msgHeader->msg_len - 6);

    u8_upgradeUSBId = id;

    if (1 == u8_wirelessUpgradeRemoteFlag)
    {

        if (0 != u16_WirelessInterfacerecDataLength)
        {
            //DLOG_Critical("Upgrade data send too fast, drop: %d", packet_index);
	    DLOG_Critical("drop packet: %d", packet_index);
        }
        else
        {
            memcpy((uint8_t *)(u8_WirelessInterfaceRecData),(msgContent + 6),u16_packetLen);

            u16_WirelessInterfacerecPacketNum  = packet_index;

            DLOG_Critical("get packet_index: %d total = %d", packet_index, packet_total);

            s_u16_wirelessUpgradeTotalPacket   = packet_total;

            u16_WirelessInterfacerecDataLength = u16_packetLen;
        }

        if ((packet_index + 1) == packet_total)
        {
            u8_upgradeLastPacket = 1; // transmission complete
        }
    }
    else
    {
        /* copy to SDRAM */
        memcpy((uint8_t *)(u32_sdramAddr),(msgContent + 6),u16_packetLen);

        if (su16_packetPosition != packet_index)
        {
            u32_sdramAddr += u16_packetLen;
            u32_WirelessInterfaceRecCount += u16_packetLen;
            su16_packetPosition = packet_index;


            if ((packet_index + 1) == packet_total)
            {
                u8_upgradeLastPacket = 1; // transmission complete
            }
        }

        SYS_EVENT_Notify_From_ISR(SYS_EVENT_ID_WIRELESS_UPGRADE, NULL);
    }

    return 0;
}


uint8_t WIRELESS_INTERFACE_ENTER_TEST_MODE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_ENTER_TEST_MODE_Handler\n");

    if (WIRELESS_IsInDebugMode() == 1)
    {
        BB_SPI_WriteByte(PAGE2, 0x02, 0x06);
    }
    else
    {
        HAL_BB_SetItOnlyFreqProxy(1);
    }

    return 0;
}


uint8_t WIRELESS_INTERFACE_SYNCHRONIZE_FREQ_CHANNEL_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SYNCHRONIZE_FREQ_CHANNEL_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_AUTO_MODE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_AUTO_MODE_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SELF_ADAPTION_MODE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SELF_ADAPTION_MODE_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_TX_MODE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_TX_MODE_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_RX_MODE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_RX_MODE_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_USB1_MODE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_USB1_MODE_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_USB2_MODE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_USB2_MODE_Handler\n");

    return 0;
}




__attribute__((weak)) void board_reset_all(void)
{

}


uint8_t WIRELESS_INTERFACE_ALL_RESET_Handler(void *param, uint8_t id)
{
    
    uint8_t buff[1] = {1};
    Wireless_InsertMsgIntoReplyBuff(0x0a, 1, 1, 0, buff, id);
    
    DLOG_Critical("WIRELESS_INTERFACE_ALL_RESET_Handler\n");
    board_reset_all();
    
    return 0;
}


uint8_t WIRELESS_INTERFACE_RX_RESET_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_RX_RESET_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_TX_RESET_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_TX_RESET_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_MIMO_1T2R_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_MIMO_1T2R_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_WRITE_BB_REG_Handler(void *param, uint8_t id)
{
    uint8_t             *msgContent;

    msgContent          = (uint8_t *)param;
    msgContent         += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (WIRELESS_IsInDebugMode() == 1)
    {
        if (BB_SPI_curPageWriteByte(msgContent[0], msgContent[1]))
        {
            DLOG_Error("write fail!\n");

            return 1;
        }
    }
    else
    {
        Wireless_InsertMsgIntoReplyBuff(0x0e, 0, 1, 0, NULL, id);
    }

    return 0;
}


uint8_t WIRELESS_INTERFACE_READ_BB_REG_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (WIRELESS_IsInDebugMode() == 1)
    {
        msgContent[1] = BB_SPI_curPageReadByte(msgContent[0]);

        Wireless_InsertMsgIntoReplyBuff(0x0f, 2, 1, 0, msgContent, id);
    }
    else
    {
        Wireless_InsertMsgIntoReplyBuff(0x0f, 0, 1, 0, NULL, id);
    }

    return 0;
}


uint8_t WIRELESS_INTERFACE_MIMO_2T2R_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_MIMO_1T2R_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_OSD_DISPLAY_Handler(void *param, uint8_t id)
{
    // uint8_t                *msgContent;

    // msgContent              = (uint8_t *)param;
    // msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    // if (id > HAL_USB_PORT_NUM)
    // {
    //     DLOG_Error("error usb port id");

    //     return 1;
    // }

    // g_pstWirelessInfoDisplay  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;

    // if (msgContent[0] == 0)
    // {
    //     DLOG_Info("close osd: %d", id);

    //     g_u8OSDEnable[id] = 0;

    //     if ((g_u8OSDEnable[0] == 0)&&
    //         (g_u8OSDEnable[1] == 0))
    //     {
    //         g_pstWirelessInfoDisplay->osd_enable = 0;
    //     }
    // }
    // else
    // {
    //     DLOG_Info("open osd: %d", id);

    //     g_u8OSDEnable[id] = 1;
    //     g_pstWirelessInfoDisplay->osd_enable = 1;
    // }

    return 0;
}


uint8_t WIRELESS_INTERFACE_GET_ID_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_GET_ID_Handler\n");
    return 0;
}


uint8_t WIRELESS_INTERFACE_GET_GROUND_TX_PWR_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_GET_GROUND_TX_PWR_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_GET_SKY_TX_PWR_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_GET_SKY_TX_PWR_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_GET_RC_FREQ_CHANNEL_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_GET_RC_FREQ_CHANNEL_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_GET_VIDEO_FREQ_CHANNEL_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_GET_VIDEO_FREQ_CHANNEL_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_GET_SOFTWARE_VERSION_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_GET_SOFTWARE_VERSION_Handler\n");

    return 0;
}

uint8_t       DeviceInfo[64];
uint8_t WIRELESS_INTERFACE_GET_DEV_INFO_Handler(void *param, uint8_t id)
{
    STRU_DEVICE_INFO       *pstDeviceInfo;
    uint8_t                *msgContent;
    uint16_t                i;

    // DLOG_Info("--\n");

    pstDeviceInfo           = (STRU_DEVICE_INFO *)DEVICE_INFO_SHM_ADDR;

    memcpy((void *)&DeviceInfo, (void *)pstDeviceInfo, sizeof(STRU_DEVICE_INFO));

    pstDeviceInfo           = (STRU_DEVICE_INFO *)DeviceInfo;

    pstDeviceInfo->magic_header[0]   = 0xFF;
    pstDeviceInfo->magic_header[1]   = 0x5A;
    pstDeviceInfo->msg_id            = WIRELESS_INTERFACE_GET_DEV_INFO;
    pstDeviceInfo->packet_num        = 1;
    pstDeviceInfo->packet_cur        = 0;
    pstDeviceInfo->msg_len           = sizeof(STRU_DEVICE_INFO) - sizeof(STRU_WIRELESS_MSG_HEADER);
    pstDeviceInfo->msg_chksum        = 0;

    msgContent  = (uint8_t *)(DeviceInfo + sizeof(STRU_WIRELESS_MSG_HEADER));

    for (i = 0; i < pstDeviceInfo->msg_len; i++)
    {
        pstDeviceInfo->msg_chksum   += msgContent[i];

        // DLOG_Info("%02x", msgContent[i]);
    }

	// if (HAL_USB_Get_USB_DR_Mode(id) == HAL_USB_DR_MODE_HOST)
	// {
	// 	if(g_mtp_enable)
	// 		USBH_MTP_Send((uint8_t *)pstDeviceInfo, sizeof(STRU_DEVICE_INFO));	
	// }
    // else
    // {
        if (HAL_OK != HAL_USB_DeviceSendCtrl((uint8_t *)pstDeviceInfo, sizeof(STRU_DEVICE_INFO), id))
        {
            DLOG_Error("send osd info error");
        }
    // }

    return 0;
}


uint8_t WIRELESS_INTERFACE_SET_RC_FREQ_CHANNEL_MASK_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SET_RC_FREQ_CHANNEL_MASK_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SET_VIDEO_FREQ_CHANNEL_MASK_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SET_VIDEO_FREQ_CHANNEL_MASK_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SELECT_VIDEO_FREQ_CHANNEL_Handler(void *param, uint8_t id)
{

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_QAM_MODE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_QAM_MODE_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SET_RC_FREQ_CHANNEL_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    uint8_t                 u8_index;
    uint32_t                u32_freValue = 0;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (WIRELESS_IsInDebugMode() == 1)
    {
        for (u8_index = 0; u8_index < msgContent[2]; ++u8_index)
        {
            BB_SPI_WriteByte(msgContent[0],msgContent[1],msgContent[u8_index+3]);
            msgContent[1] += 1;
        }
    }
    else
    {
        for (u8_index = 0; u8_index < msgContent[2]; ++u8_index)
        {
            u32_freValue = (u32_freValue << 8) + msgContent[u8_index+3];
        }
        HAL_BB_SetRcFreqProxy(u32_freValue);
    }

    return 0;
}


uint8_t WIRELESS_INTERFACE_SET_TX_PWR_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SET_TX_PWR_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SET_VIDEO_TX_ID_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SET_VIDEO_TX_ID_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SET_CTRL_ID_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SET_CTRL_ID_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_WORKING_FREQ_BAND_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_RF_BAND            enRfBand;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] == 0)
    {
        DLOG_Info("2.4 G\n");
        enRfBand = RF_2G;
    }
    else
    {
        DLOG_Info("5.8 G\n");
        enRfBand = RF_5G;
    }

    HAL_BB_SetFreqBandProxy(enRfBand);

    return 0;
}


uint8_t WIRELESS_INTERFACE_RC_SCAN_ALL_BAND_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_RC_SCAN_ALL_BAND_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_RC_SCAN_WORKING_BAND_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_RC_SCAN_WORKING_BAND_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_VIDEO_SCAN_ALL_BAND_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_VIDEO_SCAN_ALL_BAND_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_VIDEO_SCAN_WORKING_BAND_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_VIDEO_SCAN_WORKING_BAND_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_RECOVER_TO_FACTORY_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_RECOVER_TO_FACTORY_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_RC_HOPPING_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_RUN_MODE           e_mode;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] == 1)
    {
        e_mode      = AUTO;

        DLOG_Info("RC HOPPING MODE\n");
    }
    else
    {
        e_mode      = MANUAL;

        DLOG_Info("RC SELECT MODE\n");
    }

    HAL_BB_SetRcChannelSelectionModeProxy(e_mode);

    return 0;
}


uint8_t WIRELESS_INTERFACE_SAVE_CONFIGURE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SAVE_CONFIGURE_Handler\n");

    return 0;
}

uint8_t WIRELESS_INTERFACE_READ_MCU_ID_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_READ_MCU_ID_Handler\n");

    return 0;
}

uint8_t WIRELESS_INTERFACE_SWITCH_DEBUG_MODE_Handler(void *param, uint8_t id)
{
    uint8_t                 inDebugFlag = 0;
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] == 0 && msgContent[1] == 0)
    {
        /*enter debug mode */
        if (!eventFlag)
        {
           HAL_BB_SetBoardDebugModeProxy(0);
           eventFlag = 1;
        }

        inDebugFlag = 1;
    }
    else if (msgContent[0] != 0 && msgContent[1] == 0)
    {
        /*exit debug mode */
        if (eventFlag)
        {
            BB_SPI_DisableEnable(0); //
            HAL_BB_SetBoardDebugModeProxy(1);
            eventFlag = 0;
        }

        //Force cpu0 not write BB spi anymore
        g_pstWirelessInfoDisplay  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;
        g_pstWirelessInfoDisplay->in_debug = 0;

        inDebugFlag = 0;
    }

    /*send to PC*/
    msgContent[1] = inDebugFlag;

    Wireless_InsertMsgIntoReplyBuff(WIRELESS_INTERFACE_SWITCH_DEBUG_MODE, 2, 1, 0, msgContent, id);

    return 0;
}

uint8_t WIRELESS_INTERFACE_WRITE_RF9363_Handler(void *param, uint8_t id)
{

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_PURE_VT_MODE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetPureVtMode(msgContent[0]);

    return 0;

}

uint8_t WIRELESS_INTERFACE_CMD_SELECT_FILTER_Handler(void *param, uint8_t id)
{
    // uint8_t                *msgContent;

    // msgContent              = (uint8_t *)param;
    // msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    // HAL_BB_CmdSelectFilter(msgContent[0]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_CMD_VT_SWEEP_Handler(void *param, uint8_t id)
{
    // uint8_t                *msgContent;

    // msgContent              = (uint8_t *)param;
    // msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    // HAL_BB_CmdVtSweep(msgContent[0]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_SWEEP_MODE_Handler(void *param, uint8_t id)
{
    // uint8_t                *msgContent;

    // msgContent              = (uint8_t *)param;
    // msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    // HAL_BB_SetSweepMode(msgContent[0]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_CHIP_ID_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_NV_SaveChipId((void *)(&msgContent[0]));

    return 0;
}


uint8_t WIRELESS_INTERFACE_RW_BB_RF_REG_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_RwBbRfReg(msgContent);

    return 0;

}
uint8_t WIRELESS_INTERFACE_SINGLE_TONE_Handler(void *param, uint8_t id)
{
    // uint8_t                *msgContent;

    // msgContent              = (uint8_t *)param;
    // msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    // if (WIRELESS_IsInDebugMode() == 1)
    // {
    //     Wireless_SetSingleTone(msgContent[0]);
    // }
    // else
    // {
    //     DLOG_Warning("single tone, must debug mode");
    // }
    return 0;

}

uint8_t WIRELESS_INTERFACE_BB_SAVE_RC_ID_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SaveRcId(msgContent, msgContent + RC_ID_SIZE);

    DLOG_Info("id:0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x",msgContent[0], msgContent[1], msgContent[2], msgContent[3], msgContent[4], msgContent[5], msgContent[6]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_BB_SET_TMP_RC_VT_ID_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetTmpRcVtId(msgContent, msgContent + RC_ID_SIZE);

    DLOG_Info("id:0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x",msgContent[0], msgContent[1], msgContent[2], msgContent[3], msgContent[4], msgContent[5], msgContent[6]);

    return 0;
}


uint8_t WIRELESS_INTERFACE_GET_OSD_INFO_ONCE_Handler(void *param, uint8_t id)
{
    // g_pstWirelessInfoDisplay  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;

    // if (g_pstWirelessInfoDisplay->osd_enable)
    // {
    //     if (g_u8OSDEnable[id])
    //     {
    //         return 0;
    //     }
    //     else
    //     {
    //         g_u8OSDOnce[id] = 1;
    //         g_u8OSDEnable[id] = 1;
    //     }
    // }
    // else
    // {
    //     g_u8OSDOnce[id] = 1;
    //     g_u8OSDEnable[id] = 1;

    //     g_pstWirelessInfoDisplay->osd_enable = 1;
    // }

    return 0;
}


uint8_t WIRELESS_INTERFACE_BB_GET_RC_ID_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    memcpy(msgContent, (uint8_t *)(SRAM_SHARE_FLAG_ST_ADDR + SHARE_FLAG_RC_ID_OFFSET), 5);

    Wireless_InsertMsgIntoReplyBuff(WIRELESS_INTERFACE_BB_GET_RC_ID, 5, 1, 0, msgContent, id);

    DLOG_Warning("WIRELESS_INTERFACE_BB_GET_RC_ID:  %x %x %x %x %x",
                                            msgContent[0],
                                            msgContent[1],
                                            msgContent[2],
                                            msgContent[3],
                                            msgContent[4]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_ENABLE_FREQUENCY_Handler(void *param, uint8_t id)
{
    SYS_EVENT_Notify_From_ISR(SYS_EVENT_ID_TO_APP, (void*)(param));
    return 0;
}

uint8_t WIRELESS_INTERFACE_SLEEP_MODE_SET_Handler(void *param, uint8_t id)
{
    SYS_EVENT_Notify_From_ISR(SYS_EVENT_ID_TO_APP, (void*)(param));
    return 0;
}

uint8_t WIRELESS_INTERFACE_FCT_RESET_Handler(void *param, uint8_t id)
{
    SYS_EVENT_Notify_From_ISR(SYS_EVENT_ID_TO_APP, (void*)(param));

    return 0;
}

uint8_t WIRELESS_INTERFACE_TAKE_PICTURE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_TakePicture(msgContent[0]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_PICTURE_QUALITY_SET_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_PictureQualitySet(msgContent[0]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SUB_BAND_SET_CH_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SubBandSetCH(msgContent[0]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_POWER_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent              += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetPower(*msgContent, *(msgContent+1));
    DLOG_Warning("power: %d %d", *msgContent, *(msgContent+1));
    return 0;
}

uint8_t WIRELESS_INTERFACE_BB_GET_CHIP_ID_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    memcpy(msgContent, (uint8_t *)(SRAM_SHARE_FLAG_ST_ADDR + SHARE_FLAG_CHIP_ID_OFFSET), 5);

    Wireless_InsertMsgIntoReplyBuff(WIRELESS_INTERFACE_BB_GET_CHIP_ID, 5, 1, 0, msgContent, id);

    DLOG_Warning("WIRELESS_INTERFACE_BB_GET_CHIP_ID: %x %x %x %x %x",
                                            msgContent[0],
                                            msgContent[1],
                                            msgContent[2],
                                            msgContent[3],
                                            msgContent[4]);

    return 0;
}



uint8_t WIRELESS_INTERFACE_WRITE_RF_REG_Handler(void *param, uint8_t id)
{

    return 1; // failed
}


uint8_t WIRELESS_INTERFACE_OPEN_VIDEO_Handler(void *param, uint8_t id)
{
    HAL_USB_OpenVideo(id);

    return 0;
}


uint8_t WIRELESS_INTERFACE_CLOSE_VIDEO_Handler(void *param, uint8_t id)
{
    HAL_USB_CloseVideo(id);

    return 0;
}


uint8_t WIRELESS_INTERFACE_READ_RF9363_Handler(void *param, uint8_t id)
{   

    return 0;
}


uint8_t WIRELESS_INTERFACE_READ_RF_REG_Handler(void *param, uint8_t id)
{
    return 0;
}


uint8_t WIRELESS_INTERFACE_LOAD_SKY_REG_TABLE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_LOAD_SKY_REG_TABLE_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_LOAD_GRD_REG_TABLE_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_LOAD_GRD_REG_TABLE_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_BB_POWER_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_BB_POWER_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SKY_ONLY_RX_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SKY_ONLY_RX_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_RF_PWR_0_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_RF_PWR_0_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_RF_PWR_1_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_RF_PWR_1_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_EXT_ONEKEY_IT_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_EXT_ONEKEY_IT_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_IT_CHAN_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_IT_CHAN_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SWITCH_RMT_CHAN_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SWITCH_RMT_CHAN_Handler\n");

    return 0;
}
uint8_t WIRELESS_INTERFACE_SET_PWR_CAL_0_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SET_PWR_CAL_0_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_SET_PWR_CAL_1_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_SET_PWR_CAL_1_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_RST_MCU_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_RST_MCU_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_RF_PWR_AUTO_Handler(void *param, uint8_t id)
{
    DLOG_Info("WIRELESS_INTERFACE_RF_PWR_AUTO_Handler\n");

    return 0;
}


uint8_t WIRELESS_INTERFACE_OPEN_ADAPTION_BIT_STREAM_Handler(void *param, uint8_t id)
{
    ENUM_RUN_MODE           enRunMode;
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] == 1)
    {
        enRunMode           = AUTO;

        DLOG_Info("auto\n");
    }
    else
    {
        enRunMode           = MANUAL;

        DLOG_Info("manual\n");
    }

    HAL_BB_SetMcsModeProxy(enRunMode);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SWITCH_CH1_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    uint8_t                 u8_data = 0;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    DLOG_Info("WIRELESS_INTERFACE_SWITCH_CH1_Handler");

    if (msgContent[0] == 0)
    {
        DLOG_Info("ch1 off");
        u8_data = 0;
    }
    else
    {
        DLOG_Info("ch1 on");
        u8_data = 1;
    }

    HAL_BB_SwitchOnOffChProxy(0, u8_data);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SWITCH_CH2_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    uint8_t                 u8_data = 0;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    DLOG_Info("WIRELESS_INTERFACE_SWITCH_CH2_Handler");

    if (msgContent[0] == 0)
    {
        DLOG_Info("ch1 off");
        u8_data = 0;
    }
    else
    {
        DLOG_Info("ch1 on");
        u8_data = 1;
    }

    HAL_BB_SwitchOnOffChProxy(1, u8_data);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_CH1_BIT_RATE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    DLOG_Info("set ch1 bit rate");

    HAL_BB_SetEncoderBitrateProxy(0, msgContent[0]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_CH2_BIT_RATE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    DLOG_Info("set ch2 bit rate");

    HAL_BB_SetEncoderBitrateProxy(1, msgContent[0]);

    return 0;
}

uint8_t WIRELESS_INTERFACE_VIDEO_QAM_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_BB_QAM             enBBQAM;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    enBBQAM             = (ENUM_BB_QAM)(msgContent[0] & 0x3);


    DLOG_Critical("QAM : %d", msgContent[0]);

    HAL_BB_SetFreqBandQamSelectionProxy(enBBQAM);

    return 0;
}

uint8_t WIRELESS_INTERFACE_VIDEO_CODE_RATE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_BB_LDPC            enldpc;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    enldpc                  = (ENUM_BB_LDPC)msgContent[0];

    DLOG_Critical("ldpc: %d", msgContent[0]);

    HAL_BB_SetItLdpcProxy(enldpc);

    return 0;
}

uint8_t WIRELESS_INTERFACE_RC_QAM_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_BB_QAM             enBBQAM;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    enBBQAM             = (ENUM_BB_QAM)(msgContent[0] & 0x1);

    DLOG_Info("RC QAM : %d", msgContent[0]);

    HAL_BB_SetRcQamSelectionProxy(enBBQAM);

    return 0;
}

uint8_t WIRELESS_INTERFACE_RC_CODE_RATE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_BB_LDPC            e_ldpc;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    DLOG_Info("RC CODE RATE: %d", msgContent[0]);

    switch (msgContent[0])
    {
        case 0:
            e_ldpc      = LDPC_1_2;
            break;

        case 1:
            e_ldpc      = LDPC_2_3;
            break;

        default:
            e_ldpc      = LDPC_1_2;
            break;
    }

    HAL_BB_SetRcLdpcProxy(e_ldpc);

    return 0;
}

uint8_t WIRELESS_INTERFACE_VIDEO_AUTO_HOPPING_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_RUN_MODE           e_mode;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] == 1)
    {
        e_mode      = AUTO;

        DLOG_Info("VIDEO HOPPING MODE\n");
    }
    else
    {
        e_mode      = MANUAL;

        DLOG_Info("VIDEO SELECT MODE\n");
    }

    HAL_BB_SetItChannelSelectionModeProxy(e_mode);

    return 0;
}

uint8_t WIRELESS_INTERFACE_VIDEO_BAND_WIDTH_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_CH_BW              enBandWidth;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] == 2)
    {
        DLOG_Info("10M Bandwidth\n");
        enBandWidth             = BW_10M;
    }
    else
    {
        DLOG_Info("20M Bandwidth\n");
        enBandWidth             = BW_20M;
    }

    HAL_BB_SetFreqBandwidthSelectionProxy(enBandWidth);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_LNA_STATUS_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    // ENUM_CH_BW              enBandWidth;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] < 6)
    {
        HAL_BB_SetLnaStatusProxy(msgContent[0]);
    }
    else
    {
        DLOG_Warning("%d failed",msgContent[0]);
    }

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_NON_LBT_STATUS_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    // ENUM_CH_BW              enBandWidth;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] < 2)
    {
        HAL_BB_SetNonLbt(msgContent[0]);
    }
    else
    {
        DLOG_Warning("%d failed",msgContent[0]);
    }

    return 0;
}
uint8_t WIRELESS_INTERFACE_SET_BANDEDGE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    // ENUM_CH_BW              enBandWidth;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    if (msgContent[0] < 2)
    {
        HAL_BB_SetBandedge(msgContent[0],msgContent[1]);
    }
    else
    {
        DLOG_Warning("%d failed",msgContent[0]);
    }

    return 0;
}

uint8_t WIRELESS_INTERFACE_OPERATE_REG_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    uint32_t               *regAddr;
    uint32_t                regValue;
    uint32_t                temp = 0;
    uint8_t                 addrOffset;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    addrOffset              = msgContent[1];

    regAddr                 = (uint32_t *)(0xA0010000 + (addrOffset - (addrOffset & 0x3)));

    addrOffset             &= 0x3;
    /* little-big endian change */
    addrOffset              = (3 - addrOffset);

    regValue                = *(uint32_t *)regAddr;

    /* read register */
    if (msgContent[0] == 0)
    {
        temp                = regValue;
        temp              >>= (addrOffset << 3);

        msgContent[2] = (uint8_t)temp;
    }
    /* write register */
    else if (msgContent[0] == 1)
    {
        temp                   = msgContent[2];
        temp                  &= 0xFF;
        temp                 <<= (addrOffset << 3);

        regValue              &= ~(0xFF << (addrOffset << 3));
        regValue              |= temp;

        *regAddr               = regValue;
    }
    else
    {
        return 1;
    }

    Wireless_InsertMsgIntoReplyBuff(WIRELESS_INTERFACE_OPERATE_REG, 3, 1, 0, msgContent, id);

    return 0;
}

uint8_t WIRELESS_INTERFACE_BB_SOFT_RESET_Handler(void *param, uint8_t id)
{
    // if(singletone_flag)
    // {
    //     BB_SPI_curPageWriteByte(0x01,0x02);

    //     SysTicks_DelayUS(500000);
    //     DLOG_Warning("%02x",BB_SPI_ReadByte(PAGE0,0x00));
    //     BB_SPI_WriteByteMask(PAGE0,0x00,0x01,0x01);
    //     DLOG_Warning("%02x",BB_SPI_ReadByte(PAGE0,0x00));
    //     //SysTicks_DelayUS(1000);
    //     BB_SPI_WriteByteMask(PAGE0,0x00,0x00,0x01);
    //     DLOG_Warning("%02x",BB_SPI_ReadByte(PAGE0,0x00));

    //     SysTicks_DelayUS(1000*500);

    //     BB_SPI_curPageWriteByte(0x01,0x01);

    //     DLOG_Warning("singletone reset");

    //     return 0;
    // }

    HAL_BB_SoftResetProxy();

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_SKYorGRD_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    STRU_WIRELESS_RESET_DATA_RSV *p;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);
    p                       = (STRU_WIRELESS_RESET_DATA_RSV *)(SRAM_USR_GRD_SKY_SELECT_ST_ADDR);

    if(msgContent[0] > 1)
    {
        p->magic_header         = 0;
        DLOG_Warning("%d : clear sram sky/grd flag",msgContent[0]);
        msgContent[0] = 0;
        Wireless_InsertMsgIntoReplyBuff(WIRELESS_INTERFACE_SET_SRAM_SKY_OR_GRD, 1, 1, 0, msgContent, id);
        while(1);//wait watch dog reset
    }
    else
    {
        p->magic_header         = 0x1234abcd;
        p->sky_or_grd           = msgContent[0];
        DLOG_Warning("set %s",p->sky_or_grd == 0 ? "sky" : "grd");
        while(1);//wait watch dog reset
    }

    return 0;
}

uint8_t WIRELESS_INTERFACE_GET_BESIDE_DEV_NUM_Handler(void *param, uint8_t id)
{
    uint8_t value;

    STRU_WIRELESS_INFO_DISPLAY *p  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;
    if(p->find_beside_dev_finish)
    {
        value = p->find_beside_dev_num;
    }
    else
    {
        value = 0xff;
    }
    Wireless_InsertMsgIntoReplyBuff(WIRELESS_INTERFACE_GET_BESIDE_DEV_NUM, 1, 1, 0, &value, id);

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_GRD_SLAVE_MODE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetGrdSlaveMode(msgContent, msgContent + RC_ID_SIZE);
    return 0;

}

uint8_t WIRELESS_INTERFACE_SET_FIND_BESIDE_DEV_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetSkyFindBesideDevMode(msgContent[0]);

    return 0;

}

uint8_t WIRELESS_INTERFACE_RESET_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    while(1);

    return 0;

}

STRU_FACTORY_SETTING     g_factoryDataBuffer;
uint8_t                 *g_pFactoryDataBuffer = NULL;
uint8_t                  g_reportFactoryDataBuffer[512];

static void Wireless_ReportFactoryData(uint8_t id)
{
    STRU_WIRELESS_MSG_HEADER            *pst_factoryDataHeader;
    uint8_t                             *pst_factoryData;
    uint8_t         packet_index = 0;
    uint8_t         packet_num;
    uint16_t        last_packet_size = 0;
    uint16_t        i;
    uint16_t        msg_len = 0;

    DLOG_Critical("report factory data");

    FCT_CopySetting((void *)&g_factoryDataBuffer, sizeof(STRU_FACTORY_SETTING));

    g_pFactoryDataBuffer = (uint8_t *)&g_factoryDataBuffer;

    packet_num = sizeof(STRU_FACTORY_SETTING) / (512 - sizeof(STRU_WIRELESS_MSG_HEADER));

    last_packet_size = sizeof(STRU_FACTORY_SETTING) % (512 - sizeof(STRU_WIRELESS_MSG_HEADER));

    if (last_packet_size)
    {
        packet_num++;
    }
    else
    {
        last_packet_size = 512 - sizeof(STRU_WIRELESS_MSG_HEADER);
    }

    /* call usb send api and report to PC factory tool */
    while (packet_index < packet_num)
    {
        HAL_RET_T ret;
        pst_factoryDataHeader   = (STRU_WIRELESS_MSG_HEADER *)g_reportFactoryDataBuffer;
        pst_factoryData         = g_reportFactoryDataBuffer + sizeof(STRU_WIRELESS_MSG_HEADER);

        pst_factoryDataHeader->magic_header[0] = 0xFF;
        pst_factoryDataHeader->magic_header[1] = 0x5A;
        pst_factoryDataHeader->msg_id   = WIRELESS_INTERFACE_GET_FACTORY_DATA;
        pst_factoryDataHeader->packet_num = packet_num;
        pst_factoryDataHeader->packet_cur = packet_index;

        /* not the last packet */
        if ((packet_index + 1) != packet_num)
        {
            msg_len = 512 - sizeof(STRU_WIRELESS_MSG_HEADER);
        }
        else
        {
            msg_len = last_packet_size;
        }

        pst_factoryDataHeader->msg_len = msg_len;
        pst_factoryDataHeader->chk_sum = 0;

        for (i = 0; i < pst_factoryDataHeader->msg_len; i++)
        {
            pst_factoryData[i] = g_pFactoryDataBuffer[i];

            pst_factoryDataHeader->chk_sum += pst_factoryData[i];
        }

        do
        {
            ret = HAL_USB_SendData(g_reportFactoryDataBuffer, ((msg_len + sizeof(STRU_WIRELESS_MSG_HEADER) + 0x03) & 0xfffffffc) , id, 0x84);
            HAL_Delay(5);
        } while(ret != HAL_OK);

        g_pFactoryDataBuffer += msg_len;

        packet_index++;
    }

    return;
}

static void Wireless_SaveFactoryData(uint8_t usb_id)
{
    uint8_t       msgContent;

    msgContent = (uint8_t)FCT_Save2Flash(&g_factoryDataBuffer);

    Wireless_InsertMsgIntoReplyBuff(WIRELESS_INTERFACE_SET_FACTORY_DATA, 1, 1, 0, &msgContent, usb_id);

    return;
}


static void Wireless_FactoryDataEvent(void *p)
{
    STRU_SysEvent_FACTORY_DATA  *st_factoryDataEvent;

    st_factoryDataEvent = (STRU_SysEvent_FACTORY_DATA *)p;

    if (st_factoryDataEvent->direction == 1)
    {
        Wireless_ReportFactoryData(st_factoryDataEvent->usb_id);
    }
    else
    {
        Wireless_SaveFactoryData(st_factoryDataEvent->usb_id);
    }
}


uint8_t WIRELESS_INTERFACE_SET_FACTORY_DATA_Handler(void *param, uint8_t id)
{
    STRU_WIRELESS_MSG_HEADER            *pst_factoryDataHeader;
    uint8_t                             *pst_factoryData;
    uint16_t                             data_len = 0;
    uint16_t                             check_sum = 0;
    uint16_t                             i = 0;
    STRU_SysEvent_FACTORY_DATA           st_factoryDataEvent;

    pst_factoryDataHeader = (STRU_WIRELESS_MSG_HEADER *)param;
    pst_factoryData       = (uint8_t *)param + sizeof(STRU_WIRELESS_MSG_HEADER);

    data_len    = pst_factoryDataHeader->msg_len;

    if (pst_factoryDataHeader->packet_cur == 0)
    {
        DLOG_Critical("Enter factory mode test");

        g_pFactoryDataBuffer = (uint8_t *)&g_factoryDataBuffer;
    }

    for (i = 0; i < data_len; i++)
    {
        check_sum += pst_factoryData[i];
    }

    if (check_sum != pst_factoryDataHeader->chk_sum)
    {
        DLOG_Critical("checksum is not correct");

        return 1;
    }

    memcpy((void *)g_pFactoryDataBuffer,
           (void *)pst_factoryData,
           data_len);

    g_pFactoryDataBuffer += data_len;

    if ((pst_factoryDataHeader->packet_cur + 1) == pst_factoryDataHeader->packet_num)
    {
        DLOG_Critical("all factory data received");

        st_factoryDataEvent.direction = 0;
        st_factoryDataEvent.usb_id    = id;

        SYS_EVENT_NotifyLocal(SYS_EVENT_ID_FACTORY_DATA, &st_factoryDataEvent);
    }

    return 0;
}


uint8_t WIRELESS_INTERFACE_GET_FACTORY_DATA_Handler(void *param, uint8_t id)
{
    STRU_SysEvent_FACTORY_DATA  st_factoryDataEvent;

    st_factoryDataEvent.direction = 1;
    st_factoryDataEvent.usb_id    = id;

    SYS_EVENT_NotifyLocal(SYS_EVENT_ID_FACTORY_DATA, &st_factoryDataEvent);

    return 0;
}


uint8_t PAD_FREQUENCY_BAND_WIDTH_SELECT_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;
    ENUM_CH_BW              enBandWidth;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    enBandWidth             = msgContent[0];

    HAL_BB_SetFreqBandwidthSelectionProxy(enBandWidth);

    return 0;
}


uint8_t PAD_FREQUENCY_BAND_OPERATION_MODE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetFreqBandSelectionModeProxy((ENUM_RUN_MODE)msgContent[0]);

    return 0;
}


uint8_t PAD_FREQUENCY_BAND_SELECT_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetFreqBandProxy((ENUM_RF_BAND)msgContent[0]);

    return 0;
}


uint8_t PAD_FREQUENCY_CHANNEL_OPERATION_MODE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetItChannelSelectionModeProxy((ENUM_RUN_MODE)msgContent[0]);

    return 0;
}


uint8_t PAD_FREQUENCY_CHANNEL_SELECT_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetItChannelProxy(msgContent[0]);

    return 0;
}


uint8_t PAD_MCS_OPERATION_MODE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetMcsModeProxy((ENUM_RUN_MODE)msgContent[0]);

    return 0;
}


uint8_t PAD_MCS_MODULATION_MODE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetItQamProxy((ENUM_BB_QAM)msgContent[0]);

    return 0;
}


uint8_t PAD_ENCODER_DYNAMIC_BITRATE_MODE_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetEncoderBrcModeProxy((ENUM_RUN_MODE)msgContent[0]);

    return 0;
}


uint8_t PAD_ENCODER_DYNAMIC_BITRATE_SELECT_Handler(void *param, uint8_t id)
{
    uint8_t                *msgContent;

    msgContent              = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    HAL_BB_SetEncoderBitrateProxy(0, msgContent[0]);

    return 0;
}


uint8_t PAD_WIRELESS_OSD_DISPLAY_Handler(void *param, uint8_t id)
{
    // uint8_t                *msgContent;

    // msgContent              = (uint8_t *)param;
    // msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    // g_pstWirelessInfoDisplay  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;

    // if (msgContent[0] == 0)
    // {
    //     DLOG_Info("close osd");

    //     g_pstWirelessInfoDisplay->osd_enable    = 0;
    // }
    // else
    // {
    //     DLOG_Info("open osd");

    //     g_pstWirelessInfoDisplay->osd_enable    = 1;
    // }

    return 0;
}


extern HAL_RET_T NV_DataWrite(uint32_t addr, uint8_t *wdata, uint32_t wlen);
extern HAL_RET_T NV_DataRead(uint32_t addr, uint8_t *rdata, uint32_t rlen);

uint8_t WIRELESS_INTERFACE_SET_PWR_OFFSET_Handler(void *param, uint8_t id)
{
#ifdef AR8020_MP_INFO_RECORD
    uint8_t                 *msgContent;
    uint16_t                u16_msgLen;
    uint16_t                u16_store_len;
    HAL_RET_T               ret;

    msgContent             = (uint8_t *)param;
    u16_msgLen             = msgContent[6] + (msgContent[7] << 8);
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    uint8_t                buf[32] = {0};
    uint16_t               i;
    memset(buf, 0x00, sizeof(buf));
    ret = NV_DataRead(0, buf, 32);     //offset: 32, read: 32 bytre;
    for (i = 0; i < 4; i++)
    {
        if (msgContent[i] == 0xFF)
            msgContent[i] = buf[10 + i];
    }

    STRU_DEVICE_INFO       *pstDeviceInfo;
    pstDeviceInfo           = (STRU_DEVICE_INFO *)DEVICE_INFO_SHM_ADDR;
    int pwr_2G_offset = 0;
    int pwr_5G_offset = 0;
    if (pstDeviceInfo->skyGround == 0x00)       //Sky
    {
        if (msgContent[0] != 0xFF)
            pwr_2G_offset = ((msgContent[0] & 0x80) == 0x80) ? ((msgContent[0] & 0x7F) * (-1)) : (msgContent[0] & 0x7F);

        if (msgContent[2] != 0xFF)
            pwr_5G_offset = ((msgContent[2] & 0x80) == 0x80) ? ((msgContent[2] & 0x7F) * (-1)) : (msgContent[2] & 0x7F);
    }
    else
    {
        if (msgContent[1] != 0xFF)
            pwr_2G_offset = ((msgContent[1] & 0x80) == 0x80) ? ((msgContent[1] & 0x7F) * (-1)) : (msgContent[1] & 0x7F);

        if (msgContent[3] != 0xFF)
            pwr_5G_offset = ((msgContent[3] & 0x80) == 0x80) ? ((msgContent[3] & 0x7F) * (-1)) : (msgContent[3] & 0x7F);
        
    }
/*
    int pwr_2G = BB_get_band_power(RF_2G);
    int pwr_5G = BB_get_band_power(RF_5G);
**/
    int pwr_2G = 0, pwr_5G = 0;

    STRU_RF_POWER_CTRL *pst_powercfg = NULL;
    STRU_cfgNode *cfgnode;
    pst_powercfg = (STRU_RF_POWER_CTRL *)FCT_GetNodeAndData(FACTORY_SUBNODE_POWER_NODE_ID, &cfgnode);
    switch (pst_powercfg->power_work_mode)
    {
        case FCC:
            if (pstDeviceInfo->skyGround == BB_SKY_MODE)   //Sky 0x00
            {
                pwr_5G = pst_powercfg->vtPowerFcc[1];
                pwr_2G = pst_powercfg->vtPowerFcc[0];
            }
            else
            {
                pwr_5G = pst_powercfg->rcPowerFcc[1];
                pwr_2G = pst_powercfg->rcPowerFcc[0];
            }            
            break;
        case CE:
            if (pstDeviceInfo->skyGround == BB_SKY_MODE)   //Sky 0x00
            {
                pwr_5G = pst_powercfg->vtPowerCe[1];
                pwr_2G = pst_powercfg->vtPowerCe[0];
            }
            else
            {
                pwr_5G = pst_powercfg->rcPowerCe[1];
                pwr_2G = pst_powercfg->rcPowerCe[0];
            }
            break;
        case SRRC:
            if (pstDeviceInfo->skyGround == BB_SKY_MODE)
            {
                pwr_5G = pst_powercfg->vtPowerSrrc[1];
                pwr_2G = pst_powercfg->vtPowerSrrc[0];
            }
            else
            {
                pwr_5G = pst_powercfg->rcPowerSrrc[1];
                pwr_2G = pst_powercfg->rcPowerSrrc[0];
            }
            break;
        case OTHER:
            if (pstDeviceInfo->skyGround == BB_SKY_MODE)  //Sky 0x00
            {
                    pwr_5G = pst_powercfg->vtPowerOther[1];
                    pwr_2G = pst_powercfg->vtPowerOther[0];
            }
            else
            {
                    pwr_5G = pst_powercfg->rcPowerOther[1];
                    pwr_2G = pst_powercfg->rcPowerOther[0];
            }
            break;
    } 


    DLOG_Critical("********** pwr_2G_offset: %d, pwr_5G_offset: %d, 2G: %d, 5G: %d ************", pwr_2G_offset, pwr_5G_offset, pwr_2G, pwr_5G);

    pwr_2G += pwr_2G_offset;
    pwr_5G += pwr_5G_offset;
    //pstDeviceInfo->reserved[0]
    
    HAL_BB_SetPower(pwr_2G, pwr_5G);
    
    uint16_t               msgId;
    uint16_t               msgLen = 0;
    uint16_t               chksum = 0;
    uint16_t               tmp_chksum;

    STRU_WIRELESS_MSG_HEADER *msg_header;
    msg_header =  (STRU_WIRELESS_MSG_HEADER *)param;
    msg_header->chk_sum = 0;

    for (i = 0; i < msg_header->msg_len; i++)
    {
        msg_header->chk_sum += msgContent[i];
    }

    ret = NV_DataWrite(0, (uint8_t *)param, u16_msgLen + 10);         //offset: 0

    msgContent[0] = 0x01;

    Wireless_InsertMsgIntoReplyBuff(0x78, 1, 1, 0, msgContent, id);
#endif
    return 0;
}

uint8_t WIRELESS_INTERFACE_GET_PWR_OFFSET_Handler(void *param, uint8_t id)
{
#ifdef AR8020_MP_INFO_RECORD
    uint8_t                *msgContent;

    msgContent             = (uint8_t *)param;
    msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

    uint8_t                buffer[32];
    uint16_t               u16_msgId;
    uint16_t               u16_msgLen = 0;
    uint16_t               u16_chksum;
    uint16_t               calc_chksum;
    uint16_t               i;

    NV_DataRead(0, buffer, 32);     //offset: 32, read: 32 bytre;

    if ((buffer[0] == 0xFF) && (buffer[1] == 0x5A))
    {
        u16_msgId = buffer[2] + (buffer[3] << 8);
        u16_msgLen = buffer[6] + (buffer[7] << 8);
        u16_chksum      = buffer[8] + (buffer[9] << 8);

        calc_chksum = 0;

        for (i = 0; i < u16_msgLen; i++)
        {
            calc_chksum += buffer[10 + i];
        }

        if (calc_chksum != u16_chksum)
        {
            DLOG_Critical("Check sum not correct !!!");
            return 0xFF;
        }

        Wireless_InsertMsgIntoReplyBuff(0x79, u16_msgLen, 1, 0, buffer + 10, id);
    }
#endif

    return 0;
}

uint8_t WIRELESS_INTERFACE_SET_PVT_INFO_Handler(void *param, uint8_t id)
{
#ifdef AR8020_MP_INFO_RECORD
	uint8_t                *msgContent;
	uint16_t				u16_msgLen;
	uint16_t				u16_store_len;
	HAL_RET_T				ret;

	msgContent             = (uint8_t *)param;
	u16_msgLen			   = msgContent[6] + (msgContent[7] << 8);
	msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

	ret = NV_DataWrite(32, (uint8_t *)param, u16_msgLen + 10);	//offset: 32

	msgContent[0] = 0x01;

	Wireless_InsertMsgIntoReplyBuff(0x7A, 1, 1, 0, msgContent, id);
#endif

	return 0;
}

uint8_t WIRELESS_INTERFACE_GET_PVT_INFO_Handler(void *param, uint8_t id)
{
#ifdef AR8020_MP_INFO_RECORD
	uint8_t                *msgContent;

	msgContent             = (uint8_t *)param;
	msgContent             += sizeof(STRU_WIRELESS_MSG_HEADER);

	uint8_t				   buffer[32];
	uint16_t			   u16_msgId;
	uint16_t			   u16_msgLen;
	uint16_t               u16_chksum;
	uint16_t               calc_chksum;
	uint16_t               i;
	
	NV_DataRead(32, buffer, 32);		//offset: 32, read: 32 bytre;

	if ((buffer[0] == 0xFF) && (buffer[1] == 0x5A))
	{
		u16_msgId = buffer[2] + (buffer[3] << 8);
		u16_msgLen = buffer[6] + (buffer[7] << 8);
		u16_chksum      = buffer[8] + (buffer[9] << 8);

		calc_chksum = 0;

		for (i = 0; i < u16_msgLen; i++)
 		{
			calc_chksum += buffer[10 + i];
		}

		if (calc_chksum != u16_chksum)
		{
			DLOG_Critical("Check sum not correct !!!");
			return 0xFF;
		}

		Wireless_InsertMsgIntoReplyBuff(0x7B, u16_msgLen, 1, 0, buffer + 10, id);
	}
#endif

	return 0;
}

void WIRELESS_ParseParamConfig(void *param, uint8_t id)
{
    // uint8_t                                 u8_usbPortId;
    uint8_t                                *u8_msgContent = (uint8_t *)param;
    uint16_t                                u16_msgId;
    uint16_t                                u16_msgLen;
    uint16_t                                u16_chksum;
    // uint8_t                                 u8_packetNum;
    // uint8_t                                 u8_packetCur;
    uint16_t                                i;
    uint16_t                                temp;

    if ((u8_msgContent[0] == 0x44)||(u8_msgContent[0] == 0x45))
    {
        g_stWirelessMsgHandler[u8_msgContent[0]](param, id);

        return;
    }

    if ((u8_msgContent[0] == 0xFF)&&(u8_msgContent[1] == 0x5A))
    {
        u16_msgId       = u8_msgContent[2] + (u8_msgContent[3] << 8);
        // u8_packetNum    = u8_msgContent[4];
        // u8_packetCur    = u8_msgContent[5];
        u16_msgLen      = u8_msgContent[6] + (u8_msgContent[7] << 8);
        u16_chksum      = u8_msgContent[8] + (u8_msgContent[9] << 8);

        temp = 0;

        for (i = 0; i < u16_msgLen; i++)
        {
            temp += u8_msgContent[10 + i];
        }

        if (temp != u16_chksum)
        {
            DLOG_Critical("check sum not correct: %d, %d, %d", temp, u16_chksum, u16_msgLen);

            return;
        }
    }
    else
    {
        return;
    }

    if ((u16_msgId == WIRELESS_INTERFACE_UPGRADE) || (u16_msgId == 0x84) || (u16_msgLen > 54) || (u16_msgId == WIRELESS_INTERFACE_SET_SRAM_SKY_OR_GRD) || (u16_msgId == WIRELESS_INTERFACE_RESET)) // 0x84 : CMD_WRITE_USB_BYPASS
    {
        if (g_stWirelessMsgHandler[u16_msgId])
        {
            (g_stWirelessMsgHandler[u16_msgId])(param, id);
        }
    }
    else
    {
        // insert message to the buffer tail
        memcpy((void *)&g_stWirelessParamConfig.stMsgPool[g_stWirelessParamConfig.u8_buffTail],
               (void *)u8_msgContent,
               64);

        g_stWirelessParamConfig.u8_usbPortId[g_stWirelessParamConfig.u8_buffTail] = id;
        g_stWirelessParamConfig.u8_buffTail++;
        g_stWirelessParamConfig.u8_buffTail &= (WIRELESS_INTERFACE_MAX_MESSAGE_NUM - 1);

        if (g_stWirelessParamConfig.u8_buffTail == g_stWirelessParamConfig.u8_buffHead)
        {
            DLOG_Warning("wireless buff is full");
        }
    }

    return;
}


void Wireless_MessageProcess(void)
{
    uint8_t                                *u8_msgContent;
    uint16_t                                u16_msgId;
    uint8_t                                *u8_sendBuff;
    uint8_t                                 debugMode = 0;
    uint32_t                                u32_sendLength;
    uint8_t                                 u8_usbPortId;

    g_pstWirelessInfoDisplay  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;

    if (((HAL_USB_DeviceGetConnState(0) == HAL_USB_ERR_DEVICE_NOT_CONGIURED)&&
          (HAL_USB_DeviceGetConnState(1) == HAL_USB_ERR_DEVICE_NOT_CONGIURED)))
    {
        return;
    }

    if (g_stWirelessReply.u8_buffTail != g_stWirelessReply.u8_buffHead)
    {
        u8_sendBuff = g_stWirelessReply.stMsgPool[g_stWirelessReply.u8_buffHead];

        u32_sendLength      = 64;

		// uint8_t usb_port_id = g_stWirelessReply.u8_usbPortId[g_stWirelessReply.u8_buffHead];
		// if (HAL_USB_Get_USB_DR_Mode(usb_port_id) == HAL_USB_DR_MODE_HOST)
		// {
		// 	if(g_mtp_enable)
		// 		USBH_MTP_Send(u8_sendBuff, u32_sendLength);
		// }
        // else
        // {
            if (HAL_OK != HAL_USB_DeviceSendCtrl(u8_sendBuff, u32_sendLength, g_stWirelessReply.u8_usbPortId[g_stWirelessReply.u8_buffHead]))
            {
                DLOG_Error("send wireless info fail");
            }
            else
            {
                g_stWirelessReply.u8_buffHead++;
                g_stWirelessReply.u8_buffHead &= (WIRELESS_INTERFACE_MAX_MESSAGE_NUM - 1);
            }
        // }
    }
  

    if (g_stWirelessParamConfig.u8_buffTail != g_stWirelessParamConfig.u8_buffHead)
    {
        // get the head node from the buffer
        u8_msgContent = g_stWirelessParamConfig.stMsgPool[g_stWirelessParamConfig.u8_buffHead];

        u16_msgId       = u8_msgContent[2] + (u8_msgContent[3] << 8);

        if (u16_msgId < MAX_PID_NUM)
        {
            if (g_stWirelessMsgHandler[u16_msgId])
            {
                u8_usbPortId = g_stWirelessParamConfig.u8_usbPortId[g_stWirelessParamConfig.u8_buffHead];

                (g_stWirelessMsgHandler[u16_msgId])((void *)u8_msgContent, u8_usbPortId);
            }
            else
            {
                DLOG_Warning("no this message handler,%d", u16_msgId);
            }
        }

        g_stWirelessParamConfig.u8_buffHead++;
        g_stWirelessParamConfig.u8_buffHead &= (WIRELESS_INTERFACE_MAX_MESSAGE_NUM - 1);
    }

    if (debugMode != (g_pstWirelessInfoDisplay->in_debug))
    {
        debugMode = g_pstWirelessInfoDisplay->in_debug;
        if (1 == debugMode)
        {
            BB_SPI_DisableEnable(debugMode);
        }
    }


    
}

static void Wireless_Task(void const *argument)
{
    DLOG_Info("wireless task entry");

    while (1)
    {
        Wireless_MessageProcess();

        HAL_Delay(2);
    }
}


void Wireless_InitBuffer(void)
{
    memset((void *)&g_stWirelessParamConfig, 0, sizeof(STRU_WIRELESS_MESSAGE_BUFF));
    memset((void *)&g_stWirelessReply, 0, sizeof(STRU_WIRELESS_MESSAGE_BUFF));

    // g_pstWirelessInfoDisplay  = (STRU_WIRELESS_INFO_DISPLAY *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR;
    // g_pstWirelessInfoDisplay->osd_enable = 0;
}

__attribute__((weak)) void ar_osWirelessTaskInit(void TaskHandler(void const *argument))
{
}


void Wireless_TaskInit(uint8_t u8_useRTOS)
{    
    Wireless_InitBuffer();

    memset((void *)SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR, 0, 512);

    HAL_USB_RegisterUserProcess(WIRELESS_ParseParamConfig, Wireless_InitBuffer);

    // SYS_EVENT_RegisterHandler(SYS_EVENT_ID_FACTORY_DATA, Wireless_FactoryDataEvent);
}


static void Wireless_InsertMsgIntoReplyBuff(uint16_t msg_id,
                                         uint16_t msg_len,
                                         uint8_t packet_num,
                                         uint8_t packet_cur,
                                         uint8_t *msg_content,
                                         uint8_t u8_usbPortId)
{
    STRU_WIRELESS_MSG_HEADER      *msg_header;
    uint16_t                       i;
    uint8_t                       *u8_msg;

    msg_header  = (STRU_WIRELESS_MSG_HEADER *)g_stWirelessReply.stMsgPool[g_stWirelessReply.u8_buffTail];
    u8_msg      = g_stWirelessReply.stMsgPool[g_stWirelessReply.u8_buffTail] + sizeof(STRU_WIRELESS_MSG_HEADER);

    msg_header->magic_header[0] = 0xFF;
    msg_header->magic_header[1] = 0x5A;
    msg_header->msg_id          = msg_id;
    msg_header->packet_num      = packet_num;
    msg_header->packet_cur      = packet_cur;
    msg_header->msg_len         = msg_len;
    msg_header->chk_sum         = 0;

    for (i = 0; i < msg_len; i++)
    {
        msg_header->chk_sum += msg_content[i];
        u8_msg[i]            = msg_content[i];
    }

    g_stWirelessReply.u8_usbPortId[g_stWirelessReply.u8_buffTail] = u8_usbPortId;

    g_stWirelessReply.u8_buffTail++;
    g_stWirelessReply.u8_buffTail &= (WIRELESS_INTERFACE_MAX_MESSAGE_NUM - 1);

    if (g_stWirelessReply.u8_buffTail == g_stWirelessReply.u8_buffHead)
    {
        DLOG_Warning("reply buff is full");
        g_stWirelessReply.u8_buffHead = 0;
        g_stWirelessReply.u8_buffTail = 0;
    }

}


void WIRELESS_INTERFACE_RegisterUserHandler(STRU_WIRELESS_USER_HANDLER *user_handler, uint32_t user_handler_num)
{
    uint32_t    i = 0;

    if (user_handler_num > (MAX_PID_NUM - CUSTOMER_MSG_ID_BEGIN))
    {
        DLOG_Error("too many user handler");

        return;
    }

    for (i = 0; i < user_handler_num; i++)
    {
        g_stWirelessMsgHandler[user_handler[i].msg_id] = user_handler[i].handler;
    }
}

uint8_t WIRELESS_INTERFACE_GET_BB_TX_FREEBUF_Handler(void *param, uint8_t id){
	uint8_t 			   *msgContent;
	// STRU_WIRELESS_RESET_DATA_RSV *p;
	msgContent			   = (uint8_t *)param;
	DLOG_Info("get bb_tx_freebuff_len");
	int size =BB_ComGetFreeLength(1); 
	msgContent[0]=size;
	msgContent[1]=size>>8;
	msgContent[2]=size>>16;
	msgContent[3]=size>>24;
	DLOG_Info("size=%d",size);
	Wireless_InsertMsgIntoReplyBuff(WIRELESS_INTERFACE_GET_BB_TX_FREEBUF, 4, 1, 0, msgContent, id);

    return 0;
}

uint8_t WIRELESS_INTERFACE_CLEAR_BB_TX_BUF_Handler(void *param, uint8_t id){
	BB_ComClearTxbuffer(1);
	DLOG_Warning("usb%d get cmd clear bb_tx_buffer",id);

    return 0;
}



