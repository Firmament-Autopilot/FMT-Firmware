/***************************************************************************//**
* \file cy_autanalog_ctb.h
* \version 2.0
*
* \brief
* Provides an API declaration of the CTB subsystem of the Autonomous Analog.
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
* \addtogroup group_autanalog_ctb
* \{
* This driver provides API functions to configure the CTB subsystem of the Autonomous Analog.
*
* The CTB block provides operational amplifiers (Opamps) for use in continuous-time signal chains.
* Each CTB includes two identical Opamps marked OA0 and OA1, a switch matrix for input/output routing, and
* the resistor ladder for each Opamp gain setting.
*
* For more information on the CTB,
* refer to the device Architecture Technical Reference Manual (TRM).\n
* For the exact location of the pins, see the device datasheet.
*
* \section group_autanalog_ctb_static Static Configuration
*
* The static configuration contains application-specific settings
* intended to remain static for any Opamp application.
* The Autonomous Controller (AC) will NOT change the static configuration during operation.
*
* \image html LPPASS_CTB_Static.png
*
* The static configuration of the Opamp includes:
* - Power mode;
* - Topology;
* - Interrupt mode (Comparator only);
* - Opamp compensation;\n
* For configuration settings, see \ref cy_stc_autanalog_ctb_sta_t.
*
* The Opamp topology in the CTB can be configured as follows:
* - Comparator (with or without hysteresis);
* \note The comparator output is not connected to pin and can only be used as an interrupt or trigger source.
* - Programmable Gain Amplifier (PGA, inverting and non-inverting, ground and Vref referenced);
* - Trans-impedance Amplifier (TIA);
* - Opamp with open loop (Potentiostat);
* - Differential Amplifier (DiffAmp);
* - Buffer (Voltage follower).
*
* \section group_autanalog_ctb_dynamic Dynamic Configuration and State Transition Table
*
* The dynamic configuration structure includes the Opamp settings,
* which can be modified by the Autonomous Controller (AC) during operation.
*
* \image html LPPASS_CTB_OpAmp_Dynamic.png
*
* The Autonomous Controller is able to modify the following characteristics of the CTB in runtime
* per settings provided in the State Transition Table:
* - Enable/Disable Opamp within the CTB;
* - Re-configure the switch matrix:
*    - change the connection of the non-inverting Opamp input to the pin or voltage reference;
*    - change the connection of the inverting Opamp input to the pin;
*    - change the connection of the bottom end of the resistor ladder to the pin or voltage reference;
* - Adjust the Opamps gain;
*
* For the configuration settings, see \ref cy_stc_autanalog_ctb_dyn_t and \ref cy_stc_autanalog_stt_ctb_t.
*
* The gain settings for each topology are as follows:
* <table class="doxtable">
*    <tr>
*       <th>Index</th>
*       <th>Gain</th>
*       <th>R-ladder, Ohm</th>
*       <th>Non-inv PGA</th>
*       <th>Inv PGA</th>
*       <th>DiffAmp</th>
*       <th>TIA</th>
*    </tr>
*    <tr>
*       <td>0</td>
*       <td>1.00</td>
*       <td>Rin = 192k, Rfb = 0</td>
*       <td>1.00</td>
*       <td>0</td>
*       <td>1.00</td>
*       <td>0k</td>
*    </tr>
*    <tr>
*       <td>1</td>
*       <td>1.42</td>
*       <td>Rin = 135k, Rfb = 57k</td>
*       <td>1.42</td>
*       <td>0.42</td>
*       <td>1.42</td>
*       <td>Rfb = 57k</td>
*    </tr>
*    <tr>
*       <td>2</td>
*       <td>2.00</td>
*       <td>Rin = 96k, Rfb = 96k</td>
*       <td>2.00</td>
*       <td>1.00</td>
*       <td>2.00</td>
*       <td>Rfb = 96k</td>
*    </tr>
*    <tr>
*       <td>3</td>
*       <td>2.78</td>
*       <td>Rin = 69k, Rfb = 123k</td>
*       <td>2.78</td>
*       <td>1.78</td>
*       <td>2.78</td>
*       <td>Rfb = 123k</td>
*    </tr>
*    <tr>
*       <td>4</td>
*       <td>4.00</td>
*       <td>Rin = 48k, Rfb = 144k</td>
*       <td>4.00</td>
*       <td>3.00</td>
*       <td>4.00</td>
*       <td>Rfb = 144k</td>
*    </tr>
*    <tr>
*       <td>5</td>
*       <td>5.82</td>
*       <td>Rin = 33k, Rfb = 159k</td>
*       <td>5.82</td>
*       <td>4.82</td>
*       <td>5.82</td>
*       <td>Rfb = 159k</td>
*    </tr>
*    <tr>
*       <td>6</td>
*       <td>8.00</td>
*       <td>Rin = 24k, Rfb = 168k</td>
*       <td>8.00</td>
*       <td>7.00</td>
*       <td>8.00</td>
*       <td>Rfb = 168k</td>
*    </tr>
*    <tr>
*       <td>7</td>
*       <td>10.67</td>
*       <td>Rin = 18k, Rfb = 174k</td>
*       <td>10.67</td>
*       <td>9.67</td>
*       <td>10.67</td>
*       <td>Rfb = 174k</td>
*    </tr>
*    <tr>
*       <td>8</td>
*       <td>16.00</td>
*       <td>Rin = 12k, Rfb = 180k</td>
*       <td>16.00</td>
*       <td>15.00</td>
*       <td>16.00</td>
*       <td>Rfb = 180k</td>
*    </tr>
*    <tr>
*       <td>9</td>
*       <td>21.33</td>
*       <td>Rin = 9k, Rfb = 183k</td>
*       <td>21.33</td>
*       <td>20.33</td>
*       <td>21.33</td>
*       <td>Rfb = 183k</td>
*    </tr>
*    <tr>
*       <td>10</td>
*       <td>32.00</td>
*       <td>Rin = 6k, Rfb = 186k</td>
*       <td>32.00</td>
*       <td>31.00</td>
*       <td>32.00</td>
*       <td>Rfb = 186k</td>
*    </tr>
* </table>
*
* \note For more information on the operating principles of the Autonomous Controller (static and dynamic configurations,
* State transition Table, etc.), refer to the corresponding chapter \ref group_autanalog_ac.
*
* \section group_autanalog_ctb_pump Opamp Input and Output Ranges
*
* The input range of the Opamp can be rail-to-rail if the charge pump is enabled.
* Without the charge pump, the input range is 0 V to VDDA - 1.5 V. The output range
* of the Opamp is typically 0.2 V to VDDA - 1.0 V and will depend on the load.
* See the device datasheet for more details.
*
* <table class="doxtable">
*    <tr>
*       <th>Charge Pump</th>
*       <th>Input Range</th>
*       <th>Output Range</th>
*    </tr>
*    <tr>
*       <td>Enabled</td>
*       <td>0 V to VDDA</td>
*       <td>0.2 V to VDDA - 0.2 V</td>
*    </tr>
*    <tr>
*       <td>Disabled</td>
*       <td>0 V to VDDA - 1.5 V</td>
*       <td>0.2 V to VDDA - 1.0 V</td>
*    </tr>
* </table>
*
* \note The charge pump nominal clock is 4MHz
*
* For the configuration settings, see \ref cy_en_autanalog_ctb_oa_pwr_t.
*
* \section group_autanalog_ctb_caps Opamp compensation
*
* The Opamp stability is affected by the phase delay caused by the
* resistance in the Opmap feedback and parasitic capacitance at the Opamp input.
* Therefore, a 4-bit programmable compensation capacitor block is added in parallel with the
* resistor in the Opmap feedback to optimize the stability of the Opamp performance.
* For the configuration settings, see \ref cy_en_autanalog_ctb_oa_fb_cap_t and \ref cy_en_autanalog_ctb_oa_cc_cap_t.
* \note Use the Autonomous Analog Configurator to define the actual capacitance value required for a particular configuration.
*
* \section group_autanalog_ctb_sample1 Sample use case: inverting PGA and Comparator
*
* \image html LPPASS_CTB_PGA_Comp.png
*
* \snippet autanalog/snippet/autanalog_ctb.c SNIPPET_CTB_CONFIG_COMMON
*
* \snippet autanalog/snippet/autanalog_ctb.c SNIPPET_CTB_CONFIG_PGA_COMP
*
* \snippet autanalog/snippet/autanalog_ctb.c SNIPPET_CTB_INIT_COMMON
*
* \snippet autanalog/snippet/autanalog_ctb.c SNIPPET_CTB_INIT_PGA_COMP
*
* \section group_autanalog_ctb_sample2 Sample use case: non-inverting PGA and Voltage follower
*
* \image html LPPASS_CTB_PGA_Buff.png
*
* \snippet autanalog/snippet/autanalog_ctb.c SNIPPET_CTB_CONFIG_COMMON
*
* \snippet autanalog/snippet/autanalog_ctb.c SNIPPET_CTB_CONFIG_PGA_BUFF
*
* \note The configuration must only be done while the AC is in High Speed mode,
* when \ref cy_stc_autanalog_stt_ac_t::lpMode is equal to FALSE.
*
* \snippet autanalog/snippet/autanalog_ctb.c SNIPPET_CTB_INIT_COMMON
*
* \snippet autanalog/snippet/autanalog_ctb.c SNIPPET_CTB_INIT_PGA_BUFF
*
* \defgroup group_autanalog_ctb_macros Macros
* \defgroup group_autanalog_ctb_functions Functions
*   \{
*       \defgroup group_autanalog_ctb_functions_init Initialization Functions
*   \}
* \defgroup group_autanalog_ctb_data_structures Data Structures
* \defgroup group_autanalog_ctb_enums Enumerated Types
*/

