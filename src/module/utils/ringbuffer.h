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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t static_flag;
    unsigned head;
    unsigned tail;
    unsigned size;
    uint8_t* buff;
} ringbuffer;

ringbuffer* ringbuffer_create(uint32_t size);
ringbuffer* ringbuffer_static_create(uint32_t size, uint8_t* buffer);
uint32_t ringbuffer_getlen(ringbuffer* rb);
uint8_t ringbuffer_putc(ringbuffer* rb, uint8_t c);
uint8_t ringbuffer_getc(ringbuffer* rb);
uint32_t ringbuffer_get(ringbuffer* rb, uint8_t* ptr, uint32_t len);
uint32_t ringbuffer_put(ringbuffer* rb, const uint8_t* ptr, uint32_t len);
void ringbuffer_flush(ringbuffer* rb);
void ringbuffer_delete(ringbuffer* rb);

#ifdef __cplusplus
}
#endif
