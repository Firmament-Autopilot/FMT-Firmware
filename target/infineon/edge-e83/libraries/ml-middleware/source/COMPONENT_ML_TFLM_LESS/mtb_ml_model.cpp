/******************************************************************************
* File Name: mtb_ml_model.cpp
*
* Description: This file contains API calls to initialize and invoke Tflite-Micro
*              inference without interpreter for model generated from
*              MTB ML software.
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "mtb_ml.h"
#include <tensorflow/lite/kernels/kernel_util.h>

extern "C" {

/* LCOV_EXCL_START (Excluded from the code coverage, until the STOP marker) */
int __attribute__((weak)) mtb_ml_model_profile_get_tsc(uint64_t *val)
{
    return 0;
}
/* LCOV_EXCL_STOP */

}

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

static int input_elements(tflm_rmf_apis_t *rmf_api, int index)
{
    int count = 1;
    for (int i = 0; i < rmf_api->model_input_dims_len(index); ++i)
    {
        count *= rmf_api->model_input_dims(index)[i];
    }
    return count;
}

static int output_elements(tflm_rmf_apis_t *rmf_api, int index)
{
    int count = 1;
    for (int i = 0; i < rmf_api->model_output_dims_len(index); ++i)
    {
        count *= rmf_api->model_output_dims(index)[i];
    }
    return count;
}

static MTB_ML_DATA_T * input_ptr(tflm_rmf_apis_t *rmf_api, int index)
{
    return (MTB_ML_DATA_T *) rmf_api->model_input_ptr(index);
}

static MTB_ML_DATA_T * output_ptr(tflm_rmf_apis_t *rmf_api, int index)
{
    return (MTB_ML_DATA_T *) rmf_api->model_output_ptr(index);
}

