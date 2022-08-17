#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "efuse.h"
#include "reg_rw.h"
#include "hal.h"
#include "debuglog.h"
#include "mpu.h"

#include "drv_systick.h"

#define EFUSE_EFUSEDATA0              (0x40B000FC)
#define EFUSE_EFUSEDATA1              (0x40B00100)
#define EFUSE_EFUSEDATA2              (0x40B00104) // bit 1   1 mean efuse 


#define EFUSE_EFUSECONTROL            (0x40B00108)
#define EFUSE_EFUSWRITEEBALE          (0x40C00000 + ( 112 )*4) //bit 7 0 write disable  1 write enable

static int8_t EFUSE_GetEfuseCtrstatus(uint8_t u8_statusBit)
{
    return ((Reg_Read32(EFUSE_EFUSECONTROL) >> u8_statusBit) & 0x1);
}

int8_t EFUSE_EfuseInit(uint32_t u32_key0, uint32_t u32_key1)
{
    uint32_t u32_data = 0;
    do
    {
        u32_data = EFUSE_GetEfuseCtrstatus(3);
        DLOG_Critical("Efuse ready %ld",u32_data);
        HAL_Delay(1);
    }while(!u32_data);

    DLOG_Critical("key0 %lx key1 %lx", u32_key0, u32_key1);

    Reg_Write32(EFUSE_EFUSEDATA0, u32_key0);
    Reg_Write32(EFUSE_EFUSEDATA1, u32_key1);
    Reg_Write32(EFUSE_EFUSEDATA2, (1 << 1));
    Reg_Write32(EFUSE_EFUSECONTROL, 0xaaabeef5);
    Reg_Write32(EFUSE_EFUSECONTROL, 0xaaabeef1);

    do
    {
        u32_data = EFUSE_GetEfuseCtrstatus(4);
        DLOG_Critical("wait Efuse%ld", u32_data);
        HAL_Delay(1);
    }while(!u32_data);

    u32_data = EFUSE_GetEfuseCtrstatus(5);
    if (1 == u32_data)
    {
        DLOG_Critical("Efuse success");
    }
    else
    {
        DLOG_Error("Efuse error");
    }
    return u32_data;
}

int32_t EFUSE_GetEfuseEnable(void)
{
    uint32_t u32_data = 0;
    do
    {
        u32_data = EFUSE_GetEfuseCtrstatus(3);
        HAL_Delay(1);
    }while(!u32_data);

    Reg_Write32(EFUSE_EFUSECONTROL, 0xaaabeef6);
    Reg_Write32(EFUSE_EFUSECONTROL, 0xaaabeef2);

    do
    {
        u32_data = EFUSE_GetEfuseCtrstatus(3);
        HAL_Delay(1);
    }while(!u32_data);

    u32_data = *(((uint32_t *) EFUSE_EFUSEDATA2));
    DLOG_Info("efuse data2 value %lx", u32_data);
    return ((u32_data >> 1) & 0x01);
}

void EFUSE_CtrFlashWriteEfuse(uint8_t u8_state)
{
    MPU_QuadspiProtectDisable();
    uint8_t state = Reg_Read32(EFUSE_EFUSWRITEEBALE);
    DLOG_Info("flash write efuse  %x", state);       
   
    if (u8_state)
    {
        state |= 0x80;
    }
    else
    {
        state &= (~0x80);
    }

    Reg_Write32(EFUSE_EFUSWRITEEBALE, state);
    state = Reg_Read32(EFUSE_EFUSWRITEEBALE);
    DLOG_Info("flash write efuse  %x", state); 

    MPU_QuadspiProtectEnable();

}
