/*******************************************************************************
* File Name: mtb_syspm_callbacks_pdl.h
*
* Description:
* File that includes aliases for all syspm callbacks that are already available
* in the PDL to uniform the naming convention.
*
********************************************************************************
* \copyright
* Copyright 2024-2024 Cypress Semiconductor Corporation (an Infineon company) or
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
 * \addtogroup mtb_syspm_group_pdl_aliases PDL Aliases
 * \{
 * All the following deepsleep callbacks are defined in the PDL and this file only
 * reports the documentation about them as weel as the redefinition to match the
 * asset's signature.
 */

#pragma once

#include "cy_pdl.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_AUTANALOG)
/*******************************************************************************
* Function Name: mtb_syspm_autanalog_deepsleep_callback
****************************************************************************//**
*
* Changes the FIFO mode to write only before entering into Deep Sleep mode
* and restores it to write/read upon wake-up.
*
* \note Changing the FIFO mode applies only to the AC in LP mode.
*
* \param callbackParams
* Callback parameters, see cy_stc_syspm_callback_params_t
*
* \param mode
* Callback mode
*
* \return
* cy_en_syspm_status_t
*
*******************************************************************************/
#define mtb_syspm_autanalog_deepsleep_callback   Cy_AutAnalog_DeepSleepCallback
#endif // defined(MTB_SYSPM_CALLBACKS_AVAILABLE_AUTANALOG)

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_CTDAC)
/*******************************************************************************
* Function Name: mtb_syspm_ctdac_deepsleep_callback
****************************************************************************//**
*
* Callback to prepare the CTDAC before entering and after exiting Deep Sleep
* mode. If deglitching is used, it is disabled before entering Deep Sleep
* to ensure the deglitch switches are closed. This is needed only
* if the CTDAC will be enabled in DeepSleep. Upon wakeup, deglitching will
* be re-enabled if it was previously used.
*
* \param callbackParams
* Pointer to structure of type cy_stc_syspm_callback_params_t.
* The context pointer should point to cy_stc_ctdac_context_t.
*
* \param mode
* Callback mode
*
* \return
* cy_en_syspm_status_t
*
*******************************************************************************/
#define mtb_syspm_ctdac_deepsleep_callback   Cy_CTDAC_DeepSleepCallback
#endif // defined(MTB_SYSPM_CALLBACKS_AVAILABLE_CTDAC)

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_HPPASS)
/*******************************************************************************
* Function Name: mtb_syspm_hppass_deepsleep_callback
****************************************************************************//**
*
* DeepSleep callback saves the SAR ADC calibration values before switch to
* deep sleep power mode and restore them after the wakeup.
*
* \param callbackParams
* Callback parameters
*
* \param mode
* Callback mode
*
* \return
*  cy_en_syspm_status_t
*
*******************************************************************************/
#define mtb_syspm_hppass_deepsleep_callback   Cy_HPPASS_DeepSleepCallback
#endif // defined(MTB_SYSPM_CALLBACKS_AVAILABLE_HPPASS)

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_I3C)
/*******************************************************************************
* Function Name: mtb_syspm_i3c_deepsleep_callback
****************************************************************************//**
*
* This function handles transition of I3C controller into and out of
* deep sleep mode.
*
* \param callbackParams
* The pointer to the callback parameters structure
*
* \param mode
* Callback mode
*
* \return
*  cy_en_syspm_status_t
*
*******************************************************************************/
#define mtb_syspm_i3c_deepsleep_callback   Cy_I3C_DeepSleepCallback
#endif // defined(MTB_SYSPM_CALLBACKS_AVAILABLE_I3C)

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_LPCOMP)
/*******************************************************************************
* Function Name: mtb_syspm_lpcomp_deepsleep_callback
****************************************************************************//**
*
* This function checks the current low-power comparator power mode and disables
* the low-power comparator block, if there is no wake-up source from
* the low-power comparator in Deep-Sleep mode.
* This function stores the state of the low-power comparator "Enable", disables
* the low-power comparator block before going to low power modes and then
* recovers the low-power comparator power "after a wake-up" state using
* the stored value.
*
* \param *callbackParams
*     A  cy_stc_syspm_callback_params_t structure with callback
*     parameters that consists of mode, base and context fields:
*    *base - a low-power comparator register structure pointer.
*    *context - context for the call-back function.
*     mode
*     * CY_SYSPM_CHECK_READY - no action for this state.
*     * CY_SYSPM_CHECK_FAIL - no action for this state.
*     * CY_SYSPM_BEFORE_TRANSITION - checks the low-power comparator interrupt mask
*                            and power mode and then disables or enables the
*                            low-power comparator block per condition.
*                            Stores the low-power comparator state
*                            to recover the state after a wake up.
*     * CY_SYSPM_AFTER_TRANSITION - enables the low-power comparator block
*                            if it was disabled before Sleep mode.
*
* \param mode
* Callback mode
*
* \return
*  cy_en_syspm_status_t
*
*******************************************************************************/
#define mtb_syspm_lpcomp_deepsleep_callback   Cy_LPComp_DeepSleepCallback
#endif // defined(MTB_SYSPM_CALLBACKS_AVAILABLE_LPCOMP)

