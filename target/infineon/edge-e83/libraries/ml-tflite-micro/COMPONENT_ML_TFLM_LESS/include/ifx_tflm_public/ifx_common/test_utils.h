/* Copyright 2022 The TensorFlow Authors. All Rights Reserved.

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

#ifndef IFX_TFLM_PUBLIC_IFX_COMMON_TEST_UTILS_H_
#define IFX_TFLM_PUBLIC_IFX_COMMON_TEST_UTILS_H_

#include <random>
#include <cstring>
#include "packing_utils.h"
#include "tensorflow/lite/c/builtin_op_data.h"
#if ENABLE_GR_DECODER
#include "mxnnlite_types.h"
#endif
namespace tflite {
namespace testing {



#if CY_IP_MXNNLITE_VERSION>=2
std::vector<int8_t> channelwiseSlicedWeights(const int8_t *filters, const TfLiteIntArray &dims,
                                                    const unsigned int slice_size);
#endif


/**
 * \brief       Pack weights in IFX sparse/narrow bitwidth formats. 
 *
 * \details     Packs 8-bit quantized weights using "tflite(u)-RMF" format
 *  For HW support the number of non-zero elements in each  "unpacking run" (corresponding and individual filters in conv kernels)
 *  is tracked and recorded. 
 * 
 * \param[in]   weights       C array of weights
 * \param[in]   weights_dims  Dimensions of weights  
 * \param[in ]  format        Required packing format
 * \param[in]   num_sops_dim  Dimension whose size gives number of sums-of-products...
 * 
 * \note Functionass correct for 8-bit non-sparse (no-op))
 * \return  Packed weights (byte vector)
 *
 */

std::vector<int8_t> PackedWeights(
    const int8_t* weights, const TfLiteIntArray &weights_dims,
    const TfLiteCustomSub8BitPackingDetails * ormat, int zero_code, int num_sops_dim);



/**
 * \brief       Pack (sparse) 8-bit quantized weights (with workaround for mxnnlite HW)
 *
 * \details     Packs 8-bit quantized weights using "tflite(u)-RMF" format
 *  For HW support the number of non-zero elements in each  "unpacking run" (corresponding and individual filters in conv kernels)
 *  is tracked and recorded.  For MxNNLite HW workaround weights for 1 N-filter kernel is packed
 *  as for N 1-filter kernels.
 *
 * 
 * \param[in]   weights_dims  Dimensions of weights  
 * \param[in ]  format        Required packing format
 * \param[in]   zero_code         Code representing zero (only checked, must be 0)
 * \param[in ]  unpacked_weights  Sparse 8-bit weights .
 * \return  Packed representation of weights (bitmap, non-zero weight counts, non-zero weights)
 *
 */

std::vector<int8_t> 
PackedWeightsConv(const int8_t* unpacked_weights, const TfLiteIntArray &weights_dims,
                  const TfLiteCustomSub8BitPackingDetails *format, int zero_code);

/**
 * @brief count zseros in C-style array
 * 
 * @param input     Point to array start
 * @param inputSize Size of array
 * @return size_t   Number of zero elements present in array
 */
size_t CountZeros(const int8_t* input, size_t inputSize);

/**
 * @brief Random tflite fused activation supported by tflite-micro kernels
*/
TfLiteFusedActivation GetRandomTflmSupportedFusedActivation(std::mt19937 &random);


/**
 * @brief Select a random (legal) item and container bitwidth 
*/
void GetRandomBitWidth(std::mt19937 &random, uint8_t &bits_per_item, uint8_t &container_bits);

#if ENABLE_GR_DECODER
std::vector<int8_t> GRCompression(std::mt19937 &random, std::vector<int8_t> &unpacked_weights, const ifx::mxnnlite::GRCompressionMode gr_mode, size_t num_w_elts); 
#endif

/**
 * @brief Randomly generate parameters for conv and depthwise_conv operators.
 * 
 * Chooses settings suitable for directed randomized testing of kernel implementations
 * 
 * @tparam PARAMS   parameter struct tyoe
 * @param random    Random generator.
 * @param input_dims  Input tensor dimensinos
 * @param filter_dims   Filter tensor dimenstions
 * @param params    Parameter struct to fill with 
 */
