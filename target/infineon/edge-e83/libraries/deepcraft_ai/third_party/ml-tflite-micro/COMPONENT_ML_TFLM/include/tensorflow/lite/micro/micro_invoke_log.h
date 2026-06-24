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

#ifndef TENSORFLOW_LITE_MICRO_MICRO_INVOKE_LOG_H_
#define TENSORFLOW_LITE_MICRO_MICRO_INVOKE_LOG_H_

#include <cstdint>
#include "tensorflow/lite/c/common.h"
#include <string>

namespace tflite {

uint32_t computeDataChecksum(const void *data, size_t bytes);

#if ENABLE_LOG_DATA_CHECK_SUMS
void logDataCheckSum(const std::string &msg, const void *data, size_t len_bytes ) ;
#endif

#if LOG_OP_INPUTS
void logOpInvoke(TfLiteContext* context, TfLiteNode* node);
#endif



} // namespace tflite

#endif // TENSORFLOW_LITE_MICRO_MICRO_INVOKE_LOG_H_
