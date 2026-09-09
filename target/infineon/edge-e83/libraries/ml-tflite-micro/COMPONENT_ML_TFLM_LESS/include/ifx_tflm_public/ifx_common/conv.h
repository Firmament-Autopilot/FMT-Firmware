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

#ifndef IFX_TFLM_PUBLIC_IFX_COMMON_CONV_COMMON_H_
#define IFX_TFLM_PUBLIC_IFX_COMMON_CONV_COMMON_H_


#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/kernels/internal/common.h"
#include "ifx_fast/conv/conv_op_data.h"


namespace tflite {

extern const int kConvInputTensor;
extern const int kConvWeightsTensor;
extern const int kConvBiasTensor;
extern const int kConvOutputTensor;
extern const int kConvQuantizedDimension;


namespace ops {
namespace micro {
namespace conv {

using ops::micro::conv::OpData;

/*
 * Init function is called once at the beginning to initialize kernels and allocate memory.
 */
void* IfxFastInit(TfLiteContext* context, const char* buffer, size_t length);

/*
 * Calculates the OpData which stores all important metadata about the kernel and parameters.
 */
TfLiteStatus CalculateOpData(TfLiteContext* context, TfLiteNode* node,
                             TfLiteConvParams* params, int width, int height,
                             int filter_width, int filter_height, int out_width,
                             int out_height, const TfLiteType data_type,
                             OpData* data);

/*
 * Precomputes a factor from the filter and offsets, which needs to be calculated
 * only once, not in every invocation.
 */
template<typename T>
void PrecomputeSumOfFilters(
    const int32_t* bias,
    const TfLiteTensor* filters,
    int32_t* sum_of_filters_factor,
    RuntimeShape filter_shape,
    int32_t input_offset,
    int32_t filter_offset = 0);



void PrecomputeSumOfFiltersPadding(
    const int32_t* bias,
    int32_t* sum_of_filters_factor,
    RuntimeShape filter_shape);


/*
 * Precomputes a factor from the filter and offsets for the packed weights version,
 * which needs to be calculated only once, not in every invocation.
 */

void PrecomputeSumOfPackedFiltersFactor(
    const int32_t* bias, const TfLiteTensor* filters,
    int32_t* sum_of_filters_factor, RuntimeShape filter_shape,
    int32_t input_offset, int32_t filter_offset,
    const TfLiteCustomSub8BitPackingDetails& packing_details);


/**
 * @brief Wrapper for tflite reference float implementation
 * 
 * Consistent signature with other ifx_conv Eval functions to
 * allow re-use as reference fallback.
*/
TfLiteStatus IfxFastFloatRef(TfLiteConvParams* params, OpData* data,
                           const TfLiteEvalTensor* input,
                           const TfLiteEvalTensor* filter,
                           const TfLiteEvalTensor* bias,
                           TfLiteEvalTensor* output, TfLiteContext* context);

/*
 * Evaluation function. Called in every invocation.
 */
TfLiteStatus IfxFastEval(TfLiteContext* context, TfLiteNode* node);

}  // namespace conv
}  // namespace micro
}  // namespace ops



}  // namespace tflite



#endif /* IFX_TFLM_PUBLIC_IFX_COMMON_CONV_COMMON_H_ */
