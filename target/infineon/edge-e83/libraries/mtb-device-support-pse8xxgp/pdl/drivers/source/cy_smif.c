/***************************************************************************//**
* \file cy_smif.c
* \version 2.130
*
* \brief
*  This file provides the source code for the SMIF driver APIs.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2016-2025 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#include "cy_device.h"

#if defined (CY_IP_MXSMIF)

#include "cy_smif.h"
#include "cy_sysclk.h"

 #include "cy_smif_memnum.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Function Name: Cy_SMIF_Init
****************************************************************************//**
*
* This function initializes the SMIF block as a communication block. The user
* must ensure that the SMIF interrupt is disabled while this function
* is called. Enabling the interrupts can lead to triggering in the middle
* of the initialization operation, which can lead to erroneous initialization.
*
* As parameters, this function takes the SMIF register base address and a
* context structure along with the configuration needed for the SMIF block,
* stored in a config.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param config
* Passes a configuration structure that configures the SMIF block for operation.
*
* \param timeout
* A timeout in microseconds for blocking APIs in use.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \note Make sure that the interrupts are initialized and disabled.
*
* \return
*     - \ref CY_SMIF_BAD_PARAM
*     - \ref CY_SMIF_SUCCESS
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Init(SMIF_Type *base,
                                    cy_stc_smif_config_t const *config,
                                    uint32_t timeout,
                                    cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t result = CY_SMIF_SUCCESS;

    /* Ensure none of the input pointers are null. */
    if ((NULL == base) || (NULL == config) || (NULL == context))
    {
        return CY_SMIF_BAD_PARAM;
    }

    /* Check config structure */
    CY_ASSERT_L3(CY_SMIF_MODE_VALID(config->mode));
    CY_ASSERT_L3(CY_SMIF_BLOCK_EVENT_VALID(config->blockEvent));
    CY_ASSERT_L2(CY_SMIF_DESELECT_DELAY_VALID(config->deselectDelay));


    /* Initialize context parameters */
    context->txBufferAddress = NULL;
    context->txBufferSize = 0U;
    context->txBufferCounter = 0U;
    context->rxBufferAddress = NULL;
    context->rxBufferSize = 0U;
    context->rxBufferCounter = 0U;
    context->transferStatus = CY_SMIF_STARTED;
    context->txCompleteCb = NULL;
    context->rxCompleteCb = NULL;
    context->timeout = timeout;
    context->memReadyPollDelay = 0U;
        context->preCmdDataRate = CY_SMIF_SDR;
        context->preCmdWidth = CY_SMIF_WIDTH_SINGLE;
        context->preXIPDataRate = CY_SMIF_SDR;
        context->dummyCycles = 0U;
        context->flags = 0U;

    /* The SMIF CTL and CTL2 registers cannot be modified while the SMIF is enabled in XIP mode. */
    uint32_t smif_ctl_value = SMIF_CTL(base);
    if (!((_FLD2VAL(SMIF_CTL_ENABLED, smif_ctl_value) == 1U) && (_FLD2VAL(SMIF_CTL_XIP_MODE, smif_ctl_value) == 1U)))
    {
        /* Construct the SMIF CTL register value, starting from register defaults. */
        uint32_t tmp_ctl = CY_SMIF_CTL_REG_DEFAULT;


        /* Configure the initial interrupt mask */
        /* Disable the TR_TX_REQ and TR_RX_REQ interrupts */
        Cy_SMIF_SetInterruptMask(base, Cy_SMIF_GetInterruptMask(base)
                    & ~(SMIF_INTR_TR_TX_REQ_Msk | SMIF_INTR_TR_RX_REQ_Msk));

        /* Configure the SMIF interface */
        tmp_ctl = _CLR_SET_FLD32U(tmp_ctl, SMIF_CTL_XIP_MODE, config->mode);
        tmp_ctl = _CLR_SET_FLD32U(tmp_ctl, SMIF_CTL_BLOCK, config->blockEvent);
        tmp_ctl = _CLR_SET_FLD32U(tmp_ctl, SMIF_CTL_DESELECT_DELAY, config->deselectDelay);

        /* Enable the DLL, if enabled and input frequency is above minimum threshold.
           Otherwise, enable the bypass for SMIFv5 or greater. */
        result = Cy_SMIF_DllConfig(base, config, context);
        if (result != CY_SMIF_SUCCESS)
        {
            CY_ASSERT(false);
            return result;
        }

        /* Set the MDL taps for SMIF, and SDL taps for device0 and device1. */
        result = Cy_SMIF_Set_DelayTapSel(base, (uint8_t)config->mdl_tap);
#if (SMIF_DEVICE_NR >= 1)
        if (result == CY_SMIF_SUCCESS) {
            result = Cy_SMIF_Set_Sdl_DelayTapSel(&(base->DEVICE[0]), (uint8_t)config->device0_sdl_tap);
        }
#endif
#if (SMIF_DEVICE_NR >= 2)
        if (result == CY_SMIF_SUCCESS) {
            result = Cy_SMIF_Set_Sdl_DelayTapSel(&(base->DEVICE[1]), (uint8_t)config->device1_sdl_tap);
        }
#endif
#if (SMIF_DEVICE_NR >= 3)
        if (result == CY_SMIF_SUCCESS) {
            result = Cy_SMIF_Set_Sdl_DelayTapSel(&(base->DEVICE[2]), (uint8_t)config->device2_sdl_tap);
        }
#endif
#if (SMIF_DEVICE_NR >= 4)
        if (result == CY_SMIF_SUCCESS) {
            result = Cy_SMIF_Set_Sdl_DelayTapSel(&(base->DEVICE[3]), (uint8_t)config->device3_sdl_tap);
        }
#endif

        /* In case user is working with higher frequencies increase initial set up and hold delay */
        tmp_ctl &= ~(SMIF_CORE_CTL_SELECT_SETUP_DELAY_Msk | SMIF_CORE_CTL_SELECT_HOLD_DELAY_Msk);
        if (config->inputFrequencyMHz >= 300U)
        {
            tmp_ctl |= _VAL2FLD(SMIF_CORE_CTL_SELECT_SETUP_DELAY, 2);
            tmp_ctl |= _VAL2FLD(SMIF_CORE_CTL_SELECT_HOLD_DELAY, 2);
        }
        else
        {
            tmp_ctl |= _VAL2FLD(SMIF_CORE_CTL_SELECT_SETUP_DELAY, 1);
            tmp_ctl |= _VAL2FLD(SMIF_CORE_CTL_SELECT_HOLD_DELAY, 1);
        }

        SMIF_CTL(base) = tmp_ctl;
    }

    return result;
}

/*******************************************************************************
* Function Name: Cy_SMIF_DllConfig
****************************************************************************//**
*
* This function configures the DLL for use, per the SMIF configuration structure
* parameters.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param config
* Passes a configuration structure that configures the SMIF block for operation,
* here specifically it is used to configure the DLL.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return
*     - \ref CY_SMIF_BAD_PARAM
*     - \ref CY_SMIF_SUCCESS

* \note The SMIF must be disabled before calling the function. Call
*  \ref Cy_SMIF_Disable
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_DllConfig(volatile SMIF_Type *base,
                                    cy_stc_smif_config_t const *config,
                                    cy_stc_smif_context_t *context)
{
    if ((NULL == base) || (NULL == config) || (NULL == context))
    {
        return CY_SMIF_BAD_PARAM;
    }

    /* Bounds check the tap selection.  See MDL_TAP_SEL restrictions in TRM. */
    if (config->dll_divider_value != CY_SMIF_DLL_DIVIDE_BY_2)
    {
        if ((config->mode == (uint32_t)CY_SMIF_NORMAL) && (context->preCmdDataRate == CY_SMIF_SDR))
        {
            /* Bounds for when SDR is in use. */
            if ((config->mdl_tap < CY_SMIF_CLKOUT_NON_ZERO_MDL_TAP_MIN_SDR) || (config->mdl_tap > CY_SMIF_CLKOUT_NON_ZERO_MDL_TAP_MAX_SDR))
            {
                return CY_SMIF_BAD_PARAM;
            }
        }
        else
        {
            /* Bounds for when DDR is in use. */
            if ((config->mdl_tap < CY_SMIF_CLKOUT_NON_ZERO_MDL_TAP_MIN_DDR) || (config->mdl_tap > CY_SMIF_CLKOUT_NON_ZERO_MDL_TAP_MAX_DDR))
            {
                return CY_SMIF_BAD_PARAM;
            }
        }
    }

    /* Make sure we start from a sane default. */
    uint32_t tmp_ctl2 = CY_SMIF_CTL2_REG_DEFAULT;

    /* Enable the DLL, if needed.   Otherwise, enable the bypass. */
    if (config->enable_internal_dll)
    {
        /* These values are taken from the Register TRM entry for SMIF_CORE_CTL2_DLL_SPEED_MODE. */
        static uint32_t pll_freq_bounds[] = {150u, 192u, 245u, 313u, 400u};
        static uint32_t dll_skip_lsb_vals[] = {0U, 0U, 1U, 3U};


        if (config->inputFrequencyMHz <= 150U)
        {
            /* DLL must run in open loop mode when input frequency is lower
             than 150 MHz for SMIFv5 or greater. */
            tmp_ctl2 |= _VAL2FLD(SMIF_CORE_CTL2_DLL_OPENLOOP_ENABLE, 1U);
            SMIF_IDAC(base) = 0; /* Set to 0 for max delay (for accuracy), minimum delay value is 0xA7F. */
        }
        else
        {
            /* Determine the frequency bounds and set the speed mode accordingly */
            uint32_t pll_bounds_idx;
            uint32_t pll_bounds_cnt = (sizeof(pll_freq_bounds) / sizeof(pll_freq_bounds[0])) - 1UL;
            for (pll_bounds_idx = 0UL; pll_bounds_idx < pll_bounds_cnt; pll_bounds_idx++)
            {
                if ((pll_freq_bounds[pll_bounds_idx] <= config->inputFrequencyMHz) &&
                    (config->inputFrequencyMHz <= pll_freq_bounds[pll_bounds_idx + 1UL]))
                {
                    tmp_ctl2 |= _VAL2FLD(SMIF_CORE_CTL2_DLL_SPEED_MODE, pll_bounds_idx);
                    tmp_ctl2 |= (_VAL2FLD(SMIF_CORE_CTL2_DLL_SKIP_LSB, dll_skip_lsb_vals[pll_bounds_idx]) |
                            SMIF_CORE_CTL2_DLL_IGNORE_LOCK_Msk |             //Recommendation from IP team
                            _VAL2FLD(SMIF_CORE_CTL2_DLL_UNLOCK_VALUE, 5U));  //Recommendation from IP team
                     break;
                }
            }
            if (pll_bounds_idx == pll_bounds_cnt)
            {
                return CY_SMIF_BAD_PARAM;
            }
        }
    }
    else
    {
        /* DLL runs in open loop mode */
        tmp_ctl2 |= SMIF_CORE_CTL2_DLL_BYPASS_MODE_Msk;
        tmp_ctl2 |= _VAL2FLD(SMIF_CORE_CTL2_DLL_OPENLOOP_ENABLE, 1U);
        SMIF_IDAC(base) = 0U; /* Set max delay for accuracy */
    }

    tmp_ctl2 |= _VAL2FLD(SMIF_CORE_CTL2_CLKOUT_DIV, config->dll_divider_value);
    tmp_ctl2 |= _VAL2FLD(SMIF_CORE_CTL2_MDL_TAP_SEL, config->mdl_tap);
    tmp_ctl2 |= _VAL2FLD(SMIF_CORE_CTL2_RX_CAPTURE_MODE, config->rx_capture_mode);
    tmp_ctl2 |= _VAL2FLD(SMIF_CORE_CTL2_RX_CHASE_MARGIN, 2UL); /* The default value expected to always work */
    tmp_ctl2 |= _VAL2FLD(SMIF_CORE_CTL2_TX_SDR_EXTRA_SETUP, config->tx_sdr_extra);

    /* Write the register value that has been constructed per the configuration input. */
    SMIF_CTL2(base) = tmp_ctl2;

    return CY_SMIF_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_SMIF_DeInit
****************************************************************************//**
*
* This function de-initializes the SMIF block to default values.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \note The SMIF must be disabled before calling the function. Call
*  \ref Cy_SMIF_Disable
*
*******************************************************************************/
void Cy_SMIF_DeInit(SMIF_Type *base)
{
    uint32_t idx;

    /* Configure the SMIF interface to default values.
    * The default value is 0.
    */
    SMIF_CTL(base) = CY_SMIF_CTL_REG_DEFAULT;
    SMIF_CTL2(base) = CY_SMIF_CTL2_REG_DEFAULT;
     SMIF_TX_DATA_FIFO_CTL(base) = 0U;
    SMIF_RX_DATA_FIFO_CTL(base) = 0U;
    SMIF_INTR_MASK(base) = 0U;

    for(idx = 0UL; idx < SMIF_DEVICE_NR; idx++)
    {
        SMIF_DEVICE_IDX_CTL(base, idx) = 0U;
    }
}


