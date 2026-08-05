
#ifndef IFX_TFLM_PRIVATE_IFX_CMSIS_NN_MUL_OP_DATA_H_
#define IFX_TFLM_PRIVATE_IFX_CMSIS_NN_MUL_OP_DATA_H_


#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/micro/kernels/mul.h"

namespace tflite {
namespace ops {
namespace micro {
namespace mul {

struct OpData;

#define EVAL_FUNC_DECL(name) \
  TfLiteStatus name(TfLiteContext* context, TfLiteNode* node, \
            const OpDataMul* data, \
            const TfLiteEvalTensor* input1, \
            const TfLiteEvalTensor* input2, TfLiteEvalTensor* output)

typedef EVAL_FUNC_DECL((*EvalVariantFptr)) ;

EVAL_FUNC_DECL(EvalQuantizedInt8);
EVAL_FUNC_DECL(EvalQuantizedInt16);
EVAL_FUNC_DECL(EvalFloatReference);

#undef EVAL_FUNC_DECL

struct OpData {
  ::tflite::OpDataMul common;

  // Eval function pointer
  EvalVariantFptr eval_function;
};


}  // namespace mul
}  // namespace micro
}  // namespace ops
}  // namespace tflite

#endif // IFX_TFLM_PRIVATE_IFX_CMSIS_NN_MUL_OP_DATA_H_
