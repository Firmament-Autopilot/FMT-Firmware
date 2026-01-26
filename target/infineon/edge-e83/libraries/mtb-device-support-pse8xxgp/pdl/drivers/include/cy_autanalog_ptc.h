/***************************************************************************//**
* \file cy_autanalog_ptc.h
* \version 2.0
*
* \brief
* Header file for the Programmable Threshold Comparator (PTComp) subsystem of the Autonomous Analog
*
********************************************************************************
* \copyright
* Copyright(c) 2022-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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
* \addtogroup group_autanalog_ptcomp
* \{
* This driver provides API functions to configure the PTComp subsystem of the Autonomous Analog.
*
* The PTComp block provides a pair of comparators that are used to compare the voltage on one input
* to the reference on another input.
*
* For more information on the PTComp,
* refer to the device Architecture Technical Reference Manual (TRM).\n
* For the exact location of the pins, see the device datasheet.
*
* \section group_autanalog_ptc_static Static Configuration
*
* The static configuration contains application-specific settings
* intended to remain static for any PTComp application.
* The Autonomous Controller (AC) will NOT change the static configuration during operation.
*
* \image html LPPASS_PTC_Static.png
*
* The static configuration of the Comp includes:
* - Clock divider (used in LP mode only);
* - Power mode;
* - Interrupt mode;
* - Comp hysteresis;
* - PTComp post-processing configuration, refer to \ref group_autanalog_ptc_pp section.
*
* For configuration settings, see \ref cy_stc_autanalog_ptcomp_comp_sta_t structure.
*
* \section group_autanalog_ptc_dynamic Dynamic Configuration
*
* The dynamic configuration structure includes the Comp settings,
* which can be modified by the Autonomous Controller (AC) during operation.
*
* \image html LPPASS_PTC_Dynamic.png
*
* The Autonomous Controller is able to modify the following characteristics of the PTComp in runtime
* per settings provided in the State Transition Table:
* - Enable/Disable Comp within the PTComp;
* - Change the connection of the Comp inputs;
*
* For configuration settings, see \ref cy_stc_autanalog_ptcomp_comp_dyn_t and \ref cy_stc_autanalog_stt_ptcomp_t structures.
*
* \section group_autanalog_ptc_pp Post-processing Configuration
* The PTComp contains two post-processing blocks that can be used to measure time between events and/or count events.
* The Comp state (level) or rising/falling change can be used as an input event for post-processing.
*
* The PTComp post-processing can operate in the following modes (\ref cy_stc_autanalog_ptcomp_comp_pp_t::cntMode):
* - DIRECT - the counter is configured to count the number of input events cy_stc_autanalog_ptcomp_comp_pp_t::inpSrc.
*            The condition is evaluated based on the \ref cy_en_autanalog_ptcomp_pp_cond_t every rising edge of the
*            post-processing clock (refer to chapter \ref group_autanalog_ptc_clock).
*            If the condition is met, the counter is reset.
* - FRAME - the counter is configured to count the number of input events cy_stc_autanalog_ptcomp_comp_pp_t::inpSrc
*           that occur during a given frame. The frame rate is determined by cy_stc_autanalog_ptcomp_comp_pp_t::period.
*           At the end of the frame, the condition is evaluated based on the \ref cy_en_autanalog_ptcomp_pp_cond_t
*           and the counter is reset to begin the next frame.
* - WINDOW - the counter is configured to count the number of input events cy_stc_autanalog_ptcomp_comp_pp_t::inpSrc
*            that occur inside a given window. The window size is set by cy_stc_autanalog_ptcomp_comp_pp_t::windowSize.
*            After filling the window, the condition is evaluated based on the \ref cy_en_autanalog_ptcomp_pp_cond_t
*            every rising edge of the post processor clock. The counter is not reset in this mode.
*
* The post-processing result of each Comp can be combined together using the dual-input look-up table block.
* This block implements a set of Boolean functions \ref cy_stc_autanalog_ptcomp_comp_pp_t::dataFunction and
* allows a common functional logic to be defined for a pair of Comps.
*
* \section group_autanalog_ptc_clock Clocking
* The PTComp is clocked from the SRSS peripheral clock
* (Clk_HF9, up to 80MHz, refer to \ref group_autanalog_section_configuration) in chip Active mode
* using Peri 0 Clock Group 2 8-bit divider in the clock chain.\n
* Or from the local Low Power Oscillator
* (LPOSC, 4096kHz, refer to \ref cy_en_autanalog_timer_clk_src_t) in chip Deep Sleep mode.
* The clock value can be adjusted using dedicated divider cy_stc_autanalog_ptcomp_comp_sta_t::lpDivPtcomp,
* which divides the incoming clock in chip Deep Sleep mode.
*
* \section group_autanalog_ptc_int Interrupts, Triggers and STT Events
*
* The following internal events of the PTComp can be configured to generate an interrupt or trigger
* or used as the STT event in the Autonomous Analog
* (refer to \ref cy_en_autanalog_ac_out_trigger_mask_t and \ref cy_en_autanalog_stt_ac_condition_t):
* - PTCOMP_CMPx - Indicates Comp output event;
* - PTCOMP_RANGEx - Indicates range detection conditions;
* - PTCOMP_STROBEx (STT event only) - Indicates finish of post-processing iteration and
*   readiness range conditions for evaluation (refer to \ref group_autanalog_ptc_pp chapter);
*
* \defgroup group_autanalog_ptcomp_macros Macros
* \defgroup group_autanalog_ptcomp_functions Functions
*   \{
*       \defgroup group_autanalog_ptcomp_functions_init Initialization Functions
*   \}
* \defgroup group_autanalog_ptcomp_data_structures Data Structures
* \defgroup group_autanalog_ptcomp_enums Enumerated Types
*/
#if !defined(CY_AUTANALOG_PTC_H)
#define CY_AUTANALOG_PTC_H