/*******************************************************************************
* Function Name: Cy_SMIF_SetMode
****************************************************************************//**
*
* Sets the mode of operation for the SMIF. The mode of operation can be the XIP
* mode where the slave devices are mapped as memories and are directly accessed
* from the PSoC register map. In the MMIO mode, the SMIF block acts as a simple
* SPI engine. MMIO mode and XIP modes are mutually exclusive. SMIF IP Version 3
* and above support MMIO mode transactions even when XIP mode is enabled. However,
* user has to ensure that XIP transaction is not issued during an ongoing MMIO
* transaction. Rather wait for MMIO transaction to complete since few MMIO operations
* make external flash busy and it cannot respond to XIP read transaction.
*
* \note With SMIF V1 IP, Interrupt and triggers are not working in XIP mode, see TRM for details
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param mode
* The mode of the SMIF operation.
*
*******************************************************************************/
void Cy_SMIF_SetMode(SMIF_Type *base, cy_en_smif_mode_t mode)
{
    CY_ASSERT_L3(CY_SMIF_MODE_VALID(mode));

    /*  Set the register SMIF.CTL.XIP_MODE = TRUE */
    if (CY_SMIF_NORMAL == mode)
    {
        SMIF_CTL(base) &= ~ SMIF_CTL_XIP_MODE_Msk;
    }
    else
    {
         SMIF_CTL(base) |= SMIF_CTL_XIP_MODE_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_SMIF_GetMode
****************************************************************************//**
*
* Reads the mode of operation for the SMIF. The mode of operation can be the
* XIP mode where the slave devices are mapped as memories and are directly
* accessed from the PSoC register map. In the MMIO mode, the SMIF block acts as
* a simple SPI engine.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return The mode of SMIF operation (see \ref cy_en_smif_mode_t).
*
*******************************************************************************/
cy_en_smif_mode_t Cy_SMIF_GetMode(SMIF_Type const *base)
{
    cy_en_smif_mode_t result = CY_SMIF_NORMAL;

    /* Read the register SMIF.CTL.XIP_MODE */
    if (0U != (SMIF_CTL(base) & SMIF_CTL_XIP_MODE_Msk))
    {
        result = CY_SMIF_MEMORY;
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_SMIF_SetDataSelect
****************************************************************************//**
*
* This function configures the data select option for a specific slave. The
* selection provides pre-set combinations for connecting the SMIF data lines to
* the GPIOs.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slaveSelect
* The slave device ID. This number is either CY_SMIF_SLAVE_SELECT_0 or
* CY_SMIF_SLAVE_SELECT_1 or CY_SMIF_SLAVE_SELECT_2 or CY_SMIF_SLAVE_SELECT_3
* (\ref cy_en_smif_slave_select_t). It defines the slave select line to be used
* during the transmission.
*
* \param dataSelect
* This parameter selects the data select option. \ref cy_en_smif_data_select_t
*
*******************************************************************************/
void Cy_SMIF_SetDataSelect(SMIF_Type *base, cy_en_smif_slave_select_t slaveSelect,
                            cy_en_smif_data_select_t dataSelect)
{
    SMIF_DEVICE_Type volatile *device;

    CY_ASSERT_L3(CY_SMIF_SLAVE_SEL_VALID(slaveSelect));
    CY_ASSERT_L3(CY_SMIF_DATA_SEL_VALID(dataSelect));

    /* Connect the slave to its data lines */
    device = Cy_SMIF_GetDeviceBySlot(base, slaveSelect);

    if(NULL != device)
    {
        SMIF_DEVICE_CTL(device) = _CLR_SET_FLD32U(SMIF_DEVICE_CTL(device),
                                                  SMIF_DEVICE_CTL_DATA_SEL,
                                                  (uint32_t)dataSelect);
    }
}

/*******************************************************************************
* Function Name: Cy_SMIF_Set_Sdl_DelayTapSel
****************************************************************************//**
*
* This function sets the SDL (slave clock) delay tap number for the SMIF (common
* for all its devices).  It sets both the positive and negative taps to the same
* value.
*
* \param smif_device_base
* Holds the base address of the SMIF_DEVICE block registers.
*
* \param tapSel
* positive and negative delay tap selection to be set
*
* \return status (see \ref cy_en_smif_status_t).
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Set_Sdl_DelayTapSel(SMIF_CORE_DEVICE_Type *smif_device_base, uint8_t tapSel)
{
    /* Check the the delay tap is within range. */
    if (tapSel > (CY_SMIF_GetDelayTapsNumber(smif_device_base) - 1UL))
    {
        return CY_SMIF_BAD_PARAM;
    }

    SMIF_DEVICE_RX_CAPTURE_CONFIG(smif_device_base) = _CLR_SET_FLD32U(SMIF_DEVICE_RX_CAPTURE_CONFIG(smif_device_base), SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_POS_SDL_TAP_SEL, tapSel);
    SMIF_DEVICE_RX_CAPTURE_CONFIG(smif_device_base) = _CLR_SET_FLD32U(SMIF_DEVICE_RX_CAPTURE_CONFIG(smif_device_base), SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_NEG_SDL_TAP_SEL, tapSel);

    return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function Name: CY_SMIF_GetDelayTapsNumber
****************************************************************************//**
*
* This function returns tap number which the SMIF IP has.
* User can input both SMIF DEVICE block address and SMIF block address
*
* \param base
* Base address of the SMIF block or the SMIF DEVICE block.
*
* \return Delay tap Number of the SMIF IP
*
*******************************************************************************/
uint32_t CY_SMIF_GetDelayTapsNumber(volatile void *base)
{
    CY_UNUSED_PARAMETER(base);
    return SMIF_DELAY_TAPS_NR;
}



/*******************************************************************************
* Function Name: Cy_SMIF_TransmitCommand()
****************************************************************************//**
*
* This function transmits a command byte followed by a parameter which is
* typically an address field. The transfer is implemented using the TX FIFO.
* This function also asserts the slave select line.
* A command to a memory device generally starts with a command byte
* transmission. This function sets up the slave lines for the rest of the
* command structure. The \ref Cy_SMIF_TransmitCommand is called before \ref
* Cy_SMIF_TransmitData or \ref Cy_SMIF_ReceiveData is called. When enabled, the
* completeTxfr parameter in the function will de-assert the slave select line at
* the end of the function execution.
*
* \note This function blocks until all the command and associated parameters
* have been transmitted over the SMIF block or timeout expire.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param cmd
* The command byte to be transmitted.
*
* \param cmdTxfrWidth
* The width of command byte transfer \ref cy_en_smif_txfr_width_t.
*
* \param cmdParam
* This is the pointer to an array that has bytes to be transmitted
* after the command byte. Typically, this field has the address bytes
* associated with the memory command.
*
* \param paramSize
* The size of the cmdParam array.
*
* \param paramTxfrWidth
* The width of parameter transfer \ref cy_en_smif_txfr_width_t.
*
* \param slaveSelect
* Denotes the number of the slave device to which the transfer is made.
* (0, 1, 2 or 4 - the bit defines which slave to enable) Two-bit enable is
* possible only for the double quad SPI mode.
*
* \param completeTxfr
* Specifies if the slave select line must be de-asserted after transferring
* the last byte in the parameter array. Typically, this field is set to 0 when
* this function succeed through \ref Cy_SMIF_TransmitData or \ref
* Cy_SMIF_ReceiveData.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of the command transmit.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_EXCEED_TIMEOUT
*
* \note Check \ref group_smif_usage_rules for any usage restriction
*
*******************************************************************************/
cy_en_smif_status_t  Cy_SMIF_TransmitCommand(SMIF_Type *base,
                                uint8_t cmd,
                                cy_en_smif_txfr_width_t cmdTxfrWidth,
                                uint8_t const cmdParam[],
                                uint32_t paramSize,
                                cy_en_smif_txfr_width_t paramTxfrWidth,
                                cy_en_smif_slave_select_t  slaveSelect,
                                uint32_t completeTxfr,
                                cy_stc_smif_context_t const *context)
{
    return Cy_SMIF_TransmitCommand_Ext(base,
                                       (uint16_t)cmd,
                                       false,
                                       cmdTxfrWidth,
                                       CY_SMIF_SDR,
                                       cmdParam,
                                       paramSize,
                                       paramTxfrWidth,
                                       CY_SMIF_SDR,
                                       slaveSelect,
                                       completeTxfr,
                                       context);
 }


/*******************************************************************************
* Function Name: Cy_SMIF_TransmitData
****************************************************************************//**
*
* This function is used to transmit data using the SMIF interface. This
* function uses the TX Data FIFO to implement the transmit functionality. The
* function sets up an interrupt to trigger the TX Data FIFO and uses that
* interrupt to fill the TX Data FIFO until all the data is transmitted. At the
* end of the transmission, the TxCompleteCb is executed.
*
* \note  This function is to be preceded by \ref Cy_SMIF_TransmitCommand where
* the slave select is selected. The slave is de-asserted at the end of a
* transmit. The function triggers the transfer and the transfer itself utilizes
* the interrupt for FIFO operations in the background. Thus, frequent
* interrupts will be executed after this function is triggered.
* Since this API is non-blocking and sets up the interrupt to act on the data
* FIFO, ensure there will be no another instance of the function called
* before the current instance has completed execution.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param txBuffer
* The pointer to the data to be transferred. If this pointer is a NULL, then the
* function does not enable the interrupt. This use case is typically used when
* the FIFO is handled outside the interrupt and is managed in either a
* polling-based code or a DMA. The user would handle the FIFO management in a
* DMA or a polling-based code.
*
* \note If the user provides a NULL pointer in this function and does not handle
* the FIFO transaction, this could either stall or timeout the operation.
* The transfer statuses returned by \ref Cy_SMIF_GetTransferStatus are no longer
* valid.
*
* \param size
* The size of txBuffer. Must be > 0 and not greater than 65536.
*
* \param transferWidth
* The width of transfer \ref cy_en_smif_txfr_width_t.
*
* \param TxCompleteCb
* The callback executed at the end of a transmission. NULL interpreted as no
* callback.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of a transmission.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*
*******************************************************************************/
cy_en_smif_status_t  Cy_SMIF_TransmitData(SMIF_Type *base,
                            uint8_t const *txBuffer,
                            uint32_t size,
                            cy_en_smif_txfr_width_t transferWidth,
                            cy_smif_event_cb_t TxCompleteCb,
                            cy_stc_smif_context_t *context)
{

    return Cy_SMIF_TransmitData_Ext(base,
                                    txBuffer,
                                    size,
                                    transferWidth,
                                    CY_SMIF_SDR,
                                    TxCompleteCb,
                                    context);
 }


/*******************************************************************************
* Function Name: Cy_SMIF_TransmitDataBlocking
****************************************************************************//**
*
* This function implements the transmit data phase in the memory command. The
* data is transmitted using the Tx Data FIFO and the TX_COUNT command. This
* function blocks until completion. The function does not use the interrupts and
* will use CPU to monitor the FIFO status and move data accordingly. The
* function returns only on completion.
*
* \note  Since this API is blocking, ensure that other transfers finished and it
* will not be called during non-blocking transfer.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param txBuffer
* The pointer to the data to be transferred. If this pointer is a NULL, then the
* function does not fill TX_FIFO. The user would handle the FIFO management in a
* DMA or a polling-based code.
*
* \note If the user provides a NULL pointer in this function and does not handle
* the FIFO transaction, this could either stall or timeout the operation.
* The transfer statuses returned by \ref Cy_SMIF_GetTransferStatus are no longer
* valid.
*
* \param size
* The size of txBuffer. Must be > 0 and not greater than 65536.
*
* \param transferWidth
* The width of transfer \ref cy_en_smif_txfr_width_t.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of a transmission.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_EXCEED_TIMEOUT
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t  Cy_SMIF_TransmitDataBlocking(SMIF_Type *base,
                            uint8_t const *txBuffer,
                            uint32_t size,
                            cy_en_smif_txfr_width_t transferWidth,
                            cy_stc_smif_context_t const *context)
{
    return Cy_SMIF_TransmitDataBlocking_Ext(base,
                                            txBuffer,
                                            size,
                                            transferWidth,
                                            CY_SMIF_SDR,
                                            context);
 }


/*******************************************************************************
* Function Name: Cy_SMIF_ReceiveData
****************************************************************************//**
*
* This function implements the receive data phase in the memory command. The
* data is received into the RX Data FIFO using the RX_COUNT command. This
* function sets up the interrupt to trigger on the RX Data FIFO level, and the
* data is fetched from the RX Data FIFO to the rxBuffer as it gets filled. This
* function does not block until completion. The completion will trigger the call
* back function.
*
* \note This function is to be preceded by \ref Cy_SMIF_TransmitCommand. The
* slave select is de-asserted at the end of the receive.
* The function triggers the transfer and the transfer itself utilizes the
* interrupt for FIFO operations in the background. Thus, frequent
* interrupts will be executed after this function is triggered.
* This API is non-blocking and sets up the interrupt to act on the data
* FIFO, ensure there will be no another instance of the function called
* before the current instance has completed execution.
*
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param rxBuffer
* The pointer to the variable where the receive data is stored. If this pointer
* is a NULL, then the function does not enable the interrupt. This use case is
* typically used when the FIFO is handled outside the interrupt and is managed
* in either a polling-based code or a DMA. The user would handle the FIFO
* management in a DMA or a polling-based code.
*
* \note If the user provides a NULL pointer in this function and does not handle
* the FIFO transaction, this could either stall or timeout the operation.
* The transfer statuses returned by \ref Cy_SMIF_GetTransferStatus are no longer
* valid.
*
* \param size
* The size of data to be received. Must be > 0 and not greater than 65536.
*
* \param transferWidth
* The width of transfer \ref cy_en_smif_txfr_width_t.
*
* \param RxCompleteCb
* The callback executed at the end of a reception. NULL interpreted as no
* callback.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of a reception.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_BAD_PARAM
*
* \note Check \ref group_smif_usage_rules for any usage restriction
*
*******************************************************************************/
cy_en_smif_status_t  Cy_SMIF_ReceiveData(SMIF_Type *base,
                            uint8_t *rxBuffer,
                            uint32_t size,
                            cy_en_smif_txfr_width_t transferWidth,
                            cy_smif_event_cb_t RxCompleteCb,
                            cy_stc_smif_context_t *context)
{
    return Cy_SMIF_ReceiveData_Ext(base,
                                   rxBuffer,
                                   size,
                                   transferWidth,
                                   CY_SMIF_SDR,
                                   RxCompleteCb,
                                   context);
 }


/*******************************************************************************
* Function Name: Cy_SMIF_ReceiveDataBlocking
****************************************************************************//**
*
* This function implements the receive data phase in the memory command. The
* data is received into the RX Data FIFO using the RX_COUNT command. This
* function blocks until completion. The function does not use the interrupts and
* will use CPU to monitor the FIFO status and move data accordingly. The
* function returns only on completion.
*
* \note This function is to be preceded by \ref Cy_SMIF_TransmitCommand. The
* slave select is de-asserted at the end of the receive. Ensure there is
* no another transfers.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param rxBuffer
* The pointer to the variable where the receive data is stored. If this pointer
* is a NULL, then the function does not enable the interrupt. This use case is
* typically used when the FIFO is handled outside the interrupt and is managed
* in either a polling-based code or a DMA. The user would handle the FIFO
* management in a DMA or a polling-based code.
*
* \note If the user provides a NULL pointer in this function and does not handle
* the FIFO transaction, this could either stall or timeout the operation.
* The transfer statuses returned by \ref Cy_SMIF_GetTransferStatus are no longer
* valid.
*
* \param size
* The size of data to be received. Must be > 0 and not greater than 65536.
*
* \param transferWidth
* The width of transfer \ref cy_en_smif_txfr_width_t.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of a reception.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_EXCEED_TIMEOUT
*       - \ref CY_SMIF_BAD_PARAM
*
* \note Check \ref group_smif_usage_rules for any usage restriction
*
*******************************************************************************/
cy_en_smif_status_t  Cy_SMIF_ReceiveDataBlocking(SMIF_Type *base,
                            uint8_t *rxBuffer,
                            uint32_t size,
                            cy_en_smif_txfr_width_t transferWidth,
                            cy_stc_smif_context_t const *context)
{
     return Cy_SMIF_ReceiveDataBlocking_Ext(base,
                            rxBuffer,
                            size,
                            transferWidth,
                            CY_SMIF_SDR,
                            context);
 }


/*******************************************************************************
* Function Name: Cy_SMIF_SendDummyCycles()
****************************************************************************//**
*
* This function sends dummy-clock cycles. The data lines are tri-stated during
* the dummy cycles.
*
* \note This function is to be preceded by \ref Cy_SMIF_TransmitCommand.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param cycles
* The number of dummy cycles. Must be > 0 and not greater than 65536.
*
* \return A status of dummy cycles sending.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t  Cy_SMIF_SendDummyCycles(SMIF_Type *base,
                                uint32_t cycles)
{
    return Cy_SMIF_SendDummyCycles_Ext(base,
                                       CY_SMIF_WIDTH_SINGLE,
                                       CY_SMIF_SDR,
                                       cycles);
 }


/*******************************************************************************
* Function Name: Cy_SMIF_GetTransferStatus
****************************************************************************//**
*
* This function provides the status of the transfer. This function is used to
* poll for the status of the TransmitData or receiveData function. When this
* function is called to determine the status of ongoing
* \ref Cy_SMIF_ReceiveData() or \ref Cy_SMIF_TransmitData(), the returned status
* is only valid if the functions passed a non-NULL buffer to transmit or
* receive respectively. If the pointer passed to \ref Cy_SMIF_ReceiveData()
* or \ref Cy_SMIF_TransmitData() is a NULL, then the code/DMA outside this
* driver will take care of the transfer and the Cy_GetTxfrStatus() will return
* an erroneous result.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return Returns the transfer status. \ref cy_en_smif_txfr_status_t
*
*******************************************************************************/
cy_en_smif_txfr_status_t Cy_SMIF_GetTransferStatus(SMIF_Type const *base, cy_stc_smif_context_t const *context)
{
    (void)base; /* Suppress warning */
    return (context->transferStatus);
}


/*******************************************************************************
* Function Name: Cy_SMIF_Enable
****************************************************************************//**
*
* Enables the operation of the SMIF block.
*
* \note This function only enables the SMIF IP. The interrupts associated with
* the SMIF will need to be separately enabled using the interrupt driver.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
*******************************************************************************/
void Cy_SMIF_Enable(SMIF_Type *base, cy_stc_smif_context_t *context)
{
    /* Global variables initialization */
    context->txBufferAddress = NULL;
    context->txBufferSize = 0U;
    context->txBufferCounter = 0U;
    context->rxBufferAddress = NULL;
    context->rxBufferSize = 0U;
    context->rxBufferCounter = 0U;
    context->transferStatus = CY_SMIF_STARTED;

    SMIF_CTL(base) |= SMIF_CTL_ENABLED_Msk;

    if ((_FLD2VAL(SMIF_CORE_CTL2_DLL_OPENLOOP_ENABLE, (SMIF_CTL2(base))) == 0U) &&
        (_FLD2VAL(SMIF_CORE_CTL2_DLL_BYPASS_MODE, (SMIF_CTL2(base))) == 0U))
    {
        /* Wait for DLL Lock to be attained */
        while ((SMIF_STATUS(base) & SMIF_CORE_STATUS_DLL_LOCKED_Msk) == 0U) { }
        Cy_SysLib_DelayUs(10);
        /* Wait for the SMIF to no longer be busy */
        while (Cy_SMIF_BusyCheck(base)) { }
    }
 }


/*******************************************************************************
* Function Name: Cy_SMIF_TransmitCommand_Ext()
****************************************************************************//**
*
* This function transmits a command byte followed by a parameter which is
* typically an address field. The transfer is implemented using the TX FIFO.
* This function also asserts the slave select line.
* A command to a memory device generally starts with a command byte
* transmission. This function sets up the slave lines for the rest of the
* command structure. The \ref Cy_SMIF_TransmitCommand_Ext is called before \ref
* Cy_SMIF_TransmitData_Ext or \ref Cy_SMIF_ReceiveData_Ext is called. When enabled, the
* completeTxfr parameter in the function will de-assert the slave select line at
* the end of the function execution.
*
* \note This function blocks until all the command and associated parameters
* have been transmitted over the SMIF block or timeout expire.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param cmd
* The command byte to be transmitted.
*
* \param isCommand2byte
* isCommand2byte
*
* \param cmdTxfrWidth
* The width of command byte transfer \ref cy_en_smif_txfr_width_t.
*
* \param cmdDataRate
* cmdDataRate
*
* \param cmdParam
* This is the pointer to an array that has bytes to be transmitted
* after the command byte. Typically, this field has the address bytes
* associated with the memory command.
*
* \param paramSize
* The size of the cmdParam array.
*
* \param paramTxfrWidth
* The width of parameter transfer \ref cy_en_smif_txfr_width_t.
*
* \param paramDataRate
* paramDataRate
*
* \param slaveSelect
* Denotes the number of the slave device to which the transfer is made.
* (0, 1, 2 or 4 - the bit defines which slave to enable) Two-bit enable is
* possible only for the Double Quad SPI mode.
*
* \param completeTxfr
* Specifies if the slave select line must be de-asserted after transferring
* the last byte in the parameter array. Typically, this field is set to 0 when
* this function succeed through \ref Cy_SMIF_TransmitData_Ext or \ref
* Cy_SMIF_ReceiveData_Ext.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of the command transmit.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_EXCEED_TIMEOUT
*
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_TransmitCommand_Ext(SMIF_Type *base,
                                                 uint16_t cmd,
                                                 bool isCommand2byte,
                                                 cy_en_smif_txfr_width_t cmdTxfrWidth,
                                                 cy_en_smif_data_rate_t cmdDataRate,
                                                 uint8_t const cmdParam[],
                                                 uint32_t paramSize,
                                                 cy_en_smif_txfr_width_t paramTxfrWidth,
                                                 cy_en_smif_data_rate_t paramDataRate,
                                                 cy_en_smif_slave_select_t slaveSelect,
                                                 uint32_t completeTxfr,
                                                 cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t result = CY_SMIF_SUCCESS;

    /* Check input values */
     CY_ASSERT_L3(CY_SMIF_TXFR_WIDTH_VALID(cmdTxfrWidth));
     CY_ASSERT_L3(CY_SMIF_TXFR_WIDTH_VALID(paramTxfrWidth));
     CY_ASSERT_L3(CY_SMIF_SLAVE_SEL_VALID(slaveSelect));
     CY_ASSERT_L3(CY_SMIF_CMD_DATA_RATE_VALID(cmdDataRate));
     CY_ASSERT_L3(CY_SMIF_CMD_PARAM_DATA_RATE_VALID(paramDataRate));
     CY_ASSERT_L1(CY_SMIF_CMD_PARAM_VALID(cmdParam, paramSize));
     CY_ASSERT_L1(CY_SMIF_WIDTH_NA_VALID(paramTxfrWidth, paramSize));

     uint8_t bufIndex = 0U;
     /* The common part of a command and parameter transfer */
     uint32_t const constCmdPart = (
         _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_TX_MODE) |
         _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_SS, slaveSelect));
     uint32_t timeoutUnits = context->timeout;


    /* Prepare a cmd fifo data */
    if (isCommand2byte == true)
    {
        if((cmdTxfrWidth == CY_SMIF_WIDTH_OCTAL) && (cmdDataRate == CY_SMIF_DDR))
        {
             /* 2byte for each one command */
             SMIF_TX_CMD_MMIO_FIFO_WR(base) = constCmdPart |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t) cmdTxfrWidth) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) cmdDataRate) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_1, (uint8_t)(cmd & 0x00FFU)) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_2, (uint8_t)((cmd >> 8U) & 0x00FFU)) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE,
                     ((0UL == paramSize) ? completeTxfr : 0UL)) ;
         }
         else
         {
             /* 1byte for each one command. need to send two command to send a command of 2byte.*/
             SMIF_TX_CMD_MMIO_FIFO_WR(base) = constCmdPart |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t) cmdTxfrWidth) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) cmdDataRate) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_1, (uint8_t)((cmd >> 8U) & 0x00FFU)) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_2, 0U) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE, 0U);

             SMIF_TX_CMD_MMIO_FIFO_WR(base) = constCmdPart |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t) cmdTxfrWidth) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) cmdDataRate) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_1, (uint8_t)(cmd & 0x00FFU)) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_2, 0U) |
                 _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE,
                     ((0UL == paramSize) ? completeTxfr : 0UL)) ;
         }
     }
     else
     {
         /* Send the command byte */
         SMIF_TX_CMD_MMIO_FIFO_WR(base) = constCmdPart |
             _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t) cmdTxfrWidth) |
             _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) cmdDataRate) |
             _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_1, (uint8_t) cmd) |
             _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_2, (uint8_t) 0) |
             _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE,
                 ((0UL == paramSize) ? completeTxfr : 0UL)) ;
     }


    if ((paramTxfrWidth == CY_SMIF_WIDTH_OCTAL) && (paramDataRate == CY_SMIF_DDR))
    {
            // 2 byte transmission for each one command.
            while ((bufIndex < paramSize) && (CY_SMIF_EXCEED_TIMEOUT != result))
            {
                /* Check if there is at least one free entry in TX_CMD_FIFO */
                if    (Cy_SMIF_GetCmdFifoStatus(base) < CY_SMIF_TX_CMD_FIFO_STATUS_RANGE)
                {
                    SMIF_TX_CMD_MMIO_FIFO_WR(base) = constCmdPart |
                        _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_1, (uint32_t) cmdParam[bufIndex+1U]) |
                        _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_2, (uint32_t) cmdParam[bufIndex])|
                        _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t) paramTxfrWidth) |
                        _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) paramDataRate) |
                        _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE,
                            ((((uint32_t)bufIndex + 2UL) < paramSize) ?  0UL : completeTxfr));
                    bufIndex += 2U;
                }
                result = Cy_SMIF_TimeoutRun(&timeoutUnits);
            }
    }
    else
    {
        /* Send the command parameters (usually address) in the blocking mode */
        while ((bufIndex < paramSize) && (CY_SMIF_EXCEED_TIMEOUT != result))
        {
            /* Check if there is at least one free entry in TX_CMD_FIFO */
            if  (Cy_SMIF_GetCmdFifoStatus(base) < CY_SMIF_TX_CMD_FIFO_STATUS_RANGE)
            {
                SMIF_TX_CMD_MMIO_FIFO_WR(base) = constCmdPart |
                    _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_1, (uint32_t) cmdParam[bufIndex]) |
                    _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TXDATA_BYTE_2, 0)|
                    _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t) paramTxfrWidth) |
                    _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) paramDataRate) |
                    _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE,
                            ((((uint32_t)bufIndex + 1UL) < paramSize) ?  0UL : completeTxfr));

                bufIndex++;
            }
            result = Cy_SMIF_TimeoutRun(&timeoutUnits);
        }
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_SMIF_TransmitData_Ext
****************************************************************************//**
*
* This function is used to transmit data using the SMIF interface. This
* function uses the TX Data FIFO to implement the transmit functionality. The
* function sets up an interrupt to trigger the TX Data FIFO and uses that
* interrupt to fill the TX Data FIFO until all the data is transmitted. At the
* end of the transmission, the TxCmpltCb is executed.
*
* \note  This function is to be preceded by \ref Cy_SMIF_TransmitCommand_Ext where
* the slave select is selected. The slave is de-asserted at the end of a
* transmit. The function triggers the transfer and the transfer itself utilizes
* the interrupt for FIFO operations in the background. Thus, frequent
* interrupts will be executed after this function is triggered.
* Since this API is non-blocking and sets up the interrupt to act on the data
* FIFO, ensure there will be no another instance of the function called
* before the current instance has completed execution.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param txBuffer
* The pointer to the data to be transferred. If this pointer is a NULL, then the
* function does not enable the interrupt. This use case is typically used when
* the FIFO is handled outside the interrupt and is managed in either a
* polling-based code or a DMA. The user would handle the FIFO management in a
* DMA or a polling-based code.
*
* \note If the user provides a NULL pointer in this function and does not handle
* the FIFO transaction, this could either stall or timeout the operation.
* The transfer statuses returned by \ref Cy_SMIF_GetTransferStatus are no longer
* valid.
*
* \param size
* The size of txBuffer. Must be > 0 and not greater than 65536.
*
* \param transferWidth
* The width of transfer \ref cy_en_smif_txfr_width_t.
*
* \param dataDataRate
* dataDataRate
*
* \param TxCmpltCb
* The callback executed at the end of a transmission. NULL interpreted as no
* callback.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of a transmission.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_TransmitData_Ext(SMIF_Type *base,
                                                uint8_t const *txBuffer,
                                                uint32_t size,
                                                cy_en_smif_txfr_width_t transferWidth,
                                                cy_en_smif_data_rate_t dataDataRate,
                                                cy_smif_event_cb_t TxCmpltCb,
                                                cy_stc_smif_context_t *context)
{
    /* The return variable */
    cy_en_smif_status_t result = CY_SMIF_CMD_FIFO_FULL;
    uint32_t trUnitNum;

    /* Check input values */
    CY_ASSERT_L3(CY_SMIF_TXFR_WIDTH_VALID(transferWidth));
    CY_ASSERT_L2(CY_SMIF_BUF_SIZE_VALID(size));


    /* If the mode is octal SPI with DDR data unit is a 2-byte */
    if((transferWidth == CY_SMIF_WIDTH_OCTAL) && (dataDataRate == CY_SMIF_DDR))
    {
        trUnitNum = (size / 2U) + (size % 2U);
    }
    else
    {
        trUnitNum = size;
    }

    /* Check if there are enough free entries in TX_CMD_FIFO */
    if  (Cy_SMIF_GetCmdFifoStatus(base) < CY_SMIF_TX_CMD_FIFO_STATUS_RANGE)
    {
        /* Enter the transmitting mode */
        SMIF_TX_CMD_MMIO_FIFO_WR(base) =
            _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_TX_COUNT_MODE) |
            _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t)transferWidth)    |
            _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) dataDataRate) |
            _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TX_COUNT, (trUnitNum - 1UL))|
            _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE, 1U);

        if (NULL != txBuffer)
        {
            /* Move the parameters to the global variables */
            context->txBufferAddress = (uint8_t*)txBuffer;
            context->txBufferSize = size;
            context->txBufferCounter = size;
            context->txCompleteCb = TxCmpltCb;
            context->transferStatus = CY_SMIF_SEND_BUSY;
            context->preCmdDataRate = dataDataRate;
            context->preCmdWidth = transferWidth;

            Cy_SMIF_SetTxFifoTriggerLevel(base, 1U);

            /* Enable the TR_TX_REQ interrupt */
            Cy_SMIF_SetInterruptMask(base,
                                     Cy_SMIF_GetInterruptMask(base) |
                                     SMIF_INTR_TR_TX_REQ_Msk);
        }
        result = CY_SMIF_SUCCESS;
    }


    return (result);
}

