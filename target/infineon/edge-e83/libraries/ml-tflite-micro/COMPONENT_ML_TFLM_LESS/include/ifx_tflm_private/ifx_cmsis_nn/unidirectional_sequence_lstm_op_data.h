/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

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

#ifndef IFX_TFLM_PRIVATE_IFX_CMSIS_NN_LSTM_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_CMSIS_NN_LSTM_OP_DATA_H_

#include "tensorflow/lite/c/common.h"
#include "arm_nn_types.h"
#include "tensorflow/lite/micro/kernels/lstm_eval.h"

namespace tflite {
namespace ops {
namespace micro {
namespace lstm {

struct OpData;

#define EVAL_FUNC_DECL(name) \
  TfLiteStatus name( \
    TfLiteContext* context, \
    TfLiteNode* node, \
    const OpData &op_data)

typedef EVAL_FUNC_DECL((*EvalVariantFptr));

template <typename ActivationType, typename WeightType,
        typename CellType, typename BiasType>
class LSTMTypes {
 public:
  static EVAL_FUNC_DECL(EvalLstmCmsisNN);
  static EVAL_FUNC_DECL(EvalRef);
};

#undef EVAL_FUNC_DECL

struct OpData {
  OpDataLSTM params_ref;

  // Weights tensor packing information
  const TfLiteCustomSub8BitPackingDetails *custom_sub8bit_packing;

  //scratch buffer to store unpacked weights for performance variant.
  int unpacked_weights_buff_idx;
  
  int num_out_per_slice;

  // Eval function pointer
  EvalVariantFptr eval_function;
};

} // namespace lstm
} // namespace micro
} // namespace ops
} // namespace tflite

#endif // IFX_TFLM_PRIVATE_IFX_CMSIS_NN_LSTM_OP_DATA_H_