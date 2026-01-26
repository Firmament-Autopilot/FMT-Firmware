/***************************************************************************//**
* \file mtb_hal_gpio.h
*
* \brief
* Provides a high level interface for interacting with the GPIO on Infineon devices.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/**
 * \addtogroup group_hal_gpio GPIO (General Purpose Input Output)
 * \ingroup group_hal
 * \{
 * High level interface for configuring and interacting with general purpose input/outputs (GPIO).
 *
 * The GPIO driver provides functions to configure and initialize GPIO, and to read and write data
 * to the pin.
 * The driver also supports interrupt generation on GPIO signals with rising, falling or both edges.
 *
 * \note The APIs in this driver need not be used if a GPIO is to be used as an input or output of
 * peripherals like I2C or PWM.
 * The respective peripheral's driver will utilize the GPIO interface to configure and initialize
 * its GPIO pins.
 *
 * \section subsection_gpio_features Features
 * * Configurable GPIO pin direction - \ref mtb_hal_gpio_direction_t
 * * Configurable GPIO pin drive modes - \ref mtb_hal_gpio_drive_mode_t
 * * Configurable analog and digital characteristics
 * * Configurable edge-triggered interrupts and callback assignment on GPIO events - \ref
 * mtb_hal_gpio_event_t
 *
 * \section subsection_gpio_quickstart Quick Start
 *
 * \section subsection_gpio_sample_snippets Code Snippets
 *
 * \subsection subsection_gpio_snippet_1 Snippet 1: Reading value from GPIO
 * The following snippet initializes GPIO pin as an input with high impedance digital drive mode and
 * initial value = <b>false</b> (low). A value is read
 * from the pin and stored to a uint8_t variable (<b>read_val</b>).

 * \snippet hal_gpio.c snippet_mtb_hal_gpio_read

 * \subsection subsection_gpio_snippet_2 Snippet 2: Writing value to a GPIO
 * The following snippet initializes GPIO pin as an output pin with strong drive mode and initial
 * value = <b>false</b> (low).
 * A value = <b>true</b> (high) is written to the output driver.

 * \snippet hal_gpio.c snippet_mtb_hal_gpio_write

 * \subsection subsection_gpio_snippet_3 Snippet 3: Reconfiguring a GPIO
 * The following snippet shows how to reconfigure a GPIO pin during run-time using the firmware. The
 * GPIO pin
 * is first initialized as an output pin with strong drive mode. The pin is then reconfigured as an
 * input with high impedance digital drive mode.
 * \note \ref mtb_hal_gpio_configure only changes the <b>direction</b> and the <b>drive_mode</b>
 * of the pin. Previously set pin value is retained.
 *
 * \snippet hal_gpio.c snippet_mtb_hal_gpio_reconfigure

 * \subsection subsection_gpio_snippet_4 Snippet 4: Interrupts on GPIO events
 * GPIO events can be mapped to an interrupt and assigned to a callback function. The callback
 * function needs to be first registered and
 * then the event needs to be enabled.
 ** The following snippet initializes GPIO pin as an input pin. It registers a callback function and
 **enables detection
 * of a falling edge event to trigger the callback.
 * \note If no argument needs to be passed to the callback function then a NULL can be passed during
 * registering. <br>
 *
 * \snippet hal_gpio.c snippet_mtb_hal_gpio_interrupt
 *
 * \subsection subsection_gpio_snippet_5 Snippet 5: Reading and writing from a port
 * The following snippet shows how to configure a GPIO port to do port-wide reads and writes. The
 * GPIO pins are first initialized as output pins with strong drive mode. These are then accessed
 * at a port level.
 *
 * \snippet hal_gpio.c snippet_mtb_hal_gpio_port_write_read
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_GPIO)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Defines
*******************************************************************************/

/** \addtogroup group_hal_results_gpio GPIO HAL Results
 *  GPIO specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */
/** Interrupt status bit is not set for the specified GPIO pin */
#define MTB_HAL_GPIO_RSLT_WRN_INTERRUPT_STATUS_NOT_SET             \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_WARNING, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_GPIO, 0))
/**
 * \}
 */
/** Integer representation of no connect gpio (required to exist in all BSPs) */
#define MTB_HAL_GPIO_NC_VALUE (0xFF)
#define NC 0xFF //!< No Connect/Invalid Pin

/*******************************************************************************
*       Enumerations
*******************************************************************************/

/** Pin events */
typedef enum
{
    /** No interrupt */
    MTB_HAL_GPIO_IRQ_NONE = 0,
    /** Interrupt on rising edge */
    MTB_HAL_GPIO_IRQ_RISE = 1 << 0,
    /** Interrupt on falling edge */
    MTB_HAL_GPIO_IRQ_FALL = 1 << 1,
    /** Interrupt on both rising and falling edges */
    MTB_HAL_GPIO_IRQ_BOTH = (MTB_HAL_GPIO_IRQ_RISE | MTB_HAL_GPIO_IRQ_FALL)
} mtb_hal_gpio_event_t;

