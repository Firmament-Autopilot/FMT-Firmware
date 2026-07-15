/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_OPS_H_
#define IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_OPS_H_

#include "ifx_fast/fully_connected/fully_connected_op_data.h"
#include "tensorflow/lite/kernels/internal/common.h"
#include "tensorflow/lite/kernels/internal/cppmath.h"
#include "tensorflow/lite/kernels/internal/quantization_util.h"
#include "tensorflow/lite/kernels/internal/types.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/micro/kernels/kernel_util.h"
#include "tensorflow/lite/kernels/kernel_util.h"
#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/kernels/internal/reference/fully_connected.h"
#include "tensorflow/lite/kernels/internal/reference/integer_ops/fully_connected.h"

#if IFX_DEBUG_LOGGING
#include <iostream>
#endif


namespace tflite {
namespace ops {
namespace micro {
namespace fully_connected {

template <typename T>
TfLiteStatus EvalQuantized(TfLiteContext* context,
                           TfLiteFullyConnectedParams* params, OpData* opData,
                           const TfLiteEvalTensor* input,
                           const TfLiteEvalTensor* weights,
                           const TfLiteEvalTensor* bias, TfLiteEvalTensor* output) {
  // Get input info
  const T* input_data = tflite::micro::GetTensorData<T>(input);

  // Get weights info
  const T* weights_data = tflite::micro::GetTensorData<T>(weights);
  const int32_t weights_offset = -opData->weights_zero_point;
  RuntimeShape weights_shape = tflite::micro::GetTensorShape(weights);
  TFLITE_DCHECK_GE(weights_shape.DimensionsCount(), 2);
  const int weights_dim_count = weights_shape.DimensionsCount();
  const int accum_depth = weights_shape.Dims(weights_dim_count - 1);

  // Get output info
  T* output_data = tflite::micro::GetTensorData<T>(output);
  const int32_t output_offset = opData->output_zero_point;
  RuntimeShape output_shape = tflite::micro::GetTensorShape(output);
  TFLITE_DCHECK_EQ(output_shape.DimensionsCount(), 2);
  const int32_t output_multiplier = opData->output_multiplier;
  const int output_shift = -opData->output_shift;
  const int32_t output_activation_min = opData->output_activation_min;
  const int32_t output_activation_max = opData->output_activation_max;
  TFLITE_DCHECK_LE(output_activation_min, output_activation_max);
  const int batches = output_shape.Dims(0);
  const int output_depth = output_shape.Dims(1);
  TFLITE_DCHECK_LE(output_depth, weights_shape.Dims(weights_dim_count - 2));

#if IFX_DEBUG_LOGGING
  std::cout << "Unpacked implementation!: weights_offset = " << std::dec << weights_offset << std::endl;
#endif

  // Get factor pre-computed in the Prepare-phase
  const int32_t* sum_of_weights_factor = opData->sum_of_weights_factor;

  for (int b = 0; b < batches; ++b) {
    // Pre-compute factor for this output-batch
    int32_t sum_of_inputs_factor = 0;
    if (weights_offset != 0) {
      for (int d = 0; d < accum_depth; ++d) {
        sum_of_inputs_factor += input_data[d];
      }
      sum_of_inputs_factor *= weights_offset;
    }
    // Calculate output-nodes using pre-computed factors
    KernelCore<T>::run(output_data, input_data, weights_data,
                         sum_of_weights_factor, sum_of_inputs_factor,
                         accum_depth, output_depth, output_offset,
                         output_multiplier, output_shift, output_activation_min,
                         output_activation_max);
    output_data += output_depth;
    input_data += accum_depth;
  }
  return kTfLiteOk;
}

TfLiteStatus EvalQuantizedInt8(TfLiteContext* context,
                               TfLiteFullyConnectedParams* params,
                               OpData* opData, const TfLiteEvalTensor* input,
                               const TfLiteEvalTensor* weights,
                               const TfLiteEvalTensor* bias, TfLiteEvalTensor* output) {
  return EvalQuantized<int8_t>(context, params, opData, input, weights, bias,
                               output);
}

TfLiteStatus EvalFloat(TfLiteContext* context,
                       TfLiteFullyConnectedParams* params, OpData* opData,
                       const TfLiteEvalTensor* input, const TfLiteEvalTensor* weights,
                       const TfLiteEvalTensor* bias, TfLiteEvalTensor* output) {
  float output_activation_min, output_activation_max;
  CalculateActivationRange(params->activation, &output_activation_min,
                           &output_activation_max);
  tflite::FullyConnectedParams op_params;
  op_params.float_activation_min = output_activation_min;
  op_params.float_activation_max = output_activation_max;
  const float* bias_data =
    bias ? tflite::micro::GetTensorData<float>(bias) : nullptr;
  tflite::reference_ops::FullyConnected(
      op_params, tflite::micro::GetTensorShape(input), tflite::micro::GetTensorData<float>(input),
      tflite::micro::GetTensorShape(weights), tflite::micro::GetTensorData<float>(weights),
      tflite::micro::GetTensorShape(bias), bias_data, tflite::micro::GetTensorShape(output),
      tflite::micro::GetTensorData<float>(output));
  return kTfLiteOk;
}

}  // fully_connected
}  // namespace micro
}  // namespace ops
}  // namespace tflite


#endif /* IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_OPS_H_ */
