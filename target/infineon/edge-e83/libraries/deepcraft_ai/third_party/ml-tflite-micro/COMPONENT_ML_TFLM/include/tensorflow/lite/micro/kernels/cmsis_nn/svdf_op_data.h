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

#ifndef TENSORFLOW_LITE_MICRO_CMSIS_NN_CONV_OP_DATA_H_
#define TENSORFLOW_LITE_MICRO_CMSIS_NN_CONV_OP_DATA_H_


#include <cstdint>

namespace tflite {

struct CmsisNnOpDataSvdf {
  int32_t effective_scale_1_a;
  int32_t effective_scale_2_a;
  // b versions of each scale are kept at int since the numbers are just the
  // shift value - typically between [-32, 32].
  int effective_scale_1_b;
  int effective_scale_2_b;
  int scratch_tensor_index;
#if defined(KERNELS_OPTIMIZED_FOR_SIZE)
  int scratch_weight_tensor_index;
#endif
  int scratch_output_tensor_index;

  // Cached tensor zero point values for quantized operations.
  int input_zero_point;
  int output_zero_point;
  int activation_state_zero_point;
  int32_t* kernel_sums;
  int32_t  kernel_sums_size;
};


}  // namespace tflite

#endif  // TENSORFLOW_LITE_MICRO_CMSIS_NN_CONV_OP_DATA_H_
