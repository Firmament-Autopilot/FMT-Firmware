/***************************************************************************//**
* \file cy_autanalog_dac.h
* \version 2.0
*
* \brief
* Provides an API declaration of the CT DAC subsystem of the Autonomous Analog.
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
* \addtogroup group_autanalog_dac
* \{
* This driver provides API functions to configure the CT DAC subsystem of the Autonomous Analog.
*
* The CT DAC (hereafter DAC) is a 12-bit, continuous-time segmented DAC. It is based on an 8-bit R-2R array
* and a 4-bit thermometer array. A buffered sample and hold (S/H) circuit is useful for low power operation
* where an occasional update of the DAC output is acceptable. The DAC can be used in applications
* that require voltage references, bias, or analog waveform output. The DAC can work in conjunction with
* the CTB and PRB, which are used as buffered reference voltage sources.
*
* For more information on the CT DAC,
* refer to the device Architecture Technical Reference Manual (TRM).\n
* For the exact location of the pins, see the device datasheet.
*
* \section group_autanalog_dac_static Static Configuration
*
* The static configuration contains application-specific settings
* intended to remain static for any DAC application.
* The Autonomous Controller (AC) will NOT change the static configuration during operation.
*
* \image html LPPASS_DAC_Static.png
*
* The static configuration of the DAC includes:
* - Clock rate (for Low Power mode only);
* - Input data format (signed/unsigned);
* - Reference voltage source selector;
* - DAC topology and use of reference and output voltage buffers;
* - Output control settings;\n
* For configuration settings, refer to \ref cy_stc_autanalog_dac_sta_t.
*
* \section group_autanalog_dac_channels DAC Channels and State Transition Table
*
* Up to 15 configurations are available for the "virtual" DAC channels.
* The last channel with index 15 is preserved for updates from FW only.

* The DAC channel configuration includes:
* - Operating mode of the DAC (refer to \ref group_autanalog_dac_mode chapter);
* - The option to enable the S/H functionality (refer to \ref group_autanalog_dac_sampleAndHold chapter)
* - Start/end address and step size for the waveform in the LUT;
* - Output voltage range;\n
* For the configuration settings, refer to cy_stc_autanalog_dac_ch_t structure.
*
* The DAC channel can be switched by the Autonomous Controller (AC) in runtime
* per settings provided in the State Transition Table (refer to \ref cy_stc_autanalog_stt_dac_t structure)
*
* \section group_autanalog_dac_topology Topology
*
* \subsection group_autanalog_dac_vref Reference Voltage
*
* The reference voltage can be Vdda or an internal Vref used with or without the unity gain buffer
* for the reference voltage in the DAC:
* - VBGR - Internal, temperature-independent, band-gap voltage reference;
* - CTB_OA - The reference voltage is driven by the Opamp output in the CTB
*   (refer to \ref group_autanalog_ctb section);
* - PRB_VREF - The reference voltage is driven from the PRB
*   (refer to \ref cy_stc_autanalog_prb_t structure);
*
* \note Vdda is 1.8V and Vbgr is 0.9V
*
* \subsection group_autanalog_dac_path Output Paths
*
* The DAC output can be routed in different paths:
* - Direct output path (NOT to pin);
* - Direct output path with Ctrack capacitor connected;
* - Direct output path with Ctrack and Chold capacitors connected;
* - Buffered output path for internal connection within the chip;
* - Buffered output path for internal and external connections;
*
* \section group_autanalog_dac_pump Buffer Input and Output Ranges
*
* The input range of the buffer can be rail-to-rail if the charge pump is enabled.
* Without the charge pump, the input range is 0 V to VDDA - 1.5 V. The output range
* of the buffer is typically 0.2 V to VDDA - 1.0 V and will depend on the load.
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
* For the configuration settings, see \ref cy_en_autanalog_dac_out_buf_pwr_t.
*
* \section group_autanalog_dac_rate Update Rates
*
* The DAC supports two update rates of operation:
* - Single step mode (default);
* - Continuous mode;\n
* In Single step mode, the DAC output changes on each subsequent trigger
* cy_stc_autanalog_stt_dac_t::trigger in the State Transition Table.\n
* In Continuous mode, the output value changes on each subsequent clock of the DAC.\n
* For more details, refer to \ref group_autanalog_dac_mode.
*
* \subsection group_autanalog_dac_clock Clocking
*
* The DAC is clocked from the SRSS peripheral clock
* (Clk_HF9, up to 80MHz, refer to \ref group_autanalog_section_configuration) in chip Active mode
* using Peri 0 Clock Group 2 8-bit divider in the clock chain.\n
* Or from the local Low Power Oscillator
* (LPOSC, 4096kHz, refer to \ref cy_en_autanalog_timer_clk_src_t) in chip Deep Sleep mode.\n
* The clock value can also be adjusted using the cy_stc_autanalog_dac_sta_t::lpDivDac,
* which divides the incoming clock in chip Deep Sleep mode.\n
*
* \section group_autanalog_dac_sampleAndHold Sample and Hold
*
* The cy_stc_autanalog_dac_ch_t::sampleAndHold mode allows duty cycling of the DAC
* where Chold capacitor (Chold >> Ctrack) holds the previous value of the DAC output.
* The cy_stc_autanalog_dac_sta_t::sampleTime is defined as the time it takes for
* the DAC output to drop by 1 LSB.
*
* The DAC is updated every positive edge of the DAC clock with the following sequence:
* - The DAC is configured for SAMPLE: the COS and CHD switches are closed, DAC array is enabled
* and outputs the updated value (based on \ref group_autanalog_dac_mode) onto a Chold capacitor
* for sample time duration;
* - The DAC is configured for HOLD: the COS switch is opened, CHD switch is closed, DAC array is disabled
* and the last output value is held on the Chold capacitor until the next positive edge of the DAC clock.
* HOLD duration is DAC clock period - duration of the sample time.
* \note For \ref group_autanalog_dac_mode ADDRESS or DATA, the AC must wait (ACTION = WAIT_FOR) for
* the DAC strobe (CONDITION = DAC_STROBE) before re-triggering the DAC_INC/DAC_DEC fields.
* Refer to \ref cy_en_autanalog_stt_ac_action_t and \ref cy_en_autanalog_stt_ac_condition_t.
*
* \section group_autanalog_dac_deglitch De-glitch
*
* A typical issue in DACs is the glitch during code transitions. Blanking can be used to reduce
* the glitch. During data changes, a dedicated switch on the output path is used to block the glitch
* from propagating to the DAC output. The Ctrack capacitor maintains the previous value
* while the switch is open, so the DAC output doesn't drop.
*
* If cy_stc_autanalog_dac_sta_t::topology is set to
* - CY_AUTANALOG_DAC_TOPO_DIRECT;
* - CY_AUTANALOG_DAC_TOPO_DIRECT_WITH_TRACK_CAP;
* - CY_AUTANALOG_DAC_TOPO_DIRECT_WITH_TRACK_HOLD_CAP;
*
* the CHD switch is opened during the de-glitch time.
*
* If cy_stc_autanalog_dac_sta_t::topology is set to
* - CY_AUTANALOG_DAC_TOPO_BUFFERED_INTERNAL;
* - CY_AUTANALOG_DAC_TOPO_BUFFERED_EXTERNAL;
*
* the COS switch is opened during the de-glitch time.
*
* De-glitch time set with cy_stc_autanalog_dac_sta_t::deGlitchTime and calculated as follow:\n
* (DEGLITCH_CNT + 1) / DAC_CLOCK_FREQ
*
* \section group_autanalog_dac_mode Operating Mode
*
* <table class="doxtable">
*    <tr>
*       <th>Mode</th>
*       <th>Description</th>
*    </tr>
*    <tr>
*       <td>One Shot, One Quadrant</td>
*       <td>
*           The LUT address is incremented on every positive edge of the DAC clock
*           until the END_ADDR is reached or exceeded.\n
*           The update step size is defined by STEP_VAL.\n
*           The One Shot mode is completed when the END_ADDR is reached.\n
*           The DAC outputs an EPOCH trigger after reaching (or exceeding)
*           the END_ADDR and outputting the corresponding value.
*       </td>
*    </tr>
*    <tr>
*       <td>One Shot, Two Quadrant</td>
*       <td>
*           The LUT address is incremented on every positive edge of the DAC clock
*           until the END_ADDR is reached*, then the LUT address is decremented back to the START_ADDR.\n
*           The DAC outputs an EPOCH trigger after returning to (or exceeding)
*           the START_ADDR and outputting the corresponding value.
*           \note *If the END_ADDR is not reached but exceeded
*           (which can happen with STEP_VAL greater than 1), the LUT address is decremented from
*           the END_ADDR by the amount exceeded).\n
*           After outputting the END_ADDR in one direction, while wrapping around in the reverse direction,
*           the STEP_VAL is decremented from this last address value (i.e. we output the last value only once
*           and while wrapping around in the reverse direction, we output the address that is the last address
*           minus the STEP_VAL).
*       </td>
*    </tr>
*    <tr>
*       <td>One Shot, Four Quadrant</td>
*       <td>
*           The LUT address is updated on every positive edge of the DAC clock
*           according to the following algorithm:\n
*              1. The LUT address is incremented until the END_ADDR is reached*\n
*              2. The LUT address is decremented until the START_ADDR is reached*\n
*              3. The polarity of the DAC output signal is inverted and steps 1 and 2 are repeated\n
*
*           The DAC outputs an EPOCH trigger after returning to (or exceeding)
*           the START_ADDR with an inverted polarity and outputting the corresponding value.\n
*           This mode assumes that the DAC waveform table constitutes 1/4 of the desired generated waveform.
*           \note *If the START_ADDR/END_ADDR address is not reached but instead exceeded
*           (which can happen with STEP_VAL greater than 1), the LUT address is adjusted
*           (i.e. decremented from END_ADDR or incremented from START_ADDR by the amount exceeded).\n
*           After outputting the START/END ADDR in one direction, while wrapping around in the opposite direction,
*           the STEP_VAL is incremented/decremented from this last address value (i.e. we output the last value only once
*           and when we go back in the opposite direction, we output the address that is the last address
*           plus/minus the STEP_VAL).
*       </td>
*    </tr>
*    <tr>
*       <td>Continuous, One Quadrant</td>
*       <td>
*           The LUT address is incremented on every positive edge of the DAC clock
*           until the END_ADDR is reached*.\n
*           The address then wraps back to the START_ADDR and repeats indefinitely.\n
*           The update step size is defined by STEP_VAL.\n
*           The DAC outputs an EPOCH trigger after reaching (or exceeding)
*           the END_ADDR and outputting the corresponding value.
*           \note *If the END_ADDR is not reached, but instead exceeded
*           (which can happen with STEP_VAL greater than 1), the LUT address wraps back
*           to START_ADDR and is incremented by the amount exceeded).
*       </td>
*    </tr>
*    <tr>
*       <td>Continuous, Two Quadrant</td>
*       <td>
*           The LUT address is incremented on every positive edge of the DAC clock
*           until the END_ADDR is reached*, then the LUT address is decremented back
*           to the START_ADDR and repeats indefinitely.\n
*           The DAC outputs an EPOCH trigger after returning to the START_ADDR
*           and outputting the corresponding value.
*           \note *If the START_ADDR or the END_ADDR is not reached but instead exceeded
*           (which can happen with STEP_VAL greater than 1), the LUT address is adjusted
*           (i.e. decremented from END_ADDR or incremented from START_ADDR by the amount exceeded).\n
*           After outputting the START/END ADDR in one direction, while wrapping around in the opposite direction,
*           the STEP_VAL is incremented/decremented from this last address value (i.e. we output the last value only once
*           and while wrapping around we output the address which is the last address plus/minus the STEP_VAL).
*       </td>
*    </tr>
*    <tr>
*       <td>Continuous, Four Quadrant</td>
*       <td>
*           The LUT address is updated on every positive edge of the DAC clock
*           according to the following algorithm:\n
*              1. The LUT address is incremented until the END_ADDR is reached*.
*              2. The LUT address is decremented until the START_ADDR is reached*.
*              3. The polarity of the DAC output signal is inverted and steps 1 and 2 are repeated indefinitely.\n
*
*           The DAC outputs an EPOCH trigger after returning to (or exceeding)
*           the START_ADDR with an inverted polarity and outputting the corresponding value.\n
*           This mode assumes that the DAC waveform table constitutes 1/4 of the desired generated waveform.
*           \note *If the START_ADDR/END_ADDR is not reached but instead exceeded
*           (which can happen with STEP_VAL greater than 1), the LUT address is adjusted
*           (i.e. decremented from END_ADDR or incremented from STAR_ADDR by the amount exceeded).\n
*           After outputting the START/END ADDR in one direction, while wrapping around in the opposite direction,
*           the STEP_VAL is incremented/decremented from this last address value (i.e. we output the last value only once
*           and while wrapping around in the opposite direction, we output the address that is the last address
*           plus/minus the STEP_VAL).
*       </td>
*    </tr>
*    <tr>
*       <td>Address mode</td>
*       <td>
*           The LUT address is updated on every positive edge of the DAC_INC or DAC_DEC
*           from the State Transition Table, see cy_stc_autanalog_stt_dac_t::direction,
*           unless cy_stc_autanalog_dac_ch_t::sampleAndHold is set\n
*           (for more details, refer to \ref group_autanalog_dac_sampleAndHold chapter).\n
*           The update step size is defined by STEP_VAL.\n
*           If on the START_ADDR and DAC_DEC is triggered, the address wraps forward to the END_ADDR.\n
*           If on the END_ADDR and DAC_INC is triggered, the address wraps back to the START_ADDR.\n
*           \note In this mode, the DAC does not output an EPOCH trigger.
*           \note The DAC does not support validation range conditions for address,
*                 see \ref cy_stc_autanalog_dac_ch_limit_t
*       </td>
*    </tr>
*    <tr>
*       <td>Data mode</td>
*       <td>
*           The DAC outputs the data stored at the START_ADDR.\n
*           The DAC output value is incremented or decremented based on
*           every positive edge of the DAC_INC or DAC_DEC from the State Transition Table,
*           see cy_stc_autanalog_stt_dac_t::direction, unless cy_stc_autanalog_dac_ch_t::sampleAndHold is set\n
*           (for more details, refer to \ref group_autanalog_dac_sampleAndHold chapter).\n
*           The increment/decrement amount is set by STEP_VAL.\n
*           \note In this mode, the DAC does not output an EPOCH trigger.
*           \note The DAC value is clamped if requested to go under the minimum code
*           (0x000 for unsigned or 0x800 for signed) or above the maximum code
*           (0xFFF for unsigned or 0x7FF for signed).
*       </td>
*    </tr>
* </table>
* Where START_ADDR, END_ADDR and STEP_VAL are configured individually for each channel:
* - The START_ADDR is defined in cy_stc_autanalog_dac_ch_t::startAddr;\n
* - The END_ADDR is defined in cy_stc_autanalog_dac_ch_t::endAddr;\n
* - The STEP_VAL is selected in cy_stc_autanalog_dac_ch_t::stepSel.\n
*
* For the configuration settings, see \ref cy_stc_autanalog_dac_ch_t::operMode.
*
* \section group_autanalog_dac_output Output Drive Control
*
* The DAC can be programmed so that code 0 corresponds to ground or 1 LSB.
* The bottom end of the R-2R ladder (LSB side) can be configured to connect to the Vref or Vssa
* using cy_stc_autanalog_dac_sta_t::bottomSel. This setting determines the output drive control
* in row with cy_stc_autanalog_stt_dac_t::enable, cy_stc_autanalog_dac_waveform_t::driveMode and
* cy_stc_autanalog_dac_sta_t::disabledMode as follow:
*
* <table class="doxtable">
*    <tr>
*       <th>DAC Enabled</th>
*       <th>Drive Mode</th>
*       <th>Disabled Mode</th>
*       <th>DAC Range</th>
*       <th>Output State</th>
*    </tr>
*    <tr>
*       <td>FALSE</td>
*       <td>X</td>
*       <td>X</td>
*       <td>X</td>
*       <td>tri-state</td>
*    </tr>
*    <tr>
*       <td>TRUE</td>
*       <td>Hi-Z</td>
*       <td>tri-state</td>
*       <td>X</td>
*       <td>tri-state</td>
*    </tr>
*    <tr>
*       <td>TRUE</td>
*       <td>Hi-Z</td>
*       <td>Vssa/Vref</td>
*       <td>Vssa</td>
*       <td>Vssa</td>
*    </tr>
*    <tr>
*       <td>TRUE</td>
*       <td>Hi-Z</td>
*       <td>Vssa/Vref</td>
*       <td>Vref</td>
*       <td>Vref</td>
*    </tr>
*    <tr>
*       <td>TRUE</td>
*       <td>Vref</td>
*       <td>tri-state</td>
*       <td>X</td>
*       <td>tri-state</td>
*    </tr>
*    <tr>
*       <td>TRUE</td>
*       <td>Vref</td>
*       <td>Vssa/Vref</td>
*       <td>Vssa</td>
*       <td>Vssa</td>
*    </tr>
*    <tr>
*       <td>TRUE</td>
*       <td>Vref</td>
*       <td>Vssa/Vref</td>
*       <td>Vref</td>
*       <td>Vref</td>
*    </tr>
*    <tr>
*       <td>TRUE</td>
*       <td>Enabled</td>
*       <td>X</td>
*       <td>Vssa</td>
*       <td>[0, 4095] * Vref / 4096</td>
*    </tr>
*    <tr>
*       <td>TRUE</td>
*       <td>Enabled</td>
*       <td>X</td>
*       <td>Vref</td>
*       <td>[1, 4096] * Vref / 4096</td>
*    </tr>
** </table>
*
* \section group_autanalog_dac_sign Signed/Unsigned Input
*
* The format of the DAC code can be either unsigned or signed two's complement.
* Only the first 12 bits are used by the DAC, so no sign extension is required.
* For the signed format, the DAC decodes the input code by adding 0x800.\n
*
* For the configuration settings, see \ref cy_stc_autanalog_dac_sta_t::sign.
*
* \section group_autanalog_dac_int Interrupts, Triggers and STT Events
*
* The following internal events of the DAC can be configured to generate an interrupt or trigger
* or used as the STT event in the Autonomous Analog
* (refer to \ref cy_en_autanalog_ac_out_trigger_mask_t and \ref cy_en_autanalog_stt_ac_condition_t):
* - DAC_EPOCH - Indicates end of waveform event;
* - DAC_RANGE - Indicates range detection conditions;
* - DAC_EMPTY (interrupt only) - Indicates empty conditions on FW channel (Ch#15),
*   refer to \ref Cy_AutAnalog_DAC_WriteNextSample ;
* - DAC_STROBE (STT event only) - Indicates the S/H iteration finished
*   (refer to \ref group_autanalog_dac_sampleAndHold chapter);
*
* \section group_autanalog_dac_sample1 Sample use case: FW Channel #15
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_CONFIG_COMMON
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_CONFIG_FWCH15
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_INIT_COMMON
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_INIT_FWCH15
*
* \section group_autanalog_dac_sample2 Sample use case: Output Analog Waveform
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_CONFIG_COMMON
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_DEFINE_WAVEFORM
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_CONFIG_WAVEFORM
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_INIT_COMMON
*
* \snippet autanalog/snippet/autanalog_dac.c SNIPPET_DAC_INIT_WAVEFORM
*
* \defgroup group_autanalog_dac_macros Macros
* \defgroup group_autanalog_dac_functions Functions
*   \{
*       \defgroup group_autanalog_dac_functions_init Initialization Functions
*       \defgroup group_autanalog_dac_functions_lut LUT Functions
*   \}
* \defgroup group_autanalog_dac_data_structures Data Structures
* \defgroup group_autanalog_dac_enums Enumerated Types
*/

