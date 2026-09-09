/***************************************************************************//**
* \file mtb_ml_dataset.h
*
* \brief
* This is the test dataset header file of ModusToolbox ML middleware library.
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
#if !defined(__MTB_ML_DATASET_H__)
#define __MTB_ML_DATASET_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Typedefs
 *****************************************************************************/

typedef enum MTB_ML_X_DATA_TYPE {
    MTB_ML_X_DATA_UNKNOWN = 0,
    MTB_ML_X_DATA_FLOAT32 = 1,
    MTB_ML_X_DATA_INT8 =    2,
    MTB_ML_X_DATA_INT16 =   3,
} mtb_ml_x_data_type_t;

/******************************************************************************
* Public definitions
******************************************************************************/

/******************************************************************************
* Structures
******************************************************************************/
/**
 * Sample data file header data structure
 */
typedef struct mtb_ml_x_file_header
{
    mtb_ml_x_data_type_t data_type; /**< data type of sample dataset */
    int32_t num_of_samples;         /**< number of samples (or frames) in dataset */
    int32_t input_size;             /**< Input length (or frame size) of dataset */
    int32_t recurrent_ts_size;      /**< -1 - non-RNN model, 1 - non-streaming RNN, other - number of time steps */
} mtb_ml_x_file_header_t;

#if defined(__cplusplus)
}
#endif

#endif /* __MTB_ML_DATASET_H__ */
