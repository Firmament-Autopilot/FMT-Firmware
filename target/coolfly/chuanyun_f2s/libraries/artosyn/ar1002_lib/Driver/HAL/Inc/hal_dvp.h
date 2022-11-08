/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_dvp.h
Description: The external HAL APIs to use the dvp controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2017/03/06
History: 
        0.0.1    2017/03/06    The initial version of hal_dvp.h
*****************************************************************************/
#ifndef __HAL_DVP_H__
#define __HAL_DVP_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "hal_ret_type.h"




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
                        uint8_t u8_frameRate);

/**
* @brief    
* @param     
* @retval  
* @note    
*/
HAL_RET_T HAL_DVP_GetImageInfo(uint8_t u8_ch, uint16_t *u16_width, uint16_t *u16_hight, uint8_t *u8_frameRate);

/**
* @brief    
* @param     
* @retval  
* @note    
*/
HAL_RET_T HAL_DVP_SendInfoToEncoder(uint8_t u8_ch);


#ifdef __cplusplus
}
#endif

#endif
