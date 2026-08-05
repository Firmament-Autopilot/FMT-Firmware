/******************************************************************************
* File Name: mtb_ml_model_defs.h
*
* Description: This file contains macro defines for TFLM with interptreter
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

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "cy_result.h"

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

#define INCLUDE_FILE(x,y)                    EXPAND_AND_STRINGIFY(CONCAT(x,y))
#define MODEL_DATA_BIN(x,y)                  EXPANDSTR(CONCAT(x,y))
#define MODEL_DATA_LEN(x,y)                  EXPANDSTR(CONCAT(x,y))

#if defined(COMPONENT_ML_FLOAT32)
#define ML_INCLUDE_MODEL_FILE_IMPL(m)          INCLUDE_FILE(m,_tflm_model_float.h)
#define ML_INCLUDE_MODEL_X_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_x_data_float.h)
#define ML_INCLUDE_MODEL_Y_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_y_data_float.h)
#elif defined(COMPONENT_ML_INT8x8)
#define ML_INCLUDE_MODEL_FILE_IMPL(m)          INCLUDE_FILE(m,_tflm_model_int8x8.h)
#define ML_INCLUDE_MODEL_X_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_x_data_int8x8.h)
#define ML_INCLUDE_MODEL_Y_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_y_data_int8x8.h)
#elif defined(COMPONENT_ML_INT16x8)
#define ML_INCLUDE_MODEL_FILE_IMPL(m)          INCLUDE_FILE(m,_tflm_model_int16x8.h)
#define ML_INCLUDE_MODEL_X_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_x_data_int16x8.h)
#define ML_INCLUDE_MODEL_Y_DATA_FILE_IMPL(m)   INCLUDE_FILE(m,_tflm_y_data_int16x8.h)
#else
/* Need to do model and regression types inclusion manually, without macros-es.
   * See readme.md for examples. */
#endif

#define MTB_ML_MODEL_ARENA_SIZE(m)           MODEL_DATA_LEN(m,_ARENA_SIZE)

#define ML_MODEL_NAME_STR_IMPL(m)            EXPAND_AND_STRINGIFY(m)
#define ML_MODEL_BIN_IMPL(m)                 MODEL_DATA_BIN(m,_model_bin)
#define ML_MODEL_X_DATA_BIN_IMPL(m)          MODEL_DATA_BIN(m,_x_data_bin)
#define ML_MODEL_Y_DATA_BIN_IMPL(m)          MODEL_DATA_BIN(m,_y_data_bin)
#define ML_MODEL_SIZE_IMPL(m)                MODEL_DATA_LEN(m,_MODEL_BIN_LEN)

#define ML_MODEL_BIN_DATA_IMPL(x)            MTB_ML_MODEL_NAME_STR(x), \
                                             MTB_ML_MODEL_BIN(x), \
                                             MTB_ML_MODEL_SIZE(x), \
                                             MTB_ML_MODEL_ARENA_SIZE(x)

#define ML_MODEL_INFERENCE_ERROR_IMPL(err) \
    do { \
           printf("Inference error: Tflite-Micro status: %d \r\n", err); \
    } while(0)

#endif  // __MTB_ML_MODEL_DEFS_H__
