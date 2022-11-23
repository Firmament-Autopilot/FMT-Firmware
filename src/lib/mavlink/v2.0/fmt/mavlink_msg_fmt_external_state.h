#pragma once
// MESSAGE FMT_EXTERNAL_STATE PACKING

#define MAVLINK_MSG_ID_FMT_EXTERNAL_STATE 12001


typedef struct __mavlink_fmt_external_state_t {
 uint32_t timestamp; /*< [ms] Timestamp*/
 float quat[4]; /*<  Vehicle quaternion*/
 float rot[3]; /*< [rad/s] Vehicle rotation speed in body frame*/
 float acc[3]; /*< [m/s^2] Vehicle accleration in earth frame*/
 float vel[3]; /*< [m/s] Vehicle velocity in earth frame*/
 float pos[3]; /*< [m] Vehicle position in earth frame*/
 int32_t lla[3]; /*< [degE7/degE7/mm] Vehicle WGS84 global position*/
 float h_AGL; /*< [m] Height above ground*/
 uint32_t flag; /*<  External states flag*/
} mavlink_fmt_external_state_t;

#define MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN 88
#define MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN 88
#define MAVLINK_MSG_ID_12001_LEN 88
#define MAVLINK_MSG_ID_12001_MIN_LEN 88

#define MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_CRC 168
#define MAVLINK_MSG_ID_12001_CRC 168

#define MAVLINK_MSG_FMT_EXTERNAL_STATE_FIELD_QUAT_LEN 4
#define MAVLINK_MSG_FMT_EXTERNAL_STATE_FIELD_ROT_LEN 3
#define MAVLINK_MSG_FMT_EXTERNAL_STATE_FIELD_ACC_LEN 3
#define MAVLINK_MSG_FMT_EXTERNAL_STATE_FIELD_VEL_LEN 3
#define MAVLINK_MSG_FMT_EXTERNAL_STATE_FIELD_POS_LEN 3
#define MAVLINK_MSG_FMT_EXTERNAL_STATE_FIELD_LLA_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FMT_EXTERNAL_STATE { \
    12001, \
    "FMT_EXTERNAL_STATE", \
    9, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_fmt_external_state_t, timestamp) }, \
         { "quat", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_fmt_external_state_t, quat) }, \
         { "rot", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_fmt_external_state_t, rot) }, \
         { "acc", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_fmt_external_state_t, acc) }, \
         { "vel", NULL, MAVLINK_TYPE_FLOAT, 3, 44, offsetof(mavlink_fmt_external_state_t, vel) }, \
         { "pos", NULL, MAVLINK_TYPE_FLOAT, 3, 56, offsetof(mavlink_fmt_external_state_t, pos) }, \
         { "lla", NULL, MAVLINK_TYPE_INT32_T, 3, 68, offsetof(mavlink_fmt_external_state_t, lla) }, \
         { "h_AGL", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_fmt_external_state_t, h_AGL) }, \
         { "flag", NULL, MAVLINK_TYPE_UINT32_T, 0, 84, offsetof(mavlink_fmt_external_state_t, flag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FMT_EXTERNAL_STATE { \
    "FMT_EXTERNAL_STATE", \
    9, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_fmt_external_state_t, timestamp) }, \
         { "quat", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_fmt_external_state_t, quat) }, \
         { "rot", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_fmt_external_state_t, rot) }, \
         { "acc", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_fmt_external_state_t, acc) }, \
         { "vel", NULL, MAVLINK_TYPE_FLOAT, 3, 44, offsetof(mavlink_fmt_external_state_t, vel) }, \
         { "pos", NULL, MAVLINK_TYPE_FLOAT, 3, 56, offsetof(mavlink_fmt_external_state_t, pos) }, \
         { "lla", NULL, MAVLINK_TYPE_INT32_T, 3, 68, offsetof(mavlink_fmt_external_state_t, lla) }, \
         { "h_AGL", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_fmt_external_state_t, h_AGL) }, \
         { "flag", NULL, MAVLINK_TYPE_UINT32_T, 0, 84, offsetof(mavlink_fmt_external_state_t, flag) }, \
         } \
}
#endif

