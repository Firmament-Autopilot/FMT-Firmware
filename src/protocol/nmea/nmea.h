/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef NMEA_H__
#define NMEA_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NMEA_RECV_BUFFER_SIZE 1024

#define NMEA_MSG_KSXT         (1)
#define NMEA_MSG_GPGSA        (2)

/* Decoder state */
typedef enum {
    NMEA_DECODE_START = 0,
    NMEA_DECODE_PAYLOAD,
    NMEA_DECODE_CS1,
    NMEA_DECODE_CS2,
} nmea_decode_state_t;

typedef struct {
    uint16_t year;           /**< Year (UTC)*/
    uint8_t month;           /**< Month, range 1..12 (UTC) */
    uint8_t day;             /**< Day of month, range 1..31 (UTC) */
    uint8_t hour;            /**< Hour of day, range 0..23 (UTC) */
    uint8_t min;             /**< Minute of hour, range 0..59 (UTC) */
    uint8_t sec;             /**< Seconds of minute, range 0..60 (UTC) */
    int32_t lon;             /**< Longitude [1e-7 deg] */
    int32_t lat;             /**< Latitude [1e-7 deg] */
    int32_t height;          /**< Height above ellipsoid [mm] */
    float velN;              /**< NED north velocity [m/s]*/
    float velE;              /**< NED east velocity [m/s]*/
    float velD;              /**< NED down velocity [m/s]*/
    float heading;           /**< Heading [rad] */
    float gSpeed;            /**< Ground Speed (2-D) [m/s] */
    uint8_t pos_fixType;     /**< position fix type: 0 = No fix, 1 = Single fix, 2 = rtk floating, 3 = rtk fix */
    uint8_t heading_fixType; /**< heading fix type: 0 = No fix, 1 = Single fix, 2 = rtk floating, 3 = rtk fix */
    uint8_t MnumSV;          /**< Number of SVs used in master antenna  */
    uint8_t SnumSV;          /**< Number of SVs used in sub antenna  */
} nmea_payload_rx_ksxt_t;

typedef struct {
    uint8_t pdop;
    uint8_t hdop;
    uint8_t vdop;
} nmea_payload_rx_gpgsa_t;

/* General message and payload buffer union */
typedef union {
    nmea_payload_rx_ksxt_t payload_rx_ksxt;
    nmea_payload_rx_gpgsa_t payload_rx_gpgsa;
    uint8_t raw[256];
} nmea_buf_t;

typedef int (*nmea_rx_handle_ptr)(uint16_t msg_id);

typedef struct {
    rt_device_t nmea_dev;
    nmea_decode_state_t decode_state;
    nmea_buf_t buf;
    char nmea_rx_buf[NMEA_RECV_BUFFER_SIZE];
    uint16_t rx_buf_index;
    bool got_posllh;
    bool got_velned;
    bool got_svinfo;
    bool got_dop;
    nmea_rx_handle_ptr rx_handle;
} nmea_decoder_t;

fmt_err_t init_nmea_decoder(nmea_decoder_t* decoder, rt_device_t dev, nmea_rx_handle_ptr rx_handle);
int parse_nmea_sentence(nmea_decoder_t* decoder, const char* sentence);
int parse_nmea_char(nmea_decoder_t* decoder, const uint8_t c);

#ifdef __cplusplus
}
#endif

#endif
