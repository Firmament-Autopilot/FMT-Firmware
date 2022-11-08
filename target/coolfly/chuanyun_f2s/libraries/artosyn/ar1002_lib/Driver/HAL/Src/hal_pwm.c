/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_pwm.c
Description: this module contains the helper fucntions necessary to control the general
             purpose pwm block
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/19
History:
         0.0.1    2016/12/19    The initial version of hal_pwm.c
*****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "interrupt.h"
#include "hal_ret_type.h"
#include "timer.h"
#include "hal_pwm.h"
#include "debuglog.h"
#include "driver_mutex.h"
#include "driver_module_init.h"

static volatile uint32_t    PWM_LOW_US[HAL_PWM_MAX] = {0};
static volatile uint32_t    PWM_HIGH_US[HAL_PWM_MAX] = {0};

static volatile uint32_t    PWM_LOW_US_LAST[HAL_PWM_MAX] = {0};
static volatile uint32_t    PWM_HIGH_US_LAST[HAL_PWM_MAX] = {0};

static volatile uint32_t    PWM_COUNT[HAL_PWM_MAX] = {0};

extern void TIMER_ClearNvic(uint32_t e_vectorNum);

/**
* @brief    register pwm
* @param    e_pwmNum: pwm number, the right number should be 0-127.
            u32_lowus: timer load count of low
            u32_highus: timer load count of high
* @retval   HAL_OK                means the registeration pwm success.
*           HAL_GPIO_ERR_UNKNOWN  means the pwm number error. 
* @note     none
*/
HAL_RET_T HAL_PWM_RegisterPwm(ENUM_HAL_PWM_NUM e_pwmNum, uint32_t u32_lowus, uint32_t u32_highus)
{
    if (e_pwmNum > HAL_PWM_NUM9)
    {
        return HAL_PWM_ERR_UNKNOWN;
    }

    if ( -1 == COMMON_driverMutexGet(MUTEX_TIMER, e_pwmNum) )
    {
        DLOG_Error("fail, timer for pwm channel = %d", e_pwmNum);
        return HAL_OCCUPIED;
    }
    COMMON_driverMutexSet(MUTEX_TIMER, (uint32_t)e_pwmNum);
	COMMON_driverInitSet(INITED_TIMER, (uint32_t)e_pwmNum);

    init_timer_st st_pwm;
    memset(&st_pwm,0,sizeof(init_timer_st));

    st_pwm.base_time_group = e_pwmNum/8;
    st_pwm.time_num = e_pwmNum%8;
    st_pwm.ctrl |= TIME_ENABLE | USER_DEFINED |TIME_PWM_ENABLE;

    TIM_RegisterPwm(st_pwm, u32_lowus, u32_highus);

    return HAL_OK;

}

void LoadTimerValue(uint32_t e_vectorNum)
{
    uint8_t e_pwmNum = e_vectorNum - TIMER_INTR00_VECTOR_NUM;
    init_timer_st st_pwm;    

    if(!(++PWM_COUNT[e_pwmNum] % 2))
    {            
        if (e_pwmNum > HAL_PWM_NUM9)
        {
            return;
        }

        if((PWM_LOW_US_LAST[e_pwmNum] != PWM_LOW_US[e_pwmNum]) || (PWM_HIGH_US_LAST[e_pwmNum] != PWM_HIGH_US[e_pwmNum]))
        {        
            memset(&st_pwm,0,sizeof(init_timer_st));

            st_pwm.base_time_group = e_pwmNum/8;
            st_pwm.time_num = e_pwmNum%8;
            st_pwm.ctrl |= TIME_ENABLE | USER_DEFINED | TIME_PWM_ENABLE;
            
            TIM_ModifyPwmCount(st_pwm,PWM_LOW_US[e_pwmNum],PWM_HIGH_US[e_pwmNum]);
            
            PWM_LOW_US_LAST[e_pwmNum] = PWM_LOW_US[e_pwmNum];
            PWM_HIGH_US_LAST[e_pwmNum] = PWM_HIGH_US[e_pwmNum];
        } 
    }  
}

HAL_RET_T HAL_PWM_RegisterPwmWithIntr(ENUM_HAL_PWM_NUM e_pwmNum, uint32_t u32_lowus, uint32_t u32_highus)
{
    HAL_PWM_RegisterPwm(e_pwmNum, u32_lowus, u32_highus);

    PWM_LOW_US[e_pwmNum] = u32_lowus;
    PWM_HIGH_US[e_pwmNum] = u32_highus;

    PWM_LOW_US_LAST[e_pwmNum] = u32_lowus;
    PWM_HIGH_US_LAST[e_pwmNum] = u32_highus;

    reg_IrqHandle(TIMER_INTR00_VECTOR_NUM + e_pwmNum, LoadTimerValue, TIMER_ClearNvic);
    NVIC_SetPriority(TIMER_INTR00_VECTOR_NUM + e_pwmNum, NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_TIMER_DEFAULT,0));
    NVIC_EnableIRQ(TIMER_INTR00_VECTOR_NUM + e_pwmNum);

    return HAL_OK;

}


