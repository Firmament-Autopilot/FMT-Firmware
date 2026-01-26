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


#ifndef _CY_NN_TYPES_H
#define _CY_NN_TYPES_H


#include <stdint.h>

/** Enum for specifying activation function types */
typedef enum cy_nn_activation_type_s
{
    CY_NN_SIGMOID = 0, /**< Sigmoid activation function */
    CY_NN_TANH = 1,    /**< Tanh activation function */
} cy_nn_activation_type;


/**  LSTM specific input parameters related to dimensions */
typedef struct cy_nn_lstm_dims_s
{
    int32_t max_time;
    int32_t num_inputs;
    int32_t num_batches;
    int32_t num_outputs;
} cy_nn_lstm_dims;


/** LSTM scratch buffer container */
typedef struct cy_nn_lstm_context_s
{
    int16_t *input_gate;
    int16_t *forget_gate;
    int16_t *cell_gate;
    int16_t *output_gate;
    int16_t *tmp_gate_buf;
} cy_nn_lstm_context;


/** Parameters for quantization parameters */
typedef struct cy_nn_lstm_scaling_s
{
#if 0 // ORIGINAL CMSIS-NN
    int32_t multiplier; /**< Multiplier value */
    int32_t shift;      /**< Shift value */
#endif
    float scale;
} cy_nn_scaling;

/** CMSIS-NN norm layer coefficients */
typedef struct cy_nn_layer_norm_s
{
    int16_t *input_weight;
    int16_t *forget_weight;
    int16_t *cell_weight;
    int16_t *output_weight;
} cy_nn_layer_norm;


/** Parameters for integer LSTM, as defined in TFLM */
typedef struct cy_nn_lstm_params_s
{
    int32_t time_major; /**< Nonzero (true) if first row of data is timestamps for input */
    cy_nn_scaling input_to_input_scaling;
    cy_nn_scaling input_to_forget_scaling;
    cy_nn_scaling input_to_cell_scaling;
    cy_nn_scaling input_to_output_scaling;
    cy_nn_scaling recurrent_to_input_scaling;
    cy_nn_scaling recurrent_to_forget_scaling;
    cy_nn_scaling recurrent_to_cell_scaling;
    cy_nn_scaling recurrent_to_output_scaling;
    
    cy_nn_scaling hidden_scaling;
#if 0 // UNUSED even in original CMSIS-NN
    cy_nn_scaling cell_to_input_scaling;
    cy_nn_scaling cell_to_forget_scaling;
    cy_nn_scaling cell_to_output_scaling;
    cy_nn_scaling projection_scaling;
    cy_nn_scaling layer_norm_input_scaling;  /**< layer normalization for input layer */
    cy_nn_scaling layer_norm_forget_scaling; /**< layer normalization for forget gate */
    cy_nn_scaling layer_norm_cell_scaling;   /**< layer normalization for cell */
    cy_nn_scaling layer_norm_output_scaling; /**< layer normalization for output layer */
#endif

    int32_t cell_state_shift;
    int32_t hidden_offset;
    int32_t output_state_offset;
    int32_t input_offset;

#if 0 // ORIGINAL CMSIS-NN 
       // NNLite can handle zero points and bias on the fly
    /* Effective bias is precalculated as bias + zero_point * weight.
    Only applicable to when input/output are s8 and weights are s16 */
    const int32_t *i2i_effective_bias; /**< input to input effective bias */
    const int32_t *i2f_effective_bias; /**< input to forget gate effective bias */
    const int32_t *i2c_effective_bias; /**< input to cell effective bias */
    const int32_t *i2o_effective_bias; /**< input to output effective bias */

    const int32_t *r2i_effective_bias; /**< recurrent gate to input effective bias */
    const int32_t *r2f_effective_bias; /**< recurrent gate to forget gate effective bias */
    const int32_t *r2c_effective_bias; /**< recurrent gate to cell effective bias */
    const int32_t *r2o_effective_bias; /**< recurrent gate to output effective bias */

    const int32_t *projection_effective_bias;
#endif
    /* Not precalculated bias */
    const int32_t *input_gate_bias;
    const int32_t *forget_gate_bias;
    const int32_t *cell_gate_bias;
    const int32_t *output_gate_bias;


} cy_nn_lstm_params;



#endif //_CY_NN_TYPES_H