#if !defined(CY_AUTANALOG_CTB_H)
#define CY_AUTANALOG_CTB_H

#include "cy_autanalog_common.h"

#ifdef CY_IP_MXS22LPPASS_CTB

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_autanalog_ctb_macros
* \{
*/

/** The maximum number of dynamic configurations that can to be used to configure the CTB,
 *  for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_CTB_DYN_CFG_MAX                             (8UL)

/** \cond INTERNAL */

/* Helper macros for range validation */
#define AUTANALOG_CTB_COMP_IDX(value)                            ((value) < 2UL)

/** \endcond */

/** \} group_autanalog_ctb_macros */

/***************************************
*       Enumerated Types
***************************************/

/**
* \addtogroup group_autanalog_ctb_enums
* \{
*/

/**
* Configures the power mode and charge pump usage for each Opamp.
* Each power setting consumes different levels of current
* and supports a different input range and gain bandwidth.
* The charge pump is used to increase the input range to the rails.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_PWR_OFF             = 0UL,  /**< The Opamp powering is off. */
    CY_AUTANALOG_CTB_OA_PWR_ULTRA_LOW       = 1UL,  /**< The Opamp power mode is ULTRA LOW,\n
                                                     *   the charge pump is OFF,\n
                                                     *   the Opamp quiescent current is 15uA.
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: FALSE\n
                                                     *      the gain bandwidth is 30kHz;\n
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: TRUE\n
                                                     *      the gain bandwidth is 100kHz;\n
                                                     *      and the drive capability of the Opamp output is 10uA; */
    CY_AUTANALOG_CTB_OA_PWR_ULTRA_LOW_RAIL  = 2UL,  /**< The Opamp power mode is ULTRA LOW,\n
                                                     *   the charge pump is ON,\n
                                                     *   the Opamp quiescent current is 35uA.
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: FALSE\n
                                                     *      the gain bandwidth is 30kHz;\n
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: TRUE\n
                                                     *      the gain bandwidth is 100kHz;\n
                                                     *      and the drive capability of the Opamp output is 10uA; */
    CY_AUTANALOG_CTB_OA_PWR_LOW_RAIL        = 4UL,  /**< The Opamp power mode is LOW,\n
                                                     *   the charge pump is ON,\n
                                                     *   the Opamp quiescent current is 150uA.
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: FALSE\n
                                                     *      the gain bandwidth is 350kHz;\n
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: TRUE\n
                                                     *      the gain bandwidth is 1.2MHz;\n
                                                     *      and the drive capability of the Opamp output is 100uA; */
    CY_AUTANALOG_CTB_OA_PWR_MEDIUM_RAIL     = 6UL,  /**< The Opamp power mode is MEDIUM,\n
                                                     *   the charge pump is ON,\n
                                                     *   the Opamp quiescent current is 200uA.
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: FALSE\n
                                                     *      the gain bandwidth is 700kHz;\n
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: TRUE\n
                                                     *      the gain bandwidth is 2.4MHz;\n
                                                     *      and the drive capability of the Opamp output is 1mA; */
    CY_AUTANALOG_CTB_OA_PWR_HIGH_RAIL       = 8UL,  /**< The Opamp power mode is HIGH,\n
                                                     *   the charge pump is ON,\n
                                                     *   the Opamp quiescent current is 600uA.
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: FALSE\n
                                                     *      the gain bandwidth is 1.75MHz;\n
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: TRUE\n
                                                     *      the gain bandwidth is 6MHz;\n
                                                     *      and the drive capability of the Opamp output is 1mA; */
    CY_AUTANALOG_CTB_OA_PWR_ULTRA_HIGH_RAIL = 10UL, /**< The Opamp power mode is ULTRA HIGH,\n
                                                     *   the charge pump is ON,\n
                                                     *   the Opamp quiescent current is 800uA.
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: FALSE\n
                                                     *      the gain bandwidth is 2.8MHz;\n
                                                     *   If cy_stc_autanalog_ctb_dyn_t::outToPin: TRUE\n
                                                     *      the gain bandwidth is 7.5MHz;\n
                                                     *      and the drive capability of the Opamp output is 10mA; */

} cy_en_autanalog_ctb_oa_pwr_t;


