/**
 * LED control for FMU-v6C
 */
#ifndef LED_H__
#define LED_H__

#include <firmament.h>

#include "hal/pin/pin.h"

#ifdef __cplusplus
extern "C" {
#endif

/* simple two-color indicator: RED (PD10), BLUE (PD11) */
#define __STM32_PORT(port)  GPIO##port##_BASE
#define GET_PIN(PORTx, PIN) (rt_base_t)((16 * (((rt_base_t)__STM32_PORT(PORTx) - (rt_base_t)GPIOA_BASE) / (0x0400UL))) + PIN)

#define FMU_LED_RED_PIN     GET_PIN(D, 10)
#define FMU_LED_BLUE_PIN    GET_PIN(D, 11)

#define LED_ON(_pin)        led_set((struct device_pin_status) { .pin = _pin, .status = 0 })
#define LED_OFF(_pin)       led_set((struct device_pin_status) { .pin = _pin, .status = 1 })
#define LED_TOGGLE(_pin)    led_toggle(_pin)

fmt_err_t led_control_init(void);
fmt_err_t led_init(struct device_pin_mode pin_mode);
fmt_err_t led_set(struct device_pin_status pin_sta);
fmt_err_t led_toggle(uint32_t pin);
fmt_err_t rgb_led_set_color(uint32_t color);
/* signal a hardware fault: 1 = hardware fault active (red solid), 0 = clear */
void led_set_hardware_fault(uint8_t hw_fault);
/* early init for turning on LEDs during early boot (uses HAL, no RT device)
 * and a helper to force red LED on in fatal error paths */
void led_early_init(void);
void led_force_red(void);

#ifdef __cplusplus
}
#endif

#endif
