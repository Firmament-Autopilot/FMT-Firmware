#include "driver/ist8310.h"
#include "hal/i2c.h"
#include "hal/i2c_dev.h"
#include <firmament.h>

uint8_t ist8310_id;

struct rt_i2c_bus_device* i2c_bus;

int16_t magRaw[3] = { 0 };

static rt_err_t write_reg(struct rt_i2c_bus_device* bus, rt_uint8_t reg)
{
    rt_uint8_t buf[2];
    struct rt_i2c_msg msgs;

    buf[0] = reg;

    msgs.addr = IST8310_ADDRESS;
    msgs.flags = RT_I2C_WR;
    msgs.buf = buf;
    msgs.len = 1;

    /* 调用I2C设备接口传输数据 */
    rt_i2c_transfer(bus, &msgs, 1);

    return RT_EOK;
}

static rt_err_t write_reg_data(struct rt_i2c_bus_device* bus, rt_uint8_t reg, rt_uint8_t data)
{
    rt_uint8_t buf[2];
    struct rt_i2c_msg msgs;

    buf[0] = reg;
    buf[1] = data;

    msgs.addr = IST8310_ADDRESS;
    msgs.flags = RT_I2C_WR;
    msgs.buf = buf;
    msgs.len = 2;

    /* 调用I2C设备接口传输数据 */
    rt_i2c_transfer(bus, &msgs, 1);

    return RT_EOK;
}

static rt_err_t read_regs(struct rt_i2c_bus_device* bus, rt_uint8_t len, rt_uint8_t* buf)
{
    struct rt_i2c_msg msgs;

    msgs.addr = IST8310_ADDRESS;
    msgs.flags = RT_I2C_RD;
    msgs.buf = buf;
    msgs.len = len;

    /* 调用I2C设备接口传输数据 */
    rt_i2c_transfer(bus, &msgs, 1);
    return RT_EOK;
}

void my_read_reg(struct rt_i2c_bus_device* bus, rt_uint8_t reg, rt_uint8_t* buf)
{
    rt_uint8_t send_buf;
    struct rt_i2c_msg msgs[2];

    send_buf = reg;

    msgs[0].addr = IST8310_ADDRESS;
    msgs[0].flags = RT_I2C_WR;
    msgs[0].buf = &send_buf;
    msgs[0].len = 1;

    msgs[1].addr = IST8310_ADDRESS;
    msgs[1].flags = RT_I2C_RD;
    msgs[1].buf = buf;
    msgs[1].len = 1;

    rt_i2c_transfer(bus, msgs, 2);
}

void my_read_multi_reg(struct rt_i2c_bus_device* bus, rt_uint8_t reg, rt_uint8_t* buf)
{
    rt_uint8_t send_buf;
    struct rt_i2c_msg msgs[2];

    send_buf = reg;

    msgs[0].addr = IST8310_ADDRESS;
    msgs[0].flags = RT_I2C_WR;
    msgs[0].buf = &send_buf;
    msgs[0].len = 1;

    msgs[1].addr = IST8310_ADDRESS;
    msgs[1].flags = RT_I2C_RD;
    msgs[1].buf = buf;
    msgs[1].len = 6;

    rt_i2c_transfer(bus, msgs, 2);
}

int rt_ist8310_init(char* i2c_device_name)
{
    i2c_bus = rt_i2c_bus_device_find(i2c_device_name);
    if (i2c_bus == RT_NULL) {
        rt_kprintf("find i2c bus fail!\n");
        return RT_ERROR;
    }
    rt_kprintf("find i2c bus success!\n");

    // write_reg(i2c_bus,IST8310_REG_WHOAMI);
    // read_regs(i2c_bus,1,&ist8310_id);
    my_read_reg(i2c_bus, IST8310_REG_WHOAMI, &ist8310_id);

    console_printf("ist8310 id:%x\n", ist8310_id);

    write_reg_data(i2c_bus, IST8310_REG_CNTRL1, IST8310_ODR_200_HZ);

    return 0;
}

void ist8310_read_raw_data(void)
{
    uint8_t buffer[6];

    // write_reg(i2c_bus,IST8310_REG_HX_L);
    // read_regs(i2c_bus,1,&buffer[1]);

    // write_reg(i2c_bus,IST8310_REG_HX_H);
    // read_regs(i2c_bus,1,&buffer[0]);
    // magRaw[0] = (int16_t)buffer[0] << 8 | buffer[1];

    // write_reg(i2c_bus,IST8310_REG_HY_L);
    // read_regs(i2c_bus,1,&buffer[3]);

    // write_reg(i2c_bus,IST8310_REG_HY_H);
    // read_regs(i2c_bus,1,&buffer[2]);
    // magRaw[1] = (int16_t)buffer[2] << 8 | buffer[3];

    // write_reg(i2c_bus,IST8310_REG_HZ_L);
    // read_regs(i2c_bus,1,&buffer[5]);

    // write_reg(i2c_bus,IST8310_REG_HZ_H);
    // read_regs(i2c_bus,1,&buffer[4]);
    // magRaw[2] = (int16_t)buffer[4] << 8 | buffer[5];

    // my_read_reg(i2c_bus,IST8310_REG_HX_L, &buffer[1]);
    // my_read_reg(i2c_bus,IST8310_REG_HX_H, &buffer[0]);
    // magRaw[0] = (int16_t)buffer[0] << 8 | buffer[1];

    // my_read_reg(i2c_bus,IST8310_REG_HY_L, &buffer[3]);
    // my_read_reg(i2c_bus,IST8310_REG_HY_H, &buffer[2]);
    // magRaw[1] = (int16_t)buffer[2] << 8 | buffer[3];

    // my_read_reg(i2c_bus,IST8310_REG_HZ_L, &buffer[5]);
    // my_read_reg(i2c_bus,IST8310_REG_HZ_H, &buffer[4]);
    // magRaw[2] = (int16_t)buffer[4] << 8 | buffer[5];

    my_read_multi_reg(i2c_bus, IST8310_REG_HX_L, buffer);
    magRaw[0] = (int16_t)buffer[1] << 8 | buffer[0];
    magRaw[1] = (int16_t)buffer[3] << 8 | buffer[2];
    magRaw[2] = (int16_t)buffer[5] << 8 | buffer[4];

    write_reg(i2c_bus, IST8310_REG_HX_H);
    read_regs(i2c_bus, 1, &buffer[0]);

    write_reg(i2c_bus, IST8310_REG_HX_H);
    read_regs(i2c_bus, 1, &buffer[0]);

    write_reg(i2c_bus, IST8310_REG_HY_H);
    read_regs(i2c_bus, 1, &buffer[2]);

    console_printf("mag %d %d %d\n", magRaw[0], magRaw[1], magRaw[2]);
}