#include <firmament.h>
#include <uxr/client/profile/transport/serial/serial_transport_external.h>
#include <uxr/client/profile/transport/serial/serial_transport_platform.h>

bool uxr_init_serial_platform(struct uxrSerialPlatform* platform, int fd, uint8_t remote_addr, uint8_t local_addr)
{
    platform->dev = (rt_device_t)fd;

    // Return true if success
    return true;
}

bool uxr_close_serial_platform(struct uxrSerialPlatform* platform)
{
    if (platform->dev) {
        rt_device_close(platform->dev);
    }

    // Return true if success
    return true;
}

size_t uxr_write_serial_data_platform(uxrSerialPlatform* platform, uint8_t* buf, size_t len, uint8_t* errcode)
{
    ssize_t bytes_written = rt_device_write(platform->dev, RT_WAITING_FOREVER, (void*)buf, (rt_size_t)len);

    // Return number of bytes written
    return bytes_written;
}

size_t uxr_read_serial_data_platform(uxrSerialPlatform* platform, uint8_t* buf, size_t len, int timeout, uint8_t* errcode)
{
    rt_size_t bytes_read = 0;
    uint32_t time_start_ms = systime_now_ms();

    do {
        bytes_read += rt_device_read(platform->dev, timeout, (void*)&buf[bytes_read], (rt_size_t)(len - bytes_read));
    } while (bytes_read < len && (systime_now_ms() - time_start_ms < timeout));

    // Return number of bytes read (max bytes: len)
    return bytes_read;
}
