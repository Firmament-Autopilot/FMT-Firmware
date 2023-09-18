#pragma once
// MESSAGE FMT_ENVIRONMENT_INFO PACKING

#define MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO 12002


typedef struct __mavlink_fmt_environment_info_t {
 float hit_point[3]; /*< [m] Hit point in global frame*/
 float hit_normal[3]; /*<  Hit normal in global frame*/
 float hit_location[3]; /*< [m] Hit location in global frame*/
} mavlink_fmt_environment_info_t;

#define MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN 36
#define MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN 36
#define MAVLINK_MSG_ID_12002_LEN 36
#define MAVLINK_MSG_ID_12002_MIN_LEN 36

#define MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_CRC 127
#define MAVLINK_MSG_ID_12002_CRC 127

#define MAVLINK_MSG_FMT_ENVIRONMENT_INFO_FIELD_HIT_POINT_LEN 3
#define MAVLINK_MSG_FMT_ENVIRONMENT_INFO_FIELD_HIT_NORMAL_LEN 3
#define MAVLINK_MSG_FMT_ENVIRONMENT_INFO_FIELD_HIT_LOCATION_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FMT_ENVIRONMENT_INFO { \
    12002, \
    "FMT_ENVIRONMENT_INFO", \
    3, \
    {  { "hit_point", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_fmt_environment_info_t, hit_point) }, \
         { "hit_normal", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_fmt_environment_info_t, hit_normal) }, \
         { "hit_location", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_fmt_environment_info_t, hit_location) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FMT_ENVIRONMENT_INFO { \
    "FMT_ENVIRONMENT_INFO", \
    3, \
    {  { "hit_point", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_fmt_environment_info_t, hit_point) }, \
         { "hit_normal", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_fmt_environment_info_t, hit_normal) }, \
         { "hit_location", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_fmt_environment_info_t, hit_location) }, \
         } \
}
#endif

