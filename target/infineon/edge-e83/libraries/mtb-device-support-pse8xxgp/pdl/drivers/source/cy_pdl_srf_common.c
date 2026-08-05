/***************************************************************************//**
* \file cy_pdl_srf_common.c
* \version 1.000
*
* This file provides helpers / shared code between the various Secure Aware drivers.
*
********************************************************************************
* \copyright
* Copyright (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
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
*
*******************************************************************************/

#include "cy_pdl_srf_common.h"

#if !defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_ENABLE_SECURE_AWARE)
cy_rslt_t _Cy_PDL_Invoke_SRF(cy_pdl_invoke_srf_args* args)
{
    cy_rslt_t result = CY_PDL_SRF_SUCCESS;
    uint8_t inVec_cnt = 1;
    uint8_t outVec_cnt = 1;
    size_t pool_max_input_len = 0;
    size_t pool_max_output_len = 0;

    /* Our first inVec is always a mtb_srf_input_ns_t */
    mtb_srf_input_ns_t* input = (mtb_srf_input_ns_t*)(args->inVec[0].base);
    mtb_srf_output_ns_t* output = (mtb_srf_output_ns_t*)(args->outVec[0].base);

    input->request.module_id = MTB_SRF_MODULE_PDL;
    input->request.submodule_id = args->submodule_id;
    input->request.op_id = args->op_id;

    input->request.base = args->base;
    input->request.sub_block = args->sub_block;

    result = mtb_srf_pool_get_entry_len(&cy_pdl_srf_default_pool, &pool_max_input_len, &pool_max_output_len);
    if(result == CY_RSLT_SUCCESS)
    {
        if((args->input_len > pool_max_input_len) || (args->output_len > pool_max_output_len))
        {
            result = CY_PDL_SRF_BAD_PARAM;
        }
        else
        {
            if(args->input_base != NULL)
            {
                memcpy(&(input->input_values[0]), args->input_base, args->input_len);
                input->len = args->input_len;
            }
            else
            {
                input->len = 0x0;
            }
            if(args->output_base != NULL)
            {
                output->len = args->output_len;
            }
            else
            {
                output->len = 0x0;
            }

            args->inVec[0].len = sizeof(mtb_srf_input_ns_t) + input->len;
            args->outVec[0].len = sizeof(mtb_srf_output_ns_t) + output->len;

            /* inVec[0] and outVec[0] are addressed above - this leaves two vector slots remaining.
            * Copy up to two of each for inVec[1,2] and outVec[1,2].
            * We do not test that ioVec count < MAX, as the SRF will already perform this check */
            for(uint8_t i = 0; i < (MTB_SRF_MAX_IOVEC - 2); ++i)
            {
                if(args->invec_bases != NULL && args->invec_bases[i] != NULL)
                {
                    args->inVec[i + 1].base = args->invec_bases[i];
                    args->inVec[i + 1].len = args->invec_sizes[i];
                    ++inVec_cnt;
                }
                if(args->outvec_bases != NULL && args->outvec_bases[i] != NULL)
                {
                    args->outVec[i + 1].base = args->outvec_bases[i];
                    args->outVec[i + 1].len = args->outvec_sizes[i];
                    ++outVec_cnt;
                }
            }

            result = mtb_srf_request_submit(args->inVec, inVec_cnt, args->outVec, outVec_cnt);

            *(args->output_ptr) = output;
        }
    }
    return result;
}

#endif /* !defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_ENABLE_SECURE_AWARE)*/
