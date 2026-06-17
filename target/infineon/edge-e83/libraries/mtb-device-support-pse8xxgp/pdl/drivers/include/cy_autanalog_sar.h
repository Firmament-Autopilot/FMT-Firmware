/***************************************************************************//**
* \file cy_autanalog_sar.h
* \version 2.0
*
* \brief
* Header file for the SAR ADC subsystem of the Autonomous Analog
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
* \addtogroup group_autanalog_sar
* \{
* This driver provides the API functions to configure the successive approximation register analog-to-digital converter
* (SAR ADC) subsystem of the Autonomous Analog.
*
* The versatile SAR ADC is an analog-to-digital converter with a dual-core 12-bit successive approximation register.
* The SAR ADC (hereafter ADC) contains a High Speed (HS) Core that can operate in Active mode with the SRSS clock up to 80 MHz
* and a Low Power (LP) Core based on the 4.096 MHz LPOSC from the Autonomous Analog.
* The HS Core is not available in DeepSleep while the LP Core is available in all power modes.
* \note Only one core can be active at a time.
*
* For more information on the ADC,
* refer to the device Architecture Technical Reference Manual (TRM).\n
* For the exact location of the pins, see the device datasheet.
*
* The key components of the ADC are:
* - The inputs selector for routing signals from external pins (GPIO) or analog-capable internal IOs (MUX);
* - A pair of Hi-Z buffers, which are in the MUX path only and can be bypassed;
* - The sampler with sample and hold circuits (S/H) for simultaneous sampling from multiple sources:
*    - 8 single-ended S/H circuits directly connected to the GPIO and available in Active mode only;
*    - 2 single-ended S/H circuits connected to the MUX IOs and available in Active mode only;
*    - 1 fully differential sampler for all sources, available in Active and Deep Sleep modes;
* - The source of reference voltages for HS/LP ADC Cores;
* - Post-processing of the ADC output;
*
* \section group_autanalog_sar_ch Channel Configuration
*
* The signal path to the ADC input is controlled by the logical channel (a high-level abstraction).
* The configuration of the ADC logical channel includes the following settings (common for HS//LP modes):
*    - assign the source for the ADC input
*      (refer to \ref cy_en_autanalog_sar_pin_hs_t for GPIO sources and
*      \ref cy_en_autanalog_sar_pin_mux_t for MUX sources accordingly);
*    - configuration of the allowable range for the ADC
*      (refer to \ref cy_en_autanalog_sar_limit_t);
*    - signed/unsigned the format for the ADC output data
*      (refer to \ref group_autanalog_sar_sign chapter);
*    - enable the averaging of the conversion result in HW;
*    - store the conversion result in the FIFO
*      (refer to \ref cy_en_autanalog_fifo_sel_t)
*    - correct the linearity of the channel - channel gain and offset
*      (refer to \ref cy_en_autanalog_sar_ch_coeff_t and \ref Cy_AutAnalog_SAR_LoadOffsetGainCorr)
*
* Also:
*    - enable the pseudo differential sampling for the single-ended ADC in HS mode
*      (refer to cy_stc_autanalog_sar_hs_chan_t::hsDiffEn and cy_stc_autanalog_sar_seq_tab_hs_t::muxMode);
*      \note Negative input correction coefficient is applicable only for
*      the second channel in Pseudo Differential sampling mode
*    - support Single-ended mode for ADC in LP mode of operation
*      (refer to cy_stc_autanalog_sar_sta_lp_t::lpDiffEn);
*    - bypass the Hi-Z buffers for MUX channels
*      (refer to cy_stc_autanalog_sar_mux_chan_t::buffBypass)
*
* 8 individually-configurable logical channels are available to the ADC in HS mode and
* 16 logical channels are available to the ADC in LP mode.
*
* The logical channels configuration is a part of the ADC \ref group_autanalog_sar_static
* (refer to cy_stc_autanalog_sar_sta_hs_t::hsGpioChan for GPIO inputs and
* \ref cy_stc_autanalog_sar_sta_t::intMuxChan for MUX inputs accordingly).
*
* \section group_autanalog_sar_static Static Configuration
*
* The static configuration contains application-specific settings
* intended to remain static for any ADC application.
* The Autonomous Controller (AC) will NOT change the static configuration during operation.
*
* The diagram below shows the static configuration for ADC in HS mode.
*
* \image html LPPASS_ADC_HS_Static.png
*
* The diagram below shows the static configuration for ADC in LP mode.
*
* \image html LPPASS_ADC_LP_Static.png
*
* The diagram below shows the static configuration for LP ADC in Single Ended mode.
*
* \image html LPPASS_ADC_LP_Static_SE.png
*
* The static configuration for the whole ADC consists of static configurations for the HS and LP parts
* (refer to \ref cy_stc_autanalog_sar_sta_hs_t, \ref cy_stc_autanalog_sar_sta_lp_t)
* and includes the following settings in total (refer to \ref cy_stc_autanalog_sar_sta_t):
*    - the reference voltage source for the HS and LP Cores of the ADC
*      (refer to cy_stc_autanalog_sar_sta_hs_t::hsVref and cy_stc_autanalog_sar_sta_lp_t::lpVref);
*    - a set of sample times for the ADC input
*      (refer to cy_stc_autanalog_sar_sta_hs_t::hsSampleTime and cy_stc_autanalog_sar_sta_lp_t::lpSampleTime);
*    - average mode settings
*      (refer to cy_stc_autanalog_sar_sta_t::accMode and cy_stc_autanalog_sar_sta_t::shiftMode);
*    - the notification of the conversion result for the selected input of the ADC or the output of the FIR filter
*      (refer to cy_stc_autanalog_sar_sta_hs_t::hsGpioResultMask and cy_stc_autanalog_sar_sta_t::muxResultMask
*      for the GPIO inputs and MUX inputs accordingly or cy_stc_autanalog_sar_sta_t::firResultMask for the FIR filter output);
*    - a set of conditions for the allowable range of the ADC
*      (refer to cy_stc_autanalog_sar_sta_t::limitCond);
*    - the presence of the logical channel ID in FIFO data (refer to cy_stc_autanalog_sar_sta_t::chanID);
*    - the ADC calibration during start-up (refer to cy_stc_autanalog_sar_sta_t::startupCal);
*
* Also:
*    - Power mode for the Hi-Z buffers
*      (refer to cy_stc_autanalog_sar_sta_t::posBufPwr and cy_stc_autanalog_sar_sta_t::negBufPwr);
*
* \section group_autanalog_sar_sequencer Sequencer and State Transition Table
*
* The sequencer is used to control the ADC to perform an automatic scan on all enabled logical channels without MCU intervention.
* Each ADC Core has its own sequencer, refer to \ref cy_stc_autanalog_sar_seq_tab_hs_t for HS mode and
* refer to \ref cy_stc_autanalog_sar_seq_tab_lp_t for LP mode. Both sequencers contain up to 32 states.
* Each state of the sequencer defines a single step in the ADC scan.

* The Autonomous Controller is able to trigger the ADC. It points to a particular step (Entry State) of the sequencer in runtime
* using the State Transition Table, refer to \ref cy_stc_autanalog_stt_sar_t.
* The next step of the sequencer is defined in the nextAction field of the sequencer configuration structure
* (refer to e.g. cy_stc_autanalog_sar_seq_tab_hs_t::nextAction):
*    - NEXT - Go to the next sequencer state to proceed to the next step in a given ADC scan;
*    - ENTRY_ADDR - Assert the SAR_EOS condition and jump to Entry State for continuous ADC scanning;
*    - STOP - Assert the SAR_DONE and SAR_EOS conditions and go to Idle to indicate the end of a scan;
*
* The remaining fields of the sequencer are (common for HS//LP modes):
*    - enable and select the appropriate sample time configuration for a particular logical channel
*      (refer to e.g. cy_stc_autanalog_sar_seq_tab_hs_t::sampleTimeEn and cy_stc_autanalog_sar_seq_tab_hs_t::sampleTime);
*    - enable the averaging for the ADC conversion result and define the average count
*      (refer to e.g. cy_stc_autanalog_sar_seq_tab_hs_t::accEn and cy_stc_autanalog_sar_seq_tab_hs_t::accCount);
*
* Also, the HS sequencer allows you to configure the following:
* - enable and select specific GPIO channels, refer to cy_stc_autanalog_sar_seq_tab_hs_t::chanEn
*   with their configurations provided in the cy_stc_autanalog_sar_sta_hs_t::hsGpioChan;
* - enable and select the operation mode for specific MUX channels, refer to cy_stc_autanalog_sar_seq_tab_hs_t::muxMode.
*   Select the configurations for the enabled MUX channels
*   cy_stc_autanalog_sar_seq_tab_hs_t::mux0Sel, cy_stc_autanalog_sar_seq_tab_hs_t::mux1Sel
*   provided in the cy_stc_autanalog_sar_sta_t::intMuxChan;
*
* Also, the LP sequencer allows you to configure the following:
* - enable the operation for the LP sampler cy_stc_autanalog_sar_seq_tab_lp_t::chanEn and
*   select the configuration for the MUX channel cy_stc_autanalog_sar_seq_tab_lp_t::mux0Sel
*   provided in the cy_stc_autanalog_sar_sta_t::intMuxChan;
*
* The ADC scan can be started by the Autonomous Controller (AC) in runtime
* per settings provided in the sequencer (refer to cy_stc_autanalog_sar_seq_tab_hs_t, \ref cy_stc_autanalog_sar_seq_tab_lp_t)
* and State Transition Table (refer to \ref cy_stc_autanalog_stt_sar_t structure).
*
* \note When ADC is powered down, the ADC logic and FIRs are reset, ADC/FIR clocks are gated, and all ADC AC conditions
*       are cleared. The ADC configuration and sequencer tables are retained. The FIFO status and content are not cleared,
*       i.e. the FIFO contents can still be read if the ADC is disabled.
*
* \section group_autanalog_sar_clk Clock and Throughput
*
* The ADC in HS mode is clocked from the SRSS peripheral clock
* (Clk_HF9, up to 80MHz, refer to \ref group_autanalog_section_configuration) in chip Active mode
* using Peri 0 Clock Group 2 8-bit divider in the clock chain.\n
* The ADC in LP mode is clocked from the local Low Power Oscillator
* (LPOSC, 4096kHz, refer to \ref cy_en_autanalog_timer_clk_src_t) in chip Deep Sleep mode.\n
*
* <table class="doxtable">
*    <tr>
*       <th>ADC mode</th>
*       <th>Clock source</th>
*       <th>Clock frequency, MHz</th>
*       <th>Throughput, samples/s</th>
*    </tr>
*    <tr>
*       <td>High Speed</td>
*       <td>Clk_HF9</td>
*       <td>80</td>
*       <td>5Msps</td>
*    </tr>
*    <tr>
*       <td>Low Power</td>
*       <td>LPOSC</td>
*       <td>4.096</td>
*       <td>200ksps</td>
*    </tr>
* </table>
*
* \section group_autanalog_sar_sampling Sample Time
*
* The sample time can be set separately for each HS\\LP ADC Cores.
*
* For HS mode, enable this option in the corresponding ADC sequencer,
* refer to cy_stc_autanalog_sar_seq_tab_hs_t::sampleTimeEn, cy_stc_autanalog_sar_seq_tab_hs_t::sampleTime.
* And the selection of a particular value of the acquisition time is defined in the corresponding Static configuration,
* refer to cy_stc_autanalog_sar_sta_hs_t::hsSampleTime.
*
* For LP mode, enable this option in the corresponding ADC sequencer,
* refer to cy_stc_autanalog_sar_seq_tab_lp_t::sampleTimeEn, cy_stc_autanalog_sar_seq_tab_lp_t::sampleTime.
* The selection of a particular value of the acquisition time is defined in the corresponding Static configuration,
* refer to cy_stc_autanalog_sar_sta_lp_t::lpSampleTime.
*
* \note 15us is the recommended sampling time for Die temperature measurement in LP mode.
* \note 12us is the recommended sampling time for Die temperature measurement in HS mode.
*
*   \section group_autanalog_sar_vref Reference Voltage
*
* The level of the reference voltage can be defined separately for each HS\\LP ADC Cores
* in the corresponding parts of the Static configuration,
* refer to cy_stc_autanalog_sar_sta_hs_t::hsVref and cy_stc_autanalog_sar_sta_lp_t::lpVref.
*
* For the PRB configuration settings, refer to \ref cy_stc_autanalog_prb_t structure.
*
* \note Vdda is 1.8V and Vbgr is 0.9V
*
* \section group_autanalog_sar_pump Buffer Input and Output Ranges
*
* The input range of the buffer can be rail-to-rail if the charge pump is enabled.
* Without the charge pump, the input range is 0 V to VDDA - 1.5 V. The output range
* of the buffer is typically 0.2 V to VDDA - 1.0 V.
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
* For the configuration settings, see \ref cy_en_autanalog_sar_buf_pwr_t.
*
* \section group_autanalog_sar_sign Signed/Unsigned Output
*
* The ADC conversion result and the FIR//FIFO output are represented as 32-bit width integer,
* (zero or sign extended) regardless of the actual resolution of the ADC.
*
* For the configuration settings,
* refer to cy_stc_autanalog_sar_hs_chan_t::sign and cy_stc_autanalog_sar_mux_chan_t::sign.
*
* \section group_autanalog_sar_result Handling of the Result
*
* The results of the ADC conversion or FIR filtering can be stored with further notification about update,
* or sent directly to the FIFO buffer.
* To save the result for a specific logical channel or FIR filter,
* use the following settings in the Static configuration:
* - GPIO channels result mask, refer to cy_stc_autanalog_sar_sta_hs_t::hsGpioResultMask;
* - MUX channels result mask, refer to cy_stc_autanalog_sar_sta_t::muxResultMask;
* - FIR filters result mask, refer to cy_stc_autanalog_sar_sta_t::firResultMask;
*
* \section group_autanalog_sar_avg Averaging
*
* The ADC subsystem includes an accumulator and shift registers to support the averaging at the hardware level.
*
* To configure the averaging for the ADC conversion result, use:
* - enable the averaging (applies to all channels enabled in the sequencer) in the sequencer configuration
*   (refer e.g. to cy_stc_autanalog_sar_seq_tab_hs_t::accEn);
*
* - enable and select Averaging mode in the Static configuration (refer to cy_stc_autanalog_sar_sta_t::accMode)
*    - ACCUNDUMP - the enabled channels will be sampled, converted, and accumulated back to back.
*      After e.g. cy_stc_autanalog_sar_seq_tab_hs_t::accCount times, the accumulated results for each enabled channels are
*      optionally shifted (refer to e.g. cy_stc_autanalog_sar_hs_chan_t::accShift);
*
* - define the average count in the sequencer configuration (refer to e.g. cy_stc_autanalog_sar_seq_tab_hs_t::accCount);
* - enable the averaging execution in HW (refer to e.g. cy_stc_autanalog_sar_hs_chan_t::accShift);
* - define the mode of the average shift (result resolution) if the averaging is carried out by the HW
*   (refer to cy_stc_autanalog_sar_sta_t::shiftMode):
*   - TWELVE - after the last accumulation, the result is shifted back to 12 bits;
*   - SIXTEEN - after the last accumulation, if the average count >= 32, the result will be shifted back to 16-bits,
*               if the average count < 32, no shift will be done as the result is already guaranteed to fit in 16 bits.
*
* \section group_autanalog_sar_fir FIR Filter
*
* Two instances of the 64-tap FIR filters are available for the ADC post-processing.
*
* The FIR filter configuration (refer to \ref cy_stc_autanalog_sar_fir_cfg_t) includes:
* - the source for the FIR filter input defined in \ref cy_en_autanalog_sar_fir_channel_t;
* - the FIR filter order, refer to cy_stc_autanalog_sar_fir_cfg_t::tapSel;
* - the array of FIR filter coefficients, refer to cy_stc_autanalog_sar_fir_cfg_t::coeff.\n
*   The coefficient values may range from -1 + 1/2^15 to 1 - 1/2^15, with a resolution of 1/2^15.\n
*   The coefficient uses the two-complement notation and the decimal point is fixed to the right of the most significant bit.\n
*   Example: -0.25 = 0xE000 and 0.25 = 0x2000
* - the FIR filter output scaling, refer to cy_stc_autanalog_sar_fir_cfg_t::shiftSel;
* - the FIR filter output init delay, refer to cy_stc_autanalog_sar_fir_cfg_t::waitTapInit;
* - routing the FIR filter output to the FIFO, refer to cy_stc_autanalog_sar_fir_cfg_t::fifoSel;
* - range detection, refer to refer to cy_stc_autanalog_sar_fir_cfg_t::firLimit;
*
* \section group_autanalog_sar_int Interrupts, Triggers and STT Events
*
* The following internal events of the ADC can be configured to generate an interrupt or trigger
* or used as the STT event in the Autonomous Analog
* (refer to \ref cy_en_autanalog_ac_out_trigger_mask_t and \ref cy_en_autanalog_stt_ac_condition_t):
* - SAR_EOS - Indicates the end of the scanning of the logical ADC channels by the sequencer;
* - SAR_RESULT (interrupt only) - Indicates an updated ADC conversion result;
* - SAR_DONE - Indicates that the sequencer stopped scanning the ADC;
* - SAR_RANGE - Indicates range detection conditions;
* - SAR_FIR_RESULT (interrupt only) - Indicates an updated FIR filter calculation result;
* - SAR_BUSY (STT event only) - Indicates that the ADC is in conversion;
* - SAR_FIR_DONE (STT event only) - Indicates an updated FIR filter result;
* - SAR_FIFO_DONE (STT event only) - Indicates SAR_DONE ANDED with FIFO writing complete;
* - SAR_FIR_FIFO_DONE (STT event only) - Indicates that the FIR filter result is sent to the FIFO;
*
* Refer to \ref group_autanalog_fifo_int chapter for the FIFO events.
*
* \section group_autanalog_sar_sample1 Sample use case: Die Temperature
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_SCENARIO1
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_INCLUDES1
*
* \snippet autanalog/snippet/autanalog_sar.c SNIPPET_ADC_DEFINES1
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_CH_GPIO
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_CH_MUX
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_STATIC_HS
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_STATIC_LP
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_STATIC
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_SEQUENCER_HS
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_SEQUENCER_LP
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_CONFIG
*
* \snippet autanalog_sar1/autanalog_sar.c SNIPPET_ADC_STT
*
* \snippet autanalog/snippet/autanalog_sar.c SNIPPET_ADC_INIT_COMMON
*
* \snippet autanalog/snippet/autanalog_sar.c SNIPPET_ADC_LOAD_CFG
*
* \warning The first reading of the die temperature in HS mode may be incorrect.
*
*   \defgroup group_autanalog_sar_macros Macros
*   \{
*     \defgroup group_autanalog_sar_hs_chan_macros High Speed Channels and Masks
*     \defgroup group_autanalog_sar_lp_chan_macros Low Power Channels and Masks
*     \defgroup group_autanalog_fir_macros         FIR filter Channels and Masks
*   \}
*   \defgroup group_autanalog_sar_functions Functions
*   \{
*       \defgroup group_autanalog_sar_functions_init   Initialization Functions
*       \defgroup group_autanalog_sar_functions_status Status Functions
*       \defgroup group_autanalog_sar_functions_conv   Conversion Functions
*       \defgroup group_autanalog_sar_functions_fir    FIR Filter Functions
*   \}
*   \defgroup group_autanalog_sar_data_structures Data Structures
*   \defgroup group_autanalog_sar_enums Enumerated Types
*
* \}
*
* \addtogroup group_autanalog_fifo
* \{
*   The FIFO subsystem is used to store the ADC data or the FIR filter results.
*   The FIFO buffer consists of 512 32-bit words and FIFO fullness can be signaled by means of an interrupt.
*   The ADC measurements stored in the FIFO can be supplemented with the channel IDs.
*
*   \section group_autanalog_fifo_static Static Configuration
*
*   The static configuration contains application-specific settings
*   intended to remain static for any FIFO application.
*   The Autonomous Controller (AC) will NOT change the static configuration during operation.
*
*   The FIFO buffer can be divided into several (maximum 8) sub-FIFOs
*   each with independent read/write/status functionality.
*   For configuration settings, see \ref cy_stc_autanalog_fifo_cfg_t structure.
*
* \section group_autanalog_fifo_dynamic Dynamic Configuration
*
* The Dynamic Configuration is not available for the FIFO subsystem.
*
*  \section group_autanalog_fifo_int Interrupts, Triggers and STT Events
*
*  A FIFO level status can be configured as an output trigger and/or as an interrupt to wake up the CPU:
*  - FIFO_UNDERFLOW (interrupt only) - Indicates empty conditions for the FIFO, read value ni this case is undefined;
*  - FIFO_OVERFLOW (interrupt only) - Indicates overflow conditions for the FIFO, hardware will not over-write the FIFO;
*  - FIFO_LEVEL - Indicates FIFO level event, see \ref cy_stc_autanalog_fifo_cfg_t::level setting;
*
*   \defgroup group_autanalog_fifo_macros Macros
*   \defgroup group_autanalog_fifo_functions Functions
*   \{
*       \defgroup group_autanalog_fifo_functions_init Initialization Functions
*       \defgroup group_autanalog_fifo_functions_int Interrupt Functions
*   \}
*   \defgroup group_autanalog_fifo_data_structures Data Structures
*   \defgroup group_autanalog_fifo_enums Enumerated Types
* \}
*/

