/******************************************************************************
* File Name: mtb_ml_model_defs.h
*
* Description: This is the header file of macros define for TFLM inference
* without interpreter
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
#ifndef __MTB_ML_MODEL_DEFS_H__
#define __MTB_ML_MODEL_DEFS_H__

/*******************************************************************************
 * Include header file
 ******************************************************************************/
#include "tensorflow/lite/c/common.h"

/******************************************************************************
 * Typedef
 *****************************************************************************/
typedef size_t (*tflm_rmf_inputs) (void);
typedef size_t (*tflm_rmf_outputs) (void);
typedef void * (*tflm_rmf_input_ptr) (int);
typedef size_t (*tflm_rmf_input_size) (int);
typedef int *  (*tflm_rmf_input_dims) (int);
typedef int    (*tflm_rmf_input_dims_len) (int);
typedef void * (*tflm_rmf_output_ptr) (int);
typedef size_t (*tflm_rmf_output_size) (int);
typedef int *  (*tflm_rmf_output_dims) (int);
typedef int    (*tflm_rmf_output_dims_len) (int);
typedef TfLiteStatus (*tflm_rmf_init) (void);
typedef TfLiteStatus (*tflm_rmf_invoke) (void);
typedef TfLiteStatus (*tflm_rmf_reset) (void);
typedef TfLiteTensor* (*tflm_rmf_input) (int);
typedef TfLiteTensor* (*tflm_rmf_output) (int index);

/******************************************************************************
 * Structure
 *****************************************************************************/
/**
 * API object data structure
 */
typedef struct
{
    tflm_rmf_inputs model_inputs;                   /**< Pointer to function that returns the number of input tensors */
    tflm_rmf_outputs model_outputs;                 /**< Pointer to function that returns the number of output tensors */
    tflm_rmf_input model_input;                     /**< Pointer to function that returns the input context */
    tflm_rmf_output model_output;                   /**< Pointer to function that returns the output context */
    tflm_rmf_input_ptr model_input_ptr;             /**< Pointer to function that returns the input data */
    tflm_rmf_input_size model_input_size;           /**< Pointer to function that returns the input data size */
    tflm_rmf_input_dims model_input_dims;           /**< Pointer to function that returns the input dimention */
    tflm_rmf_input_dims_len model_input_dims_len;   /**< Pointer to function that returns the input dimemtion size */
    tflm_rmf_output_ptr model_output_ptr;           /**< Pointer to function that returns the output data */
    tflm_rmf_output_size model_output_size;         /**< Pointer to function that returns the output data size */
    tflm_rmf_output_dims model_output_dims;         /**< Pointer to function that returns the output dimention */
    tflm_rmf_output_dims_len model_output_dims_len; /**< Pointer to function that returns the output dimention size */
    tflm_rmf_init model_init;                       /**< Pointer to function that initializes the model */
    tflm_rmf_invoke model_invoke;                   /**< Pointer to function that invokes the model */
    tflm_rmf_reset model_reset;                     /**< Pointer to function that resets variable tensors*/
    int model_data_size;                            /**< model data size */
    int model_buffer_size;                          /**< model runtime buffer size */
} tflm_rmf_apis_t;

/******************************************************************************
 * Typedefs
 *****************************************************************************/
/**
 * A type definition for MTB ML Model's input/output data
 */
#if defined(COMPONENT_ML_INT16x8)
typedef int16_t MTB_ML_DATA_T;
#elif defined(COMPONENT_ML_INT8x8)
typedef int8_t MTB_ML_DATA_T;
#elif defined(COMPONENT_ML_FLOAT32)
typedef float MTB_ML_DATA_T;
#else
/* Run-time type detect */
typedef void MTB_ML_DATA_T;
#endif

/******************************************************************************
 * Macros
 *****************************************************************************/
#define EXPANDSTR(x) x
#define STRINGIFY(x) #x
#define EXPAND_AND_STRINGIFY(x) STRINGIFY(x)
#define CONCAT(X,Y) X##Y

#define TFLM_RMF_CONCAT(x,y)                 EXPANDSTR(CONCAT(x,y))
#define INCLUDE_FILE(x,y)                    EXPAND_AND_STRINGIFY(CONCAT(x,y))
#define MODEL_DATA_BIN(x,y)                  EXPANDSTR(CONCAT(x,y))