#if !defined(CY_AUTANALOG_DAC_H)
#define CY_AUTANALOG_DAC_H

#include "cy_device.h"

#ifdef CY_IP_MXS22LPPASS_DAC

#include "cy_autanalog_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_autanalog_dac_macros
* \{
*/

/** The maximum number of configurations for the DAC channels,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_DAC_CH_CFG_NUM                    (15UL)

/** The maximum number of configuration structures to define the DAC channel range,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_DAC_CH_RANGE_NUM                  (3UL)

/** The maximum number of configuration structures to define the DAC step value,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_DAC_STEP_VAL_NUM                  (3UL)

/** The maximum number of samples in the DAC LUT
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_DAC_DATA_SAMPLES_NUM              (512U)

/** \cond INTERNAL */

/* Helper macros for range validation */
#define AUTANALOG_DAC_LUT_IDX(value)                   ((value) < CY_AUTANALOG_DAC_DATA_SAMPLES_NUM)

/* Validation macros for RANGE_STATUS register */
#define AUTANALOG_DAC_CH_RANGE_STATUS(value)           ((value) <= DAC_STA_RANGE_STATUS_CHAN_RANGE_STATUS_Msk)

/* Validation macro for AUTANALOG_DAC_LUT register */
#define AUTANALOG_DAC_OUT_DM(value)                    ((value) <= CY_AUTANALOG_DAC_OUT_DRIVE_MODE_VREF)

/** \endcond */

/** The DAC channels configurations */
#define CY_AUTANALOG_DAC_CHAN_CFG0                     (0x00000000UL) /**< The DAC channel 0 */
#define CY_AUTANALOG_DAC_CHAN_CFG1                     (0x00000001UL) /**< The DAC channel 1 */
#define CY_AUTANALOG_DAC_CHAN_CFG2                     (0x00000002UL) /**< The DAC channel 2 */
#define CY_AUTANALOG_DAC_CHAN_CFG3                     (0x00000003UL) /**< The DAC channel 3 */
#define CY_AUTANALOG_DAC_CHAN_CFG4                     (0x00000004UL) /**< The DAC channel 4 */
#define CY_AUTANALOG_DAC_CHAN_CFG5                     (0x00000005UL) /**< The DAC channel 5 */
#define CY_AUTANALOG_DAC_CHAN_CFG6                     (0x00000006UL) /**< The DAC channel 6 */
#define CY_AUTANALOG_DAC_CHAN_CFG7                     (0x00000007UL) /**< The DAC channel 7 */
#define CY_AUTANALOG_DAC_CHAN_CFG8                     (0x00000008UL) /**< The DAC channel 8 */
#define CY_AUTANALOG_DAC_CHAN_CFG9                     (0x00000009UL) /**< The DAC channel 9 */
#define CY_AUTANALOG_DAC_CHAN_CFG10                    (0x0000000AUL) /**< The DAC channel 10 */
#define CY_AUTANALOG_DAC_CHAN_CFG11                    (0x0000000BUL) /**< The DAC channel 11 */
#define CY_AUTANALOG_DAC_CHAN_CFG12                    (0x0000000CUL) /**< The DAC channel 12 */
#define CY_AUTANALOG_DAC_CHAN_CFG13                    (0x0000000DUL) /**< The DAC channel 13 */
#define CY_AUTANALOG_DAC_CHAN_CFG14                    (0x0000000EUL) /**< The DAC channel 14 */
#define CY_AUTANALOG_DAC_CHAN_CFG15                    (0x0000000FUL) /**< The DAC channel 15 */

/** The set of masks for defining the DAC channels */
#define CY_AUTANALOG_DAC_CHAN_MASK0                    (0x00000001UL) /**< The mask for channel 0 */
#define CY_AUTANALOG_DAC_CHAN_MASK1                    (0x00000002UL) /**< The mask for channel 1 */
#define CY_AUTANALOG_DAC_CHAN_MASK2                    (0x00000004UL) /**< The mask for channel 2 */
#define CY_AUTANALOG_DAC_CHAN_MASK3                    (0x00000008UL) /**< The mask for channel 3 */
#define CY_AUTANALOG_DAC_CHAN_MASK4                    (0x00000010UL) /**< The mask for channel 4 */
#define CY_AUTANALOG_DAC_CHAN_MASK5                    (0x00000020UL) /**< The mask for channel 5 */
#define CY_AUTANALOG_DAC_CHAN_MASK6                    (0x00000040UL) /**< The mask for channel 6 */
#define CY_AUTANALOG_DAC_CHAN_MASK7                    (0x00000080UL) /**< The mask for channel 7 */
#define CY_AUTANALOG_DAC_CHAN_MASK8                    (0x00000100UL) /**< The mask for channel 8 */
#define CY_AUTANALOG_DAC_CHAN_MASK9                    (0x00000200UL) /**< The mask for channel 9 */
#define CY_AUTANALOG_DAC_CHAN_MASK10                   (0x00000400UL) /**< The mask for channel 10 */
#define CY_AUTANALOG_DAC_CHAN_MASK11                   (0x00000800UL) /**< The mask for channel 11 */
#define CY_AUTANALOG_DAC_CHAN_MASK12                   (0x00001000UL) /**< The mask for channel 12 */
#define CY_AUTANALOG_DAC_CHAN_MASK13                   (0x00002000UL) /**< The mask for channel 13 */
#define CY_AUTANALOG_DAC_CHAN_MASK14                   (0x00004000UL) /**< The mask for channel 14 */

/** \} group_autanalog_dac_macros */

/***************************************
*       Enumerated Types
***************************************/

/**
* \addtogroup group_autanalog_dac_enums
* \{
*/

/**
 * Defines the connection topology for the DAC,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_TOPO_DIRECT                     = 0UL, /**< The DAC drives the output directly */
    CY_AUTANALOG_DAC_TOPO_DIRECT_WITH_TRACK_CAP      = 1UL, /**< The DAC drives the output directly
                                                             *   with a Ctrack capacitor at the output */
    CY_AUTANALOG_DAC_TOPO_DIRECT_WITH_TRACK_HOLD_CAP = 2UL, /**< The DAC drives output directly
                                                             *   with Ctrack and Chold capacitors
                                                             *   at the output */
    CY_AUTANALOG_DAC_TOPO_BUFFERED_INTERNAL          = 3UL, /**< The output of the DAC is buffered
                                                             *   (for internal connections only) */
    CY_AUTANALOG_DAC_TOPO_BUFFERED_EXTERNAL          = 4UL, /**< The output of the DAC is buffered
                                                             *   for internal or external connections */
} cy_en_autanalog_dac_topo_cfg_t;


