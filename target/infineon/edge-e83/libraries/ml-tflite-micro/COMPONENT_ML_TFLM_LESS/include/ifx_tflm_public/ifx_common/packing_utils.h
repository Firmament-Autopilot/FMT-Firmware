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

/*
IFX FAST
Preinterpretation support:
* TAGS="record_model autodump" -- Run using these tags to write the used kernel variants to a file
* TAGS="recorded_model" -- Use this TAG to use previously recorded kernel variants
*     Advantages: Smaller binaries, since only the required kernels are compiled
*                 Smaller runtime, because many intermediate values are stored
==============================================================================*/

#ifndef IFX_TFLM_PUBLIC_IFX_COMMON_PACKING_UTILS_H_
#define IFX_TFLM_PUBLIC_IFX_COMMON_PACKING_UTILS_H_

#include "packing_types.h"

namespace tflite {
namespace ops {
namespace micro {

/***
 * @brief Sparse packing type based on current selected optimized kernel lib / co-processor
 * 
 * @return Coding type for sparse weight tensors 
 **/

constexpr int sparse_weight_type =
#if defined(IFX_FAST_RIVAL) || defined(IFX_MXNNLITE) || defined(IFX_MXNNLITE2) || defined(IFX_MXNNLITE3) 
  TfliteCompressionType::WORD_RUN_LENGTHS;
#else
  TfliteCompressionType::NO_RUN_LENGTHS;
#endif

inline size_t sparsityMapSize(const unsigned int number_of_elts)
{
    static const unsigned int bits_per_byte = 8u;
    return ((number_of_elts + bits_per_byte - 1u) / bits_per_byte);
}

/**
 * @brief Compute next word alligned location / offset
 * 
 * Some elemnts packed weight format need to be word-aligned for efficiency.
 * This computes the next word-aligned offset given an offset from wird-aligned
 * base address (or address).
*/

inline size_t wordAlign(const size_t offset, const unsigned int bits_per_word) {
    unsigned int bytes_per_word = bits_per_word/8u;
    unsigned int misalign = offset % bytes_per_word;
    if (misalign != 0 ) {
      return offset+(bytes_per_word-misalign);
    } else {
      return offset;
    }
}


}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif /* IFX_TFLM_PUBLIC_IFX_COMMON_PACKING_UTILS_H_ */
