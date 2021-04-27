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
#include "hal/i2c.h"
#include "stm32f7xx_ll_i2c.h"

#define I2C_TIMEOUT_US (500)

struct stm32_i2c_bus {
    struct rt_i2c_bus parent;
    I2C_TypeDef* I2C;
};

static void i2c1_hw_init(void)
{
    LL_I2C_InitTypeDef I2C_InitStruct = { 0 };

    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    /**I2C1 GPIO Configuration
  PB8   ------> I2C1_SCL
  PB9   ------> I2C1_SDA
  */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C1);

    /** I2C Initialization
  */
    LL_I2C_EnableAutoEndMode(I2C1);
    LL_I2C_SetOwnAddress2(I2C1, 0, LL_I2C_OWNADDRESS2_NOMASK);
    LL_I2C_DisableOwnAddress2(I2C1);
    LL_I2C_DisableGeneralCall(I2C1);
    LL_I2C_EnableClockStretching(I2C1);
    I2C_InitStruct.PeripheralMode = LL_I2C_MODE_I2C;
    I2C_InitStruct.Timing = 0x6000030D;
    I2C_InitStruct.AnalogFilter = LL_I2C_ANALOGFILTER_ENABLE;
    I2C_InitStruct.DigitalFilter = 0;
    I2C_InitStruct.OwnAddress1 = 0;
    I2C_InitStruct.TypeAcknowledge = LL_I2C_ACK;
    I2C_InitStruct.OwnAddrSize = LL_I2C_OWNADDRESS1_7BIT;
    LL_I2C_Init(I2C1, &I2C_InitStruct);
}

static void i2c2_hw_init(void)
{
    LL_I2C_InitTypeDef I2C_InitStruct = { 0 };

    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
    /**I2C2 GPIO Configuration
  PF0   ------> I2C2_SDA
  PF1   ------> I2C2_SCL
  */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C2);

    /** I2C Initialization
  */
    LL_I2C_EnableAutoEndMode(I2C2);
    LL_I2C_SetOwnAddress2(I2C2, 0, LL_I2C_OWNADDRESS2_NOMASK);
    LL_I2C_DisableOwnAddress2(I2C2);
    LL_I2C_DisableGeneralCall(I2C2);
    LL_I2C_EnableClockStretching(I2C2);
    I2C_InitStruct.PeripheralMode = LL_I2C_MODE_I2C;
    I2C_InitStruct.Timing = 0x6000030D;
    I2C_InitStruct.AnalogFilter = LL_I2C_ANALOGFILTER_ENABLE;
    I2C_InitStruct.DigitalFilter = 0;
    I2C_InitStruct.OwnAddress1 = 0;
    I2C_InitStruct.TypeAcknowledge = LL_I2C_ACK;
    I2C_InitStruct.OwnAddrSize = LL_I2C_OWNADDRESS1_7BIT;
    LL_I2C_Init(I2C2, &I2C_InitStruct);
}

static void i2c3_hw_init(void)
{
    LL_I2C_InitTypeDef I2C_InitStruct = { 0 };

    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
    /**I2C3 GPIO Configuration
  PH8   ------> I2C3_SDA
  PH7   ------> I2C3_SCL
  */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C3);

    /** I2C Initialization
  */
    LL_I2C_EnableAutoEndMode(I2C3);
    LL_I2C_SetOwnAddress2(I2C3, 0, LL_I2C_OWNADDRESS2_NOMASK);
    LL_I2C_DisableOwnAddress2(I2C3);
    LL_I2C_DisableGeneralCall(I2C3);
    LL_I2C_EnableClockStretching(I2C3);
    I2C_InitStruct.PeripheralMode = LL_I2C_MODE_I2C;
    I2C_InitStruct.Timing = 0x6000030D;
    I2C_InitStruct.AnalogFilter = LL_I2C_ANALOGFILTER_ENABLE;
    I2C_InitStruct.DigitalFilter = 0;
    I2C_InitStruct.OwnAddress1 = 0;
    I2C_InitStruct.TypeAcknowledge = LL_I2C_ACK;
    I2C_InitStruct.OwnAddrSize = LL_I2C_OWNADDRESS1_7BIT;
    LL_I2C_Init(I2C3, &I2C_InitStruct);
}

static void i2c4_hw_init(void)
{
    LL_I2C_InitTypeDef I2C_InitStruct = { 0 };

    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
    /**I2C4 GPIO Configuration
  PF15   ------> I2C4_SDA
  PF14   ------> I2C4_SCL
  */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C4);

    /** I2C Initialization
  */
    LL_I2C_EnableAutoEndMode(I2C4);
    LL_I2C_SetOwnAddress2(I2C4, 0, LL_I2C_OWNADDRESS2_NOMASK);
    LL_I2C_DisableOwnAddress2(I2C4);
    LL_I2C_DisableGeneralCall(I2C4);
    LL_I2C_EnableClockStretching(I2C4);
    I2C_InitStruct.PeripheralMode = LL_I2C_MODE_I2C;
    I2C_InitStruct.Timing = 0x6000030D;
    I2C_InitStruct.AnalogFilter = LL_I2C_ANALOGFILTER_ENABLE;
    I2C_InitStruct.DigitalFilter = 0;
    I2C_InitStruct.OwnAddress1 = 0;
    I2C_InitStruct.TypeAcknowledge = LL_I2C_ACK;
    I2C_InitStruct.OwnAddrSize = LL_I2C_OWNADDRESS1_7BIT;
    LL_I2C_Init(I2C4, &I2C_InitStruct);
}