#if !defined(CY_AUTANALOG_SAR_H)
#define CY_AUTANALOG_SAR_H

#include "cy_device.h"

#ifdef CY_IP_MXS22LPPASS_SAR

#include "cy_autanalog_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_autanalog_sar_macros
* \{
*/

/** The number of High Speed and Low Power ADC sequencers.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_SAR_SEQUENCER_NUM                     (32UL)

/** Number of ADC input sampling timers.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_SAR_SAMPLE_TIME_NUM                   (4UL)

/** The number of structures for configuring the limits of the ADC result.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_SAR_LIMIT_CFG_NUM                     (4UL)

/** The number of ADC channel correction coefficients.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_SAR_CH_CORR_COEFF_NUM                 (8UL)

/** The number of FIR filters.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_SAR_FIR_NUM                           (2UL)

/** The maximum number of taps in FIR filter configuration.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_SAR_FIR_TAP_NUM                       (64UL)


/** \addtogroup group_autanalog_sar_hs_chan_macros
* The ADC HS mode: can be ORed together and applied to the cy_stc_autanalog_sar_seq_tab_hs_t::chanEn
* \{
*/

/** The GPIO channels masks */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO_DISABLED           (0x00000000UL) /**< The GPIO channels disabled */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO0                   (0x00000001UL) /**< The GPIO channel 0 */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO1                   (0x00000002UL) /**< The GPIO channel 1 */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO2                   (0x00000004UL) /**< The GPIO channel 2 */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO3                   (0x00000008UL) /**< The GPIO channel 3 */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO4                   (0x00000010UL) /**< The GPIO channel 4 */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO5                   (0x00000020UL) /**< The GPIO channel 5 */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO6                   (0x00000040UL) /**< The GPIO channel 6 */
#define CY_AUTANALOG_SAR_CHAN_MASK_GPIO7                   (0x00000080UL) /**< The GPIO channel 7 */

/** The MUX channels configurations */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX_DISABLED             (0x00000000UL) /**< The MUX channels disabled */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX0_SINGLE_ENDED        (0x00000001UL) /**< The MUX channel 0 single ended */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX1_SINGLE_ENDED        (0x00000002UL) /**< The MUX channel 1 single ended */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX0_MUX1_SINGLE_ENDED   (0x00000003UL) /**< The MUX channel 0, 1 single ended */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX0_PSEUDO_DIFF         (0x00000004UL) /**< The MUX channel pseudo differential */

/** \} group_autanalog_sar_hs_chan_macros */


/** \addtogroup group_autanalog_sar_lp_chan_macros
* The ADC LP mode.
* \{
*/
/** The MUX channels configurations */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX0                     (0x00000000UL) /**< The MUX channel 0 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX1                     (0x00000001UL) /**< The MUX channel 1 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX2                     (0x00000002UL) /**< The MUX channel 2 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX3                     (0x00000003UL) /**< The MUX channel 3 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX4                     (0x00000004UL) /**< The MUX channel 4 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX5                     (0x00000005UL) /**< The MUX channel 5 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX6                     (0x00000006UL) /**< The MUX channel 6 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX7                     (0x00000007UL) /**< The MUX channel 7 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX8                     (0x00000008UL) /**< The MUX channel 8 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX9                     (0x00000009UL) /**< The MUX channel 9 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX10                    (0x0000000AUL) /**< The MUX channel 10 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX11                    (0x0000000BUL) /**< The MUX channel 11 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX12                    (0x0000000CUL) /**< The MUX channel 12 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX13                    (0x0000000DUL) /**< The MUX channel 13 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX14                    (0x0000000EUL) /**< The MUX channel 14 */
#define CY_AUTANALOG_SAR_CHAN_CFG_MUX15                    (0x0000000FUL) /**< The MUX channel 15 */

/** The MUX channels masks */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX_DISABLED            (0x00000000UL) /**< Disable usage of MUX channels */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX0                    (0x00000001UL) /**< The MUX channel 0 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX1                    (0x00000002UL) /**< The MUX channel 1 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX2                    (0x00000004UL) /**< The MUX channel 2 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX3                    (0x00000008UL) /**< The MUX channel 3 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX4                    (0x00000010UL) /**< The MUX channel 4 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX5                    (0x00000020UL) /**< The MUX channel 5 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX6                    (0x00000040UL) /**< The MUX channel 6 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX7                    (0x00000080UL) /**< The MUX channel 7 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX8                    (0x00000100UL) /**< The MUX channel 8 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX9                    (0x00000200UL) /**< The MUX channel 9 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX10                   (0x00000400UL) /**< The MUX channel 10 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX11                   (0x00000800UL) /**< The MUX channel 11 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX12                   (0x00001000UL) /**< The MUX channel 12 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX13                   (0x00002000UL) /**< The MUX channel 13 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX14                   (0x00004000UL) /**< The MUX channel 14 */
#define CY_AUTANALOG_SAR_CHAN_MASK_MUX15                   (0x00008000UL) /**< The MUX channel 15 */

/** \} group_autanalog_sar_lp_chan_macros */


/** \addtogroup group_autanalog_fir_macros
* \{
*/

/** The FIR filter channels configurations */
#define CY_AUTANALOG_SAR_CFG_FIR0                          (0x00000000UL) /**< The FIR filter 0 */
#define CY_AUTANALOG_SAR_CFG_FIR1                          (0x00000001UL) /**< The FIR filter 1 */

/** The FIR channels masks */
#define CY_AUTANALOG_SAR_MASK_FIR_DISABLED                 (0x00000000UL) /**< Disable usage of FIR filters */
#define CY_AUTANALOG_SAR_MASK_FIR0                         (0x00000001UL) /**< The FIR filter 0 */
#define CY_AUTANALOG_SAR_MASK_FIR1                         (0x00000002UL) /**< The FIR filter 1 */

/** \} group_autanalog_fir_macros */

/** \} group_autanalog_sar_macros */

/** \addtogroup group_autanalog_fifo_macros
* \{
*/
#define CY_AUTANALOG_FIFO_BUFS_NUM       (8UL)    /**< The maximum number of FIFO buffers */

/** FIFO LEVEL 0 overflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_OVERFLOW0  (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_OVERFLOW0_INT_Msk)
/** FIFO LEVEL 1 overflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_OVERFLOW1  (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_OVERFLOW1_INT_Msk)
/** FIFO LEVEL 2 overflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_OVERFLOW2  (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_OVERFLOW2_INT_Msk)
/** FIFO LEVEL 3 overflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_OVERFLOW3  (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_OVERFLOW3_INT_Msk)
/** FIFO LEVEL 4 overflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_OVERFLOW4  (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_OVERFLOW4_INT_Msk)
/** FIFO LEVEL 5 overflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_OVERFLOW5  (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_OVERFLOW5_INT_Msk)
/** FIFO LEVEL 6 overflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_OVERFLOW6  (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_OVERFLOW6_INT_Msk)
/** FIFO LEVEL 7 overflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_OVERFLOW7  (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_OVERFLOW7_INT_Msk)
/** FIFO LEVEL 0 cause interrupt mask */
#define CY_AUTANALOG_INT_FIFO_LEVEL0     (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_LEVEL0_INT_Msk)
/** FIFO LEVEL 1 cause interrupt mask */
#define CY_AUTANALOG_INT_FIFO_LEVEL1     (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_LEVEL1_INT_Msk)
/** FIFO LEVEL 2 cause interrupt mask */
#define CY_AUTANALOG_INT_FIFO_LEVEL2     (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_LEVEL2_INT_Msk)
/** FIFO LEVEL 3 cause interrupt mask */
#define CY_AUTANALOG_INT_FIFO_LEVEL3     (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_LEVEL3_INT_Msk)
/** FIFO LEVEL 4 cause interrupt mask */
#define CY_AUTANALOG_INT_FIFO_LEVEL4     (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_LEVEL4_INT_Msk)
/** FIFO LEVEL 5 cause interrupt mask */
#define CY_AUTANALOG_INT_FIFO_LEVEL5     (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_LEVEL5_INT_Msk)
/** FIFO LEVEL 6 cause interrupt mask */
#define CY_AUTANALOG_INT_FIFO_LEVEL6     (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_LEVEL6_INT_Msk)
/** FIFO LEVEL 7 cause interrupt mask */
#define CY_AUTANALOG_INT_FIFO_LEVEL7     (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_LEVEL7_INT_Msk)
/** FIFO LEVEL 0 underflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_UNDERFLOW0 (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_UNDERFLOW0_INT_Msk)
/** FIFO LEVEL 1 underflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_UNDERFLOW1 (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_UNDERFLOW1_INT_Msk)
/** FIFO LEVEL 2 underflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_UNDERFLOW2 (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_UNDERFLOW2_INT_Msk)
/** FIFO LEVEL 3 underflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_UNDERFLOW3 (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_UNDERFLOW3_INT_Msk)
/** FIFO LEVEL 4 underflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_UNDERFLOW4 (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_UNDERFLOW4_INT_Msk)
/** FIFO LEVEL 5 underflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_UNDERFLOW5 (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_UNDERFLOW5_INT_Msk)
/** FIFO LEVEL 6 underflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_UNDERFLOW6 (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_UNDERFLOW6_INT_Msk)
/** FIFO LEVEL 7 underflow interrupt mask */
#define CY_AUTANALOG_INT_FIFO_UNDERFLOW7 (LPPASS_MMIO_FIFO_INTR_CAUSE_FIFO_UNDERFLOW7_INT_Msk)

/** \cond INTERNAL */

/* Combined FIFO interrupt mask */
#define CY_AUTANALOG_INTR_FIFO          (CY_AUTANALOG_INT_FIFO_OVERFLOW0  | \
                                         CY_AUTANALOG_INT_FIFO_OVERFLOW1  | \
                                         CY_AUTANALOG_INT_FIFO_OVERFLOW2  | \
                                         CY_AUTANALOG_INT_FIFO_OVERFLOW3  | \
                                         CY_AUTANALOG_INT_FIFO_OVERFLOW4  | \
                                         CY_AUTANALOG_INT_FIFO_OVERFLOW5  | \
                                         CY_AUTANALOG_INT_FIFO_OVERFLOW6  | \
                                         CY_AUTANALOG_INT_FIFO_OVERFLOW7  | \
                                         CY_AUTANALOG_INT_FIFO_UNDERFLOW0 | \
                                         CY_AUTANALOG_INT_FIFO_UNDERFLOW1 | \
                                         CY_AUTANALOG_INT_FIFO_UNDERFLOW2 | \
                                         CY_AUTANALOG_INT_FIFO_UNDERFLOW3 | \
                                         CY_AUTANALOG_INT_FIFO_UNDERFLOW4 | \
                                         CY_AUTANALOG_INT_FIFO_UNDERFLOW5 | \
                                         CY_AUTANALOG_INT_FIFO_UNDERFLOW6 | \
                                         CY_AUTANALOG_INT_FIFO_UNDERFLOW7 | \
                                         CY_AUTANALOG_INT_FIFO_LEVEL0     | \
                                         CY_AUTANALOG_INT_FIFO_LEVEL1     | \
                                         CY_AUTANALOG_INT_FIFO_LEVEL2     | \
                                         CY_AUTANALOG_INT_FIFO_LEVEL3     | \
                                         CY_AUTANALOG_INT_FIFO_LEVEL4     | \
                                         CY_AUTANALOG_INT_FIFO_LEVEL5     | \
                                         CY_AUTANALOG_INT_FIFO_LEVEL6     | \
                                         CY_AUTANALOG_INT_FIFO_LEVEL7)

