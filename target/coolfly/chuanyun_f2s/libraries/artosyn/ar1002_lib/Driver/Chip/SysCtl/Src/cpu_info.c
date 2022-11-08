#include <stdint.h>
#include "ar8020.h" 
#include "cpu_info.h"

ENUM_CPU_ID CPUINFO_GetLocalCpuId(void) 
{
    return *((ENUM_CPU_ID*)CPU_ID_INFO_ADDRESS);
}

void CPUINFO_ICacheEnable(uint8_t u8_icacheEnable)
{
    static uint8_t s_u8_icacheEnable = 0;
    
    if (u8_icacheEnable != 0)
    {
        /* Enable I-Cache */
        SCB_EnableICache();
        s_u8_icacheEnable = 1;
    }
    else
    {
        if (s_u8_icacheEnable != 0)
        {
            /* Disable I-Cache */
            SCB_DisableICache();
            s_u8_icacheEnable = 0;
        }
    }
}

void CPUINFO_DCacheEnable(uint8_t u8_dcacheEnable)
{
    static uint8_t s_u8_dcacheEnable = 0;
    
    if (u8_dcacheEnable != 0)
    {
        /* Enable D-Cache */
        SCB_EnableDCache();
        s_u8_dcacheEnable = 1;
    }
    else
    {
        if (s_u8_dcacheEnable != 0)
        {
            /* Disable D-Cache */
            SCB_DisableDCache();
            s_u8_dcacheEnable = 0;
        }
    }
}

void CPUINFO_ICacheInvalidate(void)
{
    SCB_InvalidateICache();
}

void CPUINFO_DCacheInvalidate(void)
{
    SCB_InvalidateDCache();
}

void CPUINFO_DCacheClean(void)
{
    SCB_CleanDCache();
}

void CPUINFO_DCacheCleanInvalidate(void)
{
    SCB_CleanInvalidateDCache();
}

void CPUINFO_DCacheInvalidateByAddr(uint32_t *addr, int32_t dsize)
{
    SCB_InvalidateDCache_by_Addr(addr, dsize);
}

void CPUINFO_DCacheCleanByAddr(uint32_t *addr, int32_t dsize)
{
    SCB_CleanDCache_by_Addr(addr, dsize);
}

void CPUINFO_DCacheCleanInvalidateByAddr(uint32_t *addr, int32_t dsize)
{
    SCB_CleanInvalidateDCache_by_Addr(addr, dsize);
}

uint32_t peripheralAddrConvert(uint32_t addr)
{
    ENUM_CPU_ID cpu_id = CPUINFO_GetLocalCpuId();

    switch (cpu_id)
    {
        case ENUM_CPU0_ID:
            if((addr >= 0 && addr <= 0x7FFFF) ||                // ITCM
               (addr >= 0x20000000 && addr <= 0x2007FFFF))      // DTCM
            {
                if ((addr >= 0 && addr <= 0x7FFFF))
                {
                    return addr + ITCM_CPU0_DMA_ADDR_OFFSET;
                }
                else if ((addr >= 0x20000000 && addr <= 0x2007FFFF))
                {
                    return addr + DTCM_CPU0_DMA_ADDR_OFFSET;                
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return addr;
            }
        break;

        case ENUM_CPU1_ID:
            if((addr >= 0 && addr <= 0x3FFFF) ||                // ITCM
               (addr >= 0x20000000 && addr <= 0x2003FFFF))      // DTCM
            {
                if((addr >= 0 && addr <= 0x3FFFF))
                {
                    return addr + ITCM_CPU1_DMA_ADDR_OFFSET;
                }
                else if ((addr >= 0x20000000 && addr <= 0x2003FFFF))
                {
                    return addr + DTCM_CPU1_DMA_ADDR_OFFSET;            
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return addr;
            }
        break;

        case ENUM_CPU2_ID:
            if((addr >= 0 && addr <= 0xFFFF) ||                // ITCM
               (addr >= 0x20000000 && addr <= 0x2000FFFF))      // DTCM
            {
                if ((addr >= 0 && addr <= 0xFFFF))
                {
                    return addr + ITCM_CPU2_DMA_ADDR_OFFSET;
                }
                else if ((addr >= 0x20000000 && addr <= 0x2000FFFF))
                {
                    return addr + DTCM_CPU2_DMA_ADDR_OFFSET;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return addr;
            }
        break;

        default:
        break;
    }
    return -1;
}


