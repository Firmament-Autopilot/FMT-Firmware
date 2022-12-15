#pragma once
// MESSAGE FMT_PILOT_CMD PACKING

#define MAVLINK_MSG_ID_FMT_PILOT_CMD 12000


typedef struct __mavlink_fmt_pilot_cmd_t {
 uint32_t timestamp; /*< [ms] Timestamp*/
 float ls_lr; /*<  Left stick left/right*/
 float ls_ud; /*<  Left stick up/down*/
 float rs_lr; /*<  Right stick left/right*/
 float rs_ud; /*<  Right stick up/down*/
 uint32_t mode; /*<  Pilot mode*/
 uint32_t command_1; /*<  Pilot command 1*/
 uint32_t command_2; /*<  Pilot command 2*/
} mavlink_fmt_pilot_cmd_t;

#define MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN 32
#define MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN 32
#define MAVLINK_MSG_ID_12000_LEN 32
#define MAVLINK_MSG_ID_12000_MIN_LEN 32

#define MAVLINK_MSG_ID_FMT_PILOT_CMD_CRC 143
#define MAVLINK_MSG_ID_12000_CRC 143



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FMT_PILOT_CMD { \
    12000, \
    "FMT_PILOT_CMD", \
    8, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_fmt_pilot_cmd_t, timestamp) }, \
         { "ls_lr", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_fmt_pilot_cmd_t, ls_lr) }, \
         { "ls_ud", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_fmt_pilot_cmd_t, ls_ud) }, \
         { "rs_lr", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_fmt_pilot_cmd_t, rs_lr) }, \
         { "rs_ud", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_fmt_pilot_cmd_t, rs_ud) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_fmt_pilot_cmd_t, mode) }, \
         { "command_1", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_fmt_pilot_cmd_t, command_1) }, \
         { "command_2", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_fmt_pilot_cmd_t, command_2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FMT_PILOT_CMD { \
    "FMT_PILOT_CMD", \
    8, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_fmt_pilot_cmd_t, timestamp) }, \
         { "ls_lr", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_fmt_pilot_cmd_t, ls_lr) }, \
         { "ls_ud", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_fmt_pilot_cmd_t, ls_ud) }, \
         { "rs_lr", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_fmt_pilot_cmd_t, rs_lr) }, \
         { "rs_ud", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_fmt_pilot_cmd_t, rs_ud) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_fmt_pilot_cmd_t, mode) }, \
         { "command_1", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_fmt_pilot_cmd_t, command_1) }, \
         { "command_2", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_fmt_pilot_cmd_t, command_2) }, \
         } \
}
#endif

