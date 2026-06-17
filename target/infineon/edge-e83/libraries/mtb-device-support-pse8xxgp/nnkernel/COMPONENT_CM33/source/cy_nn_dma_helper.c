/***************************************************************************//**
 * \file  cy_nn_dma_helper.c
 * \version 1.0
 *
 * \brief
 * Provides helper function for nnlite kernel
 *
 ********************************************************************************
 * \copyright
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
#include "cy_nn_kernel.h"
#if CY_IP_MXNNLITE_VERSION == 2
#include "cy_nn_kernel_private.h"
#if CY_NNLITE_DMA_DEVICE
#include <string.h>
#include <stdlib.h>


/**
 *****************************************************************************
 ** \brief API will initialize DMA Channel with DMA descriptor
 **
 ** [in]  channelConfig DMA channel configuration
 ** [in]  desc dma descriptor
 **
 *****************************************************************************/
void Cy_NNLite_DMAChannelInit(cy_stc_dma_channel_config_t *channelConfig,
                              cy_stc_dma_descriptor_t *desc)
{
  channelConfig->descriptor = desc;
  channelConfig->preemptable = false;
  channelConfig->priority = 3;
  channelConfig->enable = false;
  channelConfig->bufferable = false;
  Cy_DMA_Channel_Init(DW0, NNLITE_DMA_CHAN, channelConfig);
}

/**
 *****************************************************************************
 ** \brief API will Link DMA Descriptor in DMA Queue and will update
 ** prev and curr desc pointer in nnliteDMAQ structure
 **
 ** [in]  nnliteDMAQ structure maintaining DMA Queue pointers
 ** [in]  desc dma descriptor
 ** [in]  cfgDesc dma config descriptor
 ** [in]  descCount array count of desc to be linked
 **
 *****************************************************************************/
void Cy_NNLite_LinkDMADesc(
                cy_nnlite_dma_queue_config_t *nnliteDMAQ,
                cy_stc_dma_descriptor_t *desc,
                cy_stc_dma_descriptor_config_t *cfgDesc,
                uint8_t descCount)
{
    if (NULL != nnliteDMAQ->currCfgDesc)
    {
       /* link new descriptor to current queued */
        nnliteDMAQ->currCfgDesc->nextDescriptor = desc;
        Cy_DMA_Descriptor_SetNextDescriptor(nnliteDMAQ->currDesc, desc);
    }
    else
    {
       nnliteDMAQ->headDesc = desc;
    }
    /* updated current pointer of queue */
    nnliteDMAQ->currCfgDesc = cfgDesc + (descCount - 1);
    nnliteDMAQ->currDesc = desc + (descCount - 1);
}

/**
 *****************************************************************************
 ** \brief API will setup DMA Descriptors for kernel layer
 **
 ** [in]  nnliteMemio NNLite MEMIO structure for DMA mode
 ** [in]  nnliteDMAQ structure maintaining DMA Queue pointers
 ** [in]  cfgDesc dma config descriptor
 **
 *****************************************************************************/
void Cy_NNLite_SetupNNLiteMemioDMADesc(
         NNLITE_Type *nnliteMemio,
         cy_nnlite_dma_queue_config_t *nnliteDMAQ,
         cy_stc_dma_descriptor_config_t *cfgDesc,
         cy_stc_dma_descriptor_t *desc)
{
  if (nnliteDMAQ->dmaQState == CY_NNLITE_DMA_QUEUE_DONE)
  {
    /* new queue setup */
    Cy_NNlite_MarkDMAQueueEmpty(nnliteDMAQ);
    /* no pending descriptor, immediate trigger */
    cfgDesc->retrigger = CY_DMA_RETRIG_IM;
  }
  else if ((nnliteDMAQ->dmaQDepth == 0) ||
            (nnliteDMAQ->currDescType != CY_NNLITE_DMA_DESC_MEMIO))
  {
    /* no pending descriptor, immediate trigger */
    cfgDesc->retrigger = CY_DMA_RETRIG_IM;
  }
  else
  {
     /* wait for next trigger */
    cfgDesc->retrigger = CY_DMA_WAIT_FOR_REACT;
  }
  nnliteMemio->INTR = NNLITE_INTR_ENABLE_MASK;
  cfgDesc->interruptType = CY_DMA_DESCR_CHAIN;
  cfgDesc->triggerInType = CY_DMA_DESCR;
  cfgDesc->triggerOutType = CY_DMA_DESCR;
  cfgDesc->channelState = CY_DMA_CHANNEL_ENABLED;
  cfgDesc->dataSize = CY_DMA_WORD;
  cfgDesc->srcTransferSize = CY_DMA_TRANSFER_SIZE_WORD;
  cfgDesc->dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD;
  cfgDesc->descriptorType = CY_DMA_1D_TRANSFER;
  cfgDesc->srcAddress = (void *)&nnliteMemio->WEIGHTSTREAMERBASEADDR;
  cfgDesc->dstAddress = (void *)&MXNNLITE_2_0->WEIGHTSTREAMERBASEADDR;
  cfgDesc->srcXincrement = 1;
  cfgDesc->dstXincrement = 1;
  cfgDesc->xCount = NNLITE_DESC_LENGTH;
  cfgDesc->srcYincrement = 1;
  cfgDesc->dstYincrement = 1;
  cfgDesc->yCount = 1;
  cfgDesc->nextDescriptor = NULL;
  Cy_DMA_Descriptor_Init(desc, cfgDesc);
  Cy_NNLite_LinkDMADesc(nnliteDMAQ, desc, cfgDesc, DESC_COUNT_PER_LAYER);
  nnliteDMAQ->currDescType = CY_NNLITE_DMA_DESC_MEMIO;
  nnliteDMAQ->dmaQDepth++;
  nnliteDMAQ->dmaQState = CY_NNLITE_DMA_OPERATION_QUEUED;
}

/**
 *****************************************************************************
 ** \brief API will Cleanup DMA Queue
 **
 ** [in]  nnliteDMAQ structure maintaining DMA Queue pointers
 **
 *****************************************************************************/
void Cy_NNlite_MarkDMAQueueEmpty(cy_nnlite_dma_queue_config_t *nnliteDMAQ)
{
  Cy_DMA_Channel_Disable(DW0, NNLITE_DMA_CHAN);
  /* disable DMA interrupt */
  Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, 0);
  nnliteDMAQ->dmaQDepth = 0;
  nnliteDMAQ->dmaQState = CY_NNLITE_DMA_QUEUE_EMPTY;
  nnliteDMAQ->currCfgDesc = NULL;
  nnliteDMAQ->currDesc = NULL;
  nnliteDMAQ->headDesc = NULL;
}
#endif //CY_NNLITE_DMA_DEVICE
#endif //CY_IP_MXNNLITE_VERSION
