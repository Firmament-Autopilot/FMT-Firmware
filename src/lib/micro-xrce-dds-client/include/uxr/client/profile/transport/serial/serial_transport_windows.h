// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _UXR_CLIENT_SERIAL_TRANSPORT_H_
#define _UXR_CLIENT_SERIAL_TRANSPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <uxr/client/visibility.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct SerialProperties;

typedef struct SerialTransport {
    intmax_t (*send_data)(struct SerialTransport* transport, char* buf, size_t len);
    intmax_t (*recv_data)(struct SerialTransport* transport, char** buf, size_t* len);
    struct SerialProperties* properties;
} SerialTransport;

UXRDLLAPI bool uxr_init_uart_transport(SerialTransport* transport, const char* device);

#ifdef __cplusplus
}
#endif

#endif //_UXR_CLIENT_SERIAL_TRANSPORT_H_