#include "cy_device.h"

#ifdef CY_IP_MXS22LPPASS_PTC

#include "cy_autanalog_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_autanalog_ptcomp_macros
* \{
*/

/** The maximum number of dynamic configurations that can to be used to configure the PTComp,
 *  for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_PTCOMP_DYN_CFG_MAX                          (8UL)

/** The maximum number of post-processing configurations that can to be used to configure the PTComp,
 *  for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_PTCOMP_PP_CFG_MAX                           (2UL)

/** \cond INTERNAL */

/* Helper macros for range validation */
#define AUTANALOG_PTCOMP_IDX(value)                              ((value) < 2UL)

/** \endcond */

/** \} group_autanalog_ptcomp_macros */

/***************************************
*       Enumerated Types
***************************************/

/**
* \addtogroup group_autanalog_ptcomp_enums
* \{
*/

/**
* Configures the power mode usage for each Comp.
* Each power setting consumes different levels of current
* and supports a different response time.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_COMP_PWR_OFF    = 0UL, /**< The Comp powering is off */
    CY_AUTANALOG_PTCOMP_COMP_PWR_ULP    = 1UL, /**< The Comp power mode is ULTRA LOW,\n
                                                *   the Opamp quiescent current is less then 300nA
                                                *   and response time is 7uS to 100mV overdrive */
    CY_AUTANALOG_PTCOMP_COMP_PWR_LP     = 2UL, /**< The Comp power mode is LOW,\n
                                                *   the Opamp quiescent current is less then 10uA
                                                *   and response time is 1uS to 100mV overdrive */
    CY_AUTANALOG_PTCOMP_COMP_PWR_NORMAL = 3UL, /**< The Comp power mode is NORMAL,\n
                                                *   the Opamp quiescent current is less then 150uA
                                                *   and response time is 0.1uS to 100mV overdrive */
} cy_en_autanalog_ptcomp_comp_pwr_t;


/**
* Configures 30mV hysteresis for Comp.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_COMP_HYST_OFF   = 0UL, /**< The Comp hysteresis is OFF */
    CY_AUTANALOG_PTCOMP_COMP_HYST_ON    = 1UL, /**< The Comp hysteresis is ON */

} cy_en_autanalog_ptcomp_comp_hyst_t;


