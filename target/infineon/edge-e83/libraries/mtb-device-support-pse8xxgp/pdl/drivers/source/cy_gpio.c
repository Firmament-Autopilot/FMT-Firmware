/***************************************************************************//**
* \file cy_gpio.c
* \version 1.140
*
* Provides an API implementation of the GPIO driver
*
********************************************************************************
* \copyright
* Copyright (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#if defined (CY_IP_MXS40SIOSS) || defined (CY_IP_MXS40IOSS) || defined (CY_IP_MXS22IOSS)

#include "cy_gpio.h"
#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
#include "cy_pra.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif


/* Define for AMUX A splitters */
#define GPIO_AMUXA_SPLITTER_MASK     (uint32_t)(HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SL_Msk \
                                              | HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SR_Msk \
                                              | HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_S0_Msk)

/* Define for AMUX B splitters */
#define GPIO_AMUXB_SPLITTER_MASK     (uint32_t)(HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Msk \
                                              | HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SR_Msk \
                                              | HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_S0_Msk)

/*******************************************************************************
* Function Name: Cy_GPIO_Pin_Init
****************************************************************************//**
*
* Initializes all pin configuration settings for the specified pin.
*
* \param base
* Pointer to the pin's port register base address
*
* \param pinNum
* Position of the pin bit-field within the port register
*
* \param config
* Pointer to the pin config structure base address
*
* \return
* Initialization status
*
* \note
* This function modifies port registers in read-modify-write operations. It is
* not thread safe as the resource is shared among multiple pins on a port.
*
* \note
* When EXT_CLK is source to HF0 and this API is called from application then
* make sure that the drivemode argument is CY_GPIO_DM_HIGHZ.
*
* \funcusage
* \snippet gpio/snippet/main.c snippet_Cy_GPIO_Pin_Init
*
*******************************************************************************/
cy_en_gpio_status_t Cy_GPIO_Pin_Init(GPIO_PRT_Type *base, uint32_t pinNum, const cy_stc_gpio_pin_config_t *config)
{
    cy_en_gpio_status_t status = CY_GPIO_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {
#if defined (CY_IP_MXS40IOSS)
#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
        cy_en_pra_pin_prot_type_t pinType;
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
        uint32_t maskCfgOut;
#endif /* CY_IP_MXS40IOSS */
        uint32_t tempReg, tempReg2;

        CY_ASSERT_L2(CY_GPIO_IS_PIN_VALID(pinNum));
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->outVal));
        CY_ASSERT_L2(CY_GPIO_IS_DM_VALID(config->driveMode));
        CY_ASSERT_L2(CY_GPIO_IS_HSIOM_VALID(config->hsiom));
        CY_ASSERT_L2(CY_GPIO_IS_INT_EDGE_VALID(config->intEdge));
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->intMask));
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->vtrip));

        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->vregEn));
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->ibufMode));
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->vtripSel));
        CY_ASSERT_L2(CY_GPIO_IS_VREF_SEL_VALID(config->vrefSel));
        CY_ASSERT_L2(CY_GPIO_IS_VOH_SEL_VALID(config->vohSel));
        CY_ASSERT_L2(CY_GPIO_IS_DRIVE_SEL_VALID(config->driveSel));

#if defined (CY_IP_MXS22IOSS)
        CY_ASSERT_L2(CY_GPIO_IS_PULLUP_RES_VALID(config->pullUpRes));
#endif /* CY_IP_MXS22IOSS */

        /* Slew rate and Driver strength */
#if defined (CY_IP_MXS40IOSS)
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->slewRate));
#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)

        pinType = CY_PRA_GET_PIN_PROT_TYPE(base, pinNum);

        if (pinType == CY_PRA_PIN_SECURE)
        {
            return(status); /* Protected pins are not allowed to configure */
        }
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
        maskCfgOut = (CY_GPIO_CFG_OUT_SLOW_MASK << pinNum)
                     | (CY_GPIO_CFG_OUT_DRIVE_SEL_MASK << ((uint32_t)(pinNum << 1U) + CY_GPIO_CFG_OUT_DRIVE_OFFSET));

#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) && defined(CY_DEVICE_PSOC6ABLE2)
        if (pinType == CY_PRA_PIN_SECURE_UNCONSTRAINED)
        {
            tempReg = CY_PRA_REG32_GET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_OUT)) & ~(maskCfgOut);
        }
        else
        {
            tempReg = GPIO_PRT_CFG_OUT(base) & ~(maskCfgOut);
        }
#else
        tempReg = GPIO_PRT_CFG_OUT(base) & ~(maskCfgOut);
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) && defined(CY_DEVICE_PSOC6ABLE2) */

        tempReg2 = tempReg | ((config->slewRate & CY_GPIO_CFG_OUT_SLOW_MASK) << pinNum)
                            | ((config->driveSel & CY_GPIO_CFG_OUT_DRIVE_SEL_MASK) << ((uint32_t)(pinNum << 1U) + CY_GPIO_CFG_OUT_DRIVE_OFFSET));

#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
        if (pinType == CY_PRA_PIN_SECURE_UNCONSTRAINED)
        {
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_OUT), tempReg2);
        }
        else /* non-secure pin */
        {
            GPIO_PRT_CFG_OUT(base) = tempReg2;
        }
#else
        GPIO_PRT_CFG_OUT(base) = tempReg2;
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */

