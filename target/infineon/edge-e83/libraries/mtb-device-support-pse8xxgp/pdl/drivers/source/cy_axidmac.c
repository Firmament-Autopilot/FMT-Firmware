/***************************************************************************//**
* \file cy_axidmac.c
* \version 1.0
*
* \brief
* The source code file for the AXIDMAC driver.
*
********************************************************************************
* \copyright
* Copyright 2018-2025 Cypress Semiconductor Corporation
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

#if defined (CY_IP_MXSAXIDMAC) || defined (CY_IP_MXAXIDMAC)

#include "cy_axidmac.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.3', 5, \
'Implicit conversion from essential type "unsigned 32-bit int" to different or narrower essential type "signed 16-bit int".')

/*******************************************************************************
* Function Name: Cy_AXIDMAC_Descriptor_Init
****************************************************************************//**
*
* Initializes the descriptor structure in SRAM from a pre-initialized
* configuration structure.
* This function initializes only the descriptor and not the channel.
*
*******************************************************************************/
cy_en_axidmac_status_t Cy_AXIDMAC_Descriptor_Init(cy_stc_axidmac_descriptor_t * descriptor, const cy_stc_axidmac_descriptor_config_t * config)
{
    cy_en_axidmac_status_t ret = CY_AXIDMAC_BAD_PARAM;

    if ((NULL != descriptor) && (NULL != config))
    {
        CY_ASSERT_L3(CY_AXIDMAC_IS_RETRIGGER_VALID(config->retrigger));
        CY_ASSERT_L3(CY_AXIDMAC_IS_TRIG_TYPE_VALID(config->interruptType));
        CY_ASSERT_L3(CY_AXIDMAC_IS_TRIG_TYPE_VALID(config->triggerOutType));
        CY_ASSERT_L3(CY_AXIDMAC_IS_TRIG_TYPE_VALID(config->triggerInType));
        CY_ASSERT_L3(CY_AXIDMAC_IS_CHANNEL_STATE_VALID(config->channelState));
        CY_ASSERT_L3(CY_AXIDMAC_IS_TYPE_VALID(config->descriptorType));

        descriptor->ctl =
            _VAL2FLD(AXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT, config->retrigger) |
            _VAL2FLD(AXI_DMAC_CH_DESCR_CTL_INTR_TYPE, config->interruptType) |
            _VAL2FLD(AXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE, config->triggerOutType) |
            _VAL2FLD(AXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE, config->triggerInType) |
           _BOOL2FLD(AXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH, config->dataPrefetch) |
            _VAL2FLD(AXI_DMAC_CH_DESCR_CTL_CH_DISABLE, config->channelState) |
            _VAL2FLD(AXI_DMAC_CH_DESCR_CTL_DESCR_TYPE, config->descriptorType);

        descriptor->src = (uint32_t)config->srcAddress;

        Cy_AXIDMAC_Descriptor_SetDstAddress(descriptor, config->dstAddress);

        Cy_AXIDMAC_Descriptor_SetMloopDataCount(descriptor, config->mCount);

        if(CY_AXIDMAC_1D_MEMORY_COPY != config->descriptorType)
        {
            Cy_AXIDMAC_Descriptor_SetXloopDataCount(descriptor, config->xCount);
        }

        Cy_AXIDMAC_Descriptor_SetNextDescriptor(descriptor, config->nextDescriptor);

        if((CY_AXIDMAC_2D_MEMORY_COPY == config->descriptorType) ||
           (CY_AXIDMAC_3D_MEMORY_COPY == config->descriptorType))
        {

            descriptor->xIncr = _VAL2FLD(AXI_DMAC_CH_DESCR_X_INCR_SRC_X, config->srcXincrement) |
                                _VAL2FLD(AXI_DMAC_CH_DESCR_X_INCR_DST_X, config->dstXincrement);
        }

        if(CY_AXIDMAC_3D_MEMORY_COPY == config->descriptorType)
        {
            Cy_AXIDMAC_Descriptor_SetYloopDataCount(descriptor, config->yCount);

            descriptor->yIncr = _VAL2FLD(AXI_DMAC_CH_DESCR_Y_INCR_SRC_Y, config->srcYincrement) |
                                _VAL2FLD(AXI_DMAC_CH_DESCR_Y_INCR_DST_Y, config->dstYincrement);
        }

        ret = CY_AXIDMAC_SUCCESS;
    }

    return ret;
}


/*******************************************************************************
* Function Name: Cy_AXIDMAC_Descriptor_DeInit
****************************************************************************//**
*
* Clears the content of the specified descriptor.
*
*******************************************************************************/
void Cy_AXIDMAC_Descriptor_DeInit(cy_stc_axidmac_descriptor_t * descriptor)
{
    descriptor->ctl = 0UL;
    descriptor->src = 0UL;
    descriptor->dst = 0UL;
    descriptor->mSize = 0UL;
    descriptor->xSize = 0UL;
    descriptor->xIncr = 0UL;
    descriptor->ySize = 0UL;
    descriptor->yIncr = 0UL;
    descriptor->nextPtr = 0UL;
}


