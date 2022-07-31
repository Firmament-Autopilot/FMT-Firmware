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

#ifndef UXR_CLIENT_CORE_SESSION_SESSION_H_
#define UXR_CLIENT_CORE_SESSION_SESSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <uxr/client/core/session/session_info.h>
#include <uxr/client/core/session/stream/stream_storage.h>
#include <uxr/client/core/type/xrce_types.h>

#define UXR_TIMEOUT_INF -1

struct uxrSession;
struct uxrCommunication;

typedef void (*uxrOnStatusFunc)(
    struct uxrSession* session,
    uxrObjectId object_id,
    uint16_t request_id,
    uint8_t status,
    void* args);

typedef void (*uxrOnTopicFunc)(
    struct uxrSession* session,
    uxrObjectId object_id,
    uint16_t request_id,
    uxrStreamId stream_id,
    struct ucdrBuffer* ub,
    uint16_t length,
    void* args);

typedef void (*uxrOnTimeFunc)(
    struct uxrSession* session,
    int64_t current_timestamp,
    int64_t transmit_timestamp,
    int64_t received_timestamp,
    int64_t originate_timestamp,
    void* args);

typedef void (*uxrOnRequestFunc)(
    struct uxrSession* session,
    uxrObjectId object_id,
    uint16_t request_id,
    SampleIdentity* sample_id,
    struct ucdrBuffer* ub,
    uint16_t length,
    void* args);

typedef void (*uxrOnReplyFunc)(
    struct uxrSession* session,
    uxrObjectId object_id,
    uint16_t request_id,
    uint16_t reply_id,
    struct ucdrBuffer* ub,
    uint16_t length,
    void* args);

#ifdef PERFORMANCE_TESTING
typedef void (*uxrOnPerformanceFunc)(struct uxrSession* session, struct ucdrBuffer* mb, void* args);
#endif

typedef struct uxrSession {
    uxrSessionInfo info;
    uxrStreamStorage streams;
    struct uxrCommunication* comm;

    const uint16_t* request_list;
    uint8_t* status_list;
    size_t request_status_list_size;

    uxrOnStatusFunc on_status;
    void* on_status_args;

    uxrOnTopicFunc on_topic;
    void* on_topic_args;

    uxrOnTimeFunc on_time;
    void* on_time_args;
    int64_t time_offset;
    bool synchronized;

    uxrOnRequestFunc on_request;
    void* on_request_args;

    uxrOnReplyFunc on_reply;
    void* on_reply_args;

    bool on_data_flag;

#ifdef PERFORMANCE_TESTING
    uxrOnPerformanceFunc on_performance;
    void* on_performance_args;
#endif
} uxrSession;

/**
 * @brief Initializes a uxrSession structure.
 * @param session   The structure where the session data is stored.
 * @param comm      The uxrCommunication used for connecting with the Agent.
 *                  This parameter shall not be shared between active sessions.
 * @param key       The identifier of the Client.
 *                  All Client connected to an Agent shall have different key.
 */
UXRDLLAPI void uxr_init_session(
    uxrSession* session,
    struct uxrCommunication* comm,
    uint32_t key);

/**
 * @brief Sets the status callback.
 *        This is called when a status message is received from the Agent.
 * @param session           A uxrSession structure previously initialized.
 * @param on_status_func    The function that will be called when a valid status message arrives from the Agent.
 * @param args              User pointer data. The args will be provided to the `on_status_func` callback.
 */
UXRDLLAPI void uxr_set_status_callback(
    uxrSession* session,
    uxrOnStatusFunc on_status_func,
    void* args);

/**
 * @brief Sets the topic callback.
 *        This is called when a topic is received from the Agent.
 *        The topics will be received only if a `request_data` function has been called with a `DataReader` object id.
 * @param session           A uxrSession structure previously initialized.
 * @param on_topic_func     The function that will be called when a valid data message arrives from the Agent.
 * @param args              User pointer data. The args will be provided to the `on_topic_func` callback.
 */
UXRDLLAPI void uxr_set_topic_callback(
    uxrSession* session,
    uxrOnTopicFunc on_topic_func,
    void* args);