#if defined (MTB_SYSPM_CALLBACKS_AVAILABLE_LVD_HT)
/*******************************************************************************
* Function Name: mtb_syspm_lvd_ht_deepsleep_callback
****************************************************************************//**
*
* When this function is registered by Cy_SysPm_RegisterCallback - it
* automatically enables the LVD after wake up from Deep-Sleep mode.
*
* \param callbackParams The pointer to the callback parameters structure,
* see  cy_stc_syspm_callback_params_t.
*
* \param mode
* Callback mode
*
* \return cy_en_syspm_status_t.
*
*******************************************************************************/
#define mtb_syspm_lvd_ht_deepsleep_callback   Cy_LVD_HT_DeepSleepCallback
#endif // defined (MTB_SYSPM_CALLBACKS_AVAILABLE_LVD_HT)

#if defined (MTB_SYSPM_CALLBACKS_AVAILABLE_LVD)
/*******************************************************************************
* Function Name: mtb_syspm_lvd_deepsleep_callback
****************************************************************************//**
*
* When this function is registered by  Cy_SysPm_RegisterCallback - it
* automatically enables the LVD after wake up from Deep-Sleep mode.
*
* \param callbackParams The pointer to the callback parameters structure,
*
* \param mode
* Callback mode
*
* \return cy_en_syspm_status_t.
*
*******************************************************************************/
#define mtb_syspm_lvd_deepsleep_callback   Cy_LVD_DeepSleepCallback
#endif // defined (MTB_SYSPM_CALLBACKS_AVAILABLE_LVD)


#if defined (MTB_SYSPM_CALLBACKS_AVAILABLE_RTC)
/*******************************************************************************
* Function Name: mtb_syspm_rtc_deepsleep_callback
****************************************************************************//**
*
* This function checks the RTC_BUSY bit to avoid data corruption before
* enters the Deep Sleep mode.
*
* \param callbackParams
* The structure with the SysPm callback parameters
*
* \param mode
* Callback mode
*
* \return
* cy_en_syspm_status_t
*
* \note The *base and *context elements are required to be present in
* the parameter structure because this function uses the SysPm driver
* callback type.
* The SysPm driver callback function type requires implementing the function
* with next parameters and return value:
*
* cy_en_syspm_status_t (*Cy_SysPmCallback)
* (cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);
*
*******************************************************************************/
#define mtb_syspm_rtc_deepsleep_callback   Cy_RTC_DeepSleepCallback
#endif // defined (MTB_SYSPM_CALLBACKS_AVAILABLE_RTC)

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_SAR)
/*******************************************************************************
* Function Name: mtb_syspm_sar_deepsleep_callback
****************************************************************************//**
*
* Callback to prepare the SAR before entering Deep Sleep
* and to re-enable the SAR after exiting Deep Sleep.
*
* \param callbackParams
* Pointer to structure of type cy_stc_syspm_callback_params_t
*
* \param mode
* Callback mode
*
* \return
* cy_en_syspm_status_t
*
*******************************************************************************/
#define mtb_syspm_sar_deepsleep_callback   Cy_SAR_DeepSleepCallback
#endif // defined(MTB_SYSPM_CALLBACKS_AVAILABLE_SAR)