/*******************************************************************************
* Function Name: Cy_AXIDMAC_Channel_Init
****************************************************************************//**
*
* Initializes the AXIDMAC channel with a descriptor and other parameters.
*
*
*******************************************************************************/
cy_en_axidmac_status_t Cy_AXIDMAC_Channel_Init(AXI_DMAC_Type * base, uint32_t channel, cy_stc_axidmac_channel_config_t const * config)
{
    cy_en_axidmac_status_t ret = CY_AXIDMAC_BAD_PARAM;

    if ((NULL != base) && (CY_AXIDMAC_IS_CH_NR_VALID(channel)) && (NULL != config) && (NULL != config->descriptor))
    {
        CY_ASSERT_L2(CY_AXIDMAC_IS_PRIORITY_VALID(config->priority));

        /* Set the current descriptor */
        AXIDMAC_CH_CURR(base, channel) = (uint32_t)config->descriptor;

        /* Set the channel configuration */
        AXIDMAC_CH_CTL(base, channel) = _VAL2FLD(AXI_DMAC_CH_CTL_PRIO,    config->priority) |
                                    _BOOL2FLD(AXI_DMAC_CH_CTL_ENABLED, config->enable)   |
                                    _BOOL2FLD(AXI_DMAC_CH_CTL_B,       config->bufferable);
        ret = CY_AXIDMAC_SUCCESS;
    }

    return (ret);
}


/*******************************************************************************
* Function Name: Cy_AXIDMAC_Channel_DeInit
****************************************************************************//**
*
* Clears the content of registers corresponding to the channel.
*
*
*******************************************************************************/
void Cy_AXIDMAC_Channel_DeInit(AXI_DMAC_Type * base, uint32_t channel)
{
    CY_ASSERT_L1(CY_AXIDMAC_IS_CH_NR_VALID(channel));

    AXIDMAC_CH_CTL(base, channel) = 0UL;
    AXIDMAC_CH_CURR(base, channel) = 0UL;
    AXIDMAC_CH_INTR_MASK(base, channel) = 0UL;
}


