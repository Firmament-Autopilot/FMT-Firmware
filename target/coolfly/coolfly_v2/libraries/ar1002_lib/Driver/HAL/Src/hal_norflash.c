/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_norflash.h
Description: The external HAL APIs to use the nor flash controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2017/03/23
History:
        0.0.1    2017/03/23    The initial version of hal_norflash.h
*****************************************************************************/

#include <stdint.h>
#include "nor_flash.h"
#include "debuglog.h"
#include "hal_ret_type.h"
#include "hal_norflash.h"
#include "driver_mutex.h"
#include "driver_module_init.h"
#include "hal.h"

#include "drv_systick.h"

static uint8_t cpu0_into_upgrade = 0;

HAL_RET_T HAL_NV_enterintoUpgrade(void)
{
	while (-1 == COMMON_driverMutexGet(MUTEX_NOR_FLASH, 0))
	{
		DLOG_Critical("enter into upgrading");
		HAL_Delay(100);
	}

	COMMON_driverMutexSet(MUTEX_NOR_FLASH, 0);

	cpu0_into_upgrade = 1;

    return HAL_OK;
}



HAL_RET_T HAL_NORFLASH_Init(void)
{
    if ( -1 == COMMON_driverMutexGet(MUTEX_NOR_FLASH, 0) )
    {
        DLOG_Critical("fail");
        return HAL_OCCUPIED;
    }

    COMMON_driverMutexSet(MUTEX_NOR_FLASH, 0);
    NOR_FLASH_Init();
    COMMON_driverMutexFree(MUTEX_NOR_FLASH, 0);
    return HAL_OK;
}



HAL_RET_T HAL_NORFLASH_Erase(ENUM_HAL_NORFLASH_EraseIndex e_index, uint32_t u32_startAddr)
{
    if ( -1 == COMMON_driverMutexGet(MUTEX_NOR_FLASH, 0) )
    {
        DLOG_Critical("fail, not inited");
        return HAL_NOT_INITED;
    }

    COMMON_driverMutexSet(MUTEX_NOR_FLASH, 0);

    switch (e_index)
    {
        case 0:
            NOR_FLASH_EraseSector(u32_startAddr);
            break;
        case 1:
            NOR_FLASH_EraseBlock(u32_startAddr);
            break;
        case 2:
            NOR_FLASH_EraseChip();
            break;

        default:
            return HAL_NORFLASH_ERR_ERASE;
            break;
    }

   	if (cpu0_into_upgrade)
   	{
		COMMON_driverMutexFree(MUTEX_NOR_FLASH, 0);
   	}

    return HAL_OK;
}



HAL_RET_T HAL_NORFLASH_WriteByteBuffer(uint32_t u32_startAddr, uint8_t* pu8_dataBuff, uint32_t u32_size)
{
    if ( -1 == COMMON_driverMutexGet(MUTEX_NOR_FLASH, 0) )
    {
        DLOG_Critical("fail, not inited");
        return HAL_NOT_INITED;
    }

    COMMON_driverMutexSet(MUTEX_NOR_FLASH, 0);

    NOR_FLASH_WriteByteBuffer(u32_startAddr, pu8_dataBuff, u32_size);

   	if (cpu0_into_upgrade)
   	{
		COMMON_driverMutexFree(MUTEX_NOR_FLASH, 0);
   	}

    return HAL_OK;
}



HAL_RET_T HAL_NORFLASH_ReadByteBuffer(uint32_t u32_startAddr,uint8_t* pu8_dataBuff, uint32_t u32_size)
{
    if ( -1 == COMMON_driverMutexGet(MUTEX_NOR_FLASH, 0) )
    {
        DLOG_Critical("fail, not inited");
        return HAL_NOT_INITED;
    }
    COMMON_driverMutexSet(MUTEX_NOR_FLASH, 0);

    NOR_FLASH_ReadByteBuffer(u32_startAddr, pu8_dataBuff, u32_size);

   	if (cpu0_into_upgrade)
   	{
		COMMON_driverMutexFree(MUTEX_NOR_FLASH, 0);
   	}

    return HAL_OK;
}



void HAL_NOR_FLASH_SetFlashDisableFlag(uint8_t u8_flag)
{
    NOR_FLASH_SetFlashDisableFlag(u8_flag);
}

uint32_t HAL_NOR_FLASH_ReadStatusReg1(void)
{
    return NOR_FLASH_ReadStatusReg1();
}

uint32_t HAL_NOR_FLASH_ReadStatusReg2(void)
{
    return NOR_FLASH_ReadStatusReg2();
}

void HAL_NOR_FLASH_SetStatusReg1(uint8_t u8_flag)
{
    NOR_FLASH_SetStatusReg1(u8_flag);
}

void HAL_NOR_FLASH_SetStatusReg2(uint8_t u8_flag)
{
    NOR_FLASH_SetStatusReg2(u8_flag);
}

void HAL_NOR_FLASH_ReadFlashID(uint8_t* pu8_data_buf, uint8_t u8_buflen)
{
    NOR_FLASH_ReadJEDECID(pu8_data_buf, u8_buflen);
}