/**
 * Defines the source of the reference voltage for the DAC,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_VREF_MUX_OUT = 0UL, /**< The DAC reference is driven by the reference multiplexer,
                                          *   see \ref cy_en_autanalog_dac_vref_mux_t. This option requires
                                          *   that \ref cy_stc_autanalog_dac_sta_t::refBuffPwr be set to a value
                                          *   other than OFF */
    CY_AUTANALOG_DAC_VREF_VDDA    = 1UL, /**< The DAC reference is driven directly from the Vdda.
                                          *   As this path does not use the DAC reference buffer,
                                          *   \ref cy_stc_autanalog_dac_sta_t::refBuffPwr should be set to OFF */
} cy_en_autanalog_dac_vref_sel_t;


/**
 * Defines Power mode for the reference buffer.
 * Each power setting consumes different levels of the current
 * and supports a different input range and gain bandwidth.
 * The charge pump is used to increase the input range to the rails.\n
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_REF_BUF_PWR_OFF             =  0UL, /**< The power mode for the buffer is OFF,\n
                                                          *   the buffer is disabled */
    CY_AUTANALOG_DAC_REF_BUF_PWR_ULTRA_LOW       =  1UL, /**< The power mode for the buffer is ULTRA LOW,\n
                                                          *   the charge pump is OFF,\n
                                                          *   the buffer quiescent current is 15uA,\n
                                                          *   the gain bandwidth is 30kHz; */
    CY_AUTANALOG_DAC_REF_BUF_PWR_ULTRA_LOW_RAIL  =  2UL, /**< The power mode for the buffer is ULTRA LOW,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 35uA,\n
                                                          *   the gain bandwidth is 30kHz; */
    CY_AUTANALOG_DAC_REF_BUF_PWR_LOW_RAIL        =  4UL, /**< The power mode for the buffer is LOW,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 150uA,\n
                                                          *   the gain bandwidth is 350kHz; */
    CY_AUTANALOG_DAC_REF_BUF_PWR_MEDIUM_RAIL     =  6UL, /**< The power mode for the buffer is MEDIUM,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 200uA,\n
                                                          *   the gain bandwidth is 700kHz; */
    CY_AUTANALOG_DAC_REF_BUF_PWR_HIGH            =  7UL, /**< The power mode for the buffer is HIGH,\n
                                                          *   the charge pump is OFF,\n
                                                          *   the buffer quiescent current is 400uA,\n
                                                          *   the gain bandwidth is 1.75MHz;
                                                          *   \note This is the recommended power mode for
                                                          *   the DAC reference buffer when the DAC reference
                                                          *   is 0.9V or less. */
    CY_AUTANALOG_DAC_REF_BUF_PWR_HIGH_RAIL       =  8UL, /**< The power mode for the buffer is HIGH,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 600uA,\n
                                                          *   the gain bandwidth is 1.75MHz; */
    CY_AUTANALOG_DAC_REF_BUF_PWR_ULTRA_HIGH_RAIL = 10UL, /**< The power mode for the buffer is ULTRA HIGH,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 800uA,\n
                                                          *   the gain bandwidth is 2.8MHz; */
} cy_en_autanalog_dac_ref_buf_pwr_t;