/* Validation macros for FIFO registers */
#define CY_AUTANALOG_INTR_FIFO_MASK(interrupt)    (0UL == ((interrupt) & ~CY_AUTANALOG_INTR_FIFO))
#define AUTANALOG_MMIO_FIFO_BUFF_IDX(value)       ((value) < CY_AUTANALOG_FIFO_BUFS_NUM)

/* Validation macros for FIR RESULT STATUS */
#define AUTANALOG_SAR_FIR_STATUS(value)           ((value) <= CY_AUTANALOG_SAR_MASK_FIR1)

/* Helper macros for range validation */
#define AUTANALOG_SAR_FIR_IDX(value)              ((value) < CY_AUTANALOG_SAR_FIR_NUM)
#define AUTANALOG_SAR_INPUT(value)                ((value) <= CY_AUTANALOG_SAR_INPUT_MUX)
#define AUTANALOG_SAR_CHANNEL(key, value)         ((value) < ((key == CY_AUTANALOG_SAR_INPUT_GPIO) ? \
                                                                   PASS_SAR_SAR_GPIO_CHANNELS : \
                                                                   PASS_SAR_SAR_MUX_CHANNELS))

/** \endcond */

/** \} group_autanalog_fifo_macros */


/* Forward declarations */
void Cy_AutAnalog_SAR_LoadDieTempTrimmCoeff(uint32_t dieTrimmMultiplierHS,
                                            uint32_t dieTrimmOffsetHS,
                                            uint32_t dieTrimmMultiplierLP,
                                            uint32_t dieTrimmOffsetLP);
__STATIC_INLINE uint32_t Cy_AutAnalog_FIFO_GetInterruptCause(uint8_t fifoIdx);
__STATIC_INLINE uint32_t Cy_AutAnalog_FIFO_GetInterruptStatus(uint8_t fifoIdx);
__STATIC_INLINE void Cy_AutAnalog_FIFO_ClearInterrupt(uint8_t fifoIdx, uint32_t interrupt);
__STATIC_INLINE void Cy_AutAnalog_FIFO_SetInterrupt(uint8_t fifoIdx, uint32_t interrupt);
__STATIC_INLINE void Cy_AutAnalog_FIFO_SetInterruptMask(uint8_t fifoIdx, uint32_t mask);
__STATIC_INLINE uint32_t Cy_AutAnalog_FIFO_GetInterruptMask(uint8_t fifoIdx);
__STATIC_INLINE uint32_t Cy_AutAnalog_FIFO_GetInterruptStatusMasked(uint8_t fifoIdx);


/***************************************
*       Enumerated Types
***************************************/

/**
* \addtogroup group_autanalog_sar_enums
* \{
*/

/** The ADC input type,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_INPUT_GPIO = 0U, /**< The GPIO channels */
    CY_AUTANALOG_SAR_INPUT_MUX  = 1U, /**< The MUX channels */

} cy_en_autanalog_sar_input_t;


/** The channel input assignment in ADC HS operating mode,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_PIN_GPIO0 =  0UL, /**< The GPIO pin 0 */
    CY_AUTANALOG_SAR_PIN_GPIO1 =  1UL, /**< The GPIO pin 1 */
    CY_AUTANALOG_SAR_PIN_GPIO2 =  2UL, /**< The GPIO pin 2 */
    CY_AUTANALOG_SAR_PIN_GPIO3 =  3UL, /**< The GPIO pin 3 */
    CY_AUTANALOG_SAR_PIN_GPIO4 =  4UL, /**< The GPIO pin 4 */
    CY_AUTANALOG_SAR_PIN_GPIO5 =  5UL, /**< The GPIO pin 5 */
    CY_AUTANALOG_SAR_PIN_GPIO6 =  6UL, /**< The GPIO pin 6 */
    CY_AUTANALOG_SAR_PIN_GPIO7 =  7UL, /**< The GPIO pin 7 */

} cy_en_autanalog_sar_pin_hs_t;


/** The channel input assignment in the ADC HS/LP operating mode,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_PIN_MUX_CTB0_PIN1    =  0UL, /**< The CTB0 GPIO pin 1 */
    CY_AUTANALOG_SAR_PIN_MUX_CTB0_PIN4    =  1UL, /**< The CTB0 GPIO pin 4 */
    CY_AUTANALOG_SAR_PIN_MUX_CTB0_PIN6    =  2UL, /**< The CTB0 GPIO pin 6 */
    CY_AUTANALOG_SAR_PIN_MUX_CTB0_PIN7    =  3UL, /**< The CTB0 GPIO pin 7 */
    CY_AUTANALOG_SAR_PIN_MUX_CTB1_PIN1    =  4UL, /**< The CTB1 GPIO pin 1 */
    CY_AUTANALOG_SAR_PIN_MUX_CTB1_PIN4    =  5UL, /**< The CTB1 GPIO pin 4 */
    CY_AUTANALOG_SAR_PIN_MUX_CTB1_PIN6    =  6UL, /**< The CTB1 GPIO pin 6 */
    CY_AUTANALOG_SAR_PIN_MUX_CTB1_PIN7    =  7UL, /**< The CTB1 GPIO pin 7 */
    CY_AUTANALOG_SAR_PIN_MUX_CTB0_OA0_OUT =  8UL, /**< The CTB0 OpAmp0 output */
    CY_AUTANALOG_SAR_PIN_MUX_CTB0_OA1_OUT =  9UL, /**< The CTB0 OpAmp1 output */
    CY_AUTANALOG_SAR_PIN_MUX_CTB1_OA0_OUT = 10UL, /**< The CTB1 OpAmp0 output */
    CY_AUTANALOG_SAR_PIN_MUX_CTB1_OA1_OUT = 11UL, /**< The CTB1 OpAmp1 output */
    CY_AUTANALOG_SAR_PIN_MUX_DAC0         = 12UL, /**< The DAC0 output  */
    CY_AUTANALOG_SAR_PIN_MUX_DAC1         = 13UL, /**< The DAC1 output  */
    CY_AUTANALOG_SAR_PIN_MUX_TEMP_SENSOR  = 14UL, /**< Temperature sensor */
    CY_AUTANALOG_SAR_PIN_MUX_GPIO0        = 15UL, /**< The GPIO 0 */
    CY_AUTANALOG_SAR_PIN_MUX_GPIO1        = 16UL, /**< The GPIO 1 */
    CY_AUTANALOG_SAR_PIN_MUX_GPIO2        = 17UL, /**< The GPIO 2 */
    CY_AUTANALOG_SAR_PIN_MUX_GPIO3        = 18UL, /**< The GPIO 3 */
    CY_AUTANALOG_SAR_PIN_MUX_GPIO4        = 19UL, /**< The GPIO 4 */
    CY_AUTANALOG_SAR_PIN_MUX_GPIO5        = 20UL, /**< The GPIO 5 */
    CY_AUTANALOG_SAR_PIN_MUX_GPIO6        = 21UL, /**< The GPIO 6 */
    CY_AUTANALOG_SAR_PIN_MUX_GPIO7        = 22UL, /**< The GPIO 7 */
    CY_AUTANALOG_SAR_PIN_MUX_VSSA         = 25UL, /**< The ADC ground */

} cy_en_autanalog_sar_pin_mux_t;


