/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

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

#ifndef IFX_TFLM_PRIVATE_IFX_CMSIS_NN_ADDSUB_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_CMSIS_NN_ADDSUB_OP_DATA_H_


#include "tensorflow/lite/c/builtin_op_data.h"

namespace tflite {
namespace ops {
namespace micro {
namespace addsub {

struct OpData;

#define EVAL_FUNC_DECL(name) \
  TfLiteStatus name(TfLiteContext* context, TfLiteNode* node,\
                    TfLiteAddParams* params, const OpData* data,\
                    const TfLiteEvalTensor* input1,\
                    const TfLiteEvalTensor* input2,\
                    TfLiteEvalTensor* output)

typedef EVAL_FUNC_DECL((*EvalVariantFptr)) ;

EVAL_FUNC_DECL(EvalAddQuantizedInt8);
EVAL_FUNC_DECL(EvalAddQuantizedInt16);
EVAL_FUNC_DECL(EvalAddInt32);
EVAL_FUNC_DECL(EvalAddFloat);

EVAL_FUNC_DECL(EvalSubQuantizedInt8);
EVAL_FUNC_DECL(EvalSubQuantizedInt16);
EVAL_FUNC_DECL(EvalSubInt32);
EVAL_FUNC_DECL(EvalSubFloat);

#undef EVAL_FUNC_DECL

struct OpData {
  bool requires_broadcast;

  // These fields are used in both the general 8-bit -> 8bit quantized path,
  // and the special 16-bit -> 16bit quantized path
  int input1_shift;
  int input2_shift;
  int32_t output_activation_min;
  int32_t output_activation_max;

  // These fields are used only in the general 8-bit -> 8bit quantized path
  int32_t input1_multiplier;
  int32_t input2_multiplier;
  int32_t output_multiplier;
  int output_shift;
  int left_shift;
  int32_t input1_offset;
  int32_t input2_offset;
  int32_t output_offset;

  // Used only for float evals:
  float output_activation_min_f32;
  float output_activation_max_f32;

  // Eval function pointer
  EvalVariantFptr eval_function;
};

}  // namespace addsub
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif // IFX_TFLM_PRIVATE_IFX_CMSIS_NN_ADDSUB_OP_DATA_H_