/**
* Configures the predefined topology for the Opamps within the CTB
* (COMP (with/without hysteresis), PGA, TIA, Potentiostat, DiffAmp, Follower).
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_TOPO_COMPARATOR      = 0UL, /**< The Opamp operational topology is Comparator without hysteresis */
    CY_AUTANALOG_CTB_OA_TOPO_PGA             = 1UL, /**< The Opamp operational topology is Programmable Gain Amplifier */
    CY_AUTANALOG_CTB_OA_TOPO_TIA             = 2UL, /**< The Opamp operational topology is Trans-impedance Amplifier */
    CY_AUTANALOG_CTB_OA_TOPO_OPEN_LOOP_OPAMP = 3UL, /**< The Opamp operational topology is Opamp with open loop\n
                                                     *  (cy_stc_autanalog_ctb_dyn_t::outToPin must be TRUE
                                                     *   for this configuration) */
    CY_AUTANALOG_CTB_OA_TOPO_DIFF_AMPLIFIER  = 4UL, /**< The Opamp operational topology is Differential Amplifier\n
                                                     *  (requires the same configuration for both Opamps) */
    CY_AUTANALOG_CTB_OA_TOPO_HYST_COMPARATOR = 5UL, /**< The Opamp operational topology is Comparator with hysteresis
                                                      *   \note The hysteresis is not a constant and depends on
                                                      *   \ref cy_en_autanalog_ctb_oa_pwr_t \n
                                                      *    ULTRA LOW:  80mV \n
                                                      *    LOW:        40mV \n
                                                      *    MEDIUM:     20mV \n
                                                      *    HIGH:       10mV \n
                                                      *    ULTRA HIGH: 4mV  \n */
    CY_AUTANALOG_CTB_OA_TOPO_BUFFER          = 6UL, /**< The Opamp operational topology is Voltage follower */

} cy_en_autanalog_ctb_oa_topo_t;


