/*******************************************************************************
 * File Name: cycfg_peripheral_clocks.h
 *
 * Description:
 * Peripheral clock divider configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.37.0.10260
 * mtb-dsl-pse8xxgp 1.5.0.1072
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
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
 ******************************************************************************/

#if !defined(CYCFG_PERIPHERAL_CLOCKS_H)
#define CYCFG_PERIPHERAL_CLOCKS_H

#include "cycfg_notices.h"
#include "cy_sysclk.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define peri_0_mmio_0_ENABLED 1U
#define peri_1_mmio_0_ENABLED 1U
#define CYBSP_UART1_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_UART1_CLK_DIV_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_UART1_CLK_DIV_NUM 0U
#define CYBSP_UART1_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_UART1_CLK_DIV_GRP_NUM)
#define CYBSP_UART1_CLK_DIV_GRP_NUM CYBSP_UART1_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_UART1_CLK_DIV_GRP_NUM) */

#define CYBSP_SPI_CONTROLLER_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_SPI_CONTROLLER_CLK_DIV_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_SPI_CONTROLLER_CLK_DIV_NUM 1U
#define CYBSP_SPI_CONTROLLER_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_SPI_CONTROLLER_CLK_DIV_GRP_NUM)
#define CYBSP_SPI_CONTROLLER_CLK_DIV_GRP_NUM CYBSP_SPI_CONTROLLER_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_SPI_CONTROLLER_CLK_DIV_GRP_NUM) */

#define CYBSP_USB_OS_TIMER_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_USB_OS_TIMER_CLK_DIV_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_USB_OS_TIMER_CLK_DIV_NUM 2U
#define CYBSP_USB_OS_TIMER_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_USB_OS_TIMER_CLK_DIV_GRP_NUM)
#define CYBSP_USB_OS_TIMER_CLK_DIV_GRP_NUM CYBSP_USB_OS_TIMER_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_USB_OS_TIMER_CLK_DIV_GRP_NUM) */

#define CYBSP_UART2_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_UART2_CLK_DIV_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_UART2_CLK_DIV_NUM 3U
#define CYBSP_UART2_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_UART2_CLK_DIV_GRP_NUM)
#define CYBSP_UART2_CLK_DIV_GRP_NUM CYBSP_UART2_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_UART2_CLK_DIV_GRP_NUM) */

#define peri_0_group_1_div_8_4_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_1_div_8_4_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_1_div_8_4_NUM 4U
#define PERI_0_GROUP_1_DIV_8_4_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_1_div_8_4_GRP_NUM)
#define peri_0_group_1_div_8_4_GRP_NUM PERI_0_GROUP_1_DIV_8_4_GRP_NUM
#endif /* !defined (peri_0_group_1_div_8_4_GRP_NUM) */

#define CYBSP_I2C_CONTROLLER_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_I2C_CONTROLLER_CLK_DIV_HW CY_SYSCLK_DIV_16_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_I2C_CONTROLLER_CLK_DIV_NUM 0U
#define CYBSP_I2C_CONTROLLER_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_I2C_CONTROLLER_CLK_DIV_GRP_NUM)
#define CYBSP_I2C_CONTROLLER_CLK_DIV_GRP_NUM CYBSP_I2C_CONTROLLER_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_I2C_CONTROLLER_CLK_DIV_GRP_NUM) */

#define CYBSP_UART4_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_UART4_CLK_DIV_HW CY_SYSCLK_DIV_16_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_UART4_CLK_DIV_NUM 1U
#define CYBSP_UART4_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_UART4_CLK_DIV_GRP_NUM)
#define CYBSP_UART4_CLK_DIV_GRP_NUM CYBSP_UART4_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_UART4_CLK_DIV_GRP_NUM) */

#define CYBSP_UART9_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_UART9_CLK_DIV_HW CY_SYSCLK_DIV_16_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_UART9_CLK_DIV_NUM 2U
#define CYBSP_UART9_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_UART9_CLK_DIV_GRP_NUM)
#define CYBSP_UART9_CLK_DIV_GRP_NUM CYBSP_UART9_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_UART9_CLK_DIV_GRP_NUM) */

