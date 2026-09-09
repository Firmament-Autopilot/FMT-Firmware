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

#ifndef IFX_TFLM_PRIVATE_IFX_MXNNLITE2_ADDSUBMUL_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_MXNNLITE2_ADDSUBMUL_OP_DATA_H_


#include "tensorflow/lite/c/builtin_op_data.h"


// TODO pre-intepreter: need to split out structs for external use into "anonymized"
// forms tha don't depend on the entirety of cy_ PDL.

#include "cy_nn_kernel.h"

namespace tflite {
namespace ops {
namespace micro {
namespace addsubmul {


struct NNLiteOpData;
#define EVAL_FUNC_DECL(name) \
  TfLiteStatus name(TfLiteContext* context, TfLiteNode* node,\
                    TfLiteAddParams* params, const NNLiteOpData* data,\
                    const TfLiteEvalTensor* input1,\
                    const TfLiteEvalTensor* input2,\
                    TfLiteEvalTensor* output)

typedef EVAL_FUNC_DECL((*EvalNNLiteFptr)) ;

EVAL_FUNC_DECL(EvalAddNNLite);
EVAL_FUNC_DECL(EvalSubNNLite);
EVAL_FUNC_DECL(EvalMulNNLite);

#undef EVAL_FUNC_DECL

struct NNLiteOpData  {

  // Alas, we can't (yet) rely on a C++17 build so we don't have the more useful
  // C++17 aggregate initialization of direct super-classes...
  cy_nn_pwise_binary_params_t nnlite;   //*< NNLite kernel-lib settings... save copying...
  bool    lhs_is_input2;    //*< Which tensor is lhs

  // Eval function pointer
  EvalNNLiteFptr eval_function;
};


struct VariantOpData {
  enum data_types {  SW_KERNEL,  NNLITE_KERNEL };
  int     data_type;
  const void    *op_data;  // Allows initialization from any concrete pointer type in lieu of
                     // designated union initialization (C++20 only)
};

}  // namespace addsubmul




}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif // IFX_TFLM_PRIVATE_IFX_MXNNLITE2_ADDSUBMUL_OP_DATA_H_