/**
* Configures the type of edge that triggers a comparator interrupt.
* \note This setting applies only to the Opamp in Comparator mode.
*/
typedef enum
{
    CY_AUTANALOG_CTB_COMP_INT_EDGE_DISABLED = 0UL, /**< Disabled, no interrupts detected */
    CY_AUTANALOG_CTB_COMP_INT_EDGE_RISING   = 1UL, /**< Rising edge generates an interrupt */
    CY_AUTANALOG_CTB_COMP_INT_EDGE_FALLING  = 2UL, /**< Falling edge generates an interrupt */
    CY_AUTANALOG_CTB_COMP_INT_EDGE_BOTH     = 3UL, /**< Both edges generate an interrupt */

} cy_en_autanalog_ctb_comp_int_t;


/**
* Configures the value of the feedback capacitor (Miller capacitance).
* The feedback capacitor (FB cap) is only used in the following configurations:
* PGA, TIA, Differential Amplifier
* (for the topologies 1, 2 or 4, in \ref cy_en_autanalog_ctb_oa_topo_t) and
* for non-unity value of the Opamp gain (\ref cy_en_autanalog_stt_ctb_oa_gain_t).
* Use the Autonomous Analog Configurator to define the actual capacitance value required for a particular configuration.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_FB_CAP_0_pF    = 0UL,  /**< The capacitor is NOT connected in the feedback loop */
    CY_AUTANALOG_CTB_OA_FB_CAP_0_7_pF  = 1UL,  /**< The value of the feedback capacitor is 0.7 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_1_4_pF  = 2UL,  /**< The value of the feedback capacitor is 1.4 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_2_1_pF  = 3UL,  /**< The value of the feedback capacitor is 2.1 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_2_8_pF  = 4UL,  /**< The value of the feedback capacitor is 2.8 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_3_5_pF  = 5UL,  /**< The value of the feedback capacitor is 3.5 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_4_2_pF  = 6UL,  /**< The value of the feedback capacitor is 4.2 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_4_9_pF  = 7UL,  /**< The value of the feedback capacitor is 4.9 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_5_6_pF  = 8UL,  /**< The value of the feedback capacitor is 5.6 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_6_3_pF  = 9UL,  /**< The value of the feedback capacitor is 6.3 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_7_0_pF  = 10UL, /**< The value of the feedback capacitor is 7.0 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_7_7_pF  = 11UL, /**< The value of the feedback capacitor is 7.7 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_8_4_pF  = 12UL, /**< The value of the feedback capacitor is 8.4 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_9_1_pF  = 13UL, /**< The value of the feedback capacitor is 9.1 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_9_8_pF  = 14UL, /**< The value of the feedback capacitor is 9.8 pF */
    CY_AUTANALOG_CTB_OA_FB_CAP_10_5_pF = 15UL, /**< The value of the feedback capacitor is 10.5 pF */

} cy_en_autanalog_ctb_oa_fb_cap_t;


