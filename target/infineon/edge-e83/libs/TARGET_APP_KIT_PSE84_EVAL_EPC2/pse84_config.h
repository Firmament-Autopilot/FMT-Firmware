/***************************************************************************//**
* PSE84 device configuration header
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
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

#ifndef _PSE84_CONFIG_H_
#define _PSE84_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_ETH_CLK_SLOW               = 0x00000000u, /* eth.clk_slow */
    PCLK_SCB0_CLOCK_SCB_EN          = 0x00000100u, /* scb[0].clock_scb_en */
    PCLK_SCB2_CLOCK_SCB_EN          = 0x00000101u, /* scb[2].clock_scb_en */
    PCLK_SCB3_CLOCK_SCB_EN          = 0x00000102u, /* scb[3].clock_scb_en */
    PCLK_SCB4_CLOCK_SCB_EN          = 0x00000103u, /* scb[4].clock_scb_en */
    PCLK_SCB5_CLOCK_SCB_EN          = 0x00000104u, /* scb[5].clock_scb_en */
    PCLK_SCB6_CLOCK_SCB_EN          = 0x00000105u, /* scb[6].clock_scb_en */
    PCLK_SCB7_CLOCK_SCB_EN          = 0x00000106u, /* scb[7].clock_scb_en */
    PCLK_SCB8_CLOCK_SCB_EN          = 0x00000107u, /* scb[8].clock_scb_en */
    PCLK_SCB9_CLOCK_SCB_EN          = 0x00000108u, /* scb[9].clock_scb_en */
    PCLK_SCB10_CLOCK_SCB_EN         = 0x00000109u, /* scb[10].clock_scb_en */
    PCLK_SCB11_CLOCK_SCB_EN         = 0x0000010Au, /* scb[11].clock_scb_en */
    PCLK_CANFD0_CLOCK_CAN_EN0       = 0x0000010Bu, /* canfd[0].clock_can_en[0] */
    PCLK_CANFD0_CLOCK_CAN_EN1       = 0x0000010Cu, /* canfd[0].clock_can_en[1] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN0   = 0x0000010Du, /* tcpwm[0].clock_counter_en[0] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN1   = 0x0000010Eu, /* tcpwm[0].clock_counter_en[1] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN2   = 0x0000010Fu, /* tcpwm[0].clock_counter_en[2] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN3   = 0x00000110u, /* tcpwm[0].clock_counter_en[3] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN4   = 0x00000111u, /* tcpwm[0].clock_counter_en[4] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN5   = 0x00000112u, /* tcpwm[0].clock_counter_en[5] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN6   = 0x00000113u, /* tcpwm[0].clock_counter_en[6] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN7   = 0x00000114u, /* tcpwm[0].clock_counter_en[7] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN256 = 0x00000115u, /* tcpwm[0].clock_counter_en[256] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN257 = 0x00000116u, /* tcpwm[0].clock_counter_en[257] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN258 = 0x00000117u, /* tcpwm[0].clock_counter_en[258] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN259 = 0x00000118u, /* tcpwm[0].clock_counter_en[259] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN260 = 0x00000119u, /* tcpwm[0].clock_counter_en[260] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN261 = 0x0000011Au, /* tcpwm[0].clock_counter_en[261] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN262 = 0x0000011Bu, /* tcpwm[0].clock_counter_en[262] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN263 = 0x0000011Cu, /* tcpwm[0].clock_counter_en[263] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN264 = 0x0000011Du, /* tcpwm[0].clock_counter_en[264] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN265 = 0x0000011Eu, /* tcpwm[0].clock_counter_en[265] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN266 = 0x0000011Fu, /* tcpwm[0].clock_counter_en[266] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN267 = 0x00000120u, /* tcpwm[0].clock_counter_en[267] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN268 = 0x00000121u, /* tcpwm[0].clock_counter_en[268] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN269 = 0x00000122u, /* tcpwm[0].clock_counter_en[269] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN270 = 0x00000123u, /* tcpwm[0].clock_counter_en[270] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN271 = 0x00000124u, /* tcpwm[0].clock_counter_en[271] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN272 = 0x00000125u, /* tcpwm[0].clock_counter_en[272] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN273 = 0x00000126u, /* tcpwm[0].clock_counter_en[273] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN274 = 0x00000127u, /* tcpwm[0].clock_counter_en[274] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN275 = 0x00000128u, /* tcpwm[0].clock_counter_en[275] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN276 = 0x00000129u, /* tcpwm[0].clock_counter_en[276] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN277 = 0x0000012Au, /* tcpwm[0].clock_counter_en[277] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN278 = 0x0000012Bu, /* tcpwm[0].clock_counter_en[278] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN279 = 0x0000012Cu, /* tcpwm[0].clock_counter_en[279] */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN11 = 0x0000012Du, /* ioss.clock_smartio_pclk_pos_en[11] */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN17 = 0x0000012Eu, /* ioss.clock_smartio_pclk_pos_en[17] */
    PCLK_PASS_CLOCK_DAC0            = 0x00000200u, /* pass.clock_dac[0] */
    PCLK_PASS_CLOCK_DAC1            = 0x00000201u, /* pass.clock_dac[1] */
    PCLK_PASS_CLOCK_PTC             = 0x00000202u, /* pass.clock_ptc */
    PCLK_PASS_CLOCK_PUMP_PERI       = 0x00000203u, /* pass.clock_pump_peri */
    PCLK_ETH0_REF_CLK_INT           = 0x00000300u, /* eth[0].ref_clk_int */
    PCLK_ETH0_CLK_TSU               = 0x00000400u, /* eth[0].clk_tsu */
    PCLK_IOSS_CLK_HF                = 0x00000500u, /* ioss.clk_hf */
    PCLK_I3C0_CLK_IF                = 0x00000600u, /* i3c[0].clk_if */
    PCLK_DEBUG600_CLOCK_TRACE_IN    = 0x00000700u, /* debug600.clock_trace_in */
    PCLK_SCB1_CLOCK_SCB_EN          = 0x00000800u, /* scb[1].clock_scb_en */
    PCLK_I3C_CLOCK_I3C_EN           = 0x00000900u, /* i3c.clock_i3c_en */
    PCLK_SDHC0_CLK_SLOW             = 0x00010000u, /* sdhc[0].clk_slow */
    PCLK_SDHC1_CLK_SLOW             = 0x00010001u, /* sdhc[1].clk_slow */
    PCLK_SMIF0_CLK_MEM              = 0x00010002u, /* smif[0].clk_mem */
    PCLK_SMIF1_CLK_MEM              = 0x00010003u, /* smif[1].clk_mem */
    PCLK_USBHS_MMIO_CLK_HF          = 0x00010004u, /* usbhs.mmio_clk_hf */
    PCLK_MXU55_CLK_HF               = 0x00010005u, /* mxu55.clk_hf */
    PCLK_SOCMEM_CLK_PORT_0          = 0x00010006u, /* socmem.clk_port_0 */
    PCLK_SOCMEM_CLK_PORT_1          = 0x00010007u, /* socmem.clk_port_1 */
    PCLK_SOCMEM_CLK_PORT_2          = 0x00010008u, /* socmem.clk_port_2 */
    PCLK_GFXSS_CLK_HF               = 0x00010009u, /* gfxss.clk_hf */
    PCLK_TDM0_CLK_IF_SRSS0          = 0x00010100u, /* tdm[0].clk_if_srss[0] */
    PCLK_TDM0_CLK_IF_SRSS1          = 0x00010101u, /* tdm[0].clk_if_srss[1] */
    PCLK_PDM0_CLK_IF_SRSS           = 0x00010102u, /* pdm[0].clk_if_srss */
    PCLK_SDHC0_CLK_HF               = 0x00010200u, /* sdhc[0].clk_hf */
    PCLK_SDHC1_CLK_HF               = 0x00010300u, /* sdhc[1].clk_hf */
    PCLK_SMIF0_CLK_SLOW             = 0x00010400u, /* smif[0].clk_slow */
    PCLK_SMIF1_CLK_SLOW             = 0x00010401u, /* smif[1].clk_slow */
    PCLK_SOCMEM_CLK_PORT_3          = 0x00010402u, /* socmem.clk_port_3 */
    PCLK_SOCMEM_CLK_PORT_4          = 0x00010403u, /* socmem.clk_port_4 */
    PCLK_SOCMEM_CLK_SRAM_0          = 0x00010500u, /* socmem.clk_sram_0 */
    PCLK_SOCMEM_CLK_SRAM_1          = 0x00010501u, /* socmem.clk_sram_1 */
    PCLK_SOCMEM_CLK_SRAM_2          = 0x00010502u, /* socmem.clk_sram_2 */
    PCLK_SOCMEM_CLK_SRAM_3          = 0x00010503u /* socmem.clk_sram_3 */
} en_clk_dst_t;

/* Peripheral Group */
typedef enum
{
    PERI_0_GROUP_0                  = 0x0000u,  /* SYS_MMIO0 */
    PERI_0_GROUP_1                  = 0x0001u,  /* SYS_MMIO1 */
    PERI_0_GROUP_2                  = 0x0002u,  /* SYS_MMIO2 */
    PERI_0_GROUP_3                  = 0x0003u,  /* SYS_MMIO3 */
    PERI_0_GROUP_4                  = 0x0004u,  /* SYS_MMIO4 */
    PERI_0_GROUP_5                  = 0x0005u,  /* SYS_MMIO5 */
    PERI_1_GROUP_0                  = 0x0100u,  /* APP_MMIO0 */
    PERI_1_GROUP_1                  = 0x0101u,  /* APP_MMIO1 */
    PERI_1_GROUP_2                  = 0x0102u,  /* APP_MMIO2 */
    PERI_1_GROUP_3                  = 0x0103u,  /* APP_MMIO3 */
    PERI_1_GROUP_4                  = 0x0104u   /* APP_MMIO_TCM */
} en_peri_grp_t;

/* Trigger Group */
/* This section contains the enums related to the Trigger multiplexer (TrigMux) driver.
* Refer to the Cypress Peripheral Driver Library Documentation, section Trigger multiplexer (TrigMux) -> Enumerated Types for details.
*/
/* Trigger Group Inputs */
/* Peri 0 Trigger Input Group 0 - P-DMA0 Request Assignments */
typedef enum
{
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT0 = 0x00000001u, /* m33syscpuss.dw0_tr_out[0] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT1 = 0x00000002u, /* m33syscpuss.dw0_tr_out[1] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT2 = 0x00000003u, /* m33syscpuss.dw0_tr_out[2] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT3 = 0x00000004u, /* m33syscpuss.dw0_tr_out[3] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT4 = 0x00000005u, /* m33syscpuss.dw0_tr_out[4] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT5 = 0x00000006u, /* m33syscpuss.dw0_tr_out[5] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT6 = 0x00000007u, /* m33syscpuss.dw0_tr_out[6] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT7 = 0x00000008u, /* m33syscpuss.dw0_tr_out[7] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT8 = 0x00000009u, /* m33syscpuss.dw0_tr_out[8] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT9 = 0x0000000Au, /* m33syscpuss.dw0_tr_out[9] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT10 = 0x0000000Bu, /* m33syscpuss.dw0_tr_out[10] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT11 = 0x0000000Cu, /* m33syscpuss.dw0_tr_out[11] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT12 = 0x0000000Du, /* m33syscpuss.dw0_tr_out[12] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT13 = 0x0000000Eu, /* m33syscpuss.dw0_tr_out[13] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT14 = 0x0000000Fu, /* m33syscpuss.dw0_tr_out[14] */
    PERI_0_TRIG_IN_MUX_0_PDMA0_TR_OUT15 = 0x00000010u, /* m33syscpuss.dw0_tr_out[15] */
    PERI_0_TRIG_IN_MUX_0_AXIDMAC_TR_OUT0 = 0x00000011u, /* m55appcpuss.axidmac_tr_out[0] */
    PERI_0_TRIG_IN_MUX_0_AXIDMAC_TR_OUT1 = 0x00000012u, /* m55appcpuss.axidmac_tr_out[1] */
    PERI_0_TRIG_IN_MUX_0_AXIDMAC_TR_OUT2 = 0x00000013u, /* m55appcpuss.axidmac_tr_out[2] */
    PERI_0_TRIG_IN_MUX_0_AXIDMAC_TR_OUT3 = 0x00000014u, /* m55appcpuss.axidmac_tr_out[3] */
    PERI_0_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT0 = 0x00000015u, /* ioss.peri0_tr_io_input_in[0] */
    PERI_0_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT1 = 0x00000016u, /* ioss.peri0_tr_io_input_in[1] */
    PERI_0_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT2 = 0x00000017u, /* ioss.peri0_tr_io_input_in[2] */
    PERI_0_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT3 = 0x00000018u, /* ioss.peri0_tr_io_input_in[3] */
    PERI_0_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT4 = 0x00000019u, /* ioss.peri0_tr_io_input_in[4] */
    PERI_0_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT5 = 0x0000001Au, /* ioss.peri0_tr_io_input_in[5] */
    PERI_0_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT6 = 0x0000001Bu, /* ioss.peri0_tr_io_input_in[6] */
    PERI_0_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT7 = 0x0000001Cu, /* ioss.peri0_tr_io_input_in[7] */
    PERI_0_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT0 = 0x0000001Du, /* ioss.peri1_tr_io_input_in[0] */
    PERI_0_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT1 = 0x0000001Eu, /* ioss.peri1_tr_io_input_in[1] */
    PERI_0_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT2 = 0x0000001Fu, /* ioss.peri1_tr_io_input_in[2] */
    PERI_0_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT3 = 0x00000020u, /* ioss.peri1_tr_io_input_in[3] */
    PERI_0_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT4 = 0x00000021u, /* ioss.peri1_tr_io_input_in[4] */
    PERI_0_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT5 = 0x00000022u, /* ioss.peri1_tr_io_input_in[5] */
    PERI_0_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT6 = 0x00000023u, /* ioss.peri1_tr_io_input_in[6] */
    PERI_0_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT7 = 0x00000024u, /* ioss.peri1_tr_io_input_in[7] */
    PERI_0_TRIG_IN_MUX_0_DEBUG600_CTI_TR_OUT0 = 0x00000025u, /* debug600.cti_tr_out[0] */
    PERI_0_TRIG_IN_MUX_0_DEBUG600_CTI_TR_OUT1 = 0x00000026u, /* debug600.cti_tr_out[1] */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT0 = 0x00000027u, /* scb[0].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT1 = 0x00000028u, /* scb[1].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT2 = 0x00000029u, /* scb[2].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT3 = 0x0000002Au, /* scb[3].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT4 = 0x0000002Bu, /* scb[4].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT5 = 0x0000002Cu, /* scb[5].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT6 = 0x0000002Du, /* scb[6].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT7 = 0x0000002Eu, /* scb[7].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT8 = 0x0000002Fu, /* scb[8].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT9 = 0x00000030u, /* scb[9].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT10 = 0x00000031u, /* scb[10].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT11 = 0x00000032u, /* scb[11].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT0 = 0x00000033u, /* scb[0].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT1 = 0x00000034u, /* scb[1].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT2 = 0x00000035u, /* scb[2].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT3 = 0x00000036u, /* scb[3].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT4 = 0x00000037u, /* scb[4].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT5 = 0x00000038u, /* scb[5].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT6 = 0x00000039u, /* scb[6].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT7 = 0x0000003Au, /* scb[7].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT8 = 0x0000003Bu, /* scb[8].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT9 = 0x0000003Cu, /* scb[9].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT10 = 0x0000003Du, /* scb[10].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT11 = 0x0000003Eu, /* scb[11].tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT0 = 0x0000003Fu, /* scb[0].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT1 = 0x00000040u, /* scb[1].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT2 = 0x00000041u, /* scb[2].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT3 = 0x00000042u, /* scb[3].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT4 = 0x00000043u, /* scb[4].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT5 = 0x00000044u, /* scb[5].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT6 = 0x00000045u, /* scb[6].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT7 = 0x00000046u, /* scb[7].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT8 = 0x00000047u, /* scb[8].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT9 = 0x00000048u, /* scb[9].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT10 = 0x00000049u, /* scb[10].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SCB_RX_TR_OUT11 = 0x0000004Au, /* scb[11].tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_CAN0_TT_TR_OUT0 = 0x0000004Bu, /* canfd[0].tr_tmp_rtp_out[0] */
    PERI_0_TRIG_IN_MUX_0_CAN0_TT_TR_OUT1 = 0x0000004Cu, /* canfd[0].tr_tmp_rtp_out[1] */
    PERI_0_TRIG_IN_MUX_0_I2S_TDM_TX0 = 0x0000004Du, /* tdm.tr_tx_req[0] */
    PERI_0_TRIG_IN_MUX_0_I2S_TDM_RX0 = 0x0000004Eu, /* tdm.tr_rx_req[0] */
    PERI_0_TRIG_IN_MUX_0_I2S_TDM_TX1 = 0x0000004Fu, /* tdm.tr_tx_req[1] */
    PERI_0_TRIG_IN_MUX_0_I2S_TDM_RX1 = 0x00000050u, /* tdm.tr_rx_req[1] */
    PERI_0_TRIG_IN_MUX_0_SMIF0_TR_RX_REQ = 0x00000051u, /* smif[0].smif0_tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SMIF0_TR_TX_REQ = 0x00000052u, /* smif[0].smif0_tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_SMIF1_TR_RX_REQ = 0x00000053u, /* smif[1].smif0_tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_SMIF1_TR_TX_REQ = 0x00000054u, /* smif[1].smif0_tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_PDM_TX_RX_REQ0 = 0x00000055u, /* pdm.tr_rx_req[0] */
    PERI_0_TRIG_IN_MUX_0_PDM_TX_RX_REQ1 = 0x00000056u, /* pdm.tr_rx_req[1] */
    PERI_0_TRIG_IN_MUX_0_PDM_TX_RX_REQ2 = 0x00000057u, /* pdm.tr_rx_req[2] */
    PERI_0_TRIG_IN_MUX_0_PDM_TX_RX_REQ3 = 0x00000058u, /* pdm.tr_rx_req[3] */
    PERI_0_TRIG_IN_MUX_0_PDM_TX_RX_REQ4 = 0x00000059u, /* pdm.tr_rx_req[4] */
    PERI_0_TRIG_IN_MUX_0_PDM_TX_RX_REQ5 = 0x0000005Au, /* pdm.tr_rx_req[5] */
    PERI_0_TRIG_IN_MUX_0_PDM_RX_REQ_ALL = 0x0000005Bu, /* pdm.tr_rx_req_all */
    PERI_0_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT0 = 0x0000005Cu, /* pass.tr_lppass_out[0] */
    PERI_0_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT1 = 0x0000005Du, /* pass.tr_lppass_out[1] */
    PERI_0_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT2 = 0x0000005Eu, /* pass.tr_lppass_out[2] */
    PERI_0_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT3 = 0x0000005Fu, /* pass.tr_lppass_out[3] */
    PERI_0_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT4 = 0x00000060u, /* pass.tr_lppass_out[4] */
    PERI_0_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT5 = 0x00000061u, /* pass.tr_lppass_out[5] */
    PERI_0_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT6 = 0x00000062u, /* pass.tr_lppass_out[6] */
    PERI_0_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT7 = 0x00000063u, /* pass.tr_lppass_out[7] */
    PERI_0_TRIG_IN_MUX_0_I3C_TR_TX_REQ = 0x00000064u, /* i3c.tr_tx_req */
    PERI_0_TRIG_IN_MUX_0_I3C_TR_RX_REQ = 0x00000065u, /* i3c.tr_rx_req */
    PERI_0_TRIG_IN_MUX_0_MXNNLITE_TR_MXNNLITE = 0x00000066u, /* mxnnlite.tr_mxnnlite */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT00 = 0x00000067u, /* tcpwm[0].tr_out0[0] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT01 = 0x00000068u, /* tcpwm[0].tr_out0[1] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT02 = 0x00000069u, /* tcpwm[0].tr_out0[2] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT03 = 0x0000006Au, /* tcpwm[0].tr_out0[3] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT04 = 0x0000006Bu, /* tcpwm[0].tr_out0[4] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT05 = 0x0000006Cu, /* tcpwm[0].tr_out0[5] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT06 = 0x0000006Du, /* tcpwm[0].tr_out0[6] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT07 = 0x0000006Eu, /* tcpwm[0].tr_out0[7] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT10 = 0x0000006Fu, /* tcpwm[0].tr_out1[0] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT11 = 0x00000070u, /* tcpwm[0].tr_out1[1] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT12 = 0x00000071u, /* tcpwm[0].tr_out1[2] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT13 = 0x00000072u, /* tcpwm[0].tr_out1[3] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT14 = 0x00000073u, /* tcpwm[0].tr_out1[4] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT15 = 0x00000074u, /* tcpwm[0].tr_out1[5] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT16 = 0x00000075u, /* tcpwm[0].tr_out1[6] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT17 = 0x00000076u, /* tcpwm[0].tr_out1[7] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0256 = 0x00000077u, /* tcpwm[0].tr_out0[256] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0257 = 0x00000078u, /* tcpwm[0].tr_out0[257] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0258 = 0x00000079u, /* tcpwm[0].tr_out0[258] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0259 = 0x0000007Au, /* tcpwm[0].tr_out0[259] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0260 = 0x0000007Bu, /* tcpwm[0].tr_out0[260] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0261 = 0x0000007Cu, /* tcpwm[0].tr_out0[261] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0262 = 0x0000007Du, /* tcpwm[0].tr_out0[262] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0263 = 0x0000007Eu, /* tcpwm[0].tr_out0[263] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0264 = 0x0000007Fu, /* tcpwm[0].tr_out0[264] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0265 = 0x00000080u, /* tcpwm[0].tr_out0[265] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0266 = 0x00000081u, /* tcpwm[0].tr_out0[266] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0267 = 0x00000082u, /* tcpwm[0].tr_out0[267] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0268 = 0x00000083u, /* tcpwm[0].tr_out0[268] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0269 = 0x00000084u, /* tcpwm[0].tr_out0[269] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0270 = 0x00000085u, /* tcpwm[0].tr_out0[270] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0271 = 0x00000086u, /* tcpwm[0].tr_out0[271] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0272 = 0x00000087u, /* tcpwm[0].tr_out0[272] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0273 = 0x00000088u, /* tcpwm[0].tr_out0[273] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0274 = 0x00000089u, /* tcpwm[0].tr_out0[274] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0275 = 0x0000008Au, /* tcpwm[0].tr_out0[275] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0276 = 0x0000008Bu, /* tcpwm[0].tr_out0[276] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0277 = 0x0000008Cu, /* tcpwm[0].tr_out0[277] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0278 = 0x0000008Du, /* tcpwm[0].tr_out0[278] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0279 = 0x0000008Eu, /* tcpwm[0].tr_out0[279] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1256 = 0x0000008Fu, /* tcpwm[0].tr_out1[256] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1257 = 0x00000090u, /* tcpwm[0].tr_out1[257] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1258 = 0x00000091u, /* tcpwm[0].tr_out1[258] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1259 = 0x00000092u, /* tcpwm[0].tr_out1[259] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1260 = 0x00000093u, /* tcpwm[0].tr_out1[260] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1261 = 0x00000094u, /* tcpwm[0].tr_out1[261] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1262 = 0x00000095u, /* tcpwm[0].tr_out1[262] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1263 = 0x00000096u, /* tcpwm[0].tr_out1[263] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1264 = 0x00000097u, /* tcpwm[0].tr_out1[264] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1265 = 0x00000098u, /* tcpwm[0].tr_out1[265] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1266 = 0x00000099u, /* tcpwm[0].tr_out1[266] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1267 = 0x0000009Au, /* tcpwm[0].tr_out1[267] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1268 = 0x0000009Bu, /* tcpwm[0].tr_out1[268] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1269 = 0x0000009Cu, /* tcpwm[0].tr_out1[269] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1270 = 0x0000009Du, /* tcpwm[0].tr_out1[270] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1271 = 0x0000009Eu, /* tcpwm[0].tr_out1[271] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1272 = 0x0000009Fu, /* tcpwm[0].tr_out1[272] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1273 = 0x000000A0u, /* tcpwm[0].tr_out1[273] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1274 = 0x000000A1u, /* tcpwm[0].tr_out1[274] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1275 = 0x000000A2u, /* tcpwm[0].tr_out1[275] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1276 = 0x000000A3u, /* tcpwm[0].tr_out1[276] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1277 = 0x000000A4u, /* tcpwm[0].tr_out1[277] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1278 = 0x000000A5u, /* tcpwm[0].tr_out1[278] */
    PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT1279 = 0x000000A6u, /* tcpwm[0].tr_out1[279] */
    PERI_0_TRIG_IN_MUX_0_M33SYSCPUSS_TR_FAULT0 = 0x000000A7u, /* m33syscpuss.tr_fault[0] */
    PERI_0_TRIG_IN_MUX_0_M33SYSCPUSS_TR_FAULT1 = 0x000000A8u, /* m33syscpuss.tr_fault[1] */
    PERI_0_TRIG_IN_MUX_0_CAN0_FIFO0_TR_OUT0 = 0x000000A9u, /* canfd[0].tr_fifo0[0] */
    PERI_0_TRIG_IN_MUX_0_CAN0_FIFO1_TR_OUT0 = 0x000000AAu, /* canfd[0].tr_fifo1[0] */
    PERI_0_TRIG_IN_MUX_0_CAN0_FIFO0_TR_OUT1 = 0x000000ABu, /* canfd[0].tr_fifo0[1] */
    PERI_0_TRIG_IN_MUX_0_CAN0_FIFO1_TR_OUT1 = 0x000000ACu, /* canfd[0].tr_fifo1[1] */
    PERI_0_TRIG_IN_MUX_0_CAN0_DBG_TR_OUT0 = 0x000000ADu, /* canfd[0].tr_dbg_dma_req[0] */
    PERI_0_TRIG_IN_MUX_0_CAN0_DBG_TR_OUT1 = 0x000000AEu, /* canfd[0].tr_dbg_dma_req[1] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT0 = 0x000000AFu, /* m33syscpuss.dw1_tr_out[0] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT1 = 0x000000B0u, /* m33syscpuss.dw1_tr_out[1] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT2 = 0x000000B1u, /* m33syscpuss.dw1_tr_out[2] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT3 = 0x000000B2u, /* m33syscpuss.dw1_tr_out[3] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT4 = 0x000000B3u, /* m33syscpuss.dw1_tr_out[4] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT5 = 0x000000B4u, /* m33syscpuss.dw1_tr_out[5] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT6 = 0x000000B5u, /* m33syscpuss.dw1_tr_out[6] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT7 = 0x000000B6u, /* m33syscpuss.dw1_tr_out[7] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT8 = 0x000000B7u, /* m33syscpuss.dw1_tr_out[8] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT9 = 0x000000B8u, /* m33syscpuss.dw1_tr_out[9] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT10 = 0x000000B9u, /* m33syscpuss.dw1_tr_out[10] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT11 = 0x000000BAu, /* m33syscpuss.dw1_tr_out[11] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT12 = 0x000000BBu, /* m33syscpuss.dw1_tr_out[12] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT13 = 0x000000BCu, /* m33syscpuss.dw1_tr_out[13] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT14 = 0x000000BDu, /* m33syscpuss.dw1_tr_out[14] */
    PERI_0_TRIG_IN_MUX_0_PDMA1_TR_OUT15 = 0x000000BEu /* m33syscpuss.dw1_tr_out[15] */
} en_peri0_trig_input_pdma0_tr_t;

/* Peri 0 Trigger Input Group 1 - CAN TT Synchronization triggers */
typedef enum
{
    PERI_0_TRIG_IN_MUX_1_CAN0_TT_TR_OUT0 = 0x00000101u, /* canfd[0].tr_tmp_rtp_out[0] */
    PERI_0_TRIG_IN_MUX_1_CAN0_TT_TR_OUT1 = 0x00000102u /* canfd[0].tr_tmp_rtp_out[1] */
} en_peri0_trig_input_can_t;

/* Peri 0 Trigger Input Group 2 -  */
typedef enum
{
    PERI_0_TRIG_IN_MUX_2_CAN0_DBG_TR_OUT0 = 0x00000201u, /* canfd[0].tr_dbg_dma_req[0] */
    PERI_0_TRIG_IN_MUX_2_CAN0_FIFO0_TR_OUT0 = 0x00000202u, /* canfd[0].tr_fifo0[0] */
    PERI_0_TRIG_IN_MUX_2_CAN0_FIFO1_TR_OUT0 = 0x00000203u, /* canfd[0].tr_fifo1[0] */
    PERI_0_TRIG_IN_MUX_2_CAN0_DBG_TR_OUT1 = 0x00000204u, /* canfd[0].tr_dbg_dma_req[1] */
    PERI_0_TRIG_IN_MUX_2_CAN0_FIFO0_TR_OUT1 = 0x00000205u, /* canfd[0].tr_fifo0[1] */
    PERI_0_TRIG_IN_MUX_2_CAN0_FIFO1_TR_OUT1 = 0x00000206u, /* canfd[0].tr_fifo1[1] */
    PERI_0_TRIG_IN_MUX_2_CAN0_TT_TR_OUT0 = 0x00000207u, /* canfd[0].tr_tmp_rtp_out[0] */
    PERI_0_TRIG_IN_MUX_2_CAN0_TT_TR_OUT1 = 0x00000208u, /* canfd[0].tr_tmp_rtp_out[1] */
    PERI_0_TRIG_IN_MUX_2_LPCOMP_DSI_COMP0 = 0x00000209u, /* lpcomp.dsi_comp0 */
    PERI_0_TRIG_IN_MUX_2_LPCOMP_DSI_COMP1 = 0x0000020Au, /* lpcomp.dsi_comp1 */
    PERI_0_TRIG_IN_MUX_2_I2S_TDM_TX0 = 0x0000020Bu, /* tdm.tr_tx_req[0] */
    PERI_0_TRIG_IN_MUX_2_I2S_TDM_RX0 = 0x0000020Cu, /* tdm.tr_rx_req[0] */
    PERI_0_TRIG_IN_MUX_2_I2S_TDM_TX1 = 0x0000020Du, /* tdm.tr_tx_req[1] */
    PERI_0_TRIG_IN_MUX_2_I2S_TDM_RX1 = 0x0000020Eu, /* tdm.tr_rx_req[1] */
    PERI_0_TRIG_IN_MUX_2_SMIF0_TR_RX_REQ = 0x0000020Fu, /* smif[0].smif0_tr_rx_req */
    PERI_0_TRIG_IN_MUX_2_SMIF0_TR_TX_REQ = 0x00000210u, /* smif[0].smif0_tr_tx_req */
    PERI_0_TRIG_IN_MUX_2_SMIF1_TR_RX_REQ = 0x00000211u, /* smif[1].smif0_tr_rx_req */
    PERI_0_TRIG_IN_MUX_2_SMIF1_TR_TX_REQ = 0x00000212u, /* smif[1].smif0_tr_tx_req */
    PERI_0_TRIG_IN_MUX_2_PDM_TX_RX_REQ0 = 0x00000213u, /* pdm.tr_rx_req[0] */
    PERI_0_TRIG_IN_MUX_2_PDM_TX_RX_REQ1 = 0x00000214u, /* pdm.tr_rx_req[1] */
    PERI_0_TRIG_IN_MUX_2_PDM_TX_RX_REQ2 = 0x00000215u, /* pdm.tr_rx_req[2] */
    PERI_0_TRIG_IN_MUX_2_PDM_TX_RX_REQ3 = 0x00000216u, /* pdm.tr_rx_req[3] */
    PERI_0_TRIG_IN_MUX_2_PDM_TX_RX_REQ4 = 0x00000217u, /* pdm.tr_rx_req[4] */
    PERI_0_TRIG_IN_MUX_2_PDM_TX_RX_REQ5 = 0x00000218u, /* pdm.tr_rx_req[5] */
    PERI_0_TRIG_IN_MUX_2_PDM_RX_REQ_ALL = 0x00000219u, /* pdm.tr_rx_req_all */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT00 = 0x0000021Au, /* tcpwm[0].tr_out0[0] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT01 = 0x0000021Bu, /* tcpwm[0].tr_out0[1] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT02 = 0x0000021Cu, /* tcpwm[0].tr_out0[2] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT03 = 0x0000021Du, /* tcpwm[0].tr_out0[3] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT04 = 0x0000021Eu, /* tcpwm[0].tr_out0[4] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT05 = 0x0000021Fu, /* tcpwm[0].tr_out0[5] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT06 = 0x00000220u, /* tcpwm[0].tr_out0[6] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT07 = 0x00000221u, /* tcpwm[0].tr_out0[7] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT10 = 0x00000222u, /* tcpwm[0].tr_out1[0] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT11 = 0x00000223u, /* tcpwm[0].tr_out1[1] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT12 = 0x00000224u, /* tcpwm[0].tr_out1[2] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT13 = 0x00000225u, /* tcpwm[0].tr_out1[3] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT14 = 0x00000226u, /* tcpwm[0].tr_out1[4] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT15 = 0x00000227u, /* tcpwm[0].tr_out1[5] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT16 = 0x00000228u, /* tcpwm[0].tr_out1[6] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT17 = 0x00000229u, /* tcpwm[0].tr_out1[7] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0256 = 0x0000022Au, /* tcpwm[0].tr_out0[256] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0257 = 0x0000022Bu, /* tcpwm[0].tr_out0[257] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0258 = 0x0000022Cu, /* tcpwm[0].tr_out0[258] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0259 = 0x0000022Du, /* tcpwm[0].tr_out0[259] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0260 = 0x0000022Eu, /* tcpwm[0].tr_out0[260] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0261 = 0x0000022Fu, /* tcpwm[0].tr_out0[261] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0262 = 0x00000230u, /* tcpwm[0].tr_out0[262] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0263 = 0x00000231u, /* tcpwm[0].tr_out0[263] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0264 = 0x00000232u, /* tcpwm[0].tr_out0[264] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0265 = 0x00000233u, /* tcpwm[0].tr_out0[265] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0266 = 0x00000234u, /* tcpwm[0].tr_out0[266] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0267 = 0x00000235u, /* tcpwm[0].tr_out0[267] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0268 = 0x00000236u, /* tcpwm[0].tr_out0[268] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0269 = 0x00000237u, /* tcpwm[0].tr_out0[269] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0270 = 0x00000238u, /* tcpwm[0].tr_out0[270] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0271 = 0x00000239u, /* tcpwm[0].tr_out0[271] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0272 = 0x0000023Au, /* tcpwm[0].tr_out0[272] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0273 = 0x0000023Bu, /* tcpwm[0].tr_out0[273] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0274 = 0x0000023Cu, /* tcpwm[0].tr_out0[274] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0275 = 0x0000023Du, /* tcpwm[0].tr_out0[275] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0276 = 0x0000023Eu, /* tcpwm[0].tr_out0[276] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0277 = 0x0000023Fu, /* tcpwm[0].tr_out0[277] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0278 = 0x00000240u, /* tcpwm[0].tr_out0[278] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT0279 = 0x00000241u, /* tcpwm[0].tr_out0[279] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1256 = 0x00000242u, /* tcpwm[0].tr_out1[256] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1257 = 0x00000243u, /* tcpwm[0].tr_out1[257] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1258 = 0x00000244u, /* tcpwm[0].tr_out1[258] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1259 = 0x00000245u, /* tcpwm[0].tr_out1[259] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1260 = 0x00000246u, /* tcpwm[0].tr_out1[260] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1261 = 0x00000247u, /* tcpwm[0].tr_out1[261] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1262 = 0x00000248u, /* tcpwm[0].tr_out1[262] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1263 = 0x00000249u, /* tcpwm[0].tr_out1[263] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1264 = 0x0000024Au, /* tcpwm[0].tr_out1[264] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1265 = 0x0000024Bu, /* tcpwm[0].tr_out1[265] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1266 = 0x0000024Cu, /* tcpwm[0].tr_out1[266] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1267 = 0x0000024Du, /* tcpwm[0].tr_out1[267] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1268 = 0x0000024Eu, /* tcpwm[0].tr_out1[268] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1269 = 0x0000024Fu, /* tcpwm[0].tr_out1[269] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1270 = 0x00000250u, /* tcpwm[0].tr_out1[270] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1271 = 0x00000251u, /* tcpwm[0].tr_out1[271] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1272 = 0x00000252u, /* tcpwm[0].tr_out1[272] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1273 = 0x00000253u, /* tcpwm[0].tr_out1[273] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1274 = 0x00000254u, /* tcpwm[0].tr_out1[274] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1275 = 0x00000255u, /* tcpwm[0].tr_out1[275] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1276 = 0x00000256u, /* tcpwm[0].tr_out1[276] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1277 = 0x00000257u, /* tcpwm[0].tr_out1[277] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1278 = 0x00000258u, /* tcpwm[0].tr_out1[278] */
    PERI_0_TRIG_IN_MUX_2_TCPWM0_TR_OUT1279 = 0x00000259u, /* tcpwm[0].tr_out1[279] */
    PERI_0_TRIG_IN_MUX_2_M33SYSCPUSS_TR_FAULT0 = 0x0000025Au, /* m33syscpuss.tr_fault[0] */
    PERI_0_TRIG_IN_MUX_2_M33SYSCPUSS_TR_FAULT1 = 0x0000025Bu, /* m33syscpuss.tr_fault[1] */
    PERI_0_TRIG_IN_MUX_2_PERI0_HSIOM_TR_OUT0 = 0x0000025Cu, /* ioss.peri0_tr_io_input_in[0] */
    PERI_0_TRIG_IN_MUX_2_PERI0_HSIOM_TR_OUT1 = 0x0000025Du, /* ioss.peri0_tr_io_input_in[1] */
    PERI_0_TRIG_IN_MUX_2_PERI0_HSIOM_TR_OUT2 = 0x0000025Eu, /* ioss.peri0_tr_io_input_in[2] */
    PERI_0_TRIG_IN_MUX_2_PERI0_HSIOM_TR_OUT3 = 0x0000025Fu, /* ioss.peri0_tr_io_input_in[3] */
    PERI_0_TRIG_IN_MUX_2_PERI0_HSIOM_TR_OUT4 = 0x00000260u, /* ioss.peri0_tr_io_input_in[4] */
    PERI_0_TRIG_IN_MUX_2_PERI0_HSIOM_TR_OUT5 = 0x00000261u, /* ioss.peri0_tr_io_input_in[5] */
    PERI_0_TRIG_IN_MUX_2_PERI0_HSIOM_TR_OUT6 = 0x00000262u, /* ioss.peri0_tr_io_input_in[6] */
    PERI_0_TRIG_IN_MUX_2_PERI0_HSIOM_TR_OUT7 = 0x00000263u, /* ioss.peri0_tr_io_input_in[7] */
    PERI_0_TRIG_IN_MUX_2_PERI1_HSIOM_TR_OUT0 = 0x00000264u, /* ioss.peri1_tr_io_input_in[0] */
    PERI_0_TRIG_IN_MUX_2_PERI1_HSIOM_TR_OUT1 = 0x00000265u, /* ioss.peri1_tr_io_input_in[1] */
    PERI_0_TRIG_IN_MUX_2_PERI1_HSIOM_TR_OUT2 = 0x00000266u, /* ioss.peri1_tr_io_input_in[2] */
    PERI_0_TRIG_IN_MUX_2_PERI1_HSIOM_TR_OUT3 = 0x00000267u, /* ioss.peri1_tr_io_input_in[3] */
    PERI_0_TRIG_IN_MUX_2_PERI1_HSIOM_TR_OUT4 = 0x00000268u, /* ioss.peri1_tr_io_input_in[4] */
    PERI_0_TRIG_IN_MUX_2_PERI1_HSIOM_TR_OUT5 = 0x00000269u, /* ioss.peri1_tr_io_input_in[5] */
    PERI_0_TRIG_IN_MUX_2_PERI1_HSIOM_TR_OUT6 = 0x0000026Au, /* ioss.peri1_tr_io_input_in[6] */
    PERI_0_TRIG_IN_MUX_2_PERI1_HSIOM_TR_OUT7 = 0x0000026Bu, /* ioss.peri1_tr_io_input_in[7] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT0 = 0x0000026Cu, /* m33syscpuss.dw0_tr_out[0] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT1 = 0x0000026Du, /* m33syscpuss.dw0_tr_out[1] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT2 = 0x0000026Eu, /* m33syscpuss.dw0_tr_out[2] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT3 = 0x0000026Fu, /* m33syscpuss.dw0_tr_out[3] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT4 = 0x00000270u, /* m33syscpuss.dw0_tr_out[4] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT5 = 0x00000271u, /* m33syscpuss.dw0_tr_out[5] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT6 = 0x00000272u, /* m33syscpuss.dw0_tr_out[6] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT7 = 0x00000273u, /* m33syscpuss.dw0_tr_out[7] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT8 = 0x00000274u, /* m33syscpuss.dw0_tr_out[8] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT9 = 0x00000275u, /* m33syscpuss.dw0_tr_out[9] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT10 = 0x00000276u, /* m33syscpuss.dw0_tr_out[10] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT11 = 0x00000277u, /* m33syscpuss.dw0_tr_out[11] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT12 = 0x00000278u, /* m33syscpuss.dw0_tr_out[12] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT13 = 0x00000279u, /* m33syscpuss.dw0_tr_out[13] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT14 = 0x0000027Au, /* m33syscpuss.dw0_tr_out[14] */
    PERI_0_TRIG_IN_MUX_2_PDMA0_TR_OUT15 = 0x0000027Bu, /* m33syscpuss.dw0_tr_out[15] */
    PERI_0_TRIG_IN_MUX_2_AXIDMAC_TR_OUT0 = 0x0000027Cu, /* m55appcpuss.axidmac_tr_out[0] */
    PERI_0_TRIG_IN_MUX_2_AXIDMAC_TR_OUT1 = 0x0000027Du, /* m55appcpuss.axidmac_tr_out[1] */
    PERI_0_TRIG_IN_MUX_2_AXIDMAC_TR_OUT2 = 0x0000027Eu, /* m55appcpuss.axidmac_tr_out[2] */
    PERI_0_TRIG_IN_MUX_2_AXIDMAC_TR_OUT3 = 0x0000027Fu, /* m55appcpuss.axidmac_tr_out[3] */
    PERI_0_TRIG_IN_MUX_2_PASS_TR_LPPASS_OUT0 = 0x00000280u, /* pass.tr_lppass_out[0] */
    PERI_0_TRIG_IN_MUX_2_PASS_TR_LPPASS_OUT1 = 0x00000281u, /* pass.tr_lppass_out[1] */
    PERI_0_TRIG_IN_MUX_2_PASS_TR_LPPASS_OUT2 = 0x00000282u, /* pass.tr_lppass_out[2] */
    PERI_0_TRIG_IN_MUX_2_PASS_TR_LPPASS_OUT3 = 0x00000283u, /* pass.tr_lppass_out[3] */
    PERI_0_TRIG_IN_MUX_2_PASS_TR_LPPASS_OUT4 = 0x00000284u, /* pass.tr_lppass_out[4] */
    PERI_0_TRIG_IN_MUX_2_PASS_TR_LPPASS_OUT5 = 0x00000285u, /* pass.tr_lppass_out[5] */
    PERI_0_TRIG_IN_MUX_2_PASS_TR_LPPASS_OUT6 = 0x00000286u, /* pass.tr_lppass_out[6] */
    PERI_0_TRIG_IN_MUX_2_PASS_TR_LPPASS_OUT7 = 0x00000287u, /* pass.tr_lppass_out[7] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT0 = 0x00000288u, /* m33syscpuss.dw1_tr_out[0] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT1 = 0x00000289u, /* m33syscpuss.dw1_tr_out[1] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT2 = 0x0000028Au, /* m33syscpuss.dw1_tr_out[2] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT3 = 0x0000028Bu, /* m33syscpuss.dw1_tr_out[3] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT4 = 0x0000028Cu, /* m33syscpuss.dw1_tr_out[4] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT5 = 0x0000028Du, /* m33syscpuss.dw1_tr_out[5] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT6 = 0x0000028Eu, /* m33syscpuss.dw1_tr_out[6] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT7 = 0x0000028Fu, /* m33syscpuss.dw1_tr_out[7] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT8 = 0x00000290u, /* m33syscpuss.dw1_tr_out[8] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT9 = 0x00000291u, /* m33syscpuss.dw1_tr_out[9] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT10 = 0x00000292u, /* m33syscpuss.dw1_tr_out[10] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT11 = 0x00000293u, /* m33syscpuss.dw1_tr_out[11] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT12 = 0x00000294u, /* m33syscpuss.dw1_tr_out[12] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT13 = 0x00000295u, /* m33syscpuss.dw1_tr_out[13] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT14 = 0x00000296u, /* m33syscpuss.dw1_tr_out[14] */
    PERI_0_TRIG_IN_MUX_2_PDMA1_TR_OUT15 = 0x00000297u /* m33syscpuss.dw1_tr_out[15] */
} en_peri0_trig_input_tcpwm0_20_31_t;

/* Peri 0 Trigger Input Group 3 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT0 = 0x00000301u, /* m33syscpuss.dw0_tr_out[0] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT1 = 0x00000302u, /* m33syscpuss.dw0_tr_out[1] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT2 = 0x00000303u, /* m33syscpuss.dw0_tr_out[2] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT3 = 0x00000304u, /* m33syscpuss.dw0_tr_out[3] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT4 = 0x00000305u, /* m33syscpuss.dw0_tr_out[4] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT5 = 0x00000306u, /* m33syscpuss.dw0_tr_out[5] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT6 = 0x00000307u, /* m33syscpuss.dw0_tr_out[6] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT7 = 0x00000308u, /* m33syscpuss.dw0_tr_out[7] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT8 = 0x00000309u, /* m33syscpuss.dw0_tr_out[8] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT9 = 0x0000030Au, /* m33syscpuss.dw0_tr_out[9] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT10 = 0x0000030Bu, /* m33syscpuss.dw0_tr_out[10] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT11 = 0x0000030Cu, /* m33syscpuss.dw0_tr_out[11] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT12 = 0x0000030Du, /* m33syscpuss.dw0_tr_out[12] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT13 = 0x0000030Eu, /* m33syscpuss.dw0_tr_out[13] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT14 = 0x0000030Fu, /* m33syscpuss.dw0_tr_out[14] */
    PERI_0_TRIG_IN_MUX_3_PDMA0_TR_OUT15 = 0x00000310u, /* m33syscpuss.dw0_tr_out[15] */
    PERI_0_TRIG_IN_MUX_3_AXIDMAC_TR_OUT0 = 0x00000311u, /* m55appcpuss.axidmac_tr_out[0] */
    PERI_0_TRIG_IN_MUX_3_AXIDMAC_TR_OUT1 = 0x00000312u, /* m55appcpuss.axidmac_tr_out[1] */
    PERI_0_TRIG_IN_MUX_3_AXIDMAC_TR_OUT2 = 0x00000313u, /* m55appcpuss.axidmac_tr_out[2] */
    PERI_0_TRIG_IN_MUX_3_AXIDMAC_TR_OUT3 = 0x00000314u, /* m55appcpuss.axidmac_tr_out[3] */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT0 = 0x00000315u, /* scb[0].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT1 = 0x00000316u, /* scb[1].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT2 = 0x00000317u, /* scb[2].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT3 = 0x00000318u, /* scb[3].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT4 = 0x00000319u, /* scb[4].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT5 = 0x0000031Au, /* scb[5].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT6 = 0x0000031Bu, /* scb[6].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT7 = 0x0000031Cu, /* scb[7].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT8 = 0x0000031Du, /* scb[8].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT9 = 0x0000031Eu, /* scb[9].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT10 = 0x0000031Fu, /* scb[10].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_TX_TR_OUT11 = 0x00000320u, /* scb[11].tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT0 = 0x00000321u, /* scb[0].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT1 = 0x00000322u, /* scb[1].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT2 = 0x00000323u, /* scb[2].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT3 = 0x00000324u, /* scb[3].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT4 = 0x00000325u, /* scb[4].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT5 = 0x00000326u, /* scb[5].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT6 = 0x00000327u, /* scb[6].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT7 = 0x00000328u, /* scb[7].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT8 = 0x00000329u, /* scb[8].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT9 = 0x0000032Au, /* scb[9].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT10 = 0x0000032Bu, /* scb[10].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_RX_TR_OUT11 = 0x0000032Cu, /* scb[11].tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT0 = 0x0000032Du, /* scb[0].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT1 = 0x0000032Eu, /* scb[1].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT2 = 0x0000032Fu, /* scb[2].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT3 = 0x00000330u, /* scb[3].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT4 = 0x00000331u, /* scb[4].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT5 = 0x00000332u, /* scb[5].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT6 = 0x00000333u, /* scb[6].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT7 = 0x00000334u, /* scb[7].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT8 = 0x00000335u, /* scb[8].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT9 = 0x00000336u, /* scb[9].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT10 = 0x00000337u, /* scb[10].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_SCB_I2C_SCL_TR_OUT11 = 0x00000338u, /* scb[11].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_3_CAN0_DBG_TR_OUT0 = 0x00000339u, /* canfd[0].tr_dbg_dma_req[0] */
    PERI_0_TRIG_IN_MUX_3_CAN0_FIFO0_TR_OUT0 = 0x0000033Au, /* canfd[0].tr_fifo0[0] */
    PERI_0_TRIG_IN_MUX_3_CAN0_FIFO1_TR_OUT0 = 0x0000033Bu, /* canfd[0].tr_fifo1[0] */
    PERI_0_TRIG_IN_MUX_3_CAN0_TT_TR_OUT0 = 0x0000033Cu, /* canfd[0].tr_tmp_rtp_out[0] */
    PERI_0_TRIG_IN_MUX_3_CAN0_DBG_TR_OUT1 = 0x0000033Du, /* canfd[0].tr_dbg_dma_req[1] */
    PERI_0_TRIG_IN_MUX_3_CAN0_FIFO0_TR_OUT1 = 0x0000033Eu, /* canfd[0].tr_fifo0[1] */
    PERI_0_TRIG_IN_MUX_3_CAN0_FIFO1_TR_OUT1 = 0x0000033Fu, /* canfd[0].tr_fifo1[1] */
    PERI_0_TRIG_IN_MUX_3_CAN0_TT_TR_OUT1 = 0x00000340u, /* canfd[0].tr_tmp_rtp_out[1] */
    PERI_0_TRIG_IN_MUX_3_DEBUG600_CTI_TR_OUT0 = 0x00000341u, /* debug600.cti_tr_out[0] */
    PERI_0_TRIG_IN_MUX_3_DEBUG600_CTI_TR_OUT1 = 0x00000342u, /* debug600.cti_tr_out[1] */
    PERI_0_TRIG_IN_MUX_3_I2S_TDM_TX0 = 0x00000343u, /* tdm.tr_tx_req[0] */
    PERI_0_TRIG_IN_MUX_3_I2S_TDM_RX0 = 0x00000344u, /* tdm.tr_rx_req[0] */
    PERI_0_TRIG_IN_MUX_3_I2S_TDM_TX1 = 0x00000345u, /* tdm.tr_tx_req[1] */
    PERI_0_TRIG_IN_MUX_3_I2S_TDM_RX1 = 0x00000346u, /* tdm.tr_rx_req[1] */
    PERI_0_TRIG_IN_MUX_3_SMIF0_TR_RX_REQ = 0x00000347u, /* smif[0].smif0_tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SMIF0_TR_TX_REQ = 0x00000348u, /* smif[0].smif0_tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_SMIF1_TR_RX_REQ = 0x00000349u, /* smif[1].smif0_tr_rx_req */
    PERI_0_TRIG_IN_MUX_3_SMIF1_TR_TX_REQ = 0x0000034Au, /* smif[1].smif0_tr_tx_req */
    PERI_0_TRIG_IN_MUX_3_PDM_TX_RX_REQ0 = 0x0000034Bu, /* pdm.tr_rx_req[0] */
    PERI_0_TRIG_IN_MUX_3_PDM_TX_RX_REQ1 = 0x0000034Cu, /* pdm.tr_rx_req[1] */
    PERI_0_TRIG_IN_MUX_3_PDM_TX_RX_REQ2 = 0x0000034Du, /* pdm.tr_rx_req[2] */
    PERI_0_TRIG_IN_MUX_3_PDM_TX_RX_REQ3 = 0x0000034Eu, /* pdm.tr_rx_req[3] */
    PERI_0_TRIG_IN_MUX_3_PDM_TX_RX_REQ4 = 0x0000034Fu, /* pdm.tr_rx_req[4] */
    PERI_0_TRIG_IN_MUX_3_PDM_TX_RX_REQ5 = 0x00000350u, /* pdm.tr_rx_req[5] */
    PERI_0_TRIG_IN_MUX_3_PDM_RX_REQ_ALL = 0x00000351u, /* pdm.tr_rx_req_all */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT00 = 0x00000352u, /* tcpwm[0].tr_out0[0] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT01 = 0x00000353u, /* tcpwm[0].tr_out0[1] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT02 = 0x00000354u, /* tcpwm[0].tr_out0[2] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT03 = 0x00000355u, /* tcpwm[0].tr_out0[3] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT04 = 0x00000356u, /* tcpwm[0].tr_out0[4] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT05 = 0x00000357u, /* tcpwm[0].tr_out0[5] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT06 = 0x00000358u, /* tcpwm[0].tr_out0[6] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT07 = 0x00000359u, /* tcpwm[0].tr_out0[7] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT10 = 0x0000035Au, /* tcpwm[0].tr_out1[0] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT11 = 0x0000035Bu, /* tcpwm[0].tr_out1[1] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT12 = 0x0000035Cu, /* tcpwm[0].tr_out1[2] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT13 = 0x0000035Du, /* tcpwm[0].tr_out1[3] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT14 = 0x0000035Eu, /* tcpwm[0].tr_out1[4] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT15 = 0x0000035Fu, /* tcpwm[0].tr_out1[5] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT16 = 0x00000360u, /* tcpwm[0].tr_out1[6] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT17 = 0x00000361u, /* tcpwm[0].tr_out1[7] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0256 = 0x00000362u, /* tcpwm[0].tr_out0[256] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0257 = 0x00000363u, /* tcpwm[0].tr_out0[257] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0258 = 0x00000364u, /* tcpwm[0].tr_out0[258] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0259 = 0x00000365u, /* tcpwm[0].tr_out0[259] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0260 = 0x00000366u, /* tcpwm[0].tr_out0[260] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0261 = 0x00000367u, /* tcpwm[0].tr_out0[261] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0262 = 0x00000368u, /* tcpwm[0].tr_out0[262] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0263 = 0x00000369u, /* tcpwm[0].tr_out0[263] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0264 = 0x0000036Au, /* tcpwm[0].tr_out0[264] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0265 = 0x0000036Bu, /* tcpwm[0].tr_out0[265] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0266 = 0x0000036Cu, /* tcpwm[0].tr_out0[266] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0267 = 0x0000036Du, /* tcpwm[0].tr_out0[267] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0268 = 0x0000036Eu, /* tcpwm[0].tr_out0[268] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0269 = 0x0000036Fu, /* tcpwm[0].tr_out0[269] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0270 = 0x00000370u, /* tcpwm[0].tr_out0[270] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0271 = 0x00000371u, /* tcpwm[0].tr_out0[271] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0272 = 0x00000372u, /* tcpwm[0].tr_out0[272] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0273 = 0x00000373u, /* tcpwm[0].tr_out0[273] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0274 = 0x00000374u, /* tcpwm[0].tr_out0[274] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0275 = 0x00000375u, /* tcpwm[0].tr_out0[275] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0276 = 0x00000376u, /* tcpwm[0].tr_out0[276] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0277 = 0x00000377u, /* tcpwm[0].tr_out0[277] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0278 = 0x00000378u, /* tcpwm[0].tr_out0[278] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT0279 = 0x00000379u, /* tcpwm[0].tr_out0[279] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1256 = 0x0000037Au, /* tcpwm[0].tr_out1[256] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1257 = 0x0000037Bu, /* tcpwm[0].tr_out1[257] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1258 = 0x0000037Cu, /* tcpwm[0].tr_out1[258] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1259 = 0x0000037Du, /* tcpwm[0].tr_out1[259] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1260 = 0x0000037Eu, /* tcpwm[0].tr_out1[260] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1261 = 0x0000037Fu, /* tcpwm[0].tr_out1[261] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1262 = 0x00000380u, /* tcpwm[0].tr_out1[262] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1263 = 0x00000381u, /* tcpwm[0].tr_out1[263] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1264 = 0x00000382u, /* tcpwm[0].tr_out1[264] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1265 = 0x00000383u, /* tcpwm[0].tr_out1[265] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1266 = 0x00000384u, /* tcpwm[0].tr_out1[266] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1267 = 0x00000385u, /* tcpwm[0].tr_out1[267] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1268 = 0x00000386u, /* tcpwm[0].tr_out1[268] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1269 = 0x00000387u, /* tcpwm[0].tr_out1[269] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1270 = 0x00000388u, /* tcpwm[0].tr_out1[270] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1271 = 0x00000389u, /* tcpwm[0].tr_out1[271] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1272 = 0x0000038Au, /* tcpwm[0].tr_out1[272] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1273 = 0x0000038Bu, /* tcpwm[0].tr_out1[273] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1274 = 0x0000038Cu, /* tcpwm[0].tr_out1[274] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1275 = 0x0000038Du, /* tcpwm[0].tr_out1[275] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1276 = 0x0000038Eu, /* tcpwm[0].tr_out1[276] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1277 = 0x0000038Fu, /* tcpwm[0].tr_out1[277] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1278 = 0x00000390u, /* tcpwm[0].tr_out1[278] */
    PERI_0_TRIG_IN_MUX_3_TCPWM0_TR_OUT1279 = 0x00000391u, /* tcpwm[0].tr_out1[279] */
    PERI_0_TRIG_IN_MUX_3_M33SYSCPUSS_TR_FAULT0 = 0x00000392u, /* m33syscpuss.tr_fault[0] */
    PERI_0_TRIG_IN_MUX_3_M33SYSCPUSS_TR_FAULT1 = 0x00000393u, /* m33syscpuss.tr_fault[1] */
    PERI_0_TRIG_IN_MUX_3_PERI0_HSIOM_TR_OUT0 = 0x00000394u, /* ioss.peri0_tr_io_input_in[0] */
    PERI_0_TRIG_IN_MUX_3_PERI0_HSIOM_TR_OUT1 = 0x00000395u, /* ioss.peri0_tr_io_input_in[1] */
    PERI_0_TRIG_IN_MUX_3_PERI0_HSIOM_TR_OUT2 = 0x00000396u, /* ioss.peri0_tr_io_input_in[2] */
    PERI_0_TRIG_IN_MUX_3_PERI0_HSIOM_TR_OUT3 = 0x00000397u, /* ioss.peri0_tr_io_input_in[3] */
    PERI_0_TRIG_IN_MUX_3_PERI0_HSIOM_TR_OUT4 = 0x00000398u, /* ioss.peri0_tr_io_input_in[4] */
    PERI_0_TRIG_IN_MUX_3_PERI0_HSIOM_TR_OUT5 = 0x00000399u, /* ioss.peri0_tr_io_input_in[5] */
    PERI_0_TRIG_IN_MUX_3_PERI0_HSIOM_TR_OUT6 = 0x0000039Au, /* ioss.peri0_tr_io_input_in[6] */
    PERI_0_TRIG_IN_MUX_3_PERI0_HSIOM_TR_OUT7 = 0x0000039Bu, /* ioss.peri0_tr_io_input_in[7] */
    PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT0 = 0x0000039Cu, /* ioss.peri1_tr_io_input_in[0] */
    PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT1 = 0x0000039Du, /* ioss.peri1_tr_io_input_in[1] */
    PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT2 = 0x0000039Eu, /* ioss.peri1_tr_io_input_in[2] */
    PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT3 = 0x0000039Fu, /* ioss.peri1_tr_io_input_in[3] */
    PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT4 = 0x000003A0u, /* ioss.peri1_tr_io_input_in[4] */
    PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT5 = 0x000003A1u, /* ioss.peri1_tr_io_input_in[5] */
    PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT6 = 0x000003A2u, /* ioss.peri1_tr_io_input_in[6] */
    PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT7 = 0x000003A3u, /* ioss.peri1_tr_io_input_in[7] */
    PERI_0_TRIG_IN_MUX_3_PASS_TR_LPPASS_OUT0 = 0x000003A4u, /* pass.tr_lppass_out[0] */
    PERI_0_TRIG_IN_MUX_3_PASS_TR_LPPASS_OUT1 = 0x000003A5u, /* pass.tr_lppass_out[1] */
    PERI_0_TRIG_IN_MUX_3_PASS_TR_LPPASS_OUT2 = 0x000003A6u, /* pass.tr_lppass_out[2] */
    PERI_0_TRIG_IN_MUX_3_PASS_TR_LPPASS_OUT3 = 0x000003A7u, /* pass.tr_lppass_out[3] */
    PERI_0_TRIG_IN_MUX_3_PASS_TR_LPPASS_OUT4 = 0x000003A8u, /* pass.tr_lppass_out[4] */
    PERI_0_TRIG_IN_MUX_3_PASS_TR_LPPASS_OUT5 = 0x000003A9u, /* pass.tr_lppass_out[5] */
    PERI_0_TRIG_IN_MUX_3_PASS_TR_LPPASS_OUT6 = 0x000003AAu, /* pass.tr_lppass_out[6] */
    PERI_0_TRIG_IN_MUX_3_PASS_TR_LPPASS_OUT7 = 0x000003ABu, /* pass.tr_lppass_out[7] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT0 = 0x000003ACu, /* m33syscpuss.dw1_tr_out[0] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT1 = 0x000003ADu, /* m33syscpuss.dw1_tr_out[1] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT2 = 0x000003AEu, /* m33syscpuss.dw1_tr_out[2] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT3 = 0x000003AFu, /* m33syscpuss.dw1_tr_out[3] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT4 = 0x000003B0u, /* m33syscpuss.dw1_tr_out[4] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT5 = 0x000003B1u, /* m33syscpuss.dw1_tr_out[5] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT6 = 0x000003B2u, /* m33syscpuss.dw1_tr_out[6] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT7 = 0x000003B3u, /* m33syscpuss.dw1_tr_out[7] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT8 = 0x000003B4u, /* m33syscpuss.dw1_tr_out[8] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT9 = 0x000003B5u, /* m33syscpuss.dw1_tr_out[9] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT10 = 0x000003B6u, /* m33syscpuss.dw1_tr_out[10] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT11 = 0x000003B7u, /* m33syscpuss.dw1_tr_out[11] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT12 = 0x000003B8u, /* m33syscpuss.dw1_tr_out[12] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT13 = 0x000003B9u, /* m33syscpuss.dw1_tr_out[13] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT14 = 0x000003BAu, /* m33syscpuss.dw1_tr_out[14] */
    PERI_0_TRIG_IN_MUX_3_PDMA1_TR_OUT15 = 0x000003BBu /* m33syscpuss.dw1_tr_out[15] */
} en_peri0_trig_input_debugreducation1_t;

/* Peri 0 Trigger Input Group 4 - PERI0 Freeze trigger multiplexer */
typedef enum
{
    PERI_0_TRIG_IN_MUX_4_DEBUG600_CTI_TR_OUT0 = 0x00000401u, /* debug600.cti_tr_out[0] */
    PERI_0_TRIG_IN_MUX_4_DEBUG600_CTI_TR_OUT1 = 0x00000402u, /* debug600.cti_tr_out[1] */
    PERI_0_TRIG_IN_MUX_4_M33SYSCPUSS_TR_FAULT0 = 0x00000403u, /* m33syscpuss.tr_fault[0] */
    PERI_0_TRIG_IN_MUX_4_M33SYSCPUSS_TR_FAULT1 = 0x00000404u /* m33syscpuss.tr_fault[1] */
} en_peri0_trig_input_peri0_freeze_t;

/* Peri 0 Trigger Input Group 5 - LPPASS Request Assignments */
typedef enum
{
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT0 = 0x00000501u, /* m33syscpuss.dw0_tr_out[0] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT1 = 0x00000502u, /* m33syscpuss.dw0_tr_out[1] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT2 = 0x00000503u, /* m33syscpuss.dw0_tr_out[2] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT3 = 0x00000504u, /* m33syscpuss.dw0_tr_out[3] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT4 = 0x00000505u, /* m33syscpuss.dw0_tr_out[4] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT5 = 0x00000506u, /* m33syscpuss.dw0_tr_out[5] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT6 = 0x00000507u, /* m33syscpuss.dw0_tr_out[6] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT7 = 0x00000508u, /* m33syscpuss.dw0_tr_out[7] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT8 = 0x00000509u, /* m33syscpuss.dw0_tr_out[8] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT9 = 0x0000050Au, /* m33syscpuss.dw0_tr_out[9] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT10 = 0x0000050Bu, /* m33syscpuss.dw0_tr_out[10] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT11 = 0x0000050Cu, /* m33syscpuss.dw0_tr_out[11] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT12 = 0x0000050Du, /* m33syscpuss.dw0_tr_out[12] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT13 = 0x0000050Eu, /* m33syscpuss.dw0_tr_out[13] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT14 = 0x0000050Fu, /* m33syscpuss.dw0_tr_out[14] */
    PERI_0_TRIG_IN_MUX_5_PDMA0_TR_OUT15 = 0x00000510u, /* m33syscpuss.dw0_tr_out[15] */
    PERI_0_TRIG_IN_MUX_5_AXIDMAC_TR_OUT0 = 0x00000511u, /* m55appcpuss.axidmac_tr_out[0] */
    PERI_0_TRIG_IN_MUX_5_AXIDMAC_TR_OUT1 = 0x00000512u, /* m55appcpuss.axidmac_tr_out[1] */
    PERI_0_TRIG_IN_MUX_5_AXIDMAC_TR_OUT2 = 0x00000513u, /* m55appcpuss.axidmac_tr_out[2] */
    PERI_0_TRIG_IN_MUX_5_AXIDMAC_TR_OUT3 = 0x00000514u, /* m55appcpuss.axidmac_tr_out[3] */
    PERI_0_TRIG_IN_MUX_5_PERI0_HSIOM_TR_OUT0 = 0x00000515u, /* ioss.peri0_tr_io_input_in[0] */
    PERI_0_TRIG_IN_MUX_5_PERI0_HSIOM_TR_OUT1 = 0x00000516u, /* ioss.peri0_tr_io_input_in[1] */
    PERI_0_TRIG_IN_MUX_5_PERI0_HSIOM_TR_OUT2 = 0x00000517u, /* ioss.peri0_tr_io_input_in[2] */
    PERI_0_TRIG_IN_MUX_5_PERI0_HSIOM_TR_OUT3 = 0x00000518u, /* ioss.peri0_tr_io_input_in[3] */
    PERI_0_TRIG_IN_MUX_5_PERI0_HSIOM_TR_OUT4 = 0x00000519u, /* ioss.peri0_tr_io_input_in[4] */
    PERI_0_TRIG_IN_MUX_5_PERI0_HSIOM_TR_OUT5 = 0x0000051Au, /* ioss.peri0_tr_io_input_in[5] */
    PERI_0_TRIG_IN_MUX_5_PERI0_HSIOM_TR_OUT6 = 0x0000051Bu, /* ioss.peri0_tr_io_input_in[6] */
    PERI_0_TRIG_IN_MUX_5_PERI0_HSIOM_TR_OUT7 = 0x0000051Cu, /* ioss.peri0_tr_io_input_in[7] */
    PERI_0_TRIG_IN_MUX_5_PERI1_HSIOM_TR_OUT0 = 0x0000051Du, /* ioss.peri1_tr_io_input_in[0] */
    PERI_0_TRIG_IN_MUX_5_PERI1_HSIOM_TR_OUT1 = 0x0000051Eu, /* ioss.peri1_tr_io_input_in[1] */
    PERI_0_TRIG_IN_MUX_5_PERI1_HSIOM_TR_OUT2 = 0x0000051Fu, /* ioss.peri1_tr_io_input_in[2] */
    PERI_0_TRIG_IN_MUX_5_PERI1_HSIOM_TR_OUT3 = 0x00000520u, /* ioss.peri1_tr_io_input_in[3] */
    PERI_0_TRIG_IN_MUX_5_PERI1_HSIOM_TR_OUT4 = 0x00000521u, /* ioss.peri1_tr_io_input_in[4] */
    PERI_0_TRIG_IN_MUX_5_PERI1_HSIOM_TR_OUT5 = 0x00000522u, /* ioss.peri1_tr_io_input_in[5] */
    PERI_0_TRIG_IN_MUX_5_PERI1_HSIOM_TR_OUT6 = 0x00000523u, /* ioss.peri1_tr_io_input_in[6] */
    PERI_0_TRIG_IN_MUX_5_PERI1_HSIOM_TR_OUT7 = 0x00000524u, /* ioss.peri1_tr_io_input_in[7] */
    PERI_0_TRIG_IN_MUX_5_DEBUG600_CTI_TR_OUT0 = 0x00000525u, /* debug600.cti_tr_out[0] */
    PERI_0_TRIG_IN_MUX_5_DEBUG600_CTI_TR_OUT1 = 0x00000526u, /* debug600.cti_tr_out[1] */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT0 = 0x00000527u, /* scb[0].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT1 = 0x00000528u, /* scb[1].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT2 = 0x00000529u, /* scb[2].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT3 = 0x0000052Au, /* scb[3].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT4 = 0x0000052Bu, /* scb[4].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT5 = 0x0000052Cu, /* scb[5].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT6 = 0x0000052Du, /* scb[6].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT7 = 0x0000052Eu, /* scb[7].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT8 = 0x0000052Fu, /* scb[8].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT9 = 0x00000530u, /* scb[9].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT10 = 0x00000531u, /* scb[10].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_I2C_SCL_TR_OUT11 = 0x00000532u, /* scb[11].tr_i2c_scl_filtered */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT0 = 0x00000533u, /* scb[0].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT1 = 0x00000534u, /* scb[1].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT2 = 0x00000535u, /* scb[2].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT3 = 0x00000536u, /* scb[3].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT4 = 0x00000537u, /* scb[4].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT5 = 0x00000538u, /* scb[5].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT6 = 0x00000539u, /* scb[6].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT7 = 0x0000053Au, /* scb[7].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT8 = 0x0000053Bu, /* scb[8].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT9 = 0x0000053Cu, /* scb[9].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT10 = 0x0000053Du, /* scb[10].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_TX_TR_OUT11 = 0x0000053Eu, /* scb[11].tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT0 = 0x0000053Fu, /* scb[0].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT1 = 0x00000540u, /* scb[1].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT2 = 0x00000541u, /* scb[2].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT3 = 0x00000542u, /* scb[3].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT4 = 0x00000543u, /* scb[4].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT5 = 0x00000544u, /* scb[5].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT6 = 0x00000545u, /* scb[6].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT7 = 0x00000546u, /* scb[7].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT8 = 0x00000547u, /* scb[8].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT9 = 0x00000548u, /* scb[9].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT10 = 0x00000549u, /* scb[10].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SCB_RX_TR_OUT11 = 0x0000054Au, /* scb[11].tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_CAN0_TT_TR_OUT0 = 0x0000054Bu, /* canfd[0].tr_tmp_rtp_out[0] */
    PERI_0_TRIG_IN_MUX_5_CAN0_TT_TR_OUT1 = 0x0000054Cu, /* canfd[0].tr_tmp_rtp_out[1] */
    PERI_0_TRIG_IN_MUX_5_I2S_TDM_TX0 = 0x0000054Du, /* tdm.tr_tx_req[0] */
    PERI_0_TRIG_IN_MUX_5_I2S_TDM_RX0 = 0x0000054Eu, /* tdm.tr_rx_req[0] */
    PERI_0_TRIG_IN_MUX_5_I2S_TDM_TX1 = 0x0000054Fu, /* tdm.tr_tx_req[1] */
    PERI_0_TRIG_IN_MUX_5_I2S_TDM_RX1 = 0x00000550u, /* tdm.tr_rx_req[1] */
    PERI_0_TRIG_IN_MUX_5_SMIF0_TR_RX_REQ = 0x00000551u, /* smif[0].smif0_tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SMIF0_TR_TX_REQ = 0x00000552u, /* smif[0].smif0_tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_SMIF1_TR_RX_REQ = 0x00000553u, /* smif[1].smif0_tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_SMIF1_TR_TX_REQ = 0x00000554u, /* smif[1].smif0_tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_PDM_TX_RX_REQ0 = 0x00000555u, /* pdm.tr_rx_req[0] */
    PERI_0_TRIG_IN_MUX_5_PDM_TX_RX_REQ1 = 0x00000556u, /* pdm.tr_rx_req[1] */
    PERI_0_TRIG_IN_MUX_5_PDM_TX_RX_REQ2 = 0x00000557u, /* pdm.tr_rx_req[2] */
    PERI_0_TRIG_IN_MUX_5_PDM_TX_RX_REQ3 = 0x00000558u, /* pdm.tr_rx_req[3] */
    PERI_0_TRIG_IN_MUX_5_PDM_TX_RX_REQ4 = 0x00000559u, /* pdm.tr_rx_req[4] */
    PERI_0_TRIG_IN_MUX_5_PDM_TX_RX_REQ5 = 0x0000055Au, /* pdm.tr_rx_req[5] */
    PERI_0_TRIG_IN_MUX_5_PDM_RX_REQ_ALL = 0x0000055Bu, /* pdm.tr_rx_req_all */
    PERI_0_TRIG_IN_MUX_5_PASS_TR_LPPASS_OUT0 = 0x0000055Cu, /* pass.tr_lppass_out[0] */
    PERI_0_TRIG_IN_MUX_5_PASS_TR_LPPASS_OUT1 = 0x0000055Du, /* pass.tr_lppass_out[1] */
    PERI_0_TRIG_IN_MUX_5_PASS_TR_LPPASS_OUT2 = 0x0000055Eu, /* pass.tr_lppass_out[2] */
    PERI_0_TRIG_IN_MUX_5_PASS_TR_LPPASS_OUT3 = 0x0000055Fu, /* pass.tr_lppass_out[3] */
    PERI_0_TRIG_IN_MUX_5_PASS_TR_LPPASS_OUT4 = 0x00000560u, /* pass.tr_lppass_out[4] */
    PERI_0_TRIG_IN_MUX_5_PASS_TR_LPPASS_OUT5 = 0x00000561u, /* pass.tr_lppass_out[5] */
    PERI_0_TRIG_IN_MUX_5_PASS_TR_LPPASS_OUT6 = 0x00000562u, /* pass.tr_lppass_out[6] */
    PERI_0_TRIG_IN_MUX_5_PASS_TR_LPPASS_OUT7 = 0x00000563u, /* pass.tr_lppass_out[7] */
    PERI_0_TRIG_IN_MUX_5_I3C_TR_TX_REQ = 0x00000564u, /* i3c.tr_tx_req */
    PERI_0_TRIG_IN_MUX_5_I3C_TR_RX_REQ = 0x00000565u, /* i3c.tr_rx_req */
    PERI_0_TRIG_IN_MUX_5_MXNNLITE_TR_MXNNLITE = 0x00000566u, /* mxnnlite.tr_mxnnlite */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT00 = 0x00000567u, /* tcpwm[0].tr_out0[0] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT01 = 0x00000568u, /* tcpwm[0].tr_out0[1] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT02 = 0x00000569u, /* tcpwm[0].tr_out0[2] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT03 = 0x0000056Au, /* tcpwm[0].tr_out0[3] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT04 = 0x0000056Bu, /* tcpwm[0].tr_out0[4] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT05 = 0x0000056Cu, /* tcpwm[0].tr_out0[5] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT06 = 0x0000056Du, /* tcpwm[0].tr_out0[6] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT07 = 0x0000056Eu, /* tcpwm[0].tr_out0[7] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT10 = 0x0000056Fu, /* tcpwm[0].tr_out1[0] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT11 = 0x00000570u, /* tcpwm[0].tr_out1[1] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT12 = 0x00000571u, /* tcpwm[0].tr_out1[2] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT13 = 0x00000572u, /* tcpwm[0].tr_out1[3] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT14 = 0x00000573u, /* tcpwm[0].tr_out1[4] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT15 = 0x00000574u, /* tcpwm[0].tr_out1[5] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT16 = 0x00000575u, /* tcpwm[0].tr_out1[6] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT17 = 0x00000576u, /* tcpwm[0].tr_out1[7] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0256 = 0x00000577u, /* tcpwm[0].tr_out0[256] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0257 = 0x00000578u, /* tcpwm[0].tr_out0[257] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0258 = 0x00000579u, /* tcpwm[0].tr_out0[258] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0259 = 0x0000057Au, /* tcpwm[0].tr_out0[259] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0260 = 0x0000057Bu, /* tcpwm[0].tr_out0[260] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0261 = 0x0000057Cu, /* tcpwm[0].tr_out0[261] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0262 = 0x0000057Du, /* tcpwm[0].tr_out0[262] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0263 = 0x0000057Eu, /* tcpwm[0].tr_out0[263] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0264 = 0x0000057Fu, /* tcpwm[0].tr_out0[264] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0265 = 0x00000580u, /* tcpwm[0].tr_out0[265] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0266 = 0x00000581u, /* tcpwm[0].tr_out0[266] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0267 = 0x00000582u, /* tcpwm[0].tr_out0[267] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0268 = 0x00000583u, /* tcpwm[0].tr_out0[268] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0269 = 0x00000584u, /* tcpwm[0].tr_out0[269] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0270 = 0x00000585u, /* tcpwm[0].tr_out0[270] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0271 = 0x00000586u, /* tcpwm[0].tr_out0[271] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0272 = 0x00000587u, /* tcpwm[0].tr_out0[272] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0273 = 0x00000588u, /* tcpwm[0].tr_out0[273] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0274 = 0x00000589u, /* tcpwm[0].tr_out0[274] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0275 = 0x0000058Au, /* tcpwm[0].tr_out0[275] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0276 = 0x0000058Bu, /* tcpwm[0].tr_out0[276] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0277 = 0x0000058Cu, /* tcpwm[0].tr_out0[277] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0278 = 0x0000058Du, /* tcpwm[0].tr_out0[278] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT0279 = 0x0000058Eu, /* tcpwm[0].tr_out0[279] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1256 = 0x0000058Fu, /* tcpwm[0].tr_out1[256] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1257 = 0x00000590u, /* tcpwm[0].tr_out1[257] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1258 = 0x00000591u, /* tcpwm[0].tr_out1[258] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1259 = 0x00000592u, /* tcpwm[0].tr_out1[259] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1260 = 0x00000593u, /* tcpwm[0].tr_out1[260] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1261 = 0x00000594u, /* tcpwm[0].tr_out1[261] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1262 = 0x00000595u, /* tcpwm[0].tr_out1[262] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1263 = 0x00000596u, /* tcpwm[0].tr_out1[263] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1264 = 0x00000597u, /* tcpwm[0].tr_out1[264] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1265 = 0x00000598u, /* tcpwm[0].tr_out1[265] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1266 = 0x00000599u, /* tcpwm[0].tr_out1[266] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1267 = 0x0000059Au, /* tcpwm[0].tr_out1[267] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1268 = 0x0000059Bu, /* tcpwm[0].tr_out1[268] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1269 = 0x0000059Cu, /* tcpwm[0].tr_out1[269] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1270 = 0x0000059Du, /* tcpwm[0].tr_out1[270] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1271 = 0x0000059Eu, /* tcpwm[0].tr_out1[271] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1272 = 0x0000059Fu, /* tcpwm[0].tr_out1[272] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1273 = 0x000005A0u, /* tcpwm[0].tr_out1[273] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1274 = 0x000005A1u, /* tcpwm[0].tr_out1[274] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1275 = 0x000005A2u, /* tcpwm[0].tr_out1[275] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1276 = 0x000005A3u, /* tcpwm[0].tr_out1[276] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1277 = 0x000005A4u, /* tcpwm[0].tr_out1[277] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1278 = 0x000005A5u, /* tcpwm[0].tr_out1[278] */
    PERI_0_TRIG_IN_MUX_5_TCPWM0_TR_OUT1279 = 0x000005A6u, /* tcpwm[0].tr_out1[279] */
    PERI_0_TRIG_IN_MUX_5_M33SYSCPUSS_TR_FAULT0 = 0x000005A7u, /* m33syscpuss.tr_fault[0] */
    PERI_0_TRIG_IN_MUX_5_M33SYSCPUSS_TR_FAULT1 = 0x000005A8u, /* m33syscpuss.tr_fault[1] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT0 = 0x000005A9u, /* m33syscpuss.dw1_tr_out[0] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT1 = 0x000005AAu, /* m33syscpuss.dw1_tr_out[1] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT2 = 0x000005ABu, /* m33syscpuss.dw1_tr_out[2] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT3 = 0x000005ACu, /* m33syscpuss.dw1_tr_out[3] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT4 = 0x000005ADu, /* m33syscpuss.dw1_tr_out[4] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT5 = 0x000005AEu, /* m33syscpuss.dw1_tr_out[5] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT6 = 0x000005AFu, /* m33syscpuss.dw1_tr_out[6] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT7 = 0x000005B0u, /* m33syscpuss.dw1_tr_out[7] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT8 = 0x000005B1u, /* m33syscpuss.dw1_tr_out[8] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT9 = 0x000005B2u, /* m33syscpuss.dw1_tr_out[9] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT10 = 0x000005B3u, /* m33syscpuss.dw1_tr_out[10] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT11 = 0x000005B4u, /* m33syscpuss.dw1_tr_out[11] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT12 = 0x000005B5u, /* m33syscpuss.dw1_tr_out[12] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT13 = 0x000005B6u, /* m33syscpuss.dw1_tr_out[13] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT14 = 0x000005B7u, /* m33syscpuss.dw1_tr_out[14] */
    PERI_0_TRIG_IN_MUX_5_PDMA1_TR_OUT15 = 0x000005B8u /* m33syscpuss.dw1_tr_out[15] */
} en_peri0_trig_input_lppass_tr_t;

/* Peri 1 Trigger Input Group 0 - P-DMA0 Request Assignments */
typedef enum
{
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT0 = 0x00010001u, /* m33syscpuss.dw0_tr_out[0] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT1 = 0x00010002u, /* m33syscpuss.dw0_tr_out[1] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT2 = 0x00010003u, /* m33syscpuss.dw0_tr_out[2] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT3 = 0x00010004u, /* m33syscpuss.dw0_tr_out[3] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT4 = 0x00010005u, /* m33syscpuss.dw0_tr_out[4] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT5 = 0x00010006u, /* m33syscpuss.dw0_tr_out[5] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT6 = 0x00010007u, /* m33syscpuss.dw0_tr_out[6] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT7 = 0x00010008u, /* m33syscpuss.dw0_tr_out[7] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT8 = 0x00010009u, /* m33syscpuss.dw0_tr_out[8] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT9 = 0x0001000Au, /* m33syscpuss.dw0_tr_out[9] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT10 = 0x0001000Bu, /* m33syscpuss.dw0_tr_out[10] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT11 = 0x0001000Cu, /* m33syscpuss.dw0_tr_out[11] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT12 = 0x0001000Du, /* m33syscpuss.dw0_tr_out[12] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT13 = 0x0001000Eu, /* m33syscpuss.dw0_tr_out[13] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT14 = 0x0001000Fu, /* m33syscpuss.dw0_tr_out[14] */
    PERI_1_TRIG_IN_MUX_0_PDMA0_TR_OUT15 = 0x00010010u, /* m33syscpuss.dw0_tr_out[15] */
    PERI_1_TRIG_IN_MUX_0_AXIDMAC_TR_OUT0 = 0x00010011u, /* m55appcpuss.axidmac_tr_out[0] */
    PERI_1_TRIG_IN_MUX_0_AXIDMAC_TR_OUT1 = 0x00010012u, /* m55appcpuss.axidmac_tr_out[1] */
    PERI_1_TRIG_IN_MUX_0_AXIDMAC_TR_OUT2 = 0x00010013u, /* m55appcpuss.axidmac_tr_out[2] */
    PERI_1_TRIG_IN_MUX_0_AXIDMAC_TR_OUT3 = 0x00010014u, /* m55appcpuss.axidmac_tr_out[3] */
    PERI_1_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT0 = 0x00010015u, /* ioss.peri0_tr_io_input_in[0] */
    PERI_1_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT1 = 0x00010016u, /* ioss.peri0_tr_io_input_in[1] */
    PERI_1_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT2 = 0x00010017u, /* ioss.peri0_tr_io_input_in[2] */
    PERI_1_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT3 = 0x00010018u, /* ioss.peri0_tr_io_input_in[3] */
    PERI_1_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT4 = 0x00010019u, /* ioss.peri0_tr_io_input_in[4] */
    PERI_1_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT5 = 0x0001001Au, /* ioss.peri0_tr_io_input_in[5] */
    PERI_1_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT6 = 0x0001001Bu, /* ioss.peri0_tr_io_input_in[6] */
    PERI_1_TRIG_IN_MUX_0_PERI0_HSIOM_TR_OUT7 = 0x0001001Cu, /* ioss.peri0_tr_io_input_in[7] */
    PERI_1_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT0 = 0x0001001Du, /* ioss.peri1_tr_io_input_in[0] */
    PERI_1_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT1 = 0x0001001Eu, /* ioss.peri1_tr_io_input_in[1] */
    PERI_1_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT2 = 0x0001001Fu, /* ioss.peri1_tr_io_input_in[2] */
    PERI_1_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT3 = 0x00010020u, /* ioss.peri1_tr_io_input_in[3] */
    PERI_1_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT4 = 0x00010021u, /* ioss.peri1_tr_io_input_in[4] */
    PERI_1_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT5 = 0x00010022u, /* ioss.peri1_tr_io_input_in[5] */
    PERI_1_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT6 = 0x00010023u, /* ioss.peri1_tr_io_input_in[6] */
    PERI_1_TRIG_IN_MUX_0_PERI1_HSIOM_TR_OUT7 = 0x00010024u, /* ioss.peri1_tr_io_input_in[7] */
    PERI_1_TRIG_IN_MUX_0_DEBUG600_CTI_TR_OUT0 = 0x00010025u, /* debug600.cti_tr_out[0] */
    PERI_1_TRIG_IN_MUX_0_DEBUG600_CTI_TR_OUT1 = 0x00010026u, /* debug600.cti_tr_out[1] */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT0 = 0x00010027u, /* scb[0].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT1 = 0x00010028u, /* scb[1].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT2 = 0x00010029u, /* scb[2].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT3 = 0x0001002Au, /* scb[3].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT4 = 0x0001002Bu, /* scb[4].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT5 = 0x0001002Cu, /* scb[5].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT6 = 0x0001002Du, /* scb[6].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT7 = 0x0001002Eu, /* scb[7].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT8 = 0x0001002Fu, /* scb[8].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT9 = 0x00010030u, /* scb[9].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT10 = 0x00010031u, /* scb[10].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_I2C_SCL_TR_OUT11 = 0x00010032u, /* scb[11].tr_i2c_scl_filtered */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT0 = 0x00010033u, /* scb[0].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT1 = 0x00010034u, /* scb[1].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT2 = 0x00010035u, /* scb[2].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT3 = 0x00010036u, /* scb[3].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT4 = 0x00010037u, /* scb[4].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT5 = 0x00010038u, /* scb[5].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT6 = 0x00010039u, /* scb[6].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT7 = 0x0001003Au, /* scb[7].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT8 = 0x0001003Bu, /* scb[8].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT9 = 0x0001003Cu, /* scb[9].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT10 = 0x0001003Du, /* scb[10].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_TX_TR_OUT11 = 0x0001003Eu, /* scb[11].tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT0 = 0x0001003Fu, /* scb[0].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT1 = 0x00010040u, /* scb[1].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT2 = 0x00010041u, /* scb[2].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT3 = 0x00010042u, /* scb[3].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT4 = 0x00010043u, /* scb[4].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT5 = 0x00010044u, /* scb[5].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT6 = 0x00010045u, /* scb[6].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT7 = 0x00010046u, /* scb[7].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT8 = 0x00010047u, /* scb[8].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT9 = 0x00010048u, /* scb[9].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT10 = 0x00010049u, /* scb[10].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SCB_RX_TR_OUT11 = 0x0001004Au, /* scb[11].tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_CAN0_TT_TR_OUT0 = 0x0001004Bu, /* canfd[0].tr_tmp_rtp_out[0] */
    PERI_1_TRIG_IN_MUX_0_CAN0_TT_TR_OUT1 = 0x0001004Cu, /* canfd[0].tr_tmp_rtp_out[1] */
    PERI_1_TRIG_IN_MUX_0_I2S_TDM_TX0 = 0x0001004Du, /* tdm.tr_tx_req[0] */
    PERI_1_TRIG_IN_MUX_0_I2S_TDM_RX0 = 0x0001004Eu, /* tdm.tr_rx_req[0] */
    PERI_1_TRIG_IN_MUX_0_I2S_TDM_TX1 = 0x0001004Fu, /* tdm.tr_tx_req[1] */
    PERI_1_TRIG_IN_MUX_0_I2S_TDM_RX1 = 0x00010050u, /* tdm.tr_rx_req[1] */
    PERI_1_TRIG_IN_MUX_0_PDM_TX_RX_REQ0 = 0x00010051u, /* pdm.tr_rx_req[0] */
    PERI_1_TRIG_IN_MUX_0_PDM_TX_RX_REQ1 = 0x00010052u, /* pdm.tr_rx_req[1] */
    PERI_1_TRIG_IN_MUX_0_PDM_TX_RX_REQ2 = 0x00010053u, /* pdm.tr_rx_req[2] */
    PERI_1_TRIG_IN_MUX_0_PDM_TX_RX_REQ3 = 0x00010054u, /* pdm.tr_rx_req[3] */
    PERI_1_TRIG_IN_MUX_0_PDM_TX_RX_REQ4 = 0x00010055u, /* pdm.tr_rx_req[4] */
    PERI_1_TRIG_IN_MUX_0_PDM_TX_RX_REQ5 = 0x00010056u, /* pdm.tr_rx_req[5] */
    PERI_1_TRIG_IN_MUX_0_PDM_RX_REQ_ALL = 0x00010057u, /* pdm.tr_rx_req_all */
    PERI_1_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT0 = 0x00010058u, /* pass.tr_lppass_out[0] */
    PERI_1_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT1 = 0x00010059u, /* pass.tr_lppass_out[1] */
    PERI_1_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT2 = 0x0001005Au, /* pass.tr_lppass_out[2] */
    PERI_1_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT3 = 0x0001005Bu, /* pass.tr_lppass_out[3] */
    PERI_1_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT4 = 0x0001005Cu, /* pass.tr_lppass_out[4] */
    PERI_1_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT5 = 0x0001005Du, /* pass.tr_lppass_out[5] */
    PERI_1_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT6 = 0x0001005Eu, /* pass.tr_lppass_out[6] */
    PERI_1_TRIG_IN_MUX_0_PASS_TR_LPPASS_OUT7 = 0x0001005Fu, /* pass.tr_lppass_out[7] */
    PERI_1_TRIG_IN_MUX_0_I3C_TR_TX_REQ = 0x00010060u, /* i3c.tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_I3C_TR_RX_REQ = 0x00010061u, /* i3c.tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_MXNNLITE_TR_MXNNLITE = 0x00010062u, /* mxnnlite.tr_mxnnlite */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT00 = 0x00010063u, /* tcpwm[0].tr_out0[0] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT01 = 0x00010064u, /* tcpwm[0].tr_out0[1] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT02 = 0x00010065u, /* tcpwm[0].tr_out0[2] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT03 = 0x00010066u, /* tcpwm[0].tr_out0[3] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT04 = 0x00010067u, /* tcpwm[0].tr_out0[4] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT05 = 0x00010068u, /* tcpwm[0].tr_out0[5] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT06 = 0x00010069u, /* tcpwm[0].tr_out0[6] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT07 = 0x0001006Au, /* tcpwm[0].tr_out0[7] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT10 = 0x0001006Bu, /* tcpwm[0].tr_out1[0] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT11 = 0x0001006Cu, /* tcpwm[0].tr_out1[1] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT12 = 0x0001006Du, /* tcpwm[0].tr_out1[2] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT13 = 0x0001006Eu, /* tcpwm[0].tr_out1[3] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT14 = 0x0001006Fu, /* tcpwm[0].tr_out1[4] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT15 = 0x00010070u, /* tcpwm[0].tr_out1[5] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT16 = 0x00010071u, /* tcpwm[0].tr_out1[6] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT17 = 0x00010072u, /* tcpwm[0].tr_out1[7] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0256 = 0x00010073u, /* tcpwm[0].tr_out0[256] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0257 = 0x00010074u, /* tcpwm[0].tr_out0[257] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0258 = 0x00010075u, /* tcpwm[0].tr_out0[258] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0259 = 0x00010076u, /* tcpwm[0].tr_out0[259] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0260 = 0x00010077u, /* tcpwm[0].tr_out0[260] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0261 = 0x00010078u, /* tcpwm[0].tr_out0[261] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0262 = 0x00010079u, /* tcpwm[0].tr_out0[262] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0263 = 0x0001007Au, /* tcpwm[0].tr_out0[263] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0264 = 0x0001007Bu, /* tcpwm[0].tr_out0[264] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0265 = 0x0001007Cu, /* tcpwm[0].tr_out0[265] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0266 = 0x0001007Du, /* tcpwm[0].tr_out0[266] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0267 = 0x0001007Eu, /* tcpwm[0].tr_out0[267] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0268 = 0x0001007Fu, /* tcpwm[0].tr_out0[268] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0269 = 0x00010080u, /* tcpwm[0].tr_out0[269] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0270 = 0x00010081u, /* tcpwm[0].tr_out0[270] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0271 = 0x00010082u, /* tcpwm[0].tr_out0[271] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0272 = 0x00010083u, /* tcpwm[0].tr_out0[272] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0273 = 0x00010084u, /* tcpwm[0].tr_out0[273] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0274 = 0x00010085u, /* tcpwm[0].tr_out0[274] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0275 = 0x00010086u, /* tcpwm[0].tr_out0[275] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0276 = 0x00010087u, /* tcpwm[0].tr_out0[276] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0277 = 0x00010088u, /* tcpwm[0].tr_out0[277] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0278 = 0x00010089u, /* tcpwm[0].tr_out0[278] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT0279 = 0x0001008Au, /* tcpwm[0].tr_out0[279] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1256 = 0x0001008Bu, /* tcpwm[0].tr_out1[256] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1257 = 0x0001008Cu, /* tcpwm[0].tr_out1[257] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1258 = 0x0001008Du, /* tcpwm[0].tr_out1[258] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1259 = 0x0001008Eu, /* tcpwm[0].tr_out1[259] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1260 = 0x0001008Fu, /* tcpwm[0].tr_out1[260] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1261 = 0x00010090u, /* tcpwm[0].tr_out1[261] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1262 = 0x00010091u, /* tcpwm[0].tr_out1[262] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1263 = 0x00010092u, /* tcpwm[0].tr_out1[263] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1264 = 0x00010093u, /* tcpwm[0].tr_out1[264] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1265 = 0x00010094u, /* tcpwm[0].tr_out1[265] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1266 = 0x00010095u, /* tcpwm[0].tr_out1[266] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1267 = 0x00010096u, /* tcpwm[0].tr_out1[267] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1268 = 0x00010097u, /* tcpwm[0].tr_out1[268] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1269 = 0x00010098u, /* tcpwm[0].tr_out1[269] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1270 = 0x00010099u, /* tcpwm[0].tr_out1[270] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1271 = 0x0001009Au, /* tcpwm[0].tr_out1[271] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1272 = 0x0001009Bu, /* tcpwm[0].tr_out1[272] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1273 = 0x0001009Cu, /* tcpwm[0].tr_out1[273] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1274 = 0x0001009Du, /* tcpwm[0].tr_out1[274] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1275 = 0x0001009Eu, /* tcpwm[0].tr_out1[275] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1276 = 0x0001009Fu, /* tcpwm[0].tr_out1[276] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1277 = 0x000100A0u, /* tcpwm[0].tr_out1[277] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1278 = 0x000100A1u, /* tcpwm[0].tr_out1[278] */
    PERI_1_TRIG_IN_MUX_0_TCPWM0_TR_OUT1279 = 0x000100A2u, /* tcpwm[0].tr_out1[279] */
    PERI_1_TRIG_IN_MUX_0_SMIF0_TR_RX_REQ = 0x000100A3u, /* smif[0].smif0_tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SMIF0_TR_TX_REQ = 0x000100A4u, /* smif[0].smif0_tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_SMIF1_TR_RX_REQ = 0x000100A5u, /* smif[1].smif0_tr_rx_req */
    PERI_1_TRIG_IN_MUX_0_SMIF1_TR_TX_REQ = 0x000100A6u, /* smif[1].smif0_tr_tx_req */
    PERI_1_TRIG_IN_MUX_0_CAN0_FIFO0_TR_OUT0 = 0x000100A7u, /* canfd[0].tr_fifo0[0] */
    PERI_1_TRIG_IN_MUX_0_CAN0_FIFO1_TR_OUT0 = 0x000100A8u, /* canfd[0].tr_fifo1[0] */
    PERI_1_TRIG_IN_MUX_0_CAN0_FIFO0_TR_OUT1 = 0x000100A9u, /* canfd[0].tr_fifo0[1] */
    PERI_1_TRIG_IN_MUX_0_CAN0_FIFO1_TR_OUT1 = 0x000100AAu, /* canfd[0].tr_fifo1[1] */
    PERI_1_TRIG_IN_MUX_0_CAN0_DBG_TR_OUT0 = 0x000100ABu, /* canfd[0].tr_dbg_dma_req[0] */
    PERI_1_TRIG_IN_MUX_0_CAN0_DBG_TR_OUT1 = 0x000100ACu, /* canfd[0].tr_dbg_dma_req[1] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT0 = 0x000100ADu, /* m33syscpuss.dw1_tr_out[0] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT1 = 0x000100AEu, /* m33syscpuss.dw1_tr_out[1] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT2 = 0x000100AFu, /* m33syscpuss.dw1_tr_out[2] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT3 = 0x000100B0u, /* m33syscpuss.dw1_tr_out[3] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT4 = 0x000100B1u, /* m33syscpuss.dw1_tr_out[4] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT5 = 0x000100B2u, /* m33syscpuss.dw1_tr_out[5] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT6 = 0x000100B3u, /* m33syscpuss.dw1_tr_out[6] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT7 = 0x000100B4u, /* m33syscpuss.dw1_tr_out[7] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT8 = 0x000100B5u, /* m33syscpuss.dw1_tr_out[8] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT9 = 0x000100B6u, /* m33syscpuss.dw1_tr_out[9] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT10 = 0x000100B7u, /* m33syscpuss.dw1_tr_out[10] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT11 = 0x000100B8u, /* m33syscpuss.dw1_tr_out[11] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT12 = 0x000100B9u, /* m33syscpuss.dw1_tr_out[12] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT13 = 0x000100BAu, /* m33syscpuss.dw1_tr_out[13] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT14 = 0x000100BBu, /* m33syscpuss.dw1_tr_out[14] */
    PERI_1_TRIG_IN_MUX_0_PDMA1_TR_OUT15 = 0x000100BCu /* m33syscpuss.dw1_tr_out[15] */
} en_peri1_trig_input_axidma0_tr_t;

/* Peri 1 Trigger Input Group 1 - PERI1 Freeze trigger multiplexer */
typedef enum
{
    PERI_1_TRIG_IN_MUX_1_DEBUG600_CTI_TR_OUT0 = 0x00010101u, /* debug600.cti_tr_out[0] */
    PERI_1_TRIG_IN_MUX_1_DEBUG600_CTI_TR_OUT1 = 0x00010102u /* debug600.cti_tr_out[1] */
} en_peri1_trig_input_peri1_freeze_t;

/* Peri 1 Trigger Input Group 2 - TCPWM and PDM trigger multiplexer */
typedef enum
{
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT00 = 0x00010201u, /* tcpwm[0].tr_out0[0] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT01 = 0x00010202u, /* tcpwm[0].tr_out0[1] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT02 = 0x00010203u, /* tcpwm[0].tr_out0[2] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT03 = 0x00010204u, /* tcpwm[0].tr_out0[3] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT04 = 0x00010205u, /* tcpwm[0].tr_out0[4] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT05 = 0x00010206u, /* tcpwm[0].tr_out0[5] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT06 = 0x00010207u, /* tcpwm[0].tr_out0[6] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT07 = 0x00010208u, /* tcpwm[0].tr_out0[7] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT10 = 0x00010209u, /* tcpwm[0].tr_out1[0] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT11 = 0x0001020Au, /* tcpwm[0].tr_out1[1] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT12 = 0x0001020Bu, /* tcpwm[0].tr_out1[2] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT13 = 0x0001020Cu, /* tcpwm[0].tr_out1[3] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT14 = 0x0001020Du, /* tcpwm[0].tr_out1[4] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT15 = 0x0001020Eu, /* tcpwm[0].tr_out1[5] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT16 = 0x0001020Fu, /* tcpwm[0].tr_out1[6] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT17 = 0x00010210u, /* tcpwm[0].tr_out1[7] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0256 = 0x00010211u, /* tcpwm[0].tr_out0[256] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0257 = 0x00010212u, /* tcpwm[0].tr_out0[257] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0258 = 0x00010213u, /* tcpwm[0].tr_out0[258] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0259 = 0x00010214u, /* tcpwm[0].tr_out0[259] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0260 = 0x00010215u, /* tcpwm[0].tr_out0[260] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0261 = 0x00010216u, /* tcpwm[0].tr_out0[261] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0262 = 0x00010217u, /* tcpwm[0].tr_out0[262] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0263 = 0x00010218u, /* tcpwm[0].tr_out0[263] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0264 = 0x00010219u, /* tcpwm[0].tr_out0[264] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0265 = 0x0001021Au, /* tcpwm[0].tr_out0[265] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0266 = 0x0001021Bu, /* tcpwm[0].tr_out0[266] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0267 = 0x0001021Cu, /* tcpwm[0].tr_out0[267] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0268 = 0x0001021Du, /* tcpwm[0].tr_out0[268] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0269 = 0x0001021Eu, /* tcpwm[0].tr_out0[269] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0270 = 0x0001021Fu, /* tcpwm[0].tr_out0[270] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0271 = 0x00010220u, /* tcpwm[0].tr_out0[271] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0272 = 0x00010221u, /* tcpwm[0].tr_out0[272] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0273 = 0x00010222u, /* tcpwm[0].tr_out0[273] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0274 = 0x00010223u, /* tcpwm[0].tr_out0[274] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0275 = 0x00010224u, /* tcpwm[0].tr_out0[275] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0276 = 0x00010225u, /* tcpwm[0].tr_out0[276] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0277 = 0x00010226u, /* tcpwm[0].tr_out0[277] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0278 = 0x00010227u, /* tcpwm[0].tr_out0[278] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT0279 = 0x00010228u, /* tcpwm[0].tr_out0[279] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1256 = 0x00010229u, /* tcpwm[0].tr_out1[256] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1257 = 0x0001022Au, /* tcpwm[0].tr_out1[257] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1258 = 0x0001022Bu, /* tcpwm[0].tr_out1[258] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1259 = 0x0001022Cu, /* tcpwm[0].tr_out1[259] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1260 = 0x0001022Du, /* tcpwm[0].tr_out1[260] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1261 = 0x0001022Eu, /* tcpwm[0].tr_out1[261] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1262 = 0x0001022Fu, /* tcpwm[0].tr_out1[262] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1263 = 0x00010230u, /* tcpwm[0].tr_out1[263] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1264 = 0x00010231u, /* tcpwm[0].tr_out1[264] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1265 = 0x00010232u, /* tcpwm[0].tr_out1[265] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1266 = 0x00010233u, /* tcpwm[0].tr_out1[266] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1267 = 0x00010234u, /* tcpwm[0].tr_out1[267] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1268 = 0x00010235u, /* tcpwm[0].tr_out1[268] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1269 = 0x00010236u, /* tcpwm[0].tr_out1[269] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1270 = 0x00010237u, /* tcpwm[0].tr_out1[270] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1271 = 0x00010238u, /* tcpwm[0].tr_out1[271] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1272 = 0x00010239u, /* tcpwm[0].tr_out1[272] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1273 = 0x0001023Au, /* tcpwm[0].tr_out1[273] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1274 = 0x0001023Bu, /* tcpwm[0].tr_out1[274] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1275 = 0x0001023Cu, /* tcpwm[0].tr_out1[275] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1276 = 0x0001023Du, /* tcpwm[0].tr_out1[276] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1277 = 0x0001023Eu, /* tcpwm[0].tr_out1[277] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1278 = 0x0001023Fu, /* tcpwm[0].tr_out1[278] */
    PERI_1_TRIG_IN_MUX_2_TCPWM0_TR_OUT1279 = 0x00010240u /* tcpwm[0].tr_out1[279] */
} en_peri1_trig_input_tcpwm_pdm_t;

/* Trigger Group Outputs */
/* Peri 0 Trigger Output Group 0 - P-DMA0 Request Assignments */
typedef enum
{
    PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN0 = 0x40000000u, /* m33syscpuss.dw0_tr_in[0] */
    PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN1 = 0x40000001u, /* m33syscpuss.dw0_tr_in[1] */
    PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN2 = 0x40000002u, /* m33syscpuss.dw0_tr_in[2] */
    PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN3 = 0x40000003u, /* m33syscpuss.dw0_tr_in[3] */
    PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN4 = 0x40000004u, /* m33syscpuss.dw0_tr_in[4] */
    PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN5 = 0x40000005u, /* m33syscpuss.dw0_tr_in[5] */
    PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN6 = 0x40000006u, /* m33syscpuss.dw0_tr_in[6] */
    PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN7 = 0x40000007u, /* m33syscpuss.dw0_tr_in[7] */
    PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN0 = 0x40000008u, /* m33syscpuss.dw1_tr_in[0] */
    PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN1 = 0x40000009u, /* m33syscpuss.dw1_tr_in[1] */
    PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN2 = 0x4000000Au, /* m33syscpuss.dw1_tr_in[2] */
    PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN3 = 0x4000000Bu, /* m33syscpuss.dw1_tr_in[3] */
    PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN4 = 0x4000000Cu, /* m33syscpuss.dw1_tr_in[4] */
    PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN5 = 0x4000000Du, /* m33syscpuss.dw1_tr_in[5] */
    PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN6 = 0x4000000Eu, /* m33syscpuss.dw1_tr_in[6] */
    PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN7 = 0x4000000Fu, /* m33syscpuss.dw1_tr_in[7] */
    PERI_0_TRIG_OUT_MUX_0_DEBUG600_CTI_TR_IN0 = 0x40000010u, /* debug600.cti_tr_in[0] */
    PERI_0_TRIG_OUT_MUX_0_DEBUG600_CTI_TR_IN1 = 0x40000011u /* debug600.cti_tr_in[1] */
} en_peri0_trig_output_pdma0_tr_t;

/* Peri 0 Trigger Output Group 1 - CAN TT Synchronization triggers */
typedef enum
{
    PERI_0_TRIG_OUT_MUX_1_CAN0_TT_TR_IN0 = 0x40000100u, /* canfd[0].tr_evt_swt_in[0] */
    PERI_0_TRIG_OUT_MUX_1_CAN0_TT_TR_IN1 = 0x40000101u /* canfd[0].tr_evt_swt_in[1] */
} en_peri0_trig_output_can_t;

/* Peri 0 Trigger Output Group 2 -  */
typedef enum
{
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN0 = 0x40000200u, /* tcpwm[0].tr_all_cnt_in[0] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN1 = 0x40000201u, /* tcpwm[0].tr_all_cnt_in[1] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN2 = 0x40000202u, /* tcpwm[0].tr_all_cnt_in[2] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN3 = 0x40000203u, /* tcpwm[0].tr_all_cnt_in[3] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN4 = 0x40000204u, /* tcpwm[0].tr_all_cnt_in[4] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN5 = 0x40000205u, /* tcpwm[0].tr_all_cnt_in[5] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN6 = 0x40000206u, /* tcpwm[0].tr_all_cnt_in[6] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN7 = 0x40000207u, /* tcpwm[0].tr_all_cnt_in[7] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN8 = 0x40000208u, /* tcpwm[0].tr_all_cnt_in[8] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN9 = 0x40000209u, /* tcpwm[0].tr_all_cnt_in[9] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN10 = 0x4000020Au, /* tcpwm[0].tr_all_cnt_in[10] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN11 = 0x4000020Bu, /* tcpwm[0].tr_all_cnt_in[11] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN12 = 0x4000020Cu, /* tcpwm[0].tr_all_cnt_in[12] */
    PERI_0_TRIG_OUT_MUX_2_TCPWM0_ALL_CNT_TR_IN13 = 0x4000020Du, /* tcpwm[0].tr_all_cnt_in[13] */
    PERI_0_TRIG_OUT_MUX_2_CAN0_DBG_TR_IN0 = 0x4000020Eu, /* canfd[0].tr_dbg_dma_ack[0] */
    PERI_0_TRIG_OUT_MUX_2_CAN0_DBG_TR_IN1 = 0x4000020Fu /* canfd[0].tr_dbg_dma_ack[1] */
} en_peri0_trig_output_tcpwm0_20_31_t;

/* Peri 0 Trigger Output Group 3 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    PERI_0_TRIG_OUT_MUX_3_PERI0_HSIOM_TR_IO_OUTPUT0 = 0x40000300u, /* ioss.peri0_tr_io_output_out[0] */
    PERI_0_TRIG_OUT_MUX_3_PERI0_HSIOM_TR_IO_OUTPUT1 = 0x40000301u, /* ioss.peri0_tr_io_output_out[1] */
    PERI_0_TRIG_OUT_MUX_3_PERI1_HSIOM_TR_IO_OUTPUT0 = 0x40000302u, /* ioss.peri1_tr_io_output_out[0] */
    PERI_0_TRIG_OUT_MUX_3_PERI1_HSIOM_TR_IO_OUTPUT1 = 0x40000303u, /* ioss.peri1_tr_io_output_out[1] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN4 = 0x40000304u, /* tcpwm[0].tr_one_cnt_in[4] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN5 = 0x40000305u, /* tcpwm[0].tr_one_cnt_in[5] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN6 = 0x40000306u, /* tcpwm[0].tr_one_cnt_in[6] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN7 = 0x40000307u, /* tcpwm[0].tr_one_cnt_in[7] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN268 = 0x40000308u, /* tcpwm[0].tr_one_cnt_in[268] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN269 = 0x40000309u, /* tcpwm[0].tr_one_cnt_in[269] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN270 = 0x4000030Au, /* tcpwm[0].tr_one_cnt_in[270] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN271 = 0x4000030Bu, /* tcpwm[0].tr_one_cnt_in[271] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN272 = 0x4000030Cu, /* tcpwm[0].tr_one_cnt_in[272] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN273 = 0x4000030Du, /* tcpwm[0].tr_one_cnt_in[273] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN274 = 0x4000030Eu, /* tcpwm[0].tr_one_cnt_in[274] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN275 = 0x4000030Fu, /* tcpwm[0].tr_one_cnt_in[275] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN276 = 0x40000310u, /* tcpwm[0].tr_one_cnt_in[276] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN277 = 0x40000311u, /* tcpwm[0].tr_one_cnt_in[277] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN278 = 0x40000312u, /* tcpwm[0].tr_one_cnt_in[278] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN279 = 0x40000313u, /* tcpwm[0].tr_one_cnt_in[279] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN14 = 0x40000314u, /* tcpwm[0].tr_all_cnt_in[14] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN15 = 0x40000315u, /* tcpwm[0].tr_all_cnt_in[15] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN16 = 0x40000316u, /* tcpwm[0].tr_all_cnt_in[16] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN17 = 0x40000317u, /* tcpwm[0].tr_all_cnt_in[17] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN18 = 0x40000318u, /* tcpwm[0].tr_all_cnt_in[18] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN19 = 0x40000319u, /* tcpwm[0].tr_all_cnt_in[19] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN20 = 0x4000031Au, /* tcpwm[0].tr_all_cnt_in[20] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN21 = 0x4000031Bu, /* tcpwm[0].tr_all_cnt_in[21] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN22 = 0x4000031Cu, /* tcpwm[0].tr_all_cnt_in[22] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN23 = 0x4000031Du, /* tcpwm[0].tr_all_cnt_in[23] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN24 = 0x4000031Eu, /* tcpwm[0].tr_all_cnt_in[24] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN25 = 0x4000031Fu, /* tcpwm[0].tr_all_cnt_in[25] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN26 = 0x40000320u, /* tcpwm[0].tr_all_cnt_in[26] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN27 = 0x40000321u, /* tcpwm[0].tr_all_cnt_in[27] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN0 = 0x40000322u, /* tcpwm[0].tr_one_cnt_in[0] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN1 = 0x40000323u, /* tcpwm[0].tr_one_cnt_in[1] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN2 = 0x40000324u, /* tcpwm[0].tr_one_cnt_in[2] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN3 = 0x40000325u, /* tcpwm[0].tr_one_cnt_in[3] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN256 = 0x40000326u, /* tcpwm[0].tr_one_cnt_in[256] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN257 = 0x40000327u, /* tcpwm[0].tr_one_cnt_in[257] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN258 = 0x40000328u, /* tcpwm[0].tr_one_cnt_in[258] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN259 = 0x40000329u, /* tcpwm[0].tr_one_cnt_in[259] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN260 = 0x4000032Au, /* tcpwm[0].tr_one_cnt_in[260] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN261 = 0x4000032Bu, /* tcpwm[0].tr_one_cnt_in[261] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN262 = 0x4000032Cu, /* tcpwm[0].tr_one_cnt_in[262] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN263 = 0x4000032Du, /* tcpwm[0].tr_one_cnt_in[263] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN264 = 0x4000032Eu, /* tcpwm[0].tr_one_cnt_in[264] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN265 = 0x4000032Fu, /* tcpwm[0].tr_one_cnt_in[265] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN266 = 0x40000330u, /* tcpwm[0].tr_one_cnt_in[266] */
    PERI_0_TRIG_OUT_MUX_3_TCPWM0_ONE_CNT_TR_IN267 = 0x40000331u /* tcpwm[0].tr_one_cnt_in[267] */
} en_peri0_trig_output_debugreducation1_t;

/* Peri 0 Trigger Output Group 4 - PERI0 Freeze trigger multiplexer */
typedef enum
{
    PERI_0_TRIG_OUT_MUX_4_PERI0_DEBUG_FREEZE_TR_IN = 0x40000400u, /* peri[0].tr_dbg_freeze */
    PERI_0_TRIG_OUT_MUX_4_TCPWM_DEBUG_FREEZE_TR_IN = 0x40000401u /* tcpwm[0].tr_debug_freeze */
} en_peri0_trig_output_peri0_freeze_t;

/* Peri 0 Trigger Output Group 5 - LPPASS Request Assignments */
typedef enum
{
    PERI_0_TRIG_OUT_MUX_5_PASS_TR_LPPASS_IN0 = 0x40000500u, /* pass.tr_lppass_in[0] */
    PERI_0_TRIG_OUT_MUX_5_PASS_TR_LPPASS_IN1 = 0x40000501u, /* pass.tr_lppass_in[1] */
    PERI_0_TRIG_OUT_MUX_5_PASS_TR_LPPASS_IN2 = 0x40000502u, /* pass.tr_lppass_in[2] */
    PERI_0_TRIG_OUT_MUX_5_PASS_TR_LPPASS_IN3 = 0x40000503u /* pass.tr_lppass_in[3] */
} en_peri0_trig_output_lppass_tr_t;

/* Peri 0 Trigger Output Group 0 - SCB PDMA0 Triggers (OneToOne) */
typedef enum
{
    PERI_0_TRIG_OUT_1TO1_0_SCB0_TX_TO_PDMA0_TR_IN8 = 0x40001000u, /* From scb[0].tr_tx_req to m33syscpuss.dw0_tr_in[8] */
    PERI_0_TRIG_OUT_1TO1_0_SCB0_RX_TO_PDMA0_TR_IN9 = 0x40001001u, /* From scb[0].tr_rx_req to m33syscpuss.dw0_tr_in[9] */
    PERI_0_TRIG_OUT_1TO1_0_SCB1_TX_TO_PDMA0_TR_IN10 = 0x40001002u, /* From scb[1].tr_tx_req to m33syscpuss.dw0_tr_in[10] */
    PERI_0_TRIG_OUT_1TO1_0_SCB1_RX_TO_PDMA0_TR_IN11 = 0x40001003u, /* From scb[1].tr_rx_req to m33syscpuss.dw0_tr_in[11] */
    PERI_0_TRIG_OUT_1TO1_0_SCB2_TX_TO_PDMA0_TR_IN12 = 0x40001004u, /* From scb[2].tr_tx_req to m33syscpuss.dw0_tr_in[12] */
    PERI_0_TRIG_OUT_1TO1_0_SCB2_RX_TO_PDMA0_TR_IN13 = 0x40001005u, /* From scb[2].tr_rx_req to m33syscpuss.dw0_tr_in[13] */
    PERI_0_TRIG_OUT_1TO1_0_SCB3_TX_TO_PDMA0_TR_IN14 = 0x40001006u, /* From scb[3].tr_tx_req to m33syscpuss.dw0_tr_in[14] */
    PERI_0_TRIG_OUT_1TO1_0_SCB3_RX_TO_PDMA0_TR_IN15 = 0x40001007u, /* From scb[3].tr_rx_req to m33syscpuss.dw0_tr_in[15] */
    PERI_0_TRIG_OUT_1TO1_0_SCB4_TX_TO_PDMA1_TR_IN8 = 0x40001008u, /* From scb[4].tr_tx_req to m33syscpuss.dw1_tr_in[8] */
    PERI_0_TRIG_OUT_1TO1_0_SCB4_RX_TO_PDMA1_TR_IN9 = 0x40001009u, /* From scb[4].tr_rx_req to m33syscpuss.dw1_tr_in[9] */
    PERI_0_TRIG_OUT_1TO1_0_SCB5_TX_TO_PDMA1_TR_IN10 = 0x4000100Au, /* From scb[5].tr_tx_req to m33syscpuss.dw1_tr_in[10] */
    PERI_0_TRIG_OUT_1TO1_0_SCB5_RX_TO_PDMA1_TR_IN11 = 0x4000100Bu, /* From scb[5].tr_rx_req to m33syscpuss.dw1_tr_in[11] */
    PERI_0_TRIG_OUT_1TO1_0_SCB6_TX_TO_PDMA1_TR_IN12 = 0x4000100Cu, /* From scb[6].tr_tx_req to m33syscpuss.dw1_tr_in[12] */
    PERI_0_TRIG_OUT_1TO1_0_SCB6_RX_TO_PDMA1_TR_IN13 = 0x4000100Du, /* From scb[6].tr_rx_req to m33syscpuss.dw1_tr_in[13] */
    PERI_0_TRIG_OUT_1TO1_0_SCB7_TX_TO_PDMA1_TR_IN14 = 0x4000100Eu, /* From scb[7].tr_tx_req to m33syscpuss.dw1_tr_in[14] */
    PERI_0_TRIG_OUT_1TO1_0_SCB7_RX_TO_PDMA1_TR_IN15 = 0x4000100Fu /* From scb[7].tr_rx_req to m33syscpuss.dw1_tr_in[15] */
} en_peri0_trig_output_1to1_scb_pdma0_tr_t;

/* Peri 1 Trigger Output Group 0 - P-DMA0 Request Assignments */
typedef enum
{
    PERI_1_TRIG_OUT_MUX_0_AXIDMAC_TR_IN0 = 0x40010000u, /* m55appcpuss.axidmac_tr_in[0] */
    PERI_1_TRIG_OUT_MUX_0_AXIDMAC_TR_IN1 = 0x40010001u, /* m55appcpuss.axidmac_tr_in[1] */
    PERI_1_TRIG_OUT_MUX_0_AXIDMAC_TR_IN2 = 0x40010002u, /* m55appcpuss.axidmac_tr_in[2] */
    PERI_1_TRIG_OUT_MUX_0_AXIDMAC_TR_IN3 = 0x40010003u /* m55appcpuss.axidmac_tr_in[3] */
} en_peri1_trig_output_axidma0_tr_t;

/* Peri 1 Trigger Output Group 1 - PERI1 Freeze trigger multiplexer */
typedef enum
{
    PERI_1_TRIG_OUT_MUX_1_TDM_DEBUG_FREEZE_TR_IN = 0x40010100u, /* tdm.tr_dbg_freeze */
    PERI_1_TRIG_OUT_MUX_1_PDM_DEBUG_FREEZE_TR_IN = 0x40010101u, /* pdm.tr_dbg_freeze */
    PERI_1_TRIG_OUT_MUX_1_PERI1_DEBUG_FREEZE_TR_IN = 0x40010102u /* peri[1].tr_dbg_freeze */
} en_peri1_trig_output_peri1_freeze_t;

/* Peri 1 Trigger Output Group 2 - TCPWM and PDM trigger multiplexer */
typedef enum
{
    PERI_1_TRIG_OUT_MUX_2_PDM_TR_ACTIVATE0 = 0x40010200u, /* pdm.tr_activate[0] */
    PERI_1_TRIG_OUT_MUX_2_PDM_TR_ACTIVATE1 = 0x40010201u, /* pdm.tr_activate[1] */
    PERI_1_TRIG_OUT_MUX_2_PDM_TR_ACTIVATE2 = 0x40010202u, /* pdm.tr_activate[2] */
    PERI_1_TRIG_OUT_MUX_2_PDM_TR_ACTIVATE3 = 0x40010203u, /* pdm.tr_activate[3] */
    PERI_1_TRIG_OUT_MUX_2_PDM_TR_ACTIVATE4 = 0x40010204u, /* pdm.tr_activate[4] */
    PERI_1_TRIG_OUT_MUX_2_PDM_TR_ACTIVATE5 = 0x40010205u /* pdm.tr_activate[5] */
} en_peri1_trig_output_tcpwm_pdm_t;

/* Level or edge detection setting for a trigger mux */
typedef enum
{
    /* The trigger is a simple level output */
    TRIGGER_TYPE_LEVEL = 0u,
    /* The trigger is synchronized to the consumer blocks clock
       and a two cycle pulse is generated on this clock */
    TRIGGER_TYPE_EDGE = 1u
} en_trig_type_t;

/* Trigger Type Defines */
/* CANFD Trigger Types */
#define TRIGGER_TYPE_CANFD_TR_DBG_DMA_ACK       TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CANFD_TR_DBG_DMA_REQ       TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_EVT_SWT_IN        TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CANFD_TR_FIFO0             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_FIFO1             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_TMP_RTP_OUT       TRIGGER_TYPE_EDGE
/* I3C Trigger Types */
#define TRIGGER_TYPE_I3C_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_I3C_TR_TX_REQ              TRIGGER_TYPE_LEVEL
/* LPCOMP Trigger Types */
#define TRIGGER_TYPE_LPCOMP_DSI_COMP0           TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_LPCOMP_DSI_COMP1           TRIGGER_TYPE_LEVEL
/* M33SYSCPUSS Trigger Types */
#define TRIGGER_TYPE_M33SYSCPUSS_DW0_TR_IN__LEVEL TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_M33SYSCPUSS_DW0_TR_IN__EDGE TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_M33SYSCPUSS_DW0_TR_OUT     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_M33SYSCPUSS_DW1_TR_IN__LEVEL TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_M33SYSCPUSS_DW1_TR_IN__EDGE TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_M33SYSCPUSS_DW1_TR_OUT     TRIGGER_TYPE_EDGE
/* M55APPCPUSS Trigger Types */
#define TRIGGER_TYPE_M55APPCPUSS_AXIDMAC_TR_IN__LEVEL TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_M55APPCPUSS_AXIDMAC_TR_IN__EDGE TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_M55APPCPUSS_AXIDMAC_TR_OUT TRIGGER_TYPE_EDGE
/* MXNNLITE Trigger Types */
#define TRIGGER_TYPE_MXNNLITE_TR_MXNNLITE       TRIGGER_TYPE_LEVEL
/* PASS Trigger Types */
#define TRIGGER_TYPE_PASS_TR_LPPASS_IN          TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_LPPASS_OUT__LEVEL  TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_LPPASS_OUT__EDGE   TRIGGER_TYPE_EDGE
/* PDM Trigger Types */
#define TRIGGER_TYPE_PDM_TR_ACTIVATE            TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PDM_TR_DBG_FREEZE          TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PDM_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PDM_TR_RX_REQ_ALL          TRIGGER_TYPE_LEVEL
/* PERI Trigger Types */
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__LEVEL   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__EDGE    TRIGGER_TYPE_EDGE
/* SCB Trigger Types */
#define TRIGGER_TYPE_SCB_TR_I2C_SCL_FILTERED    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TX_REQ              TRIGGER_TYPE_LEVEL
/* SMIF Trigger Types */
#define TRIGGER_TYPE_SMIF_SMIF0_TR_RX_REQ       TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SMIF_SMIF0_TR_TX_REQ       TRIGGER_TYPE_LEVEL
/* TCPWM Trigger Types */
#define TRIGGER_TYPE_TCPWM_TR_DEBUG_FREEZE      TRIGGER_TYPE_LEVEL
/* TDM Trigger Types */
#define TRIGGER_TYPE_TDM_TR_DBG_FREEZE          TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TDM_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TDM_TR_TX_REQ              TRIGGER_TYPE_LEVEL

/* Fault connections */
typedef enum
{
    PERI_0_PERI_MS0_PPC_VIO         = 0x0000u,
    PERI_0_PERI_MS1_PPC_VIO         = 0x0001u,
    PERI_0_PERI_PPC_PC_MASK_VIO     = 0x0002u,
    PERI_0_PERI_GP1_TIMEOUT_VIO     = 0x0003u,
    PERI_0_PERI_GP2_TIMEOUT_VIO     = 0x0004u,
    PERI_0_PERI_GP3_TIMEOUT_VIO     = 0x0005u,
    PERI_0_PERI_GP4_TIMEOUT_VIO     = 0x0006u,
    PERI_0_PERI_GP5_TIMEOUT_VIO     = 0x0007u,
    PERI_0_PERI_GP0_AHB_VIO         = 0x0008u,
    PERI_0_PERI_GP1_AHB_VIO         = 0x0009u,
    PERI_0_PERI_GP2_AHB_VIO         = 0x000Au,
    PERI_0_PERI_GP3_AHB_VIO         = 0x000Bu,
    PERI_0_PERI_GP4_AHB_VIO         = 0x000Cu,
    PERI_0_PERI_GP5_AHB_VIO         = 0x000Du,
    PERI_1_PERI_MS0_PPC_VIO         = 0x000Eu,
    PERI_1_PERI_MS1_PPC_VIO         = 0x000Fu,
    PERI_1_PERI_PPC_PC_MASK_VIO     = 0x0010u,
    PERI_1_PERI_GP1_TIMEOUT_VIO     = 0x0011u,
    PERI_1_PERI_GP2_TIMEOUT_VIO     = 0x0012u,
    PERI_1_PERI_GP3_TIMEOUT_VIO     = 0x0013u,
    PERI_1_PERI_GP4_TIMEOUT_VIO     = 0x0014u,
    PERI_1_PERI_GP0_AHB_VIO         = 0x0015u,
    PERI_1_PERI_GP1_AHB_VIO         = 0x0016u,
    PERI_1_PERI_GP2_AHB_VIO         = 0x0017u,
    PERI_1_PERI_GP3_AHB_VIO         = 0x0018u,
    PERI_1_PERI_GP4_AHB_VIO         = 0x0019u,
    M33SYSCPUSS_RAMC0_MPC_FAULT_MMIO = 0x001Au,
    M33SYSCPUSS_RAMC1_MPC_FAULT_MMIO = 0x001Bu,
    M33SYSCPUSS_RRAMC_HOST_IF_MPC_FAULT = 0x001Cu,
    M33SYSCPUSS_RRAMC_HOST_IF_OTP_WR_TAG_ERROR_FAULT = 0x001Du,
    M33SYSCPUSS_RRAMC_POST_READ_TAG_MISMATCH_FAULT = 0x001Eu,
    M33SYSCPUSS_RRAMC_POST_READ_ADDR_CHECKER_ALARM_FAULT = 0x001Fu,
    M33SYSCPUSS_RRAMC_INCOMPLETE_WRITE_FAULT = 0x0020u,
    M33SYSCPUSS_RRAMC_NVM_ADDRESS_MISMATCH_FAULT = 0x0021u,
    M33SYSCPUSS_RRAMC_MMIO_PROTECTED_LOCKABLE_FAULT = 0x0022u,
    M33SYSCPUSS_RRAMC_MMIO_UDS_CTRL_FAULT = 0x0023u,
    M33SYSCPUSS_RRAMC_NVM_TRAP_FAULT = 0x0024u,
    M33SYSCPUSS_RRAMC_NVM_IR_ECCLOG_FAULT = 0x0025u,
    M55APPCPUSS_APP_SYS_BR_ERROR_MMIO = 0x0027u,
    M55APPCPUSS_SYS_APP_BR_ERROR_MMIO = 0x0028u,
    M0SECCPUSS_FAULT_M0SEC          = 0x0029u,
    SRSS_FAULT_CSV                  = 0x002Au,
    SRSS_FAULT_SSV                  = 0x002Bu,
    SMIF_0_FAULT_MXSMIF_TOP         = 0x002Cu,
    SMIF_1_FAULT_MXSMIF_TOP         = 0x002Du,
    SOCMEM_SOCMEM_MPC               = 0x002Eu,
    SOCMEM_SOCMEM_AHB_ERROR         = 0x002Fu,
    M33SYSCPUSS_RRAMC_INVALID_LCS_FAULT = 0x0030u,
    M33SYSCPUSS_RRAMC_MMIO_RECLAIMED_REGION_SIZE_FAULT = 0x0031u,
    M33SYSCPUSS_RRAMC_RRAM_SFR_NVM_HRESP_FAULT = 0x0032u,
    M33SYSCPUSS_RRAMC_BANK_MAPPING_FAULT = 0x0033u,
    M33SYSCPUSS_RRAMC_MMIO_TB_GATING_CTL_FAULT = 0x0034u,
    M33SYSCPUSS_RRAMC_MMIO_PC_LOCK_FAULT = 0x0035u,
    CY_SYSFAULT_NO_FAULT            = 0x0036u
} en_sysfault_source_t;

/* Include IP definitions */
#include "ip/cyip_main_nvm_pse84.h"
#include "ip/cyip_non_secure_sflash_pse84.h"
#include "ip/cyip_peri_v2_1.h"
#include "ip/cyip_ppc_v2_1.h"
#include "ip/cyip_peri_pclk_v2_1.h"
#include "ip/cyip_rramc.h"
#include "ip/cyip_ramc_ppu_v2_2.h"
#include "ip/cyip_icache_v2_2.h"
#include "ip/cyip_cpuss_ppu_v2_2.h"
#include "ip/cyip_ramc_v2_1.h"
#include "ip/cyip_mxcm33_v2_1.h"
#include "ip/cyip_dw.h"
#include "ip/cyip_cpuss_v2_2.h"
#include "ip/cyip_ms_ctl_2_1_v2_2.h"
#include "ip/cyip_cpuss_sl_ctl_v2_2.h"
#include "ip/cyip_ipc.h"
#include "ip/cyip_fault.h"
#include "ip/cyip_srss_v1_1.h"
#include "ip/cyip_pwrmode_v1_1.h"
#include "ip/cyip_rtc_v1_1.h"
#include "ip/cyip_debug600_v1_2.h"
#include "ip/cyip_m0seccpuss_status_v2.h"
#include "ip/cyip_crypto_v2_1.h"
#include "ip/cyip_hsiom.h"
#include "ip/cyip_gpio.h"
#include "ip/cyip_smartio.h"
#include "ip/cyip_canfd_v4.h"
#include "ip/cyip_tcpwm_v2.h"
#include "ip/cyip_lpcomp.h"
#include "ip/cyip_scb.h"
#include "ip/cyip_i3c_v1_1.h"
#include "ip/cyip_eth_v3.h"
#include "ip/cyip_mxnnlite_2_0_v2.h"
#include "ip/cyip_ctbl_v1_1.h"
#include "ip/cyip_ptc_v1_1.h"
#include "ip/cyip_dac_v1_1.h"
#include "ip/cyip_sar_v1_1.h"
#include "ip/cyip_actrlr_v1_1.h"
#include "ip/cyip_infra_v1_1.h"
#include "ip/cyip_lppass_mmio_v1_1.h"
#include "ip/cyip_ppu_appcpuss_v1_1.h"
#include "ip/cyip_ppu_cm55_0_v1_1.h"
#include "ip/cyip_ppu_cm55_1_v1_1.h"
#include "ip/cyip_pd_v1_1.h"
#include "ip/cyip_mxcm55.h"
#include "ip/cyip_saxi_dmac.h"
#include "ip/cyip_appcpuss_v1_1.h"
#include "ip/cyip_ms_ctl_v1_1.h"
#include "ip/cyip_appcpuss_sl_ctl_v1_1.h"
#include "ip/cyip_pdm_v1_1.h"
#include "ip/cyip_tdm_v3.h"
#include "ip/cyip_smif_v6.h"
#include "ip/cyip_u55.h"
#include "ip/cyip_socmem.h"
#include "ip/cyip_gfxss.h"
#include "ip/cyip_sdhc_v2.h"
#include "ip/cyip_usbhs.h"

/* Parameter Defines */
/* AXI DMA controller-0 present or not ('0': no, '1': yes) */
#define APPCPUSS_AXIDMAC0_PRESENT       1u
/* Number of AXI DMA controller-0 channels ([1, 8]) */
#define APPCPUSS_AXIDMAC0_CH_NR         4u
/* AXI DMA controller-0 buffer depth ([64...256]) */
#define APPCPUSS_AXIDMAC0_BUFFER_DEPTH  128u
/* AXI DMA controller-1 present or not ('0': no, '1': yes) */
#define APPCPUSS_AXIDMAC1_PRESENT       0u
/* Number of AXI DMA controller-1 channels ([1, 8]) */
#define APPCPUSS_AXIDMAC1_CH_NR         2u
/* AXI DMA controller-1 buffer depth ([64...256]) */
#define APPCPUSS_AXIDMAC1_BUFFER_DEPTH  128u
/* IPC present or not ('0': no, '1': yes) */
#define APPCPUSS_IPC_PRESENT            1u
/* Number of IPC structures. Legal range [1, 16] */
#define APPCPUSS_IPC_NR                 16u
/* Number of IPC interrupt structures. Legal range [1, 16] */
#define APPCPUSS_IPC_IRQ_NR             8u
/* IRQ expander present ('0': no, '1': yes) */
#define APPCPUSS_SYSTEM_IRQ_PRESENT     0u
/* Number of system interrupt inputs to APPCPUSS */
#define APPCPUSS_SYSTEM_INT_NR          174u
/* Number of DeepSleep system interrupt inputs to APPCPUSS */
#define APPCPUSS_SYSTEM_DPSLP_INT_NR    39u
/* Number of CPU interrupts used when SYSTEM_IRQ_PRESENT is '1'. Legal values 8,
   16. */
#define APPCPUSS_CM55_INT_NR            8u
/* Individual CPU interrupts to be disabled when SYSTEM_IRQ_PRESENT is '0'. 0: To
   enable respective interrupt-bit functionality; 1: To disable respective
   interrupt-bit functionality; Default value {480{1'b0}} to enable all 480
   interrupts of CM55; Example: {479{1'b0},1'b1} disables the interrupt IRQ[0]
   of CM55 and enables all other interrupts. This parameter is NOT applicable
   when SYSTEM_IRQ_PRESENT is '1'. */
#define APPCPUSS_CM55_IRQ_DISABLE       0u
/* Specifies the CPU interrupts to support low latency or incur extra latency
   IRQTIER[n] = 0 indicates lowest latency for IRQ[n] IRQTIER[n] = 1 indicates
   highest latency for IRQ[n] If many interrupts are included IRQTIER improves
   the implemented frequency at the expense of extra interrupt latency. This
   option works when SYSTEM_IRQ_PRESENT is '0' */
#define APPCPUSS_CM55_IRQ_TIER          0u
/* CM55_0 Floating point unit present or not ('0': no, '1': yes) */
#define APPCPUSS_CM55_0_FPU_PRESENT     1u
/* CM55_0 M-profile Vector Extension (MVE) 0: MVE Extension not included 1:
   Integer MVE 2: Integer & FP MVE (requires CM55_0_FPU_PRESENT==1) */
#define APPCPUSS_CM55_0_MVE             2u
/* CM55_0 Security extension present or not ('0': no, '1': yes) */
#define APPCPUSS_CM55_0_SECEXT_PRESENT  0u
/* CM55_0 non-secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define APPCPUSS_CM55_0_MPU_NS_REGION_NR 12u
/* CM55_0 secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define APPCPUSS_CM55_0_MPU_S_REGION_NR 0u
/* CM55_0 SAU regions. Legal values [0, 4, 8] */
#define APPCPUSS_CM55_0_SAU_REGION_NR   0u
/* CM55_0 I-Cache size in Kbytes. Legal values [0, 4, 8, 16, 32] */
#define APPCPUSS_CM55_0_ICACHE_SIZE     32u
/* CM55_0 D-Cache size in Kbytes. Legal values [0, 4, 8, 16, 32] */
#define APPCPUSS_CM55_0_DCACHE_SIZE     32u
/* CM55_0 ITCM size in Kbytes. Legal values [0, 16, 32, 64, 128] */
#define APPCPUSS_CM55_0_ITCM_SIZE       256u
/* CM55_0 DTCM size in Kbytes. Legal values [0, 16, 32, 64, 128] */
#define APPCPUSS_CM55_0_DTCM_SIZE       256u
/* Number of SRAM macros used to build total ITCM size */
#define APPCPUSS_CM55_0_ITCM_MACRO_NR   4u
/* Number of SRAM macros used to build total DTCM size */
#define APPCPUSS_CM55_0_DTCM_MACRO_NR   1u
/* Specifies whether CM55_0 ITCM Gate Unit is included 0: ITGU is not included 1:
   ITGU is included Note: If CM55_0_SECEXT_PRESENT is set to 0 this parameter is
   ignored */
#define APPCPUSS_CM55_0_ITGU_PRESENT    1u
/* ITCM gate unit block size Size in bytes = 2^(CM55_0_ITGU_BLOCK_SIZE+5) Minimum
   block size: 32 bytes Maximum block size: 1 MB Typical block size is 4KBytes */
#define APPCPUSS_CM55_0_ITGU_BLOCK_SIZE 7u
/* Specifies whether CM55_0 DTCM Gate Unit is included 0: DTGU is not included 1:
   DTGU is included Note: If CM55_0_SECEXT_PRESENT is set to 0 this parameter is
   ignored */
#define APPCPUSS_CM55_0_DTGU_PRESENT    1u
/* DTCM gate unit block size Size in bytes = 2^(CM55_0_DTGU_BLOCK_SIZE+5) Minimum
   block size: 32 bytes Maximum block size: 1 MB Typical block size is 4KBytes */
#define APPCPUSS_CM55_0_DTGU_BLOCK_SIZE 7u
/* Number of CM55-0 RET switches of strength 1 */
#define APPCPUSS_CM55_0_VCCRET_MUX1_SW_NR 2u
/* Number of CM55-0 RET switches of strength 2 */
#define APPCPUSS_CM55_0_VCCRET_MUX2_SW_NR 2u
/* Number of CM55-0 RET switches of strength 3 */
#define APPCPUSS_CM55_0_VCCRET_MUX3_SW_NR 0u
/* Number of CM55-0 SRAM switches of strength 1 */
#define APPCPUSS_CM55_0_VCCSRAM_MUX1_SW_NR 2u
/* Number of CM55-0 SRAM switches of strength 2 */
#define APPCPUSS_CM55_0_VCCSRAM_MUX2_SW_NR 2u
/* Number of CM55-0 SRAM switches of strength 3 */
#define APPCPUSS_CM55_0_VCCSRAM_MUX3_SW_NR 0u
/* Num of CM55-0 ITCM pwr switches */
#define APPCPUSS_CM55_0_ITCM_SW_NR      4u
/* Num of CM55-0 DTCM pwr switches */
#define APPCPUSS_CM55_0_DTCM_SW_NR      4u
/* Num of CM55-0 ICACHE DATA pwr switches */
#define APPCPUSS_CM55_0_ICACHE_DATA_SW_NR 1u
/* Num of CM55-0 ICACHE TAG pwr switches */
#define APPCPUSS_CM55_0_ICACHE_TAG_SW_NR 1u
/* Num of CM55-0 DCACHE DATA pwr switches */
#define APPCPUSS_CM55_0_DCACHE_DATA_SW_NR 1u
/* Num of CM55-0 DCACHE TAG pwr switches */
#define APPCPUSS_CM55_0_DCACHE_TAG_SW_NR 1u
/* CM55_1 present or not. */
#define APPCPUSS_CM55_1_PRESENT         0u
/* CM55_1 Floating point unit present or not ('0': no, '1': yes) */
#define APPCPUSS_CM55_1_FPU_PRESENT     0u
/* CM55_1 M-profile Vector Extension (MVE) 0: MVE Extension not included 1:
   Integer MVE 2: Integer & FP MVE (requires CM55_0_FPU_PRESENT==1) */
#define APPCPUSS_CM55_1_MVE             0u
/* CM55_1 Security extension present or not ('0': no, '1': yes) */
#define APPCPUSS_CM55_1_SECEXT_PRESENT  0u
/* CM55_1 non-secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define APPCPUSS_CM55_1_MPU_NS_REGION_NR 0u
/* CM55_1 secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define APPCPUSS_CM55_1_MPU_S_REGION_NR 0u
/* CM55_1 SAU regions. Legal values [0, 4, 8] */
#define APPCPUSS_CM55_1_SAU_REGION_NR   0u
/* CM55_1 I-Cache size in Kbytes. Legal values [0, 4, 8, 16, 32] */
#define APPCPUSS_CM55_1_ICACHE_SIZE     0u
/* CM55_1 D-Cache size in Kbytes. Legal values [0, 4, 8, 16, 32] */
#define APPCPUSS_CM55_1_DCACHE_SIZE     0u
/* CM55_1 ITCM size in Kbytes. Legal values [0, 16, 32, 64, 128] */
#define APPCPUSS_CM55_1_ITCM_SIZE       0u
/* CM55_1 DTCM size in Kbytes. Legal values [0, 16, 32, 64, 128] */
#define APPCPUSS_CM55_1_DTCM_SIZE       0u
/* Number of SRAM macros used to build total ITCM size */
#define APPCPUSS_CM55_1_ITCM_MACRO_NR   16u
/* Number of SRAM macros used to build total DTCM size */
#define APPCPUSS_CM55_1_DTCM_MACRO_NR   16u
/* Specifies whether CM55_1 ITCM Gate Unit is included 0: ITGU is not included 1:
   ITGU is included Note: If CM55_1_SECEXT_PRESENT is set to 0 this parameter is
   ignored */
#define APPCPUSS_CM55_1_ITGU_PRESENT    0u
/* ITCM gate unit block size Size in bytes = 2^(CM55_1_ITGU_BLOCK_SIZE+5) Minimum
   block size: 32 bytes Maximum block size: 1 MB Typical block size is 4KBytes */
#define APPCPUSS_CM55_1_ITGU_BLOCK_SIZE 15u
/* Specifies whether CM55_1 DTCM Gate Unit is included 0: DTGU is not included 1:
   DTGU is included Note: If CM55_1_SECEXT_PRESENT is set to 0 this parameter is
   ignored */
#define APPCPUSS_CM55_1_DTGU_PRESENT    0u
/* DTCM gate unit block size Size in bytes = 2^(CM55_1_DTGU_BLOCK_SIZE+5) Minimum
   block size: 32 bytes Maximum block size: 1 MB Typical block size is 4KBytes */
#define APPCPUSS_CM55_1_DTGU_BLOCK_SIZE 15u
/* Number of CM55-1 RET switches of strength 1 */
#define APPCPUSS_CM55_1_VCCRET_MUX1_SW_NR 2u
/* Number of CM55-1 RET switches of strength 2 */
#define APPCPUSS_CM55_1_VCCRET_MUX2_SW_NR 2u
/* Number of CM55-1 RET switches of strength 3 */
#define APPCPUSS_CM55_1_VCCRET_MUX3_SW_NR 2u
/* Number of CM55-1 SRAM switches of strength 1 */
#define APPCPUSS_CM55_1_VCCSRAM_MUX1_SW_NR 2u
/* Number of CM55-1 SRAM switches of strength 2 */
#define APPCPUSS_CM55_1_VCCSRAM_MUX2_SW_NR 2u
/* Number of CM55-1 SRAM switches of strength 3 */
#define APPCPUSS_CM55_1_VCCSRAM_MUX3_SW_NR 2u
/* Num of CM55-1 ITCM pwr switches */
#define APPCPUSS_CM55_1_ITCM_SW_NR      1u
/* Num of CM55-1 DTCM pwr switches */
#define APPCPUSS_CM55_1_DTCM_SW_NR      1u
/* Num of CM55-1 ICACHE DATA pwr switches */
#define APPCPUSS_CM55_1_ICACHE_DATA_SW_NR 1u
/* Num of CM55-1 ICACHE TAG pwr switches */
#define APPCPUSS_CM55_1_ICACHE_TAG_SW_NR 1u
/* Num of CM55-1 DCACHE DATA pwr switches */
#define APPCPUSS_CM55_1_DCACHE_DATA_SW_NR 1u
/* Num of CM55-1 DCACHE TAG pwr switches */
#define APPCPUSS_CM55_1_DCACHE_TAG_SW_NR 1u
/* Debug level. Legal range [0,2]. 0: Minumum debug (only BKPT instruction
   support) 1: Reduced debug set (2 watchpoints and 4 break points) 2: Full
   debug set (4 watchpoints and 8 breakpoints) */
#define APPCPUSS_DEBUG_LVL              2u
/* Trace level. Legal range [0,2] 0: No trace support 1: ITM trace (ITM and TPIU)
   2: ITM and ETM trace (ITM, ETM, and TPIU) */
#define APPCPUSS_TRACE_LVL              2u
/* CPUSS external SYS master interface 0 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define APPCPUSS_SYS_MS_0_PRESENT       0u
/* CPUSS external SYS master interface 1 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define APPCPUSS_SYS_MS_1_PRESENT       0u
/* CPUSS external SYS master NVM interface 0 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define APPCPUSS_SYS_MS_0_NVM_PRESENT   0u
/* CPUSS external SYS master NVM interface 1 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define APPCPUSS_SYS_MS_1_NVM_PRESENT   0u
/* External AXI slave0 present or not ('0': No, '1': Yes) */
#define APPCPUSS_AXI_SL_0_PRESENT       1u
/* External AXI slave1 present or not ('0': No, '1': Yes) */
#define APPCPUSS_AXI_SL_1_PRESENT       1u
/* External AXI slave2 present or not ('0': No, '1': Yes) */
#define APPCPUSS_AXI_SL_2_PRESENT       0u
/* External AXI slave3 present or not ('0': No, '1': Yes) */
#define APPCPUSS_AXI_SL_3_PRESENT       0u
/* External AXI master0 present or not ('0': No, '1': Yes) */
#define APPCPUSS_AXI_MS_0_PRESENT       1u
/* External AXI master1 present or not ('0': No, '1': Yes) */
#define APPCPUSS_AXI_MS_1_PRESENT       1u
/* External AXI master2 present or not ('0': No, '1': Yes) */
#define APPCPUSS_AXI_MS_2_PRESENT       1u
/* External AXI master3 present or not ('0': No, '1': Yes) */
#define APPCPUSS_AXI_MS_3_PRESENT       1u
/* AXI Master Cyclic Dependence Avoidance Scheme, this is bitwise mask enable for
   all the masters in APPCPUSS */
#define APPCPUSS_AXI_MS_CDAS            1u
/* External AHB master0 present or not ('0': No, '1': Yes) */
#define APPCPUSS_EXP_MS_0_PRESENT       1u
/* External AHB master1 present or not ('0': No, '1': Yes) */
#define APPCPUSS_EXP_MS_1_PRESENT       1u
/* External AHB master2 present or not ('0': No, '1': Yes) */
#define APPCPUSS_EXP_MS_2_PRESENT       1u
/* External AHB master3 present or not ('0': No, '1': Yes) */
#define APPCPUSS_EXP_MS_3_PRESENT       0u
/* Specifies the AHB5 interconnect arbitration type used for generating the RTL.
   0: ROUND; round insert an extra cycle each time the downstream port selects a
   new upstream port to service and must be used to avoid timing issues when
   target frequency is >=200MHz; 1: ROUND_NOLAT; round_nolat have no such
   latency and can be used when target frequency is <200MHz; Improves the
   performance by reducing latency; */
#define APPCPUSS_AHB_INFRA_ARB_TYPE     0u
/* SRAM TYPE for ITCM SRAM (To determine ITCM SRAM memory type) */
#define APPCPUSS_SRAM_TYPE_ITCM         3u
/* SRAM TYPE for DTCM SRAM (To determine DTCM SRAM memory type) */
#define APPCPUSS_SRAM_TYPE_DTCM         3u
/* SRAM TYPE for ICACHE DATA SRAM (To determine ICACHE DATA SRAM memory type) */
#define APPCPUSS_SRAM_TYPE_ICACHE_DATA  0u
/* SRAM TYPE for DCACHE DATA SRAM (To determine DCACHE DATA SRAM memory type) */
#define APPCPUSS_SRAM_TYPE_DCACHE_DATA  0u
/* SRAM TYPE for ICACHE TAG (To determine ICACHE TAG SRAM memory type) */
#define APPCPUSS_SRAM_TYPE_ICACHE_TAG   0u
/* SRAM TYPE for DCACHE TAG (To determine ICACHE TAG SRAM memory type) */
#define APPCPUSS_SRAM_TYPE_DCACHE_TAG   4u
/* External Crystal Oscillator is present (high frequency) */
#define APPCPUSS_ECO_PRESENT            1u
/* APPCPUSS Security extension present or not ('0': no, '1': yes) */
#define APPCPUSS_APP_SECEXT_PRESENT     1u
/* CoreSight Part Identification Number */
#define APPCPUSS_JEPID                  65u
/* CoreSight Part Identification Number */
#define APPCPUSS_JEPCONTINUATION        0u
/* CoreSight Part Identification Number */
#define APPCPUSS_FAMILYID               277u
/* See MMIO2 instantiation or not */
#define APPCPUSS_CHIP_TOP_PROFILER_PRESENT 0u
/* MS_CTL_P default value */
#define APPCPUSS_MS_CTL_STRUCT_MS_CTL_P_DEFAULT 1u
/* MS_CTL_NS default value */
#define APPCPUSS_MS_CTL_STRUCT_MS_CTL_NS_DEFAULT 1u
/* MS_CTL_PC_MASK default value */
#define APPCPUSS_MS_CTL_STRUCT_MS_CTL_PC_MASK_DEFAULT 64u
/* MS_CTL_PC default value */
#define APPCPUSS_MS_PC_STRUCT_MS_CTL_PC_DEFAULT 6u
/* Number of DMA channels */
#define AXI_DMAC_CH_NR                  4u
/* Software trigger present or not */
#define AXI_DMAC_SW_TR_PRESENT          1u
/* Number of TTCAN instances */
#define CANFD_CAN_NR                    2u
/* ECC logic present or not */
#define CANFD_ECC_PRESENT               0u
/* address included in ECC logic or not */
#define CANFD_ECC_ADDR_PRESENT          0u
/* Time Stamp counter present or not (required for instance 0, otherwise not
   allowed) */
#define CANFD_TS_PRESENT                1u
/* Message RAM size in KB */
#define CANFD_MRAM_SIZE                 8u
/* Message RAM address width */
#define CANFD_MRAM_ADDR_WIDTH           11u
/* System RAM 0 MPC protection block size in Bytes: 1<< (RAMC0_BLOCK_SIZE+5).
   Example: 7 = 4KB protection block size. */
#define CPUSS_RAMC0_BLOCK_SIZE          7u
/* Number of macros used to implement System RAM 0. Example: 8 if 256 KB System
   SRAM0 is implemented with 8 32KB macros. */
#define CPUSS_RAMC0_MACRO_NR            8u
/* Number of power partitions in system RAM 0. Each power partition can be
   independently power controlled using a switch. Example: RAMC0_MACRO_NR = 16
   and RAMC0_PWR_GROUP_NR = 4 will create 4 power partitions with 4 macros in
   each power partition. */
#define CPUSS_RAMC0_PWR_GROUP_NR        8u
/* System RAM 1 present or not (0=No, 1=Yes) */
#define CPUSS_RAMC1_PRESENT             1u
/* System RAM 1 MPC protection block size in Bytes: 1<< (RAMC1_BLOCK_SIZE+5).
   Example: 7 = 4KB protection block size. */
#define CPUSS_RAMC1_BLOCK_SIZE          7u
/* Number of macros used to implement System RAM 1. Example: 8 if 256 KB System
   RAM 1 is implemented with 8 32KB macros. */
#define CPUSS_RAMC1_MACRO_NR            8u
/* Number of power partitions in system RAM 1. Each power partition can be
   independently power controlled using a switch. Example: RAMC1_MACRO_NR = 16
   and RAMC1_PWR_GROUP_NR = 4 will create 4 power partitions with 4 macros in
   each power partition. */
#define CPUSS_RAMC1_PWR_GROUP_NR        8u
/* System RAM 2 present or not (0=No, 1=Yes) */
#define CPUSS_RAMC2_PRESENT             0u
/* System RAM 2 MPC protection block size in Bytes: 1<< (RAMC2_BLOCK_SIZE+5).
   Example: 7 = 4KB protection block size. */
#define CPUSS_RAMC2_BLOCK_SIZE          7u
/* Number of macros used to implement System RAM 2. Example: 8 if 256 KB System
   RAM 2 is implemented with 8 32KB macros. */
#define CPUSS_RAMC2_MACRO_NR            1u
/* Number of power partitions in system RAM 2. Each power partition can be
   independently power controlled using a switch. Example: RAMC2_MACRO_NR = 16
   and RAMC2_PWR_GROUP_NR = 4 will create 4 power partitions with 4 macros in
   each power partition. */
#define CPUSS_RAMC2_PWR_GROUP_NR        1u
/* System SRAM(s) ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_PRESENT          0u
/* System SRAM(s) address ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_ADDR_PRESENT     0u
/* System Patchable ROM Controller Present or not ('0' : no, '1': yes) */
#define CPUSS_PROMC_PRESENT             0u
/* Number of macros used to implement system patchable ROM. Example: 4 if 512 KB
   system patchable ROM is implemented with 4 128KB macros. */
#define CPUSS_PROMC_MACRO_NR            1u
/* PROMC memory block size for protection scheme : 1<< (PROMC_BLOCK_SIZE+5).
   Example: 7 = 4KB protection block size. */
#define CPUSS_PROMC_BLOCK_SIZE          6u
/* Presence of the patch functionality. 0: ROM cannot be patched. 1: ROM can be
   patched. */
#define CPUSS_PROMC_PATCH_PRESENT       0u
/* Number of patchable locations (patch entries). Possible range [32,512] in
   powers of 2. (BRCM: 512 is only supported) These are implemented using SRAM.
   (SNPS: 32x128, 64x128, 128x128, 256x128, 512x128 are supported; BRCM: 4
   instances of 512x32 only supported) */
#define CPUSS_PROMC_PATCH_NR            64u
/* Patch size selection of a single structure. 0: 8 Bytes. 1: 16 Bytes. **) 2: 32
   Bytes. 3: 64 Bytes. **) The patch size should fit to the word size of the
   ROM. Thus only PATCH_SIZE=1 is supported for this ROM controller. */
#define CPUSS_PROMC_PATCH_SIZE          1u
/* Width of compared address bits. The LSB is determined by the PATCH_SIZE, for 16
   bytes this equals to bit [4]. The MSB is chosen to address the full size of
   the ROM in bytes. */
#define CPUSS_PROMC_MATCH_ADDR_SIZE     12u
/* Initial value of the first patchable address in the ROM. This address and the
   following higher addresses are patchable if the function is enabled. */
#define CPUSS_PROMC_SROM_BOUNDARY       0x00001000u
/* RRAM Controller Present or not ('0' : no, '1': yes) */
#define CPUSS_RRAMC_PRESENT             1u
/* RRAM NVM memory size in KB */
#define CPUSS_RRAMC_NVM_SIZE            512u
/* Size of RRAM Extra region */
#define CPUSS_RRAMC_EXTRA_REGION_SIZE   16u
/* RRAMC MPC protection block size in Bytes: 1<< (RRAMC_BLOCK_SIZE+5). Example: 7
   = 4KB protection block size. */
#define CPUSS_RRAMC_BLOCK_SIZE          7u
/* Main NVM region start address */
#define CPUSS_RRAMC_MAIN_START_ADDRESS  0x02000000u
/* Work NVM region start address */
#define CPUSS_RRAMC_WORK_START_ADDRESS  0x03000000u
/* Sflash NVM region start address */
#define CPUSS_RRAMC_SFLASH_START_ADDRESS 0x03600000u
/* Protected NVM region start address */
#define CPUSS_RRAMC_PROTECTED_START_ADDRESS 0x03C00000u
/* Main NVM region size in multiples of 8KB (8KB*N) */
#define CPUSS_RRAMC_MAIN_N              32u
/* Work NVM region size in multiples of 8KB (8KB*Z) */
#define CPUSS_RRAMC_WORK_Z              0u
/* Sflash NVM region size in multiples of 8KB (8KB*Y) */
#define CPUSS_RRAMC_SFLASH_Y            0u
/* Protected NVM region size in multiples of 8KB (8KB*X) */
#define CPUSS_RRAMC_PROTECTED_X         32u
/* Address of Session key for encoding/decoding Secure data */
#define CPUSS_RRAMC_SESSION_KEY_ADDRESS 0x40051000u
/* Default value of the 32-bit Session key */
#define CPUSS_RRAMC_SESSION_KEY_VALUE   0x16071971u
/* Bootrow Block Address [21:4] */
#define CPUSS_BOOTROW_BLOCK_ADDRESS     0x00008000u
/* Start address for "a defined space in RRAM Secure OTP region to be blocked when
   test_block_nvm is 1" */
#define CPUSS_RRAMC_BLOCK_START         16u
/* End address for "a defined space in RRAM Secure OTP region to be blocked when
   test_block_nvm is 1" */
#define CPUSS_RRAMC_BLOCK_END           507u
/* DataWire 0 present or not ('0': no, '1': yes) */
#define CPUSS_DW0_PRESENT               1u
/* Number of DataWire 0 channels (8, 16 or 32) */
#define CPUSS_DW0_CH_NR                 16u
/* DataWire 1 present or not ('0': no, '1': yes) */
#define CPUSS_DW1_PRESENT               1u
/* Number of DataWire 1 channels (8, 16 or 32) */
#define CPUSS_DW1_CH_NR                 16u
/* DataWire SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_PRESENT            0u
/* DataWire SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_ADDR_PRESENT       0u
/* DMA controller-0 present or not ('0': no, '1': yes) */
#define CPUSS_DMAC0_PRESENT             0u
/* Number of DMA controller-0 channels ([1, 8]) */
#define CPUSS_DMAC0_CH_NR               1u
/* DMA controller-1 present or not ('0': no, '1': yes) */
#define CPUSS_DMAC1_PRESENT             0u
/* Number of DMA controller-1 channels ([1, 8]) */
#define CPUSS_DMAC1_CH_NR               1u
/* Number of IPC structures. Legal range [1, 16] */
#define CPUSS_IPC_NR                    16u
/* Number of IPC interrupt structures. Legal range [1, 16] */
#define CPUSS_IPC_IRQ_NR                8u
/* Number of protection contexts supported. Legal range [3, 4, 6, 8] (CDT-336698) */
#define CPUSS_PC_NR                     8u
/* CM33_0 PC monitor present or not */
#define CPUSS_CM33_0_PC_MON_PRESENT     1u
/* System interrupt functionality present or not ('0': no; '1': yes). Not used for
   CM0+ PCU, which always uses system interrupt functionality. */
#define CPUSS_SYSTEM_IRQ_PRESENT        0u
/* Number of total interrupt request inputs to CPUSS */
#define CPUSS_SYSTEM_INT_NR             197u
/* Number of DeepSleep wakeup interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_DPSLP_INT_NR       59u
/* SYSCPUSS Security extension present or not ('0': no, '1': yes) */
#define CPUSS_SYS_SECEXT_PRESENT        1u
/* Number of CPU interrupts used when SYSTEM_IRQ_PRESENT is '1'. Legal values 8,
   16. */
#define CPUSS_CM33_INT_NR               8u
/* Individual CPU interrupts to be disabled when SYSTEM_IRQ_PRESENT is '0'. 0: To
   enable respective interrupt-bit functionality; 1: To disable respective
   interrupt-bit functionality; Default value {480{1'b0}} to enable all 480
   interrupts of CM33; Example: {479{1'b0},1'b1} disables the interrupt IRQ[0]
   of CM33 and enables all other interrupts. This parameter is NOT applicable
   when SYSTEM_IRQ_PRESENT is '1'. */
#define CPUSS_CM33_IRQ_DISABLE          0u
/* CM33_0 Floating point unit present or not ('0': no, '1': yes) */
#define CPUSS_CM33_0_FPU_PRESENT        1u
/* CM33_0 DSP extension present or not ('0': no, '1': yes) */
#define CPUSS_CM33_0_DSP_PRESENT        1u
/* CM33_0 Security extension present or not ('0': no, '1': yes) */
#define CPUSS_CM33_0_SECEXT_PRESENT     1u
/* CM33_0 non-secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define CPUSS_CM33_0_MPU_NS_REGION_NR   8u
/* CM33_0 secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define CPUSS_CM33_0_MPU_S_REGION_NR    8u
/* CM33_0 SAU regions. Legal values [0, 4, 8] */
#define CPUSS_CM33_0_SAU_REGION_NR      8u
/* CM33_0 default WAIT value; 0: CM33_0 will start code execution after reset
   release; 1: CM33_0 will wait until SE or FW to clear this bit to start code
   execution after reset release. */
#define CPUSS_CM33_0_WAIT_DEFAULT       1u
/* Default value for CM33 Secure Vector table base address */
#define CPUSS_CM33_S_VECTOR_TABLE_DEFAULT 0x00680000u
/* Default value for CM33 Non-secure Vector table base address */
#define CPUSS_CM33_NS_VECTOR_TABLE_DEFAULT 0x00480000u
/* CM33_1 present or not. */
#define CPUSS_CM33_1_PRESENT            0u
/* CM33_1 Floating point unit present or not ('0': no, '1': yes) */
#define CPUSS_CM33_1_FPU_PRESENT        0u
/* CM33_1 DSP extension present or not ('0': no, '1': yes) */
#define CPUSS_CM33_1_DSP_PRESENT        0u
/* CM33_1 Security extension present or not ('0': no, '1': yes) */
#define CPUSS_CM33_1_SECEXT_PRESENT     0u
/* CM33_1 non-secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define CPUSS_CM33_1_MPU_NS_REGION_NR   0u
/* CM33_1 secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define CPUSS_CM33_1_MPU_S_REGION_NR    0u
/* CM33_1 SAU regions. Legal values [0, 4, 8] */
#define CPUSS_CM33_1_SAU_REGION_NR      0u
/* Cache RAM size in Kilo Bytes; Supported values are [8, 16, 32]. */
#define CPUSS_CACHE_SIZE                16u
/* Cache RAM ECC present or not ('0': no, '1': yes) */
#define CPUSS_CACHE_RAM_ECC_PRESENT     0u
/* Debug level. Legal range [0,3] (0= No support, 1= Minimum: CM0/4 both 2
   breakpoints +1 watchpoint, 2= Full debug: CM0/4 have 4/6 breakpoints, 2/4
   watchpoints and 0/2 literal compare, 3= Full debug + data matching) */
#define CPUSS_DEBUG_LVL                 2u
/* Trace level. Legal range [0,2] (0= No tracing, 1= ITM + TPIU + SWO, 2= ITM +
   ETM + TPIU) */
#define CPUSS_TRACE_LVL                 2u
/* PTM interface present (0=No, 1=Yes) */
#define CPUSS_PTM_PRESENT               0u
/* CPUSS external CODE master interface 0 present or not on CODE infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_CODE_MS_0_PRESENT         1u
/* CPUSS external SYS master interface 0 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_SYS_MS_0_PRESENT          1u
/* CPUSS external SYS master interface 1 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_SYS_MS_1_PRESENT          1u
/* CPUSS external SYS master NVM interface 0 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_SYS_MS_0_NVM_PRESENT      0u
/* CPUSS external SYS master NVM interface 1 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_SYS_MS_1_NVM_PRESENT      0u
/* Number of external AHB5 slave interfaces connected to SYSTEM infrastructure.
   Maximum number of slaves supported is 4. Width of this parameter is 4-bits.
   1-bit mask for each slave indicating present or not. Example: 4'b0001 - slave
   0 is present. */
#define CPUSS_SYS_SL_PRESENT            7u
/* Number of external EXPANSION masters driving the EXP AHB5 infrastructure.
   Maximum number of masters supported is 8. Width of this parameter is 8-bits.
   1-bit mask for each master indicating present or not. Example: 8'b0000_0101 -
   master 0 & master 2 are present. */
#define CPUSS_EXP_MS_PRESENT            7u
/* The timing de-coupled AHB brdige is present or not on the output of EXP
   infrastructure. ('0': no, '1':yes) */
#define CPUSS_EXP_BRIDGE_PRESENT        0u
/* Specifies the CODE interconnect arbitration type used for generating the RTL.
   0: ROUND; round insert an extra cycle each time the downstream port selects a
   new upstream port to service and must be used to avoid timing issues when
   target frequency is >=100MHz; 1: ROUND_NOLAT; round_nolat have no such
   latency and can be used when target frequency is <100MHz; Improves the
   performance by reducing latency; */
#define CPUSS_CODE_INFRA_ARB_TYPE       1u
/* Specifies the SYSTEM interconnect arbitration type used for generating the RTL.
   0: ROUND; round insert an extra cycle each time the downstream port selects a
   new upstream port to service and must be used to avoid timing issues when
   target frequency is >=100MHz; 1: ROUND_NOLAT; round_nolat have no such
   latency and can be used when target frequency is <100MHz; Improves the
   performance by reducing latency; */
#define CPUSS_SYSTEM_INFRA_ARB_TYPE     1u
/* Specifies the EXPANSION interconnect arbitration type used for generating the
   RTL. 0: ROUND; round insert an extra cycle each time the downstream port
   selects a new upstream port to service and must be used to avoid timing
   issues when target frequency is >=100MHz; 1: ROUND_NOLAT; round_nolat have no
   such latency and can be used when target frequency is <100MHz; Improves the
   performance by reducing latency; */
#define CPUSS_EXP_INFRA_ARB_TYPE        1u
/* ROM trim register width (for ARM 3, for Synopsys 5, for BRCM 6) */
#define CPUSS_ROM_TRIM_WIDTH            4u
/* ROM trim register default (for both ARM and Synopsys 0x0000_0002; for BRCM
   0x0000_0000) */
#define CPUSS_ROM_TRIM_DEFAULT          10u
/* Embedded Trace Buffer in mxdebug600 present or not ('0': no, '1': yes) */
#define CPUSS_ETB_PRESENT               1u
/* SRAM_TYPE for CM33-0 Cache SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_CM33_0_CACHE    0u
/* SRAM_TYPE for CM33-1 Cache SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_CM33_1_CACHE    0u
/* SRAM_TYPE for DW0 SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_DW0             4u
/* SRAM_TYPE for DW1 SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_DW1             4u
/* SRAM_TYPE for RAMC0 MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC0_MPC       4u
/* SRAM_TYPE for RAMC1 MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC1_MPC       4u
/* SRAM_TYPE for RAMC2 MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC2_MPC       4u
/* SRAM_TYPE for RRAMC MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RRAMC_MPC       4u
/* SRAM_TYPE for PROMC MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_PROMC_MPC       4u
/* SRAM_TYPE for RAMC0 System SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC0           0u
/* SRAM_TYPE for RAMC1 System SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC1           0u
/* SRAM_TYPE for RAMC2 System SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC2           0u
/* SRAM_TYPE for PROMC Patch SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_PROMC_PATCH     5u
/* Specifies the CM33-0 CACHE SRAM POWER SWITCH is present or not; 0: Not present;
   1: Present; */
#define CPUSS_CM33_0_CACHE_SWITCH_PRESENT 1u
/* Specifies the CM33-1 CACHE SRAM POWER SWITCH is present or not; 0: Not present;
   1: Present; */
#define CPUSS_CM33_1_CACHE_SWITCH_PRESENT 0u
/* Specifies the DW-0 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_DW0_SWITCH_PRESENT        1u
/* Specifies the DW-1 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_DW1_SWITCH_PRESENT        1u
/* Specifies the MPC SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_MPC_SWITCH_PRESENT        1u
/* Specifies the PROMC Patch-SRAM POWER SWITCH is present or not; 0: Not present;
   1: Present; */
#define CPUSS_PROMC_SWITCH_PRESENT      1u
/* Specifies the RAMC-0 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_RAMC0_SRAM_SWITCH_PRESENT 1u
/* Specifies the RAMC-1 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_RAMC1_SRAM_SWITCH_PRESENT 1u
/* Specifies the RAMC-2 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_RAMC2_SRAM_SWITCH_PRESENT 0u
/* External Crystal Oscillator is present (high frequency) */
#define CPUSS_ECO_PRESENT               1u
/* Number of Fault reporting structures; Legal range [1, 4] */
#define CPUSS_FAULT_NR                  2u
/* FlashC controller is present or not. 0: Not present 1: Present */
#define CPUSS_FLASHC_PRESENT            0u
/* ECC present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_ECC_PRESENT        1u
/* Start address of 33rd column */
#define CPUSS_FLASHC_COLUMN_33_START_ADDRESS 0x1FFFFFFCu
/* Main region start address */
#define CPUSS_FLASHC_MAIN_START_ADDRESS 0x1FFFFFFCu
/* Work region start address */
#define CPUSS_FLASHC_WORK_START_ADDRESS 0x1FFFFFFCu
/* SFLASH region start address */
#define CPUSS_FLASHC_SFLASH_START_ADDRESS 0x1FFFFFFCu
/* Refresh rows start address */
#define CPUSS_FLASHC_REFRESH_ROW_START_ADDRESS 0x1FFFFFFCu
/* FM MMIO start address */
#define CPUSS_FM_MMIO_START_ADDRESS     0x5FFFFFFCu
/* mxs40flashc MMIO start address */
#define CPUSS_FLASHC_MMIO_START_ADDRESS 0x5FFFFFFCu
/* mxs40flashc MPC MMIO start address */
#define CPUSS_FLASHC_MPC_START_ADDRESS  0x5FFFFFFCu
/* Number of sectors in FM */
#define CPUSS_FLASHC_SECTOR_M           4u
/* Size of MAIN NVM in 8 KB blocks for each pair of sectors. */
#define CPUSS_FLASHC_MAIN_N             64u
/* Size of WORK NVM in 8 KB blocks for each pair of sectors. */
#define CPUSS_FLASHC_WORK_Z             64u
/* Size of SFLASH NVM in 8 KB blocks in Sector 1. */
#define CPUSS_FLASHC_SFLASH_Y           32u
/* Size of refresh rows for each sector. */
#define CPUSS_FLASHC_REFRESH_ROW        64u
/* SFLASH sector number */
#define CPUSS_FLASHC_SFLASH_SECNUM      1u
/* Number of rows per sector */
#define CPUSS_FLASHC_ROWS_PER_SECTOR    512u
/* CM330 HMASTER ID */
#define CPUSS_CM33_0_HMASTER_ID         8u
/* CM331 HMASTER ID */
#define CPUSS_CM33_1_HMASTER_ID         0x0000FFFFu
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     65u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_FAMILYID                  277u
/* System RAM 0 size in KB */
#define CPUSS_CHIP_TOP_RAMC0_SIZE       512u
/* System RAM 1 size in kilobytes */
#define CPUSS_CHIP_TOP_RAMC1_SIZE       512u
/* System RAM 2 size in kilobytes */
#define CPUSS_CHIP_TOP_RAMC2_SIZE       1u
/* System Patchable ROM size in KB */
#define CPUSS_CHIP_TOP_PROMC_SIZE       64u
/* See MMIO2 instantiation or not */
#define CPUSS_CHIP_TOP_PROFILER_PRESENT 0u
/* ETAS Calibration support pin out present (automotive only) */
#define CPUSS_CHIP_TOP_CAL_SUP_NZ_PRESENT 0u
/* TRACE_LVL>0 */
#define CPUSS_CHIP_TOP_TRACE_PRESENT    1u
/* Width of HPROT */
#define CPUSS_CHIP_TOP_HPROT_WIDTH      7u
/* MS_CTL_P (Privileged) default value */
#define CPUSS_MS_CTL_STRUCT_MS_CTL_P_DEFAULT 1u
/* MS_CTL_NS (Non-secure) default value */
#define CPUSS_MS_CTL_STRUCT_MS_CTL_NS_DEFAULT 0u
/* MS_CTL_PC_MASK default value */
#define CPUSS_MS_CTL_STRUCT_MS_CTL_PC_MASK_DEFAULT 4u
/* Number of protection contexts supported. Legal range [3, 4, 6, 8] (CDT-336698) */
#define CPUSS_MS_CTL_STRUCT_PC_NR       8u
/* MS_CTL_PC (Protection Context) default value */
#define CPUSS_MS_PC_STRUCT_MS_CTL_PC_DEFAULT 2u
/* Cryptography SRAMs ECC present or not ('0': no, '1': yes) */
#define CRYPTO_ECC_PRESENT              0u
/* Cryptography SRAMs address ECC present or not ('0': no, '1': yes) */
#define CRYPTO_ECC_ADDR_PRESENT         0u
/* AES cipher support ('0': no, '1': yes) */
#define CRYPTO_AES                      1u
/* (Tripple) DES cipher support ('0': no, '1': yes) */
#define CRYPTO_DES                      1u
/* Chacha support ('0': no, '1': yes) */
#define CRYPTO_CHACHA                   1u
/* Pseudo random number generation support ('0': no, '1': yes) */
#define CRYPTO_PR                       1u
/* SHA1 hash support ('0': no, '1': yes) */
#define CRYPTO_SHA1                     1u
/* SHA2 hash support ('0': no, '1': yes) */
#define CRYPTO_SHA2                     1u
/* SHA3 hash support ('0': no, '1': yes) */
#define CRYPTO_SHA3                     1u
/* Cyclic Redundancy Check support ('0': no, '1': yes) */
#define CRYPTO_CRC                      1u
/* True random number generation support ('0': no, '1': yes) */
#define CRYPTO_TR                       1u
/* Vector unit support ('0': no, '1': yes) */
#define CRYPTO_VU                       1u
/* Galios/Counter Mode (GCM) support ('0': no, '1': yes) */
#define CRYPTO_GCM                      1u
/* Number of 32-bit words in the IP internal memory buffer (from the set [64, 128,
   256, 512, 1024, 2048, 4096], to allow for a 256 B, 512 B, 1 kB, 2 kB, 4 kB, 8
   kB and 16 kB memory buffer) */
#define CRYPTO_BUFF_SIZE                1024u
/* Decides Trim variant in MXS22 Platform - SRAM_TYPE = 0: S22:ULL:D114:HVT:SRAM -
   SRAM_TYPE = 1: S22:ULL:D114:RVT:SRAM - SRAM_TYPE = 2: S22:ULL:D140:HVT:SRAM -
   SRAM_TYPE = 3: S22:ULL:D140:RVT:SRAM - SRAM_TYPE = 4: S22:ULL:D140:HVT:RF -
   SRAM_TYPE = 5: S22:ULL:D140:RVT:RF - SRAM_TYPE = 6: S22:ULL:D217:HVT:RF -
   SRAM_TYPE = 7: S22:ULL:D217:RVT:RF */
#define CRYPTO_SRAM_TYPE                0u
/* Used to define signal width of "mmio_trim_ram_ctl_trim" to support separate RF
   and SRAM trims */
#define CRYPTO_TRIM_WIDTH               32u
/* 0=ULL65, 1=MXS40-ULP, 2=MXS40E, 3=M0S8, 4=MXS40-HD, 5=F45, 6=MXS40v2, 7=T28HPM,
   8=T28HPL, 9=T28HPC */
#define CRYPTO_PLATFORM_VARIANT         10u
/* RAM vendor (0=Cypress, 1=Synopsys, 2=ARM, 3=Broadcom,4=TSMC) */
#define CRYPTO_RAM_VEND                 2u
/* IP MMIO registers base address in the system address space (32-bit Byte address
   at a 64 kB multiple). The IP MMIO registers occupy a 64 kB memory region in
   the system address space. */
#define CRYPTOLITE_ADDR_BASE            0x40080000u
/* IP master identifier. For the MXS40 platform, this parameter is used as the IP
   master identifier "ms[3:0]" (encoded on "hmaster[3:0]") for outgoing AHB-Lite
   transfers. */
#define CRYPTOLITE_CRYPTO_MS            7u
/* ECC present or not ('0': no, '1': yes). */
#define CRYPTOLITE_ECC_PRESENT          0u
/* True random number generation component support ('0': no, '1': yes). */
#define CRYPTOLITE_TRNG_PRESENT         0u
/* Vector unit component support ('0': no, '1': yes). */
#define CRYPTOLITE_VU_PRESENT           1u
/* SHA-256 hash component support ('0': no, '1': yes). */
#define CRYPTOLITE_SHA_PRESENT          1u
/* AES-128 block cipher component support ('0': no, '1': yes). */
#define CRYPTOLITE_AES_PRESENT          0u
/* Is Cryptolite at SoC level */
#define CRYPTOLITE_CHIP_TOP_CRYPTOLITE_IN_SOC 0u
/* Trace level. Legal range [0,2] 0: No trace support 1: ITM trace (ITM, TPIU, and
   SWO) 2: ITM and ETM trace (ITM, ETM, TPIU, and SWO) Note: No support for CM33
   MTB. ETB present or not is determined by separate ETB_PRESENT parameter. */
#define DEBUG600_TRACE_LVL              2u
/* Embedded Trace Buffer present or not ('0': no, '1': yes) */
#define DEBUG600_ETF_PRESENT            1u
/* Width of the TPIU interface in bits ([1,4]) */
#define DEBUG600_TPIU_WIDTH             4u
/* Compiled cells vendor: 1:SNPS, 2:ARM, 3:BRCM */
#define DEBUG600_RAM_VEND               2u
/* PLATFORM VARIANT for ITCM SRAM (To determine ITCM SRAM memory type) */
#define DEBUG600_PLATFORM_VARIANT       10u
/* ECOREV Value to the Coresight components */
#define DEBUG600_REVAND                 0u
/* CM55_0 present or not. */
#define DEBUG600_CM55_0_PRESENT         1u
/* CM55_1 present or not. */
#define DEBUG600_CM55_1_PRESENT         0u
/* CM33_1 present or not. */
#define DEBUG600_CM33_1_PRESENT         0u
/* Length of JTAG instruction register. Supported Values [4,8] */
#define DEBUG600_JTAG_IR_LENGTH         8u
/* CoreSight Part Identification Number */
#define DEBUG600_JEPID                  65u
/* CoreSight Part Identification Number */
#define DEBUG600_JEPCONTINUATION        0u
/* CoreSight Part Identification Number */
#define DEBUG600_FAMILYID               277u
/* VT type of instantiated tech cells through mxtk. */
#define DEBUG600_CELL_VT_TYPE           0u
/* Number of HFCLK roots present. Must be > 0. Must be same as set for SRSS */
#define DFT_NUM_HFROOT                  14u
/* Width of clk_occ_fast output bus (number of external OCCs) */
#define DFT_EXT_OCC                     11u
/* Number of PLLs usable as struct mode clock source (number of clk_occ_fast
   clocks). Not expected to be more than 4 */
#define DFT_NUM_FASTCLK                 3u
/* Number of select signals to control each FASTCLK multiplexer. Not expected to
   be more than 2 */
#define DFT_NUM_FASTCLK_SEL             2u
/* Number of MBIST controllers with corresponding mbist(pg)_done and mbist(pg)_go
   signals. Value defined by CIC during Pass 1. */
#define DFT_MBIST_C_NUM                 8u
/* Number of LBIST controllers. One LBIST controller on top level and one LBIST
   controller in each optional HDFT block */
#define DFT_LBIST_C_NUM                 1u
/* Number of MBISR chains. Separate chains are required for power domains that can
   be enabled independently */
#define DFT_MBISR_CH_NUM                1u
/* Defines if (Burn-In) Monitor function is present */
#define DFT_MONITOR_PRESENT             0u
/* Defines if Mentor BISR controller is present (controls generation of control
   and status register) */
#define DFT_MENTOR_BISR_PRESENT         1u
/* Defines if Direct MBIST Access function is present (controls generation of
   control and status registers) */
#define DFT_DIRECT_MBIST_ACCESS_PRESENT 1u
/* Defines if DIRECT_MBIST*SEL and DIRECT_MBIST*_RESULT registers are generated
   (only used for DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_CTRL_ACCESS_PRESENT 1u
/* Controls generation of BIST_STEP_SEL_EN and BIST_STEP_SEL register fields
   within DIRECT_MBIST_CTL reg (only used for DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_STEP_ACCESS_PRESENT 1u
/* Controls generation of BIST_MEM_SEL_EN and BIST_MEM_SEL register fields within
   DIRECT_MBIST_CTL reg (only used for DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_MEM_ACCESS_PRESENT 0u
/* Number of HLBs with Direct MBIST Access function (only used for
   DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_BAP_NUM        2u
/* Maximum value of MBIST controllers connected to single BAP (only used for
   DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_CTRL_NUM       8u
/* local parameter: chooses to instantiate mxdft_rram_gasket or not - depends on
   whether Rram is used to store repair signature */
#define DFT_RRAM_REPAIR_STORAGE         1u
/* Must be set to 1 when using this mxdft version in MXS40Sv2 devices */
#define DFT_PLATFORM_MXS40SV2           1u
/* Number of AHB5 "hmaster[]" bits ([1, 8]). */
#define DFT_MASTER_WIDTH                6u
/* Number of AHB5 "huser[]" bits ([1, 8]). */
#define DFT_USER_WIDTH                  4u
/* local parameter: Number of repair bytes allocated in the Rram for storing the
   repair signature */
#define DFT_NUM_REP_BYTE                128u
/* Determines the size of the repair cache - it's generally
   2^CACHE_ADDR_W*8+(2^CACHE_ADDR_W)*2+The total number of tag bits */
#define DFT_CACHE_ADDR_W                5u
/* Ring Oscillator Instantiation Enablement parameter */
#define DFT_RING_OSC_INST               1u
/* Number of edt IO channels */
#define DFT_NUM_EDT_CHAN                5u
/* SHIFT_DR Code */
#define DFT_SHIFT_DR                    2u
/* EXIT1_DR - EXIT1_DR FSM Code */
#define DFT_EXIT1_DR                    1u
/* RUN_TEST_IDLE - run test idle FSM code */
#define DFT_RUN_TEST_IDLE               12u
/* CLK_HF_MUX_BYP_BUF - bypass OCC muxing logic */
#define DFT_CLK_HF_MUX_BYP_BUF          0u
/* Used for mxdft_tap: controls generation of logic for "TDR capture&update via
   MMIO" (default value is 1) */
#define DFT_CAP_UP_PRESENT              0u
/* Rram Controller SRAM Repair OTP Offset */
#define DFT_NVM_OFFSET                  0x42208000u
/* Number of DataWire channels ([1, 512]) */
#define DW0_CH_NR                       16u
/* DataWire SRAM ECC present or not ('0': no, '1': yes) */
#define DW0_ECC_PRESENT                 0u
/* DataWire SRAM address ECC present or not ('0': no, '1': yes) */
#define DW0_ECC_ADDR_PRESENT            0u
#define DW0_CH_NR_WIDTH                 1u
#define DW0_CH_STRUCT_ECC_PRESENT       0u
/* Number of DataWire channels ([1, 512]) */
#define DW1_CH_NR                       16u
/* DataWire SRAM ECC present or not ('0': no, '1': yes) */
#define DW1_ECC_PRESENT                 0u
/* DataWire SRAM address ECC present or not ('0': no, '1': yes) */
#define DW1_ECC_ADDR_PRESENT            0u
#define DW1_CH_NR_WIDTH                 1u
#define DW1_CH_STRUCT_ECC_PRESENT       0u
/* AXI Master present ([0,1]): 0 - AHB master interface is present 1 - AXI master
   interface is present. */
#define ETH_AXI_MASTER_PRESENT          0u
/* TX Packet Buffer Size (jumbo frame size is 1.5KB): 00: 16KB to support four
   queues with capacity for two jumbo frames; 01: 8KB to support two queues with
   capacity for two jumbo frames or four queues with capacity for one jumbo
   frame; 10: 4KB to support one queue with capacity for two jumbo frames or two
   queues with capacity for one jumbo frame; 11: 2KB to support one queue with
   capacity for one jumbo frame; Note: mxeth supports 01 only. */
#define ETH_TX_PACKET_BUFFER_SIZE       1u
/* RX Packet Buffer Size (jumbo frame size is 1.5KB): 00: 4KB to support capacity
   for two jumbo frames; 01: 2KB to support capacity for one jumbo frames; Note:
   mxeth supports 00 only. */
#define ETH_RX_PACKET_BUFFER_SIZE       0u
/* This parameter is used to specify if mxeth should contain a clock divider. The
   clock divider is useful for chips where multiple mxeth are instantiated as it
   allows a single source PLL to be used 0=No Divider, ref_clk_int_in is used as
   is 1=Divider instantiated, ref_clk_int_in should be 125MHz */
#define ETH_SRC_CLOCK_DIVIDER           1u
/* Number of Priority Queues. */
#define ETH_ETH_NPQ                     3u
/* RMII internal clock mode support */
#define ETH_CHIP_TOP_MXETH_RMII_INT_MODE_EN 1u
/* RGMII internal clock mode support */
#define ETH_CHIP_TOP_MXETH_RGMII_INT_MODE_EN 0u
/* GMII internal clock mode support */
#define ETH_CHIP_TOP_MXETH_GMII_INT_MODE_EN 0u
/* Ethernet MII Interface Supported */
#define ETH_CHIP_TOP_MXETH_MII_SUPPORTED 1u
/* Ethernet RMII Interface Supported */
#define ETH_CHIP_TOP_MXETH_RMII_SUPPORTED 1u
/* Ethernet GMII Interface Supported */
#define ETH_CHIP_TOP_MXETH_GMII_SUPPORTED 0u
/* Ethernet RGMII Interface Supported */
#define ETH_CHIP_TOP_MXETH_RGMII_SUPPORTED 0u
/* Cache SRAM ECC present or not ('0': no, '1': yes) */
#define ICACHE_ECC_PRESENT              0u
/* Security extension present ('0': no, '1': yes) */
#define IOSS_SECEXT                     1u
/* Number of GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_NR_0_31     22u
/* Number of GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_NR_32_63    0u
/* Number of GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_NR_64_95    0u
/* Number of GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_NR_96_127   0u
/* GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_B_0_31      1u
/* GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_B_32_63     0u
/* GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_B_64_95     0u
/* GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_B_96_127    0u
/* Secure GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_SEC_B_0_31  1u
/* Secure GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_SEC_B_32_63 0u
/* Secure GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_SEC_B_64_95 0u
/* Secure GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_SEC_B_96_127 0u
/* Number of ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          22u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO 0u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLEW_EXT 0u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVE_EXT 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVEMODE_EXT 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLEW_WIDTH 0u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVE_WIDTH 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_RES_CFG 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_RES_WIDTH 3u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO 0u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLEW_EXT 0u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVE_EXT 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVEMODE_EXT 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLEW_WIDTH 0u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVE_WIDTH 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_DRIVEMODE_EXT 1u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO7 1u
/* Port supports MSCv3 connections */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_MSCV3 0u
/* Number of VDDIO domains (e.g. Vddio_a, Vddio_backup, Vddd, Vddio_csd, Vddio_*) */
#define IOSS_GPIO_PWRSW                 0u
/* Security extension present ('0': no, '1': yes) */
#define IOSS_GPIO_SECEXT                1u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        7u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_PORT_NR        22u
/* Number of PWR/GND MONITOR CELLs in the device */
#define IOSS_HSIOM_MONITOR_NR           0u
/* Number of PWR/GND MONITOR CELLs in range 0..31 */
#define IOSS_HSIOM_MONITOR_NR_0_31      0u
/* Number of PWR/GND MONITOR CELLs in range 32..63 */
#define IOSS_HSIOM_MONITOR_NR_32_63     0u
/* Number of PWR/GND MONITOR CELLs in range 64..95 */
#define IOSS_HSIOM_MONITOR_NR_64_95     0u
/* Number of PWR/GND MONITOR CELLs in range 96..127 */
#define IOSS_HSIOM_MONITOR_NR_96_127    0u
/* Security extension present ('0': no, '1': yes) */
#define IOSS_HSIOM_SECURE_PRT_SECEXT    1u
/* Mask of SMARTIO instances presence */
#define IOSS_SMARTIO_SMARTIO_MASK       0x00020800u
/* Page size in # of 32-bit words (1: 4 bytes, 2: 8 bytes, ... */
#define IPC0_PA_SIZE                    1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define IPC0_MASTER_WIDTH               6u
#define IPC0_IPC_NR                     16u
#define IPC0_IPC_IRQ_NR                 8u
/* Page size in # of 32-bit words (1: 4 bytes, 2: 8 bytes, ... */
#define IPC1_PA_SIZE                    1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define IPC1_MASTER_WIDTH               6u
#define IPC1_IPC_NR                     16u
#define IPC1_IPC_IRQ_NR                 8u
/* SRAM Type 0=S22:ULL:D114:HVT:SRAM, 1=S22:ULL:D114:RVT:SRAM,
   2=S22:ULL:D140:HVT:SRAM,
   3=S22:ULL:D140:RVT:SRAM,4=S22:ULL:D140:HVT:RF,5=S22:ULL:D140:RVT:RF,6=S22:ULL:D217:HVT:RF,7=S22:ULL:D217:RVT:RF */
#define M0SECCPUSS_SRAM_TYPE            0u
/* RAM Size in Kbytes {64k,128K,192K, 256K} */
#define M0SECCPUSS_SRAM_SIZE            64u
/* RTL definition of the SRAM Base address */
#define M0SECCPUSS_SRAM_ADDR_BASE       0x20000000u
/* RTL definition of SRAM size in bytes */
#define M0SECCPUSS_SRAM_ADDR_SIZE       0x00010000u
/* ROM size in KB {16K, 32K, 48K, 64K} */
#define M0SECCPUSS_ROM_SIZE             64u
/* RTL definition of the ROM Base Address */
#define M0SECCPUSS_ROM_ADDR_BASE        0u
/* RTL definition of ROM size in bytes */
#define M0SECCPUSS_ROM_ADDR_SIZE        0x00010000u
/* Master Port ID for M0 SEC CPUSS in HOST system */
#define M0SECCPUSS_PROT_MASTER          7u
/* Stack Pointer Limit Registers Present */
#define M0SECCPUSS_SP_LIM_PRESENT       1u
/* Secure OTP Base address - must be within the Cacheable Memory Address */
#define M0SECCPUSS_OTP_ADDR_BASE        0x42200000u
/* PC Mask Number ( 1 says PC can be enabled.) */
#define M0SECCPUSS_PC_NR                2u
/* Clock Synch Factor Reset value */
#define M0SECCPUSS_CLK_SYNC_FACTOR      1u
/* CM33[0] should be 0, CM33[1] should have 1 */
#define MXCM33_CPU_WAIT_DEFAULT         1u
/* Number of CPU interrupts used when SYSTEM_IRQ_PRESENT is '1'. Legal values 8,
   16. */
#define MXCM33_CM33_INT_NR              8u
/* IRQ expander present ('0': no, '1': yes) */
#define MXCM33_SYSTEM_IRQ_PRESENT       0u
/* CM33[0] should be 1, CM33[1] should have 0 */
#define MXCM33_PC_MON_PRESENT           1u
/* Number of system interrupt inputs to CPUSS */
#define MXCM33_SYSTEM_INT_NR            197u
/* TrustZone security extention present or not */
#define MXCM33_SECEXT                   1u
/* FPU extention present or not */
#define MXCM33_FPU_PRESENT              1u
/* DSP extention present or not */
#define MXCM33_DSP_PRESENT              1u
/* Default value for CM33 Secure Vector table base address */
#define MXCM33_CM33_S_VECTOR_TABLE_DEFAULT 0x00680000u
/* Default value for CM33 Non-secure Vector table base address */
#define MXCM33_CM33_NS_VECTOR_TABLE_DEFAULT 0x00480000u
/* CM55 default CPUWAIT */
#define MXCM55_CPU_WAIT_DEFAULT         1u
/* Number of CPU interrupts used when SYSTEM_IRQ_PRESENT is '1'. Legal values 8,
   16. */
#define MXCM55_CM55_INT_NR              8u
/* IRQ expander present ('0': no, '1': yes) */
#define MXCM55_SYSTEM_IRQ_PRESENT       0u
/* Number of system interrupt inputs to CPUSS */
#define MXCM55_SYSTEM_INT_NR            174u
/* Default value of CM55 secure vector table base */
#define MXCM55_SECURE_VTOR_DEFAULT      0x00200000u
/* Number of FAULT infrastructure channels ([1, 4]) */
#define MXFAULT_FAULT_NR                2u
/* Number of CTBLs in the Subsystem */
#define PASS_NR_CTBLS                   2u
/* Number of PTCs in the Subsystem */
#define PASS_NR_PTCS                    1u
/* Number of DACs in the Subsystem */
#define PASS_NR_DACS                    2u
/* Number of SARs in the Subsystem */
#define PASS_NR_SARS                    1u
/* Number of CTBL Pads */
#define PASS_NR_CTBL_PADS               16u
/* Number of PTC Pads */
#define PASS_NR_PTC_PADS                8u
/* Number of DAC Pads */
#define PASS_NR_DAC_PADS                2u
/* Number of SARMUX Pads */
#define PASS_NR_SARMUX_PADS             8u
/* CTBL0 Exists */
#define PASS_CTBL0_EXISTS               1u
/* CTBL1 Exists */
#define PASS_CTBL1_EXISTS               1u
/* PTC0 Exists */
#define PASS_PTC0_EXISTS                1u
/* DAC0 Exists */
#define PASS_DAC0_EXISTS                1u
/* DAC1 Exists */
#define PASS_DAC1_EXISTS                1u
/* SAR0 Exists */
#define PASS_SAR0_EXISTS                1u
/* FIFO0 Exists */
#define PASS_FIFO0_EXISTS               1u
/* Number of HP GPIO SAR channels */
#define PASS_SAR_SAR_GPIO_CHANNELS      8u
/* Number of HP/LP Muxed SAR channels */
#define PASS_SAR_SAR_MUX_CHANNELS       16u
/* Number of PDM structures ({2, 4, 6, 8}]). */
#define PDM_NR                          6u
/* Master interface presence mask (4 bits) */
#define PERI0_MS_PRESENT                3u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI0_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT 0u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI0_GROUP_PRESENT0_PERI_GROUP_SL_CTL_DEFAULT 0xFFFFFFFFu
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI0_GROUP_PRESENT0_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI0_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI0_GROUP_PRESENT1_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI0_GROUP_PRESENT1_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI0_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI0_GROUP_PRESENT2_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI0_GROUP_PRESENT2_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 1u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI0_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI0_GROUP_PRESENT3_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI0_GROUP_PRESENT3_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI0_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT 0u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI0_GROUP_PRESENT4_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI0_GROUP_PRESENT4_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI0_GROUP_PRESENT5_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI0_GROUP_PRESENT5_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI0_GROUP_PRESENT5_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Number of asynchronous PCLK groups */
#define PERI0_PCLK_GROUP_NR             10u
/* Timeout functionality present ('0': no, '1': yes) */
#define PERI0_TIMEOUT_PRESENT           1u
/* AHB ERROR response reporting present ('0': no, '1':yes) */
#define PERI0_AHB_ERROR_PRESENT         1u
/* Trigger module present ('0': no, '1': yes) */
#define PERI0_TR                        1u
/* Number of trigger groups */
#define PERI0_TR_GROUP_NR               6u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI0_TR_GROUP_NR0_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI0_TR_GROUP_NR1_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI0_TR_GROUP_NR2_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI0_TR_GROUP_NR3_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI0_TR_GROUP_NR4_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI0_TR_GROUP_NR5_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI0_TR_1TO1_GROUP_NR_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Number of AHB5 "huser[]" bits ([1, 8]). */
#define PERI0_USER_WIDTH                4u
/* Number of AHB5 "hprot[]" bits ([1, 8]). */
#define PERI0_HPROT_WIDTH               7u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI0_GR_DIV_ADDR_WIDTH         3u
/* Number of asynchronous PCLK groups */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR   10u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_8_VECT 5u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_VECT 4u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_5_VECT 2u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_24_5_VECT 1u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_CLOCK_VECT 47u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_8_VECT 4u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_CLOCK_VECT 4u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_CLOCK_VECT 1u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_CLOCK_VECT 1u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_16_5_VECT 1u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_CLOCK_VECT 1u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_16_VECT 1u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_CLOCK_VECT 1u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_CLOCK_VECT 1u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_PCLK_DIV_PRESENT 1u
/* Number of protection contexts supported. Legal range [3, 4, 6, 8] (CDT-336698) */
#define PERI0_PPC_PC_NR                 8u
/* Security extension present ('0': no, '1': yes) */
#define PERI0_PPC_SECEXT                1u
/* Security Aware */
#define PERI0_PPC_PPC_NR0_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR1_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR2_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR3_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR4_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR5_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR6_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR7_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR8_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR9_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR10_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR11_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR12_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR13_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR14_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR15_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR16_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR17_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR18_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR19_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR20_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR21_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR22_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR23_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR24_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR25_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR26_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR27_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR28_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR29_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR30_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR31_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR32_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR33_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR34_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR35_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR36_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR37_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR38_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR39_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR40_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR41_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR42_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR43_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR44_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR45_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR46_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR47_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR48_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR49_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR50_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR51_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR52_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR53_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR54_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR55_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR56_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR57_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR58_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR59_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR60_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR61_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR62_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR63_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR64_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR65_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR66_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR67_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR68_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR69_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR70_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR71_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR72_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR73_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR74_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR75_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR76_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR77_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR78_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR79_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR80_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR81_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR82_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR83_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR84_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR85_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR86_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR87_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR88_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR89_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR90_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR91_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR92_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR93_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR94_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR95_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR96_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR97_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR98_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR99_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR100_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR101_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR102_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR103_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR104_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR105_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR106_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR107_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR108_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR109_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR110_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR111_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR112_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR113_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR114_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR115_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR116_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR117_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR118_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR119_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR120_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR121_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR122_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR123_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR124_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR125_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR126_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR127_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR128_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR129_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR130_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR131_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR132_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR133_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR134_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR135_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR136_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR137_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR138_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR139_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR140_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR141_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR142_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR143_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR144_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR145_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR146_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR147_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR148_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR149_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR150_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR151_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR152_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR153_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR154_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR155_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR156_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR157_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR158_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR159_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR160_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR161_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR162_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR163_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR164_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR165_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR166_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR167_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR168_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR169_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR170_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR171_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR172_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR173_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR174_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR175_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR176_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR177_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR178_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR179_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR180_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR181_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR182_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR183_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR184_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR185_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR186_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR187_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR188_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR189_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR190_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR191_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR192_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR193_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR194_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR195_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR196_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR197_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR198_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR199_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR200_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR201_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR202_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR203_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR204_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR205_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR206_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR207_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR208_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR209_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR210_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR211_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR212_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR213_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR214_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR215_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR216_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR217_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR218_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR219_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR220_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR221_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR222_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR223_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR224_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR225_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR226_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR227_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR228_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR229_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR230_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR231_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR232_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR233_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR234_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR235_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR236_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR237_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR238_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR239_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR240_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR241_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR242_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR243_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR244_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR245_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR246_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR247_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR248_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR249_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR250_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR251_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR252_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR253_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR254_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR255_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR256_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR257_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR258_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR259_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR260_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR261_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR262_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR263_SECURITY_AWARE 1u
/* Security Aware */
#define PERI0_PPC_PPC_NR264_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR265_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR266_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR267_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR268_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR269_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR270_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR271_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR272_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR273_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR274_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR275_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR276_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR277_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR278_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR279_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR280_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR281_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR282_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR283_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR284_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR285_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR286_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR287_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR288_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR289_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR290_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR291_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR292_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR293_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR294_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR295_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR296_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR297_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR298_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR299_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR300_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR301_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR302_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR303_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR304_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR305_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR306_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR307_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR308_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR309_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR310_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR311_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR312_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR313_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR314_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR315_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR316_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR317_SECURITY_AWARE 0u
/* Security Aware */
#define PERI0_PPC_PPC_NR318_SECURITY_AWARE 0u
/* Master interface presence mask (4 bits) */
#define PERI1_MS_PRESENT                3u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI1_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT 0u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI1_GROUP_PRESENT0_PERI_GROUP_SL_CTL_DEFAULT 0xFFFFFFFFu
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI1_GROUP_PRESENT0_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI1_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI1_GROUP_PRESENT1_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI1_GROUP_PRESENT1_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 1u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI1_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT 0u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI1_GROUP_PRESENT2_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI1_GROUP_PRESENT2_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI1_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI1_GROUP_PRESENT3_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI1_GROUP_PRESENT3_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 3u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI1_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT 0u
/* Default value for SL_CTL register value on POR. RTL is hard coded Group-0 it is
   0xFFFF_FFFF Group-1 to Group-15 it is 0x000_0000 */
#define PERI1_GROUP_PRESENT4_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI1_GROUP_PRESENT4_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Number of asynchronous PCLK groups */
#define PERI1_PCLK_GROUP_NR             6u
/* Timeout functionality present ('0': no, '1': yes) */
#define PERI1_TIMEOUT_PRESENT           1u
/* AHB ERROR response reporting present ('0': no, '1':yes) */
#define PERI1_AHB_ERROR_PRESENT         1u
/* Trigger module present ('0': no, '1': yes) */
#define PERI1_TR                        1u
/* Number of trigger groups */
#define PERI1_TR_GROUP_NR               3u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI1_TR_GROUP_NR0_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI1_TR_GROUP_NR1_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI1_TR_GROUP_NR2_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Number of AHB5 "huser[]" bits ([1, 8]). */
#define PERI1_USER_WIDTH                4u
/* Number of AHB5 "hprot[]" bits ([1, 8]). */
#define PERI1_HPROT_WIDTH               7u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI1_GR_DIV_ADDR_WIDTH         2u
/* Number of asynchronous PCLK groups */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR   6u
/* Number of 8.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_5_VECT 3u
/* Number of 24.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_CLOCK_VECT 3u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_CLOCK_VECT 1u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_CLOCK_VECT 1u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_PCLK_DIV_PRESENT 0u
/* Number of protection contexts supported. Legal range [3, 4, 6, 8] (CDT-336698) */
#define PERI1_PPC_PC_NR                 8u
/* Security extension present ('0': no, '1': yes) */
#define PERI1_PPC_SECEXT                1u
/* Security Aware */
#define PERI1_PPC_PPC_NR0_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR1_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR2_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR3_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR4_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR5_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR6_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR7_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR8_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR9_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR10_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR11_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR12_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR13_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR14_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR15_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR16_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR17_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR18_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR19_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR20_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR21_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR22_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR23_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR24_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR25_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR26_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR27_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR28_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR29_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR30_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR31_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR32_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR33_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR34_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR35_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR36_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR37_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR38_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR39_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR40_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR41_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR42_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR43_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR44_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR45_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR46_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR47_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR48_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR49_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR50_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR51_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR52_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR53_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR54_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR55_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR56_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR57_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR58_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR59_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR60_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR61_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR62_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR63_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR64_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR65_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR66_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR67_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR68_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR69_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR70_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR71_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR72_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR73_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR74_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR75_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR76_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR77_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR78_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR79_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR80_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR81_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR82_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR83_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR84_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR85_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR86_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR87_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR88_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR89_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR90_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR91_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR92_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR93_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR94_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR95_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR96_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR97_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR98_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR99_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR100_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR101_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR102_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR103_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR104_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR105_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR106_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR107_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR108_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR109_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR110_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR111_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR112_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR113_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR114_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR115_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR116_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR117_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR118_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR119_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR120_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR121_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR122_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR123_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR124_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR125_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR126_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR127_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR128_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR129_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR130_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR131_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR132_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR133_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR134_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR135_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR136_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR137_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR138_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR139_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR140_SECURITY_AWARE 1u
/* Security Aware */
#define PERI1_PPC_PPC_NR141_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR142_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR143_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR144_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR145_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR146_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR147_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR148_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR149_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR150_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR151_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR152_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR153_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR154_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR155_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR156_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR157_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR158_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR159_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR160_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR161_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR162_SECURITY_AWARE 0u
/* Security Aware */
#define PERI1_PPC_PPC_NR163_SECURITY_AWARE 0u
/* Presence of the patch functionality. 0: ROM cannot be patched. 1: ROM can be
   patched. */
#define PROMC_PATCH_PRESENT             0u
/* Number of patchable locations (patch entries). Possible range [0,512]. */
#define PROMC_PATCH_NR                  0u
/* Number of patchable locations, qualified by PATCH_PRESENT. Local param to mimic
   by product XLS. */
#define PROMC_PATCH_NR_QUAL             0u
/* Patch size selection of a single structure. 0: 8 Bytes. 1: 16 Bytes. **) 2: 32
   Bytes. 3: 64 Bytes. **) The patch size should fit to the word size of the
   ROM. Thus only PATCH_SIZE=1 is supported for this ROM controller. */
#define PROMC_PATCH_SIZE                1u
/* Width of compared address bits. The LSB is determined by the PATCH_SIZE, for 16
   bytes this equals to bit [4]. The MSB is chosen to address the full size of
   the ROM in bytes. */
#define PROMC_MATCH_ADDR_SIZE           12u
/* Initial value of the first patchable address in the ROM. This address and the
   following higher addresses are patchable if the function is enabled. */
#define PROMC_SROM_BOUNDARY             303u
/* Width of the byte address (2^ROMC_ADDR_WIDTH byte of total SROM region). */
#define PROMC_ROMC_ADDR_WIDTH           16u
/* Number of physical SROM macros used. */
#define PROMC_ROMC_MACRO_NR             1u
/* Width of the byte address per each physical macro. */
#define PROMC_ROMC_MACRO_ADDR_WIDTH     16u
/* Bit width of hrdata and hwdata (AHB5 slave for ROM access). */
#define PROMC_DATA_PATH_WIDTH           128u
/* Number of RAM words for patch data. Local param to mimic by product XLS. */
#define PROMC_PATCH_RAM_WORDS           0u
/* VT type of instantiated tech cells through mxtk. */
#define PROMC_CELL_VT_TYPE              0u
/* Bit width of mmio_trim_ram_ctl_trim. */
#define PROMC_TRIM_WIDTH                4u
/* Existence of power switch control for the SRAM containing patch data. */
#define PROMC_SWITCH_PRESENT            1u
/* Security based access checks are valid (1: NS bit is checked, 0: NS bit is
   ignored). */
#define PROMC_MPC_SECEXT                1u
#define PROMC_MPC_MASTER_WIDTH          6u
#define PROMC_MPC_PC_WIDTH              4u
#define PROMC_MPC_PC_NR                 8u
#define PROMC_MPC_BLK_IDX_MAX           0u
#define PROMC_MPC_BLK_IDX_WIDTH         0u
#define PROMC_MPC_EXT_PRESENT           0u
#define PROMC_MPC_BLK_IDX_MAX_TIMES_FOUR_PLUS_THREE 3u
#define PROMC_MPC_BLK_IDX_WIDTH_PLUS_TWO 2u
#define PROMC_MPC_BLOCK_SIZE            6u
/* Number of System SRAM power partions */
#define RAMC0_PWR_GROUP_NR              8u
/* SRAM ECC present or not ('0': no, '1': yes) */
#define RAMC0_ECC_PRESENT               0u
#define RAMC0_MPC_MASTER_WIDTH          6u
#define RAMC0_MPC_PC_WIDTH              4u
#define RAMC0_MPC_PC_NR                 8u
#define RAMC0_MPC_BLK_IDX_MAX           3u
#define RAMC0_MPC_BLK_IDX_WIDTH         2u
#define RAMC0_MPC_EXT_PRESENT           0u
#define RAMC0_MPC_BLK_IDX_MAX_TIMES_FOUR_PLUS_THREE 15u
#define RAMC0_MPC_BLK_IDX_WIDTH_PLUS_TWO 4u
#define RAMC0_MPC_BLOCK_SIZE            7u
/* Number of System SRAM power partions */
#define RAMC1_PWR_GROUP_NR              8u
/* SRAM ECC present or not ('0': no, '1': yes) */
#define RAMC1_ECC_PRESENT               0u
#define RAMC1_MPC_MASTER_WIDTH          6u
#define RAMC1_MPC_PC_WIDTH              4u
#define RAMC1_MPC_PC_NR                 8u
#define RAMC1_MPC_BLK_IDX_MAX           3u
#define RAMC1_MPC_BLK_IDX_WIDTH         2u
#define RAMC1_MPC_EXT_PRESENT           0u
#define RAMC1_MPC_BLK_IDX_MAX_TIMES_FOUR_PLUS_THREE 15u
#define RAMC1_MPC_BLK_IDX_WIDTH_PLUS_TWO 4u
#define RAMC1_MPC_BLOCK_SIZE            7u
#define RRAMC_AXI_PRESENT               1u
#define RRAMC_SECEXT                    1u
#define RRAMC_PC_NR                     8u
#define RRAMC_MAIN_START_ADDRESS        0x02000000u
#define RRAMC_WORK_START_ADDRESS        0x03000000u
#define RRAMC_SFLASH_START_ADDRESS      0x03600000u
#define RRAMC_PROTECTED_START_ADDRESS   0x03C00000u
#define RRAMC_PROTECTED_OTP_START_ADDRESS 0x42200000u
#define RRAMC_GENERAL_OTP_START_ADDRESS 0x42204000u
#define RRAMC_SRAM_REPAIR_OTP_START_ADDRESS 0x42208000u
#define RRAMC_CONFIGURATION_SPACE_START_ADDRESS 0x42209000u
#define RRAMC_RRAM_SFR_START_ADDRESS    0x42213000u
#define RRAMC_RRAMC_MMIO_START_ADDRESS  0x42210000u
#define RRAMC_MPC_START_ADDRESS         0x42211000u
#define RRAMC_SESSION_KEY_ADDRESS       0x40051000u
#define RRAMC_SESSION_KEY_VALUE         0x16071971u
#define RRAMC_BOOTROW_BLOCK_ADDRESS     0x00008000u
#define RRAMC_BLOCK_START               16u
#define RRAMC_BLOCK_END                 507u
#define RRAMC_MAIN_N                    32u
#define RRAMC_WORK_Z                    0u
#define RRAMC_SFLASH_Y                  0u
#define RRAMC_PROTECTED_X               32u
#define RRAMC_TRIM_WIDTH                32u
#define RRAMC_MPC_PC_NR                 8u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB0_DEEPSLEEP                  1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB0_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB0_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB0_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB0_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB0_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB0_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB0_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB0_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB0_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB0_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB0_I2C_S_EC                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB0_SPI_M                      0u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB0_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB0_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB0_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB0_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB0_UART                       0u
/* SPI or UART (SPI | UART) */
#define SCB0_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB0_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB0_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB0_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB0_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB0_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB0_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB0_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB0_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB0_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB0_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB1_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB1_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB1_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB1_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB1_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB1_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB1_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB1_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB1_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB1_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB1_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB1_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB1_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB1_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB1_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB1_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB1_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB1_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB1_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB1_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB1_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB1_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB1_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB1_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB1_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB1_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB1_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB1_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB1_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB2_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB2_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB2_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB2_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB2_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB2_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB2_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB2_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB2_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB2_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB2_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB2_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB2_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB2_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB2_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB2_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB2_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB2_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB2_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB2_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB2_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB2_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB2_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB2_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB2_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB2_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB2_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB2_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB2_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB3_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB3_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB3_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB3_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB3_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB3_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB3_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB3_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB3_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB3_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB3_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB3_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB3_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB3_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB3_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB3_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB3_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB3_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB3_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB3_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB3_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB3_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB3_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB3_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB3_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB3_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB3_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB3_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB3_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB4_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB4_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB4_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB4_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB4_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB4_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB4_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB4_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB4_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB4_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB4_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB4_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB4_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB4_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB4_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB4_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB4_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB4_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB4_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB4_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB4_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB4_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB4_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB4_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB4_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB4_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB4_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB4_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB4_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB5_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB5_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB5_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB5_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB5_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB5_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB5_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB5_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB5_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB5_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB5_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB5_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB5_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB5_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB5_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB5_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB5_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB5_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB5_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB5_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB5_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB5_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB5_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB5_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB5_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB5_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB5_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB5_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB5_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB6_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB6_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB6_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB6_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB6_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB6_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB6_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB6_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB6_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB6_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB6_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB6_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB6_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB6_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB6_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB6_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB6_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB6_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB6_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB6_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB6_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB6_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB6_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB6_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB6_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB6_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB6_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB6_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB6_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB7_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB7_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB7_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB7_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB7_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB7_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB7_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB7_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB7_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB7_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB7_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB7_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB7_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB7_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB7_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB7_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB7_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB7_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB7_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB7_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB7_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB7_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB7_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB7_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB7_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB7_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB7_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB7_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB7_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB8_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB8_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB8_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB8_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB8_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB8_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB8_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB8_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB8_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB8_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB8_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB8_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB8_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB8_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB8_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB8_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB8_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB8_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB8_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB8_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB8_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB8_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB8_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB8_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB8_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB8_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB8_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB8_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB8_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB9_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB9_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB9_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB9_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB9_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB9_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB9_I2C_HS                     0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB9_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB9_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB9_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB9_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB9_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB9_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB9_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB9_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB9_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB9_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB9_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB9_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB9_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB9_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB9_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB9_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB9_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB9_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB9_MASTER_WIDTH               6u
/* Number of used spi_select signals (max 4) */
#define SCB9_CHIP_TOP_SPI_SEL_NR        2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB9_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB9_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB10_DEEPSLEEP                 0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB10_EC                        0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB10_I2C_M                     1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB10_I2C_S                     1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB10_I2C                       1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB10_I2C_GLITCH                1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB10_I2C_HS                    0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB10_I2C_EC                    0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB10_I2C_M_S                   1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB10_I2C_M_HS                  0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB10_I2C_S_HS                  0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB10_I2C_S_EC                  0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB10_SPI_M                     1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB10_SPI_S                     1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB10_SPI                       1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB10_SPI_EC                    0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB10_SPI_S_EC                  0u
/* UART support? ('0': no, '1': yes) */
#define SCB10_UART                      1u
/* SPI or UART (SPI | UART) */
#define SCB10_SPI_UART                  1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB10_EZ_DATA_NR                256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB10_CMD_RESP                  0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB10_EZ                        1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB10_EZ_CMD_RESP               1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB10_I2C_S_EZ                  1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB10_SPI_S_EZ                  1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB10_MASTER_WIDTH              6u
/* Number of used spi_select signals (max 4) */
#define SCB10_CHIP_TOP_SPI_SEL_NR       2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB10_CHIP_TOP_I2C_FAST_PLUS    1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB10_CHIP_TOP_DDFT_USED        4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB11_DEEPSLEEP                 0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB11_EC                        0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB11_I2C_M                     1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB11_I2C_S                     1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB11_I2C                       1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB11_I2C_GLITCH                1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB11_I2C_HS                    0u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB11_I2C_EC                    0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB11_I2C_M_S                   1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB11_I2C_M_HS                  0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB11_I2C_S_HS                  0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB11_I2C_S_EC                  0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB11_SPI_M                     1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB11_SPI_S                     1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB11_SPI                       1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB11_SPI_EC                    0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB11_SPI_S_EC                  0u
/* UART support? ('0': no, '1': yes) */
#define SCB11_UART                      1u
/* SPI or UART (SPI | UART) */
#define SCB11_SPI_UART                  1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB11_EZ_DATA_NR                256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB11_CMD_RESP                  0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB11_EZ                        1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB11_EZ_CMD_RESP               1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB11_I2C_S_EZ                  1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB11_SPI_S_EZ                  1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB11_MASTER_WIDTH              6u
/* Number of used spi_select signals (max 4) */
#define SCB11_CHIP_TOP_SPI_SEL_NR       2u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB11_CHIP_TOP_I2C_FAST_PLUS    1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB11_CHIP_TOP_DDFT_USED        4u
/* Basically the max packet size, which gets double buffered in RAM 0: 512B
   (implies 1KB of RAM space for data) 1: 1KB (implies 2KB of RAM space for
   data) */
#define SDHC0_MAX_BLK_SIZE              1u
/* 0: No Command Queuing Engine present 1: Command Queuing Engine present; this
   adds 288 bytes of space to the RAM for this purpose. */
#define SDHC0_CQE_PRESENT               1u
/* 0: no retention of any SDHC_CORE regs 1: retention of SDHC_CORE regs that have
   the Retention flag (Note, CTL.ENABLE is always retained irrespective of this
   parameter) */
#define SDHC0_RETENTION_PRESENT         1u
/* Chip top connect all 8 data pins (0= connect 4 data pins, 1= connect 8 data
   pins) */
#define SDHC0_CHIP_TOP_DATA8_PRESENT    0u
/* Chip top connect card_detect */
#define SDHC0_CHIP_TOP_CARD_DETECT_PRESENT 1u
/* Chip top connect card_mech_write_prot_in */
#define SDHC0_CHIP_TOP_CARD_WRITE_PROT_PRESENT 1u
/* Chip top connect led_ctrl_out and led_ctrl_out_en */
#define SDHC0_CHIP_TOP_LED_CTRL_PRESENT 0u
/* Chip top connect io_volt_sel_out and io_volt_sel_out_en */
#define SDHC0_CHIP_TOP_IO_VOLT_SEL_PRESENT 1u
/* Chip top connect io_drive_strength_out and io_drive_strength_out_en */
#define SDHC0_CHIP_TOP_IO_DRIVE_STRENGTH_PRESENT 0u
/* Chip top connect card_if_pwr_en_out and card_if_pwr_en_out_en */
#define SDHC0_CHIP_TOP_CARD_IF_PWR_EN_PRESENT 1u
/* Chip top connect card_emmc_reset_n_out and card_emmc_reset_n_out_en */
#define SDHC0_CHIP_TOP_CARD_EMMC_RESET_PRESENT 0u
/* Chip top connect interrupt_wakeup (not used for eMMC) */
#define SDHC0_CHIP_TOP_INTERRUPT_WAKEUP_PRESENT 1u
/* Basically the max packet size, which gets double buffered in RAM 0: 512B
   (implies 1KB of RAM space for data) 1: 1KB (implies 2KB of RAM space for
   data) */
#define SDHC0_CORE_MAX_BLK_SIZE         1u
/* 0: No Command Queuing Engine present 1: Command Queuing Engine present; this
   adds 288 bytes of space to the RAM for this purpose. */
#define SDHC0_CORE_CQE_PRESENT          1u
/* 0: no retention of any SDHC_CORE regs 1: retention of SDHC_CORE regs that have
   the Retention flag (Note, CTL.ENABLE is always retained irrespective of this
   parameter) */
#define SDHC0_CORE_RETENTION_PRESENT    1u
/* Basically the max packet size, which gets double buffered in RAM 0: 512B
   (implies 1KB of RAM space for data) 1: 1KB (implies 2KB of RAM space for
   data) */
#define SDHC1_MAX_BLK_SIZE              1u
/* 0: No Command Queuing Engine present 1: Command Queuing Engine present; this
   adds 288 bytes of space to the RAM for this purpose. */
#define SDHC1_CQE_PRESENT               1u
/* 0: no retention of any SDHC_CORE regs 1: retention of SDHC_CORE regs that have
   the Retention flag (Note, CTL.ENABLE is always retained irrespective of this
   parameter) */
#define SDHC1_RETENTION_PRESENT         0u
/* Chip top connect all 8 data pins (0= connect 4 data pins, 1= connect 8 data
   pins) */
#define SDHC1_CHIP_TOP_DATA8_PRESENT    1u
/* Chip top connect card_detect */
#define SDHC1_CHIP_TOP_CARD_DETECT_PRESENT 1u
/* Chip top connect card_mech_write_prot_in */
#define SDHC1_CHIP_TOP_CARD_WRITE_PROT_PRESENT 1u
/* Chip top connect led_ctrl_out and led_ctrl_out_en */
#define SDHC1_CHIP_TOP_LED_CTRL_PRESENT 1u
/* Chip top connect io_volt_sel_out and io_volt_sel_out_en */
#define SDHC1_CHIP_TOP_IO_VOLT_SEL_PRESENT 1u
/* Chip top connect io_drive_strength_out and io_drive_strength_out_en */
#define SDHC1_CHIP_TOP_IO_DRIVE_STRENGTH_PRESENT 0u
/* Chip top connect card_if_pwr_en_out and card_if_pwr_en_out_en */
#define SDHC1_CHIP_TOP_CARD_IF_PWR_EN_PRESENT 1u
/* Chip top connect card_emmc_reset_n_out and card_emmc_reset_n_out_en */
#define SDHC1_CHIP_TOP_CARD_EMMC_RESET_PRESENT 1u
/* Chip top connect interrupt_wakeup (not used for eMMC) */
#define SDHC1_CHIP_TOP_INTERRUPT_WAKEUP_PRESENT 1u
/* Basically the max packet size, which gets double buffered in RAM 0: 512B
   (implies 1KB of RAM space for data) 1: 1KB (implies 2KB of RAM space for
   data) */
#define SDHC1_CORE_MAX_BLK_SIZE         1u
/* 0: No Command Queuing Engine present 1: Command Queuing Engine present; this
   adds 288 bytes of space to the RAM for this purpose. */
#define SDHC1_CORE_CQE_PRESENT          1u
/* 0: no retention of any SDHC_CORE regs 1: retention of SDHC_CORE regs that have
   the Retention flag (Note, CTL.ENABLE is always retained irrespective of this
   parameter) */
#define SDHC1_CORE_RETENTION_PRESENT    0u
/* 0: AHB MPC ignores security checks 1: AHB MPC performs security checks */
#define SMIF0_AHB_SECEXT                1u
/* 0: AXI MPC ignores security checks 1: AXI MPC performs security checks */
#define SMIF0_AXI_SECEXT                1u
/* 0: Bridge is not present. Only SMIF0 is present. SMIF_NR must be set to 1. 1:
   Bridge is present. Both SMIF0 and SMIF1 are present. SMIF_NR must be set to
   2. */
#define SMIF0_BRIDGE_PRESENT            0u
/* Slow AHB XIP cache is present ([0,1]). If SLOW_AHB_XIP_IF_PRESENT=0 then set
   this to 0 as well. Applies to all present SMIFs. */
#define SMIF0_SLOW_CACHE_PRESENT        0u
/* Fast AHB XIP cache is present ([0,1]). If FAST_AHB_XIP_IF_PRESENT=0 then set
   this to 0 as well. Applies to all present SMIFs. */
#define SMIF0_FAST_CACHE_PRESENT        0u
/* Base address of the SMIF0 XIP memory region. This address must be a multiple of
   the SMIF0 XIP memory region capacity (see SMIF0_XIP_MASK below). The SMIF0
   XIP memory region should NOT overlap with other memory regions. This adress
   must be in the [0x0000:0000, 0xffff:0000] memory region. However, for MXS40
   CM4 based platform variant, this address must be in the [0x0000:0000,
   0x1fff:0000] memory region (to ensure a connection to the ARM CM4 CPU
   ICode/DCode memory region [0x0000:0000, 0x1fff:ffff]). The external memory
   devices are located within the SMIF0 XIP memory region. */
#define SMIF0_SMIF0_XIP_ADDR            0x60000000u
/* Same as SMIF0_XIP_ADDR except for SMIF1. Only applicable if BRIDGE_PRESENT=1. */
#define SMIF0_SMIF1_XIP_ADDR            0x64000000u
/* Capacity of the SMIF0 XIP memory region. The capacity must be a power of 2 and
   greater or equal than 64 KB). The more significant bits of this parameter are
   '1' and the lesser significant bits of this parameter are '0'. E.g.,
   0xfff0:0000 specifies a 1 MB memory region. Must be set to 512MB when
   BRIDGE_PRESENT=1. */
#define SMIF0_SMIF0_XIP_MASK            0xFC000000u
/* Same as SMIF0_XIP_MASK except for SMIF1. Only applicable if BRIDGE_PRESENT=1. */
#define SMIF0_SMIF1_XIP_MASK            0xFC000000u
/* Cryptography (AES) support. This is a 1-bit parameter: '0' = no support, '1' =
   support. Applies to all present SMIFs. */
#define SMIF0_CRYPTO                    1u
/* Number of cryptography keys [0,1,2,4,8]; set to 0 if CRYPTO=0. Applies to all
   present SMIFs. */
#define SMIF0_CRYPTO_KEY_NR             4u
/* Hardcoded 8-bit parameter (do NOT override) that allows crypto key 0 to take on
   additional registers to support MMIO encryption. Applies to all present
   SMIFs. */
#define SMIF0_CRYPTO_KEY_MMIO_CAPABLE   1u
/* Bus CRC support is present ([0,1]). Applies to all present SMIFs. Note: In
   current mxsmif_ver3 this option is not available (BUS_CRC_PRESENT=0). Based
   on project schedules this feature may be added already to mxsmif ver3 /
   mxsmif_ver3_phase2 or to a later SMIF version. */
#define SMIF0_BUS_CRC_PRESENT           0u
/* Number of external memory devices supported. This parameter is in the range
   [1,4]. Applies to all present SMIFs. */
#define SMIF0_DEVICE_NR                 4u
/* External memory devices write support. This is a 4-bit field. Each external
   memory device has a dedicated bit. E.g., if bit 2 is '1', external device 2
   has write support. Applies to all present SMIFs. */
#define SMIF0_DEVICE_WR_EN              15u
/* DLP capture scheme present ([0,1]). Applies to all present SMIFs. */
#define SMIF0_DLP_PRESENT               1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SMIF0_MASTER_WIDTH              6u
/* AXI ID width. Legal range [11,16] */
#define SMIF0_AXIS_ID_WIDTH             15u
/* Number of SMIFs present - must be set as described in BRIDGE_PRESENT. */
#define SMIF0_SMIF_NR                   1u
/* Chip top connect all 8 data pins (0= connect 4 data pins, 1= connect 8 data
   pins). Applies to all present SMIFs. */
#define SMIF0_CHIP_TOP_DATA8_PRESENT    1u
/* Number of used spi_select signals (max 4). Applies to all present SMIFs. */
#define SMIF0_CHIP_TOP_SPI_SEL_NR       4u
/* Number of GPIO ports in range 0..31 */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR_0_31 3u
/* Number of GPIO ports in range 32..63 */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR_32_63 0u
/* Number of GPIO ports in range 64..95 */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR_64_95 0u
/* Number of GPIO ports in range 96..127 */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR_96_127 0u
/* Number of ports in device */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR    3u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DRIVEMODE_EXT 0u
/* Inidcates port support RES_CFG bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DRIVEMODE_EXT 0u
/* Inidcates port support RES_CFG bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DRIVEMODE_EXT 0u
/* Inidcates port support RES_CFG bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define SMIF0_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_MSCV3 0u
/* Power Switch exists */
#define SMIF0_SMIF_GPIO_PWRSW           0u
/* Security extension present ('0': no, '1': yes) */
#define SMIF0_SMIF_GPIO_SECEXT_IOSS     0u
/* Number of AMUX splitter cells */
#define SMIF0_SMIF_HSIOM_AMUX_SPLIT_NR  0u
/* Number of HSIOM ports in device */
#define SMIF0_SMIF_HSIOM_HSIOM_PORT_NR  3u
/* Number of PWR/GND MONITOR CELLs in the device */
#define SMIF0_SMIF_HSIOM_MONITOR_NR     0u
/* Number of PWR/GND MONITOR CELLs in range 0..31 */
#define SMIF0_SMIF_HSIOM_MONITOR_NR_0_31 0u
/* Number of PWR/GND MONITOR CELLs in range 32..63 */
#define SMIF0_SMIF_HSIOM_MONITOR_NR_32_63 0u
/* Number of PWR/GND MONITOR CELLs in range 64..95 */
#define SMIF0_SMIF_HSIOM_MONITOR_NR_64_95 0u
/* Number of PWR/GND MONITOR CELLs in range 96..127 */
#define SMIF0_SMIF_HSIOM_MONITOR_NR_96_127 0u
/* Security extension present ('0': no, '1': yes) */
#define SMIF0_SMIF_HSIOM_SECURE_PRT_SECEXT_IOSS 0u
/* 0: AHB MPC ignores security checks 1: AHB MPC performs security checks */
#define SMIF1_AHB_SECEXT                1u
/* 0: AXI MPC ignores security checks 1: AXI MPC performs security checks */
#define SMIF1_AXI_SECEXT                1u
/* 0: Bridge is not present. Only SMIF0 is present. SMIF_NR must be set to 1. 1:
   Bridge is present. Both SMIF0 and SMIF1 are present. SMIF_NR must be set to
   2. */
#define SMIF1_BRIDGE_PRESENT            0u
/* Slow AHB XIP cache is present ([0,1]). If SLOW_AHB_XIP_IF_PRESENT=0 then set
   this to 0 as well. Applies to all present SMIFs. */
#define SMIF1_SLOW_CACHE_PRESENT        0u
/* Fast AHB XIP cache is present ([0,1]). If FAST_AHB_XIP_IF_PRESENT=0 then set
   this to 0 as well. Applies to all present SMIFs. */
#define SMIF1_FAST_CACHE_PRESENT        0u
/* Base address of the SMIF0 XIP memory region. This address must be a multiple of
   the SMIF0 XIP memory region capacity (see SMIF0_XIP_MASK below). The SMIF0
   XIP memory region should NOT overlap with other memory regions. This adress
   must be in the [0x0000:0000, 0xffff:0000] memory region. However, for MXS40
   CM4 based platform variant, this address must be in the [0x0000:0000,
   0x1fff:0000] memory region (to ensure a connection to the ARM CM4 CPU
   ICode/DCode memory region [0x0000:0000, 0x1fff:ffff]). The external memory
   devices are located within the SMIF0 XIP memory region. */
#define SMIF1_SMIF0_XIP_ADDR            0x64000000u
/* Same as SMIF0_XIP_ADDR except for SMIF1. Only applicable if BRIDGE_PRESENT=1. */
#define SMIF1_SMIF1_XIP_ADDR            0x64000000u
/* Capacity of the SMIF0 XIP memory region. The capacity must be a power of 2 and
   greater or equal than 64 KB). The more significant bits of this parameter are
   '1' and the lesser significant bits of this parameter are '0'. E.g.,
   0xfff0:0000 specifies a 1 MB memory region. Must be set to 512MB when
   BRIDGE_PRESENT=1. */
#define SMIF1_SMIF0_XIP_MASK            0xFC000000u
/* Same as SMIF0_XIP_MASK except for SMIF1. Only applicable if BRIDGE_PRESENT=1. */
#define SMIF1_SMIF1_XIP_MASK            0xFC000000u
/* Cryptography (AES) support. This is a 1-bit parameter: '0' = no support, '1' =
   support. Applies to all present SMIFs. */
#define SMIF1_CRYPTO                    1u
/* Number of cryptography keys [0,1,2,4,8]; set to 0 if CRYPTO=0. Applies to all
   present SMIFs. */
#define SMIF1_CRYPTO_KEY_NR             4u
/* Hardcoded 8-bit parameter (do NOT override) that allows crypto key 0 to take on
   additional registers to support MMIO encryption. Applies to all present
   SMIFs. */
#define SMIF1_CRYPTO_KEY_MMIO_CAPABLE   1u
/* Bus CRC support is present ([0,1]). Applies to all present SMIFs. Note: In
   current mxsmif_ver3 this option is not available (BUS_CRC_PRESENT=0). Based
   on project schedules this feature may be added already to mxsmif ver3 /
   mxsmif_ver3_phase2 or to a later SMIF version. */
#define SMIF1_BUS_CRC_PRESENT           0u
/* Number of external memory devices supported. This parameter is in the range
   [1,4]. Applies to all present SMIFs. */
#define SMIF1_DEVICE_NR                 4u
/* External memory devices write support. This is a 4-bit field. Each external
   memory device has a dedicated bit. E.g., if bit 2 is '1', external device 2
   has write support. Applies to all present SMIFs. */
#define SMIF1_DEVICE_WR_EN              15u
/* DLP capture scheme present ([0,1]). Applies to all present SMIFs. */
#define SMIF1_DLP_PRESENT               1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SMIF1_MASTER_WIDTH              6u
/* AXI ID width. Legal range [11,16] */
#define SMIF1_AXIS_ID_WIDTH             15u
/* Number of SMIFs present - must be set as described in BRIDGE_PRESENT. */
#define SMIF1_SMIF_NR                   1u
/* Chip top connect all 8 data pins (0= connect 4 data pins, 1= connect 8 data
   pins). Applies to all present SMIFs. */
#define SMIF1_CHIP_TOP_DATA8_PRESENT    1u
/* Number of used spi_select signals (max 4). Applies to all present SMIFs. */
#define SMIF1_CHIP_TOP_SPI_SEL_NR       4u
/* Number of GPIO ports in range 0..31 */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR_0_31 3u
/* Number of GPIO ports in range 32..63 */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR_32_63 0u
/* Number of GPIO ports in range 64..95 */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR_64_95 0u
/* Number of GPIO ports in range 96..127 */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR_96_127 0u
/* Number of ports in device */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR    3u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DRIVEMODE_EXT 0u
/* Inidcates port support RES_CFG bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR0_SMIF_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DRIVEMODE_EXT 0u
/* Inidcates port support RES_CFG bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR1_SMIF_GPIO_PRT_MSCV3 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DRIVE_EXT 1u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DRIVEMODE_EXT 0u
/* Inidcates port support RES_CFG bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DRIVE_WIDTH 3u
/* Width of CFG_RES Bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_RES_WIDTH 0u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates that pin #0 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_SLOW_IO7 0u
/* Port supports MSCv3 connections */
#define SMIF1_SMIF_GPIO_GPIO_PORT_NR2_SMIF_GPIO_PRT_MSCV3 0u
/* Power Switch exists */
#define SMIF1_SMIF_GPIO_PWRSW           0u
/* Security extension present ('0': no, '1': yes) */
#define SMIF1_SMIF_GPIO_SECEXT_IOSS     0u
/* Number of AMUX splitter cells */
#define SMIF1_SMIF_HSIOM_AMUX_SPLIT_NR  0u
/* Number of HSIOM ports in device */
#define SMIF1_SMIF_HSIOM_HSIOM_PORT_NR  3u
/* Number of PWR/GND MONITOR CELLs in the device */
#define SMIF1_SMIF_HSIOM_MONITOR_NR     0u
/* Number of PWR/GND MONITOR CELLs in range 0..31 */
#define SMIF1_SMIF_HSIOM_MONITOR_NR_0_31 0u
/* Number of PWR/GND MONITOR CELLs in range 32..63 */
#define SMIF1_SMIF_HSIOM_MONITOR_NR_32_63 0u
/* Number of PWR/GND MONITOR CELLs in range 64..95 */
#define SMIF1_SMIF_HSIOM_MONITOR_NR_64_95 0u
/* Number of PWR/GND MONITOR CELLs in range 96..127 */
#define SMIF1_SMIF_HSIOM_MONITOR_NR_96_127 0u
/* Security extension present ('0': no, '1': yes) */
#define SMIF1_SMIF_HSIOM_SECURE_PRT_SECEXT_IOSS 0u
/* SROM controller presence '0': SROM controller not instantiated in this IP '1':
   SROM controller is instantiated in this IP */
#define SOCMEM_SROM_PRESENT             0u
/* Port type, 2 bits per port There are up to 16 ports. Each port has 2 bits in
   this structure: 00 = RESERVED 01 = 64-bit AXI5 10 = 32-bit AHB5 11 = 128-bit
   AHB5 EXAMPLE 1: If PORT_TYPE is 0x55B00000 and PORT_NR is 6, then ports 0, 1,
   2, and 3 are 64-bit AXI5, port 4 is 32-bit AHB5, and port 5 is 128-bit AHB5.
   EXAMPLE 2: If PORT_TYPE is 0x55B00000 and PORT_NR is 4, then ports 0, 1, 2,
   and 3 are 64-bit AXI5. */
#define SOCMEM_PORT_TYPE                725u
/* Defines if SOCMEM power domain is SYS CPUSS power domain or APP CPUSS power
   domain. 0- SOCMEM is in SYS CPUSS power domain; 1- SOCMEM is in APP CPUSS
   power domain. Note that for PSoC Edge configuration this parameter value is
   '1', i.e. SOCMEM is in APP CPUSS power domain. */
#define SOCMEM_SOCMEM_PWR_DOMAIN        1u
/* Defines power domain of each SOCMEM port. 1-bit per port. There can be upto
   16-ports. 0- SYS CPUSS power domain; 1-APP CPUSS power domain. */
#define SOCMEM_PORT_PWR_DOMAIN          7u
/* Defines input SOCMEM MMIO I/F is in SYS CPUSS power domain or APP CPUSS power
   domain. 0- SOCMEM MMIO I/F is in SYS CPUSS power domain; 1- SOCMEM MMIO I/F
   is in APP CPUSS power domain. */
#define SOCMEM_MMIO_PWR_DOMAIN          1u
/* Numbers partitions in a bank [1, 2, 3, 4, 5, 6, 7, 8] */
#define SOCMEM_SRAM_BANK_NR             4u
/* Numbers partitions in a bank [1, 2, 4, 8] */
#define SOCMEM_SRAM_PARTITION_NR        10u
/* Presence of sub-partion. Note that this is supported only for partition-0. */
#define SOCMEM_SUB_PARTITION_PRESENT    0u
/* This parameter is passed on to MPC instantiation which defines support of
   Secure extension */
#define SOCMEM_SECEXT                   1u
/* Number of ports ([0, 16]). */
#define SOCMEM_PORT_NR                  5u
/* Depth of AXI port address channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR0_PORT_STRUCT_PORT_ADDR_FF_DEPTH 2u
/* Depth of AXI port write data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR0_PORT_STRUCT_PORT_WDATA_FF_DEPTH 4u
/* Depth of AXI port read data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR0_PORT_STRUCT_PORT_RDATA_FF_DEPTH 4u
/* Depth of AXI port write done channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR0_PORT_STRUCT_PORT_WDONE_FF_DEPTH 2u
/* SROM patching present ({0, 1}, one 1-bit field for each port). */
#define SOCMEM_PORT_NR0_PORT_STRUCT_PATCH_PRESENT 0u
/* Number of patch entries ({[1, 512], one 2-Byte field for each port). */
#define SOCMEM_PORT_NR0_PORT_STRUCT_PATCH_NR 1u
/* Patch entry size ({0, 1, 2, 3} ({8 B, 16 B, 32 B, 64 B}), one 1-Byte field for
   each port). */
#define SOCMEM_PORT_NR0_PORT_STRUCT_PATCH_SIZE 0u
/* SRAM patch address. */
#define SOCMEM_PORT_NR0_PORT_STRUCT_SRAM_PATCH_ADDR 0x28007000u
/* SROM patch boundary. Boundary between non-patchable and patchable SROM. */
#define SOCMEM_PORT_NR0_PORT_STRUCT_SROM_BOUNDARY 0x1000C000u
#define SOCMEM_PORT_NR0_PORT_STRUCT_MATCH_ADDR_SIZE 0x00001000u
/* Existance of MPC in each port */
#define SOCMEM_PORT_NR0_PORT_STRUCT_MPC_PRESENT 1u
/* Depth of AXI port address channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR1_PORT_STRUCT_PORT_ADDR_FF_DEPTH 2u
/* Depth of AXI port write data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR1_PORT_STRUCT_PORT_WDATA_FF_DEPTH 4u
/* Depth of AXI port read data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR1_PORT_STRUCT_PORT_RDATA_FF_DEPTH 4u
/* Depth of AXI port write done channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR1_PORT_STRUCT_PORT_WDONE_FF_DEPTH 2u
/* SROM patching present ({0, 1}, one 1-bit field for each port). */
#define SOCMEM_PORT_NR1_PORT_STRUCT_PATCH_PRESENT 0u
/* Number of patch entries ({[1, 512], one 2-Byte field for each port). */
#define SOCMEM_PORT_NR1_PORT_STRUCT_PATCH_NR 1u
/* Patch entry size ({0, 1, 2, 3} ({8 B, 16 B, 32 B, 64 B}), one 1-Byte field for
   each port). */
#define SOCMEM_PORT_NR1_PORT_STRUCT_PATCH_SIZE 0u
/* SRAM patch address. */
#define SOCMEM_PORT_NR1_PORT_STRUCT_SRAM_PATCH_ADDR 0x28007000u
/* SROM patch boundary. Boundary between non-patchable and patchable SROM. */
#define SOCMEM_PORT_NR1_PORT_STRUCT_SROM_BOUNDARY 0x1000C000u
#define SOCMEM_PORT_NR1_PORT_STRUCT_MATCH_ADDR_SIZE 0x00001000u
/* Existance of MPC in each port */
#define SOCMEM_PORT_NR1_PORT_STRUCT_MPC_PRESENT 1u
/* Depth of AXI port address channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR2_PORT_STRUCT_PORT_ADDR_FF_DEPTH 2u
/* Depth of AXI port write data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR2_PORT_STRUCT_PORT_WDATA_FF_DEPTH 4u
/* Depth of AXI port read data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR2_PORT_STRUCT_PORT_RDATA_FF_DEPTH 4u
/* Depth of AXI port write done channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR2_PORT_STRUCT_PORT_WDONE_FF_DEPTH 2u
/* SROM patching present ({0, 1}, one 1-bit field for each port). */
#define SOCMEM_PORT_NR2_PORT_STRUCT_PATCH_PRESENT 0u
/* Number of patch entries ({[1, 512], one 2-Byte field for each port). */
#define SOCMEM_PORT_NR2_PORT_STRUCT_PATCH_NR 1u
/* Patch entry size ({0, 1, 2, 3} ({8 B, 16 B, 32 B, 64 B}), one 1-Byte field for
   each port). */
#define SOCMEM_PORT_NR2_PORT_STRUCT_PATCH_SIZE 0u
/* SRAM patch address. */
#define SOCMEM_PORT_NR2_PORT_STRUCT_SRAM_PATCH_ADDR 0x28007000u
/* SROM patch boundary. Boundary between non-patchable and patchable SROM. */
#define SOCMEM_PORT_NR2_PORT_STRUCT_SROM_BOUNDARY 0x1000C000u
#define SOCMEM_PORT_NR2_PORT_STRUCT_MATCH_ADDR_SIZE 0x00001000u
/* Existance of MPC in each port */
#define SOCMEM_PORT_NR2_PORT_STRUCT_MPC_PRESENT 1u
/* Depth of AXI port address channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR3_PORT_STRUCT_PORT_ADDR_FF_DEPTH 2u
/* Depth of AXI port write data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR3_PORT_STRUCT_PORT_WDATA_FF_DEPTH 4u
/* Depth of AXI port read data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR3_PORT_STRUCT_PORT_RDATA_FF_DEPTH 4u
/* Depth of AXI port write done channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR3_PORT_STRUCT_PORT_WDONE_FF_DEPTH 2u
/* SROM patching present ({0, 1}, one 1-bit field for each port). */
#define SOCMEM_PORT_NR3_PORT_STRUCT_PATCH_PRESENT 0u
/* Number of patch entries ({[1, 512], one 2-Byte field for each port). */
#define SOCMEM_PORT_NR3_PORT_STRUCT_PATCH_NR 1u
/* Patch entry size ({0, 1, 2, 3} ({8 B, 16 B, 32 B, 64 B}), one 1-Byte field for
   each port). */
#define SOCMEM_PORT_NR3_PORT_STRUCT_PATCH_SIZE 0u
/* SRAM patch address. */
#define SOCMEM_PORT_NR3_PORT_STRUCT_SRAM_PATCH_ADDR 0x28007000u
/* SROM patch boundary. Boundary between non-patchable and patchable SROM. */
#define SOCMEM_PORT_NR3_PORT_STRUCT_SROM_BOUNDARY 0x1000C000u
#define SOCMEM_PORT_NR3_PORT_STRUCT_MATCH_ADDR_SIZE 0x00001000u
/* Existance of MPC in each port */
#define SOCMEM_PORT_NR3_PORT_STRUCT_MPC_PRESENT 1u
/* Depth of AXI port address channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR4_PORT_STRUCT_PORT_ADDR_FF_DEPTH 1u
/* Depth of AXI port write data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR4_PORT_STRUCT_PORT_WDATA_FF_DEPTH 4u
/* Depth of AXI port read data channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR4_PORT_STRUCT_PORT_RDATA_FF_DEPTH 4u
/* Depth of AXI port write done channel FIFO ({[1, 4], one 1-Byte field for each
   port). */
#define SOCMEM_PORT_NR4_PORT_STRUCT_PORT_WDONE_FF_DEPTH 1u
/* SROM patching present ({0, 1}, one 1-bit field for each port). */
#define SOCMEM_PORT_NR4_PORT_STRUCT_PATCH_PRESENT 0u
/* Number of patch entries ({[1, 512], one 2-Byte field for each port). */
#define SOCMEM_PORT_NR4_PORT_STRUCT_PATCH_NR 1u
/* Patch entry size ({0, 1, 2, 3} ({8 B, 16 B, 32 B, 64 B}), one 1-Byte field for
   each port). */
#define SOCMEM_PORT_NR4_PORT_STRUCT_PATCH_SIZE 0u
/* SRAM patch address. */
#define SOCMEM_PORT_NR4_PORT_STRUCT_SRAM_PATCH_ADDR 0x28007000u
/* SROM patch boundary. Boundary between non-patchable and patchable SROM. */
#define SOCMEM_PORT_NR4_PORT_STRUCT_SROM_BOUNDARY 0x1000C000u
#define SOCMEM_PORT_NR4_PORT_STRUCT_MATCH_ADDR_SIZE 0x00001000u
/* Existance of MPC in each port */
#define SOCMEM_PORT_NR4_PORT_STRUCT_MPC_PRESENT 1u
/* Number of SROM banks ({1, 2, 4, 8}). */
#define SOCMEM_SROM_BANK_NR             1u
/* SROM base address. */
#define SOCMEM_SROM_ADDR                0x01000000u
/* SROM base mask (to determine next "power of two" Byte capacity). */
#define SOCMEM_SROM_MASK                0xFFFF0000u
/* SROM capacity in Bytes minus 1. */
#define SOCMEM_SROM_SIZE                0x00010000u
/* SRAM trim default value. */
#define SOCMEM_TRIM_SRAM_DEFAULT        706u
/* SRAM trim field bit size ([0, 32]). */
#define SOCMEM_TRIM_SRAM_WIDTH          32u
/* SROM trim default value. */
#define SOCMEM_TRIM_SROM_DEFAULT        1023u
/* SROM trim field bit size ([0, 32]). */
#define SOCMEM_TRIM_SROM_WIDTH          32u
/* Error correction code (ECC) present ({0, 1}). ECC used: Single Error
   Correction, Double Error Detection. */
#define SOCMEM_ECC_PRESENT              0u
/* ECC on address present ({0, 1}). */
#define SOCMEM_ECC_ADDR_PRESENT         0u
/* Fault functionality for ECC present ({0, 1}). Should be set to '0', when
   ECC_PRESENT is '0'. */
#define SOCMEM_FAULT_PRESENT            1u
/* VT type of instantiated tech cells through mxtk. */
#define SOCMEM_CELL_VT_TYPE             0u
#define SOCMEM_NON_SRPG                 0u
#define SOCMEM_USE_BALLOON_TYPE_SRPG    0u
/* Number of SOCMEM SRAM switches of strength 1 */
#define SOCMEM_SOCMEM_VCCSRAM_MUX1_SW_NR 0u
/* Number of SOCMEM SRAM switches of strength 2 */
#define SOCMEM_SOCMEM_VCCSRAM_MUX2_SW_NR 2u
/* Number of SOCMEM RET switches of strength 1 */
#define SOCMEM_SOCMEM_VCCRET_MUX1_SW_NR 0u
/* Number of SOCMEM RET switches of strength 2 */
#define SOCMEM_SOCMEM_VCCRET_MUX2_SW_NR 0u
/* SRAM Macro read data register stage ([0,1]) ( 0 - read data is registered after
   muxing from all SRAM Macros, 1 - read data from each SRAM Macro is registerd
   ) */
#define SOCMEM_SRAM_RDATA_REG_STAGE     1u
/* FAULT_PRESENT&ECC_PRESENT */
#define SOCMEM_CHIP_TOP_ECC_FAULT_PRESENT 0u
/* FAULT_PRESENT&MPC_PRESENT */
#define SOCMEM_CHIP_TOP_MPC_FAULT_PRESENT 1u
/* Port 0, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT0_ID_WIDTH      15u
/* Port 1, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT1_ID_WIDTH      15u
/* Port 2, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT2_ID_WIDTH      15u
/* Port 3, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT3_ID_WIDTH      15u
/* Port 4, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT4_ID_WIDTH      15u
/* Port 5, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT5_ID_WIDTH      15u
/* Port 6, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT6_ID_WIDTH      15u
/* Port 7, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT7_ID_WIDTH      15u
/* Port 8, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT8_ID_WIDTH      15u
/* Port 9, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT9_ID_WIDTH      15u
/* Port 10, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT10_ID_WIDTH     15u
/* Port 11, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT11_ID_WIDTH     15u
/* Port 12, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT12_ID_WIDTH     15u
/* Port 13, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT13_ID_WIDTH     15u
/* Port 14, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT14_ID_WIDTH     15u
/* Port 15, identifier bit size ([1, 16]). */
#define SOCMEM_MAIN_PORT15_ID_WIDTH     15u
/* SRAM base address. */
#define SOCMEM_MAIN_SRAM_ADDR           0x06000000u
/* SRAM base mask (to determine next "power of two" Byte capacity). */
#define SOCMEM_MAIN_SRAM_MASK           0xCF800000u
/* SRAM capacity in Bytes minus 1. */
#define SOCMEM_MAIN_SRAM_SIZE           0x00500000u
#define SOCMEM_MPC_MASTER_WIDTH         6u
#define SOCMEM_MPC_PC_WIDTH             4u
#define SOCMEM_MPC_PC_NR                8u
#define SOCMEM_MPC_BLK_IDX_MAX          31u
#define SOCMEM_MPC_BLK_IDX_WIDTH        5u
#define SOCMEM_MPC_EXT_PRESENT          0u
#define SOCMEM_MPC_BLK_IDX_MAX_TIMES_FOUR_PLUS_THREE 127u
#define SOCMEM_MPC_BLK_IDX_WIDTH_PLUS_TWO 7u
#define SOCMEM_MPC_BLOCK_SIZE           8u
/* Is SRAM clock same as Port clock */
#define SOCMEM_PORT_STRUCT_PORT_SRAM_SYNC 0u
/* Is SRAM clock same as Port clock */
#define SOCMEM_PORT_STRUCT_PORT_SROM_SYNC 0u
/* Number of LP DPLLs present. */
#define SRSS_NUM_DPLL_LP                2u
/* Number of HP DPLLs present. */
#define SRSS_NUM_DPLL_HP                1u
/* Total number of DPLLs present. Must be calculated (NUM_DPLL_LP+NUM_DPLL_HP).
   Cannot exceed max or NUM_CLKPATH-1. */
#define SRSS_NUM_TOTAL_DPLL             3u
/* Precision ILO (PILO) is present */
#define SRSS_PILO_PRESENT               1u
/* ILO is present */
#define SRSS_ILO_PRESENT                0u
/* WCO is present */
#define SRSS_WCO_PRESENT                1u
/* IMO is present */
#define SRSS_IMO_PRESENT                0u
/* External Crystal Oscillator is present (high frequency) */
#define SRSS_ECO_PRESENT                1u
/* Alternate high-frequency clock is present. This is used for logic optimization. */
#define SRSS_NUM_ALTHF                  0u
/* Alternate low-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTLF_PRESENT              0u
/* Use the hardened clkmux block */
#define SRSS_USE_HARD_CLKMUX            1u
/* Number of clock paths, including direct paths in hardened clkmux block Must be
   >NUM_CLKPATH because implementation internally reserves one path for IMO
   direct mux. Requires a hardened cell to match the setting. See table in SRSS
   Parameters_* tab for valid combinations. */
#define SRSS_HARD_CLKPATH               13u
/* Number of clock paths with muxes in hardened clkmux block Must be >=
   NUM_TOTAL_PLL+1. Requires a hardened cell to match the setting. See table in
   SRSS Parameters_* tab for valid combinations. */
#define SRSS_HARD_CLKPATHMUX            13u
/* Number of HFCLKS present in hardened clkmux block Must be >= NUM_HFROOT.
   Requires a hardened cell to match the setting. See table in SRSS Parameters_*
   tab for valid combinations. */
#define SRSS_HARD_HFROOT                16u
/* Number of clock paths. Must be > 0. Recommend
   NUM_CLKPATH>=NUM_TOTAL_PLL+CSV_PRESENT+2. CSV and FLL requires special paths,
   and one extra is recommended for programming flexibility. minimum is 1.
   Maximum is 15, because one is reserved for IHO direct mux. */
#define SRSS_NUM_CLKPATH                6u
/* Number of HFCLK roots present. Must be > 0. Recommend NUM_HFROOT=<# chipwide
   roots>+CSV_PRESENT. minimum is 1 */
#define SRSS_NUM_HFROOT                 14u
/* Mask of DIRECT_MUX defaults. For each clock root i, if bit[i] is low the
   DIRECT_MUX defaults to IMO. If bit[0] is high, the DIRECT_MUX selects the
   output of ROOT_MUX. For backward compatibility, M33-only systems can have all
   mask bits high. In all cases, must have bit[0]==1 to start the chip. Must
   have bit[0]==1 to start the chip properly. */
#define SRSS_MASK_DIRECTMUX_DEF         0x0000FFFFu
/* Mask of which HFCLK roots are enabled when the debugger requests power up
   (CDBGPWRUPREQ). For each clock root i, SRSS enables the clock in response to
   CDBGPWRUPREQ, if bit[i] of mask is high. SRSS automatically enables clk_hf0,
   regardless of setting of mask bit0. */
#define SRSS_MASK_DEBUG_CLK             3u
/* CSV present. User must add one NUM_CLKPATH and one NUM_HFROOT to monitor ILO0
   with CSV_HF_REF clock. */
#define SRSS_CSV_PRESENT                1u
/* CSV_LF present. Monitors clk_lf with CSV_LF_REF clock. */
#define SRSS_CSV_LF_PRESENT             1u
/* CSV_PILO present. Monitors clk_pilo with CSV_PILO_REF clock. */
#define SRSS_CSV_PILO_PRESENT           0u
/* CSV_RTC is present. Monitors clk_rtc_hv with CSV_RTC_REF_SEL clock. Must have
   RTC_PRESENT==1. */
#define SRSS_CSV_RTC_PRESENT            0u
/* Number of DSI inputs into clock muxes. This is used for logic optimization.
   Must be > 0 */
#define SRSS_NUM_DSI                    16u
/* WDT type A is present (backward compatible version) Must have WDT_A_PRESENT or
   WDT_B_PRESENT, but not both */
#define SRSS_WDT_A_PRESENT              1u
/* Number of multi-counter watchdog timers (type A). Min is zero. If backward
   compatibility is not needed, it is recommended to use type B instead. */
#define SRSS_NUM_MCWDT                  2u
/* Width of the WDT (Type A) counter. For backward compatibility, the minimum
   allowed is 16b. */
#define SRSS_NUM_WDT_A_BITS             22u
/* WDT type B is present. Software incompatibility with type A. Must have
   WDT_A_PRESENT or WDT_B_PRESENT, but not both */
#define SRSS_WDT_B_PRESENT              0u
/* Number of multi-counter watchdog timers (type B). Software incompatibility with
   type A. */
#define SRSS_NUM_MCWDT_B                0u
/* POR present. */
#define SRSS_POR_PRESENT                1u
/* OVD present on VCCD */
#define SRSS_OVD_PRESENT                1u
/* LVD present */
#define SRSS_LVD_PRESENT                1u
/* S22 Regulator Set A system is present */
#define SRSS_REGSETA_PRESENT            1u
/* S22 Regulator Set B system is present */
#define SRSS_REGSETB_PRESENT            0u
/* Mask for whether a PD is present in the PDCM. The zeroth bit is the PD
   controlled by the main PPU and must always be set. Must have
   PDCM_PD_PRESENT[0]==1. */
#define SRSS_PDCM_PD_PRESENT            511u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT0_PDCM_PD_DEFAULT_ON 30u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT0_PDCM_PD_CONFIG_ON 1u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT1_PDCM_PD_DEFAULT_ON 32u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT1_PDCM_PD_CONFIG_ON 2u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT2_PDCM_PD_DEFAULT_ON 16u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT2_PDCM_PD_CONFIG_ON 4u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT3_PDCM_PD_DEFAULT_ON 16u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT3_PDCM_PD_CONFIG_ON 8u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT4_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT4_PDCM_PD_CONFIG_ON 336u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT5_PDCM_PD_DEFAULT_ON 448u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT5_PDCM_PD_CONFIG_ON 48u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT6_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT6_PDCM_PD_CONFIG_ON 80u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT7_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT7_PDCM_PD_CONFIG_ON 496u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT8_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT8_PDCM_PD_CONFIG_ON 336u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT9_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT9_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT10_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT10_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT11_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT11_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT12_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT12_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT13_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT13_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT14_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT14_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT15_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT15_PDCM_PD_CONFIG_ON 0u
/* Number of main power domains */
#define SRSS_NUM_GLOBAL_PD              2u
/* Number of PWR_HIB_DATA registers. Min is zero. */
#define SRSS_NUM_HIBDATA                0u
/* Number of additional HIBERNATE wakeup sources It is recommended to have min 4
   and assign them to GPIOs for backward compatibility with previous products.
   Encoding is product-specific. */
#define SRSS_NUM_HIB_WAKE               4u
/* RTC Logic is present. */
#define SRSS_RTC_PRESENT                1u
/* Numer of SRAM trim registers. The number denotes the types of SRAMs used in the
   platform. */
#define SRSS_TRIM_NR                    9u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR0_TRIM_DEFAULT      1859u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR1_TRIM_DEFAULT      1859u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR2_TRIM_DEFAULT      1540u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR3_TRIM_DEFAULT      1540u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR4_TRIM_DEFAULT      1540u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR5_TRIM_DEFAULT      1540u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR6_TRIM_DEFAULT      557u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR7_TRIM_DEFAULT      1540u
/* This is a vector parameter that defines the default value of the trim register
   for each SRAM type. There are TRIM_NR of members */
#define SRSS_TRIM_NR8_TRIM_DEFAULT      11u
/* CSV_RTC is present. Monitors clk_rtc_hv with CSV_RTC_REF_SEL clock. Must have
   RTC_PRESENT==1. */
#define SRSS_BACKUP_CSV_RTC_PRESENT     0u
/* Number of HP DPLLs present. */
#define SRSS_CLK_TRIM_DPLL_HP_NUM_DPLL_HP 1u
/* Number of LP DPLLs present. */
#define SRSS_CLK_TRIM_DPLL_LP_NUM_DPLL_LP 2u
/* Mask of HFCLK root clock supervisors (CSV). For each clock root i, bit[i] of
   mask indicates presence of a CSV. Requires CSV_PRESENT==1. */
#define SRSS_CSV_HF_MASK_HFCSV          0x00003FFFu
/* CSV_RTC is present. Monitors clk_rtc_hv with CSV_RTC_REF_SEL clock. Must have
   RTC_PRESENT==1. */
#define SRSS_RTC_CSV_RTC_PRESENT        0u
/* Alarm1 present in RTC Requires RTC_PRESENT==1 */
#define SRSS_RTC_ALM1_PRESENT           1u
/* Alarm2 present in RTC this requires ALM1_PRESENT to be set */
#define SRSS_RTC_ALM2_PRESENT           1u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_RTC_NUM_BREG0              4u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_RTC_NUM_BREG1              4u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_RTC_NUM_BREG2              8u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_RTC_NUM_BREG3              0u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define TCPWM_MASTER_WIDTH              6u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define TCPWM_TR_ONE_CNT_NR             1u
/* Number of input triggers routed to all counters (0..254),
   NR_TR_ONE_CNT+NR_TR_ALL CNT <= 254 */
#define TCPWM_TR_ALL_CNT_NR             28u
/* Number of TCPWM counter groups (1..4) */
#define TCPWM_GRP_NR                    2u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR0_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_GRP_CC1_PRESENT 0u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR0_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR0_CNT_GRP_SMC_PRESENT 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR0_GRP_GRP_CNT_NR    8u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR1_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR1_CNT_GRP_SMC_PRESENT 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR1_GRP_GRP_CNT_NR    24u
/* Number of AHB-Lite "hmaster[]" bits ([4, 8]). */
#define TDM_MASTER_WIDTH                6u
/* Number of TDM structures ({1, 2, 3, 4}]). */
#define TDM_NR                          2u
/* Number of channels per TDM structure. */
#define TDM_NR0_CH_NR                   8u
/* Number of channels per TDM structure. */
#define TDM_NR0_TDM_RX_STRUCT_CH_NR     8u
/* Number of channels per TDM structure. */
#define TDM_NR0_TDM_TX_STRUCT_CH_NR     8u
/* Number of channels per TDM structure. */
#define TDM_NR1_CH_NR                   8u
/* Number of channels per TDM structure. */
#define TDM_NR1_TDM_RX_STRUCT_CH_NR     8u
/* Number of channels per TDM structure. */
#define TDM_NR1_TDM_TX_STRUCT_CH_NR     8u
/* Spare Enable 0=no spare, 1=max, 2=min */
#define TDM_SPARE_EN                    0u
/* 0=ULL65, 1=MXS40-ULP, 2=MXS40E, 3=M0S8, 4=MXS40-HD, 5=F45, 6=MXS40v2, 7=T28HPM,
   8=T28HPL, 9=T28HPC */
#define TDM_PLATFORM_VARIANT            10u
/* SRAM vendor ({0=Cypress, 1=Synopsys, 2=ARM, 3=BRCM}) */
#define TDM_RAM_VEND                    2u
/* Type of SRAM used (applicable for S22 platform) */
#define TDM_SRAM_TYPE                   0u
/* Use mxsramwrap IP */
#define TDM_MXSRAMWRAP_EN               1u
/* Number of connected clocks at the IP's top level ([1, 4]). */
#define TDM_CHIP_TOP_CLK_NR             2u
/* Replay functionality for transmitter. This functionality adds significant
   silicon area. */
#define TDM_TDM_TX_STRUCT_REPLAY_PRESENT 0u

/* MMIO Targets Defines */
/* SYS_MMIO0.SRSS22 - PERI0, CLK_HF0 */
#define CY_MMIO_SRSS22_GROUP_NR         0u
#define CY_MMIO_SRSS22_SLAVE_NR         4u
#define CY_MMIO_SRSS22_PERI_NR          0u
#define CY_MMIO_SRSS22_CLK_HF_NR        0u
/* SYS_MMIO0.PWRMODE22 - PERI0, CLK_HF0 */
#define CY_MMIO_PWRMODE22_GROUP_NR      0u
#define CY_MMIO_PWRMODE22_SLAVE_NR      5u
#define CY_MMIO_PWRMODE22_PERI_NR       0u
#define CY_MMIO_PWRMODE22_CLK_HF_NR     0u
/* SYS_MMIO0.BACKUP22 - PERI0, CLK_HF0 */
#define CY_MMIO_BACKUP22_GROUP_NR       0u
#define CY_MMIO_BACKUP22_SLAVE_NR       6u
#define CY_MMIO_BACKUP22_PERI_NR        0u
#define CY_MMIO_BACKUP22_CLK_HF_NR      0u
/* SYS_MMIO0.DEBUG600 - PERI0, CLK_HF0 */
#define CY_MMIO_DEBUG600_GROUP_NR       0u
#define CY_MMIO_DEBUG600_SLAVE_NR       7u
#define CY_MMIO_DEBUG600_PERI_NR        0u
#define CY_MMIO_DEBUG600_CLK_HF_NR      0u
/* SYS_MMIO0.M0SECCPUSS_STATUS - PERI0, CLK_HF0 */
#define CY_MMIO_M0SECCPUSS_STATUS_GROUP_NR 0u
#define CY_MMIO_M0SECCPUSS_STATUS_SLAVE_NR 8u
#define CY_MMIO_M0SECCPUSS_STATUS_PERI_NR 0u
#define CY_MMIO_M0SECCPUSS_STATUS_CLK_HF_NR 0u
/* SYS_MMIO1.HSIOM - PERI0, CLK_HF10 */
#define CY_MMIO_HSIOM_GROUP_NR          1u
#define CY_MMIO_HSIOM_SLAVE_NR          0u
#define CY_MMIO_HSIOM_PERI_NR           0u
#define CY_MMIO_HSIOM_CLK_HF_NR         10u
/* SYS_MMIO1.GPIO - PERI0, CLK_HF10 */
#define CY_MMIO_GPIO_GROUP_NR           1u
#define CY_MMIO_GPIO_SLAVE_NR           1u
#define CY_MMIO_GPIO_PERI_NR            0u
#define CY_MMIO_GPIO_CLK_HF_NR          10u
/* SYS_MMIO1.SMARTIO - PERI0, CLK_HF10 */
#define CY_MMIO_SMARTIO_GROUP_NR        1u
#define CY_MMIO_SMARTIO_SLAVE_NR        2u
#define CY_MMIO_SMARTIO_PERI_NR         0u
#define CY_MMIO_SMARTIO_CLK_HF_NR       10u
/* SYS_MMIO1.CANFD0 - PERI0, CLK_HF10 */
#define CY_MMIO_CANFD0_GROUP_NR         1u
#define CY_MMIO_CANFD0_SLAVE_NR         3u
#define CY_MMIO_CANFD0_PERI_NR          0u
#define CY_MMIO_CANFD0_CLK_HF_NR        10u
/* SYS_MMIO1.TCPWM0 - PERI0, CLK_HF10 */
#define CY_MMIO_TCPWM0_GROUP_NR         1u
#define CY_MMIO_TCPWM0_SLAVE_NR         4u
#define CY_MMIO_TCPWM0_PERI_NR          0u
#define CY_MMIO_TCPWM0_CLK_HF_NR        10u
/* SYS_MMIO1.LPCOMP - PERI0, CLK_HF10 */
#define CY_MMIO_LPCOMP_GROUP_NR         1u
#define CY_MMIO_LPCOMP_SLAVE_NR         5u
#define CY_MMIO_LPCOMP_PERI_NR          0u
#define CY_MMIO_LPCOMP_CLK_HF_NR        10u
/* SYS_MMIO1.SCB0 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB0_GROUP_NR           1u
#define CY_MMIO_SCB0_SLAVE_NR           6u
#define CY_MMIO_SCB0_PERI_NR            0u
#define CY_MMIO_SCB0_CLK_HF_NR          10u
/* SYS_MMIO1.SCB2 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB2_GROUP_NR           1u
#define CY_MMIO_SCB2_SLAVE_NR           7u
#define CY_MMIO_SCB2_PERI_NR            0u
#define CY_MMIO_SCB2_CLK_HF_NR          10u
/* SYS_MMIO1.SCB3 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB3_GROUP_NR           1u
#define CY_MMIO_SCB3_SLAVE_NR           8u
#define CY_MMIO_SCB3_PERI_NR            0u
#define CY_MMIO_SCB3_CLK_HF_NR          10u
/* SYS_MMIO1.SCB4 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB4_GROUP_NR           1u
#define CY_MMIO_SCB4_SLAVE_NR           9u
#define CY_MMIO_SCB4_PERI_NR            0u
#define CY_MMIO_SCB4_CLK_HF_NR          10u
/* SYS_MMIO1.SCB5 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB5_GROUP_NR           1u
#define CY_MMIO_SCB5_SLAVE_NR           10u
#define CY_MMIO_SCB5_PERI_NR            0u
#define CY_MMIO_SCB5_CLK_HF_NR          10u
/* SYS_MMIO1.SCB6 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB6_GROUP_NR           1u
#define CY_MMIO_SCB6_SLAVE_NR           11u
#define CY_MMIO_SCB6_PERI_NR            0u
#define CY_MMIO_SCB6_CLK_HF_NR          10u
/* SYS_MMIO1.SCB7 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB7_GROUP_NR           1u
#define CY_MMIO_SCB7_SLAVE_NR           12u
#define CY_MMIO_SCB7_PERI_NR            0u
#define CY_MMIO_SCB7_CLK_HF_NR          10u
/* SYS_MMIO1.SCB8 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB8_GROUP_NR           1u
#define CY_MMIO_SCB8_SLAVE_NR           13u
#define CY_MMIO_SCB8_PERI_NR            0u
#define CY_MMIO_SCB8_CLK_HF_NR          10u
/* SYS_MMIO1.SCB9 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB9_GROUP_NR           1u
#define CY_MMIO_SCB9_SLAVE_NR           14u
#define CY_MMIO_SCB9_PERI_NR            0u
#define CY_MMIO_SCB9_CLK_HF_NR          10u
/* SYS_MMIO1.SCB10 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB10_GROUP_NR          1u
#define CY_MMIO_SCB10_SLAVE_NR          15u
#define CY_MMIO_SCB10_PERI_NR           0u
#define CY_MMIO_SCB10_CLK_HF_NR         10u
/* SYS_MMIO1.SCB11 - PERI0, CLK_HF10 */
#define CY_MMIO_SCB11_GROUP_NR          1u
#define CY_MMIO_SCB11_SLAVE_NR          16u
#define CY_MMIO_SCB11_PERI_NR           0u
#define CY_MMIO_SCB11_CLK_HF_NR         10u
/* SYS_MMIO1.I3C - PERI0, CLK_HF10 */
#define CY_MMIO_I3C_GROUP_NR            1u
#define CY_MMIO_I3C_SLAVE_NR            17u
#define CY_MMIO_I3C_PERI_NR             0u
#define CY_MMIO_I3C_CLK_HF_NR           10u
/* SYS_MMIO2.DFT - PERI0, CLK_HF0 */
#define CY_MMIO_DFT_GROUP_NR            2u
#define CY_MMIO_DFT_SLAVE_NR            0u
#define CY_MMIO_DFT_PERI_NR             0u
#define CY_MMIO_DFT_CLK_HF_NR           0u
/* SYS_MMIO2.ETH0 - PERI0, CLK_HF0 */
#define CY_MMIO_ETH0_GROUP_NR           2u
#define CY_MMIO_ETH0_SLAVE_NR           1u
#define CY_MMIO_ETH0_PERI_NR            0u
#define CY_MMIO_ETH0_CLK_HF_NR          0u
/* SYS_MMIO3.SCB1 - PERI0, CLK_HF11 */
#define CY_MMIO_SCB1_GROUP_NR           3u
#define CY_MMIO_SCB1_SLAVE_NR           0u
#define CY_MMIO_SCB1_PERI_NR            0u
#define CY_MMIO_SCB1_CLK_HF_NR          11u
/* SYS_MMIO4.MXNNLITE - PERI0, CLK_HF0 */
#define CY_MMIO_MXNNLITE_GROUP_NR       4u
#define CY_MMIO_MXNNLITE_SLAVE_NR       0u
#define CY_MMIO_MXNNLITE_PERI_NR        0u
#define CY_MMIO_MXNNLITE_CLK_HF_NR      0u
/* SYS_MMIO5.PASS - PERI0, CLK_HF9 */
#define CY_MMIO_PASS_GROUP_NR           5u
#define CY_MMIO_PASS_SLAVE_NR           0u
#define CY_MMIO_PASS_PERI_NR            0u
#define CY_MMIO_PASS_CLK_HF_NR          9u
/* APP_MMIO1.PDM0 - PERI1, CLK_HF1 */
#define CY_MMIO_PDM0_GROUP_NR           1u
#define CY_MMIO_PDM0_SLAVE_NR           0u
#define CY_MMIO_PDM0_PERI_NR            1u
#define CY_MMIO_PDM0_CLK_HF_NR          1u
/* APP_MMIO1.TDM0 - PERI1, CLK_HF1 */
#define CY_MMIO_TDM0_GROUP_NR           1u
#define CY_MMIO_TDM0_SLAVE_NR           1u
#define CY_MMIO_TDM0_PERI_NR            1u
#define CY_MMIO_TDM0_CLK_HF_NR          1u
/* APP_MMIO1.SMIF0 - PERI1, CLK_HF1 */
#define CY_MMIO_SMIF0_GROUP_NR          1u
#define CY_MMIO_SMIF0_SLAVE_NR          2u
#define CY_MMIO_SMIF0_PERI_NR           1u
#define CY_MMIO_SMIF0_CLK_HF_NR         1u
/* APP_MMIO1.SMIF01 - PERI1, CLK_HF1 */
#define CY_MMIO_SMIF01_GROUP_NR         1u
#define CY_MMIO_SMIF01_SLAVE_NR         3u
#define CY_MMIO_SMIF01_PERI_NR          1u
#define CY_MMIO_SMIF01_CLK_HF_NR        1u
/* APP_MMIO2.MXU550 - PERI1, CLK_HF1 */
#define CY_MMIO_MXU550_GROUP_NR         2u
#define CY_MMIO_MXU550_SLAVE_NR         0u
#define CY_MMIO_MXU550_PERI_NR          1u
#define CY_MMIO_MXU550_CLK_HF_NR        1u
/* APP_MMIO2.SOCMEM - PERI1, CLK_HF1 */
#define CY_MMIO_SOCMEM_GROUP_NR         2u
#define CY_MMIO_SOCMEM_SLAVE_NR         1u
#define CY_MMIO_SOCMEM_PERI_NR          1u
#define CY_MMIO_SOCMEM_CLK_HF_NR        1u
/* APP_MMIO3.GFXSS_GPU - PERI1, CLK_HF1 */
#define CY_MMIO_GFXSS_GPU_GROUP_NR      3u
#define CY_MMIO_GFXSS_GPU_SLAVE_NR      0u
#define CY_MMIO_GFXSS_GPU_PERI_NR       1u
#define CY_MMIO_GFXSS_GPU_CLK_HF_NR     1u
/* APP_MMIO3.GFXSS_DC - PERI1, CLK_HF1 */
#define CY_MMIO_GFXSS_DC_GROUP_NR       3u
#define CY_MMIO_GFXSS_DC_SLAVE_NR       1u
#define CY_MMIO_GFXSS_DC_PERI_NR        1u
#define CY_MMIO_GFXSS_DC_CLK_HF_NR      1u
/* APP_MMIO3.GFXSS_MIPIDSI - PERI1, CLK_HF1 */
#define CY_MMIO_GFXSS_MIPIDSI_GROUP_NR  3u
#define CY_MMIO_GFXSS_MIPIDSI_SLAVE_NR  2u
#define CY_MMIO_GFXSS_MIPIDSI_PERI_NR   1u
#define CY_MMIO_GFXSS_MIPIDSI_CLK_HF_NR 1u
/* APP_MMIO3.SDHC0 - PERI1, CLK_HF1 */
#define CY_MMIO_SDHC0_GROUP_NR          3u
#define CY_MMIO_SDHC0_SLAVE_NR          3u
#define CY_MMIO_SDHC0_PERI_NR           1u
#define CY_MMIO_SDHC0_CLK_HF_NR         1u
/* APP_MMIO3.SDHC1 - PERI1, CLK_HF1 */
#define CY_MMIO_SDHC1_GROUP_NR          3u
#define CY_MMIO_SDHC1_SLAVE_NR          4u
#define CY_MMIO_SDHC1_PERI_NR           1u
#define CY_MMIO_SDHC1_CLK_HF_NR         1u
/* APP_MMIO3.USBHS - PERI1, CLK_HF1 */
#define CY_MMIO_USBHS_GROUP_NR          3u
#define CY_MMIO_USBHS_SLAVE_NR          5u
#define CY_MMIO_USBHS_PERI_NR           1u
#define CY_MMIO_USBHS_CLK_HF_NR         1u
/* APP_MMIO_TCM.CM55_TCM_512K - PERI1, CLK_HF1 */
#define CY_MMIO_CM55_TCM_512K_GROUP_NR  4u
#define CY_MMIO_CM55_TCM_512K_SLAVE_NR  0u
#define CY_MMIO_CM55_TCM_512K_PERI_NR   1u
#define CY_MMIO_CM55_TCM_512K_CLK_HF_NR 1u

/* Protection regions */
typedef enum
{
    PROT_PERI0_START                = 0x00000000u,
    PROT_PERI0_MAIN                 = 0x00000000u, /* Peri 0, Address 0x42000000, size 0x00004000 */
    PROT_PERI0_GR0_GROUP            = 0x00000001u, /* Peri 0, Address 0x42004010, size 0x00000008 */
    PROT_PERI0_GR1_GROUP            = 0x00000002u, /* Peri 0, Address 0x42004040, size 0x00000020 */
    PROT_PERI0_GR2_GROUP            = 0x00000003u, /* Peri 0, Address 0x42004080, size 0x00000020 */
    PROT_PERI0_GR3_GROUP            = 0x00000004u, /* Peri 0, Address 0x420040c0, size 0x00000020 */
    PROT_PERI0_GR4_GROUP            = 0x00000005u, /* Peri 0, Address 0x42004110, size 0x00000008 */
    PROT_PERI0_GR5_GROUP            = 0x00000006u, /* Peri 0, Address 0x42004140, size 0x00000020 */
    PROT_PERI0_GR0_BOOT             = 0x00000007u, /* Peri 0, Address 0x42004020, size 0x00000004 */
    PROT_PERI0_GR1_BOOT             = 0x00000008u, /* Peri 0, Address 0x42004060, size 0x00000004 */
    PROT_PERI0_GR2_BOOT             = 0x00000009u, /* Peri 0, Address 0x420040a0, size 0x00000004 */
    PROT_PERI0_GR3_BOOT             = 0x0000000Au, /* Peri 0, Address 0x420040e0, size 0x00000004 */
    PROT_PERI0_GR4_BOOT             = 0x0000000Bu, /* Peri 0, Address 0x42004120, size 0x00000004 */
    PROT_PERI0_GR5_BOOT             = 0x0000000Cu, /* Peri 0, Address 0x42004160, size 0x00000004 */
    PROT_PERI0_TR                   = 0x0000000Du, /* Peri 0, Address 0x42008000, size 0x00008000 */
    PROT_PERI0_PPC0_PPC_PPC_SECURE  = 0x0000000Eu, /* Peri 0, Address 0x42020000, size 0x00004000 */
    PROT_PERI0_PPC0_PPC_PPC_NONSECURE = 0x0000000Fu, /* Peri 0, Address 0x42024000, size 0x00004000 */
    PROT_PERI0_PERI_PCLK0_MAIN      = 0x00000010u, /* Peri 0, Address 0x42040000, size 0x00020000 */
    PROT_PERI0_RRAMC0_RRAM_EXTRA_AREA_RRAMC_PROTECTED = 0x00000011u, /* Peri 0, Address 0x42200000, size 0x00002000 */
    PROT_PERI0_RRAMC0_RRAM_EXTRA_AREA_RRAMC_GENERAL = 0x00000012u, /* Peri 0, Address 0x42204000, size 0x00002000 */
    PROT_PERI0_RRAMC0_RRAM_EXTRA_AREA_RRAMC_REPAIR = 0x00000013u, /* Peri 0, Address 0x42208000, size 0x00000200 */
    PROT_PERI0_RRAMC0_RRAM_EXTRA_AREA_RRAMC_EXTRA = 0x00000014u, /* Peri 0, Address 0x42209000, size 0x00001000 */
    PROT_PERI0_RRAMC0_RRAMC0_RRAMC_USER = 0x00000015u, /* Peri 0, Address 0x42210000, size 0x00000004 */
    PROT_PERI0_RRAMC0_RRAMC0_RRAMC_ALLUSER = 0x00000016u, /* Peri 0, Address 0x42210020, size 0x00000020 */
    PROT_PERI0_RRAMC0_RRAMC0_RRAMC_M0SEC = 0x00000017u, /* Peri 0, Address 0x42210100, size 0x00000020 */
    PROT_PERI0_RRAMC0_MPC0_PPC_MPC_MAIN = 0x00000018u, /* Peri 0, Address 0x42211000, size 0x00000004 */
    PROT_PERI0_RRAMC0_MPC1_PPC_MPC_MAIN = 0x00000019u, /* Peri 0, Address 0x42212000, size 0x00000004 */
    PROT_PERI0_RRAMC0_MPC0_PPC_MPC_PC = 0x0000001Au, /* Peri 0, Address 0x42211100, size 0x00000020 */
    PROT_PERI0_RRAMC0_MPC1_PPC_MPC_PC = 0x0000001Bu, /* Peri 0, Address 0x42212100, size 0x00000020 */
    PROT_PERI0_RRAMC0_MPC0_PPC_MPC_ROT = 0x0000001Cu, /* Peri 0, Address 0x42211200, size 0x00000020 */
    PROT_PERI0_RRAMC0_MPC1_PPC_MPC_ROT = 0x0000001Du, /* Peri 0, Address 0x42212200, size 0x00000020 */
    PROT_PERI0_RRAMC0_RRAM_SFR_RRAMC_SFR_USER = 0x0000001Eu, /* Peri 0, Address 0x42213000, size 0x00000040 */
    PROT_PERI0_RRAMC0_RRAM_SFR_RRAMC_SFR_FPGA = 0x0000001Fu, /* Peri 0, Address 0x42213040, size 0x00000010 */
    PROT_PERI0_RRAMC0_RRAM_SFR_RRAMC_SFR_NONUSER = 0x00000020u, /* Peri 0, Address 0x42213800, size 0x00000800 */
    PROT_PERI0_M33SYSCPUSS          = 0x00000021u, /* Peri 0, Address 0x42220000, size 0x00010000 */
    PROT_PERI0_PASS                 = 0x00000022u, /* Peri 0, Address 0x42e00000, size 0x00100000 */
    PROT_PERI0_RAMC0_CM33           = 0x00000023u, /* Peri 0, Address 0x42230000, size 0x00000010 */
    PROT_PERI0_RAMC1_CM33           = 0x00000024u, /* Peri 0, Address 0x42240000, size 0x00000010 */
    PROT_PERI0_RAMC0_BOOT           = 0x00000025u, /* Peri 0, Address 0x42230100, size 0x00000004 */
    PROT_PERI0_RAMC1_BOOT           = 0x00000026u, /* Peri 0, Address 0x42240100, size 0x00000004 */
    PROT_PERI0_RAMC0_RAM_PWR        = 0x00000027u, /* Peri 0, Address 0x42230200, size 0x00000100 */
    PROT_PERI0_RAMC1_RAM_PWR        = 0x00000028u, /* Peri 0, Address 0x42240200, size 0x00000100 */
    PROT_PERI0_RAMC0_MPC0_PPC_MPC_MAIN = 0x00000029u, /* Peri 0, Address 0x42234000, size 0x00000004 */
    PROT_PERI0_RAMC1_MPC0_PPC_MPC_MAIN = 0x0000002Au, /* Peri 0, Address 0x42244000, size 0x00000004 */
    PROT_PERI0_RAMC0_MPC0_PPC_MPC_PC = 0x0000002Bu, /* Peri 0, Address 0x42234100, size 0x00000020 */
    PROT_PERI0_RAMC1_MPC0_PPC_MPC_PC = 0x0000002Cu, /* Peri 0, Address 0x42244100, size 0x00000020 */
    PROT_PERI0_RAMC0_MPC0_PPC_MPC_ROT = 0x0000002Du, /* Peri 0, Address 0x42234200, size 0x00000020 */
    PROT_PERI0_RAMC1_MPC0_PPC_MPC_ROT = 0x0000002Eu, /* Peri 0, Address 0x42244200, size 0x00000020 */
    PROT_PERI0_MXCM33_CM33          = 0x0000002Fu, /* Peri 0, Address 0x42260000, size 0x00000100 */
    PROT_PERI0_MXCM33_CM33_S        = 0x00000030u, /* Peri 0, Address 0x42261000, size 0x00000004 */
    PROT_PERI0_MXCM33_CM33_NS       = 0x00000031u, /* Peri 0, Address 0x42261004, size 0x00000004 */
    PROT_PERI0_MXCM33_BOOT_PC0      = 0x00000032u, /* Peri 0, Address 0x42262000, size 0x00000080 */
    PROT_PERI0_MXCM33_BOOT_PC1      = 0x00000033u, /* Peri 0, Address 0x42262100, size 0x00000004 */
    PROT_PERI0_MXCM33_BOOT_PC2      = 0x00000034u, /* Peri 0, Address 0x42262140, size 0x00000004 */
    PROT_PERI0_MXCM33_BOOT_PC3      = 0x00000035u, /* Peri 0, Address 0x42262180, size 0x00000004 */
    PROT_PERI0_MXCM33_BOOT          = 0x00000036u, /* Peri 0, Address 0x422621c0, size 0x00000004 */
    PROT_PERI0_MXCM33_CM33_INT      = 0x00000037u, /* Peri 0, Address 0x42268000, size 0x00000400 */
    PROT_PERI0_DW0_DW               = 0x00000038u, /* Peri 0, Address 0x42270000, size 0x00000080 */
    PROT_PERI0_DW1_DW               = 0x00000039u, /* Peri 0, Address 0x42280000, size 0x00000080 */
    PROT_PERI0_DW0_DW_CRC           = 0x0000003Au, /* Peri 0, Address 0x42270100, size 0x00000080 */
    PROT_PERI0_DW1_DW_CRC           = 0x0000003Bu, /* Peri 0, Address 0x42280100, size 0x00000080 */
    PROT_PERI0_DW0_CH_STRUCT0_CH    = 0x0000003Cu, /* Peri 0, Address 0x42278000, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT1_CH    = 0x0000003Du, /* Peri 0, Address 0x42278040, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT2_CH    = 0x0000003Eu, /* Peri 0, Address 0x42278080, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT3_CH    = 0x0000003Fu, /* Peri 0, Address 0x422780c0, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT4_CH    = 0x00000040u, /* Peri 0, Address 0x42278100, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT5_CH    = 0x00000041u, /* Peri 0, Address 0x42278140, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT6_CH    = 0x00000042u, /* Peri 0, Address 0x42278180, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT7_CH    = 0x00000043u, /* Peri 0, Address 0x422781c0, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT8_CH    = 0x00000044u, /* Peri 0, Address 0x42278200, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT9_CH    = 0x00000045u, /* Peri 0, Address 0x42278240, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT10_CH   = 0x00000046u, /* Peri 0, Address 0x42278280, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT11_CH   = 0x00000047u, /* Peri 0, Address 0x422782c0, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT12_CH   = 0x00000048u, /* Peri 0, Address 0x42278300, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT13_CH   = 0x00000049u, /* Peri 0, Address 0x42278340, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT14_CH   = 0x0000004Au, /* Peri 0, Address 0x42278380, size 0x00000040 */
    PROT_PERI0_DW0_CH_STRUCT15_CH   = 0x0000004Bu, /* Peri 0, Address 0x422783c0, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT0_CH    = 0x0000004Cu, /* Peri 0, Address 0x42288000, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT1_CH    = 0x0000004Du, /* Peri 0, Address 0x42288040, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT2_CH    = 0x0000004Eu, /* Peri 0, Address 0x42288080, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT3_CH    = 0x0000004Fu, /* Peri 0, Address 0x422880c0, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT4_CH    = 0x00000050u, /* Peri 0, Address 0x42288100, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT5_CH    = 0x00000051u, /* Peri 0, Address 0x42288140, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT6_CH    = 0x00000052u, /* Peri 0, Address 0x42288180, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT7_CH    = 0x00000053u, /* Peri 0, Address 0x422881c0, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT8_CH    = 0x00000054u, /* Peri 0, Address 0x42288200, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT9_CH    = 0x00000055u, /* Peri 0, Address 0x42288240, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT10_CH   = 0x00000056u, /* Peri 0, Address 0x42288280, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT11_CH   = 0x00000057u, /* Peri 0, Address 0x422882c0, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT12_CH   = 0x00000058u, /* Peri 0, Address 0x42288300, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT13_CH   = 0x00000059u, /* Peri 0, Address 0x42288340, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT14_CH   = 0x0000005Au, /* Peri 0, Address 0x42288380, size 0x00000040 */
    PROT_PERI0_DW1_CH_STRUCT15_CH   = 0x0000005Bu, /* Peri 0, Address 0x422883c0, size 0x00000040 */
    PROT_PERI0_CPUSS_ALL_PC         = 0x0000005Cu, /* Peri 0, Address 0x42290000, size 0x00000080 */
    PROT_PERI0_CPUSS_DDFT           = 0x0000005Du, /* Peri 0, Address 0x42290080, size 0x00000004 */
    PROT_PERI0_CPUSS_CM33_S         = 0x0000005Eu, /* Peri 0, Address 0x42290100, size 0x00000004 */
    PROT_PERI0_CPUSS_CM33_NS        = 0x0000005Fu, /* Peri 0, Address 0x42290120, size 0x00000004 */
    PROT_PERI0_CPUSS_MSC_INT        = 0x00000060u, /* Peri 0, Address 0x42290200, size 0x00000010 */
    PROT_PERI0_CPUSS_AP             = 0x00000061u, /* Peri 0, Address 0x42291000, size 0x00000004 */
    PROT_PERI0_CPUSS_BOOT           = 0x00000062u, /* Peri 0, Address 0x42292000, size 0x00000008 */
    PROT_PERI0_MS0_MAIN             = 0x00000063u, /* Peri 0, Address 0x42294000, size 0x00000004 */
    PROT_PERI0_MS4_MAIN             = 0x00000064u, /* Peri 0, Address 0x42294040, size 0x00000004 */
    PROT_PERI0_MS5_MAIN             = 0x00000065u, /* Peri 0, Address 0x42294050, size 0x00000004 */
    PROT_PERI0_MS6_MAIN             = 0x00000066u, /* Peri 0, Address 0x42294060, size 0x00000004 */
    PROT_PERI0_MS7_MAIN             = 0x00000067u, /* Peri 0, Address 0x42294070, size 0x00000004 */
    PROT_PERI0_MS8_MAIN             = 0x00000068u, /* Peri 0, Address 0x42294080, size 0x00000004 */
    PROT_PERI0_MS9_MAIN             = 0x00000069u, /* Peri 0, Address 0x42294090, size 0x00000004 */
    PROT_PERI0_MS10_MAIN            = 0x0000006Au, /* Peri 0, Address 0x422940a0, size 0x00000004 */
    PROT_PERI0_MS11_MAIN            = 0x0000006Bu, /* Peri 0, Address 0x422940b0, size 0x00000004 */
    PROT_PERI0_MS29_MAIN            = 0x0000006Cu, /* Peri 0, Address 0x422941d0, size 0x00000004 */
    PROT_PERI0_MS31_MAIN            = 0x0000006Du, /* Peri 0, Address 0x422941f0, size 0x00000004 */
    PROT_PERI0_MS_PC0_PRIV          = 0x0000006Eu, /* Peri 0, Address 0x42295000, size 0x00000004 */
    PROT_PERI0_MS_PC6_PRIV          = 0x0000006Fu, /* Peri 0, Address 0x42295060, size 0x00000004 */
    PROT_PERI0_MS_PC9_PRIV          = 0x00000070u, /* Peri 0, Address 0x42295090, size 0x00000004 */
    PROT_PERI0_MS_PC11_PRIV         = 0x00000071u, /* Peri 0, Address 0x422950b0, size 0x00000004 */
    PROT_PERI0_MS_PC31_PRIV         = 0x00000072u, /* Peri 0, Address 0x422951f0, size 0x00000004 */
    PROT_PERI0_MS_PC0_PRIV_MIR      = 0x00000073u, /* Peri 0, Address 0x42295004, size 0x00000004 */
    PROT_PERI0_MS_PC6_PRIV_MIR      = 0x00000074u, /* Peri 0, Address 0x42295064, size 0x00000004 */
    PROT_PERI0_MS_PC9_PRIV_MIR      = 0x00000075u, /* Peri 0, Address 0x42295094, size 0x00000004 */
    PROT_PERI0_MS_PC11_PRIV_MIR     = 0x00000076u, /* Peri 0, Address 0x422950b4, size 0x00000004 */
    PROT_PERI0_MS_PC31_PRIV_MIR     = 0x00000077u, /* Peri 0, Address 0x422951f4, size 0x00000004 */
    PROT_PERI0_MSC_ACG              = 0x00000078u, /* Peri 0, Address 0x42296000, size 0x00000040 */
    PROT_PERI0_CPUSS_SL_CTL_GROUP   = 0x00000079u, /* Peri 0, Address 0x42298000, size 0x00000008 */
    PROT_PERI0_IPC0_STRUCT0_IPC     = 0x0000007Au, /* Peri 0, Address 0x422a0000, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT1_IPC     = 0x0000007Bu, /* Peri 0, Address 0x422a0020, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT2_IPC     = 0x0000007Cu, /* Peri 0, Address 0x422a0040, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT3_IPC     = 0x0000007Du, /* Peri 0, Address 0x422a0060, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT4_IPC     = 0x0000007Eu, /* Peri 0, Address 0x422a0080, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT5_IPC     = 0x0000007Fu, /* Peri 0, Address 0x422a00a0, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT6_IPC     = 0x00000080u, /* Peri 0, Address 0x422a00c0, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT7_IPC     = 0x00000081u, /* Peri 0, Address 0x422a00e0, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT8_IPC     = 0x00000082u, /* Peri 0, Address 0x422a0100, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT9_IPC     = 0x00000083u, /* Peri 0, Address 0x422a0120, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT10_IPC    = 0x00000084u, /* Peri 0, Address 0x422a0140, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT11_IPC    = 0x00000085u, /* Peri 0, Address 0x422a0160, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT12_IPC    = 0x00000086u, /* Peri 0, Address 0x422a0180, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT13_IPC    = 0x00000087u, /* Peri 0, Address 0x422a01a0, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT14_IPC    = 0x00000088u, /* Peri 0, Address 0x422a01c0, size 0x00000020 */
    PROT_PERI0_IPC0_STRUCT15_IPC    = 0x00000089u, /* Peri 0, Address 0x422a01e0, size 0x00000020 */
    PROT_PERI0_IPC0_INTR_STRUCT0_INTR = 0x0000008Au, /* Peri 0, Address 0x422a1000, size 0x00000010 */
    PROT_PERI0_IPC0_INTR_STRUCT1_INTR = 0x0000008Bu, /* Peri 0, Address 0x422a1020, size 0x00000010 */
    PROT_PERI0_IPC0_INTR_STRUCT2_INTR = 0x0000008Cu, /* Peri 0, Address 0x422a1040, size 0x00000010 */
    PROT_PERI0_IPC0_INTR_STRUCT3_INTR = 0x0000008Du, /* Peri 0, Address 0x422a1060, size 0x00000010 */
    PROT_PERI0_IPC0_INTR_STRUCT4_INTR = 0x0000008Eu, /* Peri 0, Address 0x422a1080, size 0x00000010 */
    PROT_PERI0_IPC0_INTR_STRUCT5_INTR = 0x0000008Fu, /* Peri 0, Address 0x422a10a0, size 0x00000010 */
    PROT_PERI0_IPC0_INTR_STRUCT6_INTR = 0x00000090u, /* Peri 0, Address 0x422a10c0, size 0x00000010 */
    PROT_PERI0_IPC0_INTR_STRUCT7_INTR = 0x00000091u, /* Peri 0, Address 0x422a10e0, size 0x00000010 */
    PROT_PERI0_FAULT_STRUCT0_MAIN   = 0x00000092u, /* Peri 0, Address 0x422b0000, size 0x00000100 */
    PROT_PERI0_FAULT_STRUCT1_MAIN   = 0x00000093u, /* Peri 0, Address 0x422b0100, size 0x00000100 */
    PROT_PERI0_SRSS_GENERAL         = 0x00000094u, /* Peri 0, Address 0x42400000, size 0x00000400 */
    PROT_PERI0_SRSS_GENERAL2        = 0x00000095u, /* Peri 0, Address 0x42400400, size 0x00000080 */
    PROT_PERI0_SRSS_HIB_DATA        = 0x00000096u, /* Peri 0, Address 0x424008a0, size 0x00000010 */
    PROT_PERI0_SRSS_SECURE2         = 0x00000097u, /* Peri 0, Address 0x42400900, size 0x00000020 */
    PROT_PERI0_SRSS_MAIN            = 0x00000098u, /* Peri 0, Address 0x42401000, size 0x00001000 */
    PROT_PERI0_SRSS_SECURE          = 0x00000099u, /* Peri 0, Address 0x42402000, size 0x00002000 */
    PROT_PERI0_RAM_TRIM_SRSS_SRAM   = 0x0000009Au, /* Peri 0, Address 0x42404000, size 0x00000040 */
    PROT_PERI0_SRSS_WDT             = 0x0000009Bu, /* Peri 0, Address 0x4240c000, size 0x00000010 */
    PROT_PERI0_SRSS_MCWDTA          = 0x0000009Cu, /* Peri 0, Address 0x4240d000, size 0x00000080 */
    PROT_PERI0_PWRMODE_PWRMODE      = 0x0000009Du, /* Peri 0, Address 0x42410000, size 0x00008000 */
    PROT_PERI0_RTC_BACKUP           = 0x0000009Eu, /* Peri 0, Address 0x42420000, size 0x00000080 */
    PROT_PERI0_RTC_B_BREG0          = 0x0000009Fu, /* Peri 0, Address 0x42421000, size 0x00000010 */
    PROT_PERI0_RTC_B_BREG1          = 0x000000A0u, /* Peri 0, Address 0x42421010, size 0x00000010 */
    PROT_PERI0_RTC_B_BREG2          = 0x000000A1u, /* Peri 0, Address 0x42421020, size 0x00000020 */
    PROT_PERI0_DEBUG600_DEBUG600    = 0x000000A2u, /* Peri 0, Address 0x42430000, size 0x00000004 */
    PROT_PERI0_M0SECCPUSS_STATUS_MAIN = 0x000000A3u, /* Peri 0, Address 0x42430100, size 0x00000004 */
    PROT_PERI0_M0SECCPUSS_STATUS_PC1 = 0x000000A4u, /* Peri 0, Address 0x42430180, size 0x00000008 */
    PROT_PERI0_CRYPTO_MAIN          = 0x000000A5u, /* Peri 0, Address 0x42440000, size 0x00000400 */
    PROT_PERI0_CRYPTO_CRYPTO        = 0x000000A6u, /* Peri 0, Address 0x42441000, size 0x00000800 */
    PROT_PERI0_CRYPTO_BOOT          = 0x000000A7u, /* Peri 0, Address 0x42442000, size 0x00000100 */
    PROT_PERI0_CRYPTO_KEY0          = 0x000000A8u, /* Peri 0, Address 0x42442100, size 0x00000004 */
    PROT_PERI0_CRYPTO_KEY1          = 0x000000A9u, /* Peri 0, Address 0x42442120, size 0x00000004 */
    PROT_PERI0_CRYPTO_BUF           = 0x000000AAu, /* Peri 0, Address 0x42448000, size 0x00001000 */
    PROT_PERI0_HSIOM_PRT0_PRT       = 0x000000ABu, /* Peri 0, Address 0x42800000, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT1_PRT       = 0x000000ACu, /* Peri 0, Address 0x42800010, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT2_PRT       = 0x000000ADu, /* Peri 0, Address 0x42800020, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT3_PRT       = 0x000000AEu, /* Peri 0, Address 0x42800030, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT4_PRT       = 0x000000AFu, /* Peri 0, Address 0x42800040, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT5_PRT       = 0x000000B0u, /* Peri 0, Address 0x42800050, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT6_PRT       = 0x000000B1u, /* Peri 0, Address 0x42800060, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT7_PRT       = 0x000000B2u, /* Peri 0, Address 0x42800070, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT8_PRT       = 0x000000B3u, /* Peri 0, Address 0x42800080, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT9_PRT       = 0x000000B4u, /* Peri 0, Address 0x42800090, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT10_PRT      = 0x000000B5u, /* Peri 0, Address 0x428000a0, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT11_PRT      = 0x000000B6u, /* Peri 0, Address 0x428000b0, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT12_PRT      = 0x000000B7u, /* Peri 0, Address 0x428000c0, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT13_PRT      = 0x000000B8u, /* Peri 0, Address 0x428000d0, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT14_PRT      = 0x000000B9u, /* Peri 0, Address 0x428000e0, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT15_PRT      = 0x000000BAu, /* Peri 0, Address 0x428000f0, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT16_PRT      = 0x000000BBu, /* Peri 0, Address 0x42800100, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT17_PRT      = 0x000000BCu, /* Peri 0, Address 0x42800110, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT18_PRT      = 0x000000BDu, /* Peri 0, Address 0x42800120, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT19_PRT      = 0x000000BEu, /* Peri 0, Address 0x42800130, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT20_PRT      = 0x000000BFu, /* Peri 0, Address 0x42800140, size 0x00000008 */
    PROT_PERI0_HSIOM_PRT21_PRT      = 0x000000C0u, /* Peri 0, Address 0x42800150, size 0x00000008 */
    PROT_PERI0_HSIOM_SECURE_PRT0_SECURE_PRT = 0x000000C1u, /* Peri 0, Address 0x42801000, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT1_SECURE_PRT = 0x000000C2u, /* Peri 0, Address 0x42801010, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT2_SECURE_PRT = 0x000000C3u, /* Peri 0, Address 0x42801020, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT3_SECURE_PRT = 0x000000C4u, /* Peri 0, Address 0x42801030, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT4_SECURE_PRT = 0x000000C5u, /* Peri 0, Address 0x42801040, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT5_SECURE_PRT = 0x000000C6u, /* Peri 0, Address 0x42801050, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT6_SECURE_PRT = 0x000000C7u, /* Peri 0, Address 0x42801060, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT7_SECURE_PRT = 0x000000C8u, /* Peri 0, Address 0x42801070, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT8_SECURE_PRT = 0x000000C9u, /* Peri 0, Address 0x42801080, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT9_SECURE_PRT = 0x000000CAu, /* Peri 0, Address 0x42801090, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT10_SECURE_PRT = 0x000000CBu, /* Peri 0, Address 0x428010a0, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT11_SECURE_PRT = 0x000000CCu, /* Peri 0, Address 0x428010b0, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT12_SECURE_PRT = 0x000000CDu, /* Peri 0, Address 0x428010c0, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT13_SECURE_PRT = 0x000000CEu, /* Peri 0, Address 0x428010d0, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT14_SECURE_PRT = 0x000000CFu, /* Peri 0, Address 0x428010e0, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT15_SECURE_PRT = 0x000000D0u, /* Peri 0, Address 0x428010f0, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT16_SECURE_PRT = 0x000000D1u, /* Peri 0, Address 0x42801100, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT17_SECURE_PRT = 0x000000D2u, /* Peri 0, Address 0x42801110, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT18_SECURE_PRT = 0x000000D3u, /* Peri 0, Address 0x42801120, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT19_SECURE_PRT = 0x000000D4u, /* Peri 0, Address 0x42801130, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT20_SECURE_PRT = 0x000000D5u, /* Peri 0, Address 0x42801140, size 0x00000004 */
    PROT_PERI0_HSIOM_SECURE_PRT21_SECURE_PRT = 0x000000D6u, /* Peri 0, Address 0x42801150, size 0x00000004 */
    PROT_PERI0_HSIOM_AMUX           = 0x000000D7u, /* Peri 0, Address 0x42802000, size 0x00000020 */
    PROT_PERI0_HSIOM_MON            = 0x000000D8u, /* Peri 0, Address 0x42802200, size 0x00000010 */
    PROT_PERI0_GPIO_PRT0_PRT        = 0x000000D9u, /* Peri 0, Address 0x42810000, size 0x00000040 */
    PROT_PERI0_GPIO_PRT1_PRT        = 0x000000DAu, /* Peri 0, Address 0x42810080, size 0x00000040 */
    PROT_PERI0_GPIO_PRT2_PRT        = 0x000000DBu, /* Peri 0, Address 0x42810100, size 0x00000040 */
    PROT_PERI0_GPIO_PRT3_PRT        = 0x000000DCu, /* Peri 0, Address 0x42810180, size 0x00000040 */
    PROT_PERI0_GPIO_PRT4_PRT        = 0x000000DDu, /* Peri 0, Address 0x42810200, size 0x00000040 */
    PROT_PERI0_GPIO_PRT5_PRT        = 0x000000DEu, /* Peri 0, Address 0x42810280, size 0x00000040 */
    PROT_PERI0_GPIO_PRT6_PRT        = 0x000000DFu, /* Peri 0, Address 0x42810300, size 0x00000040 */
    PROT_PERI0_GPIO_PRT7_PRT        = 0x000000E0u, /* Peri 0, Address 0x42810380, size 0x00000040 */
    PROT_PERI0_GPIO_PRT8_PRT        = 0x000000E1u, /* Peri 0, Address 0x42810400, size 0x00000040 */
    PROT_PERI0_GPIO_PRT9_PRT        = 0x000000E2u, /* Peri 0, Address 0x42810480, size 0x00000040 */
    PROT_PERI0_GPIO_PRT10_PRT       = 0x000000E3u, /* Peri 0, Address 0x42810500, size 0x00000040 */
    PROT_PERI0_GPIO_PRT11_PRT       = 0x000000E4u, /* Peri 0, Address 0x42810580, size 0x00000040 */
    PROT_PERI0_GPIO_PRT12_PRT       = 0x000000E5u, /* Peri 0, Address 0x42810600, size 0x00000040 */
    PROT_PERI0_GPIO_PRT13_PRT       = 0x000000E6u, /* Peri 0, Address 0x42810680, size 0x00000040 */
    PROT_PERI0_GPIO_PRT14_PRT       = 0x000000E7u, /* Peri 0, Address 0x42810700, size 0x00000040 */
    PROT_PERI0_GPIO_PRT15_PRT       = 0x000000E8u, /* Peri 0, Address 0x42810780, size 0x00000040 */
    PROT_PERI0_GPIO_PRT16_PRT       = 0x000000E9u, /* Peri 0, Address 0x42810800, size 0x00000040 */
    PROT_PERI0_GPIO_PRT17_PRT       = 0x000000EAu, /* Peri 0, Address 0x42810880, size 0x00000040 */
    PROT_PERI0_GPIO_PRT18_PRT       = 0x000000EBu, /* Peri 0, Address 0x42810900, size 0x00000040 */
    PROT_PERI0_GPIO_PRT19_PRT       = 0x000000ECu, /* Peri 0, Address 0x42810980, size 0x00000040 */
    PROT_PERI0_GPIO_PRT20_PRT       = 0x000000EDu, /* Peri 0, Address 0x42810a00, size 0x00000040 */
    PROT_PERI0_GPIO_PRT21_PRT       = 0x000000EEu, /* Peri 0, Address 0x42810a80, size 0x00000040 */
    PROT_PERI0_GPIO_PRT0_CFG        = 0x000000EFu, /* Peri 0, Address 0x42810040, size 0x00000040 */
    PROT_PERI0_GPIO_PRT1_CFG        = 0x000000F0u, /* Peri 0, Address 0x428100c0, size 0x00000008 */
    PROT_PERI0_GPIO_PRT2_CFG        = 0x000000F1u, /* Peri 0, Address 0x42810140, size 0x00000040 */
    PROT_PERI0_GPIO_PRT3_CFG        = 0x000000F2u, /* Peri 0, Address 0x428101c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT4_CFG        = 0x000000F3u, /* Peri 0, Address 0x42810240, size 0x00000008 */
    PROT_PERI0_GPIO_PRT5_CFG        = 0x000000F4u, /* Peri 0, Address 0x428102c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT6_CFG        = 0x000000F5u, /* Peri 0, Address 0x42810340, size 0x00000040 */
    PROT_PERI0_GPIO_PRT7_CFG        = 0x000000F6u, /* Peri 0, Address 0x428103c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT8_CFG        = 0x000000F7u, /* Peri 0, Address 0x42810440, size 0x00000040 */
    PROT_PERI0_GPIO_PRT9_CFG        = 0x000000F8u, /* Peri 0, Address 0x428104c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT10_CFG       = 0x000000F9u, /* Peri 0, Address 0x42810540, size 0x00000040 */
    PROT_PERI0_GPIO_PRT11_CFG       = 0x000000FAu, /* Peri 0, Address 0x428105c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT12_CFG       = 0x000000FBu, /* Peri 0, Address 0x42810640, size 0x00000040 */
    PROT_PERI0_GPIO_PRT13_CFG       = 0x000000FCu, /* Peri 0, Address 0x428106c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT14_CFG       = 0x000000FDu, /* Peri 0, Address 0x42810740, size 0x00000040 */
    PROT_PERI0_GPIO_PRT15_CFG       = 0x000000FEu, /* Peri 0, Address 0x428107c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT16_CFG       = 0x000000FFu, /* Peri 0, Address 0x42810840, size 0x00000040 */
    PROT_PERI0_GPIO_PRT17_CFG       = 0x00000100u, /* Peri 0, Address 0x428108c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT18_CFG       = 0x00000101u, /* Peri 0, Address 0x42810940, size 0x00000040 */
    PROT_PERI0_GPIO_PRT19_CFG       = 0x00000102u, /* Peri 0, Address 0x428109c0, size 0x00000040 */
    PROT_PERI0_GPIO_PRT20_CFG       = 0x00000103u, /* Peri 0, Address 0x42810a40, size 0x00000040 */
    PROT_PERI0_GPIO_PRT21_CFG       = 0x00000104u, /* Peri 0, Address 0x42810ac0, size 0x00000040 */
    PROT_PERI0_GPIO_SEC_GPIO        = 0x00000105u, /* Peri 0, Address 0x42817000, size 0x00000004 */
    PROT_PERI0_GPIO_GPIO            = 0x00000106u, /* Peri 0, Address 0x42818000, size 0x00000040 */
    PROT_PERI0_GPIO_TEST            = 0x00000107u, /* Peri 0, Address 0x42819000, size 0x00000008 */
    PROT_PERI0_SMARTIO_PRT11_PRT    = 0x00000108u, /* Peri 0, Address 0x42820b00, size 0x00000100 */
    PROT_PERI0_SMARTIO_PRT17_PRT    = 0x00000109u, /* Peri 0, Address 0x42821100, size 0x00000100 */
    PROT_PERI0_CANFD0_CH0_CH        = 0x0000010Au, /* Peri 0, Address 0x42840000, size 0x00000200 */
    PROT_PERI0_CANFD0_CH1_CH        = 0x0000010Bu, /* Peri 0, Address 0x42840200, size 0x00000200 */
    PROT_PERI0_CANFD0_MAIN          = 0x0000010Cu, /* Peri 0, Address 0x42841000, size 0x00000040 */
    PROT_PERI0_CANFD0_BUF           = 0x0000010Du, /* Peri 0, Address 0x42850000, size 0x00010000 */
    PROT_PERI0_TCPWM0_GRP0_CNT0_CNT = 0x0000010Eu, /* Peri 0, Address 0x42860000, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP0_CNT1_CNT = 0x0000010Fu, /* Peri 0, Address 0x42860080, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP0_CNT2_CNT = 0x00000110u, /* Peri 0, Address 0x42860100, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP0_CNT3_CNT = 0x00000111u, /* Peri 0, Address 0x42860180, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP0_CNT4_CNT = 0x00000112u, /* Peri 0, Address 0x42860200, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP0_CNT5_CNT = 0x00000113u, /* Peri 0, Address 0x42860280, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP0_CNT6_CNT = 0x00000114u, /* Peri 0, Address 0x42860300, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP0_CNT7_CNT = 0x00000115u, /* Peri 0, Address 0x42860380, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT0_CNT = 0x00000116u, /* Peri 0, Address 0x42868000, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT1_CNT = 0x00000117u, /* Peri 0, Address 0x42868080, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT2_CNT = 0x00000118u, /* Peri 0, Address 0x42868100, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT3_CNT = 0x00000119u, /* Peri 0, Address 0x42868180, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT4_CNT = 0x0000011Au, /* Peri 0, Address 0x42868200, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT5_CNT = 0x0000011Bu, /* Peri 0, Address 0x42868280, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT6_CNT = 0x0000011Cu, /* Peri 0, Address 0x42868300, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT7_CNT = 0x0000011Du, /* Peri 0, Address 0x42868380, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT8_CNT = 0x0000011Eu, /* Peri 0, Address 0x42868400, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT9_CNT = 0x0000011Fu, /* Peri 0, Address 0x42868480, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT10_CNT = 0x00000120u, /* Peri 0, Address 0x42868500, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT11_CNT = 0x00000121u, /* Peri 0, Address 0x42868580, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT12_CNT = 0x00000122u, /* Peri 0, Address 0x42868600, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT13_CNT = 0x00000123u, /* Peri 0, Address 0x42868680, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT14_CNT = 0x00000124u, /* Peri 0, Address 0x42868700, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT15_CNT = 0x00000125u, /* Peri 0, Address 0x42868780, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT16_CNT = 0x00000126u, /* Peri 0, Address 0x42868800, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT17_CNT = 0x00000127u, /* Peri 0, Address 0x42868880, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT18_CNT = 0x00000128u, /* Peri 0, Address 0x42868900, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT19_CNT = 0x00000129u, /* Peri 0, Address 0x42868980, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT20_CNT = 0x0000012Au, /* Peri 0, Address 0x42868a00, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT21_CNT = 0x0000012Bu, /* Peri 0, Address 0x42868a80, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT22_CNT = 0x0000012Cu, /* Peri 0, Address 0x42868b00, size 0x00000080 */
    PROT_PERI0_TCPWM0_GRP1_CNT23_CNT = 0x0000012Du, /* Peri 0, Address 0x42868b80, size 0x00000080 */
    PROT_PERI0_LPCOMP               = 0x0000012Eu, /* Peri 0, Address 0x42880000, size 0x00010000 */
    PROT_PERI0_SCB0                 = 0x0000012Fu, /* Peri 0, Address 0x42990000, size 0x00010000 */
    PROT_PERI0_SCB2                 = 0x00000130u, /* Peri 0, Address 0x429a0000, size 0x00010000 */
    PROT_PERI0_SCB3                 = 0x00000131u, /* Peri 0, Address 0x429b0000, size 0x00010000 */
    PROT_PERI0_SCB4                 = 0x00000132u, /* Peri 0, Address 0x429c0000, size 0x00010000 */
    PROT_PERI0_SCB5                 = 0x00000133u, /* Peri 0, Address 0x429d0000, size 0x00010000 */
    PROT_PERI0_SCB6                 = 0x00000134u, /* Peri 0, Address 0x429e0000, size 0x00010000 */
    PROT_PERI0_SCB7                 = 0x00000135u, /* Peri 0, Address 0x429f0000, size 0x00010000 */
    PROT_PERI0_SCB8                 = 0x00000136u, /* Peri 0, Address 0x42a00000, size 0x00010000 */
    PROT_PERI0_SCB9                 = 0x00000137u, /* Peri 0, Address 0x42a10000, size 0x00010000 */
    PROT_PERI0_SCB10                = 0x00000138u, /* Peri 0, Address 0x42a20000, size 0x00010000 */
    PROT_PERI0_SCB11                = 0x00000139u, /* Peri 0, Address 0x42a30000, size 0x00010000 */
    PROT_PERI0_SCB1                 = 0x0000013Au, /* Peri 0, Address 0x42d00000, size 0x00010000 */
    PROT_PERI0_I3C                  = 0x0000013Bu, /* Peri 0, Address 0x42a50000, size 0x00010000 */
    PROT_PERI0_DFT                  = 0x0000013Cu, /* Peri 0, Address 0x42c00000, size 0x00001000 */
    PROT_PERI0_ETH0                 = 0x0000013Du, /* Peri 0, Address 0x42c10000, size 0x00010000 */
    PROT_PERI0_MXNNLITE_2_0         = 0x0000013Eu, /* Peri 0, Address 0x42d80000, size 0x00001000 */
    PROT_PERI0_END                  = 0x0000013Eu,
    PROT_PERI1_START                = 0x10000000u,
    PROT_PERI1_MAIN                 = 0x10000000u, /* Peri 1, Address 0x44000000, size 0x00004000 */
    PROT_PERI1_GR0_GROUP            = 0x10000001u, /* Peri 1, Address 0x44004010, size 0x00000008 */
    PROT_PERI1_GR1_GROUP            = 0x10000002u, /* Peri 1, Address 0x44004040, size 0x00000020 */
    PROT_PERI1_GR2_GROUP            = 0x10000003u, /* Peri 1, Address 0x44004090, size 0x00000008 */
    PROT_PERI1_GR3_GROUP            = 0x10000004u, /* Peri 1, Address 0x440040c0, size 0x00000020 */
    PROT_PERI1_GR4_GROUP            = 0x10000005u, /* Peri 1, Address 0x44004110, size 0x00000008 */
    PROT_PERI1_GR0_BOOT             = 0x10000006u, /* Peri 1, Address 0x44004020, size 0x00000004 */
    PROT_PERI1_GR1_BOOT             = 0x10000007u, /* Peri 1, Address 0x44004060, size 0x00000004 */
    PROT_PERI1_GR2_BOOT             = 0x10000008u, /* Peri 1, Address 0x440040a0, size 0x00000004 */
    PROT_PERI1_GR3_BOOT             = 0x10000009u, /* Peri 1, Address 0x440040e0, size 0x00000004 */
    PROT_PERI1_GR4_BOOT             = 0x1000000Au, /* Peri 1, Address 0x44004120, size 0x00000004 */
    PROT_PERI1_TR                   = 0x1000000Bu, /* Peri 1, Address 0x44008000, size 0x00001000 */
    PROT_PERI1_PPC1_PPC_PPC_SECURE  = 0x1000000Cu, /* Peri 1, Address 0x44020000, size 0x00004000 */
    PROT_PERI1_PPC1_PPC_PPC_NONSECURE = 0x1000000Du, /* Peri 1, Address 0x44024000, size 0x00004000 */
    PROT_PERI1_PERI_PCLK1_MAIN      = 0x1000000Eu, /* Peri 1, Address 0x44040000, size 0x00020000 */
    PROT_PERI1_M55APPCPUSS          = 0x1000000Fu, /* Peri 1, Address 0x44100000, size 0x00010000 */
    PROT_PERI1_MXCM55_CM55          = 0x10000010u, /* Peri 1, Address 0x44160000, size 0x00000100 */
    PROT_PERI1_MXCM55_CM55_S        = 0x10000011u, /* Peri 1, Address 0x44161000, size 0x00000004 */
    PROT_PERI1_MXCM55_CM55_NS       = 0x10000012u, /* Peri 1, Address 0x44161004, size 0x00000004 */
    PROT_PERI1_MXCM55_BOOT          = 0x10000013u, /* Peri 1, Address 0x441620c0, size 0x00000004 */
    PROT_PERI1_MXCM55_CM55_INT      = 0x10000014u, /* Peri 1, Address 0x44168000, size 0x00000400 */
    PROT_PERI1_SAXI_DMAC_TOP        = 0x10000015u, /* Peri 1, Address 0x441a0000, size 0x00000010 */
    PROT_PERI1_SAXI_DMAC_CH0_CH     = 0x10000016u, /* Peri 1, Address 0x441a1000, size 0x00000100 */
    PROT_PERI1_SAXI_DMAC_CH1_CH     = 0x10000017u, /* Peri 1, Address 0x441a1100, size 0x00000100 */
    PROT_PERI1_SAXI_DMAC_CH2_CH     = 0x10000018u, /* Peri 1, Address 0x441a1200, size 0x00000100 */
    PROT_PERI1_SAXI_DMAC_CH3_CH     = 0x10000019u, /* Peri 1, Address 0x441a1300, size 0x00000100 */
    PROT_PERI1_APPCPUSS_ALL_PC      = 0x1000001Au, /* Peri 1, Address 0x441c0000, size 0x00000080 */
    PROT_PERI1_APPCPUSS_CM33_NS     = 0x1000001Bu, /* Peri 1, Address 0x441c0120, size 0x00000004 */
    PROT_PERI1_APPCPUSS_MSC_INT     = 0x1000001Cu, /* Peri 1, Address 0x441c0200, size 0x00000010 */
    PROT_PERI1_APPCPUSS_AHB2AXI_INT = 0x1000001Du, /* Peri 1, Address 0x441c0300, size 0x00000010 */
    PROT_PERI1_APPCPUSS_AP          = 0x1000001Eu, /* Peri 1, Address 0x441c1000, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS13_MAIN     = 0x1000001Fu, /* Peri 1, Address 0x441c40d0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS14_MAIN     = 0x10000020u, /* Peri 1, Address 0x441c40e0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS15_MAIN     = 0x10000021u, /* Peri 1, Address 0x441c40f0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS19_MAIN     = 0x10000022u, /* Peri 1, Address 0x441c4130, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS23_MAIN     = 0x10000023u, /* Peri 1, Address 0x441c4170, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS25_MAIN     = 0x10000024u, /* Peri 1, Address 0x441c4190, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS26_MAIN     = 0x10000025u, /* Peri 1, Address 0x441c41a0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS27_MAIN     = 0x10000026u, /* Peri 1, Address 0x441c41b0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS28_MAIN     = 0x10000027u, /* Peri 1, Address 0x441c41c0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC13_PRIV  = 0x10000028u, /* Peri 1, Address 0x441c50d0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC14_PRIV  = 0x10000029u, /* Peri 1, Address 0x441c50e0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC15_PRIV  = 0x1000002Au, /* Peri 1, Address 0x441c50f0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC19_PRIV  = 0x1000002Bu, /* Peri 1, Address 0x441c5130, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC25_PRIV  = 0x1000002Cu, /* Peri 1, Address 0x441c5190, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC26_PRIV  = 0x1000002Du, /* Peri 1, Address 0x441c51a0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC27_PRIV  = 0x1000002Eu, /* Peri 1, Address 0x441c51b0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC28_PRIV  = 0x1000002Fu, /* Peri 1, Address 0x441c51c0, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC13_PRIV_MIR = 0x10000030u, /* Peri 1, Address 0x441c50d4, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC14_PRIV_MIR = 0x10000031u, /* Peri 1, Address 0x441c50e4, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC15_PRIV_MIR = 0x10000032u, /* Peri 1, Address 0x441c50f4, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC19_PRIV_MIR = 0x10000033u, /* Peri 1, Address 0x441c5134, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC25_PRIV_MIR = 0x10000034u, /* Peri 1, Address 0x441c5194, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC26_PRIV_MIR = 0x10000035u, /* Peri 1, Address 0x441c51a4, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC27_PRIV_MIR = 0x10000036u, /* Peri 1, Address 0x441c51b4, size 0x00000004 */
    PROT_PERI1_MS_CTL_MS_PC28_PRIV_MIR = 0x10000037u, /* Peri 1, Address 0x441c51c4, size 0x00000004 */
    PROT_PERI1_MS_CTL_MSC_ACG       = 0x10000038u, /* Peri 1, Address 0x441c6000, size 0x00000080 */
    PROT_PERI1_APPCPUSS_SL_CTL_GROUP = 0x10000039u, /* Peri 1, Address 0x441c8000, size 0x00000008 */
    PROT_PERI1_IPC1_STRUCT0_IPC     = 0x1000003Au, /* Peri 1, Address 0x441d0000, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT1_IPC     = 0x1000003Bu, /* Peri 1, Address 0x441d0020, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT2_IPC     = 0x1000003Cu, /* Peri 1, Address 0x441d0040, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT3_IPC     = 0x1000003Du, /* Peri 1, Address 0x441d0060, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT4_IPC     = 0x1000003Eu, /* Peri 1, Address 0x441d0080, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT5_IPC     = 0x1000003Fu, /* Peri 1, Address 0x441d00a0, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT6_IPC     = 0x10000040u, /* Peri 1, Address 0x441d00c0, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT7_IPC     = 0x10000041u, /* Peri 1, Address 0x441d00e0, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT8_IPC     = 0x10000042u, /* Peri 1, Address 0x441d0100, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT9_IPC     = 0x10000043u, /* Peri 1, Address 0x441d0120, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT10_IPC    = 0x10000044u, /* Peri 1, Address 0x441d0140, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT11_IPC    = 0x10000045u, /* Peri 1, Address 0x441d0160, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT12_IPC    = 0x10000046u, /* Peri 1, Address 0x441d0180, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT13_IPC    = 0x10000047u, /* Peri 1, Address 0x441d01a0, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT14_IPC    = 0x10000048u, /* Peri 1, Address 0x441d01c0, size 0x00000020 */
    PROT_PERI1_IPC1_STRUCT15_IPC    = 0x10000049u, /* Peri 1, Address 0x441d01e0, size 0x00000020 */
    PROT_PERI1_IPC1_INTR_STRUCT0_INTR = 0x1000004Au, /* Peri 1, Address 0x441d1000, size 0x00000010 */
    PROT_PERI1_IPC1_INTR_STRUCT1_INTR = 0x1000004Bu, /* Peri 1, Address 0x441d1020, size 0x00000010 */
    PROT_PERI1_IPC1_INTR_STRUCT2_INTR = 0x1000004Cu, /* Peri 1, Address 0x441d1040, size 0x00000010 */
    PROT_PERI1_IPC1_INTR_STRUCT3_INTR = 0x1000004Du, /* Peri 1, Address 0x441d1060, size 0x00000010 */
    PROT_PERI1_IPC1_INTR_STRUCT4_INTR = 0x1000004Eu, /* Peri 1, Address 0x441d1080, size 0x00000010 */
    PROT_PERI1_IPC1_INTR_STRUCT5_INTR = 0x1000004Fu, /* Peri 1, Address 0x441d10a0, size 0x00000010 */
    PROT_PERI1_IPC1_INTR_STRUCT6_INTR = 0x10000050u, /* Peri 1, Address 0x441d10c0, size 0x00000010 */
    PROT_PERI1_IPC1_INTR_STRUCT7_INTR = 0x10000051u, /* Peri 1, Address 0x441d10e0, size 0x00000010 */
    PROT_PERI1_PDM0_MAIN            = 0x10000052u, /* Peri 1, Address 0x44400000, size 0x00000200 */
    PROT_PERI1_PDM0_CH0_RX          = 0x10000053u, /* Peri 1, Address 0x44408000, size 0x00000100 */
    PROT_PERI1_PDM0_CH1_RX          = 0x10000054u, /* Peri 1, Address 0x44408100, size 0x00000100 */
    PROT_PERI1_PDM0_CH2_RX          = 0x10000055u, /* Peri 1, Address 0x44408200, size 0x00000100 */
    PROT_PERI1_PDM0_CH3_RX          = 0x10000056u, /* Peri 1, Address 0x44408300, size 0x00000100 */
    PROT_PERI1_PDM0_CH4_RX          = 0x10000057u, /* Peri 1, Address 0x44408400, size 0x00000100 */
    PROT_PERI1_PDM0_CH5_RX          = 0x10000058u, /* Peri 1, Address 0x44408500, size 0x00000100 */
    PROT_PERI1_TDM0_TDM_STRUCT0_TDM_TX_STRUCT_TX = 0x10000059u, /* Peri 1, Address 0x44418000, size 0x00000100 */
    PROT_PERI1_TDM0_TDM_STRUCT1_TDM_TX_STRUCT_TX = 0x1000005Au, /* Peri 1, Address 0x44418200, size 0x00000100 */
    PROT_PERI1_TDM0_TDM_STRUCT0_TDM_RX_STRUCT_RX = 0x1000005Bu, /* Peri 1, Address 0x44418100, size 0x00000100 */
    PROT_PERI1_TDM0_TDM_STRUCT1_TDM_RX_STRUCT_RX = 0x1000005Cu, /* Peri 1, Address 0x44418300, size 0x00000100 */
    PROT_PERI1_SMIF0_CACHE_BLOCK_MAIN = 0x1000005Du, /* Peri 1, Address 0x44450000, size 0x00001000 */
    PROT_PERI1_SMIF1_CACHE_BLOCK_MAIN = 0x1000005Eu, /* Peri 1, Address 0x44490000, size 0x00001000 */
    PROT_PERI1_SMIF0_CACHE_BLOCK_MMIO_MAIN = 0x1000005Fu, /* Peri 1, Address 0x44452000, size 0x00000080 */
    PROT_PERI1_SMIF1_CACHE_BLOCK_MMIO_MAIN = 0x10000060u, /* Peri 1, Address 0x44492000, size 0x00000080 */
    PROT_PERI1_SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0_PPC_MPC_MAIN = 0x10000061u, /* Peri 1, Address 0x44454000, size 0x00000004 */
    PROT_PERI1_SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0_PPC_MPC_MAIN = 0x10000062u, /* Peri 1, Address 0x44494000, size 0x00000004 */
    PROT_PERI1_SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0_PPC_MPC_PC = 0x10000063u, /* Peri 1, Address 0x44454100, size 0x00000020 */
    PROT_PERI1_SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0_PPC_MPC_PC = 0x10000064u, /* Peri 1, Address 0x44494100, size 0x00000020 */
    PROT_PERI1_SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0_PPC_MPC_ROT = 0x10000065u, /* Peri 1, Address 0x44454200, size 0x00000020 */
    PROT_PERI1_SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0_PPC_MPC_ROT = 0x10000066u, /* Peri 1, Address 0x44494200, size 0x00000020 */
    PROT_PERI1_SMIF0_CORE_MAIN      = 0x10000067u, /* Peri 1, Address 0x44460000, size 0x00000100 */
    PROT_PERI1_SMIF1_CORE_MAIN      = 0x10000068u, /* Peri 1, Address 0x444a0000, size 0x00000100 */
    PROT_PERI1_SMIF0_CORE_CRYPTO    = 0x10000069u, /* Peri 1, Address 0x44460200, size 0x00000200 */
    PROT_PERI1_SMIF1_CORE_CRYPTO    = 0x1000006Au, /* Peri 1, Address 0x444a0200, size 0x00000200 */
    PROT_PERI1_SMIF0_CORE_MAIN2     = 0x1000006Bu, /* Peri 1, Address 0x444607c0, size 0x00000040 */
    PROT_PERI1_SMIF1_CORE_MAIN2     = 0x1000006Cu, /* Peri 1, Address 0x444a07c0, size 0x00000040 */
    PROT_PERI1_SMIF0_CORE_DEVICE    = 0x1000006Du, /* Peri 1, Address 0x44460800, size 0x00000200 */
    PROT_PERI1_SMIF1_CORE_DEVICE    = 0x1000006Eu, /* Peri 1, Address 0x444a0800, size 0x00000200 */
    PROT_PERI1_SMIF0_CORE_AXI_MPC0_PPC_MPC_MAIN = 0x1000006Fu, /* Peri 1, Address 0x44463000, size 0x00000004 */
    PROT_PERI1_SMIF1_CORE_AXI_MPC0_PPC_MPC_MAIN = 0x10000070u, /* Peri 1, Address 0x444a3000, size 0x00000004 */
    PROT_PERI1_SMIF0_CORE_AXI_MPC0_PPC_MPC_PC = 0x10000071u, /* Peri 1, Address 0x44463100, size 0x00000020 */
    PROT_PERI1_SMIF1_CORE_AXI_MPC0_PPC_MPC_PC = 0x10000072u, /* Peri 1, Address 0x444a3100, size 0x00000020 */
    PROT_PERI1_SMIF0_CORE_AXI_MPC0_PPC_MPC_ROT = 0x10000073u, /* Peri 1, Address 0x44463200, size 0x00000020 */
    PROT_PERI1_SMIF1_CORE_AXI_MPC0_PPC_MPC_ROT = 0x10000074u, /* Peri 1, Address 0x444a3200, size 0x00000020 */
    PROT_PERI1_SMIF0_CORE_SMIF_HSIOM_SMIF_PRT0_PRT = 0x10000075u, /* Peri 1, Address 0x44464000, size 0x00000008 */
    PROT_PERI1_SMIF0_CORE_SMIF_HSIOM_SMIF_PRT1_PRT = 0x10000076u, /* Peri 1, Address 0x44464010, size 0x00000008 */
    PROT_PERI1_SMIF0_CORE_SMIF_HSIOM_SMIF_PRT2_PRT = 0x10000077u, /* Peri 1, Address 0x44464020, size 0x00000008 */
    PROT_PERI1_SMIF1_CORE_SMIF_HSIOM_SMIF_PRT0_PRT = 0x10000078u, /* Peri 1, Address 0x444a4000, size 0x00000008 */
    PROT_PERI1_SMIF1_CORE_SMIF_HSIOM_SMIF_PRT1_PRT = 0x10000079u, /* Peri 1, Address 0x444a4010, size 0x00000008 */
    PROT_PERI1_SMIF1_CORE_SMIF_HSIOM_SMIF_PRT2_PRT = 0x1000007Au, /* Peri 1, Address 0x444a4020, size 0x00000008 */
    PROT_PERI1_SMIF0_CORE_SMIF_HSIOM_MON = 0x1000007Bu, /* Peri 1, Address 0x44466200, size 0x00000010 */
    PROT_PERI1_SMIF1_CORE_SMIF_HSIOM_MON = 0x1000007Cu, /* Peri 1, Address 0x444a6200, size 0x00000010 */
    PROT_PERI1_SMIF0_CORE_SMIF_GPIO_SMIF_PRT0_PRT = 0x1000007Du, /* Peri 1, Address 0x44470000, size 0x00000040 */
    PROT_PERI1_SMIF0_CORE_SMIF_GPIO_SMIF_PRT1_PRT = 0x1000007Eu, /* Peri 1, Address 0x44470080, size 0x00000040 */
    PROT_PERI1_SMIF0_CORE_SMIF_GPIO_SMIF_PRT2_PRT = 0x1000007Fu, /* Peri 1, Address 0x44470100, size 0x00000040 */
    PROT_PERI1_SMIF1_CORE_SMIF_GPIO_SMIF_PRT0_PRT = 0x10000080u, /* Peri 1, Address 0x444b0000, size 0x00000040 */
    PROT_PERI1_SMIF1_CORE_SMIF_GPIO_SMIF_PRT1_PRT = 0x10000081u, /* Peri 1, Address 0x444b0080, size 0x00000040 */
    PROT_PERI1_SMIF1_CORE_SMIF_GPIO_SMIF_PRT2_PRT = 0x10000082u, /* Peri 1, Address 0x444b0100, size 0x00000040 */
    PROT_PERI1_SMIF0_CORE_SMIF_GPIO_SMIF_PRT0_CFG = 0x10000083u, /* Peri 1, Address 0x44470040, size 0x00000040 */
    PROT_PERI1_SMIF0_CORE_SMIF_GPIO_SMIF_PRT1_CFG = 0x10000084u, /* Peri 1, Address 0x444700c0, size 0x00000040 */
    PROT_PERI1_SMIF0_CORE_SMIF_GPIO_SMIF_PRT2_CFG = 0x10000085u, /* Peri 1, Address 0x44470140, size 0x00000040 */
    PROT_PERI1_SMIF1_CORE_SMIF_GPIO_SMIF_PRT0_CFG = 0x10000086u, /* Peri 1, Address 0x444b0040, size 0x00000040 */
    PROT_PERI1_SMIF1_CORE_SMIF_GPIO_SMIF_PRT1_CFG = 0x10000087u, /* Peri 1, Address 0x444b00c0, size 0x00000040 */
    PROT_PERI1_SMIF1_CORE_SMIF_GPIO_SMIF_PRT2_CFG = 0x10000088u, /* Peri 1, Address 0x444b0140, size 0x00000040 */
    PROT_PERI1_SMIF0_CORE_SMIF_GPIO_GPIO = 0x10000089u, /* Peri 1, Address 0x44478000, size 0x00000040 */
    PROT_PERI1_SMIF1_CORE_SMIF_GPIO_GPIO = 0x1000008Au, /* Peri 1, Address 0x444b8000, size 0x00000040 */
    PROT_PERI1_SMIF0_CORE_SMIF_GPIO_TEST = 0x1000008Bu, /* Peri 1, Address 0x44479000, size 0x00000008 */
    PROT_PERI1_SMIF1_CORE_SMIF_GPIO_TEST = 0x1000008Cu, /* Peri 1, Address 0x444b9000, size 0x00000008 */
    PROT_PERI1_U550_U55             = 0x1000008Du, /* Peri 1, Address 0x44600000, size 0x00001000 */
    PROT_PERI1_U550_ROT             = 0x1000008Eu, /* Peri 1, Address 0x44601000, size 0x00000004 */
    PROT_PERI1_U550_ACG             = 0x1000008Fu, /* Peri 1, Address 0x44601004, size 0x00000004 */
    PROT_PERI1_U550_MXU55_PPU_PPU   = 0x10000090u, /* Peri 1, Address 0x44602000, size 0x00001000 */
    PROT_PERI1_U550_PD_PD           = 0x10000091u, /* Peri 1, Address 0x44603000, size 0x00000020 */
    PROT_PERI1_SOCMEM_MAIN          = 0x10000092u, /* Peri 1, Address 0x44640000, size 0x00000080 */
    PROT_PERI1_SOCMEM_BOOT          = 0x10000093u, /* Peri 1, Address 0x44640110, size 0x00000004 */
    PROT_PERI1_SOCMEM_SOCMEM_PWR    = 0x10000094u, /* Peri 1, Address 0x44640200, size 0x00000100 */
    PROT_PERI1_SOCMEM_SRAM_MPC0_PPC_MPC_MAIN = 0x10000095u, /* Peri 1, Address 0x44642000, size 0x00000004 */
    PROT_PERI1_SOCMEM_SRAM_MPC0_PPC_MPC_PC = 0x10000096u, /* Peri 1, Address 0x44642100, size 0x00000020 */
    PROT_PERI1_SOCMEM_SRAM_MPC0_PPC_MPC_ROT = 0x10000097u, /* Peri 1, Address 0x44642200, size 0x00000020 */
    PROT_PERI1_SOCMEM_MAIN_PORT     = 0x10000098u, /* Peri 1, Address 0x44650000, size 0x00008000 */
    PROT_PERI1_SOCMEM_PPU_SOCMEM_PPU = 0x10000099u, /* Peri 1, Address 0x44660000, size 0x00001000 */
    PROT_PERI1_SOCMEM_SOCMEM_PD_PD  = 0x1000009Au, /* Peri 1, Address 0x44661000, size 0x00000020 */
    PROT_PERI1_GFXSS_GPU_GFXSS      = 0x1000009Bu, /* Peri 1, Address 0x44800000, size 0x00001000 */
    PROT_PERI1_GFXSS_DC_GFXSS       = 0x1000009Cu, /* Peri 1, Address 0x44801000, size 0x00001000 */
    PROT_PERI1_GFXSS_MIPIDSI_GFXSS  = 0x1000009Du, /* Peri 1, Address 0x44802000, size 0x00002000 */
    PROT_PERI1_SDHC0                = 0x1000009Eu, /* Peri 1, Address 0x44810000, size 0x00010000 */
    PROT_PERI1_SDHC1                = 0x1000009Fu, /* Peri 1, Address 0x44820000, size 0x00010000 */
    PROT_PERI1_USBHS_DWC_otg_intreg_CONTROLLER = 0x100000A0u, /* Peri 1, Address 0x44900000, size 0x00001000 */
    PROT_PERI1_USBHS_SS_SUBSYSTEM   = 0x100000A1u, /* Peri 1, Address 0x44940000, size 0x00000040 */
    PROT_PERI1_ITCM                 = 0x100000A2u, /* Peri 1, Address 0x48000000, size 0x00010000 */
    PROT_PERI1_DTCM                 = 0x100000A3u, /* Peri 1, Address 0x48040000, size 0x00010000 */
    PROT_PERI1_END                  = 0x100000A3u
} cy_en_prot_region_t;

#endif /* _PSE84_CONFIG_H_ */


/* [] END OF FILE */
