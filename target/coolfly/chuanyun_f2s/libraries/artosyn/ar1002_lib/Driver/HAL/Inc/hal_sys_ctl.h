/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_sys_ctl.h
Description: The external HAL APIs to use the I2C controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal_sys_ctl.h
*****************************************************************************/

#ifndef __HAL_SYS_CTL_H__
#define __HAL_SYS_CTL_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "hal_ret_type.h"

typedef struct
{
    uint16_t u16_cpu0cpu1Clk;
    uint16_t u16_cpu2Clk;
    uint8_t  u8_fpuEnable;
    uint8_t  u8_icacheEnable;
    uint8_t  u8_dcacheEnable;
    uint16_t u16_sysTickIntervalUs;
    uint8_t  u8_workMode; /*0: sky mode  1: ground mode*/
} STRU_HAL_SYS_CTL_CONFIG;

/**
* @brief  The CPU clock set function.
* @param  u16_cpu0cpu1Clk               CPU0 and CPU1 clock in MHz.
*         u16_cpu2Clk                   CPU2 clock in MHz.
          u8_workMode                   chip work mode in sky(0) or ground(1), (2): depend on the GPIO to control sky or grd
* @retval HAL_OK                        means the CPU clock initializtion is well done.
*         HAL_SYS_CTL_ERR_SET_CPU_CLK   means some error happens in the CPU clock initializtion.
* @note   This API need be called only once by CPU0.
*/

HAL_RET_T HAL_SYS_CTL_SetCpuClk(uint16_t u16_cpu0cpu1Clk, uint16_t u16_cpu2Clk);

/**
* @brief  The FPU enable function.
* @param  u8_fpuEnable                0 - disable FPU access.
*                                     1 - enable FPU access.
* @retval HAL_OK                      means the FPU is enabled or disabled well.
*         HAL_SYS_CTL_ERR_FPU_ENABLE  means some error happens in the initializtion.
* @note   The default FPU is enabled by HAL_SYS_CTL_Init. 
*/

HAL_RET_T HAL_SYS_CTL_FpuEnable(uint8_t u8_fpuEnable);

/**
* @brief  The system controller configure get function.
* @param  None                
* @retval HAL_OK    means the system controller configure pointer can be used by application.
* @note   The right way to use this function:
*         1. Call the function HAL_SYS_CTL_GetConfig to get the current system controller configuration.
*         2. Change some paramter if you want.
*         3. Call the function HAL_SYS_CTL_Init to do system controller init.
*/

HAL_RET_T HAL_SYS_CTL_GetConfig(STRU_HAL_SYS_CTL_CONFIG **ppst_halSysCtlCfg);

/**
* @brief  The system controller initial function.
* @param  None                
* @retval HAL_OK                means the system controller is initialized well.
*         HAL_SYS_CTL_ERR_INIT  means some error happens in the system controller init.
* @note   This function must be called when the system starts.
*         The right way to use this function:
*         1. Call the function HAL_SYS_CTL_GetConfig to get the current system controller configuration.
*         2. Change some paramter if you want.
*         3. Call the function HAL_SYS_CTL_Init to do system controller init.
*/

HAL_RET_T HAL_SYS_CTL_Init(STRU_HAL_SYS_CTL_CONFIG *pst_halSysCtlCfg);

/**
* @brief  The system tick init function.
* @param  u32_sysTick                System tick count to create tick interrupt.
* @retval HAL_OK                         means the FPU is enabled.
*         HAL_SYS_CTL_ERR_SYS_TICK_INIT  means some error happens in the init period.
* @note   The tick interrupt interval is set to 1ms by HAL_SYS_CTL_Init.
*/

HAL_RET_T HAL_SYS_CTL_SysTickInit(uint32_t u32_sysTickCount);


#ifdef __cplusplus
}
#endif

#endif

