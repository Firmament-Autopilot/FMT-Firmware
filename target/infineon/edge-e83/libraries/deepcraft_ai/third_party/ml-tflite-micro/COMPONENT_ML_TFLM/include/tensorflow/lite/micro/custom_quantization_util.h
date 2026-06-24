/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

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
#ifndef TENSORFLOW_LITE_EXPERIMENAL_CUSTOM_QUANTIZATION_UTIL_H_
#define TENSORFLOW_LITE_EXPERIMENAL_CUSTOM_QUANTIZATION_UTIL_H_

#include <cmath>
#include <cstdint>
#include <limits>

#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/micro_log.h"

namespace tflite {

namespace custom_quant {

extern const uint32_t PACKED_SUB8BIT_UNIFORM_DETAILS_MAGIC;

// 
// Fetch custom quantization details for packed sub 8-bit quantized
// constants.

const TfLiteCustomSub8BitPackingDetails *ParseSub8BitPackedQuantizationDetails(const void *details);


} // namespace custom_quant
}  // namespace tflite

#endif  // TENSORFLOW_LITE_EXPERIMENAL_CUSTOM_QUANTIZATION_UTIL_H_