#define TFLM_RMF_INIT(m)                     TFLM_RMF_CONCAT(m,_init)
#define TFLM_RMF_INPUT(m)                    TFLM_RMF_CONCAT(m,_input)
#define TFLM_RMF_OUTPUT(m)                   TFLM_RMF_CONCAT(m,_output)
#define TFLM_RMF_INPUTS(m)                   TFLM_RMF_CONCAT(m,_inputs)
#define TFLM_RMF_OUTPUTS(m)                  TFLM_RMF_CONCAT(m,_outputs)
#define TFLM_RMF_INVOKE(m)                   TFLM_RMF_CONCAT(m,_invoke)
#define TFLM_RMF_RESET(m)                    TFLM_RMF_CONCAT(m,_reset)
#define TFLM_RMF_INPUT_PTR(m)                TFLM_RMF_CONCAT(m,_input_ptr)
#define TFLM_RMF_INPUT_SIZE(m)               TFLM_RMF_CONCAT(m,_input_size)
#define TFLM_RMF_INPUT_DIMS(m)               TFLM_RMF_CONCAT(m,_input_dims)
#define TFLM_RMF_INPUT_DIMS_LEN(m)           TFLM_RMF_CONCAT(m,_input_dims_len)
#define TFLM_RMF_OUTPUT_PTR(m)               TFLM_RMF_CONCAT(m,_output_ptr)
#define TFLM_RMF_OUTPUT_SIZE(m)              TFLM_RMF_CONCAT(m,_output_size)
#define TFLM_RMF_OUTPUT_DIMS(m)              TFLM_RMF_CONCAT(m,_output_dims)
#define TFLM_RMF_OUTPUT_DIMS_LEN(m)          TFLM_RMF_CONCAT(m,_output_dims_len)

#define TFLM_RMF_MODEL_CONST_DATA_SIZE(m)    TFLM_RMF_CONCAT(m,_MODEL_CONST_DATA_SIZE)
#define TFLM_RMF_MODEL_INIT_DATA_SIZE(m)     TFLM_RMF_CONCAT(m,_MODEL_INIT_DATA_SIZE)
#define TFLM_RMF_MODEL_UNINIT_DATA_SIZE(m)   TFLM_RMF_CONCAT(m,_MODEL_UNINIT_DATA_SIZE)

#define TFLM_RMF_MODEL_OBJECT(m)  \
                  { \
                    .model_inputs          = TFLM_RMF_INPUTS(m), \
                    .model_outputs         = TFLM_RMF_OUTPUTS(m), \
                    .model_input           = TFLM_RMF_INPUT(m), \
                    .model_output          = TFLM_RMF_OUTPUT(m), \
                    .model_input_ptr       = TFLM_RMF_INPUT_PTR(m), \
                    .model_input_size      = TFLM_RMF_INPUT_SIZE(m), \
                    .model_input_dims      = TFLM_RMF_INPUT_DIMS(m), \
                    .model_input_dims_len  = TFLM_RMF_INPUT_DIMS_LEN(m), \
                    .model_output_ptr      = TFLM_RMF_OUTPUT_PTR(m), \
                    .model_output_size     = TFLM_RMF_OUTPUT_SIZE(m), \
                    .model_output_dims     = TFLM_RMF_OUTPUT_DIMS(m), \
                    .model_output_dims_len = TFLM_RMF_OUTPUT_DIMS_LEN(m), \
                    .model_init            = TFLM_RMF_INIT(m), \
                    .model_invoke          = TFLM_RMF_INVOKE(m), \
                    .model_reset           = TFLM_RMF_RESET(m), \
                    .model_data_size       = TFLM_RMF_MODEL_CONST_DATA_SIZE(m), \
                    .model_buffer_size     = TFLM_RMF_MODEL_INIT_DATA_SIZE(m) + \
                                             TFLM_RMF_MODEL_UNINIT_DATA_SIZE(m) \
                  }


#if defined(COMPONENT_ML_FLOAT32)
#define ML_INCLUDE_MODEL_FILE_IMPL(m)          INCLUDE_FILE(m,_tflm_less_model_float.h)
#define ML_INCLUDE_MODEL_X_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_x_data_float.h)
#define ML_INCLUDE_MODEL_Y_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_y_data_float.h)
#elif defined(COMPONENT_ML_INT8x8)
#define ML_INCLUDE_MODEL_FILE_IMPL(m)          INCLUDE_FILE(m,_tflm_less_model_int8x8.h)
#define ML_INCLUDE_MODEL_X_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_x_data_int8x8.h)
#define ML_INCLUDE_MODEL_Y_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_y_data_int8x8.h)
#elif defined(COMPONENT_ML_INT16x8)
#define ML_INCLUDE_MODEL_FILE_IMPL(m)          INCLUDE_FILE(m,_tflm_less_model_int16x8.h)
#define ML_INCLUDE_MODEL_X_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_x_data_int16x8.h)
#define ML_INCLUDE_MODEL_Y_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_y_data_int16x8.h)
#else
  /* Need to do model and regression types inclusion manually, without macros-es.
   * See readme.md for examples. */
#endif

#define ML_MODEL_X_DATA_BIN_IMPL(m)            MODEL_DATA_BIN(m,_x_data_bin)
#define ML_MODEL_Y_DATA_BIN_IMPL(m)            MODEL_DATA_BIN(m,_y_data_bin)

#define ML_MODEL_NAME_STR_IMPL(m)              EXPAND_AND_STRINGIFY(m)
#define ML_MODEL_BIN_IMPL(m)                   MTB_ML_TFLM_RMF_MODEL_BIN(m)

#define ML_MODEL_BIN_DATA_IMPL(x)              MTB_ML_MODEL_NAME_STR(x), \
                                               TFLM_RMF_MODEL_OBJECT(x)

#define ML_MODEL_INFERENCE_ERROR_IMPL(err) \
    do { \
           printf("Inference error: Tflite-Micro status: %d \r\n", err); \
    } while(0)


#endif /* __MTB_ML_MODEL_DEFS_H__ */