/**
 * Defines Power mode for the output buffer.
 * Each power setting consumes different levels of the current
 * and supports a different input range and gain bandwidth.
 * The charge pump is used to increase the input range to the rails.\n
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_OUT_BUF_PWR_OFF             =  0UL, /**< The power mode for the buffer is OFF,\n
                                                          *   the buffer is disabled */
    CY_AUTANALOG_DAC_OUT_BUF_PWR_ULTRA_LOW       =  1UL, /**< The power mode for the buffer is ULTRA LOW,\n
                                                          *   the charge pump is OFF,\n
                                                          *   the buffer quiescent current is 15uA,\n
                                                          *   the output drive capability is 10uA.
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is INTERNAL\n
                                                          *      the gain bandwidth is 30kHz;\n
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is EXTERNAL\n
                                                          *      the gain bandwidth is 100kHz; */
    CY_AUTANALOG_DAC_OUT_BUF_PWR_ULTRA_LOW_RAIL  =  2UL, /**< The power mode for the buffer is ULTRA LOW,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 35uA,\n
                                                          *   the output drive capability is 10uA.
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is INTERNAL\n
                                                          *      the gain bandwidth is 30kHz;\n
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is EXTERNAL\n
                                                          *      the gain bandwidth is 100kHz; */
    CY_AUTANALOG_DAC_OUT_BUF_PWR_LOW_RAIL        =  4UL, /**< The power mode for the buffer is LOW,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 150uA,\n
                                                          *   the output drive capability is 100uA.
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is INTERNAL\n
                                                          *      the gain bandwidth is 350kHz;\n
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is EXTERNAL\n
                                                          *      the gain bandwidth is 1.2MHz; */
    CY_AUTANALOG_DAC_OUT_BUF_PWR_MEDIUM_RAIL     =  6UL, /**< The power mode for the buffer is MEDIUM,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 200uA,\n
                                                          *   the output drive capability is 1mA.
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is INTERNAL\n
                                                          *      the gain bandwidth is 700kHz;\n
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is EXTERNAL\n
                                                          *      the gain bandwidth is 2.4MHz; */
    CY_AUTANALOG_DAC_OUT_BUF_PWR_HIGH_RAIL       =  8UL, /**< The power mode for the buffer is HIGH,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 600uA,\n
                                                          *   the output drive capability is 1mA.
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is INTERNAL\n
                                                          *      the gain bandwidth is 1.75MHz;\n
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is EXTERNAL\n
                                                          *      the gain bandwidth is 6MHz; */
    CY_AUTANALOG_DAC_OUT_BUF_PWR_ULTRA_HIGH_RAIL = 10UL, /**< The power mode for the buffer is ULTRA HIGH,\n
                                                          *   the charge pump is ON,\n
                                                          *   the buffer quiescent current is 800uA,\n
                                                          *   the output drive capability is 10mA.
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is INTERNAL\n
                                                          *      the gain bandwidth is 2.8MHz;\n
                                                          *   If cy_stc_autanalog_dac_sta_t::outBuffPwr is EXTERNAL\n
                                                          *      the gain bandwidth is 7.5MHz; */
} cy_en_autanalog_dac_out_buf_pwr_t;