#else
        CY_ASSERT_L2(CY_GPIO_IS_SLEW_RATE_VALID(config->slewRate));
#if ((defined (IOSS_HSIOM_HSIOM_SEC_PORT_NR) && (IOSS_HSIOM_HSIOM_SEC_PORT_NR != 0)) || (CPUSS_CM33_0_SECEXT_PRESENT != 0))
        /* Set HSIOM NONSECURE_MASK for Secure access to be able to configure pin in Secure mode */
        Cy_GPIO_SetHSIOM_SecPin(base, pinNum, CY_GPIO_HSIOM_SECURE_ACCESS);
#endif /* IOSS_HSIOM_HSIOM_SEC_PORT_NR, CPUSS_CM33_0_SECEXT_PRESENT */
        Cy_GPIO_SetSlewRate(base, pinNum, config->slewRate);
        Cy_GPIO_SetDriveSel(base, pinNum, config->driveSel);
#endif /* CY_IP_MXS40IOSS */
        Cy_GPIO_SetHSIOM(base, pinNum, config->hsiom);
        Cy_GPIO_SetDrivemode(base, pinNum, config->driveMode);

        Cy_GPIO_SetInterruptEdge(base, pinNum, config->intEdge);
        Cy_GPIO_SetInterruptMask(base, pinNum, config->intMask);
        Cy_GPIO_SetVtrip(base, pinNum, config->vtrip);

        /* SIO specific configuration */
 #if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) && defined(CY_DEVICE_PSOC6ABLE2)
        if (pinType == CY_PRA_PIN_SECURE_UNCONSTRAINED)
        {
            tempReg = CY_PRA_REG32_GET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_SIO)) & ~(CY_GPIO_SIO_PIN_MASK);
        }
        else
        {
            tempReg = GPIO_PRT_CFG_SIO(base) & ~(CY_GPIO_SIO_PIN_MASK);
        }
#else
        tempReg = GPIO_PRT_CFG_SIO(base) & ~(CY_GPIO_SIO_PIN_MASK);
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) && defined(CY_DEVICE_PSOC6ABLE2) */

        tempReg2 = tempReg | (((config->vregEn & CY_GPIO_VREG_EN_MASK)
                                         | ((config->ibufMode & CY_GPIO_IBUF_MASK) << CY_GPIO_IBUF_SHIFT)
                                         | ((config->vtripSel & CY_GPIO_VTRIP_SEL_MASK) << CY_GPIO_VTRIP_SEL_SHIFT)
                                         | ((config->vrefSel & CY_GPIO_VREF_SEL_MASK)  << CY_GPIO_VREF_SEL_SHIFT)
                                         | ((config->vohSel & CY_GPIO_VOH_SEL_MASK) << CY_GPIO_VOH_SEL_SHIFT))
                                           << ((pinNum & CY_GPIO_SIO_ODD_PIN_MASK) << CY_GPIO_CFG_SIO_OFFSET));

#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
        if (pinType == CY_PRA_PIN_SECURE_UNCONSTRAINED)
        {
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_SIO), tempReg2);
        }
        else /* non-secure pin */
        {
            GPIO_PRT_CFG_SIO(base) = tempReg2;
        }
#else
        GPIO_PRT_CFG_SIO(base) = tempReg2;
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */

#if defined (CY_IP_MXS22IOSS)
        Cy_GPIO_SetPullupResistance(base, pinNum, config->pullUpRes);
#endif /* CY_IP_MXS22IOSS */

        Cy_GPIO_Write(base, pinNum, config->outVal);

#if ((defined (IOSS_HSIOM_HSIOM_SEC_PORT_NR) && (IOSS_HSIOM_HSIOM_SEC_PORT_NR != 0)) || \
    (defined (CPUSS_CM33_0_SECEXT_PRESENT) && (CPUSS_CM33_0_SECEXT_PRESENT != 0)))
        /* Set HSIOM NONSECURE_MASK as per configurator's settings */
        CY_ASSERT_L2(CY_GPIO_IS_HSIOM_SEC_VALID(config->nonSec));
        Cy_GPIO_SetHSIOM_SecPin(base, pinNum, config->nonSec);
#endif /* IOSS_HSIOM_HSIOM_SEC_PORT_NR, CPUSS_CM33_0_SECEXT_PRESENT */

        status = CY_GPIO_SUCCESS;
    }

    return(status);
}