/**
 * @brief Pack a fmt_pilot_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp [ms] Timestamp
 * @param ls_lr  Left stick left/right
 * @param ls_ud  Left stick up/down
 * @param rs_lr  Right stick left/right
 * @param rs_ud  Right stick up/down
 * @param mode  Pilot mode
 * @param command_1  Pilot command 1
 * @param command_2  Pilot command 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fmt_pilot_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t timestamp, float ls_lr, float ls_ud, float rs_lr, float rs_ud, uint32_t mode, uint32_t command_1, uint32_t command_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN];
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, ls_lr);
    _mav_put_float(buf, 8, ls_ud);
    _mav_put_float(buf, 12, rs_lr);
    _mav_put_float(buf, 16, rs_ud);
    _mav_put_uint32_t(buf, 20, mode);
    _mav_put_uint32_t(buf, 24, command_1);
    _mav_put_uint32_t(buf, 28, command_2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN);
#else
    mavlink_fmt_pilot_cmd_t packet;
    packet.timestamp = timestamp;
    packet.ls_lr = ls_lr;
    packet.ls_ud = ls_ud;
    packet.rs_lr = rs_lr;
    packet.rs_ud = rs_ud;
    packet.mode = mode;
    packet.command_1 = command_1;
    packet.command_2 = command_2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FMT_PILOT_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_CRC);
}

/**
 * @brief Pack a fmt_pilot_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp [ms] Timestamp
 * @param ls_lr  Left stick left/right
 * @param ls_ud  Left stick up/down
 * @param rs_lr  Right stick left/right
 * @param rs_ud  Right stick up/down
 * @param mode  Pilot mode
 * @param command_1  Pilot command 1
 * @param command_2  Pilot command 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fmt_pilot_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t timestamp,float ls_lr,float ls_ud,float rs_lr,float rs_ud,uint32_t mode,uint32_t command_1,uint32_t command_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN];
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, ls_lr);
    _mav_put_float(buf, 8, ls_ud);
    _mav_put_float(buf, 12, rs_lr);
    _mav_put_float(buf, 16, rs_ud);
    _mav_put_uint32_t(buf, 20, mode);
    _mav_put_uint32_t(buf, 24, command_1);
    _mav_put_uint32_t(buf, 28, command_2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN);
#else
    mavlink_fmt_pilot_cmd_t packet;
    packet.timestamp = timestamp;
    packet.ls_lr = ls_lr;
    packet.ls_ud = ls_ud;
    packet.rs_lr = rs_lr;
    packet.rs_ud = rs_ud;
    packet.mode = mode;
    packet.command_1 = command_1;
    packet.command_2 = command_2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FMT_PILOT_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_CRC);
}

/**
 * @brief Encode a fmt_pilot_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param fmt_pilot_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fmt_pilot_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_fmt_pilot_cmd_t* fmt_pilot_cmd)
{
    return mavlink_msg_fmt_pilot_cmd_pack(system_id, component_id, msg, fmt_pilot_cmd->timestamp, fmt_pilot_cmd->ls_lr, fmt_pilot_cmd->ls_ud, fmt_pilot_cmd->rs_lr, fmt_pilot_cmd->rs_ud, fmt_pilot_cmd->mode, fmt_pilot_cmd->command_1, fmt_pilot_cmd->command_2);
}

/**
 * @brief Encode a fmt_pilot_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fmt_pilot_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fmt_pilot_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_fmt_pilot_cmd_t* fmt_pilot_cmd)
{
    return mavlink_msg_fmt_pilot_cmd_pack_chan(system_id, component_id, chan, msg, fmt_pilot_cmd->timestamp, fmt_pilot_cmd->ls_lr, fmt_pilot_cmd->ls_ud, fmt_pilot_cmd->rs_lr, fmt_pilot_cmd->rs_ud, fmt_pilot_cmd->mode, fmt_pilot_cmd->command_1, fmt_pilot_cmd->command_2);
}

/**
 * @brief Send a fmt_pilot_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp [ms] Timestamp
 * @param ls_lr  Left stick left/right
 * @param ls_ud  Left stick up/down
 * @param rs_lr  Right stick left/right
 * @param rs_ud  Right stick up/down
 * @param mode  Pilot mode
 * @param command_1  Pilot command 1
 * @param command_2  Pilot command 2
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fmt_pilot_cmd_send(mavlink_channel_t chan, uint32_t timestamp, float ls_lr, float ls_ud, float rs_lr, float rs_ud, uint32_t mode, uint32_t command_1, uint32_t command_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN];
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, ls_lr);
    _mav_put_float(buf, 8, ls_ud);
    _mav_put_float(buf, 12, rs_lr);
    _mav_put_float(buf, 16, rs_ud);
    _mav_put_uint32_t(buf, 20, mode);
    _mav_put_uint32_t(buf, 24, command_1);
    _mav_put_uint32_t(buf, 28, command_2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_PILOT_CMD, buf, MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_CRC);
#else
    mavlink_fmt_pilot_cmd_t packet;
    packet.timestamp = timestamp;
    packet.ls_lr = ls_lr;
    packet.ls_ud = ls_ud;
    packet.rs_lr = rs_lr;
    packet.rs_ud = rs_ud;
    packet.mode = mode;
    packet.command_1 = command_1;
    packet.command_2 = command_2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_PILOT_CMD, (const char *)&packet, MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_CRC);
#endif
}

/**
 * @brief Send a fmt_pilot_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_fmt_pilot_cmd_send_struct(mavlink_channel_t chan, const mavlink_fmt_pilot_cmd_t* fmt_pilot_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fmt_pilot_cmd_send(chan, fmt_pilot_cmd->timestamp, fmt_pilot_cmd->ls_lr, fmt_pilot_cmd->ls_ud, fmt_pilot_cmd->rs_lr, fmt_pilot_cmd->rs_ud, fmt_pilot_cmd->mode, fmt_pilot_cmd->command_1, fmt_pilot_cmd->command_2);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_PILOT_CMD, (const char *)fmt_pilot_cmd, MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_fmt_pilot_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t timestamp, float ls_lr, float ls_ud, float rs_lr, float rs_ud, uint32_t mode, uint32_t command_1, uint32_t command_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, ls_lr);
    _mav_put_float(buf, 8, ls_ud);
    _mav_put_float(buf, 12, rs_lr);
    _mav_put_float(buf, 16, rs_ud);
    _mav_put_uint32_t(buf, 20, mode);
    _mav_put_uint32_t(buf, 24, command_1);
    _mav_put_uint32_t(buf, 28, command_2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_PILOT_CMD, buf, MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_CRC);
#else
    mavlink_fmt_pilot_cmd_t *packet = (mavlink_fmt_pilot_cmd_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->ls_lr = ls_lr;
    packet->ls_ud = ls_ud;
    packet->rs_lr = rs_lr;
    packet->rs_ud = rs_ud;
    packet->mode = mode;
    packet->command_1 = command_1;
    packet->command_2 = command_2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_PILOT_CMD, (const char *)packet, MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN, MAVLINK_MSG_ID_FMT_PILOT_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE FMT_PILOT_CMD UNPACKING


/**
 * @brief Get field timestamp from fmt_pilot_cmd message
 *
 * @return [ms] Timestamp
 */
