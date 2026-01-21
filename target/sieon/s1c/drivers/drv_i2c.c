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
// #define I2C_TIMEOUT_US    (10000)
#define DRV_I2C_TIMEOUT (0x40000UL)
// #define DRV_I2C_TIMEOUT   (0x4000000UL)

// #define EXAMPLE_PERIPH_WE (LL_PERIPH_GPIO | LL_PERIPH_EFM | LL_PERIPH_FCG | LL_PERIPH_PWC_CLK_RMU | LL_PERIPH_SRAM)
// #define EXAMPLE_PERIPH_WP (LL_PERIPH_EFM | LL_PERIPH_FCG | LL_PERIPH_SRAM)
// #define EXAMPLE_PERIPH_WE (LL_PERIPH_GPIO | LL_PERIPH_EFM | LL_PERIPH_FCG | LL_PERIPH_PWC_CLK_RMU | LL_PERIPH_SRAM)

// #define I2C_UNIT          (CM_I2C1)
// #define I2C_FCG_USE       (FCG1_PERIPH_I2C1)
// #define I2C_BAUDRATE      (400000UL)

// /* Define port and pin for SDA and SCL */
// #define I2C_SCL_PORT      (GPIO_PORT_E)
// #define I2C_SCL_PIN       (GPIO_PIN_12)
// #define I2C_SDA_PORT      (GPIO_PORT_E)
// #define I2C_SDA_PIN       (GPIO_PIN_13)
// #define I2C_GPIO_SCL_FUNC (GPIO_FUNC_49)
// #define I2C_GPIO_SDA_FUNC (GPIO_FUNC_48)

struct hc32_i2c_bus {
    struct rt_i2c_bus parent;
    CM_I2C_TypeDef* i2c_periph;
};

static int32_t drv_i2c_trans_addr(CM_I2C_TypeDef *I2Cx, uint16_t u16Addr, uint8_t u8Dir, uint32_t u32Timeout)
{
    int32_t i32Ret;

    DDL_ASSERT(IS_I2C_UNIT(I2Cx));
    DDL_ASSERT(IS_I2C_TRANS_DIR(u8Dir));
    DDL_ASSERT(IS_I2C_7BIT_ADDR(u16Addr));

    i32Ret = I2C_WaitStatus(I2Cx, I2C_FLAG_TX_EMPTY, SET, u32Timeout);

    if (LL_OK == i32Ret) {
        /* Send I2C address */
        I2C_WriteData(I2Cx, (uint8_t)u16Addr | u8Dir);

        if (I2C_DIR_TX == u8Dir) {
            /* If in master transfer process, Need wait transfer end */
            i32Ret = I2C_WaitStatus(I2Cx, I2C_FLAG_TX_CPLT, SET, u32Timeout);
        } else {
            /* If in master receive process, wait I2C_FLAG_TRA changed to receive */
            i32Ret = I2C_WaitStatus(I2Cx, I2C_FLAG_TRA, RESET, u32Timeout);
        }

        if (i32Ret == LL_OK) {
            if (I2C_GetStatus(I2Cx, I2C_FLAG_NACKF) == SET) {
                i32Ret = LL_ERR;
            }
        }
    }

    return i32Ret;
}

static int32_t drv_i2c_master_receive(CM_I2C_TypeDef* i2c, uint16_t u16DevAddr, uint8_t au8Data[], uint32_t u32Size, uint32_t u32Timeout)
{
    int32_t i32Ret;

    I2C_Cmd(i2c, ENABLE);
    I2C_SWResetCmd(i2c, ENABLE);
    I2C_SWResetCmd(i2c, DISABLE);
    i32Ret = I2C_Start(i2c, u32Timeout);
    if (LL_OK == i32Ret) {
        if (1UL == u32Size) {
            I2C_AckConfig(i2c, I2C_NACK);
        }

        i32Ret = drv_i2c_trans_addr(i2c, u16DevAddr, I2C_DIR_RX, u32Timeout);

        if (LL_OK == i32Ret) {
            i32Ret = I2C_MasterReceiveDataAndStop(i2c, au8Data, u32Size, u32Timeout);
        }

        I2C_AckConfig(i2c, I2C_ACK);
    }

    if (LL_OK != i32Ret) {
        (void)I2C_Stop(i2c, u32Timeout);
    }
    I2C_Cmd(i2c, DISABLE);

    return i32Ret;
}
static int32_t drv_i2c_master_transmit(CM_I2C_TypeDef* i2c, uint16_t u16DevAddr, const uint8_t au8Data[], uint32_t u32Size, uint32_t u32Timeout)
{
    int32_t i32Ret;
    I2C_Cmd(i2c, ENABLE);

    I2C_SWResetCmd(i2c, ENABLE);
    I2C_SWResetCmd(i2c, DISABLE);
    i32Ret = I2C_Start(i2c, u32Timeout);
    if (LL_OK == i32Ret) {
        i32Ret = drv_i2c_trans_addr(i2c, u16DevAddr, I2C_DIR_TX, u32Timeout);
        if (LL_OK == i32Ret) {
            i32Ret = I2C_TransData(i2c, au8Data, u32Size, u32Timeout);
        }
    }

    (void)I2C_Stop(i2c, u32Timeout);
    I2C_Cmd(i2c, DISABLE);

    return i32Ret;
}

