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


#ifndef IFX_TFLM_PRIVATE_IFX_CMSIS_NN_UNIDIRECTIONAL_SEQUUENCE_LSTM_COMMON_H_
#define IFX_TFLM_PRIVATE_IFX_CMSIS_NN_UNIDIRECTIONAL_SEQUUENCE_LSTM_COMMON_H_

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/kernels/internal/common.h"
#include "tensorflow/lite/kernels/internal/quantization_util.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/kernels/kernel_util.h"
#include "tensorflow/lite/micro/kernels/kernel_util.h"
#include "tensorflow/lite/micro/kernels/micro_tensor_utils.h"
#include "tensorflow/lite/micro/kernels/lstm_eval.h"
#include "tensorflow/lite/micro/kernels/lstm_shared.h"
#include "unidirectional_sequence_lstm_op_data.h"
#include "ifx_common/kernel_primitives.h"
#include "ifx_common/offline_prepare_utils.h"
#include "tensorflow/lite/kernels/internal/types.h"


namespace tflite {


namespace micro {
    class CppItems;
}

namespace ops {
namespace micro {
namespace lstm {


void* Init(TfLiteContext* context, const char* buffer, size_t length);

/**
 * @brief OpData initialization common to  our optimized and the reference kernels.
 * 
 * @param context 
 * @param node 
 * @param op_data 
 * @return TfLiteStatus 
 */
TfLiteStatus LSTMPrepareCommon(TfLiteContext* context, TfLiteNode* node, OpData* op_data);

/**
 * @brief Record Opdata struct for offline pre-interpreter
 * 
 * @param od 
 * @return tflite::micro::CppItems* 
 */
tflite::micro::CppItems* record_opuserdata(OpData& od);


/**
 * @brief Preprare for registration of tflite-micro reference implementation
 * 
 * @param context 
 * @param node 
 * @return TfLiteStatus 
 */
TfLiteStatus PrepareCommon(TfLiteContext* context, TfLiteNode* node);


TfLiteStatus Eval(TfLiteContext* context, TfLiteNode* node);

} // namespace lstm
} // namespace micro
} // namespace ops
} // namespace tflite

#endif // IFX_TFLM_PRIVATE_IFX_CMSIS_NN_UNIDIRECTIONAL_SEQUUENCE_LSTM_COMMON_H_
