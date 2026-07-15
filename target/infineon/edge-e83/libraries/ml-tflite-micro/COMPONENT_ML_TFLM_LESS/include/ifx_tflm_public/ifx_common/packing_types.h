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

#ifndef IFX_TFLM_PUBLIC_IFX_COMMON_PACKING_TYPES_H_
#define IFX_TFLM_PUBLIC_IFX_COMMON_PACKING_TYPES_H_

#include <stdint.h>

enum TfliteCompressionType {
    DENSE = 0,
    NO_RUN_LENGTHS = 1,
    WORD_RUN_LENGTHS = 2,
    CHANNELWISE_DENSE = 3,       // Currently only used for tensor packed for NNLite NPU DW-mode
    GR_ENCODING = 4,
    FILTERWISE_DENSE =5,
};

/* MAX_SPEED, MIN_MEMORY indicate intermediate degrees of memory / performance trade-off.
 Currently: the number of "slices" computation is performed in. */
enum TfliteUnpackingType {
    NO_HINT = 0,
    MAX_SPEED = 1,
    MIN_MEMORY = 255
};

#endif /*IFX_TFLM_PUBLIC_IFX_COMMON_PACKING_TYPES_H_*/