/*******************************************************************************
* Function Name: Cy_SMIF_TransmitDataBlocking_Ext
****************************************************************************//**
*
* This function implements the transmit data phase in the memory command. The
* data is transmitted using the Tx Data FIFO and the TX_COUNT command. This
* function blocks until completion. The function does not use the interrupts and
* will use CPU to monitor the FIFO status and move data accordingly. The
* function returns only on completion.
*
* \note  Since this API is blocking, ensure that other transfers finished and it
* will not be called during non-blocking transfer.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param txBuffer
* The pointer to the data to be transferred. If this pointer is a NULL, then the
* function does not fill TX_FIFO. The user would handle the FIFO management in a
* DMA or a polling-based code.
*
* \note If the user provides a NULL pointer in this function and does not handle
* the FIFO transaction, this could either stall or timeout the operation.
* The transfer statuses returned by \ref Cy_SMIF_GetTransferStatus are no longer
* valid.
*
* \param size
* The size of txBuffer. Must be > 0 and not greater than 65536.
*
* \param transferWidth
* The width of transfer \ref cy_en_smif_txfr_width_t.
*
* \param dataDataRate
* dataDataRate
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of a transmission.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_EXCEED_TIMEOUT
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_TransmitDataBlocking_Ext(SMIF_Type *base,
                            uint8_t const *txBuffer,
                            uint32_t size,
                            cy_en_smif_txfr_width_t transferWidth,
                            cy_en_smif_data_rate_t  dataDataRate,
                            cy_stc_smif_context_t const *context)
{
    /* The return variable */
    cy_en_smif_status_t result = CY_SMIF_BAD_PARAM;
    uint32_t trUnitNum;

    /* Check input values */
    CY_ASSERT_L3(CY_SMIF_TXFR_WIDTH_VALID(transferWidth));

    if(size > 0U)
    {
        result = CY_SMIF_CMD_FIFO_FULL;
        /* Check if there are enough free entries in TX_CMD_FIFO */
        if  (Cy_SMIF_GetCmdFifoStatus(base) < CY_SMIF_TX_CMD_FIFO_STATUS_RANGE)
        {
            /* If the mode is octal SPI with DDR or Hyperbus, data unit is a 2-byte */
            if((transferWidth == CY_SMIF_WIDTH_OCTAL) && (dataDataRate == CY_SMIF_DDR))
            {
                trUnitNum = (size / 2U) + (size % 2U);
            }
            else
            {
                trUnitNum = size;
            }

            /* Enter the transmitting mode */
            SMIF_TX_CMD_MMIO_FIFO_WR(base) =
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_TX_COUNT_MODE) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) dataDataRate) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t)transferWidth)    |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_TX_COUNT, (trUnitNum - 1U)) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE, 1U);

            result = CY_SMIF_SUCCESS;

            if (NULL != txBuffer)
            {
                uint32_t timeoutUnits = context->timeout;
                cy_stc_smif_context_t contextLoc = *context;

                /* initialize parameters for Cy_SMIF_PushTxFifo */
                contextLoc.txBufferAddress = (uint8_t*)txBuffer;
                contextLoc.txBufferCounter = size;
                contextLoc.txCompleteCb = NULL;
                contextLoc.transferStatus = CY_SMIF_SEND_BUSY;
                contextLoc.preCmdDataRate = dataDataRate;
                contextLoc.preCmdWidth = transferWidth;

                while ((CY_SMIF_SEND_BUSY == contextLoc.transferStatus) &&
                        (CY_SMIF_EXCEED_TIMEOUT != result))
                {
                    Cy_SMIF_PushTxFifo(base, &contextLoc);
                    result = Cy_SMIF_TimeoutRun(&timeoutUnits);
                }
            }
        }
    }


    return (result);
}

