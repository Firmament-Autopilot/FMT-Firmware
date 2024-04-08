#pragma once
// MESSAGE FMT_STATES_INIT PACKING

#define MAVLINK_MSG_ID_FMT_STATES_INIT 12003


typedef struct __mavlink_fmt_states_init_t {
 float euler[3]; /*< [rad] Initial attitude*/
 float pos[3]; /*< [m] Initial position*/
} mavlink_fmt_states_init_t;

#define MAVLINK_MSG_ID_FMT_STATES_INIT_LEN 24
#define MAVLINK_MSG_ID_FMT_STATES_INIT_MIN_LEN 24
#define MAVLINK_MSG_ID_12003_LEN 24
#define MAVLINK_MSG_ID_12003_MIN_LEN 24

#define MAVLINK_MSG_ID_FMT_STATES_INIT_CRC 215
#define MAVLINK_MSG_ID_12003_CRC 215

#define MAVLINK_MSG_FMT_STATES_INIT_FIELD_EULER_LEN 3
#define MAVLINK_MSG_FMT_STATES_INIT_FIELD_POS_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FMT_STATES_INIT { \
    12003, \
    "FMT_STATES_INIT", \
    2, \
    {  { "euler", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_fmt_states_init_t, euler) }, \
         { "pos", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_fmt_states_init_t, pos) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FMT_STATES_INIT { \
    "FMT_STATES_INIT", \
    2, \
    {  { "euler", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_fmt_states_init_t, euler) }, \
         { "pos", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_fmt_states_init_t, pos) }, \
         } \
}
#endif

/**
 * @brief Pack a fmt_states_init message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param euler [rad] Initial attitude
 * @param pos [m] Initial position
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fmt_states_init_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const float *euler, const float *pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_STATES_INIT_LEN];

    _mav_put_float_array(buf, 0, euler, 3);
    _mav_put_float_array(buf, 12, pos, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN);
#else
    mavlink_fmt_states_init_t packet;

    mav_array_memcpy(packet.euler, euler, sizeof(float)*3);
    mav_array_memcpy(packet.pos, pos, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FMT_STATES_INIT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FMT_STATES_INIT_MIN_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_CRC);
}

/**
 * @brief Pack a fmt_states_init message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param euler [rad] Initial attitude
 * @param pos [m] Initial position
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fmt_states_init_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const float *euler,const float *pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_STATES_INIT_LEN];

    _mav_put_float_array(buf, 0, euler, 3);
    _mav_put_float_array(buf, 12, pos, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN);
#else
    mavlink_fmt_states_init_t packet;

    mav_array_memcpy(packet.euler, euler, sizeof(float)*3);
    mav_array_memcpy(packet.pos, pos, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FMT_STATES_INIT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FMT_STATES_INIT_MIN_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_CRC);
}

/**
 * @brief Encode a fmt_states_init struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param fmt_states_init C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fmt_states_init_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_fmt_states_init_t* fmt_states_init)
{
    return mavlink_msg_fmt_states_init_pack(system_id, component_id, msg, fmt_states_init->euler, fmt_states_init->pos);
}

/**
 * @brief Encode a fmt_states_init struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fmt_states_init C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fmt_states_init_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_fmt_states_init_t* fmt_states_init)
{
    return mavlink_msg_fmt_states_init_pack_chan(system_id, component_id, chan, msg, fmt_states_init->euler, fmt_states_init->pos);
}

/**
 * @brief Send a fmt_states_init message
 * @param chan MAVLink channel to send the message
 *
 * @param euler [rad] Initial attitude
 * @param pos [m] Initial position
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fmt_states_init_send(mavlink_channel_t chan, const float *euler, const float *pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_STATES_INIT_LEN];

    _mav_put_float_array(buf, 0, euler, 3);
    _mav_put_float_array(buf, 12, pos, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_STATES_INIT, buf, MAVLINK_MSG_ID_FMT_STATES_INIT_MIN_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_CRC);
#else
    mavlink_fmt_states_init_t packet;

    mav_array_memcpy(packet.euler, euler, sizeof(float)*3);
    mav_array_memcpy(packet.pos, pos, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_STATES_INIT, (const char *)&packet, MAVLINK_MSG_ID_FMT_STATES_INIT_MIN_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_CRC);
#endif
}

/**
 * @brief Send a fmt_states_init message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_fmt_states_init_send_struct(mavlink_channel_t chan, const mavlink_fmt_states_init_t* fmt_states_init)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fmt_states_init_send(chan, fmt_states_init->euler, fmt_states_init->pos);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_STATES_INIT, (const char *)fmt_states_init, MAVLINK_MSG_ID_FMT_STATES_INIT_MIN_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_CRC);
#endif
}

#if MAVLINK_MSG_ID_FMT_STATES_INIT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_fmt_states_init_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *euler, const float *pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_float_array(buf, 0, euler, 3);
    _mav_put_float_array(buf, 12, pos, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_STATES_INIT, buf, MAVLINK_MSG_ID_FMT_STATES_INIT_MIN_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_CRC);
#else
    mavlink_fmt_states_init_t *packet = (mavlink_fmt_states_init_t *)msgbuf;

    mav_array_memcpy(packet->euler, euler, sizeof(float)*3);
    mav_array_memcpy(packet->pos, pos, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_STATES_INIT, (const char *)packet, MAVLINK_MSG_ID_FMT_STATES_INIT_MIN_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN, MAVLINK_MSG_ID_FMT_STATES_INIT_CRC);
#endif
}
#endif

#endif

// MESSAGE FMT_STATES_INIT UNPACKING


/**
 * @brief Get field euler from fmt_states_init message
 *
 * @return [rad] Initial attitude
 */
static inline uint16_t mavlink_msg_fmt_states_init_get_euler(const mavlink_message_t* msg, float *euler)
{
    return _MAV_RETURN_float_array(msg, euler, 3,  0);
}

/**
 * @brief Get field pos from fmt_states_init message
 *
 * @return [m] Initial position
 */
static inline uint16_t mavlink_msg_fmt_states_init_get_pos(const mavlink_message_t* msg, float *pos)
{
    return _MAV_RETURN_float_array(msg, pos, 3,  12);
}

/**
 * @brief Decode a fmt_states_init message into a struct
 *
 * @param msg The message to decode
 * @param fmt_states_init C-struct to decode the message contents into
 */
static inline void mavlink_msg_fmt_states_init_decode(const mavlink_message_t* msg, mavlink_fmt_states_init_t* fmt_states_init)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fmt_states_init_get_euler(msg, fmt_states_init->euler);
    mavlink_msg_fmt_states_init_get_pos(msg, fmt_states_init->pos);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FMT_STATES_INIT_LEN? msg->len : MAVLINK_MSG_ID_FMT_STATES_INIT_LEN;
        memset(fmt_states_init, 0, MAVLINK_MSG_ID_FMT_STATES_INIT_LEN);
    memcpy(fmt_states_init, _MAV_PAYLOAD(msg), len);
#endif
}
