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

#ifndef IFX_TFLM_PRIVATE_IFX_CMSIS_NN_SVDF_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_CMSIS_NN_SVDF_OP_DATA_H_

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/micro_common.h"

#include "tensorflow/lite/micro/kernels/cmsis_nn/svdf_op_data.h"

namespace tflite {
namespace ops {
namespace micro {
namespace svdf {

struct IfxCmsisNnOpDataSvdf;

#define EVAL_FUNC_DECL(name) \
  TfLiteStatus name( \
    TfLiteContext* context, TfLiteNode* node,   \
    const TfLiteEvalTensor* input, const TfLiteEvalTensor* weights_feature, \
    const TfLiteEvalTensor* weights_time, const TfLiteEvalTensor* bias, \
    const TfLiteSVDFParams* params,  \
    TfLiteEvalTensor* activation_state, TfLiteEvalTensor* output,   \
    const CmsisNnOpDataSvdf& data)

typedef EVAL_FUNC_DECL((*EvalVariantFptr));

EVAL_FUNC_DECL(EvalFloatSVDF);
EVAL_FUNC_DECL(EvalInteger8SVDF);
EVAL_FUNC_DECL(EvalInteger16SVDF);


#undef EVAL_FUNC_DECL

struct IfxCmsisNnOpDataSvdf {
  CmsisNnOpDataSvdf common;


  // Eval function pointer
  EvalVariantFptr eval_function;
};


}  // namespace svdf
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif  // IFX_TFLM_PRIVATE_IFX_CMSIS_NN_SVDF_OP_DATA_H_