/**
 * @brief Pack a fmt_external_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp [ms] Timestamp
 * @param quat  Vehicle quaternion
 * @param rot [rad/s] Vehicle rotation speed in body frame
 * @param acc [m/s^2] Vehicle accleration in earth frame
 * @param vel [m/s] Vehicle velocity in earth frame
 * @param pos [m] Vehicle position in earth frame
 * @param lla [degE7/degE7/mm] Vehicle WGS84 global position
 * @param h_AGL [m] Height above ground
 * @param flag  External states flag
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fmt_external_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t timestamp, const float *quat, const float *rot, const float *acc, const float *vel, const float *pos, const int32_t *lla, float h_AGL, uint32_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN];
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_float(buf, 80, h_AGL);
    _mav_put_uint32_t(buf, 84, flag);
    _mav_put_float_array(buf, 4, quat, 4);
    _mav_put_float_array(buf, 20, rot, 3);
    _mav_put_float_array(buf, 32, acc, 3);
    _mav_put_float_array(buf, 44, vel, 3);
    _mav_put_float_array(buf, 56, pos, 3);
    _mav_put_int32_t_array(buf, 68, lla, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN);
#else
    mavlink_fmt_external_state_t packet;
    packet.timestamp = timestamp;
    packet.h_AGL = h_AGL;
    packet.flag = flag;
    mav_array_memcpy(packet.quat, quat, sizeof(float)*4);
    mav_array_memcpy(packet.rot, rot, sizeof(float)*3);
    mav_array_memcpy(packet.acc, acc, sizeof(float)*3);
    mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
    mav_array_memcpy(packet.pos, pos, sizeof(float)*3);
    mav_array_memcpy(packet.lla, lla, sizeof(int32_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FMT_EXTERNAL_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_CRC);
}

/**
 * @brief Pack a fmt_external_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp [ms] Timestamp
 * @param quat  Vehicle quaternion
 * @param rot [rad/s] Vehicle rotation speed in body frame
 * @param acc [m/s^2] Vehicle accleration in earth frame
 * @param vel [m/s] Vehicle velocity in earth frame
 * @param pos [m] Vehicle position in earth frame
 * @param lla [degE7/degE7/mm] Vehicle WGS84 global position
 * @param h_AGL [m] Height above ground
 * @param flag  External states flag
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fmt_external_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t timestamp,const float *quat,const float *rot,const float *acc,const float *vel,const float *pos,const int32_t *lla,float h_AGL,uint32_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN];
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_float(buf, 80, h_AGL);
    _mav_put_uint32_t(buf, 84, flag);
    _mav_put_float_array(buf, 4, quat, 4);
    _mav_put_float_array(buf, 20, rot, 3);
    _mav_put_float_array(buf, 32, acc, 3);
    _mav_put_float_array(buf, 44, vel, 3);
    _mav_put_float_array(buf, 56, pos, 3);
    _mav_put_int32_t_array(buf, 68, lla, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN);
#else
    mavlink_fmt_external_state_t packet;
    packet.timestamp = timestamp;
    packet.h_AGL = h_AGL;
    packet.flag = flag;
    mav_array_memcpy(packet.quat, quat, sizeof(float)*4);
    mav_array_memcpy(packet.rot, rot, sizeof(float)*3);
    mav_array_memcpy(packet.acc, acc, sizeof(float)*3);
    mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
    mav_array_memcpy(packet.pos, pos, sizeof(float)*3);
    mav_array_memcpy(packet.lla, lla, sizeof(int32_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FMT_EXTERNAL_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_CRC);
}

/**
 * @brief Encode a fmt_external_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param fmt_external_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fmt_external_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_fmt_external_state_t* fmt_external_state)
{
    return mavlink_msg_fmt_external_state_pack(system_id, component_id, msg, fmt_external_state->timestamp, fmt_external_state->quat, fmt_external_state->rot, fmt_external_state->acc, fmt_external_state->vel, fmt_external_state->pos, fmt_external_state->lla, fmt_external_state->h_AGL, fmt_external_state->flag);
}

/**
 * @brief Encode a fmt_external_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fmt_external_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fmt_external_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_fmt_external_state_t* fmt_external_state)
{
    return mavlink_msg_fmt_external_state_pack_chan(system_id, component_id, chan, msg, fmt_external_state->timestamp, fmt_external_state->quat, fmt_external_state->rot, fmt_external_state->acc, fmt_external_state->vel, fmt_external_state->pos, fmt_external_state->lla, fmt_external_state->h_AGL, fmt_external_state->flag);
}

/**
 * @brief Send a fmt_external_state message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp [ms] Timestamp
 * @param quat  Vehicle quaternion
 * @param rot [rad/s] Vehicle rotation speed in body frame
 * @param acc [m/s^2] Vehicle accleration in earth frame
 * @param vel [m/s] Vehicle velocity in earth frame
 * @param pos [m] Vehicle position in earth frame
 * @param lla [degE7/degE7/mm] Vehicle WGS84 global position
 * @param h_AGL [m] Height above ground
 * @param flag  External states flag
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fmt_external_state_send(mavlink_channel_t chan, uint32_t timestamp, const float *quat, const float *rot, const float *acc, const float *vel, const float *pos, const int32_t *lla, float h_AGL, uint32_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN];
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_float(buf, 80, h_AGL);
    _mav_put_uint32_t(buf, 84, flag);
    _mav_put_float_array(buf, 4, quat, 4);
    _mav_put_float_array(buf, 20, rot, 3);
    _mav_put_float_array(buf, 32, acc, 3);
    _mav_put_float_array(buf, 44, vel, 3);
    _mav_put_float_array(buf, 56, pos, 3);
    _mav_put_int32_t_array(buf, 68, lla, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE, buf, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_CRC);
#else
    mavlink_fmt_external_state_t packet;
    packet.timestamp = timestamp;
    packet.h_AGL = h_AGL;
    packet.flag = flag;
    mav_array_memcpy(packet.quat, quat, sizeof(float)*4);
    mav_array_memcpy(packet.rot, rot, sizeof(float)*3);
    mav_array_memcpy(packet.acc, acc, sizeof(float)*3);
    mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
    mav_array_memcpy(packet.pos, pos, sizeof(float)*3);
    mav_array_memcpy(packet.lla, lla, sizeof(int32_t)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE, (const char *)&packet, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_CRC);
#endif
}

/**
 * @brief Send a fmt_external_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_fmt_external_state_send_struct(mavlink_channel_t chan, const mavlink_fmt_external_state_t* fmt_external_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fmt_external_state_send(chan, fmt_external_state->timestamp, fmt_external_state->quat, fmt_external_state->rot, fmt_external_state->acc, fmt_external_state->vel, fmt_external_state->pos, fmt_external_state->lla, fmt_external_state->h_AGL, fmt_external_state->flag);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE, (const char *)fmt_external_state, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_fmt_external_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t timestamp, const float *quat, const float *rot, const float *acc, const float *vel, const float *pos, const int32_t *lla, float h_AGL, uint32_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp);
    _mav_put_float(buf, 80, h_AGL);
    _mav_put_uint32_t(buf, 84, flag);
    _mav_put_float_array(buf, 4, quat, 4);
    _mav_put_float_array(buf, 20, rot, 3);
    _mav_put_float_array(buf, 32, acc, 3);
    _mav_put_float_array(buf, 44, vel, 3);
    _mav_put_float_array(buf, 56, pos, 3);
    _mav_put_int32_t_array(buf, 68, lla, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE, buf, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_CRC);
#else
    mavlink_fmt_external_state_t *packet = (mavlink_fmt_external_state_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->h_AGL = h_AGL;
    packet->flag = flag;
    mav_array_memcpy(packet->quat, quat, sizeof(float)*4);
    mav_array_memcpy(packet->rot, rot, sizeof(float)*3);
    mav_array_memcpy(packet->acc, acc, sizeof(float)*3);
    mav_array_memcpy(packet->vel, vel, sizeof(float)*3);
    mav_array_memcpy(packet->pos, pos, sizeof(float)*3);
    mav_array_memcpy(packet->lla, lla, sizeof(int32_t)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE, (const char *)packet, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE FMT_EXTERNAL_STATE UNPACKING


/**
 * @brief Get field timestamp from fmt_external_state message
 *
 * @return [ms] Timestamp
 */
