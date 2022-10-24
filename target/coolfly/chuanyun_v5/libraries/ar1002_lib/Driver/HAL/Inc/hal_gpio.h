/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_gpio.h
Description: this module contains the helper fucntions necessary to control the general
             purpose IO block
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/19
History:
         0.0.1    2016/12/19    The initial version of hal_gpio.h
*****************************************************************************/


#ifndef __HAL_GPIO_H__
#define __HAL_GPIO_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hal_ret_type.h"



typedef enum
{
    HAL_GPIO_PIN_MODE0 = 0, 
    HAL_GPIO_PIN_MODE1,
    HAL_GPIO_PIN_MODE2        
} ENUM_HAL_GPIO_PinMode;


typedef enum
{
    HAL_GPIO_PIN_RESET = 0, //gpio output 0
    HAL_GPIO_PIN_SET        //gpio output 1
} ENUM_HAL_GPIO_PinState;

typedef enum
{
    HAL_GPIO_ACTIVE_LOW = 0, //falling-edge or active-low sensitive
    HAL_GPIO_ACTIVE_HIGH     //rising-edge or active-high sensitive
} ENUM_HAL_GPIO_InterrputPolarity;

typedef enum
{
    HAL_GPIO_LEVEL_SENUMSITIVE = 0,//level-interrupt
    HAL_GPIO_EDGE_SENUMSITIVE      //edge-interrupt
} ENUM_HAL_GPIO_InterrputLevel;

typedef enum
{
    HAL_GPIO_NUM0 = 0,
    HAL_GPIO_NUM1,
    HAL_GPIO_NUM2,
    HAL_GPIO_NUM3,
    HAL_GPIO_NUM4,
    HAL_GPIO_NUM5,
    HAL_GPIO_NUM6,
    HAL_GPIO_NUM7,
    HAL_GPIO_NUM8,
    HAL_GPIO_NUM9,
    HAL_GPIO_NUM10,
    HAL_GPIO_NUM11,
    HAL_GPIO_NUM12,
    HAL_GPIO_NUM13,
    HAL_GPIO_NUM14,
    HAL_GPIO_NUM15,
    HAL_GPIO_NUM16,
    HAL_GPIO_NUM17,
    HAL_GPIO_NUM18,
    HAL_GPIO_NUM19,
    HAL_GPIO_NUM20,
    HAL_GPIO_NUM21,
    HAL_GPIO_NUM22,
    HAL_GPIO_NUM23,
    HAL_GPIO_NUM24,
    HAL_GPIO_NUM25,
    HAL_GPIO_NUM26,
    HAL_GPIO_NUM27,
    HAL_GPIO_NUM28,
    HAL_GPIO_NUM29,
    HAL_GPIO_NUM30,
    HAL_GPIO_NUM31,
    HAL_GPIO_NUM32,
    HAL_GPIO_NUM33,
    HAL_GPIO_NUM34,
    HAL_GPIO_NUM35,
    HAL_GPIO_NUM36,
    HAL_GPIO_NUM37,
    HAL_GPIO_NUM38,
    HAL_GPIO_NUM39,
    HAL_GPIO_NUM40,
    HAL_GPIO_NUM41,
    HAL_GPIO_NUM42,
    HAL_GPIO_NUM43,
    HAL_GPIO_NUM44,
    HAL_GPIO_NUM45,
    HAL_GPIO_NUM46,
    HAL_GPIO_NUM47,
    HAL_GPIO_NUM48,
    HAL_GPIO_NUM49,
    HAL_GPIO_NUM50,
    HAL_GPIO_NUM51,
    HAL_GPIO_NUM52,
    HAL_GPIO_NUM53,
    HAL_GPIO_NUM54,
    HAL_GPIO_NUM55,
    HAL_GPIO_NUM56,
    HAL_GPIO_NUM57,
    HAL_GPIO_NUM58,
    HAL_GPIO_NUM59,
    HAL_GPIO_NUM60,
    HAL_GPIO_NUM61,
    HAL_GPIO_NUM62,
    HAL_GPIO_NUM63,
    HAL_GPIO_NUM64,
    HAL_GPIO_NUM65,
    HAL_GPIO_NUM66,
    HAL_GPIO_NUM67,
    HAL_GPIO_NUM68,
    HAL_GPIO_NUM69,
    HAL_GPIO_NUM70,
    HAL_GPIO_NUM71,
    HAL_GPIO_NUM72,
    HAL_GPIO_NUM73,
    HAL_GPIO_NUM74,
    HAL_GPIO_NUM75,
    HAL_GPIO_NUM76,
    HAL_GPIO_NUM77,
    HAL_GPIO_NUM78,
    HAL_GPIO_NUM79,
    HAL_GPIO_NUM80,
    HAL_GPIO_NUM81,
    HAL_GPIO_NUM82,
    HAL_GPIO_NUM83,
    HAL_GPIO_NUM84,
    HAL_GPIO_NUM85,
    HAL_GPIO_NUM86,
    HAL_GPIO_NUM87,
    HAL_GPIO_NUM88,
    HAL_GPIO_NUM89,
    HAL_GPIO_NUM90,
    HAL_GPIO_NUM91,
    HAL_GPIO_NUM92,
    HAL_GPIO_NUM93,
    HAL_GPIO_NUM94,
    HAL_GPIO_NUM95,
    HAL_GPIO_NUM96,
    HAL_GPIO_NUM97,
    HAL_GPIO_NUM98,
    HAL_GPIO_NUM99,
    HAL_GPIO_NUM100,
    HAL_GPIO_NUM101,
    HAL_GPIO_NUM102,
    HAL_GPIO_NUM103,
    HAL_GPIO_NUM104,
    HAL_GPIO_NUM105,
    HAL_GPIO_NUM106,
    HAL_GPIO_NUM107,
    HAL_GPIO_NUM108,
    HAL_GPIO_NUM109,
    HAL_GPIO_NUM110,
    HAL_GPIO_NUM111,
    HAL_GPIO_NUM112,
    HAL_GPIO_NUM113,
    HAL_GPIO_NUM114,
    HAL_GPIO_NUM115,
    HAL_GPIO_NUM116,
    HAL_GPIO_NUM117,
    HAL_GPIO_NUM118,
    HAL_GPIO_NUM119,
    HAL_GPIO_NUM120,
    HAL_GPIO_NUM121,
    HAL_GPIO_NUM122,
    HAL_GPIO_NUM123,
    HAL_GPIO_NUM124,
    HAL_GPIO_NUM125,
    HAL_GPIO_NUM126,
    HAL_GPIO_NUM127
} ENUM_HAL_GPIO_NUM;

