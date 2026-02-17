/****************************************************************************
 * Temporary software (bit-bang) I2C fallback for FMU-V6C
 *
 * WARNING: This is a temporary fallback implementation used while the
 * hardware I2C controller is being diagnosed. It is blocking, uses
 * busy-wait delays, and is NOT optimized for production use. Replace with
 * the hardware I2C driver and remove this file once hardware I2C is fixed.
 *****************************************************************************/
#include "drv_i2c.h"
#include "hal/i2c/i2c.h"
#include "board.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_bus.h"
#include "module/system/systime.h"
#include "stm32h7xx.h"
#include <rtthread.h>
#include <string.h>
#include <stddef.h>

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

/* Software I2C timing (half-period in microseconds). Increase for slower SCL.
 * Raised from 5us to 20us to improve ACK reliability on slower or weakly
 * pulled-up buses. */
#ifndef SCL_DELAY_US
#define SCL_DELAY_US 20
#endif

/* Define software I2C pins used for the soft buses. Adjust as needed. */
// Bus 1 uses PB7 = SDA, PB8 = SCL (same as hardware mapping)
#define SOFT_I2C1_SDA_PORT GPIOB
#define SOFT_I2C1_SDA_PIN LL_GPIO_PIN_7
#define SOFT_I2C1_SCL_PORT GPIOB
#define SOFT_I2C1_SCL_PIN LL_GPIO_PIN_8

// Bus 2 uses PB11 = SDA, PB10 = SCL (I2C2 mapping on FMU-V6C)
#define SOFT_I2C2_SDA_PORT GPIOB
#define SOFT_I2C2_SDA_PIN LL_GPIO_PIN_11
#define SOFT_I2C2_SCL_PORT GPIOB
#define SOFT_I2C2_SCL_PIN LL_GPIO_PIN_10

// Bus 4 uses PD13 = SDA, PD12 = SCL (I2C4 mapping on FMU-V6C)
#define SOFT_I2C4_SDA_PORT GPIOD
#define SOFT_I2C4_SDA_PIN LL_GPIO_PIN_13
#define SOFT_I2C4_SCL_PORT GPIOD
#define SOFT_I2C4_SCL_PIN LL_GPIO_PIN_12

