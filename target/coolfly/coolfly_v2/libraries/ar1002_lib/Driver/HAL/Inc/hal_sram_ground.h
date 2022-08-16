/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_sram.h
Description: The external HAL APIs to use the SRAM.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/21
History: 
        0.0.1    2016/12/21    The initial version of hal_sram.h
*****************************************************************************/

#ifndef __HAL_SRAM_H__
#define __HAL_SRAM_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "hal_ret_type.h"
#include "hal_usb_otg.h"


typedef enum
{
    ENUM_HAL_SRAM_CHANNEL_TYPE_VIDEO0  = 0,
    ENUM_HAL_SRAM_CHANNEL_TYPE_VIDEO1  = 1,
    ENUM_HAL_SRAM_CHANNEL_TYPE_AUDIO   = 2,
    ENUM_HAL_SRAM_CHANNEL_TYPE_RTSP_BYPASS = 2,
} ENUM_HAL_SRAM_CHANNEL_TYPE;


/**
* @brief  Config the Buffer in SRAM to Receive Video Data from SKY.
* @param  void
* @retval   void
* @note  
*/
void HAL_SRAM_ReceiveVideoConfig(void);


void HAL_SRAM_CheckChannelTimeout(void);

/**
* @brief  config the BB channel for video or audio
* @param  void
* @retval   void
* @note  
*/
void HAL_SRAM_ChannelConfig(ENUM_HAL_SRAM_CHANNEL_TYPE e_channelType,
                           uint8_t u8_channel);


void HAL_SRAM_GetReceivedDataSize(uint32_t* p_sram0Size, uint32_t* p_sram1Size);


uint32_t HAL_SRAM_GetMp3BufferLength(void);
uint32_t HAL_SRAM_GetMp3Data(uint32_t dataLen, uint8_t *dataBuff);
void HAL_SRAM_ResetAudioRecv(void);

void HAL_USB_Video_Config_Priority(ENUM_HAL_USB_PORT e_usbPort);

ENUM_HAL_USB_PORT HAL_USB_Get_Video_Priority(void);

#ifdef ARCAST
void HAL_SRAM_Channel_USB_Config(ENUM_HAL_SRAM_CHANNEL_TYPE e_channelType,
                                    ENUM_HAL_USB_PORT e_usbPort,
                                    uint8_t u8_channel);
#endif

#ifdef __cplusplus
}
#endif

#endif


