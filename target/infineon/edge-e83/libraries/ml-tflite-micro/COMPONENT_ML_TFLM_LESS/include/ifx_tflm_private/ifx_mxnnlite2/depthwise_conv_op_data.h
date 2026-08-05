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

#ifndef IFX_TFLM_PRIVATE_IFX_MXNNLITE_DEPTHWISE_CONV_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_MXNNLITE_DEPTHWISE_CONV_OP_DATA_H_

namespace tflite {
namespace ops {
namespace micro {
namespace depthwise_conv {


/* A.Stevens 2022-06-20  ideally we'd just define an OpData sub-class
   for the ifx_cmsis_nn OpData class and be done here.  However, this
   is defeated by the need to support C++11 code-generation for static
   OpData tables.  If we have a base-class we no longer have an aggregate so
   initialization  via C style initializer lists will break.  Code re-use is
   also a MESS.  So the only workable way of avoid duplicating everything
   is a macro hack.
   */

struct MxNNLiteExtOpData {
  float* per_channel_mxnnlite_scaler;
  int32_t* depthwise_padded_bias;
};


}  // namespace depthwise_conv
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#define IFX_CMSIS_NN_EXTENDED_OP_DATA MxNNLiteExtOpData

#include "ifx_cmsis_nn/depthwise_conv_op_data.h"

#undef IFX_CMSIS_NN_EXTENDED_OP_DATA

namespace tflite {
namespace ops {
namespace micro {
namespace depthwise_conv {

bool MxNNLiteSupported(int output_zp, const TfLiteConvParams &conv_params);

TfLiteStatus EvalQuantizedPerChannelNNLite( 
    TfLiteContext* context, TfLiteNode* node, 
    const TfLiteDepthwiseConvParams& params, const OpData& data, 
    const TfLiteEvalTensor* input, const TfLiteEvalTensor* filter, 
    const TfLiteEvalTensor* bias, TfLiteEvalTensor* output);

TfLiteStatus EvalQuantizedPerChannelNNLiteCPU( 
    TfLiteContext* context, TfLiteNode* node, 
    const TfLiteDepthwiseConvParams& params, const OpData& data, 
    const TfLiteEvalTensor* input, const TfLiteEvalTensor* filter, 
    const TfLiteEvalTensor* bias, TfLiteEvalTensor* output);


}  // namespace depthwise_conv
}  // namespace micro
}  // namespace ops
}  // namespace tflite



#endif // IFX_TFLM_PRIVATE_IFX_MXNNLITE_DEPTHWISE_CONV_OP_DATA_H_
