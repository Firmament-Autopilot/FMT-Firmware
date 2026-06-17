/***************************************************************************//**
* \file mtb_hal_hw_types_comp_lp.h
*
*********************************************************************************
* \copyright
* Copyright(c) 2024-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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

#include "cy_pdl.h"

#if defined(CY_IP_MXLPCOMP_INSTANCES) || \
    defined (CY_IP_MXS40LPCOMP_INSTANCES) || \
    defined (CY_IP_MXS22LPCOMP_INSTANCES)

#if !defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)
#define _MTB_HAL_DRIVER_AVAILABLE_COMP_LP (1u)
#endif // !defined(_MTB_HAL_DRIVER_AVAILABLE_COMP_LP)


typedef LPCOMP_Type            _mtb_hal_lpcomp_base_t;
typedef cy_en_lpcomp_channel_t _mtb_hal_lpcomp_channel_t;
typedef cy_stc_lpcomp_config_t _mtb_hal_lpcomp_pdl_config_t;

#endif
