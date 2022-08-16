/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_gpio.c
Description: this module contains the helper fucntions necessary to control the general
             purpose IO block
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/19
History:
         0.0.1    2016/12/19    The initial version of hal_gpio.c
*****************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "debuglog.h"
#include "interrupt.h"
#include "hal_ret_type.h"
#include "gpio.h"
#include "hal_gpio.h"

static void GPIO_VectorFunctionN0(uint32_t u32_vectorNum);
static void GPIO_VectorFunctionN1(uint32_t u32_vectorNum);
static void GPIO_VectorFunctionN2(uint32_t u32_vectorNum);
static void GPIO_VectorFunctionN3(uint32_t u32_vectorNum);
static void GPIO_VectorFunctionNULL(uint32_t u32_vectorNum);

static void (*g_pv_GpioVectorNumArray[4])(uint32_t u32_vectorNum)={ GPIO_VectorFunctionN0,
                                                                    GPIO_VectorFunctionN1,
                                                                    GPIO_VectorFunctionN2,
                                                                    GPIO_VectorFunctionN3};

static void (*g_pv_GpioVectorListArray[4][8])(uint32_t u32_vectorNum);

static void GPIO_ClearNvic(uint32_t u32_vectorNum);


/**
* @brief    set gpio input mode.
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @param    e_gpioMode: The gpio mode, the right number should be 0-2.
* @retval   HAL_OK                means the initializtion mode is well done.
*           HAL_GPIO_ERR_UNKNOWN  means the gpio number error. 
* @note     none
*/
HAL_RET_T HAL_GPIO_SetMode(ENUM_HAL_GPIO_NUM e_gpioPin,ENUM_HAL_GPIO_PinMode e_gpioMode)
{
    if ((e_gpioPin > HAL_GPIO_NUM127) && (e_gpioMode > HAL_GPIO_PIN_MODE2))
    {
        return HAL_GPIO_ERR_UNKNOWN;
    }

    GPIO_SetMode(e_gpioPin, e_gpioMode);
    return HAL_OK;
}

/**
* @brief    set gpio output mode.
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @retval   HAL_OK                means the initializtion output mode is well done.
*           HAL_GPIO_ERR_UNKNOWN  means the gpio number error.
* @note     none
*/
HAL_RET_T HAL_GPIO_OutPut(ENUM_HAL_GPIO_NUM e_gpioPin)
{
    if (e_gpioPin > HAL_GPIO_NUM127)
    {
        return HAL_GPIO_ERR_UNKNOWN;
    }

    GPIO_SetMode(e_gpioPin, GPIO_MODE_2);

    GPIO_SetPinDirect(e_gpioPin, GPIO_DATA_DIRECT_OUTPUT);

    GPIO_SetPinCtrl(e_gpioPin, GPIO_CTRL_SOFTWARE);

    return HAL_OK;
}

/**
* @brief    set gpio input mode.
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @retval   HAL_OK                means the initializtion input mode is well done.
*           HAL_GPIO_ERR_UNKNOWN  means the gpio number error. 
* @note     none
*/
HAL_RET_T HAL_GPIO_InPut(ENUM_HAL_GPIO_NUM e_gpioPin)
{
    if (e_gpioPin > HAL_GPIO_NUM127)
    {
        return HAL_GPIO_ERR_UNKNOWN;
    }

    GPIO_SetMode(e_gpioPin, GPIO_MODE_2);

    GPIO_SetPinDirect(e_gpioPin, GPIO_DATA_DIRECT_INPUT);

    GPIO_SetPinCtrl(e_gpioPin, GPIO_CTRL_SOFTWARE);

    return HAL_OK;
}

/**
* @brief    get gpio value
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @retval   gpio state
            0                  means the gpio is low
            1                  means the gpio is high
            HAL_GPIO_ERR_UNKNOWN  means the gpio number error. 
* @note     gpio must be seted input mode
*/
HAL_RET_T HAL_GPIO_GetPin(ENUM_HAL_GPIO_NUM e_gpioPin,uint32_t *p_retGpioState)
{
    if (e_gpioPin > HAL_GPIO_NUM127)
    {
        return HAL_GPIO_ERR_UNKNOWN;
    }

    *p_retGpioState = GPIO_GetPin(e_gpioPin);

    return HAL_OK;

}

/**
* @brief    set gpio high or low
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @param    e_pinState:  GPIO_PIN_RESET set gpio low
                         GPIO_PIN_SET set gpio high
* @retval   HAL_OK                means the set pin state is well done.
*           HAL_GPIO_ERR_UNKNOWN  means the gpio number error. 
* @note     gpio must be seted output mode
*/
HAL_RET_T HAL_GPIO_SetPin(ENUM_HAL_GPIO_NUM e_gpioPin, ENUM_HAL_GPIO_PinState e_pinState)
{
    if (e_gpioPin > HAL_GPIO_NUM127)
    {
        return HAL_GPIO_ERR_UNKNOWN;
    }

    GPIO_SetPin(e_gpioPin,e_pinState);

    return HAL_OK;
} 

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
                                     void *fun_callBack)
{

    if ((e_gpioPin%32) > 7)
    {
        return HAL_GPIO_ERR_UNKNOWN;
    }
    
    g_pv_GpioVectorListArray[e_gpioPin>>5][(e_gpioPin%32)%8] = fun_callBack;
    reg_IrqHandle(GPIO_INTR_N0_VECTOR_NUM + (e_gpioPin>>5), g_pv_GpioVectorNumArray[e_gpioPin>>5], NULL);    
    
    GPIO_SetPinDirect(e_gpioPin, GPIO_DATA_DIRECT_INPUT);
    
    GPIO_SetPinCtrl(e_gpioPin, GPIO_CTRL_SOFTWARE);
    
    GPIO_SetMode(e_gpioPin, GPIO_MODE_2);
    
    GPIO_Intr_SetPinIntrEn(e_gpioPin, GPIO_INTEN_INTERRUPT);
    
    GPIO_Intr_SetPinIntrMask(e_gpioPin, GPIO_MASK_MASK);
    
    GPIO_Intr_SetPinIntrType(e_gpioPin, e_inttype);
    
    GPIO_Intr_SetPinIntrPol(e_gpioPin, e_polarity);   
    
    NVIC_SetPriority(GPIO_INTR_N0_VECTOR_NUM + (e_gpioPin>>5), NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,INTR_NVIC_PRIORITY_GPIO_DEFAULT,0));
    
    GPIO_Intr_ClearIntr(e_gpioPin);
    
    NVIC_EnableIRQ(GPIO_INTR_N0_VECTOR_NUM + (e_gpioPin>>5));
    
    return HAL_OK;
}

