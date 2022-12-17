#include <firmament.h>
#include <uxr/client/profile/transport/serial/serial_transport_external.h>
#include <uxr/client/profile/transport/serial/serial_transport_platform.h>

// Place here your includes

bool uxr_init_serial_platform(struct uxrSerialPlatform* platform, int fd, uint8_t remote_addr, uint8_t local_addr)
{
    // Place here your initialization platform code
    // console_printf("init serial platform 0x%x\n", fd);

    platform->dev = (rt_device_t)fd;

    // Return true if success
    return true;
}

bool uxr_close_serial_platform(struct uxrSerialPlatform* platform)
{
    // Place here your closing platform code
    // console_printf("close serial platform\n");

    if (platform->dev) {
        rt_device_close(platform->dev);
    }

    // Return true if success
    return true;
}

size_t uxr_write_serial_data_platform(uxrSerialPlatform* platform, uint8_t* buf, size_t len, uint8_t* errcode)
{
    // Place here your writing bytes platform code
    ssize_t bytes_written = rt_device_write(platform->dev, 0, (void*)buf, (rt_size_t)len);
    // console_printf("write serial platform: %d %d\n", len, bytes_written);

    // Return number of bytes written
    return bytes_written;
}

size_t uxr_read_serial_data_platform(uxrSerialPlatform* platform, uint8_t* buf, size_t len, int timeout, uint8_t* errcode)
{
    // Place here your reading bytes platform code
    rt_size_t bytes_read = 0;
    uint32_t time_start_ms = systime_now_ms();

    do {
        bytes_read += rt_device_read(platform->dev, 0, (void*)&buf[bytes_read], (rt_size_t)(len - bytes_read));
    } while (bytes_read < len && (systime_now_ms() - time_start_ms < timeout));

    // console_printf("read serial platform: %d %d\n", len, bytes_read);

    // Return number of bytes read (max bytes: len)
    return bytes_read;
}
