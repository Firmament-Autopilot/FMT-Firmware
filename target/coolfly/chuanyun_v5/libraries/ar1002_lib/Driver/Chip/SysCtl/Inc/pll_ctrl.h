#ifndef __PLL_CTRL_H
#define __PLL_CTRL_H

#include <stdint.h>
#include "cpu_info.h"

#define CPU0_CPU1_CORE_PLL_CLK       200                                       /* unit: MHz */
#define CPU2_CORE_PLL_CLK            200                                       /* unit: MHz */
#define SPI_UART_SEL                 (*(volatile unsigned int *)0xA003009C)

#define SRAM_CPU_PLL_INIT_FLAG_VALUE 0x20A5A502

void PLLCTRL_SetCoreClk(uint16_t u16_pllClk, ENUM_CPU_ID e_cpuId);
void PLLCTRL_GetCoreClk(uint16_t *pu16_pllClk, ENUM_CPU_ID e_cpuId);
uint8_t PLLCTRL_CheckCoreClkReady(void);

#endif