/*******************************************************************************
* Function Name: Cy_SMIF_ReceiveData_Ext
****************************************************************************//**
*
* This function implements the receive data phase in the memory command. The
* data is received into the RX Data FIFO using the RX_COUNT command. This
* function sets up the interrupt to trigger on the RX Data FIFO level, and the
* data is fetched from the RX Data FIFO to the rxBuffer as it gets filled. This
* function does not block until completion. The completion will trigger the call
* back function.
*
* \note This function is to be preceded by \ref Cy_SMIF_TransmitCommand. The
* slave select is de-asserted at the end of the receive.
* The function triggers the transfer and the transfer itself utilizes the
* interrupt for FIFO operations in the background. Thus, frequent
* interrupts will be executed after this function is triggered.
* This API is non-blocking and sets up the interrupt to act on the data
* FIFO, ensure there will be no another instance of the function called
* before the current instance has completed execution.
*
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param rxBuffer
* The pointer to the variable where the receive data is stored. If this pointer
* is a NULL, then the function does not enable the interrupt. This use case is
* typically used when the FIFO is handled outside the interrupt and is managed
* in either a polling-based code or a DMA. The user would handle the FIFO
* management in a DMA or a polling-based code.
*
* \note If the user provides a NULL pointer in this function and does not handle
* the FIFO transaction, this could either stall or timeout the operation.
* The transfer statuses returned by \ref Cy_SMIF_GetTransferStatus are no longer
* valid.
*
* \param size
* The size of data to be received. Must be > 0 and not greater than 65536.
*
* \param transferWidth
* The width of transfer \ref cy_en_smif_txfr_width_t.
*
* \param dataRate
* dataRate
*
* \param RxCmpltCb
* The callback executed at the end of a reception. NULL interpreted as no
* callback.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of a reception.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_BAD_PARAM
*
* \note Check \ref group_smif_usage_rules for any usage restriction
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_ReceiveData_Ext(SMIF_Type *base,
                                                uint8_t *rxBuffer,
                                                uint32_t size,
                                                cy_en_smif_txfr_width_t transferWidth,
                                                cy_en_smif_data_rate_t dataRate,
                                                cy_smif_event_cb_t RxCmpltCb,
                                                cy_stc_smif_context_t *context)
{
    /* The return variable */
    cy_en_smif_status_t result = CY_SMIF_BAD_PARAM;
    uint32_t rxUnitNum;

    /* Check input values */
    CY_ASSERT_L3(CY_SMIF_TXFR_WIDTH_VALID(transferWidth));

    if(size > 0U)
    {
        result = CY_SMIF_CMD_FIFO_FULL;
        /* Check if there are enough free entries in TX_CMD_FIFO */
        if  (Cy_SMIF_GetCmdFifoStatus(base) < CY_SMIF_TX_CMD_FIFO_STATUS_RANGE)
        {
            /* If the mode is octal SPI with DDR or Hyperbus, data unit is a 2-byte */
            if((transferWidth == CY_SMIF_WIDTH_OCTAL) && (dataRate == CY_SMIF_DDR))
            {
                rxUnitNum = (size / 2U) + (size % 2U);
            }
            else
            {
                rxUnitNum = size;
            }

            /* Enter the receiving mode */
            SMIF_TX_CMD_MMIO_FIFO_WR(base) =
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_RX_COUNT_MODE) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t)transferWidth)    |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) dataRate) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_RX_COUNT, (rxUnitNum - 1UL)) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE, 1U);

            if (NULL != rxBuffer)
            {
                /* Move the parameters to the global variables */
                context->rxBufferAddress = (uint8_t*)rxBuffer;
                context->rxBufferSize = size;
                context->rxBufferCounter = size;
                context->rxCompleteCb = RxCmpltCb;
                context->transferStatus = CY_SMIF_REC_BUSY;

                /* Enable the TR_RX_REQ interrupt */
                Cy_SMIF_SetInterruptMask(base,
                    Cy_SMIF_GetInterruptMask(base) | SMIF_INTR_TR_RX_REQ_Msk);
            }
            result = CY_SMIF_SUCCESS;
        }
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_SMIF_ReceiveDataBlocking_Ext
****************************************************************************//**
*
* This function implements the receive data phase in the memory command. The
* data is received into the RX Data FIFO using the RX_COUNT command. This
* function blocks until completion. The function does not use the interrupts and
* will use CPU to monitor the FIFO status and move data accordingly. The
* function returns only on completion.
*
* \note This function is to be preceded by \ref Cy_SMIF_TransmitCommand. The
* slave select is de-asserted at the end of the receive. Ensure there is
* no another transfers.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param rxBuffer
* The pointer to the variable where the receive data is stored. If this pointer
* is a NULL, then the function does not enable the interrupt. This use case is
* typically used when the FIFO is handled outside the interrupt and is managed
* in either a polling-based code or a DMA. The user would handle the FIFO
* management in a DMA or a polling-based code.
*
* \note If the user provides a NULL pointer in this function and does not handle
* the FIFO transaction, this could either stall or timeout the operation.
* The transfer statuses returned by \ref Cy_SMIF_GetTransferStatus are no longer
* valid.
*
* \param size
* The size of data to be received. Must be > 0 and not greater than 65536.
*
* \param transferWidth
* The width of transfer \ref cy_en_smif_txfr_width_t.
*
* \param dataRate
* dataRate
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of a reception.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_EXCEED_TIMEOUT
*       - \ref CY_SMIF_BAD_PARAM
*
* \note Check \ref group_smif_usage_rules for any usage restriction
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_ReceiveDataBlocking_Ext(SMIF_Type *base,
                            uint8_t *rxBuffer,
                            uint32_t size,
                            cy_en_smif_txfr_width_t transferWidth,
                            cy_en_smif_data_rate_t dataRate,
                            cy_stc_smif_context_t const *context)
{
    /* The return variable */
    cy_en_smif_status_t result = CY_SMIF_BAD_PARAM;
    uint32_t rxUnitNum;

    /* Check input values */
    CY_ASSERT_L3(CY_SMIF_TXFR_WIDTH_VALID(transferWidth));

    if(size > 0U)
    {
        result = CY_SMIF_CMD_FIFO_FULL;
        /* Check if there are enough free entries in TX_CMD_FIFO */
        if  (Cy_SMIF_GetCmdFifoStatus(base) < CY_SMIF_TX_CMD_FIFO_STATUS_RANGE)
        {
              /* If the mode is octal SPI with DDR or Hyperbus, data unit is a 2-byte */
            if((transferWidth == CY_SMIF_WIDTH_OCTAL) && (dataRate == CY_SMIF_DDR))
            {
                rxUnitNum = (size / 2U) + (size % 2U);
            }
            else
            {
                rxUnitNum = size;
            }

            /* Enter the receiving mode */
            SMIF_TX_CMD_MMIO_FIFO_WR(base) =
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_RX_COUNT_MODE) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t)transferWidth)    |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_RX_COUNT, (rxUnitNum - 1UL)) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) dataRate) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE, 1U);

            /* Add delay to ensure receiving mode was entered correctly */
            Cy_SysLib_DelayUs(1);

            result = CY_SMIF_SUCCESS;

            if (NULL != rxBuffer)
            {
                uint32_t timeoutUnits = context->timeout;
                cy_stc_smif_context_t contextLoc;

                /* initialize parameters for Cy_SMIF_PushTxFifo */
                contextLoc.rxBufferAddress = (uint8_t*)rxBuffer;
                contextLoc.rxBufferCounter = size;
                contextLoc.rxCompleteCb = NULL;
                contextLoc.transferStatus = CY_SMIF_REC_BUSY;

                while ((CY_SMIF_REC_BUSY == contextLoc.transferStatus) &&
                        (CY_SMIF_EXCEED_TIMEOUT != result))
                {
                    Cy_SMIF_PopRxFifo(base, &contextLoc);
                    result = Cy_SMIF_TimeoutRun(&timeoutUnits);
                }
            }
        }
    }


    return (result);
}


/*******************************************************************************
* Function Name: Cy_SMIF_SendDummyCycles_Ext()
****************************************************************************//**
*
* This function sends dummy-clock cycles. The data lines are tri-stated during
* the dummy cycles.
*
* \note This function is to be preceded by \ref Cy_SMIF_TransmitCommand.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param transferWidth
*
* \param dataRate
*
* \param cycles
* The number of dummy cycles. Must be > 0 and not greater than 65536.
*
* \return A status of dummy cycles sending.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_SendDummyCycles_Ext(SMIF_Type *base,
                                                cy_en_smif_txfr_width_t transferWidth,
                                                cy_en_smif_data_rate_t dataRate,
                                                uint32_t cycles)
{
    /* The return variable */
    cy_en_smif_status_t result = CY_SMIF_BAD_PARAM;
    if (cycles > 0U)
    {
        result = CY_SMIF_CMD_FIFO_FULL;
        uint32_t dummyRWDS = 0U;
        if (_FLD2VAL(SMIF_CORE_CTL2_RX_CAPTURE_MODE, (SMIF_CTL2(base))) == (uint32_t)CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS)
        {
            dummyRWDS = 1U;
        }
        /* Check if there are enough free entries in TX_CMD_FIFO */
        if  (Cy_SMIF_GetCmdFifoStatus(base) < CY_SMIF_TX_CMD_FIFO_STATUS_RANGE)
        {
            /* Send the dummy bytes */
            SMIF_TX_CMD_MMIO_FIFO_WR(base) =
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_DUMMY_COUNT_MODE) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY, (cycles-1UL)) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t)transferWidth)    |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) dataRate) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_READ_RWDS, dummyRWDS) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE, 0);

            result = CY_SMIF_SUCCESS;
        }
    }

    return (result);
}
/*******************************************************************************
* Function Name: Cy_SMIF_SendDummyCycles_With_RWDS()
****************************************************************************//**
*
* This function sends dummy-clock cycles and observes additional input data signal RWDS.
* The data lines are tri-stated during
* the dummy cycles.
*
* \note This function is to be preceded by \ref Cy_SMIF_TransmitCommand_Ext.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param read_rwds
* Indicates whether it is read/write transaction. "true" in case of read. "false" in case of write.
*
* \param refresh_indicator
* Dummy cycles are doubled when RWDS refresh indicator is high during CA cycle. (HyperRAM variable latency mode)
*
* \param cycles
* The number of dummy cycles. Must be > 0 and not greater than 65536.
*
* \return A status of dummy cycles sending.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_CMD_FIFO_FULL
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_SendDummyCycles_With_RWDS(SMIF_Type *base,
                                                bool read_rwds,
                                                bool refresh_indicator,
                                                uint32_t cycles)
{
    /* The return variable */
    cy_en_smif_status_t result = CY_SMIF_BAD_PARAM;

    if (cycles > 0U)
    {
        result = CY_SMIF_CMD_FIFO_FULL;

        /* Check if there are enough free entries in TX_CMD_FIFO */
        if  (Cy_SMIF_GetCmdFifoStatus(base) < CY_SMIF_TX_CMD_FIFO_STATUS_RANGE)
        {
            /* Send the dummy bytes */
            SMIF_TX_CMD_MMIO_FIFO_WR(base) =
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_DUMMY_COUNT_MODE) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY, (cycles-1UL)) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_WIDTH, (uint32_t)CY_SMIF_WIDTH_OCTAL)    |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DATA_RATE, (uint32_t) CY_SMIF_DDR) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_READ_RWDS, (uint32_t)read_rwds) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_DUMMY_WRITE_RWDS,(uint32_t)!(read_rwds)) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_RWDS_REFRESH, (uint32_t)refresh_indicator) |
                _VAL2FLD(CY_SMIF_CMD_MMIO_FIFO_WR_LAST_BYTE, 0);

            result = CY_SMIF_SUCCESS;
        }
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_SMIF_SetCryptoKey
****************************************************************************//**
*
* Sets the AES-128 encryption key into SMIF crypto registers.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param key
* An array containing 128 bit crypto key: uint32_t key[4].
* The least significant word first.
*
*******************************************************************************/
void Cy_SMIF_SetCryptoKey(SMIF_Type *base, uint32_t *key)
{
    SMIF_CRYPTO_KEY0(base) = key[0U];
    SMIF_CRYPTO_KEY1(base) = key[1U];
    SMIF_CRYPTO_KEY2(base) = key[2U];
    SMIF_CRYPTO_KEY3(base) = key[3U];
}

