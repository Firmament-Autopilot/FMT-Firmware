/***************************************************************************/ /**
* \file cy_mipidsi.c
* \version 1.0
*
* Provides an API implementation for Graphics Driver
*
********************************************************************************
* \copyright
* Copyright 2021-2025 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"

#if defined(CY_IP_MXS22GFXSS)

#include "cy_mipidsi.h"
#include "cy_syspm.h"

#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif

#define DSI_CMD_BUF_MAXSIZE (128U)
#define DSI_PWR_UP 0x04
#define CY_MIPIDSI_RESET 0
#define CY_MIPIDSI_POWERUP BIT(0)

#define DSI_CLKMGR_CFG 0x08
#define TO_CLK_DIVISION(div) (((div) & 0xffUL) << 8)
#define TX_ESC_CLK_DIVISION(div) ((div) & 0xffUL)

#define DSI_DPI_VCID 0x0c
#define DPI_VCID(vcid) ((vcid) & 0x3UL)

#define DSI_DPI_COLOR_CODING 0x10
#define LOOSELY18_EN BIT(8)
#define DPI_COLOR_CODING_16BIT_1 0x0
#define DPI_COLOR_CODING_16BIT_2 0x1
#define DPI_COLOR_CODING_16BIT_3 0x2
#define DPI_COLOR_CODING_18BIT_1 0x3
#define DPI_COLOR_CODING_18BIT_2 0x4
#define DPI_COLOR_CODING_24BIT 0x5

#define DSI_DPI_CFG_POL 0x14
#define COLORM_ACTIVE_LOW BIT(4)
#define SHUTD_ACTIVE_LOW BIT(3)
#define HSYNC_ACTIVE_LOW BIT(2)
#define VSYNC_ACTIVE_LOW BIT(1)
#define DATAEN_ACTIVE_LOW BIT(0)

#define DSI_DPI_LP_CMD_TIM 0x18
#define OUTVACT_LPCMD_TIME(p) (((p) & 0xffUL) << 16)
#define INVACT_LPCMD_TIME(p) ((p) & 0xffUL)

#define DSI_DBI_VCID 0x1c
#define DSI_DBI_CFG 0x20
#define DSI_DBI_PARTITIONING_EN 0x24
#define DSI_DBI_CMDSIZE 0x28

#define DSI_PCKHDL_CFG 0x2c
#define CRC_RX_EN BIT(4)
#define ECC_RX_EN BIT(3)
#define BTA_EN BIT(2)
#define EOTP_RX_EN BIT(1)
#define EOTP_TX_EN BIT(0)

#define DSI_GEN_VCID 0x30

#define DSI_MODE_CFG 0x34
#define ENABLE_VIDEO_MODE 0
#define ENABLE_CMD_MODE BIT(0)

#define DSI_VID_MODE_CFG 0x38
#define ENABLE_LOW_POWER_MASK (0x3f << 8)
#define VID_MODE_VPG_ENABLE BIT(16)
#define VID_MODE_VPG_MODE BIT(20)
#define VID_MODE_VPG_HORIZONTAL BIT(24)

#define DSI_VID_PKT_SIZE 0x3c
#define VID_PKT_SIZE(p) ((p) & 0x3fffUL)

#define DSI_VID_NUM_CHUNKS 0x40
#define VID_NUM_CHUNKS(c) ((c) & 0x1fffUL)

#define DSI_VID_NULL_SIZE 0x44
#define VID_NULL_SIZE(b) ((b) & 0x1fffUL)

#define DSI_VID_HSA_TIME 0x48
#define DSI_VID_HBP_TIME 0x4c
#define DSI_VID_HLINE_TIME 0x50
#define DSI_VID_VSA_LINES 0x54
#define DSI_VID_VBP_LINES 0x58
#define DSI_VID_VFP_LINES 0x5c
#define DSI_VID_VACTIVE_LINES 0x60
#define DSI_EDPI_CMD_SIZE 0x64

#define DSI_CMD_MODE_CFG 0x68
#define MAX_RD_PKT_SIZE_LP BIT(24)
#define DCS_LW_TX_LP BIT(19)
#define DCS_SR_0P_TX_LP BIT(18)
#define DCS_SW_1P_TX_LP BIT(17)
#define DCS_SW_0P_TX_LP BIT(16)
#define GEN_LW_TX_LP BIT(14)
#define GEN_SR_2P_TX_LP BIT(13)
#define GEN_SR_1P_TX_LP BIT(12)
#define GEN_SR_0P_TX_LP BIT(11)
#define GEN_SW_2P_TX_LP BIT(10)
#define GEN_SW_1P_TX_LP BIT(9)
#define GEN_SW_0P_TX_LP BIT(8)
#define ACK_RQST_EN BIT(1)
#define TEAR_FX_EN BIT(0)

#define CMD_MODE_ALL_LP                                                                                                \
    (MAX_RD_PKT_SIZE_LP | DCS_LW_TX_LP | DCS_SR_0P_TX_LP | DCS_SW_1P_TX_LP | DCS_SW_0P_TX_LP | GEN_LW_TX_LP |          \
     GEN_SR_2P_TX_LP | GEN_SR_1P_TX_LP | GEN_SR_0P_TX_LP | GEN_SW_2P_TX_LP | GEN_SW_1P_TX_LP | GEN_SW_0P_TX_LP)

#define DSI_GEN_HDR 0x6c
#define DSI_GEN_PLD_DATA 0x70

#define DSI_CMD_PKT_STATUS 0x74
#define GEN_RD_CMD_BUSY BIT(6)
#define GEN_PLD_R_FULL BIT(5)
#define GEN_PLD_R_EMPTY BIT(4)
#define GEN_PLD_W_FULL BIT(3)
#define GEN_PLD_W_EMPTY BIT(2)
#define GEN_CMD_FULL BIT(1)
#define GEN_CMD_EMPTY BIT(0)

#define DSI_TO_CNT_CFG 0x78
#define HSTX_TO_CNT(p) (((p) & 0xffffUL) << 16)
#define LPRX_TO_CNT(p) ((p) & 0xffffUL)

#define DSI_HS_RD_TO_CNT 0x7c
#define DSI_LP_RD_TO_CNT 0x80
#define DSI_HS_WR_TO_CNT 0x84
#define DSI_LP_WR_TO_CNT 0x88
#define DSI_BTA_TO_CNT 0x8c

#define DSI_LPCLK_CTRL 0x94
#define AUTO_CLKLANE_CTRL BIT(1)
#define PHY_TXREQUESTCLKHS BIT(0)

#define DSI_PHY_TMR_LPCLK_CFG 0x98
#define PHY_CLKHS2LP_TIME(lbcc) (((lbcc) & 0x3ffUL) << 16)
#define PHY_CLKLP2HS_TIME(lbcc) ((lbcc) & 0x3ffUL)

#define DSI_PHY_TMR_CFG 0x9c
#define PHY_HS2LP_TIME(lbcc) (((lbcc) & 0xffUL) << 24)
#define PHY_LP2HS_TIME(lbcc) (((lbcc) & 0xffUL) << 16)
#define MAX_RD_TIME(lbcc) ((lbcc) & 0x7fffUL)
#define PHY_HS2LP_TIME_V131(lbcc) (((lbcc) & 0x3ffUL) << 16)
#define PHY_LP2HS_TIME_V131(lbcc) ((lbcc) & 0x3ffUL)

#define DSI_PHY_RSTZ (0xa0)
#define PHY_DISFORCEPLL (0UL)
#define PHY_ENFORCEPLL BIT(3)
#define PHY_DISABLECLK (0UL)
#define PHY_ENABLECLK BIT(2)
#define DPHY_RSTZ (0UL)
#define PHY_UNRSTZ BIT(1)
#define PHY_SHUTDOWNZ (0UL)
#define PHY_UNSHUTDOWNZ BIT(0)

#define DSI_PHY_IF_CFG (0xa4)
#define PHY_STOP_WAIT_TIME(cycle) (((cycle) & 0xffUL) << 8)
#define N_LANES(n) (((n) - 1UL) & 0x3UL)

#define DSI_PHY_ULPS_CTRL 0xa8
#define DSI_PHY_TX_TRIGGERS 0xac

#define DSI_PHY_STATUS 0xb0
#define PHY_STOP_STATE_CLK_LANE BIT(2)
#define PHY_LOCK BIT(0)

#define DSI_PHY_TST_CTRL0 0xb4
#define PHY_TESTCLK BIT(1)
#define PHY_UNTESTCLK 0
#define PHY_TESTCLR BIT(0)
#define PHY_UNTESTCLR 0

#define DSI_PHY_TST_CTRL1 0xb8
#define PHY_TESTEN BIT(16)
#define PHY_UNTESTEN 0
#define PHY_TESTDOUT(n) (((n) & 0xff) << 8)
#define PHY_TESTDIN(n) ((n) & 0xff)

#define DSI_INT_ST0 0xbc
#define DSI_INT_ST1 0xc0
#define DSI_INT_MSK0 0xc4
#define DSI_INT_MSK1 0xc8

#define DSI_PHY_TMR_RD_CFG 0xf4
#define MAX_RD_TIME_V131(lbcc) ((lbcc) & 0x7fff)

#define PHY_STATUS_TIMEOUT_US 10000
#define CMD_PKT_STATUS_TIMEOUT_US 20000
#define MIPI_FIFO_TIMEOUT_IN_MS 250
#define MIPI_DPHY_MAX_RETRIES 100U
#define MIPI_DPHY_STATUS_DATA_LINES 0x120UL
#define MIPI_DPHY_STATUS_DATA_LINE0 0x20UL
#define dphy2txtester_DIG_RDWR_TX_LANE1_SLEWRATE_0 0x70b

/* Time to wait for DPHY lock, as per MIPI D-PHY Specifications max time is 180 microseconds,
 * Timeout checks every 10us if register status lock is updated */
