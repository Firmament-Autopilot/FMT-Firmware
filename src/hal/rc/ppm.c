/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include <firmament.h>
#include <string.h>

#include "hal/rc/ppm.h"

#define GET_GAP(x, y) (x > y ? (x - y) : (0xFFFF - y + x))

// static uint8_t ppm_reading;
// static uint8_t ppm_recvd;
static float scale_us = 1000000.0f / PPM_DECODER_FREQUENCY;

void ppm_update(ppm_decoder_t* decoder, uint32_t ic_val)
{
    static uint16_t temp_val[MAX_PPM_CHANNEL];
    uint16_t gap;

    gap = GET_GAP(ic_val, decoder->last_ic);

    if (gap > 90 && gap < 210) {
        /* valid ppm signal should between 1ms(100) to 2ms(200) */
        if (decoder->chan_id < MAX_PPM_CHANNEL) {
            temp_val[decoder->chan_id] = gap;
            decoder->chan_id++;
        }
    } else {
        /* sync signal */
        if (decoder->chan_id >= 1 && decoder->chan_id <= MAX_PPM_CHANNEL) {
            /* get total channel count */
            decoder->total_chan = decoder->chan_id;
        }

        /* if user is reading ppm data while we got a new frame, just drop this frame */
        if (decoder->total_chan && decoder->chan_id == decoder->total_chan && !decoder->ppm_reading) {
            /* reveived all channel data */
            for (uint8_t i = 0; i < decoder->total_chan; i++) {
                decoder->ppm_val[i] = scale_us * temp_val[i];

                if (decoder->ppm_val[i] < 1000) {
                    decoder->ppm_val[i] = 1000;
                } else if (decoder->ppm_val[i] > 2000) {
                    decoder->ppm_val[i] = 2000;
                }
            }

            decoder->ppm_recvd = 1;
        }

        decoder->chan_id = 0;
    }

    /* update last capture value */
    decoder->last_ic = ic_val;
}

// uint8_t ppm_read(uint16_t val[MAX_PPM_CHANNEL])
// {
//     ppm_reading = 1;
//     memcpy(val, decoder->ppm_val, decoder->total_chan * 2);
//     ppm_reading = 0;

//     return decoder->total_chan;
// }

rt_err_t ppm_decoder_init(ppm_decoder_t* decoder)
{
    decoder->chan_id = 0;
    decoder->total_chan = 0;
    decoder->last_ic = 0;
    decoder->ppm_recvd = 0;
    decoder->ppm_reading = 0;

    memset(decoder->ppm_val, 0, sizeof(decoder->ppm_val));

    return RT_EOK;
}