/**
* Configures the type of edge that triggers a comparator interrupt or
* disable the interrupt entirely.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_COMP_INT_DISABLED     = 0UL, /**< Disabled, no interrupts detected */
    CY_AUTANALOG_PTCOMP_COMP_INT_EDGE_RISING  = 1UL, /**< Rising edge generates an interrupt */
    CY_AUTANALOG_PTCOMP_COMP_INT_EDGE_FALLING = 2UL, /**< Falling edge generates an interrupt */
    CY_AUTANALOG_PTCOMP_COMP_INT_EDGE_BOTH    = 3UL, /**< Both edges generate an interrupt */

} cy_en_autanalog_ptcomp_comp_int_t;


/**
* The PTComp has possibility to configuring the switch routing matrix
* for connection of the inputs of each Comp to the different sources.
* For more details, refer to the device Architecture Technical Reference Manual
* and product datasheet for specific pin number.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_COMP_CTB0_PIN1    = 0UL,  /**< The Comp input connected to CTB0 GPIO Pin 1 */
    CY_AUTANALOG_PTCOMP_COMP_CTB0_PIN4    = 1UL,  /**< The Comp input connected to CTB0 GPIO Pin 4 */
    CY_AUTANALOG_PTCOMP_COMP_CTB0_PIN6    = 2UL,  /**< The Comp input connected to CTB0 GPIO Pin 6 */
    CY_AUTANALOG_PTCOMP_COMP_CTB0_PIN7    = 3UL,  /**< The Comp input connected to CTB0 GPIO Pin 7 */
    CY_AUTANALOG_PTCOMP_COMP_CTB1_PIN1    = 4UL,  /**< The Comp input connected to CTB1 GPIO Pin 1 */
    CY_AUTANALOG_PTCOMP_COMP_CTB1_PIN4    = 5UL,  /**< The Comp input connected to CTB1 GPIO Pin 4 */
    CY_AUTANALOG_PTCOMP_COMP_CTB1_PIN6    = 6UL,  /**< The Comp input connected to CTB1 GPIO Pin 6 */
    CY_AUTANALOG_PTCOMP_COMP_CTB1_PIN7    = 7UL,  /**< The Comp input connected to CTB1 GPIO Pin 7 */
    CY_AUTANALOG_PTCOMP_COMP_CTB0_OA0_OUT = 8UL,  /**< The Comp input connected to CTB0 OA0 output */
    CY_AUTANALOG_PTCOMP_COMP_CTB0_OA1_OUT = 9UL,  /**< The Comp input connected to CTB0 OA1 output */
    CY_AUTANALOG_PTCOMP_COMP_CTB1_OA0_OUT = 10UL, /**< The Comp input connected to CTB1 OA0 output */
    CY_AUTANALOG_PTCOMP_COMP_CTB1_OA1_OUT = 11UL, /**< The Comp input connected to CTB1 OA1 output */
    CY_AUTANALOG_PTCOMP_COMP_DAC0         = 12UL, /**< The Comp input connected to VREF0 (from DAC0)*/
    CY_AUTANALOG_PTCOMP_COMP_DAC1         = 13UL, /**< The Comp input connected to VREF1 (from DAC1) */
    CY_AUTANALOG_PTCOMP_COMP_PRB_OUT0     = 14UL, /**< The Comp input connected to VREF2 (from PRB0) */
    CY_AUTANALOG_PTCOMP_COMP_PRB_OUT1     = 15UL, /**< The Comp input connected to VREF3 (from PRB1) */
    CY_AUTANALOG_PTCOMP_COMP_GPIO0        = 16UL, /**< The Comp input connected to SAR/PTC GPIO Pin 0 */
    CY_AUTANALOG_PTCOMP_COMP_GPIO1        = 17UL, /**< The Comp input connected to SAR/PTC GPIO Pin 1 */
    CY_AUTANALOG_PTCOMP_COMP_GPIO2        = 18UL, /**< The Comp input connected to SAR/PTC GPIO Pin 2 */
    CY_AUTANALOG_PTCOMP_COMP_GPIO3        = 19UL, /**< The Comp input connected to SAR/PTC GPIO Pin 3 */
    CY_AUTANALOG_PTCOMP_COMP_GPIO4        = 20UL, /**< The Comp input connected to SAR/PTC GPIO Pin 4 */
    CY_AUTANALOG_PTCOMP_COMP_GPIO5        = 21UL, /**< The Comp input connected to SAR/PTC GPIO Pin 5 */
    CY_AUTANALOG_PTCOMP_COMP_GPIO6        = 22UL, /**< The Comp input connected to SAR/PTC GPIO Pin 6 */
    CY_AUTANALOG_PTCOMP_COMP_GPIO7        = 23UL, /**< The Comp input connected to SAR/PTC GPIO Pin 7 */

} cy_en_autanalog_ptcomp_comp_mux_t;


