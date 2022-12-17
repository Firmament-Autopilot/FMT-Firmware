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

#ifndef UXR_CLIENT_PROFILE_DISCOVERY_DISCOVERY_H_
#define UXR_CLIENT_PROFILE_DISCOVERY_DISCOVERY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <uxr/client/config.h>
#include <uxr/client/core/type/xrce_types.h>
#include <uxr/client/visibility.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef bool (*uxrOnAgentFound)(const TransportLocator* locator, void* args);

/**
 * @brief Discovers Agents within the network using UDP/IP multicast with address "239.255.0.2" and port 7400.
 * @param attempts      The times a discovery message is sent across the network.
 * @param period        The period using to send multicast messages through the network.
 * @param on_agent_func The callback function that will be called when an Agent is discovered.
 * @param args          The user argument provided to the callback function.
 */
UXRDLLAPI void uxr_discovery_agents_default(
    uint32_t attempts,
    int period,
    uxrOnAgentFound on_agent_func,
    void* args);

/**
 * @brief Discovers Agents within the network using UDP/IP unicast with the address and port set by the user.
 * @param attempts          The times a discovery message is sent across the network.
 * @param period            The period using to send unicast messages through the network.
 * @param on_agent_func     The callback function that will called when an Agent is discovered.
 * @param args              The user argument provided to the callback function.
 * @param agent_list        The list of addresses used for discovering Agents.
 * @param agent_list_size   The size of the address list.
 */
UXRDLLAPI void uxr_discovery_agents(
    uint32_t attempts,
    int period,
    uxrOnAgentFound on_agent_func,
    void* args,
    const TransportLocator* agent_list,
    size_t agent_list_size);

#ifdef __cplusplus
}
#endif

#endif // UXR_CLIENT_PROFILE_DISCOVERY_DISCOVERY_H_
