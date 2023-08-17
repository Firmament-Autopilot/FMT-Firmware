/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_adc.h
Description: The external HAL APIs to use the I2C controller.
Author: Artosy Software Team
Version: 0.0.1
Date: 2017/1/23
History: 
        0.0.1    2017/1/23    The initial version of hal_adc.h
*****************************************************************************/


#ifndef __AR1002_CHIP_H__
#define __AR1002_CHIP_H__

#ifdef __cplusplus
extern "C"
{
#endif


// #include "dma.h"
#include "quad_spi_ctrl.h"
#include "efuse.h"
#include "i2c_ll.h"
#include "i2c.h"
#include "drv_systick.h"
#include "core_cmInstr.h"
#include "fpu.h"
#include "core_cmFunc.h"
#include "core_cmSimd.h"
#include "pll_ctrl.h"
#include "reg_rw.h"
#include "gpio.h"
#include "timer.h"
#include "interrupt.h"
#include "ar8020.h"
#include "inter_core.h"
#include "cpu_info.h"
#include "core_cm7.h"
#include "mpu.h"
#include "serial.h"
// #include "sram_ground.h"
#include "sram_sky.h"
#include "spi.h"
#include "bb_sky_ctrl.h"
#include "pwr_ctrl.h"
#include "bb_ctrl_internal.h"
#include "bb_ctrl.h"
#include "bb_uart_com.h"
#include "bb_spi.h"
#include "bb_customerctx.h"
#include "bb_types.h"
#include "bb_spi_com.h"
#include "bb_regs.h"


#define UNUSED(X) (void)X      /* To avoid gcc/g++ warnings */



#ifdef __cplusplus
}
#endif

#endif
