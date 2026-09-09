/***************************************************************************//**
* \file mtb_hal_adc_impl.h
*
* \brief
* Provides a high level interface for interacting with the Infineon Analog to
* Digital Converter. This interface abstracts out the chip specific details.
* If any chip specific functionality is necessary, or performance is critical
* the low level functions can be used directly.
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

//! IP-specific implementation header for ADC
#if defined(CY_IP_MXS40PASS_SAR_INSTANCES)
#include  "mtb_hal_adc_mxs40pass.h"
#elif defined(CY_IP_MXS40EPASS_ESAR_INSTANCES)
#include  "mtb_hal_adc_mxs40epass_v1.h"
#elif defined(CY_IP_M0S8PASS4A_SAR_INSTANCES)
#include  "mtb_hal_adc_m0s8pass4a.h"
#elif defined(CY_IP_MXS22LPPASS_SAR_INSTANCES)
#include  "mtb_hal_adc_mxs22lppass_v1.h"
#elif defined(CY_IP_MXS40PPSS_INSTANCES)
#include  "mtb_hal_adc_mxs40ppss_v1.h"
#elif defined(CY_IP_MXS40MCPASS_INSTANCES)
#include  "mtb_hal_adc_mxs40mcpass_v1.h"
#endif // if defined(CY_IP_MXS40PASS_SAR_INSTANCES)

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Defines
*******************************************************************************/

/*******************************************************************************
*       Functions
*******************************************************************************/

#if defined(__cplusplus)
}
#endif
