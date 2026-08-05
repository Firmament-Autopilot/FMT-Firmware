/***************************************************************************//**
* \file cy_trigmux.c
* \version 1.70
*
* \brief Trigger mux API.
*
********************************************************************************
* \copyright
* Copyright 2016-2025 Cypress Semiconductor Corporation
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

#if defined (CY_IP_MXSPERI) || defined (CY_IP_MXPERI)

#include "cy_trigmux.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 14.3', 4, \
'CY_PERI_V1 is not available for CAT1B devices.')


/*******************************************************************************
* Function Name: Cy_TrigMux_Connect
****************************************************************************//**
*
* Connects an input trigger source and output trigger.
*
* \param inTrig
* An input selection for the trigger mux.
* - Bit 30 should be cleared.
* - Bit 12 should be cleared.
* - Bits 11:8 represent the trigger group selection.
* - Bits 7:0 select the input trigger signal for the specified trigger multiplexer.
*
* \param outTrig
* The output of the trigger mux. This refers to the consumer of the trigger mux.
* - Bit 30 should be set.
* - Bit 12 should be cleared.
* - Bits 11:8 represent the trigger group selection.<br>
*  For PERI_ver1:
* - Bits 6:0 select the output trigger number in the trigger group.<br>
*  For PERI_ver2:
* - Bits 7:0 select the output trigger number in the trigger group.
*
* \param invert
* - true: The output trigger is inverted.
* - false: The output trigger is not inverted.
*
* \param trigType The trigger signal type.
* - TRIGGER_TYPE_EDGE: The trigger is synchronized to the consumer blocks clock
*   and a two-cycle pulse is generated on this clock.
* - TRIGGER_TYPE_LEVEL: The trigger is a simple level output.
*
* \return status:
* - CY_TRIGMUX_SUCCESS: The connection is made successfully.
* - CY_TRIGMUX_BAD_PARAM: Some parameter is invalid.
*
* \funcusage
* \snippet trigmux/snippet/main.c snippet_Cy_TrigMux_Connect
*
*******************************************************************************/
cy_en_trigmux_status_t Cy_TrigMux_Connect(uint32_t inTrig, uint32_t outTrig, bool invert, en_trig_type_t trigType)
{
    cy_en_trigmux_status_t retVal = CY_TRIGMUX_BAD_PARAM;
    CY_ASSERT_L3(CY_TRIGMUX_IS_TRIGTYPE_VALID(trigType));
    CY_ASSERT_L2(CY_TRIGMUX_IS_INTRIG_VALID(inTrig));
    CY_ASSERT_L2(CY_TRIGMUX_IS_OUTTRIG_VALID(outTrig));

    /* inTrig and outTrig should be in the same group */
    if ((inTrig & PERI_TR_CMD_GROUP_SEL_Msk) == (outTrig & PERI_TR_CMD_GROUP_SEL_Msk))
    {
        uint32_t interruptState = Cy_SysLib_EnterCriticalSection();

#if defined (CY_IP_MXSPERI) && (CY_IP_MXSPERI_INSTANCES == 2U)
        if (0UL != (outTrig & PERI_INSTANCE_1_IDENT_Msk))
        {
            CY_TRIGMUX1_TR_CTL(outTrig) = (CY_TRIGMUX1_TR_CTL(outTrig) &
                                      (uint32_t)~(PERI_TR_GR_TR_OUT_CTL_TR_SEL_Msk |
                                                  PERI_TR_GR_TR_OUT_CTL_TR_INV_Msk |
                                                  PERI_TR_GR_TR_OUT_CTL_TR_EDGE_Msk)) |
                                        (_VAL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_SEL, inTrig) |
                                        _BOOL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_INV, invert) |
                                         _VAL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_EDGE, trigType));

        }
        else
        {
            CY_TRIGMUX_TR_CTL(outTrig) = (CY_TRIGMUX_TR_CTL(outTrig) &
                                      (uint32_t)~(PERI_TR_GR_TR_OUT_CTL_TR_SEL_Msk |
                                                  PERI_TR_GR_TR_OUT_CTL_TR_INV_Msk |
                                                  PERI_TR_GR_TR_OUT_CTL_TR_EDGE_Msk)) |
                                        (_VAL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_SEL, inTrig) |
                                        _BOOL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_INV, invert) |
                                         _VAL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_EDGE, trigType));
        }
#else

        CY_TRIGMUX_TR_CTL(outTrig) = (CY_TRIGMUX_TR_CTL(outTrig) &
                                      (uint32_t)~(PERI_TR_GR_TR_OUT_CTL_TR_SEL_Msk |
                                                  PERI_TR_GR_TR_OUT_CTL_TR_INV_Msk |
                                                  PERI_TR_GR_TR_OUT_CTL_TR_EDGE_Msk)) |
                                        (_VAL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_SEL, inTrig) |
                                        _BOOL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_INV, invert) |
                                         _VAL2FLD(PERI_TR_GR_TR_OUT_CTL_TR_EDGE, trigType));
#endif

        Cy_SysLib_ExitCriticalSection(interruptState);

        retVal = CY_TRIGMUX_SUCCESS;
    }

    return retVal;
}


