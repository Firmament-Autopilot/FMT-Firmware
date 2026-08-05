/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

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
#ifndef IFX_TFLM_PUBLIC_IFX_COMMON_QUANTIZATION_UTILS_H_
#define IFX_TFLM_PUBLIC_IFX_COMMON_QUANTIZATION_UTILS_H_

#include <cmath>
#include <cstdint>
#include <limits>

#include <tensorflow/lite/c/common.h>


namespace tflite {
namespace testing {

// Derives the quantization range max from scaling factor and zero point.
// N.b. no support for limited_range etc.
template <typename T>
inline float MaxFromZeroPointScale(const int zero_point, const float scale) {
  return (std::numeric_limits<T>::max() - zero_point) * scale;
}

// Derives the quantization range min from scaling factor and zero point.
// N.b. no support for limited_range etc.
template <typename T>
inline float MinFromZeroPointScale(const int zero_point, const float scale) {
  return (std::numeric_limits<T>::min() - zero_point) * scale;
}



// Derives the quantization scaling factor from a min and max range
// and coding bitwidth.  

inline float ScaleFromMinMaxPacked(const float min, const float max, 
                                   const uint32_t num_bits, bool symmetric=false) {
  float code_points  = static_cast<float>((1<<num_bits)-1);
  if (symmetric) {
    code_points -= 1.0f;
  }
  return (max - min) / code_points;
}


// Derives the quantization zero point from a min and max range
// and coding bitwidth.   N.b. no support for nudging etc
// intended primarily for creating test-data in simple tests.
inline int ZeroPointFromMinMaxPacked(const float min, const float max, 
                                     const uint32_t num_bits, bool symmetric=false, bool int8=false) {
  int min_code = int8 ? -(1<<(num_bits-1)) : 0;
  if (symmetric) {
    min_code += 1;
  }

  return min_code + static_cast<int>(-min / ScaleFromMinMaxPacked(min, max, num_bits, symmetric) + 0.5f);
}


// Derives the quantization scale from a min and max range
// and coding bitwidth.   N.b. no support for limited_range, nudging etc.
// intended primarily for creating test-data in simple tests.
template<uint32_t NUM_BITS>
inline uint8_t F2QB(const float value, const float min, const float max, bool symmetric=false) {
  int32_t result =
      floorf(
        ZeroPointFromMinMaxPacked(min, max, NUM_BITS, symmetric) +
          (value / ScaleFromMinMaxPacked(min, max, NUM_BITS, symmetric)) + 0.5f);
  const int32_t min_code = 0;
  const int32_t max_code = (1<<NUM_BITS)-1;
  if (result < min_code) {
    result = min_code;
  }
  if (result > max_code) {
    result = max_code;
  }
  return static_cast<uint8_t>(result);
}

// Derives the quantization scale from a min and max range
// and coding bitwidth.   N.b. no support for limited_range, nudging etc.
// intended primarily for creating test-data in simple tests.
template<uint32_t NUM_BITS>
inline int8_t F2QSB(const float value, const float min, const float max, bool symmetric=false) {
  int32_t result =
      floorf(value / ScaleFromMinMaxPacked(min, max, NUM_BITS, symmetric) + 0.5f);

  const int32_t max_code = (1<<(NUM_BITS-1)) - 1;
  const int32_t min_code = symmetric ? -max_code : -(1<<(NUM_BITS-1));
  if (result < min_code) {
    result = min_code;
  }
  if (result > max_code) {
    result = max_code;
  }
  return static_cast<int8_t>(result);
}

// Converts a quantized value to coded float
float Q2F(int32_t code, float scale, float zero_point);

// Converts a quantized value to coded float for quantization
// params of specified tensor
float Q2F(int32_t code, const TfLiteTensor *tensor);

// Converts a float value into an unsigned eight-bit quantized value
// for quantizations params of specified tensor 
uint8_t F2Q(float value, const TfLiteTensor *tensor);

// Converts a float value into an signed eight-bit quantized value
// for quantizations params of specified tensor 
int8_t F2QS(const float value, const TfLiteTensor *tensor);

// Converts a float value into an unsigned eight-bit quantized value.
uint8_t F2Q(float value, float min, float max);

// Converts a float value into a signed eight-bit quantized value.
int8_t F2QS(const float value, const float min, const float max);

// Converts a float value into a signed thirty-two-bit quantized value.  Note
// that values close to max int and min int may see significant error due to
// a lack of floating point granularity for large values.
int32_t F2Q32(const float value, const float scale);


}  // namespace testing
}  // namespace tflite

#endif  // IFX_TFLM_PUBLIC_IFX_COMMON_QUANTIZATION_UTILS_H_
