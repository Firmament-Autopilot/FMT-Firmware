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
 *
 * Note derivative of components of CMSIS-NN library provided by Arm Limited under
 * Apache-2.0 license.
 */


#include "cy_nn_kernel.h"
#if CY_IP_MXNNLITE_VERSION !=1
#include "cy_nn_kernel_private.h"
#include "cy_nnsupportfunctions.h"


/*
 * LSTM unidirectional function with 8 bit input and output and 16 bit intermediates
 *
 * Refer header file for details.
 *
 */
cy_en_nnlite_status_t Cy_NNLite_LSTM_Int8(cy_nn_lstm_context *scratch_buffers,
                                                   const int8_t *input_data,
                                                   const cy_nn_lstm_dims *lstm_dims,
                                                   const int8_t *in_to_in_weights,
                                                   const int8_t *in_to_forget_weights,
                                                   const int8_t *in_to_cell_weights,
                                                   const int8_t *in_to_out_weights,
                                                   const int8_t *recurrent_to_in_weights,
                                                   const int8_t *recurrent_to_forget_weights,
                                                   const int8_t *recurrent_to_cell_weights,
                                                   const int8_t *recurrent_to_out_weights,
                                                   const int8_t *projection_weights,
                                                   const cy_nn_lstm_params *lstm,
                                                   int8_t *output_state,
                                                   int16_t *cell_state,
                                                   int8_t *output_data)
{
    cy_en_nnlite_status_t status = CY_NNLITE_BAD_PARAM; // Empty time sequence
    const int32_t num_batch = lstm_dims->num_batches;
    const int32_t num_input = lstm_dims->num_inputs;
    const int32_t max_time = lstm_dims->max_time;

    const int32_t num_output = lstm_dims->num_outputs;
    const int32_t out_batch_leading_dim = num_output;

    // num_cell = num_output is considered in the code under the assumption that projection is NULL.
    const int32_t num_cell = num_output;

    if (projection_weights != NULL)
    {
        return CY_NNLITE_BAD_PARAM;
    }

    Cy_NNLite_StartMacroKernel();
    if (lstm->time_major)
    {
        const int32_t in_step = num_batch * num_input;
        const int32_t out_step = num_batch * out_batch_leading_dim;
        for (int i_time = 0; i_time < max_time; i_time++)
        {
            status = cy_nn_lstm_step_s8_s16(input_data + i_time * in_step,
                                                                 in_to_in_weights,
                                                                 in_to_forget_weights,
                                                                 in_to_cell_weights,
                                                                 in_to_out_weights,
                                                                 recurrent_to_in_weights,
                                                                 recurrent_to_forget_weights,
                                                                 recurrent_to_cell_weights,
                                                                 recurrent_to_out_weights,
                                                                 lstm,
                                                                 num_batch,
                                                                 num_cell,
                                                                 num_input,
                                                                 num_output,
                                                                 output_state,
                                                                 cell_state,
                                                                 output_data + i_time * out_step,
                                                                 scratch_buffers);
            if (status != CY_NNLITE_SUCCESS)
            {
                break;
            }
        }
    }
    else
    {
        for (int i_batch = 0; i_batch < num_batch; i_batch++)
        {
            const int32_t in_step = num_input;
            const int32_t out_step = out_batch_leading_dim;
            for (int i_time = 0; i_time < max_time; i_time++)
            {
                const int32_t time_offset = i_batch * max_time + i_time;

                status = cy_nn_lstm_step_s8_s16(input_data + time_offset * in_step,
                                                                     in_to_in_weights,
                                                                     in_to_forget_weights,
                                                                     in_to_cell_weights,
                                                                     in_to_out_weights,
                                                                     recurrent_to_in_weights,
                                                                     recurrent_to_forget_weights,
                                                                     recurrent_to_cell_weights,
                                                                     recurrent_to_out_weights,
                                                                     lstm,
                                                                     /*num_batch=*/1,
                                                                     num_cell,
                                                                     num_input,
                                                                     num_output,
                                                                     output_state + i_batch * out_batch_leading_dim,
                                                                     cell_state + i_batch * num_cell,
                                                                     output_data + time_offset * out_step,
                                                                     scratch_buffers);
                if (status != CY_NNLITE_SUCCESS)
                {
                    break;
                }
            }
        }
    }
    Cy_NNLite_EndMacrokernel();
    return status;
}

#endif //CY_IP_MXNNLITE_VERSION