/*******************************************************************************
* Function Name: Cy_GPIO_Port_Init
****************************************************************************//**
*
* Initialize a complete port of pins from a single init structure.
*
* The configuration structure used in this function has a 1:1 mapping to the
* GPIO and HSIOM registers. Refer to the device Technical Reference Manual (TRM)
* for the register details on how to populate them.
*
* \param base
* Pointer to the pin's port register base address
*
* \param config
* Pointer to the pin config structure base address
*
* \return
* Initialization status
*
* \note
* If using the PSoC Creator IDE, there is no need to initialize the pins when
* using the GPIO component on the schematic. Ports are configured in
* Cy_SystemInit() before main() entry.
*
* \funcusage
* \snippet gpio/snippet/main.c snippet_Cy_GPIO_Port_Init
*
*******************************************************************************/
cy_en_gpio_status_t Cy_GPIO_Port_Init(GPIO_PRT_Type* base, const cy_stc_gpio_prt_config_t *config)
{
    cy_en_gpio_status_t status = CY_GPIO_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {
        uint32_t portNum;
        HSIOM_PRT_V1_Type* baseHSIOM;
#if (defined (CY_IP_MXS40SIOSS) &&  ((IOSS_HSIOM_HSIOM_SEC_PORT_NR != 0) || ( defined (CY_IP_MXS40SIOSS) && (CPUSS_CM33_0_SECEXT_PRESENT != 0)) ))  || defined (CY_IP_MXS22IOSS)
        HSIOM_SECURE_PRT_Type *baseSecHSIOM;
#else
#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
        bool secPort;
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
#endif /* CY_IP_MXS40SIOSS, IOSS_HSIOM_HSIOM_SEC_PORT_NR, CPUSS_CM33_0_SECEXT_PRESENT, CY_IP_MXS22IOSS */
        portNum = ((uint32_t)(base) - CY_GPIO_BASE) / GPIO_PRT_SECTION_SIZE;
        baseHSIOM = (HSIOM_PRT_V1_Type*)(CY_HSIOM_BASE + (HSIOM_PRT_SECTION_SIZE * portNum));

#if defined (CY_IP_MXSMIF) && ((CY_IP_MXSMIF_VERSION == 5) || (CY_IP_MXSMIF_VERSION == 6))
        if (CY_GPIO_IS_SMIF_GPIO(base))
        {
            uint32_t smif_core_offset = ((void *)base >= (void *)SMIF_INST1_PRT0) ? SMIF_INST_OFFSET : 0U;
            portNum = ((uint32_t)(base) - CY_SMIF_GPIO_BASE - smif_core_offset) / SMIF_CORE_SMIF_GPIO_SMIF_PRT_SECTION_SIZE;
            baseHSIOM = (HSIOM_PRT_V1_Type*)(CY_SMIF_HSIOM_BASE + (SMIF_CORE_SMIF_HSIOM_SMIF_PRT_SECTION_SIZE * portNum) + smif_core_offset);
        }
#endif

        CY_ASSERT_L2(CY_GPIO_IS_PIN_BIT_VALID(config->out));
        CY_ASSERT_L2(CY_GPIO_IS_PIN_BIT_VALID(config->cfgIn));
        CY_ASSERT_L2(CY_GPIO_IS_INTR_CFG_VALID(config->intrCfg));
        CY_ASSERT_L2(CY_GPIO_IS_INTR_MASK_VALID(config->intrMask));
        CY_ASSERT_L2(CY_GPIO_IS_SEL_ACT_VALID(config->sel0Active));
        CY_ASSERT_L2(CY_GPIO_IS_SEL_ACT_VALID(config->sel1Active));

#if defined (CY_IP_MXS22IOSS)
        CY_ASSERT_L2(CY_GPIO_PRT_IS_PULLUP_RES_VALID(config->cfgRes));
#endif /* CY_IP_MXS22IOSS */

#if defined (CY_IP_MXS40SIOSS) || defined (CY_IP_MXS22IOSS)
#if ((defined (IOSS_HSIOM_HSIOM_SEC_PORT_NR) && (IOSS_HSIOM_HSIOM_SEC_PORT_NR != 0)) || (CPUSS_CM33_0_SECEXT_PRESENT != 0))
        CY_ASSERT_L2(CY_GPIO_IS_PIN_BIT_VALID(config->nonSecMask));

        baseSecHSIOM = (HSIOM_SECURE_PRT_Type*)(CY_HSIOM_SECURE_BASE + (HSIOM_SECURE_PRT_SECTION_SIZE * portNum));

#if defined (CY_IP_MXSMIF) && ((CY_IP_MXSMIF_VERSION == 5) || (CY_IP_MXSMIF_VERSION == 6))
        uint32_t smif_core_offset = ((void *)base >= (void *)SMIF_INST1_PRT0) ? SMIF_INST_OFFSET : 0U;
        baseSecHSIOM = (HSIOM_SECURE_PRT_Type*)(CY_SMIF_SECURE_HSIOM_BASE + (SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_SECTION_SIZE * portNum) + smif_core_offset);
#endif /* CY_IP_MXSMIF, CY_IP_MXSMIF_VERSION */

        HSIOM_SEC_PRT_NONSEC_MASK(baseSecHSIOM) = config->nonSecMask;
#endif /* IOSS_HSIOM_HSIOM_SEC_PORT_NR, CPUSS_CM33_0_SECEXT_PRESENT */
        GPIO_PRT_SLEW_EXT(base)                 = config->cfgSlew;
        GPIO_PRT_DRIVE_EXT0(base)               = config->cfgDriveSel0;
        GPIO_PRT_DRIVE_EXT1(base)               = config->cfgDriveSel1;
#endif /* CY_IP_MXS40SIOSS, CY_IP_MXS22IOSS */

#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
        secPort = CY_PRA_IS_PORT_SECURE(base);
        if (secPort)
        {
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG), config->cfg);
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_IN), config->cfgIn);
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_OUT), config->cfgOut);
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_INTR_CFG), config->intrCfg);
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_INTR_MASK), config->intrMask);
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_SIO), config->cfgSIO);
            CY_PRA_REG32_SET(CY_PRA_GET_HSIOM_REG_INDEX(base, CY_PRA_SUB_INDEX_HSIOM_PORT0), config->sel0Active);
            CY_PRA_REG32_SET(CY_PRA_GET_HSIOM_REG_INDEX(base, CY_PRA_SUB_INDEX_HSIOM_PORT1), config->sel1Active);
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_OUT), config->out);
        }
        else
        {
            GPIO_PRT_CFG(base)             = config->cfg;
            GPIO_PRT_CFG_IN(base)          = config->cfgIn;
            GPIO_PRT_CFG_OUT(base)         = config->cfgOut;
            GPIO_PRT_INTR_CFG(base)        = config->intrCfg;
            GPIO_PRT_INTR_MASK(base)       = config->intrMask;
            GPIO_PRT_CFG_SIO(base)         = config->cfgSIO;
            /* For 1M device check for secure HSIOM */
#if defined(CY_DEVICE_PSOC6ABLE2)
            if (CY_PRA_IS_HSIOM_SECURE(base))
            {
                CY_PRA_REG32_SET(CY_PRA_GET_ADJHSIOM_REG_INDEX(base, CY_PRA_SUB_INDEX_HSIOM_PORT0), config->sel0Active);
                CY_PRA_REG32_SET(CY_PRA_GET_ADJHSIOM_REG_INDEX(base, CY_PRA_SUB_INDEX_HSIOM_PORT1), config->sel1Active);
            }
            else
            {
                HSIOM_PRT_PORT_SEL0(baseHSIOM) = config->sel0Active;
                HSIOM_PRT_PORT_SEL1(baseHSIOM) = config->sel1Active;
            }
#else
            HSIOM_PRT_PORT_SEL0(baseHSIOM) = config->sel0Active;
            HSIOM_PRT_PORT_SEL1(baseHSIOM) = config->sel1Active;
#endif /* defined(CY_DEVICE_PSOC6ABLE2) */
            GPIO_PRT_OUT(base)             = config->out;
        }
