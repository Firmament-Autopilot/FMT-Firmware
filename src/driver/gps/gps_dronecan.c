#include "gps_dronecan.h"

static struct gps_ops gps_ops = {
    gps_control,
    gps_read
};

rt_err_t gps_dronecan_init(const char* dronecan_device_name, const char* gps_device_name)
{
    gps_device.ops = &gps_ops;
}