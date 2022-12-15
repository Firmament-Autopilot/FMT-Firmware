/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#define DRV_DBG(...) printf(__VA_ARGS__)
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

#define AW2023_CHIP_ID            0x09
#define AW2023_CHIP_RESER         0x55
#define AW2023_CHIP_EN            BIT(0)
#define AW2023_IMAX_15mA          0
#define AW2023_IMAX_30mA          BIT(0)
#define AW2023_IMAX_5mA           BIT(1)
#define AW2023_IMAX_10mA          BIT(0) | BIT(1)
#define AW2023_FREQ_250Hz         0
#define AW2023_FREQ_125Hz         BIT(5)
#define AW2023_PWM_LIN            BIT(3)
#define AW2023_LED2_EN            BIT(2)
#define AW2023_LED1_EN            BIT(1)
#define AW2023_LED0_EN            BIT(0)
#define AW2023_LED_SYNC_MODE      BIT(7)
#define AW2023_LED_FADE_OUT       BIT(6)
#define AW2023_LED_FADE_IN        BIT(5)
#define AW2023_LED_PATERN_MODE    BIT(4)
#define AW2023_LED_CURRENT(cur)   (cur & 0x0F)
#define AW2023_PWM_DIMMING(dim)   (dim & 0xFF)
#define AW2023_T1_0_0s            0
#define AW2023_T1_0_13s           BIT(4)
#define AW2023_T1_0_26s           BIT(5)
#define AW2023_T1_0_38s           BIT(4) | BIT(5)
#define AW2023_T1_0_51s           BIT(6)
#define AW2023_T1_0_77s           BIT(4) | BIT(6)
#define AW2023_T1_1_04s           BIT(5) | BIT(6)
#define AW2023_T1_1_6s            BIT(4) | BIT(5) | BIT(6)
#define AW2023_T1_2_1s            BIT(7)
#define AW2023_T1_2_6s            BIT(4) | BIT(7)
#define AW2023_T1_3_1s            BIT(5) | BIT(7)
#define AW2023_T1_4_2s            BIT(4) | BIT(5) | BIT(7)
#define AW2023_T1_5_2s            BIT(6) | BIT(7)
#define AW2023_T1_6_2s            BIT(4) | BIT(6) | BIT(7)
#define AW2023_T1_7_3s            BIT(5) | BIT(6) | BIT(7)
#define AW2023_T1_8_3s            BIT(4) | BIT(5) | BIT(6) | BIT(7)
#define AW2023_T2_0_04s           0
#define AW2023_T2_0_13s           BIT(0)
#define AW2023_T2_0_26s           BIT(1)
#define AW2023_T2_0_38s           BIT(0) | BIT(1)
#define AW2023_T2_0_51s           BIT(2)
#define AW2023_T2_0_77s           BIT(0) | BIT(2)
#define AW2023_T2_1_04s           BIT(1) | BIT(2)
#define AW2023_T2_1_6s            BIT(0) | BIT(1) | BIT(2)
#define AW2023_T2_2_1s            BIT(3)
#define AW2023_T2_2_6s            BIT(0) | BIT(3)
#define AW2023_T2_3_1s            BIT(1) | BIT(3)
#define AW2023_T2_4_2s            BIT(0) | BIT(1) | BIT(3)
#define AW2023_T2_5_2s            BIT(2) | BIT(3)
#define AW2023_T2_6_2s            BIT(0) | BIT(2) | BIT(3)
#define AW2023_T2_7_3s            BIT(1) | BIT(2) | BIT(3)
#define AW2023_T2_8_3s            BIT(0) | BIT(1) | BIT(2) | BIT(3)
#define AW2023_T3_0_0s            0
#define AW2023_T3_0_13s           BIT(4)
#define AW2023_T3_0_26s           BIT(5)
#define AW2023_T3_0_38s           BIT(4) | BIT(5)
#define AW2023_T3_0_51s           BIT(6)
#define AW2023_T3_0_77s           BIT(4) | BIT(6)
#define AW2023_T3_1_04s           BIT(5) | BIT(6)
#define AW2023_T3_1_6s            BIT(4) | BIT(5) | BIT(6)
#define AW2023_T3_2_1s            BIT(7)
#define AW2023_T3_2_6s            BIT(4) | BIT(7)
#define AW2023_T3_3_1s            BIT(5) | BIT(7)
#define AW2023_T3_4_2s            BIT(4) | BIT(5) | BIT(7)
#define AW2023_T3_5_2s            BIT(6) | BIT(7)
#define AW2023_T3_6_2s            BIT(4) | BIT(6) | BIT(7)
#define AW2023_T3_7_3s            BIT(5) | BIT(6) | BIT(7)
#define AW2023_T3_8_3s            BIT(4) | BIT(5) | BIT(6) | BIT(7)
#define AW2023_T4_0_04s           0
#define AW2023_T4_0_13s           BIT(0)
#define AW2023_T4_0_26s           BIT(1)
#define AW2023_T4_0_38s           BIT(0) | BIT(1)
#define AW2023_T4_0_51s           BIT(2)
#define AW2023_T4_0_77s           BIT(0) | BIT(2)
#define AW2023_T4_1_04s           BIT(1) | BIT(2)
#define AW2023_T4_1_6s            BIT(0) | BIT(1) | BIT(2)
#define AW2023_T4_2_1s            BIT(3)
#define AW2023_T4_2_6s            BIT(0) | BIT(3)
#define AW2023_T4_3_1s            BIT(1) | BIT(3)
#define AW2023_T4_4_2s            BIT(0) | BIT(1) | BIT(3)
#define AW2023_T4_5_2s            BIT(2) | BIT(3)
#define AW2023_T4_6_2s            BIT(0) | BIT(2) | BIT(3)
#define AW2023_T4_7_3s            BIT(1) | BIT(2) | BIT(3)
#define AW2023_T4_8_3s            BIT(0) | BIT(1) | BIT(2) | BIT(3)
#define AW2023_T0_0_4s            0
#define AW2023_T0_0_13s           BIT(4)
#define AW2023_T0_0_26s           BIT(5)
#define AW2023_T0_0_38s           BIT(4) | BIT(5)
#define AW2023_T0_0_51s           BIT(6)
#define AW2023_T0_0_77s           BIT(4) | BIT(6)
#define AW2023_T0_1_04s           BIT(5) | BIT(6)
#define AW2023_T0_1_6s            BIT(4) | BIT(5) | BIT(6)
#define AW2023_T0_2_1s            BIT(7)
#define AW2023_T0_2_6s            BIT(4) | BIT(7)
#define AW2023_T0_3_1s            BIT(5) | BIT(7)
#define AW2023_T0_4_2s            BIT(4) | BIT(5) | BIT(7)
#define AW2023_T0_5_2s            BIT(6) | BIT(7)
#define AW2023_T0_6_2s            BIT(4) | BIT(6) | BIT(7)
#define AW2023_T0_7_3s            BIT(5) | BIT(6) | BIT(7)
#define AW2023_T0_8_3s            BIT(4) | BIT(5) | BIT(6) | BIT(7)
#define AW2023_REPEAT_TIMES(time) (time & 0x0F)