#else
        GPIO_PRT_CFG(base)             = config->cfg;
        GPIO_PRT_CFG_IN(base)          = config->cfgIn;
        GPIO_PRT_CFG_OUT(base)         = config->cfgOut;
        GPIO_PRT_INTR_CFG(base)        = config->intrCfg;
        GPIO_PRT_INTR_MASK(base)       = config->intrMask;
        GPIO_PRT_CFG_SIO(base)         = config->cfgSIO;
        HSIOM_PRT_PORT_SEL0(baseHSIOM) = config->sel0Active;
        HSIOM_PRT_PORT_SEL1(baseHSIOM) = config->sel1Active;
        GPIO_PRT_OUT(base)             = config->out;
#if defined (CY_IP_MXS22IOSS)
        GPIO_PRT_CFG_OUT3(base)    = config->cfgOut3;
        GPIO_PRT_CFG_RES(base)     = config->cfgRes;
#endif /* CY_IP_MXS22IOSS */
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */

        status = CY_GPIO_SUCCESS;
    }

    return (status);
}

#if defined(CORE_NAME_CM55_0)
CY_SECTION_ITCM_BEGIN
#else
CY_SECTION_RAMFUNC_BEGIN
#endif
/*******************************************************************************
* Function Name: Cy_GPIO_Pin_FastInit
****************************************************************************//**
*
* Initialize the most common configuration settings for all pin types.
*
* These include, drive mode, initial output value, and HSIOM connection.
*
* \param base
* Pointer to the pin's port register base address
*
* \param pinNum
* Position of the pin bit-field within the port register
*
* \param driveMode
* Pin drive mode. Options are detailed in \ref group_gpio_driveModes macros
*
* \param outVal
* Logic state of the output buffer driven to the pin (1 or 0)
*
* \param hsiom
* HSIOM input selection
*
* \note
* This function modifies port registers in read-modify-write operations. It is
* not thread safe as the resource is shared among multiple pins on a port.
* You can use the Cy_SysLib_EnterCriticalSection() and
* Cy_SysLib_ExitCriticalSection() functions to ensure that
* Cy_GPIO_Pin_FastInit() function execution is not interrupted.
*
* \note
* When EXT_CLK is source to HF0 and this API is called from application then
* make sure that the drivemode argument is CY_GPIO_DM_HIGHZ.
*
* \note
* This doesn't set pull-up resistance value. By default. the pull-up resistance
* is disabled. To select it, use Cy_GPIO_SetPullupResistance.
*
* \funcusage
* \snippet gpio/snippet/main.c snippet_Cy_GPIO_Pin_FastInit
*
*******************************************************************************/
void Cy_GPIO_Pin_FastInit(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t driveMode,
                                        uint32_t outVal, en_hsiom_sel_t hsiom)
{
#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    cy_en_pra_pin_prot_type_t pinType;
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */

    CY_ASSERT_L2(CY_GPIO_IS_PIN_VALID(pinNum));
    CY_ASSERT_L2(CY_GPIO_IS_DM_VALID(driveMode));
    CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(outVal));
    CY_ASSERT_L2(CY_GPIO_IS_HSIOM_VALID(hsiom));

    uint32_t tempReg;
#if defined (CY_IP_MXS22IOSS)
    uint32_t tempRegCfg3;
#endif /* CY_IP_MXS22IOSS */

    Cy_GPIO_SetHSIOM(base, pinNum, hsiom);

#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    pinType = CY_PRA_GET_PIN_PROT_TYPE(base, pinNum);

    if (pinType != CY_PRA_PIN_SECURE)
    {
        if (pinType == CY_PRA_PIN_SECURE_UNCONSTRAINED)
        {
#if defined(CY_DEVICE_PSOC6ABLE2)
            tempReg = (CY_PRA_REG32_GET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_OUT)) & ~(CY_GPIO_OUT_MASK << pinNum));
