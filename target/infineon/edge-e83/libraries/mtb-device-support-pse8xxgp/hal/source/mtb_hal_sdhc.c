/*******************************************************************************
* File Name: mtb_hal_sdhc.c
*
* Description:
* Provides a high level interface for interacting with the Infineon SDHC. This
* is a wrapper around the lower level PDL API.
*
********************************************************************************
* \copyright
* Copyright 2018-2024 Cypress Semiconductor Corporation (an Infineon company) or
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

#include <string.h> /* For memcpy */
#include <stdlib.h>
#include <time.h>
#include "cy_pdl.h"
#include "cy_utils.h"
#include "cy_result.h"
#include "mtb_hal.h"

/**
 * \addtogroup group_hal_impl_sdhc SDHC (SD Host Controller)
 * \ingroup group_hal_impl
 * \{
 *
 * The PDL has the following weak functions to support the use of dedicated pins for card detect,
 * write protect, pwr en, and io select signals. If the user would like to use non-dedicated pins
 * for these items, see the PDL documentation for how to implement these functions for
 * use with GPIO.
 *   - Cy_SD_Host_IsCardConnected
 *   - Cy_SD_Host_IsWpSet
 *   - Cy_SD_Host_EnableCardVoltage
 *   - Cy_SD_Host_DisableCardVoltage
 *   - Cy_SD_Host_ChangeIoVoltage
 *
 * By default, if the timeout_ms parameter given to \ref mtb_hal_sdhc_erase function is 0. The SDHC
 * HAL driver will check to see if the connected card is emmc. If so, the timeout_ms parameter
 * will be set to 100 milliseconds, otherwise it will be set to 1000 milliseconds.
 * \} group_hal_impl_sdhc
 */


#if (MTB_HAL_DRIVER_AVAILABLE_SDHC)

