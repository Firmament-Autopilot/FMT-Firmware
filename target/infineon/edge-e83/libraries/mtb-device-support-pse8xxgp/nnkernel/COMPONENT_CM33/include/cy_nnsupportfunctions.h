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


#ifndef _CY_NNSUPPORTFUNCTIONS_H_
#define _CY_NNSUPPORTFUNCTIONS_H_

#include "cy_nn_types.h"
#include "cy_nnlite.h"

#ifdef __cplusplus
extern "C" {
#endif


// Support functions for LSTM
/**
 * @brief Update LSTM function for an iteration step
 *
 * param[in]    input                           Input data
 * param[in]    input_to_input_weight           Input to input gate weights
 * param[in]    input_to_forget_weight          Input to forget gate weights
 * param[in]    input_to_cell_weight            Input to cell gate weights
 * param[in]    input_to_output_weight          Input to output weights
 * param[in]    recurrent_to_input_weight       Recurrent signal to input weights
 * param[in]    recurrent_to_forget_weight      Recurrent signal to forget gate weights
 * param[in]    recurrent_to_cell_weight        Recurrent signal to cell gate weights
 * param[in]    recurrent_to_output_weight      Recurrent signal to output weights
 * param[in]    lstm                            LSTM parameters
 * param[in]    n_batch                         Batch size
 * param[in]    n_cell                          Cell size
 * param[in]    n_input                         Input size
 * param[in]    n_output                        Output size
 * param[out]   output_state                    Output state
 * param[out]   cell_state                      Internal state
 * param[out]   output                          Output signal
 * param[in] *scratch_buffers                   Struct containing scratch buffers
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
                                            cy_nn_lstm_context *scratch_buffers);

/**
 * @brief         Updates a LSTM gate for an iteration step of LSTM function, int8x8_16 version.
 *
 * param[in]    input                           Input data
 * param[in]    input_to_gate_weights           Input to gate weights
 * param[in]    input_to_gate_bias              Input to gate weights
 * param[in]    input_to_gate_scaling           Input to gate scaling
 * param[in]    activation                      activation min and max values
 * param[in]    output_state                    Output state
 * param[in]    recurrent_to_gate_weights       Recurrent to gate weights
 * param[in]    recurrent_to_gate_scaling       Recurrent to gate scaling
 * param[in]    n_batch                         Batch size
 * param[in]    n_input                         Input size
 * param[in]    n_output                        Output size
 * param[in]    n_cell                          Cell size
 * param[in]    activation_type                 Activation type (sigmoid or tanh)
 * param[out]   gate                            Gate output
 * param[inout] tmp_gate_buf                    Temporary buffer for intermediate sum
 * 
 * @note in line with TFLM etc there is no 'recurrent_to_gate_bias' 
 */
cy_en_nnlite_status_t cy_nn_lstm_calculate_gate_s8_s16(const int8_t *input,
                                       const int32_t input_offset,
                                       const int8_t *input_to_gate_weights,
                                       const int32_t *input_to_gate_bias,
                                       const cy_nn_scaling input_to_gate_scaling,
                                       const int8_t *output_state,
                                       const int32_t output_state_offset,
                                       const int8_t *recurrent_to_gate_weights,
                                       const cy_nn_scaling recurrent_to_gate_scaling,
                                       const int32_t n_batch,
                                       const int32_t n_input,
                                       const int32_t n_output,
                                       const int32_t n_cell,
                                       const cy_nn_activation_type activation_type,
                                       int16_t *gate,
                                       int16_t *tmp_gate_buf);

/**
 * @brief       Update cell state for a single LSTM iteration step, int8x8_16 version.
 * @param[in]   n_block             total number of cells for all batches
 * @param[in]   cell_state_scale    Scaling factor of cell state (integer base-2 log - i.e. left-shift)
 * @param[in]   cell_state          Input/output vector, size n_batch*n_cell
 * @param[in]   input_gate          Input vector of size n_block
 * @param[inout]   forget_gate      Input/scratch vector of size n_block, always modified
 * @param[in]   cell_gate           Input vector of size, n_block
 */
cy_en_nnlite_status_t cy_nn_lstm_update_cell_state_s16(const int32_t n_block,
                                       const int32_t lg2_cell_state_scale,
                                       int16_t *cell_state,
                                       const int16_t *input_gate,
                                       int16_t *forget_gate,
                                       const int16_t *cell_gate);

/**
 * @brief       Calculate the output state tensor of an LSTM step, s8 input/output and s16 weight version.
 *
 * @param[in]       n_batch                     The number of distinct vectors in each array
 * @param[in]       n_cell                      Number of cells
 * @param[in,out]   cell_state                  Cell state, size n_batch*n_cell
 * @param[in]       cell_state_scale            Scaling of cell_state
 * @param[in]       output_gate                 Output gate
 * @param[in]       hidden_scale                Effective scaling of cell_state .* output_gate
 * @param[in]       hidden_offset               Zero point for cell_state .* output_gate
 * @param[out]      output_state                Output state
 * @param[in]       cell_gate_scratch           Scratch buffer
 */
cy_en_nnlite_status_t cy_nn_lstm_update_output_s8_s16(const int n_batch,
                                      const int n_cell,
                                      int16_t *cell_state,
                                      const int32_t cell_state_scale,
                                      const int16_t *output_gate,
                                      const cy_nn_scaling hidden_scale,
                                      const int32_t hidden_offset,
                                      int8_t *output_state,
                                      int16_t *cell_gate_scratch);


#ifdef __cplusplus
}
#endif

#endif
