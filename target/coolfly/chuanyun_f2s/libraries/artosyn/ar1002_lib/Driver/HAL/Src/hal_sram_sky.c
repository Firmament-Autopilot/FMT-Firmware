#include <string.h>
#include "hal_sram_sky.h"
#include "sram_sky.h"
#include "debuglog.h"
#include "reg_rw.h"


#define SRAM_BYPASS_ENCODER_MASTER_ADDR     (0xA0010000)  // master


/**
* @brief  Enable Sky Video Bypass Function
* @param  e_sramVideoCh                                     indicate which video channel to use
* @retval   HAL_OK                                               reset buffer success
*               HAL_SRAM_ERR_CHANNEL_INVALID      the input channel number is not correct
* @note  
*/
HAL_RET_T HAL_SRAM_EnableSkyBypassVideo(ENUM_HAL_SRAM_VIDEO_CHANNEL e_sramVideoCh)
{
    if (e_sramVideoCh > HAL_SRAM_VIDEO_CHANNEL_1)
    {
        return HAL_SRAM_ERR_CHANNEL_INVALID;
    }

    SRAM_SKY_EnableBypassVideoConfig(e_sramVideoCh);

    return HAL_OK;
}


/**
* @brief  Disable Sky Video Bypass Function
* @param  e_sramVideoCh                                     indicate which video channel to use
* @retval   HAL_OK                                               reset buffer success
*               HAL_SRAM_ERR_CHANNEL_INVALID      the input channel number is not correct
* @note  
*/
HAL_RET_T HAL_SRAM_DisableSkyBypassVideo(ENUM_HAL_SRAM_VIDEO_CHANNEL e_sramVideoCh)
{
    if (e_sramVideoCh > HAL_SRAM_VIDEO_CHANNEL_1)
    {
        return HAL_SRAM_ERR_CHANNEL_INVALID;
    }

    SRAM_SKY_DisableBypassVideoConfig(e_sramVideoCh);

    return HAL_OK;
}


uint8_t *HAL_SRAM_GetVideoBypassChannelBuff(ENUM_HAL_SRAM_VIDEO_CHANNEL e_channel)
{
    uint8_t          *channel_buff;

    if (e_channel == HAL_SRAM_VIDEO_CHANNEL_0)
    {
        channel_buff = (uint8_t *)VIDEO_BYPASS_CHANNEL_0_DEST_ADDR;
    }
    else
    {
        channel_buff = (uint8_t *)VIDEO_BYPASS_CHANNEL_1_DEST_ADDR;
    }

    return channel_buff;
}


void HAL_SRAM_TransferBypassVideoStream(ENUM_HAL_SRAM_VIDEO_CHANNEL e_channel, void *buff, uint32_t length)
{
    static uint8_t     *bypass_address_raw[HAL_SRAM_VIDEO_CHANNEL_NUM] = {
                                (uint8_t *)VIDEO_BYPASS_CHANNEL_0_DEST_ADDR,
                                (uint8_t *)VIDEO_BYPASS_CHANNEL_1_DEST_ADDR };
    static uint8_t     *bypass_address[HAL_SRAM_VIDEO_CHANNEL_NUM] = {
                                (uint8_t *)VIDEO_BYPASS_CHANNEL_0_DEST_ADDR,
                                (uint8_t *)VIDEO_BYPASS_CHANNEL_1_DEST_ADDR };

    if (e_channel < HAL_SRAM_VIDEO_CHANNEL_NUM)
    {
        memcpy((void *)bypass_address[e_channel],
               (void *)buff,
               length);

        bypass_address[e_channel] += length;

        /* prevent exceed the channel area */
        if (bypass_address[e_channel] >= (bypass_address_raw[e_channel] + 0x600000))
        {
            bypass_address[e_channel] = bypass_address_raw[e_channel];
        }
    }
    else
    {
        DLOG_Error("invalid channel number");
    }

    return;
}


uint32_t HAL_SRAM_GetBypassBufferLevel(ENUM_HAL_SRAM_VIDEO_CHANNEL e_channel)
{
    uint32_t buf_level = 0;

    Reg_Write32_Mask(SRAM_BYPASS_ENCODER_MASTER_ADDR + 0xDC, (unsigned int)(0x21 << 24), 0xFF000000);

    if (e_channel == HAL_SRAM_VIDEO_CHANNEL_0)
    {
        Reg_Write32_Mask(SRAM_BYPASS_ENCODER_MASTER_ADDR + 0xD8, (unsigned int)(0x04 <<  8), 0x00000F00);       // Switch to vdb debug register
    }
    else
    {
        Reg_Write32_Mask(SRAM_BYPASS_ENCODER_MASTER_ADDR + 0xD8, (unsigned int)(0x05 <<  8), 0x00000F00);       // Switch to vdb debug register
    }

    buf_level = Reg_Read32(SRAM_BYPASS_ENCODER_MASTER_ADDR + 0xF8);
    Reg_Write32_Mask(SRAM_BYPASS_ENCODER_MASTER_ADDR + 0xDC, (unsigned int)(0x00 << 24), 0xFF000000);

    return buf_level;
}