/*******************************************************************************
* Function Name: Cy_SMIF_SetCryptoIV
****************************************************************************//**
*
* Sets the 96 bit initialization vector (nonce) into SMIF crypto registers.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param nonce
* An array containing 96 bit initialization vector (nonce)
*
*******************************************************************************/
void Cy_SMIF_SetCryptoIV(SMIF_Type *base, uint32_t *nonce)
{
    /* SMIF_CRYPTO_INPUT0 is a counter, the rest 3 registers are nonce */
    SMIF_CRYPTO_INPUT1(base) = nonce[0U];
    SMIF_CRYPTO_INPUT2(base) = nonce[1U];
    SMIF_CRYPTO_INPUT3(base) = nonce[2U];
}

/*******************************************************************************
* Function Name: Cy_SMIF_ConvertSlaveSlotToIndex
****************************************************************************//**
*
* Converts Slave Select enum to the device index.
*
* \param ss
* Slave Select enum.
*
* \param device_idx
* A pointer to device index to be returned.
*
* \return \ref cy_en_smif_status_t.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_ConvertSlaveSlotToIndex(cy_en_smif_slave_select_t ss, uint32_t *device_idx)
{
    cy_en_smif_status_t ret = CY_SMIF_BAD_PARAM;

    #if defined(__clang__) && !defined(__ARMCC_VERSION) /* For LLVM Clang */
        uint32_t v = (uint32_t)ss;
        if ((v == 0U) || (v > 8U) || ((v & (v - 1U)) != 0U))
        {
            return ret;
        }
        *device_idx = (uint32_t)__builtin_ctz(v);
        ret = CY_SMIF_SUCCESS;
    #else
    switch (ss)
    {
        case CY_SMIF_SLAVE_SELECT_0:
            *device_idx = 0U;
            ret = CY_SMIF_SUCCESS;
            break;
        case CY_SMIF_SLAVE_SELECT_1:
            *device_idx = 1U;
            ret = CY_SMIF_SUCCESS;
            break;
        case CY_SMIF_SLAVE_SELECT_2:
            *device_idx = 2U;
            ret = CY_SMIF_SUCCESS;
            break;
        case CY_SMIF_SLAVE_SELECT_3:
            *device_idx = 3U;
            ret = CY_SMIF_SUCCESS;
            break;
        default:
            /* The switch statement must have a non-empty default clause. MISRA 16.4 */
            ret = CY_SMIF_BAD_PARAM;
            break;
    }
    #endif
    return ret;
}

/*******************************************************************************
* Function Name: Cy_SMIF_SetCryptoEnable
****************************************************************************//**
*
* Enables SMIF encryption
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slaveId
* slave select line to indicate the device on which encryption should be enabled.
*
* \return \ref cy_en_smif_status_t.
*
* \note Please ensure cache is disabled using \ref Cy_SMIF_CacheDisable or
* invalidated using \ref Cy_SMIF_CacheInvalidate or any other system level cache to
* be cleared so that the next read/execute from flash operation results in correct data.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_SetCryptoEnable(SMIF_Type *base, cy_en_smif_slave_select_t slaveId)
{
    uint32_t device_idx;
    cy_en_smif_status_t ret = CY_SMIF_BAD_PARAM;

    if (CY_SMIF_SUCCESS == Cy_SMIF_ConvertSlaveSlotToIndex(slaveId, &device_idx))
    {
        SMIF_DEVICE_IDX_CTL(base, device_idx) |= SMIF_DEVICE_CTL_CRYPTO_EN_Msk;
        ret = CY_SMIF_SUCCESS;
    }

    return ret;
}


/*******************************************************************************
* Function Name: Cy_SMIF_SetCryptoDisable
****************************************************************************//**
*
* Disables SMIF encryption.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slaveId
* slave select line to indicate the device on which encryption should be disabled.
*
* \return \ref cy_en_smif_status_t.
*
* \note Please ensure cache is disabled using \ref Cy_SMIF_CacheDisable or
* invalidated using \ref Cy_SMIF_CacheInvalidate or any other system level cache to
* be cleared so that the next read/execute from flash operation results in correct data.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_SetCryptoDisable(SMIF_Type *base, cy_en_smif_slave_select_t slaveId)
{
    cy_en_smif_status_t ret = CY_SMIF_BAD_PARAM;
    uint32_t device_idx;

    if (CY_SMIF_SUCCESS == Cy_SMIF_ConvertSlaveSlotToIndex(slaveId, &device_idx))
    {
        SMIF_DEVICE_IDX_CTL(base, device_idx) &= ~SMIF_DEVICE_CTL_CRYPTO_EN_Msk;
        ret = CY_SMIF_SUCCESS;
    }
    return ret;
}

/*******************************************************************************
* Function Name: Cy_SMIF_IsCryptoEnabled
****************************************************************************//**
*
* Checks the status of encryption for the selected slave device.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slaveId
* slave select line to indicate the device on which encryption should be disabled.
*
* \param crypto_status
* Holds the status of encryption.
*
* \return CY_SMIF_SUCCESS if we are able get the Cache status otherwise returns CY_SMIF_BAD_PARAM.

*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_IsCryptoEnabled(SMIF_Type *base, cy_en_smif_slave_select_t slaveId, bool *crypto_status)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(NULL != crypto_status);

    uint32_t device_idx;
    cy_en_smif_status_t ret = CY_SMIF_BAD_PARAM;


    if (CY_SMIF_SUCCESS == Cy_SMIF_ConvertSlaveSlotToIndex(slaveId, &device_idx))
    {
        *crypto_status = ((SMIF_DEVICE_IDX_CTL(base, device_idx) & SMIF_DEVICE_CTL_CRYPTO_EN_Msk) == SMIF_DEVICE_CTL_CRYPTO_EN_Msk);
        ret = CY_SMIF_SUCCESS;
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_SMIF_SetCryptoKeyRegion
****************************************************************************//**
*
* Configures a crypto region with specified start address, size and keys.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param crypto_region_index
* Crypto region index for which sub region disable mask has to be applied.
* Region index starts from 0, 1, 2, ... upto (SMIF_CRYPTO_KEY_NR - 1).
*
* \param region_config
* Crypto region configuration structure.
*
* \return
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_BAD_PARAM
*
* \funcusage
* \snippet smif/snippet/main.c snippet_Cy_SMIF_Encrypt
*
*
*******************************************************************************/

cy_en_smif_status_t Cy_SMIF_SetCryptoKeyRegion(SMIF_Type *base,
                                               uint8_t crypto_region_index,
                                               cy_stc_smif_crypto_region_config_t *region_config)
{
    if ((base == NULL) || (region_config == NULL))
    {
        return CY_SMIF_BAD_PARAM;
    }

    if (crypto_region_index >= SMIF0_CRYPTO_KEY_NR)
    {
        return CY_SMIF_BAD_PARAM;
    }


    SMIF_CRYPTO_IDX_INPUT0(base, crypto_region_index) = region_config->iv[0];
    SMIF_CRYPTO_IDX_INPUT1(base, crypto_region_index) = region_config->iv[1];
    SMIF_CRYPTO_IDX_INPUT2(base, crypto_region_index) = region_config->iv[2];
    SMIF_CRYPTO_IDX_INPUT3(base, crypto_region_index) = region_config->iv[3];

    SMIF_CRYPTO_IDX_KEY0(base, crypto_region_index) = region_config->key[0];
    SMIF_CRYPTO_IDX_KEY1(base, crypto_region_index) = region_config->key[1];
    SMIF_CRYPTO_IDX_KEY2(base, crypto_region_index) = region_config->key[2];
    SMIF_CRYPTO_IDX_KEY3(base, crypto_region_index) = region_config->key[3];

    SMIF_CRYPTO_IDX_ADDR(base, crypto_region_index) = (uint32_t)region_config->region_base_address;
    SMIF_CRYPTO_IDX_MASK(base, crypto_region_index) = (SMIF_DEVICE_MASK_MASK_Msk & (~(region_config->region_size) + 1UL));

    return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SMIF_SetCryptoSubRegionDisable
****************************************************************************//**
*
* Disable sub regions within crypto region. Each crypto region is further divided
* into 8 equal sub regions and user can disable on the fly encryption/decryption by
* setting "1" for that specific region using mask. For example, if a 1 MB region is
* specified for a crypto region then the 8 subregions will be 128 KB.
* If mask is set with "0" then cryptography will be performed on that subregion
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param crypto_region_index
* Crypto region index for which sub region disable mask has to be applied.
*
* \param mask
* 8-bit mask to disable individual sub-region within a crypto region
*
* \return \ref cy_en_smif_status_t.
*
*******************************************************************************/

cy_en_smif_status_t Cy_SMIF_SetCryptoSubRegionDisable(SMIF_Type *base,
                                                      uint8_t crypto_region_index,        /* Indexes can be upto 8 based on target platform */
                                                      uint8_t mask)
{
    if (base == NULL)
    {
        return CY_SMIF_BAD_PARAM;
    }

    if (crypto_region_index >= SMIF0_CRYPTO_KEY_NR)
    {
        return CY_SMIF_BAD_PARAM;
    }

    SMIF_CRYPTO_IDX_SUBREGION(base, crypto_region_index) = mask;

    return CY_SMIF_SUCCESS;
}
 /*******************************************************************************
* Function Name: Cy_SMIF_Encrypt()
****************************************************************************//**
*
* Uses the Encryption engine to create an encrypted result when the input, key
* and data arrays are provided. The AES-128 encryption of the address with the
* key, fetching the result and XOR with the data array are all done in the
* function. The operational scheme is the following:
*                   data = XOR(AES128(address, key), data)
* Decryption is done using the input data-array identically to the encryption.
* In the XIP mode, encryption and decryption are done without calling this
* function. The operational scheme in the XIP mode is the same. The address
* parameter in the XIP mode equals the actual address in the PSoC memory map.
* The SMIF encryption engine is designed for code storage.
* For data storage, the encryption key can be changed.
* For sensitive data, the Crypto block is used.
*
* \note The API does not have access to the encryption key. The key must be
* placed in the register using \ref Cy_SMIF_SetCryptoKey() before calling this API.
* The crypto routine that can access the key storage area is recommended.
* This crypto routine is typically a protection context 0 function.
*
* \note This is a blocking API. The API waits for encryption completion. Will
* exit if a timeout is set (not equal to 0) and expired.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param address
* The address that gets encrypted is a masked 16-byte block address. The 32-bit
* address with the last 4 bits masked is placed as the last 4 bytes in the
* 128-bit input. The rest of the higher bit for the 128 bits are padded zeros by default.
* PA[127:0]:
* PA[3:0] = 0
* PA[7:4] = ADDR[7:4].
* PA[15:8] = ADDR[15:8].
* PA[23:16] = ADDR[23:16].
* PA[31:24] = ADDR[31:24].
* The other twelve of the sixteen plain text address bytes of PA[127:0] are "0" by default.
* User can initialize PA[127:32] with \ref Cy_SMIF_SetCryptoIV().
*
* \param data
* This is the location where the input data-array is passed while the function
* is called. This array gets populated with the result after encryption is
* completed.
*
* \param size
* Provides a size of the array.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return A status of the command transmit.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_EXCEED_TIMEOUT
*       - \ref CY_SMIF_BAD_PARAM
*
* \funcusage
* \snippet smif/snippet/main.c snippet_Cy_SMIF_Encrypt
*
*******************************************************************************/
cy_en_smif_status_t  Cy_SMIF_Encrypt(SMIF_Type *base,
                                        uint32_t address,
                                        uint8_t data[],
                                        uint32_t size,
                                        cy_stc_smif_context_t const *context)
{
    uint32_t bufIndex;
    cy_en_smif_status_t status = CY_SMIF_BAD_PARAM;
    uint32_t timeoutUnits = context->timeout;

    CY_ASSERT_L2(size > 0U);

    if((NULL != data) && ((address & (~CY_SMIF_CRYPTO_ADDR_MASK)) == 0UL) )
    {
        status = CY_SMIF_SUCCESS;
        /* Fill the output array */
        for(bufIndex = 0U; bufIndex < (size / CY_SMIF_AES128_BYTES); bufIndex++)
        {
            uint32_t dataIndex = bufIndex * CY_SMIF_AES128_BYTES;
            uint8_t  cryptoOut[CY_SMIF_AES128_BYTES];
            uint32_t  outIndex;

            /* Fill the input field */
            SMIF_CRYPTO_INPUT0(base) = (uint32_t) (address +
                ((bufIndex * CY_SMIF_AES128_BYTES) & CY_SMIF_CRYPTO_ADDR_MASK));

            /* Start the encryption */
            SMIF_CRYPTO_CMD(base) &= ~SMIF_CRYPTO_CMD_START_Msk;
            SMIF_CRYPTO_CMD(base) = (uint32_t)(_VAL2FLD(SMIF_CRYPTO_CMD_START,
                                                    CY_SMIF_CRYPTO_START));

            while((CY_SMIF_CRYPTO_COMPLETED != _FLD2VAL(SMIF_CRYPTO_CMD_START,
                                                    SMIF_CRYPTO_CMD(base))) &&
                                                    (CY_SMIF_EXCEED_TIMEOUT != status))
            {
                /* Wait until the encryption is completed and check the
                * timeout
                */
                status = Cy_SMIF_TimeoutRun(&timeoutUnits);
            }

            if (CY_SMIF_EXCEED_TIMEOUT == status)
            {
                break;
            }

            Cy_SMIF_UnPackByteArray(SMIF_CRYPTO_OUTPUT0(base),
                                &cryptoOut[CY_SMIF_CRYPTO_FIRST_WORD] , true);
            Cy_SMIF_UnPackByteArray(SMIF_CRYPTO_OUTPUT1(base),
                                &cryptoOut[CY_SMIF_CRYPTO_SECOND_WORD], true);
            Cy_SMIF_UnPackByteArray(SMIF_CRYPTO_OUTPUT2(base),
                                &cryptoOut[CY_SMIF_CRYPTO_THIRD_WORD] , true);
            Cy_SMIF_UnPackByteArray(SMIF_CRYPTO_OUTPUT3(base),
                                &cryptoOut[CY_SMIF_CRYPTO_FOURTH_WORD], true);

            for(outIndex = 0U; outIndex < CY_SMIF_AES128_BYTES; outIndex++)
            {
                data[dataIndex + outIndex] ^= cryptoOut[outIndex];
            }
        }
    }
    return (status);
}


/*******************************************************************************
* Function Name: Cy_SMIF_CacheEnable
****************************************************************************//**
*
* This function is used to enable the fast cache, the slow cache or both.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param cacheType
* Holds the type of the cache to be modified. \ref cy_en_smif_cache_t
*
* \return A status of function completion.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_CacheEnable(SMIF_Type *base,
                                        cy_en_smif_cache_t cacheType)
{
    cy_en_smif_status_t status = CY_SMIF_SUCCESS;
    switch (cacheType)
    {
        case CY_SMIF_CACHE_SLOW:
            SMIF_SLOW_CA_CTL(base) |= SMIF_SLOW_CA_CTL_ENABLED_Msk;
            break;
        case CY_SMIF_CACHE_FAST:
            SMIF_FAST_CA_CTL(base) |= SMIF_FAST_CA_CTL_ENABLED_Msk;
            break;
        case CY_SMIF_CACHE_BOTH:
            SMIF_SLOW_CA_CTL(base) |= SMIF_SLOW_CA_CTL_ENABLED_Msk;
            SMIF_FAST_CA_CTL(base) |= SMIF_FAST_CA_CTL_ENABLED_Msk;
            break;
        default:
            /* A user error */
            status = CY_SMIF_BAD_PARAM;
            break;
    }
    return (status);
}


