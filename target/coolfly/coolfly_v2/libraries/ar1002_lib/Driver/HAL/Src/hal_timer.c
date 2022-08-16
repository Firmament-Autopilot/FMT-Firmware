/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_timer.c
Description: this module contains the helper fucntions necessary to control the general
             purpose timer block
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/19
History:
         0.0.1    2016/12/19    The initial version of hal_timer.c
*****************************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "interrupt.h"
#include "hal_ret_type.h"
#include "timer.h"
#include "hal_timer.h"
#include "debuglog.h"
#include "driver_mutex.h"
#include "driver_module_init.h"

void TIMER_ClearNvic(uint32_t e_vectorNum);

/**
* @brief    register timer
* @param    e_timerNum: timer number, the right number should be 0-23.
            u32_timeus: timer load count
            *fun_callBack: interrput callback
* @retval   HAL_OK                 means the registeration tiemr is well done.
*           HAL_TIMER_ERR_UNKNOWN  means the timer number error. 
* @note     none
*/
HAL_RET_T HAL_TIMER_RegisterTimer(ENUM_HAL_TIMER_NUM e_timerNum, uint32_t u32_timeus, void *fun_callBack)
{
    if (e_timerNum > HAL_TIMER_NUM23)
    {
        return HAL_TIMER_ERR_UNKNOWN;
    }

    if ( -1 == COMMON_driverMutexGet(MUTEX_TIMER, e_timerNum) )
    {
        DLOG_Error("fail, channel = %d", e_timerNum);
        return HAL_OCCUPIED;
    }
    COMMON_driverMutexSet(MUTEX_TIMER, (uint32_t)e_timerNum);
    COMMON_driverInitSet(INITED_TIMER, (uint32_t)e_timerNum);

    init_timer_st st_timer;
    memset(&st_timer,0,sizeof(init_timer_st));

    st_timer.base_time_group = e_timerNum/8;
    st_timer.time_num = e_timerNum%8;
    st_timer.ctrl |= TIME_ENABLE | USER_DEFINED;

    TIM_RegisterTimer(st_timer,u32_timeus);
   
    reg_IrqHandle(TIMER_INTR00_VECTOR_NUM + e_timerNum, fun_callBack, TIMER_ClearNvic);
    NVIC_SetPriority(TIMER_INTR00_VECTOR_NUM + e_timerNum, NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_TIMER_DEFAULT,0));
    NVIC_EnableIRQ(TIMER_INTR00_VECTOR_NUM + e_timerNum);
    TIM_StartTimer(st_timer);
    
    return HAL_OK;
}

/**
* @brief    stop timer
* @param    e_timerNum: timer number, the right number should be 0-23.
* @retval   HAL_OK                 means the stop tiemr success.
*           HAL_TIMER_ERR_UNKNOWN  means the timer number error. 
* @note     none
*/
HAL_RET_T HAL_TIMER_Stop(ENUM_HAL_TIMER_NUM e_timerNum)
{
    if (e_timerNum > HAL_TIMER_NUM23)
    {
        return HAL_TIMER_ERR_UNKNOWN;
    }

    if ( -1 == COMMON_driverInitGet(INITED_TIMER, e_timerNum) )
    {
        DLOG_Error("fail, timer = %d", e_timerNum);
        return HAL_NOT_INITED;
    }

    init_timer_st st_timer;
    memset(&st_timer,0,sizeof(init_timer_st));

    st_timer.base_time_group = e_timerNum/8;
    st_timer.time_num = e_timerNum%8;
    st_timer.ctrl |= TIME_ENABLE | USER_DEFINED;

    NVIC_DisableIRQ(TIMER_INTR00_VECTOR_NUM + e_timerNum);

    NVIC_ClearPendingIRQ(TIMER_INTR00_VECTOR_NUM + e_timerNum);

    TIM_StopTimer(st_timer);
    
    return HAL_OK;
}

/**
* @brief    start timer
* @param    e_timerNum: timer number, the right number should be 0-23.
* @retval   HAL_OK                 means the start tiemr success.
*           HAL_TIMER_ERR_UNKNOWN  means the timer number error. 
* @note     none
*/
HAL_RET_T HAL_TIMER_Start(ENUM_HAL_TIMER_NUM e_timerNum)
{
    if (e_timerNum > HAL_TIMER_NUM23)
    {
        return HAL_TIMER_ERR_UNKNOWN;
    }

    if ( -1 == COMMON_driverInitGet(INITED_TIMER, e_timerNum) )
    {
        DLOG_Error("fail, timer = %d", e_timerNum);
        return HAL_NOT_INITED;
    }

    init_timer_st st_timer;
    memset(&st_timer,0,sizeof(init_timer_st));

    st_timer.base_time_group = e_timerNum/8;
    st_timer.time_num = e_timerNum%8;
    st_timer.ctrl |= TIME_ENABLE | USER_DEFINED;

    NVIC_SetPriority(TIMER_INTR00_VECTOR_NUM + e_timerNum, NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_TIMER_DEFAULT,0));
    NVIC_EnableIRQ(TIMER_INTR00_VECTOR_NUM + e_timerNum);
    TIM_StartTimer(st_timer);
    
    return HAL_OK;
}

/**
* @brief    clear timer interrupt
* @param    e_timerNum: timer number, the right number should be 0-23.
* @retval   HAL_OK                 means the clear tiemr interrupt success.
*           HAL_TIMER_ERR_UNKNOWN  means the timer number error. 
* @note     none
*/
void TIMER_ClearNvic(uint32_t e_vectorNum)
{
    if ((e_vectorNum > TIMER_INTR27_VECTOR_NUM) || (e_vectorNum < TIMER_INTR00_VECTOR_NUM) )
    {
        return ;
    }

    uint8_t u8_timerNum = e_vectorNum - TIMER_INTR00_VECTOR_NUM;
    init_timer_st st_timer;
    memset(&st_timer,0,sizeof(init_timer_st));

    st_timer.base_time_group = u8_timerNum/8;
    st_timer.time_num = u8_timerNum%8;
    st_timer.ctrl |= TIME_ENABLE | USER_DEFINED;
    TIM_ClearNvic(st_timer);
}
