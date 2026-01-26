/*
 * SPDX-FileCopyrightText: Copyright 2023 Infineon Technologies AG
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

/* ----------------------------------------------------------------------
 * Project:      CMSIS NN Library
 * Title:        cy_nn_lstm_calculate_gate_s8_s16.c
 * Description:  Update single gate for an incremental step of LSTM function.
 *
 * $Date:        8 September 2022
 * $Revision:    V.1.0.0
 *
 * Target Processor:  Cortex-M cores
 *
 * -------------------------------------------------------------------- */


#include "cy_nn_kernel.h"
#if CY_IP_MXNNLITE_VERSION != 1
#include "cy_nnsupportfunctions.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


cy_en_nnlite_status_t
cy_nnlite_fc_s8_s16(const int8_t *input,
                    const int32_t input_offset,
                    const int8_t *weights,
                    const int32_t *bias,
                    int16_t *output,
                    float output_scale,
                    const int32_t n_input,
                    const int32_t n_output,
                    const int32_t n_batch)
{    
    cy_en_nnlite_status_t status;                    
    cy_nn_dims_t input_dims = {{n_batch, n_input}};
    cy_nn_dims_t output_dims = {{n_batch, n_output}};
    cy_nn_dims_t filter_dims = {{n_output, n_input}};
    cy_nn_fc_params_t fc_param;
    fc_param.inputOffset = input_offset;
    fc_param.filterOffset = 0;
    fc_param.outputOffset = 0;
    fc_param.outScalingFactor = output_scale;
    fc_param.outClipping.min = INT16_MIN;
    fc_param.outClipping.max = INT16_MAX;
    fc_param.inputSize = CY_NNLITE_ACTIVATION_8BIT;
    fc_param.outputSize = CY_NNLITE_OUTPUT_16BIT;
    fc_param.sparseWeights = false;

    status =
        Cy_NNLite_FullyConnected(input, (int8_t *)output, 
                &input_dims, &output_dims, &filter_dims, 
                weights, bias, 
                &fc_param, CY_NNLITE_ACTIVATION_NONE, NULL);
    return status;
}



/*
 * Calculates a single LSTM gate, int8x8_16 version.
 * Refer to header file for details
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
                                       int16_t *tmp_gate_buf)
{
    const int32_t n_block = n_batch * n_cell;
    // Note: with only 16-bit accumulation this factoring of LSTM is prone overflow.
    //  If we simply compute a FC on concatenated input and output_state values (as in the
    // "classic"presentation of LSTM ... these values are narrower than the cell state... this would no occur.

#if 0 // ORIGINAL CMSIS-NN
    memset(gate, 0, 2*n_block * sizeof(int16_t));
    arm_nn_vec_mat_mul_result_acc_s8(input,
                                     input_to_gate_weights,
                                     input_to_gate_bias,
                                     gate,
                                     0,
                                     input_to_gate_scaling.multiplier,
                                     input_to_gate_scaling.shift,
                                     n_input,
                                     n_cell,
                                     n_batch);
#endif
    cy_en_nnlite_status_t status =
        cy_nnlite_fc_s8_s16(input,
                            input_offset,
                            input_to_gate_weights,
                            input_to_gate_bias,
                            gate,
                            input_to_gate_scaling.scale,
                            n_input,
                            n_cell,
                            n_batch);
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }


#if 0 // ORIGINAL CMSIS-NN
    arm_nn_vec_mat_mul_result_acc_s8(output_state,
                                     recurrent_to_gate_weights,
                                     recurrent_to_gate_bias,
                                     gate,
                                     0, 
                                     recurrent_to_gate_scaling.multiplier,
                                     recurrent_to_gate_scaling.shift,
                                     n_output,
                                     n_cell,
                                     n_batch);
#endif
    status =
        cy_nnlite_fc_s8_s16(output_state,
                            output_state_offset,
                            recurrent_to_gate_weights,
                            NULL, //  TFLM etc don't include a recurrent_to_gate_bias,
                            tmp_gate_buf,
                            recurrent_to_gate_scaling.scale,
                            n_output,
                            n_cell,
                            n_batch);    
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }



    // Fused addition of partial sums and application of activation function so at least
    // overflow in the summation can't happen (NNLite has 64-bit accumulators)
        
    cy_nn_dims_t inoutDims = {{1,1,1,n_block}};

    cy_en_nnlite_fused_activation_t nnlite_activation = CY_NNLITE_ACTIVATION_NONE;
    
    switch( activation_type) {
        case CY_NN_SIGMOID:
            nnlite_activation = CY_NNLITE_ACTIVATION_SIGMOID;
            break;
        case CY_NN_TANH:
            nnlite_activation = CY_NNLITE_ACTIVATION_TANH;
            break;
        default:
            abort();
    }

    // Scale fields not need as we're using the common scaling parameters...
    cy_nn_pwise_binary_params_t add_params;
    add_params.lhsOffset = 0;   
    add_params.rhsOffset = 0;     
    add_params.outputOffset = 0;        
    add_params.outClipping.min = INT16_MIN;
    add_params.outClipping.max = INT16_MAX;
    add_params.inputSize = CY_NNLITE_ACTIVATION_16BIT;      
    add_params.outputSize = CY_NNLITE_OUTPUT_16BIT;

    // For now we're following CMSIS-NN and with tanh/sigmoid
    // being provided with Q3.12 inputs and producing Q.15 outputs
    const float act_in_scale = 1.0f/(float)(1<<12);
    const float act_out_scale = 1.0f/(1<<15);
    status = 
        Cy_NNLite_Scaling_Setup( &add_params.scaling, act_in_scale, act_in_scale, act_out_scale, 
                                CY_NNLITE_ACTIVATION_16BIT, 
                                CY_NNLITE_ADD,
                                nnlite_activation
                                );
                                
    if(status != CY_NNLITE_SUCCESS) {
        return status;
    }
    status = 
        Cy_NNLite_AddSubMul((const int8_t *)gate, (const int8_t*)tmp_gate_buf, 
                        (int8_t *)gate,
                        &inoutDims, &inoutDims, &add_params,
                        CY_NNLITE_ADD, nnlite_activation);




#if 0 // ORIGINAL CMSIS-NN

    // Not really documented by ARM but expects Q3.12 input and produces
    // Q.15 output
    arm_nn_activation_s16(gate, gate, n_block, 0, activation_type);

    if (status == CY_NNLITE_SUCCESS) {
        int i;
        static const char *type_name[2] = { "sigmoid", "tanh"};

        for (i=0; i < n_cell; ++i) {
            if ( abs(gate[i]-gate[i+n_block]) > 1) {
                double ref = gate[i]/(double)(1<<15); // Q.15
                double tst = gate[i+n_block]/(double)(1<<15); // Q.15
                printf( "%02d: %s expected %g (%04x) got %g (%04x)\n", i, type_name[activation_type], ref, gate[i] & 0xffff, tst, gate[i+n_block]&0xffff );
                status = CY_NNLITE_BAD_PARAM;
            }
            gate[i] = gate[i+n_block];
        }
    }
#endif
    return status;
}

#endif //CY_IP_MXNNLITE_VERSION
