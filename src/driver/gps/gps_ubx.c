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
#include <firmament.h>

#include "driver/gps/gps_ubx.h"
#include "hal/gps/gps.h"
#include "hal/serial/serial.h"
#include "module/sensor/sensor_hub.h"
#include "protocol/ublox/ublox.h"

#define CONFIGURE_RETRY_MAX 5
#define M_DEG_TO_RAD_F      0.01745329251994f
#define M_RAD_TO_DEG_F      57.2957795130823f

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

static rt_device_t       serial_device;
static struct gps_device gps_device;
static ubx_decoder_t     ubx_decoder;
static gps_report_t      gps_report;

static rt_err_t gps_serial_rx_ind(rt_device_t dev, rt_size_t size)
{
    uint8_t ch;

    while (rt_device_read(serial_device, 0, &ch, 1)) {
        parse_ubx_char(&ubx_decoder, ch);
    }

    return RT_EOK;
}

static int ubx_rx_handle(void)
{
    int ret = 0;

    // return if no message handled
    if (ubx_decoder.rx_state != UBX_RXMSG_HANDLE) {
        return ret;
    }

    // handle message
    switch (ubx_decoder.rx_msg) {
    case UBX_MSG_NAV_PVT: {
        // struct gps_tm timeinfo;

        if ((ubx_decoder.buf.payload_rx_nav_pvt.flags & UBX_RX_NAV_PVT_FLAGS_GNSSFIXOK) == 1) {
            gps_report.fix_type      = ubx_decoder.buf.payload_rx_nav_pvt.fixType;
            gps_report.vel_ned_valid = 1;

        } else {
            gps_report.fix_type      = 0;
            gps_report.vel_ned_valid = 0;
        }

        gps_report.satellites_used = ubx_decoder.buf.payload_rx_nav_pvt.numSV;

        gps_report.lat = ubx_decoder.buf.payload_rx_nav_pvt.lat;
        gps_report.lon = ubx_decoder.buf.payload_rx_nav_pvt.lon;
        gps_report.alt = ubx_decoder.buf.payload_rx_nav_pvt.hMSL;

        gps_report.eph            = (float)ubx_decoder.buf.payload_rx_nav_pvt.hAcc * 1e-3f;
        gps_report.epv            = (float)ubx_decoder.buf.payload_rx_nav_pvt.vAcc * 1e-3f;
        gps_report.s_variance_m_s = (float)ubx_decoder.buf.payload_rx_nav_pvt.sAcc * 1e-3f;

        gps_report.vel_m_s = (float)ubx_decoder.buf.payload_rx_nav_pvt.gSpeed * 1e-3f;

        gps_report.vel_n_m_s = (float)ubx_decoder.buf.payload_rx_nav_pvt.velN * 1e-3f;
        gps_report.vel_e_m_s = (float)ubx_decoder.buf.payload_rx_nav_pvt.velE * 1e-3f;
        gps_report.vel_d_m_s = (float)ubx_decoder.buf.payload_rx_nav_pvt.velD * 1e-3f;

        gps_report.cog_rad        = (float)ubx_decoder.buf.payload_rx_nav_pvt.headMot * M_DEG_TO_RAD_F * 1e-5f;
        gps_report.c_variance_rad = (float)ubx_decoder.buf.payload_rx_nav_pvt.headAcc * M_DEG_TO_RAD_F * 1e-5f;

        // Check if time and date fix flags are good
        if ((ubx_decoder.buf.payload_rx_nav_pvt.valid & UBX_RX_NAV_PVT_VALID_VALIDDATE)
            && (ubx_decoder.buf.payload_rx_nav_pvt.valid & UBX_RX_NAV_PVT_VALID_VALIDTIME)
            && (ubx_decoder.buf.payload_rx_nav_pvt.valid & UBX_RX_NAV_PVT_VALID_FULLYRESOLVED)) {
            /* convert to unix timestamp */
            // timeinfo.tm_year	= ubx_decoder.buf.payload_rx_nav_pvt.year - 1900;
            // timeinfo.tm_mon		= ubx_decoder.buf.payload_rx_nav_pvt.month - 1;
            // timeinfo.tm_mday	= ubx_decoder.buf.payload_rx_nav_pvt.day;
            // timeinfo.tm_hour	= ubx_decoder.buf.payload_rx_nav_pvt.hour;
            // timeinfo.tm_min		= ubx_decoder.buf.payload_rx_nav_pvt.min;
            // timeinfo.tm_sec		= ubx_decoder.buf.payload_rx_nav_pvt.sec;

            // gps_report.time_utc_usec = 0;
        }

        gps_report.timestamp_time     = systime_now_ms();
        gps_report.timestamp_velocity = systime_now_ms();
        gps_report.timestamp_variance = systime_now_ms();
        gps_report.timestamp_position = systime_now_ms();

        ubx_decoder.got_posllh = true;
        ubx_decoder.got_velned = true;

        ret = 1;
    } break;

    case UBX_MSG_NAV_POSLLH: {
        // console_printf("Rx NAV-POSLLH\r\n");

        gps_report.lat           = ubx_decoder.buf.payload_rx_nav_posllh.lat;
        gps_report.lon           = ubx_decoder.buf.payload_rx_nav_posllh.lon;
        gps_report.alt           = ubx_decoder.buf.payload_rx_nav_posllh.hMSL;
        gps_report.eph           = (float)ubx_decoder.buf.payload_rx_nav_posllh.hAcc * 1e-3f; // from mm to m
        gps_report.epv           = (float)ubx_decoder.buf.payload_rx_nav_posllh.vAcc * 1e-3f; // from mm to m
        gps_report.alt_ellipsoid = ubx_decoder.buf.payload_rx_nav_posllh.height;

        gps_report.timestamp_position = systime_now_ms();

        ubx_decoder.got_posllh = true;

        // console_printf("alt:%d lat:%d lon:%d\r\n" , gps_report.alt, gps_report.lat,gps_report.lon);

        ret = 1;
    } break;

    case UBX_MSG_NAV_SOL: {
        // console_printf("Rx NAV-SOL\r\n");

        gps_report.fix_type        = ubx_decoder.buf.payload_rx_nav_sol.gpsFix;
        gps_report.s_variance_m_s  = (float)ubx_decoder.buf.payload_rx_nav_sol.sAcc * 1e-2f; // from cm to m
        gps_report.satellites_used = ubx_decoder.buf.payload_rx_nav_sol.numSV;

        gps_report.timestamp_variance = systime_now_ms();
    } break;

    case UBX_MSG_NAV_DOP: {
        // console_printf("Rx NAV-DOP\r\n");

        gps_report.hdop = ubx_decoder.buf.payload_rx_nav_dop.hDOP * 0.01f; // from cm to m
        gps_report.vdop = ubx_decoder.buf.payload_rx_nav_dop.vDOP * 0.01f; // from cm to m
        gps_report.tdop = ubx_decoder.buf.payload_rx_nav_dop.tDOP * 0.01f; // from cm to m
        gps_report.ndop = ubx_decoder.buf.payload_rx_nav_dop.nDOP * 0.01f; // from cm to m
        gps_report.edop = ubx_decoder.buf.payload_rx_nav_dop.eDOP * 0.01f; // from cm to m

        gps_report.timestamp_variance = systime_now_ms();

        ret = 1;
    } break;

    case UBX_MSG_NAV_TIMEUTC: {
        // console_printf("Rx NAV-TIMEUTC\r\n");

        // if (ubx_decoder.buf.payload_rx_nav_timeutc.valid & UBX_RX_NAV_TIMEUTC_VALID_VALIDUTC) {
        //     convert to unix timestamp
        //     struct gps_tm timeinfo;
        //     timeinfo.tm_year	= ubx_decoder.buf.payload_rx_nav_timeutc.year - 1900;
        //     timeinfo.tm_mon		= ubx_decoder.buf.payload_rx_nav_timeutc.month - 1;
        //     timeinfo.tm_mday	= ubx_decoder.buf.payload_rx_nav_timeutc.day;
        //     timeinfo.tm_hour	= ubx_decoder.buf.payload_rx_nav_timeutc.hour;
        //     timeinfo.tm_min		= ubx_decoder.buf.payload_rx_nav_timeutc.min;
        //     timeinfo.tm_sec		= ubx_decoder.buf.payload_rx_nav_timeutc.sec;

        //     gps_report.time_utc_usec = 0;
        //     console_printf("%d-%d-%d %d:%d:%d\r\n" , timeinfo.tm_year,timeinfo.tm_mon,timeinfo.tm_mday,timeinfo.tm_hour,timeinfo.tm_min,timeinfo.tm_sec);
        // }

        // gps_report.timestamp_time = systime_now_ms();

        ret = 1;
    } break;

    case UBX_MSG_NAV_SVINFO: {
        // console_printf("Rx NAV-SVINFO\r\n");
        //  _satellite_info already populated by payload_rx_add_svinfo(), just add a timestamp
        ubx_decoder.satellite_info.timestamp = systime_now_us();

        ubx_decoder.got_svinfo = true;

        ret = 2;
    } break;

    case UBX_MSG_NAV_VELNED: {
        gps_report.vel_m_s        = (float)ubx_decoder.buf.payload_rx_nav_velned.speed * 1e-2f;
        gps_report.vel_n_m_s      = (float)ubx_decoder.buf.payload_rx_nav_velned.velN * 1e-2f; /* NED NORTH velocity */
        gps_report.vel_e_m_s      = (float)ubx_decoder.buf.payload_rx_nav_velned.velE * 1e-2f; /* NED EAST velocity */
        gps_report.vel_d_m_s      = (float)ubx_decoder.buf.payload_rx_nav_velned.velD * 1e-2f; /* NED DOWN velocity */
        gps_report.cog_rad        = (float)ubx_decoder.buf.payload_rx_nav_velned.heading * M_DEG_TO_RAD_F * 1e-5f;
        gps_report.c_variance_rad = (float)ubx_decoder.buf.payload_rx_nav_velned.cAcc * M_DEG_TO_RAD_F * 1e-5f;
        gps_report.vel_ned_valid  = 1;

        gps_report.timestamp_velocity = systime_now_ms();

        ubx_decoder.got_velned = true;

        // console_printf("nV:%.2f eV:%.2f dV:%.2f" , gps_report.vel_n_m_s,gps_report.vel_e_m_s,gps_report.vel_d_m_s);

        ret = 1;
    } break;

    case UBX_MSG_MON_VER: {
        // console_printf("Rx MON-VER\r\n");
    } break;

    case UBX_MSG_MON_HW: {
        // console_printf("Rx MON-HW\r\n");

        switch (ubx_decoder.rx_payload_length) {
        case sizeof(ubx_payload_rx_mon_hw_ubx6_t): /* u-blox 6 msg format */
            gps_report.noise_per_ms      = ubx_decoder.buf.payload_rx_mon_hw_ubx6.noisePerMS;
            gps_report.jamming_indicator = ubx_decoder.buf.payload_rx_mon_hw_ubx6.jamInd;

            ret = 1;
            break;

        case sizeof(ubx_payload_rx_mon_hw_ubx7_t): /* u-blox 7+ msg format */
            gps_report.noise_per_ms      = ubx_decoder.buf.payload_rx_mon_hw_ubx7.noisePerMS;
            gps_report.jamming_indicator = ubx_decoder.buf.payload_rx_mon_hw_ubx7.jamInd;

            ret = 1;
            break;

        default:     // unexpected payload size:
            ret = 0; // don't handle message
            break;
        }
    } break;

    case UBX_MSG_ACK_ACK: {
        // DRV_DBG("Rx ACK-ACK\r\n");

        if ((ubx_decoder.ack_state == UBX_ACK_WAITING) && (ubx_decoder.buf.payload_rx_ack_ack.msg == ubx_decoder.ack_waiting_msg)) {
            ubx_decoder.ack_state = UBX_ACK_GOT_ACK;
        }

        ret = 1;
    } break;

    case UBX_MSG_ACK_NAK: {
        // DRV_DBG("Rx ACK-NAK\r\n");

        if ((ubx_decoder.ack_state == UBX_ACK_WAITING) && (ubx_decoder.buf.payload_rx_ack_ack.msg == ubx_decoder.ack_waiting_msg)) {
            ubx_decoder.ack_state = UBX_ACK_GOT_NAK;
        }

        ret = 1;
    } break;

    default:
        break;
    }

    return ret;
}

