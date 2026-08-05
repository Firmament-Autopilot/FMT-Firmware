/******************************************************************************
* File Name: mtb_ml_model_tflm.cpp
*
* Description: This file contains API calls to initialize and invoke Tflite-Micro
*              inference for model generated from CY ML software.
*
*
*******************************************************************************
* (c) 2019-2026, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnity Cypress against all liability.
*******************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "mtb_ml.h"

#include <climits>

#include "tensorflow/lite/micro/tflite_bridge/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_op_resolver.h"
#include "tensorflow/lite/micro/recording_micro_interpreter.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_utils.h"

extern "C" {

#if defined(COMPONENT_U55)
extern ethosu_driver *mtb_ml_ethosu_driver_handle;
#endif

/* LCOV_EXCL_START (Excluded from the code coverage, until the STOP marker) */
int __attribute__((weak)) mtb_ml_model_profile_get_tsc(uint64_t *val)
{
    (void)val;
    return 0;
}
/* LCOV_EXCL_STOP */

}

namespace tflite {

static tflite::AllOpsResolver resolver;

template <typename inputT>
class MTBTFLiteMicro {
 public:
  /* The lifetimes of model, op_resolver, tensor_arena must exceed
   * that of the created MicroBenchmarkRunner object.
   */
  MTBTFLiteMicro(const uint8_t* model,
                       uint8_t* tensor_arena, int tensor_arena_size,
                       const tflite::MicroOpResolver& op_resolver,
                       MicroResourceVariables* resource_variables)
      : interpreter_(GetModel(model), op_resolver, tensor_arena,
                     tensor_arena_size, resource_variables, nullptr) {
      allocate_status_ = interpreter_.AllocateTensors();

      /* Extract multi-input/output configuration */
      input_count_  = interpreter_.inputs_size();
      output_count_ = interpreter_.outputs_size();
      input_meta_.clear();
      output_meta_.clear();

      size_t input_concat_total = 0;
      for (int i = 0; i < input_count_; ++i) {
        TfLiteTensor* t = interpreter_.input(i);
        TensorMeta m;
        m.ptr = GetTensorData<inputT>(t);
        m.bytes = t->bytes;
        m.elements = tflite::ElementCount(*t->dims);
        m.dim_len = t->dims->size;
        m.dims = t->dims->data;
        m.zero_point = t->params.zero_point;
        m.scale = t->params.scale;
        m.type = t->type;
        m.concat_offset_bytes = input_concat_total;
        input_concat_total += m.bytes;
        input_meta_.push_back(m);
      }
      input_concat_total_bytes_ = input_concat_total;

      size_t output_concat_total = 0;
      for (int i = 0; i < output_count_; ++i) {
        TfLiteTensor* t = interpreter_.output(i);
        TensorMeta m;
        /* Note: output storage type may differ from inputT for float models. */
        m.ptr = reinterpret_cast<inputT*>(GetTensorData<void>(t));
        m.bytes = t->bytes;
        m.elements = tflite::ElementCount(*t->dims);
        m.dim_len = t->dims->size;
        m.dims = t->dims->data;
        m.zero_point = t->params.zero_point;
        m.scale = t->params.scale;
        m.type = t->type;
        m.concat_offset_bytes = output_concat_total;
        output_concat_total += m.bytes;
        output_meta_.push_back(m);
      }
      output_concat_total_bytes_ = output_concat_total;
  }

  TfLiteStatus RunSingleIteration() {
    /* Run the model on this input and return the status. */
    return interpreter_.Invoke();
  }

  TfLiteTensor* Input(int index = 0)  { return interpreter_.input(index); }
  TfLiteTensor* Output(int index = 0) { return interpreter_.output(index); }

  TfLiteStatus AllocationStatus() { return allocate_status_; }

  /* Use for RNN state control. This will free subgraphs to the reset state */
  TfLiteStatus reset_all_variables() { return interpreter_.Reset(); }
  TfLiteType model_input_type(int index = 0) { return interpreter_.input(index)->type; }
  TfLiteType model_output_type(int index = 0) { return interpreter_.output(index)->type; }

