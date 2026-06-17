/*
 * SPDX-FileCopyrightText: Copyright 2023 Infineon Technologies G
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
#if CY_IP_MXNNLITE_VERSION !=1
#include "cy_nnsupportfunctions.h"
#include <assert.h>
#include <math.h>


/*
 * Calculate the output state tensor of an LSTM step, s8 input/output and s16 weight version.
 * Refer to header files for details
 */
cy_en_nnlite_status_t cy_nn_lstm_update_output_s8_s16(const int n_batch,
                                      const int n_cell,
                                      int16_t *cell_state,
                                      const int32_t cell_state_scale,
                                      const int16_t *output_gate,
                                      const cy_nn_scaling hidden_scaling,
                                      const int32_t hidden_offset,
                                      int8_t *output_state,
                                      int16_t *cell_gate_scratch)
{
    const int32_t size = n_batch * n_cell;

    cy_nn_dims_t inoutDims = {{1,1,1,size}};
    cy_en_nnlite_status_t status;

    float out_scale = ((float)(1<<15))/(float)(1<<NNLITE_TANH_FRAC_BITS);


    cy_nn_pwise_unary_params_t act_params;

    act_params.inputSize = CY_NNLITE_ACTIVATION_16BIT;
    act_params.outputSize = CY_NNLITE_OUTPUT_16BIT;
    act_params.outClipping.max = (1<<15)-1;
    act_params.outClipping.min = -(1<<15);
    act_params.outOffset = 0;
    // We have a power-of-two scale factor for the cell-state.  Usually 11 or 12...
    act_params.inScale = ldexpf(1.0f, cell_state_scale);
    act_params.inOffset = 0;
    // CMSIS outputs Q.15.  NNLite outputs Q.NNLITE_<op>_FRAC_BITS need to adjust to match
    act_params.outScale =  out_scale;
    act_params.outOffset = 0;

    status =
        Cy_NNLite_Activation((int8_t *)cell_state, (int8_t*)cell_gate_scratch,
                            &inoutDims, &act_params, CY_NNLITE_ACTIVATION_TANH,
                            NULL);

    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }
#if 0 // ORIGINAL CMSIS-NN
    int32_t tanh_input_left_shift = (15 + cell_state_scale) - 3;
    if (tanh_input_left_shift < 0)
    {
        tanh_input_left_shift = -tanh_input_left_shift;
        for (int32_t i = 0; i < size; i++)
        {
            cell_state[i] = cell_state[i] >> tanh_input_left_shift;
        }
        tanh_input_left_shift = 0;
    }
    arm_nn_activation_s16(cell_state, cell_gate_scratch, size, tanh_input_left_shift, ARM_TANH);
#endif

    // Gates activation functions are Q.15 values so need
    // scale product accordingly

    cy_nn_pwise_binary_params_t mul_params;
    mul_params.lhsOffset = 0;
    mul_params.rhsOffset = 0;
    mul_params.outputOffset = hidden_offset;
    mul_params.outClipping.min = INT8_MIN;
    mul_params.outClipping.max = INT8_MAX;
    mul_params.inputSize = CY_NNLITE_ACTIVATION_16BIT;
    mul_params.outputSize = CY_NNLITE_OUTPUT_8BIT;
    mul_params.scaling.pre_mac_scaling_mode = CY_NNLITE_RESCALE_NONE;
    mul_params.scaling.pre_mac_scale = 1.0f;
    mul_params.scaling.pre_act_scaling_mode = CY_NNLITE_OUTSCALE_NONE;
    mul_params.scaling.pre_act_scale = 1.0f; // Ignored
    mul_params.scaling.post_act_scale = hidden_scaling.scale;

    status =
        Cy_NNLite_Mul((const int8_t *)output_gate, (const int8_t*)cell_gate_scratch,
                        output_state,
                        &inoutDims, &inoutDims, &mul_params);

#if 0 // ORIGINAL CMSIS-NN
    arm_elementwise_mul_s16_s8(output_gate,
                               cell_gate_scratch,
                               output_state,
                               hidden_offset,
                               hidden_scaling.multiplier,
                               hidden_scaling.shift,
                               size);

    printf( "REF %g GOT %g", ldexp((double)hidden_scaling.multiplier, hidden_scaling.shift-31), (double)hidden_scaling.scale );
    int i;
    bool fail = false;
    for( i = 0; i < size; ++i) {
        printf( "%d * %d * %g = %d got %d\n",
            (int)output_gate[i], (int)cell_gate_scratch[i], (double)hidden_scaling.scale, output_state[i], tmp[i]);
        fail |= (output_state[i] != tmp[i]);
    }
    assert( !fail );
#endif

    return status;
}
#endif //CY_IP_MXNNLITE_VERSION
