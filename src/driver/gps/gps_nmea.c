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
#include <firmament.h>

#include "driver/gps/gps_nmea.h"
#include "hal/gps/gps.h"
#include "hal/serial/serial.h"
#include "module/sensor/sensor_hub.h"
#include "protocol/nmea/nmea.h"

static rt_device_t serial_device;
static struct gps_device gps_device;
static nmea_decoder_t nmea_decoder;
static gps_report_t gps_report;

static rt_err_t gps_serial_rx_ind(rt_device_t dev, rt_size_t size)
{
    uint8_t ch;

    while (rt_device_read(serial_device, 0, &ch, 1)) {
        parse_nmea_char(&nmea_decoder, ch);
    }

    return RT_EOK;
}

static int nmea_rx_handle(uint16_t msg_id)
{
    int ret = 0;

    switch (msg_id) {
    case NMEA_MSG_KSXT: {
        gps_report.vel_ned_valid = 1;
        if (nmea_decoder.buf.payload_rx_ksxt.pos_fixType == 1) {
            gps_report.fix_type = 3; /* 3D fix */
        } else if (nmea_decoder.buf.payload_rx_ksxt.pos_fixType == 2) {
            gps_report.fix_type = 6; /* RTK fix */
        } else if (nmea_decoder.buf.payload_rx_ksxt.pos_fixType == 3) {
            gps_report.fix_type = 5; /* RTK float */
        } else {
            gps_report.fix_type = 0; /* No fix */
            gps_report.vel_ned_valid = 0;
        }

        gps_report.satellites_used = nmea_decoder.buf.payload_rx_ksxt.MnumSV;
        gps_report.lat = nmea_decoder.buf.payload_rx_ksxt.lat;
        gps_report.lon = nmea_decoder.buf.payload_rx_ksxt.lon;
        gps_report.alt = nmea_decoder.buf.payload_rx_ksxt.height;
        gps_report.vel_m_s = nmea_decoder.buf.payload_rx_ksxt.gSpeed;
        gps_report.vel_n_m_s = nmea_decoder.buf.payload_rx_ksxt.velN;
        gps_report.vel_e_m_s = nmea_decoder.buf.payload_rx_ksxt.velE;
        gps_report.vel_d_m_s = nmea_decoder.buf.payload_rx_ksxt.velD;

        gps_report.heading_rad = nmea_decoder.buf.payload_rx_ksxt.heading;
        gps_report.cog_rad = nmea_decoder.buf.payload_rx_ksxt.track;
        gps_report.c_variance_rad = (3.0f - nmea_decoder.buf.payload_rx_ksxt.heading_fixType) * PI / 6.0f;

        gps_report.timestamp_time = systime_now_ms();
        gps_report.timestamp_velocity = systime_now_ms();
        gps_report.timestamp_position = systime_now_ms();

        nmea_decoder.got_posllh = true;
        nmea_decoder.got_velned = true;
        nmea_decoder.got_svinfo = true;

    } break;
    case NMEA_MSG_GPGSA: {
        gps_report.eph = nmea_decoder.buf.payload_rx_gpgsa.hdop;
        gps_report.epv = nmea_decoder.buf.payload_rx_gpgsa.vdop;
        gps_report.s_variance_m_s = nmea_decoder.buf.payload_rx_gpgsa.hdop / 5;

        gps_report.timestamp_variance = systime_now_ms();

        nmea_decoder.got_dop = true;
    } break;
    default:
        ret = -1;
        break;
    }

    return ret;
}

static void gps_probe_entry(void* parameter)
{
    // uint32_t baudrate;
    // uint8_t i;

    // for (i = 0; i < CONFIGURE_RETRY_MAX; i++) {
    //     if (probe(&baudrate) == RT_EOK) {
    //         if (configure_by_ubx(baudrate) == RT_EOK) {
    //             /* GPS is dected, now register */
    //             hal_gps_register(&gps_device, "gps", RT_DEVICE_FLAG_RDWR, RT_NULL);
    //             register_sensor_gps((char*)parameter);
    //             break;
    //         }
    //     }
    // }

    // if (i >= CONFIGURE_RETRY_MAX) {
    //     printf("GPS configuration fail! Please check if GPS module has connected.");
    // }

    /* GPS is dected, now register */
    hal_gps_register(&gps_device, "gps", RT_DEVICE_FLAG_RDWR, RT_NULL);
    register_sensor_gps((char*)parameter);

    rt_free(parameter);
}

static rt_err_t gps_control(gps_dev_t gps_dev, int cmd, void* arg)
{
    switch (cmd) {
    case GPS_CMD_CHECK_READY:
        if (arg == NULL) {
            return RT_ERROR;
        }
        if (nmea_decoder.got_posllh && nmea_decoder.got_velned && nmea_decoder.got_svinfo && nmea_decoder.got_dop) {
            *(uint8_t*)arg = 1;
        } else {
            *(uint8_t*)arg = 0;
        }
        return RT_EOK;

        break;

    case GPS_CMD_INIT:
    case GPS_CMD_OPEN:
    case GPS_CMD_CLOSE:
        return RT_EOK;

        break;
    }

    return RT_EINVAL;
}

static rt_size_t gps_read(gps_dev_t gps_dev, gps_report_t* report)
{
    if (nmea_decoder.got_posllh && nmea_decoder.got_velned && nmea_decoder.got_svinfo && nmea_decoder.got_dop) {

        OS_ENTER_CRITICAL;
        *report = gps_report;
        nmea_decoder.got_posllh = false;
        nmea_decoder.got_velned = false;
        nmea_decoder.got_svinfo = false;
        nmea_decoder.got_dop = false;
        OS_EXIT_CRITICAL;

        return sizeof(gps_report_t);
    }

    return 0;
}

static struct gps_ops gps_ops = {
    .gps_control = gps_control,
    .gps_read = gps_read
};

rt_err_t gps_nmea_init(const char* serial_dev_name, const char* gps_dev_name)
{
    char* str_buffer;

    gps_device.ops = &gps_ops;

    str_buffer = (char*)rt_malloc(21);
    RT_ASSERT(str_buffer != NULL);
    memset(str_buffer, 0, 21);
    strncpy(str_buffer, gps_dev_name, 20);

    serial_device = rt_device_find(serial_dev_name);
    RT_ASSERT(serial_device != NULL);

    /* set gps rx indicator */
    RT_CHECK(rt_device_set_rx_indicate(serial_device, gps_serial_rx_ind));
    /* open serial device */
    RT_CHECK(rt_device_open(serial_device, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX));
    /* init ublox decoder */
    FMT_CHECK(init_nmea_decoder(&nmea_decoder, serial_device, nmea_rx_handle));

    /* create a thread to probe the gps connection */
    rt_thread_t tid = rt_thread_create("gps_probe", gps_probe_entry, str_buffer, 4096, RT_THREAD_PRIORITY_MAX - 2, 5);
    RT_ASSERT(tid != NULL);

    RT_CHECK(rt_thread_startup(tid));

    return RT_EOK;
}