#define DPHY_LOCK_TIMEOUT_US 10U
#define ULPM_TRANSITION_DELAY_MS 1U /* Required delay for ULPM transitions, as per MIPI D-PHY Specifications */

/*******************************************************************************
 * PLL Configuration Lookup Table
 *******************************************************************************/

typedef struct
{
    uint16_t bandwidth_mbps; /* Target bandwidth in Mbps */
    uint8_t n_factor;        /* Input division ratio (reg 0x178) */
    uint8_t m_factor;        /* Feedback multiplication (reg 0x179) */
    uint8_t m_carry;         /* M factor carry-forward (reg 0x17A), 0 if not needed */
    uint8_t hsfreqrange;     /* HS frequency range (reg 0x2) */
    uint8_t vco_control;     /* VCO control + override enables (reg 0x17B) */
} cy_stc_dphy_pll_config_t;

/*
 * PLL Configuration Table
 * Entries are ordered by increasing bandwidth for efficient lookup
 */
static const cy_stc_dphy_pll_config_t dphy_pll_config_table[] = {
    /* Bandwidth  N     M     M_Carry  HSFreqRange  VCO_Ctrl  Comments */
    {100U, 0x90, 0x30, 0x00, 0x20, 0xFC},  /* 100 Mbps  - VCO=0x3E */
    {150U, 0x90, 0x49, 0x00, 0x31, 0xF1},  /* 150 Mbps  - VCO=0x38 */
    {200U, 0xAB, 0x62, 0x00, 0x03, 0xDD},  /* 200 Mbps  - VCO=0x2E */
    {250U, 0xA8, 0x7B, 0x00, 0x33, 0xD1},  /* 250 Mbps  - VCO=0x28 */
    {300U, 0xAB, 0x94, 0x00, 0x14, 0xD1},  /* 300 Mbps  - VCO=0x28 */
    {350U, 0xD8, 0xAD, 0x00, 0x35, 0xBD},  /* 350 Mbps  - VCO=0x1E */
    {400U, 0xD8, 0xC6, 0x00, 0x05, 0xBD},  /* 400 Mbps  - VCO=0x1E */
    {450U, 0xD8, 0xDF, 0x00, 0x16, 0xBD},  /* 450 Mbps  - VCO=0x1E, last config needing clkdiv_clk_en */
    {500U, 0xD8, 0xF8, 0x00, 0x26, 0xB1},  /* 500 Mbps  - VCO=0x18 */
    {550U, 0xD8, 0x11, 0x01, 0x37, 0xBD},  /* 550 Mbps  - VCO=0x1E, M=0x111 (requires carry) */
    {600U, 0xD8, 0x2A, 0x01, 0x07, 0xBD},  /* 600 Mbps  - VCO=0x1E, M=0x12A, also used for 650 */
    {650U, 0xD8, 0x2A, 0x01, 0x07, 0xBD},  /* 650 Mbps  - Same config as 600 */
    {700U, 0xD8, 0xAD, 0x00, 0x28, 0x9D},  /* 700 Mbps  - VCO=0x0E */
    {750U, 0xB8, 0x7B, 0x00, 0x39, 0x9D},  /* 750 Mbps  - VCO=0x0E */
    {800U, 0xD8, 0xC6, 0x00, 0x09, 0x9D},  /* 800 Mbps  - VCO=0x0E, also used for 850 */
    {850U, 0xD8, 0xC6, 0x00, 0x09, 0x9D},  /* 850 Mbps  - Same config as 800 */
    {900U, 0xD8, 0x11, 0x01, 0x29, 0x91},  /* 900 Mbps  - VCO=0x08, M=0x111, also used for 950 */
    {950U, 0xD8, 0x11, 0x01, 0x29, 0x91},  /* 950 Mbps  - Same config as 900 */
    {1000U, 0xD8, 0xF8, 0x00, 0x0A, 0x91}, /* 1.0 Gbps  - VCO=0x08 */
    {1050U, 0xB8, 0xAD, 0x00, 0x1A, 0x91}, /* 1.05 Gbps - VCO=0x08 */
    {1100U, 0xD8, 0x11, 0x01, 0x2A, 0x91}, /* 1.1 Gbps  - VCO=0x08, M=0x111, also used for 1150 */
    {1150U, 0xD8, 0x11, 0x01, 0x2A, 0x91}, /* 1.15 Gbps - Same config as 1100 */
    {1200U, 0xD8, 0x2A, 0x01, 0x0B, 0x91}, /* 1.2 Gbps  - VCO=0x08, M=0x12A, also used for 1250 */
    {1250U, 0xD8, 0x2A, 0x01, 0x0B, 0x91}, /* 1.25 Gbps - Same config as 1200 */
    {1300U, 0xD8, 0x43, 0x01, 0x2B, 0x87}, /* 1.3 Gbps  - VCO=0x03, M=0x143 */
    {1350U, 0xB8, 0xDF, 0x00, 0x3C, 0x87}, /* 1.35 Gbps - VCO=0x03 */
    {1400U, 0xD8, 0x5C, 0x01, 0x0C, 0x87}, /* 1.4 Gbps  - VCO=0x03, M=0x15C, also used for 1450 */
    {1450U, 0xD8, 0x5C, 0x01, 0x0C, 0x87}, /* 1.45 Gbps - Same config as 1400 */
    {1500U, 0xD8, 0x75, 0x01, 0x2C, 0x87}, /* 1.5 Gbps  - VCO=0x03, M=0x175, default/max config */
};

