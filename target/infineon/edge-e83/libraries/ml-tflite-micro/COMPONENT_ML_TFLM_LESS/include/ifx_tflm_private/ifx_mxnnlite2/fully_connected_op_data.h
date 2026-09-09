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

#ifndef IFX_TFLM_PRIVATE_IFX_MXNNLITE_FULLY_CONNECTED_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_MXNNLITE_FULLY_CONNECTED_OP_DATA_H_

namespace tflite {
namespace ops {
namespace micro {
namespace fully_connected {

struct OpDataMXNNLiteExt {
  float mxnnlite_scaler;
};


}  // namespace fully_connected
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#define IFX_CMSIS_NN_EXTENDED_OP_DATA_FC OpDataMXNNLiteExt

#include "ifx_cmsis_nn/fully_connected_op_data.h"

namespace tflite {
namespace ops {
namespace micro {
namespace fully_connected {

TfLiteStatus EvalQuantizedInt8NNLite(TfLiteContext* context, TfLiteNode* node,
                               const OpData& data, const TfLiteEvalTensor* input,
                               const TfLiteEvalTensor* filter, const TfLiteEvalTensor* bias,
                               TfLiteEvalTensor* output);


}  // namespace fully_connected
}  // namespace micro
}  // namespace ops
}  // namespace tflite




#endif // IFX_TFLM_PRIVATE_IFX_MXNNLITE_CONV_OP_DATA_H_