/**
 * The ADC range status selection,
 * defines the selected range conditions for the ADC result.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_LIMIT_STATUS_DISABLED = 0UL, /**< The limit status is not used */
    CY_AUTANALOG_SAR_LIMIT_STATUS_STC0     = 1UL, /**< The limit status configuration 0 */
    CY_AUTANALOG_SAR_LIMIT_STATUS_STC1     = 2UL, /**< The limit status configuration 1 */
    CY_AUTANALOG_SAR_LIMIT_STATUS_STC2     = 3UL, /**< The limit status configuration 2 */
    CY_AUTANALOG_SAR_LIMIT_STATUS_STC3     = 4UL, /**< The limit status configuration 3 */

} cy_en_autanalog_sar_limit_t;


/**
 * Defines the range detection conditions for the ADC result,
 * refer to cy_stc_autanalog_sar_limit_t.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_COND_BELOW   = 0UL, /**< result < cy_stc_autanalog_sar_limit_t::low */
    CY_AUTANALOG_SAR_COND_INSIDE  = 1UL, /**< cy_stc_autanalog_sar_limit_t::low <= result AND
                                          *   result < cy_stc_autanalog_sar_limit_t::high */
    CY_AUTANALOG_SAR_COND_ABOVE   = 2UL, /**< result > cy_stc_autanalog_sar_limit_t::high */
    CY_AUTANALOG_SAR_COND_OUTSIDE = 3UL, /**< result < cy_stc_autanalog_sar_limit_t::low OR
                                              result >= cy_stc_autanalog_sar_limit_t::high */
} cy_en_autanalog_sar_cond_t;


/** The ADC channel correction coefficient,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_CH_COEFF_DISABLED = 0UL, /**< The channel correction coefficient not used */
    CY_AUTANALOG_SAR_CH_COEFF0         = 1UL, /**< The channel correction coefficient configuration 0 */
    CY_AUTANALOG_SAR_CH_COEFF1         = 2UL, /**< The channel correction coefficient configuration 1 */
    CY_AUTANALOG_SAR_CH_COEFF2         = 3UL, /**< The channel correction coefficient configuration 2 */
    CY_AUTANALOG_SAR_CH_COEFF3         = 4UL, /**< The channel correction coefficient configuration 3 */
    CY_AUTANALOG_SAR_CH_COEFF4         = 5UL, /**< The channel correction coefficient configuration 4 */
    CY_AUTANALOG_SAR_CH_COEFF5         = 6UL, /**< The channel correction coefficient configuration 5 */
    CY_AUTANALOG_SAR_CH_COEFF6         = 7UL, /**< The channel correction coefficient configuration 6 */
    CY_AUTANALOG_SAR_CH_COEFF7         = 8UL, /**< The channel correction coefficient configuration 7 */

} cy_en_autanalog_sar_ch_coeff_t;


/** The ADC reference voltage,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_VREF_VDDA      = 0UL, /**< The ADC reference is Vdda */
    CY_AUTANALOG_SAR_VREF_EXT       = 1UL, /**< The ADC reference is External.
                                            *  \note In HS mode,
                                            *  connect the bypass capacitor to this pin
                                            *  to hold the charge for the conversion
                                            *  if external VREF is not used.
                                            *  See the device datasheet for the capacitance value
                                            *  and exact location of this pin. */
    CY_AUTANALOG_SAR_VREF_VBGR      = 2UL, /**< The ADC reference is VBGR */
    CY_AUTANALOG_SAR_VREF_VDDA_BY_2 = 3UL, /**< The ADC reference is Vdda/2 */
    CY_AUTANALOG_SAR_VREF_PRB_OUT0  = 4UL, /**< The ADC reference is Vref0 from the PRB0 */
    CY_AUTANALOG_SAR_VREF_PRB_OUT1  = 5UL, /**< The ADC reference is Vref1 from the PRB1 */

} cy_en_autanalog_sar_vref_t;


/** The power modes of the ADC buffers.
 * Each power setting consumes different levels of the current
 * and supports a different input range and gain bandwidth.
 * The charge pump is used to increase the input range to the rails.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_BUF_PWR_OFF             =  0UL, /**< The power mode for the buffer is OFF,\n
                                                      *   the buffer is disabled */
    CY_AUTANALOG_SAR_BUF_PWR_ULTRA_LOW       =  1UL, /**< The power mode for the buffer is ULTRA LOW,\n
                                                      *   the charge pump is OFF.
                                                      *   The buffer quiescent current is 15uA and
                                                      *   the gain bandwidth is 30kHz; */
    CY_AUTANALOG_SAR_BUF_PWR_ULTRA_LOW_RAIL  =  2UL, /**< The power mode for the buffer is ULTRA LOW,\n
                                                      *   the charge pump is ON.
                                                      *   The buffer quiescent current is 35uA and
                                                      *   the gain bandwidth is 30kHz; */
    CY_AUTANALOG_SAR_BUF_PWR_LOW_RAIL        =  4UL, /**< The power mode for the buffer is LOW,\n
                                                      *   the charge pump is ON.
                                                      *   The buffer quiescent current is 150uA and
                                                      *   the gain bandwidth is 350kHz; */
    CY_AUTANALOG_SAR_BUF_PWR_MEDIUM_RAIL     =  6UL, /**< The power mode for the buffer is MEDIUM,\n
                                                      *   the charge pump is ON.
                                                      *   The buffer quiescent current is 200uA and
                                                      *   the gain bandwidth is 700kHz;
                                                      *   \note This is the recommended operating mode
                                                      *   for ADC channel buffers. */
    CY_AUTANALOG_SAR_BUF_PWR_HIGH_RAIL       =  8UL, /**< The power mode for the buffer is HIGH,\n
                                                      *   the charge pump is ON.
                                                      *   The buffer quiescent current is 600uA and
                                                      *   the gain bandwidth is 1.75MHz; */
    CY_AUTANALOG_SAR_BUF_PWR_ULTRA_HIGH_RAIL = 10UL, /**< The power mode for the buffer is ULTRA HIGH,\n
                                                      *   the charge pump is ON.
                                                      *   The buffer quiescent current is 800uA and
                                                      *   the gain bandwidth is 2.8MHz; */
} cy_en_autanalog_sar_buf_pwr_t;


/** Averaging mode applied to all channels in a scan with averaging enabled,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_ACC_DISABLED    = 0UL, /**< Average disabled */
    CY_AUTANALOG_SAR_ACC_ACCUNDUMP   = 1UL, /**< Average mode: Accumulate and Dump:\n
                                             *   channels are sampled and accumulated back-to-back */
} cy_en_autanalog_sar_acc_mode_t;


/** The number of samples for averaging,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_ACC_CNT2   = 0UL, /**< Set samples averaged to 2 */
    CY_AUTANALOG_SAR_ACC_CNT4   = 1UL, /**< Set samples averaged to 4 */
    CY_AUTANALOG_SAR_ACC_CNT8   = 2UL, /**< Set samples averaged to 8 */
    CY_AUTANALOG_SAR_ACC_CNT16  = 3UL, /**< Set samples averaged to 16 */
    CY_AUTANALOG_SAR_ACC_CNT32  = 4UL, /**< Set samples averaged to 32 */
    CY_AUTANALOG_SAR_ACC_CNT64  = 5UL, /**< Set samples averaged to 64 */
    CY_AUTANALOG_SAR_ACC_CNT128 = 6UL, /**< Set samples averaged to 128 */
    CY_AUTANALOG_SAR_ACC_CNT256 = 7UL  /**< Set samples averaged to 256 */

} cy_en_autanalog_sar_acc_cnt_t;


/** The ADC sampling timer,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_SAMPLE_TIME0 = 0U, /**< Sampling Timer 0 */
    CY_AUTANALOG_SAR_SAMPLE_TIME1 = 1U, /**< Sampling Timer 1 */
    CY_AUTANALOG_SAR_SAMPLE_TIME2 = 2U, /**< Sampling Timer 2 */
    CY_AUTANALOG_SAR_SAMPLE_TIME3 = 3U, /**< Sampling Timer 3 */

} cy_en_autanalog_sar_sample_time_t;


/** The ADC calibration,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_CAL_DISABLED  = 0UL, /**< Calibration disabled */
    CY_AUTANALOG_SAR_CAL_BOTH      = 1UL, /**< Calibrate both Offset and Linearity */
    CY_AUTANALOG_SAR_CAL_OFFSET    = 2UL, /**< Calibrate Offset only */
    CY_AUTANALOG_SAR_CAL_LINEARITY = 3UL, /**< Calibrate Linearity only */

} cy_en_autanalog_sar_calibrate_t;


/** The Next State for the ADC sequencer while scanning,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_NEXT_ACTION_STATE_STOP       = 0UL, /**< Stop, send SAR_EOS and SAR_DONE events and idle */
    CY_AUTANALOG_SAR_NEXT_ACTION_GO_TO_ENTRY_ADDR = 1UL, /**< Continuous mode, send SAR_EOS event and return to start */
    CY_AUTANALOG_SAR_NEXT_ACTION_GO_TO_NEXT       = 2UL, /**< Continue to a next state in a given scan */

} cy_en_autanalog_sar_next_act_t;


/** The FIR filter input channel selection,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_SAR_FIR_CH_DISABLED = 0UL,  /**< The FIR filter input is disabled */
    CY_AUTANALOG_SAR_FIR_CH_GPIO0    = 1UL,  /**< The GPIO channel 0 */
    CY_AUTANALOG_SAR_FIR_CH_GPIO1    = 2UL,  /**< The GPIO channel 1 */
    CY_AUTANALOG_SAR_FIR_CH_GPIO2    = 3UL,  /**< The GPIO channel 2 */
    CY_AUTANALOG_SAR_FIR_CH_GPIO3    = 4UL,  /**< The GPIO channel 3 */
    CY_AUTANALOG_SAR_FIR_CH_GPIO4    = 5UL,  /**< The GPIO channel 4 */
    CY_AUTANALOG_SAR_FIR_CH_GPIO5    = 6UL,  /**< The GPIO channel 5 */
    CY_AUTANALOG_SAR_FIR_CH_GPIO6    = 7UL,  /**< The GPIO channel 6 */
    CY_AUTANALOG_SAR_FIR_CH_GPIO7    = 8UL,  /**< The GPIO channel 7 */
    CY_AUTANALOG_SAR_FIR_CH_MUX0     = 9UL,  /**< The MUX channel  0 */
    CY_AUTANALOG_SAR_FIR_CH_MUX1     = 10UL, /**< The MUX channel  1 */
    CY_AUTANALOG_SAR_FIR_CH_MUX2     = 11UL, /**< The MUX channel  2 */
    CY_AUTANALOG_SAR_FIR_CH_MUX3     = 12UL, /**< The MUX channel  3 */
    CY_AUTANALOG_SAR_FIR_CH_MUX4     = 13UL, /**< The MUX channel  4 */
    CY_AUTANALOG_SAR_FIR_CH_MUX5     = 14UL, /**< The MUX channel  5 */
    CY_AUTANALOG_SAR_FIR_CH_MUX6     = 15UL, /**< The MUX channel  6 */
    CY_AUTANALOG_SAR_FIR_CH_MUX7     = 16UL, /**< The MUX channel  7 */
    CY_AUTANALOG_SAR_FIR_CH_MUX8     = 17UL, /**< The MUX channel  8 */
    CY_AUTANALOG_SAR_FIR_CH_MUX9     = 18UL, /**< The MUX channel  9 */
    CY_AUTANALOG_SAR_FIR_CH_MUX10    = 19UL, /**< The MUX channel  10 */
    CY_AUTANALOG_SAR_FIR_CH_MUX11    = 20UL, /**< The MUX channel  11 */
    CY_AUTANALOG_SAR_FIR_CH_MUX12    = 21UL, /**< The MUX channel  12 */
    CY_AUTANALOG_SAR_FIR_CH_MUX13    = 22UL, /**< The MUX channel  13 */
    CY_AUTANALOG_SAR_FIR_CH_MUX14    = 23UL, /**< The MUX channel  14 */
    CY_AUTANALOG_SAR_FIR_CH_MUX15    = 24UL, /**< The MUX channel  15 */

} cy_en_autanalog_sar_fir_channel_t;


/** \} group_autanalog_sar_enums */


/**
* \addtogroup group_autanalog_fifo_enums
* \{
*/

/** The FIFO selection,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_FIFO_DISABLED = 0UL, /**< DISABLED */
    CY_AUTANALOG_FIFO_SELECT0  = 1UL, /**< FIFO 0 */
    CY_AUTANALOG_FIFO_SELECT1  = 2UL, /**< FIFO 1 */
    CY_AUTANALOG_FIFO_SELECT2  = 3UL, /**< FIFO 2 */
    CY_AUTANALOG_FIFO_SELECT3  = 4UL, /**< FIFO 3 */
    CY_AUTANALOG_FIFO_SELECT4  = 5UL, /**< FIFO 4 */
    CY_AUTANALOG_FIFO_SELECT5  = 6UL, /**< FIFO 5 */
    CY_AUTANALOG_FIFO_SELECT6  = 7UL, /**< FIFO 6 */
    CY_AUTANALOG_FIFO_SELECT7  = 8UL, /**< FIFO 7 */

} cy_en_autanalog_fifo_sel_t;


/** The FIFO configuration,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_FIFO_SPLIT1 = 0UL, /**< The FIFO is a single 512-word buffer */
    CY_AUTANALOG_FIFO_SPLIT2 = 1UL, /**< The FIFO is split into two 256-word buffers */
    CY_AUTANALOG_FIFO_SPLIT4 = 2UL, /**< The FIFO is split into four 128-word buffers */
    CY_AUTANALOG_FIFO_SPLIT8 = 3UL, /**< The FIFO is split into eight 64-word buffers */

} cy_en_autanalog_fifo_split_t;