/** Pin direction */
typedef enum
{
    MTB_HAL_GPIO_DIR_INPUT,         /**< Input pin */
    MTB_HAL_GPIO_DIR_OUTPUT,        /**< Output pin */
    MTB_HAL_GPIO_DIR_BIDIRECTIONAL  /**< Input and output pin */
} mtb_hal_gpio_direction_t;

/** Pin drive mode */

/** \note When the <b> drive_mode </b> of the <b> pin </b> is set to <b>
   MTB_HAL_GPIO_DRIVE_PULL_NONE </b>,
 * it is set to <b> MTB_HAL_GPIO_DRIVE_STRONG </b> if the <b> direction </b>
 * of the <b> pin </b> is <b> MTB_HAL_GPIO_DIR_OUTPUT </b> or <b>
 * MTB_HAL_GPIO_DIR_BIDIRECTIONAL</b>.
 * If not, the <b> drive_mode </b> of the <b> pin </b> is set to <b> MTB_HAL_GPIO_DRIVE_NONE</b>.
 */

typedef enum
{
    /** Digital Hi-Z. Input only. Input init value(s): 0 or 1 */
    MTB_HAL_GPIO_DRIVE_ANALOG                 = (MTB_HAL_MAP_GPIO_DRIVE_ANALOG),
    /** Analog Hi-Z. Use only for analog purpose */
    MTB_HAL_GPIO_DRIVE_NONE                   = (MTB_HAL_MAP_GPIO_DRIVE_NONE),
    /** Pull-up resistor. Input and output. Input init value(s): 1, output value(s): 0 */
    MTB_HAL_GPIO_DRIVE_PULLUP                 = (MTB_HAL_MAP_GPIO_DRIVE_PULLUP),
    /** Pull-down resistor. Input and output. Input init value(s): 0, output value(s): 1 */
    MTB_HAL_GPIO_DRIVE_PULLDOWN               = (MTB_HAL_MAP_GPIO_DRIVE_PULLDOWN),
    /** Open-drain, Drives Low. Input and output. Input init value(s): 1, output value(s): 0 */
    MTB_HAL_GPIO_DRIVE_OPENDRAINDRIVESLOW     = (MTB_HAL_MAP_GPIO_DRIVE_OPENDRAINDRIVESLOW),
    /** Open-drain, Drives High. Input and output. Input init value(s): 0, output value(s): 1 */
    MTB_HAL_GPIO_DRIVE_OPENDRAINDRIVESHIGH    = (MTB_HAL_MAP_GPIO_DRIVE_OPENDRAINDRIVESHIGH),
    /** Strong output. Output only. Output init value(s): 0 or 1 */
    MTB_HAL_GPIO_DRIVE_STRONG                 = (MTB_HAL_MAP_GPIO_DRIVE_STRONG),
    /** Pull-up and pull-down resistors. Input and output. Input init value(s): 0 or 1,
     * output value(s): 0 or 1 */
    MTB_HAL_GPIO_DRIVE_PULLUPDOWN             = (MTB_HAL_MAP_GPIO_DRIVE_PULLUPDOWN),
    /** No Pull-up or pull-down resistors. Input and output. Input init value(s): 0 or 1,
     * output value(s): 0 or 1 */
    MTB_HAL_GPIO_DRIVE_PULL_NONE              = (MTB_HAL_MAP_GPIO_DRIVE_PULL_NONE)
} mtb_hal_gpio_drive_mode_t;

/** GPIO callback function type */
typedef void (* mtb_hal_gpio_event_callback_t)(void* callback_arg, mtb_hal_gpio_event_t event);

/*******************************************************************************
*       Functions
*******************************************************************************/
// TODO should this take a mtb_hal_gpio_configurator_t instance instead of port/pin?
/** Init the GPIO object <br>
 *
 * @param[in] obj          The GPIO object
 * @param[in] port         The port number
 * @param[in] pin          The pin number
 */
void mtb_hal_gpio_setup(mtb_hal_gpio_t* obj, const uint8_t port, const uint8_t pin);

/** Configure the GPIO pin <br>
 * See \ref subsection_gpio_snippet_3.
 *
 * @param[in] obj          The GPIO object
 * @param[in] direction    The pin direction
 * @param[in] drive_mode   The pin drive mode
 */
void mtb_hal_gpio_configure(mtb_hal_gpio_t* obj, mtb_hal_gpio_direction_t direction,
                            mtb_hal_gpio_drive_mode_t drive_mode);

/** Set the output value for the pin. This only works for output & in_out pins. <br>
 * See \ref subsection_gpio_snippet_2.
 *
 * @param[in] obj   The GPIO object
 * @param[in] value The value to be set (high = true, low = false)
 */
void mtb_hal_gpio_write(mtb_hal_gpio_t* obj, bool value);

