/***************************************************************************//**
* \file mtb_ml_model.h
*
* \brief
* This is the header file of ModusToolbox ML middleware NN model module.
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
#if !defined(__MTB_ML_MODEL_H__)
#define __MTB_ML_MODEL_H__

#include "mtb_ml_common.h"
#include "mtb_ml_model_defs.h"

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
 * Macros
 *****************************************************************************/
#define MEM_FLAG_SHIFT_PERSISTENT       (0)
#define MEM_FLAG_SHIFT_SCRATCH          (1)

#define MTB_ML_MEM_DYNAMIC_PERSISTENT   (1 << MEM_FLAG_SHIFT_PERSISTENT)
#define MTB_ML_MEM_DYNAMIC_SCRATCH      (1 << MEM_FLAG_SHIFT_SCRATCH)

#define MTB_ML_MODEL_NAME_LEN           64
/******************************************************************************
 * Typedefs
 *****************************************************************************/

/******************************************************************************
* Public definitions
******************************************************************************/

/******************************************************************************
* Structures
******************************************************************************/
/**
 * ML model working buffer structure
 */
typedef struct
{
/** @name COMPONENT_ML_TFLM
 *  Buffer pareamters for TFLM.
 */
///@{
/** Model buffer parameters for TfLite-Micro inference engine */
    uint8_t* tensor_arena;              /**< the pointer of tensor arena buffer provided by application */
    size_t tensor_arena_size;           /**< the size of ML tensor arena buffer provided by application */
///@}
} mtb_ml_model_buffer_t;

/**
 * ML tensor descriptor structure for multi-input/output models
 */
typedef struct mtb_ml_tensor_desc {
/** @name Multi-tensor descriptor fields
 *  Descriptor for individual tensors in multi-input/output models.
 */
///@{
    MTB_ML_DATA_T* ptr;                 /**< Pointer to tensor data buffer */
    size_t bytes;                       /**< Size of tensor in bytes */
    size_t elements;                    /**< Total number of elements in tensor */
    int dim_len;                        /**< Number of dimensions */
    int* dims;                          /**< Pointer to array of dimension sizes */
    int zero_point;                     /**< Quantization zero point */
    float scale;                        /**< Quantization scale factor */
    int concat_offset_bytes;            /**< Offset in bytes within concatenated buffer */
    uint8_t type_size;                  /**< Size of individual element in bytes */
///@}
} mtb_ml_tensor_desc_t;

/**
 * ML model structure
 */
typedef struct
{
/** @name
 *  Model name
 */
/**@{*/
    char name[MTB_ML_MODEL_NAME_LEN];   /**< the name of ML model */
/**@}*/
#if defined(COMPONENT_ML_TFLM)
/** @name COMPONENT_ML_TFLM
 *  Model parameters for TFLM with interpreter
 */
///@{
    const uint8_t *      model_bin;     /**< the pointer of Tflite model */
    const unsigned int   model_size;    /**< the size of Tflite model */
    const int            arena_size;    /**< the size of arena buffer for Tflite model */
///@}
#endif
#if defined(COMPONENT_ML_TFLM_LESS)
/** @name COMPONENT_ML_TFLM_LESS
 *  Model parameters for TFLM without interpreter
 */
///@{
    tflm_rmf_apis_t      rmf_bin;     /**< the data structure of Tflite APIs */
///@}
#endif
} mtb_ml_model_bin_t;

/**
 * ML model runtime object structure
 */