/**
 * Defines the multiplexed reference voltage to be used for the DAC,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_VREF_MUX_VBGR      = 0UL, /**< The DAC reference is VBGR */
    CY_AUTANALOG_DAC_VREF_MUX_CTB0_OA0  = 1UL, /**< The DAC reference is driven by the Opamp0 output in the CTB0 */
    CY_AUTANALOG_DAC_VREF_MUX_CTB0_OA1  = 2UL, /**< The DAC reference is driven by the Opamp1 output in the CTB0 */
    CY_AUTANALOG_DAC_VREF_MUX_CTB1_OA0  = 3UL, /**< The DAC reference is driven by the Opamp0 output in the CTB1 */
    CY_AUTANALOG_DAC_VREF_MUX_CTB1_OA1  = 4UL, /**< The DAC reference is driven by the Opamp1 output in the CTB1 */
    CY_AUTANALOG_DAC_VREF_MUX_PRB_OUT0  = 6UL, /**< The DAC reference is Vref0 from the PRB0 */
    CY_AUTANALOG_DAC_VREF_MUX_PRB_OUT1  = 7UL, /**< The DAC reference is Vref1 from the PRB1 */

} cy_en_autanalog_dac_vref_mux_t;


/**
 * Defines the operating mode of the DAC, refer to \ref group_autanalog_dac_mode.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_LUT_OS_ONE_QUAD    = 0UL, /**< The LUT mode is One Shot One Quadrant */
    CY_AUTANALOG_DAC_LUT_OS_TWO_QUAD    = 1UL, /**< The LUT mode is One Shot Two Quadrant */
    CY_AUTANALOG_DAC_LUT_OS_FOUR_QUAD   = 2UL, /**< The LUT mode is One Shot Four Quadrant */
    CY_AUTANALOG_DAC_LUT_CONT_ONE_QUAD  = 3UL, /**< The LUT mode is Continuous One Quadrant */
    CY_AUTANALOG_DAC_LUT_CONT_TWO_QUAD  = 4UL, /**< The LUT mode is Continuous Two Quadrant */
    CY_AUTANALOG_DAC_LUT_CONT_FOUR_QUAD = 5UL, /**< The LUT mode is Continuous Four Quadrant */
    CY_AUTANALOG_DAC_WAVEFORM_MODE_ADDR = 6UL, /**< The LUT operates in Address mode */
    CY_AUTANALOG_DAC_WAVEFORM_MODE_DATA = 7UL, /**< The LUT operates in Data mode */

} cy_en_autanalog_dac_oper_mode_t;


/**
 * The step selector for the DAC,
 * defines the selected step movement in the LUT.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_STEP_SEL_DISABLED = 0UL, /**< The selector is not used,
                                               *   the step value is 1 by default */
    CY_AUTANALOG_DAC_STEP_SEL_0        = 1UL, /**< The step value stored in the array
                                               *   cy_stc_autanalog_dac_sta_t::stepVal
                                               *   at index zero is used */
    CY_AUTANALOG_DAC_STEP_SEL_1        = 2UL, /**< The step value stored in the array
                                               *   cy_stc_autanalog_dac_sta_t::stepVal
                                               *   at index one is used */
    CY_AUTANALOG_DAC_STEP_SEL_2        = 3UL, /**< The step value stored in the array
                                               *   cy_stc_autanalog_dac_sta_t::stepVal
                                               *   at index two is used */
} cy_en_autanalog_dac_step_sel_t;


/**
 * The DAC range status selector,
 * defines the selected range conditions for the DAC output value.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_STATUS_SEL_DISABLED = 0UL, /**< The selector is not used,
                                                 *   the DAC output is not validated for
                                                 *   compliance with the range conditions */
    CY_AUTANALOG_DAC_STATUS_SEL_0        = 1UL, /**< The DAC output range stored in the array
                                                 *   cy_stc_autanalog_dac_sta_t::chLimitCfg
                                                 *   at index zero is used for validation */
    CY_AUTANALOG_DAC_STATUS_SEL_1        = 2UL, /**< The DAC output range stored in the array
                                                 *   cy_stc_autanalog_dac_sta_t::chLimitCfg
                                                 *   at index one is used for validation */
    CY_AUTANALOG_DAC_STATUS_SEL_2        = 3UL, /**< The DAC output range stored in the array
                                                 *   cy_stc_autanalog_dac_sta_t::chLimitCfg
                                                 *   at index two is used for validation */
} cy_en_autanalog_dac_stat_sel_t;


/**
 * Defines the drive mode for the DAC output,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_OUT_DRIVE_MODE_EN   = 0UL, /**< The DAC output is enabled (outputs appropriate value) */
    CY_AUTANALOG_DAC_OUT_DRIVE_MODE_HIZ  = 1UL, /**< The DAC output is disabled (output is tri-state) */
    CY_AUTANALOG_DAC_OUT_DRIVE_MODE_VREF = 2UL, /**< The DAC output is disabled (output is Vssa or Vref,
                                                 *   depends on parameter
                                                 *   \ref cy_stc_autanalog_dac_sta_t::bottomSel) */
} cy_en_autanalog_dac_out_drive_mode_t;


/**
 * Defines the range detection conditions for the DAC output,
 * refer to cy_stc_autanalog_dac_ch_limit_t.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_CH_LIMIT_BELOW   = 0UL, /**< The DAC value must satisfy the following:\n
                                              *   Value < cy_stc_autanalog_dac_ch_limit_t::low */
    CY_AUTANALOG_DAC_CH_LIMIT_INSIDE  = 1UL, /**< The DAC value must satisfy the following:\n
                                              *   (cy_stc_autanalog_dac_ch_limit_t::low <= Value) AND
                                              *   (Value < cy_stc_autanalog_dac_ch_limit_t::high) */
    CY_AUTANALOG_DAC_CH_LIMIT_ABOVE   = 2UL, /**< The DAC value must satisfy the following:\n
                                              *   Value > cy_stc_autanalog_dac_ch_limit_t::high */
    CY_AUTANALOG_DAC_CH_LIMIT_OUTSIDE = 3UL, /**< The DAC value must satisfy the following:\n
                                              *   (Value < cy_stc_autanalog_dac_ch_limit_t::low) OR
                                              *   (Value >= cy_stc_autanalog_dac_ch_limit_t::high) */
} cy_en_autanalog_dac_limit_t;


