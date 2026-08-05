/***************************************************************************//**
* \file mtb_hal_dma_impl.h
*
* \brief
* Implementation details of Infineon Datawire/DMAC DMA.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
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

#pragma once

#if defined(CY_IP_M4CPUSS_DMAC) || defined(CY_IP_M4CPUSS_DMA) || defined(CY_IP_M7CPUSS_DMAC) || \
    defined(CY_IP_M7CPUSS_DMA) || defined(CY_IP_MXAHBDMAC)
#include "mtb_hal_dma_dmac_ip_common.h"
#elif defined(CY_IP_MXSAXIDMAC)
#include "mtb_hal_dma_dmac_mxsaxidmac_v1.h"
#endif

#if defined(CY_IP_M4CPUSS_DMAC) || defined(CY_IP_M4CPUSS_DMA) || defined(CY_IP_M7CPUSS_DMAC) || \
    defined(CY_IP_M7CPUSS_DMA) || defined(CY_IP_M0S8CPUSSV3_DMAC) || defined(CY_IP_MXAHBDMAC) || \
    defined(CY_IP_MXDW) || defined(CY_IP_MXSAXIDMAC)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_impl_dma DMA (Direct Memory Access)
 * \ingroup group_hal_impl
 * \{
 * DW (DataWire) is one of two DMA hardware implementations.
 * DW is designed for low latency memory to peripheral or peripheral to memory
 * transfers but can also perform memory to memory transfers and peripheral to
 * peripheral transfers.
 *
 * DMAC (Direct Memory Access Controller) is the second of two DMA hardware
 * implementations. DMAC is designed with high memory
 * bandwidth for large memory to memory transfers but can perform peripheral
 * to memory, memory to peripheral, and peripheral to peripheral transfers.
 *
 * Which DMA type is used is dependent on the exact hardware and number of DMA
 * channels already in use. This implementation will attempt to use DMAC first
 * for memory to memory transfers and Datawire otherwise but either type may be
 * used.
 *
 * */

/** \} group_hal_impl_dma */

#if defined(__cplusplus)
}
#endif

#endif \
    /* defined(CY_IP_M4CPUSS_DMAC) || defined(CY_IP_M4CPUSS_DMA) || defined(CY_IP_M7CPUSS_DMAC) ||
       defined(CY_IP_M7CPUSS_DMA) || defined(CY_IP_M0S8CPUSSV3_DMAC) || defined(CY_IP_MXAHBDMAC) ||
       defined(CY_IP_MXDW) */