static inline uint32_t mavlink_msg_fmt_pilot_cmd_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field ls_lr from fmt_pilot_cmd message
 *
 * @return  Left stick left/right
 */
static inline float mavlink_msg_fmt_pilot_cmd_get_ls_lr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field ls_ud from fmt_pilot_cmd message
 *
 * @return  Left stick up/down
 */
static inline float mavlink_msg_fmt_pilot_cmd_get_ls_ud(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field rs_lr from fmt_pilot_cmd message
 *
 * @return  Right stick left/right
 */
static inline float mavlink_msg_fmt_pilot_cmd_get_rs_lr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field rs_ud from fmt_pilot_cmd message
 *
 * @return  Right stick up/down
 */
static inline float mavlink_msg_fmt_pilot_cmd_get_rs_ud(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field mode from fmt_pilot_cmd message
 *
 * @return  Pilot mode
 */
static inline uint32_t mavlink_msg_fmt_pilot_cmd_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field command_1 from fmt_pilot_cmd message
 *
 * @return  Pilot command 1
 */
static inline uint32_t mavlink_msg_fmt_pilot_cmd_get_command_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field command_2 from fmt_pilot_cmd message
 *
 * @return  Pilot command 2
 */
static inline uint32_t mavlink_msg_fmt_pilot_cmd_get_command_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  28);
}

/**
 * @brief Decode a fmt_pilot_cmd message into a struct
 *
 * @param msg The message to decode
 * @param fmt_pilot_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_fmt_pilot_cmd_decode(const mavlink_message_t* msg, mavlink_fmt_pilot_cmd_t* fmt_pilot_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    fmt_pilot_cmd->timestamp = mavlink_msg_fmt_pilot_cmd_get_timestamp(msg);
    fmt_pilot_cmd->ls_lr = mavlink_msg_fmt_pilot_cmd_get_ls_lr(msg);
    fmt_pilot_cmd->ls_ud = mavlink_msg_fmt_pilot_cmd_get_ls_ud(msg);
    fmt_pilot_cmd->rs_lr = mavlink_msg_fmt_pilot_cmd_get_rs_lr(msg);
    fmt_pilot_cmd->rs_ud = mavlink_msg_fmt_pilot_cmd_get_rs_ud(msg);
    fmt_pilot_cmd->mode = mavlink_msg_fmt_pilot_cmd_get_mode(msg);
    fmt_pilot_cmd->command_1 = mavlink_msg_fmt_pilot_cmd_get_command_1(msg);
    fmt_pilot_cmd->command_2 = mavlink_msg_fmt_pilot_cmd_get_command_2(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN? msg->len : MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN;
        memset(fmt_pilot_cmd, 0, MAVLINK_MSG_ID_FMT_PILOT_CMD_LEN);
    memcpy(fmt_pilot_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