// -1 = NAK, error or timeout, 0 = ACK
static int wait_for_ack(const uint16_t msg, const uint32_t timeout)
{
    int ret = -1;

    ubx_decoder.ack_state       = UBX_ACK_WAITING;
    ubx_decoder.ack_waiting_msg = msg; // memorize sent msg class&ID for ACK check

    uint32_t time_started = systime_now_ms();

    while ((ubx_decoder.ack_state == UBX_ACK_WAITING) && (systime_now_ms() < time_started + timeout)) {
        ;
    }

    if (ubx_decoder.ack_state == UBX_ACK_GOT_ACK) {
        ret = 0; // ACK received ok
    }

    ubx_decoder.ack_state = UBX_ACK_IDLE;
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

static rt_err_t probe(uint32_t* gps_baudrate)
{
    uint32_t baudrates[] = { 9600, 19200, 38400, 57600, 115200, 230400, 460800 };
    uint32_t baudrate;
    uint8_t  i;

    for (i = 0; i < sizeof(baudrates) / sizeof(baudrates[0]); i++) {
        baudrate = baudrates[i];

        if (set_baudrate(ubx_decoder.ubx_dev, baudrate) == RT_EOK) {
            DRV_DBG("gps barud rate -> %d\n", baudrate);
        } else {
            DRV_DBG("gps barud rate -> %d fail\n", baudrate);
        }

        /* flush input and wait for at least 20 ms silence */
        reset_ubx_decoder(&ubx_decoder);
        sys_msleep(20);
        reset_ubx_decoder(&ubx_decoder);

        /* Send a CFG-PRT message to set the UBX protocol for in and out
         * and leave the baudrate as it is, we just want an ACK-ACK for this */
        memset(&ubx_decoder.buf.payload_tx_cfg_prt, 0, sizeof(ubx_decoder.buf.payload_tx_cfg_prt));
        ubx_decoder.buf.payload_tx_cfg_prt.portID       = UBX_TX_CFG_PRT_PORTID;
        ubx_decoder.buf.payload_tx_cfg_prt.mode         = UBX_TX_CFG_PRT_MODE;
        ubx_decoder.buf.payload_tx_cfg_prt.baudRate     = baudrate;
        ubx_decoder.buf.payload_tx_cfg_prt.inProtoMask  = UBX_TX_CFG_PRT_INPROTOMASK;
        ubx_decoder.buf.payload_tx_cfg_prt.outProtoMask = UBX_TX_CFG_PRT_OUTPROTOMASK;

        send_ubx_msg(&ubx_decoder, UBX_MSG_CFG_PRT, ubx_decoder.buf.raw, sizeof(ubx_decoder.buf.payload_tx_cfg_prt));

        if (wait_for_ack(UBX_MSG_CFG_PRT, 2 * UBX_CONFIG_TIMEOUT) < 0) {
            /* try next baudrate */
            continue;
        }

        /* at this point we have correct baudrate on both ends */
        *gps_baudrate = baudrate;
        break;
    }

    if (i >= sizeof(baudrates) / sizeof(baudrates[0])) {
        DRV_DBG("gps connection and/or baudrate detection failed\r\n");
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t configure_by_ubx(uint32_t baudrate)
{
    /* Send a CFG-PRT message again, this time change the baudrate */
    memset(&ubx_decoder.buf.payload_tx_cfg_prt, 0, sizeof(ubx_decoder.buf.payload_tx_cfg_prt));
    ubx_decoder.buf.payload_tx_cfg_prt.portID       = UBX_TX_CFG_PRT_PORTID;
    ubx_decoder.buf.payload_tx_cfg_prt.mode         = UBX_TX_CFG_PRT_MODE;
    ubx_decoder.buf.payload_tx_cfg_prt.baudRate     = UBX_TX_CFG_PRT_BAUDRATE;
    ubx_decoder.buf.payload_tx_cfg_prt.inProtoMask  = UBX_TX_CFG_PRT_INPROTOMASK;
    ubx_decoder.buf.payload_tx_cfg_prt.outProtoMask = UBX_TX_CFG_PRT_OUTPROTOMASK;

    send_ubx_msg(&ubx_decoder, UBX_MSG_CFG_PRT, ubx_decoder.buf.raw, sizeof(ubx_decoder.buf.payload_tx_cfg_prt));

    /* no ACK is expected here, but read the buffer anyway in case we actually get an ACK */
    wait_for_ack(UBX_MSG_CFG_PRT, UBX_CONFIG_TIMEOUT);

    if (UBX_TX_CFG_PRT_BAUDRATE != baudrate) {
        if (set_baudrate(ubx_decoder.ubx_dev, UBX_TX_CFG_PRT_BAUDRATE) == RT_EOK) {
            DRV_DBG("change gps baudrate from %d to %d\n", baudrate, UBX_TX_CFG_PRT_BAUDRATE);
            baudrate = UBX_TX_CFG_PRT_BAUDRATE;

            reset_ubx_decoder(&ubx_decoder);
            systime_mdelay(20);
            reset_ubx_decoder(&ubx_decoder);
        } else {
            DRV_DBG("fail to change gps baudrate from %d to %d\n", baudrate, UBX_TX_CFG_PRT_BAUDRATE);
        }
    }

    /* Send a CFG-RATE message to define update rate */
    memset(&ubx_decoder.buf.payload_tx_cfg_rate, 0, sizeof(ubx_decoder.buf.payload_tx_cfg_rate));
    ubx_decoder.buf.payload_tx_cfg_rate.measRate = UBX_TX_CFG_RATE_MEASINTERVAL;
    ubx_decoder.buf.payload_tx_cfg_rate.navRate  = UBX_TX_CFG_RATE_NAVRATE;
    ubx_decoder.buf.payload_tx_cfg_rate.timeRef  = UBX_TX_CFG_RATE_TIMEREF;

    send_ubx_msg(&ubx_decoder, UBX_MSG_CFG_RATE, ubx_decoder.buf.raw, sizeof(ubx_decoder.buf.payload_tx_cfg_rate));

    if (wait_for_ack(UBX_MSG_CFG_RATE, UBX_CONFIG_TIMEOUT) < 0) {
        DRV_DBG("UBX_MSG_CFG_RATE config fail!\n");
        return RT_ERROR;
    }

    /* send a NAV5 message to set the options for the internal filter */
    memset(&ubx_decoder.buf.payload_tx_cfg_nav5, 0, sizeof(ubx_decoder.buf.payload_tx_cfg_nav5));
    ubx_decoder.buf.payload_tx_cfg_nav5.mask     = UBX_TX_CFG_NAV5_MASK;
    ubx_decoder.buf.payload_tx_cfg_nav5.dynModel = UBX_TX_CFG_NAV5_DYNMODEL;
    ubx_decoder.buf.payload_tx_cfg_nav5.fixMode  = UBX_TX_CFG_NAV5_FIXMODE;

    send_ubx_msg(&ubx_decoder, UBX_MSG_CFG_NAV5, ubx_decoder.buf.raw, sizeof(ubx_decoder.buf.payload_tx_cfg_nav5));

    if (wait_for_ack(UBX_MSG_CFG_NAV5, UBX_CONFIG_TIMEOUT) < 0) {
        DRV_DBG("Wait ACK for UBX_MSG_CFG_NAV5 timeout\n");
        return RT_ERROR;
    }

    /* configure message rates */
    /* the last argument is divisor for measurement rate (set by CFG RATE), i.e. 1 means 10Hz */

    /* try to set rate for NAV-PVT */
    /* (implemented for ubx7+ modules only, use NAV-SOL, NAV-POSLLH, NAV-VELNED and NAV-TIMEUTC for ubx6) */
    configure_ubx_msg_rate(&ubx_decoder, UBX_MSG_NAV_PVT, 1);

    if (wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
        DRV_DBG("Don't support NAV-PVT\n");
        ubx_decoder.use_nav_pvt = false;

    } else {
        DRV_DBG("Support NAV-PVT\n");
        ubx_decoder.use_nav_pvt = true;
    }

    if (!ubx_decoder.use_nav_pvt) {
        // _configure_message_rate(UBX_MSG_NAV_TIMEUTC, 5);

        // if (wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
        //     DRV_DBG("UBX_MSG_NAV_TIMEUTC configure fail!\n");
        //     return 1;
        // }

        configure_ubx_msg_rate(&ubx_decoder, UBX_MSG_NAV_POSLLH, 1);

        if (wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
            DRV_DBG("UBX_MSG_CFG_MSG configure fail!\n");
            return RT_ERROR;
        }

        configure_ubx_msg_rate(&ubx_decoder, UBX_MSG_NAV_SOL, 1);

        if (wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
            DRV_DBG("UBX_MSG_NAV_SOL configure fail!\n");
            return RT_ERROR;
        }

        configure_ubx_msg_rate(&ubx_decoder, UBX_MSG_NAV_VELNED, 1);

        if (wait_for_ack(UBX_MSG_CFG_MSG, UBX_CONFIG_TIMEOUT) < 0) {
            DRV_DBG("UBX_MSG_NAV_VELNED configure fail!\n");
            return RT_ERROR;
        }
    }

    /* request module version information by sending an empty MON-VER message */
    send_ubx_msg(&ubx_decoder, UBX_MSG_MON_VER, NULL, 0);

    ubx_decoder.configured = RT_TRUE;

    return RT_EOK;
}

static rt_err_t gps_control(gps_dev_t gps_dev, int cmd, void* arg)
{
    switch (cmd) {
    case GPS_CMD_CHECK_READY:
        if (arg == NULL) {
            return RT_ERROR;
        }
        if (ubx_decoder.got_posllh && ubx_decoder.got_velned) {
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
    if (ubx_decoder.got_posllh && ubx_decoder.got_velned) {

        OS_ENTER_CRITICAL;
        *report                = gps_report;
        ubx_decoder.got_posllh = false;
        ubx_decoder.got_velned = false;
        OS_EXIT_CRITICAL;

        return sizeof(gps_report_t);
    }

    return 0;
}

static struct gps_ops gps_ops = {
    gps_control,
    gps_read
};

static void gps_probe_entry(void* parameter)
{
    uint32_t baudrate;
    uint8_t  i;

    for (i = 0; i < CONFIGURE_RETRY_MAX; i++) {
        if (probe(&baudrate) == RT_EOK) {
            if (configure_by_ubx(baudrate) == RT_EOK) {
                /* GPS is dected, now register */
                hal_gps_register(&gps_device, "gps", RT_DEVICE_FLAG_RDWR, RT_NULL);
                register_sensor_gps((char*)parameter);
                break;
            }
        }
    }

    if (i >= CONFIGURE_RETRY_MAX) {
        printf("GPS configuration fail! Please check if GPS module has connected.");
    }

    rt_free(parameter);
}

rt_err_t gps_ubx_init(const char* serial_device_name, const char* gps_device_name)
{
    char* str_buffer;

    gps_device.ops = &gps_ops;

    str_buffer = (char*)rt_malloc(21);
    RT_ASSERT(str_buffer != NULL);
    memset(str_buffer, 0, 21);
    strncpy(str_buffer, gps_device_name, 20);

    serial_device = rt_device_find(serial_device_name);
    RT_ASSERT(serial_device != NULL);

    /* set gps rx indicator */
    RT_CHECK(rt_device_set_rx_indicate(serial_device, gps_serial_rx_ind));
    /* open serial device */
    RT_CHECK(rt_device_open(serial_device, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX));
    /* init ublox decoder */
    FMT_CHECK(init_ubx_decoder(&ubx_decoder, serial_device, ubx_rx_handle));

    /* create a thread to probe the gps connection */
    rt_thread_t tid = rt_thread_create("gps_probe", gps_probe_entry, str_buffer, 4096, RT_THREAD_PRIORITY_MAX - 2, 5);
    RT_ASSERT(tid != NULL);

    RT_CHECK(rt_thread_startup(tid));

    return RT_EOK;
}