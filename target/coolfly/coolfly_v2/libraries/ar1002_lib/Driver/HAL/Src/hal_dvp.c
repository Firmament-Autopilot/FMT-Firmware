/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_dvp.c
Description: The external HAL APIs to use the dvp controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2017/03/06
History: 
        0.0.1    2017/03/06    The initial version of hal_dvp.c
*****************************************************************************/
#include "hal_dvp.h"
#include <stdio.h>
#include "sys_event.h"


typedef struct
{
    uint8_t u8_dvpCh;
    uint8_t u8_dvpToEncoderCh;
    uint16_t u16_dvpWidth;
    uint16_t u16_dvpHight;
    uint8_t u8_dvpFrameRate;
} STRU_DVP_INFO;

static STRU_DVP_INFO s_st_dvpInfo[2] = 
{
    {
        .u8_dvpCh = 0,
        .u8_dvpToEncoderCh = 0,
        .u16_dvpWidth= 1280,
        .u16_dvpHight = 720,
        .u8_dvpFrameRate = 30,
    },

    {
        .u8_dvpCh = 1,
        .u8_dvpToEncoderCh = 1,
        .u16_dvpWidth= 1280,
        .u16_dvpHight = 720,
        .u8_dvpFrameRate = 30,
    }
};



/**
* @brief    
* @param     
* @retval  
* @note    
*/
HAL_RET_T HAL_DVP_Init(uint8_t u8_ch, 
                        uint8_t u8_toEncoderCh, 
                        uint16_t u16_width,
                        uint16_t u16_hight,
                        uint8_t u8_frameRate)


{
    if ((0 == u8_ch) || (1 == u8_ch))
    {
        s_st_dvpInfo[u8_ch].u8_dvpCh = u8_ch;
    }
    else
    {
        return HAL_DVP_ERR;
    }


    if ((0 == u8_toEncoderCh) || (1 == u8_toEncoderCh))
    {
        s_st_dvpInfo[u8_ch].u8_dvpToEncoderCh = u8_toEncoderCh;
    }
    else
    {
        return HAL_DVP_ERR;
    }
    
    s_st_dvpInfo[u8_ch].u8_dvpFrameRate = u8_frameRate;

    s_st_dvpInfo[u8_ch].u16_dvpWidth = u16_width;

    s_st_dvpInfo[u8_ch].u16_dvpHight = u16_hight;
    
    return HAL_OK;
}

/**
* @brief    
* @param     
* @retval  
* @note    
*/
HAL_RET_T HAL_DVP_GetImageInfo(uint8_t u8_ch, uint16_t *u16_width, uint16_t *u16_hight, uint8_t *u8_frameRate)
{
    *u16_width = s_st_dvpInfo[u8_ch].u16_dvpWidth;
    *u16_hight = s_st_dvpInfo[u8_ch].u16_dvpHight;
    *u8_frameRate = s_st_dvpInfo[u8_ch].u8_dvpFrameRate;
    
    return HAL_OK;
}

/**
* @brief    
* @param     
* @retval  
* @note    
*/
HAL_RET_T HAL_DVP_SendInfoToEncoder(uint8_t u8_ch)
{
    STRU_SysEvent_H264InputFormatChangeParameter p;

    p.index = s_st_dvpInfo[u8_ch].u8_dvpToEncoderCh;
    p.width = s_st_dvpInfo[u8_ch].u16_dvpWidth;
    p.hight = s_st_dvpInfo[u8_ch].u16_dvpHight;
    p.framerate = s_st_dvpInfo[u8_ch].u8_dvpFrameRate;
    if (0 == (s_st_dvpInfo[u8_ch].u8_dvpCh))
    {
        p.e_h264InputSrc = ENCODER_INPUT_SRC_DVP_0;
    }
    else
    {
        p.e_h264InputSrc = ENCODER_INPUT_SRC_DVP_1;
    }
    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE, (void*)&p);

    return HAL_OK;
}

