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

#ifndef IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_OP_DATA_H_
#define IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_OP_DATA_H_

#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/c/builtin_op_data.h"

namespace tflite {
namespace ops {
namespace micro {
namespace fully_connected {

struct OpData;

 typedef TfLiteStatus (*EvalVariantFptr)(TfLiteContext* context, TfLiteFullyConnectedParams* params,
      OpData* opData, const TfLiteEvalTensor* input, const TfLiteEvalTensor* weights,
      const TfLiteEvalTensor* bias, TfLiteEvalTensor* output);

#define EVAL_FUNC(name) \
  TfLiteStatus name( \
    TfLiteContext* context, TfLiteFullyConnectedParams* params, OpData* opData, \
    const TfLiteEvalTensor* input, const TfLiteEvalTensor* weights, \
    const TfLiteEvalTensor* bias, TfLiteEvalTensor* output)

EVAL_FUNC(EvalQuantizedInt8);
EVAL_FUNC(EvalFloat);
EVAL_FUNC(EvalSparseInt8);

template <typename CONTAINER_T, size_t bits_per_item,
            size_t items_per_container>
class PackedFullyConnectedInt8 {
 public:
  static EVAL_FUNC(EvalInt8PackedWeights);
};



#undef EVAL_FUNC

struct OpData {
  // The scaling factor from input to output (aka the 'real multiplier') can
  // be represented as a fixed point multiplier plus a left shift.
  int32_t output_multiplier;
  int output_shift;
  // The range of the fused activation layer. For example for kNone and
  // uint8_t these would be 0 and 255.
  int32_t output_activation_min;
  int32_t output_activation_max;
  // The index of the temporary tensor where the quantized inputs are cached.
  int input_quantized_index;
  // A buffer containing the sum-of-weights factor
  int32_t* sum_of_weights_factor;
  int32_t weights_zero_point;
  int32_t input_zero_point;
  int32_t output_zero_point;

  // Weights tensor packing information
  const TfLiteCustomSub8BitPackingDetails *custom_sub8bit_packing;

  // Eval function pointer
  EvalVariantFptr eval_function;
};

}  // namespace fully_connected
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif // IFX_TFLM_PUBLIC_IFX_FAST_FULLY_CONNECTED_FULLY_CONNECTED_OP_DATA_H_