#if defined (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_EZI2C)
/*******************************************************************************
* Function Name: mtb_syspm_scb_ezi2c_deepsleep_callback
****************************************************************************//**
*
* This function handles the transition of the EZI2C SCB into and out of
* Deep Sleep mode. It prevents the device from entering Deep Sleep mode if
* the EZI2C slave is actively communicating.
* The following behavior of the EZI2C depends on whether the SCB block is
* wakeup-capable:
* * <b>Wakeup-capable</b>: on the incoming EZI2C slave address, the slave
*   receives the address and stretches the clock until the device is woken from
*   Deep Sleep mode. If the slave address occurs before the device enters
*   Deep Sleep mode, the device will not enter Deep Sleep mode.
* * <b>Not wakeup-capable</b>: the EZI2C is disabled. It is enabled
*   when the device fails to enter Deep Sleep mode or it is woken from Deep Sleep
*   mode. While the EZI2C is disabled, it stops driving the outputs and
*   ignores the input lines. The slave NACKs all incoming addresses.
*
* \param callbackParams
* The pointer to the callback parameters structure.
*
* \param mode
* Callback mode
*
* \return
*  cy_en_syspm_status_t
*
* \note
* Only applicable for <b>rev-08 of the CY8CKIT-062-BLE</b>.
* For proper operation, when the EZI2C slave is configured to be a wakeup source
* from Deep Sleep mode, this function must be copied and modified by the user.
* The EZI2C clock disable code must be inserted in the
*  CY_SYSPM_BEFORE_TRANSITION and clock enable code in the
*  CY_SYSPM_AFTER_TRANSITION mode processing.
*
*******************************************************************************/
#define mtb_syspm_scb_ezi2c_deepsleep_callback   Cy_SCB_EZI2C_DeepSleepCallback

#endif // defined (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_EZI2C)

#if defined (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_I2C)
/*******************************************************************************
* Function Name: mtb_syspm_scb_i2c_deepsleep_callback
****************************************************************************//**
*
* This function handles the transition of the I2C SCB into and out of
* Deep Sleep mode. It prevents the device from entering Deep Sleep
* mode if the I2C slave or master is actively communicating.
* The  behavior of the I2C SCB in Deep Sleep depends on whether the SCB block is
* wakeup-capable or not:
* * <b>Wakeup-capable</b>: during Deep Sleep mode on incoming I2C slave address
*   the slave receives address and stretches the clock until the device is
*   awoken from Deep Sleep mode. If the slave address occurs before the device
*   enters Deep Sleep mode, the device will not enter Deep Sleep mode.
*   Only the I2C slave can be configured to be a wakeup source from Deep Sleep
*   mode.
* * <b>Not wakeup-capable</b>: the SCB is disabled in Deep Sleep mode.
*   It is re-enabled if the device fails to enter Deep Sleep mode or when the
*   device is awoken from Deep Sleep mode. While the SCB is disabled it stops
*   driving the outputs and ignores the inputs. The slave NACKs all incoming
*   addresses.
*
* \param callbackParams
* The pointer to the callback parameters structure
*
* \param mode
* Callback mode
*
* \return cy_en_syspm_status_t
*
* \note
* Only applicable for <b>rev-08 of the CY8CKIT-062-BLE</b>.
* For proper operation, when the I2C slave is configured to be a wakeup source
* from Deep Sleep mode, this function must be copied and modified by the user.
* The I2C clock disable code must be inserted in the  CY_SYSPM_BEFORE_TRANSITION
* and clock enable code in the  CY_SYSPM_AFTER_TRANSITION mode processing.
*
*******************************************************************************/
#define mtb_syspm_scb_i2c_deepsleep_callback   Cy_SCB_I2C_DeepSleepCallback

