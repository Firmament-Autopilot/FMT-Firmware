#include <firmament.h>
#include "hal/i2c/i2c.h"

/* --- I2C scan test (Firmament + ifx_i2c) --- */
static int i2c_scan_sample(void)
{
    struct rt_i2c_bus *bus;
    rt_uint16_t addr;   
    rt_uint8_t dummy = 0x00;

    bus = (struct rt_i2c_bus *)rt_device_find("i2c0");
    if (!bus)
    {
        rt_kprintf("i2c0 not found!\n");
        return -1;
    }

    rt_kprintf("Scanning I2C bus i2c0...\n");

    for (addr = 0x03; addr < 0x78; addr++)
    {
        struct rt_i2c_msg msg =
        {
            .flags = RT_I2C_WR,
            .buf   = &dummy,
            .len   = 1,
        };

        if (rt_i2c_transfer(bus, addr, &msg, 1) == 1)
        {
            rt_kprintf("  Found device at 0x%02X\n", addr);
        }
    }

    rt_kprintf("I2C scan done.\n");

    return 0;
}

MSH_CMD_EXPORT(i2c_scan_sample, I2C bus scan test);

static int i2c_write_sample(void)
{
    struct rt_i2c_bus *bus;
    rt_uint16_t addr = 0x1E;
    rt_uint8_t data = 0xAA;

    bus = (struct rt_i2c_bus *)rt_device_find("i2c0");
    if (!bus)
    {
        rt_kprintf("i2c0 not found!\n");
        return -1;
    }

    struct rt_i2c_msg msg =
    {
        .flags = RT_I2C_WR,
        .buf   = &data,
        .len   = 0,
    };

    if (rt_i2c_transfer(bus, addr, &msg, 1) == 1)
    {
        rt_kprintf("I2C write ok: dev=0x%02X data=0x%02X\n", addr, data);
    }
    else
    {
        rt_kprintf("I2C write failed!\n");
        return -1;
    }
    return 0;
}

MSH_CMD_EXPORT(i2c_write_sample, I2C single-byte write test);

static int i2c_read_sample(void)
{
    struct rt_i2c_bus *bus;
    rt_uint16_t addr = 0x1E;
    rt_uint8_t data = 0;

    bus = (struct rt_i2c_bus *)rt_device_find("i2c0");
    if (!bus)
    {
        rt_kprintf("i2c0 not found!\n");
        return -1;
    }

    struct rt_i2c_msg msg =
    {
        .flags = RT_I2C_RD,
        .buf   = &data,
        .len   = 1,
    };

    if (rt_i2c_transfer(bus, addr, &msg, 1) == 1)
    {
        rt_kprintf("I2C read ok: dev=0x%02X data=0x%02X\n", addr, data);
    }
    else
    {
        rt_kprintf("I2C read failed!\n");
        return -1;
    }
    return 0;
}

MSH_CMD_EXPORT(i2c_read_sample, I2C single-byte read test);