template<typename PARAMS>
void GetRandomParams(std::mt19937 &random, TfLiteIntArray* input_dims,
        TfLiteIntArray* filter_dims, PARAMS& params) {
  params.padding = static_cast<TfLitePadding>(
        std::uniform_int_distribution<int8_t>(1, 2)(random));
  // Only tflite-micro supported 
  params.activation = GetRandomTflmSupportedFusedActivation(random);

  int inputHeight = input_dims->data[1];
  int filterHeight = filter_dims->data[1];
  int inputWidth = input_dims->data[2];
  int filterWidth = filter_dims->data[2];

  int8_t strideH = std::uniform_int_distribution<int8_t>(1, 2)(random);
  params.stride_height = (inputHeight > 2*strideH) ? strideH : 1;
  int8_t strideW = std::uniform_int_distribution<int8_t>(1, 2)(random);
  params.stride_width = (inputWidth > 2*strideW) ? strideW : 1;
  bool try_dilation = std::uniform_int_distribution<int8_t>(1, 3)(random) == 1;
#if defined(IFX_MXNNLITE3) && defined(ENABLE_GR_DECODER)
  try_dilation = false;
#endif
  if (try_dilation) {
    int8_t dilationW = std::uniform_int_distribution<int8_t>(1, 3)(random);
    params.dilation_width_factor = (inputWidth >= filterWidth*dilationW) ? dilationW : 1;
    int8_t dilationH = std::uniform_int_distribution<int8_t>(1, 3)(random);
    params.dilation_height_factor = (inputHeight >= filterHeight*dilationH) ? dilationH : 1;
  } else {
    params.dilation_width_factor = 1;
    params.dilation_height_factor = 1;
  }
}

/**
 * @brief Overwrite C-style array object with random percentage of zeros
 * 
 * @tparam T      Element data tyoe
 * @param random  Randomon generator
 * @param numElts Length of array
 * @param buf     Point to array start
 * @param percent_zeros   Percentage elements to be overwriten with zeros.
 */
template<typename T>
inline void InsertZeros(std::mt19937 &random, size_t numElts, T* buf, int percent_zeros) {
  for(unsigned int k = 0; k < numElts; ++k) {
    if (std::uniform_int_distribution<int>(1, 100)(random) <= percent_zeros)
      buf[k] = 0;
  }
}

/**
 * @brief Check for near equality with allowance for rounding errors / simple overflows
 * @tparam T      Element data tyoe
 * @param expected  Expected output
 * @param observed  Observed output 
 * @param len       length of @c expected and @c observed
 * @param rouding_diffs_per_thou   Number of rounding errors permitted per thousand results
 * 
 * Note that the code is deliberately written so that simple overflows (from min to max or vice-versa)
 * are treated as a "rounding" error.  This is needed because ARM shameless code-to-the-benchmark in heir
 * CMSIS-NN kernels using only highly overflow-prone 16-bit accumulators for core int8 sum-of-products calculations.
 */

template <typename T>
void CheckWithinLsbTolerance( const T *expected, T *observed, unsigned int len, 
                              unsigned int rouding_diffs_per_thou
                              )
{
  // If non-zero then 1 1-lsb rouunding difference is o.k.
  unsigned int lsb_errs_ok = 
    rouding_diffs_per_thou > 0u
    ? roundf(((float)(len*rouding_diffs_per_thou)+999)/1000u)
    : 0u;
  int tolerance = rouding_diffs_per_thou > 0 ? 1 : 0;

  unsigned int lsb_errs = 0;
  for (unsigned int i = 0; i < len; ++i) {
    // This will deliberately treat overflows flipping min to max as
    // abs_diff 1.   This is needed for CMSIS_NN conv kernels
    // which internally use only 16-bit accumulators...
    int abs_diff = std::abs(static_cast<T>(expected[i]-observed[i])) ;
    if( abs_diff != 0 && abs_diff >= tolerance) {
      MicroPrintf( "%d: lsb err expect %d got %d %d/%d\n", i, (int)expected[i], (int)observed[i], lsb_errs, lsb_errs_ok);
      ++lsb_errs;
    }
    TF_LITE_MICRO_EXPECT( abs_diff <= tolerance ); 
  }
  TF_LITE_MICRO_EXPECT( lsb_errs <= lsb_errs_ok);
  if( lsb_errs > lsb_errs_ok )
    abort();
}

}  // namespace testing
}  // namespace tflite

#endif /*IFX_TFLM_PUBLIC_IFX_COMMON_TEST_UTILS_H_*/