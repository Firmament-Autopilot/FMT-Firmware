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

#ifndef IFX_TFLM_PUBLIC_IFX_FAST_DEPTHWISE_CONV_PACKED_OPS_H_
#define IFX_TFLM_PUBLIC_IFX_FAST_DEPTHWISE_CONV_PACKED_OPS_H_

#include "ifx_fast/depthwise_conv/depthwise_conv_op_data.h"
#include "tensorflow/lite/kernels/internal/common.h"
#include "tensorflow/lite/kernels/internal/cppmath.h"
#include "tensorflow/lite/kernels/internal/quantization_util.h"
#include "tensorflow/lite/kernels/internal/types.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/micro/kernels/kernel_util.h"
#include "tensorflow/lite/c/builtin_op_data.h"
#include "ifx_common/kernel_primitives.h"

namespace tflite {
namespace ops {
namespace micro {
namespace depthwise_conv {

struct DepthwiseConvPackedTraits {
  struct WithPadding {
    WithPadding(const int32_t input_offset, OpData* data,
                const int32_t* bias_data)
        : input_offset_(input_offset), bias_data_(bias_data) {}

    inline void SumOfFiltersCorrectionAndBias(int32_t& raw_sum,
                                              uint32_t out_chan) const {
      raw_sum += bias_data_[out_chan];
    }

    inline int32_t OffsetInputValue(int32_t input_value) const {
      return input_offset_ + input_value;
    };

    inline bool InRange( const int x, const int y, const int x_end, const int y_end) const {
      return x >= 0 && x < x_end && y >= 0 && y < y_end;
    }


    const int32_t input_offset_;
    const int32_t* bias_data_;
  };

  struct WithoutPadding {
    WithoutPadding(const int input_offset, OpData* data,
                   const int32_t* bias_data)
        : sum_of_filters_factor_(data->sum_of_filters_factor) {}

    inline void SumOfFiltersCorrectionAndBias(int32_t& raw_sum,
                                              uint32_t out_chan) const {
      raw_sum += sum_of_filters_factor_[out_chan];
    }

    inline int32_t OffsetInputValue(int32_t input_value) const {
      return input_value;
    };

    constexpr bool InRange( const int x, const int y, const int x_end, const int y_end) const {
      return true;
    }