/** Read the input value.  This only works for \ref MTB_HAL_GPIO_DIR_INPUT & \ref
   MTB_HAL_GPIO_DIR_BIDIRECTIONAL pins. <br>
 * See \ref subsection_gpio_snippet_1.
 *
 * @param[in]  obj   The GPIO object
 * @return The value of the IO (true = high, false = low)
 */
bool mtb_hal_gpio_read(mtb_hal_gpio_t* obj);

/** Toggle the output value <br>
 * See \ref subsection_gpio_snippet_4.
 * @param[in]  obj  The GPIO object
 */
void mtb_hal_gpio_toggle(mtb_hal_gpio_t* obj);

#if (MTB_HAL_DRIVER_AVAILABLE_GPIO_PORT)

/** Setup the port object
 *
 * @param[out] port Pointer to a port object. The caller must allocate the memory
 * for this object but the init function will initialize its contents.
 * `mtb_hal_gpio_port_t` is an output that is populated based on the input(port_number).
 * @param[in] port_number The port number
 *
 */
void mtb_hal_gpio_port_setup(mtb_hal_gpio_port_t* port, uint32_t port_number);

/** Set the output value for specified port with pin_mask.
 *
 * @param[in] port     The port object
 * @param[in] pin_mask The pin mask (LSB means pin 0)
 *
 * Sets output data of specific IO pins in the corresponding port to '1',
 * without affecting the output data of the other IO pads in the port.
 * All bits in the bitmask are modified at once.
 */
void mtb_hal_gpio_port_set(mtb_hal_gpio_port_t* port, uint32_t pin_mask);

/** Clear the output value with pin_mask
 *
 * @param[in] port     The GPIO object
 * @param[in] pin_mask The pin mask (LSB means pin 0)
 *
 *  Sets output data of specific IO pins in the corresponding port to '0',
 *  without affecting the output data of the other IO pads in the port.
 *  All bits in the bitmask are modified at once.
 */
void mtb_hal_gpio_port_clear(mtb_hal_gpio_port_t* port, uint32_t pin_mask);

/** Toggle the output value with pin_mask
 *
 * @param[in] port     The GPIO object
 * @param[in] pin_mask The pin mask (LSB means pin 0)
 *
 *  Inverts the output data of specific IO pins in the corresponding port,
 *  without affecting the output data of the other IO pads in the port.
 *  All bits in the bitmask are modified at once.
 */
void mtb_hal_gpio_port_toggle(mtb_hal_gpio_port_t* port, uint32_t pin_mask);

/** Set the output value for specified port.
 *
 * @param[in] port  The port object
 * @param[in] value The value to be set (high = true, low = false)
 *
 * All GPIO output bits in the port are modified.
 */
void mtb_hal_gpio_port_write(mtb_hal_gpio_port_t* port, uint32_t value);

/** Reads all bits from specified port
 *
 * @param[in] port  The port object
 * @param[in] value The value of the IO (high = true, low = false)
 *
 */
void mtb_hal_gpio_port_read(mtb_hal_gpio_port_t* port, uint32_t* value);

#endif /* MTB_HAL_DRIVER_AVAILABLE_GPIO_PORT */


/** Register/clear a callback handler for pin events <br>
 *
 * The referenced function will be called when one of the events enabled by \ref
 * mtb_hal_gpio_enable_event occurs.
 *
 * See \ref subsection_gpio_snippet_4.
 *
 * @param[in] obj           The GPIO object
 * @param[in] callback      The callback handler which will be invoked when the event occurs
 * @param[in] callback_arg  Generic argument that will be provided to the callback when called
 */
void mtb_hal_gpio_register_callback(mtb_hal_gpio_t* obj, mtb_hal_gpio_event_callback_t callback,
                                    void* callback_arg);

/** Enable or Disable the specified GPIO event <br>
 *
 * When an enabled event occurs, the function specified by \ref mtb_hal_gpio_register_callback will
 * be called.
 *
 * See \ref subsection_gpio_snippet_4.
 *
 * @param[in] obj           The GPIO object
 * @param[in] event         The GPIO event
 * @param[in] enable        True to turn on interrupts, False to turn off
 */
void mtb_hal_gpio_enable_event(mtb_hal_gpio_t* obj, mtb_hal_gpio_event_t event, bool enable);

/**
 * Process interrupts related related to a GPIO instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_gpio_process_interrupt(mtb_hal_gpio_t* obj);

/** Reads the output state of the pin
 *
 * @param[in]  obj   The GPIO object
 * @return The value of the IO (true = high, false = low)
 */
bool mtb_hal_gpio_read_out(mtb_hal_gpio_t* obj);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifdef MTB_HAL_GPIO_IMPL_HEADER
#include MTB_HAL_GPIO_IMPL_HEADER
#endif /* MTB_HAL_GPIO_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_GPIO)

/** \} group_hal_gpio */