#define DPHY_PLL_CONFIG_TABLE_SIZE (sizeof(dphy_pll_config_table) / sizeof(cy_stc_dphy_pll_config_t))

/*******************************************************************************
 *                             Function Prototypes
 *******************************************************************************/
static void cy_mipi_dsi_pll_reprogramming(cy_stc_mipidsi_config_t const *config);
static void cy_mipi_dsi_dphy_reg_write(uint16_t address, uint8_t data);
static uint8_t cy_mipi_dsi_dphy_reg_read(uint16_t address);

static void cy_mipi_dsi_dphy_reg_write(uint16_t address, uint8_t data)
{
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL1,
                 PHY_TESTEN | 0x00UL); // need to set msb of address in register 0x00
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_TESTCLK);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_UNTESTCLR);

    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL1, ((uint32_t)address >> 8UL)); // msb of address
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_TESTCLK);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_UNTESTCLR);

    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL1, PHY_TESTEN | (address & 0xFFUL)); // address of
                                                                                                   // register
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_TESTCLK);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_UNTESTCLR);

    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL1, data); // data
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_TESTCLK);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_UNTESTCLR);
}

static uint8_t cy_mipi_dsi_dphy_reg_read(uint16_t address)
{
    uint32_t tmp = 0;
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL1, PHY_TESTEN | 0x00UL);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_TESTCLK);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_UNTESTCLR);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL1, ((uint32_t)address >> 8UL));
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_TESTCLK);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_UNTESTCLR);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL1, PHY_TESTEN | (address & 0xFFUL));
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_TESTCLK);
    CY_SET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL0, PHY_UNTESTCLR);

    tmp = CY_GET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_TST_CTRL1);
    return (uint8_t)((tmp & 0x0000FF00UL) >> 8UL);
}
static void cy_mipi_dsi_pll_reprogramming(cy_stc_mipidsi_config_t const *config)
{
    uint32_t bandwidth;
    const cy_stc_dphy_pll_config_t *pll_cfg;
    uint32_t table_index;

    /* Round bandwidth to nearest multiple of 50 Mbps */
    bandwidth = (((config->per_lane_mbps + 25UL) / 50UL) * 50UL);

    /* Bypass Slew Rate Calibration for Lane 1 if only one lane is used*/
    if (config->num_of_lanes == 1U)
    {
        uint8_t rdVal = cy_mipi_dsi_dphy_reg_read(dphy2txtester_DIG_RDWR_TX_LANE1_SLEWRATE_0);
        /* Set bits [3:1] to bypass slew rate calibration:
         * - BIT 3: sr_finished_ovr_en (enable override)
         * - BIT 2: sr_finished_ovr (override value)
         * - BIT 1: srcal_en_ovr_en (enable calibration bypass) */
        cy_mipi_dsi_dphy_reg_write(dphy2txtester_DIG_RDWR_TX_LANE1_SLEWRATE_0, rdVal | 0x0EU);
    }

    /* Apply common PLL settings valid for all bandwidths */
    cy_mipi_dsi_dphy_reg_write(0x0001, 0x20); // DPHY reg 0x1, hsfreqrange_ovr_en_rw = 1'b1
    cy_mipi_dsi_dphy_reg_write(0x015E, 0x10); // DPHY reg 0x15e: pll_cpbias_cntrl_rw[6:0]=0x10
    cy_mipi_dsi_dphy_reg_write(0x0162, 0x08); // DPHY reg 0x162: pll_int_cntrl_rw=6'b000010, pll_gmp_cntrl_rw=2'b00
    cy_mipi_dsi_dphy_reg_write(0x016E, 0x0A); // DPHY reg 0x16e: pll_prop_cntrl_wr[5:0]=6'b001010

    /* Find matching configuration in lookup table
     * Search for the first entry >= requested bandwidth */
    table_index = 0;
    for (uint32_t i = 0; i < DPHY_PLL_CONFIG_TABLE_SIZE; i++)
    {
        if (dphy_pll_config_table[i].bandwidth_mbps >= bandwidth)
        {
            table_index = i;
            break;
        }
        table_index = i; /* If not found, use the last (highest) entry */
    }

    pll_cfg = &dphy_pll_config_table[table_index];

    /* Enable clock divider for bandwidths below 450 Mbps
     * This is required per D-PHY specification for lower frequency operation */
    if (pll_cfg->bandwidth_mbps < 450U)
    {
        cy_mipi_dsi_dphy_reg_write(0x01ACU, 0x10U); /* clkdiv_clk_en = 1 */
    }

    /* Program PLL multiplication and division ratios */
    cy_mipi_dsi_dphy_reg_write(0x0178U, pll_cfg->n_factor); /* Input frequency division ratio (N) */
    cy_mipi_dsi_dphy_reg_write(0x0179U, pll_cfg->m_factor); /* Feedback multiplication ratio (M) lower byte */

    /* Write M carry register only if needed (when M > 255) */
    if (pll_cfg->m_carry != 0U)
    {
        cy_mipi_dsi_dphy_reg_write(0x017AU, pll_cfg->m_carry); /* M factor upper byte/carry */
    }

    /* Program frequency range and VCO control */
    cy_mipi_dsi_dphy_reg_write(0x0002U, pll_cfg->hsfreqrange); /* High-speed frequency range override */
    cy_mipi_dsi_dphy_reg_write(0x017BU, pll_cfg->vco_control); /* VCO control override + enable bits
                                                                * Bit 0: pll_m_ovr_en_rw = 1 (enable M override)
                                                                * Bit 1: pll_vco_cntrl_ovr_en_rw = 1 (enable VCO
                                                                * override) Bits [7:2]: VCO control value */
}

