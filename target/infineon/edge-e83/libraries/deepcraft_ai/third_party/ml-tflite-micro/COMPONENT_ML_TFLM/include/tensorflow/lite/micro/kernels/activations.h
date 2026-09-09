/* Copyright 2025 The TensorFlow Authors. All Rights Reserved.

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

#ifndef TENSORFLOW_LITE_MICRO_KERNELS_ACTIVATIONS_H_
#define TENSORFLOW_LITE_MICRO_KERNELS_ACTIVATIONS_H_

#include <cstdint>

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/kernels/internal/common.h"
#include "tensorflow/lite/kernels/internal/types.h"

namespace tflite {

extern const int kActivationsInputTensor;
extern const int kActivationsOutputTensor;

struct ReluFloatParams {
  float activation_min;
  float activation_max;
};



union ReluOpData {
    ReluParams params;
    ReluFloatParams flt_params;
};


template <typename T>
void ReluQuantized(const ReluParams& qnt_params, const RuntimeShape& input_shape,
                   const RuntimeShape& output_shape, const T* input_data,
                   T* output_data) {
  const int flat_size = MatchingFlatSize(input_shape, output_shape);
  for (int i = 0; i < flat_size; ++i) {
    const int32_t val = static_cast<int32_t>(input_data[i]);
    int32_t clamped =
        qnt_params.output_offset +
        MultiplyByQuantizedMultiplier(val - qnt_params.input_offset,
                                      qnt_params.output_multiplier,
                                      qnt_params.output_shift);
    clamped = std::max(qnt_params.quantized_activation_min, clamped);
    clamped = std::min(qnt_params.quantized_activation_max, clamped);
    output_data[i] = static_cast<T>(clamped);
  }
}

template <typename T>
void CalculateReluOpData(const TfLiteTensor* input, TfLiteTensor* output,
                         ReluOpData* data);

void ReluFloat(const ReluFloatParams& flt_params,
               const RuntimeShape& input_shape, const float* input_data,
               const RuntimeShape& output_shape, float* output_data);


TfLiteStatus ReluPrepare(TfLiteContext* context, TfLiteNode* node);

TfLiteStatus Relu6Prepare(TfLiteContext* context, TfLiteNode* node);

TfLiteStatus Relu0to1Prepare(TfLiteContext* context, TfLiteNode* node);

TfLiteStatus ReluN1to1Prepare(TfLiteContext* context, TfLiteNode* node);
}  // namespace tflite

#endif  // TENSORFLOW_LITE_MICRO_KERNELS_ACTIVATIONS_H_
