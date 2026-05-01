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

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

extern uint8_t gps_config_complete;

static rt_device_t serial_device;
static struct gps_device gps_device;
static nmea_decoder_t nmea_decoder;
static gps_report_t gps_report;
static bool nmea_received;

static char nmea_cfg_sentences[][50] = {
    "KSXT 0.1\r\n",
    "GPGSA 0.1\r\n",
};

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
            gps_report.fix_type = 3; /* Single fix */
        } else if (nmea_decoder.buf.payload_rx_ksxt.pos_fixType == 2) {
            gps_report.fix_type = 5; /* RTK float */
        } else if (nmea_decoder.buf.payload_rx_ksxt.pos_fixType == 3) {
            gps_report.fix_type = 6; /* RTK fix */
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
        // gps_report.c_variance_rad = (3.0f - nmea_decoder.buf.payload_rx_ksxt.heading_fixType) * PI / 6.0f;
        gps_report.c_variance_rad = (nmea_decoder.buf.payload_rx_ksxt.heading_fixType == 0) ? 2 * PI : 0;

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

    nmea_received = true;

    return ret;
}

static rt_err_t set_baudrate(rt_device_t dev, uint32_t baudrate)
{
    struct serial_device* serial_dev = (struct serial_device*)dev;

    if (serial_dev->config.baud_rate != baudrate) {
        struct serial_configure pconfig = serial_dev->config;

        pconfig.baud_rate = baudrate;

        return rt_device_control(dev, RT_DEVICE_CTRL_CONFIG, &pconfig);
    }

    return RT_EOK;
}

static void gps_probe_entry(void* parameter)
{
    uint32_t baudrate;
    gnss_device_info* dev_info = (gnss_device_info*)parameter;
    gnss_serial_dev_config* dev_config = (gnss_serial_dev_config*)dev_info->config;

    nmea_received = false;
    baudrate = dev_config->baudrate;

    if (dev_info->auto_config == true) {
        if (baudrate == 0) {
            /* baudrate auto detect */
            uint32_t baudrates[] = { 9600, 19200, 38400, 57600, 115200, 230400, 460800 };
            uint8_t i;

            for (i = 0; i < sizeof(baudrates) / sizeof(baudrates[0]); i++) {
                baudrate = baudrates[i];

                if (set_baudrate(nmea_decoder.nmea_dev, baudrate) == RT_EOK) {
                    DRV_DBG("gps barud rate -> %lu\n", baudrate);
                } else {
                    DRV_DBG("gps barud rate -> %lu fail\n", baudrate);
                    return;
                }

                /* we send first config for testing */
                rt_device_write(nmea_decoder.nmea_dev, RT_WAITING_FOREVER, nmea_cfg_sentences[0], strlen(nmea_cfg_sentences[0]));

                uint32_t time_now = systime_now_ms();
                while ((systime_now_ms() - time_now) < 500) {
                    if (nmea_received) {
                        DRV_DBG("NMEA GPS detected on %s, with baudrate of %ld.\n", nmea_decoder.nmea_dev->parent.name, baudrate);
                        break;
                    }
                    systime_msleep(10);
                }

                if (nmea_received) {
                    break;
                }
            }

            if (i >= sizeof(baudrates) / sizeof(baudrates[0])) {
                DRV_DBG("gps connection and/or baudrate detection failed\r\n");
                return;
            }
        } else {
            if (set_baudrate(nmea_decoder.nmea_dev, baudrate) == RT_EOK) {
                DRV_DBG("gps barud rate -> %lu\n", baudrate);
            } else {
                DRV_DBG("gps barud rate -> %lu fail\n", baudrate);
                return;
            }

            /* we send first config for testing */
            rt_device_write(nmea_decoder.nmea_dev, RT_WAITING_FOREVER, nmea_cfg_sentences[0], strlen(nmea_cfg_sentences[0]));

            uint32_t time_now = systime_now_ms();
            while ((systime_now_ms() - time_now) < 500) {
                if (nmea_received) {
                    DRV_DBG("NMEA GPS detected on %s, with baudrate of %ld.\n", nmea_decoder.nmea_dev->parent.name, baudrate);
                    break;
                }
                systime_msleep(10);
            }

            if (!nmea_received) {
                return;
            }
        }

        /* now send config to nmea gnss */
        for (uint8_t i = 0; i < sizeof(nmea_cfg_sentences) / sizeof(nmea_cfg_sentences[0]); i++) {
            rt_device_write(nmea_decoder.nmea_dev, RT_WAITING_FOREVER, nmea_cfg_sentences[i], strlen(nmea_cfg_sentences[i]));
            systime_msleep(10);
        }
    } else {
        if (baudrate > 0) {
            if (set_baudrate(nmea_decoder.nmea_dev, baudrate) != RT_EOK) {
                DRV_DBG("NMEA-GPS baudrate set failed\n");
            }
        }

        DRV_DBG("NMEA-GPS config skipped.\n");
    }

    /* GPS is dected, now register */
    hal_gps_register(&gps_device, "gps", RT_DEVICE_FLAG_RDWR, RT_NULL);
    register_sensor_gps("gps");

    gps_config_complete = 1;
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

rt_err_t gps_nmea_init(gnss_device_info* dev_info)
{
    gps_device.ops = &gps_ops;

    serial_device = rt_device_find(dev_info->name);
    RT_ASSERT(serial_device != NULL);

    /* set gps rx indicator */
    RT_CHECK(rt_device_set_rx_indicate(serial_device, gps_serial_rx_ind));
    /* open serial device */
    RT_CHECK(rt_device_open(serial_device, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX));
    /* init ublox decoder */
    FMT_CHECK(init_nmea_decoder(&nmea_decoder, serial_device, nmea_rx_handle));

    /* create a thread to probe the gps connection */
    rt_thread_t tid = rt_thread_create("gps_probe", gps_probe_entry, dev_info, 4096, RT_THREAD_PRIORITY_MAX - 2, 5);
    RT_ASSERT(tid != NULL);

    RT_CHECK(rt_thread_startup(tid));

    return RT_EOK;
}