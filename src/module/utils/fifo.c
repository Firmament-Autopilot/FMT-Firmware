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

#include <firmament.h>

#include "module/utils/fifo.h"
#include "module/console/console.h"

uint8_t fifo_create(FIFO* fifo, uint16_t size)
{
	fifo->data = (float*)OS_MALLOC(size * sizeof(float));

	if(fifo->data == NULL) {
		console_printf("fifo create fail\n");
		return 1;
	}

	fifo->size = size;
	fifo->head = 0;
	fifo->cnt = 0;

	for(int i = 0 ; i < size ; i++) {
		fifo->data[i] = 0.0f;
	}

	return 0;
}

void fifo_flush(FIFO* fifo)
{
	if(fifo == NULL)
		return;

	fifo->head = 0;
	fifo->cnt = 0;

	for(int i = 0 ; i < fifo->size ; i++) {
		fifo->data[i] = 0.0f;
	}
}

void fifo_push(FIFO* fifo, float val)
{
	fifo->head = (fifo->head + 1) % fifo->size;
	fifo->data[fifo->head] = val;

	if(fifo->cnt < fifo->size)
		fifo->cnt++;
}

float fifo_pop(FIFO* fifo)
{
	uint16_t tail = (fifo->head + 1) % fifo->size;
	return fifo->data[tail];
}

float fifo_read_back(FIFO* fifo, uint16_t offset)
{
	offset = offset % fifo->size;
	uint16_t index = (fifo->head >= offset) ? (fifo->head - offset) : (fifo->head + fifo->size - offset);
	return fifo->data[index];
}