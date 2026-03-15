/**
 * LED implementation for FMU-v6C
 */
#include "led.h"
#include "FMS.h"
#include "module/workqueue/workqueue_manager.h"
#include "stm32h7xx_hal.h"
#include <firmament.h>

MCN_DECLARE(fms_output);

static rt_device_t pin_dev;
static uint8_t _b;          /* blue blink enable (1 = blink, 0 = off/solid)
                             * note: when blue is solid we set pin directly */
static uint8_t _blue_solid; /* 1 = blue solid on */
static uint8_t _red_mode;   /* 0=off,1=solid,2=slow blink,3=fast blink */
static uint8_t _hw_fault;   /* hardware fault flag */
static uint32_t _led_ticks;

static void run_led(void* parameter)
{
    /* run at 250ms period; use _led_ticks to create different blink rates */
    _led_ticks++;

    /* Blue handling */
    if (_blue_solid) {
        LED_ON(FMU_LED_BLUE_PIN);
    } else if (_b) {
        /* toggle every 500ms (every 2 ticks) */
        if ((_led_ticks & 0x1) == 0) {
            LED_TOGGLE(FMU_LED_BLUE_PIN);
        }
    } else {
        LED_OFF(FMU_LED_BLUE_PIN);
    }

    /* Red handling */
    switch (_red_mode) {
    case 0:
        LED_OFF(FMU_LED_RED_PIN);
        break;
    case 1:
        LED_ON(FMU_LED_RED_PIN);
        break;
    case 2:
        /* slow blink ~1s (toggle every 4 * 250ms = 1s) */
        if ((_led_ticks & 0x3) == 0) {
            LED_TOGGLE(FMU_LED_RED_PIN);
        }
        break;
    case 3:
        /* fast blink ~500ms (toggle every 250ms) */
        LED_TOGGLE(FMU_LED_RED_PIN);
        break;
    default:
        LED_OFF(FMU_LED_RED_PIN);
        break;
    }
}

void vehicle_status_change_cb(uint8_t status)
{
    /* Arm = blue solid, Disarm = blue blink, Standby = blue blink */
    switch (status) {
    case VehicleStatus_Arm:
        rgb_led_set_color(2); /* BLUE solid */
        break;
    case VehicleStatus_Disarm:
    case VehicleStatus_Standby:
        rgb_led_set_color(1); /* BLUE blink */
        break;
    default:
        rgb_led_set_color(0); /* RED as fallback */
        break;
    }
}

void fms_error_change_cb(uint32_t error)
{
    /* If a hardware fault is signaled, always show red solid */
    if (_hw_fault) {
        _red_mode = 1; /* solid red */
        _b = 0;
        _blue_solid = 0;
        return;
    }

    if (error == 0) {
        /* normal: blue blink, red off */
        _b = 1;
        _blue_solid = 0;
        _red_mode = 0;
    } else {
        /* classify errors: ModeDegradation(1) and LostLink(2) are recoverable */
        if ((error & FMS_Error_LostLink) || (error & FMS_Error_ModeDegradation)) {
            /* recoverable software fault: keep blue blinking, red slow blink */
            _b = 1;
            _blue_solid = 0;
            _red_mode = 2; /* slow */
        } else {
            /* other errors (e.g., LowBattery) treat as severe software fault */
            _b = 0;
            _blue_solid = 0;
            _red_mode = 3; /* fast */
        }
    }
}

fmt_err_t led_set(struct device_pin_status pin_sta)
{
    if (pin_dev->write(pin_dev, 0, (void*)&pin_sta, sizeof(pin_sta)) != sizeof(pin_sta)) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t led_toggle(uint32_t pin)
{
    struct device_pin_status pin_sta = { .pin = pin };

    if (pin_dev->read(pin_dev, 0, (void*)&pin_sta, sizeof(pin_sta)) != sizeof(pin_sta)) {
        return FMT_ERROR;
    }

    pin_sta.status = !pin_sta.status;
    if (pin_dev->write(pin_dev, 0, (void*)&pin_sta, sizeof(pin_sta)) != sizeof(pin_sta)) {
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

fmt_err_t rgb_led_set_color(uint32_t color)
{
    /* color: 0=RED(solid), 1=BLUE(blink) */
    /* ensure both leds off first */
    LED_OFF(FMU_LED_RED_PIN);
    LED_OFF(FMU_LED_BLUE_PIN);
    /* color meanings for this board:
     * 0 = RED solid (error)
     * 1 = BLUE blink (normal/disarm/standby)
     * 2 = BLUE solid (arm)
     */
    if (color == 0) {
        /* red solid */
        _b = 0;
        _blue_solid = 0;
        _red_mode = 1;
    } else if (color == 1) {
        /* blue blinking */
        _b = 1;
        _blue_solid = 0;
        _red_mode = 0;
    } else if (color == 2) {
        /* blue solid */
        _b = 0;
        _blue_solid = 1;
        _red_mode = 0;
    } else {
        _b = 0;
        _blue_solid = 0;
        _red_mode = 0;
    }

    return FMT_EOK;
}

static struct WorkItem led_item = {
    .name = "fmu6c_led",
    .period = 250,
    .schedule_time = 0,
    .run = run_led
};

fmt_err_t led_control_init(void)
{
    struct device_pin_mode red_mode = { FMU_LED_RED_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };
    struct device_pin_mode blue_mode = { FMU_LED_BLUE_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };

    pin_dev = rt_device_find("pin");
    RT_ASSERT(pin_dev != NULL);

    RT_CHECK(rt_device_open(pin_dev, RT_DEVICE_OFLAG_RDWR));

    /* default off (active low) */
    LED_OFF(FMU_LED_RED_PIN);
    LED_OFF(FMU_LED_BLUE_PIN);

    led_init(red_mode);
    led_init(blue_mode);

    /* start with blue blinking to indicate normal */
    /* initialize internal state */
    _led_ticks = 0;
    _hw_fault = 0;
    _blue_solid = 0;
    _red_mode = 0;
    rgb_led_set_color(1);

    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");
    RT_ASSERT(lp_wq);

    FMT_CHECK(workqueue_schedule_work(lp_wq, &led_item));

    return FMT_EOK;
}

/* Early init using HAL so LEDs can be used before RT devices are ready */
void led_early_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    /* Enable GPIOD clock for PD10/PD11 */
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /* Configure PD10 (RED) and PD11 (BLUE) as output push-pull, no pull */
    GPIO_InitStruct.Pin = GPIO_PIN_10 | GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Active-low LEDs: force RED on immediately, BLUE off
     * so that startup failures will show a solid red LED until
     * led_control_init clears it. */
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET); /* RED on */
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);   /* BLUE off */
}

/* Force red LED on (active-low) immediately via HAL */
void led_force_red(void)
{
    /* Ensure GPIOD clock enabled */
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /* Set RED pin low (on) and BLUE pin high (off) */
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
}

/* Signal a hardware fault to the LED logic. When hw_fault is non-zero,
 * show solid red and turn off blue. When cleared, restore normal blue blink.
 */
void led_set_hardware_fault(uint8_t hw_fault)
{
    if (hw_fault) {
        _hw_fault = 1;
        _red_mode = 1; /* solid */
        _b = 0;
        _blue_solid = 0;
    } else {
        _hw_fault = 0;
        _red_mode = 0;
        _b = 1;
        _blue_solid = 0;
    }
}