static void gpio_set_od_output(GPIO_TypeDef* port, uint32_t pin)
{
    LL_GPIO_SetPinMode(port, pin, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinSpeed(port, pin, LL_GPIO_SPEED_FREQ_LOW);
    LL_GPIO_SetPinOutputType(port, pin, LL_GPIO_OUTPUT_OPENDRAIN);
    LL_GPIO_SetPinPull(port, pin, LL_GPIO_PULL_NO);
}

static void gpio_set_input(GPIO_TypeDef* port, uint32_t pin)
{
    LL_GPIO_SetPinMode(port, pin, LL_GPIO_MODE_INPUT);
    LL_GPIO_SetPinPull(port, pin, LL_GPIO_PULL_NO);
}

/* fast pin ops using BSRR/IDR to avoid LL call overhead */
#define SET_PIN(port, pin)    ((port)->BSRR = (pin))
#define CLEAR_PIN(port, pin)  ((port)->BSRR = ((uint32_t)(pin) << 16))
#define READ_PIN(port, pin)   (((port)->IDR & (pin)) ? 1 : 0)

/* DWT-based delay for sub-microsecond precision without syscall overhead */
static uint32_t __dwt_cycles_per_us = 0;
static int __dwt_enabled = 0;

static void dwt_delay_init(void)
{
    if (__dwt_enabled)
        return;

    /* Enable TRC */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    /* Reset cycle counter */
    DWT->CYCCNT = 0;
    /* Enable cycle counter */
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    /* compute cycles per microsecond */
    __dwt_cycles_per_us = SystemCoreClock / 1000000U;
    __dwt_enabled = 1;
}

static void i2c_delay_half(void)
{
    if (__dwt_enabled && __dwt_cycles_per_us != 0) {
        uint32_t wait_cycles = __dwt_cycles_per_us * SCL_DELAY_US;
        uint32_t start = DWT->CYCCNT;
        while ((DWT->CYCCNT - start) < wait_cycles)
            ;
    } else {
        systime_udelay(SCL_DELAY_US);
    }
}

/* Bus helper struct */
struct soft_i2c_bus {
    struct rt_i2c_bus parent;
    GPIO_TypeDef* sda_port;
    uint32_t sda_pin;
    GPIO_TypeDef* scl_port;
    uint32_t scl_pin;
};

/* Transfer request queued to worker thread. Simple fixed-size support. */
#define SOFT_I2C_MAX_MSGS 8
/* maximum bytes per msg copied into request buffer (safe upper bound) */
#define SOFT_I2C_MAX_MSG_LEN 64
struct soft_i2c_request {
    volatile int pending;
    rt_uint16_t slave_addr; /* 8-bit style (addr<<1) as passed by rt-i2c */
    struct rt_i2c_msg msgs[SOFT_I2C_MAX_MSGS];
    uint8_t data[SOFT_I2C_MAX_MSGS][SOFT_I2C_MAX_MSG_LEN];
    void* user_buf[SOFT_I2C_MAX_MSGS];
    rt_uint32_t num;
    rt_size_t result; /* messages processed */
    struct rt_semaphore done; /* signaled to caller when transfer complete */
    struct rt_semaphore req_sem; /* signaled by caller to worker */
};

/* Extend bus structure with request and worker thread objects */
typedef struct soft_i2c_bus_ext {
    struct soft_i2c_bus bus;
    struct soft_i2c_request req;
    rt_thread_t worker;
    char worker_stack[512];
} soft_i2c_bus_ext_t;

/* forward: perform actual transfer on bus using provided msgs (same logic
 * as previous soft_i2c_master_transfer). Returns number of messages
 * processed. */
/* forward-declare low-level bit operations so soft_do_transfer can call them */
static void soft_start(struct soft_i2c_bus* bus);
static void soft_stop(struct soft_i2c_bus* bus);
static int soft_write_byte(struct soft_i2c_bus* bus, uint8_t data);
static uint8_t soft_read_byte(struct soft_i2c_bus* bus, int ack);

static rt_size_t soft_do_transfer(struct soft_i2c_bus* bus, rt_uint16_t slave_addr,
                                  struct rt_i2c_msg msgs[], rt_uint32_t num)
{
    rt_size_t msg_idx = 0;

    for (msg_idx = 0; msg_idx < num; msg_idx++) {
        struct rt_i2c_msg* msg = &msgs[msg_idx];
        RT_ASSERT(!(msg->flags & RT_I2C_ADDR_10BIT));

        if (msg->flags & RT_I2C_RD) {
            uint8_t addr8 = (uint8_t)slave_addr;
            soft_start(bus);
            if (soft_write_byte(bus, (uint8_t)(addr8 | 1))) {
                DRV_DBG("soft i2c: NACK on addr read\n");
                soft_stop(bus);
                break;
            }

            for (uint16_t i = 0; i < msg->len; i++) {
                int ack = (i == (msg->len - 1)) ? 1 : 0;
                msg->buf[i] = soft_read_byte(bus, ack);
            }
            soft_stop(bus);
        } else {
            uint8_t addr8 = (uint8_t)slave_addr;
            soft_start(bus);
            if (soft_write_byte(bus, (uint8_t)(addr8 & ~1))) {
                DRV_DBG("soft i2c: NACK on addr write\n");
                soft_stop(bus);
                break;
            }

            for (uint16_t i = 0; i < msg->len; i++) {
                if (soft_write_byte(bus, msg->buf[i])) {
                    DRV_DBG("soft i2c: NACK on data\n");
                    soft_stop(bus);
                    goto out;
                }
                /* yield occasionally to reduce jank */
                if ((i & 7) == 0) rt_thread_yield();
            }
            soft_stop(bus);
        }
    }

out:
    return msg_idx;
}

/* Worker thread entry: waits for req_sem, performs transfer, signals done */
static void soft_i2c_worker(void* parameter)
{
    soft_i2c_bus_ext_t* bext = (soft_i2c_bus_ext_t*)parameter;
    struct soft_i2c_request* r = &bext->req;

    while (1) {
        /* wait for a request */
        rt_sem_take(&r->req_sem, RT_WAITING_FOREVER);

        if (!r->pending)
            continue;

        r->result = soft_do_transfer(&bext->bus, r->slave_addr, r->msgs, r->num);
        r->pending = 0;
        rt_sem_release(&r->done);
    }
}

/* Low-level bit-bang primitives */
static void soft_start(struct soft_i2c_bus* bus)
{
    gpio_set_od_output(bus->sda_port, bus->sda_pin);
    gpio_set_od_output(bus->scl_port, bus->scl_pin);

    SET_PIN(bus->sda_port, bus->sda_pin);
    SET_PIN(bus->scl_port, bus->scl_pin);
    i2c_delay_half();
    CLEAR_PIN(bus->sda_port, bus->sda_pin);
    i2c_delay_half();
    CLEAR_PIN(bus->scl_port, bus->scl_pin);
    i2c_delay_half();
}

static void soft_stop(struct soft_i2c_bus* bus)
{
    gpio_set_od_output(bus->sda_port, bus->sda_pin);
    CLEAR_PIN(bus->scl_port, bus->scl_pin);
    CLEAR_PIN(bus->sda_port, bus->sda_pin);
    i2c_delay_half();
    SET_PIN(bus->scl_port, bus->scl_pin);
    i2c_delay_half();
    SET_PIN(bus->sda_port, bus->sda_pin);
    i2c_delay_half();
}

/* Write a byte, return 0 if ACK received, 1 if NACK */
static int soft_write_byte(struct soft_i2c_bus* bus, uint8_t data)
{
    for (int i = 0; i < 8; i++) {
        if (data & 0x80)
            SET_PIN(bus->sda_port, bus->sda_pin);
        else
            CLEAR_PIN(bus->sda_port, bus->sda_pin);

        i2c_delay_half();
        SET_PIN(bus->scl_port, bus->scl_pin);
        i2c_delay_half();
        CLEAR_PIN(bus->scl_port, bus->scl_pin);
        data <<= 1;
        if ((i & 3) == 0) rt_thread_yield();
    }

    /* release SDA for ACK */
    gpio_set_input(bus->sda_port, bus->sda_pin);
    i2c_delay_half();
    SET_PIN(bus->scl_port, bus->scl_pin);
    i2c_delay_half();
    int ack = READ_PIN(bus->sda_port, bus->sda_pin) ? 1 : 0;
    CLEAR_PIN(bus->scl_port, bus->scl_pin);
    gpio_set_od_output(bus->sda_port, bus->sda_pin);
    return ack; /* 0 = ACK */
}

/* Read a byte and send ACK (ack=0) or NACK (ack=1) */
static uint8_t soft_read_byte(struct soft_i2c_bus* bus, int ack)
{
    uint8_t data = 0;
    gpio_set_input(bus->sda_port, bus->sda_pin);
    for (int i = 0; i < 8; i++) {
        data <<= 1;
        SET_PIN(bus->scl_port, bus->scl_pin);
        i2c_delay_half();
        if (READ_PIN(bus->sda_port, bus->sda_pin))
            data |= 0x01;
        CLEAR_PIN(bus->scl_port, bus->scl_pin);
        i2c_delay_half();
        if ((i & 3) == 0) rt_thread_yield();
    }

    /* send ACK/NACK */
    gpio_set_od_output(bus->sda_port, bus->sda_pin);
    if (ack == 0)
        CLEAR_PIN(bus->sda_port, bus->sda_pin);
    else
        SET_PIN(bus->sda_port, bus->sda_pin);

    i2c_delay_half();
    SET_PIN(bus->scl_port, bus->scl_pin);
    i2c_delay_half();
    CLEAR_PIN(bus->scl_port, bus->scl_pin);
    i2c_delay_half();
    SET_PIN(bus->sda_port, bus->sda_pin);
    return data;
}

/* Master transfer implementation matching rt_i2c expectations (blocking) */
static rt_size_t soft_i2c_master_transfer(
    struct rt_i2c_bus* bus_base, rt_uint16_t slave_addr, struct rt_i2c_msg msgs[], rt_uint32_t num)
{
    /* Locate the extended bus structure from the parent pointer */
    size_t __off = offsetof(soft_i2c_bus_ext_t, bus) + offsetof(struct soft_i2c_bus, parent);
    soft_i2c_bus_ext_t* bext = (soft_i2c_bus_ext_t*)((char*)bus_base - __off);
    struct soft_i2c_request* r = &bext->req;

    /* bound check */
    if (num > SOFT_I2C_MAX_MSGS) {
        num = SOFT_I2C_MAX_MSGS;
    }

    /* copy request into request buffer */
    r->slave_addr = slave_addr;
    r->num = num;
    for (uint32_t i = 0; i < num; i++) {
        /* copy msg metadata and payload into per-request buffer to avoid
         * use-after-free when worker runs asynchronously */
        struct rt_i2c_msg* src = &msgs[i];
        struct rt_i2c_msg* dst = &r->msgs[i];
        *dst = *src;
        /* save user buffer pointer so we can copy read results back */
        r->user_buf[i] = src->buf;
        /* bound length */
        if (dst->len > SOFT_I2C_MAX_MSG_LEN)
            dst->len = SOFT_I2C_MAX_MSG_LEN;
        dst->buf = r->data[i];
        if (src->buf && dst->len > 0) {
            memcpy(dst->buf, src->buf, dst->len);
        }
    }

    r->pending = 1;
    /* signal worker */
    rt_sem_release(&r->req_sem);

    /* wait for completion */
    rt_sem_take(&r->done, RT_WAITING_FOREVER);

    /* copy read results back to user buffers */
    for (uint32_t i = 0; i < r->num; i++) {
        if ((r->msgs[i].flags & RT_I2C_RD) && r->user_buf[i] && r->msgs[i].len > 0) {
            memcpy(r->user_buf[i], r->data[i], r->msgs[i].len);
        }
    }

    return r->result;
}

static const struct rt_i2c_bus_device_ops soft_i2c_ops = { soft_i2c_master_transfer, RT_NULL, RT_NULL };

/* instantiate three soft buses (1,2,4) matching FMU-V6C mapping */
static soft_i2c_bus_ext_t soft_i2c1_ext = {
    .bus = { .parent.ops = &soft_i2c_ops,
             .sda_port = SOFT_I2C1_SDA_PORT,
             .sda_pin = SOFT_I2C1_SDA_PIN,
             .scl_port = SOFT_I2C1_SCL_PORT,
             .scl_pin = SOFT_I2C1_SCL_PIN },
};

static soft_i2c_bus_ext_t soft_i2c2_ext = {
    .bus = { .parent.ops = &soft_i2c_ops,
             .sda_port = SOFT_I2C2_SDA_PORT,
             .sda_pin = SOFT_I2C2_SDA_PIN,
             .scl_port = SOFT_I2C2_SCL_PORT,
             .scl_pin = SOFT_I2C2_SCL_PIN },
};

static soft_i2c_bus_ext_t soft_i2c4_ext = {
    .bus = { .parent.ops = &soft_i2c_ops,
             .sda_port = SOFT_I2C4_SDA_PORT,
             .sda_pin = SOFT_I2C4_SDA_PIN,
             .scl_port = SOFT_I2C4_SCL_PORT,
             .scl_pin = SOFT_I2C4_SCL_PIN },
};

/* i2c device instances - match names and addresses from hardware driver */
static struct rt_i2c_device i2c1_dev1 = { .slave_addr = IST8310_ADDRESS, .flags = 0 };
static struct rt_i2c_device i2c1_dev2 = { .slave_addr = NCP5623C_ADDRESS, .flags = 0 };
static struct rt_i2c_device i2c4_dev1 = { .slave_addr = IST8310_ADDRESS, .flags = 0 };
static struct rt_i2c_device i2c4_dev2 = { .slave_addr = MS5611_ADDRESS, .flags = 0 };

/* Simple init: enable GPIO clocks and register buses */
rt_err_t drv_i2c_soft_init(void)
{
    /* initialize DWT for fast delays when possible */
    dwt_delay_init();

    /* enable GPIO clocks used */
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOD);

    /* configure pins as open-drain outputs (idle high) */
    gpio_set_od_output(soft_i2c1_ext.bus.sda_port, soft_i2c1_ext.bus.sda_pin);
    gpio_set_od_output(soft_i2c1_ext.bus.scl_port, soft_i2c1_ext.bus.scl_pin);
    SET_PIN(soft_i2c1_ext.bus.sda_port, soft_i2c1_ext.bus.sda_pin);
    SET_PIN(soft_i2c1_ext.bus.scl_port, soft_i2c1_ext.bus.scl_pin);

    gpio_set_od_output(soft_i2c2_ext.bus.sda_port, soft_i2c2_ext.bus.sda_pin);
    gpio_set_od_output(soft_i2c2_ext.bus.scl_port, soft_i2c2_ext.bus.scl_pin);
    SET_PIN(soft_i2c2_ext.bus.sda_port, soft_i2c2_ext.bus.sda_pin);
    SET_PIN(soft_i2c2_ext.bus.scl_port, soft_i2c2_ext.bus.scl_pin);

    gpio_set_od_output(soft_i2c4_ext.bus.sda_port, soft_i2c4_ext.bus.sda_pin);
    gpio_set_od_output(soft_i2c4_ext.bus.scl_port, soft_i2c4_ext.bus.scl_pin);
    SET_PIN(soft_i2c4_ext.bus.sda_port, soft_i2c4_ext.bus.sda_pin);
    SET_PIN(soft_i2c4_ext.bus.scl_port, soft_i2c4_ext.bus.scl_pin);

        /* Register soft buses under the same bus names so existing device
        * registrations (i2c1_dev*, i2c4_dev*) continue to work. */
        rt_err_t rc;
        rc = rt_i2c_bus_device_register(&soft_i2c1_ext.bus.parent, "i2c1");
        DRV_DBG("rt_i2c_bus_device_register(i2c1) -> %d\n", rc);
        rc = rt_i2c_bus_device_register(&soft_i2c2_ext.bus.parent, "i2c2");
        DRV_DBG("rt_i2c_bus_device_register(i2c2) -> %d\n", rc);
        rc = rt_i2c_bus_device_register(&soft_i2c4_ext.bus.parent, "i2c4");
        DRV_DBG("rt_i2c_bus_device_register(i2c4) -> %d\n", rc);

        /* attach devices under same names as original hardware driver */
        rc = rt_i2c_bus_attach_device(&i2c1_dev1, "i2c1_dev1", "i2c1", RT_NULL);
        DRV_DBG("rt_i2c_bus_attach_device(i2c1_dev1) -> %d\n", rc);
        rc = rt_i2c_bus_attach_device(&i2c1_dev2, "i2c1_dev2", "i2c1", RT_NULL);
        DRV_DBG("rt_i2c_bus_attach_device(i2c1_dev2) -> %d\n", rc);
        rc = rt_i2c_bus_attach_device(&i2c4_dev1, "i2c4_dev1", "i2c4", RT_NULL);
        DRV_DBG("rt_i2c_bus_attach_device(i2c4_dev1) -> %d\n", rc);
        rc = rt_i2c_bus_attach_device(&i2c4_dev2, "i2c4_dev2", "i2c4", RT_NULL);
        DRV_DBG("rt_i2c_bus_attach_device(i2c4_dev2) -> %d\n", rc);

        /* Post-registration: verify devices can be found */
        rt_device_t dev;
        dev = rt_device_find("i2c4_dev2");
        DRV_DBG("rt_device_find('i2c4_dev2') -> %p\n", dev);
        dev = rt_device_find("i2c4_dev1");
        DRV_DBG("rt_device_find('i2c4_dev1') -> %p\n", dev);
        dev = rt_device_find("i2c1_dev1");
        DRV_DBG("rt_device_find('i2c1_dev1') -> %p\n", dev);
        dev = rt_device_find("i2c1_dev2");
        DRV_DBG("rt_device_find('i2c1_dev2') -> %p\n", dev);

    /* initialize request semaphores and start worker threads */
    rt_sem_init(&soft_i2c1_ext.req.req_sem, "i2c1_req", 0, RT_IPC_FLAG_FIFO);
    rt_sem_init(&soft_i2c1_ext.req.done, "i2c1_done", 0, RT_IPC_FLAG_FIFO);
    soft_i2c1_ext.req.pending = 0;
    soft_i2c1_ext.worker = rt_thread_create("softi2c1", soft_i2c_worker, &soft_i2c1_ext,
                                           512, 20, 10);
    if (soft_i2c1_ext.worker) rt_thread_startup(soft_i2c1_ext.worker);

    rt_sem_init(&soft_i2c2_ext.req.req_sem, "i2c2_req", 0, RT_IPC_FLAG_FIFO);
    rt_sem_init(&soft_i2c2_ext.req.done, "i2c2_done", 0, RT_IPC_FLAG_FIFO);
    soft_i2c2_ext.req.pending = 0;
    soft_i2c2_ext.worker = rt_thread_create("softi2c2", soft_i2c_worker, &soft_i2c2_ext,
                                           512, 20, 10);
    if (soft_i2c2_ext.worker) rt_thread_startup(soft_i2c2_ext.worker);

    rt_sem_init(&soft_i2c4_ext.req.req_sem, "i2c4_req", 0, RT_IPC_FLAG_FIFO);
    rt_sem_init(&soft_i2c4_ext.req.done, "i2c4_done", 0, RT_IPC_FLAG_FIFO);
    soft_i2c4_ext.req.pending = 0;
    soft_i2c4_ext.worker = rt_thread_create("softi2c4", soft_i2c_worker, &soft_i2c4_ext,
                                           512, 20, 10);
    if (soft_i2c4_ext.worker) rt_thread_startup(soft_i2c4_ext.worker);

    return RT_EOK;
}

/* Provide weak symbol alias for compatibility if consumer calls drv_i2c_init */
__attribute__((weak)) rt_err_t drv_i2c_init(void)
{
    return drv_i2c_soft_init();
}