/**
 * @brief Pack a fmt_environment_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param hit_point [m] Hit point in global frame
 * @param hit_normal  Hit normal in global frame
 * @param hit_location [m] Hit location in global frame
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fmt_environment_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const float *hit_point, const float *hit_normal, const float *hit_location)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN];

    _mav_put_float_array(buf, 0, hit_point, 3);
    _mav_put_float_array(buf, 12, hit_normal, 3);
    _mav_put_float_array(buf, 24, hit_location, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN);
#else
    mavlink_fmt_environment_info_t packet;

    mav_array_memcpy(packet.hit_point, hit_point, sizeof(float)*3);
    mav_array_memcpy(packet.hit_normal, hit_normal, sizeof(float)*3);
    mav_array_memcpy(packet.hit_location, hit_location, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_CRC);
}

/**
 * @brief Pack a fmt_environment_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hit_point [m] Hit point in global frame
 * @param hit_normal  Hit normal in global frame
 * @param hit_location [m] Hit location in global frame
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fmt_environment_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const float *hit_point,const float *hit_normal,const float *hit_location)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN];

    _mav_put_float_array(buf, 0, hit_point, 3);
    _mav_put_float_array(buf, 12, hit_normal, 3);
    _mav_put_float_array(buf, 24, hit_location, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN);
#else
    mavlink_fmt_environment_info_t packet;

    mav_array_memcpy(packet.hit_point, hit_point, sizeof(float)*3);
    mav_array_memcpy(packet.hit_normal, hit_normal, sizeof(float)*3);
    mav_array_memcpy(packet.hit_location, hit_location, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_CRC);
}

/**
 * @brief Encode a fmt_environment_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param fmt_environment_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fmt_environment_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_fmt_environment_info_t* fmt_environment_info)
{
    return mavlink_msg_fmt_environment_info_pack(system_id, component_id, msg, fmt_environment_info->hit_point, fmt_environment_info->hit_normal, fmt_environment_info->hit_location);
}

/**
 * @brief Encode a fmt_environment_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fmt_environment_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fmt_environment_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_fmt_environment_info_t* fmt_environment_info)
{
    return mavlink_msg_fmt_environment_info_pack_chan(system_id, component_id, chan, msg, fmt_environment_info->hit_point, fmt_environment_info->hit_normal, fmt_environment_info->hit_location);
}

/**
 * @brief Send a fmt_environment_info message
 * @param chan MAVLink channel to send the message
 *
 * @param hit_point [m] Hit point in global frame
 * @param hit_normal  Hit normal in global frame
 * @param hit_location [m] Hit location in global frame
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fmt_environment_info_send(mavlink_channel_t chan, const float *hit_point, const float *hit_normal, const float *hit_location)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN];

    _mav_put_float_array(buf, 0, hit_point, 3);
    _mav_put_float_array(buf, 12, hit_normal, 3);
    _mav_put_float_array(buf, 24, hit_location, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO, buf, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_CRC);
#else
    mavlink_fmt_environment_info_t packet;

    mav_array_memcpy(packet.hit_point, hit_point, sizeof(float)*3);
    mav_array_memcpy(packet.hit_normal, hit_normal, sizeof(float)*3);
    mav_array_memcpy(packet.hit_location, hit_location, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO, (const char *)&packet, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_CRC);
#endif
}

/**
 * @brief Send a fmt_environment_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_fmt_environment_info_send_struct(mavlink_channel_t chan, const mavlink_fmt_environment_info_t* fmt_environment_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fmt_environment_info_send(chan, fmt_environment_info->hit_point, fmt_environment_info->hit_normal, fmt_environment_info->hit_location);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO, (const char *)fmt_environment_info, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_fmt_environment_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *hit_point, const float *hit_normal, const float *hit_location)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_float_array(buf, 0, hit_point, 3);
    _mav_put_float_array(buf, 12, hit_normal, 3);
    _mav_put_float_array(buf, 24, hit_location, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO, buf, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_CRC);
#else
    mavlink_fmt_environment_info_t *packet = (mavlink_fmt_environment_info_t *)msgbuf;

    mav_array_memcpy(packet->hit_point, hit_point, sizeof(float)*3);
    mav_array_memcpy(packet->hit_normal, hit_normal, sizeof(float)*3);
    mav_array_memcpy(packet->hit_location, hit_location, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO, (const char *)packet, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE FMT_ENVIRONMENT_INFO UNPACKING


/**
 * @brief Get field hit_point from fmt_environment_info message
 *
 * @return [m] Hit point in global frame
 */
static inline uint16_t mavlink_msg_fmt_environment_info_get_hit_point(const mavlink_message_t* msg, float *hit_point)
{
    return _MAV_RETURN_float_array(msg, hit_point, 3,  0);
}

/**
 * @brief Get field hit_normal from fmt_environment_info message
 *
 * @return  Hit normal in global frame
 */
static inline uint16_t mavlink_msg_fmt_environment_info_get_hit_normal(const mavlink_message_t* msg, float *hit_normal)
{
    return _MAV_RETURN_float_array(msg, hit_normal, 3,  12);
}

/**
 * @brief Get field hit_location from fmt_environment_info message
 *
 * @return [m] Hit location in global frame
 */
static inline uint16_t mavlink_msg_fmt_environment_info_get_hit_location(const mavlink_message_t* msg, float *hit_location)
{
    return _MAV_RETURN_float_array(msg, hit_location, 3,  24);
}

/**
 * @brief Decode a fmt_environment_info message into a struct
 *
 * @param msg The message to decode
 * @param fmt_environment_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_fmt_environment_info_decode(const mavlink_message_t* msg, mavlink_fmt_environment_info_t* fmt_environment_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fmt_environment_info_get_hit_point(msg, fmt_environment_info->hit_point);
    mavlink_msg_fmt_environment_info_get_hit_normal(msg, fmt_environment_info->hit_normal);
    mavlink_msg_fmt_environment_info_get_hit_location(msg, fmt_environment_info->hit_location);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN? msg->len : MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN;
        memset(fmt_environment_info, 0, MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_LEN);
    memcpy(fmt_environment_info, _MAV_PAYLOAD(msg), len);
#endif
}