/**
 * Defines the direction of movement in the LUT or the increment/decrement of the DAC value
 * using the State Transition table, refer to cy_stc_autanalog_stt_dac_t.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_DAC_DIRECTION_DISABLED = 0UL, /**< Direction is NOT selected */
    CY_AUTANALOG_DAC_DIRECTION_FORWARD  = 1UL, /**< Forward/Increment */
    CY_AUTANALOG_DAC_DIRECTION_REVERSE  = 2UL, /**< Backward/Decrement */

} cy_en_autanalog_stt_dac_dir_t;

/** \} group_autanalog_dac_enums */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_autanalog_dac_data_structures
* \{
*/

/**
 * The configuration structure of the DAC channel.
 * Used in \ref cy_stc_autanalog_dac_sta_t
 */
typedef struct
{
    uint16_t                        startAddr;     /**< Start address of the waveform in the LUT.
                                                     *  When the DAC is triggered
                                                     *  (refer to \ref cy_stc_autanalog_stt_dac_t),
                                                     *  it outputs the value at START_ADDR.
                                                     *  The START_ADDR is word (16 bits) aligned and the value ranges
                                                     *  from 0 to 511 */
    uint16_t                        endAddr;       /**< End address of the waveform in the LUT.
                                                     *  The end address must be greater than or equal to
                                                     *  the start address (START_ADDR).
                                                     *  The END_ADDR is word (16 bit) aligned and the value ranges
                                                     *  from 0 to 511 */
    cy_en_autanalog_dac_oper_mode_t operMode;      /**< The DAC operating mode,
                                                     *  for more details, refer to \ref group_autanalog_dac_mode */
    bool                            sampleAndHold; /**< Enables Sample and Hold functionality for the DAC,
                                                     *  for more details, refer to \ref group_autanalog_dac_sampleAndHold */
    cy_en_autanalog_dac_step_sel_t  stepSel;       /**< The step selector for the DAC */
    cy_en_autanalog_dac_stat_sel_t  statSel;       /**< The status selector for the DAC output range */

} cy_stc_autanalog_dac_ch_t;


/**
 * The channel range detection configuration structure.
 * Used in \ref cy_stc_autanalog_dac_sta_t.
 */
typedef struct
{
    cy_en_autanalog_dac_limit_t cond; /**< Range detection condition */
    int16_t                     low;  /**< Low threshold for range detection */
    int16_t                     high; /**< High threshold for range detection */

} cy_stc_autanalog_dac_ch_limit_t;


/**
 * The configuration structure of the waveform.
 * Used in \ref cy_stc_autanalog_dac_t.
 */
typedef struct
{
    uint16_t                               numSamples;       /**< The number of samples in the waveform */
    const int16_t                        * waveformData;     /**< The pointer to the waveform data */
    bool                                   isDriveModeArray; /**< Indicates that all samples in the waveform array
                                                              *   have the same drive mode configuration */
    cy_en_autanalog_dac_out_drive_mode_t * driveMode;        /**< The pointer to the drive mode configurations */

}   cy_stc_autanalog_dac_waveform_t;


/**
* Defines the static configuration structure, see \ref group_autanalog_dac_static.
* Used in \ref cy_stc_autanalog_dac_t and \ref Cy_AutAnalog_DAC_LoadStaticConfig.
*/
typedef struct
{
    uint16_t                          lpDivDac;                                 /**< The Low Power clock divider,
                                                                                 *   actual divide value is DIV_VAL + 1,
                                                                                 *   valid range is 1..1024.
                                                                                 *   For more details, refer to
                                                                                 *   \ref group_autanalog_dac_clock
                                                                                 *   chapter
                                                                                 */
    cy_en_autanalog_dac_topo_cfg_t    topology;                                 /**< The DAC topology,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_topology
                                                                                 *   chapter */
    cy_en_autanalog_dac_vref_sel_t    vrefSel;                                  /**< The DAC source of the Vref,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_vref
                                                                                 *   chapter */
    bool                              deGlitch;                                 /**< Enables the DAC de-glitch functionality,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_deglitch
                                                                                 *   chapter
                                                                                 *   - FALSE - disabled;
                                                                                 *   - TRUE - enabled;
                                                                                */
    bool                              bottomSel;                                /**< The selector for the connecting the
                                                                                 *   bottom end of the R-2R resistors ladder,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_output
                                                                                 *   chapter
                                                                                 *   - FALSE - connect to Vssa;
                                                                                 *   - TRUE - connect to Vref;
                                                                                 */
    bool                              disabledMode;                             /**< The selector for the DAC output value
                                                                                 *   when the output is disabled,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_output
                                                                                 *   chapter
                                                                                 *   - FALSE - tri-state output;
                                                                                 *   - TRUE - output Vssa or Vref,
                                                                                 *     depends on the setting in the
                                                                                 *     cy_stc_autanalog_dac_sta_t::bottomSel
                                                                                 *     field;
                                                                                 */
    cy_en_autanalog_dac_ref_buf_pwr_t refBuffPwr;                               /**< The power mode of the
                                                                                 *   reference voltage buffer,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_topology
                                                                                 *   chapter */
    cy_en_autanalog_dac_out_buf_pwr_t outBuffPwr;                               /**< The power mode of the
                                                                                 *   output voltage buffer,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_topology
                                                                                 *   chapter */
    bool                              sign;                                     /**< Output data as a unsigned/signed value,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_sign
                                                                                 *   chapter
                                                                                 *   - FALSE - unsigned 12-bit number;
                                                                                 *   - TRUE - virtual signed 12-bits number;
                                                                                 */
    cy_en_autanalog_dac_vref_mux_t    vrefMux;                                  /**< Multiplexed reference voltage,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_vref */
    uint8_t                           sampleTime;                               /**< The sample time selection for the
                                                                                 *   cy_stc_autanalog_dac_ch_t::sampleAndHold.
                                                                                 *   Actual value is SAMPLE_TIME + 1,
                                                                                 *   range 1..256
                                                                                 *   \note The sample time is measured
                                                                                 *   in terms of the number of clock cycles.
                                                                                 */
    uint8_t                           stepVal[CY_AUTANALOG_DAC_STEP_VAL_NUM];   /**< The DAC step value.
                                                                                 *   Actual step value is STEP_VAL + 1.
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_mode
                                                                                 *   chapter
                                                                                 */
    uint8_t                           deGlitchTime;                             /**< The DAC de-glitch time,
                                                                                 *   for more details, refer to
                                                                                 *   \ref group_autanalog_dac_deglitch
                                                                                 *   Actual value is DEGLITCH_CNT + 1,
                                                                                 *   range 1..256
                                                                                 *   \note The sample time is measured
                                                                                 *   in terms of the number of clock cycles.
                                                                                 */
    cy_stc_autanalog_dac_ch_t       * chCfg[CY_AUTANALOG_DAC_CH_CFG_NUM];       /**< The array of pointers to the
                                                                                 *   configuration structures for the
                                                                                 *   DAC channels, a NULL element
                                                                                 *   means that the channel structure
                                                                                 *   is not configured.
                                                                                 */
    cy_stc_autanalog_dac_ch_limit_t * chLimitCfg[CY_AUTANALOG_DAC_CH_RANGE_NUM];/**< The array of pointers to the
                                                                                 *   configuration structures for the
                                                                                 *   DAC output range detection,
                                                                                 *   a NULL element means that the
                                                                                 *   range detection is not configured.
                                                                                 */
} cy_stc_autanalog_dac_sta_t;


/**
* The configuration structure to set up the entire DAC.
* Used in \ref Cy_AutAnalog_DAC_LoadConfig.
*/
typedef struct
{
    /* Static part of configuration */
    cy_stc_autanalog_dac_sta_t      * dacStaCfg; /**< The pointer to a static part of the DAC configuration */

    /* Waveform part of configuration */
    cy_stc_autanalog_dac_waveform_t * waveform;  /**< The pointer to a waveform part of the DAC configuration */

} cy_stc_autanalog_dac_t;


/**
 * The DAC section in the State Transition Table state.
 * Used in \ref cy_stc_autanalog_stt_t.
 */
typedef struct
{
    bool                          unlock;    /**< DAC Unlock\n
                                              * - FALSE - Locked:\n
                                              *     Data from fields
                                              *     enable, trigger, channel and direction
                                              *     of this structure
                                              *     are NOT taken into account in
                                              *     the corresponding state of STT;
                                              * - TRUE - Unlocked:\n
                                              *     Data from fields
                                              *     enable, trigger, channel and direction
                                              *     of this structure
                                              *     are used in the STT corresponding state;
                                              */
    bool                          enable;    /**< Enables the DAC. */
    bool                          trigger;   /**< This field initiates the DAC operation
                                              *   per selected channel. */
    uint8_t                       channel;   /**< The DAC channel selector,
                                              *   refer to cy_stc_autanalog_dac_sta_t::chCfg
                                              */
    cy_en_autanalog_stt_dac_dir_t direction; /**< Defines the direction of movement in the LUT or
                                              *   the increment/decrement of the DAC value
                                              */
} cy_stc_autanalog_stt_dac_t;

/** \} group_autanalog_dac_data_structures */

/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_autanalog_dac_functions
* \{
*/

/**
* \addtogroup group_autanalog_dac_functions_init
* This set of functions is used to configure the DAC.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_LoadConfig
****************************************************************************//**
*
* Configures the DAC per provided static and waveform settings.
*
* \note Changing Vref from external to internal (or vice versa) or
* enabling/disabling buffers requires a new initialization delay for the DAC subsystem.
* Use a global API \ref Cy_AutAnalog_LoadConfig instead of the local API.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dacCfg
* The pointer to a structure containing the static and waveform parts of the configuration data
* for the entire DAC.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_DAC_LoadConfig(uint8_t dacIdx, const cy_stc_autanalog_dac_t * dacCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_LoadStaticConfig
****************************************************************************//**
*
* Configures the DAC per settings in the static configuration structure.
*
* \note Changing Vref from external to internal (or vice versa) or
* enabling/disabling buffers requires a new initialization delay for the DAC subsystem.
* Use a global API \ref Cy_AutAnalog_LoadConfig instead of the local API.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dacStaCfg
* The pointer to a structure containing static configuration data for the DAC.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_DAC_LoadStaticConfig(uint8_t dacIdx, const cy_stc_autanalog_dac_sta_t * dacStaCfg);

/** \} group_autanalog_dac_functions_init */


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_GetLimitStatus
****************************************************************************//**
*
* Provides the range detection status for the DAC channels, except FW channel #15.
* The DAC sets this bit for each channel when the condition specified by the
* \ref cy_stc_autanalog_dac_sta_t::chLimitCfg is met.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \return
* Range detection status. Compare this value with one of the masks for the DAC channels.
* \note Under invalid DAC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE uint16_t Cy_AutAnalog_DAC_GetLimitStatus(uint8_t dacIdx)
{
    uint32_t baseAddr;

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr) ?
           (uint16_t)_FLD2VAL(DAC_STA_RANGE_STATUS_CHAN_RANGE_STATUS, AUTANALOG_DAC_RANGE_STATUS(baseAddr)) : 0U;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_ClearLimitStatus
****************************************************************************//**
*
* Clears the range detection status for the DAC channels.
* See \ref Cy_AutAnalog_DAC_GetLimitStatus
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
* \note Under invalid DAC index, the function has no effect.
*
* \param chMask
* The combined mask for DAC channels that require a reset of their range detection status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_DAC_ClearLimitStatus(uint8_t dacIdx, uint16_t chMask)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_DAC_CH_RANGE_STATUS(chMask));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr))
    {
        AUTANALOG_DAC_RANGE_STATUS(baseAddr) = _VAL2FLD(DAC_STA_RANGE_STATUS_CHAN_RANGE_STATUS, chMask);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_WriteNextSample
****************************************************************************//**
*
* Loads a value that will update the DAC output on the next refresh cycle,
* applicable to FW channel #15 only.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
* \note Under invalid DAC index, the function has no effect.
*
* \param sample
* The sample value to update of the DAC output for the next refresh cycle.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_DAC_WriteNextSample(uint8_t dacIdx, int32_t sample)
{
    uint32_t baseAddr;

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr))
    {
        CY_REG32_CLR_SET(AUTANALOG_DAC_FW_DAC_VAL_NXT(baseAddr), DAC_STA_FW_DAC_VAL_NXT_VALUE, (uint32_t)sample);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_ReadNextSample
****************************************************************************//**
*
* Reads the DAC output register.
* Applicable to FW channel #15 only.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \return
* The sample value from the DAC output.
* \note If the DAC index is not valid, zero is returned in the result.
* \note The DAC HW does not preserve the sign of the output value.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_AutAnalog_DAC_ReadNextSample(uint8_t dacIdx)
{
    uint32_t baseAddr;

    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 1, 'Review shows that type conversion from unsigned to signed does not have any negative drawbacks');
    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr) ?
           (int32_t)_FLD2VAL(DAC_STA_FW_DAC_VAL_NXT_VALUE, AUTANALOG_DAC_FW_DAC_VAL_NXT(baseAddr)) : 0;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
}


