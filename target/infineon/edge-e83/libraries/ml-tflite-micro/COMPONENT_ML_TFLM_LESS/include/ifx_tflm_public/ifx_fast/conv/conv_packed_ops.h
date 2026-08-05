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

#ifndef IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_PACKED_OPS_H_
#define IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_PACKED_OPS_H_

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
namespace conv {


template <typename CONTAINER_T, size_t bits_per_item, size_t items_per_container>
void ConvPackedWeights(
        const TfLiteConvParams*conv_params, OpData* data,
        const RuntimeShape& input_shape, const int8_t* input,
        const RuntimeShape& filter_shape, const CONTAINER_T* filter,
        const RuntimeShape& bias_shape, const int32_t* bias,
        const RuntimeShape& output_shape, int8_t* output, TfLiteContext* context) {

  typedef KernelPrimitives<int8_t, CONTAINER_T, bits_per_item> kp;

  const int32_t input_offset = -data->input_zero_point;
  const int32_t filter_offset = -data->filter_zero_point;
  const int32_t output_offset =  data->output_zero_point;

  const int stride_width =  conv_params->stride_width;
  const int stride_height =  conv_params->stride_height;
  const int dilation_x = conv_params->dilation_width_factor;
  const int dilation_y = conv_params->dilation_height_factor;

  const int pad_width = data->padding.width;
  const int pad_height = data->padding.height;
  const int32_t output_activation_min = data->output_activation_min;
  const int32_t output_activation_max = data->output_activation_max;
  TFLITE_DCHECK_LE(output_activation_min, output_activation_max);
  TFLITE_DCHECK_EQ(filter_offset,0);
  TFLITE_DCHECK_EQ(input_shape.DimensionsCount(), 4);
  TFLITE_DCHECK_EQ(filter_shape.DimensionsCount(), 4);
  TFLITE_DCHECK_EQ(output_shape.DimensionsCount(), 4);
  const int batches = MatchingDim(input_shape, 0, output_shape, 0);
  const int input_depth = MatchingDim(input_shape, 3, filter_shape, 3);
  const int output_depth = MatchingDim(filter_shape, 0, output_shape, 3);
  if (bias) {
    TFLITE_DCHECK_EQ(bias_shape.FlatSize(), output_depth);
  }
  const int input_height = input_shape.Dims(1);
  const int input_width = input_shape.Dims(2);
  const int filter_height = filter_shape.Dims(1);
  const int filter_width = filter_shape.Dims(2);
  const int output_height = output_shape.Dims(1);
  const int output_width = output_shape.Dims(2);
  const int input_row_size = (input_width * input_depth);

  int32_t acc;

  // TODO Templatize checking for padding (row/col out of input bounds)
  // to improve performance (use of pre-interpreter would reduce code-bloat)

  // When each column of input completed input_ptr is  @
  //   (in_y, in_x+1, 0)
  // this the stride to the move to
  //  (in_y, in_x+dilation_x 0)
  
  const int input_ptr_to_next_col_start = dilation_x * input_depth - input_depth;
  // When each row of input completed input_ptr is  @
  //   (in_y, in_x_origin+filter_width*dilation_x, 0)
  // this is the stride to move to
  //   (in_y+dilation_y, in_x_origin, 0)
  const int input_ptr_to_next_row_start = dilation_y * input_row_size - dilation_x*filter_width*input_depth;

  const unsigned int weights_size = filter_shape.FlatSize();
  const TfLiteCustomSub8BitPackingDetails *custom = data->custom_sub8bit_packing;

  for (int batch = 0; batch < batches; ++batch) {
    unsigned int batch_offset = batch * input_height * input_row_size;
    for (int out_y = 0; out_y < output_height; ++out_y) {
      for (int out_x = 0; out_x < output_width; ++out_x) {

        //
        // RAM-usage optimized version - unpacks each kernel "on the fly" to avoid
        // requiring a RAM buffer.  Really only interesting for the smallest embedded uC or
        // applications where inference throughput requirements are modest.
        //
        auto container_p = filter;
        tflite::ops::micro::PackedWeightUnpacker pw(reinterpret_cast<const int8_t*>(container_p),
                                        weights_size, output_depth, custom);

        for (int out_channel = 0; out_channel < output_depth; ++out_channel) {
          const int in_x_origin = (out_x * stride_width) - pad_width;
          const int in_y_origin = (out_y * stride_height) - pad_height;

          acc = 0;

          int in_y_origin_offset = batch_offset + in_y_origin * input_row_size;
          int in_x_y_offset = in_y_origin_offset + in_x_origin * input_depth;
          auto input_ptr = input + in_x_y_offset;

          for (int in_y = in_y_origin; 
              in_y < in_y_origin+filter_height*dilation_y; 
              in_y += dilation_y) {

            bool row_in_range = (in_y >= 0 && in_y < input_height);

            for (int in_x = in_x_origin; 
              in_x < in_x_origin+filter_width*dilation_x; 
              in_x += dilation_x)  {

              bool col_in_range = ( in_x >= 0 && in_x < input_width );

              for (int in_channel = 0; in_channel < input_depth; ++in_channel) {
                int32_t filter_val = 0;
                if( pw.skippedZero() ) {
                  ++input_ptr;
                  continue;
                } else {
                  filter_val = pw.unpack<CONTAINER_T, bits_per_item>() + filter_offset;
                }

                if (row_in_range && col_in_range) {
                  int32_t input_val = *input_ptr + input_offset;
                  acc += filter_val * input_val;
                }

                ++input_ptr;
              }

              input_ptr += input_ptr_to_next_col_start;
            } // for in_x


            input_ptr += input_ptr_to_next_row_start; 

          } // for in_y
    
          if (bias) {
            acc += bias[out_channel];
          }
        
          acc = kp::outputRescale(acc, out_channel, data);
          acc += output_offset;
          acc = std::max(acc, output_activation_min);
          acc = std::min(acc, output_activation_max);
          output[Offset(output_shape, batch, out_y, out_x, out_channel)] = static_cast<int8_t>(acc);
        }
      }
    }
  }
}


template <typename CONTAINER_T, size_t bits_per_item,
              size_t items_per_container>
TfLiteStatus PackedConvPerChannel<CONTAINER_T, bits_per_item, items_per_container>::Eval(
    TfLiteConvParams* params, OpData* data,
    const TfLiteEvalTensor* input,
    const TfLiteEvalTensor* filter,
    const TfLiteEvalTensor* bias,
    TfLiteEvalTensor* output,
    TfLiteContext* context) {

  ConvPackedWeights<CONTAINER_T, bits_per_item, items_per_container>(
        params,
        data,
        tflite::micro::GetTensorShape(input), tflite::micro::GetTensorData<int8_t>(input),
        tflite::micro::GetTensorShape(filter), tflite::micro::GetTensorData<CONTAINER_T>(filter),
        tflite::micro::GetTensorShape(bias), tflite::micro::GetTensorData<int32_t>(bias),
        tflite::micro::GetTensorShape(output), tflite::micro::GetTensorData<int8_t>(output),
        context);
    return kTfLiteOk;
}


template
class PackedConvPerChannel<int8_t, 4, 8/4>;

template
class PackedConvPerChannel<int16_t, 5, 16/5>;

template
class PackedConvPerChannel<int32_t, 6, 32/6>;

template
class PackedConvPerChannel<int8_t, 8, 8/8>;

} // namespace conv
} // namespace micro
} // namespace ops
} // namespace tflite


#endif /* IFX_TFLM_PUBLIC_IFX_FAST_CONV_CONV_PACKED_OPS_H_ */