/**
* @brief    set gpio input mode.
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @param    e_gpioMode: The gpio mode, the right number should be 0-2.
* @retval   HAL_OK                means the initializtion mode is well done.
*           HAL_GPIO_ERR_UNKNOWN  means the gpio number error. 
* @note     none
*/
HAL_RET_T HAL_GPIO_SetMode(ENUM_HAL_GPIO_NUM e_gpioPin,ENUM_HAL_GPIO_PinMode e_gpioMode);

/**
* @brief    set gpio output mode.
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @retval   HAL_OK                means the initializtion output mode is well done.
*           HAL_GPIO_ERR_UNKNOWN  means the gpio number error.
* @note     none
*/
HAL_RET_T HAL_GPIO_OutPut(ENUM_HAL_GPIO_NUM e_gpioPin);

/**
* @brief    set gpio input mode
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @retval   HAL_OK             means the initializtion input mode is well done.
*           HAL_GPIO_ERR_INIT  means some error happens in the initializtion. 
* @note     none
*/
HAL_RET_T HAL_GPIO_InPut(ENUM_HAL_GPIO_NUM e_gpioPin);

/**
* @brief    get gpio value
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @param    p_retGpioState: return gpio state
            0                  means the gpio is low
            1                  means the gpio is high
* @retval   HAL_OK                means the set pin state is well done.
*           HAL_GPIO_ERR_UNKNOWN  means the gpio number error. 
* @note     gpio must be seted input mode
*/
HAL_RET_T HAL_GPIO_GetPin(ENUM_HAL_GPIO_NUM e_gpioPin,uint32_t *p_retGpioState);

/**
* @brief    set gpio high or low
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @param    e_pinState:  GPIO_PIN_RESET set gpio low
                         GPIO_PIN_SET set gpio high
* @retval   HAL_OK                means the set pin state is well done.
*           HAL_GPIO_ERR_UNKNOWN  means the gpio number error. 
* @note     gpio must be seted output mode
*/
HAL_RET_T HAL_GPIO_SetPin(ENUM_HAL_GPIO_NUM e_gpioPin, ENUM_HAL_GPIO_PinState e_pinState);

/**
* @brief    set gpio interrupt mode
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
            e_polarity: GPIO_ACTIVE_LOW falling-edge or active-low sensitive
                        GPIO_ACTIVE_HIGH rising-edge or active-high sensitive
            e_inttype： GPIO_LEVEL_SENUMSITIVE is level-interrupt
                        GPIO_EDGE_SENUMSITIVE is edge-interrupt            
* @retval   HAL_OK             means the initializtion interrupt mode is well done.
*           HAL_GPIO_ERR_INIT  means some error happens in the initializtion. 
* @note     this function include set gpio input mode and debounce mode and register corresponding interrupt
*/
HAL_RET_T HAL_GPIO_RegisterInterrupt(ENUM_HAL_GPIO_NUM e_gpioPin, 
                                     ENUM_HAL_GPIO_InterrputLevel e_inttype, 
                                     ENUM_HAL_GPIO_InterrputPolarity e_polarity,
                                     void *fun_callBack);

#ifdef __cplusplus
}
#endif

#endif
