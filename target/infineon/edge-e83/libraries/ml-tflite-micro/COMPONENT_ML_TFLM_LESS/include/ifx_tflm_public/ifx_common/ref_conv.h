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

#ifndef IFX_TFLM_PUBLIC_IFX_COMMON_REF_CONV_H_
#define IFX_TFLM_PUBLIC_IFX_COMMON_REF_CONV_H_



#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/kernels/internal/common.h"


namespace tflite {

TFLMRegistration Register_CONV_2D_IFX_FAST_REF();

}  // namespace tflite



#endif /* IFX_TFLM_PUBLIC_IFX_COMMON_REF_CONV_H_ */
