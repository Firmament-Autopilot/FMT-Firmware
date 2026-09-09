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

#ifndef IFX_TFLM_PUBLIC_IFX_COMMON_KERNEL_PRIMITIVES_H_
#define IFX_TFLM_PUBLIC_IFX_COMMON_KERNEL_PRIMITIVES_H_

#include <type_traits>
#include "tensorflow/lite/kernels/padding.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/kernels/internal/common.h"
#include "tensorflow/lite/kernels/internal/compatibility.h"
#include "packing_utils.h"

namespace tflite {
namespace ops {
namespace micro {

inline PaddingType RuntimePaddingType(TfLitePadding padding) {
  switch (padding) {
    case TfLitePadding::kTfLitePaddingSame:
      return PaddingType::kSame;
    case TfLitePadding::kTfLitePaddingValid:
      return PaddingType::kValid;
    case TfLitePadding::kTfLitePaddingUnknown:
    default:
      return PaddingType::kNone;
  }
}


template<typename QUANT_VALUE_T, typename CONTAINER_T, size_t bits_per_item>
class KernelPrimitives;

template <typename CONTAINER_T,size_t bits_per_item>
class KernelPrimitives<int8_t, CONTAINER_T, bits_per_item> {

  static constexpr int32_t sign_ext_shift = sizeof(int32_t) * 8 - bits_per_item;
  static constexpr int32_t mask = (1<<bits_per_item)-1;
public:
  static int32_t unpack(CONTAINER_T  packed_weights) {
      int32_t weight_bits = (packed_weights & mask);
      int32_t weights_val = ((weight_bits << sign_ext_shift) >> sign_ext_shift);
      return weights_val;
  } 

  template<class OpData>
  static int32_t outputRescale(int32_t raw_s_o_p, int oc, const OpData *data) {
    const int32_t* output_multiplier = data->per_channel_output_multiplier;
    const int32_t* output_shift = data->per_channel_output_shift;
    return MultiplyByQuantizedMultiplier(raw_s_o_p, output_multiplier[oc], output_shift[oc]);
  }

};



/**
 * \brief       Unpacking weights (sub-word or fullword) RMF packed/sparse weight tensor
 *
 *
 */

struct WeightUnpacker
{
  void init(const int8_t *packed_weights);

  uint32_t weights_cur_container;
  uint32_t bits_in_container;
  const int8_t *next_container_word;

  /**
   * \brief       Unpacking next weight (sub-word or fullword)
   *
   * \details     Unpacks next packed weight
   *
   * \tparam       CONTAINER_T           Type of container (C++ integer type).
   * \tparam       bits_per_item         BIts per weight to unpacked
   * \param[in]    us                    Unpacking state
   *
   * \return      unpacked weight 
   *
   */

  template<typename CONTAINER_T, unsigned int bits_per_item>
  inline int32_t unpack() {
    int32_t unpacked;
    
    constexpr int32_t sign_ext_shift = sizeof(int32_t) * 8 - bits_per_item;
    constexpr int32_t mask = (1<<bits_per_item)-1;
    constexpr int32_t bits_per_container = sizeof(CONTAINER_T)*8;
    constexpr unsigned int items_per_container = bits_per_container/bits_per_item;

    if(items_per_container>1) {  // Static const - optimized away at compile-time
      // Multiple items per container so unpacking is needed

      // Fetch next container word of packed data if necessary
      if(bits_in_container < bits_per_item) {
        weights_cur_container = static_cast<uint32_t>(*reinterpret_cast<const CONTAINER_T *>(next_container_word));
        next_container_word += sizeof(CONTAINER_T);
        bits_in_container = bits_per_container;
      }

      // Unpack from container word....
      int32_t weight_bits = (weights_cur_container & mask);
      unpacked = ((weight_bits << sign_ext_shift) >> sign_ext_shift);
      weights_cur_container >>= bits_per_item;
      bits_in_container -= bits_per_item;
    } else {

      // Only one item per container - it is not packed so simply fetch it...
      // Right now this only ever CONTAINER_T == int8_t but you never know....
      unpacked = static_cast<int32_t>(*next_container_word);
      next_container_word += sizeof(CONTAINER_T);
    }
    return unpacked;
  }

