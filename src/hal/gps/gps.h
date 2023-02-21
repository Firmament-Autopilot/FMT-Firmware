/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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

#ifndef GPS_H__
#define GPS_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* gps read pos */
#define GPS_READ_REPORT 0

/* gps command */
#define GPS_CMD_INIT        0x10
#define GPS_CMD_OPEN        0x11
#define GPS_CMD_CLOSE       0x12
#define GPS_CMD_CHECK_READY 0x20

typedef struct {
    uint32_t timestamp_position; /**< Timestamp for position information */
    int32_t lat;                 /**< Latitude in 1E-7 degrees */
    int32_t lon;                 /**< Longitude in 1E-7 degrees */
    int32_t alt;                 /**< Altitude in 1E-3 meters (millimeters) above MSL  */

    uint32_t timestamp_variance;
    float s_variance_m_s; /**< speed accuracy estimate m/s */
    float c_variance_rad; /**< course accuracy estimate rad */
    uint8_t fix_type;     /**< 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.   */

    float eph; /**< GPS HDOP horizontal dilution of position in m */
    float epv; /**< GPS VDOP horizontal dilution of position in m */

    uint16_t noise_per_ms;      /**< */
    uint16_t jamming_indicator; /**< */

    uint32_t timestamp_velocity; /**< Timestamp for velocity informations */
    float vel_m_s;               /**< GPS ground speed (m/s) */
    float vel_n_m_s;             /**< North velocity in m/s */
    float vel_e_m_s;             /**< East velocity in m/s */
    float vel_d_m_s;             /**< Down velocity in m/s */
    float cog_rad;               /**< Course over ground (NOT heading, but direction of movement) in rad, -PI..PI */
    uint8_t vel_ned_valid;       /**< Flag to indicate if NED speed is valid */

    uint32_t timestamp_time; /**< Timestamp for time information */
    uint32_t time_gps_usec;  /**< Timestamp (microseconds in GPS format), this is the timestamp which comes from the gps module   */

    uint8_t satellites_used; /**< Number of satellites used */
    float hdop;
    float ndop;
    float edop;
    float vdop;
    float tdop;
    uint32_t alt_ellipsoid;
} gps_report_t;

struct gps_device {
    struct rt_device parent;
    const struct gps_ops* ops;
};
typedef struct gps_device* gps_dev_t;

/* gps driver opeations */
struct gps_ops {
    /**
     * @brief gps control function (optional)
     * @param dev gps device
     * @param cmd operation command
     * @param arg command argument
    */
    rt_err_t (*gps_control)(gps_dev_t dev, int cmd, void* arg);
    /**
     * @brief gps read function
     * @param dev gps device
     * @param report gps report buffer
    */
    rt_size_t (*gps_read)(gps_dev_t dev, gps_report_t* report);
};

rt_err_t hal_gps_register(gps_dev_t gps_dev, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif /* GPS_H__ */
