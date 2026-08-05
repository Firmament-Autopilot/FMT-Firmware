/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

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

#ifndef IFX_TFLM_PUBLIC_IFX_FAST_DEPTHWISE_CONV_DEPTHWISE_CONV_TESTING_REFS_H_
#define IFX_TFLM_PUBLIC_IFX_FAST_DEPTHWISE_CONV_DEPTHWISE_CONV_TESTING_REFS_H_

/*****
 * Reference implementations of "ifx_fast"  kernels supporting packed
 * sparse and sub-8=bit quantized weights.
 *
 *****/

#include "tensorflow/lite/kernels/internal/common.h"
#include "tensorflow/lite/kernels/internal/cppmath.h"
#include "tensorflow/lite/kernels/internal/quantization_util.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/kernels/internal/types.h"
#include "tensorflow/lite/micro/kernels/kernel_util.h"

#include "ifx_fast/depthwise_conv/depthwise_conv_impl.h"
#include "ifx_fast/depthwise_conv/depthwise_conv_op_data.h"
#include "ifx_fast/depthwise_conv/depthwise_conv_ops.h"
#include "ifx_fast/depthwise_conv/depthwise_conv_packed_ops.h"

namespace tflite {

namespace ops {
namespace micro {
namespace depthwise_conv {


TfLiteStatus DepthwisePrepareRef(TfLiteContext* context, TfLiteNode* node) {
#if !TF_LITE_MICRO_USE_OFFLINE_OP_USER_DATA
  
  OpData* data = static_cast<OpData*>(node->user_data);
  auto* params =
      reinterpret_cast<TfLiteDepthwiseConvParams*>(node->builtin_data);

  MicroContext* micro_context = GetMicroContext(context);

  TfLiteTensor* input =
      micro_context->AllocateTempInputTensor(node, kInputTensor);
  TF_LITE_ENSURE(context, input != nullptr);
  TfLiteTensor* filter =
      micro_context->AllocateTempInputTensor(node, kFilterTensor);
  TF_LITE_ENSURE(context, filter != nullptr);

  const TfLiteType data_type = input->type;
  int width = SizeOfDimension(input, 2);
  int height = SizeOfDimension(input, 1);
  int filter_width = SizeOfDimension(filter, 2);
  int filter_height = SizeOfDimension(filter, 1);
  data->sum_of_filters_factor = nullptr;

  data->per_channel_output_multiplier = nullptr;
  data->per_channel_output_shift = nullptr;
  if (filter->type == kTfLiteInt8) {
    // Per channel quantization is only needed for int8_t inference. For other
    // quantized types, only a single scale and zero point is needed.
    const int num_channels = filter->dims->data[kDepthwiseConvQuantizedDimension];
    // Dynamically allocate per-channel quantization parameters.
    data->per_channel_output_multiplier =
        static_cast<int32_t*>(TFLMC_CODE_GENERATED_BUFFER(
            context, num_channels * sizeof(int32_t)));
    TF_LITE_ENSURE(context, data->per_channel_output_multiplier != nullptr);

    data->per_channel_output_shift =
        static_cast<int32_t*>(TFLMC_CODE_GENERATED_BUFFER(
            context, num_channels * sizeof(int32_t)));
    TF_LITE_ENSURE(context, data->per_channel_output_shift != nullptr);
  }

  TF_LITE_ENSURE_STATUS(CalculateOpData(context, node, *params, width, height,
                                        filter_width, filter_height, data_type,
                                        data));

  data->custom_sub8bit_packing = nullptr;

  // Set the function pointer that is used during inference here
  switch (input->type) {  // Already know in/out types are same.
    case kTfLiteFloat32:
      data->eval_function = TFLMC_CAPTURED_OP_USER_DATA_FPTR(EvalFloat);
      break;
    case kTfLiteInt8: {
        data->eval_function =
            TFLMC_CAPTURED_OP_USER_DATA_FPTR(EvalInt8Reference);
      break;
    }
    default:
      TF_LITE_KERNEL_LOG(context, "Type %s (%d) not supported.",
                         TfLiteTypeGetName(input->type), input->type);
      return kTfLiteError;
  }
#endif // !TF_LITE_MICRO_USE_OFFLINE_OP_USER_DATA

#if TF_LITE_MICRO_RECORD_OP_USER_DATA
  tflite::micro::recordStaticOpdata(
                          "depthwise_conv",
                          record_opuserdata(
                              *data, 
                              SizeOfDimension(filter, 3))
                          );
#endif

#if !TF_LITE_MICRO_USE_OFFLINE_OP_USER_DATA
  micro_context->DeallocateTempTfLiteTensor(input);
  micro_context->DeallocateTempTfLiteTensor(filter);
#endif

  return kTfLiteOk;
}


} // namespace depthwise_conv
} // namespace micro
} // namespace ops
}  // namespace tflite

#endif /* IFX_TFLM_PUBLIC_IFX_FAST_DEPTHWISE_CONV_DEPTHWISE_CONV_TESTING_REFS_H_ */