  inputT* input_ptr(int index = 0) { return GetTensorData<inputT>(Input(index)); }
  size_t input_size(int index = 0) { return interpreter_.input(index)->bytes; }
  size_t input_elements(int index = 0) { return tflite::ElementCount(*(interpreter_.input(index)->dims)); }
  int    input_dims_len(int index=0) {return interpreter_.input(index)->dims->size; }
  int *  input_dims( int index=0) { return &interpreter_.input(index)->dims->data[0]; }
  int    input_zero_point( int index=0) { return interpreter_.input(index)->params.zero_point; }
  float  input_scale( int index=0) { return interpreter_.input(index)->params.scale; }
  int    output_zero_point( int index=0) { return interpreter_.output(index)->params.zero_point; }
  float  output_scale( int index=0) { return interpreter_.output(index)->params.scale; }
  inputT* output_ptr(int index = 0) { return GetTensorData<inputT>(Output(index)); }
  size_t output_size(int index = 0) { return interpreter_.output(index)->bytes; }
  size_t output_elements(int index = 0) { return  tflite::ElementCount(*(interpreter_.output(index)->dims));}
  int    output_dims_len(int index=0) {return interpreter_.output(index)->dims->size; }
  int *  output_dims( int index=0) { return &interpreter_.output(index)->dims->data[0]; }

  /* multi-tensor metadata and counts */
  struct TensorMeta {
    inputT* ptr;              /* pointer to tensor data */
    size_t  bytes;            /* size in bytes */
    size_t  elements;         /* number of elements */
    int     dim_len;          /* dims length */
    int*    dims;             /* dims pointer */
    int     zero_point;       /* quant zero_point */
    float   scale;            /* quant scale */
    TfLiteType type;          /* tensor type */
    size_t  concat_offset_bytes; /* offset within concatenated view */
  };

  int input_count() const { return input_count_; }
  int output_count() const { return output_count_; }
  const std::vector<TensorMeta>& inputs_meta() const { return input_meta_; }
  const std::vector<TensorMeta>& outputs_meta() const { return output_meta_; }
  size_t input_concat_bytes() const { return input_concat_total_bytes_; }
  size_t output_concat_bytes() const { return output_concat_total_bytes_; }

 void SetInput(const inputT* custom_input, int input_index) {
    TfLiteTensor* input = interpreter_.input(input_index);
    inputT* input_buffer = tflite::GetTensorData<inputT>(input);
    /* Use memcpy instead of a for loop */
    memcpy(input_buffer, custom_input, input->bytes);
  }

  void PrintAllocations() const {
    interpreter_.GetMicroAllocator().PrintAllocations();
  }
  size_t get_used_arena_size() { return interpreter_.arena_used_bytes(); }

  int get_model_time_steps(int index=0) {
    for (int i = 0; i < input_count_; ++i) {
      if (interpreter_.input(i)->dims->size > 2) {
        return interpreter_.input(i)->dims->data[1];
      }
    }
    return interpreter_.input(0)->dims->data[1];
  }

 private:
  tflite::RecordingMicroInterpreter interpreter_;
  TfLiteStatus allocate_status_;
  /* Multi-input/output metadata and counts */
  int input_count_  = 0;
  int output_count_ = 0;
  std::vector<TensorMeta> input_meta_;
  std::vector<TensorMeta> output_meta_;
  size_t input_concat_total_bytes_ = 0;
  size_t output_concat_total_bytes_ = 0;
};

using MTB_TFLM_flt = MTBTFLiteMicro<float>;
using MTB_TFLM_int8 = MTBTFLiteMicro<int8_t>;
using MTB_TFLM_int16 = MTBTFLiteMicro<int16_t>;
using MTB_TFLM_void = MTBTFLiteMicro<void>;

} // namespace tflite

#ifdef COMPONENT_ML_INT8x8
#define MTB_TFLM_Class MTB_TFLM_int8
#elif defined COMPONENT_ML_INT16x8
#define MTB_TFLM_Class MTB_TFLM_int16
#elif defined COMPONENT_ML_FLOAT
#define MTB_TFLM_Class MTB_TFLM_flt
#else
/* A run-time type selection will be used if none from
 * list of int8 / int16 / float was selected as above */