static void cy_mipi_dsi_wr_tx_header(GFXSS_MIPIDSI_Type *mipi_dsi, uint8_t di, uint8_t data0, uint8_t data1)
{
    uint32_t reg;

    reg = ((uint32_t)data1 << 16) | ((uint32_t)data0 << 8) | (((uint32_t)di & 0x3fUL) << 0);

    mipi_dsi->DWCMIPIDSI.GEN_HDR = reg;
}

static void cy_mipi_dsi_wr_tx_data(GFXSS_MIPIDSI_Type *mipi_dsi, uint32_t tx_data)
{
    mipi_dsi->DWCMIPIDSI.GEN_PLD_DATA = tx_data;
}

static void cy_mipi_dsi_long_data_wr(GFXSS_MIPIDSI_Type *mipi_dsi, const uint8_t *data0, uint32_t data_size)
{
    uint32_t word_cnt;
    uint32_t payload;
    uint32_t no_of_words;
    uint32_t data_cnt;
    uint32_t remaining_bytes;

    /* Calculate number of complete 4-byte words */
    no_of_words = data_size / 4U;

    /* Write all complete 4-byte words to FIFO */
    for (word_cnt = 0; word_cnt < no_of_words; word_cnt++)
    {
        data_cnt = word_cnt * 4U;
        payload  = (uint32_t)data0[data_cnt] |
                   ((uint32_t)data0[data_cnt + 1U] << 8) |
                   ((uint32_t)data0[data_cnt + 2U] << 16) |
                   ((uint32_t)data0[data_cnt + 3U] << 24);

        cy_mipi_dsi_wr_tx_data(mipi_dsi, payload);
    }

    /* Handle remaining bytes (1-3 bytes) */
    data_cnt        = no_of_words * 4U;
    remaining_bytes = data_size - data_cnt;

    if (remaining_bytes > 0U)
    {
        /* Build payload from remaining bytes, LSB first */
        payload = (uint32_t)data0[data_cnt];

        if (remaining_bytes >= 2U)
        {
            payload |= ((uint32_t)data0[data_cnt + 1U] << 8);
        }
        if (remaining_bytes >= 3U)
        {
            payload |= ((uint32_t)data0[data_cnt + 2U] << 16);
        }

        cy_mipi_dsi_wr_tx_data(mipi_dsi, payload);
    }
}

static cy_en_mipidsi_status_t cy_mipi_dsi_pkt_write(GFXSS_MIPIDSI_Type *mipi_dsi,
                                                    uint8_t data_type,
                                                    const uint8_t *buf,
                                                    uint32_t len)
{
    cy_en_mipidsi_status_t ret = CY_MIPIDSI_SUCCESS;
    const uint8_t *data        = buf;

    if (mipi_dsi == NULL || buf == NULL)
    {
        ret = CY_MIPIDSI_BAD_PARAM;
    }

    if (ret == CY_MIPIDSI_SUCCESS)
    {
        if (len <= 2UL)
        {
            uint16_t user_data_short = 0;
            (void)memcpy((void *)&user_data_short, (void *)buf, (uint32_t)len);
            /* handle generic short write command */
            cy_mipi_dsi_wr_tx_header(
                mipi_dsi, data_type, (uint8_t)(user_data_short & 0xFFU), (uint8_t)(user_data_short >> 8));
        }
        else
        {
            /* handle generic long write command */
            /* Wait for FIFO to be Empty */
            while (((mipi_dsi->DWCMIPIDSI.CMD_PKT_STATUS &
                     GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_BUFF_PLD_EMPTY_Msk) == 0UL) ||
                   ((mipi_dsi->DWCMIPIDSI.CMD_PKT_STATUS &
                     GFXSS_MIPIDSI_DWCMIPIDSI_CMD_PKT_STATUS_CMD_PKT_STATUS_GEN_PLD_W_EMPTY_Msk) == 0UL))
            {
            }

            cy_mipi_dsi_long_data_wr(mipi_dsi, data, len);

            cy_mipi_dsi_wr_tx_header(mipi_dsi, data_type, (uint8_t)len & 0xFFU, (uint8_t)((len & 0xFF00U) >> 8));
        }
    }

    return ret;
}

