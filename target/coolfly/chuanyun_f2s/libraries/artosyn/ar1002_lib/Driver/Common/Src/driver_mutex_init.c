/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: driver_mutex.c
Description: 
Author: Wumin @ Artosy Software Team
Version: 0.0.1
Date: 2017/17/19
History:
         0.0.1    2017/08/02    for driver mutex used
*****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "driver_mutex.h"
#include "debuglog.h"
#include "memory_config.h"
#include "cpu_info.h"

DRIVER_MUTEX_DATA *g_ps_periMutex = (DRIVER_MUTEX_DATA*)(SRAM_PERIPERIAL_MUTEX_ADDR);

void COMMON_driverMutexInit(void)
{
    memset(g_ps_periMutex, 0, sizeof(DRIVER_MUTEX_DATA));
}