/**
* \addtogroup group_autanalog_dac_functions_lut
* This set of functions is used for data handling in the DAC look-up table.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_ReadSample
****************************************************************************//**
*
* Reads data for a DAC sample from the look-up table at the defined index.
* \note The DAC should not output a waveform while this API is being called.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dataIdx
* The sample index in the DAC look-up table.
*
* \return
* The sample value from the DAC look-up table.
* \note Under invalid DAC index, "zero" returns in the result.
* \note The DAC HW does not preserve the sign of the output value.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_AutAnalog_DAC_Data_ReadSample(uint8_t dacIdx, uint16_t dataIdx)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_DAC_LUT_IDX(dataIdx));

    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 1, 'Review shows that type conversion from unsigned to signed does not have any negative drawbacks');
    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr) ?
           (int32_t)_FLD2VAL(DAC_SRAM_WAVEFORM, AUTANALOG_DAC_LUT(baseAddr, dataIdx)) : 0;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_GetDriveMode
****************************************************************************//**
*
* Reads the drive mode of the DAC output from the look-up table at the defined index.
* \note The DAC should not output a waveform while this API is being called.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dataIdx
* The sample index in the DAC look-up table.
*
* \return
* The configuration of the DAC output drive mode, see \ref cy_en_autanalog_dac_out_drive_mode_t.
* \note Under invalid DAC index, CY_AUTANALOG_DAC_OUT_DRIVE_MODE_EN returns in the result.
*
*******************************************************************************/
__STATIC_INLINE cy_en_autanalog_dac_out_drive_mode_t Cy_AutAnalog_DAC_Data_GetDriveMode(uint8_t dacIdx, uint16_t dataIdx)
{
    cy_en_autanalog_dac_out_drive_mode_t result = CY_AUTANALOG_DAC_OUT_DRIVE_MODE_EN;

    uint32_t baseAddr;
    uint32_t regVal;

    CY_ASSERT_L2(AUTANALOG_DAC_LUT_IDX(dataIdx));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr))
    {
        regVal = _FLD2VAL(DAC_SRAM_OUT_DM, AUTANALOG_DAC_LUT(baseAddr, dataIdx));

        if ((uint32_t)CY_AUTANALOG_DAC_OUT_DRIVE_MODE_EN == regVal)
        {
            result = CY_AUTANALOG_DAC_OUT_DRIVE_MODE_EN;
        }
        else if ((uint32_t)CY_AUTANALOG_DAC_OUT_DRIVE_MODE_HIZ == regVal)
        {
            result = CY_AUTANALOG_DAC_OUT_DRIVE_MODE_HIZ;
        }
        else if ((uint32_t)CY_AUTANALOG_DAC_OUT_DRIVE_MODE_VREF == regVal)
        {
            result = CY_AUTANALOG_DAC_OUT_DRIVE_MODE_VREF;
        }
        else
        {
            ;    /* Required by Rule 15.7 MISRA2012 */
        }
    }

    return result;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_WriteSample