static cy_en_mipidsi_status_t cy_mipi_dsi_dcs_cmd(GFXSS_MIPIDSI_Type *mipi_dsi,
                                                  cy_en_mipidsi_dcs_cmd_type_t cmd,
                                                  const uint32_t *param,
                                                  int len)
{
    cy_en_mipidsi_status_t err = CY_MIPIDSI_SUCCESS;
    uint8_t buf[2];

    /* Unused until short write with parameter is implemented */
    (void)param;
    (void)len;

    switch (cmd)
    {
    case MIPI_DCS_EXIT_SLEEP_MODE:
    case MIPI_DCS_ENTER_SLEEP_MODE:
    case MIPI_DCS_SET_DISPLAY_ON:
    case MIPI_DCS_SET_DISPLAY_OFF:
    case MIPI_DCS_SOFT_RESET:
        buf[0] = (uint8_t)cmd;
        err    = cy_mipi_dsi_pkt_write(mipi_dsi, (uint8_t)MIPI_DSI_DCS_SHORT_WRITE, buf, 1UL);
        break;

    default:
        err = CY_MIPIDSI_BAD_PARAM;
        break;
    }

    return err;
}
static void cy_mipi_dsi_clear_err(GFXSS_MIPIDSI_Type *mipi_dsi)
{
    mipi_dsi->DWCMIPIDSI.INT_ST0;
    mipi_dsi->DWCMIPIDSI.INT_ST1;

    mipi_dsi->DWCMIPIDSI.INT_MSK0 = 0xffffffffUL;
    mipi_dsi->DWCMIPIDSI.INT_MSK1 = 0xffffffffUL;
}

static void cy_mipi_dsi_dpi_config(GFXSS_MIPIDSI_Type *mipi_dsi, cy_stc_mipidsi_config_t const *config)
{
    uint32_t val = 0, color = 0;

    switch (config->dpi_fmt)
    {
    case CY_MIPIDSI_FMT_RGB888:
        color = DPI_COLOR_CODING_24BIT;
        break;
    case CY_MIPIDSI_FMT_RGB666:
        color = (uint32_t)DPI_COLOR_CODING_18BIT_2 | (uint32_t)LOOSELY18_EN;
        break;
    case CY_MIPIDSI_FMT_RGB666_PACKED:
        color = DPI_COLOR_CODING_18BIT_1;
        break;
    case CY_MIPIDSI_FMT_RGB565:
        color = DPI_COLOR_CODING_16BIT_1;
        break;
    default:
        // no action
        break;
    }

    if ((bool)(config->display_params->polarity_flags & DISPLAY_PARAMS_FLAG_NVSYNC))
    {
        val |= VSYNC_ACTIVE_LOW;
    }
    if ((bool)(config->display_params->polarity_flags & DISPLAY_PARAMS_FLAG_NHSYNC))
    {
        val |= HSYNC_ACTIVE_LOW;
    }

    mipi_dsi->DWCMIPIDSI.DPI_VCID         = DPI_VCID(config->virtual_ch);
    mipi_dsi->DWCMIPIDSI.DPI_COLOR_CODING = color;
    mipi_dsi->DWCMIPIDSI.DPI_CFG_POL      = val;

    mipi_dsi->DWCMIPIDSI.DPI_LP_CMD_TIM = OUTVACT_LPCMD_TIME(4UL) | INVACT_LPCMD_TIME(4UL);
}

static void cy_mipi_dsi_packet_handler_config(GFXSS_MIPIDSI_Type *mipi_dsi)
{
    /* Packet Configuration - Enable CRC, ECC, BTA*/
    mipi_dsi->DWCMIPIDSI.PCKHDL_CFG = CRC_RX_EN | ECC_RX_EN | BTA_EN;
}

static void cy_mipi_dsi_video_packet_config(GFXSS_MIPIDSI_Type *mipi_dsi, cy_stc_mipidsi_config_t const *config)
{
    mipi_dsi->DWCMIPIDSI.VID_PKT_SIZE = VID_PKT_SIZE(config->display_params->hdisplay);
}

static void cy_mipi_dsi_command_mode_config(GFXSS_MIPIDSI_Type *mipi_dsi)
{
    mipi_dsi->DWCMIPIDSI.TO_CNT_CFG = HSTX_TO_CNT(10000UL) | LPRX_TO_CNT(1000UL);
    mipi_dsi->DWCMIPIDSI.BTA_TO_CNT = 0xD00UL;
    mipi_dsi->DWCMIPIDSI.MODE_CFG   = ENABLE_CMD_MODE;
}

/* Get lane byte clock cycles. */
static uint32_t cy_mipi_dsi_get_hcomponent_lbcc(cy_stc_mipidsi_config_t const *config, uint32_t hcomponent)
{
    uint32_t frac, lbcc;
    lbcc = hcomponent * config->per_lane_mbps * 1000UL / 8UL;

    frac = lbcc % config->display_params->pixel_clock;
    lbcc = lbcc / config->display_params->pixel_clock;
    if ((bool)frac)
    {
        lbcc++;
    }
    return lbcc;
}

static void cy_mipi_dsi_line_timer_config(GFXSS_MIPIDSI_Type *mipi_dsi, cy_stc_mipidsi_config_t const *config)
{
    uint32_t htotal, lbcc;

    htotal = (uint32_t)config->display_params->hsync_width + (uint32_t)config->display_params->hdisplay +
             (uint32_t)config->display_params->hfp + (uint32_t)config->display_params->hbp;

    lbcc                                = cy_mipi_dsi_get_hcomponent_lbcc(config, htotal);
    mipi_dsi->DWCMIPIDSI.VID_HLINE_TIME = lbcc;

    lbcc                              = cy_mipi_dsi_get_hcomponent_lbcc(config, config->display_params->hsync_width);
    mipi_dsi->DWCMIPIDSI.VID_HSA_TIME = lbcc;

    lbcc                              = cy_mipi_dsi_get_hcomponent_lbcc(config, config->display_params->hbp);
    mipi_dsi->DWCMIPIDSI.VID_HBP_TIME = lbcc;
}

static void cy_mipi_dsi_vertical_timing_config(GFXSS_MIPIDSI_Type *mipi_dsi, cy_stc_mipidsi_config_t const *config)
{

    mipi_dsi->DWCMIPIDSI.VID_VACTIVE_LINES = config->display_params->vdisplay;
    mipi_dsi->DWCMIPIDSI.VID_VSA_LINES     = config->display_params->vsync_width;
    mipi_dsi->DWCMIPIDSI.VID_VFP_LINES     = config->display_params->vfp;
    mipi_dsi->DWCMIPIDSI.VID_VBP_LINES     = config->display_params->vbp;
}

static void cy_mipi_dsi_dphy_timing_config(GFXSS_MIPIDSI_Type *mipi_dsi)
{
    mipi_dsi->DWCMIPIDSI.PHY_TMR_CFG = PHY_CLKHS2LP_TIME(0x26UL) | PHY_CLKLP2HS_TIME(0x60UL);

    mipi_dsi->DWCMIPIDSI.PHY_TMR_LPCLK_CFG = PHY_CLKHS2LP_TIME(0x38UL) | PHY_CLKLP2HS_TIME(0x7DUL);
}