/**
* Configures the value of the compensation capacitor (CC).
* The compensation capacitance must be activated together with the capacitance in the feedback loop
* \ref cy_en_autanalog_ctb_oa_fb_cap_t to optimize the stability of the Opamp.
* Use the Autonomous Analog Configurator to define the actual capacitance value required for particular configuration.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_CC_CAP_0_1_pF   = 0UL,  /**< The value of the compensation capacitor is 0.1 pF */
    CY_AUTANALOG_CTB_OA_CC_CAP_1_1_pF   = 1UL,  /**< The value of the compensation capacitor is 1.1 pF */
    CY_AUTANALOG_CTB_OA_CC_CAP_2_1_pF   = 2UL,  /**< The value of the compensation capacitor is 2.1 pF */
    CY_AUTANALOG_CTB_OA_CC_CAP_3_1_pF   = 3UL,  /**< The value of the compensation capacitor is 3.1 pF */
    CY_AUTANALOG_CTB_OA_CC_CAP_4_1_pF   = 4UL,  /**< The value of the compensation capacitor is 4.1 pF */
    CY_AUTANALOG_CTB_OA_CC_CAP_5_1_pF   = 5UL,  /**< The value of the compensation capacitor is 5.1 pF */
    CY_AUTANALOG_CTB_OA_CC_CAP_6_1_pF   = 6UL,  /**< The value of the compensation capacitor is 6.1 pF */
    CY_AUTANALOG_CTB_OA_CC_CAP_7_1_pF   = 7UL,  /**< The value of the compensation capacitor is 7.1 pF */
    CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED = 8UL,  /**< The compensation capacitor is NOT used */

} cy_en_autanalog_ctb_oa_cc_cap_t;


/**
* Configures the direct connection of the non-inverting input of the Opamp to the external pin.
* The CTB subsystem allows the non-inverting input of the Opamp to be connected directly to
* the pin by means of the switch routing matrix.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_NINV_PIN_DISCONNECT    = 0UL, /**< The non-inverting inputs of the Opamps are not connected to pin */
    CY_AUTANALOG_CTB_OA_NINV_PIN_OA0_P0_OA1_P5 = 1UL, /**< The non-inverting inputs of the Opamps OA0, OA1
                                                       *   are connected to P0 and P5 respectively */
    CY_AUTANALOG_CTB_OA_NINV_PIN_OA0_P1_OA1_P4 = 2UL, /**< The non-inverting inputs of the Opamps OA0, OA1
                                                       *   are connected to P1 and P4 respectively */
} cy_en_autanalog_ctb_oa_ninv_pin_t;


/**
* Configures the direct connection of the non-inverting input of the Opamp to the Vref.
* The CTB subsystem allows the non-inverting input of the Opamp to be connected directly to
* the selected reference voltage using the switch routing matrix.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_NINV_REF_DISCONNECT  = 0UL, /**< The non-inverting input of the Opamp is not connected to Vref */
    CY_AUTANALOG_CTB_OA_NINV_REF_DAC0        = 1UL, /**< The non-inverting input is connected to VREF0 (from DAC0) */
    CY_AUTANALOG_CTB_OA_NINV_REF_DAC1        = 2UL, /**< The non-inverting input is connected to VREF1 (from DAC1 */
    CY_AUTANALOG_CTB_OA_NINV_REF_PRB_OUT0    = 3UL, /**< The non-inverting input is connected to VREF2 (from PRB0) */
    CY_AUTANALOG_CTB_OA_NINV_REF_PRB_OUT1    = 4UL, /**< The non-inverting input is connected to VREF3 (from PRB1) */
    CY_AUTANALOG_CTB_OA_NINV_REF_VBGR        = 5UL, /**< The non-inverting input is connected to VBGR */
    CY_AUTANALOG_CTB_OA_NINV_REF_CTB_OA0_OUT = 6UL, /**< The non-inverting input is connected to the
                                                     *   output of the adjacent CTB OA0 \note OA from another CTB */
    CY_AUTANALOG_CTB_OA_NINV_REF_CTB_OA1_OUT = 7UL, /**< The non-inverting input is connected to the
                                                     *   output of the adjacent CTB OA1 \note OA from another CTB */
} cy_en_autanalog_ctb_oa_ninv_ref_t;


/**
* Configures the direct connection of the inverting input of the Opamp to the external pin.
* The CTB subsystem allows the inverting input of the Opamp to be connected directly to
* the pin using the switch routing matrix.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_INV_PIN_DISCONNECT    = 0UL, /**< The inverting inputs of the Opamps are not connected to pin */
    CY_AUTANALOG_CTB_OA_INV_PIN_OA0_P0_OA1_P5 = 1UL, /**< The inverting inputs of the Opamps OA0, OA1
                                                      *   are connected to P0 and P5 respectively
                                                      */
    CY_AUTANALOG_CTB_OA_INV_PIN_OA0_P1_OA1_P4 = 2UL, /**< The inverting inputs of the Opamps OA0, OA1
                                                      *   are connected to P1 and P4 respectively
                                                      */
} cy_en_autanalog_ctb_oa_inv_pin_t;


/**
* Configures the direct connection of the bottom ends of the resistor ladders to the external pin.
* The CTB subsystem allows the bottom end of the resistor ladder in the Opamp to be connected directly to
* the pin using the switch routing matrix.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_RES_PIN_DISCONNECT    = 0UL, /**< The bottom ends of the resistor ladders are not connected to the pin */
    CY_AUTANALOG_CTB_OA_RES_PIN_OA0_P0_OA1_P5 = 1UL, /**< The bottom ends of the resistor ladders of Opamps OA0, OA1
                                                      *   are connected to P0 and P5 respectively */
    CY_AUTANALOG_CTB_OA_RES_PIN_OA0_P1_OA1_P4 = 2UL, /**< The bottom ends of the resistor ladders of Opamps OA0, OA1
                                                      *   are connected to P1 and P4 respectively */
} cy_en_autanalog_ctb_oa_res_pin_t;