static inline uint32_t mavlink_msg_fmt_external_state_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field quat from fmt_external_state message
 *
 * @return  Vehicle quaternion
 */
static inline uint16_t mavlink_msg_fmt_external_state_get_quat(const mavlink_message_t* msg, float *quat)
{
    return _MAV_RETURN_float_array(msg, quat, 4,  4);
}

/**
 * @brief Get field rot from fmt_external_state message
 *
 * @return [rad/s] Vehicle rotation speed in body frame
 */
static inline uint16_t mavlink_msg_fmt_external_state_get_rot(const mavlink_message_t* msg, float *rot)
{
    return _MAV_RETURN_float_array(msg, rot, 3,  20);
}

/**
 * @brief Get field acc from fmt_external_state message
 *
 * @return [m/s^2] Vehicle accleration in earth frame
 */
static inline uint16_t mavlink_msg_fmt_external_state_get_acc(const mavlink_message_t* msg, float *acc)
{
    return _MAV_RETURN_float_array(msg, acc, 3,  32);
}

/**
 * @brief Get field vel from fmt_external_state message
 *
 * @return [m/s] Vehicle velocity in earth frame
 */
static inline uint16_t mavlink_msg_fmt_external_state_get_vel(const mavlink_message_t* msg, float *vel)
{
    return _MAV_RETURN_float_array(msg, vel, 3,  44);
}