  inline const int8_t *followingAlignedWeightBlock(size_t alignment) {
    auto misalign = reinterpret_cast<uintptr_t>(next_container_word) % alignment;
    if (misalign != 0) {
      return next_container_word + alignment-misalign;
    } else {
      return next_container_word;
    }
  }
};


enum SparsitySupport {
  NEVER_SPARSE,
  ALWAYS_SPARSE,
  SOMETIMES_SPARSE
};

/**
 * @brief Skipping zeros when unpacking sparse/narrow RMF weight tensors
 * 
 * @tparam sparsity   ALWAYS, SOMETIMES,  NEVER sparsity map present
 */

template<SparsitySupport sparsity>
struct SparseZeroSkipping;

template<>
struct SparseZeroSkipping<NEVER_SPARSE> {
  void init(const int8_t *sparsity_map) {}

  inline bool skippedZero()  { return false; }
};



template<SparsitySupport sparsity>
struct SparseZeroSkipping
{

  void init(const int8_t *sparsity_map) {
    sparsity_curbit_mask = 0;
    sparsity_map_curbyte = 0;
    next_byte_sparsity_map = reinterpret_cast<const uint8_t *>(sparsity_map);
  }

  uint8_t sparsity_curbit_mask;
  uint8_t sparsity_map_curbyte;
  const uint8_t *next_byte_sparsity_map;


  inline bool skippedZero() {

    static_assert(sparsity != NEVER_SPARSE, "Inneficient for NEVER_SPARSE case");
    // branching optimized away for ALWAYS_SPARSE case...
    if(sparsity == ALWAYS_SPARSE || next_byte_sparsity_map != nullptr) {

      // Fetch next byte of sparsity bit-map if neccessary 
      if (sparsity_curbit_mask == 0) {
        sparsity_curbit_mask = 1u;
        sparsity_map_curbyte = *next_byte_sparsity_map;
        ++next_byte_sparsity_map;
      }
      
      bool skipped_zero = (sparsity_map_curbyte & sparsity_curbit_mask) ==0;
      sparsity_curbit_mask <<= 1u;
      return skipped_zero;
    } else {
      return false;
    }
  }

