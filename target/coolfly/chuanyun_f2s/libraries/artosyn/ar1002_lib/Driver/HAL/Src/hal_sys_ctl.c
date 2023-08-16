/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_sys_ctl.c
Description: The external HAL APIs to set system controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal_sys_ctl.c
*****************************************************************************/

#include <string.h>
#include "fpu.h"
#include "cpu_info.h"
#include "pll_ctrl.h"
#include "bb_spi.h"
#include "inter_core.h"
#include "drv_systick.h"
#include "debuglog.h"
#include "hal_sys_ctl.h"
#include "hal_ret_type.h"
#include "reg_rw.h"
#include "hal_nvic.h"
#include "interrupt.h"
#include "driver_mutex.h"
#include "bb_uart_com.h"
// #include "nosys.h"

#include  "ar1002_hal.h"

static STRU_HAL_SYS_CTL_CONFIG s_st_defHalSysCtlCfg =
{
    .u16_cpu0cpu1Clk       = CPU0_CPU1_CORE_PLL_CLK,
    .u16_cpu2Clk           = CPU2_CORE_PLL_CLK,
    .u8_fpuEnable          = 1,
    .u8_icacheEnable       = 1,
    .u8_dcacheEnable       = 1,
    .u16_sysTickIntervalUs = 1000,
    .u8_workMode           = 2,
};

/**
* @brief  The CPU clock set function.
* @param  u16_cpu0cpu1Clk               CPU0 and CPU1 clock in MHz.
*         u16_cpu2Clk                   CPU2 clock in MHz.
* @retval HAL_OK                        means the CPU clock initializtion is well done.
*         HAL_SYS_CTL_ERR_SET_CPU_CLK   means some error happens in the CPU clock initializtion.
* @note   This API need be called only once by CPU0.
*/

HAL_RET_T HAL_SYS_CTL_SetCpuClk(uint16_t u16_cpu0cpu1Clk, uint16_t u16_cpu2Clk)
{
    if (CPUINFO_GetLocalCpuId() == ENUM_CPU0_ID)
    {
        BB_SPI_init();
        PLLCTRL_SetCoreClk(u16_cpu0cpu1Clk, ENUM_CPU0_ID);
        PLLCTRL_SetCoreClk(u16_cpu2Clk, ENUM_CPU2_ID);
        BB_SPI_DisableEnable(0);
        return HAL_OK;
    }
    else
    {
        return HAL_SYS_CTL_ERR_SET_CPU_CLK;
    }
}

/**
* @brief  The FPU enable function.
* @param  u8_fpuEnable                0 - disable FPU access.
*                                     1 - enable FPU access.
* @retval HAL_OK                      means the FPU is enabled.
*         HAL_SYS_CTL_ERR_FPU_ENABLE  means some error happens in the init period.
* @note   The default FPU is enabled by HAL_SYS_CTL_Init. 
*/

HAL_RET_T HAL_SYS_CTL_FpuEnable(uint8_t u8_fpuEnable)
{
    if (u8_fpuEnable == 1)
    {
        FPU_AccessEnable();
    }
    else if (u8_fpuEnable == 0)
    {
        FPU_AccessDisable();
    }
    
    return HAL_OK;
}

/**
* @brief  The system tick init function.
* @param  u32_sysTick                System tick count to create tick interrupt.
* @retval HAL_OK                         means the FPU is enabled.
*         HAL_SYS_CTL_ERR_SYS_TICK_INIT  means some error happens in the init period.
* @note   The tick interrupt interval is set to 1ms by HAL_SYS_CTL_Init.
*/

HAL_RET_T HAL_SYS_CTL_SysTickInit(uint32_t u32_sysTickCount)
{
    NVIC_SetPriority(HAL_NVIC_SYSTICK_VECTOR_NUM,NVIC_EncodePriority(NVIC_PRIORITYGROUP_5,0x1f,0));
    // SysTicks_Init(u32_sysTickCount);
    
    return HAL_OK;
}

