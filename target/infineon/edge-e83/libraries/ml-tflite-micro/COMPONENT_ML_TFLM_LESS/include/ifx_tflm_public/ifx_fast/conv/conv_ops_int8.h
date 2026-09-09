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

#ifndef IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_OPS_H_
#define IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_OPS_H_



#include "tensorflow/lite/c/common.h"
#include "ifx_fast/conv/conv_op_data.h"
#include "ifx_fast/conv/conv_core.h"

namespace tflite {
namespace ops {
namespace micro {
namespace conv {



TfLiteStatus EvalConvInt8WithoutPadding(
    TfLiteConvParams* params, OpData* data,
    const TfLiteEvalTensor* input,
    const TfLiteEvalTensor* filter,
    const TfLiteEvalTensor* bias,
    TfLiteEvalTensor* output, TfLiteContext* context) {
  return EvalConvWithoutPadding<int8_t>(
      params, data, input, filter, bias, output, context);
}


TfLiteStatus EvalConvInt8WithPadding(
    TfLiteConvParams* params, OpData* data,
    const TfLiteEvalTensor* input,
    const TfLiteEvalTensor* filter,
    const TfLiteEvalTensor* bias,
    TfLiteEvalTensor* output, TfLiteContext* context) {
  return EvalConvWithPadding<int8_t>(
      params, data, input, filter, bias, output, context);
}


}  // namespace conv
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif /* IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_OPS_H_ */
