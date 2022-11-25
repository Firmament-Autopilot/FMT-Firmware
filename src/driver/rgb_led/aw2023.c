/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#include "driver/rgb_led/aw2023.h"
#include "hal/i2c/i2c.h"

#define DRV_DBG(...) console_printf(__VA_ARGS__)
// #define DRV_DBG(...)

#define AW2023_REG_RSTR   0x00
#define AW2023_REG_GCR1   0x01
#define AW2023_REG_ISR    0x02
#define AW2023_REG_PATST  0x03
#define AW2023_REG_GCR2   0x04
#define AW2023_REG_LCTR   0x30
#define AW2023_REG_LCFG0  0x31
#define AW2023_REG_LCFG1  0x32
#define AW2023_REG_LCFG2  0x33
#define AW2023_REG_PWM0   0x34
#define AW2023_REG_PWM1   0x35
#define AW2023_REG_PWM2   0x36
#define AW2023_REG_LED0T0 0x37
#define AW2023_REG_LED0T1 0x38
#define AW2023_REG_LED0T2 0x39
#define AW2023_REG_LED1T0 0x3A
#define AW2023_REG_LED1T1 0x3B
#define AW2023_REG_LED1T2 0x3C
#define AW2023_REG_LED2T0 0x3D
#define AW2023_REG_LED2T1 0x3E
#define AW2023_REG_LED2T2 0x3F

#define AW2023_CHIP_ID 0x09

static rt_device_t i2c_dev;

static void send_led_rgb(void)
{
    /* Do not pack 3 data into a single msg, otherwise color set would fail some how,
     * it could because that the ncp5623 speed is relatively slow */
    // struct rt_i2c_msg msgs[3];
    // uint8_t data[3] = { NCP5623_LED_PWM0 | _r, NCP5623_LED_PWM1 | _g, NCP5623_LED_PWM2 | _b };

    // msgs[0].flags = RT_I2C_WR | i2c_device->flags;
    // msgs[0].buf = &data[0];
    // msgs[0].len = 1;

    // msgs[1].flags = RT_I2C_WR | i2c_device->flags;
    // msgs[1].buf = &data[1];
    // msgs[1].len = 1;

    // msgs[2].flags = RT_I2C_WR | i2c_device->flags;
    // msgs[2].buf = &data[2];
    // msgs[2].len = 1;

    // rt_size_t ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, msgs, 3);
    // if (ret != 3) {
    //     DRV_DBG("set led rgb fail!\n");
    // }
}

static void send_led_bright(void)
{
    // struct rt_i2c_msg msgs;
    // uint8_t data = { NCP5623_LED_CURRENT | _brightness };

    // msgs.flags = RT_I2C_WR | i2c_device->flags;
    // msgs.buf = &data;
    // msgs.len = 1;

    // rt_size_t ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, &msgs, 1);
    // if (ret != 1) {
    //     PERIOD_EXECUTE(dbg, 1000, DRV_DBG("set led bright fail! IC1 ISR:0x%x ret:%d\n", I2C1->ISR, ret););
    // }
}

static rt_err_t led_shutdown(void)
{
    // struct rt_i2c_msg msgs;
    // uint8_t data = NCP5623_LED_OFF;

    // msgs.flags = RT_I2C_WR | i2c_device->flags;
    // msgs.buf = &data;
    // msgs.len = 1;

    // if (rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, &msgs, 1) != 1) {
    //     DRV_DBG("rgb led shutdown fail\n");
    //     return RT_ERROR;
    // }

    return RT_EOK;
}

static rt_err_t aw2023_control(rt_device_t dev, int cmd, void* args)
{
    // uint8_t color;

    // switch (cmd) {
    // case NCP5623_CMD_SET_COLOR:
    //     color = (uint32_t)args;
    //     if (color == NCP5623_LED_RED) {
    //         _r = LED_BRIGHT;
    //         _g = 0;
    //         _b = 0;
    //     } else if (color == NCP5623_LED_GREEN) {
    //         _r = 0;
    //         _g = LED_BRIGHT;
    //         _b = 0;
    //     } else if (color == NCP5623_LED_BLUE) {
    //         _r = 0;
    //         _g = 0;
    //         _b = LED_BRIGHT;
    //     } else if (color == NCP5623_LED_YELLOW) {
    //         _r = LED_BRIGHT;
    //         _g = LED_BRIGHT;
    //         _b = 0;
    //     } else if (color == NCP5623_LED_PURPLE) {
    //         _r = LED_BRIGHT;
    //         _g = 0;
    //         _b = LED_BRIGHT;
    //     } else if (color == NCP5623_LED_CYAN) {
    //         _r = 0;
    //         _g = LED_BRIGHT;
    //         _b = LED_BRIGHT;
    //     } else if (color == NCP5623_LED_WHITE) {
    //         _r = LED_BRIGHT;
    //         _g = LED_BRIGHT;
    //         _b = LED_BRIGHT;
    //     } else {
    //         _r = 0;
    //         _g = 0;
    //         _b = 0;
    //     }
    //     send_led_rgb();
    //     break;

    // case NCP5623_CMD_SET_BRIGHT:
    //     _brightness = (uint32_t)args & 0x1F;
    //     // NOTE: NCP5623C speed is low, so don't write i2c command too fast
    //     send_led_bright();
    //     break;

    // default:
    //     break;
    // }

    return RT_EOK;
}

static rt_err_t probe(void)
{
    uint8_t chip_id;

    RT_TRY(i2c_read_reg(i2c_dev, AW2023_REG_RSTR, &chip_id));

    if (chip_id != AW2023_CHIP_ID) {
        DRV_DBG("aw2023 wrong chip id:%x\n", chip_id);
        return RT_ENOSYS;
    }

    return RT_EOK;
}

rt_err_t drv_aw2023_init(const char* i2c_dev_name)
{
    i2c_dev = rt_device_find(i2c_dev_name);
    RT_ASSERT(i2c_dev != NULL);

    RT_CHECK(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(probe());

    /* reset the chip */
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_RSTR, 0x55));
    systime_mdelay(5);

    /* let device enters active state */
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_GCR1, 0x01));
    systime_mdelay(5);

    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LCTR, 0x00));

    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LCFG0, 0x03));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LCFG1, 0x03));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LCFG2, 0x03));
    systime_mdelay(5);

    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED0T0, 0x77));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED1T0, 0x77));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED2T0, 0x77));
    systime_mdelay(5);

    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED0T1, 0x77));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED1T1, 0x77));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED2T1, 0x77));
    systime_mdelay(5);

    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED0T2, 0x70));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED1T2, 0x70));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LED2T2, 0x70));
    systime_mdelay(5);

    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_PWM0, 127));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_PWM1, 127));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_PWM2, 127));
    systime_mdelay(5);

    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LCFG0, 0x13));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LCFG1, 0x13));
    systime_mdelay(5);
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LCFG2, 0x13));
    systime_mdelay(5);

    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_LCTR, 0x07));

    // RT_CHECK(rt_device_register(device, "ncp5623c", RT_DEVICE_OFLAG_RDWR));

    return RT_EOK;
}