/** \} group_autanalog_fifo_enums */


/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_autanalog_fifo_data_structures
* \{
*/


/** The FIFO configuration structure,
 *  refer to \ref group_autanalog_fifo chapter.
 *  Used in \ref cy_stc_autanalog_sar_t and \ref Cy_AutAnalog_FIFO_LoadConfig.
 */
typedef struct
{
    cy_en_autanalog_fifo_split_t split;                             /**< The FIFO split configuration */
    uint16_t                     level[CY_AUTANALOG_FIFO_BUFS_NUM]; /**< Array of the FIFO buffer level settings,
                                                                     *   valid range is 0..511,
                                                                     *   but the real functional range depends on
                                                                     *   the cy_stc_autanalog_fifo_cfg_t::split setting
                                                                     */
} cy_stc_autanalog_fifo_cfg_t;

/** \} group_autanalog_fifo_data_structures */


/**
* \addtogroup group_autanalog_sar_data_structures
* \{
*/

/**
 * The channel range detection configuration structure.
 * Used in \ref cy_stc_autanalog_sar_sta_t.
 */
typedef struct
{
    cy_en_autanalog_sar_cond_t cond; /**< Range detection condition */
    int32_t                    low;  /**< Low threshold for range detection */
    int32_t                    high; /**< High threshold for range detection */

} cy_stc_autanalog_sar_limit_t;


/** The GPIO channel configuration structure,
 *  refer to \ref group_autanalog_sar_ch chapter.
 *  Used in \ref cy_stc_autanalog_sar_sta_hs_t.
 */
typedef struct
{
    cy_en_autanalog_sar_pin_hs_t   posPin;     /**< Positive pin assignment */
    bool                           hsDiffEn;   /**< Enable Pseudo differential mode for the single-ended ADC
                                                *   - FALSE - Pseudo differential mode is disabled;
                                                *   - TRUE - Pseudo differential mode is enabled; */
    bool                           sign;       /**< Output data as a unsigned/signed value,
                                                *   for more details, refer to
                                                *   \ref group_autanalog_sar_sign chapter
                                                *   - FALSE - unsigned number;
                                                *   - TRUE - signed number; */
    cy_en_autanalog_sar_ch_coeff_t posCoeff;   /**< Configuration of the positive input correction coefficient */
    cy_en_autanalog_sar_pin_hs_t   negPin;     /**< The negative pin assignment
                                                      \note Only applicable in Pseudo Differential mode,
                                                      refer to cy_stc_autanalog_sar_hs_chan_t::hsDiffEn */
    bool                           accShift;   /**< Enable the averaging in the HW:
                                                *   Enable the right shift of the accumulated result for
                                                *   cy_stc_autanalog_sar_seq_tab_hs_t::accCount,
                                                *   refer to \ref group_autanalog_sar_avg chapter
                                                *   - FALSE - shift is disabled;
                                                *   - TRUE - shift is enabled; */
    cy_en_autanalog_sar_ch_coeff_t negCoeff;   /**< Configuration of the negative input correction coefficient
                                                      \note Only applicable in Pseudo Differential mode,
                                                      refer to cy_stc_autanalog_sar_hs_chan_t::hsDiffEn */
    cy_en_autanalog_sar_limit_t    hsLimit;    /**< The status selector for the ADC output range */
    cy_en_autanalog_fifo_sel_t     fifoSel;    /**< Define use of FIFO and select buffer if required,
                                                *   refer to \ref group_autanalog_fifo chapter */
} cy_stc_autanalog_sar_hs_chan_t;


/** The MUX channel configuration structure,
 *  refer to \ref group_autanalog_sar_ch chapter.
 *  Used in \ref cy_stc_autanalog_sar_sta_t.
 */
typedef struct
{
    cy_en_autanalog_sar_pin_mux_t  posPin;     /**< Positive pin assignment */
    bool                           sign;       /**< Output data as a unsigned/signed value,
                                                *   for more details, refer to
                                                *   \ref group_autanalog_sar_sign chapter
                                                *   - FALSE - unsigned number;
                                                *   - TRUE - signed number; */
    cy_en_autanalog_sar_ch_coeff_t posCoeff;   /**< Configuration of the positive input correction coefficient */
    cy_en_autanalog_sar_pin_mux_t  negPin;     /**< Negative pin assignment
                                                      \note Only applicable in Low Power mode OR
                                                      in High Speed mode and for MUX channel
                                                      configured in Pseudo Differential mode,
                                                      refer to cy_stc_autanalog_sar_seq_tab_hs_t::muxMode */
    bool                           buffBypass; /**< Bypass MUX channels buffers
                                                *   - FALSE - buffers are enabled;
                                                *   - TRUE - buffers are bypassed; */
    bool                           accShift;   /**< Enable the averaging in the HW:
                                                *   Enable the right shift of the accumulated result for
                                                *   cy_stc_autanalog_sar_seq_tab_lp_t::accCount,
                                                *   refer to \ref group_autanalog_sar_avg chapter
                                                *   - FALSE - shift is disabled;
                                                *   - TRUE - shift is enabled; */
    cy_en_autanalog_sar_ch_coeff_t negCoeff;   /**< Configuration of the negative input correction coefficient
                                                      \note Only applicable in Low Power mode OR
                                                      in High Speed mode and for MUX channel
                                                      configured in Pseudo Differential mode,
                                                      refer to cy_stc_autanalog_sar_seq_tab_hs_t::muxMode */
    cy_en_autanalog_sar_limit_t    muxLimit;   /**< The status selector for the ADC output range */
    cy_en_autanalog_fifo_sel_t     fifoSel;    /**< Define use of FIFO and select buffer if required,
                                                *   refer to \ref group_autanalog_fifo chapter */
} cy_stc_autanalog_sar_mux_chan_t;


/** The part of the Static configuration for ADC HS mode,
 *  refer to \ref group_autanalog_sar_static chapter.
 *  Used in \ref cy_stc_autanalog_sar_sta_t.
 */
typedef struct
{
    cy_en_autanalog_sar_vref_t       hsVref;                                         /**< Select ADC voltage reference,
                                                                                      * refer to \ref group_autanalog_sar_vref chapter */
    uint16_t                         hsSampleTime[CY_AUTANALOG_SAR_SAMPLE_TIME_NUM]; /**< The array of sample time settings represented
                                                                                      *   in clock cycles for ADC HS mode,
                                                                                      *   actual value is SAMPLE_TIME + 1,
                                                                                      *   valid range 1...1024.
                                                                                      * Refer to \ref group_autanalog_sar_sampling chapter.
                                                                                      * \note 12us (SAMPLE_TIME: 1023) is the recommended sampling time for
                                                                                      *       Die temperature measurement. */
    cy_stc_autanalog_sar_hs_chan_t * hsGpioChan[PASS_SAR_SAR_GPIO_CHANNELS];         /**< The array of pointers to
                                                                                      *   configuration structures for GPIO channels,
                                                                                      *   NULL means the channel is not configured */
    uint8_t                          hsGpioResultMask;                               /**< GPIO channels result mask,
                                                                                      *  valid range 0x0...0xFF.
                                                                                      * Refer to \ref group_autanalog_sar_result chapter */
} cy_stc_autanalog_sar_sta_hs_t;


/** The part of the Static configuration for ADC LP mode,
 *  refer to \ref group_autanalog_sar_static chapter.
 *  Used in \ref cy_stc_autanalog_sar_sta_t.
 */
typedef struct
{
    bool                       lpDiffEn;                                       /**< Enable ADC channel differential mode
                                                                                *   - FALSE - differential mode is disabled;
                                                                                *   - TRUE - differential mode is enabled; */
    cy_en_autanalog_sar_vref_t lpVref;                                         /**< Select ADC voltage reference,
                                                                                * refer to \ref group_autanalog_sar_vref chapter */
    uint16_t                   lpSampleTime[CY_AUTANALOG_SAR_SAMPLE_TIME_NUM]; /**< The array of sample time settings represented
                                                                                *   in clock cycles for ADC LP mode,
                                                                                *   actual value is SAMPLE_TIME + 1,
                                                                                *   valid range 1...1024.
                                                                                * Refer to \ref group_autanalog_sar_sampling chapter.
                                                                                * \note 15us (SAMPLE_TIME: 61) is the recommended sampling time for
                                                                                *       Die temperature measurement. */
} cy_stc_autanalog_sar_sta_lp_t;


/** The ADC static configuration structure,
 *  refer to \ref group_autanalog_sar_static chapter.
 *  Used in \ref cy_stc_autanalog_sar_t and \ref Cy_AutAnalog_SAR_LoadStaticConfig.
 */
typedef struct
{
    cy_stc_autanalog_sar_sta_lp_t   * lpStaCfg;                                  /**< LP part of static configuration
                                                                                  *   \note This part is optional,
                                                                                  *    NULL pointer allowed for this field */
    cy_stc_autanalog_sar_sta_hs_t   * hsStaCfg;                                  /**< HS part of static configuration
                                                                                   *   \note This part is optional,
                                                                                   *    NULL pointer allowed for this field */
    cy_en_autanalog_sar_buf_pwr_t     posBufPwr;                                 /**< The power mode of the buffer
                                                                                       in the ADC positive input */
    cy_en_autanalog_sar_buf_pwr_t     negBufPwr;                                 /**< The power mode of the buffer
                                                                                       in the ADC negative input */
    cy_en_autanalog_sar_acc_mode_t    accMode;                                   /**< Enable ADC result averaging and
                                                                                       configure averaging mode,
                                                                                   * refer to \ref group_autanalog_sar_avg chapter */
    cy_en_autanalog_sar_calibrate_t   startupCal;                                /**< Enable the ADC calibration during startup.
                                                                                  *   This field is used to request calibration
                                                                                  *   Process whenever the ADC is powered up
                                                                                  *   (refer to cy_stc_autanalog_stt_sar_t::enable) */
    bool                              chanID;                                    /**< Enable channel number identifier
                                                                                   *  for data stored in FIFO, refer to
                                                                                   * \ref Cy_AutAnalog_FIFO_ReadDataChanId function */
    bool                              shiftMode;                                 /**< Set the resolution of the averaging result
                                                                                   *  if averaging performed by HW,
                                                                                   *  refer to \ref group_autanalog_sar_avg chapter
                                                                                   *   - FALSE - 12 bit;
                                                                                   *   - TRUE - 16 bit; */
    cy_stc_autanalog_sar_mux_chan_t * intMuxChan[PASS_SAR_SAR_MUX_CHANNELS];     /**< The array of pointers to
                                                                                   *  configuration structures for MUX channels,
                                                                                   *  NULL means the channel is not configured */
    cy_stc_autanalog_sar_limit_t    * limitCond[CY_AUTANALOG_SAR_LIMIT_CFG_NUM]; /**< The array of pointers to the
                                                                                   *   configuration structures for the
                                                                                   *   ADC output range detection,
                                                                                   *   a NULL element means that the
                                                                                   *   range detection is not configured */
    uint16_t                          muxResultMask;                             /**< MUX channels result mask,
                                                                                   *  valid range 0x0...0xFFFF.
                                                                                   * Refer to \ref group_autanalog_sar_result chapter */
    uint8_t                           firResultMask;                             /**< FIR filter result mask,
                                                                                   *  valid range 0x0...0x3.
                                                                                   * Refer to \ref group_autanalog_sar_result chapter */
} cy_stc_autanalog_sar_sta_t;


/** The ADC Sequencer Table configuration structure for HS mode,
 *  refer to \ref group_autanalog_sar_sequencer chapter.
 *  Used in \ref cy_stc_autanalog_sar_t and \ref Cy_AutAnalog_SAR_LoadHSseqTable.
 */
typedef struct
{
    uint8_t                           chanEn;       /**< GPIO channels enable mask, valid range 0x0...0xFF,
                                                     *   see \ref group_autanalog_sar_hs_chan_macros macros.
                                                     *   Refer to cy_stc_autanalog_sar_sta_hs_t::hsGpioChan
                                                     *   for channels configurations */
    uint8_t                           muxMode;      /**< Define the operating mode of the MUX channels in HS mode,
                                                     *   see \ref group_autanalog_sar_hs_chan_macros macros */
    uint8_t                           mux0Sel;      /**< MUX 0 channel selection, valid range 0...15,
                                                     *   see \ref group_autanalog_sar_lp_chan_macros macros.
                                                     *   Refer to cy_stc_autanalog_sar_sta_t::intMuxChan
                                                     *   for channel configurations */
    uint8_t                           mux1Sel;      /**< MUX 1 channel selection, valid range 0...15,
                                                     *   see \ref group_autanalog_sar_lp_chan_macros macros.
                                                     *   Refer to cy_stc_autanalog_sar_sta_t::intMuxChan
                                                     *   for channel configurations */
    bool                              sampleTimeEn; /**< Enable the sample time option,
                                                     *   refer to \ref group_autanalog_sar_sampling chapter
                                                     *   - FALSE - ADC sampling is not delayed;
                                                     *   - TRUE - ADC sampling is delayed by the sampling time; */
    cy_en_autanalog_sar_sample_time_t sampleTime;   /**< Sample timer selection.
                                                     *   Select one of the four available sample timers,
                                                     *   see cy_stc_autanalog_sar_sta_hs_t::hsSampleTime */
    bool                              accEn;        /**< Enable the conversion averaging,
                                                     *   refer to \ref group_autanalog_sar_avg chapter
                                                     *   - FALSE - averaging disabled;
                                                     *   - TRUE - averaging enabled; */
    cy_en_autanalog_sar_acc_cnt_t     accCount;     /**< The averaging count for the selected averaging mode,
                                                     *   see cy_stc_autanalog_sar_sta_t::accMode */
    cy_en_autanalog_sar_calibrate_t   calReq;       /**< A real-time calibration channel request.
                                                     *   This request is the signal to the ADC to initiate a real-time
                                                     *   calibration process during an ADC scan. */
    cy_en_autanalog_sar_next_act_t    nextAction;   /**< The ADC sequencer next state,
                                                     *   refer to \ref group_autanalog_sar_sequencer chapter */
} cy_stc_autanalog_sar_seq_tab_hs_t;


/** The ADC Sequencer Table configuration structure for LP mode,
 *  refer to \ref group_autanalog_sar_sequencer chapter.
 *  Used in \ref cy_stc_autanalog_sar_t and \ref Cy_AutAnalog_SAR_LoadLPseqTable.
 */
typedef struct
{
    bool                              chanEn;       /**< Enable the LP channel
                                                     *   - FALSE - Disable ADC LP channel;
                                                     *   - TRUE - Enable ADC LP channel; */
    uint8_t                           mux0Sel;      /**< MUX 0 channel selection, valid range 0...15.
                                                     *   See \ref group_autanalog_sar_lp_chan_macros macros */
    bool                              sampleTimeEn; /**< Enable the sample time option,
                                                     *   refer to \ref group_autanalog_sar_sampling chapter
                                                     *   - FALSE - ADC sampling is not delayed;
                                                     *   - TRUE - ADC sampling is delayed by the sampling time; */
    cy_en_autanalog_sar_sample_time_t sampleTime;   /**< Sample timer selection.
                                                     *   Select one of the four available sample timers,
                                                     *   see cy_stc_autanalog_sar_sta_lp_t::lpSampleTime */
    bool                              accEn;        /**< Enable the conversion averaging,
                                                     *   refer to \ref group_autanalog_sar_avg chapter
                                                     *   - FALSE - averaging disabled;
                                                     *   - TRUE - averaging enabled; */
    cy_en_autanalog_sar_acc_cnt_t     accCount;     /**< The averaging count for the selected averaging mode,
                                                     *   see cy_stc_autanalog_sar_sta_t::accMode */
    cy_en_autanalog_sar_calibrate_t   calReq;       /**< A real-time calibration channel request.
                                                     *   This request is the signal to the ADC to initiate a real-time
                                                     *   calibration process during an ADC scan. */
    cy_en_autanalog_sar_next_act_t    nextAction;   /**< The ADC sequencer next state,
                                                     *   refer to \ref group_autanalog_sar_sequencer chapter */
} cy_stc_autanalog_sar_seq_tab_lp_t;


/** The FIR filter configuration structure,
 *  refer to \ref group_autanalog_sar_fir chapter.
 *  Used in \ref cy_stc_autanalog_sar_t and \ref Cy_AutAnalog_SAR_LoadFIRconfig.
 */
typedef struct
{
    cy_en_autanalog_sar_fir_channel_t   chanSel;     /**< The logical channel selection for the FIR filter */
    int16_t                           * coeff;       /**< The array of FIR filter coefficients,
                                                      *   the size of the array is defined by defined by
                                                      *   \ref cy_stc_autanalog_sar_fir_cfg_t::tapSel.
                                                      *   Refer to \ref group_autanalog_sar_fir chapter */
    uint8_t                             tapSel;      /**< The tap value,
                                                      *   actual value is TAP_SEL + 1, valid range 1...64 */
    uint8_t                             shiftSel;    /**< FIR filter output scaling:
                                                      *   shift the FIR filter output to the right by the specified number,
                                                      *   valid range 0...16 */
    bool                                waitTapInit; /**< FIR filter output init delay:
                                                      *   wait for a specified number of updates
                                                      *   before outputting first valid data
                                                      *   - FALSE - FIR generates a SAR_FIRx_DONE trigger after each update;
                                                      *   - TRUE - FIR waits for TAP_SEL + 1 updates before triggering; */
    cy_en_autanalog_sar_limit_t         firLimit;    /**< The status selector for the FIR filter output range */
    cy_en_autanalog_fifo_sel_t          fifoSel;     /**< Define use of FIFO and select buffer if required,
                                                      *   refer to \ref group_autanalog_fifo chapter */
} cy_stc_autanalog_sar_fir_cfg_t;


/**
* The configuration structure to set up the entire ADC.
* Used in \ref Cy_AutAnalog_SAR_LoadConfig.
*/
typedef struct
{
    /* Static configuration */
    cy_stc_autanalog_sar_sta_t        * sarStaCfg;   /**< The pointer to a static part of the ADC configuration */

    /* Sequencer table for HS mode */
    uint8_t                             hsSeqTabNum; /**< The number of HS Sequencer Table structures, valid range 0...32 */
    cy_stc_autanalog_sar_seq_tab_hs_t * hsSeqTabArr; /**< Pointer to the array of HS Sequencer Table structures,
                                                      *   the array length is specified by hsSeqTabNum */

    /* Sequencer table for LP mode */
    uint8_t                             lpSeqTabNum; /**< The number of LP Sequencer Table structures, valid range 0...32 */
    cy_stc_autanalog_sar_seq_tab_lp_t * lpSeqTabArr; /**< Pointer to the array of HS Sequencer Table structures,
                                                      *   the array length is specified by lpSeqTabNum */

    /* FIR filter */
    uint8_t                             firNum;      /**< Number of used FIR filters, valid range 0...2 */
    cy_stc_autanalog_sar_fir_cfg_t    * firCfg;      /**< Pointer to the array of FIR filter configuration structures,
                                                      *   the array length is specified by firNum */

    /* FIFO buffer */
    cy_stc_autanalog_fifo_cfg_t       * fifoCfg;     /**< Pointer to the FIFO configuration structure */

} cy_stc_autanalog_sar_t;


/**
 * The ADC section in the State Transition Table state.
 * Used in \ref cy_stc_autanalog_stt_t.
 */
typedef struct
{
    bool    unlock;     /**< ADC Unlock:
                          * - FALSE - Locked:\n
                          *     Data from fields
                          *     enable, trigger and entryState
                          *     of this structure
                          *     are NOT taken into account in
                          *     the corresponding state of STT;
                          * - TRUE - Unlocked:\n
                          *     Data from fields
                          *     enable, trigger and entryState
                          *     of this structure
                          *     are used in the STT corresponding state;
                          */
    bool    enable;     /**< Enable the ADC */
    bool    trigger;    /**< This field initiates the ADC operation
                          *  per sequencer settings. */
    uint8_t entryState; /**< ADC Sequencer entry state, points to the item of the
                          *   \ref cy_stc_autanalog_sar_t::hsSeqTabArr or
                          *   \ref cy_stc_autanalog_sar_t::lpSeqTabArr depends on the current
                          *   \ref cy_stc_autanalog_stt_ac_t::lpMode setting,
                          *   the valid range is 0...31
                          */
} cy_stc_autanalog_stt_sar_t;

/** \} group_autanalog_sar_data_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_autanalog_sar_functions
* \{
*/

/**
* \addtogroup group_autanalog_sar_functions_init
* This set of functions is used to configure the ADC.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_LoadConfig
****************************************************************************//**
*
* Configures the ADC per provided settings.
*
* \note Changing Vref from external to internal (or vice versa) requires a new initialization delay for the ADC subsystem.
* Use a global API \ref Cy_AutAnalog_LoadConfig instead of the local API.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param sarCfg
* The pointer to a structure containing static data, Sequencer Table, FIR and FIFO
* configuration structures for the entire ADC subsystem within the Autonomous Analog.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadConfig(uint8_t sarIdx, const cy_stc_autanalog_sar_t * sarCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_LoadStaticConfig
****************************************************************************//**
*
* Configures the ADC per settings in the static configuration structure.
*
* \note Changing Vref from external to internal (or vice versa) requires a new initialization delay for the ADC subsystem.
* Use a global API \ref Cy_AutAnalog_LoadConfig instead of the local API.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param sarStaCfg
* The pointer to a structure containing static configuration data for the ADC see \ref cy_stc_autanalog_sar_sta_t.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadStaticConfig(uint8_t sarIdx, const cy_stc_autanalog_sar_sta_t * sarStaCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_LoadHSseqTable
****************************************************************************//**
*
* Loads the ADC HS Sequencer Table configurations.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param seqTabNum
* The number of the ADC HS Sequencer Table configuration structures in the array.
*
* \param seqTabArr
* The pointer to the array of the ADC HS Sequencer Table configuration structures,
* see \ref cy_stc_autanalog_sar_seq_tab_hs_t.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadHSseqTable(uint8_t sarIdx, uint8_t seqTabNum,
                                                         const cy_stc_autanalog_sar_seq_tab_hs_t * seqTabArr);


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_LoadLPseqTable
****************************************************************************//**
*
* Loads the ADC LP Sequencer Table configurations.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param seqTabNum
* The number of the ADC LP Sequencer Table configuration structures in the array.
*
* \param seqTabArr
* The pointer to the array of the ADC LP Sequencer Table configuration structures,
* see \ref cy_stc_autanalog_sar_seq_tab_lp_t.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadLPseqTable(uint8_t sarIdx, uint8_t seqTabNum,
                                                         const cy_stc_autanalog_sar_seq_tab_lp_t * seqTabArr);


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_LoadFIRconfig
****************************************************************************//**
*
* Loads the ADC FIR filter configurations.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param firIdx
* The index of the FIR filter within the ADC,
* see \ref cy_stc_autanalog_sar_t::firNum.
*
* \param firCfg
* The pointer to the array of the FIR filter configuration structures,
* see \ref cy_stc_autanalog_sar_t::firCfg.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadFIRconfig(uint8_t sarIdx, uint8_t firIdx,
                                                        const cy_stc_autanalog_sar_fir_cfg_t * firCfg);

/** \} group_autanalog_sar_functions_init */


/**
* \addtogroup group_autanalog_sar_functions_status
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_GetHSchanLimitStatus
****************************************************************************//**
*
* Provides the range detect status for the ADC GPIO channels.
* The ADC sets this bit for each channel when the conversion result (or averaging result)
* of that channel meets the condition specified by the \ref cy_stc_autanalog_sar_hs_chan_t::hsLimit
* and configured in \ref cy_stc_autanalog_sar_sta_t::limitCond.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \return
* The range detect status for the GPIO channels.
* Compare this value with one of the masks for the GPIO channels.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_AutAnalog_SAR_GetHSchanLimitStatus(uint8_t sarIdx)
{
    uint32_t baseAddr;

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr) ?
           (uint8_t)_FLD2VAL(SAR_STA_RANGE_STATUS_GPIO_CHAN_RANGE_STATUS, AUTANALOG_SAR_RANGE_STATUS(baseAddr)) : 0U;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_ClearHSchanLimitStatus
****************************************************************************//**
*
* Clears the range detect status for the ADC GPIO channels.
* See \ref Cy_AutAnalog_SAR_GetHSchanLimitStatus
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
* \note Under invalid ADC index, the function has no effect.
*
* \param chMask
* The combined mask for the GPIO channels that require a reset of their range detection status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_SAR_ClearHSchanLimitStatus(uint8_t sarIdx, uint8_t chMask)
{
    uint32_t baseAddr;

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        AUTANALOG_SAR_RANGE_STATUS(baseAddr) = _VAL2FLD(SAR_STA_RANGE_STATUS_GPIO_CHAN_RANGE_STATUS, chMask);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_GetHSchanResultStatus
****************************************************************************//**
*
* Provides the result updated status for the ADC GPIO channels.
* The ADC sets this bit for each channel if that particular channel was sampled during the previous scan
* and reached the averaging count.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \return
* The result update status for the GPIO channels.
* Compare this value with one of the masks for the GPIO channels.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_AutAnalog_SAR_GetHSchanResultStatus(uint8_t sarIdx)
{
    uint32_t baseAddr;

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr) ?
           (uint8_t)_FLD2VAL(SAR_STA_CHAN_RESULT_UPDATED_GPIO_CHAN_RESULT_UPDATED, AUTANALOG_SAR_CHAN_RESULT_STATUS(baseAddr)) : 0U;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_ClearHSchanResultStatus
****************************************************************************//**
*
* Clears the result update status for the ADC GPIO channels.
* See \ref Cy_AutAnalog_SAR_GetHSchanResultStatus
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
* \note Under invalid ADC index, the function has no effect.
*
* \param chMask
* The combined mask for the GPIO channels that require a reset of their result update status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_SAR_ClearHSchanResultStatus(uint8_t sarIdx, uint8_t chMask)
{
    uint32_t baseAddr;

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        AUTANALOG_SAR_CHAN_RESULT_STATUS(baseAddr) = _VAL2FLD(SAR_STA_CHAN_RESULT_UPDATED_GPIO_CHAN_RESULT_UPDATED, chMask);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_GetMuxChanLimitStatus
****************************************************************************//**
*
* Provides the range detect status for the ADC MUX channels.
* The ADC sets this bit for each channel when the conversion result (or averaging result)
* of that channel meets the condition specified by the \ref cy_stc_autanalog_sar_mux_chan_t::muxLimit
* and configured in \ref cy_stc_autanalog_sar_sta_t::limitCond.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \return
* The range detect status for the MUX channels.
* Compare this value with one of the masks for the MUX channels.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE uint16_t Cy_AutAnalog_SAR_GetMuxChanLimitStatus(uint8_t sarIdx)
{
    uint32_t baseAddr;

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr) ?
           (uint16_t)_FLD2VAL(SAR_STA_RANGE_STATUS_MUX_CHAN_RANGE_STATUS, AUTANALOG_SAR_RANGE_STATUS(baseAddr)) : 0U;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_ClearMuxChanLimitStatus
****************************************************************************//**
*
* Clears the range detect status for the ADC MUX channels.
* See \ref Cy_AutAnalog_SAR_GetMuxChanLimitStatus
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
* \note Under invalid ADC index, the function has no effect.
*
* \param chMask
* The combined mask for MUX channels that require a reset of their range detect status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_SAR_ClearMuxChanLimitStatus(uint8_t sarIdx, uint16_t chMask)
{
    uint32_t baseAddr;

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        AUTANALOG_SAR_RANGE_STATUS(baseAddr) = _VAL2FLD(SAR_STA_RANGE_STATUS_MUX_CHAN_RANGE_STATUS, chMask);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_GetMuxChanResultStatus
****************************************************************************//**
*
* Provides a result updated status for the ADC MUX channels.
* The ADC sets this bit for each channel if that particular channel was sampled during the previous scan
* and reached the averaging count.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \return
* The result update status for the MUX channels.
* Compare this value with one of the masks for the MUX channels.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE uint16_t Cy_AutAnalog_SAR_GetMuxChanResultStatus(uint8_t sarIdx)
{
    uint32_t baseAddr;

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr) ?
           (uint16_t)_FLD2VAL(SAR_STA_CHAN_RESULT_UPDATED_MUX_CHAN_RESULT_UPDATED, AUTANALOG_SAR_CHAN_RESULT_STATUS(baseAddr)) : 0U;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_ClearMuxChanResultStatus
****************************************************************************//**
*
* Clears the result update status for the ADC MUX channels.
* See \ref Cy_AutAnalog_SAR_GetMuxChanResultStatus
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
* \note Under invalid ADC index, the function has no effect.
*
* \param chMask
* The combined mask for the MUX channels that require a reset of their result update status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_SAR_ClearMuxChanResultStatus(uint8_t sarIdx, uint16_t chMask)
{
    uint32_t baseAddr;

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        AUTANALOG_SAR_CHAN_RESULT_STATUS(baseAddr) = _VAL2FLD(SAR_STA_CHAN_RESULT_UPDATED_MUX_CHAN_RESULT_UPDATED, chMask);
    }
}

/** \} group_autanalog_sar_functions_status */


/**
* \addtogroup group_autanalog_sar_functions_fir
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_FIRgetLimitStatus
****************************************************************************//**
*
* Provides the range detect status for the ADC FIR filter output.
* The ADC sets this bit for each FIR filter when the filtering result
* meets the condition specified by the \ref cy_stc_autanalog_sar_fir_cfg_t::firLimit
* and configured in \ref cy_stc_autanalog_sar_sta_t::limitCond.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \return
* The range detect status for the ADC FIR filter output.
* Compare this value with one of the masks for the FIR filters.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_AutAnalog_SAR_FIRgetLimitStatus(uint8_t sarIdx)
{
    uint32_t baseAddr;

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr) ?
           (uint8_t)_FLD2VAL(SAR_STA_RANGE_STATUS_FIR_RANGE_STATUS, AUTANALOG_SAR_RANGE_STATUS(baseAddr)) : 0U;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_FIRclearLimitStatus
****************************************************************************//**
*
* Clears the range detect status for the ADC FIR filters.
* See \ref Cy_AutAnalog_SAR_FIRgetLimitStatus
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
* \note Under invalid ADC index, the function has no effect.
*
* \param firMask
* The combined mask for the FIR filters that require a reset of their range detect status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_SAR_FIRclearLimitStatus(uint8_t sarIdx, uint8_t firMask)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_SAR_FIR_STATUS(firMask));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        AUTANALOG_SAR_RANGE_STATUS(baseAddr) = _VAL2FLD(SAR_STA_RANGE_STATUS_FIR_RANGE_STATUS, firMask);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_FIRgetResultStatus
****************************************************************************//**
*
* Provides the result updated status for the FIR filter output.
* The ADC sets this bit for each FIR filter when the filter result is updated.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \return
* The result update status for the FIR filter output.
* Compare this value with one of the masks for the FIR filters.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_AutAnalog_SAR_FIRgetResultStatus(uint8_t sarIdx)
{
    uint32_t baseAddr;

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr) ?
           (uint8_t)_FLD2VAL(SAR_STA_FIR_RESULT_UPDATED_FIR_RESULT_UPDATED, AUTANALOG_SAR_FIR_RESULT_STATUS(baseAddr)) : 0U;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_FIRclearResultStatus
****************************************************************************//**
*
* Clears the result update status for the ADC FIR filter output.
* See \ref Cy_AutAnalog_SAR_FIRgetResultStatus
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
* \note Under invalid ADC index, the function has no effect.
*
* \param firMask
* The combined mask for the FIR filters that require a reset of their result update status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_SAR_FIRclearResultStatus(uint8_t sarIdx, uint8_t firMask)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_SAR_FIR_STATUS(firMask));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        AUTANALOG_SAR_FIR_RESULT_STATUS(baseAddr) = _VAL2FLD(SAR_STA_FIR_RESULT_UPDATED_FIR_RESULT_UPDATED, firMask);
    }
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_FIRreadResult
****************************************************************************//**
*
* Provides an FIR filter result.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param firIdx
* The index of the FIR filter within the ADC,
* see \ref cy_stc_autanalog_sar_t::firNum.
*
* \return
* The FIR filter output data.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_AutAnalog_SAR_FIRreadResult(uint8_t sarIdx, uint8_t firIdx)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_SAR_FIR_IDX(firIdx));

    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 1, 'Review shows that type conversion from unsigned to signed does not have any negative drawbacks');
    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr) ?
           (int32_t)_FLD2VAL(SAR_STA_FIR_RESULT_RESULT, AUTANALOG_SAR_FIR_RESULT(baseAddr, firIdx)) : 0;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
}

/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_FIRloadCoeff
****************************************************************************//**
*
* Loads the ADC FIR filter coefficients.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param firIdx
* The index of the FIR filter within the ADC,
* see \ref cy_stc_autanalog_sar_t::firNum.
*
* \param firCoeffNum
* The number of the FIR filter coefficients in the array.
*
* \param firCoeffArr
* The pointer to the array of the FIR filter coefficients.
*
* \return
* Status of execution, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_SAR_FIRloadCoeff(uint8_t sarIdx, uint8_t firIdx, uint8_t firCoeffNum,
                                                        const int16_t * firCoeffArr);

/** \} group_autanalog_sar_functions_fir */


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_LoadOffsetGainCorr
****************************************************************************//**
*
* Loads the offset and gain correction coefficients for the ADC channels.
* \note Only the eight channels of the ADC can be corrected.
* \note Refer to \ref cy_stc_autanalog_sar_hs_chan_t::posCoeff and cy_stc_autanalog_sar_hs_chan_t::negCoeff
* OR to \ref cy_stc_autanalog_sar_mux_chan_t::posCoeff and cy_stc_autanalog_sar_mux_chan_t::negCoeff
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param chanGain
* The array of gain correction coefficients
* for the eight channels of the ADC.
*
* \note The default value of Gain Correction Coefficient is 1.\n
*       This parameter is intended to correct sources of the gain error in the ADC channel (from the GPIO to the ADC input).\n
*       Multiplies the 12-bit ADC conversion by X.XXXXXXXXXXXXXXX\n
*       Range: 1/2^15 = (0.000030517578125) to 2 - (1/2^15) = (1.999969482421875)
*
* \param chanOffset
* The array of offset correction coefficients
* for the eight channels of the ADC.
*
* \note Default value of Offset Correction Coefficient is 0.\n
*       This parameter is intended to correct sources of the offset error in the ADC channel (from the GPIO to the ADC input).\n
*       The signed offset values range from -2048 (0x800) to +2047 (0x7FF) is added to the 12-bit ADC conversion.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadOffsetGainCorr(uint8_t sarIdx, uint16_t chanGain[], int16_t chanOffset[]);


/**
* \addtogroup group_autanalog_sar_functions_conv
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_IsBusy
****************************************************************************//**
*
* Provides the status of the ADC conversion execution at the time of the request.
*
* \note This bit is always high in Continuous mode.
* (i.e. the next state in a scan is set to \ref cy_en_autanalog_sar_next_act_t::CY_AUTANALOG_SAR_NEXT_ACTION_GO_TO_ENTRY_ADDR).
* Except for Continuous mode, the firmware waits for this bit to be low before powering down the ADC
* (cy_stc_autanalog_stt_sar_t::enable = FALSE).
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \return
* The status of the ADC conversion.
* \note Under invalid ADC index, "false" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_AutAnalog_SAR_IsBusy(uint8_t sarIdx)
{
    uint32_t baseAddr;

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr) ?
           (bool)_FLD2VAL(SAR_STA_STATUS_BUSY, AUTANALOG_SAR_STATUS(baseAddr)) : false;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_ReadResult
****************************************************************************//**
*
* Provides the conversion data for the dedicated channel.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param input
* The ADC input type is either GPIO or MUX.
*
* \param channel
* The ADC channel for conversion
*  - valid range for the GPIO: 0...7;
*  - valid range for the MUX: 0...15;
*
* \return
* The result of the ADC.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_AutAnalog_SAR_ReadResult(uint8_t sarIdx, cy_en_autanalog_sar_input_t input, uint8_t channel)
{
    uint32_t baseAddr;
    int32_t regVal = 0;

    CY_ASSERT_L2(AUTANALOG_SAR_INPUT(input));
    CY_ASSERT_L2(AUTANALOG_SAR_CHANNEL(input, channel));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 2, 'Review shows that type conversion from unsigned to signed does not have any negative drawbacks');
        regVal = (input == CY_AUTANALOG_SAR_INPUT_GPIO) ?
                 (int32_t)_FLD2VAL(SAR_STA_GPIO_CHAN_RESULT_RESULT, AUTANALOG_SAR_GPIO_CHAN_RESULT(baseAddr, channel)):
                 (int32_t)_FLD2VAL(SAR_STA_MUX_CHAN_RESULT_RESULT, AUTANALOG_SAR_MUX_CHAN_RESULT(baseAddr, channel));
        CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
    }

    return regVal;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_CountsTo_Volts
****************************************************************************//**
*
* Converts the ADC output to Volts.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param sarLP
* The operating mode of the ADC
* - FALSE - High Speed;
* - TRUE - Low Power;
*
* \param sarSequencer
* The ADC sequencer to convert the output data to Volts,
* valid range 0...31.
*
* \param sarInput
* The ADC input type is either GPIO or MUX.
*
* \param sarChannel
* The ADC channel for conversion
*  - valid range for the GPIO: 0...7;
*  - valid range for the MUX: 0...15;
*
* \param VrefmV
* The ADC reference voltage in mV.
*
* \param sarCounts
* The conversion result, see \ref Cy_AutAnalog_SAR_ReadResult.
* If conversion data is received from FIFO, see \ref Cy_AutAnalog_FIFO_ReadWord
* (\ref Cy_AutAnalog_FIFO_ReadAllData, \ref Cy_AutAnalog_FIFO_ReadDataChanId).
*
* \return
* The ADC result in Volts.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
float32_t Cy_AutAnalog_SAR_CountsTo_Volts(uint8_t sarIdx, bool sarLP, uint8_t sarSequencer, cy_en_autanalog_sar_input_t sarInput,
                                       uint8_t sarChannel, uint32_t VrefmV, int32_t sarCounts);


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_CountsTo_mVolts
****************************************************************************//**
*
* Converts the ADC output to milliVolts.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param sarLP
* The operating mode of the ADC
* - FALSE - High Speed;
* - TRUE - Low Power;
*
* \param sarSequencer
* The ADC sequencer to convert the output data to milliVolts,
* valid range 0...31.
*
* \param sarInput
* The ADC input type is either GPIO or MUX.
*
* \param sarChannel
* The ADC channel for conversion
*  - valid range for the GPIO: 0...7;
*  - valid range for the MUX: 0...15;
*
* \param VrefmV
* The ADC reference voltage in mV.
*
* \param sarCounts
* The conversion result, see \ref Cy_AutAnalog_SAR_ReadResult.
* If conversion data is received from FIFO, see \ref Cy_AutAnalog_FIFO_ReadWord
* (\ref Cy_AutAnalog_FIFO_ReadAllData, \ref Cy_AutAnalog_FIFO_ReadDataChanId).
*
* \return
* The ADC result in milliVolts.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
int16_t Cy_AutAnalog_SAR_CountsTo_mVolts(uint8_t sarIdx, bool sarLP, uint8_t sarSequencer, cy_en_autanalog_sar_input_t sarInput,
                                      uint8_t sarChannel, uint32_t VrefmV, int32_t sarCounts);


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_CountsTo_uVolts
****************************************************************************//**
*
* Converts the ADC output to microVolts.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param sarLP
* The operating mode of the ADC
* - FALSE - High Speed;
* - TRUE - Low Power;
*
* \param sarSequencer
* The ADC sequencer to convert the output data to microVolts,
* valid range 0...31.
*
* \param sarInput
* The ADC input type is either GPIO or MUX.
*
* \param sarChannel
* The ADC channel for conversion
*  - valid range for the GPIO: 0...7;
*  - valid range for the MUX: 0...15;
*
* \param VrefmV
* The ADC reference voltage in mV.
*
* \param sarCounts
* The conversion result, see \ref Cy_AutAnalog_SAR_ReadResult.
* If conversion data is received from FIFO, see \ref Cy_AutAnalog_FIFO_ReadWord
* (\ref Cy_AutAnalog_FIFO_ReadAllData, \ref Cy_AutAnalog_FIFO_ReadDataChanId).
*
* \return
* The ADC result in microVolts.
* \note Under invalid ADC index, "zero" returns in the result.
*
*******************************************************************************/
int32_t Cy_AutAnalog_SAR_CountsTo_uVolts(uint8_t sarIdx, bool sarLP, uint8_t sarSequencer, cy_en_autanalog_sar_input_t sarInput,
                                      uint8_t sarChannel, uint32_t VrefmV, int32_t sarCounts);


/*******************************************************************************
* Function Name: Cy_AutAnalog_SAR_CountsTo_degreeC
****************************************************************************//**
*
* Converts the ADC output to degrees Celsius.
*
* \warning Vbgr should be used as reference voltage when measuring the die temperature.
*
* \warning The first reading of the die temperature in HS mode may be incorrect.
*
* \note The die temperature measurement only works for MUX channels in differential configuration
*  for LP mode and pseudo differential configuration for HS mode.
*
* \note The averaging can be activated to reduce noise.
*
* \param sarIdx
* The index of the ADC subsystem within the Autonomous Analog,
* see \ref cy_stc_autanalog_cfg_t::sar.
*
* \param sarLP
* The operating mode of the ADC
* - FALSE - High Speed;
* - TRUE - Low Power;
*
* \param sarSequencer
* The ADC sequencer to convert the output data to degrees Celsius,
* valid range 0...31.
*
* \param sarChannel
* The ADC channel for conversion,
* valid range: 0...15.
*
* \param sarCounts
* The conversion result, see \ref Cy_AutAnalog_SAR_ReadResult.
* If conversion data is received from FIFO, see \ref Cy_AutAnalog_FIFO_ReadWord
* (\ref Cy_AutAnalog_FIFO_ReadAllData, \ref Cy_AutAnalog_FIFO_ReadDataChanId).
*
* \return
* The ADC result in degrees Celsius.
* \note The function returns 0 on invalid parameters or incorrect averaging configuration.
*
*******************************************************************************/
int16_t Cy_AutAnalog_SAR_CountsTo_degreeC(uint8_t sarIdx, bool sarLP, uint8_t sarSequencer, uint8_t sarChannel,
                                          int32_t sarCounts);

/** \} group_autanalog_sar_functions_conv */

/** \} group_autanalog_sar_functions */


/**
* \addtogroup group_autanalog_fifo_functions
* \{
*/

/**
* \addtogroup group_autanalog_fifo_functions_init
* This set of functions is used to configure the FIFO.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_LoadConfig
****************************************************************************//**
*
* Configures the FIFO operating mode per provided settings.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param fifoCfg
* The pointer to the FIFO configuration structure \ref cy_stc_autanalog_fifo_cfg_t.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_FIFO_LoadConfig(uint8_t fifoIdx, const cy_stc_autanalog_fifo_cfg_t * fifoCfg);

/** \} group_autanalog_fifo_functions_init */

/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_GetSize
****************************************************************************//**
*
* Returns the current number of data samples in the specified FIFO buffer.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param buffIdx
* The buffer index within the FIFO subsystem.
* The number of buffers depends on the \ref cy_stc_autanalog_fifo_cfg_t::split setting.
*
* \return
* The 9-bit number of data samples.
* \note Under invalid FIFO index, "zero" returns in the result.
*
*******************************************************************************/
__STATIC_INLINE uint16_t Cy_AutAnalog_FIFO_GetSize(uint8_t fifoIdx, uint8_t buffIdx)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_MMIO_FIFO_BUFF_IDX(buffIdx));

    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_FIFO, fifoIdx, &baseAddr) ?
           (uint16_t)_FLD2VAL(LPPASS_MMIO_STA_USED_USED, AUTANALOG_MMIO_FIFO_STA_USED(baseAddr, buffIdx)) : 0U;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_ReadWord