/**
* @brief    stop pwm
* @param    e_pwmNum: pwm number, the right number should be 0-127.
* @retval   HAL_OK                means the stop pwm success.
*           HAL_GPIO_ERR_UNKNOWN  means the pwm number error. 
* @note     none
*/
HAL_RET_T HAL_PWM_Stop(ENUM_HAL_PWM_NUM e_pwmNum)
{
    if (e_pwmNum > HAL_PWM_NUM9)
    {
        return HAL_PWM_ERR_UNKNOWN;
    }
	
    if ( -1 == COMMON_driverInitGet(INITED_TIMER, e_pwmNum) )
    {
        DLOG_Error("fail, timer = %d", e_pwmNum);
        return HAL_NOT_INITED;
    }

    init_timer_st st_pwm;
    memset(&st_pwm,0,sizeof(init_timer_st));

    st_pwm.base_time_group = e_pwmNum/8;
    st_pwm.time_num = e_pwmNum%8;
    st_pwm.ctrl |= TIME_ENABLE | USER_DEFINED |TIME_PWM_ENABLE;

    TIM_StopPwm(st_pwm);

    return HAL_OK;
}

/**
* @brief    start pwm
* @param    e_pwmNum: pwm number, the right number should be 0-127.
* @retval   HAL_OK                means the start pwm success.
*           HAL_GPIO_ERR_UNKNOWN  means the pwm number error. 
* @note     none
*/
HAL_RET_T HAL_PWM_Start(ENUM_HAL_PWM_NUM e_pwmNum)
{
    if (e_pwmNum > HAL_PWM_NUM9)
    {
        return HAL_PWM_ERR_UNKNOWN;
    }

    if ( -1 == COMMON_driverInitGet(INITED_TIMER, e_pwmNum) )
    {
        DLOG_Error("fail, timer = %d", e_pwmNum);
        return HAL_NOT_INITED;
    }
	
    init_timer_st st_pwm;
    memset(&st_pwm,0,sizeof(init_timer_st));

    st_pwm.base_time_group = e_pwmNum/8;
    st_pwm.time_num = e_pwmNum%8;
    st_pwm.ctrl |= TIME_ENABLE | USER_DEFINED |TIME_PWM_ENABLE;

    TIM_StartPwm(st_pwm);

    return HAL_OK;
}
/**
* @brief    dynamic modify pwm duty cycle
* @param    e_pwmNum: pwm number, the right number should be 0-127.
            u32_lowus: timer load count of low
            u32_highus: timer load count of high
* @retval   HAL_OK                means the registeration pwm success.
*           HAL_GPIO_ERR_UNKNOWN  means the pwm number error. 
* @note     none
*/
HAL_RET_T HAL_PWM_DynamicModifyPwmDutyCycle(ENUM_HAL_PWM_NUM e_pwmNum, uint32_t u32_lowus, uint32_t u32_highus)
{
   if (e_pwmNum > HAL_PWM_NUM9)
    {
        return HAL_PWM_ERR_UNKNOWN;
    }

    if ( -1 == COMMON_driverInitGet(INITED_TIMER, e_pwmNum) )
    {
        DLOG_Error("fail, timer = %d", e_pwmNum);
        return HAL_NOT_INITED;
    }
	
    init_timer_st st_pwm;
    memset(&st_pwm,0,sizeof(init_timer_st));

    st_pwm.base_time_group = e_pwmNum/8;
    st_pwm.time_num = e_pwmNum%8;
    st_pwm.ctrl |= TIME_ENABLE | USER_DEFINED |TIME_PWM_ENABLE;

    TIM_ModifyPwmCount(st_pwm,u32_lowus,u32_highus);

    return HAL_OK;
}


HAL_RET_T HAL_PWM_DynamicModifyPwmDutyCycleByIntr(ENUM_HAL_PWM_NUM e_pwmNum, uint32_t u32_lowus, uint32_t u32_highus)
{
   if (e_pwmNum > HAL_PWM_NUM9)
    {
        return HAL_PWM_ERR_UNKNOWN;
    }

    if ( -1 == COMMON_driverInitGet(INITED_TIMER, e_pwmNum) )
    {
        DLOG_Error("fail, timer = %d", e_pwmNum);
        return HAL_NOT_INITED;
    }

    PWM_LOW_US[e_pwmNum] = u32_lowus;
    PWM_HIGH_US[e_pwmNum] = u32_highus;

    return HAL_OK;    
}