#define CYBSP_UART10_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_UART10_CLK_DIV_HW CY_SYSCLK_DIV_16_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_UART10_CLK_DIV_NUM 3U
#define CYBSP_UART10_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_UART10_CLK_DIV_GRP_NUM)
#define CYBSP_UART10_CLK_DIV_GRP_NUM CYBSP_UART10_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_UART10_CLK_DIV_GRP_NUM) */

#define CYBSP_UART11_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_UART11_CLK_DIV_HW CY_SYSCLK_DIV_16_5_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_UART11_CLK_DIV_NUM 0U
#define CYBSP_UART11_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_UART11_CLK_DIV_GRP_NUM)
#define CYBSP_UART11_CLK_DIV_GRP_NUM CYBSP_UART11_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_UART11_CLK_DIV_GRP_NUM) */

#define CYBSP_PWM_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_PWM_CLK_DIV_HW CY_SYSCLK_DIV_16_5_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_PWM_CLK_DIV_NUM 1U
#define CYBSP_PWM_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_PWM_CLK_DIV_GRP_NUM)
#define CYBSP_PWM_CLK_DIV_GRP_NUM CYBSP_PWM_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_PWM_CLK_DIV_GRP_NUM) */

#define CYBSP_SMART_IO_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_SMART_IO_CLK_DIV_HW CY_SYSCLK_DIV_24_5_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_SMART_IO_CLK_DIV_NUM 0U
#define CYBSP_SMART_IO_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_SMART_IO_CLK_DIV_GRP_NUM)
#define CYBSP_SMART_IO_CLK_DIV_GRP_NUM CYBSP_SMART_IO_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_SMART_IO_CLK_DIV_GRP_NUM) */

#define peri_0_group_2_div_8_0_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_2_div_8_0_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_2_div_8_0_NUM 0U
#define PERI_0_GROUP_2_DIV_8_0_GRP_NUM ((2U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_2_div_8_0_GRP_NUM)
#define peri_0_group_2_div_8_0_GRP_NUM PERI_0_GROUP_2_DIV_8_0_GRP_NUM
#endif /* !defined (peri_0_group_2_div_8_0_GRP_NUM) */

#define peri_0_group_2_div_8_1_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_2_div_8_1_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_2_div_8_1_NUM 1U
#define PERI_0_GROUP_2_DIV_8_1_GRP_NUM ((2U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_2_div_8_1_GRP_NUM)
#define peri_0_group_2_div_8_1_GRP_NUM PERI_0_GROUP_2_DIV_8_1_GRP_NUM
#endif /* !defined (peri_0_group_2_div_8_1_GRP_NUM) */

#define peri_0_group_2_div_8_2_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_2_div_8_2_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_2_div_8_2_NUM 2U
#define PERI_0_GROUP_2_DIV_8_2_GRP_NUM ((2U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_2_div_8_2_GRP_NUM)
#define peri_0_group_2_div_8_2_GRP_NUM PERI_0_GROUP_2_DIV_8_2_GRP_NUM
#endif /* !defined (peri_0_group_2_div_8_2_GRP_NUM) */

#define peri_0_group_2_div_8_3_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_2_div_8_3_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_2_div_8_3_NUM 3U
#define PERI_0_GROUP_2_DIV_8_3_GRP_NUM ((2U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_2_div_8_3_GRP_NUM)
#define peri_0_group_2_div_8_3_GRP_NUM PERI_0_GROUP_2_DIV_8_3_GRP_NUM
#endif /* !defined (peri_0_group_2_div_8_3_GRP_NUM) */

#define peri_0_group_3_div_8_0_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_3_div_8_0_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_3_div_8_0_NUM 0U
#define PERI_0_GROUP_3_DIV_8_0_GRP_NUM ((3U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_3_div_8_0_GRP_NUM)
#define peri_0_group_3_div_8_0_GRP_NUM PERI_0_GROUP_3_DIV_8_0_GRP_NUM
#endif /* !defined (peri_0_group_3_div_8_0_GRP_NUM) */

