/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_sram.c
Description: The external HAL APIs to use the SRAM.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/21
History: 
        0.0.1    2016/12/21    The initial version of hal_sram.c
*****************************************************************************/

#include <stdint.h>
#include "sram_sky.h"
#include "sram_ground.h"
#include "hal_sram_ground.h"
#include "hal_nvic.h"
#include "interrupt.h"
#include "hal_usb_otg.h"
#include "debuglog.h"
#include "usbd_hid.h"
#include "reg_rw.h"

volatile ENUM_HAL_USB_PORT g_usb_priority = HAL_USB_PORT_NUM;

/**
* @brief  Config the Buffer in SRAM to Receive Video Data from SKY.
* @param  void
* @retval   void
* @note  
*/
void HAL_SRAM_ReceiveVideoConfig(void)
{
    SRAM_GROUND_ReceiveVideoConfig();

    /* register the irq handler */
    reg_IrqHandle(BB_SRAM_READY_IRQ_0_VECTOR_NUM, SRAM_Ready0IRQHandler, NULL);
    NVIC_SetPriority(BB_SRAM_READY_IRQ_0_VECTOR_NUM,NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_SRAM0,0));

    /* enable the SRAM_READY_0 IRQ */
    NVIC_EnableIRQ(BB_SRAM_READY_IRQ_0_VECTOR_NUM);

    /* register the irq handler */
    reg_IrqHandle(BB_SRAM_READY_IRQ_1_VECTOR_NUM, SRAM_Ready1IRQHandler, NULL);
    NVIC_SetPriority(BB_SRAM_READY_IRQ_1_VECTOR_NUM,NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_SRAM1,0));

    /* enable the SRAM_READY_1 IRQ */
    NVIC_EnableIRQ(BB_SRAM_READY_IRQ_1_VECTOR_NUM);
}


void HAL_SRAM_CheckChannelTimeout(void)
{
    SRAM_CheckTimeout();
}

void HAL_SRAM_GetReceivedDataSize(uint32_t* p_sram0Size, uint32_t* p_sram1Size)
{
    SRAM_GetReceivedDataSize(p_sram0Size, p_sram1Size);
}


void HAL_SRAM_ChannelConfig(ENUM_HAL_SRAM_CHANNEL_TYPE e_channelType,
                             uint8_t u8_channel)
{
    uint8_t         u8_sramChannel;
    uint8_t         u8_usbEp;
    //uint8_t         u8_usbPort;

    if (u8_channel > SRAM_CHANNEL_NUM)
    {
        DLOG_Error("u8_channel should not exceed 2");

        u8_sramChannel = 0;
    }
    else
    {
        u8_sramChannel = u8_channel;
    }

    //u8_usbPort      = (uint8_t)e_usbPort;

    if (e_channelType == ENUM_HAL_SRAM_CHANNEL_TYPE_VIDEO0)
    {
        u8_usbEp    = HID_EPIN_VIDEO_ADDR;
    }
    else if (e_channelType == ENUM_HAL_SRAM_CHANNEL_TYPE_RTSP_BYPASS)
    {
        g_stChannelPortConfig[u8_sramChannel].u8_rtspEnable = 1;
    }
    else
    {
        /* video & audio use the same endpoint,
                  because BB has only two physical channel,
                  the first is occupied by Video0
                */
        u8_usbEp    = HID_EPIN_AUDIO_ADDR;
    }

    //g_stChannelPortConfig[u8_sramChannel].u8_usbPort = u8_usbPort;
    g_stChannelPortConfig[u8_sramChannel].u8_usbEp = u8_usbEp;

    return;
}


 
void HAL_USB_Video_Config_Priority(ENUM_HAL_USB_PORT e_usbPort)
{
	if (e_usbPort >= HAL_USB_PORT_0 && e_usbPort < HAL_USB_PORT_NUM)
		g_usb_priority = e_usbPort;	
}

ENUM_HAL_USB_PORT HAL_USB_Get_Video_Priority(void)
{
	return g_usb_priority;
}


#ifdef ARCAST
uint32_t HAL_SRAM_GetMp3BufferLength(void)
{
    return SRAM_GetMp3BufferLength();
}


uint32_t HAL_SRAM_GetMp3Data(uint32_t dataLen, uint8_t *dataBuff)
{
    return SRAM_GetMp3Data(dataLen, dataBuff);
}

void HAL_SRAM_ResetAudioRecv(void)
{
    if (sramReady0 == 1)
    {
        SRAM_Ready0Confirm();
    }
}

void HAL_SRAM_Channel_USB_Config(ENUM_HAL_SRAM_CHANNEL_TYPE e_channelType,
                                 ENUM_HAL_USB_PORT e_usbPort,
                                 uint8_t u8_channel)
{
    uint8_t         u8_sramChannel;
    uint8_t         u8_usbEp;
    uint8_t         u8_usbPort;

    if (u8_channel > SRAM_CHANNEL_NUM)
    {
        DLOG_Error("u8_channel should not exceed 2");

        u8_sramChannel = 0;
    }
    else
    {
        u8_sramChannel = u8_channel;
    }

    u8_usbPort      = (uint8_t)e_usbPort;

    if (e_channelType == ENUM_HAL_SRAM_CHANNEL_TYPE_VIDEO0)
    {
        u8_usbEp    = HID_EPIN_VIDEO_ADDR;
    }
    else if (e_channelType == ENUM_HAL_SRAM_CHANNEL_TYPE_RTSP_BYPASS)
    {
        g_stChannelPortConfig[u8_sramChannel].u8_rtspEnable = 1;
    }
    else
    {
        /* video & audio use the same endpoint,
         * because BB has only two physical channel,
         * the first is occupied by Video0
         **/
        u8_usbEp    = HID_EPIN_AUDIO_ADDR;
    }
    DLOG_Critical("usb port is: %d ", u8_usbPort);
    g_stChannelPortConfig[u8_sramChannel].u8_usbPort = u8_usbPort;
    g_stChannelPortConfig[u8_sramChannel].u8_usbEp = u8_usbEp;

    return;
}

#endif