****************************************************************************//**
*
* Reads one data sample from the specified FIFO buffer.
* \note The ADC result sign extended to 32 bits.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param buffIdx
* The buffer index within the FIFO subsystem.
* The number of buffers depends on the \ref cy_stc_autanalog_fifo_cfg_t::split setting.
*
* \return
* The 32-bit data sample.
* \note If the FIFO index is not valid, zero is returned in the result.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_AutAnalog_FIFO_ReadWord(uint8_t fifoIdx, uint8_t buffIdx)
{
    uint32_t baseAddr;

    CY_ASSERT_L2(AUTANALOG_MMIO_FIFO_BUFF_IDX(buffIdx));

    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 1, 'Review shows that type conversion from unsigned to signed does not have any negative drawbacks');
    return CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_FIFO, fifoIdx, &baseAddr) ?
           (int32_t)_FLD2VAL(LPPASS_MMIO_STA_RD_DATA_RESULT, AUTANALOG_MMIO_FIFO_STA_RD_DATA(baseAddr, buffIdx)) : 0;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_ReadData
****************************************************************************//**
*
* Reads the given number of words from the specified FIFO buffer.
* \note The ADC result sign extended to 32 bits.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param buffIdx
* The buffer index within the FIFO subsystem.
*
* \param words
* The number of words to read from the FIFO buffer.
*
* \param data
* The pointer to the data array with a size bigger or equal to
* the number of words to read from the FIFO buffer.
*
* \return
* The 9-bit size of the buffer payload to be copied into the data array.
*
*******************************************************************************/
uint16_t Cy_AutAnalog_FIFO_ReadData(uint8_t fifoIdx, uint8_t buffIdx, uint16_t words, int32_t * data);


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_ReadAllData
****************************************************************************//**
*
* Reads all data from the specified FIFO buffer.
* \note The ADC result sign extended to 32 bits.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param buffIdx
* The buffer index within the FIFO subsystem.
* The number of buffers depends on the \ref cy_stc_autanalog_fifo_cfg_t::split setting.
*
* \param data
* The pointer to the data array with a size not less than the buffer size
* (specified by the \ref cy_stc_autanalog_fifo_cfg_t::split setting)
*
* \return
* The 9-bit size of the buffer payload to be copied into the data array.
*
*******************************************************************************/
uint16_t Cy_AutAnalog_FIFO_ReadAllData(uint8_t fifoIdx, uint8_t buffIdx, int32_t * data);


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_ReadDataChanId
****************************************************************************//**
*
* Reads all of the data and the channel IDs from the specified FIFO buffer.
* \note The ADC result sign extended to 32 bits.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param buffIdx
* The buffer index within the FIFO subsystem.
* The number of buffers depends on the \ref cy_stc_autanalog_fifo_cfg_t::split setting.
*
* \param input
* The ADC input type is either GPIO or MUX.
*
* \param data
* The pointer to the data array with a size not less than the buffer size
* (specified by the \ref cy_stc_autanalog_fifo_cfg_t::split setting)
*
* \param chanID
* The pointer to the channel IDs array with a size not less than the buffer size
* (specified by the \ref cy_stc_autanalog_fifo_cfg_t::split setting)
*
* \return
* The 9-bit size of the buffer payload to be copied into the data and the channel ID arrays.
*
*******************************************************************************/
uint16_t Cy_AutAnalog_FIFO_ReadDataChanId(uint8_t fifoIdx, uint8_t buffIdx, cy_en_autanalog_sar_input_t input, int32_t * data, uint8_t * chanID);