#define peri_0_group_4_div_8_0_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_4_div_8_0_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_4_div_8_0_NUM 0U
#define PERI_0_GROUP_4_DIV_8_0_GRP_NUM ((4U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_4_div_8_0_GRP_NUM)
#define peri_0_group_4_div_8_0_GRP_NUM PERI_0_GROUP_4_DIV_8_0_GRP_NUM
#endif /* !defined (peri_0_group_4_div_8_0_GRP_NUM) */

#define CYBSP_TRACE_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_TRACE_CLK_DIV_HW CY_SYSCLK_DIV_16_5_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_TRACE_CLK_DIV_NUM 0U
#define CYBSP_TRACE_CLK_DIV_GRP_NUM ((7U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_TRACE_CLK_DIV_GRP_NUM)
#define CYBSP_TRACE_CLK_DIV_GRP_NUM CYBSP_TRACE_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_TRACE_CLK_DIV_GRP_NUM) */

#define peri_0_group_8_div_16_0_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_8_div_16_0_HW CY_SYSCLK_DIV_16_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_8_div_16_0_NUM 0U
#define PERI_0_GROUP_8_DIV_16_0_GRP_NUM ((8U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_8_div_16_0_GRP_NUM)
#define peri_0_group_8_div_16_0_GRP_NUM PERI_0_GROUP_8_DIV_16_0_GRP_NUM
#endif /* !defined (peri_0_group_8_div_16_0_GRP_NUM) */

#define CYBSP_I3C_CONTROLLER_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_I3C_CONTROLLER_CLK_DIV_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_I3C_CONTROLLER_CLK_DIV_NUM 0U
#define CYBSP_I3C_CONTROLLER_CLK_DIV_GRP_NUM ((9U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_I3C_CONTROLLER_CLK_DIV_GRP_NUM)
#define CYBSP_I3C_CONTROLLER_CLK_DIV_GRP_NUM CYBSP_I3C_CONTROLLER_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_I3C_CONTROLLER_CLK_DIV_GRP_NUM) */

#define CYBSP_TDM_CONTROLLER_0_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_TDM_CONTROLLER_0_CLK_DIV_HW CY_SYSCLK_DIV_16_5_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_TDM_CONTROLLER_0_CLK_DIV_NUM 0U
#define CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (1U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM)
#define CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM) */

#define CYBSP_PDM_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_PDM_CLK_DIV_HW CY_SYSCLK_DIV_16_5_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_PDM_CLK_DIV_NUM 1U
#define CYBSP_PDM_CLK_DIV_GRP_NUM ((1U << PERI_PCLK_GR_NUM_Pos) | (1U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_PDM_CLK_DIV_GRP_NUM)
#define CYBSP_PDM_CLK_DIV_GRP_NUM CYBSP_PDM_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_PDM_CLK_DIV_GRP_NUM) */

#define CYBSP_SDHC_0_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_SDHC_0_CLK_DIV_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_SDHC_0_CLK_DIV_NUM 0U
#define CYBSP_SDHC_0_CLK_DIV_GRP_NUM ((2U << PERI_PCLK_GR_NUM_Pos) | (1U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_SDHC_0_CLK_DIV_GRP_NUM)
#define CYBSP_SDHC_0_CLK_DIV_GRP_NUM CYBSP_SDHC_0_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_SDHC_0_CLK_DIV_GRP_NUM) */

#define CYBSP_SDHC_1_CLK_DIV_ENABLED 1U

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define CYBSP_SDHC_1_CLK_DIV_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define CYBSP_SDHC_1_CLK_DIV_NUM 0U
#define CYBSP_SDHC_1_CLK_DIV_GRP_NUM ((3U << PERI_PCLK_GR_NUM_Pos) | (1U << PERI_PCLK_INST_NUM_Pos))

#if !defined (CYBSP_SDHC_1_CLK_DIV_GRP_NUM)
#define CYBSP_SDHC_1_CLK_DIV_GRP_NUM CYBSP_SDHC_1_CLK_DIV_GRP_NUM
#endif /* !defined (CYBSP_SDHC_1_CLK_DIV_GRP_NUM) */

void init_cycfg_peripheral_clocks(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PERIPHERAL_CLOCKS_H */