/**
* Configures the source signal for the post-processing logic.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_PP_IN_SRC_DISABLED  = 0UL, /**< The source for post-processing is disabled */
    CY_AUTANALOG_PTCOMP_PP_IN_SRC_COMP0     = 1UL, /**< The output of COMP0 used as a source in post-processing */
    CY_AUTANALOG_PTCOMP_PP_IN_SRC_COMP1     = 2UL, /**< The output of COMP1 used as a source in post-processing */

} cy_en_autanalog_ptcomp_pp_input_src_t;


/**
* Configures the level or edge sensing type for handling two outputs from Comps in post-processing.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_PP_IN_TYPE_LEVEL        = 0UL, /**< The level sensitive input is used for post-processing */
    CY_AUTANALOG_PTCOMP_PP_IN_TYPE_EDGE_RISING  = 1UL, /**< The rising edge sensitive input is used for post-processing */
    CY_AUTANALOG_PTCOMP_PP_IN_TYPE_EDGE_FALLING = 2UL, /**< The falling edge sensitive input is used for post-processing */
    CY_AUTANALOG_PTCOMP_PP_IN_TYPE_EDGE_BOTH    = 3UL, /**< The both edges sensitive input is used for post-processing */

} cy_en_autanalog_ptcomp_pp_input_type_t;


/**
* Configures the post-processing operational mode, refer to \ref group_autanalog_ptc_pp.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_PP_CNT_MODE_DIRECT = 0UL, /**< The mode is DIRECT */
    CY_AUTANALOG_PTCOMP_PP_CNT_MODE_FRAME  = 1UL, /**< The mode is FRAME */
    CY_AUTANALOG_PTCOMP_PP_CNT_MODE_WINDOW = 2UL, /**< The mode is WINDOW */

} cy_en_autanalog_ptcomp_pp_cnt_mode_t;


/**
* Configures the size of counter window in number of clock cycles for PTComp, refer to \ref group_autanalog_ptc_pp.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_PP_WINDOW_TWO              = 0UL, /**< The window size of 2 */
    CY_AUTANALOG_PTCOMP_PP_WINDOW_FOUR             = 1UL, /**< The window size of 4 */
    CY_AUTANALOG_PTCOMP_PP_WINDOW_EIGHT            = 2UL, /**< The window size of 8 */
    CY_AUTANALOG_PTCOMP_PP_WINDOW_SIXTEEN          = 3UL, /**< The window size of 16 */
    CY_AUTANALOG_PTCOMP_PP_WINDOW_THIRTY_TWO       = 4UL, /**< The window size of 32 */
    CY_AUTANALOG_PTCOMP_PP_WINDOW_SIXTY_FOUR       = 5UL, /**< The window size of 64 */
    CY_AUTANALOG_PTCOMP_PP_WINDOW_ONE_TWENTY_EIGHT = 6UL, /**< The window size of 128 */

} cy_en_autanalog_ptcomp_pp_window_size_t;