/*******************************************************************************
* Function Name: Cy_SMIF_CacheDisable
****************************************************************************//**
*
* This function is used to disable the fast cache, the slow cache or both
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param cacheType
* Holds the type of the cache to be modified. \ref cy_en_smif_cache_t
*
* \return A status of function completion.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_CacheDisable(SMIF_Type *base,
                                            cy_en_smif_cache_t cacheType)
{
    cy_en_smif_status_t status = CY_SMIF_SUCCESS;
    switch (cacheType)
    {
        case CY_SMIF_CACHE_SLOW:
            SMIF_SLOW_CA_CTL(base) &= ~SMIF_SLOW_CA_CTL_ENABLED_Msk;
            break;
        case CY_SMIF_CACHE_FAST:
            SMIF_FAST_CA_CTL(base) &= ~SMIF_FAST_CA_CTL_ENABLED_Msk;
            break;
        case CY_SMIF_CACHE_BOTH:
            SMIF_SLOW_CA_CTL(base) &= ~SMIF_SLOW_CA_CTL_ENABLED_Msk;
            SMIF_FAST_CA_CTL(base) &= ~SMIF_FAST_CA_CTL_ENABLED_Msk;
            break;
        default:
            /* User error */
            status = CY_SMIF_BAD_PARAM;
            break;
    }
    return (status);
}


/*******************************************************************************
* Function Name: Cy_SMIF_CachePrefetchingEnable
****************************************************************************//**
*
* This function is used to enable pre-fetching for the fast cache, the slow
* cache or both.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param cacheType
* Holds the type of the cache to be modified. \ref cy_en_smif_cache_t
*
* \return A status of function completion.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_CachePrefetchingEnable(SMIF_Type *base,
                                                    cy_en_smif_cache_t cacheType)
{
    cy_en_smif_status_t status = CY_SMIF_SUCCESS;
    switch (cacheType)
    {
        case CY_SMIF_CACHE_SLOW:
            SMIF_SLOW_CA_CTL(base) |= SMIF_SLOW_CA_CTL_PREF_EN_Msk;
            break;
        case CY_SMIF_CACHE_FAST:
            SMIF_FAST_CA_CTL(base) |= SMIF_FAST_CA_CTL_PREF_EN_Msk;
            break;
        case CY_SMIF_CACHE_BOTH:
            SMIF_SLOW_CA_CTL(base) |= SMIF_SLOW_CA_CTL_PREF_EN_Msk;
            SMIF_FAST_CA_CTL(base) |= SMIF_FAST_CA_CTL_PREF_EN_Msk;
            break;
        default:
            /* A user error */
            status = CY_SMIF_BAD_PARAM;
            break;
    }
    return (status);
}


/*******************************************************************************
* Function Name: Cy_SMIF_CachePrefetchingDisable
****************************************************************************//**
*
* This function is used to disable pre-fetching for the fast cache, the slow
* cache or both
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param cacheType
* Holds the type of the cache to be modified. \ref cy_en_smif_cache_t
*
* \return A status of function completion.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_CachePrefetchingDisable(SMIF_Type *base,
                                                    cy_en_smif_cache_t cacheType)
{
    cy_en_smif_status_t status = CY_SMIF_SUCCESS;
    switch (cacheType)
    {
        case CY_SMIF_CACHE_SLOW:
            SMIF_SLOW_CA_CTL(base) &= ~SMIF_SLOW_CA_CTL_PREF_EN_Msk;
            break;
        case CY_SMIF_CACHE_FAST:
            SMIF_FAST_CA_CTL(base) &= ~SMIF_FAST_CA_CTL_PREF_EN_Msk;
            break;
        case CY_SMIF_CACHE_BOTH:
            SMIF_SLOW_CA_CTL(base) &= ~SMIF_SLOW_CA_CTL_PREF_EN_Msk;
            SMIF_FAST_CA_CTL(base) &= ~SMIF_FAST_CA_CTL_PREF_EN_Msk;
            break;
        default:
            /* A user error */
            status = CY_SMIF_BAD_PARAM;
            break;
    }
    return (status);
}


/*******************************************************************************
* Function Name: Cy_SMIF_CacheInvalidate
****************************************************************************//**
*
* This function is used to invalidate/clear the fast cache, the slow cache or
* both
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param cacheType
* Holds the type of the cache to be modified. \ref cy_en_smif_cache_t
*
* \return A status of function completion.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_BAD_PARAM
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_CacheInvalidate(SMIF_Type *base,
                                            cy_en_smif_cache_t cacheType)
{
    cy_en_smif_status_t status = CY_SMIF_SUCCESS;
    switch (cacheType)
    {
        case CY_SMIF_CACHE_SLOW:
            SMIF_SLOW_CA_CMD(base) |= SMIF_SLOW_CA_CMD_INV_Msk;
            break;
        case CY_SMIF_CACHE_FAST:
            SMIF_FAST_CA_CMD(base) |= SMIF_FAST_CA_CMD_INV_Msk;
            break;
        case CY_SMIF_CACHE_BOTH:
            SMIF_SLOW_CA_CMD(base) |= SMIF_SLOW_CA_CMD_INV_Msk;
            SMIF_FAST_CA_CMD(base) |= SMIF_FAST_CA_CMD_INV_Msk;
            break;
        default:
            /* A user error */
            status = CY_SMIF_BAD_PARAM;
            break;
    }
    return (status);
}

#if (defined (SMIF_BRIDGE_PRESENT) && (SMIF_BRIDGE_PRESENT == 1u))
/*******************************************************************************
 * Function Name: Cy_SMIF_IsBridgeOn
 ****************************************************************************//**
* This function is used to check the bridge enable state.
*
* \param base
* Holds the base address of the SMIF base registers.
*
* \return True if the bridge is active (enabled), false if the bridge is not enabled.
*
*******************************************************************************/
bool Cy_SMIF_IsBridgeOn(SMIF_Base_Type *base)
{
    CY_ASSERT_L1(NULL != base);

    return (_FLD2VAL(SMIF_SMIF_BRIDGE_CTL_ENABLED, SMIF_BRIDGE_CTL(base)) != 0UL);
}

/*******************************************************************************
 * Function Name: Cy_SMIF_Bridge_Enable
 ****************************************************************************//**
* This function is used to enable/disable Bridge
*
* \param base
* Holds the base address of the SMIF base registers.
*
* \param enable
* enable/disable the bridge
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Bridge_Enable(SMIF_Base_Type *base, bool enable)
{
    CY_ASSERT_L1(NULL != base);

    uint32_t prevStatus = Cy_SysLib_EnterCriticalSection();

    /* Confirming all smif core is not busy */
    for(uint32_t smifCoreIdx = 0; smifCoreIdx < CY_SMIF_CORE_COUNT; smifCoreIdx+=1U)
    {
        if(Cy_SMIF_BusyCheck(&(base->CORE[smifCoreIdx])) == true)
        {
            CY_ASSERT_L1(false);
            return CY_SMIF_BUSY;
        }
    }

    /* Set Enable bit of the smif bridge */
    SMIF_BRIDGE_CTL(base) = (enable ?
                (SMIF_BRIDGE_CTL(base) | (SMIF_SMIF_BRIDGE_CTL_ENABLED_Msk)) :
                (SMIF_BRIDGE_CTL(base) & ~(SMIF_SMIF_BRIDGE_CTL_ENABLED_Msk)));

    Cy_SysLib_ExitCriticalSection(prevStatus);

    return CY_SMIF_SUCCESS;
}
#endif /* (SMIF_BRIDGE_PRESENT) && (SMIF_BRIDGE_PRESENT == 1u) */

/*******************************************************************************
* Function Name: Cy_SMIF_SetRxCaptureMode
****************************************************************************//**
* This function sets the Rx Capture mode setting for SMIF IP block instance
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param mode
* Rx Capture mode \ref cy_en_smif_capture_mode_t
*
* \param slaveId
* Slave ID for which RX Capture configuration has to be updated.
*
* \snippet smif/snippet/main.c snippet_SMIF_DLP
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_SetRxCaptureMode(SMIF_Type *base, cy_en_smif_capture_mode_t mode, cy_en_smif_slave_select_t slaveId)
{
    CY_ASSERT_L1(NULL != base);
    uint32_t device_idx;

    /* RX CAPTURE MODE cannot be changed when IP is in enabled state */
    if ((SMIF_CTL(base) & SMIF_CTL_ENABLED_Msk) != 0U)
    {
        return CY_SMIF_BAD_PARAM;
    }
    else
    {
        SMIF_CTL2(base) &= ~SMIF_CORE_CTL2_RX_CAPTURE_MODE_Msk;
        SMIF_CTL2(base) |= _VAL2FLD(SMIF_CORE_CTL2_RX_CAPTURE_MODE, (uint32_t)mode);

        /* For RX Capture MODE 2, DDR_PIPELINE_POS_DAT must be set to 1 */
        if (CY_SMIF_SUCCESS == Cy_SMIF_ConvertSlaveSlotToIndex(slaveId, &device_idx))
        {
            SMIF_DEVICE_IDX_RX_CAPTURE_CONFIG(base, device_idx) |= SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_DDR_PIPELINE_POS_DAT_Msk;
        }

        return CY_SMIF_SUCCESS;
    }
}

#if ((defined (SMIF_DLP_PRESENT) && (SMIF_DLP_PRESENT > 0)) || \
     (defined (SMIF0_DLP_PRESENT) && (SMIF0_DLP_PRESENT > 0)) || \
     (defined (SMIF1_DLP_PRESENT) && (SMIF1_DLP_PRESENT > 0)))
/*******************************************************************************
* Function Name: Cy_SMIF_SetMasterDLP
****************************************************************************//**
* This function sets the data learning pattern
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param dlp
* data learning pattern (maximum 16-bit)
*
* \param size
* pattern size (allowed range 1 to 16 bits)
*
* \return status of configuration.
*       - \ref CY_SMIF_SUCCESS
*       - \ref CY_SMIF_BAD_PARAM
*
* \snippet smif/snippet/main.c snippet_SMIF_DLP
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_SetMasterDLP(SMIF_Type *base, uint16 dlp, uint8_t size)
{
    cy_en_smif_status_t status = CY_SMIF_SUCCESS;

    CY_ASSERT_L1(NULL != base);

    if ((size == 0U) || (size > 16U))
    {
        status = CY_SMIF_BAD_PARAM;
    }

    if ( status == CY_SMIF_SUCCESS)
    {
        /* Clear values before writing user provided inputs */
        SMIF_DLP_CTL(base) = (_VAL2FLD(SMIF_CORE_DLP_CTL_DLP, 0) |
                             _VAL2FLD(SMIF_CORE_DLP_CTL_DLP_SIZE, 0));

        /* Configure user inputs */
        SMIF_DLP_CTL(base) = (_VAL2FLD(SMIF_CORE_DLP_CTL_DLP, dlp) |
                             _VAL2FLD(SMIF_CORE_DLP_CTL_DLP_SIZE, (uint32_t)size - 1UL));
    }
    return status;
}
/*******************************************************************************
* Function Name: Cy_SMIF_GetMasterDLP
****************************************************************************//**
* This function gets the data learning pattern configured.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Data learning pattern configured
*
*
* \snippet smif/snippet/main.c snippet_SMIF_DLP
*
*******************************************************************************/
uint16_t Cy_SMIF_GetMasterDLP(SMIF_Type *base)
{
    return (uint16_t)_FLD2VAL(SMIF_CORE_DLP_CTL_DLP, SMIF_DLP_CTL(base));
}
/*******************************************************************************
* Function Name: Cy_SMIF_GetMasterDLPSize
****************************************************************************//**
* This function gets the data learning pattern size configured.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \return Data learning pattern size configured.
*
* \snippet smif/snippet/main.c snippet_SMIF_DLP
*
*******************************************************************************/
uint8_t Cy_SMIF_GetMasterDLPSize(SMIF_Type *base)
{
    return (uint8_t)(_FLD2VAL(SMIF_CORE_DLP_CTL_DLP_SIZE, SMIF_DLP_CTL(base)) + 1U);
}
/*******************************************************************************
* Function Name: Cy_SMIF_GetTapNumCapturedCorrectDLP
****************************************************************************//**
* This function gets number of delay taps used for specified data line.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param bit
* DLP Tap selection for the bit position mapped as per \ref Cy_SMIF_SetDataSelect.
*
* \return Data learning pattern configured
*
* \snippet smif/snippet/main.c snippet_Cy_SMIF_GetTapNumCapturedCorrectDLP
*
*******************************************************************************/
uint8_t Cy_SMIF_GetTapNumCapturedCorrectDLP(SMIF_Type *base, uint8_t bit)
{
    uint32_t delay_tap = 0;

    switch(bit)
    {
        case 0:
        {
           delay_tap = _FLD2VAL(SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT0_TAP_SEL, SMIF_DLP_DELAY_TAP_SEL0(base));
        }
        break;
        case 1:
        {
           delay_tap = _FLD2VAL(SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT1_TAP_SEL, SMIF_DLP_DELAY_TAP_SEL0(base));
        }
        break;
        case 2:
        {
           delay_tap = _FLD2VAL(SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT2_TAP_SEL, SMIF_DLP_DELAY_TAP_SEL0(base));
        }
        break;
        case 3:
        {
           delay_tap = _FLD2VAL(SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT3_TAP_SEL, SMIF_DLP_DELAY_TAP_SEL0(base));
        }
        break;
        case 4:
        {
           delay_tap = _FLD2VAL(SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT4_TAP_SEL, SMIF_DLP_DELAY_TAP_SEL1(base));
        }
        break;
        case 5:
        {
           delay_tap = _FLD2VAL(SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT5_TAP_SEL, SMIF_DLP_DELAY_TAP_SEL1(base));
        }
        break;
        case 6:
        {
           delay_tap = _FLD2VAL(SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT6_TAP_SEL, SMIF_DLP_DELAY_TAP_SEL1(base));
        }
        break;
        case 7:
        {
           delay_tap = _FLD2VAL(SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT7_TAP_SEL, SMIF_DLP_DELAY_TAP_SEL1(base));
        }
        break;
        default:
             delay_tap = 0;
             break;
    }
    return  (uint8_t)delay_tap;
}
#endif  /* ((defined (SMIF_DLP_PRESENT) && (SMIF_DLP_PRESENT > 0)) ||
      (defined (SMIF0_DLP_PRESENT) && (SMIF0_DLP_PRESENT > 0)) ||
      (defined (SMIF1_DLP_PRESENT) && (SMIF1_DLP_PRESENT > 0)) */

