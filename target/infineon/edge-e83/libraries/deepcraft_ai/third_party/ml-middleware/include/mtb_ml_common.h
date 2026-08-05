/***************************************************************************//**
* \file mtb_ml_common.h
*
* \brief
* This is the common header file of ModusToolbox ML middleware library.
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
#if !defined(__MTB_ML_COMMON_H__)
#define __MTB_ML_COMMON_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "cy_result.h"

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
 * Version
 *****************************************************************************/
#define MTB_ML_MIDDLEWARE_VERSION_MAJOR     3
#define MTB_ML_MIDDLEWARE_VERSION_MINOR     1
#define MTB_ML_MIDDLEWARE_VERSION_PATCH     0

/******************************************************************************
 * Macros
 *****************************************************************************/

/**
 * \addtogroup Common_Macro
 * @{
 */
/*!
 * \def MTB_ML_MODEL_NAME_STR(m)
 * A helper macro that returns the string constant of a MTB ML Model's name.
 *
 * \def MTB_ML_INCLUDE_MODEL_FILE(m)
 * A helper macro that returns the header filename of a MTB ML Model.
 *
 * \def MTB_ML_MODEL_BIN(m)
 * A helper macro that returns the address of a MTB ML Model's data.
 *
 * \def MTB_ML_MODEL_SIZE(m)
 * A helper macro that returns the size of a MTB Model's data.
 *
 * \def MTB_ML_INCLUDE_MODEL_X_DATA_FILE(m)
 * A helper macro that returns the data filename of a MTB ML Model's sample data.
 *
 * \def MTB_ML_MODEL_X_DATA_BIN(m)
 * A helper macro that returns the address of a MTB ML Model's sample data.
 *
 * \def MTB_ML_INCLUDE_MODEL_Y_DATA_FILE(m)
 * A helper macro that returns the data filename of a MTB ML Model's reference result.
 *
 * \def MTB_ML_MODEL_Y_DATA_BIN(m)
 * A helper macro that returns the address of a MTB ML Model's reference result.
 */
#define MTB_ML_MODEL_NAME_STR(m)             ML_MODEL_NAME_STR_IMPL(m)
#define MTB_ML_INCLUDE_MODEL_FILE(m)         ML_INCLUDE_MODEL_FILE_IMPL(m)
#define MTB_ML_MODEL_BIN(m)                  ML_MODEL_BIN_IMPL(m)
#define MTB_ML_MODEL_SIZE(m)                 ML_MODEL_SIZE_IMPL(m)
#define MTB_ML_INCLUDE_MODEL_X_DATA_FILE(m)  ML_INCLUDE_MODEL_X_DATA_FILE_IMPL(m)
#define MTB_ML_MODEL_X_DATA_BIN(m)           ML_MODEL_X_DATA_BIN_IMPL(m)
#define MTB_ML_INCLUDE_MODEL_Y_DATA_FILE(m)  ML_INCLUDE_MODEL_Y_DATA_FILE_IMPL(m)
#define MTB_ML_MODEL_Y_DATA_BIN(m)           ML_MODEL_Y_DATA_BIN_IMPL(m)

/*!
 * \def MTB_ML_MODEL_BIN_DATA(x)
 * A helper macro that populates mtb_ml_model_bin_t structure with MTB ML Model's data.
 */
#define MTB_ML_MODEL_BIN_DATA(x)             ML_MODEL_BIN_DATA_IMPL(x)

/*!
 * \def MTB_ML_MODEL_INFERENCE_ERROR(err)
 * A helper macro that prints out the error information.
 */
#define MTB_ML_MODEL_INFERENCE_ERROR(err)    ML_MODEL_INFERENCE_ERROR_IMPL(err)

/**
 * @} end of Common_Macro group
 */

/******************************************************************************
 * Typedefs
 *****************************************************************************/
/**
 * A enum type for MTB ML profiling configuration
 */
typedef enum
{
    MTB_ML_PROFILE_DISABLE                     = 0,
    MTB_ML_PROFILE_ENABLE_MODEL                = 1,
    MTB_ML_PROFILE_ENABLE_LAYER                = 2,
    MTB_ML_PROFILE_ENABLE_MODEL_PER_FRAME      = 4,
    MTB_ML_PROFILE_ENABLE_LAYER_PER_FRAME      = 8,
    MTB_ML_LOG_ENABLE_MODEL_LOG                = 16
} mtb_ml_profile_config_t;

/******************************************************************************
* Public definitions
******************************************************************************/

#define MTB_ML_RESULT_SUCCESS            CY_RSLT_SUCCESS
#define MTB_ML_RESULT_BAD_ARG            CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 1)
#define MTB_ML_RESULT_ALLOC_ERR          CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 2)
#define MTB_ML_RESULT_BAD_MODEL          CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 3)
#define MTB_ML_RESULT_MISMATCH_DATA_TYPE CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 4)
#define MTB_ML_RESULT_INPUT_ERROR        CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 5)
#define MTB_ML_RESULT_INFERENCE_ERROR    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 6)
#define MTB_ML_RESULT_COMM_ERROR         CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 7)
#define MTB_ML_RESULT_TIMEOUT            CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 8)
#define MTB_ML_RESULT_NPU_INIT_ERROR     CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 9)
#define MTB_ML_RESULT_CYCLE_COUNT_ERROR  CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ML, 10)

/******************************************************************************
* Structures
******************************************************************************/

#if defined(__cplusplus)
}
#endif

#endif /* __MTB_ML_COMMON_H__ */
