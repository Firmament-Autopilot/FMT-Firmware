#pragma once
// MESSAGE PARAM_START_TRANSACTION PACKING

#define MAVLINK_MSG_ID_PARAM_START_TRANSACTION 328

typedef struct __mavlink_param_start_transaction_t {
    uint8_t target_system;    /*<  System ID*/
    uint8_t target_component; /*<  Component ID*/
    uint8_t param_transport;  /*<  Possible transport layers to set and get parameters via mavlink during a parameter transaction.*/
    uint8_t response;         /*<  Message acceptance response (sent back to GS).*/
} mavlink_param_start_transaction_t;

#define MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN     4
#define MAVLINK_MSG_ID_PARAM_START_TRANSACTION_MIN_LEN 4
#define MAVLINK_MSG_ID_328_LEN                         4
#define MAVLINK_MSG_ID_328_MIN_LEN                     4

#define MAVLINK_MSG_ID_PARAM_START_TRANSACTION_CRC 74
#define MAVLINK_MSG_ID_328_CRC                     74

#if MAVLINK_COMMAND_24BIT
    #define MAVLINK_MESSAGE_INFO_PARAM_START_TRANSACTION                                                                                     \
        {                                                                                                                                    \
            328,                                                                                                                             \
                "PARAM_START_TRANSACTION",                                                                                                   \
                4,                                                                                                                           \
            {                                                                                                                                \
                { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_start_transaction_t, target_system) },           \
                    { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_start_transaction_t, target_component) }, \
                    { "param_transport", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_param_start_transaction_t, param_transport) },   \
                    { "response", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_param_start_transaction_t, response) },                 \
            }                                                                                                                                \
        }
#else
    #define MAVLINK_MESSAGE_INFO_PARAM_START_TRANSACTION                                                                                     \
        {                                                                                                                                    \
            "PARAM_START_TRANSACTION",                                                                                                       \
                4,                                                                                                                           \
            {                                                                                                                                \
                { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_start_transaction_t, target_system) },           \
                    { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_start_transaction_t, target_component) }, \
                    { "param_transport", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_param_start_transaction_t, param_transport) },   \
                    { "response", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_param_start_transaction_t, response) },                 \
            }                                                                                                                                \
        }
#endif

/**
 * @brief Pack a param_start_transaction message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param_transport  Possible transport layers to set and get parameters via mavlink during a parameter transaction.
 * @param response  Message acceptance response (sent back to GS).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_start_transaction_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                                                                uint8_t target_system, uint8_t target_component, uint8_t param_transport, uint8_t response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, param_transport);
    _mav_put_uint8_t(buf, 3, response);

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN);
#else
    mavlink_param_start_transaction_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.param_transport = param_transport;
    packet.response = response;

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARAM_START_TRANSACTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_MIN_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_CRC);
}

/**
 * @brief Pack a param_start_transaction message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param_transport  Possible transport layers to set and get parameters via mavlink during a parameter transaction.
 * @param response  Message acceptance response (sent back to GS).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_start_transaction_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                                                                     mavlink_message_t* msg,
                                                                     uint8_t target_system, uint8_t target_component, uint8_t param_transport, uint8_t response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, param_transport);
    _mav_put_uint8_t(buf, 3, response);

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN);
#else
    mavlink_param_start_transaction_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.param_transport = param_transport;
    packet.response = response;

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARAM_START_TRANSACTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_MIN_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_CRC);
}

/**
 * @brief Encode a param_start_transaction struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_start_transaction C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_start_transaction_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_start_transaction_t* param_start_transaction)
{
    return mavlink_msg_param_start_transaction_pack(system_id, component_id, msg, param_start_transaction->target_system, param_start_transaction->target_component, param_start_transaction->param_transport, param_start_transaction->response);
}

/**
 * @brief Encode a param_start_transaction struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_start_transaction C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_start_transaction_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_start_transaction_t* param_start_transaction)
{
    return mavlink_msg_param_start_transaction_pack_chan(system_id, component_id, chan, msg, param_start_transaction->target_system, param_start_transaction->target_component, param_start_transaction->param_transport, param_start_transaction->response);
}

/**
 * @brief Send a param_start_transaction message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param_transport  Possible transport layers to set and get parameters via mavlink during a parameter transaction.
 * @param response  Message acceptance response (sent back to GS).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_param_start_transaction_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t param_transport, uint8_t response)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, param_transport);
    _mav_put_uint8_t(buf, 3, response);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_START_TRANSACTION, buf, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_MIN_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_CRC);
    #else
    mavlink_param_start_transaction_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.param_transport = param_transport;
    packet.response = response;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_START_TRANSACTION, (const char*)&packet, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_MIN_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_CRC);
    #endif
}

/**
 * @brief Send a param_start_transaction message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_param_start_transaction_send_struct(mavlink_channel_t chan, const mavlink_param_start_transaction_t* param_start_transaction)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_param_start_transaction_send(chan, param_start_transaction->target_system, param_start_transaction->target_component, param_start_transaction->param_transport, param_start_transaction->response);
    #else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_START_TRANSACTION, (const char*)param_start_transaction, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_MIN_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_CRC);
    #endif
}

    #if MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_param_start_transaction_send_buf(mavlink_message_t* msgbuf, mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t param_transport, uint8_t response)
{
        #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char* buf = (char*)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, param_transport);
    _mav_put_uint8_t(buf, 3, response);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_START_TRANSACTION, buf, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_MIN_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_CRC);
        #else
    mavlink_param_start_transaction_t* packet = (mavlink_param_start_transaction_t*)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->param_transport = param_transport;
    packet->response = response;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_START_TRANSACTION, (const char*)packet, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_MIN_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_CRC);
        #endif
}
    #endif

#endif

// MESSAGE PARAM_START_TRANSACTION UNPACKING

/**
 * @brief Get field target_system from param_start_transaction message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_param_start_transaction_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg, 0);
}

/**
 * @brief Get field target_component from param_start_transaction message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_param_start_transaction_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg, 1);
}

/**
 * @brief Get field param_transport from param_start_transaction message
 *
 * @return  Possible transport layers to set and get parameters via mavlink during a parameter transaction.
 */
static inline uint8_t mavlink_msg_param_start_transaction_get_param_transport(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg, 2);
}

/**
 * @brief Get field response from param_start_transaction message
 *
 * @return  Message acceptance response (sent back to GS).
 */
static inline uint8_t mavlink_msg_param_start_transaction_get_response(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg, 3);
}

/**
 * @brief Decode a param_start_transaction message into a struct
 *
 * @param msg The message to decode
 * @param param_start_transaction C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_start_transaction_decode(const mavlink_message_t* msg, mavlink_param_start_transaction_t* param_start_transaction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    param_start_transaction->target_system = mavlink_msg_param_start_transaction_get_target_system(msg);
    param_start_transaction->target_component = mavlink_msg_param_start_transaction_get_target_component(msg);
    param_start_transaction->param_transport = mavlink_msg_param_start_transaction_get_param_transport(msg);
    param_start_transaction->response = mavlink_msg_param_start_transaction_get_response(msg);
#else
    uint8_t len = msg->len < MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN ? msg->len : MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN;
    memset(param_start_transaction, 0, MAVLINK_MSG_ID_PARAM_START_TRANSACTION_LEN);
    memcpy(param_start_transaction, _MAV_PAYLOAD(msg), len);
#endif
}
