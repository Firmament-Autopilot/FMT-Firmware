/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal.c
Description: The external HAL APIs for common driver functions.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal.c
*****************************************************************************/

#include <stdint.h>
#include <string.h>
#include "drv_systick.h"
#include "hal_ret_type.h"
#include "hal.h"
// #include "dma.h"
#include "debuglog.h"
#include "image_struct.h"
#include "quad_spi_ctrl.h"


/**
* @brief  The hal delay function.
* @param  u32_ms    the delay time value in millisecond unit.               
* @retval HAL_OK    means the delay function is well done.
* @note   This function must be called when the system starts.
*/

// HAL_RET_T HAL_Delay(uint32_t u32_ms)
// {
//     HAL_Delay(u32_ms);
// }


/**
* @brief  The hal function to get system tick in millisecond level.
* @param  NONE.
* @retval The current system tick value.
* @note   This function must be called when the system starts.
*/

uint32_t HAL_GetSysMsTick(void)
{
    return SysTicks_GetTickCount();
}

/**
* @brief  The hal function to get system tick in microsecond level.
* @param  NONE.
* @retval The current system tick value.
* @note   This function must be called when the system starts.
*/

uint64_t HAL_GetSysUsTick(void)
{
    return SysTicks_GetUsTickCount();
}


static char HexToASCII(unsigned char  data_hex)
{
    char  ASCII_Data;
    ASCII_Data=data_hex & 0x0F;

    if(ASCII_Data<10)
    {
        ASCII_Data=ASCII_Data+0x30;
    }
    else
    {
        ASCII_Data=ASCII_Data+0x37;    
    }

    return ASCII_Data;
}


/**
* @brief  get app/boot informaton, include date/time/version.
* @param  store buf, least 59 bytes.
* @retval HAL_OK.
* @note   note.
* e.g.  00.00.21 2018.01.17 10:41:38 00.00.11 2017.11.17 10:55:34 
        app version: 00.00.21, app date: 2018.01.17, app time: 10:41:38
        boot version: 00.00.11, boot date: 2017.11.17, boot date: 10:55:34
*/
HAL_RET_T HAL_GetVersion(uint8_t *str)
{
#define SOFT_INFO_LEN       (10)

    uint8_t raw[32];
    uint16_t raw_idx = 0;
    uint16_t str_idx = 0;
    uint16_t i = 0;
#ifdef UPGRADE_DUAL_APP_DESIGN_EN
    STRU_Boot_Info st_bootInfo;
    QUAD_SPI_ReadBlockByByte(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),sizeof(st_bootInfo));
    if ((st_bootInfo.checkSum == (st_bootInfo.success_boot + st_bootInfo.success_app)) && (st_bootInfo.success_app == 0))
    {
        //app 0
    	memcpy(&raw[0], (uint8_t *)(APPLICATION_IMAGE_START0 + 1), 7); // APP
   	memcpy(&raw[7], (uint8_t *)(APPLICATION_IMAGE_START0 + 9), 3);
    }
    else{
    	memcpy(&raw[0], (uint8_t *)(APPLICATION_IMAGE_START1 + 1), 7); // APP
   	memcpy(&raw[7], (uint8_t *)(APPLICATION_IMAGE_START1 + 9), 3);
    }
    memcpy(&raw[SOFT_INFO_LEN +0], (uint8_t *)(0x10008000 + 1), 7); // BOOT
    memcpy(&raw[SOFT_INFO_LEN + 7], (uint8_t *)(0x10008000 + 9), 3);

#else
    memcpy(&raw[0], (uint8_t *)(0x10028000 + 1), 7); // APP
    memcpy(&raw[7], (uint8_t *)(0x10028000 + 9), 3);

    memcpy(&raw[SOFT_INFO_LEN +0], (uint8_t *)(0x10008000 + 1), 7); // BOOT
    memcpy(&raw[SOFT_INFO_LEN + 7], (uint8_t *)(0x10008000 + 9), 3);
#endif
    for(i=0; i<(2*SOFT_INFO_LEN); i += SOFT_INFO_LEN)
    {
        //version
        raw_idx = 7;
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F);
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        raw_idx++;
        str[str_idx++] = '.';
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F);
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        raw_idx++;
        str[str_idx++] = '.';
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F);
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        str[str_idx++] = ' ';

        //date
        raw_idx = 0;
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F); //year
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        raw_idx++;
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F);
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        str[str_idx++] = '.';
        raw_idx++;
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F); //month
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        str[str_idx++] = '.';
        raw_idx++;
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F); //day
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        str[str_idx++] = ' ';
        
        //time
        raw_idx++;
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F);  //hour
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        str[str_idx++] = ':';
        raw_idx++;
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F); //minutes
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        str[str_idx++] = ':';
        raw_idx++;
        str[str_idx++] = HexToASCII((raw[raw_idx+i] >> 4) & 0x0F); //second
        str[str_idx++] = HexToASCII(raw[raw_idx+i] & 0x0F);
        str[str_idx++] = ' ';
    }

    str[str_idx++] = '\0';
    DLOG_Warning("str_idx:%d", str_idx);

    return HAL_OK;
}