/**
* Configures the direct connection of the bottom ends of the resistor ladders to the Vref.
* The CTB subsystem allows the bottom end of the resistor ladder in the Opamp to be connected directly to
* the selected reference voltage using of the switch routing matrix.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_RES_REF_DISCONNECT   = 0UL, /**< The bottom end of the resistor ladder is not connected
                                                         to the voltage reference */
    CY_AUTANALOG_CTB_OA_RES_REF_DAC0         = 1UL, /**< The bottom end of the resistor ladder is connected to
                                                     *   VREF0 (from DAC0) */
    CY_AUTANALOG_CTB_OA_RES_REF_DAC1         = 2UL, /**< The bottom end of the resistor ladder is connected to
                                                     *   VREF1 (from DAC1) */
    CY_AUTANALOG_CTB_OA_RES_REF_CTB_OA0_OUT  = 3UL, /**< The bottom end of the resistor ladder is connected to
                                                     *   the output of the adjacent CTB OA0
                                                     *   \note OA from another CTB */
    CY_AUTANALOG_CTB_OA_RES_REF_CTB_OA1_OUT  = 4UL, /**< The bottom end of the resistor ladder is connected to
                                                     *   the output of the adjacent CTB OA1
                                                     *   \note OA from another CTB */
    CY_AUTANALOG_CTB_OA_RES_REF_VSSA         = 5UL, /**< The bottom end of the resistor ladder is connected to VSSA */

} cy_en_autanalog_ctb_oa_res_ref_t;


/**
* The CTB subsystem allows the pins to be connected directly to
* the internal analog bus using the input multiplexer for further routing.
* Must be used in conjunction with \ref cy_en_autanalog_ctb_oa_mux_out_t.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_MUX_IN_DISCONNECT = 0UL, /**< The input multiplexer is disconnected */
    CY_AUTANALOG_CTB_OA_MUX_IN_P0         = 1UL, /**< Pin P0 is routed to the internal analog bus */
    CY_AUTANALOG_CTB_OA_MUX_IN_P1         = 2UL, /**< Pin P1 is routed to the internal analog bus */
    CY_AUTANALOG_CTB_OA_MUX_IN_P2         = 3UL, /**< Pin P2 is routed to the internal analog bus */
    CY_AUTANALOG_CTB_OA_MUX_IN_P3         = 4UL, /**< Pin P3 is routed to the internal analog bus */
    CY_AUTANALOG_CTB_OA_MUX_IN_P4         = 5UL, /**< Pin P4 is routed to the internal analog bus */
    CY_AUTANALOG_CTB_OA_MUX_IN_P5         = 6UL, /**< Pin P5 is routed to the internal analog bus */
    CY_AUTANALOG_CTB_OA_MUX_IN_P6         = 7UL, /**< Pin P6 is routed to the internal analog bus */
    CY_AUTANALOG_CTB_OA_MUX_IN_P7         = 8UL, /**< Pin P7 is routed to the internal analog bus */

} cy_en_autanalog_ctb_oa_mux_in_t;


/**
* The CTB subsystem allows the Opamp inputs or the bottom end of the resistor ladder
* to be connected directly to the internal analog bus via the output multiplexer.
* Must be used in conjunction with \ref cy_en_autanalog_ctb_oa_mux_in_t.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_CTB_OA_MUX_OUT_DISCONNECT = 0UL, /**< The output multiplexer is disconnected */
    CY_AUTANALOG_CTB_OA_MUX_OUT_NINV       = 1UL, /**< The internal analog bus is routed to the
                                                   *   Opamps non-inverting input */
    CY_AUTANALOG_CTB_OA_MUX_OUT_INV        = 2UL, /**< The internal analog bus is routed to the
                                                   *    Opamps inverting input */
    CY_AUTANALOG_CTB_OA_MUX_OUT_RES        = 3UL, /**< The internal analog bus is routed to the
                                                   *   Opamps bottom end of the resistor ladder */
} cy_en_autanalog_ctb_oa_mux_out_t;


