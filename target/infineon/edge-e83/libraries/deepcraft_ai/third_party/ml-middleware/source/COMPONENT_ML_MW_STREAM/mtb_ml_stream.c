/***************************************************************************//**
* \file mtb_ml_stream.c
*
* \brief
* This file contains interface for ML validation data streaming feature
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
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "cy_retarget_io.h"

#include "mtb_ml_common.h"
#include "mtb_ml_utils.h"
#include "mtb_ml_stream.h"
#include "mtb_ml_model.h"

/*******************************************************************************
 * Macros
*******************************************************************************/
#define DEFAULT_TX_TIMEOUT 1000
#define DEFAULT_RX_TIMEOUT 5000

#ifndef ML_START_TIMEOUT
#define ML_START_TIMEOUT   45000
#endif
/* Set the default buffer to 25. This is only used when HOST is requesting data to be sent.
 * ML_READY, ML_START etc. will never exceed 10 characters.
 */
#define DEFAULT_RX_BUFFER  25

/* NOTE: Must match mtb_ml_regression_info_t in streaming application */
#define ML_PROFILE_FRAME_STRING         "Frame "
#define ML_PROFILE_OUTPUT_STRING        " output:"
#define ML_PROFILE_INFO_STRING          "PROFILE_INFO,"

#define ML_TC_START_STRING              "ML_START"
#define ML_CT_READY_STRING              "ML_READY"
#define ML_TC_MODEL_DATA_REQ_STRING     "ML_MODEL_DATA_REQ"
#define ML_CT_MODEL_DATA_STRING         "ML_MODEL_DATA"
#define ML_TC_DATASET_REQ_SEND_STRING   "ML_DATASET_SENDREQ"
#define ML_CT_FRAME_REQ_STRING          "ML_FRAME"
#define ML_CT_RESULT_STRING             "ML_RESULT"
#define ML_TC_DONE_STRING               "ML_COMPLETED"
#define ML_CT_DONE_STRING               "ML_DONE"
#define ML_ERROR_STRING                 "ERROR"

/*******************************************************************************
 * Private Function Prototypes
*******************************************************************************/
static inline cy_rslt_t mtb_data_streaming_receive(mtb_data_streaming_interface_t* iface,
                                                   uint8_t* data, size_t count, void* tag);
static inline cy_rslt_t mtb_data_streaming_send(mtb_data_streaming_interface_t* iface,
                                                uint8_t *data, size_t count, void* tag);

static cy_rslt_t stream_verify_test_data(mtb_ml_stream_interface_t *iface,
                                         const mtb_ml_model_t *model_object);
static cy_rslt_t send_model_regr_info   (mtb_ml_stream_interface_t *iface,
                                         const mtb_ml_model_t *model_object);
static cy_rslt_t stream_send_data   (mtb_ml_stream_interface_t *iface,
                                    void* tx_buf,
                                    size_t tx_length,
                                    uint32_t timeout_ms);
static cy_rslt_t stream_get_data    (mtb_ml_stream_interface_t *iface,
                                    void* rx_buf,
                                    size_t rx_length,
                                    uint32_t timeout_ms);
static cy_rslt_t stream_get_string  (mtb_ml_stream_interface_t *iface,
                                    const char *string,
                                    size_t size,
                                    uint32_t timeout_ms);
static cy_rslt_t stream_setup       (mtb_data_streaming_interface_t* iface);
static cy_rslt_t stream_uart_send   (mtb_data_streaming_vcontext_t* vcontext,
                                    void* data,
                                    size_t count,
                                    void* tag);
static cy_rslt_t stream_uart_get    (mtb_data_streaming_vcontext_t* vcontext,
                                    uint8_t* data,
                                    size_t count,
                                    void* tag);

#if !defined(COMPONENT_MTB_HAL)
extern cyhal_uart_t cy_retarget_io_uart_obj;
#endif
/*******************************************************************************
 * Private Typedef's/Enumerations
*******************************************************************************/
/* NOTE: Must match mtb_ml_regression_info_t in streaming application */
typedef struct
{
    uint32_t output_size;       /* NN model inference classification output size (in ELEMENTS, not bytes) */
    uint32_t buffer_size;       /* Runtime buffer size required for inference */
    uint32_t model_size;        /* Model's weights & biases */
    uint32_t model_time_steps;  /* Number of model time steps */
    int output_zero_point;      /* Model's output data zero point */
    float output_scale;         /* Model's output data */
} mtb_ml_regression_info_t;

/*******************************************************************************
 * Public Functions
*******************************************************************************/
void mtb_ml_stream_cb(void* tag, cy_rslt_t rslt)
{
    /* Currently unused */
    (void)tag;
    (void)rslt;
}

