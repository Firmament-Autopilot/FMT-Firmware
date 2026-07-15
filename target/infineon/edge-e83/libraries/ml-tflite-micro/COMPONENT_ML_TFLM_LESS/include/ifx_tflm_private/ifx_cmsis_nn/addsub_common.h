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

/**
 * @brief Declaration common functions for add/sub ops
 * 
 * Factored seperately as they are shared for SW add/sub
 * and SW fallback for accelerate add implementations.
 * 
 */

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/kernels/internal/quantization_util.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/kernels/kernel_util.h"
#include "tensorflow/lite/kernels/op_macros.h"
#include "tensorflow/lite/micro/kernels/kernel_util.h"
#include "tensorflow/lite/micro/memory_helpers.h"
#include "ifx_cmsis_nn/addsub_op_data.h"

#if TF_LITE_MICRO_RECORD_OP_USER_DATA
#include "tflite_u_preint/static_data_utils.h"
#endif


namespace tflite {
namespace ops {
namespace micro {
namespace addsub {

constexpr int kInputTensor1 = 0;
constexpr int kInputTensor2 = 1;
constexpr int kOutputTensor = 0;



#if TF_LITE_MICRO_RECORD_OP_USER_DATA
tflite::micro::CppItems* record_opuserdata(const OpData& od);
#endif

TfLiteStatus CalculateOpData(TfLiteContext* context, TfLiteAddParams* params,
                             const TfLiteTensor* input1,
                             const TfLiteTensor* input2, TfLiteTensor* output,
                             OpData* data);

void UpdateOpParams(tflite::ArithmeticParams* const op_params,
                    const OpData* data);



TfLiteStatus EvalAddQuantizedInt8(TfLiteContext* context, TfLiteNode* node,
                              TfLiteAddParams* params, const OpData* data,
                              const TfLiteEvalTensor* input1,
                              const TfLiteEvalTensor* input2,
                              TfLiteEvalTensor* output);
							  
TfLiteStatus EvalAddQuantizedInt16(TfLiteContext* context, TfLiteNode* node,
                              TfLiteAddParams* params, const OpData* data,
                              const TfLiteEvalTensor* input1,
                              const TfLiteEvalTensor* input2,
                              TfLiteEvalTensor* output);

TfLiteStatus EvalSubFloat(TfLiteContext* context, TfLiteNode* node, TfLiteAddParams* params,
                    const OpData* data, const TfLiteEvalTensor* input1,
                    const TfLiteEvalTensor* input2, TfLiteEvalTensor* output);


TfLiteStatus EvalSubQuantizedInt8(TfLiteContext* context, TfLiteNode* node,
                              TfLiteAddParams* params, const OpData* data,
                              const TfLiteEvalTensor* input1,
                              const TfLiteEvalTensor* input2,
                              TfLiteEvalTensor* output);

TfLiteStatus EvalSubQuantizedInt16(TfLiteContext* context, TfLiteNode* node,
                              TfLiteAddParams* params, const OpData* data,
                              const TfLiteEvalTensor* input1,
                              const TfLiteEvalTensor* input2,
                              TfLiteEvalTensor* output);

TfLiteStatus EvalAddFloat(TfLiteContext* context, TfLiteNode* node, TfLiteAddParams* params,
                    const OpData* data, const TfLiteEvalTensor* input1,
                    const TfLiteEvalTensor* input2, TfLiteEvalTensor* output);



}  // namespace addsub
}  // namespace micro
}  // namespace ops



}  // namespace tflite