/**
* The set of the gain configurations for the Opamp in the CTB.
* The gain of the Opamp can be modified by the Autonomous Controller during operation,
* per settings in the State Transition Table, see \ref cy_stc_autanalog_stt_t.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_STT_CTB_OA_GAIN_1_00  = 0UL,  /**< The value of the gain is 1.00. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_1_42  = 1UL,  /**< The value of the gain is 1.42. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_2_00  = 2UL,  /**< The value of the gain is 2.00. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_2_78  = 3UL,  /**< The value of the gain is 2.78. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_4_00  = 4UL,  /**< The value of the gain is 4.00. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_5_82  = 5UL,  /**< The value of the gain is 5.82. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_8_00  = 6UL,  /**< The value of the gain is 8.00. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_10_67 = 7UL,  /**< The value of the gain is 10.67. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_16_00 = 8UL,  /**< The value of the gain is 16.00. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_21_33 = 9UL,  /**< The value of the gain is 21.33. */
    CY_AUTANALOG_STT_CTB_OA_GAIN_32_00 = 10UL, /**< The value of the gain is 32.00. */

} cy_en_autanalog_stt_ctb_oa_gain_t;

/** \} group_autanalog_ctb_enums */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_autanalog_ctb_data_structures
* \{
*/

/**
* Defines the static configuration structure, see \ref group_autanalog_ctb_static.
* Used in \ref cy_stc_autanalog_ctb_t and \ref Cy_AutAnalog_CTB_LoadStaticConfig.
*/
typedef struct
{
    cy_en_autanalog_ctb_oa_pwr_t    pwrOpamp0;      /**< The Power mode for the Opamp0 */
    cy_en_autanalog_ctb_oa_topo_t   topologyOpamp0; /**< The topology configuration for Opamp0 */
    cy_en_autanalog_ctb_comp_int_t  intComp0;       /**< The Edge-detect comparator mode for Opamp0 */
    cy_en_autanalog_ctb_oa_fb_cap_t capFbOpamp0;    /**< The value of the feedback capacitor for Opamp0 */
    cy_en_autanalog_ctb_oa_cc_cap_t capCcOpamp0;    /**< The value of the compensation capacitor for Opamp0 */

    cy_en_autanalog_ctb_oa_pwr_t    pwrOpamp1;      /**< The Power mode for Opamp1 */
    cy_en_autanalog_ctb_oa_topo_t   topologyOpamp1; /**< The topology configuration for Opamp1 */
    cy_en_autanalog_ctb_comp_int_t  intComp1;       /**< The Edge-detect comparator mode for Opamp1 */
    cy_en_autanalog_ctb_oa_fb_cap_t capFbOpamp1;    /**< The value of the feedback capacitor for Opamp1 */
    cy_en_autanalog_ctb_oa_cc_cap_t capCcOpamp1;    /**< The value of the compensation capacitor for Opamp1 */

} cy_stc_autanalog_ctb_sta_t;


/**
* Defines the dynamic configuration structure, see \ref group_autanalog_ctb_dynamic.
* Used in \ref cy_stc_autanalog_ctb_t and \ref Cy_AutAnalog_CTB_LoadDynamicConfig.
*/
typedef struct
{
    cy_en_autanalog_ctb_oa_ninv_pin_t ninvInpPin;   /**< Connection of the non-inverting input of the Opamp to pin */
    cy_en_autanalog_ctb_oa_ninv_ref_t ninvInpRef;   /**< Connection of the non-inverting input of the Opamp to Vref */
    cy_en_autanalog_ctb_oa_inv_pin_t  invInpPin;    /**< Connection of the inverting input of the Opamp to pin */
    cy_en_autanalog_ctb_oa_res_pin_t  resInpPin;    /**< Connection of the bottom end of the resistor ladder to pin */
    cy_en_autanalog_ctb_oa_res_ref_t  resInpRef;    /**< Connection of the bottom end of the resistor ladder to Vref */
    cy_en_autanalog_ctb_oa_mux_in_t   sharedMuxIn;  /**< Connection of the pins to the input multiplexer in the CTB */
    cy_en_autanalog_ctb_oa_mux_out_t  sharedMuxOut; /**< Connection of the Opamp inputs to the output multiplexer in CTB */
    bool                              outToPin;     /**< Connection of the Opamp output to pin */

} cy_stc_autanalog_ctb_dyn_t;


/**
* The configuration structure to set up the entire CTB
* based on static and dynamic configurations.
* Used in \ref cy_stc_autanalog_cfg_t and \ref Cy_AutAnalog_CTB_LoadConfig.
*/
typedef struct
{
    /* Static part of configuration */
    cy_stc_autanalog_ctb_sta_t * ctbStaCfg;    /**< The pointer to a static part of the CTB configuration */

    /* Dynamic part of configuration */
    uint8_t                      ctbDynCfgNum; /**< The number of dynamic configurations used for the CTB */
    cy_stc_autanalog_ctb_dyn_t * ctbDynCfgArr; /**< The array of pointers to dynamic configurations used for the CTB */

} cy_stc_autanalog_ctb_t;


/** The CTB section in the State Transition Table state.
 * Used in \ref cy_stc_autanalog_stt_t.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef struct
{
    bool                              unlock;       /**< CTB Unlock\n
                                                     * FALSE - Locked:\n
                                                     *     Data from fields enableOpampX, cfgOpampX, gainOpampX
                                                     *     will NOT be taken into account in
                                                     *     the corresponding state of STT\n
                                                     * TRUE - Unlocked:\n
                                                     *     Data from fields enableOpampX, cfgOpampX, gainOpampX
                                                     *     will be used in the STT corresponding state
                                                     */
    /* Opamp0 */
    bool                              enableOpamp0; /**< Enable Opamp0 */
    uint8_t                           cfgOpamp0;    /**< The dynamic configuration selector for Opamp0 in the CTB,
                                                     *   see \ref cy_stc_autanalog_ctb_dyn_t,\n
                                                     *   the valid range is 0 to 7
                                                     */
    cy_en_autanalog_stt_ctb_oa_gain_t gainOpamp0;   /**< The gain control for Opamp0 in the CTB */

    /* Opamp1 */
    bool                              enableOpamp1; /**< Enable Opamp1 */
    uint8_t                           cfgOpamp1;    /**< The dynamic configuration selector for Opamp1 in the CTB,
                                                     *   see \ref cy_stc_autanalog_ctb_dyn_t,\n
                                                     *   the valid range is 0 to 7
                                                     */
    cy_en_autanalog_stt_ctb_oa_gain_t gainOpamp1;   /**< The gain control for Opamp1 in the CTB */

} cy_stc_autanalog_stt_ctb_t;

