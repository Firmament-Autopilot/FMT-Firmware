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

#ifndef _UXR_CLIENT_CORE_SESSION_OBJECT_ID_H_
#define _UXR_CLIENT_CORE_SESSION_OBJECT_ID_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <uxr/client/visibility.h>

#define UXR_INVALID_ID     0x00
#define UXR_PARTICIPANT_ID 0x01
#define UXR_TOPIC_ID       0x02
#define UXR_PUBLISHER_ID   0x03
#define UXR_SUBSCRIBER_ID  0x04
#define UXR_DATAWRITER_ID  0x05
#define UXR_DATAREADER_ID  0x06
#define UXR_REQUESTER_ID   0x07
#define UXR_REPLIER_ID     0x08
#define UXR_OTHER_ID       0x0F

typedef struct uxrObjectId {
    uint16_t id;
    uint8_t type;

} uxrObjectId;

UXRDLLAPI uxrObjectId uxr_object_id(uint16_t id, uint8_t type);

UXRDLLAPI uxrObjectId uxr_object_id_from_raw(const uint8_t* raw);
UXRDLLAPI void uxr_object_id_to_raw(uxrObjectId object_id, uint8_t* raw);

#ifdef __cplusplus
}
#endif

#endif //_UXR_CLIENT_CORE_SESSION_OBJECT_ID_H_