typedef struct
{
/** @name
 *  Model runtime object common fields
 */
/**@{*/
    char name[MTB_ML_MODEL_NAME_LEN];   /**< the name of ML model */
    int model_size;                     /**< the size of ML model */
    int buffer_size;                    /**< the size of ML model working buffer */
    int input_size;                     /**< array size of input data */
    int output_size;                    /**< array size of output data */
    int lib_error;                      /**< error code from ML inference library */
    MTB_ML_DATA_T *output;              /**< pointer of ML inference output buffer */
    MTB_ML_DATA_T *input;               /**< pointer of ML inference input buffer */
    int input_type_size;                /**< sizeof(input data) */
    int output_type_size;               /**< sizeof(output data) */
    void *tflm_obj;                     /**< pointer of Tflite-micro runtime object */
    int model_time_steps;               /**< number of model time steps */
    int recurrent_ts_size;              /**< number of data time steps in NN. 0 if non streaming RNN */
    int input_zero_point;               /**< zero point of input data */
    float input_scale;                  /**< scale of input data*/
    int output_zero_point;              /**< zero point of output data */
    float output_scale;                 /**< scale of output data */
    int input_count;                    /**< number of input tensors in multi-input models */
    int output_count;                   /**< number of output tensors in multi-output models */
    size_t input_concat_bytes;          /**< total size in bytes of all input tensors concatenated */
    size_t output_concat_bytes;         /**< total size in bytes of all output tensors concatenated */
    mtb_ml_tensor_desc_t* inputs;       /**< pointer to array of input tensor descriptors (size: input_count) */
    mtb_ml_tensor_desc_t* outputs;      /**< pointer to array of output tensor descriptors (size: output_count) */
    mtb_ml_profile_config_t profiling;  /**< flags of profiling */
    uint64_t m_cpu_cycles;              /**< CPU profiling cycles */
    uint32_t m_sum_frames;              /**< profiling frames */
    uint64_t m_cpu_sum_cycles;          /**< CPU profiling total cycles */
    uint32_t m_cpu_peak_frame;          /**< CPU profiling peak frame */
    uint64_t m_cpu_peak_cycles;         /**< CPU profiling peak cycles */
    bool is_rnn_streaming;              /**< Is the model an RNN streaming model */
/**@}*/
#if defined(COMPONENT_U55) || \
    defined(COMPONENT_NNLITE2)
/** @name COMPONENT_U55
 *  Model runtime object fields for NPU cycle count
 */
/**@{*/
    uint64_t m_npu_cycles;          /**< NPU profiling cycles */
    uint64_t m_npu_sum_cycles;      /**< NPU total cycles */
    uint32_t m_npu_peak_frame;      /**< NPU profiling peak frame */
    uint64_t m_npu_peak_cycles;     /**< NPU profiling peak cycles */
/**@}*/
#endif
#if defined(COMPONENT_ML_TFLM)
/** @name COMPONENT_ML_TFLM
 *  Model runtime object fields for TFLM with interpreter
 */
/**@{*/
    uint8_t *arena_buffer;              /**< pointer of allocated tensor arena buffer */
#endif
#if defined(COMPONENT_ML_TFLM_LESS)
/** @name COMPONENT_ML_TFLM_LESS
 *  Model runtime object fields for TFLM without interpreter
 */
/**@{*/
    tflm_rmf_apis_t rmf_apis;           /**< data structure of Tflite-micro APIs */
/**@}*/
#endif
} mtb_ml_model_t;

/******************************************************************************
* Function prototype
******************************************************************************/
/**
 * \addtogroup Model_API
 * @{
 */

/**
 * \brief : Allocate and initialize NN model runtime object based on model data. Only intended to be called once.
 *
 * \param[in]   bin      : Pointer of model binary data.
 * \param[in]   buffer   : Pointer of buffer data structure for statically allocated persistent and scratch buffer.
 *                         This is optional, if no passed-in buffer, the API will allocate memory as persistent and
 *                         scratch buffer.
 * \param[out] object    : Pointer of model object.
 *
 * \return               : MTB_ML_RESULT_SUCCESS - success
 *                       : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 *                       : MTB_ML_RESULT_ALLOC_ERR - if memory allocation failure.
 *                       : MTB_ML_RESULT_BAD_MODEL - if model parsing or initialization error.
 */
cy_rslt_t mtb_ml_model_init(const mtb_ml_model_bin_t *bin, const mtb_ml_model_buffer_t *buffer, mtb_ml_model_t **object);

/**
 * \brief : Delete NN model runtime object and free all dynamically allocated memory. Only intended to be called once.
 *
 * \param[in] object     : Pointer of model object.
 *
 * \return               : MTB_ML_RESULT_SUCCESS - success
 *                       : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 */
