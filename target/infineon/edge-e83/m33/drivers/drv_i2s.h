/******************************************************************************
* File Name : app_pdm_pcm.h
*
* Description : Header file for i2s containing  function ptototypes.
********************************************************************************
* Copyright 2025, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
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
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/


#ifndef __DRV_I2S_H__
#define __DRV_I2S_H__


#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
* Header Files
*******************************************************************************/
#include "cy_pdl.h"
#include "mtb_hal.h"
#include "cybsp.h"

// #include "mtb_tlv320dac3100.h"
// #include "i2s_playback.h"
/*******************************************************************************
* Macros
*******************************************************************************/
#if SAMPLING_RATE == 16000u
/* 16KHz playback */
#define MCLK_HZ                             (2048000)
#define I2S_CLK_DIV_16KHZ                   (24u)
#define SYSCLK_DIV_CHANGE_WAIT_TIME_MS      (50u)
#else
/* 48KHz playback. 44.1KHz also will be played at 48KHz */
#define MCLK_HZ                             (6144000u)
#endif /* SAMPLING_RATE */

/* I2S word length parameter */
#define I2S_WORD_LENGTH                     (16u)

/* I2C master address */
#define I2C_ADDRESS                         (0x18)
/* I2C frequency in Hz */
#define I2C_FREQUENCY_HZ                    (400000u)

#define I2S_HW_FIFO_SIZE                    (128u)




#define SAMPLING_RATE_16kHz                             (16000u)
#define SAMPLING_RATE_44_1kHz                           (44100u)
#define SAMPLING_RATE_48kHz                             (48000u)


/* Sampling rate in KHz */
#define SAMPLING_RATE                                   (SAMPLING_RATE_16kHz)

/* I2S playback volume */
#define DEFAULT_VOLUME                                  (100u)
#define REDUCE_VOLUME                                   (90u)
#define INCREASE_VOLUME                                 (120u)

#if SAMPLING_RATE == SAMPLING_RATE_16kHz
/* Number of samples in an audio frame */
#define FRAME_SIZE                                      (32u)
#define PLAYBACK_DATA_FRAME_SIZE                        (2048)
#elif SAMPLING_RATE == SAMPLING_RATE_48kHz
/* Number of samples in an audio frame */
#define FRAME_SIZE                                      (480u)
#define PLAYBACK_DATA_FRAME_SIZE                        (2*FRAME_SIZE)
#elif SAMPLING_RATE == SAMPLING_RATE_44_1kHz
/* Number of samples in an audio frame */
#define FRAME_SIZE                                      (441u)
#define PLAYBACK_DATA_FRAME_SIZE                        (2*480u)
#endif /* SAMPLING_RATE */

#define I2C_ADDRESS                                     (0x18)
#define I2C_FREQUENCY                                   (400000)

#define I2S_CHANNEL_LENGTH                              (16u)
#define I2S_WORD_LENGTH                                 (16u)

#define I2S_PLAYBACK_TASK_QUEUE_LENGTH                  (50u)
#define I2S_PRIORITY                                    (7u)

#define I2S_PLAYBACK_TASK_PRIORITY                      (6u)
#define I2S_PLAYBACK_TASK_STACK_SIZE                    (4*256u)

/* AEC reference */
#define AEC_REF_FRAME_SIZE                              (160u)
#define AEC_REF_SAMPLING_RATE                           (16000u)
#define AEC_REF_DATA_QUEUE_LENGTH                       2//(30u)
#define AEC_REF_DATA_QUEUE_CHECK_THRESHOLD              3//(50u)

/* Aec ref circular buffer size*/
#define AEC_REF_CBUF_SIZE                               (AEC_REF_DATA_QUEUE_LENGTH * AEC_REF_FRAME_SIZE * sizeof(int16_t))

/* ASRC related macro definitions */
#define ASRC_OUTPUT_BUFFER_SIZE                         (1000u)
#define ASRC_INPUT_SAMPLES                              (240u)
#define ASRC_NUM_ITERATIONS_PER_FRAME                   (2u)

/* Maximum value for unsigned 32-bit integer. */
#define UINT32_MAX_VALUE                                (0xFFFFFFFF)

/* I2S word length parameter */
#define I2S_WORD_LENGTH                                 (16u)
/* I2S hardware FIFO size */
#define HW_FIFO_SIZE                                    (64u)

/* PDM PCM interrupt priority */
#define I2S_INTR_PRIORITY                               (2u)
/*******************************************************************************
* Global Variables
*******************************************************************************/
extern volatile int16_t *audio_data_ptr;
extern int32_t recorded_data_size;
extern volatile bool i2s_flag;

/*******************************************************************************
* Functions Prototypes
*******************************************************************************/
void app_i2s_init(void);
void app_tlv_codec_init(void);
void tlv_codec_i2c_init(void);
void i2s_tx_interrupt_handler(void);
void app_i2s_enable(void);
void app_i2s_activate(void);
void app_i2s_deactivate(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __APP_I2S_H__ */
/* [] END OF FILE */