/**
* Configures the logical function of the lookup table to handle two outputs from Comps in post-processing.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A           = 0UL,  /**< The boolean function A */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_BAR_AND_B = 1UL,  /**< The boolean function (NOT A) AND B */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_B           = 2UL,  /**< The boolean function B */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_AND_B     = 3UL,  /**< The boolean function A AND B */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_AND_B_BAR = 4UL,  /**< The boolean function A AND (NOT B) */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_XOR_B     = 5UL,  /**< The boolean function A XOR B */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_OR_B      = 6UL,  /**< The boolean function A OR B */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_NOR_B     = 7UL,  /**< The boolean function NOT (A OR B) */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_XNOR_B    = 8UL,  /**< The boolean function (A OR (NOT B)) AND ((NOT A) OR B) */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_B_BAR       = 9UL,  /**< The boolean function NOT B */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_OR_B_BAR  = 10UL, /**< The boolean function A OR (NOT B) */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_BAR       = 11UL, /**< The boolean function NOT A */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_BAR_OR_B  = 12UL, /**< The boolean function (NOT A) OR B */
    CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_NAND_B    = 13UL, /**< The boolean function NOT (A AND B) */

} cy_en_autanalog_ptcomp_pp_data_func_t;


/**
 * Defines the range detection conditions for the post-processing counter,
 * refer to group_autanalog_ptc_pp.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_PTCOMP_PP_COND_BELOW   = 0UL, /**< The post-processing counter must satisfy the following:\n
                                                *   counter value < cy_stc_autanalog_ptcomp_comp_pp_t::thresholdLow */
    CY_AUTANALOG_PTCOMP_PP_COND_INSIDE  = 1UL, /**< The post-processing counter must satisfy the following:\n
                                                *   (cy_stc_autanalog_ptcomp_comp_pp_t::thresholdLow <= counter value) AND
                                                *   (counter value < cy_stc_autanalog_ptcomp_comp_pp_t::thresholdHigh) */
    CY_AUTANALOG_PTCOMP_PP_COND_ABOVE   = 2UL, /**< The post-processing counter must satisfy the following:\n
                                                *   Value > cy_stc_autanalog_ptcomp_comp_pp_t::thresholdHigh */
    CY_AUTANALOG_PTCOMP_PP_COND_OUTSIDE = 3UL, /**< The post-processing counter must satisfy the following:\n
                                                *   (counter value < cy_stc_autanalog_ptcomp_comp_pp_t::thresholdLow) OR
                                                *   (counter value >= cy_stc_autanalog_ptcomp_comp_pp_t::thresholdHigh) */
} cy_en_autanalog_ptcomp_pp_cond_t;