/*******************************************************************************
* Function Name: Cy_SMIF_DeviceTransfer_SetMergeTimeout
****************************************************************************//**
*
* This function enables merging continuous transfers over XIP so that the overhead
* of transferring command and address will not be there for reading consecutive addresses.
* User can specify a timeout value to specify how long the device would be selected waiting
* for next incremental address read.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slave
* Holds the slave select line for which merge should be enabled.
*
* \param timeout (see \ref cy_en_smif_merge_timeout_t)
*
* \note External memory should also support this mode of transfer.
*
* \snippet smif/snippet/main.c snippet_Cy_SMIF_MergeTimeout
*******************************************************************************/
void Cy_SMIF_DeviceTransfer_SetMergeTimeout(SMIF_Type *base, cy_en_smif_slave_select_t slave, cy_en_smif_merge_timeout_t timeout)
{
    SMIF_DEVICE_Type volatile * device = Cy_SMIF_GetDeviceBySlot(base, slave);
    if (NULL != device)
    {
        uint32_t temp;
        temp = SMIF_DEVICE_CTL(device);
        temp &= ~(SMIF_DEVICE_CTL_MERGE_TIMEOUT_Msk);
        SMIF_DEVICE_CTL(device) = temp | _VAL2FLD(SMIF_DEVICE_CTL_MERGE_EN,  1U)  |
                              _VAL2FLD(SMIF_DEVICE_CTL_MERGE_TIMEOUT,  (uint32_t)timeout);
    }
}

/*******************************************************************************
* Function Name: Cy_SMIF_DeviceTransfer_ClearMergeTimeout
****************************************************************************//**
*
* This function disables continuous transfer merging.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slave
* Holds the slave select line for which merge should be disabled.
*
* \note External memory should also support this mode of transfer.
*
* \snippet smif/snippet/main.c snippet_Cy_SMIF_MergeTimeout
*******************************************************************************/
void Cy_SMIF_DeviceTransfer_ClearMergeTimeout(SMIF_Type *base, cy_en_smif_slave_select_t slave)
{
    SMIF_DEVICE_Type volatile * device = Cy_SMIF_GetDeviceBySlot(base, slave);
    if (NULL != device)
    {
        uint32_t temp;
        temp = SMIF_DEVICE_CTL(device);
        temp &= ~(SMIF_DEVICE_CTL_MERGE_EN_Msk | SMIF_DEVICE_CTL_MERGE_TIMEOUT_Msk);
        SMIF_DEVICE_CTL(device) = temp;
    }
}

#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
/*******************************************************************************
* Function Name: Cy_SMIF_DeepSleepCallback
****************************************************************************//**
*
* This function handles the transition of the SMIF into and out of Deep
* Sleep mode. It prevents the device from entering DeepSleep if SMIF is actively
* communicating, or there is any data in the TX or RX FIFOs, or SMIF is in
* memory mode.
*
* This function should be called while execution of \ref Cy_SysPm_CpuEnterDeepSleep
* therefore must be registered as a callback before the call. To register it
* call \ref Cy_SysPm_RegisterCallback and specify \ref CY_SYSPM_DEEPSLEEP
* as the callback type.
*
* \note
* This API is template and user should add code for external memory enter/exit
* low power mode.
*
* \param callbackParams
* The pointer to the structure with SMIF SysPm callback parameters (pointer to
* SMIF registers, context and call mode \ref cy_stc_syspm_callback_params_t).
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return
* \ref cy_en_syspm_status_t
*
* Example setup of SysPM deep sleep and hibernate mode
* \snippet smif/snippet/main.c SMIF SysPM Callback
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SMIF_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{
    cy_en_syspm_status_t retStatus = CY_SYSPM_SUCCESS;

    CY_ASSERT_L1(NULL != callbackParams);

    SMIF_Type *locBase = (SMIF_Type *) callbackParams->base;
    cy_stc_smif_context_t *locContext = (cy_stc_smif_context_t *) callbackParams->context;

    static uint32_t smif_crypto_input1;
    static uint32_t smif_crypto_input2;
    static uint32_t smif_crypto_input3;

    switch(mode)
    {
        case CY_SYSPM_CHECK_READY:
        {
            /* Check if API is not busy executing transfer operation */
            /* If SPI bus is not busy, all data elements are transferred on
                * the bus from the TX FIFO and shifter and the RX FIFOs is
                * empty - the SPI is ready enter Deep Sleep.
            */
            bool checkFail = (CY_SMIF_RX_BUSY == (cy_en_smif_txfr_status_t)
                                    Cy_SMIF_GetTransferStatus(locBase, locContext));
            checkFail = (Cy_SMIF_BusyCheck(locBase)) || checkFail;
            checkFail = (Cy_SMIF_GetMode(locBase) == CY_SMIF_MEMORY) || checkFail;

            if (checkFail)
            {
                retStatus = CY_SYSPM_FAIL;
            }
            else
            {
                 Cy_SMIF_Disable(locBase);
                retStatus = CY_SYSPM_SUCCESS;
            }
            /* Add check memory that memory not in progress */
        }
        break;

        case CY_SYSPM_CHECK_FAIL:
        {
            /* Other driver is not ready for Deep Sleep. Restore Active mode
            * configuration.
            */
            Cy_SMIF_Enable(locBase, locContext);

        }
        break;

        case CY_SYSPM_BEFORE_TRANSITION:
        {
            /* This code executes inside critical section and enabling active
            * interrupt source makes interrupt pending in the NVIC. However
            * interrupt processing is delayed until code exists critical
            * section. The pending interrupt force WFI instruction does
            * nothing and device remains in the active mode.
            */

            /* Put external memory in low power mode */

            /* Save content of crypto registers */
            smif_crypto_input1 = SMIF_CRYPTO_INPUT1(locBase);
            smif_crypto_input2 = SMIF_CRYPTO_INPUT2(locBase);
            smif_crypto_input3 = SMIF_CRYPTO_INPUT3(locBase);
        }
        break;

        case CY_SYSPM_AFTER_TRANSITION:
        {
            /* Restore content of crypto registers */
            SMIF_CRYPTO_INPUT1(locBase) = smif_crypto_input1;
            SMIF_CRYPTO_INPUT2(locBase) = smif_crypto_input2;
            SMIF_CRYPTO_INPUT3(locBase) = smif_crypto_input3;
            /* Zero out copies of the crypto registers */
            smif_crypto_input1 = 0UL;
            smif_crypto_input2 = 0UL;
            smif_crypto_input3 = 0UL;
            /* Put external memory in active mode */
            Cy_SMIF_Enable(locBase, locContext);
        }
        break;

        default:
            retStatus = CY_SYSPM_FAIL;
            break;
    }

    return (retStatus);
}


/*******************************************************************************
* Function Name: Cy_SMIF_HibernateCallback
****************************************************************************//**
*
* This function handles the transition of the SMIF into Hibernate mode.
* It prevents the device from entering Hibernate if the SMIF
* is actively communicating, or there is any data in the TX or RX FIFO, or SMIF
* is in memory mode.
*
* This function should be called during execution of \ref Cy_SysPm_SystemEnterHibernate
* therefore it must be registered as a callback before the call. To register it
* call \ref Cy_SysPm_RegisterCallback and specify \ref CY_SYSPM_HIBERNATE
* as the callback type.
*
* \note
* This API is template and user should add code for external memory enter/exit
* low power mode.
*
* \param callbackParams
* The pointer to the structure with SMIF SysPm callback parameters (pointer to
* SMIF registers, context and call mode \ref cy_stc_syspm_callback_params_t).
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return
* \ref cy_en_syspm_status_t
*
* Example setup of SysPM deep sleep and hibernate mode
* \snippet smif/snippet/main.c SMIF SysPM Callback
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SMIF_HibernateCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{
    cy_en_syspm_status_t retStatus = CY_SYSPM_SUCCESS;

    CY_ASSERT_L1(NULL != callbackParams);

    SMIF_Type *locBase = (SMIF_Type *) callbackParams->base;
    cy_stc_smif_context_t *locContext = (cy_stc_smif_context_t *) callbackParams->context;

    switch(mode)
    {
        case CY_SYSPM_CHECK_READY:
        {
            /* Check if API is not busy executing transfer operation
            * If SPI bus is not busy, all data elements are transferred on
            * the bus from the TX FIFO and shifter and the RX FIFOs is
            * empty - the SPI is ready enter Deep Sleep.
            */
            bool checkFail = (CY_SMIF_RX_BUSY == (cy_en_smif_txfr_status_t)
                                Cy_SMIF_GetTransferStatus(locBase, locContext));
            checkFail = (Cy_SMIF_BusyCheck(locBase)) || checkFail;
            checkFail = (Cy_SMIF_GetMode(locBase) == CY_SMIF_MEMORY) || checkFail;

            if (checkFail)
            {
                retStatus = CY_SYSPM_FAIL;

            }
            else
            {
                retStatus = CY_SYSPM_SUCCESS;
                Cy_SMIF_Disable(locBase);
            }
            /* Add check memory that memory not in progress */
        }
        break;

        case CY_SYSPM_CHECK_FAIL:
        {
            /* Other driver is not ready for Deep Sleep. Restore Active mode
            * configuration.
            */
            Cy_SMIF_Enable(locBase, locContext);

        }
        break;

        case CY_SYSPM_BEFORE_TRANSITION:
        {
            /* Put external memory in low power mode */
        }
        break;

        case CY_SYSPM_AFTER_TRANSITION:
        {

            Cy_SMIF_Enable(locBase, locContext);
            /* Put external memory in active mode */

        }
        break;

        default:
            retStatus = CY_SYSPM_FAIL;
        break;
    }

    return (retStatus);
}


/*******************************************************************************
* Function Name: Cy_SMIF_Set_DelayTapSel
****************************************************************************//**
*
* This function sets delay tap number for the SMIF master clock which is common
* for all memory devices connected.
*
* \param base
* Holds the base address of the SMIF block or SMIF_DEVICE block registers.
*
* \param tapSel
* delay tap selection to be set
*
* \return status (see \ref cy_en_smif_status_t).
*
* \snippet smif/snippet/main.c snippet_Cy_SMIF_Set_DelayTapSel
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Set_DelayTapSel(SMIF_Type *base, uint8_t tapSel)
{
    if(tapSel > (SMIF_DELAY_TAPS_NR - 1U))
    {
      return CY_SMIF_BAD_PARAM;
    }

    SMIF_CTL2(base) &= ~SMIF_CORE_CTL2_MDL_TAP_SEL_Msk;
    SMIF_CTL2(base) |= _VAL2FLD(SMIF_CORE_CTL2_MDL_TAP_SEL, tapSel);

    return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SMIF_Get_DelayTapSel
****************************************************************************//**
*
* This function returns delay tap number which has been set for the SMIF.
*
* \param base
* Holds the base address of the SMIF block or SMIF_DEVICE block registers.
*
* \return read tap selection
*
* \snippet smif/snippet/main.c snippet_Cy_SMIF_Set_DelayTapSel
*******************************************************************************/
uint8_t Cy_SMIF_Get_DelayTapSel(SMIF_Type *base)
{
    return (uint8_t)(_FLD2VAL(SMIF_CORE_CTL2_MDL_TAP_SEL, SMIF_CTL2(base)));
}