cy_rslt_t mtb_ml_model_deinit(mtb_ml_model_t *object);

/**
 * \brief : Set input data for a specific input tensor of the NN model
 *
 * For models with multiple inputs, this function must be called for each input tensor
 * before calling mtb_ml_model_run(). For single-input models, call once with input_index=0.
 *
 * \param[in] object        : Pointer of model object.
 * \param[in] input         : Pointer of input data buffer for the specified tensor
 * \param[in] input_index   : Index of the input tensor (0 to input_count-1)
 *
 * \return                  : MTB_ML_RESULT_SUCCESS - success
 *                          : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid or input_index is out of range.
 */
cy_rslt_t mtb_ml_model_inputs(const mtb_ml_model_t *object, MTB_ML_DATA_T *input, int input_index);

/**
 * \brief : Perform NN model inference (low-level function)
 *
 * This function performs model inference without handling input data.
 * All input tensors must be set using mtb_ml_model_inputs() before calling this function.
 * For single-input models, consider using mtb_ml_model_run() instead.
 *
 * \param[in] object     : Pointer of model object.
 *
 * \return               : MTB_ML_RESULT_SUCCESS - success
 *                       : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 *                       : MTB_ML_RESULT_INFERENCE_ERROR - if inference failure
 */
cy_rslt_t mtb_ml_model_invoke(mtb_ml_model_t *object);

/**
 * \brief : Perform NN model inference (convenience wrapper for single-input models)
 *
 * This is a convenience function for single-input models that combines setting the input
 * and invoking the model. For multi-input models, use mtb_ml_model_inputs() followed by
 * mtb_ml_model_invoke().
 *
 * \param[in] object     : Pointer of model object.
 * \param[in] input      : Pointer of input data buffer
 *
 * \return               : MTB_ML_RESULT_SUCCESS - success
 *                       : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 *                       : MTB_ML_RESULT_INFERENCE_ERROR - if inference failure
 */
cy_rslt_t mtb_ml_model_run(mtb_ml_model_t *object, MTB_ML_DATA_T *input);

/**
 * \brief : Get NN model input data size
 *
 * \param[in] object     : Pointer of model object.
 *
 * \return               : Input data size
 *                       : 0 - if input parameter is invalid.
 */
int mtb_ml_model_get_input_size(const mtb_ml_model_t *object);

/**
 * \brief : Get NN model input details
 *
 * \param[in]  object        : Pointer of model object.
 * \param[in] index         : Input tensor index
 * \param[in] in_pptr       : Pointer of models input data
 * \param[in] size_ptr      : Pointer to contain size of model input data
 * \param[in] dim_ptr       : Pointer to model dimensions
 * \param[in] dim_len_ptr   : Pointer to model dimension length
 * \param[in] zero_ptr      : Pointer to model input zero point
 * \param[in] scale_ptr     : Pointer to model input scale
 *
 * \return                   : MTB_ML_RESULT_SUCCESS - success
 *                           : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 */
cy_rslt_t mtb_ml_model_get_input_detail(const mtb_ml_model_t *object, int index, MTB_ML_DATA_T **in_pptr, size_t* size_ptr,
                                        int** dim_ptr, int* dim_len_ptr, int* zero_ptr, float* scale_ptr);
/**
 * \brief : Get NN model output buffer and size for a specific output tensor
 *
 * For models with multiple outputs, this function retrieves the output buffer and size
 * for a specific output tensor. For single-output models, use output_index=0.
 *
 * \param[in] object        : Pointer of model object.
 * \param[out] out_pptr     : Pointer of output buffer pointer
 * \param[out] size_ptr     : Pointer of output size (number of elements)
 * \param[in] output_index  : Index of the output tensor (0 to output_count-1)
 *
 * \return                  : MTB_ML_RESULT_SUCCESS - success
 *                          : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid or output_index is out of range.
 */
cy_rslt_t mtb_ml_model_get_output_tensor(const mtb_ml_model_t *object, MTB_ML_DATA_T **out_pptr, int* size_ptr, int output_index);

