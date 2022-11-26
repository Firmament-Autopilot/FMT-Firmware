/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_timer.h
Description: this module contains the helper fucntions necessary to control the general
             purpose timer block
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/19
History:
         0.0.1    2016/12/19    The initial version of hal_timer.h
*****************************************************************************/


#ifndef __HAL_TIMER_H__
#define __HAL_TIMER_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    HAL_TIMER_NUM0=0,
    HAL_TIMER_NUM1,
    HAL_TIMER_NUM2,
    HAL_TIMER_NUM3,
    HAL_TIMER_NUM4,
    HAL_TIMER_NUM5,
    HAL_TIMER_NUM6,
    HAL_TIMER_NUM7,
    HAL_TIMER_NUM8,
    HAL_TIMER_NUM9,
    HAL_TIMER_NUM10,
    HAL_TIMER_NUM11,
    HAL_TIMER_NUM12,
    HAL_TIMER_NUM13,
    HAL_TIMER_NUM14,
    HAL_TIMER_NUM15,
    HAL_TIMER_NUM16,
    HAL_TIMER_NUM17,
    HAL_TIMER_NUM18,
    HAL_TIMER_NUM19,
    HAL_TIMER_NUM20,
    HAL_TIMER_NUM21,
    HAL_TIMER_NUM22,
    HAL_TIMER_NUM23
} ENUM_HAL_TIMER_NUM;

/**
* @brief    register timer
* @param    e_timerNum: timer number, the right number should be 0-23.
            u32_timeus: timer load count
            *fun_callBack: interrput callback
* @retval   HAL_OK                 means the registeration tiemr is well done.
*           HAL_TIMER_ERR_UNKNOWN  means the timer number error. 
* @note     none
*/
HAL_RET_T HAL_TIMER_RegisterTimer(ENUM_HAL_TIMER_NUM e_timerNum, uint32_t u32_timeus, void *fun_callBack);

/**
* @brief    stop timer
* @param    e_timerNum: timer number, the right number should be 0-23.
* @retval   HAL_OK                 means the stop tiemr success.
*           HAL_TIMER_ERR_UNKNOWN  means the timer number error. 
* @note     none
*/
HAL_RET_T HAL_TIMER_Stop(ENUM_HAL_TIMER_NUM e_timerNum);

/**
* @brief    start timer
* @param    e_timerNum: timer number, the right number should be 0-23.
* @retval   HAL_OK                 means the start tiemr success.
*           HAL_TIMER_ERR_UNKNOWN  means the timer number error. 
* @note     none
*/
HAL_RET_T HAL_TIMER_Start(ENUM_HAL_TIMER_NUM e_timerNum);

#ifdef __cplusplus
}
#endif

#endif