static void cy_mipi_dsi_dphy_interface_config(GFXSS_MIPIDSI_Type *mipi_dsi, cy_stc_mipidsi_config_t const *config)
{
    mipi_dsi->DWCMIPIDSI.PHY_IF_CFG = PHY_STOP_WAIT_TIME(0x28UL) | N_LANES(config->num_of_lanes);
}

static void cy_mipi_dsi_dphy_init(GFXSS_MIPIDSI_Type *mipi_dsi)
{
    cy_stc_syspm_miscldo_params_t ldo_params = {
        true, CY_SYSPM_MISCLDO_VCCACT, CY_SYSPM_MISCLDO_VOLTAGE_0_90V, CY_SYSPM_MISCLDO_VCCACT_TRIM_0};

    (void)Cy_SysPm_MiscLdoConfigure(&ldo_params);

    /* Clear PHY state */
    mipi_dsi->DWCMIPIDSI.PHY_RSTZ      = PHY_DISFORCEPLL | PHY_DISABLECLK | DPHY_RSTZ | PHY_SHUTDOWNZ;
    mipi_dsi->DWCMIPIDSI.PHY_TST_CTRL0 = PHY_UNTESTCLR;
    mipi_dsi->DWCMIPIDSI.PHY_TST_CTRL0 = PHY_TESTCLR;
    mipi_dsi->DWCMIPIDSI.PHY_TST_CTRL0 = PHY_UNTESTCLR;
}

static void cy_mipi_dsi_dphy_enable(GFXSS_MIPIDSI_Type *mipi_dsi)
{
    mipi_dsi->DWCMIPIDSI.PHY_RSTZ = 0;
    mipi_dsi->DWCMIPIDSI.PHY_RSTZ = PHY_ENABLECLK;
    mipi_dsi->DWCMIPIDSI.PHY_RSTZ = PHY_ENABLECLK | PHY_UNSHUTDOWNZ;
    mipi_dsi->DWCMIPIDSI.PHY_RSTZ = PHY_ENABLECLK | PHY_UNRSTZ | PHY_UNSHUTDOWNZ;

    while ((CY_GET_REG32(&GFXSS->GFXSS_MIPIDSI.DWCMIPIDSI.PHY_STATUS) & (PHY_LOCK)) != (PHY_LOCK))
    {
        Cy_SysLib_DelayUs(DPHY_LOCK_TIMEOUT_US);
    }
}

static void cy_mipi_dsi_init(GFXSS_MIPIDSI_Type *base, cy_stc_mipidsi_config_t const *config)
{
    /*
     * The maximum permitted escape clock is 20MHz and it is derived from
     * lanebyteclk, which is running at "max_phy_clk / 8".  Thus we want:
     *
     *     (max_phy_clk >> 3) / esc_clk_division < 20
     * which is:
     *     (max_phy_clk >> 3) / 20 > esc_clk_division
     */
    uint32_t esc_clk_division = (config->max_phy_clk >> 3) / 20UL + 1UL;

    /* RESET MIPI DSI IP Block */
    base->DWCMIPIDSI.PWR_UP = ~_VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ, 1);

    /* Configure Clock */
    base->DWCMIPIDSI.CLKMGR_CFG = TO_CLK_DIVISION(10UL) | TX_ESC_CLK_DIVISION(esc_clk_division);
}
static void cy_mipi_dsi_video_mode_config(GFXSS_MIPIDSI_Type *base, cy_stc_mipidsi_config_t const *config)
{
    base->DWCMIPIDSI.VID_MODE_CFG = config->mode_flags;
}

static void cy_mipi_dsi_set_mode(GFXSS_MIPIDSI_Type *base, cy_stc_mipidsi_config_t const *config)
{
    /* RESET MIPI DSI IP Block */
    base->DWCMIPIDSI.PWR_UP &= ~_VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ, 1);

    if (config->dsi_mode == DSI_VIDEO_MODE)
    {
        base->DWCMIPIDSI.MODE_CFG = ENABLE_VIDEO_MODE;
    }
    else
    {
        base->DWCMIPIDSI.MODE_CFG = ENABLE_CMD_MODE;
    }

    base->DWCMIPIDSI.LPCLK_CTRL = PHY_TXREQUESTCLKHS;
    /* powerup MIPI DSI IP Block */
    base->DWCMIPIDSI.PWR_UP |= _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ, 1);
}

