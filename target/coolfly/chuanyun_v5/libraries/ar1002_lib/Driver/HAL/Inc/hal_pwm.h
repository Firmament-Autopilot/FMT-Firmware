/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_pwm.h
Description: this module contains the helper fucntions necessary to control the general
             purpose pwm block
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/19
History:
         0.0.1    2016/12/19    The initial version of hal_pwm.h
*****************************************************************************/

#ifndef __HAL_PWM_H__ 
#define __HAL_PWM_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    HAL_PWM_NUM0=0,
    HAL_PWM_NUM1,
    HAL_PWM_NUM2,
    HAL_PWM_NUM3,
    HAL_PWM_NUM4,
    HAL_PWM_NUM5,
    HAL_PWM_NUM6,
    HAL_PWM_NUM7,
    HAL_PWM_NUM8,
    HAL_PWM_NUM9,
    HAL_PWM_MAX
} ENUM_HAL_PWM_NUM;


/**
* @brief    register pwm
* @param    e_pwmNum: pwm number, the right number should be 0-127.
            u32_lowus: timer load count of low
            u32_highus: timer load count of high
* @retval   HAL_OK                means the registeration pwm success.
*           HAL_GPIO_ERR_UNKNOWN  means the pwm number error. 
* @note     none
*/
HAL_RET_T HAL_PWM_RegisterPwm(ENUM_HAL_PWM_NUM e_pwmNum, uint32_t u32_lowus, uint32_t u32_highus);

/**
* @brief    stop pwm
* @param    e_pwmNum: pwm number, the right number should be 0-127.
* @retval   HAL_OK                means the stop pwm success.
*           HAL_GPIO_ERR_UNKNOWN  means the pwm number error. 
* @note     none
*/
HAL_RET_T HAL_PWM_Stop(ENUM_HAL_PWM_NUM e_pwmNum);

/**
* @brief    start pwm
* @param    e_pwmNum: pwm number, the right number should be 0-127.
* @retval   HAL_OK                means the start pwm success.
*           HAL_GPIO_ERR_UNKNOWN  means the pwm number error. 
* @note     none
*/
HAL_RET_T HAL_PWM_Start(ENUM_HAL_PWM_NUM e_pwmNum);

/**
* @brief    dynamic modify pwm duty cycle
* @param    e_pwmNum: pwm number, the right number should be 0-127.
            u32_lowus: timer load count of low
            u32_highus: timer load count of high
* @retval   HAL_OK                means the registeration pwm success.
*           HAL_GPIO_ERR_UNKNOWN  means the pwm number error. 
* @note     none
*/
HAL_RET_T HAL_PWM_DynamicModifyPwmDutyCycle(ENUM_HAL_PWM_NUM e_pwmNum, uint32_t u32_lowus, uint32_t u32_highus);

HAL_RET_T HAL_PWM_RegisterPwmWithIntr(ENUM_HAL_PWM_NUM e_pwmNum, uint32_t u32_lowus, uint32_t u32_highus);

HAL_RET_T HAL_PWM_DynamicModifyPwmDutyCycleByIntr(ENUM_HAL_PWM_NUM e_pwmNum, uint32_t u32_lowus, uint32_t u32_highus);

#ifdef __cplusplus
}
#endif

#endif