/**
* \addtogroup group_autanalog_fifo_functions_int
* This set of functions is used to handle interrupts in the FIFO.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_GetInterruptCause
****************************************************************************//**
*
* Returns the cause of the interrupt for the FIFO subsystem.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \return
* The mask of the event, which causes an interrupt in the FIFO subsystem.
* See \ref group_autanalog_fifo_macros section for defined interrupts in the FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AutAnalog_FIFO_GetInterruptCause(uint8_t fifoIdx)
{
    CY_UNUSED_PARAMETER(fifoIdx);

    return AUTANALOG_MMIO_FIFO_INTR_CAUSE(LPPASS_MMIO_BASE);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_GetInterruptStatus
****************************************************************************//**
*
* Returns the status of combined FIFO subsystem interrupt requests.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \return
* The combined mask of interrupt requests for the FIFO subsystem.
* See \ref group_autanalog_fifo_macros section for defined interrupts in the FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AutAnalog_FIFO_GetInterruptStatus(uint8_t fifoIdx)
{
    CY_UNUSED_PARAMETER(fifoIdx);

    return AUTANALOG_MMIO_FIFO_INTR(LPPASS_MMIO_BASE);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_ClearInterrupt
****************************************************************************//**
*
* Clears the interrupts for the FIFO subsystem.
* \note The interrupt is only cleared when the contents of the FIFO drop below
* the \ref cy_stc_autanalog_fifo_cfg_t::level condition.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param interrupt
* The mask of the interrupts to be cleared. Each bit of this mask is responsible for
* clearing of the corresponding interrupt in the FIFO subsystem.
* See \ref group_autanalog_fifo_macros section for defined interrupts in the FIFO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_FIFO_ClearInterrupt(uint8_t fifoIdx, uint32_t interrupt)
{
    CY_UNUSED_PARAMETER(fifoIdx);

    CY_ASSERT_L2(CY_AUTANALOG_INTR_FIFO_MASK(interrupt));

    AUTANALOG_MMIO_FIFO_INTR(LPPASS_MMIO_BASE) = CY_AUTANALOG_INTR_FIFO & interrupt;

    /*
     * This dummy read guarantees that the interrupt will be cleared on return from this function.
     */
    (void) AUTANALOG_MMIO_FIFO_INTR(LPPASS_MMIO_BASE);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_SetInterrupt