static rt_size_t i2c_master_transfer(struct rt_i2c_bus* bus, rt_uint16_t slave_addr, struct rt_i2c_msg msgs[], rt_uint32_t num)
{
    struct rt_i2c_msg* msg;
    uint32_t msg_idx = 0;
    struct hc32_i2c_bus* hc32_i2c = (struct hc32_i2c_bus*)bus;

    for (msg_idx = 0; msg_idx < num; msg_idx++) {
        msg = &msgs[msg_idx];

        if (msg->flags & RT_I2C_RD) {
            if (drv_i2c_master_receive(hc32_i2c->i2c_periph, slave_addr, msg->buf, msg->len, DRV_I2C_TIMEOUT) != LL_OK) {
                break;
            }
        } else {
            if (drv_i2c_master_transmit(hc32_i2c->i2c_periph, slave_addr, msg->buf, msg->len, DRV_I2C_TIMEOUT) != LL_OK) {
                break;
            }
        }
    }

    return msg_idx;
}

static int32_t Master_Initialize(void)
{
    int32_t i32Ret;
    stc_i2c_init_t stcI2cInit;
    float32_t fErr;

    (void)I2C_DeInit(CM_I2C1);

    (void)I2C_StructInit(&stcI2cInit);
    stcI2cInit.u32ClockDiv = I2C_CLK_DIV4;
    stcI2cInit.u32Baudrate = 400000UL;
    stcI2cInit.u32SclTime = 3UL;
    // stcI2cInit.u32Baudrate = 100000UL; // 设置波特率为 100kHz
    // stcI2cInit.u32ClockDiv = I2C_CLK_DIV16;
    // stcI2cInit.u32SclTime = 0U;
    i32Ret = I2C_Init(CM_I2C1, &stcI2cInit, &fErr);

    I2C_BusWaitCmd(CM_I2C1, ENABLE);

    return i32Ret;
}
// static uint8_t u8TxBuf[256U];
rt_err_t i2c1_hw_init(void)
{
    // /* Unlock peripherals or registers */
    // LL_PERIPH_WE(EXAMPLE_PERIPH_WE);

    // stc_gpio_init_t stcGpioInit;
    // GPIO_StructInit(&stcGpioInit);
    // stcGpioInit.u16PinDrv = PIN_HIGH_DRV;
    // stcGpioInit.u16PinInputType = PIN_IN_TYPE_CMOS;
    // GPIO_Init(GPIO_PORT_B, GPIO_PIN_08, &stcGpioInit);
    // GPIO_Init(GPIO_PORT_B, GPIO_PIN_09, &stcGpioInit);
    /* Initialize I2C port*/
    GPIO_SetFunc(GPIO_PORT_B, GPIO_PIN_08, GPIO_FUNC_51); // I2C1-SCL
    GPIO_SetFunc(GPIO_PORT_B, GPIO_PIN_09, GPIO_FUNC_50); // I2C1-SDA

    /* Enable I2C Peripheral*/
    FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_I2C1, ENABLE);

    /* Initialize I2C peripheral and enable function*/
    if (LL_OK != Master_Initialize()) {
        /* Initialize error*/
        return RT_ERROR;
    }

    return RT_EOK;
}

static const struct rt_i2c_bus_device_ops i2c_bus_ops = {
    .master_xfer = i2c_master_transfer,
    .slave_xfer = RT_NULL,
    .i2c_bus_control = RT_NULL
};

/* i2c bus instances */
static struct hc32_i2c_bus hc32_i2c1 = {
    .parent.ops = &i2c_bus_ops,
    .i2c_periph = CM_I2C1
};

/* i2c device instances */
static struct rt_i2c_device i2c1_dev0 = {
    .slave_addr = 0x2C, /* QMC5883P 7 bit address */
    .flags = 0
};

static struct rt_i2c_device i2c1_dev1 = {
    .slave_addr = 0x6D, /* XGZP6816D 7 bit address */
    .flags = 0
};

rt_err_t drv_i2c_init(void)
{
    /* i2c low-level initialization */
    RT_TRY(i2c1_hw_init());

    /* register i2c bus */
    RT_TRY(rt_i2c_bus_device_register(&hc32_i2c1.parent, "i2c1"));

    /* attach i2c devices */
    RT_TRY(rt_i2c_bus_attach_device(&i2c1_dev0, "i2c1_dev0", "i2c1", RT_NULL));
    RT_TRY(rt_i2c_bus_attach_device(&i2c1_dev1, "i2c1_dev1", "i2c1", RT_NULL));

    return RT_EOK;
}
