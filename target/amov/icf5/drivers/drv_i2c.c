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

// #define DRV_DBG(...) printf(__VA_ARGS__)
#define DRV_DBG(...)

/* We want to ensure the real-time performace, so the i2c timeout here is
 * relatively short */
#define I2C_TIMEOUT_US (10000)

struct gd32_i2c_bus {
    struct rt_i2c_bus parent;
    uint32_t i2c_periph;
};

static void i2c_hw_init(void)
{
    /* I2C0 Configuration */

    /* enable clock */
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_I2C0);

    /* connect PB8 to I2C0_SCL */
    gpio_af_set(GPIOB, GPIO_AF_4, GPIO_PIN_8);
    /* connect PB9 to I2C0_SDA */
    gpio_af_set(GPIOB, GPIO_AF_4, GPIO_PIN_9);

    /* configure I2C0 GPIO. SCL/SDA have external pull-up */
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_8);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_9);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, GPIO_PIN_9);

    /* configure I2C clock */
    i2c_clock_config(I2C0, 400000, I2C_DTCY_2);
    /* configure I2C address */
    i2c_mode_addr_config(I2C0, I2C_I2CMODE_ENABLE, I2C_ADDFORMAT_7BITS, 0x00);
    /* enable I2C0 */
    i2c_enable(I2C0);
    /* enable acknowledge */
    i2c_ack_config(I2C0, I2C_ACK_ENABLE);
}

static fmt_err_t wait_flag_until_timeout(uint32_t i2c_periph, i2c_flag_enum flag, FlagStatus status, uint64_t timeout_us)
{
    uint64_t time_start = systime_now_us();

    while (i2c_flag_get(i2c_periph, flag) == status) {
        if ((systime_now_us() - time_start) >= timeout_us) {
            return FMT_ETIMEOUT;
        }
    }
    return FMT_EOK;
}

static rt_err_t i2c_handle_transfer(uint32_t i2c_periph, rt_uint16_t slave_addr, bool addr_10bit, bool disable_ack, uint32_t trandirection)
{
    uint8_t slave10_first_byte, slave10_second_byte;

    /* start/restart read operation */
    i2c_start_on_bus(i2c_periph);
    /* wait until SBSEND bit is set */
    if (wait_flag_until_timeout(i2c_periph, I2C_FLAG_SBSEND, RESET, I2C_TIMEOUT_US) != FMT_EOK) {
        DRV_DBG("I2C wait SBSEND timeout\n");
        return RT_ERROR;
    }

    if (addr_10bit) {
        slave10_first_byte = (0xF0) | (uint8_t)((slave_addr & 0x0300) >> 7);
        /* send slave address first byte to I2C bus */
        i2c_master_addressing(i2c_periph, slave10_first_byte, I2C_TRANSMITTER);
        /* wait until ADD10SEND bit is set */
        if (wait_flag_until_timeout(i2c_periph, I2C_FLAG_ADD10SEND, RESET, I2C_TIMEOUT_US) != FMT_EOK) {
            DRV_DBG("I2C wait ADD10SEND timeout\n");
            return RT_ERROR;
        }
        /* the second byte contains the remaining 8 bits of the 10-bit address */
        slave10_second_byte = (uint8_t)(slave_addr & 0x00FF);
        /* send slave address 2nd byte to I2C bus */
        i2c_master_addressing(i2c_periph, slave10_second_byte, I2C_TRANSMITTER);
        /* wait until ADDSEND bit is set */
        if (wait_flag_until_timeout(i2c_periph, I2C_FLAG_ADDSEND, RESET, I2C_TIMEOUT_US) != FMT_EOK) {
            DRV_DBG("I2C wait ADDSEND timeout\n");
            return RT_ERROR;
        }

        if (disable_ack) {
            /* N=1,reset ACKEN bit before clearing ADDRSEND bit */
            i2c_ack_config(i2c_periph, I2C_ACK_DISABLE);
        }
        /* clear ADDSEND bit */
        i2c_flag_clear(i2c_periph, I2C_FLAG_ADDSEND);

        /* only 10bit receive need this, see gd32 datasheet */
        if (trandirection == I2C_RECEIVER) {
            /* send a start condition to I2C bus */
            i2c_start_on_bus(i2c_periph);
            /* wait until SBSEND bit is set */
            if (wait_flag_until_timeout(i2c_periph, I2C_FLAG_SBSEND, RESET, I2C_TIMEOUT_US) != FMT_EOK) {
                DRV_DBG("I2C wait SBSEND timeout\n");
                return RT_ERROR;
            }
            /* send slave address first byte to I2C bus */
            i2c_master_addressing(i2c_periph, slave10_first_byte, trandirection);
        }
    } else {
        /* send slave address to I2C bus */
        i2c_master_addressing(i2c_periph, slave_addr, trandirection);
    }

    /* wait until ADDSEND bit is set */
    if (wait_flag_until_timeout(i2c_periph, I2C_FLAG_ADDSEND, RESET, I2C_TIMEOUT_US) != FMT_EOK) {
        DRV_DBG("I2C wait ADDSEND timeout\n");
        return RT_ERROR;
    }

    /* clear ADDSEND bit */
    i2c_flag_clear(i2c_periph, I2C_FLAG_ADDSEND);

    return RT_EOK;
}