/**
 * @brief Sets the time synchronization callback.
 *        The callback is called when a TIMESTAMP_REPLY submessage is received from the Agent.
 *        The user could use this callback to implement her/his own time synchronization protocol.
 * @param session       A uxrSession structure previously initialized.
 * @param on_time_func  The function that will be called when a TIMESTAMP_REPLY submessage arrives from the Agent.
 * @param args          A user pointer data. The args will be provided to the `on_time_func` callback.
 */
UXRDLLAPI void uxr_set_time_callback(
    uxrSession* session,
    uxrOnTimeFunc on_time_func,
    void* args);

/**
 * @brief Sets the request callback.
 *        It will be called when a request is received from the Agent.
 *        The requests will be received only if a `request_data` function has been called with a `Requester` object id.
 * 
 * @param session               A uxrSession structure previously initialized.
 * @param on_request_func       The function that will be called when a valid request message arrives from the Agent.
 * @param args                  User pointer data. The args will be provided to the `on_request_func` callback.
 */
UXRDLLAPI void uxr_set_request_callback(
    uxrSession* session,
    uxrOnRequestFunc on_request_func,
    void* args);

/**
 * @brief Sets the reply callback.
 *        It will be called when a reply is received from the Agent.
 *        The reply will be received only if a `request_data` function has been called with a `Replier` object id.
 * 
 * @param session               A uxrSession structure previosly initialized.
 * @param on_reply_func         The function that will be called when a valid reply message arrives from the Agent.
 * @param args                  User pointer data. The args will be provided to the `on_reply_func` callback.
 * @return UXRDLLAPI uxr_set_reply_callback 
 */
UXRDLLAPI void uxr_set_reply_callback(
    uxrSession* session,
    uxrOnReplyFunc on_reply_func,
    void* args);

#ifdef PERFORMANCE_TESTING
UXRDLLAPI void uxr_set_performance_callback(uxrSession* session, uxrOnPerformanceFunc on_performance_func, void* args);
#endif

/**
 * @brief Creates a new session with the Agent.
 *        This function logs in a session, enabling any other XRCE communication with the Agent.
 * @param session   A uxrSesssion structure previously initialized.
 * @return  true in case of successful session establishment, and false in other case.
 */
UXRDLLAPI bool uxr_create_session(uxrSession* session);

/**
 * @brief Creates a new session with the Agent.
 *        This function logs in a session, enabling any other XRCE communication with the Agent.
 * @param session   A uxrSesssion structure previously initialized.
 * @param retries   Max attempts for creating the session
 * @return  true in case of successful session establishment, and false in other case.
 */
UXRDLLAPI bool uxr_create_session_retries(uxrSession* session, int retries);

/**
 * @brief Deletes a session previously created.
 *        All XRCE entities created within the session will be removed.
 *        This function logs out a session, disabling any other XRCE communication with the Agent.
 * @param session   A uxrSession structure previously initialized.
 * @return  true in case of successful session deletion, and false in other case.
 */
UXRDLLAPI bool uxr_delete_session(uxrSession* session);

/**
 * @brief Creates and initializes an output best-effort stream.
 *        The maximum number of output best-effort streams is set by the `CONFIG_MAX_OUTPUT_BEST_EFFORT_STREAMS`
 *        variable at `client.config` file.
 * @param session   A uxrSession structure previously initialized.
 * @param buffer    The memory block where the messages will be written.
 * @param size      The buffer size.
 * @return  A uxrStreamId which could by used for managing the stream.
 */
UXRDLLAPI uxrStreamId uxr_create_output_best_effort_stream(
    uxrSession* session,
    uint8_t* buffer,
    size_t size);

/**
 * @brief Creates and initializes an output reliable stream.
 *        The maximum number of output reliable streams is set by the `CONFIG_MAX_OUTPUT_RELIABLE_STREAMS`
 *        variable at `client.config` file.
 * @param session   A uxrSession structure previously initialized.
 * @param buffer    The memory block where the messages will be written.
 * @param size      The buffer size.
 * @param history   The amount of messages that the stream is able to manage.
 *                  The buffer size will be splitted into blocks according to this value.
 *                  This value shall be power of 2.
 * @return  A uxrStreamId which could by used for managing the stream.
 */
