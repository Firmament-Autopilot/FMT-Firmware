
#include "driver/servo/servo_himark.c"
#include "module/sensor/sensor_hub.h"

static rt_device_t dronecan_device;
static struct can_device servo_device;

struct com_himark_servo_ServoInfo servo_himark_msg;
void handle_servo_info(CanardRxTransfer* transfer)
{
    com_himark_servo_ServoInfo_encode(transfer, &com_himark_servo_ServoInfo_encode);

    // printf("handle_gnss_Fix2!\n");

}

static void servo_probe_entry(void* parameter)
{
    uint8_t i;
    for (i = 0; i < CONFIGURE_RETRY_MAX; i++) {
        systime_mdelay(50);
        if (dronecan_got_velned == true && dronecan_got_velned == true) {
            /* servo is dected, now register */
            hw_can_register(&gps_device, "can_servo", RT_DEVICE_FLAG_RDWR, RT_NULL);
            register_sensor_gps((char*)parameter);

            printf("servo himark configuration Success!\n");

            break;
        }
    }

    if (i >= CONFIGURE_RETRY_MAX) {
        printf("GPS configuration fail! Please check if GPS module has connected.\n");
    }

    rt_free(parameter);
}

rt_err_t servo_himark_init(const char* dronecan_device_name, const char* servo_device_name)
{
    char* str_buffer = (char*)rt_malloc(21);
    RT_ASSERT(str_buffer != NULL);
    memset(str_buffer, 0, 21);
    strncpy(str_buffer, servo_device_name, 20);

    dronecan_device = rt_device_find(dronecan_device_name);
    RT_ASSERT(dronecan_device != NULL);

    gps_device.ops = &gps_ops;
    servo_device.ops = 
    /* create a thread to probe the gps connection */
    rt_thread_t tid = rt_thread_create("himark_probe", servo_probe_entry, str_buffer, 4096, RT_THREAD_PRIORITY_MAX - 2, 5);
    RT_ASSERT(tid != NULL);

    RT_CHECK(rt_thread_startup(tid));

    return RT_EOK;
}
