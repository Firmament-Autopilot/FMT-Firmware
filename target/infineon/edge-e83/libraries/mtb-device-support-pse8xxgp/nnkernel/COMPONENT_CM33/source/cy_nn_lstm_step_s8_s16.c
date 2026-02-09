/*
 * SPDX-FileCopyrightText: Copyright Infineon Technologies AG
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

/*
 * Calculate the output state tensor of an LSTM step, s8 input/output and s16 weight version.
 * Refer to header file for details.
 */
cy_en_nnlite_status_t cy_nn_lstm_step_s8_s16(const int8_t *input,
                                            const int8_t *input_to_input_weight,
                                            const int8_t *input_to_forget_weight,
                                            const int8_t *input_to_cell_weight,
                                            const int8_t *input_to_output_weight,
                                            const int8_t *recurrent_to_input_weight,
                                            const int8_t *recurrent_to_forget_weight,
                                            const int8_t *recurrent_to_cell_weight,
                                            const int8_t *recurrent_to_output_weight,
                                            const cy_nn_lstm_params *lstm,
                                            const int n_batch,
                                            const int n_cell,
                                            const int n_input,
                                            const int n_output,
                                            int8_t *output_state,
                                            int16_t *cell_state,
                                            int8_t *output,
                                            cy_nn_lstm_context *scratch_buffers)
{
    const int32_t n_block = n_batch * n_cell;

    cy_en_nnlite_status_t status;
    // Calculate the input gate
   status =
     cy_nn_lstm_calculate_gate_s8_s16(input,
                                      lstm->input_offset,
                                      input_to_input_weight,
                                      lstm->input_gate_bias,
                                      lstm->input_to_input_scaling,
                                      output_state,
                                      lstm->output_state_offset,
                                      recurrent_to_input_weight,
                                      lstm->recurrent_to_input_scaling,
                                      n_batch,
                                      n_input,
                                      n_output,
                                      n_cell,
                                      CY_NN_SIGMOID,
                                      scratch_buffers->input_gate,
                                      scratch_buffers->tmp_gate_buf);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }
    // Calculate the forget gate
    status =
      cy_nn_lstm_calculate_gate_s8_s16(input,
                                      lstm->input_offset,
                                      input_to_forget_weight,
                                      lstm->forget_gate_bias,
                                      lstm->input_to_forget_scaling,
                                      output_state,
                                      lstm->output_state_offset,
                                      recurrent_to_forget_weight,
                                      lstm->recurrent_to_forget_scaling,
                                      n_batch,
                                      n_input,
                                      n_output,
                                      n_cell,
                                      CY_NN_SIGMOID,
                                      scratch_buffers->forget_gate,
                                      scratch_buffers->tmp_gate_buf);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }
    // Calculate the cell update gate
    status =
      cy_nn_lstm_calculate_gate_s8_s16(input,
                                      lstm->input_offset,
                                      input_to_cell_weight,
                                      lstm->cell_gate_bias,
                                      lstm->input_to_cell_scaling,
                                      output_state,
                                      lstm->output_state_offset,
                                      recurrent_to_cell_weight,
                                      lstm->recurrent_to_cell_scaling,
                                      n_batch,
                                      n_input,
                                      n_output,
                                      n_cell,
                                      CY_NN_TANH,
                                      scratch_buffers->cell_gate,
                                      scratch_buffers->tmp_gate_buf);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }
    // Update the cell state
    cy_nn_lstm_update_cell_state_s16(n_block,
                                      lstm->cell_state_shift,
                                      cell_state,
                                      scratch_buffers->input_gate,
                                      scratch_buffers->forget_gate,
                                      scratch_buffers->cell_gate);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }

    // Calculate the output gate
    status =
      cy_nn_lstm_calculate_gate_s8_s16(input,
                                      lstm->input_offset,
                                      input_to_output_weight,
                                      lstm->output_gate_bias,
                                      lstm->input_to_output_scaling,
                                      output_state,
                                      lstm->output_state_offset,
                                      recurrent_to_output_weight,
                                      lstm->recurrent_to_output_scaling,
                                      n_batch,
                                      n_input,
                                      n_output,
                                      n_cell,
                                      CY_NN_SIGMOID,
                                      scratch_buffers->output_gate,
                                      scratch_buffers->tmp_gate_buf);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }
    // Update the output state
    status =
      cy_nn_lstm_update_output_s8_s16(n_batch,
                                     n_cell,
                                     cell_state,
                                     lstm->cell_state_shift,
                                     scratch_buffers->output_gate,
                                     lstm->hidden_scaling,
                                     lstm->hidden_offset,
                                     output_state,
                                     scratch_buffers->input_gate);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }
    Cy_NNLite_Byte_Copy(output_state, output, n_batch * n_output * sizeof(int8_t));
#if 0 // ORIGINAL CMSIS-NN
    arm_memcpy_s8(output, output_state, n_batch * n_output * sizeof(int8_t));
#endif
    return CY_NNLITE_SUCCESS;
}

#endif //CY_IP_MXNNLITE_VERSION