#else
            tempReg = (GPIO_PRT_OUT(base) & ~(CY_GPIO_OUT_MASK << pinNum));
#endif
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_OUT), (tempReg | ((outVal & CY_GPIO_OUT_MASK) << pinNum)));

#if defined(CY_DEVICE_PSOC6ABLE2)
            tempReg = (CY_PRA_REG32_GET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG)) & ~(CY_GPIO_CFG_DM_MASK << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET)));
#else
            tempReg = (GPIO_PRT_CFG(base) & ~(CY_GPIO_CFG_DM_MASK << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET)));
#endif
            CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG), (tempReg | ((driveMode & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET))));
        }
        else /* non secure pin */
        {
            tempReg = (GPIO_PRT_OUT(base) & ~(CY_GPIO_OUT_MASK << pinNum));
            GPIO_PRT_OUT(base) = tempReg | ((outVal & CY_GPIO_OUT_MASK) << pinNum);

            tempReg = (GPIO_PRT_CFG(base) & ~(CY_GPIO_CFG_DM_MASK << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET)));
            GPIO_PRT_CFG(base) = tempReg | ((driveMode & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
        }
    }
    else
    {
        /* Secure PIN can't be modified using register policy */
    }
#else
    tempReg = (GPIO_PRT_OUT(base) & ~(CY_GPIO_OUT_MASK << pinNum));
    GPIO_PRT_OUT(base) = tempReg | ((outVal & CY_GPIO_OUT_MASK) << pinNum);

    tempReg = (GPIO_PRT_CFG(base) & ~(CY_GPIO_CFG_DM_MASK << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET)));
