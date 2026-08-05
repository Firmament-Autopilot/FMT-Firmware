/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#include "drv_usbd_cdc_rb.h"

rt_err_t drv_usbd_cdc_rb_init(drv_usbd_cdc_rb_t* rb, uint8_t* buffer, uint32_t size)
{
    if (rb == RT_NULL || buffer == RT_NULL || size == 0u) {
        return RT_EINVAL;
    }

    rb->buffer = buffer;
    rb->size = size;
    rb->head = 0u;
    rb->tail = 0u;
    rb->count = 0u;

    return RT_EOK;
}

uint32_t drv_usbd_cdc_rb_put(drv_usbd_cdc_rb_t* rb, const uint8_t* data, uint32_t len)
{
    uint32_t write_len;
    uint32_t free_space;
    uint32_t first_chunk;

    if (rb == RT_NULL || data == RT_NULL || len == 0u) {
        return 0u;
    }

    OS_ENTER_CRITICAL;
    free_space = rb->size - rb->count;
    write_len = len < free_space ? len : free_space;
    first_chunk = rb->size - rb->head;

    if (write_len <= first_chunk) {
        rt_memcpy(&rb->buffer[rb->head], data, write_len);
    } else {
        rt_memcpy(&rb->buffer[rb->head], data, first_chunk);
        rt_memcpy(rb->buffer, &data[first_chunk], write_len - first_chunk);
    }

    rb->head = (rb->head + write_len) % rb->size;
    rb->count += write_len;
    OS_EXIT_CRITICAL;

    return write_len;
}

uint32_t drv_usbd_cdc_rb_get(drv_usbd_cdc_rb_t* rb, uint8_t* data, uint32_t len)
{
    uint32_t read_len;
    uint32_t first_chunk;

    if (rb == RT_NULL || data == RT_NULL || len == 0u) {
        return 0u;
    }

    OS_ENTER_CRITICAL;
    read_len = len < rb->count ? len : rb->count;
    first_chunk = rb->size - rb->tail;

    if (read_len <= first_chunk) {
        rt_memcpy(data, &rb->buffer[rb->tail], read_len);
    } else {
        rt_memcpy(data, &rb->buffer[rb->tail], first_chunk);
        rt_memcpy(&data[first_chunk], rb->buffer, read_len - first_chunk);
    }

    rb->tail = (rb->tail + read_len) % rb->size;
    rb->count -= read_len;
    OS_EXIT_CRITICAL;

    return read_len;
}

uint32_t drv_usbd_cdc_rb_len(drv_usbd_cdc_rb_t* rb)
{
    uint32_t count;

    if (rb == RT_NULL) {
        return 0u;
    }

    OS_ENTER_CRITICAL;
    count = rb->count;
    OS_EXIT_CRITICAL;

    return count;
}

void drv_usbd_cdc_rb_flush(drv_usbd_cdc_rb_t* rb)
{
    if (rb == RT_NULL) {
        return;
    }

    OS_ENTER_CRITICAL;
    rb->head = 0u;
    rb->tail = 0u;
    rb->count = 0u;
    OS_EXIT_CRITICAL;
}
