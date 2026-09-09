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

#ifndef IFX_TFLM_PRIVATE_IFX_CMSIS_NN_POOLING_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_CMSIS_NN_POOLING_OP_DATA_H_

#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/kernels/pooling.h"

namespace tflite {
namespace ops {
namespace micro {
namespace pooling {

struct OpData;

#define EVAL_FUNC_DECL(name) \
  TfLiteStatus name( \
                    TfLiteContext* context, const TfLiteNode* node,    \
                    const TfLitePoolParams* params, const OpData& data,\
                    const TfLiteEvalTensor* input, TfLiteEvalTensor* output)

typedef EVAL_FUNC_DECL((*EvalVariantFptr));

EVAL_FUNC_DECL(AverageEvalQuantized);
EVAL_FUNC_DECL(AverageFloat);
EVAL_FUNC_DECL(MaxEvalQuantized);
EVAL_FUNC_DECL(MaxFloat);

#undef EVAL_FUNC_DECL


struct OpData {
  OpDataPooling reference_op_data;

  // Index to buffer for optimizations if applicable.
  int buffer_idx;

  // Eval function pointer
  EvalVariantFptr eval_function;
};

}  // namespace fully_connected
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif  // IFX_TFLM_PRIVATE_IFX_CMSIS_NN_POOLING_OP_DATA_H_