void HAL_SRAM_IPCameraPassThrough(void *data, uint32_t size, ENUM_HAL_SRAM_VIDEO_CHANNEL e_channel)
{
    uint32_t                    i = 0;
    uint32_t                    j = 0;
    uint32_t                   *data_buf = (uint32_t *)data;
    uint32_t                    total_size = 0;
    uint32_t                    zero_padding = 0;
    uint32_t                    temp = 0;
    uint32_t                    bytes_align = 0;
    static uint8_t              u8_bandwidthNotEnough = 0;
    uint32_t                    u32_bufferLevel;
    static uint32_t            *bypass_address_raw[HAL_SRAM_VIDEO_CHANNEL_NUM] = {
                                            (uint32_t *)VIDEO_BYPASS_CHANNEL_0_DEST_ADDR,
                                            (uint32_t *)VIDEO_BYPASS_CHANNEL_1_DEST_ADDR };
    static uint32_t            *bypass_address[HAL_SRAM_VIDEO_CHANNEL_NUM] = {
                                            (uint32_t *)VIDEO_BYPASS_CHANNEL_0_DEST_ADDR,
                                            (uint32_t *)VIDEO_BYPASS_CHANNEL_1_DEST_ADDR };

    if (e_channel >= HAL_SRAM_VIDEO_CHANNEL_NUM)
    {
        DLOG_Error("invalid channel number");

        return;
    }

    bytes_align = size;
    bytes_align = (size + 8);

    /* 16 bytes align */
    if (bytes_align & 0xF)
    {
        zero_padding = 16 - (bytes_align & 0xF);
    }

    total_size = (size + zero_padding);


    u32_bufferLevel = HAL_SRAM_GetBypassBufferLevel(1);

    if (u8_bandwidthNotEnough == 1)
    {
        if (u32_bufferLevel == 0)
        {
            u8_bandwidthNotEnough = 0;
        }
        else
        {
            DLOG_Error("bandwidth , %ld, %ld", u32_bufferLevel, total_size);
            return;
        }
    }

    if (u32_bufferLevel > 0x40000)
    {
        DLOG_Error("bandwith not  enough");

        u8_bandwidthNotEnough = 1;

        return;
    }

    temp = 0xFFA55AFF;

    *(bypass_address[e_channel]) = temp;
    (bypass_address[e_channel])++;

    *(bypass_address[e_channel])    = (((total_size & 0xFF00) >> 8)    |
                                       ((total_size & 0xFF) << 8)       |
                                       ((zero_padding & 0xFF00) << 8)   |
                                       ((zero_padding & 0xFF) << 24));

    for (i = 0; i < (size >> 2); i++)
    {
        temp = data_buf[i];

        temp = (((temp & 0xFF) << 24) |
                ((temp & 0xFF00) << 8) |
                ((temp & 0xFF0000) >> 8) |
                ((temp & 0xFF000000) >> 24));

        *(bypass_address[e_channel]) = temp;
        (bypass_address[e_channel])++;
    }

    /* 16 bytes align, padding '0' */
    if (zero_padding)
    {
        if (zero_padding & 0x3)
        {
            temp = data_buf[i];
            temp = (((temp & 0xFF) << 24) |
                    ((temp & 0xFF00) << 8) |
                    ((temp & 0xFF0000) >> 8) |
                    ((temp & 0xFF000000) >> 24));

            for (j = 0; j < (zero_padding & 0x03); j++)
            {
                temp &= (~(0xFF << (j << 3)));
            }

            *(bypass_address[e_channel]) = temp;
            (bypass_address[e_channel])++;

            for (j = 0; j < (zero_padding>>2); j++)
            {
                *(bypass_address[e_channel]) = 0;
                (bypass_address[e_channel])++;
            }
        }
        else
        {
            for (j = 0; j < (zero_padding>>2); j++)
            {
                *(bypass_address[e_channel]) = 0;
                (bypass_address[e_channel])++;
            }
        }
    }

    /* prevent exceed the channel area */
    if (bypass_address[e_channel] >= (bypass_address_raw[e_channel] + 0x60000))
    {
        bypass_address[e_channel] = bypass_address_raw[e_channel];
    }

    return;
}