UXRDLLAPI uxrStreamId uxr_create_output_reliable_stream(
    uxrSession* session,
    uint8_t* buffer,
    size_t size,
    uint16_t history);

/**
 * @brief Creates and initializes an input best-effort stream.
 *        The maximum number of input best-effort streams is set by the `CONFIG_MAX_INPUT_BEST_EFFORT_STREAMS`
 *        variable at `client.config` file.
 * @param session   A uxrSession structure previously initialized.
 * @return  A uxrStreamId which could by used for managing the stream.
 */
UXRDLLAPI uxrStreamId uxr_create_input_best_effort_stream(uxrSession* session);

/**
 * @brief Creates and initializes an input reliable stream.
 *        The maximum number of input reliable streams is set by the `CONFIG_MAX_INPUT_RELIABLE_STREAMS`
 *        variable at `client.config` file.
 * @param session   A uxrSession structure previously initialized.
 * @param buffer    The memory block where the messages will be written.
 * @param size      The buffer size.
 * @param history   The amount of messages that the stream is able to manage.
 *                  The buffer size will be splitted into blocks according to this value.
 *                  This value shall be power of 2.
 * @return  A uxrStreamId which could by used for managing the stream.
 */
UXRDLLAPI uxrStreamId uxr_create_input_reliable_stream(
    uxrSession* session,
    uint8_t* buffer,
    size_t size,
    uint16_t history);

/**
 * @brief Flashes all the output streams seding the data through the transport.
 * @param session   A uxrSession structure previously initialized.
 */
UXRDLLAPI void uxr_flash_output_streams(uxrSession* session);

/**
 * @brief  Keeps communication between the Client and the Agent.
 *         This function involves the following actions:
 *          1. flashing all the output streams sending the data through the transport,
 *          2. listening messages from the Agent calling the associated callback (topic and status).
 *        The aforementioned actions will be performed in a loop until the waiting time for a new message
 *        exceeds the `time`.
 * @param session   A uxrSession structure previously initialized.
 * @param time      The waiting time in milliseconds.
 * @return  `true` in case of the Agent confirms the reception of all the output messages. `false` in other case.
 */
UXRDLLAPI bool uxr_run_session_time(
    uxrSession* session,
    int time);

/**
 * @brief  Keeps communication between the Client and the Agent.
 *         This function involves the following actions:
 *          1. flashing all the output streams sending the data through the transport,
 *          2. listening messages from the Agent calling the associated callback (topic and status).
 *        The aforementioned actions will be performed in a loop until the `timeout` is exceeded.
 * @param session   A uxrSession structure previously initialized.
 * @param timeout   The waiting time in milliseconds.
 * @return  `true` in case of the Agent confirms the reception of all the output messages. `false` in other case.
 */
UXRDLLAPI bool uxr_run_session_timeout(
    uxrSession* session,
    int timeout);

/**
 * @brief  Keeps communication between the Client and the Agent.
 *         This function involves the following actions:
 *          1. flashing all the output streams sending the data through the transport,
 *          2. listening messages from the Agent calling the associated callback (topic, status, request and replies).
 *        The aforementioned actions will be performed in a loop until a data message is received 
 *        or the `timeout` is exceeded.
 * @param session   A uxrSession structure previously initialized.
 * @param timeout   The waiting time in milliseconds.
 * @return  `true` in case of a data message is received before the timeout. `false` in other case.
 */
UXRDLLAPI bool uxr_run_session_until_data(
    uxrSession* session,
    int timeout);

/**
 * @brief  Keeps communication between the Client and the Agent.
 *         This function involves the following actions:
 *          1. flashing all the output streams sending the data through the transport,
 *          2. listening messages from the Agent calling the associated callback (topic and status).
 *        The aforementioned actions will be performed in a loop until a message is received
 *        or the `timeout` is exceeded.
 * @param session   A uxrSession structure previously initialized.
 * @param timeout   The waiting time in milliseconds.
 * @return  `true` if a message is received. `false` in other case.
 */