/**
* @brief    clear corresponding interrupt bit
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @retval   HAL_OK                means the initializtion input mode is well done. 
            HAL_GPIO_ERR_UNKNOWN  means the gpio number error.          
* @note     none
*/
static void GPIO_ClearNvic(uint32_t u32_vectorNum)
{
    
    uint32_t i = 0;
    for (i=(u32_vectorNum-66)*32; i<8+(u32_vectorNum-66)*32; i++)
    {
        
        if(GPIO_Intr_GetIntrStatus(i))
        {
            GPIO_Intr_ClearIntr(i);
        }
    }
}

/**
* @brief    clear corresponding interrupt bit
* @param    e_gpioPin: The gpio number, the right number should be 0-127.
* @retval   HAL_OK                means that disbale corresponding interrupt.
            HAL_GPIO_ERR_UNKNOWN  means the gpio number error.  
* @note   none
*/
HAL_RET_T HAL_GPIO_DisableNvic(ENUM_HAL_GPIO_NUM e_gpioPin)
{
    uint8_t i = 0;
    uint8_t u8_flg = 0;

    if ((e_gpioPin%32) > 7)
    {
        return HAL_GPIO_ERR_UNKNOWN;
    }

    g_pv_GpioVectorListArray[e_gpioPin>>5][(e_gpioPin%32)%8] = NULL;

    for (i=0;i<8;i++)
    {
       if ((g_pv_GpioVectorListArray[e_gpioPin>>5][i]) == NULL)
       {
            u8_flg++;
       } 
    }
    if(8 == u8_flg)
    {
        NVIC_DisableIRQ(GPIO_INTR_N0_VECTOR_NUM + (e_gpioPin>>5));
        NVIC_ClearPendingIRQ(GPIO_INTR_N0_VECTOR_NUM + (e_gpioPin>>5));
    }

    return HAL_OK;
}


static void GPIO_VectorFunctionN0(uint32_t u32_vectorNum)
{
    uint8_t i = 0;
    uint8_t u8_intrStattus = GPIO_Intr_GetIntrGroupStatus(u32_vectorNum);
    GPIO_Intr_ClearIntrGroup(u32_vectorNum,u8_intrStattus);
    for (i=0; i<8; i++)
    {
        if((u8_intrStattus & (0x01 << i)))
        {
            if (g_pv_GpioVectorListArray[0][i] != NULL)
            {
                (*(g_pv_GpioVectorListArray[0][i]))(u32_vectorNum);
            }
        }
    }

}

static void GPIO_VectorFunctionN1(uint32_t u32_vectorNum)
{
    uint8_t i = 0;
    uint8_t u8_intrStattus = GPIO_Intr_GetIntrGroupStatus(u32_vectorNum);
    GPIO_Intr_ClearIntrGroup(u32_vectorNum,u8_intrStattus);
    for (i=0; i<8; i++)
    {
        if((u8_intrStattus & (0x01 << i)))
        {
            if (g_pv_GpioVectorListArray[1][i] != NULL)
            {
                (*(g_pv_GpioVectorListArray[1][i]))(u32_vectorNum);
            }
        }
    }
}

static void GPIO_VectorFunctionN2(uint32_t u32_vectorNum)
{
    uint8_t i = 0;
    uint8_t u8_intrStattus = GPIO_Intr_GetIntrGroupStatus(u32_vectorNum);
    GPIO_Intr_ClearIntrGroup(u32_vectorNum,u8_intrStattus);
    for (i=0; i<8; i++)
    {
        if((u8_intrStattus & (0x01 << i)))
        {
            if (g_pv_GpioVectorListArray[2][i] != NULL)
            {
                (*(g_pv_GpioVectorListArray[2][i]))(u32_vectorNum);
            }
        }
    }
}

static void GPIO_VectorFunctionN3(uint32_t u32_vectorNum)
{
   
    uint8_t i = 0;
    uint8_t u8_intrStattus = GPIO_Intr_GetIntrGroupStatus(u32_vectorNum);
    GPIO_Intr_ClearIntrGroup(u32_vectorNum,u8_intrStattus);
    for (i=0; i<8; i++)
    {
        if((u8_intrStattus & (0x01 << i)))
        {
            if (g_pv_GpioVectorListArray[3][i] != NULL)
            {
                (*(g_pv_GpioVectorListArray[3][i]))(u32_vectorNum);
            }
        }
    }
}

static void GPIO_VectorFunctionNULL(uint32_t u32_vectorNum)
{
   return;
}