#define LED_CURRENT 0x0F /**< full current */

#ifndef BIT
    #define BIT(_idx) (1 << _idx)
#endif
#define REG_VAL(_setbits, _clearbits) \
    (reg_val_t) { .setbits = (_setbits), .clearbits = (_clearbits) }

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

static uint8_t r;
static uint8_t g;
static uint8_t b;
static uint16_t brightness;
static uint8_t mode; //manual mode by default
static rt_device_t i2c_dev;

static rt_err_t i2c_write_checked_reg(rt_device_t i2c_dev, uint8_t reg, uint8_t val)
{
    uint8_t reg_val;

    RT_TRY(i2c_write_reg(i2c_dev, reg, val));
    RT_TRY(i2c_read_reg(i2c_dev, reg, &reg_val));

    if (reg_val != val) {
        DRV_DBG("checked reg %x fail:%x %x\n", reg, val, reg_val);
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t i2c_modify_reg(rt_device_t i2c_dev, uint8_t reg, reg_val_t reg_val)
{
    uint8_t value;

    RT_TRY(i2c_read_reg(i2c_dev, reg, &value));

    value &= ~reg_val.clearbits;
    value |= reg_val.setbits;

    RT_TRY(i2c_write_checked_reg(i2c_dev, reg, value));

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

static rt_err_t aw2023_control(rt_device_t dev, int cmd, void* args)
{
    uint8_t color;

    switch (cmd) {
    case AW2023_CMD_SET_COLOR:
        color = (uint32_t)args;
        if (color == AW2023_LED_RED) {
            r = LED_CURRENT;
            g = 0;
            b = 0;
        } else if (color == AW2023_LED_GREEN) {
            r = 0;
            g = LED_CURRENT;
            b = 0;
        } else if (color == AW2023_LED_BLUE) {
            r = 0;
            g = 0;
            b = LED_CURRENT;
        } else if (color == AW2023_LED_YELLOW) {
            r = LED_CURRENT;
            g = LED_CURRENT;
            b = 0;
        } else if (color == AW2023_LED_PURPLE) {
            r = LED_CURRENT;
            g = 0;
            b = LED_CURRENT;
        } else if (color == AW2023_LED_CYAN) {
            r = 0;
            g = LED_CURRENT;
            b = LED_CURRENT;
        } else if (color == AW2023_LED_WHITE) {
            r = LED_CURRENT;
            g = LED_CURRENT;
            b = LED_CURRENT;
        } else {
            /* unknown color, just close rgd leds */
            r = 0;
            g = 0;
            b = 0;
        }
        /* in sync mode, the led's current is controlled indivisualy */
        RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG0, AW2023_LED_SYNC_MODE | mode | AW2023_LED_CURRENT(b)));
        RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG1, mode | AW2023_LED_CURRENT(g)));
        RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG2, mode | AW2023_LED_CURRENT(r)));
        break;

    case AW2023_CMD_SET_BRIGHT:
        brightness = (uint32_t)args & 0xFF;
        /* in sync mode, the pwm0 is applyed for all leds */
        RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_PWM0, AW2023_PWM_DIMMING(brightness)));
        break;

    case AW2023_CMD_SET_MANUAL_MODE:
        mode = 0;
        /* in sync mode we only need set led0 mode for all leds */
        RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG0, AW2023_LED_SYNC_MODE | mode | AW2023_LED_CURRENT(b)));
        break;

    case AW2023_CMD_SET_PATERN_MODE:
        mode = AW2023_LED_PATERN_MODE;
        /* in sync mode we only need set led0 mode for all leds */
        RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG0, AW2023_LED_SYNC_MODE | mode | AW2023_LED_CURRENT(b)));
        break;

    default:
        return RT_EINVAL;
    }

    return RT_EOK;
}