static rt_size_t i2c_master_transfer(struct rt_i2c_bus* bus, rt_uint16_t slave_addr, struct rt_i2c_msg msgs[], rt_uint32_t num)
{
    struct rt_i2c_msg* msg;
    uint32_t msg_idx;
    struct stm32_i2c_bus* stm32_i2c = (struct stm32_i2c_bus*)bus;

    /* wait until bus is free */
    WAIT_TIMEOUT(LL_I2C_IsActiveFlag_BUSY(stm32_i2c->I2C), I2C_TIMEOUT_US, return 0;);
    /* clear stop flag */
    LL_I2C_ClearFlag_STOP(stm32_i2c->I2C);
    LL_I2C_ClearFlag_NACK(stm32_i2c->I2C);

    for (msg_idx = 0; msg_idx < num; msg_idx++) {
        msg = &msgs[msg_idx];
        uint16_t nbytes = msg->len;

        /* TODO: add support for 10bit addr */
        RT_ASSERT(!(msg->flags & RT_I2C_ADDR_10BIT));

        if (msg->flags & RT_I2C_RD) {
            /* start/restart read operation */
            LL_I2C_HandleTransfer(stm32_i2c->I2C, slave_addr, LL_I2C_ADDRESSING_MODE_7BIT, msg->len,
                LL_I2C_MODE_SOFTEND, LL_I2C_GENERATE_START_READ);

            while (nbytes--) {
                if (LL_I2C_IsActiveFlag_STOP(stm32_i2c->I2C)) {
                    return msg_idx;
                }
                /* wait data received */
                WAIT_TIMEOUT(!LL_I2C_IsActiveFlag_RXNE(stm32_i2c->I2C), I2C_TIMEOUT_US, return msg_idx;);
                /* receive data */
                *(msg->buf++) = LL_I2C_ReceiveData8(stm32_i2c->I2C);
            }
        } else {
            /* start/restart write operation */
            LL_I2C_HandleTransfer(stm32_i2c->I2C, slave_addr, LL_I2C_ADDRESSING_MODE_7BIT, msg->len,
                LL_I2C_MODE_SOFTEND, LL_I2C_GENERATE_START_WRITE);

            while (nbytes--) {
                if (LL_I2C_IsActiveFlag_STOP(stm32_i2c->I2C)) {
                    return msg_idx;
                }
                /* transmit data */
                LL_I2C_TransmitData8(stm32_i2c->I2C, *(msg->buf++));
                /* wait write complete */
                WAIT_TIMEOUT(!LL_I2C_IsActiveFlag_TXE(stm32_i2c->I2C), I2C_TIMEOUT_US, return msg_idx;);
            }
        }
    }

    /* generate stop condition, NACK is automatically generated before stop */
    LL_I2C_HandleTransfer(stm32_i2c->I2C, slave_addr, LL_I2C_ADDRESSING_MODE_7BIT, 0,
        LL_I2C_MODE_SOFTEND, LL_I2C_GENERATE_STOP);

    return num;
}

static const struct rt_i2c_bus_device_ops i2c_bus_ops = {
    i2c_master_transfer,
    RT_NULL,
    RT_NULL
};

/* i2c bus instances */
static struct stm32_i2c_bus stm32_i2c1 = {
    .parent.ops = &i2c_bus_ops,
    .I2C = I2C1
};

static struct stm32_i2c_bus stm32_i2c2 = {
    .parent.ops = &i2c_bus_ops,
    .I2C = I2C2
};

static struct stm32_i2c_bus stm32_i2c3 = {
    .parent.ops = &i2c_bus_ops,
    .I2C = I2C3
};

static struct stm32_i2c_bus stm32_i2c4 = {
    .parent.ops = &i2c_bus_ops,
    .I2C = I2C4
};

/* i2c device instances */
static struct rt_i2c_device i2c1_dev1 = {
    .slave_addr = IST8310_ADDRESS, /* 7 bit address */
    .flags = 0
};

static struct rt_i2c_device i2c1_dev2 = {
    .slave_addr = NCP5623C_ADDRESS, /* 7 bit address */
    .flags = 0
};

rt_err_t drv_i2c_init(void)
{
    /* i2c low-level initialization */
    i2c1_hw_init();
    i2c2_hw_init();
    i2c3_hw_init();
    i2c4_hw_init();

    /* register i2c bus */
    RT_CHECK_RETURN(rt_i2c_bus_device_register(&stm32_i2c1.parent, "i2c1"));
    RT_CHECK_RETURN(rt_i2c_bus_device_register(&stm32_i2c2.parent, "i2c2"));
    RT_CHECK_RETURN(rt_i2c_bus_device_register(&stm32_i2c3.parent, "i2c3"));
    RT_CHECK_RETURN(rt_i2c_bus_device_register(&stm32_i2c4.parent, "i2c4"));

    /* attach i2c devices */
    RT_CHECK_RETURN(rt_i2c_bus_attach_device(&i2c1_dev1, "i2c1_dev1", "i2c1", RT_NULL));
    RT_CHECK_RETURN(rt_i2c_bus_attach_device(&i2c1_dev2, "i2c1_dev2", "i2c1", RT_NULL));

    return RT_EOK;
}