****************************************************************************//**
*
* Sets a software interrupt request for the FIFO subsystem.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param interrupt
* The mask of the interrupts to be set. Each bit of this mask is responsible for
* triggering of the corresponding interrupt in the FIFO subsystem.
* See \ref group_autanalog_fifo_macros section for defined interrupts in the FIFO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_FIFO_SetInterrupt(uint8_t fifoIdx, uint32_t interrupt)
{
    CY_UNUSED_PARAMETER(fifoIdx);

    CY_ASSERT_L2(CY_AUTANALOG_INTR_FIFO_MASK(interrupt));

    AUTANALOG_MMIO_FIFO_INTR_SET(LPPASS_MMIO_BASE) = CY_AUTANALOG_INTR_FIFO & interrupt;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_SetInterruptMask
****************************************************************************//**
*
* Configures which bits of the interrupt request register will trigger
* an interrupt event in the FIFO subsystem.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param mask
* The mask of interrupts allowed to be activated. Each bit of this mask
* allows the corresponding interrupt to be triggered in the FIFO subsystem.
* See \ref group_autanalog_fifo_macros section for defined interrupts in the FIFO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_FIFO_SetInterruptMask(uint8_t fifoIdx, uint32_t mask)
{
    CY_UNUSED_PARAMETER(fifoIdx);

    CY_ASSERT_L2(CY_AUTANALOG_INTR_FIFO_MASK(mask));

    AUTANALOG_MMIO_FIFO_INTR_MASK(LPPASS_MMIO_BASE) = CY_AUTANALOG_INTR_FIFO & mask;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_ClearInterruptMask
****************************************************************************//**
*
* Configures which bits of the interrupt request register will be cleared
* in the FIFO subsystem.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \param mask
* The mask for the clearing of the bits of the interrupt request register
* in the FIFO subsystem.
* See \ref group_autanalog_fifo_macros section for defined interrupts in the FIFO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_FIFO_ClearInterruptMask(uint8_t fifoIdx, uint32_t mask)
{
    CY_UNUSED_PARAMETER(fifoIdx);

    CY_ASSERT_L2(CY_AUTANALOG_INTR_FIFO_MASK(mask));

    AUTANALOG_MMIO_FIFO_INTR_MASK(LPPASS_MMIO_BASE) &= CY_AUTANALOG_INTR_FIFO & (~mask);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask. Each bit of this mask represents an interrupt
* that is allowed in the FIFO subsystem.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \return
* The mask of the interrupts that can be activated.
* See \ref group_autanalog_fifo_macros section for defined interrupts in the FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AutAnalog_FIFO_GetInterruptMask(uint8_t fifoIdx)
{
    CY_UNUSED_PARAMETER(fifoIdx);

    return AUTANALOG_MMIO_FIFO_INTR_MASK(LPPASS_MMIO_BASE);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_FIFO_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the result of the bitwise AND operation between the
* corresponding interrupt request and mask bits.
* See \ref Cy_AutAnalog_FIFO_GetInterruptStatus and \ref Cy_AutAnalog_FIFO_SetInterruptMask.
*
* \param fifoIdx
* The index of the FIFO subsystem within the Autonomous Analog.
* \note One instance of the FIFO is currently supported.
*
* \return
* The masked status of combined interrupt requests for the FIFO subsystem.
* See \ref group_autanalog_fifo_macros section for defined interrupts in the FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AutAnalog_FIFO_GetInterruptStatusMasked(uint8_t fifoIdx)
{
    CY_UNUSED_PARAMETER(fifoIdx);

    return AUTANALOG_MMIO_FIFO_INTR_MASKED(LPPASS_MMIO_BASE);
}

/** \} group_autanalog_fifo_functions_int */

/** \} group_autanalog_fifo_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22LPPASS_SAR */

#endif /** !defined(CY_AUTANALOG_SAR_H) */

/* [] END OF FILE */
