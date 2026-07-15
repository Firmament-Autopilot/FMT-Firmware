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

/*
Preinterpretation support:
* TF_LITE_MICRO_RECORD_OP_USER_DATA -- Set  to capture op user_data for code generation
* TF_LITE_MICRO_USE_OFFLINE_OP_USER_DATA -- 
*      Set to use pre-compiled previously from a captured model Init/Prepare 
*     Advantages: Smaller binaries, since only the required kernels are compiled
*                 Smaller runtime, because many intermediate values are stored
==============================================================================*/

#ifndef IFX_TFLM_PUBLIC_IFX_COMMON_OFFLINE_PREPARE_UTILS_H_
#define IFX_TFLM_PUBLIC_IFX_COMMON_OFFLINE_PREPARE_UTILS_H_

#if TF_LITE_MICRO_RECORD_OP_USER_DATA
#include <string>

#define TFLMC_CAPTURED_OP_USER_DATA_FPTR(funptr_name) \
  (tflite::micro::recordLiteralForPointer(#funptr_name, reinterpret_cast<void*>(&funptr_name)), &funptr_name)

#elif TF_LITE_MICRO_USE_OFFLINE_OP_USER_DATA

#define TFLMC_CAPTURED_OP_USER_DATA_FPTR(funptr_name) \
  &funptr_name
  
#else
#define TFLMC_CAPTURED_OP_USER_DATA_FPTR(funptr_name) \
  &funptr_name

#endif

/* For pre-interpreter case (TF_LITE_MICRO_RECORD_OP_USER_DATA) the buffer will be allocated from heap
as the objects normally held in those buffers will code-generated static data objects in the pre-intepreted model
and so will need no space in the arena.
For interpreter execution, buffer need to be allocated in the arena (contents filled in 'Prepare').
*/
#if TF_LITE_MICRO_RECORD_OP_USER_DATA

#define TFLMC_CODE_GENERATED_BUFFER(context, buf_size) \
  malloc(buf_size)

#else

#define TFLMC_CODE_GENERATED_BUFFER(context, buf_size) \
  context->AllocatePersistentBuffer(context, buf_size)

#endif

namespace tflite {
namespace micro {

#if TF_LITE_MICRO_USE_OFFLINE_OP_USER_DATA


  /**
 * @brief Reset table of pre-computed (offline) op user_data to use new inference
 * 
 * @param op_user_data_tbl  Start of array of void * pointers to user_data
 * 
 * Table is in op-inference order and contains entries only for instances of
 * ops supporting offline user_data.
 * 
 * Needs to be called prior to each inference.
 */

void resetOfflineOpUserData(void **op_user_data_tbl);


/**
 * @brief Fetch next offline op user_data 
 * 
 * @return void*    Pointer to next offline pre-computed user_data 
 * 
 * @note Should only be called in  @c init function registered for operator.
 * Fetches next entry in Table set using  @c resetOfflineOpUserData
 * 
 */
void *nextOfflineOpUserData();
#endif

}  // namespace micro
}  // namespace tflite


#endif // IFX_TFLM_PUBLIC_IFX_COMMON_OFFLINE_PREPARE_UTILS_H_