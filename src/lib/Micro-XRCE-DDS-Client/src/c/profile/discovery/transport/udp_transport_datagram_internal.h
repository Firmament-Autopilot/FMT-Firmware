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

#ifndef SRC_C_CLIENT_UDP_TRANSPORT_DATAGRAM_INTERNAL_H_
#define SRC_C_CLIENT_UDP_TRANSPORT_DATAGRAM_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <uxr/client/config.h>
#include <uxr/client/core/type/xrce_types.h>
#include <uxr/client/visibility.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(UCLIENT_PLATFORM_POSIX)
    #include <poll.h>
    #include <sys/socket.h>
    #include <sys/types.h>
#elif defined(UCLIENT_PLATFORM_WINDOWS)
    #include <winsock2.h>
#elif defined(PLATFORM_NAME_FREERTOS_PLUS_TCP)
    #include "FreeRTOS.h"
    #include "FreeRTOS_IP.h"
    #include "FreeRTOS_Sockets.h"
    #include "list.h"
#endif

// TODO (julibert): move this to CMake flag.
#define UXR_UDP_TRANSPORT_MTU_DATAGRAM 200 //Adjusted to the minimun necessary buffer for discovery messages.

typedef struct uxrUDPTransportDatagram {
    uint8_t buffer[UXR_UDP_TRANSPORT_MTU_DATAGRAM];
#if defined(UCLIENT_PLATFORM_POSIX)
    struct pollfd poll_fd;
#elif defined(UCLIENT_PLATFORM_POSIX_NOPOLL)
    int fd;
#elif defined(UCLIENT_PLATFORM_WINDOWS)
    WSAPOLLFD poll_fd;
#elif defined(PLATFORM_NAME_FREERTOS_PLUS_TCP)
    SocketSet_t poll_fd;
    Socket_t fd;
#endif

} uxrUDPTransportDatagram;

bool uxr_init_udp_transport_datagram(
    struct uxrUDPTransportDatagram* transport);

bool uxr_udp_send_datagram_to(
    struct uxrUDPTransportDatagram* transport,
    const uint8_t* buf,
    size_t length,
    const TransportLocator* locator);

bool uxr_udp_recv_datagram(
    struct uxrUDPTransportDatagram* transport,
    uint8_t** buf,
    size_t* len,
    int timeout);

bool uxr_close_udp_transport_datagram(
    struct uxrUDPTransportDatagram* transport);

void uxr_bytes_to_ip(
    const uint8_t* bytes,
    char* ip);

#ifdef __cplusplus
}
#endif

#endif // SRC_C_CLIENT_UDP_TRANSPORT_DATAGRAM_INTERNAL_H_
