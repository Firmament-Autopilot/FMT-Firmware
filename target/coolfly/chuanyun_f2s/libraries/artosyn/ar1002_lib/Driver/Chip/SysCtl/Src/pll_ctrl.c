#include "pll_ctrl.h"
#include "bb_spi.h"
#include "cpu_info.h"
#include "debuglog.h"
#include "memory_config.h"

static uint8_t s_u8_cpuClkInitFlag = 0;

void PLLCTRL_SetCoreClk(uint16_t u16_pllClk, ENUM_CPU_ID e_cpuId)
{
    uint8_t clk_low;
    uint8_t clk_high;

    //DLOG_Info("pll setcoreclk: %dMHz\n", pllclk);

    if(u16_pllClk > 255)
    {
        clk_high    = 1;
        clk_low     = u16_pllClk - 256;
    }
    else
    {
        clk_high    = 0;
        clk_low     = (uint8_t)(u16_pllClk & 0xff);
    }

    SPI_UART_SEL    = 0x03;

    if ((ENUM_CPU0_ID == e_cpuId) || (ENUM_CPU1_ID == e_cpuId))
    {
        BB_SPI_WriteByte(PAGE1, 0xA1, clk_low);
        BB_SPI_WriteByte(PAGE1, 0xA2, clk_high);
        *((uint32_t *)SRAM_MODULE_SHARE_PLL_CPU0CPU1) = u16_pllClk;
        s_u8_cpuClkInitFlag |= 0x1;
    }
    else
    {
        BB_SPI_WriteByte(PAGE1, 0xA4, clk_low);
        BB_SPI_WriteByte(PAGE1, 0xA5, clk_high);
        *((uint32_t *)SRAM_MODULE_SHARE_PLL_CPU2) = u16_pllClk;
        s_u8_cpuClkInitFlag |= 0x2;
    }

    if ((s_u8_cpuClkInitFlag & 0x3) == 0x3)
    {
        *((volatile uint32_t *)SRAM_MODULE_SHARE_PLL_INIT_FLAG) = SRAM_CPU_PLL_INIT_FLAG_VALUE;
    }

    SPI_UART_SEL    = 0x0;
}

void PLLCTRL_GetCoreClk(uint16_t *pu16_pllClk, ENUM_CPU_ID e_cpuId)
{
    switch (e_cpuId)
    {
    case ENUM_CPU0_ID:
        *pu16_pllClk = (uint16_t)(*((volatile uint32_t *)SRAM_MODULE_SHARE_PLL_CPU0CPU1));
        break;
    case ENUM_CPU1_ID:
        *pu16_pllClk = (uint16_t)(*((volatile uint32_t *)SRAM_MODULE_SHARE_PLL_CPU0CPU1));
        break;
    case ENUM_CPU2_ID:
        *pu16_pllClk = (uint16_t)(*((volatile uint32_t *)SRAM_MODULE_SHARE_PLL_CPU2));
        break;
    default:
        break;
    }

    return;
}

uint8_t PLLCTRL_CheckCoreClkReady(void)
{
    if (*((volatile uint32_t *)SRAM_MODULE_SHARE_PLL_INIT_FLAG) == SRAM_CPU_PLL_INIT_FLAG_VALUE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