#endif // defined (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_I2C)

#if defined (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_SPI)
/*******************************************************************************
* Function Name: mtb_syspm_scb_spi_deepsleep_callback
****************************************************************************//**
*
* This function handles the transition of the SCB SPI into and out of
* Deep Sleep mode. It prevents the device from entering Deep Sleep mode
* if the SPI slave or master is actively communicating, or there is any data
* in the TX or RX FIFOs.
* The following behavior of the SPI SCB depends on whether the SCB block is
* wakeup-capable or not:
* * <b>Wakeup-capable</b>: any transfer intended to the slave wakes up
*   the device from Deep Sleep mode. The slave responds with 0xFF to the
*   transfer and incoming data is ignored.
*   If the transfer occurs before the device enters Deep Sleep mode, the device
*   will not enter Deep Sleep mode and incoming data is stored in the RX FIFO.
*   The SCB clock is disabled before entering Deep Sleep and enabled after the
*   device exits Deep Sleep mode. The SCB clock disabling may lead to
*   corrupted data in the RX FIFO. Clear the RX FIFO after this callback is
*   executed.
*   Note that for proper SPI operation after Deep Sleep the source of
*   hf_clk[0] must be stable, this includes the FLL/PLL. The SysClk callback
*   ensures that hf_clk[0] gets stable and it must be called before
*    Cy_SCB_SPI_DeepSleepCallback.
*   Only the SPI slave can be configured to be a wakeup source from Deep Sleep
*   mode.
* * <b>Not wakeup-capable</b>: the SPI is disabled. It is enabled when
*   the device fails to enter Deep Sleep mode or it is awakened from Deep Sleep
*   mode. While the SPI is disabled, it stops driving the outputs and ignores
*   the inputs. Any incoming data is ignored.
*   Refer to section  mtb_syspm_group_scb_spi_lp for more information about SPI pins
*   when SCB disabled.
*
* This function must be called during execution of  Cy_SysPm_CpuEnterDeepSleep.
* To do it, register this function as a callback before calling
*  Cy_SysPm_CpuEnterDeepSleep : specify  CY_SYSPM_DEEPSLEEP as the callback
* type and call  Cy_SysPm_RegisterCallback.
*
* \param callbackParams
* The pointer to the callback parameters structure
*
* \param mode
* Callback mode
*
* \return
*  cy_en_syspm_status_t
*
* \note
* Only applicable for <b>rev-08 of the CY8CKIT-062-BLE</b>.
* For proper operation, when the SPI slave is configured to be a wakeup source
* from Deep Sleep mode, this function must be copied and modified by the user.
* The SPI clock disable code must be inserted in the  CY_SYSPM_BEFORE_TRANSITION
* and clock enable code in the  CY_SYSPM_AFTER_TRANSITION mode processing.
*
*******************************************************************************/
#define mtb_syspm_scb_spi_deepsleep_callback   Cy_SCB_SPI_DeepSleepCallback

#endif // defined (MTB_SYSPM_CALLBACKS_AVAILABLE_SCB_SPI)