#if defined(__cplusplus)
extern "C"
{
#endif

#define _MTB_HAL_SDXX_MHZ(x)                              (((uint32_t)(x)) * 1000UL * 1000UL)

#define _MTB_HAL_SDHC_RW_RETRY_CYCLES                     (1000u)     /* Number of cycles for
                                                                         read/write operation
                                                                         complete */
#define _MTB_HAL_SDHC_BLOCK_SIZE                          (512U)      /* The block size for
                                                                         transfers done with SDHC */
#define _MTB_HAL_SDHC_RETRY_TIMES                         (1000UL)    /* The number loops to make
                                                                         the timeout in msec */
#define _MTB_HAL_SDHC_FUJE_TIMEOUT_MS                     (1000U)     /* The Fuje timeout for
                                                                         one block */
#define _MTB_HAL_SDHC_RW_TIMEOUT_US                       (500U)      /* The SDHC Read/Write timeout
                                                                         for one block */
#define _MTB_HAL_SDHC_TRANSFER_TIMEOUT                    (0xCUL)     /* The transfer timeout */
#define _MTB_HAL_SDHC_EMMC_TRIM_DELAY_MS                  (100U)      /* The EMMC TRIM timeout */
#define _MTB_HAL_SDHC_ALL_ERR_INTERRUPTS                  \
    (MTB_HAL_SDHC_CMD_TOUT_ERR | MTB_HAL_SDHC_CMD_CRC_ERR |\
    MTB_HAL_SDHC_CMD_END_BIT_ERR | MTB_HAL_SDHC_CMD_IDX_ERR |\
    MTB_HAL_SDHC_DATA_TOUT_ERR | MTB_HAL_SDHC_DATA_CRC_ERR |\
    MTB_HAL_SDHC_DATA_END_BIT_ERR | MTB_HAL_SDHC_CUR_LMT_ERR |\
    MTB_HAL_SDHC_AUTO_CMD_ERR | MTB_HAL_SDHC_ADMA_ERR |\
    MTB_HAL_SDHC_TUNNING_ERR | MTB_HAL_SDHC_RESP_ERR |\
    MTB_HAL_SDHC_BOOT_ACK_ERR)

#define _MTB_HAL_SDHC_RCA_SHIFT                           (16U)
#define _MTB_HAL_SDHC_1_8_REG_STABLE_TIME_MS              (30U)       /* The 1.8 voltage regulator
                                                                         stable time. */
#define _MTB_HAL_SDHC_PWR_RAMP_UP_TIME_MS                 (36U)       /* Time needed for card VDD to
                                                                         achieve operating
                                                                       * supply range level after
                                                                       * power on (power on time,
                                                                       * 1 ms + pwr ramp up,
                                                                       * max 35 ms) */
#define _MTB_HAL_SDHC_TOUT_TMCLK_POW_MIN                  (13U)        /* Minimal power of 2 for
                                                                          data timeout counter value
                                                                        */
#define _MTB_HAL_SDHC_TOUT_TMCLK_POW_MAX                  (27U)        /* Maximal power of 2 for
                                                                          data timeout counter value
                                                                        */
#define _MTB_HAL_SDHC_EXPECTED_BASE_CLK_FREQ_HZ           (_MTB_HAL_SDXX_MHZ(100))
/* By default SDHC block is expected to be clocked by 100 MHz */
#define _MTB_HAL_SDHC_UPPER_FREQ_SEL_POS                  (8U)       /* To shift upper bits in Freq
                                                                        Sel to proper position */

#define _MTB_HAL_SDHC_EXTCSD_SIZE                         (512U)       /* EMMC EXT_CSD register size
                                                                          in bytes */
#define _MTB_HAL_SDHC_EMMC_CMD6_TIMEOUT_MULT              (10U)        /* The 10x multiplier of
                                                                          GENERIC_CMD6_TIME[248]. */
#define _MTB_HAL_SDHC_EXTCSD_GENERIC_CMD6_TIME            (248U)       /* Idx of GENERIC_CMD6_TIME
                                                                          byte in EXT_CSD register
                                                                        */
#define _MTB_HAL_SDHC_EMMC_MAX_SUP_FREQ_HZ                (_MTB_HAL_SDXX_MHZ(52))
/* Maximal supported frequency for eMMC for current
 * implementation */

#define _MTB_HAL_SDIO_CMD_CMPLT_DELAY_US                  (5U)        /* The Command complete delay
                                                                       */
#define _MTB_HAL_SDIO_HOST_CLK_400K                       (400UL * 1000UL)    /* 400 kHz clock
                                                                                 frequency */
#define _MTB_HAL_SDIO_64B_BLOCK                           (64U)
#define _MTB_HAL_SDIO_DATA_TIMEOUT                        (0x0dUL)


#define _MTB_HAL_SDIO_SET_ALL_INTERRUPTS_MASK             (0x61FFUL)
#define _MTB_HAL_SDIO_TRANSFER_TRIES                      (50U)
#define _MTB_HAL_SDXX_MAX_FREQUENCY                       (50000000)

#if (defined(SDHC_CHIP_TOP_DATA8_PRESENT) && (SDHC_CHIP_TOP_DATA8_PRESENT)) || \
    (defined(SDHC0_CHIP_TOP_DATA8_PRESENT) && (SDHC0_CHIP_TOP_DATA8_PRESENT)) || \
    (defined(SDHC1_CHIP_TOP_DATA8_PRESENT) && (SDHC1_CHIP_TOP_DATA8_PRESENT))
    #define _MTB_HAL_SDHC_DATA8_PRESENT   1
#else
    #define _MTB_HAL_SDHC_DATA8_PRESENT   0
#endif
#if (defined(SDHC_CHIP_TOP_CARD_DETECT_PRESENT) && (SDHC_CHIP_TOP_CARD_DETECT_PRESENT)) || \
    (defined(SDHC0_CHIP_TOP_CARD_DETECT_PRESENT) && (SDHC0_CHIP_TOP_CARD_DETECT_PRESENT)) || \
    (defined(SDHC1_CHIP_TOP_CARD_DETECT_PRESENT) && (SDHC1_CHIP_TOP_CARD_DETECT_PRESENT))
    #define _MTB_HAL_SDHC_CARD_DETECT_PRESENT   1
#else
    #define _MTB_HAL_SDHC_CARD_DETECT_PRESENT   0
#endif
#if (defined(SDHC_CHIP_TOP_CARD_WRITE_PROT_PRESENT) && (SDHC_CHIP_TOP_CARD_WRITE_PROT_PRESENT)) || \
    (defined(SDHC0_CHIP_TOP_CARD_WRITE_PROT_PRESENT) && (SDHC0_CHIP_TOP_CARD_WRITE_PROT_PRESENT)) || \
    (defined(SDHC1_CHIP_TOP_CARD_WRITE_PROT_PRESENT) && (SDHC1_CHIP_TOP_CARD_WRITE_PROT_PRESENT))
    #define _MTB_HAL_SDHC_CARD_WRITE_PROT_PRESENT   1
#else
    #define _MTB_HAL_SDHC_CARD_WRITE_PROT_PRESENT   0
#endif
#if (defined(SDHC_CHIP_TOP_LED_CTRL_PRESENT) && (SDHC_CHIP_TOP_LED_CTRL_PRESENT)) || \
    (defined(SDHC0_CHIP_TOP_LED_CTRL_PRESENT) && (SDHC0_CHIP_TOP_LED_CTRL_PRESENT)) || \
    (defined(SDHC1_CHIP_TOP_LED_CTRL_PRESENT) && (SDHC1_CHIP_TOP_LED_CTRL_PRESENT))
    #define _MTB_HAL_SDHC_LED_CTRL_PRESENT   1
#else
    #define _MTB_HAL_SDHC_LED_CTRL_PRESENT   0
#endif
#if (defined(SDHC_CHIP_TOP_IO_VOLT_SEL_PRESENT) && (SDHC_CHIP_TOP_IO_VOLT_SEL_PRESENT)) || \
    (defined(SDHC0_CHIP_TOP_IO_VOLT_SEL_PRESENT) && (SDHC0_CHIP_TOP_IO_VOLT_SEL_PRESENT)) || \
    (defined(SDHC1_CHIP_TOP_IO_VOLT_SEL_PRESENT) && (SDHC1_CHIP_TOP_IO_VOLT_SEL_PRESENT))
    #define _MTB_HAL_SDHC_IO_VOLT_SEL_PRESENT   1
#else
    #define _MTB_HAL_SDHC_IO_VOLT_SEL_PRESENT   0
#endif
#if (defined(SDHC_CHIP_TOP_CARD_IF_PWR_EN_PRESENT) && (SDHC_CHIP_TOP_CARD_IF_PWR_EN_PRESENT)) || \
    (defined(SDHC0_CHIP_TOP_CARD_IF_PWR_EN_PRESENT) && (SDHC0_CHIP_TOP_CARD_IF_PWR_EN_PRESENT)) || \
    (defined(SDHC1_CHIP_TOP_CARD_IF_PWR_EN_PRESENT) && (SDHC1_CHIP_TOP_CARD_IF_PWR_EN_PRESENT))
    #define _MTB_HAL_SDHC_CARD_IF_PWR_EN_PRESENT   1
#else
    #define _MTB_HAL_SDHC_CARD_IF_PWR_EN_PRESENT   0
#endif
#if (defined(SDHC_CHIP_TOP_CARD_EMMC_RESET_PRESENT) && (SDHC_CHIP_TOP_CARD_EMMC_RESET_PRESENT)) || \
    (defined(SDHC0_CHIP_TOP_CARD_EMMC_RESET_PRESENT) && (SDHC0_CHIP_TOP_CARD_EMMC_RESET_PRESENT)) || \
    (defined(SDHC1_CHIP_TOP_CARD_EMMC_RESET_PRESENT) && (SDHC1_CHIP_TOP_CARD_EMMC_RESET_PRESENT))
    #define _MTB_HAL_SDHC_CARD_EMMC_RESET_PRESENT   1
#else
    #define _MTB_HAL_SDHC_CARD_EMMC_RESET_PRESENT   0
#endif

/* SDHC/SDIO I/O voltage select principle.
 *  Internal version of mtb_hal_sdhc_io_volt_action_type_t and mtb_hal_sdio_io_volt_action_type_t */
typedef enum
{
    _MTB_HAL_SDXX_IO_VOLT_ACTION_NEGOTIATE         = 0U,
    _MTB_HAL_SDXX_IO_VOLT_ACTION_SWITCH_SEQ_ONLY   = 1U,
    _MTB_HAL_SDXX_IO_VOLT_ACTION_NONE              = 2U
} _mtb_hal_sdxx_io_switch_action_t;

/** I/O voltage levels.
 * Internal version of mtb_hal_sdhc_io_voltage_t and mtb_hal_sdio_io_voltage_t */
typedef enum
{
    _MTB_HAL_SDXX_IO_VOLTAGE_3_3V                  = 0U,   //!< I/O voltage is 3.3V.
    _MTB_HAL_SDXX_IO_VOLTAGE_1_8V                  = 1U    //!< I/O voltage is 1.8V.
} mtb_hal_sdxx_io_voltage_t;

#if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
#include "cyabs_rtos.h"

typedef enum
{
    /* Semaphore is not initialized */
    _MTB_HAL_SDXX_SEMA_NOT_INITED,
    /* Semaphore is initialized, but will not be used */
    _MTB_HAL_SDXX_SEMA_NOT_USED,
    /* Semaphore is initialized and used (expected to be set in IRQ handler) */
    _MTB_HAL_SDXX_SEMA_USED,
    /* Set in irq handler */
    _MTB_HAL_SDXX_SEMA_SET
} _mtb_hal_sdxx_semaphore_status_t;

/* _mtb_hal_sdxx_t would be the better place for keeping these items, but since
 * cy_semaphore_t depends on cyabs_rtos.h that results in circular includes/
 * messy forward declarations. */
static cy_semaphore_t _mtb_hal_sdxx_semaphore_xfer_done[CY_IP_MXSDHC_INSTANCES];
static _mtb_hal_sdxx_semaphore_status_t _mtb_hal_sdxx_semaphore_status[CY_IP_MXSDHC_INSTANCES];

//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdxx_get_block_num
//--------------------------------------------------------------------------------------------------
static uint8_t _mtb_hal_sdxx_get_block_num(_mtb_hal_sdxx_t* sdxx)
{
    #if defined(SDHC0)
    if ((sdxx->base) == SDHC0)
    {
        return (uint8_t)0U;
    }
    #endif
    #if defined(SDHC1)
    if ((sdxx->base) == SDHC1)
    {
        return (uint8_t)1U;
    }
    #endif

    // Should never get here, return an invalid block num
    return (uint8_t)-1;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdxx_is_smfr_ready_for_set
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_sdxx_is_smfr_ready_for_set(_mtb_hal_sdxx_t* sdxx)
{
    CY_ASSERT(sdxx != NULL);
    return (_MTB_HAL_SDXX_SEMA_USED ==
            _mtb_hal_sdxx_semaphore_status[_mtb_hal_sdxx_get_block_num(sdxx)]);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdxx_is_smfr_ready_for_get
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_sdxx_is_smfr_ready_for_get(_mtb_hal_sdxx_t* sdxx)
{
    CY_ASSERT(sdxx != NULL);
    return (_MTB_HAL_SDXX_SEMA_USED ==
            _mtb_hal_sdxx_semaphore_status[_mtb_hal_sdxx_get_block_num(sdxx)]) ||
           (_MTB_HAL_SDXX_SEMA_SET ==
            _mtb_hal_sdxx_semaphore_status[_mtb_hal_sdxx_get_block_num(sdxx)]);
}


#endif /* CY_RTOS_AWARE or COMPONENT_RTOS_AWARE defined */

//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdxx_prepare_for_transfer
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_sdxx_prepare_for_transfer(_mtb_hal_sdxx_t* sdxx)
{
    CY_ASSERT(sdxx != NULL);

    uint32_t activated_cmd_complete = 0;
    if (sdxx->irq_cause & (sdxx->is_sdio ? MTB_HAL_SDIO_CMD_COMPLETE : CY_SD_HOST_CMD_COMPLETE))
    {
        /* Activate CY_SD_HOST_CMD_COMPLETE interrupt mask only if user enabled callback for that
           event */
        activated_cmd_complete = CY_SD_HOST_CMD_COMPLETE;
    }

    /* Enabling transfer complete interrupt as it takes part in in write / read processes */
    Cy_SD_Host_SetNormalInterruptMask(sdxx->base, Cy_SD_Host_GetNormalInterruptMask(
                                          sdxx->base) | activated_cmd_complete |
                                      CY_SD_HOST_XFER_COMPLETE);

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_is_busy
//--------------------------------------------------------------------------------------------------
bool _mtb_hal_sdhc_is_busy(const _mtb_hal_sdxx_t* sdxx)
{
    bool busy_status = true;
    /* Check DAT Line Active */
    uint32_t pState = Cy_SD_Host_GetPresentState(sdxx->base);
    if ((CY_SD_HOST_DAT_LINE_ACTIVE != (pState & CY_SD_HOST_DAT_LINE_ACTIVE)) &&
        (CY_SD_HOST_CMD_CMD_INHIBIT_DAT != (pState & CY_SD_HOST_CMD_CMD_INHIBIT_DAT)))
    {
        busy_status = false;
    }
    return busy_status || (_MTB_HAL_SDXX_NOT_RUNNING != sdxx->data_transfer_status);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdio_is_busy
//--------------------------------------------------------------------------------------------------
bool _mtb_hal_sdio_is_busy(const _mtb_hal_sdxx_t* sdxx)
{
    return (_MTB_HAL_SDXX_NOT_RUNNING != sdxx->data_transfer_status);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_buswidth_hal_to_pdl
//--------------------------------------------------------------------------------------------------
static cy_en_sd_host_bus_width_t _mtb_hal_sdhc_buswidth_hal_to_pdl(uint8_t sd_data_bits)
{
    switch (sd_data_bits)
    {
        case 1:
            return CY_SD_HOST_BUS_WIDTH_1_BIT;

        case 4:
            return CY_SD_HOST_BUS_WIDTH_4_BIT;

        case 8:
            return CY_SD_HOST_BUS_WIDTH_8_BIT;

        default:
            CY_ASSERT(false);
            return CY_SD_HOST_BUS_WIDTH_1_BIT;
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_buswidth_pdl_to_hal
//--------------------------------------------------------------------------------------------------
static uint8_t _mtb_hal_sdhc_buswidth_pdl_to_hal(cy_en_sd_host_bus_width_t sd_data_bits)
{
    switch (sd_data_bits)
    {
        case CY_SD_HOST_BUS_WIDTH_1_BIT:
            return 1;

        case CY_SD_HOST_BUS_WIDTH_4_BIT:
            return 4;

        case CY_SD_HOST_BUS_WIDTH_8_BIT:
            return 8;

        default:
            CY_ASSERT(false);
            return 1;
    }
}


/***********************************************************************************************************************
*
* Finds SDHC internal divider value according to source clock frequency and desired frequency.
*
* hz_src                - Source clock frequency, that needs to be divided
* desired_hz            - Desired clock frequency
* tolerance             - (Not used)
* only_below_desired    - (Not used)
* div                   - Calculated divider value will be placed by this pointer
* min_hf_freq           - (Not used)
*
***********************************************************************************************************************/
static cy_rslt_t _mtb_hal_sdxx_find_best_div(uint32_t hz_src, uint32_t desired_hz,
                                             const mtb_hal_clock_tolerance_t* tolerance,
                                             bool only_below_desired, uint32_t* div,
                                             uint32_t min_hf_freq)
{
    CY_UNUSED_PARAMETER(tolerance);
    CY_UNUSED_PARAMETER(only_below_desired);
    CY_UNUSED_PARAMETER(min_hf_freq);

    /* Rounding up for correcting the error in integer division
     * to ensure the actual frequency is less than or equal to
     * the requested frequency.
     * Ensure computed divider is no more than 10-bit.
     */

    if (hz_src > desired_hz)
    {
        uint32_t freq = (desired_hz << 1);
        uint32_t calculated_divider = ((hz_src + freq - 1) / freq) & 0x3FF;
        /* Real divider is 2 x calculated_divider */
        *div = calculated_divider << 1;
    }
    else
    {
        *div = 1;
    }

    return CY_RSLT_SUCCESS;
}


/***********************************************************************************************************************
*
* Determines SD bus speed mode according to provided clock frequency and updates SDHC HW registers
* with corresponding speed mode setting and, optionally, negotiates new speed mode with the card
*
* sdxx                  - Pointer to SDHC/SDIO common structure
* freq                  - Clock frequency, according to which speed mode will be determined
* lv_signaling          - Support 1.8V
* negotiate             - Whether new frequency value needs to be negotiated with the card
*
***********************************************************************************************************************/
static cy_rslt_t _mtb_hal_sdxx_update_hw_clock_config(_mtb_hal_sdxx_t* sdxx, uint32_t freq,
                                                      bool lv_signaling, bool negotiate)
{
    cy_en_sd_host_bus_speed_mode_t  busSpeed;
    cy_rslt_t                       result;

    if (!sdxx->is_sdio && sdxx->emmc)
    {
        /* legacy MMC speed is 0-26 MHz */
        if (freq <= _MTB_HAL_SDXX_MHZ(26))
        {
            busSpeed = CY_SD_HOST_BUS_SPEED_EMMC_LEGACY;
        }
        /* High Speed SDR is 0-52 MHz */
        else
        {
            busSpeed = CY_SD_HOST_BUS_SPEED_EMMC_HIGHSPEED_SDR;
        }
    }
    else
    {
        if (freq <= _MTB_HAL_SDXX_MHZ(25))
        {
            busSpeed = (lv_signaling)
                ? CY_SD_HOST_BUS_SPEED_SDR12_5
                : CY_SD_HOST_BUS_SPEED_DEFAULT;
        }
        else if (freq <= _MTB_HAL_SDXX_MHZ(50))
        {
            busSpeed = (lv_signaling)
                ? CY_SD_HOST_BUS_SPEED_SDR25
                : CY_SD_HOST_BUS_SPEED_HIGHSPEED;
        }
        else
        {
            busSpeed = (lv_signaling)
                ? CY_SD_HOST_BUS_SPEED_SDR50
                : CY_SD_HOST_BUS_SPEED_HIGHSPEED;
        }
    }

    /* Currently can only negotiate with SD Card. SDIO negotiation proccess is tracked in BSP-2643.
     */
    if (negotiate && !sdxx->is_sdio)
    {
        result = (cy_rslt_t)Cy_SD_Host_SetBusSpeedMode(sdxx->base, busSpeed, sdxx->context);
    }
    else
    {
        result = (cy_rslt_t)Cy_SD_Host_SetHostSpeedMode(sdxx->base, busSpeed);
    }
    return result;
}


/***********************************************************************************************************************
*
* Changes the Host controller SD clock.
*
* sdxx                  - Pointer to SHDC/SDIO common structure
* frequency             - The frequency in Hz (pointer). This variable will be updated with actual
*  frequency achieved upon function return.
* lv_signaling          - Support 1.8V
* negotiate             - Whether new frequency value needs to be negotiated with the card
*
***********************************************************************************************************************/
static cy_rslt_t _mtb_hal_sdxx_sdcardchangeclock(_mtb_hal_sdxx_t* sdxx, uint32_t* frequency,
                                                 bool lv_signaling, bool negotiate)
{
    CY_ASSERT(NULL != sdxx);
    CY_ASSERT(NULL != frequency);
    CY_ASSERT(NULL != sdxx->base);

    cy_rslt_t result = CY_RSLT_SUCCESS;
    uint32_t most_suitable_div = 0;
    uint32_t bus_freq = 0;
    uint32_t source_freq = 0;

    #if defined(CY_IP_MXS22SRSS)
    if (*frequency > _MTB_HAL_SDXX_MHZ(100))
    {
        result = MTB_HAL_SDHC_RSLT_ERR_CLOCK;
    }
    #endif

    if (CY_RSLT_SUCCESS == result)
    {
        result = _mtb_hal_sdxx_find_best_div(sdxx->clock->interface->get_frequency_hz(
                                                 sdxx->clock->clock_ref), *frequency, NULL, false,
                                             &most_suitable_div, 0);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        source_freq = sdxx->clock->interface->get_frequency_hz(sdxx->clock->clock_ref);
        bus_freq = source_freq / most_suitable_div;

        if (CY_RSLT_SUCCESS == result)
        {
            result = _mtb_hal_sdxx_update_hw_clock_config(sdxx, bus_freq, lv_signaling, negotiate);
        }
    }

    if (CY_RSLT_SUCCESS == result)
    {
        Cy_SD_Host_DisableSdClk(sdxx->base);
        result = (cy_rslt_t)Cy_SD_Host_SetSdClkDiv(sdxx->base, most_suitable_div >> 1);
        Cy_SD_Host_EnableSdClk(sdxx->base);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        *frequency = bus_freq;
    }

    return result;
}


/*******************************************************************************
*
* Waits for the command complete event.
*
* sdxx                     - Pointer to SHDC/SDIO common structure
* time_used_ms             - Pointer to uint32_t value for the total time taken for the function.
*
*******************************************************************************/
static cy_en_sd_host_status_t _mtb_hal_sdxx_pollcmdcomplete(_mtb_hal_sdxx_t* sdxx,
                                                            uint32_t* time_used_ms)
{
    cy_en_sd_host_status_t result = CY_SD_HOST_ERROR_TIMEOUT;
    uint32_t retry  = _MTB_HAL_SDHC_RETRY_TIMES * _MTB_HAL_SDIO_CMD_CMPLT_DELAY_US;

    while (retry > 0UL)
    {
        /* Command complete */
        if (CY_SD_HOST_CMD_COMPLETE ==
            (CY_SD_HOST_CMD_COMPLETE & Cy_SD_Host_GetNormalInterruptStatus(sdxx->base)))
        {
            sdxx->data_transfer_status &= ~_MTB_HAL_SDXX_WAIT_CMD_COMPLETE;

            /* Clear interrupt flag */
            Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base, CY_SD_HOST_CMD_COMPLETE);

            result = CY_SD_HOST_SUCCESS;
            break;
        }

        mtb_hal_system_delay_us(1);
        retry--;
    }
    if (time_used_ms != NULL)
    {
        *time_used_ms =
            (((_MTB_HAL_SDHC_RETRY_TIMES * _MTB_HAL_SDIO_CMD_CMPLT_DELAY_US) - retry) / 1000);
    }

    return result;
}


/*******************************************************************************
*
* Waits for the transfer complete event.
*
* sdxx                  - Pointer to SHDC/SDIO common structure
* delay                 - The delay timeout for one block transfer.
*
* return If the sdxx pointer is NULL, returns error.
*
*******************************************************************************/
static cy_en_sd_host_status_t _mtb_hal_sdxx_polltransfercomplete(_mtb_hal_sdxx_t* sdxx,
                                                                 const uint16_t delay)
{
    cy_en_sd_host_status_t result = CY_SD_HOST_ERROR_TIMEOUT;
    uint32_t               retry = _MTB_HAL_SDHC_RW_RETRY_CYCLES;
    uint32_t               status = 0UL;

    while ((CY_SD_HOST_ERROR_TIMEOUT == result) && (retry-- > 0U))
    {
        /* We check for either the interrupt register or the byte set in the
         * _mtb_hal_sdxx_irq_handler to avoid a deadlock in the case where if an API
         * that is polling is called from an ISR and its priority is higher than the
         * priority of the _mtb_hal_sdxx_irq_handler thus not allowing
         * the signalling byte to be set.
         */
        status = Cy_SD_Host_GetNormalInterruptStatus(sdxx->base);
        if ((CY_SD_HOST_XFER_COMPLETE == (CY_SD_HOST_XFER_COMPLETE & status)) ||
            (sdxx->is_sdio ? !_mtb_hal_sdio_is_busy(sdxx) : !_mtb_hal_sdhc_is_busy(sdxx)))
        {
            /* Transfer complete */
            result = CY_SD_HOST_SUCCESS;
            break;
        }
        mtb_hal_system_delay_us(delay);
    }

    return result;
}


// Indicates that a sync transfer is in process
static void _mtb_hal_sdxx_setup_smphr(_mtb_hal_sdxx_t* sdxx)
{
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    uint8_t block_num = _mtb_hal_sdxx_get_block_num(sdxx);
    bool in_isr = (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0;
    if (!in_isr)
    {
        cy_rslt_t result = CY_RSLT_SUCCESS;
        if (_MTB_HAL_SDXX_SEMA_NOT_INITED == _mtb_hal_sdxx_semaphore_status[block_num])
        {
            /* Semaphore is used to make transfer complete event wait process be more RTOS-friendly.
             * It cannot be initialized in ISR context (some of mbed layers are initializing sdio
             * in ISR conext), so we have to do it in scope of transfer functions. */
            /* Assert that we are not in an ISR */
            CY_ASSERT((SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) == 0);
            result = cy_rtos_init_semaphore(&(_mtb_hal_sdxx_semaphore_xfer_done[block_num]), 1, 0);
        }
        else if (_MTB_HAL_SDXX_SEMA_SET == _mtb_hal_sdxx_semaphore_status[block_num])
        {
            /* Situation, when semaphore was set, but _mtb_hal_sdxx_waitfor_transfer_complete
             * function was not used for the transfer to get the semaphore (async transfer).
             * Clearing the semaphore in order to prepare it for another transfer.  */
            result =
                cy_rtos_get_semaphore(&(_mtb_hal_sdxx_semaphore_xfer_done[block_num]), 500, in_isr);
        }
        if (CY_RSLT_SUCCESS == result)
        {
            _mtb_hal_sdxx_semaphore_status[block_num] = _MTB_HAL_SDXX_SEMA_USED;
        }
    }
    else if (_MTB_HAL_SDXX_SEMA_NOT_INITED != _mtb_hal_sdxx_semaphore_status[block_num])
    {
        _mtb_hal_sdxx_semaphore_status[block_num] = _MTB_HAL_SDXX_SEMA_NOT_USED;
    }
    #else // if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    // We don't need to do anything special if we're not in an RTOS context
    CY_UNUSED_PARAMETER(sdxx);
    #endif // if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdxx_waitfor_transfer_complete
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_sdxx_waitfor_transfer_complete(_mtb_hal_sdxx_t* sdxx)
{
    /* When using an RTOS if a sdxx api (read or write) is called from and ISR in
     * in certain RTOSes cy_rtos_get_semaphore returns immediately without blocking. So we can
     * either busy wait around the semaphore being set in the ISR or use the normal polling method
     * we use in the non-RTOS case. For simplicity and to avoid the calling ISR from depending on
     * the SDXX ISR priority we use the normal polling method.
     */
    cy_rslt_t result = CY_RSLT_SUCCESS;
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    bool in_isr = (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0;
    if ((!in_isr) && _mtb_hal_sdxx_is_smfr_ready_for_get(sdxx))
    {
        result =
            cy_rtos_get_semaphore(&(_mtb_hal_sdxx_semaphore_xfer_done[_mtb_hal_sdxx_get_block_num(
                                                                          sdxx)]), 500, in_isr);
        if (CY_RSLT_SUCCESS == result)
        {
            _mtb_hal_sdxx_semaphore_status[_mtb_hal_sdxx_get_block_num(sdxx)] =
                _MTB_HAL_SDXX_SEMA_NOT_USED;
        }
    }
    else
    {
    #endif // if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    result = (cy_rslt_t)_mtb_hal_sdxx_polltransfercomplete(sdxx, _MTB_HAL_SDHC_RW_TIMEOUT_US);
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
}


    #endif

    return result;
}

//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_irq_handler
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_sdhc_irq_handler(_mtb_hal_sdxx_t* sdxx)
{
    uint32_t interruptStatus = Cy_SD_Host_GetNormalInterruptStatus(sdxx->base);
    uint32_t userInterruptStatus = interruptStatus & sdxx->irq_cause;

    /* Some parts of SDHost PDL and SDHC HAL drivers are sending SD commands and polling interrupt
     * status until CY_SD_HOST_CMD_COMPLETE occurs. Thats why we can't clear
     * CY_SD_HOST_CMD_COMPLETE interrupt status and code below prevents _mtb_hal_sdhc_irq_handler
     * from being continuosly called because of uncleared CY_SD_HOST_CMD_COMPLETE event. */

    if (interruptStatus & Cy_SD_Host_GetNormalInterruptMask(sdxx->base) & CY_SD_HOST_CMD_COMPLETE)
    {
        /* Disabling command complete interrupt mask */
        Cy_SD_Host_SetNormalInterruptMask(sdxx->base,
                                          Cy_SD_Host_GetNormalInterruptMask(
                                              sdxx->base) & (uint32_t) ~CY_SD_HOST_CMD_COMPLETE);
        sdxx->data_transfer_status &= ~_MTB_HAL_SDXX_WAIT_CMD_COMPLETE;
    }

    /* During SDHost PDL driver operation, CY_SD_HOST_XFER_COMPLETE status can occur and driver
     * is polling Cy_SD_Host_GetNormalInterruptStatus while waiting for it. Because of this
     * it is critical to have CY_SD_HOST_XFER_COMPLETE event mask disabled and only enabled during
     * transfers. Write / Read SDHC/SDIO HAL functions are taking care of enabling
     * CY_SD_HOST_XFER_COMPLETE mask before transfer while code below disables it. */

    /* CY_SD_HOST_XFER_COMPLETE occured and appropriate bit in interrupt mask is enabled */
    if (interruptStatus & Cy_SD_Host_GetNormalInterruptMask(sdxx->base) & CY_SD_HOST_XFER_COMPLETE)
    {
        /* Clearing transfer complete status */
        Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base, CY_SD_HOST_XFER_COMPLETE);

        sdxx->data_transfer_status &= ~_MTB_HAL_SDXX_WAIT_XFER_COMPLETE;

        #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
        if (_mtb_hal_sdxx_is_smfr_ready_for_set(sdxx))
        {
            cy_rtos_set_semaphore(&(_mtb_hal_sdxx_semaphore_xfer_done[_mtb_hal_sdxx_get_block_num(
                                                                          sdxx)]), true);
            _mtb_hal_sdxx_semaphore_status[_mtb_hal_sdxx_get_block_num(sdxx)] =
                _MTB_HAL_SDXX_SEMA_SET;
        }
        #endif /* CY_RTOS_AWARE or COMPONENT_RTOS_AWARE defined */

        /* Disabling transfer complete interrupt mask */
        Cy_SD_Host_SetNormalInterruptMask(sdxx->base,
                                          Cy_SD_Host_GetNormalInterruptMask(
                                              sdxx->base) & (uint32_t) ~CY_SD_HOST_XFER_COMPLETE);
    }

    /* Cannot clear cmd complete interrupt, as it is being polling-waited by many SD Host
       functions. It is expected to be cleared by mentioned polling functions. */
    userInterruptStatus &= (uint32_t) ~CY_SD_HOST_CMD_COMPLETE;

    /* Clear only handled events */
    Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base, userInterruptStatus);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdio_irq_handler
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_sdio_irq_handler(mtb_hal_sdio_t* obj)
{
    uint32_t interruptStatus = Cy_SD_Host_GetNormalInterruptStatus(obj->sdxx.base);
    uint32_t userInterruptStatus = interruptStatus & obj->sdxx.irq_cause;
    uint32_t normalInterruptMask = Cy_SD_Host_GetNormalInterruptMask(obj->sdxx.base);

    /* Some parts of SDHost PDL and SDIO HAL drivers are sending SD commands and polling interrupt
     * status until CY_SD_HOST_CMD_COMPLETE occurs. Thats why we can't clear
     * CY_SD_HOST_CMD_COMPLETE interrupt status and code below prevents _mtb_hal_sdio_irq_handler
     * from being continuosly called because of uncleared CY_SD_HOST_CMD_COMPLETE event. */

    if (interruptStatus & normalInterruptMask & CY_SD_HOST_CMD_COMPLETE)
    {
        /* Disabling command complete interrupt mask */
        Cy_SD_Host_SetNormalInterruptMask(obj->sdxx.base,
                                          Cy_SD_Host_GetNormalInterruptMask(obj->sdxx.base) &
                                          (uint32_t) ~CY_SD_HOST_CMD_COMPLETE);
        obj->sdxx.data_transfer_status &= ~_MTB_HAL_SDXX_WAIT_CMD_COMPLETE;
    }

    /* During SDHost PDL driver operation, CY_SD_HOST_XFER_COMPLETE status can occur and driver
     * is polling Cy_SD_Host_GetNormalInterruptStatus while waiting for it. Because of this
     * it is critical to have CY_SD_HOST_XFER_COMPLETE event mask disabled and only enabled during
     * transfers. Write / Read SDHC/SDIO HAL functions are taking care of enabling
     * CY_SD_HOST_XFER_COMPLETE mask before transfer while code below disables it. */

    /*  We don't want to modify userInterruptStatus before the callback, but we should still clear
     *  the interrupts as soon as soon as we're able, so assign to a new variable to modify,
     *  then clear the interrupts before performing the callback, without modifying what we pass
     *  into the callback. */
    uint32_t interruptsToClear = userInterruptStatus;

    /*  Cannot clear cmd complete interrupt, as it is being polling-waited by many SD Host
     *  functions. It is expected to be cleared by mentioned polling functions. */
    interruptsToClear &= (uint32_t) ~CY_SD_HOST_CMD_COMPLETE;

    /*  CY_SD_HOST_XFER_COMPLETE occured and appropriate bit in interrupt mask is enabled */
    if (interruptStatus & normalInterruptMask & CY_SD_HOST_XFER_COMPLETE)
    {
        obj->sdxx.data_transfer_status &= ~_MTB_HAL_SDXX_WAIT_XFER_COMPLETE;
        interruptsToClear |= (uint32_t)CY_SD_HOST_XFER_COMPLETE;
        #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
        if (_mtb_hal_sdxx_is_smfr_ready_for_set(&(obj->sdxx)))
        {
            cy_rtos_set_semaphore(&(_mtb_hal_sdxx_semaphore_xfer_done[
                                        _mtb_hal_sdxx_get_block_num(&(obj->sdxx))]), true);
            _mtb_hal_sdxx_semaphore_status[_mtb_hal_sdxx_get_block_num(&(obj->sdxx))] =
                _MTB_HAL_SDXX_SEMA_SET;
        }
        #endif /* CY_RTOS_AWARE or COMPONENT_RTOS_AWARE defined */

        /* Disabling transfer complete interrupt mask */
        Cy_SD_Host_SetNormalInterruptMask(obj->sdxx.base,
                                          Cy_SD_Host_GetNormalInterruptMask(obj->sdxx.base) &
                                          (uint32_t) ~CY_SD_HOST_XFER_COMPLETE);

        /* Transfer is no more active. If card interrupt was not yet enabled after it was disabled
         * in interrupt handler, enable it.
         */
        uint32_t interrupt_enable_status = Cy_SD_Host_GetNormalInterruptEnable(obj->sdxx.base);
        if ((interrupt_enable_status & CY_SD_HOST_CARD_INTERRUPT) == 0)
        {
            Cy_SD_Host_SetNormalInterruptEnable(obj->sdxx.base,
                                                (interrupt_enable_status |
                                                 CY_SD_HOST_CARD_INTERRUPT));
        }
    }

    /* Clear only handled events */
    Cy_SD_Host_ClearNormalInterruptStatus(obj->sdxx.base, interruptsToClear);

    /* To clear Card Interrupt need to disable Card Interrupt Enable bit.
     * The Card Interrupt is enabled after the current transfer is complete
     */
    if (0U != (interruptStatus & CY_SD_HOST_CARD_INTERRUPT))
    {
        uint32_t interruptMask = Cy_SD_Host_GetNormalInterruptEnable(obj->sdxx.base);
        interruptMask &= (uint32_t) ~CY_SD_HOST_CARD_INTERRUPT;
        /* Disable Card Interrupt */
        Cy_SD_Host_SetNormalInterruptEnable(obj->sdxx.base, interruptMask);
    }

    if ((obj->callback_data.callback != NULL) && ((userInterruptStatus & normalInterruptMask) > 0))
    {
        mtb_hal_sdio_event_callback_t callback =
            (mtb_hal_sdio_event_callback_t)obj->callback_data.callback;
        /* Call registered callbacks here */
        /* We may have masked off CMD_COMPLETE above on a previous interrupt, mask here with
           normalInterruptMask to echo this */
        (callback)(obj->callback_data.callback_arg,
                   (mtb_hal_sdio_event_t)(userInterruptStatus & normalInterruptMask));
    }
}


/* Software reset of SDHC block data and command circuits */
static void _mtb_hal_sdxx_reset(_mtb_hal_sdxx_t* sdxx)
{
    CY_ASSERT(NULL != sdxx);
    CY_ASSERT(NULL != sdxx->base);

    sdxx->data_transfer_status = _MTB_HAL_SDXX_NOT_RUNNING;
    Cy_SD_Host_SoftwareReset(sdxx->base, CY_SD_HOST_RESET_DATALINE);
    Cy_SD_Host_SoftwareReset(sdxx->base, CY_SD_HOST_RESET_CMD_LINE);
}


// Internal function is needed for switching from 1.8V IO Voltage Signaling to 3.3V Signaling, due
// to a necessary power cycle of the card
static cy_rslt_t _mtb_hal_sdhc_init_card_common(mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->sdxx.base);

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    /* Initialize the card */
    cy_rslt_t result =
        (cy_rslt_t)Cy_SD_Host_InitCard(sdxx->base, obj->card_config, sdxx->context);

    if (CY_RSLT_SUCCESS == result)
    {
        result = mtb_hal_sdhc_set_frequency(obj, _MTB_HAL_SDXX_MHZ(25), true);
    }

    if ((CY_RSLT_SUCCESS == result) && (sdxx->emmc))
    {
        uint8_t ext_csd[_MTB_HAL_SDHC_EXTCSD_SIZE] = { 0UL };
        memset(&ext_csd, 0x00, sizeof(ext_csd));
        if (CY_RSLT_SUCCESS ==
            (cy_rslt_t)Cy_SD_Host_GetExtCsd(sdxx->base, (uint32_t*)ext_csd, sdxx->context))
        {
            /* Get GENERIC_CMD6_TIME [248] of the EXTCSD register */
            obj->emmc_generic_cmd6_time_ms =
                (uint16_t)(_MTB_HAL_SDHC_EMMC_CMD6_TIMEOUT_MULT *
                           ext_csd[_MTB_HAL_SDHC_EXTCSD_GENERIC_CMD6_TIME]);
        }
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_setup(mtb_hal_sdhc_t* obj, const mtb_hal_sdhc_configurator_t* config,
                             const mtb_hal_clock_t* clock,
                             cy_stc_sd_host_context_t* sdhc_host_context)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != config);
    memset(obj, 0, sizeof(mtb_hal_sdhc_t));

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    obj->low_voltage_io_desired = config->card_config->lowVoltageSignaling;
    obj->bus_width = _mtb_hal_sdhc_buswidth_pdl_to_hal(config->card_config->busWidth);

    sdxx->obj = obj;
    sdxx->is_sdio = false;

    sdxx->dma_type = config->host_config->dmaType;

    if (config->host_config->dmaType != CY_SD_HOST_DMA_ADMA2)
    {
        /* SDHC HAL does not support non-CY_SD_HOST_DMA_ADMA2 DMA configurations */
        return MTB_HAL_SDHC_RSLT_ERR_UNSUPPORTED;
    }

    CY_ASSERT(NULL != sdhc_host_context);

    sdxx->context = sdhc_host_context;

    // If NULL, use the clock provided from device-configurator selections
    if (clock != NULL)
    {
        sdxx->clock = clock;
    }
    else
    {
        CY_ASSERT(config->clock != NULL);

        sdxx->clock = config->clock;
    }

    sdxx->pin_cmd = config->gpios.cmd;
    sdxx->pin_clk = config->gpios.clk;
    obj->pin_data[0] = config->gpios.data[0];
    obj->pin_data[1] = config->gpios.data[1];
    obj->pin_data[2] = config->gpios.data[2];
    obj->pin_data[3] = config->gpios.data[3];
    obj->pin_data[4] = config->gpios.data[4];
    obj->pin_data[5] = config->gpios.data[5];
    obj->pin_data[6] = config->gpios.data[6];
    obj->pin_data[7] = config->gpios.data[7];
    obj->card_config = config->card_config;

    obj->data_timeout_tout = _MTB_HAL_SDHC_TRANSFER_TIMEOUT;
    obj->data_timeout_card_clocks_user = 0;
    obj->data_timeout_auto_reconfig = false;

    sdxx->base = config->base;
    sdxx->data_transfer_status = _MTB_HAL_SDXX_NOT_RUNNING;
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    _mtb_hal_sdxx_semaphore_status[_mtb_hal_sdxx_get_block_num(sdxx)] =
        _MTB_HAL_SDXX_SEMA_NOT_INITED;
    #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */

    sdxx->emmc = config->host_config->emmc;

    sdxx->irq_cause = 0UL;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_erase
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_erase(mtb_hal_sdhc_t* obj, uint32_t start_addr, size_t length,
                             uint32_t timeout_ms)
{
    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    if (timeout_ms == 0)
    {
        timeout_ms = sdxx->emmc ? _MTB_HAL_SDHC_EMMC_TRIM_DELAY_MS : _MTB_HAL_SDHC_RETRY_TIMES;
    }
    if (0 == length)
    {
        return MTB_HAL_SDHC_RSLT_ERR_WRONG_PARAM;
    }

    cy_rslt_t result = CY_RSLT_SUCCESS;
    cy_en_sd_host_erase_type_t eraseType = CY_SD_HOST_ERASE_ERASE;
    uint32_t cardStatus;

    if (sdxx->emmc)
    {
        eraseType = CY_SD_HOST_ERASE_TRIM;
    }

    /* First clear out the transfer and command complete statuses */
    Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base,
                                          (CY_SD_HOST_XFER_COMPLETE | CY_SD_HOST_CMD_COMPLETE));

    if (sdxx->irq_cause & CY_SD_HOST_CMD_COMPLETE)
    {
        /* Enabling command complete interrupt mask if corresponding event was enabled by user
         * _mtb_hal_sdhc_irq_handler will disable CY_SD_HOST_CMD_COMPLETE mask once interrupt
         * is generated. */
        Cy_SD_Host_SetNormalInterruptMask(sdxx->base, Cy_SD_Host_GetNormalInterruptMask(
                                              sdxx->base) |
                                          CY_SD_HOST_CMD_COMPLETE);
    }

    result = (cy_rslt_t)Cy_SD_Host_Erase(sdxx->base, start_addr, (start_addr + length - 1),
                                         eraseType, sdxx->context);

    if (CY_RSLT_SUCCESS == result)
    {
        uint32_t time_used_ms;
        result = (cy_rslt_t)_mtb_hal_sdxx_pollcmdcomplete(sdxx, &time_used_ms);
        timeout_ms = timeout_ms - time_used_ms;
    }
    if (CY_RSLT_SUCCESS == result)
    {
        if (false == sdxx->emmc)
        {
            /* polling result */
            result = MTB_HAL_SDHC_RSLT_ERR_ERASE_CMPLT_TIMEOUT;
            while (timeout_ms > 0)
            {
                cardStatus = Cy_SD_Host_GetCardStatus(sdxx->base, sdxx->context);
                if (((CY_SD_HOST_CARD_TRAN << CY_SD_HOST_CMD13_CURRENT_STATE) |
                     (1UL << CY_SD_HOST_CMD13_READY_FOR_DATA)) == cardStatus)
                {
                    result = CY_RSLT_SUCCESS;
                    break;
                }
                mtb_hal_system_delay_us(_MTB_HAL_SDHC_FUJE_TIMEOUT_MS); /* The Fuje timeout for
                                                                           one block. */
                timeout_ms--;
            }
        }
        else
        {
            mtb_hal_system_delay_ms(timeout_ms);
        }
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_async_transfer
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_sdhc_async_transfer(mtb_hal_sdhc_t* obj, uint32_t address,
                                              size_t* length,
                                              cy_stc_sd_host_write_read_config_t* dataConfig,
                                              bool write)
{
    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);
    cy_rslt_t result;

    /* The address to write/read data on the card or eMMC. */
    dataConfig->address = address;
    /* The number of blocks to write/read. */
    dataConfig->numberOfBlocks = (uint32_t)*length;
    dataConfig->autoCommand = (1UL == (uint32_t)*length)
        ? CY_SD_HOST_AUTO_CMD_NONE
        : CY_SD_HOST_AUTO_CMD_AUTO;
    /* The timeout value for the transfer. */
    dataConfig->dataTimeout = obj->data_timeout_tout;
    /* For EMMC cards enable reliable write. */
    dataConfig->enReliableWrite = false;
    dataConfig->enableDma = true;

    #if defined(CORE_NAME_CM55_0)
    SCB_CleanDCache_by_Addr((void*)dataConfig->data,
                            (uint32_t)(dataConfig->numberOfBlocks * _MTB_HAL_SDHC_BLOCK_SIZE));
    #endif

    /* First clear out the transfer and command complete statuses */
    Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base,
                                          (CY_SD_HOST_XFER_COMPLETE | CY_SD_HOST_CMD_COMPLETE));

    result = _mtb_hal_sdxx_prepare_for_transfer(sdxx);

    if (CY_RSLT_SUCCESS == result)
    {
        // The PDL takes care of the cmd complete stage in sdhc mode so we can jump straight
        // to waiting for the xfer complete
        sdxx->data_transfer_status = _MTB_HAL_SDXX_WAIT_XFER_COMPLETE;
        if (write)
        {
            result = (cy_rslt_t)Cy_SD_Host_Write(sdxx->base, dataConfig, sdxx->context);
        }
        else
        {
            result = (cy_rslt_t)Cy_SD_Host_Read(sdxx->base, dataConfig, sdxx->context);
        }
        /* Write/Read operation failed */
        if (CY_RSLT_SUCCESS != result)
        {
            sdxx->data_transfer_status = _MTB_HAL_SDXX_NOT_RUNNING;
        }
    }

    #if defined(CORE_NAME_CM55_0)
    SCB_InvalidateDCache_by_Addr((void*)dataConfig->data,
                                 (uint32_t)(dataConfig->numberOfBlocks * _MTB_HAL_SDHC_BLOCK_SIZE));
    #endif

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_read_async
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_read_async(mtb_hal_sdhc_t* obj, uint32_t address, uint8_t* data,
                                  size_t* length)
{
    cy_stc_sd_host_write_read_config_t dataConfig;

    /* The pointer to data. */
    dataConfig.data = (uint32_t*)data;
    /* Pass false, we are not writing, but we are instead reading */
    return _mtb_hal_sdhc_async_transfer(obj, address, length, &dataConfig, false);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_write_async
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_write_async(mtb_hal_sdhc_t* obj, uint32_t address, const uint8_t* data,
                                   size_t* length)
{
    cy_stc_sd_host_write_read_config_t dataConfig;

    /* The pointer to data. */
    dataConfig.data = (uint32_t*)data;
    /* Pass true, as we are writing */
    return _mtb_hal_sdhc_async_transfer(obj, address, length, &dataConfig, true);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_is_card_inserted
//--------------------------------------------------------------------------------------------------
bool mtb_hal_sdhc_is_card_inserted(const mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->sdxx.base);
    return Cy_SD_Host_IsCardConnected(obj->sdxx.base);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_is_card_mech_write_protected
//--------------------------------------------------------------------------------------------------
bool mtb_hal_sdhc_is_card_mech_write_protected(const mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->sdxx.base);
    return Cy_SD_Host_IsWpSet(obj->sdxx.base);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_get_block_count
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_get_block_count(mtb_hal_sdhc_t* obj, uint32_t* block_count)
{
    CY_ASSERT(NULL != obj);

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);
    cy_rslt_t result = MTB_HAL_SDHC_RSLT_ERR_BLOCK_COUNT_GET_FAILURE;

    if (CY_SD_HOST_SUCCESS == Cy_SD_Host_GetBlockCount(sdxx->base, block_count, sdxx->context))
    {
        result = CY_RSLT_SUCCESS;
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_set_frequency
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_set_frequency(mtb_hal_sdhc_t* obj, uint32_t hz, bool negotiate)
{
    CY_ASSERT(NULL != obj);
    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    cy_rslt_t result = MTB_HAL_SDHC_RSLT_ERR_SET_FREQ;
    if (NULL != sdxx->base)
    {
        if ((sdxx->emmc) && (_MTB_HAL_SDHC_EMMC_MAX_SUP_FREQ_HZ < hz))
        {
            /* Maximal supported frequency for eMMC for current implementation is exceeded */
            return MTB_HAL_SDHC_RSLT_ERR_UNSUPPORTED;
        }

        /*  Assigning for desired freq as for now and this variable
         *  will be updated with achieved freq. */
        uint32_t actual_freq = hz;
        /* Register check tells us whether we are using 1.8V or 3.3V, used for determining if reset
           is required */
        bool low_voltage_io_set = (_FLD2BOOL(SDHC_CORE_HOST_CTRL2_R_SIGNALING_EN,
                                             SDHC_CORE_HOST_CTRL2_R(obj->sdxx.base)));

        result = _mtb_hal_sdxx_sdcardchangeclock(sdxx, &actual_freq, low_voltage_io_set, negotiate);
        if (CY_RSLT_SUCCESS == result)
        {
            if (obj->data_timeout_auto_reconfig && (0 != obj->data_timeout_card_clocks_user))
            {
                /* User have data timeout configured, we need to reconfigure it according to new
                   card clock */
                result = mtb_hal_sdhc_set_data_read_timeout(obj, obj->data_timeout_card_clocks_user,
                                                            true);
            }
        }
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_get_sdclk_div
//--------------------------------------------------------------------------------------------------
static uint16_t _mtb_hal_sdhc_get_sdclk_div(mtb_hal_sdhc_t* obj)
{
    uint16_t clkDiv = 0;
    uint16_t upperFreqSel =
        _FLD2VAL(SDHC_CORE_CLK_CTRL_R_UPPER_FREQ_SEL, SDHC_CORE_CLK_CTRL_R(obj->sdxx.base));
    uint16_t lowerFreqSel =
        _FLD2VAL(SDHC_CORE_CLK_CTRL_R_FREQ_SEL, SDHC_CORE_CLK_CTRL_R(obj->sdxx.base));

    clkDiv = ((upperFreqSel << _MTB_HAL_SDHC_UPPER_FREQ_SEL_POS) | lowerFreqSel);

    return clkDiv;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_get_frequency
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_sdhc_get_frequency(mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    uint16_t clkDiv = _mtb_hal_sdhc_get_sdclk_div(obj);

    // If clkDiv is returned 0, then source clock is not divided
    if (clkDiv == (uint16_t)0)
    {
        return (obj->sdxx.clock->interface->get_frequency_hz(obj->sdxx.clock->clock_ref));
    }
    else
    {
        // SDHC bus freq is 1/(2*clkDiv)
        return (obj->sdxx.clock->interface->get_frequency_hz(obj->sdxx.clock->clock_ref) /
                (clkDiv * 2));
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_set_data_read_timeout
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_set_data_read_timeout(mtb_hal_sdhc_t* obj, uint32_t timeout,
                                             bool auto_reconfigure)
{
    CY_ASSERT(NULL != obj);

    uint32_t current_card_clock = mtb_hal_sdhc_get_frequency(obj);

    /* TMCLK works on 1 MHz in current block implementation if corresponding HF clock is 100 MHz.
     *  This is defined in registers (TOUT_CLK_FREQ[5:0] = 1 and TOUT_CLK_UNIT[7] = 1).  */
    cy_float32_t tout_clk_period_us = _MTB_HAL_SDHC_EXPECTED_BASE_CLK_FREQ_HZ /
                                      (cy_float32_t)(obj->sdxx.clock->interface->get_frequency_hz(
                                                         obj->sdxx.clock->clock_ref));

    uint32_t user_needs_us = (((uint64_t)timeout * 1000000) + current_card_clock - 1) /
                             current_card_clock;

    /* Timeout range from 0x0 to 0xE is valid, which corresponds to
     * TMCLK x 2^13 for 0, TMCLK x 2^14 for 1, ..., TMCLK x 2^27 for 0xE. 0xF is reserved. */
    const uint8_t tout_clk_power_base = _MTB_HAL_SDHC_TOUT_TMCLK_POW_MIN;
    for (uint8_t tmclk_power = tout_clk_power_base; tmclk_power <= _MTB_HAL_SDHC_TOUT_TMCLK_POW_MAX;
         tmclk_power++)
    {
        if (tout_clk_period_us * ((uint32_t)1 << tmclk_power) >= user_needs_us)
        {
            obj->data_timeout_tout = tmclk_power - tout_clk_power_base;
            obj->data_timeout_card_clocks_user = timeout;
            obj->data_timeout_auto_reconfig = auto_reconfigure;
            return CY_RSLT_SUCCESS;
        }
    }
    return MTB_HAL_SDHC_RSLT_ERR_TOUT_CFG;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_config_data_transfer
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_config_data_transfer(mtb_hal_sdhc_t* obj,
                                            mtb_hal_sdhc_data_config_t* data_config)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != data_config);

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);
    CY_ASSERT(NULL != sdxx->base);

    if (NULL == data_config->data_ptr)
    {
        return MTB_HAL_SDHC_RSLT_ERR_WRONG_PARAM;
    }

    cy_stc_sd_host_data_config_t dataConfig =
    {
        .blockSize           = data_config->block_size,
        .numberOfBlock       = data_config->number_of_blocks,
        .enableDma           = true,
        .autoCommand         = (cy_en_sd_host_auto_cmd_t)data_config->auto_command,
        .read                = data_config->is_read,
        /* .data is skipped to configure adma2 descriptor for it later */
        .dataTimeout         = obj->data_timeout_tout,
        .enableIntAtBlockGap = false,
        .enReliableWrite     = false
    };

    uint32_t length = data_config->block_size * data_config->number_of_blocks;

    sdxx->adma_descriptor_tbl[0] = (1UL << CY_SD_HOST_ADMA_ATTR_VALID_POS) | /* Attr Valid */
                                   (1UL << CY_SD_HOST_ADMA_ATTR_END_POS) | /* Attr End */
                                   (0UL << CY_SD_HOST_ADMA_ATTR_INT_POS) | /* Attr Int */
                                   (CY_SD_HOST_ADMA_TRAN << CY_SD_HOST_ADMA_ACT_POS) |
                                   (length << CY_SD_HOST_ADMA_LEN_POS); /* Len */

    /* SDHC needs to be able to access the data_ptr that is in DTCM when using CM55. Remap this
       address for access */
    #if defined(CORE_NAME_CM55_0)
    sdxx->adma_descriptor_tbl[1] = (uint32_t)cy_DTCMRemapAddr(data_config->data_ptr);
    dataConfig.data = (uint32_t*)cy_DTCMRemapAddr(&sdxx->adma_descriptor_tbl[0]); /* The address of
                                                                                     the ADMA
                                                                                     descriptor
                                                                                     table. */
    #else
    sdxx->adma_descriptor_tbl[1] = (uint32_t)data_config->data_ptr;
    dataConfig.data = (uint32_t*)&sdxx->adma_descriptor_tbl[0]; /* The address of the ADMA
                                                                   descriptor table. */
    #endif

    return (cy_rslt_t)Cy_SD_Host_InitDataTransfer(sdxx->base, &dataConfig);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_send_cmd
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_send_cmd(mtb_hal_sdhc_t* obj, mtb_hal_sdhc_cmd_config_t* cmd_config)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != cmd_config);

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);
    CY_ASSERT(NULL != sdxx->base);

    cy_rslt_t result = CY_RSLT_SUCCESS;
    bool cmd_data_present = (NULL != cmd_config->data_config);

    cy_stc_sd_host_cmd_config_t cmd =
    {
        .commandIndex                 = cmd_config->command_index,
        .commandArgument              = cmd_config->command_argument,
        .enableCrcCheck               = cmd_config->enable_crc_check,
        .enableAutoResponseErrorCheck = false,
        .respType                     = (cy_en_sd_host_response_type_t)cmd_config->response_type,
        .enableIdxCheck               = cmd_config->enable_idx_check,
        .dataPresent                  = cmd_data_present,
        .cmdType                      = (cy_en_sd_host_cmd_type_t)cmd_config->command_type
    };

    /* First clear out the transfer and command complete statuses */
    Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base,
                                          (CY_SD_HOST_XFER_COMPLETE | CY_SD_HOST_CMD_COMPLETE));

    if (cmd_data_present)
    {
        result = _mtb_hal_sdxx_prepare_for_transfer(sdxx);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        if (cmd_data_present)
        {
            /* Data will be transfered in scope of this command, so setting _MTB_HAL_SDXX_WAIT_BOTH
             * (cmd and data) and setting up xfer complete semaphore */
            sdxx->data_transfer_status = _MTB_HAL_SDXX_WAIT_BOTH;
            _mtb_hal_sdxx_setup_smphr(sdxx);
        }
        else
        {
            /* No data is transfered in this command, just waiting for cmd to complete */
            sdxx->data_transfer_status = _MTB_HAL_SDXX_WAIT_CMD_COMPLETE;
        }
        result = (cy_rslt_t)Cy_SD_Host_SendCommand(sdxx->base, &cmd);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        result = (cy_rslt_t)_mtb_hal_sdxx_pollcmdcomplete(sdxx, NULL);
    }

    if (CY_RSLT_SUCCESS != result)
    {
        /* Transfer failed */
        sdxx->data_transfer_status = _MTB_HAL_SDXX_NOT_RUNNING;
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_get_response
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_get_response(mtb_hal_sdhc_t* obj, uint32_t* response, bool large_response)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->sdxx.base);
    CY_ASSERT(NULL != response);
    return (cy_rslt_t)Cy_SD_Host_GetResponse(obj->sdxx.base, response, large_response);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_wait_transfer_complete
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_wait_transfer_complete(mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->sdxx.base);
    return _mtb_hal_sdxx_waitfor_transfer_complete(&(obj->sdxx));
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdxx_io_volt_switch_seq
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_sdxx_io_volt_switch_seq(SDHC_Type* base)
{
    CY_ASSERT(NULL != base);

    uint32_t p_state;
    cy_rslt_t result = CY_RSLT_SUCCESS;

    /* Disable providing the SD Clock. */
    Cy_SD_Host_DisableSdClk(base);

    p_state = Cy_SD_Host_GetPresentState(base) & SDHC_CORE_PSTATE_REG_DAT_3_0_Msk;

    /* Check DAT[3:0]. */
    if (0UL == p_state)
    {
        /* Switch the bus to 1.8 V (Set the IO_VOLT_SEL pin to low)*/
        Cy_SD_Host_ChangeIoVoltage(base, CY_SD_HOST_IO_VOLT_1_8V);

        /* Wait 10 ms to 1.8 voltage regulator to be stable. */
        mtb_hal_system_delay_ms(_MTB_HAL_SDHC_1_8_REG_STABLE_TIME_MS);

        /* Check the 1.8V signaling enable. */
        if (true == _FLD2BOOL(SDHC_CORE_HOST_CTRL2_R_SIGNALING_EN,
                              SDHC_CORE_HOST_CTRL2_R(base)))
        {
            /* Enable providing the SD Clock. */
            Cy_SD_Host_EnableSdClk(base);

            /* Wait for the stable CLK */
            mtb_hal_system_delay_ms(CY_SD_HOST_CLK_RAMP_UP_TIME_MS);

            p_state = Cy_SD_Host_GetPresentState(base) & SDHC_CORE_PSTATE_REG_DAT_3_0_Msk;

            /* Check DAT[3:0]. */
            if (SDHC_CORE_PSTATE_REG_DAT_3_0_Msk != p_state)
            {
                result = (cy_rslt_t)CY_SD_HOST_ERROR;
            }
        }
        else
        {
            result = (cy_rslt_t)CY_SD_HOST_ERROR;
        }
    }
    else
    {
        result = (cy_rslt_t)CY_SD_HOST_ERROR;
    }

    return result;
}


/* Ncc - is time, needed to wait after certain commands before issuing next cmd.
 *  Ncc is 8 clock cycles which for 400 kHz is 20 us */
__STATIC_INLINE void _mtb_hal_sdhc_wait_ncc_time_at_400khz(void)
{
    mtb_hal_system_delay_us(20);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_io_volt_negotiate
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_sdhc_io_volt_negotiate(mtb_hal_sdhc_t* obj,
                                                 mtb_hal_sdhc_io_voltage_t io_voltage)
{
    /* GO_IDLE (CMD0) command is issued in scope of Cy_SD_Host_SelBusVoltage, which resets
     * SD bus to 1 bit bus width and 400 khz on the SD card side. Preparing host side for that. */

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    /* 1 bit data bus width */
    cy_rslt_t result = mtb_hal_sdhc_set_bus_width(obj, 1, true);

    if (CY_RSLT_SUCCESS == result)
    {
        /* 400 khz sd bus clock */
        result = mtb_hal_sdhc_set_frequency(obj, 400000, false);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        bool voltage_1v8 = (io_voltage == MTB_HAL_SDHC_IO_VOLTAGE_1_8V);
        result = (cy_rslt_t)Cy_SD_Host_SelBusVoltage(sdxx->base, voltage_1v8, sdxx->context);
        /* Card is expected to be in "ready" state now */
    }

    if (CY_RSLT_SUCCESS == result)
    {
        /* GetCid (CMD2) will switch card from "ready" state to "ident" */
        uint32_t cid_reg[4];  /* The Device Identification register. */
        result = (cy_rslt_t)Cy_SD_Host_GetCid(sdxx->base, cid_reg);
        _mtb_hal_sdhc_wait_ncc_time_at_400khz();
    }

    if (CY_RSLT_SUCCESS == result)
    {
        /* Cy_SD_Host_GetRca (CMD3) will switch card from "ident" state to "stand-by" state */
        sdxx->context->RCA = Cy_SD_Host_GetRca(sdxx->base);
        _mtb_hal_sdhc_wait_ncc_time_at_400khz();

        /* CMD7 will switch card from "stand-by" state to "transfer" state */
        mtb_hal_sdhc_cmd_config_t cmd =
        {
            .command_index    = 7,
            .command_argument = sdxx->context->RCA << _MTB_HAL_SDHC_RCA_SHIFT,
            .enable_crc_check = false,
            .response_type    = MTB_HAL_SDHC_RESPONSE_LEN_48B,
            .enable_idx_check = false,
            .command_type     = MTB_HAL_SDHC_CMD_NORMAL,
            .data_config      = NULL
        };

        result = mtb_hal_sdhc_send_cmd(obj, &cmd);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        _mtb_hal_sdhc_wait_ncc_time_at_400khz();
        result = _mtb_hal_sdxx_waitfor_transfer_complete(sdxx);
    }

    return result;
}


typedef struct
{
    en_hsiom_sel_t      clk;
    en_hsiom_sel_t      cmd;
    #if _MTB_HAL_SDHC_DATA8_PRESENT
    en_hsiom_sel_t      data[8];
    #else
    en_hsiom_sel_t      data[4];
    #endif
} _mtb_hal_sdhc_saved_lines_hsiom_t;

/* power cycle config single pin */
static void _mtb_hal_sdhc_pc_config_single_pin(mtb_hal_gpio_t gpio, en_hsiom_sel_t* hsiom_ptr,
                                               bool set_line_low)
{
    GPIO_PRT_Type* port;
    uint8_t pin;

    port = Cy_GPIO_PortToAddr(gpio.port_num);
    pin = gpio.pin_num;
    if (set_line_low)
    {
        /* Switching HSIOM to GPIO and set pin to low state */
        *hsiom_ptr = Cy_GPIO_GetHSIOM(port, pin);
        Cy_GPIO_Clr(port, pin);
        Cy_GPIO_SetHSIOM(port, pin, HSIOM_SEL_GPIO);
    }
    else
    {
        /* Restore pin's HSIOM configuration for SDHC block signals */
        Cy_GPIO_SetHSIOM(port, pin, *hsiom_ptr);
    }
}


/* Per SD Spec, during card power down, DAT, CMD and CLK lines should be disconnected or driven to
 * logical 0 by the host to avoid operating current being drawn through the signal lines.
 * Lines are set low if set_lines_low true, pins configuration resored if set_lines_low false */
static void _mtb_hal_sdhc_power_cycle_config_lines(mtb_hal_sdhc_t* obj,
                                                   _mtb_hal_sdhc_saved_lines_hsiom_t* pins_cfg,
                                                   bool set_lines_low)
{
    _mtb_hal_sdhc_pc_config_single_pin(obj->sdxx.pin_clk, &pins_cfg->clk, set_lines_low);
    _mtb_hal_sdhc_pc_config_single_pin(obj->sdxx.pin_cmd, &pins_cfg->cmd, set_lines_low);
    for (size_t i = 0; i < sizeof(pins_cfg->data)/sizeof(pins_cfg->data[0]); ++i)
    {
        _mtb_hal_sdhc_pc_config_single_pin(obj->pin_data[i], &(pins_cfg->data[i]), set_lines_low);
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_card_power_cycle
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_sdhc_card_power_cycle(mtb_hal_sdhc_t* obj)
{
    // To perform reliable SD card hard reset, Card VDD should drop to below 0.5V for at least 1 ms
    _mtb_hal_sdhc_saved_lines_hsiom_t pins_cfg;

    /* Drive signal lines logic 0 to avoid card being powered through signal lines */
    _mtb_hal_sdhc_power_cycle_config_lines(obj, &pins_cfg, true);
    /* Power down the card */
    mtb_hal_sdhc_enable_card_power(obj, false);
    /* Waiting for 1 ms per spec */
    mtb_hal_system_delay_us(1000);
    /* Restore signals configuration */
    _mtb_hal_sdhc_power_cycle_config_lines(obj, &pins_cfg, false);
    /* Power up the card */
    mtb_hal_sdhc_enable_card_power(obj, true);
    mtb_hal_system_delay_ms(_MTB_HAL_SDHC_PWR_RAMP_UP_TIME_MS);

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdxx_set_io_voltage
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _mtb_hal_sdxx_set_io_voltage(_mtb_hal_sdxx_t* sdxx,
                                              mtb_hal_sdxx_io_voltage_t io_voltage,
                                              _mtb_hal_sdxx_io_switch_action_t io_switch_type)
{
    CY_ASSERT(NULL != sdxx);
    CY_ASSERT(NULL != sdxx->base);

    if ((!sdxx->is_sdio && (CY_SD_HOST_SD != sdxx->context->cardType)) &&
        (_MTB_HAL_SDXX_IO_VOLT_ACTION_NONE != io_switch_type))
    {
        /* For SDHC, Negotiation or Voltage switch is not supported when eMMC used */
        return MTB_HAL_SDHC_RSLT_ERR_UNSUPPORTED;
    }

    if (sdxx->is_sdio && (_MTB_HAL_SDXX_IO_VOLT_ACTION_NEGOTIATE == io_switch_type))
    {
        /* For SDIO, Negotiation is not supported */
        return MTB_HAL_SDIO_RSLT_ERR_UNSUPPORTED;
    }

    cy_rslt_t result = CY_RSLT_SUCCESS;

    switch (io_switch_type)
    {
        /* Not supported by current SDIO HAL implementation */
        case _MTB_HAL_SDXX_IO_VOLT_ACTION_NEGOTIATE:
        {
            mtb_hal_sdhc_t* sdhc_obj = (mtb_hal_sdhc_t*)sdxx->obj;

            /* Bus width and card frequency settings are initialized to default during negotiation.
             * Saving the parameters to restore them after I/O switch is done. */
            uint8_t sd_bus_width_before_switch = mtb_hal_sdhc_get_bus_width(sdhc_obj);
            uint32_t sd_freq_before_switch = mtb_hal_sdhc_get_frequency(sdhc_obj);

            /* Once the card enters 1.8V signaling mode, it cannot be switched back to 3.3V
               signaling without power cycle. */
            if ((_FLD2BOOL(SDHC_CORE_HOST_CTRL2_R_SIGNALING_EN,
                           SDHC_CORE_HOST_CTRL2_R(sdhc_obj->sdxx.base))) &&
                (_MTB_HAL_SDXX_IO_VOLTAGE_3_3V == io_voltage))
            {
                result = _mtb_hal_sdhc_card_power_cycle(sdhc_obj);
                if (CY_RSLT_SUCCESS == result)
                {
                    sdhc_obj->low_voltage_io_desired = false;
                    result = _mtb_hal_sdhc_init_card_common(sdhc_obj);
                }
            }
            else
            {
                result = _mtb_hal_sdhc_io_volt_negotiate(sdhc_obj,
                                                         (mtb_hal_sdhc_io_voltage_t)io_voltage);
            }

            /* Return back bus width and frequency regardless of volt select change status */
            (void)mtb_hal_sdhc_set_bus_width(sdhc_obj, sd_bus_width_before_switch, true);
            (void)mtb_hal_sdhc_set_frequency(sdhc_obj, sd_freq_before_switch, true);
            break;
        }

        case _MTB_HAL_SDXX_IO_VOLT_ACTION_SWITCH_SEQ_ONLY:
            if (_MTB_HAL_SDXX_IO_VOLTAGE_1_8V == io_voltage)
            {
                result = _mtb_hal_sdxx_io_volt_switch_seq(sdxx->base);
                if (CY_RSLT_SUCCESS != result)
                {
                    result =
                        sdxx->is_sdio ? MTB_HAL_SDIO_RSLT_ERR_IO_VOLT_SWITCH_SEQ :
                        MTB_HAL_SDHC_RSLT_ERR_IO_VOLT_SWITCH_SEQ;
                }
                /* Cy_SD_Host_ChangeIoVoltage is already called within
                 * _mtb_hal_sdxx_io_volt_switch_seq, so we can safely break, as the IO Voltage
                 * has already been updated for this 1.8V case. */
                break;
            }
            else
            {
                Cy_SD_Host_ChangeIoVoltage(sdxx->base, (cy_en_sd_host_io_voltage_t)io_voltage);
                break;
            }

        case _MTB_HAL_SDXX_IO_VOLT_ACTION_NONE:
            Cy_SD_Host_ChangeIoVoltage(sdxx->base, (cy_en_sd_host_io_voltage_t)io_voltage);
            break;

        default:
            /* Illegal io_switch_type value provided */
            CY_ASSERT(false);
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_set_io_voltage
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_set_io_voltage(mtb_hal_sdhc_t* obj, mtb_hal_sdhc_io_voltage_t io_voltage,
                                      mtb_hal_sdhc_io_volt_action_type_t io_switch_type)
{
    CY_ASSERT(NULL != obj);

    return _mtb_hal_sdxx_set_io_voltage(&(obj->sdxx), (mtb_hal_sdxx_io_voltage_t)io_voltage,
                                        (_mtb_hal_sdxx_io_switch_action_t)io_switch_type);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_get_io_voltage
//--------------------------------------------------------------------------------------------------
mtb_hal_sdhc_io_voltage_t mtb_hal_sdhc_get_io_voltage(mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    return (_FLD2BOOL(SDHC_CORE_HOST_CTRL2_R_SIGNALING_EN,
                      SDHC_CORE_HOST_CTRL2_R(obj->sdxx.base))) ? MTB_HAL_SDHC_IO_VOLTAGE_1_8V :
           MTB_HAL_SDHC_IO_VOLTAGE_3_3V;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_sdhc_is_buswidth_correct
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_sdhc_is_buswidth_correct(uint8_t sd_data_bits)
{
    return ((1 == sd_data_bits) || (4 == sd_data_bits) || (8 == sd_data_bits));
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_set_bus_width
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_set_bus_width(mtb_hal_sdhc_t* obj, uint8_t bus_width, bool configure_card)
{
    CY_ASSERT(NULL != obj);

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);
    CY_ASSERT(NULL != sdxx->base);

    if (!_mtb_hal_sdhc_is_buswidth_correct(bus_width))
    {
        return MTB_HAL_SDHC_RSLT_ERR_WRONG_PARAM;
    }

    cy_rslt_t result;

    if (configure_card)
    {
        result =
            (cy_rslt_t)Cy_SD_Host_SetBusWidth(sdxx->base, _mtb_hal_sdhc_buswidth_hal_to_pdl(
                                                  bus_width), sdxx->context);
        if ((CY_RSLT_SUCCESS == result) && (sdxx->emmc))
        {
            /* GENERIC_CMD6_TIME is maximum timeout for a SWITCH command (CMD6), that is called for
               eMMC in scope of Cy_SD_Host_SetBusWidth */
            mtb_hal_system_delay_ms(obj->emmc_generic_cmd6_time_ms);
        }
    }
    else
    {
        result = (cy_rslt_t)Cy_SD_Host_SetHostBusWidth(sdxx->base, _mtb_hal_sdhc_buswidth_hal_to_pdl(
                                                           bus_width));
    }

    if (CY_RSLT_SUCCESS == result)
    {
        obj->bus_width = bus_width;
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_get_bus_width
//--------------------------------------------------------------------------------------------------
uint8_t mtb_hal_sdhc_get_bus_width(mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    return obj->bus_width;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_clear_errors
//--------------------------------------------------------------------------------------------------
void mtb_hal_sdhc_clear_errors(mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->sdxx.base);
    Cy_SD_Host_ClearErrorInterruptStatus(obj->sdxx.base, _MTB_HAL_SDHC_ALL_ERR_INTERRUPTS);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_get_last_command_errors
//--------------------------------------------------------------------------------------------------
mtb_hal_sdhc_error_type_t mtb_hal_sdhc_get_last_command_errors(mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->sdxx.base);
    return (mtb_hal_sdhc_error_type_t)Cy_SD_Host_GetErrorInterruptStatus(obj->sdxx.base);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_software_reset
//--------------------------------------------------------------------------------------------------
void mtb_hal_sdhc_software_reset(mtb_hal_sdhc_t* obj)
{
    CY_ASSERT(NULL != obj);
    _mtb_hal_sdxx_reset(&(obj->sdxx));
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_enable_card_power
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_enable_card_power(mtb_hal_sdhc_t* obj, bool enable)
{
    CY_ASSERT(NULL != obj);

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);
    CY_ASSERT(NULL != sdxx->base);

    if (enable)
    {
        Cy_SD_Host_EnableCardVoltage(sdxx->base);
    }
    else
    {
        Cy_SD_Host_DisableCardVoltage(sdxx->base);
    }
    return CY_RSLT_SUCCESS;
}


/*******************************************************************************
*
*   The asynchronous transfer is implemented on the CY_SD_HOST_XFER_COMPLETE
*   interrupt. The function sets up data and enables the CY_SD_HOST_XFER_COMPLETE
*   interrupt mask, which causes the interrupt to occur and get handled by
*   _mtb_hal_sdio_irq_handler which takes care of disabling CY_SD_HOST_XFER_COMPLETE mask.
*   This function can also activate CY_SD_HOST_CMD_COMPLETE interrupt mask if it was
*   enabled by user via mtb_hal_sdio_enable_event function.
*
*******************************************************************************/
static cy_rslt_t _mtb_hal_sdio_host_transfer_async(mtb_hal_sdio_t* obj,
                                                   mtb_hal_sdio_host_transfer_type_t direction,
                                                   uint32_t argument, const uint32_t* data,
                                                   uint16_t length)
{
    if (NULL == obj)
    {
        return MTB_HAL_SDIO_RSLT_ERR_BAD_PARAM;
    }

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    cy_rslt_t                    result;
    uint32_t                     retry = _MTB_HAL_SDIO_TRANSFER_TRIES;
    cy_stc_sd_host_cmd_config_t  cmd;
    cy_stc_sd_host_data_config_t data_config;

    /* Initialize data constants*/
    data_config.autoCommand         = CY_SD_HOST_AUTO_CMD_NONE;
    data_config.dataTimeout         = _MTB_HAL_SDIO_DATA_TIMEOUT;
    data_config.enableIntAtBlockGap = false;
    data_config.enReliableWrite     = false;
    data_config.enableDma           = true;

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    if (direction == MTB_HAL_SDIO_XFER_TYPE_WRITE)
    {
        SCB_CleanDCache_by_Addr((void*)data, length);
    }
    #endif

    do
    {
        /* Add SDIO Error Handling
         * SDIO write timeout is expected when doing first write to register
         * after KSO bit disable (as it goes to AOS core).
         * This timeout, however, triggers an error state in the hardware.
         * So, check for the error and then recover from it
         * as needed via reset issuance. This is the only time known that
         * a write timeout occurs.
         */

        /* First clear out the command complete and transfer complete statuses */
        Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base,
                                              (CY_SD_HOST_XFER_COMPLETE | CY_SD_HOST_CMD_COMPLETE));

        /* Check if an error occurred on any previous transactions or reset after the first
           unsuccessful transfer try */
        if ((Cy_SD_Host_GetNormalInterruptStatus(sdxx->base) & CY_SD_HOST_ERR_INTERRUPT) ||
            (retry < _MTB_HAL_SDIO_TRANSFER_TRIES))
        {
            /* Reset the block if there was an error. Note a full reset usually
             * requires more time, but this short version is working quite well and
             * successfully clears out the error state.
             */
            Cy_SD_Host_ClearErrorInterruptStatus(sdxx->base, _MTB_HAL_SDIO_SET_ALL_INTERRUPTS_MASK);
            _mtb_hal_sdxx_reset(sdxx);
        }

        /* Prepare the data transfer register */
        cmd.commandIndex                 = (uint32_t)MTB_HAL_SDIO_CMD_IO_RW_EXTENDED;
        cmd.commandArgument              = argument;
        cmd.enableCrcCheck               = true;
        cmd.enableAutoResponseErrorCheck = false;
        cmd.respType                     = CY_SD_HOST_RESPONSE_LEN_48;
        cmd.enableIdxCheck               = true;
        cmd.dataPresent                  = true;
        cmd.cmdType                      = CY_SD_HOST_CMD_NORMAL;

        data_config.read = (direction == MTB_HAL_SDIO_XFER_TYPE_WRITE) ? false : true;

        /* Block mode */
        if (length >= obj->block_size)
        {
            if ((length % obj->block_size) != 0)
            {
                return MTB_HAL_SDIO_RSLT_ERR_UNSUPPORTED;
            }

            data_config.blockSize     = obj->block_size;
            data_config.numberOfBlock = (length + obj->block_size - 1) / obj->block_size;
        }
        /* Byte mode */
        else
        {
            data_config.blockSize     = length;
            data_config.numberOfBlock = 1UL;
        }

        length = data_config.blockSize * data_config.numberOfBlock;

        sdxx->adma_descriptor_tbl[0] = (1UL << CY_SD_HOST_ADMA_ATTR_VALID_POS) | /* Attr Valid */
                                       (1UL << CY_SD_HOST_ADMA_ATTR_END_POS) |   /* Attr End */
                                       (0UL << CY_SD_HOST_ADMA_ATTR_INT_POS) |   /* Attr Int */
                                       (CY_SD_HOST_ADMA_TRAN << CY_SD_HOST_ADMA_ACT_POS) |
                                       ((uint32_t)length << CY_SD_HOST_ADMA_LEN_POS);     /* Len */

        /* SDHC needs to be able to access the data_ptr that is in DTCM when using CM55. Remap this
         * address for access */
        #if defined(CORE_NAME_CM55_0)
        sdxx->adma_descriptor_tbl[1] = (uint32_t)cy_DTCMRemapAddr(data);
        /* The address of the ADMA descriptor table. */
        data_config.data = (uint32_t*)cy_DTCMRemapAddr(&(sdxx->adma_descriptor_tbl[0]));
        #else
        sdxx->adma_descriptor_tbl[1] = (uint32_t)data;
        /* The address of the ADMA descriptor table. */
        data_config.data = (uint32_t*)&(sdxx->adma_descriptor_tbl[0]);
        #endif // if defined(CORE_NAME_CM55_0)
        /* Clean DCache for ADMA descriptor table. */
        #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
        SCB_CleanDCache_by_Addr((void*)sdxx->adma_descriptor_tbl,
                                sizeof(sdxx->adma_descriptor_tbl));
        #endif
        result = _mtb_hal_sdxx_prepare_for_transfer(sdxx);

        if (CY_RSLT_SUCCESS == result)
        {
            result = (cy_rslt_t)Cy_SD_Host_InitDataTransfer(sdxx->base, &data_config);
        }

        if (CY_RSLT_SUCCESS == result)
        {
            /* Indicate that async transfer in progress */
            sdxx->data_transfer_status = _MTB_HAL_SDXX_WAIT_BOTH;
            result = (cy_rslt_t)Cy_SD_Host_SendCommand(sdxx->base, &cmd);
        }

        if (CY_RSLT_SUCCESS == result)
        {
            result = (cy_rslt_t)_mtb_hal_sdxx_pollcmdcomplete(sdxx, NULL);
        }
    } while ((CY_RSLT_SUCCESS != result) && (--retry > 0UL));

    if (CY_RSLT_SUCCESS != result)
    {
        /* Transfer failed */
        sdxx->data_transfer_status = _MTB_HAL_SDXX_NOT_RUNNING;
    }

    // Invalidate dcache if enabled to update dcache's contents after DMA transfer
    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    if (direction == MTB_HAL_SDIO_XFER_TYPE_READ)
    {
        SCB_InvalidateDCache_by_Addr((void*)data, length);
    }
    #endif

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdio_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdio_setup(mtb_hal_sdio_t* obj, const mtb_hal_sdio_configurator_t* config,
                             const mtb_hal_clock_t* clock, cy_stc_sd_host_context_t* sdio_context)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != config);
    CY_ASSERT(NULL != config->host_config);
    memset(obj, 0, sizeof(mtb_hal_sdio_t));

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    sdxx->obj = obj;
    sdxx->is_sdio = true;

    sdxx->dma_type = config->host_config->dmaType;

    if (config->host_config->emmc || (config->host_config->dmaType != CY_SD_HOST_DMA_ADMA2))
    {
        /*  emmc setting should be false for SDIO.
            Next settings are only supported by SDIO HAL:
                - DMA type : ADMA2
                - Data bus width : 4 bit
         */
        return MTB_HAL_SDIO_RSLT_ERR_UNSUPPORTED;
    }

    CY_ASSERT(NULL != sdio_context);

    sdxx->context = sdio_context;

    // If NULL, use the clock provided from device-configurator selections
    if (clock != NULL)
    {
        sdxx->clock = clock;
    }
    else
    {
        CY_ASSERT(config->clock != NULL);

        sdxx->clock = config->clock;
    }

    sdxx->pin_cmd = config->gpios.cmd;
    sdxx->pin_clk = config->gpios.clk;
    obj->pin_data0 = config->gpios.data[0];
    obj->pin_data1 = config->gpios.data[1];
    obj->pin_data2 = config->gpios.data[2];
    obj->pin_data3 = config->gpios.data[3];

    sdxx->base = config->base;
    sdxx->data_transfer_status = _MTB_HAL_SDXX_NOT_RUNNING;
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    _mtb_hal_sdxx_semaphore_status[_mtb_hal_sdxx_get_block_num(sdxx)] =
        _MTB_HAL_SDXX_SEMA_NOT_INITED;
    #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */

    sdxx->irq_cause = 0UL;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdio_configure
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdio_configure(mtb_hal_sdio_t* obj, const mtb_hal_sdio_cfg_t* config)
{
    cy_rslt_t result = MTB_HAL_SDIO_RSLT_ERR_CONFIG;

    if ((NULL == obj) || (config == NULL))
    {
        return MTB_HAL_SDIO_RSLT_ERR_BAD_PARAM;
    }

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    if (config->frequencyhal_hz != 0U)
    {
        uint32_t freq = config->frequencyhal_hz;
        /* Register check tells us whether we are using 1.8V or 3.3V, used for determining if reset
           is required */
        bool low_voltage_io_set = (_FLD2BOOL(SDHC_CORE_HOST_CTRL2_R_SIGNALING_EN,
                                             SDHC_CORE_HOST_CTRL2_R(obj->sdxx.base)));

        result = _mtb_hal_sdxx_sdcardchangeclock(sdxx, &freq, low_voltage_io_set, false);
    }

    if (config->block_size != 0U)
    {
        /* No need to change anything in HW, because it will be overwritten
         *  in mtb_hal_sdio_bulk_transfer()/mtb_hal_sdio_transfer_async() functions.
         *  The HW block size will taken based on obj->block_size, which is
         *  updated here.
         */
        obj->block_size = config->block_size;
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdio_host_send_cmd
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdio_host_send_cmd(mtb_hal_sdio_t* obj,
                                     mtb_hal_sdio_host_transfer_type_t direction, \
                                     mtb_hal_sdio_host_command_t command, uint32_t argument,
                                     uint32_t* response)
{
    CY_UNUSED_PARAMETER(direction);
    if (NULL == obj)
    {
        return MTB_HAL_SDIO_RSLT_ERR_BAD_PARAM;
    }

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    cy_rslt_t                   result;
    cy_stc_sd_host_cmd_config_t cmd;
    uint32_t                    retry = _MTB_HAL_SDIO_TRANSFER_TRIES;

    /* Clear out the response */
    if (response != NULL)
    {
        *response = 0UL;
    }

    do
    {
        /* First clear out the command complete and transfer complete statuses */
        Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base, CY_SD_HOST_CMD_COMPLETE);

        /* Check if an error occurred on any previous transactions */
        if (Cy_SD_Host_GetNormalInterruptStatus(sdxx->base) & CY_SD_HOST_ERR_INTERRUPT)
        {
            /* Reset the block if there was an error. Note a full reset usually
             * requires more time, but this short version is working quite well and
             * successfully clears out the error state.
             */
            Cy_SD_Host_ClearErrorInterruptStatus(sdxx->base, _MTB_HAL_SDIO_SET_ALL_INTERRUPTS_MASK);
            _mtb_hal_sdxx_reset(sdxx);
        }

        cmd.commandIndex                 = (uint32_t)command;
        cmd.commandArgument              = argument;
        cmd.enableCrcCheck               = true;
        cmd.enableAutoResponseErrorCheck = false;
        cmd.respType                     = CY_SD_HOST_RESPONSE_LEN_48;
        cmd.enableIdxCheck               = true;
        cmd.dataPresent                  = false;
        cmd.cmdType                      = CY_SD_HOST_CMD_NORMAL;

        if (sdxx->irq_cause & MTB_HAL_SDIO_CMD_COMPLETE)
        {
            /*  Enabling command complete interrupt mask if corresponding event was enabled by user
             *   _mtb_hal_sdio_irq_handler will disable CY_SD_HOST_CMD_COMPLETE mask once interrupt
             *   is generated. */
            Cy_SD_Host_SetNormalInterruptMask(sdxx->base,
                                              Cy_SD_Host_GetNormalInterruptMask(sdxx->base) |
                                              CY_SD_HOST_CMD_COMPLETE);
        }

        result = (cy_rslt_t)Cy_SD_Host_SendCommand(sdxx->base, &cmd);

        if (CY_RSLT_SUCCESS == result)
        {
            result = (cy_rslt_t)_mtb_hal_sdxx_pollcmdcomplete(sdxx, NULL);
        }
    } while ((CY_RSLT_SUCCESS != result) && (retry-- > 0UL));

    if (CY_RSLT_SUCCESS == result)
    {
        result = (cy_rslt_t)Cy_SD_Host_GetResponse(sdxx->base, response, false);
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdio_host_bulk_transfer
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdio_host_bulk_transfer(mtb_hal_sdio_t* obj,
                                          mtb_hal_sdio_host_transfer_type_t direction,
                                          uint32_t argument, const uint32_t* data,
                                          uint16_t length, uint32_t* response)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    uint32_t retry = _MTB_HAL_SDIO_TRANSFER_TRIES;

    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    _mtb_hal_sdxx_setup_smphr(sdxx);

    do
    {
        result = _mtb_hal_sdio_host_transfer_async(obj, direction, argument, data, length);

        if (CY_RSLT_SUCCESS == result)
        {
            result = _mtb_hal_sdxx_waitfor_transfer_complete(sdxx);
        }

        if (CY_RSLT_SUCCESS != result)
        {
            /*  SDIO Error Handling
             *   SDIO write timeout is expected when doing first write to register
             *   after KSO bit disable (as it goes to AOS core).
             *   This is the only time known that a write timeout occurs.
             *   Issue the reset to recover from error. */
            _mtb_hal_sdxx_reset(sdxx);
        }
    } while ((CY_RSLT_SUCCESS != result) && (--retry > 0UL));

    if (CY_RSLT_SUCCESS != result)
    {
        sdxx->data_transfer_status = _MTB_HAL_SDXX_NOT_RUNNING;
    }

    if ((response != NULL) && (CY_RSLT_SUCCESS == result))
    {
        *response = 0UL;
        result = (cy_rslt_t)Cy_SD_Host_GetResponse(sdxx->base, response, false);
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdio_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_sdio_register_callback(mtb_hal_sdio_t* obj, mtb_hal_sdio_event_callback_t callback,
                                    void* callback_arg)
{
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    mtb_hal_system_critical_section_exit(savedIntrStatus);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdio_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_sdio_enable_event(mtb_hal_sdio_t* obj, mtb_hal_sdio_event_t event, bool enable)
{
    _mtb_hal_sdxx_t* sdxx = &(obj->sdxx);

    /* Configure interrupt-based event(s) */
    if (0U != ((uint32_t)event & (uint32_t)MTB_HAL_SDIO_ALL_INTERRUPTS))
    {
        uint32_t cur_interrupt_mask = Cy_SD_Host_GetNormalInterruptMask(sdxx->base);
        uint32_t new_interrupt_mask = cur_interrupt_mask;

        if (enable)
        {
            sdxx->irq_cause |= event;

            /*  CY_SD_HOST_CMD_COMPLETE and CY_SD_HOST_XFER_COMPLETE cannot be always enabled
               because of SD Host driver limitations.
             *   SDHC HAL transfer APIs are taking care of enabling these statuses.
             * CY_SD_HOST_CMD_COMPLETE is only
             *   enabled if corresponding user callback is enabled while CY_SD_HOST_XFER_COMPLETE is
             * enabled by transfer API
             *   regardless it was enabled by user or not. */
            event &= ((uint32_t) ~CY_SD_HOST_CMD_COMPLETE) & ((uint32_t) ~CY_SD_HOST_XFER_COMPLETE);

            new_interrupt_mask |= event;
            Cy_SD_Host_ClearNormalInterruptStatus(sdxx->base,
                                                  new_interrupt_mask & ~cur_interrupt_mask);
        }
        else
        {
            new_interrupt_mask &= ~(event);
            sdxx->irq_cause &= ~event;
        }

        Cy_SD_Host_SetNormalInterruptMask(sdxx->base, new_interrupt_mask);
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdio_host_set_io_voltage
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdio_host_set_io_voltage(mtb_hal_sdio_t* obj,
                                           mtb_hal_sdio_host_io_voltage_t io_voltage,
                                           mtb_hal_sdio_host_io_volt_action_type_t io_switch_type)
{
    CY_ASSERT(NULL != obj);

    return _mtb_hal_sdxx_set_io_voltage((&(obj->sdxx)), (mtb_hal_sdxx_io_voltage_t)io_voltage,
                                        (_mtb_hal_sdxx_io_switch_action_t)io_switch_type);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdhc_process_interrupt(mtb_hal_sdhc_t* obj)
{
    _mtb_hal_sdhc_irq_handler(&(obj->sdxx));
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_sdhc_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_sdio_process_interrupt(mtb_hal_sdio_t* obj)
{
    _mtb_hal_sdio_irq_handler(obj);
    return CY_RSLT_SUCCESS;
}


#if defined(__cplusplus)
}
#endif

#endif /* MTB_HAL_DRIVER_AVAILABLE_SDHC */