UXRDLLAPI bool uxr_run_session_until_timeout(
    uxrSession* session,
    int timeout);

/**
 * @brief  Keeps communication between the Client and the Agent.
 *         This function involves the following actions:
 *          1. flashing all the output streams sending the data through the transport,
 *          2. listening messages from the Agent calling the associated callback (topic and status).
 *        The aforementioned actions will be performed in a loop until a the `timeout` is exceeded
 *        or the output reliable streams confirm the delivery of all their messages.
 * @param session   A uxrSession structure previously initialized.
 * @param timeout   The waiting time in milliseconds.
 * @return  `true` if all output reliable streams confirm the delivery of their messages. `false` in other case.
 */
UXRDLLAPI bool uxr_run_session_until_confirm_delivery(
    uxrSession* session,
    int timeout);

/**
 * @brief  Keeps communication between the Client and the Agent.
 *         This function involves the following actions:
 *          1. flashing all the output streams sending the data through the transport,
 *          2. listening messages from the Agent calling the associated callback (topic and status).
 *        The aforementioned actions will be performed in a loop until a the `timeout` is exceeded
 *        or all the requested status are received.
 * @param session       A uxrSession structure previously initialized.
 * @param timeout       The waiting time in milliseconds.
 * @param request_list  The array of requests to confirm with a status.
 * @param status_list   The uninitialized array with the same size as `request_list`
 *                      where the status values will be written.
 * @param list_size     the size of `request_list` and `status_list` arrays.
 * @return  `true` if all status are received. `false` in other case.
 */
UXRDLLAPI bool uxr_run_session_until_all_status(
    uxrSession* session,
    int timeout,
    const uint16_t* request_list,
    uint8_t* status_list,
    size_t list_size);

/**
 * @brief  Keeps communication between the Client and the Agent.
 *         This function involves the following actions:
 *          1. flashing all the output streams sending the data through the transport,
 *          2. listening messages from the Agent calling the associated callback (topic and status).
 *        The aforementioned actions will be performed in a loop until a the `timeout` is exceeded
 *        or one of the requested status is received.
 * @param session       A uxrSession structure previously initialized.
 * @param timeout       The waiting time in milliseconds.
 * @param request_list  The array of requests to confirm with a status.
 * @param status_list   The uninitialized array with the same size as `request_list`
 *                      where the status values will be written.
 * @param list_size     the size of `request_list` and `status_list` arrays.
 * @return  `true` if a status is received and its value is `UXR_STATUS_OK` or `UXR_STATUS_OK_MATCHED`.
 *          `false` in other case.
 */
UXRDLLAPI bool uxr_run_session_until_one_status(
    uxrSession* session,
    int timeout,
    const uint16_t* request_list,
    uint8_t* status_list,
    size_t list_size);

/**
 * @brief Synchronizes the session time using by default the NTP protocol.
 * @param session   A uxrSession structure previously initialized.
 * @param time      The waiting time in milliseconds.
 * @return  `true` in case of successful synchronization. `false` in other case.
 */
UXRDLLAPI bool uxr_sync_session(
    uxrSession* session,
    int time);

/**
 * @brief Returns the epoch time in milliseconds taking into account the offset computed during the time synchronization.
 * @param session   A uxrSession structure previosly initialized.
 * @return The epoch time in milliseconds.
 */
UXRDLLAPI int64_t uxr_epoch_millis(uxrSession* session);

/**
 * @brief Returns the epoch time in nanoseconds taking into account the offset computed during the time synchronization.
 * @param session   A uxrSession structure previosly initialized.
 * @return The epoch time in nanoseconds.
 */
UXRDLLAPI int64_t uxr_epoch_nanos(uxrSession* session);

#ifdef PERFORMANCE_TESTING
UXRDLLAPI bool uxr_buffer_performance(uxrSession* session,
                                      uxrStreamId stream_id,
                                      uint64_t epoch_time,
                                      uint8_t* buf,
                                      uint16_t len,
                                      bool echo);
#endif

#ifdef __cplusplus
}
#endif

#endif // UXR_CLIENT_CORE_SESSION_SESSION_H
