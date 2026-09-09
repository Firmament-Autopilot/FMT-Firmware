/* Copyright 2024 The TensorFlow Authors. All Rights Reserved.

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


#ifndef IFX_TFLM_PRIVATE_IFX_MXNNLITE2_COMMON_PREINT_H_
#define IFX_TFLM_PRIVATE_IFX_MXNNLITE2_COMMON_PREINT_H_


struct cy_nn_pwise_unary_params_s;
struct cy_nnlite_clipping_s;
struct cy_nn_dims_s;

namespace tflite {
namespace micro {

  class CppPODStructInitializer;


} // namespace micro


namespace ops {
namespace micro {
namespace ifx_mxnnlite2 {  
  

#if TF_LITE_MICRO_RECORD_OP_USER_DATA
  tflite::micro::CppPODStructInitializer CyNNliteClippingStruct(const struct cy_nnlite_clipping_s &cl);

  tflite::micro::CppPODStructInitializer CyNNliteUnaryOpParamsStruct(const struct cy_nn_pwise_unary_params_s &pw);

  tflite::micro::CppPODStructInitializer CyNNliteDimsStruct(const struct cy_nn_dims_s &d);
#endif


}  // namespace ifx_mxnnlite2
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif // IFX_TFLM_PRIVATE_IFX_MXNNLITE2_COMMON_PREINT_H_