/*******************************************************************************
* Function Name: Cy_TrigMux_Select
****************************************************************************//**
*
* Enables and configures the specified 1-to-1 trigger line. For PERI_ver2 only.
*
* \param outTrig
* The 1to1 trigger line.
* - Bit 30 should be set.
* - Bit 12 should be set.
* - Bits 11:8 represent the 1-to-1 trigger group selection.
* - Bits 7:0 select the trigger line number in the trigger group.
*
* \param invert
* - true: The trigger signal is inverted.
* - false: The trigger signal is not inverted.
*
* \param trigType The trigger signal type.
* - TRIGGER_TYPE_EDGE: The trigger is synchronized to the consumer blocks clock
*   and a two-cycle pulse is generated on this clock.
* - TRIGGER_TYPE_LEVEL: The trigger is a simple level output.
*
* \return status:
* - CY_TRIGMUX_SUCCESS: The selection is made successfully.
* - CY_TRIGMUX_BAD_PARAM: Some parameter is invalid.
*
* \funcusage
* \snippet trigmux/snippet/main.c snippet_Cy_TrigMux_Select
*
*******************************************************************************/
cy_en_trigmux_status_t Cy_TrigMux_Select(uint32_t outTrig, bool invert, en_trig_type_t trigType)
{
    CY_ASSERT_L3(CY_TRIGMUX_IS_TRIGTYPE_VALID(trigType));
    CY_ASSERT_L2(CY_TRIGMUX_IS_ONETRIG_VALID(outTrig));

    uint32_t interruptState;

    interruptState = Cy_SysLib_EnterCriticalSection();

    CY_TRIGMUX_TR_CTL(outTrig) = (CY_TRIGMUX_TR_CTL(outTrig) &
                        (uint32_t)~(PERI_TR_1TO1_GR_V2_TR_CTL_TR_INV_Msk |
                                    PERI_TR_1TO1_GR_V2_TR_CTL_TR_EDGE_Msk)) |
                                    (PERI_TR_1TO1_GR_V2_TR_CTL_TR_SEL_Msk      |
                        _BOOL2FLD(PERI_TR_1TO1_GR_V2_TR_CTL_TR_INV, invert) |
                            _VAL2FLD(PERI_TR_1TO1_GR_V2_TR_CTL_TR_EDGE, trigType));

    Cy_SysLib_ExitCriticalSection(interruptState);

    return CY_TRIGMUX_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_TrigMux_Deselect
****************************************************************************//**
*
* Disables the specified 1-to-1 trigger line. For PERI_ver2 only.
*
* \param outTrig
* The 1to1 trigger line.
* - Bit 30 should be set.
* - Bit 12 should be set.
* - Bits 11:8 represent the 1-to-1 trigger group selection.
* - Bits 7:0 select the trigger line number in the trigger group.
*
* \return status:
* - CY_TRIGMUX_SUCCESS: The deselection is made successfully.
* - CY_TRIGMUX_BAD_PARAM: Some parameter is invalid.
*
* \funcusage
* \snippet trigmux/snippet/main.c snippet_Cy_TrigMux_Deselect
*
*******************************************************************************/
cy_en_trigmux_status_t Cy_TrigMux_Deselect(uint32_t outTrig)
{
    CY_ASSERT_L2(CY_TRIGMUX_IS_ONETRIG_VALID(outTrig));

    uint32_t interruptState;

    interruptState = Cy_SysLib_EnterCriticalSection();

    CY_TRIGMUX_TR_CTL(outTrig) &= (uint32_t)~(PERI_TR_1TO1_GR_V2_TR_CTL_TR_SEL_Msk |
                                                PERI_TR_1TO1_GR_V2_TR_CTL_TR_INV_Msk |
                                                PERI_TR_1TO1_GR_V2_TR_CTL_TR_EDGE_Msk);

    Cy_SysLib_ExitCriticalSection(interruptState);

    return CY_TRIGMUX_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_TrigMux_SetDebugFreeze
****************************************************************************//**
*
* Enables/disables the Debug Freeze feature for the specified trigger
* multiplexer or 1-to-1 trigger line. For PERI_ver2 only.
*
* \param outTrig
* The output of the trigger mux or dedicated 1-to-1 trigger line.
* - Bit 30 should be set.
* - For PERI_ver1 Bits 11:8 represent the trigger group selection.
* - For PERI_ver2 Bits 12:8 represent the trigger group selection.
* - Bits 7:0 select the output trigger number in the trigger group.
*
* \param enable
* - true: The Debug Freeze feature is enabled.
* - false: The Debug Freeze feature is disabled.
*
* \return status:
* - CY_TRIGMUX_SUCCESS: The operation is made successfully.
* - CY_TRIGMUX_BAD_PARAM: The outTrig parameter is invalid.
*
* \funcusage
* \snippet trigmux/snippet/main.c snippet_Cy_TrigMux_SetDebugFreeze
*
*******************************************************************************/
cy_en_trigmux_status_t Cy_TrigMux_SetDebugFreeze(uint32_t outTrig, bool enable)
{
    uint32_t interruptState;

    interruptState = Cy_SysLib_EnterCriticalSection();

    if (enable)
    {
        CY_TRIGMUX_TR_CTL(outTrig) |= PERI_TR_GR_V2_TR_CTL_DBG_FREEZE_EN_Msk;
    }
    else
    {
        CY_TRIGMUX_TR_CTL(outTrig) &= (uint32_t)~PERI_TR_GR_V2_TR_CTL_DBG_FREEZE_EN_Msk;
    }

    Cy_SysLib_ExitCriticalSection(interruptState);

    return CY_TRIGMUX_SUCCESS;
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 14.3')

#endif /* CY_IP_MXSPERI, CY_IP_MXPERI */

/* [] END OF FILE */
