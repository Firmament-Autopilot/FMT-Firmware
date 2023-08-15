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

#include "drv_i2c.h"
#include "hal/i2c/i2c.h"

#include "ar1002_hal.h"
#include "i2c.h"

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

/* We want to ensure the real-time performace, so the i2c timeout here is
 * relatively short */
#define I2C_TIMEOUT_US (1000)

#ifndef BIT
    #define BIT(n) ((uint32_t)1 << (n))
#endif /* BIT */

struct ar1002_i2c_bus {
    struct rt_i2c_bus      parent;
    ENUM_HAL_I2C_COMPONENT I2C;
};

static void put_reg32_mask(uint32_t regAddr, uint32_t regData, uint32_t regDataMask)
{
    uint32_t u32_regDataTmp;

    u32_regDataTmp = *((volatile uint32_t*)regAddr);
    u32_regDataTmp &= ~regDataMask;
    u32_regDataTmp |= regData & regDataMask;

    *((volatile uint32_t*)regAddr) = u32_regDataTmp;
}

extern void cf_delay_ms(uint32_t num);

// i2c2  prevent lock fucntion
static void reset_i2c2(void)
{
    uint8_t i = 0;

    for (i = 0; i < 10; i++) {
        HAL_GPIO_OutPut(120); // fix the i2c 2  lock bug
        HAL_GPIO_SetPin(120, HAL_GPIO_PIN_RESET);
        cf_delay_ms(10);
        put_reg32_mask(SFR_PAD_CTRL7_REG, 0, BIT(14) | BIT(15) | BIT(16) | BIT(17));
        cf_delay_ms(10);
    }

    HAL_GPIO_OutPut(119); // fix the i2c 2  lock bug
    HAL_GPIO_SetPin(119, HAL_GPIO_PIN_RESET);
    cf_delay_ms(10);
    HAL_GPIO_OutPut(120); // fix the i2c 2  lock bug
    HAL_GPIO_SetPin(120, HAL_GPIO_PIN_RESET);
    cf_delay_ms(10);

    put_reg32_mask(SFR_PAD_CTRL7_REG, 0, BIT(16) | BIT(17));
    cf_delay_ms(10);

    put_reg32_mask(SFR_PAD_CTRL7_REG, 0, BIT(14) | BIT(15));
    cf_delay_ms(10);
}

static rt_size_t i2c_master_transfer(struct rt_i2c_bus* bus, rt_uint16_t slave_addr, struct rt_i2c_msg msgs[], rt_uint32_t num)
{

    uint32_t               msg_idx    = 0;
    struct ar1002_i2c_bus* ar1002_i2c = (struct ar1002_i2c_bus*)bus;

    // console_println("bus = %d slave_addr = %04x  num = %d \r\n", ar1002_i2c->I2C, slave_addr, num);

    if (num == 1) {
        struct rt_i2c_msg* msg;
        msg = &msgs[0];

        if (msg->flags & RT_I2C_RD) {
            console_println("error---------(msg->flags & RT_I2C_RD) 1 \r\n");
        } else {
            // only support msg = 1 just for now
            HAL_RET_T ret = HAL_I2C_MasterWriteData(ar1002_i2c->I2C,
                                                    slave_addr >> 1,
                                                    msg->buf,
                                                    msg->len,
                                                    I2C_TIMEOUT_US);
            if (ret != HAL_OK) {
                console_println("1 ret = %d  \r\n", ret);
            }
        }
        msg_idx = 1;
    } else if (num == 2) {
        struct rt_i2c_msg* msg0;
        struct rt_i2c_msg* msg1;
        msg0 = &msgs[0];
        msg1 = &msgs[1];

        if (!(msg0->flags & RT_I2C_RD) && (msg1->flags & RT_I2C_RD)) {

            HAL_RET_T ret = HAL_I2C_MasterReadData(ar1002_i2c->I2C,
                                                   slave_addr >> 1,
                                                   msg0->buf,
                                                   msg0->len,
                                                   msg1->buf,
                                                   msg1->len,
                                                   I2C_TIMEOUT_US);

            if (ret != HAL_OK) {
                console_println("2 ret = %d  \r\n", ret);
            }
        }
        msg_idx = 2;
    } else {
        console_println("bus = %d slave_addr = %04x  num = %d \r\n", ar1002_i2c->I2C, slave_addr, num);
        msg_idx = 0;
    }

    return msg_idx;
}