cy_en_mipidsi_status_t Cy_MIPIDSI_Init(GFXSS_MIPIDSI_Type *base,
                                       cy_stc_mipidsi_config_t const *config,
                                       cy_stc_mipidsi_context_t *context)
{
    cy_en_mipidsi_status_t result = CY_MIPIDSI_SUCCESS;

    if ((base == NULL) || (config == NULL))
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    if (config->display_params == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    if ((config->num_of_lanes == 0U) || (config->num_of_lanes > 4U))
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    if ((config->per_lane_mbps < 100U) || (config->per_lane_mbps > 2500U))
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    if (config->virtual_ch > 3U)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    if (config->display_params->pixel_clock == 0U)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    if ((config->display_params->hdisplay == 0U) || (config->display_params->vdisplay == 0U))
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    (void)context;

    /* Power up DSI and DPHY */
    cy_mipi_dsi_init(base, config);

    /* DSI Display Interface Configuration */
    cy_mipi_dsi_dpi_config(base, config);

    cy_mipi_dsi_packet_handler_config(base);
    cy_mipi_dsi_video_mode_config(base, config);
    cy_mipi_dsi_video_packet_config(base, config);
    cy_mipi_dsi_command_mode_config(base);
    cy_mipi_dsi_line_timer_config(base, config);
    cy_mipi_dsi_vertical_timing_config(base, config);

    cy_mipi_dsi_dphy_init(base);
    cy_mipi_dsi_dphy_timing_config(base);
    cy_mipi_dsi_dphy_interface_config(base, config);

    cy_mipi_dsi_clear_err(base);
    cy_mipi_dsi_pll_reprogramming(config);
    cy_mipi_dsi_dphy_enable(base);

    cy_mipi_dsi_set_mode(base, config);

    /* Clear Error Status */
    cy_mipi_dsi_clear_err(base);

    return result;
}

void Cy_MIPIDSI_Enable(GFXSS_MIPIDSI_Type *base)
{
    CY_ASSERT_L1(NULL != base);

    base->MXMIPIDSI.CTL |= GFXSS_MIPIDSI_MXMIPIDSI_CTL_ENABLED_Msk;
}

void Cy_MIPIDSI_Disable(GFXSS_MIPIDSI_Type *base)
{
    CY_ASSERT_L1(NULL != base);

    base->MXMIPIDSI.CTL &= ~GFXSS_MIPIDSI_MXMIPIDSI_CTL_ENABLED_Msk;
}

void Cy_MIPIDSI_DeInit(GFXSS_MIPIDSI_Type *base)
{
    CY_ASSERT_L1(NULL != base);

    /* Power down DPHY */
    base->DWCMIPIDSI.PHY_RSTZ = 0;
}

void Cy_MIPIDSI_SetInterruptMask(GFXSS_MIPIDSI_Type *base, uint32_t interrupt_mask)
{
    CY_ASSERT_L1(NULL != base);

    base->MXMIPIDSI.INTR_MASK = interrupt_mask;
}

uint32_t Cy_MIPIDSI_GetInterruptMask(GFXSS_MIPIDSI_Type const *base)
{
    CY_ASSERT_L1(NULL != base);

    return base->MXMIPIDSI.INTR_MASK;
}

uint32_t Cy_MIPIDSI_GetInterruptStatusMasked(GFXSS_MIPIDSI_Type const *base)
{
    CY_ASSERT_L1(NULL != base);

    return base->MXMIPIDSI.INTR_MASKED;
}

cy_en_mipidsi_status_t Cy_MIPIDSI_WritePacket(GFXSS_MIPIDSI_Type *base, const uint8_t *buf, uint32_t length)
{
    cy_en_mipidsi_packet_type_t packet_type;

    if (buf == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    if ((length == 0U) || (length > DSI_CMD_BUF_MAXSIZE))
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    else if (1UL == length)
    {
        packet_type = MIPI_DSI_DCS_SHORT_WRITE;
    }
    else if (2UL == length)
    {
        packet_type = MIPI_DSI_DCS_SHORT_WRITE_PARAM;
    }
    else
    {
        packet_type = MIPI_DSI_DCS_LONG_WRITE;
    }

    return cy_mipi_dsi_pkt_write(base, (uint8_t)packet_type, buf, length);
}

cy_en_mipidsi_status_t Cy_MIPIDSI_GenericWritePacket(GFXSS_MIPIDSI_Type *base, const uint8_t *buf, uint32_t length)
{
    cy_en_mipidsi_packet_type_t packet_type;

    if (base == NULL || buf == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    if ((length == 0U) || (length > DSI_CMD_BUF_MAXSIZE))
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    else if (1UL == length)
    {
        packet_type = MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM;
    }
    else if (2UL == length)
    {
        packet_type = MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM;
    }
    else if (3UL == length)
    {
        packet_type = MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM;
    }
    else
    {
        packet_type = MIPI_DSI_GENERIC_LONG_WRITE;
    }

    return cy_mipi_dsi_pkt_write(base, (uint8_t)packet_type, buf, length);
}

cy_en_mipidsi_status_t Cy_MIPIDSI_ReadPacket(GFXSS_MIPIDSI_Type *base,
                                             cy_en_mipidsi_packet_type_t packet_type,
                                             uint32_t *buf,
                                             uint32_t length)
{
    /* To be implemented - As per SAS DSI Read is not supported yet. Need to implement this using Generic APB Slave
     * interface */

    (void)base;
    (void)packet_type;
    (void)buf;
    (void)length;

    return CY_MIPIDSI_SUCCESS;
}

cy_en_mipidsi_status_t Cy_MIPIDSI_EnterSleep(GFXSS_MIPIDSI_Type *base)
{
    cy_en_mipidsi_status_t result;
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }
    result = cy_mipi_dsi_dcs_cmd(base, MIPI_DCS_ENTER_SLEEP_MODE, NULL, 0);
    if (result != CY_MIPIDSI_SUCCESS)
    {
        return result;
    }
    return result;
}

cy_en_mipidsi_status_t Cy_MIPIDSI_ExitSleep(GFXSS_MIPIDSI_Type *base)
{
    cy_en_mipidsi_status_t result;
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    result = cy_mipi_dsi_dcs_cmd(base, MIPI_DCS_EXIT_SLEEP_MODE, NULL, 0);
    if (result != CY_MIPIDSI_SUCCESS)
    {
        return result;
    }
    return result;
}

cy_en_mipidsi_status_t Cy_MIPIDSI_SoftReset(GFXSS_MIPIDSI_Type *base)
{
    cy_en_mipidsi_status_t result;
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    result = cy_mipi_dsi_dcs_cmd(base, MIPI_DCS_SOFT_RESET, NULL, 0);
    if (result != CY_MIPIDSI_SUCCESS)
    {
        return result;
    }
    return result;
}

cy_en_mipidsi_status_t Cy_MIPIDSI_DisplayON(GFXSS_MIPIDSI_Type *base)
{
    cy_en_mipidsi_status_t result;
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    result = cy_mipi_dsi_dcs_cmd(base, MIPI_DCS_SET_DISPLAY_ON, NULL, 0);
    if (result != CY_MIPIDSI_SUCCESS)
    {
        return result;
    }
    return result;
}

cy_en_mipidsi_status_t Cy_MIPIDSI_DisplayOFF(GFXSS_MIPIDSI_Type *base)
{
    cy_en_mipidsi_status_t result;
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    result = cy_mipi_dsi_dcs_cmd(base, MIPI_DCS_SET_DISPLAY_OFF, NULL, 0);
    if (result != CY_MIPIDSI_SUCCESS)
    {
        return result;
    }
    return result;
}

cy_en_mipidsi_status_t Cy_MIPIDSI_EnterULPM(GFXSS_MIPIDSI_Type *base)
{
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    cy_en_mipidsi_status_t status = CY_MIPIDSI_TIMEOUT;
    uint32_t no_of_lanes =
        _FLD2VAL(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_N_LANES, base->DWCMIPIDSI.PHY_IF_CFG);

    /*  Set PHY_ULPS_CTRL[3:0] = 4'h5 to enter ULPM in the data and clock lanes. */
    base->DWCMIPIDSI.PHY_ULPS_CTRL =
        _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXREQULPSCLK, 1) |
        _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXREQULPSLAN, 1);
    Cy_SysLib_Delay(ULPM_TRANSITION_DELAY_MS);
    /*  Verify that all the data lanes has entered in ULPM using PHY_STATUS register. */
    if (no_of_lanes == N_LANES(2UL)) // Two lanes configured
    {
        if ((base->DWCMIPIDSI.PHY_STATUS & MIPI_DPHY_STATUS_DATA_LINES) == 0x0U)
        {
            status = CY_MIPIDSI_SUCCESS;
        }
    }
    else
    { // one lane configured
        if ((base->DWCMIPIDSI.PHY_STATUS & MIPI_DPHY_STATUS_DATA_LINE0) == 0x0U)
        {
            status = CY_MIPIDSI_SUCCESS;
        }
    }

    base->DWCMIPIDSI.PWR_UP &= ~_VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ, 1);

    return status;
}
cy_en_mipidsi_status_t Cy_MIPIDSI_ExitULPM(GFXSS_MIPIDSI_Type *base)
{
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    cy_en_mipidsi_status_t status = CY_MIPIDSI_TIMEOUT;
    uint32_t no_of_lanes =
        _FLD2VAL(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_N_LANES, base->DWCMIPIDSI.PHY_IF_CFG);

    base->DWCMIPIDSI.PWR_UP |= _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ, 1);

    /* Exit ULPM Data and Clock lines */
    base->DWCMIPIDSI.PHY_ULPS_CTRL =
        _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXEXITULPSLAN, 1) |
        _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXEXITULPSCLK, 1);

    Cy_SysLib_Delay(ULPM_TRANSITION_DELAY_MS);
    /*  Verify that all the data lanes has exited in ULPM using PHY_STATUS register. */
    if (no_of_lanes == N_LANES(2UL)) // Two lanes configured
    {
        if ((base->DWCMIPIDSI.PHY_STATUS & MIPI_DPHY_STATUS_DATA_LINES) == MIPI_DPHY_STATUS_DATA_LINES)
        {
            status = CY_MIPIDSI_SUCCESS;
        }
    }
    else
    { // one lane configured
        if ((base->DWCMIPIDSI.PHY_STATUS & MIPI_DPHY_STATUS_DATA_LINE0) == MIPI_DPHY_STATUS_DATA_LINE0)
        {
            status = CY_MIPIDSI_SUCCESS;
        }
    }

    return status;
}
cy_en_mipidsi_status_t Cy_MIPIDSI_EnterULPM_Data(GFXSS_MIPIDSI_Type *base)
{
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    cy_en_mipidsi_status_t status = CY_MIPIDSI_TIMEOUT;
    uint32_t no_of_lanes =
        _FLD2VAL(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_N_LANES, base->DWCMIPIDSI.PHY_IF_CFG);

    /*  Set PHY_ULPS_CTRL[3:0] = 0x4 to enter ULPM in the data lanes. */
    base->DWCMIPIDSI.PHY_ULPS_CTRL = _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXREQULPSLAN, 1);
    Cy_SysLib_Delay(ULPM_TRANSITION_DELAY_MS);
    /*  Verify that all the data lanes has entered in ULPM using PHY_STATUS register. */
    if (no_of_lanes == N_LANES(2UL)) // Two lanes configured
    {
        if ((base->DWCMIPIDSI.PHY_STATUS & MIPI_DPHY_STATUS_DATA_LINES) == 0x0U)
        {
            status = CY_MIPIDSI_SUCCESS;
        }
    }
    else
    { // one lane configured
        if ((base->DWCMIPIDSI.PHY_STATUS & MIPI_DPHY_STATUS_DATA_LINE0) == 0x0U)
        {
            status = CY_MIPIDSI_SUCCESS;
        }
    }

    base->DWCMIPIDSI.PWR_UP &= ~_VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ, 1);

    return status;
}
cy_en_mipidsi_status_t Cy_MIPIDSI_ExitULPM_Data(GFXSS_MIPIDSI_Type *base)
{
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    cy_en_mipidsi_status_t status = CY_MIPIDSI_TIMEOUT;
    uint32_t no_of_lanes =
        (uint8_t)_FLD2VAL(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_IF_CFG_PHY_IF_CFG_N_LANES, base->DWCMIPIDSI.PHY_IF_CFG);

    base->DWCMIPIDSI.PWR_UP |= _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PWR_UP_PWR_UP_SHUTDOWNZ, 1);

    /* Assert the Exit ULPM bits by setting PHY_ULPS_CTRL[3:0] = 0x8 */
    base->DWCMIPIDSI.PHY_ULPS_CTRL =
        _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_PHY_ULPS_CTRL_PHY_ULPS_CTRL_PHY_TXEXITULPSLAN, 1);
    ;
    Cy_SysLib_Delay(ULPM_TRANSITION_DELAY_MS);
    /*  Verify that all the data lanes has exited in ULPM using PHY_STATUS register. */
    if (no_of_lanes == N_LANES(2UL)) // Two lanes configured
    {
        if ((base->DWCMIPIDSI.PHY_STATUS & MIPI_DPHY_STATUS_DATA_LINES) == MIPI_DPHY_STATUS_DATA_LINES)
        {
            status = CY_MIPIDSI_SUCCESS;
        }
    }
    else
    { // one lane configured
        if ((base->DWCMIPIDSI.PHY_STATUS & MIPI_DPHY_STATUS_DATA_LINE0) == MIPI_DPHY_STATUS_DATA_LINE0)
        {
            status = CY_MIPIDSI_SUCCESS;
        }
    }

    return status;
}

cy_en_mipidsi_status_t Cy_MIPIDSI_CMD_MODE_DCS_SetLowPower(GFXSS_MIPIDSI_Type *base, bool enable)
{
    if (base == NULL)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    if ((base->DWCMIPIDSI.MODE_CFG & ENABLE_CMD_MODE) == 0U)
    {
        return CY_MIPIDSI_BAD_PARAM;
    }

    if (enable)
    {
        base->DWCMIPIDSI.CMD_MODE_CFG |= GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SW_0P_TX_Msk |
                                         GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SW_1P_TX_Msk |
                                         GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SR_0P_TX_Msk |
                                         GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_LW_TX_Msk;
    }
    else
    {
        base->DWCMIPIDSI.CMD_MODE_CFG &= ~(GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SW_0P_TX_Msk |
                                           GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SW_1P_TX_Msk |
                                           GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_SR_0P_TX_Msk |
                                           GFXSS_MIPIDSI_DWCMIPIDSI_CMD_MODE_CFG_CMD_MODE_CFG_DCS_LW_TX_Msk);
    }

    return CY_MIPIDSI_SUCCESS;
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22GFXSS */
/* [] END OF FILE */
