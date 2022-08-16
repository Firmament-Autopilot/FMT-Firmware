/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_hdmi_rx.h
Description: The external HAL APIs to use the HDMI RX.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal_hdmi_rx.h
*****************************************************************************/

#ifndef __HAL_HDMI_RX_H__
#define __HAL_HDMI_RX_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "hal_ret_type.h"
#include "hal_gpio.h"

typedef void (*HAL_HDMI_RxHandle)(void *pu8_rxBuf);

typedef struct
{
    uint16_t u16_width;
    uint16_t u16_hight;
    uint8_t  u8_framerate;
    uint8_t  u8_vic;
} STRU_HDMI_RX_OUTPUT_FORMAT;


typedef enum
{
    HAL_HDMI_POLLING = 0,
    HAL_HDMI_INTERRUPT,
} ENUM_HAL_HDMI_GETFORMATMETHOD;

typedef struct
{
    ENUM_HAL_GPIO_NUM e_interruptGpioNum;
    ENUM_HAL_GPIO_InterrputPolarity e_interruptGpioPolarity;
    ENUM_HAL_GPIO_InterrputLevel e_interruptGpioType;
} STRU_HDMI_GPIOCONFIGURE;

typedef enum
{
    HAL_HDMI_RX_16BIT = 0,
    HAL_HDMI_RX_8BIT,
} ENUM_HAL_HDMI_COLOR_DEPTH;


typedef struct
{
    ENUM_HAL_HDMI_GETFORMATMETHOD e_getFormatMethod;
    ENUM_HAL_HDMI_COLOR_DEPTH e_colorDepth;
    STRU_HDMI_GPIOCONFIGURE st_interruptGpio;
    uint8_t u8_hdmiToEncoderCh;
} STRU_HDMI_CONFIGURE;

typedef struct
{
    uint8_t u8_devEnable;
    STRU_HDMI_RX_OUTPUT_FORMAT st_videoFormat;
    STRU_HDMI_CONFIGURE        st_configure;
} STRU_HDMI_RX_STATUS;

typedef enum
{
    HAL_HDMI_RX_0 = 0,
    HAL_HDMI_RX_1,
    HAL_HDMI_RX_MAX
} ENUM_HAL_HDMI_RX;


#define HDMI_RX_FORMAT_NOT_SUPPORT_COUNT_MAX 50

/**
* @brief  The HDMI RX init function.
* @param  e_hdmiIndex       The HDMI RX index number, the right number should be 0-1 and totally
*                           2 HDMI RX can be supported.
* @param  pst_hdmiConfigure hdmiconfigure include polling or interrupr.
* @retval HAL_OK            means the HDMI RX init is well done.
*         HAL_I2C_ERR_INIT  means some error happens in the HDMI RX init.
*         HAL_HDMI_GET_ERR_GORMAT_METHOD means get format method error.
*         HAL_HDMI_INPUT_SOURCE means the nunber of hdmi input error.
* @note   None.
*/

HAL_RET_T HAL_HDMI_RX_Init(ENUM_HAL_HDMI_RX e_hdmiIndex, 
                           STRU_HDMI_CONFIGURE *pst_hdmiConfigure);

HAL_RET_T HAL_HDMI_RX_UnInit(ENUM_HAL_HDMI_RX e_hdmiIndex);

/**
* @brief  The HDMI RX GetVideoFormat function.
* @param  e_hdmiIndex         The HDMI RX index number, the right number should be 0-1 and totally
*                             2 HDMI RX can be supported.
* @param  pu16_width          The pointer to the video width value.
* @param  pu16_hight          The pointer to the video hight value.
* @param  pu8_framterate      The pointer to the video framerate value.
* @retval HAL_OK                            means the HDMI RX init is well done.
*         HAL_HDMI_RX_ERR_GET_VIDEO_FORMAT  means some error happens in the HDMI RX init.
* @note   None.
*/

HAL_RET_T HAL_HDMI_RX_GetVideoFormat(ENUM_HAL_HDMI_RX e_hdmiIndex, 
                                     uint16_t *pu16_width, 
                                     uint16_t *pu16_hight, 
                                     uint8_t  *pu8_framterate);

/**
* @brief  The HDMI RX GetAudioSampleRate function.
* @param  e_hdmiIndex         The HDMI RX index number, the right number should be 0-1 and totally
*                             2 HDMI RX can be supported.
* @param  pu8_sampleRate      The pointer to the audio sample rate.
* @retval HAL_OK                            means the HDMI RX init is well done.
*         HAL_HDMI_RX_ERR_GET_AUDIO_RATE    means some error happens in the HDMI RX audio sample rate.
* @note   None.
*/

HAL_RET_T HAL_HDMI_RX_GetAudioSampleRate(ENUM_HAL_HDMI_RX e_hdmiIndex, uint32_t *pu32_sampleRate);

/**
* @brief  The HDMI RX detect video change callbak.
* @param  pfun_hdmiVideoHandle hdmi Video handle,default notify h264 encoder,fucntion passing arguments 
                               (void *)STRU_SysEvent_H264InputFormatChangeParameter.
* @retval HAL_OK               means the HDMI RX callbak init is well done.
* @note   None.
*/
HAL_RET_T HAL_HDMI_RX_VideoCallbak(HAL_HDMI_RxHandle pfun_hdmiVideoHandle);
HAL_RET_T HAL_HDMI_RX_AudioCallbak(HAL_HDMI_RxHandle pfun_hdmiAudioHandle);
/**
* @brief  The HDMI RX notify h264 encoder.
* @param  pu8_rxBuf            (void *)STRU_SysEvent_H264InputFormatChangeParameter.
* @retval None.
* @note   None.
*/
void HDMI_RxVideoNotifyH264Endcoder(void *pu8_rxBuf);

void IT_66021_reset(void *p);

/**
* @brief  The HDMI RX VideoFormatSupport Check
* @param  u16_width          The pointer to the video width value.
* @param  u16_hight          The pointer to the video hight value.
* @param  u8_framterate      The pointer to the video framerate value.
* @retval HAL_OK: means this VideoFormat Support; HAL_HDMI_RX_FALSE: means this VideoFormat not Support
* @note   Support video format list
            {720,  480,  60},
            {1280, 720,  30},
            {1280, 720,  25},
            {1280, 720,  50},
            {1280, 720,  60},
            {1920, 1080, 25},
            {1920, 1080, 30},
*/
uint32_t HDMI_RX_CheckVideoFormatSupportOrNot(uint16_t u16_width, uint16_t u16_hight, uint8_t u8_framerate);



//  check if the IT66021 is on the board
HAL_RET_T HAL_HDMI_CHECK_CHIP(void);


#ifdef __cplusplus
}
#endif

#endif