  inline void skipToNextBitMap() {
    sparsity_curbit_mask = 0; // Start again at next byte...
  } 
};




     
class PackedWeightUnpacker
  : public WeightUnpacker
  , public SparseZeroSkipping<SOMETIMES_SPARSE>
{
  unsigned int bits_per_container_;
  unsigned int bits_per_item_;

  /**
   * @brief Code for a zero value.  Currently always zero in tflite.
   * 
   */
  static const int32_t zerocode              = 0;

  public:

    PackedWeightUnpacker( const int8_t *packed_weights, 
        unsigned int num_weights, unsigned num_filters,
        const TfLiteCustomSub8BitPackingDetails* custom);

  /**
   * @brief Constructor for MxNNLite conv HW bug workaround.
   *
   */
    PackedWeightUnpacker( const int8_t *packed_weights, const int8_t *sparsity_map);

    PackedWeightUnpacker( const int8_t *packed_weights,
        size_t num_weights, size_t num_filters,
        unsigned int bits_per_item, unsigned int bits_per_container,
        unsigned int compression_type);

    /**
     * \brief       Unpack specified number of weights to buffer
     *
     * \details     Unpacks specified number of narrow bit width packed weights and/or
     *              8-bit packed sparse weight data, if sparse bitmap is set else adds zero.
     *              Pointer to packed weights, sparsity bitmap count value is stored
     *              and used for next iterations of unpacking.
     *
     * \tparam       CONTAINER_T           Type of container (C++ integer type).
     * \tparam       items_per_container   Number of packed items per container
     * \tparam       sparsity              Weights always/never/possibly sparse
     * \param[in]  
     *              
     *              num_unpack        Number of weight data to be unpacked.
     *
     * \param[out]  unpacked_weights   Holds the unpacked weight data.
     *
     */

    template<typename VALUE_T, typename CONTAINER_T, unsigned int BITS_PER_ITEM>
    void unpackWeights(VALUE_T *unpacked_weights, unsigned int num_unpack);



    /**
     * \brief       Unpack weights based the custom packing format information.
     *
     * \details     For efficiency, delegates actual unpacking to template function instance
     *              specialized for the to packed item bitwidth and item container type.
     *
     * \param[in]   num_weights_unpack    Number of weight data to be unpacked.
     *
     * \param[out]  unpacked_weights   Holds the unpacked weight data.
     */

    void unpackWeightsSlice(int8_t *unpacked_weights, unsigned int num_weights_unpack);

    /**
     * \brief       Switch to unpacking to continue from first item in next container word.
     *
     * \details     Unpacking will continue from first item next container word.
     *              This is needed to skip garbage items in the final container-word
     *              of a packing "run" for some packing cases where the final container
     *              in each run may only be partially filled.
     *
     */

    void skipToNextContainer();

};





template<typename VALUE_T, typename CONTAINER_T, unsigned int BITS_PER_ITEM>
inline void PackedWeightUnpacker::unpackWeights(VALUE_T *unpacked_weights, unsigned int num_weights_unpack) {

  static_assert(sizeof(VALUE_T) <= sizeof(uint32_t), "Small enough VALUE_T"); // We use uint32 to cache value container...
  static_assert(std::is_same<VALUE_T,int8_t>::value, "VALUE_T int8-t"); // Output ptr is used direct...
  for( unsigned int i = 0; i < num_weights_unpack; ++i) {

    // Do we have a skipped zero?
    // This expression optimizes to compile-time constant for NEVER_SPARSE
    // and inlines otherwise...
    if( skippedZero() ) {
      unpacked_weights[i]  = static_cast<VALUE_T>(zerocode);
      continue;
    }

    unpacked_weights[i]  = unpack<CONTAINER_T,BITS_PER_ITEM>();
  }
}


inline void PackedWeightUnpacker::skipToNextContainer() {
  bits_in_container = 0;
}


/**
 * \brief       Unpacking conv weights (with workaround for MxNNlite conv HW Bug)
 *
 * \details     Unpacks 8-bit "tflite(u)-RMF" format packed  conv kernel weight data
 *              packed as N 1-filter kernels.   Supports dense case to simplify use
 *              in test-case / SW emulation etc.
 * 
 * Format: N0,N1, …Nn, B0, B1, … Bn, [padding to align packing container words], W0, W1, .. Wn
 *
 * \param[in]   packed_weights    The packed weight data to be unpacked.
 * \param[in]   num_weights       Number of weight data to be unpacked.
 * \param[in]   num_filters       Number of filters (needed for mxnnlite HW support).
 * \param[in]   sparse            Packed sparse weights with sparsity bitmap and non-zero weight counts.
 *
 * \param[out]  unpacked_weights  Holds the unpacked weight data.
 *
 */
inline void UnpackSparseWeightsMxNNLiteConv(const int8_t *packed_weights, size_t num_weights,
                                            size_t num_filters, int8_t *unpacked_weights, bool sparse) {

  size_t per_filter_weights = num_weights / num_filters;
  const unsigned int accum_run_lens_size = sparse ? num_filters * 2u :0;
  const unsigned int sparsity_map_size =
    sparse ? num_filters * tflite::ops::micro::sparsityMapSize(per_filter_weights) : 0;
  auto filter_unpacked = unpacked_weights;
  auto filter_packed = packed_weights + accum_run_lens_size + sparsity_map_size;
  auto sparsity_map = sparse ? packed_weights + accum_run_lens_size : nullptr;
  PackedWeightUnpacker pw(filter_packed, sparsity_map);
  for (size_t f = 0; f < num_filters; ++f ) {
    pw.unpackWeights<int8_t, int8_t, 8u>(filter_unpacked, per_filter_weights);
    pw.skipToNextContainer();
    pw.skipToNextBitMap();
    filter_unpacked += per_filter_weights;
  }
}

}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif /* IFX_TFLM_PUBLIC_IFX_COMMON_KERNEL_PRIMITIVES_H_ */