static const struct rt_i2c_bus_device_ops i2c_bus_ops = {
    i2c_master_transfer,
    RT_NULL,
    RT_NULL
};

// /* i2c bus instances */
// static struct ar1002_i2c_bus ar1002_i2c0 = {
//     .parent.ops = &i2c_bus_ops,
//     .I2C = HAL_I2C_COMPONENT_0
// };

// static struct ar1002_i2c_bus ar1002_i2c1 = {
//     .parent.ops = &i2c_bus_ops,
//     .I2C = HAL_I2C_COMPONENT_1
// };

static struct ar1002_i2c_bus ar1002_i2c2 = {
    .parent.ops = &i2c_bus_ops,
    .I2C        = HAL_I2C_COMPONENT_2
};

static struct ar1002_i2c_bus ar1002_i2c3 = {
    .parent.ops = &i2c_bus_ops,
    .I2C        = HAL_I2C_COMPONENT_3
};

// static struct rt_i2c_device i2c2_dev1 = {
//     .slave_addr = IST8310_ADDRESS, /* 7 bit address */
//     .flags = 0
// };

static struct rt_i2c_device i2c2_dev2 = {
    .slave_addr = MMC5983_7BITI2C_ADDRESS, /* 7 bit address */
    .flags      = 0
};

static struct rt_i2c_device i2c3_dev1 = {
    .slave_addr = AW2023_ADDRESS, /* 7 bit address */
    .flags      = 0
};

static struct rt_i2c_device i2c3_dev2 = {
    .slave_addr = IST8310_ADDRESS, /* 7 bit address */
    .flags      = 0
};

rt_err_t drv_i2c_init(void)
{
    /* i2c low-level initialization */

    reset_i2c2();
    // HAL_I2C_MasterInit( ar1002_i2c2.I2C, i2c2_dev1.slave_addr, HAL_I2C_FAST_SPEED);
    HAL_I2C_MasterInit(ar1002_i2c2.I2C, i2c2_dev2.slave_addr, HAL_I2C_FAST_SPEED);
    HAL_I2C_MasterInit(ar1002_i2c3.I2C, i2c3_dev1.slave_addr, HAL_I2C_FAST_SPEED);

    /* register i2c bus */
    // RT_TRY(rt_i2c_bus_device_register(&ar1002_i2c1.parent, "i2c1"));
    RT_TRY(rt_i2c_bus_device_register(&ar1002_i2c2.parent, "i2c2"));
    RT_TRY(rt_i2c_bus_device_register(&ar1002_i2c3.parent, "i2c3"));

    /* attach i2c devices */
    // RT_TRY(rt_i2c_bus_attach_device(&i2c2_dev1, "i2c2_dev1", "i2c2", RT_NULL));
    RT_TRY(rt_i2c_bus_attach_device(&i2c2_dev2, "i2c2_dev2", "i2c2", RT_NULL));
    // RT_TRY(rt_i2c_bus_attach_device(&i2c3_dev1, "i2c3_dev1", "i2c3", RT_NULL));
    RT_TRY(rt_i2c_bus_attach_device(&i2c3_dev1, "i2c3_dev1", "i2c3", RT_NULL));
    RT_TRY(rt_i2c_bus_attach_device(&i2c3_dev2, "i2c3_dev2", "i2c3", RT_NULL));

    return RT_EOK;
}
