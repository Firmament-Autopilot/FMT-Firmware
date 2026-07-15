/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

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


#ifndef IFX_TFLM_PRIVATE_IFX_MXNNLITE2_ADDSUBMUL_PREINT_H_
#define IFX_TFLM_PRIVATE_IFX_MXNNLITE2_ADDSUBMUL_PREINT_H_



namespace tflite {

namespace micro {

  struct CppNamedStruct;

  struct CppItems;

} // namespace micro


namespace ops {
namespace micro {
namespace addsubmul {  
  

#if TF_LITE_MICRO_RECORD_OP_USER_DATA

  struct NNLiteOpData;
  tflite::micro::CppNamedStruct record_nnlite_op_data(const NNLiteOpData &od);

  struct VariantOpData;
  tflite::micro::CppItems *record_variant_op_data(VariantOpData &od);

#endif


}  // namespace addsubmul
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif // IFX_TFLM_PRIVATE_IFX_MXNNLITE2_ADDSUBMUL_PREINT_H_