cy_rslt_t mtb_ml_stream_init(mtb_ml_stream_interface_t *interface,
                            const mtb_ml_model_t *model_object)
{
    if(!interface || !model_object)
    {
        printf("ERROR: mtb_ml_stream_init invalid parameters\r\n");
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Initialize comm */
    stream_setup(interface->interface_obj);

    /* Verify test data */
    return stream_verify_test_data(interface, model_object);
}

cy_rslt_t mtb_ml_stream_output_data(mtb_ml_stream_interface_t *iface, void *tx_buf, uint32_t timeout_ms)
{
    if(!iface || !tx_buf)
    {
        printf("ERROR: mtb_ml_stream_output_data invalid parameters\r\n");
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Send "result" string to host */
    cy_rslt_t result = stream_send_data(iface, ML_CT_RESULT_STRING, sizeof(ML_CT_RESULT_STRING), timeout_ms);
    if(result != MTB_ML_RESULT_SUCCESS)
    {
        printf("ERROR: failed to send result string to host\r\n");
        return result;
    }

    /* Send output data */
    return stream_send_data(iface, tx_buf, iface->output_size * iface->output_data_size, timeout_ms);
}

cy_rslt_t mtb_ml_stream_input_data(mtb_ml_stream_interface_t *iface, void *rx_buf, uint32_t timeout_ms)
{
    if(!iface || !rx_buf)
    {
        printf("ERROR: mtb_ml_stream_input_data invalid parameters\r\n");
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Send frame request string to host. */
    cy_rslt_t result = stream_send_data(iface, ML_CT_FRAME_REQ_STRING, sizeof(ML_CT_FRAME_REQ_STRING), timeout_ms);
    if(result != MTB_ML_RESULT_SUCCESS)
    {
        printf("ERROR: failed to send frame request to host.\r\n");
        return result;
    }
    /* Get input data */
    return stream_get_data(iface, rx_buf, (iface->input_size * iface->input_data_size) , timeout_ms);

}

cy_rslt_t mtb_ml_inform_host_done( mtb_ml_stream_interface_t *iface, uint32_t timeout_ms)
{
    if(!iface)
    {
        printf("ERROR: mtb_ml_inform_host_done invalid parameters\r\n");
        return MTB_ML_RESULT_BAD_ARG;
    }
    cy_rslt_t result = stream_get_string(iface, ML_TC_DONE_STRING, sizeof(ML_TC_DONE_STRING), timeout_ms);
    if(result != MTB_ML_RESULT_SUCCESS)
    {
        return result;
    }
    return stream_send_data(iface, ML_CT_DONE_STRING, sizeof(ML_CT_DONE_STRING), timeout_ms);
}

/*******************************************************************************
 * Private Functions
*******************************************************************************/
static cy_rslt_t stream_verify_test_data(   mtb_ml_stream_interface_t *iface,
                                            const mtb_ml_model_t *model_object)
{
    cy_rslt_t result;
    mtb_ml_x_file_header_t test_data_info;

    /* Wait for the start string from the host (ML_START) */
    printf("Waiting for the data stream to begin...\r\n");
    result = stream_get_string(iface, ML_TC_START_STRING,
                                  sizeof(ML_TC_START_STRING), ML_START_TIMEOUT);
    if(result != MTB_ML_RESULT_SUCCESS)
    {
        printf("Timed out waiting for start string\r\n");
        return result;
    }

    /* Print the model info */
    result = mtb_ml_utils_print_model_info(model_object);

    if (result != MTB_ML_RESULT_SUCCESS)
    {
        return result;
    }

    /* Indicate the host that we are ready (ML_READY) */
    result = stream_send_data(iface, ML_CT_READY_STRING, sizeof(ML_CT_READY_STRING), DEFAULT_TX_TIMEOUT);
    if (result != MTB_ML_RESULT_SUCCESS)
    {
        return result;
    }

    /* Send model regression info to host */
    result = send_model_regr_info(iface, model_object);
    if (result != MTB_ML_RESULT_SUCCESS)
    {
        return result;
    }

    /* Receive test data info from host */
    result = stream_get_string(iface, ML_TC_DATASET_REQ_SEND_STRING,
                               sizeof(ML_TC_DATASET_REQ_SEND_STRING), DEFAULT_RX_TIMEOUT);
    if(result != MTB_ML_RESULT_SUCCESS)
    {
        printf("ERROR: failed to receive %s from the host\r\n", ML_TC_DATASET_REQ_SEND_STRING);
        return MTB_ML_RESULT_COMM_ERROR;
    }

    result = stream_send_data(iface, ML_CT_READY_STRING, sizeof(ML_CT_READY_STRING), DEFAULT_TX_TIMEOUT);
    if (result != MTB_ML_RESULT_SUCCESS)
    {
        printf("ERROR: failed to send %s to the host\r\n", ML_CT_READY_STRING);
        return MTB_ML_RESULT_COMM_ERROR;
    }

    result = stream_get_data(iface, &test_data_info, sizeof(test_data_info), DEFAULT_TX_TIMEOUT);
    if (result != MTB_ML_RESULT_SUCCESS)
    {
        printf("ERROR: failure receiving dataset header\r\n");
        return MTB_ML_RESULT_COMM_ERROR;
    }

    /* Print data received from host */
    printf("\r\nReceived: num frames:%d frame size:%d recurrent_ts_size:%d\r\n",
           (int)test_data_info.num_of_samples, (int)test_data_info.input_size, (int)test_data_info.recurrent_ts_size);

    int input_type_size = model_object->input_type_size;
    /* Validate test data against model */
    switch(test_data_info.data_type)
    {
        case(MTB_ML_X_DATA_FLOAT32):
            if(input_type_size != sizeof(float))
            {
                printf("ERROR: Test data size (%d) does not match model data size (%d).\r\n", (int)sizeof(float), input_type_size);
                return MTB_ML_RESULT_INPUT_ERROR;
            }
            break;
        case(MTB_ML_X_DATA_INT8):
            if(input_type_size != sizeof(int8_t))
            {
                printf("ERROR: Test data size (%d) does not match model data size (%d).\r\n", (int)sizeof(int8_t), input_type_size);
                return MTB_ML_RESULT_INPUT_ERROR;
            }
            break;
        case(MTB_ML_X_DATA_INT16):
            if(input_type_size != sizeof(int16_t))
            {
                printf("ERROR: Test data size (%d) does not match model data size (%d).\r\n", (int)sizeof(int16_t), input_type_size);
                return MTB_ML_RESULT_INPUT_ERROR;
            }
            break;
        default:
            printf("ERROR: Unknown test data type\r\n");
            return MTB_ML_RESULT_BAD_ARG;
    }

    /* Initialize interface with concatenated sizes for multi-input/output models.
     * Desktop software sends/receives data concatenated across all input/output tensors.
     * Both input_size and output_size are in elements (not bytes).
     */
    iface->input_size = (size_t)model_object->input_concat_bytes / model_object->input_type_size;
    iface->output_size = (size_t)model_object->output_concat_bytes / model_object->output_type_size;
    iface->input_data_size = (size_t)model_object->input_type_size;
    iface->output_data_size = (size_t)model_object->output_type_size;

    /* Update x data info */
    iface->x_data_info.num_of_samples = test_data_info.num_of_samples;
    iface->x_data_info.input_size = test_data_info.input_size;
    iface->x_data_info.recurrent_ts_size = test_data_info.recurrent_ts_size;

    return MTB_ML_RESULT_SUCCESS;
}

static cy_rslt_t stream_send_data(mtb_ml_stream_interface_t *iface, void* tx_buf, size_t tx_length, uint32_t timeout_ms)
{
    return mtb_data_streaming_send(iface->interface_obj, (uint8_t *)tx_buf, tx_length, (void *)(&timeout_ms));
}

static cy_rslt_t stream_get_data(mtb_ml_stream_interface_t *iface, void* rx_buf, size_t rx_length, uint32_t timeout_ms)
{
    return mtb_data_streaming_receive(iface->interface_obj, (uint8_t *)rx_buf, rx_length, (void *)(&timeout_ms));
}

static cy_rslt_t stream_get_string(mtb_ml_stream_interface_t *iface, const char *string, size_t size, uint32_t timeout_ms)
{
    cy_rslt_t result = MTB_ML_RESULT_SUCCESS;
    char rx_buf[DEFAULT_RX_BUFFER];

    result = stream_get_data(iface, rx_buf, size, timeout_ms);
    if(result != MTB_ML_RESULT_SUCCESS)
    {
        return result;
    }

    if(strncmp(rx_buf, string, size) != 0)
    {
        printf("ERROR: Expected string %s but got string %s\r\n", string, rx_buf);
        result = MTB_ML_RESULT_COMM_ERROR;
    }
    return result;
}

static cy_rslt_t send_model_regr_info(mtb_ml_stream_interface_t *iface, const mtb_ml_model_t *model_object)
{
    cy_rslt_t result;
    mtb_ml_regression_info_t model_regr_info;

    /* Wait for data request string */
    result = stream_get_string(iface, ML_TC_MODEL_DATA_REQ_STRING, sizeof(ML_TC_MODEL_DATA_REQ_STRING), DEFAULT_RX_TIMEOUT);
    if(result != MTB_ML_RESULT_SUCCESS)
    {
        return result;
    }

    /* Send model data string */
    result = stream_send_data(iface, ML_CT_MODEL_DATA_STRING, sizeof(ML_CT_MODEL_DATA_STRING), DEFAULT_TX_TIMEOUT);
    if (result != MTB_ML_RESULT_SUCCESS)
    {
        return result;
    }

    /* Populate model info.
     * output_size is in elements (concatenated across all outputs for multi-output models).
     */
    model_regr_info.model_size = model_object->model_size;
    model_regr_info.output_size = model_object->output_concat_bytes / model_object->output_type_size;
    model_regr_info.buffer_size = model_object->buffer_size;
    model_regr_info.model_time_steps = model_object->model_time_steps;
    model_regr_info.output_zero_point = model_object->output_zero_point;
    model_regr_info.output_scale = model_object->output_scale;

    /* Send model info */
    return stream_send_data(iface, (void *)&model_regr_info, sizeof(model_regr_info), DEFAULT_TX_TIMEOUT);
}

static cy_rslt_t stream_setup(mtb_data_streaming_interface_t* iface)
{
    iface->send     = stream_uart_send;
    iface->receive  = stream_uart_get;
    /* for CY_HAL rely on object allocated in retarget-io itself */
#if !defined(COMPONENT_MTB_HAL)
    mtb_data_streaming_context_t *context = (mtb_data_streaming_context_t *)&(iface->context);
    context->obj_inst.uart = &cy_retarget_io_uart_obj;
#endif

    return CY_RSLT_SUCCESS;
}

#if !defined(COMPONENT_MTB_HAL)
#define ml_uart_writable   cyhal_uart_writable
#define ml_uart_write      cyhal_uart_write
#define ml_uart_read       cyhal_uart_read
#define ml_system_delay_ms cyhal_system_delay_ms
#define ml_system_delay_us cyhal_system_delay_us
#else
#define ml_uart_writable   mtb_hal_uart_writable
#define ml_uart_write      mtb_hal_uart_write
#define ml_uart_read       mtb_hal_uart_read
#define ml_system_delay_ms mtb_hal_system_delay_ms
#define ml_system_delay_us mtb_hal_system_delay_us
#endif

static cy_rslt_t stream_uart_send(mtb_data_streaming_vcontext_t* vcontext,
                                    void* data, size_t count, void* tag)
{
    mtb_data_streaming_context_t *context = (mtb_data_streaming_context_t *)vcontext;
    /* tag is the timeout in ms */
    volatile uint32_t timeout_ms = *((uint32_t *)tag);
    size_t requested_tx = count;
    size_t bytes_sent = 0;
    char *tx_p = (char *)data;
    while(bytes_sent < requested_tx)
    {
        /* Wait until UART TX buffer has some space */
        while(ml_uart_writable(context->obj_inst.uart) < 32)
        {
            /* Timeout of 0 means wait forever */
            if(timeout_ms == 0)
            {
                continue;
            }
            (void)ml_system_delay_ms(1);
            if(--timeout_ms == 0)
            {
                return MTB_ML_RESULT_TIMEOUT;
            }
        }

        if (ml_uart_write(context->obj_inst.uart, tx_p, &count) != CY_RSLT_SUCCESS)
        {
            return MTB_ML_RESULT_COMM_ERROR;
        }
        bytes_sent += count;
        tx_p = tx_p + count;
        count = requested_tx - bytes_sent;
    }

    return MTB_ML_RESULT_SUCCESS;
}

static cy_rslt_t stream_uart_get(mtb_data_streaming_vcontext_t* vcontext,
                                uint8_t* data, size_t count, void* tag)
{
    mtb_data_streaming_context_t *context = (mtb_data_streaming_context_t *)vcontext;
    /* tag is the timeout in ms */
    volatile uint32_t timeout_ms = *((uint32_t *)tag);
    size_t rx_length = count;
    size_t rx_count = 0;
    uint8_t *rx_p = data;

    while(rx_count < count)
    {
        rx_length = count - rx_count;
        if(ml_uart_read(context->obj_inst.uart, rx_p, &rx_length) != CY_RSLT_SUCCESS)
        {
            return MTB_ML_RESULT_COMM_ERROR;
        }

        if(rx_length == 0)
        {
            /* Timeout of 0 means wait forever */
            if(timeout_ms != 0)
            {
                (void)ml_system_delay_ms(1);
                if(--timeout_ms == 0)
                {
                    return MTB_ML_RESULT_TIMEOUT;
                }
            }
        }
        rx_count += rx_length;
        rx_p += rx_length;
    }

    return MTB_ML_RESULT_SUCCESS;
}

static inline cy_rslt_t mtb_data_streaming_receive(mtb_data_streaming_interface_t* iface,
                                                   uint8_t* data, size_t count, void* tag)
{
    return iface->receive(&(iface->context), data, count, tag);
}

static inline cy_rslt_t mtb_data_streaming_send(mtb_data_streaming_interface_t* iface,
                                                uint8_t* data, size_t count, void* tag)
{
    return iface->send(&(iface->context), data, count, tag);
}
