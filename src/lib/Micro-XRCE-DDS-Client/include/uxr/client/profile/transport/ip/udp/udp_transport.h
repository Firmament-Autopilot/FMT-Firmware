// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#ifndef UXR_CLIENT_UDP_TRANSPORT_H_
#define UXR_CLIENT_UDP_TRANSPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <uxr/client/config.h>
#include <uxr/client/core/communication/communication.h>
#include <uxr/client/profile/transport/ip/ip.h>
#include <uxr/client/visibility.h>

struct uxrUDPPlatform;

typedef struct uxrUDPTransport {
    uint8_t buffer[UXR_CONFIG_UDP_TRANSPORT_MTU];
    uxrCommunication comm;
    struct uxrUDPPlatform* platform;

} uxrUDPTransport;

/**
 * @brief Initializes a UDP transport.
 * @param transport     The uninitialized transport structure used for managing the transport.
 *                      This structure must be accesible during the connection.
 * @param platform      A structure that contains the platform dependencies.
 * @param ip_protocol   The IP protocol, it could be UXR_IPv4 or UXR_IPv6.
 * @param ip            The IP address of the Agent.
 * @param port          The port of the Agent.
 * @return `true` in case of successful initialization. `false` in other case.
 */
UXRDLLAPI bool uxr_init_udp_transport(
    uxrUDPTransport* transport,
    struct uxrUDPPlatform* platform,
    uxrIpProtocol ip_protocol,
    const char* ip,
    const char* port);

/**
 * @brief Closes a UDP transport.
 * @param transport The transport structure.
 * @return `true` in case of successful closing. `false` in other case.
 */
UXRDLLAPI bool uxr_close_udp_transport(
    uxrUDPTransport* transport);

#ifdef __cplusplus
}
#endif

#endif // UXR_CLIENT_UDP_TRANSPORT_H_