/**
 * @brief Get field pos from fmt_external_state message
 *
 * @return [m] Vehicle position in earth frame
 */
static inline uint16_t mavlink_msg_fmt_external_state_get_pos(const mavlink_message_t* msg, float *pos)
{
    return _MAV_RETURN_float_array(msg, pos, 3,  56);
}

/**
 * @brief Get field lla from fmt_external_state message
 *
 * @return [degE7/degE7/mm] Vehicle WGS84 global position
 */
static inline uint16_t mavlink_msg_fmt_external_state_get_lla(const mavlink_message_t* msg, int32_t *lla)
{
    return _MAV_RETURN_int32_t_array(msg, lla, 3,  68);
}

/**
 * @brief Get field h_AGL from fmt_external_state message
 *
 * @return [m] Height above ground
 */
static inline float mavlink_msg_fmt_external_state_get_h_AGL(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field flag from fmt_external_state message
 *
 * @return  External states flag
 */
static inline uint32_t mavlink_msg_fmt_external_state_get_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  84);
}

/**
 * @brief Decode a fmt_external_state message into a struct
 *
 * @param msg The message to decode
 * @param fmt_external_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_fmt_external_state_decode(const mavlink_message_t* msg, mavlink_fmt_external_state_t* fmt_external_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    fmt_external_state->timestamp = mavlink_msg_fmt_external_state_get_timestamp(msg);
    mavlink_msg_fmt_external_state_get_quat(msg, fmt_external_state->quat);
    mavlink_msg_fmt_external_state_get_rot(msg, fmt_external_state->rot);
    mavlink_msg_fmt_external_state_get_acc(msg, fmt_external_state->acc);
    mavlink_msg_fmt_external_state_get_vel(msg, fmt_external_state->vel);
    mavlink_msg_fmt_external_state_get_pos(msg, fmt_external_state->pos);
    mavlink_msg_fmt_external_state_get_lla(msg, fmt_external_state->lla);
    fmt_external_state->h_AGL = mavlink_msg_fmt_external_state_get_h_AGL(msg);
    fmt_external_state->flag = mavlink_msg_fmt_external_state_get_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN? msg->len : MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN;
        memset(fmt_external_state, 0, MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_LEN);
    memcpy(fmt_external_state, _MAV_PAYLOAD(msg), len);
#endif
}