#if defined (CY_IP_MXS22IOSS)
    tempRegCfg3 = (GPIO_PRT_CFG_OUT3(base) & ~(CY_GPIO_CFG_DM_MASK << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET)));

    if(CY_GPIO_DM_CFGOUT3_STRONG_PULLUP_HIGHZ == driveMode)
    {
        /* Enable CFG_OUT3 register and configure the extra drive mode with input buffer enabled. */
        GPIO_PRT_CFG(base) = tempReg | (GPIO_PRT_CFG_IN_EN0_Msk << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
        GPIO_PRT_CFG_OUT3(base) = tempRegCfg3 | (((driveMode >> CY_GPIO_EXT_DM_SHIFT) & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
    }
    else
    {
        /* If High-Z drive mode is selected, enable CFG_OUT3 register using CFG register and configure drive mode using CFG_OUT3 register. */
        /* For other drive modes, disable CFG_OUT3 register and use CFG register to configure drive modes. */
        GPIO_PRT_CFG(base) = tempReg | ((driveMode & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
        GPIO_PRT_CFG_OUT3(base) = tempRegCfg3 | ((0U & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
    }
#else
    GPIO_PRT_CFG(base) = tempReg | ((driveMode & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
#endif /* CY_IP_MXS22IOSS */
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
}
#if defined(CORE_NAME_CM55_0)
CY_SECTION_ITCM_END
#else
CY_SECTION_RAMFUNC_END
#endif
#if (defined (CY_IP_MXS40SIOSS) &&  ((IOSS_HSIOM_HSIOM_SEC_PORT_NR != 0) || (CPUSS_CM33_0_SECEXT_PRESENT != 0))) || defined (CY_IP_MXS22IOSS)
/*******************************************************************************
* Function Name: Cy_GPIO_Pin_SecFastInit
****************************************************************************//**
*
* Initialize the most common configuration settings for all pin types.
*
* These include, drive mode, initial output value, and HSIOM connection. This
* function should be called from appropriate protection context where secure
* HSIOM port (HSIOM_SECURE_PRT_Type) is accessible.
*
* \param base
* Pointer to the pin's port register base address
*
* \param pinNum
* Position of the pin bit-field within the port register
*
* \param driveMode
* Pin drive mode. Options are detailed in \ref group_gpio_driveModes macros
*
* \param outVal
* Logic state of the output buffer driven to the pin (1 or 0)
*
* \param hsiom
* HSIOM input selection
*
* \note
* This function modifies port registers in read-modify-write operations. It is
* not thread safe as the resource is shared among multiple pins on a port.
* You can use the Cy_SysLib_EnterCriticalSection() and
* Cy_SysLib_ExitCriticalSection() functions to ensure that
* Cy_GPIO_Pin_SecFastInit() function execution is not interrupted.
*
* \note
* This API should be accessed from secure domain only.
*
*******************************************************************************/
void Cy_GPIO_Pin_SecFastInit(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t driveMode,
                                        uint32_t outVal, en_hsiom_sel_t hsiom)
{
/* Restrict access to secure API. It should be accessed from secure domain only */
#if defined (CY_PDL_TZ_ENABLED)
    CY_ASSERT_L2(CY_GPIO_IS_PIN_VALID(pinNum));
    CY_ASSERT_L2(CY_GPIO_IS_DM_VALID(driveMode));
    CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(outVal));
    CY_ASSERT_L2(CY_GPIO_IS_HSIOM_VALID(hsiom));

    uint32_t tempReg;
#if defined (CY_IP_MXS22IOSS)
    uint32_t tempRegCfg3;
#endif /* CY_IP_MXS22IOSS */

    Cy_GPIO_SetHSIOM_SecPin(base, pinNum, CY_GPIO_HSIOM_SECURE_ACCESS); /* make the pin as secure */

    Cy_GPIO_SetHSIOM(base, pinNum, hsiom);

    tempReg = (GPIO_PRT_CFG(base) & ~(CY_GPIO_CFG_DM_MASK << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET)));
#if defined (CY_IP_MXS22IOSS)
    tempRegCfg3 = (GPIO_PRT_CFG_OUT3(base) & ~(CY_GPIO_CFG_DM_MASK << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET)));

    if(driveMode == CY_GPIO_DM_CFGOUT3_STRONG_PULLUP_HIGHZ)
    {
        /* Enable CFG_OUT3 register and configure the extra drive mode. */
        GPIO_PRT_CFG(base) = tempReg | ((0U & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
        GPIO_PRT_CFG_OUT3(base) = tempRegCfg3 | (((driveMode >> CY_GPIO_EXT_DM_SHIFT) & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
    }
    else
    {
        /* If High-Z drive mode is selected, enable CFG_OUT3 register using CFG register and configure drive mode using CFG_OUT3 register. */
        /* For other drive modes, disable CFG_OUT3 register and use CFG register to configure drive modes. */
        GPIO_PRT_CFG(base) = tempReg | ((driveMode & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
        GPIO_PRT_CFG_OUT3(base) = tempRegCfg3 | ((0U & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
    }
#else
    GPIO_PRT_CFG(base) = tempReg | ((driveMode & CY_GPIO_CFG_DM_MASK) << (pinNum << CY_GPIO_DRIVE_MODE_OFFSET));
#endif /* CY_IP_MXS22IOSS */

    tempReg = (GPIO_PRT_OUT(base) & ~(CY_GPIO_OUT_MASK << pinNum));
    GPIO_PRT_OUT(base) = tempReg | ((outVal & CY_GPIO_OUT_MASK) << pinNum);
#else
    /* Suppress a compiler warning about unused variables */
    (void)base;
    (void)pinNum;
    (void)driveMode;
    (void)outVal;
    (void)hsiom;
#endif /* CY_PDL_TZ_ENABLED */
}
#endif /* CY_IP_MXS40SIOSS, IOSS_HSIOM_HSIOM_SEC_PORT_NR, CPUSS_CM33_0_SECEXT_PRESENT, CY_IP_MXS22IOSS */

/*******************************************************************************
* Function Name: Cy_GPIO_Port_Deinit
****************************************************************************//**
*
* Reset a complete port of pins back to power on reset defaults.
*
* \param base
* Pointer to the pin's port register base address
*
* \funcusage
* \snippet gpio/snippet/main.c snippet_Cy_GPIO_Port_Deinit
*
*******************************************************************************/
void Cy_GPIO_Port_Deinit(GPIO_PRT_Type* base)
{
#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    bool secPort;
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
    uint32_t portNum;
    HSIOM_PRT_V1_Type* baseHSIOM;
    portNum = ((uint32_t)(base) - CY_GPIO_BASE) / GPIO_PRT_SECTION_SIZE;
    baseHSIOM = (HSIOM_PRT_V1_Type*)(CY_HSIOM_BASE + (HSIOM_PRT_SECTION_SIZE * portNum));

#if defined (CY_IP_MXSMIF) && ((CY_IP_MXSMIF_VERSION == 5) || (CY_IP_MXSMIF_VERSION == 6))
    if (CY_GPIO_IS_SMIF_GPIO(base))
    {
        uint32_t smif_core_offset = ((void *)base >= (void *)SMIF_INST1_PRT0) ? SMIF_INST_OFFSET : 0U;
        portNum = ((uint32_t)(base) - CY_SMIF_GPIO_BASE - smif_core_offset) / SMIF_CORE_SMIF_GPIO_SMIF_PRT_SECTION_SIZE;
        baseHSIOM = (HSIOM_PRT_V1_Type*)(CY_SMIF_HSIOM_BASE + (SMIF_CORE_SMIF_HSIOM_SMIF_PRT_SECTION_SIZE * portNum) + smif_core_offset);
    }
#endif

#if defined (CY_IP_MXS40SIOSS) || defined (CY_IP_MXS22IOSS)
#if ((defined (IOSS_HSIOM_HSIOM_SEC_PORT_NR) && (IOSS_HSIOM_HSIOM_SEC_PORT_NR != 0)) || (CPUSS_CM33_0_SECEXT_PRESENT != 0 ))
    HSIOM_SECURE_PRT_Type *baseSecHSIOM;
    baseSecHSIOM = (HSIOM_SECURE_PRT_Type*)(CY_HSIOM_SECURE_BASE + (HSIOM_SECURE_PRT_SECTION_SIZE * portNum));
    HSIOM_SEC_PRT_NONSEC_MASK(baseSecHSIOM) = CY_HSIOM_NONSEC_DEINIT;
#endif /* IOSS_HSIOM_HSIOM_SEC_PORT_NR, CPUSS_CM33_0_SECEXT_PRESENT */
    GPIO_PRT_SLEW_EXT(base)                 = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_DRIVE_EXT0(base)               = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_DRIVE_EXT1(base)               = CY_GPIO_PRT_DEINIT;
#endif /* CY_IP_MXS40SIOSS */

#if (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE)
    secPort = CY_PRA_IS_PORT_SECURE(base);
    if (secPort)
    {
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_OUT), CY_GPIO_PRT_DEINIT);
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG), CY_GPIO_PRT_DEINIT);
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_IN), CY_GPIO_PRT_DEINIT);
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_OUT), CY_GPIO_PRT_DEINIT);
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_INTR_CFG), CY_GPIO_PRT_DEINIT);
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_INTR_MASK), CY_GPIO_PRT_DEINIT);
        CY_PRA_REG32_SET(CY_PRA_GET_PORT_REG_INDEX(base, CY_PRA_SUB_INDEX_PORT_CFG_SIO), CY_GPIO_PRT_DEINIT);
        CY_PRA_REG32_SET(CY_PRA_GET_HSIOM_REG_INDEX(base, CY_PRA_SUB_INDEX_HSIOM_PORT0), CY_GPIO_PRT_DEINIT);
        CY_PRA_REG32_SET(CY_PRA_GET_HSIOM_REG_INDEX(base, CY_PRA_SUB_INDEX_HSIOM_PORT1), CY_GPIO_PRT_DEINIT);

    }
    else
    {
        GPIO_PRT_OUT(base)             = CY_GPIO_PRT_DEINIT;
        GPIO_PRT_CFG(base)             = CY_GPIO_PRT_DEINIT;
        GPIO_PRT_CFG_IN(base)          = CY_GPIO_PRT_DEINIT;
        GPIO_PRT_CFG_OUT(base)         = CY_GPIO_PRT_DEINIT;
        GPIO_PRT_INTR_CFG(base)        = CY_GPIO_PRT_DEINIT;
        GPIO_PRT_INTR_MASK(base)       = CY_GPIO_PRT_DEINIT;
        GPIO_PRT_CFG_SIO(base)         = CY_GPIO_PRT_DEINIT;
        /* For 1M device check for secure HSIOM */
#if defined(CY_DEVICE_PSOC6ABLE2)
        if (CY_PRA_IS_HSIOM_SECURE(base))
        {
            CY_PRA_REG32_SET(CY_PRA_GET_ADJHSIOM_REG_INDEX(base, CY_PRA_SUB_INDEX_HSIOM_PORT0), CY_GPIO_PRT_DEINIT);
            CY_PRA_REG32_SET(CY_PRA_GET_ADJHSIOM_REG_INDEX(base, CY_PRA_SUB_INDEX_HSIOM_PORT1), CY_GPIO_PRT_DEINIT);
        }
        else
        {
            HSIOM_PRT_PORT_SEL0(baseHSIOM) = CY_GPIO_PRT_DEINIT;
            HSIOM_PRT_PORT_SEL1(baseHSIOM) = CY_GPIO_PRT_DEINIT;
        }
#else
        HSIOM_PRT_PORT_SEL0(baseHSIOM) = CY_GPIO_PRT_DEINIT;
        HSIOM_PRT_PORT_SEL1(baseHSIOM) = CY_GPIO_PRT_DEINIT;
#endif /* defined(CY_DEVICE_PSOC6ABLE2) */
    }
#else
    GPIO_PRT_OUT(base)             = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_CFG(base)             = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_CFG_IN(base)          = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_CFG_OUT(base)         = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_INTR_CFG(base)        = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_INTR_MASK(base)       = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_CFG_SIO(base)         = CY_GPIO_PRT_DEINIT;
    HSIOM_PRT_PORT_SEL0(baseHSIOM) = CY_GPIO_PRT_DEINIT;
    HSIOM_PRT_PORT_SEL1(baseHSIOM) = CY_GPIO_PRT_DEINIT;
#if defined (CY_IP_MXS22IOSS)
    GPIO_PRT_CFG_OUT3(base)         = CY_GPIO_PRT_DEINIT;
    GPIO_PRT_CFG_RES(base)          = CY_GPIO_PRT_DEINIT;
#endif /* CY_IP_MXS22IOSS */
#endif /* (CY_CPU_CORTEX_M4) && defined(CY_DEVICE_SECURE) */
}


/*******************************************************************************
* Function Name: Cy_GPIO_SetAmuxSplit
****************************************************************************//**
*
* Configure a specific AMux bus splitter switch cell into a specific
* configuration.
*
* \param switchCtrl
* Selects specific AMux bus splitter cell between two segments.
* The cy_en_amux_split_t enumeration can be found in the GPIO header file
* for the device package.
*
* \param amuxConnect
* Selects configuration of the three switches within the splitter cell
*
* \param amuxBus
* Selects which AMux bus within the splitter is being configured
*
*******************************************************************************/
void Cy_GPIO_SetAmuxSplit(cy_en_amux_split_t switchCtrl, cy_en_gpio_amuxconnect_t amuxConnect,
                                                         cy_en_gpio_amuxselect_t amuxBus)
{
    CY_ASSERT_L2(CY_GPIO_IS_AMUX_SPLIT_VALID(switchCtrl));
    CY_ASSERT_L3(CY_GPIO_IS_AMUX_CONNECT_VALID(amuxConnect));
    CY_ASSERT_L3(CY_GPIO_IS_AMUX_SELECT_VALID(amuxBus));

    uint32_t tmpReg;

    if (amuxBus != CY_GPIO_AMUXBUSB)
    {
        tmpReg = HSIOM_AMUX_SPLIT_CTL(switchCtrl) & GPIO_AMUXB_SPLITTER_MASK;
        HSIOM_AMUX_SPLIT_CTL(switchCtrl) = tmpReg | ((uint32_t) amuxConnect & GPIO_AMUXA_SPLITTER_MASK);
    }
    else
    {
        tmpReg = HSIOM_AMUX_SPLIT_CTL(switchCtrl) & GPIO_AMUXA_SPLITTER_MASK;
        HSIOM_AMUX_SPLIT_CTL(switchCtrl) =
        tmpReg | (((uint32_t) amuxConnect << HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Pos) & GPIO_AMUXB_SPLITTER_MASK);
    }
}


/*******************************************************************************
* Function Name: Cy_GPIO_GetAmuxSplit
****************************************************************************//**
*
* Returns the configuration of a specific AMux bus splitter switch cell.
*
* \param switchCtrl
* Selects specific AMux bus splitter cell between two segments.
* The cy_en_amux_split_t enumeration can be found in the GPIO header file
* for the device package.
*
* \param amuxBus
* Selects which AMux bus within the splitter is being configured
*
* \return
* Returns configuration of the three switches in the selected splitter cell
*
*******************************************************************************/
cy_en_gpio_amuxconnect_t Cy_GPIO_GetAmuxSplit(cy_en_amux_split_t switchCtrl, cy_en_gpio_amuxselect_t amuxBus)
{
    CY_ASSERT_L2(CY_GPIO_IS_AMUX_SPLIT_VALID(switchCtrl));
    CY_ASSERT_L3(CY_GPIO_IS_AMUX_SELECT_VALID(amuxBus));

    uint32_t retVal;

    if (amuxBus != CY_GPIO_AMUXBUSB)
    {
        retVal = HSIOM_AMUX_SPLIT_CTL(switchCtrl) & GPIO_AMUXA_SPLITTER_MASK;
    }
    else
    {
        retVal = ((uint32_t) ((HSIOM_AMUX_SPLIT_CTL(switchCtrl) & GPIO_AMUXB_SPLITTER_MASK)
                                                     >> HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Pos));
    }

    return ((cy_en_gpio_amuxconnect_t) retVal);
}




#if defined (CY_IP_MXS22IOSS)
/*******************************************************************************
* Function Name: Cy_GPIO_SetPullupResistance
****************************************************************************//**
*
* Configures the GPIO pin Pull-up mode.
*
* \param base
* Pointer to the pin's port register base address
*
* \param pinNum
* Position of the pin bit-field within the port register
*
* \param value
* Pull-up mode for a pin. Options are detailed in
* \ref group_gpio_PullUpMode macros
*
* \note
* This API configures pull-up resistors only when
* \ref CY_GPIO_DM_CFGOUT3_STRONG_PULLUP_HIGHZ is selected. For all other pin drive
* modes, it disables additional pull-up resistors.
*
* \note
* This API modifies a port register in a read-modify-write operation. It is
* not thread safe as the resource is shared among multiple pins on a port.
*
* \funcusage
* \snippet gpio/snippet/main.c snippet_Cy_GPIO_SetPullupResistance
*
*******************************************************************************/
void Cy_GPIO_SetPullupResistance(GPIO_PRT_Type* base, uint32_t pinNum, uint32_t value)
{
    uint32_t tempReg, pinLoc, prtCfg;

    CY_ASSERT_L2(CY_GPIO_IS_PIN_VALID(pinNum));
    CY_ASSERT_L2(CY_GPIO_IS_PULLUP_RES_VALID(value));

    if(Cy_GPIO_GetDrivemode(base, pinNum) != CY_GPIO_DM_CFGOUT3_STRONG_PULLUP_HIGHZ)
    {
        value = CY_GPIO_PULLUP_RES_DISABLE;
    }

    pinLoc = pinNum << CY_GPIO_CFG_RES_PULLUP_MODE_OFFSET;
    tempReg = (GPIO_PRT_CFG_RES(base) & ~(CY_GPIO_CFG_RES_PULLUP_MODE_MASK << pinLoc));
    prtCfg = tempReg | ((value & CY_GPIO_CFG_RES_PULLUP_MODE_MASK) << pinLoc);

    GPIO_PRT_CFG_RES(base) = prtCfg;
}

/*******************************************************************************
* Function Name: Cy_GPIO_GetPullupResistance
****************************************************************************//**
*
* Returns the Pull-up mode of GPIO Pin.
*
* \param base
* Pointer to the pin's port register base address
*
* \param pinNum
* Position of the pin bit-field within the port register
*
* \return
* Pull-up mode. Options are detailed in \ref group_gpio_PullUpMode macros
*
* \funcusage
* \snippet gpio/snippet/main.c snippet_Cy_GPIO_SetPullupResistance
*
*******************************************************************************/
uint32_t Cy_GPIO_GetPullupResistance(GPIO_PRT_Type* base, uint32_t pinNum)
{
    uint32_t tempReg;

    CY_ASSERT_L2(CY_GPIO_IS_PIN_VALID(pinNum));

    tempReg = GPIO_PRT_CFG_RES(base);

    return ((tempReg >> (pinNum << CY_GPIO_CFG_RES_PULLUP_MODE_OFFSET)) & CY_GPIO_CFG_RES_PULLUP_MODE_MASK);
}
#endif /* CY_IP_MXS22IOSS */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40SIOSS, CY_IP_MXS40IOSS, CY_IP_MXS22IOSS */
/* [] END OF FILE */