/*******************************************************************************
* Function Name: Cy_SMIF_InitCache
****************************************************************************//**
*
* This function initializes SMIF internal CACHE with user provided configuration \ref cy_stc_smif_cache_config_t.
*
* \param base
* Holds the base address of the SMIF block.
*
* \param cache_config
* Contains the configuration information to configure SMIF internal Cache.
*
* \return Returns result of CACHE configuration.
*
* \snippet smif/snippet/main.c snippet_Cy_SMIF_InitCache
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_InitCache(SMIF_CACHE_BLOCK_Type *base, const cy_stc_smif_cache_config_t *cache_config)
{

    if ((base == NULL) || (cache_config == NULL))
    {
        return CY_SMIF_BAD_PARAM;
    }

#if defined (COMPONENT_SECURE_DEVICE)
    cy_en_smif_status_t result = CY_SMIF_SUCCESS;

    volatile uint32_t *region_base_address = &(base->MMIO.REGION0_BASE);

    if(cache_config->cache_region_0.enabled)
    {
        if ((cache_config->cache_region_0.start_address % CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES == 0U) && (cache_config->cache_region_0.end_address % CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES == 0U))
        {
            *(region_base_address++) = cache_config->cache_region_0.start_address;
            *(region_base_address++) = (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ENABLE, 1U) |
                                                  _VAL2FLD(SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ATTR, (uint32_t)cache_config->cache_region_0.cache_attributes) |
                                                  cache_config->cache_region_0.end_address);
        }
        else
        {
            result = CY_SMIF_BAD_PARAM;
        }
    }
    if(cache_config->cache_region_1.enabled)
    {
        region_base_address = &(base->MMIO.REGION1_BASE);
        if ((cache_config->cache_region_1.start_address % CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES == 0U) && (cache_config->cache_region_1.end_address % CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES == 0U))
        {
            *(region_base_address++) = cache_config->cache_region_1.start_address;
            *(region_base_address++) = (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ENABLE, 1U) |
                                                  _VAL2FLD(SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ATTR, (uint32_t)cache_config->cache_region_1.cache_attributes) |
                                                  cache_config->cache_region_1.end_address);
        }
        else
        {
            result = CY_SMIF_BAD_PARAM;
        }
    }
    if(cache_config->cache_region_2.enabled)
    {
        region_base_address = &(base->MMIO.REGION2_BASE);
        if ((cache_config->cache_region_2.start_address % CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES == 0U) && (cache_config->cache_region_2.end_address % CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES == 0U))
        {
            *(region_base_address++) = cache_config->cache_region_2.start_address;
            *(region_base_address++) = (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ENABLE, 1U) |
                                                  _VAL2FLD(SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ATTR, (uint32_t)cache_config->cache_region_2.cache_attributes) |
                                                  cache_config->cache_region_2.end_address);
        }
        else
        {
            result = CY_SMIF_BAD_PARAM;
        }
    }

    if(cache_config->cache_region_3.enabled)
    {
        region_base_address = &(base->MMIO.REGION3_BASE);
        if ((cache_config->cache_region_3.start_address % CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES == 0U) && (cache_config->cache_region_3.end_address % CY_SMIF_CACHE_SUB_REGION_ALIGN_IN_BYTES == 0U))
        {
            *(region_base_address++) = cache_config->cache_region_3.start_address;
            *(region_base_address++) = (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ENABLE, 1U) |
                                                  _VAL2FLD(SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ATTR, (uint32_t)cache_config->cache_region_3.cache_attributes) |
                                                  cache_config->cache_region_3.end_address);
        }
        else
        {
            result = CY_SMIF_BAD_PARAM;
        }
    }

    if (result != CY_SMIF_BAD_PARAM)
    {
         base->CTRL =  (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_CTRL_ENABLE, cache_config->enabled) |
                             _VAL2FLD(SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_ENABLE_READ, 1U) |
                             _VAL2FLD(SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_MAINT_LINES, 1U) |
                             _VAL2FLD(SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_NSECSTAT, 1U));

        base->MMIO.MMIO_CACHE_RET_EN = (uint32_t)cache_config->cache_retention_on;
    }
    return result;
#else
   return CY_SMIF_BAD_PARAM;
#endif
}
/*******************************************************************************
* Function Name: Cy_SMIF_Clean_All_Cache
****************************************************************************//**
*
* This function cleans complete SMIF internal CACHE. This is a blocking call and
* returns with the status of CACHE clean operation.
*
* \param base
* Holds the base address of the SMIF block.
*
* \return Returns result of CACHE clean operation.
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Clean_All_Cache(SMIF_CACHE_BLOCK_Type *base)
{
    if (base == NULL)
    {
        return CY_SMIF_BAD_PARAM;
    }

#if defined (COMPONENT_SECURE_DEVICE)
    base->MAINT_CTRL_ALL =  (uint32_t)_VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_ALL_TRIG_CLEAN_ALL, 1U);

    /* Wait for Maintenance flag to be CLEARED */
    while (((base->MAINT_STATUS) & SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_MAINT_Msk) == SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_MAINT_Msk) {}

    return CY_SMIF_SUCCESS;
#else
   return CY_SMIF_BAD_PARAM;
#endif
}
/*******************************************************************************
* Function Name: Cy_SMIF_Invalidate_All_Cache
****************************************************************************//**
* This function invalidates complete SMIF internal CACHE. This is a blocking call and
* returns with the status of CACHE invalidate operation.
*
* \param base
* Holds the base address of the SMIF block.
*
* \return Returns result of CACHE invalidate operation.
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Invalidate_All_Cache(SMIF_CACHE_BLOCK_Type *base)
{
    if (base == NULL)
    {
        return CY_SMIF_BAD_PARAM;
    }

#if defined (COMPONENT_SECURE_DEVICE)
    base->MAINT_CTRL_ALL =  (uint32_t)_VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_ALL_TRIG_INVALIDATE_ALL, 1U);

    /* Wait for Maintenance flag to be CLEARED */
    while (((base->MAINT_STATUS) & SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_MAINT_Msk) == SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_MAINT_Msk) {}

    return CY_SMIF_SUCCESS;
#else
   return CY_SMIF_BAD_PARAM;
#endif
}
/*******************************************************************************
* Function Name: Cy_SMIF_Clean_And_Invalidate_All_Cache
****************************************************************************//**
*
* This function cleans and invalidates complete SMIF internal CACHE. This is a blocking call and
* returns with the status of CACHE invalidate and clean operation.
*
* \param base
* Holds the base address of the SMIF block.
*
* \return Returns result of CACHE clean and invalidate operation.
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Clean_And_Invalidate_All_Cache(SMIF_CACHE_BLOCK_Type *base)
{
    if (base == NULL)
    {
        return CY_SMIF_BAD_PARAM;
    }

#if defined (COMPONENT_SECURE_DEVICE)
    base->MAINT_CTRL_ALL =  (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_ALL_TRIG_INVALIDATE_ALL, 1U) |
                                        _VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_ALL_TRIG_CLEAN_ALL, 1U));

    /* Wait for Maintenance flag to be CLEARED */
    while (((base->MAINT_STATUS) & SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_MAINT_Msk) == SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_MAINT_Msk) {}

    return CY_SMIF_SUCCESS;
#else
   return CY_SMIF_BAD_PARAM;
#endif
}

/*******************************************************************************
* Function Name: Cy_SMIF_Clean_Cache_by_Addr
****************************************************************************//**
*
* This function cleans cache using the address and size specified by user.
* This is a blocking call and returns with the status of CACHE clean operation.
* Size must be specified in multiples of CACHE line size (32 bytes).
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that the address is DCache aligned when calling from a non-secured
* Core onto a secured hardware resource.  This is only relevent for cross-core calls,
* not calls between security contexts on the same core.
*
* \param base
* Holds the base address of the SMIF block.
*
* \param is_secure_view
* Specifies the view on which cache operation has to be performed. In non-secure world
* this parameter is ignored and defaulted to non-secure view cache operation.
*
* \param address
* start address from which cache operation should be performed.
*
* \param size
* size in multiples of CACHE line size \ref CY_SMIF_CACHE_LINE_SIZE_IN_BYTES.
*
* \return Returns result of CACHE clean operation.
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Clean_Cache_by_Addr(SMIF_CACHE_BLOCK_Type *base, bool is_secure_view, uint32_t address, uint32_t size)
{

    if ( (base == NULL) || ((address % CY_SMIF_CACHE_LINE_SIZE_IN_BYTES) != 0U) || ((size % CY_SMIF_CACHE_LINE_SIZE_IN_BYTES) != 0U))
    {
        return CY_SMIF_BAD_PARAM;
    }

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    CY_UNUSED_PARAM(is_secure_view);
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_smif_srf_clean_cache_in_t input_args;
    cy_pdl_smif_srf_status_out_t output_args;
    input_args.address = address;
    input_args.size = size;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    void* invec_bases[] = {(void *)address, NULL};
    size_t invec_sizes[] = {size, 0};

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SMIF_OP_CLEAN_CACHE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .base = base,
        .sub_block = ((base == SMIF0_CACHE_BLOCK) ? CY_SMIF_SUB_BLOCK_0: CY_SMIF_SUB_BLOCK_1),
        .input_base = (uint8_t*)&input_args,
        .input_len = sizeof(input_args),
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = invec_bases,
        .invec_sizes = invec_sizes,
        .outvec_bases = NULL,
        .outvec_sizes = NULL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
    {
        (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        return CY_SMIF_SECURITY_POLICY_VIOLATION;
    }
    else
    {
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    }
    memcpy(&output_args, (cy_rslt_t*)(&(output->output_values[0])), sizeof(output_args));
    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.op_res;
#else
    while (size != 0U)
    {
         base->MAINT_CTRL_LINES =  (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_TRIG_CLEAN, 1U) |
                                        _VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_SECURITY, (uint8_t)is_secure_view) |
                                        _VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_SECURITY, (uint8_t)address));
        address += CY_SMIF_CACHE_LINE_SIZE_IN_BYTES;
        size -= CY_SMIF_CACHE_LINE_SIZE_IN_BYTES;
    }
    return CY_SMIF_SUCCESS;
#endif
}
/*******************************************************************************
* Function Name: Cy_SMIF_Invalidate_Cache_by_Addr
****************************************************************************//**
*
* This function invalidates cache using the address and size specified by user.
* This is a blocking call and returns with the status of CACHE invalidate operation.
* Size must be specified in multiples of CACHE line size (32 bytes).
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that the address is DCache aligned when calling from a non-secured
* Core onto a secured hardware resource.  This is only relevent for cross-core calls,
* not calls between security contexts on the same core.
*
* \param base
* Holds the base address of the SMIF block.
*
* \param is_secure_view
* Specifies the view on which cache operation has to be performed. In non-secure world
* this parameter is ignored and defaulted to non-secure view cache operation.
*
* \param address
* start address from which cache operation should be performed.
*
* \param size
* size in multiples of CACHE line size \ref CY_SMIF_CACHE_LINE_SIZE_IN_BYTES.
*
* \return Returns result of CACHE invalidate operation.
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Invalidate_Cache_by_Addr(SMIF_CACHE_BLOCK_Type *base, bool is_secure_view, uint32_t address, uint32_t size)
{
    if ( (base == NULL) || ((address % CY_SMIF_CACHE_LINE_SIZE_IN_BYTES) != 0U) || ((size % CY_SMIF_CACHE_LINE_SIZE_IN_BYTES) != 0U))
    {
        return CY_SMIF_BAD_PARAM;
    }

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    CY_UNUSED_PARAM(is_secure_view);
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_smif_srf_invalidate_cache_in_t input_args;
    cy_pdl_smif_srf_status_out_t output_args;
    input_args.address = address;
    input_args.size = size;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    void* invec_bases[] = {(void *)address, NULL};
    size_t invec_sizes[] = {size, 0};

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SMIF_OP_INVALIDATE_CACHE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .base = base,
        .sub_block = ((base == SMIF0_CACHE_BLOCK) ? CY_SMIF_SUB_BLOCK_0: CY_SMIF_SUB_BLOCK_1),
        .input_base = (uint8_t*)&input_args,
        .input_len = sizeof(input_args),
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = invec_bases,
        .invec_sizes = invec_sizes,
        .outvec_bases = NULL,
        .outvec_sizes = NULL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
    {
        (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        return CY_SMIF_SECURITY_POLICY_VIOLATION;
    }
    else
    {
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    }
    memcpy(&output_args, (cy_rslt_t*)(&(output->output_values[0])), sizeof(output_args));
    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.op_res;
#else
    while (size != 0U)
    {
         base->MAINT_CTRL_LINES =  (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_TRIG_INVALIDATE, 1U) |
                                        _VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_SECURITY, (uint8_t)is_secure_view) |
                                        _VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_SECURITY, (uint8_t)address));
        address += CY_SMIF_CACHE_LINE_SIZE_IN_BYTES;
        size -= CY_SMIF_CACHE_LINE_SIZE_IN_BYTES;
    }
    return CY_SMIF_SUCCESS;
#endif
}
/*******************************************************************************
* Function Name: Cy_SMIF_Clean_And_Invalidate_Cache_by_Addr
****************************************************************************//**
*
* This function cleans and invalidates cache using the address and size specified by user.
* This is a blocking call and returns with the status of CACHE operation.
* Size must be specified in multiples of CACHE line size (32 bytes).
*
* \note This API is Secure Aware.  On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC regions are SMIF<inst>_CORE_MAIN, SMIF<inst>_CORE_CRYPTO,
* SMIF<inst>_CORE_MAIN2, and SMIF<inst>_CORE_DEVICE.  These four regions must have
* the same security state.
*
* \note Ensure that the address is DCache aligned when calling from a non-secured
* Core onto a secured hardware resource.  This is only relevent for cross-core calls,
* not calls between security contexts on the same core.
*
* \param base
* Holds the base address of the SMIF block.
*
* \param is_secure_view
* Specifies the view on which cache operation has to be performed. In non-secure world
* this parameter is ignored and defaulted to non-secure view cache operation.
*
* \param address
* start address from which cache operation should be performed.
*
* \param size
* size in multiples of CACHE line size \ref CY_SMIF_CACHE_LINE_SIZE_IN_BYTES.
*
* \return Returns result of CACHE operation.
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_Clean_And_Invalidate_Cache_by_Addr(SMIF_CACHE_BLOCK_Type *base, bool is_secure_view, uint32_t address, uint32_t size)
{

    if ( (base == NULL) || ((address % CY_SMIF_CACHE_LINE_SIZE_IN_BYTES) != 0U) || ((size % CY_SMIF_CACHE_LINE_SIZE_IN_BYTES) != 0U))
    {
        return CY_SMIF_BAD_PARAM;
    }

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    CY_UNUSED_PARAM(is_secure_view);
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_smif_srf_cl_inv_cache_in_t input_args;
    cy_pdl_smif_srf_status_out_t output_args;
    input_args.address = address;
    input_args.size = size;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    void* invec_bases[] = {(void *)address, NULL};
    size_t invec_sizes[] = {size, 0};

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SMIF_OP_CL_INV_CACHE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .base = base,
        .sub_block = ((base == SMIF0_CACHE_BLOCK) ? CY_SMIF_SUB_BLOCK_0: CY_SMIF_SUB_BLOCK_1),
        .input_base = (uint8_t*)&input_args,
        .input_len = sizeof(input_args),
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = invec_bases,
        .invec_sizes = invec_sizes,
        .outvec_bases = NULL,
        .outvec_sizes = NULL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
    {
        (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        return CY_SMIF_SECURITY_POLICY_VIOLATION;
    }
    else
    {
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    }
    memcpy(&output_args, (cy_rslt_t*)(&(output->output_values[0])), sizeof(output_args));
    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.op_res;
#else
    while (size != 0U)
    {
         base->MAINT_CTRL_LINES =  (uint32_t)(_VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_TRIG_INVALIDATE, 1U) |
                                              _VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_TRIG_CLEAN, 1U) |
                                              _VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_SECURITY, (uint8_t)is_secure_view) |
                                              _VAL2FLD(SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_SECURITY, (uint8_t)address));
        address += CY_SMIF_CACHE_LINE_SIZE_IN_BYTES;
        size -= CY_SMIF_CACHE_LINE_SIZE_IN_BYTES;
    }
    return CY_SMIF_SUCCESS;
#endif
}
/*******************************************************************************
* Function Name: Cy_SMIF_IsCacheEnabled
****************************************************************************//**
*
* This function checks whether Cache is enabled or not
*
* \param base
* Holds the base address of the SMIF block.
*
* \param cache_status
* Holds the Cache status
*
* \return CY_SMIF_SUCCESS if we are able get the Cache status otherwise returns CY_SMIF_BAD_PARAM.
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_IsCacheEnabled(SMIF_CACHE_BLOCK_Type *base, bool *cache_status)
{
   CY_ASSERT_L1(NULL != base);
   CY_ASSERT_L1(NULL != cache_status);

#if defined (COMPONENT_SECURE_DEVICE)

   *cache_status = (bool)_FLD2VAL(SMIF_CACHE_BLOCK_CTRL_ENABLE, base->CTRL);
   return CY_SMIF_SUCCESS;
#else
   (void)base;
   (void)cache_status;
   return CY_SMIF_BAD_PARAM;
#endif
}


#endif /* defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXSMIF */

/* [] END OF FILE */