/**
 * \brief : Get NN model output buffer and size (convenience wrapper for single-output models)
 *
 * This is a convenience function for single-output models that retrieves the first output tensor.
 * For multi-output models, use mtb_ml_model_get_output_tensor() instead.
 *
 * \param[in] object     : Pointer of model object.
 * \param[out] out_pptr  : Pointer of output buffer pointer
 * \param[out] size_ptr  : Pointer of output size
 *
 * \return               : MTB_ML_RESULT_SUCCESS - success
 *                       : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 */
cy_rslt_t mtb_ml_model_get_output(const mtb_ml_model_t *object, MTB_ML_DATA_T **out_pptr, int* size_ptr);

/**
 * \brief : Load and concatenate all output tensors into a single buffer
 *
 * For multi-output models, this function copies and concatenates data from all output tensors
 * into a single pre-allocated buffer. The concatenation follows the order of output tensors
 * using their concat_offset_bytes values.
 *
 * \param[in] object        : Pointer of model object.
 * \param[in] output_pptr   : Pointer to pre-allocated output buffer pointer.
 *                            Buffer must be at least object->output_concat_bytes in size.
 *
 * \return                  : MTB_ML_RESULT_SUCCESS - success
 *                          : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 */
cy_rslt_t mtb_ml_model_load_output(const mtb_ml_model_t *object, MTB_ML_DATA_T **output_pptr);

/**
 * \brief : Get NN model output details
 *
 * \param[in] object        : Pointer of model object.
 * \param[in] index         : Output tensor index
 * \param[in] out_pptr      : Pointer of models output data
 * \param[in] size_ptr      : Pointer to contain size of model output data
 * \param[in] dim_ptr       : Pointer to model dimensions
 * \param[in] dim_len_ptr   : Pointer to model dimension length
 * \param[in] zero_ptr      : Pointer to model output zero point
 * \param[in] scale_ptr     : Pointer to model output scale
 *
 * \return                   : MTB_ML_RESULT_SUCCESS - success
 *                           : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 */
cy_rslt_t mtb_ml_model_get_output_detail(const mtb_ml_model_t *object, int index, MTB_ML_DATA_T **out_pptr, size_t* size_ptr,
                                         int** dim_ptr, int* dim_len_ptr, int* zero_ptr, float* scale_ptr);

/**
 * \brief : Reset model parameters
 *
 * \param[in] object     : Pointer of model object.
 *
 * \return               : MTB_ML_RESULT_SUCCESS - success
 *                       : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 */
cy_rslt_t mtb_ml_model_rnn_reset_all_parameters(mtb_ml_model_t *object);

/**
 * \brief : Get MTB ML inference runtime object
 *
 * \param[in] object     : Pointer of model object.
 *
 * \return               : Pointer of inference object
 *                       : NULL - if input parameter is invalid.
 */
void* mtb_ml_model_get_inference_object(const mtb_ml_model_t *object);

/**
 * \brief : Read time stamp counter (TSC) .
 *
 * Platform specific function to read HW time stamp counter or OS tick timer counter for profiling.
 * The application program developer should provide this function if profiling is enabled.
 *
 * \param[out]   val        : Pointer to time stamp counter return value
 *
 * \return                  : Return 0 when success, otherwise return error code
 */
int mtb_ml_model_profile_get_tsc(uint64_t *val);

/**
 * \brief : Update MTB ML inference profiling setting
 *
 * \param[in] object    : Pointer of model object's pointer.
 * \param[in] config     : Profiling setting
 *
 * \return               : MTB_ML_RESULT_SUCCESS - success
 *                       : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 */
cy_rslt_t mtb_ml_model_profile_config(mtb_ml_model_t *object, mtb_ml_profile_config_t config);

/**
 * \brief : Generate MTB ML profiling log
 *
 * \param[in] object     : Pointer of model object.
 *
 * \return               : MTB_ML_RESULT_SUCCESS - success
 *                       : MTB_ML_RESULT_BAD_ARG - if input parameter is invalid.
 */
cy_rslt_t mtb_ml_model_profile_log(mtb_ml_model_t *object);

/**
 * @} end of Model_API group
 */

#if defined(__cplusplus)
}
#endif

#endif /* __MTB_ML_MODEL_H__ */