/**
* @brief  The system controller configure get function.
* @param  None                
* @retval HAL_OK    means the system controller configure pointer can be used by application.
* @note   The right way to use this function:
*         1. Call the function HAL_SYS_CTL_GetConfig to get the current system controller configuration.
*         2. Change some paramter if you want.
*         3. Call the function HAL_SYS_CTL_Init to do system controller init.
*/

HAL_RET_T HAL_SYS_CTL_GetConfig(STRU_HAL_SYS_CTL_CONFIG **ppst_halSysCtlCfg)
{
    *ppst_halSysCtlCfg = &s_st_defHalSysCtlCfg;
    
    return HAL_OK;
}



//RESERVE register, hw reset = 0, cpu0 copy all resouce, write to 0x35533553
#define RESERVE_1_OUT_0  (0x40b00048)

static uint8_t PLLCTRL_CheckCpu0ResourceReady(void)
{
    return (*((volatile uint32_t *)RESERVE_1_OUT_0) == 0x35533553);
}


static void PLLCTRL_SetCpu0ResourceReady(void)
{
    *((volatile uint32_t *)RESERVE_1_OUT_0) = 0x35533553;
}


/*
 * when system start, clear the sram resources by cpu0; cpu1,2 will wait until the resouce cleared
*/
void SYS_ClearResouce(void)
{
    COMMON_driverMutexInit();
    BB_ComClearResource();
}

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

HAL_RET_T HAL_SYS_CTL_Init(STRU_HAL_SYS_CTL_CONFIG *pst_usrHalSysCtlCfg)
{
    // uint16_t u16_pllClk = 0;
    // uint32_t u32_tickCnt = 0;

    STRU_HAL_SYS_CTL_CONFIG *pst_halSysCtlCfg = NULL;
    
    if (pst_usrHalSysCtlCfg == NULL)
    {
        pst_halSysCtlCfg = &s_st_defHalSysCtlCfg;
    }
    else
    {
        pst_halSysCtlCfg = pst_usrHalSysCtlCfg;
    }

    if (CPUINFO_GetLocalCpuId() == ENUM_CPU0_ID)
    {
        /*
         * u8_workMode: 1->  ground mode
         *              0->  sky mode 
         */
        Reg_Write32(0x40B00068, (pst_halSysCtlCfg->u8_workMode) ? 0x03 : 0x01);
        if (pst_halSysCtlCfg->u8_workMode == 0)
        {
            /*
             * Leave 2MB SDRAM for CPU access in sky mode
             */
            Reg_Write32(0xA003007C, 0x81C00000); // SDRAM offset for channel 0
            Reg_Write32(0xA0030080, 0x81D00000); // SDRAM offset for channel 1
            Reg_Write32(0xA0030084, 0x00000036); // SDRAM 1MB size for both channel 0 and channel 1
        }

        SYS_ClearResouce();
    }
    else
    {
        //wait unitl cpu0 init ready
        while (0 == PLLCTRL_CheckCpu0ResourceReady());
    }
    
    // Inter core SRAM init
    InterCore_Init();

    HAL_NVIC_SetPriorityGrouping(HAL_NVIC_PRIORITYGROUP_5);
    
    // Default clock: CPU0 and CPU1 200M; CPU2 166M.
    HAL_SYS_CTL_SetCpuClk(pst_halSysCtlCfg->u16_cpu0cpu1Clk, pst_halSysCtlCfg->u16_cpu2Clk);

    //cpu0 copy data to sram finish, now cpu1,cpu2 can run
    if (CPUINFO_GetLocalCpuId() == ENUM_CPU0_ID)
    {
        PLLCTRL_SetCpu0ResourceReady();
    }
    // Wait till the PLL ready
    while (PLLCTRL_CheckCoreClkReady() == 0) {;}

    // Enable FPU access
    HAL_SYS_CTL_FpuEnable(pst_halSysCtlCfg->u8_fpuEnable);


    CPUINFO_ICacheEnable(pst_halSysCtlCfg->u8_icacheEnable);
    // CPUINFO_DCacheEnable(pst_halSysCtlCfg->u8_dcacheEnable);
    CPUINFO_DCacheEnable(0);
    
    return HAL_OK;
}


