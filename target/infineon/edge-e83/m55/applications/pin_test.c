#include <firmament.h>
#include "hal/pin/pin.h"

#define GET_PIN(PORTx,PIN)      ((((uint8_t)(PORTx)) << 3U) + ((uint8_t)(PIN)))
#define LED_ON(_pin)          led_set((struct device_pin_status) { .pin = _pin, .status = 0 })
#define LED_OFF(_pin)         led_set((struct device_pin_status) { .pin = _pin, .status = 1 })

static rt_thread_t pin_test_tid = RT_NULL;
struct device_pin_mode led_mode = { GET_PIN(16, 5), PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };
static rt_device_t pin_dev;

fmt_err_t led_set(struct device_pin_status pin_sta)
{
    if (pin_dev->write(pin_dev, 0, (void*)&pin_sta, sizeof(&pin_sta)) != sizeof(&pin_sta)) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t led_init(struct device_pin_mode pin_mode)
{
    if (pin_dev->control(pin_dev, 0, &pin_mode) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}


static void pin_test_entry(void* parameter)
{
    pin_dev = rt_device_find("pin");
    RT_ASSERT(pin_dev != NULL);
    RT_CHECK(rt_device_open(pin_dev, RT_DEVICE_OFLAG_RDWR));
    led_init(led_mode);
    while (1) {
        LED_ON(GET_PIN(16, 6));
        rt_thread_mdelay(500);
        LED_OFF(GET_PIN(16, 6));
        rt_thread_mdelay(500);
    }
}

static int pin_test_entry_init(void)
{
    pin_test_tid = rt_thread_create(
        "pin_test_thread",
        pin_test_entry,       
        (void*)0x01,      // Default parameter
        2048,        // Stack size
        15,          // Priority
        5            // Time slice
    );

    if (RT_NULL == pin_test_tid) {
        rt_kprintf("[%s] Create failed!\n", __FUNCTION__);
        return -RT_ENOMEM;
    }

    if (RT_EOK != rt_thread_startup(pin_test_tid)) {
        rt_kprintf("[%s] Startup failed!\n", __FUNCTION__);
        return -RT_ERROR;
    }

    rt_kprintf("[%s] Created successfully\n", __FUNCTION__);
    return RT_EOK;
}

MSH_CMD_EXPORT(pin_test_entry_init, pin_test thread demo);