rt_err_t drv_aw2023_init(const char* i2c_dev_name)
{
    static struct rt_device aw2023_dev;

    i2c_dev = rt_device_find(i2c_dev_name);
    RT_ASSERT(i2c_dev != NULL);

    RT_CHECK(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(probe());

    /* reset the chip */
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_RSTR, AW2023_CHIP_RESER));
    systime_mdelay(2);
    /* let device enters active state */
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_GCR1, AW2023_CHIP_EN));
    systime_mdelay(2);

    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_GCR2, AW2023_IMAX_10mA));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG0, AW2023_LED_SYNC_MODE));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_PWM0, AW2023_PWM_DIMMING(brightness)));
    /* default patern time */
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED0T0, AW2023_T1_0_77s | AW2023_T2_0_26s));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED0T1, AW2023_T3_0_77s | AW2023_T4_0_13s));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED0T2, AW2023_T0_0_13s | AW2023_REPEAT_TIMES(0)));
    /* enable all LEDs */
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCTR, AW2023_FREQ_250Hz | AW2023_LED0_EN | AW2023_LED1_EN | AW2023_LED2_EN));

    /* give some time for rgb led to startup */
    systime_mdelay(10);

    aw2023_dev.type = RT_Device_Class_Miscellaneous;
    aw2023_dev.rx_indicate = RT_NULL;
    aw2023_dev.tx_complete = RT_NULL;
    aw2023_dev.user_data = RT_NULL;

    aw2023_dev.init = RT_NULL;
    aw2023_dev.open = RT_NULL;
    aw2023_dev.close = RT_NULL;
    aw2023_dev.read = RT_NULL;
    aw2023_dev.write = RT_NULL;
    aw2023_dev.control = aw2023_control;

    RT_CHECK(rt_device_register(&aw2023_dev, "aw2023", RT_DEVICE_OFLAG_RDWR));

    return RT_EOK;
}
