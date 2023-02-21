/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef PPM_H__
#define PPM_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_PPM_CHANNEL 10

typedef struct {
    uint8_t chan_id;
    uint8_t total_chan; /* total ppm channel number */
    uint16_t last_ic;
    uint16_t ppm_recvd;
    uint16_t ppm_reading;
    uint32_t freq_hz;
    float scale_us;
    uint16_t ppm_val[MAX_PPM_CHANNEL]; /* ppm raw value in microseconds */
} ppm_decoder_t;

rt_inline void ppm_lock(ppm_decoder_t* decoder)
{
    decoder->ppm_reading = 1;
}

rt_inline void ppm_unlock(ppm_decoder_t* decoder)
{
    decoder->ppm_reading = 0;
}

rt_inline uint16_t ppm_data_ready(ppm_decoder_t* decoder)
{
    return decoder->ppm_recvd;
}

rt_inline void ppm_data_clear(ppm_decoder_t* decoder)
{
    decoder->ppm_recvd = 0;
}

void ppm_update(ppm_decoder_t* decoder, uint32_t ic_val);
rt_err_t ppm_decoder_init(ppm_decoder_t* decoder, uint32_t freq_hz);

#ifdef __cplusplus
}
#endif

#endif
