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

#ifndef IFX_TFLM_PRIVATE_IFX_MXNNLITE_POOLING_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_MXNNLITE_POOLING_OP_DATA_H_

#include "ifx_cmsis_nn/pooling_op_data.h"

namespace tflite {
namespace ops {
namespace micro {
namespace pooling {

TfLiteStatus AverageInt8Accel( 
                    TfLiteContext* context, const TfLiteNode* node,
                    const TfLitePoolParams* params, const OpData& data,
                    const TfLiteEvalTensor* input, TfLiteEvalTensor* output);

TfLiteStatus MaxInt8Accel(TfLiteContext* context, const TfLiteNode* node,
                          const TfLitePoolParams* params, const OpData& data,
                          const TfLiteEvalTensor* input,
                          TfLiteEvalTensor* output);

                          

}  // namespace fully_connected
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif  // IFX_TFLM_PRIVATE_IFX_CMSIS_NN_POOLING_OP_DATA_H_