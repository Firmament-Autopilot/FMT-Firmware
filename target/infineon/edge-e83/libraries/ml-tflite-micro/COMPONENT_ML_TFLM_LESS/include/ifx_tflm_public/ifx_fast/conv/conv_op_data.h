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

#ifndef IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_OP_DATA_H_
#define IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_OP_DATA_H_

#include "tensorflow/lite/c/common.h"

namespace tflite {
namespace ops {
namespace micro {
namespace conv {


struct OpData;

#define EVAL_FUNC_DECL(name) \
  TfLiteStatus name( \
      TfLiteConvParams* params, OpData* data, \
      const TfLiteEvalTensor* input, const TfLiteEvalTensor* filter, \
      const TfLiteEvalTensor* bias, TfLiteEvalTensor* output, TfLiteContext* context)

typedef EVAL_FUNC_DECL((*EvalVariantFptr));

EVAL_FUNC_DECL(EvalConvInt8);
EVAL_FUNC_DECL(IfxFastFloatRef);
EVAL_FUNC_DECL(EvalConvSparseInt8);
EVAL_FUNC_DECL(EvalConvInt8WithPadding);
EVAL_FUNC_DECL(EvalConvInt8WithoutPadding);


template <typename CONTAINER_T, size_t bits_per_item,
            size_t items_per_container>
class PackedConvPerChannel {
 public:
  static EVAL_FUNC_DECL(Eval);
};


template <typename ACT_TYPE, typename BIAS_TYPE>
class ConvPerChannelIntRef {
 public:
  static EVAL_FUNC_DECL(Eval);
};

#undef EVAL_FUNC_DECL


struct OpData {
  TfLitePaddingValues padding;
  // The scaling factor from input to output (aka the 'real multiplier') can
  // be represented as a fixed point multiplier plus a left shift.

  // Cached tensor zero point values for quantized operations.
  int32_t input_zero_point;
  int32_t filter_zero_point;
  int32_t output_zero_point;

  int32_t output_multiplier;
  int output_shift;

  // Per channel output multiplier and shift (allocated dynamically).
  int32_t *per_channel_output_multiplier;
  int32_t *per_channel_output_shift;

  // The range of the fused activation layer. For example for kNone and
  // uint8_t these would be 0 and 255.
  int32_t output_activation_min;
  int32_t output_activation_max;

  // The precomputed sum of filters factor
  int32_t *sum_of_filters_factor;

    // Weights tensor packing information
  const TfLiteCustomSub8BitPackingDetails *custom_sub8bit_packing;

  int unpacked_weights_buff_idx;

  // Eval function pointer
  EvalVariantFptr eval_function;
};



}  // namespace conv
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif // IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_OP_DATA_H_