static rt_size_t i2c_master_transfer(struct rt_i2c_bus* bus, rt_uint16_t slave_addr, struct rt_i2c_msg msgs[], rt_uint32_t num)
{
    struct rt_i2c_msg* msg;
    uint32_t msg_idx = 0;
    struct gd32_i2c_bus* gd32_i2c = (struct gd32_i2c_bus*)bus;
    uint64_t start_us;

    if (wait_flag_until_timeout(gd32_i2c->i2c_periph, I2C_FLAG_I2CBSY, SET, I2C_TIMEOUT_US) != FMT_EOK) {
        DRV_DBG("I2C wait BUSY timeout\n");
        goto _stop;
    }

    for (msg_idx = 0; msg_idx < num; msg_idx++) {
        msg = &msgs[msg_idx];
        uint16_t nbytes = msg->len;

        if (msg->flags & RT_I2C_RD) {
            /* start/restart read operation */
            i2c_handle_transfer(gd32_i2c->i2c_periph, slave_addr, (msg->flags & RT_I2C_ADDR_10BIT) != 0, nbytes == 1, I2C_RECEIVER);

            while (nbytes--) {
                if (nbytes == 0) {
                    /* send a NACK for the last data byte, this should be done before last byte is received */
                    i2c_ack_config(gd32_i2c->i2c_periph, I2C_ACK_DISABLE);
                }
                /* wait data received */
                if (wait_flag_until_timeout(gd32_i2c->i2c_periph, I2C_FLAG_RBNE, RESET, I2C_TIMEOUT_US) != FMT_EOK) {
                    DRV_DBG("I2C wait RBNE timeout\n");
                    goto _stop;
                }
                /* receive data */
                *(msg->buf++) = i2c_data_receive(gd32_i2c->i2c_periph);
            }
        } else {
            /* start/restart write operation */
            i2c_handle_transfer(gd32_i2c->i2c_periph, slave_addr, (msg->flags & RT_I2C_ADDR_10BIT) != 0, false, I2C_TRANSMITTER);

            while (nbytes--) {
                if (wait_flag_until_timeout(gd32_i2c->i2c_periph, I2C_FLAG_TBE, RESET, I2C_TIMEOUT_US) != FMT_EOK) {
                    DRV_DBG("I2C wait TBE timeout\n");
                    goto _stop;
                }

                /* transmit data */
                i2c_data_transmit(gd32_i2c->i2c_periph, *(msg->buf++));
            }

            /* wait transmit complete */
            if (wait_flag_until_timeout(gd32_i2c->i2c_periph, I2C_FLAG_BTC, RESET, I2C_TIMEOUT_US) != FMT_EOK) {
                DRV_DBG("I2C wait BTC timeout\n");
                goto _stop;
            }
        }
    }

_stop:
    /* send a stop condition to I2C bus */
    i2c_stop_on_bus(gd32_i2c->i2c_periph);

    /* wait until stop flag is set */
    start_us = systime_now_us();
    while (I2C_CTL0(gd32_i2c->i2c_periph) & I2C_CTL0_STOP) {
        if ((systime_now_us() - start_us) >= I2C_TIMEOUT_US) {
            DRV_DBG("I2C wait stop timeout\n");
            break;
        }
    }

    i2c_ack_config(gd32_i2c->i2c_periph, I2C_ACK_ENABLE);

    return msg_idx;
}

static const struct rt_i2c_bus_device_ops i2c_bus_ops = {
    i2c_master_transfer,
    RT_NULL,
    RT_NULL
};

/* i2c bus instances */
static struct gd32_i2c_bus gd32_i2c0 = {
    .parent.ops = &i2c_bus_ops,
    .i2c_periph = I2C0
};

/* i2c device instances */
static struct rt_i2c_device i2c0_dev0 = {
    .slave_addr = 0x45, /* AW2023 7 bit address */
    .flags = 0
};

static struct rt_i2c_device i2c0_dev1 = {
    .slave_addr = 0x28, /* MS4525 7 bit address */
    .flags = 0
};

rt_err_t drv_i2c_init(void)
{
    /* i2c low-level initialization */
    i2c_hw_init();

    /* register i2c bus */
    RT_TRY(rt_i2c_bus_device_register(&gd32_i2c0.parent, "i2c0"));

    /* attach i2c devices */
    RT_TRY(rt_i2c_bus_attach_device(&i2c0_dev0, "i2c0_dev0", "i2c0", RT_NULL));

    /* attach i2c devices */
    RT_TRY(rt_i2c_bus_attach_device(&i2c0_dev1, "i2c0_dev1", "i2c0", RT_NULL));

    return RT_EOK;
}