#define MTB_TFLM_Class MTB_TFLM_void
#endif


#ifndef TFLM_RESVAR_COUNT
/* Set externally on demand by user. Disabled (0) by default */
#define TFLM_RESVAR_COUNT (0u)
#endif

#if (TFLM_RESVAR_COUNT != 0)
#if (TFLM_RESVAR_COUNT > 64)
#error "Maximum resource variables count has to be 64."
#else
static uint8_t var_arena[160 + 20 * TFLM_RESVAR_COUNT] __attribute__ ((aligned (16)));
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/*******************************************************************************
 * Public Functions
*******************************************************************************/

cy_rslt_t mtb_ml_model_init(const mtb_ml_model_bin_t *bin, const mtb_ml_model_buffer_t *buffer, mtb_ml_model_t **object)
{
    mtb_ml_model_t *model_object = NULL;
    uint8_t * arena_buffer = NULL;
    int arena_size;
    tflite::MTB_TFLM_Class * TFLMClass;
    int ret = MTB_ML_RESULT_SUCCESS;

#if ((TFLM_RESVAR_COUNT != 0) && (TFLM_RESVAR_COUNT <= 64))
    tflite::MicroAllocator *ma = nullptr;
#endif

    tflite::MicroResourceVariables *mrv = nullptr;

    /* Sanity check of input parameters */
    if (bin == NULL || bin->model_bin == NULL || object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Allocate runtime object */
    model_object = (mtb_ml_model_t *)calloc(1, sizeof(mtb_ml_model_t));

    if (model_object == NULL)
    {
        return MTB_ML_RESULT_ALLOC_ERR;
    }

    /* Copy the model name */
    memcpy(model_object->name, bin->name, MTB_ML_MODEL_NAME_LEN);

    /* Get the arena size specified in model data file */
    arena_size = bin->arena_size;
    if (buffer != NULL)
    {
        if (buffer->tensor_arena_size != 0)
        {
            /* over-write with application provided value */
            arena_size = buffer->tensor_arena_size;
        }
        arena_buffer = buffer->tensor_arena;
    }

    /* Get model and buffer size */
    model_object->model_size = bin->model_size;
    model_object->buffer_size = arena_size;

    /* Allocate tensor arena if it is not specified */
    if (arena_buffer == NULL)
    {
        /*
        *  Vela compiler in coretools is set to 16 byte alignment for tensors.
        *  May need to change if configuration is made accesible by user
        */
#if defined (__ARMCC_VERSION)
        int ret_val = posix_memalign((void **)(&(model_object->arena_buffer)), (size_t) 16, arena_size);
        if (ret_val != 0)
        {
            ret = MTB_ML_RESULT_ALLOC_ERR;
            goto ret_err;
        }
#else
        /* Allocation must be a multiple of alignment for aligned_alloc */
        model_object->arena_buffer = (uint8_t *) aligned_alloc(16, arena_size + (16 - (arena_size % 16)));
        if (model_object->arena_buffer == NULL)
        {
            ret = MTB_ML_RESULT_ALLOC_ERR;
            goto ret_err;
        }
#endif
        arena_buffer = model_object->arena_buffer;
    }

#if ((TFLM_RESVAR_COUNT != 0) && (TFLM_RESVAR_COUNT <= 64))
    ma = tflite::MicroAllocator::Create(var_arena, sizeof(var_arena));
    mrv = tflite::MicroResourceVariables::Create(ma, TFLM_RESVAR_COUNT);
#endif

    TFLMClass = new tflite::MTB_TFLM_Class(bin->model_bin, arena_buffer, arena_size, tflite::resolver, mrv);
    model_object->tflm_obj = reinterpret_cast<void *>(TFLMClass);
    if( model_object->tflm_obj == NULL)
    {
        ret = MTB_ML_RESULT_BAD_MODEL;
        goto ret_err;
    }

    /* Check Tensor allocation failure */
    if (TFLMClass->AllocationStatus() != kTfLiteOk)
    {
        ret = MTB_ML_RESULT_ALLOC_ERR;
        goto ret_err;
    }

    /* Input parameters */
    model_object->input = (MTB_ML_DATA_T *)TFLMClass->input_ptr();
    model_object->input_size = TFLMClass->input_elements();
    model_object->input_zero_point = TFLMClass->input_zero_point();
    model_object->input_scale = TFLMClass->input_scale();
    model_object->model_time_steps = TFLMClass->get_model_time_steps();
    /* Output parameters*/
    model_object->output = (MTB_ML_DATA_T *)TFLMClass->output_ptr();
    model_object->output_size = TFLMClass->output_elements();
    model_object->buffer_size = TFLMClass->get_used_arena_size();
    model_object->output_zero_point = TFLMClass->output_zero_point();
    model_object->output_scale = TFLMClass->output_scale();

    /* Multi-tensor fields */
    model_object->input_count = TFLMClass->input_count();
    model_object->output_count = TFLMClass->output_count();
    model_object->input_concat_bytes = TFLMClass->input_concat_bytes();
    model_object->output_concat_bytes = TFLMClass->output_concat_bytes();

    if (model_object->input_count > 0) {
        model_object->inputs = (mtb_ml_tensor_desc_t*)calloc(model_object->input_count, sizeof(mtb_ml_tensor_desc_t));
        for (int i = 0; i < model_object->input_count; ++i) {
            const auto& m = TFLMClass->inputs_meta()[i];
            model_object->inputs[i].ptr = (MTB_ML_DATA_T*)m.ptr;
            model_object->inputs[i].bytes = m.bytes;
            model_object->inputs[i].elements = m.elements;
            model_object->inputs[i].dim_len = m.dim_len;
            model_object->inputs[i].dims = m.dims;
            model_object->inputs[i].zero_point = m.zero_point;
            model_object->inputs[i].scale = m.scale;
            model_object->inputs[i].concat_offset_bytes = (int)m.concat_offset_bytes;
            model_object->inputs[i].type_size =
                (m.type == kTfLiteInt8) ? sizeof(int8_t) :
                (m.type == kTfLiteInt16) ? sizeof(int16_t) :
                (m.type == kTfLiteFloat32) ? sizeof(float) : 0;
        }
    }

    if (model_object->output_count > 0) {
        model_object->outputs = (mtb_ml_tensor_desc_t*)calloc(model_object->output_count, sizeof(mtb_ml_tensor_desc_t));
        for (int i = 0; i < model_object->output_count; ++i) {
            const auto& m = TFLMClass->outputs_meta()[i];
            model_object->outputs[i].ptr = (MTB_ML_DATA_T*)m.ptr;
            model_object->outputs[i].bytes = m.bytes;
            model_object->outputs[i].elements = m.elements;
            model_object->outputs[i].dim_len = m.dim_len;
            model_object->outputs[i].dims = m.dims;
            model_object->outputs[i].zero_point = m.zero_point;
            model_object->outputs[i].scale = m.scale;
            model_object->outputs[i].concat_offset_bytes = (int)m.concat_offset_bytes;
            model_object->outputs[i].type_size =
                (m.type == kTfLiteInt8) ? sizeof(int8_t) :
                (m.type == kTfLiteInt16) ? sizeof(int16_t) :
                (m.type == kTfLiteFloat32) ? sizeof(float) : 0;
        }
    }

    switch (TFLMClass->model_input_type()) {
    case kTfLiteInt8:
        model_object->input_type_size = sizeof(int8_t);
        break;
    case kTfLiteInt16:
        model_object->input_type_size = sizeof(int16_t);
        break;
    case kTfLiteFloat32:
        model_object->input_type_size = sizeof(float);
        break;
    default:
        ret = MTB_ML_RESULT_MISMATCH_DATA_TYPE;
        goto ret_err;
    }

    switch (TFLMClass->model_output_type()) {
    case kTfLiteInt8:
        model_object->output_type_size = sizeof(int8_t);
        break;
    case kTfLiteInt16:
        model_object->output_type_size = sizeof(int16_t);
        break;
    case kTfLiteFloat32:
        model_object->output_type_size = sizeof(float);
        break;
    default:
        ret = MTB_ML_RESULT_MISMATCH_DATA_TYPE;
        goto ret_err;
    }

    *object = model_object;
    return ret;
ret_err:
    free(model_object->arena_buffer);
    free(model_object);
    return ret;
}

cy_rslt_t mtb_ml_model_deinit(mtb_ml_model_t *object)
{
    /* Sanity check of input parameters */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }
    delete reinterpret_cast<tflite::MTB_TFLM_Class *>(object->tflm_obj);
    free(object->inputs);   /* Multi-input/output fields */
    free(object->outputs);  /* Multi-input/output fields */
    free(object->arena_buffer);
    free(object);

    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_inputs(const mtb_ml_model_t *object, MTB_ML_DATA_T *input_ptr, int input_index)
{
    /* Sanity check of input parameters */
    if (object == NULL || object->tflm_obj == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Validate input index bounds */
    if (input_index < 0 || input_index >= object->input_count)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Ensure source data exists */
    if (input_ptr != NULL)
    {
        tflite::MTB_TFLM_Class *Tflm = reinterpret_cast<tflite::MTB_TFLM_Class *>(object->tflm_obj);
        Tflm->SetInput(input_ptr, input_index);
    }
    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_invoke(mtb_ml_model_t *object)
{
    TfLiteStatus ret;
    /* Sanity check of input parameters */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    tflite::MTB_TFLM_Class *Tflm = reinterpret_cast<tflite::MTB_TFLM_Class *>(object->tflm_obj);

    /* Model profiling */
    if (object->profiling & MTB_ML_PROFILE_ENABLE_MODEL)
    {
        mtb_ml_model_profile_get_tsc(&object->m_cpu_cycles);
#if (!defined(COMPONENT_RTOS) && \
     (defined(COMPONENT_U55) || \
      defined(COMPONENT_NNLITE2)))
        mtb_ml_npu_cycles = 0;
#endif
    }
#if defined(COMPONENT_U55)
    if(mtb_ml_get_cache_mgmt_type() == MTB_ML_ETHOSU_CACHE_MGMT_OUTER_LAYERS)
    {
        SCB_CleanDCache_by_Addr((uint32_t *)object->input, object->input_size);
    }
#endif
    ret = Tflm->RunSingleIteration();
#if defined(COMPONENT_U55)
    if(mtb_ml_get_cache_mgmt_type() == MTB_ML_ETHOSU_CACHE_MGMT_OUTER_LAYERS)
    {
        SCB_InvalidateDCache_by_Addr((uint32_t *)object->output, object->output_size);
    }
#endif
    if ( ret != kTfLiteOk )
    {
        object->lib_error = ret;
        return MTB_ML_RESULT_INFERENCE_ERROR;
    }

    if (object->profiling & MTB_ML_PROFILE_ENABLE_MODEL)
    {
        uint64_t cycles = 0U;
        mtb_ml_model_profile_get_tsc(&cycles);
        uint64_t cpu_cycles_only = cycles - object->m_cpu_cycles;
#if (!defined(COMPONENT_RTOS) && \
     (defined(COMPONENT_U55) || \
      defined(COMPONENT_NNLITE2)))
        /* mtb_ml_init() : mtb_ml_norm_clk_freq = npu_freq/cpu_freq */
        uint64_t norm_npu_cycles = (uint64_t)(((float)mtb_ml_npu_cycles) / mtb_ml_norm_clk_freq);
        /* Check for bad cpu/npu count values so we don't overflow */
        if (norm_npu_cycles > cpu_cycles_only)
        {
            return MTB_ML_RESULT_CYCLE_COUNT_ERROR;
        }

        object->m_npu_cycles = mtb_ml_npu_cycles;
        if (object->m_npu_cycles > object->m_npu_peak_cycles)
        {
            object->m_npu_peak_cycles = object->m_npu_cycles;
            object->m_npu_peak_frame = object->m_sum_frames;
        }
        object->m_npu_sum_cycles += object->m_npu_cycles;
        /* Subtracting NPU fraction */
        cpu_cycles_only -= norm_npu_cycles;
#endif
        if (cpu_cycles_only > object->m_cpu_peak_cycles)
        {
            object->m_cpu_peak_cycles = cpu_cycles_only;
            object->m_cpu_peak_frame = object->m_sum_frames;
        }
        object->m_cpu_cycles = cpu_cycles_only;
        object->m_cpu_sum_cycles += cpu_cycles_only;
        object->m_sum_frames++;
    }
    else if (object->profiling & MTB_ML_LOG_ENABLE_MODEL_LOG)
    {
        MTB_ML_DATA_T * output_ptr = object->output;
        /**
        * This string must track ML_PROFILE_OUTPUT_STRING in mtb_ml_stream_impl.h,
        * as the header file is currently unable to be included due to conflicts.
        */
        printf(" output:");
        switch (object->output_type_size)
        {
            case sizeof(float):
                for (int j = 0; j < object->output_size; j++)
                {
                    printf("%6.3f ", (float) (((float*)output_ptr)[j]));
                }
                break;
            case sizeof(int16_t):
                for (int j = 0; j < object->output_size; j++)
                {
                    printf("%6.3f ", (float) (((int16_t*)output_ptr)[j]));
                }
                break;
            case sizeof(int8_t):
                for (int j = 0; j < object->output_size; j++)
                {
                    printf("%6.3f ", (float) (((int8_t*)output_ptr)[j]));
                }
                break;
            default:
                return MTB_ML_RESULT_MISMATCH_DATA_TYPE;
        }
        printf("\r\n");
    }

    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_run(mtb_ml_model_t *object, MTB_ML_DATA_T *input)
{
    cy_rslt_t result;

    /* Sanity check of input parameters */
    if (object == NULL || input == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Set input data for single-input model */
    result = mtb_ml_model_inputs(object, input, 0);
    if (result != MTB_ML_RESULT_SUCCESS)
    {
        return result;
    }

    /* Invoke the model */
    return mtb_ml_model_invoke(object);
}

cy_rslt_t mtb_ml_model_get_output_tensor(const mtb_ml_model_t *object, MTB_ML_DATA_T **output_pptr, int *size_ptr, int output_index)
{
    /* Sanity check of input parameters */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Validate output_index is within range */
    if (output_index < 0 || output_index >= object->output_count)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    if (output_pptr != NULL)
    {
        *output_pptr = object->outputs[output_index].ptr;
    }

    if (size_ptr != NULL)
    {
        *size_ptr = object->outputs[output_index].elements;
    }

    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_get_output(const mtb_ml_model_t *object, MTB_ML_DATA_T **output_pptr, int *size_ptr)
{
    /* Call mtb_ml_model_get_output_tensor with output_index=0 for backward compatibility */
    return mtb_ml_model_get_output_tensor(object, output_pptr, size_ptr, 0);
}

cy_rslt_t mtb_ml_model_load_output(const mtb_ml_model_t *object, MTB_ML_DATA_T **output_pptr)
{
    /* Sanity check of input parameters */
    if (object == NULL || output_pptr == NULL || *output_pptr == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }
    /* Iterate through all output tensors and concatenate them into the provided buffer */
    for (int i = 0; i < object->output_count; ++i)
    {
        const mtb_ml_tensor_desc_t *tensor = &object->outputs[i];
        uint8_t *dest = (uint8_t*)(*output_pptr) + tensor->concat_offset_bytes;
        memcpy(dest, tensor->ptr, tensor->bytes);
    }
    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_get_output_detail(const mtb_ml_model_t *object, int index, MTB_ML_DATA_T **out_pptr, size_t* size_ptr,
                                         int** dim_ptr, int* dim_len_ptr, int* zero_ptr, float* scale_ptr)
{
    /* Sanity check of input parameters */
    if (object == NULL || size_ptr == NULL || out_pptr == NULL || zero_ptr == NULL || scale_ptr == NULL || dim_len_ptr == NULL || dim_ptr == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    tflite::MTB_TFLM_Class *Tflm = reinterpret_cast<tflite::MTB_TFLM_Class *>(object->tflm_obj);

    *size_ptr	  = Tflm->output_elements(index);
    *out_pptr	  = static_cast<MTB_ML_DATA_T*>(Tflm->output_ptr(index));
    *zero_ptr 	  = Tflm->output_zero_point(index);
    *scale_ptr 	  = Tflm->output_scale(index);
    *dim_len_ptr  = Tflm->output_dims_len(index);
    *dim_ptr 	  = Tflm->output_dims(index);

    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_get_input_detail(const mtb_ml_model_t *object, int index, MTB_ML_DATA_T **in_pptr, size_t* size_ptr,
                                        int** dim_ptr, int* dim_len_ptr, int* zero_ptr, float* scale_ptr)
{
    /* Sanity check of input parameters */
    if (object == NULL || size_ptr == NULL || in_pptr == NULL || zero_ptr == NULL || scale_ptr == NULL || dim_len_ptr == NULL || dim_ptr == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    tflite::MTB_TFLM_Class	*Tflm  = reinterpret_cast<tflite::MTB_TFLM_Class *>(object->tflm_obj);

    *size_ptr	  = Tflm->input_elements(index);
    *in_pptr	  = static_cast<MTB_ML_DATA_T*>(Tflm->input_ptr(index));
    *zero_ptr 	  = Tflm->input_zero_point(index);
    *scale_ptr 	  = Tflm->input_scale(index);
    *dim_len_ptr  = Tflm->input_dims_len(index);
    *dim_ptr 	  = Tflm->input_dims(index);

    return MTB_ML_RESULT_SUCCESS;
}

int mtb_ml_model_get_input_size(const mtb_ml_model_t *object)
{
    return object->input_concat_bytes;
}

cy_rslt_t mtb_ml_model_profile_config(mtb_ml_model_t *object, mtb_ml_profile_config_t config)
{
    /* Sanity check of input parameters */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

#if defined(COMPONENT_U55)
    /* Enable PMU block */
    ETHOSU_PMU_Enable(mtb_ml_ethosu_driver_handle);
#endif

    object->profiling = config;
    if (object->profiling != MTB_ML_PROFILE_DISABLE)
    {
        object->m_sum_frames = 0;
        object->m_cpu_sum_cycles = 0;
        object->m_cpu_peak_frame = 0;
        object->m_cpu_peak_cycles = 0;
    }
#if defined(COMPONENT_U55) || \
    defined(COMPONENT_NNLITE2)
        object->m_npu_sum_cycles = 0;
        object->m_npu_peak_frame = 0;
        object->m_npu_peak_cycles = 0;
#endif
    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_profile_log(mtb_ml_model_t *object)
{
    /* Sanity check of input parameters */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    if (object->profiling & MTB_ML_PROFILE_ENABLE_MODEL)
    {
        printf("PROFILE_INFO, MTB ML model profile, avg_cpu_cyc=%-10.2f, peak_cpu_cyc=%.0f, peak_cpu_frame=%-" PRIu32 ", cpu_freq_Mhz=%-" PRIu32 "\r\n",
                (float)object->m_cpu_sum_cycles / object->m_sum_frames,
                (float)object->m_cpu_peak_cycles,
                object->m_cpu_peak_frame,
                mtb_ml_cpu_clk_freq / 1000000);
#if defined(COMPONENT_U55) || \
    defined(COMPONENT_NNLITE2)
        printf("PROFILE_INFO, MTB ML model profile, avg_npu_cyc=%-10.2f, peak_npu_cyc=%.0f, peak_npu_frame=%-" PRIu32 ", npu_freq_Mhz=%-" PRIu32 "\r\n",
                (float)object->m_npu_sum_cycles / object->m_sum_frames,
                (float)object->m_npu_peak_cycles,
                object->m_npu_peak_frame,
                mtb_ml_npu_clk_freq / 1000000);
#endif
    }

    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_rnn_reset_all_parameters(mtb_ml_model_t *object)
{
    /* Sanity check of model object parameter */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }
    tflite::MTB_TFLM_Class *Tflm = reinterpret_cast<tflite::MTB_TFLM_Class *>(object->tflm_obj);
    TfLiteStatus ret = Tflm->reset_all_variables();
    if (ret != kTfLiteOk)
    {
        object->lib_error = ret;
        return MTB_ML_RESULT_BAD_ARG;
    }
    return MTB_ML_RESULT_SUCCESS;
}

#ifdef __cplusplus
}
#endif  // __cplusplus
