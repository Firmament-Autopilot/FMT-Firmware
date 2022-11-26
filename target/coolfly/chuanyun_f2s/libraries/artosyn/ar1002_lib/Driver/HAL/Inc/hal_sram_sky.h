#ifndef __HAL_SRAM_SKY_H__
#define __HAL_SRAM_SKY_H__

#ifdef __cplusplus
extern "C"
{
#endif


#include <stdint.h>
#include "hal_ret_type.h"


typedef enum
{
    HAL_SRAM_VIDEO_CHANNEL_0    = 0,
    HAL_SRAM_VIDEO_CHANNEL_1    = 1,
    HAL_SRAM_VIDEO_CHANNEL_NUM  = 2,
} ENUM_HAL_SRAM_VIDEO_CHANNEL;



/**
* @brief  Enable Sky Video Bypass Function
* @param  e_sramVideoCh                                     indicate which video channel to use
* @retval   HAL_OK                                               reset buffer success
*               HAL_SRAM_ERR_CHANNEL_INVALID      the input channel number is not correct
* @note  
*/
HAL_RET_T HAL_SRAM_EnableSkyBypassVideo(ENUM_HAL_SRAM_VIDEO_CHANNEL e_sramVideoCh);

/**
* @brief  Disable Sky Video Bypass Function
* @param  e_sramVideoCh                                     indicate which video channel to use
* @retval   HAL_OK                                               reset buffer success
*               HAL_SRAM_ERR_CHANNEL_INVALID      the input channel number is not correct
* @note  
*/
HAL_RET_T HAL_SRAM_DisableSkyBypassVideo(ENUM_HAL_SRAM_VIDEO_CHANNEL e_sramVideoCh);


/**
* @brief  Get Bypass Channel Buffer
* @param  e_sramVideoCh                                     indicate which video channel to use
* @retval   buffer address
* @note  
*/
uint8_t *HAL_SRAM_GetVideoBypassChannelBuff(ENUM_HAL_SRAM_VIDEO_CHANNEL e_channel);


/**
* @brief    Transfer Bypass Data
* @param  e_sramVideoCh           indicate which video channel to use
                   buffer address
                   buffer length
* @retval   void
* @note  
*/
void HAL_SRAM_TransferBypassVideoStream(ENUM_HAL_SRAM_VIDEO_CHANNEL e_channel, void *buff, uint32_t length);


/**
* @brief     Get current remain bandwidth
* @param  e_sramVideoCh           indicate which video channel to use
* @retval   remain bandwidth
* @note  
*/
uint32_t HAL_SRAM_GetBypassBufferLevel(ENUM_HAL_SRAM_VIDEO_CHANNEL e_channel);


/**
* @brief     Bypass IP Camera data
* @param  
* @retval   void
* @note  
*/
void HAL_SRAM_IPCameraPassThrough(void *data, uint32_t size, ENUM_HAL_SRAM_VIDEO_CHANNEL e_channel);


#ifdef __cplusplus
}
#endif


#endif