/** \} group_autanalog_ptcomp_enums */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_autanalog_ptcomp_data_structures
* \{
*/

/**
 * Defines the post-processing configuration structure, see \ref group_autanalog_ptc_pp.
 * Used in \ref cy_stc_autanalog_ptcomp_comp_sta_t
 */
typedef struct
{
    cy_en_autanalog_ptcomp_pp_input_src_t   inpSrc;         /**< The post-processor input source */
    cy_en_autanalog_ptcomp_pp_input_type_t  inputType;      /**< The post-processor edge-detect mode */
    cy_en_autanalog_ptcomp_pp_cnt_mode_t    cntMode;        /**< The post-processor operation mode */
    cy_en_autanalog_ptcomp_pp_data_func_t   dataFunction;   /**< The post-processor LUT function */
    cy_en_autanalog_ptcomp_pp_window_size_t windowSize;     /**< The window size for post-processing mode WINDOW */
    uint16_t                                period;         /**< The frame period in number of clock cycles for PTComp */
    cy_en_autanalog_ptcomp_pp_cond_t        limitCondition; /**< The post-processor counter limit condition */
    uint16_t                                thresholdLow;   /**< Low threshold for post-processing counter */
    uint16_t                                thresholdHigh;  /**< High threshold for post-processing counter */

} cy_stc_autanalog_ptcomp_comp_pp_t;


/**
* Defines the static configuration structure, see \ref group_autanalog_ptc_static.
* Used in \ref cy_stc_autanalog_ptcomp_t and \ref Cy_AutAnalog_PTComp_LoadStaticConfig.
*/
typedef struct
{
    uint16_t                            lpDivPtcomp;    /**< The Low Power clock divider,
                                                         *   actual divide value is DIV_VAL + 1,
                                                         *   valid range is 1...1024.
                                                         *   For more details, refer to
                                                         *   \ref group_autanalog_ptc_clock chapter */
    /**< Static part of configuration for Comp0 */
    cy_en_autanalog_ptcomp_comp_pwr_t   powerModeComp0; /**< The Power mode for the Comp0 */
    cy_en_autanalog_ptcomp_comp_hyst_t  compHystComp0;  /**< The Comp0 30mV hysteresis */
    cy_en_autanalog_ptcomp_comp_int_t   compEdgeComp0;  /**< The edge-detect comparator mode for Comp0 */

    /**< Static part of configuration for Comp1 */
    cy_en_autanalog_ptcomp_comp_pwr_t   powerModeComp1; /**< The Power mode for the Comp1 */
    cy_en_autanalog_ptcomp_comp_hyst_t  compHystComp1;  /**< The Comp1 30mV hysteresis */
    cy_en_autanalog_ptcomp_comp_int_t   compEdgeComp1;  /**< The edge-detect comparator mode for Comp1 */

    /**< Post-processing part of configuration for PTComp */
    uint8_t                             compPpCfgNum;   /**< The number of post-processing configurations */
    cy_stc_autanalog_ptcomp_comp_pp_t * compPpCfgArr;   /**< The array of pointers to post-processing configurations */

} cy_stc_autanalog_ptcomp_comp_sta_t;


/**
* Defines the dynamic configuration structure, see \ref group_autanalog_ptc_dynamic.
* Used in \ref cy_stc_autanalog_ptcomp_t and \ref Cy_AutAnalog_PTComp_LoadDynamicConfig.
*/
typedef struct
{
    cy_en_autanalog_ptcomp_comp_mux_t ninvInpMux; /**< Connection of the non-inverting input of the Comp */
    cy_en_autanalog_ptcomp_comp_mux_t invInpMux;  /**< Connection of the inverting input of the Comp */

} cy_stc_autanalog_ptcomp_comp_dyn_t;


/**
* The configuration structure to set up the entire PTComp
* based on static and dynamic configurations.
* Used in \ref cy_stc_autanalog_cfg_t and \ref Cy_AutAnalog_PTComp_LoadConfig.
*/
typedef struct
{
    /* Static part of configuration */
    cy_stc_autanalog_ptcomp_comp_sta_t * ptcompStaCfg;    /**< The pointer to a static part of the PTComp configuration */

    /* Dynamic part of configuration */
    uint8_t                              ptcompDynCfgNum; /**< The number of dynamic configurations used for the PTComp */
    cy_stc_autanalog_ptcomp_comp_dyn_t * ptcompDynCfgArr; /**< The array of pointers to dynamic configurations used for
                                                               the PTComp */
} cy_stc_autanalog_ptcomp_t;


/** The PTComp section in the State Transition Table state.
 * Used in \ref cy_stc_autanalog_stt_t.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef struct
{
    bool     unlock;         /**< PTComp Unlock\n
                              * FALSE - Locked:\n
                              *     Data from fields enableComp0, dynCfgIdxComp0 and
                              *     enableComp1, dynCfgIdxComp1
                              *     will NOT be taken into account in
                              *     the corresponding state of STT\n
                              * TRUE - Unlocked:\n
                              *     Data from fields enableComp0, dynCfgIdxComp0 and
                              *     enableComp1, dynCfgIdxComp1
                              *     will used in the corresponding state of STT
                              */
    bool     enableComp0;    /**< Enable Comp0. */
    uint8_t  dynCfgIdxComp0; /**< The dynamic configuration selector for Comp0,
                              *   see \ref cy_stc_autanalog_ptcomp_comp_dyn_t,
                              *   the range is 0 to 7.
                              */
    bool     enableComp1;    /**< Enable Comp1. */
    uint8_t  dynCfgIdxComp1; /**< The dynamic configuration selector for Comp1,
                              *   see \ref cy_stc_autanalog_ptcomp_comp_dyn_t,
                              *   the range is 0 to 7.
                              */
} cy_stc_autanalog_stt_ptcomp_t;

