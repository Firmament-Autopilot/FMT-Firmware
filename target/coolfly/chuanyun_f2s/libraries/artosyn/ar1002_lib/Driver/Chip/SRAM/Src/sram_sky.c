#include <stdint.h>
#include "sram_sky.h"
#include "reg_rw.h"

void SRAM_SKY_EnableBypassVideoConfig(uint32_t channel)
{
    if (0 == channel)
    {
        Reg_Write32(SRAM_VIEW0_ENABLE_ADDR, SRAM_VIEW0_ENABLE);
    }
    else
    {
        Reg_Write32(SRAM_VIEW1_ENABLE_ADDR, SRAM_VIEW1_ENABLE);
    }

    Reg_Write32(SRAM_SKY_MASTER_ID_ADDR, SRAM_SKY_MASTER_ID_VALUE);

    Reg_Write32(SRAM_SKY_MASTER_ID_MASK_ADDR, SRAM_SKY_MASTER_ID_MASK_VALUE);
}


void SRAM_SKY_DisableBypassVideoConfig(uint32_t channel)
{
    uint32_t        regValue;

    if (0 == channel)
    {
        regValue    = Reg_Read32(SRAM_VIEW0_ENABLE_ADDR);
        regValue   &= ~SRAM_VIEW0_ENABLE;

        Reg_Write32(SRAM_VIEW0_ENABLE_ADDR, regValue);
    }
    else
    {
        regValue    = Reg_Read32(SRAM_VIEW1_ENABLE_ADDR);
        regValue   &= ~SRAM_VIEW1_ENABLE;

        Reg_Write32(SRAM_VIEW1_ENABLE_ADDR, regValue);
    }
}