/*******************************************************************************
 * Public Functions
*******************************************************************************/
cy_rslt_t mtb_ml_model_init(const mtb_ml_model_bin_t *bin, const mtb_ml_model_buffer_t *buffer, mtb_ml_model_t **object)
{
    mtb_ml_model_t *model_object = NULL;
    (void) buffer;

    /* Sanity check of input parameters */
    if (bin == NULL || object == NULL)
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

    /* Get model API structure */
    model_object->rmf_apis = bin->rmf_bin;
    model_object->tflm_obj = (void *)&model_object->rmf_apis;

    /* Get model and buffer size */
    model_object->model_size = bin->rmf_bin.model_data_size;
    model_object->buffer_size = bin->rmf_bin.model_buffer_size;

    /* Init the model */
    tflm_rmf_apis_t * rmf_api = (tflm_rmf_apis_t *) model_object->tflm_obj;
    if ( rmf_api->model_init() != kTfLiteOk )
    {
        free(model_object);
        return MTB_ML_RESULT_BAD_MODEL;
    }

    /* Get model parameters */
    /* Input parameters */
    model_object->input = input_ptr(rmf_api, 0);
    model_object->input_size = input_elements(rmf_api, 0);
    model_object->input_zero_point = rmf_api->model_input(0)->params.zero_point;
    model_object->input_scale = rmf_api->model_input(0)->params.scale;
    /* Output parameters*/
    model_object->output = output_ptr(rmf_api, 0);
    model_object->output_size = output_elements(rmf_api, 0);
    model_object->output_zero_point = rmf_api->model_output(0)->params.zero_point;
    model_object->output_scale = rmf_api->model_output(0)->params.scale;

    /* Multi-tensor fields */
    model_object->input_count = rmf_api->model_inputs();
    model_object->output_count = rmf_api->model_outputs();

    /* Calculate time steps for multi-input models */
    model_object->model_time_steps = rmf_api->model_input(0)->dims->data[1];
    for (int i = 0; i < model_object->input_count; ++i) {
        if (rmf_api->model_input(i)->dims->size > 2) {
            model_object->model_time_steps = rmf_api->model_input(i)->dims->data[1];
            break;
        }
    }

    /* Calculate concatenated sizes */
    model_object->input_concat_bytes = 0;
    for (int i = 0; i < model_object->input_count; ++i) {
        model_object->input_concat_bytes += rmf_api->model_input_size(i);
    }
    model_object->output_concat_bytes = 0;
    for (int i = 0; i < model_object->output_count; ++i) {
        model_object->output_concat_bytes += rmf_api->model_output_size(i);
    }

    if (model_object->input_count > 0) {
        model_object->inputs = (mtb_ml_tensor_desc_t*)calloc(model_object->input_count, sizeof(mtb_ml_tensor_desc_t));
        if (model_object->inputs == NULL) {
            free(model_object);
            return MTB_ML_RESULT_ALLOC_ERR;
        }
        int concat_offset = 0;
        for (int i = 0; i < model_object->input_count; ++i) {
            const TfLiteTensor* t = rmf_api->model_input(i);
            model_object->inputs[i].ptr = (MTB_ML_DATA_T*)rmf_api->model_input_ptr(i);
            model_object->inputs[i].bytes = rmf_api->model_input_size(i);
            model_object->inputs[i].elements = input_elements(rmf_api, i);
            model_object->inputs[i].dim_len = rmf_api->model_input_dims_len(i);
            model_object->inputs[i].dims = rmf_api->model_input_dims(i);
            model_object->inputs[i].zero_point = t->params.zero_point;
            model_object->inputs[i].scale = t->params.scale;
            model_object->inputs[i].concat_offset_bytes = concat_offset;
            model_object->inputs[i].type_size =
                (t->type == kTfLiteInt8) ? sizeof(int8_t) :
                (t->type == kTfLiteInt16) ? sizeof(int16_t) :
                (t->type == kTfLiteFloat32) ? sizeof(float) : 0;
            concat_offset += model_object->inputs[i].bytes;
        }
    }

    if (model_object->output_count > 0) {
        model_object->outputs = (mtb_ml_tensor_desc_t*)calloc(model_object->output_count, sizeof(mtb_ml_tensor_desc_t));
        if (model_object->outputs == NULL) {
            free(model_object->inputs);
            free(model_object);
            return MTB_ML_RESULT_ALLOC_ERR;
        }
        int concat_offset = 0;
        for (int i = 0; i < model_object->output_count; ++i) {
            const TfLiteTensor* t = rmf_api->model_output(i);
            model_object->outputs[i].ptr = (MTB_ML_DATA_T*)rmf_api->model_output_ptr(i);
            model_object->outputs[i].bytes = rmf_api->model_output_size(i);
            model_object->outputs[i].elements = output_elements(rmf_api, i);
            model_object->outputs[i].dim_len = rmf_api->model_output_dims_len(i);
            model_object->outputs[i].dims = rmf_api->model_output_dims(i);
            model_object->outputs[i].zero_point = t->params.zero_point;
            model_object->outputs[i].scale = t->params.scale;
            model_object->outputs[i].concat_offset_bytes = concat_offset;
            model_object->outputs[i].type_size =
                (t->type == kTfLiteInt8) ? sizeof(int8_t) :
                (t->type == kTfLiteInt16) ? sizeof(int16_t) :
                (t->type == kTfLiteFloat32) ? sizeof(float) : 0;
            concat_offset += model_object->outputs[i].bytes;
        }
    }

    switch (rmf_api->model_input(0)->type) {
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
        return MTB_ML_RESULT_MISMATCH_DATA_TYPE;
    }

    switch (rmf_api->model_output(0)->type) {
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
        return MTB_ML_RESULT_MISMATCH_DATA_TYPE;
    }

    *object = model_object;
    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_deinit(mtb_ml_model_t *object)
{
    /* Sanity check of input parameters */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    free(object->inputs);
    free(object->outputs);
    free(object);

    return MTB_ML_RESULT_SUCCESS;
}

cy_rslt_t mtb_ml_model_inputs(const mtb_ml_model_t *object, MTB_ML_DATA_T *input_ptr, int input_index)
{
    /* Sanity check of input parameters */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Validate input_index is within range */
    if (input_index < 0 || input_index >= object->input_count)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Ensure source data exists */
    if (input_ptr != NULL)
    {
        tflm_rmf_apis_t *rmf_api = (tflm_rmf_apis_t *) object->tflm_obj;
        memcpy(rmf_api->model_input_ptr(input_index), input_ptr, rmf_api->model_input_size(input_index));
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

    tflm_rmf_apis_t *rmf_api = (tflm_rmf_apis_t *) object->tflm_obj;

    /* Model profiling */
    if (object->profiling & MTB_ML_PROFILE_ENABLE_MODEL)
    {
        mtb_ml_model_profile_get_tsc(&object->m_cpu_cycles);
#if (!defined(COMPONENT_RTOS) && \
      defined(COMPONENT_NNLITE2))
        mtb_ml_npu_cycles = 0;
#endif
    }
    ret = rmf_api->model_invoke();
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
      defined(COMPONENT_NNLITE2))
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
       * This string must track ML_PROFILE_OUTPUT_STRING in mtb_ml_stream.c,
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

    tflm_rmf_apis_t * rmf_api = (tflm_rmf_apis_t *) object->tflm_obj;

    *size_ptr	 = output_elements(rmf_api, index);
    *out_pptr	 = output_ptr(rmf_api, index);
    *zero_ptr 	 = rmf_api->model_output(index)->params.zero_point;
    *scale_ptr 	 = rmf_api->model_output(index)->params.scale;
    *dim_len_ptr = rmf_api->model_output_dims_len(index);

    TfLiteIntArray* dims = rmf_api->model_output(index)->dims;
    for (int i = 0; i < dims->size; ++i) {
        (*dim_ptr)[i] = dims->data[i];
    }

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

    tflm_rmf_apis_t * rmf_api = (tflm_rmf_apis_t *) object->tflm_obj;

    *size_ptr	 = input_elements(rmf_api, index);
    *in_pptr	 = input_ptr(rmf_api, index);
    *zero_ptr 	 = rmf_api->model_input(index)->params.zero_point;
    *scale_ptr 	 = rmf_api->model_input(index)->params.scale;
    *dim_len_ptr = rmf_api->model_input_dims_len(index);

    TfLiteIntArray* dims = rmf_api->model_input(index)->dims;
    for (int i = 0; i < dims->size; ++i) {
        (*dim_ptr)[i] = dims->data[i];
    }

    return MTB_ML_RESULT_SUCCESS;
}

int mtb_ml_model_get_input_size(const mtb_ml_model_t *object)
{
    return object->input_size;
}

cy_rslt_t mtb_ml_model_profile_config(mtb_ml_model_t *object, mtb_ml_profile_config_t config)
{
    /* Sanity check of input parameters */
    if (object == NULL)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

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
    tflm_rmf_apis_t * rmf_api = (tflm_rmf_apis_t *) object->tflm_obj;
    if ( rmf_api->model_reset() != kTfLiteOk )
    {
        return MTB_ML_RESULT_BAD_ARG;
    }
    return MTB_ML_RESULT_SUCCESS;
}

/* LCOV_EXCL_STOP */

#ifdef __cplusplus
}
#endif  // __cplusplus