/*******************************************************************************
* Function Name: Cy_AXIDMAC_Descriptor_GetXloopDataCount
****************************************************************************//**
*
* Returns the number of data elements for the X loop of the specified
* descriptor (for 2D and 3D memory copy descriptors).
*
*******************************************************************************/
uint32_t Cy_AXIDMAC_Descriptor_GetXloopDataCount(cy_stc_axidmac_descriptor_t const * descriptor)
{
    uint32_t retVal = 0UL;

    CY_ASSERT_L1(CY_AXIDMAC_1D_MEMORY_COPY != Cy_AXIDMAC_Descriptor_GetDescriptorType(descriptor));


     /* Convert the data count from the machine range (0-65535) into the user's range (1-65536). */
     retVal = _FLD2VAL(AXI_DMAC_CH_DESCR_X_SIZE_X_COUNT, descriptor->xSize) + 1UL;

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_AXIDMAC_Descriptor_SetXloopDataCount
****************************************************************************//**
*
* Sets the number of data elements to transfer in the X loop
* for the specified descriptor (for 2D and 3D memory copy descriptors).
*
*******************************************************************************/
void Cy_AXIDMAC_Descriptor_SetXloopDataCount(cy_stc_axidmac_descriptor_t * descriptor, uint32_t xCount)
{

    CY_ASSERT_L1(CY_AXIDMAC_1D_MEMORY_COPY != Cy_AXIDMAC_Descriptor_GetDescriptorType(descriptor));

    CY_ASSERT_L2(CY_AXIDMAC_IS_LOOP_COUNT_VALID(xCount));
    /* Convert the data count from the user's range (1-65536) into the machine range (0-65535). */
    descriptor->xSize = _VAL2FLD(AXI_DMAC_CH_DESCR_X_SIZE_X_COUNT, xCount - 1UL);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetNextDescriptor
****************************************************************************//**
*
* Sets a Next Descriptor parameter for the specified descriptor.
*
* Based on the descriptor type, the offset of the address for the next descriptor
* register may vary:
* For the 1D memory copy descriptor type, this register is at offset 0x10.
* For the 2D memory copy descriptor type, this register is at offset 0x18.
* For the 3D memory copy descriptor type, this register is at offset 0x20.
*
*******************************************************************************/
void Cy_AXIDMAC_Descriptor_SetNextDescriptor(cy_stc_axidmac_descriptor_t * descriptor, cy_stc_axidmac_descriptor_t const * nextDescriptor)
{
    CY_ASSERT_L1(NULL != descriptor);
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_axidmac_descriptor_type_t enum.');
    switch((cy_en_axidmac_descriptor_type_t)_FLD2VAL(AXI_DMAC_CH_DESCR_CTL_DESCR_TYPE, descriptor->ctl))
    {
        case CY_AXIDMAC_1D_MEMORY_COPY:
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_axidmac_dscr_1d_t.');
            ((cy_stc_axidmac_dscr_1d_t*)descriptor)->nextPtr = (uint32_t)nextDescriptor;
            break;

        case CY_AXIDMAC_2D_MEMORY_COPY:
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_axidmac_dscr_2d_t.');
            ((cy_stc_axidmac_dscr_2d_t*)descriptor)->nextPtr = (uint32_t)nextDescriptor;
            break;

        case CY_AXIDMAC_3D_MEMORY_COPY:
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_axidmac_dscr_3d_t.');
            ((cy_stc_axidmac_dscr_3d_t*)descriptor)->nextPtr = (uint32_t)nextDescriptor;
            break;

        default:
            /* Unsupported type of descriptor */
            break;
    }
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetNextDescriptor
****************************************************************************//**
*
* Returns a next descriptor address of the specified descriptor.
*
* Based on the descriptor type, the offset of the address for the next descriptor
* register may vary:
* For the 1D memory copy descriptor type, this register is at offset 0x10.
* For the 2D memory copy descriptor type, this register is at offset 0x18.
* For the 3D memory copy descriptor type, this register is at offset 0x20.
*
*
*******************************************************************************/
cy_stc_axidmac_descriptor_t * Cy_AXIDMAC_Descriptor_GetNextDescriptor(cy_stc_axidmac_descriptor_t const * descriptor)
{
    uint32_t retVal = 0UL;
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_axidmac_descriptor_type_t enum.');
    switch((cy_en_axidmac_descriptor_type_t)_FLD2VAL(AXI_DMAC_CH_DESCR_CTL_DESCR_TYPE, descriptor->ctl))
    {

        case CY_AXIDMAC_1D_MEMORY_COPY:
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_axidmac_dscr_1d_t.');
            retVal = ((cy_stc_axidmac_dscr_1d_t const*)descriptor)->nextPtr;
            break;

        case CY_AXIDMAC_2D_MEMORY_COPY:
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_axidmac_dscr_2d_t.');
            retVal = ((cy_stc_axidmac_dscr_2d_t const*)descriptor)->nextPtr;
            break;

        case CY_AXIDMAC_3D_MEMORY_COPY:
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_axidmac_dscr_3d_t.');
            retVal = ((cy_stc_axidmac_dscr_3d_t const*)descriptor)->nextPtr;
            break;

        default:
            /* An unsupported type of the descriptor */
            break;
    }

    return ((cy_stc_axidmac_descriptor_t*)retVal);
}


/*******************************************************************************
* Function Name: Cy_AXIDMAC_Descriptor_SetDescriptorType
****************************************************************************//**
*
* Sets the descriptor's type for the specified descriptor.
* Moves the next descriptor pointer and M data count values into the proper
* offset in accordance to the actual descriptor type.
*
* During the descriptor's type change, carefully set up the settings starting
* from dstAddress and all the rest below in the \ref cy_stc_axidmac_descriptor_config_t
* structure. This is because the content of the descriptor registers might be
* lost/overridden by other descriptor settings due to the
* different registers structure for different descriptor types.
*
*******************************************************************************/
void Cy_AXIDMAC_Descriptor_SetDescriptorType(cy_stc_axidmac_descriptor_t * descriptor, cy_en_axidmac_descriptor_type_t descriptorType)
{
    CY_ASSERT_L3(CY_AXIDMAC_IS_TYPE_VALID(descriptorType));

    if (descriptorType != Cy_AXIDMAC_Descriptor_GetDescriptorType(descriptor)) /* Do not perform if the type is not changed */
    {
        /* Store the current nextDescriptor pointer. */
        cy_stc_axidmac_descriptor_t const *locNextDescriptor = Cy_AXIDMAC_Descriptor_GetNextDescriptor(descriptor);
        /* Store the current M data counter. */
        uint32_t locMcount = Cy_AXIDMAC_Descriptor_GetMloopDataCount(descriptor);
        /* Change the descriptor type. */
        CY_REG32_CLR_SET(descriptor->ctl, AXI_DMAC_CH_DESCR_CTL_DESCR_TYPE, descriptorType);
        /* Restore the current M data counter. */
        Cy_AXIDMAC_Descriptor_SetMloopDataCount(descriptor, locMcount);
        /* Restore the nextDescriptor pointer into the proper place. */
        Cy_AXIDMAC_Descriptor_SetNextDescriptor(descriptor, locNextDescriptor);
    }
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.3')
#endif /* CY_IP_MXSAXIDMAC || CY_IP_MXAXIDMAC */

/* [] END OF FILE */
