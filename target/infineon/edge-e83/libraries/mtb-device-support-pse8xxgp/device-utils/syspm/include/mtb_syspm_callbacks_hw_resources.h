/*******************************************************************************
* File Name: mtb_syspm_callbacks_hw_resources.h
*
* Description:
* Provides struct definitions for configuration resources in the PDL.
*
********************************************************************************
* \copyright
* Copyright 2024-2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
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

/**
 * \addtogroup mtb_syspm_group_syspm_availability SYSPM Callbacks Availability
 * \{
 * This section documents the macros that can be used to check if a specific callback is available
 * for the current device. This includes macros for all IP that exist for any device, even
 * those that are not applicable (included) with this library. This is intended to help write code
 * that can port between device categories that might not have the same IPs available.
 */
#pragma once


#include "cy_pdl.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** Macro specifying whether the DMA DW callback is available for the current device */
#if ((defined(CY_IP_M4CPUSS_DMA_INSTANCES) && ((CY_IP_M4CPUSS_DMA_INSTANCES) > 0)) || \
    (defined(CY_IP_M7CPUSS_DMA_INSTANCES) && ((CY_IP_M7CPUSS_DMA_INSTANCES) > 0)) || \
    (defined(CY_IP_MXDW_INSTANCES) && ((CY_IP_MXDW_INSTANCES) > 0)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_DMA_DW (1u)
#endif

/** Macro specifying whether the DMA DMAC callback is available for the current device */
#if ((defined(CY_IP_M4CPUSS_DMA_INSTANCES) && ((CY_IP_M4CPUSS_DMAC_INSTANCES) > 0)) || \
    (defined(CY_IP_M7CPUSS_DMAC_INSTANCES) && ((CY_IP_M7CPUSS_DMAC_INSTANCES) > 0)) || \
    (defined(CY_IP_MXAHBDMAC_INSTANCES) && ((CY_IP_MXAHBDMAC_INSTANCES) > 0)) || \
    (defined(CY_IP_MXSAXIDMAC_INSTANCES) && ((CY_IP_MXSAXIDMAC_INSTANCES) > 0)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_DMA_DMAC (1u)
#endif

/** Macro specifying whether DMA callback is available for the current device */
#if  (defined(MTB_SYSPM_CALLBACKS_AVAILABLE_DMA_DW) || \
    defined(MTB_SYSPM_CALLBACKS_AVAILABLE_DMA_DMAC))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_DMA (1u)
#endif

/** Macro specifying whether I2S IP is available for the current device */
#if ((defined(CY_IP_MXAUDIOSS_INSTANCES) && ((CY_IP_MXAUDIOSS_INSTANCES) > 0)) && \
    ((defined(AUDIOSS_I2S) && AUDIOSS_I2S) \
    || (defined(AUDIOSS0_I2S) && AUDIOSS0_I2S) \
    || (defined(AUDIOSS0_I2S_I2S) && AUDIOSS0_I2S_I2S)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_I2S (1u)
#endif

/** Macro specifying whether TDM IP is available for the current device */
#if  (defined(CY_IP_MXTDM_INSTANCES) && ((CY_IP_MXTDM_INSTANCES) > 0))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_TDM (1u)
#endif

/** Macro specifying whether I2S_TDM callback is available for the current device */
#if (defined(MTB_SYSPM_CALLBACKS_AVAILABLE_I2S) || \
    defined(MTB_SYSPM_CALLBACKS_AVAILABLE_TDM))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_I2S_TDM (1u)
#endif

/** Macro specifying whether AUDIOSS PDM IP is available for the current device */
#if ((defined(CY_IP_MXAUDIOSS_INSTANCES) && ((CY_IP_MXAUDIOSS_INSTANCES) > 0)) && \
    ((defined(AUDIOSS_PDM) && AUDIOSS_PDM) \
    || (defined(AUDIOSS0_PDM) && AUDIOSS0_PDM) \
    || (defined(AUDIOSS0_PDM_PDM) && AUDIOSS0_PDM_PDM)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_AUDIOSS_PDM (1u)
#endif

/** Macro specifying whether MXPDM IP is available for the current device */
#if (defined(CY_IP_MXPDM_INSTANCES) && ((CY_IP_MXPDM_INSTANCES) > 0))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_MX_PDM (1u)
#endif

/** Macro specifying whether PDM_PCM callback is available for the current device */
#if  (defined(MTB_SYSPM_CALLBACKS_AVAILABLE_AUDIOSS_PDM) || \
    defined(MTB_SYSPM_CALLBACKS_AVAILABLE_MX_PDM))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_PDM_PCM (1u)
#endif

/** Macro specifying whether the SCB IP is available for the current device */
#if  ((defined(CY_IP_MXSCB_INSTANCES) && ((CY_IP_MXSCB_INSTANCES) > 0)) || \
    (defined(CY_IP_MXS22SCB_INSTANCES) && ((CY_IP_MXS22SCB_INSTANCES) > 0)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB (1u)
#endif

/** Macro specifying whether the SCB UART callback is available for the current device */
#if defined(SCB_UART)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_UART         \
    (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB) && (SCB_UART)     //SCB[x]_UART
#else
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_UART         (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB) //SCB[x]_UART
#endif /* defined(SCB_UART) */

/** Macro specifying whether the SMIF callback is available for the current device */
#if (defined(CY_IP_MXSMIF_INSTANCES) && ((CY_IP_MXSMIF_INSTANCES) > 0))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SMIF  (1u)
#endif

/** Macro specifying whether the TCPWM callback is available for the current device */
#if  ((defined(CY_IP_MXTCPWM_INSTANCES) && ((CY_IP_MXTCPWM_INSTANCES) > 0)) || \
    (defined(CY_IP_MXS40TCPWM_INSTANCES) && ((CY_IP_MXS40TCPWM_INSTANCES) > 0)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_TCPWM (1u)
#endif

/** Macro specifying whether the NVM callback is available for the current device */
#if (defined(CY_IP_MXFLASHC_VERSION_ECT) || defined (CY_IP_MXS40FLASHC) \
    || defined(FLASHC_BASE) || ((CPUSS_FLASHC_PRESENT) > 0) \
    || (defined(CY_IP_MXS22RRAMC) && ((CY_IP_MXS22RRAMC_INSTANCES) > 0)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_NVM (1u)
#endif

//PDL Aliased Callbacks Section

/** Macro specifying whether the AUTANALOG callback is available for the current device */
#if defined(CY_IP_MXS22LPPASS)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_AUTANALOG (1u)
#endif

/** Macro specifying whether the CTDAC callback is available for the current device */
#if defined(CY_IP_MXS40PASS_CTDAC)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_CTDAC (1u)
#endif

/** Macro specifying whether the HPPASS callback is available for the current device */
#if defined(CY_IP_MXS40MCPASS)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_HPPASS (1u)
#endif

/** Macro specifying whether the I3C callback is available for the current device */
#if defined(CY_IP_MXI3C)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_I3C (1u)
#endif

/** Macro specifying whether the LPCOMP callback is available for the current device */
#if (defined(CY_IP_MXLPCOMP) || defined(CY_IP_MXS22LPCOMP) || defined(CY_IP_MXS40LPCOMP))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_LPCOMP (1u)
#endif

/** Macro specifying whether the LVD HT callback is available for the current device */
#if (defined (CY_IP_MXS40SRSS) &&  \
    (defined(CY_IP_MXS40SRSS_VERSION) && (CY_IP_MXS40SRSS_VERSION >= 2)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_LVD_HT (1u)
#endif

/** Macro specifying whether the LVD callback is available for the current device */
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || \
    (defined (CY_IP_MXS40SRSS) && (defined(CY_IP_MXS40SRSS_VERSION) && \
    (CY_IP_MXS40SRSS_VERSION == 1)))
#define MTB_SYSPM_CALLBACKS_AVAILABLE_LVD (1u)
#endif

/** Macro specifying whether the RTC callback is available for the current device */
#if defined (CY_IP_MXS40SRSS_RTC) || defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || \
    defined (CY_IP_MXS22SRSS)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_RTC (1u)
#endif

/** Macro specifying whether the SAR callback is available for the current device */
#if defined(CY_IP_MXS40PASS_SAR)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SAR (1u)
#endif

/** Macro specifying whether the SCB EZI2C callback is available for the current device */
#if defined(SCB_EZI2C)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_EZI2C         \
    (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB) && (SCB_EZI2C)     //SCB_EZI2C
#else
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_EZI2C         (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB)
#endif /* defined(SCB_EZI2C) */

/** Macro specifying whether the SCB I2C callback is available for the current device */
#if defined(SCB_I2C)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_I2C         \
    (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB) && (SCB_I2C)     //SCB_I2C
#else
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_I2C         (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB)
#endif /* defined(SCB_I2C) */

/** Macro specifying whether the SCB SPI callback is available for the current device */
#if defined(SCB_SPI)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_SPI         \
    (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB) && (SCB_SPI)     //SCB_SPI
#else
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_SPI         (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB)
#endif /* defined(SCB_SPI) */

/** Macro specifying whether the SD HOST callback is available for the current device */
#if defined(CY_IP_MXSDHC)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SD_HOST (1u)
#endif

/** Macro specifying whether the SYSCLK callback is available for the current device */
#if defined(CY_IP_MXS28SRSS) || defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || \
    defined(CY_IP_MXS22SRSS)
#define MTB_SYSPM_CALLBACKS_AVAILABLE_SYSCLK (1u)
#endif

#if defined(__cplusplus)
}
#endif
/** \} mtb_syspm_group_syspm_availability */