#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_SD_HOST)
/*******************************************************************************
* Function Name: mtb_syspm_sd_host_deepsleep_callback
****************************************************************************//**
*
* This function handles the transition of the SD Host into and out of
* Deep Sleep mode. It disables SD CLK before going to Deep Sleep mode and
* enables SD CLK after wake up from Deep Sleep mode.
* If the DAT line is active, or a read (write) transfer is being executed on
* the bus, the device cannot enter Deep Sleep mode.
*
* This function must be called during execution of  Cy_SysPm_CpuEnterDeepSleep.
* To do it, register this function as a callback before calling
*  Cy_SysPm_CpuEnterDeepSleep : specify  CY_SYSPM_DEEPSLEEP as the callback
* type and call  Cy_SysPm_RegisterCallback.
*
* \note When waking up from Deep Sleep, the SD Host driver requires up to 1 us
* for clock stabilization. By default the SD Host driver will wait this length
* of time on power up. The waiting loop is implemented in this function.
* If the application is time sensitive this delay can be overridden by the
* application by defining  CY_SD_HOST_CLK_RAMP_UP_TIME_US_WAKEUP.
* This allows the application to perform other operations while the clock
* is stabilizing in the background. However, the application must still make sure
* that the SD Host clock has had time to stabilize before attempting to use the
* SD card. The recommended way to override the value is to specify this as
* a custom define on the compiler command line. This can be done by appending
* the entry to the DEFINES variable in the application Makefile.
* Eg: DEFINES+=CY_SD_HOST_CLK_RAMP_UP_TIME_US_WAKEUP=40.
*
* \param callbackParams
* The pointer to the callback parameters structure.
*
* \param mode
* Callback mode
*
* \return
*  cy_en_syspm_status_t
*
*******************************************************************************/
#define mtb_syspm_sd_host_deepsleep_callback   Cy_SD_Host_DeepSleepCallback
#endif // defined(MTB_SYSPM_CALLBACKS_AVAILABLE_SD_HOST)

#if defined(MTB_SYSPM_CALLBACKS_AVAILABLE_SYSCLK)
/*******************************************************************************
* Function Name: mtb_syspm_sysclk_deepsleep_callback
****************************************************************************//**
*
* Callback function to be used when entering system Deep Sleep mode.
* This function is applicable if:
* - The FLL is enabled
* - The PLL is enabled and is driven by ECO
*
* This function performs the following:
*
* 1. Before entering Deep Sleep, the clock configuration is saved in SRAM.
*    If the FLL/PLL source is the ECO, then the FLL/PLL is bypassed and the
*    source is changed to IMO. \n
*    If the FLL is enabled - it is just bypassed.
* 2. Upon wakeup from Deep Sleep, the function waits for ECO stabilization,
*    then restores the configuration and waits for the FLL/PLL to regain their
*    frequency locks. \n
*    If ECO is not used and FLL is enabled - it waits for FLL lock and unbypasses it.
*
* The function prevents entry into Deep Sleep mode if the measurement counters
* are currently counting; see  Cy_SysClk_StartClkMeasurementCounters.
*
* This function can be called during execution of  Cy_SysPm_CpuEnterDeepSleep.
* To do so, register this function as a callback before calling
*  Cy_SysPm_CpuEnterDeepSleep - specify  CY_SYSPM_DEEPSLEEP as the callback
* type and call  Cy_SysPm_RegisterCallback.
*
* \note
* This function is recommended to be the last callback that is registered.
* Doing so minimizes the time spent on low power mode entry and exit. \n
* This function implements all four SysPm callback modes  cy_en_syspm_callback_mode_t.
* So the  cy_stc_syspm_callback_t::skipMode must be set to 0UL. \n
* This function does not support such cases as, for example, FLL is enabled
* but bypassed by user code before entering Deep Sleep. \n
* You can use this callback implementation as an example to design custom low-power
* callbacks for certain user application.
*
* \param callbackParams
* structure with the syspm callback parameters.
*
* \param mode
* Callback mode
*
* \return Error / status code; see  cy_en_syspm_status_t. Pass if not doing
* a clock measurement, otherwise Fail. Timeout if timeout waiting for ECO, FLL
* or PLL to get stable / regain its frequency lock.
* CY_PRA_STATUS_* - For the PSoC 64 devices there are possible situations when
* function returns the PRA error status code  cy_en_pra_status_t instead of
*  cy_en_sysclk_status_t. This is because for PSoC 64 devices the function
* uses the PRA driver to change the protected registers. Refer to
*  cy_en_pra_status_t for more details.
*
*******************************************************************************/
#define mtb_syspm_sysclk_deepsleep_callback   Cy_SysClk_DeepSleepCallback
#endif // defined(MTB_SYSPM_CALLBACKS_AVAILABLE_SYSCLK)


#if defined(__cplusplus)
}
#endif

/** \} mtb_syspm_group_pdl_aliases */
