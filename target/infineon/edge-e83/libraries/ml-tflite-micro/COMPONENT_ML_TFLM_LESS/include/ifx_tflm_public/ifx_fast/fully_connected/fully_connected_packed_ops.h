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

#ifndef IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_PACKED_OPS_H_
#define IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_PACKED_OPS_H_

#include "ifx_fast/fully_connected/fully_connected_op_data.h"
#include "tensorflow/lite/kernels/internal/common.h"
#include "tensorflow/lite/kernels/internal/cppmath.h"
#include "tensorflow/lite/kernels/internal/quantization_util.h"
#include "tensorflow/lite/kernels/internal/types.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/micro/kernels/kernel_util.h"
#include "tensorflow/lite/c/builtin_op_data.h"
#include "ifx_common/kernel_primitives.h"

namespace tflite {
namespace ops {
namespace micro {
namespace fully_connected {



//
//  Quantized fully connect kernel for < 8-bit packed weights
// "little-endian" format (first weight in LSB) ordering assumed.
//
// TODO Use specializations to handle fast case where dimensions
// allow efficient loop-unroll etc.
// accum_container_depth should really be  a params value
//

template <typename QUANT_VALUE_T, typename CONTAINER_T, size_t bits_per_item, size_t items_per_container>
void EvaluatePacked(
        const FullyConnectedParams& params, OpData *data,
        const RuntimeShape& input_shape, const QUANT_VALUE_T* input_data,
        const RuntimeShape& weights_shape, const CONTAINER_T* weights_data,
        const RuntimeShape& bias_shape, const int32_t* bias_data,
        const RuntimeShape& output_shape, QUANT_VALUE_T* output_data ) {

  const int32_t weights_offset = params.weights_offset;
  const int32_t output_offset = params.output_offset;
  const int32_t output_multiplier = params.output_multiplier;
  const int output_shift = params.output_shift;
  const int32_t output_activation_min = params.quantized_activation_min;
  const int32_t output_activation_max = params.quantized_activation_max;
  TFLITE_DCHECK_GE(weights_shape.DimensionsCount(), 2);
  TFLITE_DCHECK_GE(output_shape.DimensionsCount(), 1);
  TFLITE_DCHECK_LE(output_activation_min, output_activation_max);


  const int output_dim_count = output_shape.DimensionsCount();
  const int weights_dim_count = weights_shape.DimensionsCount();
  const int batches = FlatSizeSkipDim(output_shape, output_dim_count - 1);
  const unsigned int output_depth = MatchingDim(weights_shape, weights_dim_count - 2,
                                       output_shape, output_dim_count - 1);
  const unsigned int accum_depth = weights_shape.Dims(weights_dim_count - 1);
  const unsigned int weights_size = weights_shape.FlatSize();
#if IFX_DEBUG_LOGGING
  std::cout << "Packed implementation!: bits_per_item = " << std::dec << bits_per_item << std::endl;
  std::cout << "Packed implementation!: accum-depth = " << std::dec << accum_depth << std::endl;
#endif

  int32_t acc;
  const TfLiteCustomSub8BitPackingDetails *custom = data->custom_sub8bit_packing;
  const int32_t *sum_of_weights_factor = data->sum_of_weights_factor;

  for (int b = 0; b < batches; ++b) {

    // Pre-compute factor for this output-batch
    int32_t sum_of_inputs_factor = 0;
    if (weights_offset != 0) {
      for (unsigned int d = 0; d < accum_depth; ++d) {
        sum_of_inputs_factor += input_data[d];
      }
      sum_of_inputs_factor *= weights_offset;
    }

    PackedWeightUnpacker pw(reinterpret_cast<const int8_t*>(weights_data),
                                        weights_size, output_depth, custom);

    for (unsigned int out_c = 0; out_c < output_depth; ++out_c) {

      // Factors folding in bias, and products of offsets with inputs / weights.
      acc = sum_of_weights_factor[out_c] + sum_of_inputs_factor;
      for (unsigned int d = 0; d < accum_depth; ++d) {
        int32_t input_val = input_data[b * accum_depth + d];
        int32_t weights_val = 0;
        if( pw.skippedZero() ) {
          continue;
        }
        else {
          weights_val = pw.unpack<CONTAINER_T, bits_per_item>();
        }
#if IFX_DEBUG_LOGGING
        std::cout <<  std::dec << input_val << "*" << weights_val << ", ";
#endif

        acc += weights_val * input_val;
      }

#if IFX_DEBUG_LOGGING
      std::cout << "RAW ACC " << acc << std::endl;
#endif
      acc = MultiplyByQuantizedMultiplier(acc, output_multiplier, output_shift);
      acc += output_offset;
      acc = std::max(acc, output_activation_min);
      acc = std::min(acc, output_activation_max);
      output_data[out_c + output_depth * b] = static_cast<QUANT_VALUE_T>(acc);
    }
  }
}

template <typename CONTAINER_T, size_t bits_per_item,
          size_t items_per_container>
TfLiteStatus
PackedFullyConnectedInt8<CONTAINER_T, bits_per_item, items_per_container>::
    EvalInt8PackedWeights(TfLiteContext* context,
                           TfLiteFullyConnectedParams* params, OpData* opData,
                           const TfLiteEvalTensor* input,
                           const TfLiteEvalTensor* weights,
                           const TfLiteEvalTensor* bias, TfLiteEvalTensor* output) {
  const RuntimeShape& input_shape = tflite::micro::GetTensorShape(input);
  auto input_data = tflite::micro::GetTensorData<int8_t>(input);
  const RuntimeShape& filter_shape = tflite::micro::GetTensorShape(weights);
  auto filter_data = tflite::micro::GetTensorData<CONTAINER_T>(weights);
  const RuntimeShape& bias_shape = tflite::micro::GetTensorShape(bias);
  auto bias_data = bias ? tflite::micro::GetTensorData<int32_t>(bias) : nullptr;
  const RuntimeShape& output_shape = tflite::micro::GetTensorShape(output);
  auto output_data = tflite::micro::GetTensorData<int8_t>(output);

  tflite::FullyConnectedParams op_params;
  op_params.input_offset = -opData->input_zero_point;
  op_params.weights_offset = -opData->weights_zero_point;
  op_params.output_offset = opData->output_zero_point;
  op_params.output_multiplier = opData->output_multiplier;
  // Legacy ops used mixed left and right shifts. Now all are +ve-means-left.
  op_params.output_shift = -opData->output_shift;
  op_params.quantized_activation_min = opData->output_activation_min;
  op_params.quantized_activation_max = opData->output_activation_max;

  EvaluatePacked<int8_t, CONTAINER_T, bits_per_item, items_per_container>(
      op_params, opData, input_shape, input_data, filter_shape, filter_data,
      bias_shape, bias_data, output_shape, output_data);
  return kTfLiteOk;
}

template class PackedFullyConnectedInt8<int8_t, 4, 8 / 4>;

template class PackedFullyConnectedInt8<int16_t, 5, 16 / 5>;

template class PackedFullyConnectedInt8<int32_t, 6, 32 / 6>;

template class PackedFullyConnectedInt8<int8_t, 8, 8 / 8>;

}  // fully_connected
}  // namespace micro
}  // namespace ops
}  // namespace tflite


#endif  // IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_PACKED_OPS_H_