/** \} group_autanalog_ctb_data_structures */

/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_autanalog_ctb_functions
* \{
*/

/**
* \addtogroup group_autanalog_ctb_functions_init
* This set of functions is used to configure the CTB.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_CTB_LoadConfig
****************************************************************************//**
*
* Configures the CTB per provided static and dynamic settings.
*
* \note Enabling or disabling the Opamp requires a new initialization delay for the CTB subsystem.
* Use a global API \ref Cy_AutAnalog_LoadConfig instead of the local API.
*
* \param ctbIdx
* The index of the CTB subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::ctb
*
* \param ctbCfg
* The pointer to a structure containing the static and dynamic parts of the configuration data
* for the entire CTB.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_CTB_LoadConfig(uint8_t ctbIdx, const cy_stc_autanalog_ctb_t * ctbCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_CTB_LoadStaticConfig
****************************************************************************//**
*
* Configures the CTB per settings in the static configuration structure.
*
* \note Enabling or disabling the Opamp requires a new initialization delay for the CTB subsystem.
* Use a global API \ref Cy_AutAnalog_LoadConfig instead of the local API.
*
* \param ctbIdx
* The index of the CTB subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::ctb
*
* \param ctbStaCfg
* The pointer to a structure containing static configuration data for the CTB.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_CTB_LoadStaticConfig(uint8_t ctbIdx, const cy_stc_autanalog_ctb_sta_t * ctbStaCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_CTB_LoadDynamicConfig
****************************************************************************//**
*
* Configures the CTB per settings in the dynamic configuration structure.
* The dynamic configuration of the CTB can be modified by the Autonomous Controller during operation,
* per settings in the State Transition Table, see \ref cy_stc_autanalog_stt_t.
*
* \param ctbIdx
* The index of the CTB subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::ctb
*
* \param ctbDynCfgNum
* The actual number of dynamic configurations used to configure the CTB.
*
* \param ctbDynCfgArr
* The pointer to a structure containing dynamic configuration data for the CTB.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_CTB_LoadDynamicConfig(uint8_t ctbIdx, uint8_t ctbDynCfgNum, const cy_stc_autanalog_ctb_dyn_t * ctbDynCfgArr);

/** \} group_autanalog_ctb_functions_init */


/*******************************************************************************
* Function Name: Cy_AutAnalog_CTB_Comp_Read
****************************************************************************//**
*
* Returns the status of the comparator output.
* \note This function applies only to the Opamp in Comparator mode.
*
* \param ctbIdx
* The index of the CTB subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::ctb
*
* \param compIdx
* The index of the Opamp within the CTB.
*
* \return
* The status of the Opamp output in Comparator mode:
* - false means low;
* - true means high.
* \note Under invalid CTB index, "false" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_AutAnalog_CTB_Comp_Read(uint8_t ctbIdx, uint8_t compIdx)
{
    bool result = false;

    uint32_t baseAddr;
    uint32_t regMask;

    CY_ASSERT_L1(AUTANALOG_CTB_COMP_IDX(compIdx));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_CTB, ctbIdx, &baseAddr))
    {
        regMask = (0UL == compIdx) ? CTBL_STA_COMP_STAT_OA0_COMP_Msk : CTBL_STA_COMP_STAT_OA1_COMP_Msk;
        result = (regMask == (AUTANALOG_CTBX_COMP_STATUS(baseAddr) & regMask)) ? true : false;
    }

    return result;
}


/** \} group_autanalog_ctb_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22LPPASS_CTB */

#endif /** !defined(CY_AUTANALOG_CTB_H) */

/** \} group_autanalog_ctb */

/* [] END OF FILE */