    const int32_t* sum_of_filters_factor_;
  };
};


template <typename QUANT_VALUE_T, typename CONTAINER_T, size_t bits_per_item,
          size_t items_per_container, class PADDING_TRAIT>
TfLiteStatus DepthwiseConvPacked(
    TfLiteContext* context, const TfLiteDepthwiseConvParams& params,
    OpData* data, const TfLiteEvalTensor* input, const TfLiteEvalTensor* filter,
    const TfLiteEvalTensor* bias, TfLiteEvalTensor* output) {

  typedef KernelPrimitives<QUANT_VALUE_T, CONTAINER_T, bits_per_item> kp;

  const RuntimeShape& input_shape = tflite::micro::GetTensorShape(input);
  const QUANT_VALUE_T* input_data = tflite::micro::GetTensorData<QUANT_VALUE_T>(input);
  const RuntimeShape& filter_shape = tflite::micro::GetTensorShape(filter);
  const CONTAINER_T* filter_data = static_cast<const CONTAINER_T*>(
      tflite::micro::GetTensorData<void>(filter));
  const RuntimeShape& bias_shape = tflite::micro::GetTensorShape(bias);
  const int32_t* bias_data = tflite::micro::GetTensorData<int32_t>(bias);
  const RuntimeShape& output_shape = tflite::micro::GetTensorShape(output);
  QUANT_VALUE_T* output_data = tflite::micro::GetTensorData<QUANT_VALUE_T>(output);

  const PADDING_TRAIT pad_traits(-data->input_zero_point, data, bias_data);
  const int stride_width = params.stride_width;
  const int stride_height = params.stride_height;
  const int dilation_width_factor = params.dilation_width_factor;
  const int dilation_height_factor = params.dilation_height_factor;
  const int pad_width = data->padding.width;
  const int pad_height = data->padding.height;
  const int depth_multiplier = params.depth_multiplier;
  const int32_t output_activation_min = data->output_activation_min;
  const int32_t output_activation_max = data->output_activation_max;
  const int32_t filter_offset = -data->filter_zero_point;
  const int32_t output_offset = data->output_zero_point;

  TFLITE_DCHECK_EQ(input_shape.DimensionsCount(), 4);
  TFLITE_DCHECK_EQ(filter_shape.DimensionsCount(), 4);
  TFLITE_DCHECK_EQ(output_shape.DimensionsCount(), 4);

  TFLITE_DCHECK_LE(output_activation_min, output_activation_max);
  const int batches = MatchingDim(input_shape, 0, output_shape, 0);
  const int output_depth = MatchingDim(filter_shape, 3, output_shape, 3);
  const int input_height = input_shape.Dims(1);
  const int input_width = input_shape.Dims(2);
  const int input_depth = input_shape.Dims(3);
  const int filter_height = filter_shape.Dims(1);
  const int filter_width = filter_shape.Dims(2);
  const int output_height = output_shape.Dims(1);
  const int output_width = output_shape.Dims(2);
  TFLITE_DCHECK_EQ(output_depth, input_depth * depth_multiplier);
  TFLITE_DCHECK_EQ(bias_shape.FlatSize(), output_depth);

  int32_t* accbuf = static_cast<int32_t*>(
      context->GetScratchBuffer(context, data->acc_buf_idx));

  auto in_dims = input_shape.DimsData();

  const unsigned int weights_size = filter_shape.FlatSize();
  const TfLiteCustomSub8BitPackingDetails *custom = data->custom_sub8bit_packing;

  for (int b = 0; b < batches; ++b) {
    const uint32_t input_offset0 = in_dims[1] * b;
    for (int out_y = 0; out_y < output_height; ++out_y) {
      for (int out_x = 0; out_x < output_width; ++out_x) {
        const int in_x_origin = (out_x * stride_width) - pad_width;
        const int in_y_origin = (out_y * stride_height) - pad_height;

        for (int i = 0; i < output_depth; ++i) {
          accbuf[i] = 0;
        }

        // First container...
        const CONTAINER_T* filter_vals_container_p = filter_data;
        tflite::ops::micro::PackedWeightUnpacker pw(reinterpret_cast<const int8_t*>(filter_vals_container_p),
                                        weights_size, output_depth, custom);

        for (int filter_y = 0; filter_y < filter_height; ++filter_y) {
          const int in_y = in_y_origin + dilation_height_factor * filter_y;
          const uint32_t input_offset1 = in_dims[2] * (input_offset0 + in_y);

          for (int filter_x = 0; filter_x < filter_width; ++filter_x) {
            const int in_x = in_x_origin + dilation_width_factor * filter_x;
            const QUANT_VALUE_T* input_p =
                &input_data[in_dims[3] * (input_offset1 + in_x)];

            // If the location is outside the bounds of the input image,
            // use zero as a default value.
            const bool in_range = pad_traits.InRange(in_x, in_y, input_width, input_height);

             for (int in_channel = 0; in_channel < input_depth; ++in_channel) {
              for (int m = 0; m < depth_multiplier; ++m) {
                const int out_channel = m + in_channel * depth_multiplier;
                int32_t offset_filter_val = 0;
                if( pw.skippedZero() ) {
                  continue;
                } else {
                  offset_filter_val = pw.unpack<CONTAINER_T, bits_per_item>() + filter_offset;
                }

                if (in_range) {
                  int32_t offset_input_val =
                      pad_traits.OffsetInputValue(input_p[in_channel]);
                  accbuf[out_channel] +=
                      offset_filter_val * offset_input_val;
                }
              }
            }
          }
        }

        for (int oc = 0; oc < output_depth; ++oc) {
          int32_t acc = accbuf[oc];
          pad_traits.SumOfFiltersCorrectionAndBias(acc, oc);
          acc = kp::outputRescale(acc, oc, data);
          acc += output_offset;
          acc = std::max(acc, output_activation_min);
          acc = std::min(acc, output_activation_max);
          output_data[Offset(output_shape, b, out_y, out_x, oc)] =
              static_cast<QUANT_VALUE_T>(acc);
        }
      }
    }
  }
  return kTfLiteOk;
}


template <typename CONTAINER_T, size_t bits_per_item,
              size_t items_per_container>
TfLiteStatus PackedWithPaddingInt8<CONTAINER_T, bits_per_item, items_per_container>::Run(
    TfLiteContext* context, const TfLiteDepthwiseConvParams& params,
    OpData* data, const TfLiteEvalTensor* input, const TfLiteEvalTensor* filter,
    const TfLiteEvalTensor* bias, TfLiteEvalTensor* output) {
  return DepthwiseConvPacked<int8_t, CONTAINER_T, bits_per_item, items_per_container,
        DepthwiseConvPackedTraits::WithPadding>(
        context, params, data, input, filter, bias, output);
}

template <typename CONTAINER_T, size_t bits_per_item,
              size_t items_per_container>
TfLiteStatus PackedWithoutPaddingInt8<CONTAINER_T, bits_per_item, items_per_container>::Run(
    TfLiteContext* context, const TfLiteDepthwiseConvParams& params,
    OpData* data, const TfLiteEvalTensor* input, const TfLiteEvalTensor* filter,
    const TfLiteEvalTensor* bias, TfLiteEvalTensor* output) {
  return DepthwiseConvPacked<int8_t, CONTAINER_T, bits_per_item, items_per_container,
      DepthwiseConvPackedTraits::WithoutPadding>(
      context, params, data, input, filter, bias, output);
}

template
class PackedWithoutPaddingInt8<int8_t, 4, 8/4>;

template
class PackedWithoutPaddingInt8<int16_t, 5, 16/5>;

template
class PackedWithoutPaddingInt8<int32_t, 6, 32/6>;

template
class PackedWithoutPaddingInt8<int8_t, 8, 8/8>;

template
class PackedWithPaddingInt8<int8_t, 4, 8/4>;

template
class PackedWithPaddingInt8<int16_t, 5, 16/5>;

template
class PackedWithPaddingInt8<int32_t, 6, 32/6>;

template
class PackedWithPaddingInt8<int8_t, 8, 8/8>;

}  // namespace depthwise_conv
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif /* IFX_TFLM_PUBLIC_IFX_FAST_DEPTHWISE_CONV_PACKED_OPS_H_ */