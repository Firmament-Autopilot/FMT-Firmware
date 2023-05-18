
#include "driver/gps/gps_dronecan.h"
#include "module/sensor/sensor_hub.h"

#define CONFIGURE_RETRY_MAX 5

static rt_device_t dronecan_device;
static gps_report_t gps_report;
static struct gps_device gps_device;

static bool dronecan_got_posllh, dronecan_got_velned;

static rt_err_t gnss_control(gps_dev_t gps_dev, int cmd, void* arg)
{
    switch (cmd) {
    case GPS_CMD_CHECK_READY:
        if (arg == NULL) {
            return RT_ERROR;
        }
        if (dronecan_got_velned && dronecan_got_posllh) {
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

static rt_size_t gnss_read(gps_dev_t gps_dev, gps_report_t* report)
{
    if (dronecan_got_posllh && dronecan_got_velned) {
        OS_ENTER_CRITICAL;
        *report = gps_report;
        dronecan_got_velned = false;
        dronecan_got_posllh = false;
        OS_EXIT_CRITICAL;
        return sizeof(gps_report_t);
    }

    return 0;
}

static struct gps_ops gps_ops = {
    gnss_control,
    gnss_read,
};

static void gnss_probe_entry(void* parameter)
{
    for (uint8_t i = 0; i < CONFIGURE_RETRY_MAX; i++) {
    }

    rt_free(parameter);
}

struct uavcan_equipment_gnss_Fix2 gnss_Fix2_msg;
void handle_gnss_Fix2(CanardRxTransfer* transfer)
{
    uavcan_equipment_gnss_Fix2_decode(transfer, &gnss_Fix2_msg);

    gps_report.fix_type = gnss_Fix2_msg.status;

    gps_report.lat = gnss_Fix2_msg.latitude_deg_1e8 * 10;
    gps_report.lon = gnss_Fix2_msg.longitude_deg_1e8 * 10;
    gps_report.alt = gnss_Fix2_msg.height_msl_mm;

    gps_report.vel_n_m_s = gnss_Fix2_msg.ned_velocity[0];
    gps_report.vel_e_m_s = gnss_Fix2_msg.ned_velocity[1];
    gps_report.vel_d_m_s = gnss_Fix2_msg.ned_velocity[2];

    gps_report.time_gps_usec = gnss_Fix2_msg.gnss_timestamp.usec;

    gps_report.timestamp_time = systime_now_ms();
    gps_report.timestamp_velocity = systime_now_ms();
    gps_report.timestamp_variance = systime_now_ms();
    gps_report.timestamp_position = systime_now_ms();

    dronecan_got_posllh = true;
    dronecan_got_velned = true;
}

struct uavcan_equipment_gnss_Auxiliary gnss_Auxiliary_msg;
void handle_gnss_Auxiliary(CanardRxTransfer* transfer)
{
    uavcan_equipment_gnss_Auxiliary_decode(transfer, &gnss_Auxiliary_msg);

    gps_report.satellites_used = gnss_Auxiliary_msg.sats_used;

    gps_report.vdop = gnss_Auxiliary_msg.vdop;
    gps_report.tdop = gnss_Auxiliary_msg.tdop;
    gps_report.hdop = gnss_Auxiliary_msg.hdop;
    gps_report.ndop = gnss_Auxiliary_msg.ndop;
    gps_report.edop = gnss_Auxiliary_msg.edop;
}

static void gps_probe_entry(void* parameter)
{
    uint8_t i;
    for (i = 0; i < CONFIGURE_RETRY_MAX; i++) {
        if (dronecan_got_velned == true && dronecan_got_velned == true) {
            /* GPS is dected, now register */
            hal_gps_register(&gps_device, "gps", RT_DEVICE_FLAG_RDWR, RT_NULL);
            register_sensor_gps((char*)parameter);
            break;
        }
    }

    if (i >= CONFIGURE_RETRY_MAX) {
        printf("GPS configuration fail! Please check if GPS module has connected.");
    }

    rt_free(parameter);
}

rt_err_t gps_dronecan_init(const char* dronecan_device_name, const char* gps_device_name)
{
    char* str_buffer = (char*)rt_malloc(21);
    RT_ASSERT(str_buffer != NULL);
    memset(str_buffer, 0, 21);
    strncpy(str_buffer, gps_device_name, 20);

    dronecan_device = rt_device_find(dronecan_device_name);
    RT_ASSERT(dronecan_device != NULL);

    gps_device.ops = &gps_ops;

    /* create a thread to probe the gps connection */
    rt_thread_t tid = rt_thread_create("gps_probe", gps_probe_entry, str_buffer, 4096, RT_THREAD_PRIORITY_MAX - 2, 5);
    RT_ASSERT(tid != NULL);

    RT_CHECK(rt_thread_startup(tid));

    return RT_EOK;
}
