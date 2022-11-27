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

#ifndef BIT
    #define BIT(_idx) (1 << _idx)
#endif
#define REG_VAL(_setbits, _clearbits) \
    (reg_val_t) { .setbits = (_setbits), .clearbits = (_clearbits) }

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

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

    /* In case of read operations of the accelerometer part, the requested data is not sent 
    immediately, but instead first a dummy byte is sent, and after this dummy byte the actual 
    reqested register content is transmitted. */
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

rt_err_t drv_aw2023_init(const char* i2c_dev_name)
{
    i2c_dev = rt_device_find(i2c_dev_name);
    RT_ASSERT(i2c_dev != NULL);

    RT_CHECK(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(probe());

    /* reset the chip */
    RT_TRY(i2c_write_reg(i2c_dev, AW2023_REG_RSTR, AW2023_CHIP_RESER));
    systime_mdelay(5);

    /* let device enters active state */
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_GCR1, AW2023_CHIP_EN));
    systime_mdelay(5);

    uint8_t reg_val;
    RT_TRY(i2c_read_reg(i2c_dev, AW2023_REG_PATST, &reg_val));
    printf("PATST1:%x\n", reg_val);

    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCTR, 0x00));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG0, 0x00));

    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_GCR2, AW2023_IMAX_15mA));
    

    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG0, AW2023_LED_SYNC_MODE | AW2023_LED_CURRENT(15)));

    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_PWM0, AW2023_PWM_DIMMING(255)));

    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED0T0, AW2023_T1_2_1s | AW2023_T2_2_1s));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED0T1, AW2023_T3_2_1s | AW2023_T4_2_1s));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED0T2, AW2023_T0_2_1s | AW2023_REPEAT_TIMES(0)));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED1T0, AW2023_T1_2_1s | AW2023_T2_2_1s));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED1T1, AW2023_T3_2_1s | AW2023_T4_2_1s));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED1T2, AW2023_T0_2_1s | AW2023_REPEAT_TIMES(0)));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED2T0, AW2023_T1_2_1s | AW2023_T2_2_1s));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED2T1, AW2023_T3_2_1s | AW2023_T4_2_1s));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LED2T2, AW2023_T0_2_1s | AW2023_REPEAT_TIMES(0)));

    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG0, AW2023_LED_CURRENT(15) | AW2023_LED_PATERN_MODE));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG1, AW2023_LED_CURRENT(7) | AW2023_LED_PATERN_MODE));
    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCFG2, AW2023_LED_CURRENT(0) | AW2023_LED_PATERN_MODE));

    RT_TRY(i2c_write_checked_reg(i2c_dev, AW2023_REG_LCTR, AW2023_FREQ_250Hz | AW2023_LED0_EN | AW2023_LED1_EN | AW2023_LED2_EN));

    systime_mdelay(10);

    // uint8_t reg_val;
    RT_TRY(i2c_read_reg(i2c_dev, AW2023_REG_PATST, &reg_val));
    printf("PATST2:%x\n", reg_val);

    return RT_EOK;
}