****************************************************************************//**
*
* Writes data for a DAC sample to a look-up table at a defined index.
* \note The DAC should not output a waveform while this API is being called.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dataIdx
* The sample index in the DAC look-up table.
* \note Under invalid DAC index, the function has no effect.
*
* \param sample
* The sample value for the DAC look-up table.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_DAC_Data_WriteSample(uint8_t dacIdx, uint16_t dataIdx, int32_t sample)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_DAC_LUT_IDX(dataIdx));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr))
    {
        CY_REG32_CLR_SET(AUTANALOG_DAC_LUT(baseAddr, dataIdx), DAC_SRAM_WAVEFORM, (uint32_t)sample);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_SetDriveMode
****************************************************************************//**
*
* Writes the drive mode of the DAC output to the look-up table at a defined index.
* \note The DAC should not output a waveform while this API is being called.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dataIdx
* The sample index in the DAC look-up table.
* \note Under invalid DAC index, the function has no effect.
*
* \param driveMode
* The configuration of the DAC output drive mode, see \ref cy_en_autanalog_dac_out_drive_mode_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_DAC_Data_SetDriveMode(uint8_t dacIdx, uint16_t dataIdx, cy_en_autanalog_dac_out_drive_mode_t driveMode)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_DAC_LUT_IDX(dataIdx));
    CY_ASSERT_L2(AUTANALOG_DAC_OUT_DM(driveMode));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr))
    {
        CY_REG32_CLR_SET(AUTANALOG_DAC_LUT(baseAddr, dataIdx), DAC_SRAM_OUT_DM, driveMode);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_ReadWaveform
****************************************************************************//**
*
* Reads a block of samples for the entire waveform from the DAC look-up table,
* starting from a defined index.
* \note The DAC should not output a waveform while this API is being called.
* \note The function does not apply if the channel operMode is set to
* CY_AUTANALOG_DAC_WAVEFORM_MODE_DATA, see \ref cy_stc_autanalog_dac_ch_t::operMode.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dataIdx
* Start index of the DAC waveform in the look-up table.
* See \ref cy_stc_autanalog_dac_ch_t::startAddr
*
* \param numSamples
* The number of samples for the DAC waveform:
* numSamples = endAddr - startAddr + 1;
* see \ref cy_stc_autanalog_dac_ch_t.
*
* \param waveform
* The pointer to the location of the DAC waveform data.
*
* \return
* Status of execution, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_DAC_Data_ReadWaveform(uint8_t dacIdx, uint16_t dataIdx, uint16_t numSamples, int32_t * waveform);


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_GetDriveModeArray
****************************************************************************//**
*
* Reads the block of Drive mode configurations for the DAC output from the look-up table.
* \note The DAC should not output a waveform while this API is being called.
* \note The function does not apply if the channel operMode is set to
* CY_AUTANALOG_DAC_WAVEFORM_MODE_DATA, see \ref cy_stc_autanalog_dac_ch_t::operMode.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dataIdx
* Start index of the waveform in the DAC look-up table.
* See \ref cy_stc_autanalog_dac_ch_t::startAddr
*
* \param numSamples
* The number of samples for the DAC waveform:
* numSamples = endAddr - startAddr + 1;
* see \ref cy_stc_autanalog_dac_ch_t.
*
* \param driveModeArray
* The pointer to the location of the DAC output drive mode configurations,
* see \ref cy_en_autanalog_dac_out_drive_mode_t.
*
* \return
* Status of execution, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_DAC_Data_GetDriveModeArray(uint8_t dacIdx, uint16_t dataIdx, uint16_t numSamples, cy_en_autanalog_dac_out_drive_mode_t * driveModeArray);


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_WriteWaveform
****************************************************************************//**
*
* Writes a block of samples for the entire waveform into the DAC look-up table,
* starting from a defined index.
* \note The DAC should not output a waveform while this API is being called.
* \note The function does not apply if the channel operMode is set to
* CY_AUTANALOG_DAC_WAVEFORM_MODE_DATA, see \ref cy_stc_autanalog_dac_ch_t::operMode.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dataIdx
* Start index of the waveform in the DAC look-up table.
* See \ref cy_stc_autanalog_dac_ch_t::startAddr
*
* \param numSamples
* The number of samples for the DAC waveform:
* numSamples = endAddr - startAddr + 1;
* see \ref cy_stc_autanalog_dac_ch_t.
*
* \param waveform
* The pointer to the location of the DAC waveform data.
*
* \return
* Status of execution, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_DAC_Data_WriteWaveform(uint8_t dacIdx, uint16_t dataIdx, uint16_t numSamples, const int32_t * waveform);


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_SetDriveModeArray
****************************************************************************//**
*
* Writes a block of Drive mode configurations for the DAC output to the look-up table.
* \note The DAC should not output a waveform while this API is being called.
* \note The function does not apply if the channel operMode is set to
* CY_AUTANALOG_DAC_WAVEFORM_MODE_DATA, see \ref cy_stc_autanalog_dac_ch_t::operMode.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
*
* \param dataIdx
* Start index of the waveform in the DAC look-up table.
* See \ref cy_stc_autanalog_dac_ch_t::startAddr
*
* \param numSamples
* The number of samples for the waveform:
* numSamples = endAddr - startAddr + 1;
* see \ref cy_stc_autanalog_dac_ch_t.
*
* \param driveModeArray
* The pointer to the location of the DAC output drive mode configurations,
* see \ref cy_en_autanalog_dac_out_drive_mode_t.
*
* \return
* Status of execution, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_DAC_Data_SetDriveModeArray(uint8_t dacIdx, uint16_t dataIdx, uint16_t numSamples, const cy_en_autanalog_dac_out_drive_mode_t * driveModeArray);


/*******************************************************************************
* Function Name: Cy_AutAnalog_DAC_Data_SetDriveModeAll
****************************************************************************//**
*
* Modifies the DAC output Drive mode for the entire look-up table
* according to the supplied configuration.
* \note The DAC should not output a waveform while this API is being called.
* \note The function does not apply if the channel operMode is set to
* CY_AUTANALOG_DAC_WAVEFORM_MODE_DATA, see \ref cy_stc_autanalog_dac_ch_t::operMode.
*
* \param dacIdx
* The index of the DAC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::dac
* \note Under invalid DAC index, the function has no effect.
*
* \param driveModeAll
* The DAC output drive mode configuration,
* see \ref cy_en_autanalog_dac_out_drive_mode_t.
*
*******************************************************************************/
void Cy_AutAnalog_DAC_Data_SetDriveModeAll(uint8_t dacIdx, const cy_en_autanalog_dac_out_drive_mode_t driveModeAll);

/** \} group_autanalog_dac_functions_lut */

/** \} group_autanalog_dac_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22LPPASS_DAC */

#endif /** !defined(CY_AUTANALOG_DAC_H) */

/** \} group_autanalog_dac */

/* [] END OF FILE */