/** \} group_autanalog_ptcomp_data_structures */

/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_autanalog_ptcomp_functions
* \{
*/

/**
* \addtogroup group_autanalog_ptcomp_functions_init
* This set of functions is used to configure the PTComp.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_PTComp_LoadConfig
****************************************************************************//**
*
* Configures the PTComp per provided static and dynamic settings.
*
* \note Reconfiguring the Comp power mode requires a new initialization delay for the PTComp subsystem.
* Use a global API \ref Cy_AutAnalog_LoadConfig instead of the local API.
*
* \param ptcompIdx
* The index of the PTComp subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::ptcomp
*
* \param ptcompCfg
* The pointer to a structure containing the static and dynamic parts of the configuration data
* for the entire PTComp.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_PTComp_LoadConfig(uint8_t ptcompIdx,
                                                        const cy_stc_autanalog_ptcomp_t * ptcompCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_PTComp_LoadStaticConfig
****************************************************************************//**
*
* Configures the PTComp per settings in the static configuration structure.
*
* \note Reconfiguring the Comp power mode requires a new initialization delay for the PTComp subsystem.
* Use a global API \ref Cy_AutAnalog_LoadConfig instead of the local API.
*
* \note The post-processing configuration is a part of static configuration.
*
* \param ptcompIdx
* The index of the PTComp subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::ptcomp
*
* \param ptcompStaCfg
* The pointer to a structure containing static configuration data for the PTComp.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_PTComp_LoadStaticConfig(uint8_t ptcompIdx,
                                                              const cy_stc_autanalog_ptcomp_comp_sta_t * ptcompStaCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_PTComp_LoadDynamicConfig
****************************************************************************//**
*
* Configures the PTComp per settings in the dynamic configuration structure.
* The dynamic configuration of the PTComp can be modified by the Autonomous Controller during operation,
* per settings in the State Transition Table, see \ref cy_stc_autanalog_stt_t.
*
* \param ptcompIdx
* The index of the PTComp subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::ptcomp
*
* \param ptcompDynCfgNum
* The actual number of dynamic configurations used to configure the PTComp.
*
* \param ptcompDynCfgArr
* The pointer to a structure containing dynamic configuration data for the PTComp.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_PTComp_LoadDynamicConfig(uint8_t ptcompIdx, uint8_t ptcompDynCfgNum,
                                                               const cy_stc_autanalog_ptcomp_comp_dyn_t * ptcompDynCfgArr);

/** \} group_autanalog_ptcomp_functions_init */


/*******************************************************************************
* Function Name: Cy_AutAnalog_PTComp_Read
****************************************************************************//**
*
* Returns the status of the comparator output.
*
* \param ptcompIdx
* The index of the PTComp subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::ptcomp
*
* \param compIdx
* The index of the Comp within the PTComp.
*
* \return
* The status of the Comp output:
* - false means low;
* - true means high.
* \note Under invalid PTComp index, "false" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_AutAnalog_PTComp_Read(uint8_t ptcompIdx, uint8_t compIdx)
{
    bool result = false;

    uint32_t baseAddr;
    uint32_t regMask;

    CY_ASSERT_L1(AUTANALOG_PTCOMP_IDX(compIdx));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_PTC, ptcompIdx, &baseAddr))
    {
        regMask = (0UL == compIdx) ? PTC_STA_COMP_STAT_OUT0_Msk : PTC_STA_COMP_STAT_OUT1_Msk;
        result = ((AUTANALOG_PTC_COMP_STAT(baseAddr) & regMask) == regMask);
    }

    return result;
}

/** \} group_autanalog_ptcomp_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22LPPASS_PTC */

#endif /** !defined(CY_AUTANALOG_PTC_H) */

/** \} group_autanalog_ptcomp */

/* [] END OF FILE */
