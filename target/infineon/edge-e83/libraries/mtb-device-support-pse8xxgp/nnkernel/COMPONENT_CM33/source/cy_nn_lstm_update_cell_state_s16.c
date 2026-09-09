/*
 * SPDX-FileCopyrightText: Copyright 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "cy_nn_kernel.h"
#if CY_IP_MXNNLITE_VERSION != 1

#include "cy_nnsupportfunctions.h"
#include <assert.h>
#include <math.h>

/*
 * Update cell state for a single LSTM iteration step, int8x8_16 version.
 *
 * Refer to header file for more details
 *
 * Note: forget gate is over-written as it is mis-used
 * as a buffer for an intermediate sum
 */
cy_en_nnlite_status_t cy_nn_lstm_update_cell_state_s16(const int32_t n_block,
                                       const int32_t lg2_cell_state_scale,
                                       int16_t *cell_state,
                                       const int16_t *input_gate,
                                       int16_t *forget_gate,
                                       const int16_t *cell_gate)
{
    // In CMSIS-NN operator implementation this is  constrained to <= -9
    cy_en_nnlite_status_t status;
    const int32_t cell_scale = 30 + lg2_cell_state_scale;
    cy_nn_dims_t inoutDims = {{1,1,1,n_block}};

    cy_nn_pwise_binary_params_t       binop_params;
    binop_params.lhsOffset = 0;
    binop_params.rhsOffset = 0;
    binop_params.outputOffset = 0;
    binop_params.outClipping.min = INT16_MIN;
    binop_params.outClipping.max = INT16_MAX;
    binop_params.inputSize = CY_NNLITE_ACTIVATION_16BIT;
    binop_params.outputSize = CY_NNLITE_OUTPUT_16BIT;
    binop_params.scaling.pre_mac_scaling_mode = CY_NNLITE_RESCALE_NONE;
    binop_params.scaling.pre_mac_scale = 1.0f;
    binop_params.scaling.pre_act_scaling_mode = CY_NNLITE_OUTSCALE_NONE;
    binop_params.scaling.pre_act_scale = 1.0f; // Ignored
    // Gates activation functions are Q.15 values so need
    // scale product accordingly
    binop_params.scaling.post_act_scale = ldexpf(1.0f, -15);


    status =
        Cy_NNLite_Mul((const int8_t *)cell_state, (const int8_t*)forget_gate,
                        (int8_t*)cell_state,
                        &inoutDims, &inoutDims, &binop_params);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }

    // Abuse forget_gate as scratch buffer for intermediate sum...
    binop_params.scaling.post_act_scale = ldexpf(1.0f, -cell_scale);
    status =
        Cy_NNLite_Mul((const int8_t *)input_gate, (const int8_t*)cell_gate,
                        (int8_t*)forget_gate,
                        &inoutDims, &inoutDims, &binop_params);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }

    // Compute final sum.  No output rescaling...
    binop_params.scaling.post_act_scale = 1.0f;
    status =
        Cy_NNLite_Add((const int8_t *)cell_state, (const int8_t*)forget_gate,
                        (int8_t*)cell_state,
                        &inoutDims, &inoutDims, &binop_params);
#if 0 // ORIGINAL CMSIS-NN
    const int32_t cell_scale = 30 + cell_state_scale;
    int32_t loop_count = n_block;

    for (int i = 0; i < loop_count; i++)
    {
        int32_t value = cell_state[i] * forget_gate[i];
        int32_t value_1 = input_gate[i] * cell_gate[i];

        value = arm_nn_divide_by_power_of_two(value, 15);
        value_1 = arm_nn_divide_by_power_of_two(value_1, cell_scale);

        cell_state[i] = CLAMP(value + value_1, NN_Q15_MAX, NN_Q15_MIN);
    }
#endif
    return status;
}
#endif //CY_IP_MXNNLITE_VERSION
