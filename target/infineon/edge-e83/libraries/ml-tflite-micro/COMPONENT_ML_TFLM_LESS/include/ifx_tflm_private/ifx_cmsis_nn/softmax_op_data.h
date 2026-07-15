/* Copyright 2022 The TensorFlow Authors. All Rights Reserved.

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

#ifndef IFX_TFLM_PRIVATE_IFX_CMSIS_NN_SOFTMAX_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_CMSIS_NN_SOFTMAX_OP_DATA_H_

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
// Needed for SoftmaxParams
#include "tensorflow/lite/kernels/internal/types.h"

namespace tflite {
namespace ops {
namespace micro {
namespace softmax {

struct OpData;

#define EVAL_FUNC_DECL(name) \
  TfLiteStatus name( \
    const TfLiteEvalTensor* input, TfLiteEvalTensor* output,  \
    const OpData& op_data)

typedef EVAL_FUNC_DECL((*EvalVariantFptr));

EVAL_FUNC_DECL(SoftmaxFloat);
EVAL_FUNC_DECL(SoftmaxQuantizedInt8);
EVAL_FUNC_DECL(SoftmaxQuantizedInt8OutInt16);
EVAL_FUNC_DECL(SoftmaxQuantizedInt16);

#undef EVAL_FUNC_DECL


struct OpData {
  SoftmaxParams ref_op_data;
  int32_t num_rows;
  int32_t row_size;

  // Eval function pointer
  EvalVariantFptr eval_function;
};


}  // namespace softmax
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif  // IFX_TFLM_PRIVATE_IFX_CMSIS_NN_SOFTMAX_OP_DATA_H_