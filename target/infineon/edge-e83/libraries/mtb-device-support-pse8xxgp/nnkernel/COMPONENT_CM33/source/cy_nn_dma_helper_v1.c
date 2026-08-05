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
#if CY_IP_MXNNLITE_VERSION ==1
#include "cy_nn_kernel_private_v1.h"
#include <string.h>
#include <stdlib.h>

/**
 *****************************************************************************
 ** \brief API will setup transpose DMA Descriptors
 **
 ** [in]  nnliteDMAQ DMA Queue configuration
 ** [in]  srcAddress source address
 ** [in]  dstAddress destination address
 ** [in]  heightTimeWidth height times width
 ** [in]  channel channel or output depth
 ** [in]  cfgDesc dma configuration descriptor
 ** [in]  desc dma descriptor
 ** [in]  descCnt count for pare of cfgDesc and desc
 **
 *****************************************************************************/
void Cy_NNLite_SetupTransposeDMADesc(cy_nnlite_dma_queue_config_t *nnliteDMAQ,
                          int8_t *srcAddress, int8_t *dstAddress,
                          uint32_t heightTimeWidth, uint32_t channel,
                          cy_stc_dma_descriptor_config_t *cfgDesc,
                          cy_stc_dma_descriptor_t *desc,
                           uint8_t descCnt, cy_nnlite_dma_xmode_t mode)
{

  int8_t *dstTemp, *srcTemp;
  uint32_t xferLength;

  /* heightTimeWidth is with in max value
     use 2D DMA
  */
  if (heightTimeWidth <= CY_DMA_LOOP_COUNT_MAX)
  {
    if (nnliteDMAQ->dmaQDepth == 0)
    {
      /* no pending descriptor, immediate trigger */
      cfgDesc->retrigger = CY_DMA_RETRIG_IM;
    }
    else
    {
      /* wait for next trigger */
      cfgDesc->retrigger = CY_DMA_WAIT_FOR_REACT;
    }
    cfgDesc->interruptType = CY_DMA_DESCR_CHAIN;
    cfgDesc->triggerOutType = CY_DMA_DESCR_CHAIN;
    cfgDesc->channelState = CY_DMA_CHANNEL_ENABLED;
    cfgDesc->triggerInType = CY_DMA_DESCR_CHAIN;
    cfgDesc->dataSize = CY_DMA_BYTE;
    cfgDesc->srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA;
    cfgDesc->dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA;
    cfgDesc->descriptorType = CY_DMA_2D_TRANSFER;
    cfgDesc->srcAddress = srcAddress;
    cfgDesc->dstAddress = dstAddress;
    cfgDesc->yCount =  heightTimeWidth;
    cfgDesc->xCount = channel;
    if (mode == CY_NNLITE_DMA_CHW_TO_HWC)
    {
      cfgDesc->srcXincrement = heightTimeWidth;
      cfgDesc->srcYincrement = 1;
      cfgDesc->dstXincrement = 1;
      cfgDesc->dstYincrement = channel;

    }
    else
    {
      cfgDesc->srcXincrement = 1;
      cfgDesc->srcYincrement = channel;
      cfgDesc->dstYincrement = 1;
      cfgDesc->dstXincrement = heightTimeWidth;
    }
    cfgDesc->nextDescriptor = NULL;
    Cy_DMA_Descriptor_Init(desc, cfgDesc);

  }
  /* heightTimeWidth is with in Xincrement max value
     2D DMA, split in two multiple descriptors
  */
  else if (heightTimeWidth <= CY_DMA_LOOP_INCREMENT_MAX)
  {
    xferLength = heightTimeWidth;
    srcTemp = srcAddress;
    dstTemp = dstAddress;
    for (int i = 0; i < descCnt; i++)
    {
      if ((i == 0) && (nnliteDMAQ->dmaQDepth != 0))
      {
        /* wait for next trigger */
        cfgDesc[i].retrigger = CY_DMA_WAIT_FOR_REACT;
      }
      else
      {
        /* no pending descriptor, immediate trigger */
       cfgDesc[i].retrigger = CY_DMA_RETRIG_IM;
      }
      cfgDesc[i].interruptType = CY_DMA_DESCR_CHAIN;
      cfgDesc[i].triggerOutType = CY_DMA_DESCR_CHAIN;
      cfgDesc[i].channelState = CY_DMA_CHANNEL_ENABLED;
      cfgDesc[i].triggerInType = CY_DMA_DESCR_CHAIN;
      cfgDesc[i].dataSize = CY_DMA_BYTE;
      cfgDesc[i].srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA;
      cfgDesc[i].dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA;
      cfgDesc[i].descriptorType = CY_DMA_2D_TRANSFER;

      cfgDesc[i].srcAddress = srcTemp;
      cfgDesc[i].dstAddress = dstTemp;
      if (mode == CY_NNLITE_DMA_CHW_TO_HWC)
      {
        cfgDesc[i].srcXincrement = heightTimeWidth;
        cfgDesc[i].srcYincrement = 1;
        cfgDesc[i].dstXincrement = 1;
        cfgDesc[i].dstYincrement = channel;
        srcTemp += CY_DMA_LOOP_COUNT_MAX;
        dstTemp += (CY_DMA_LOOP_COUNT_MAX * channel);
      }
      else
      {
        cfgDesc[i].srcXincrement = 1;
        cfgDesc[i].srcYincrement = channel;
        cfgDesc[i].dstYincrement = 1;
        cfgDesc[i].dstXincrement = heightTimeWidth;
        srcTemp += (CY_DMA_LOOP_COUNT_MAX * channel);
        dstTemp += (CY_DMA_LOOP_COUNT_MAX);
      }

      cfgDesc[i].xCount = channel;

      if (xferLength > CY_DMA_LOOP_COUNT_MAX)
      {
        cfgDesc[i].yCount = CY_DMA_LOOP_COUNT_MAX;
        cfgDesc[i].nextDescriptor = &desc[i + 1];
        xferLength -= (CY_DMA_LOOP_COUNT_MAX);
      }
      else
      {
        cfgDesc[i].yCount = xferLength;
        cfgDesc[i].nextDescriptor = NULL;
      }

      Cy_DMA_Descriptor_Init(desc + i, cfgDesc + i);

    }

  }
  /* heightTimeWidth exceed max value for Xincrement,
    Only 1D DMA is possible, split across multiple
    Descriptors
 */
  else
  {
    uint32_t perChanDesc;

    perChanDesc = (heightTimeWidth + (CY_DMA_LOOP_COUNT_MAX - 1)) /
                  CY_DMA_LOOP_COUNT_MAX;

    for (uint32_t i = 0; i < channel; i++)
    {
      if (mode == CY_NNLITE_DMA_CHW_TO_HWC)
      {
        srcTemp = srcAddress + (i * heightTimeWidth);
        dstTemp = dstAddress + i;
      }
      else
      {
        dstTemp = dstAddress + (i * heightTimeWidth);
        srcTemp = srcAddress + i;
      }
      xferLength = heightTimeWidth;
      for (uint32_t j = 0; j < perChanDesc; j++)
      {
        uint32_t index = (i * perChanDesc) + j;
        if ((index == 0) && (nnliteDMAQ->dmaQDepth != 0))
        {
          /* wait for next trigger */
         cfgDesc[index].retrigger = CY_DMA_WAIT_FOR_REACT;
        }
        else
        {
          /* no pending descriptor, immediate trigger */
         cfgDesc[index].retrigger = CY_DMA_RETRIG_IM;
        }
        cfgDesc[index].interruptType = CY_DMA_DESCR_CHAIN;
        cfgDesc[index].triggerOutType = CY_DMA_DESCR_CHAIN;
        cfgDesc[index].channelState = CY_DMA_CHANNEL_ENABLED;
        cfgDesc[index].triggerInType = CY_DMA_DESCR_CHAIN;
        cfgDesc[index].dataSize = CY_DMA_BYTE;
        cfgDesc[index].srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA;
        cfgDesc[index].dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA;
        cfgDesc[index].descriptorType = CY_DMA_1D_TRANSFER;
        cfgDesc[index].srcAddress = srcTemp;
        cfgDesc[index].dstAddress = dstTemp;
        if (xferLength > CY_DMA_LOOP_COUNT_MAX)
        {
          cfgDesc[index].xCount = CY_DMA_LOOP_COUNT_MAX;
          xferLength -= (CY_DMA_LOOP_COUNT_MAX);
        }
        else
        {
          cfgDesc[index].xCount = xferLength;
        }
        if (mode == CY_NNLITE_DMA_CHW_TO_HWC)
        {
          cfgDesc[index].srcXincrement = 1;
          cfgDesc[index].dstXincrement = channel;
          srcTemp += cfgDesc[index].xCount;
          dstTemp += (cfgDesc[index].xCount * channel);
        }
        else
        {
          cfgDesc[index].srcXincrement = channel;
          cfgDesc[index].dstXincrement = 1;
          srcTemp += (cfgDesc[index].xCount * channel);
          dstTemp += cfgDesc[index].xCount;
        }

        cfgDesc[index].nextDescriptor = &desc[index + 1];
        Cy_DMA_Descriptor_Init(desc + index, cfgDesc + index);
      }
    }

  }

}

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
 ** \brief API will Trigger Transpose DMA, only used for CPU mode convolution,
 ** In pure DMA mode, transpose descriptor will be linked with
 ** convolution
 **
 ** [in]  channelConfig DMA channel configuration
 ** [in]  desc dma descriptor
 **
 *****************************************************************************/
void Cy_NNLite_TriggerTransposeDMA(cy_stc_dma_channel_config_t *channelConfig,
                                   cy_stc_dma_descriptor_t *desc)
{
  Cy_NNLite_DMAChannelInit(channelConfig, desc);
  Cy_DMA_Channel_Enable(DW0, NNLITE_DMA_CHAN);
  Cy_DMA_Channel_ClearInterrupt(DW0, NNLITE_DMA_CHAN);
  Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, CY_DMA_INTR_MASK);
  Cy_TrigMux_SwTrigger(PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN0 + NNLITE_DMA_CHAN,
      CY_TRIGGER_TWO_CYCLES);
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
         cy_nnlite_memio_dma_t *nnliteMemio,
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
  cfgDesc->interruptType = CY_DMA_DESCR_CHAIN;
  cfgDesc->triggerOutType = CY_DMA_DESCR_CHAIN;
  cfgDesc->channelState = CY_DMA_CHANNEL_ENABLED;
  cfgDesc->triggerInType = CY_DMA_DESCR_CHAIN;
  cfgDesc->dataSize = CY_DMA_WORD;
  cfgDesc->srcTransferSize = CY_DMA_TRANSFER_SIZE_WORD;
  cfgDesc->dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD;
  cfgDesc->descriptorType = CY_DMA_1D_TRANSFER;
  cfgDesc->srcAddress = (void *)nnliteMemio;
  cfgDesc->dstAddress = (void *)&MXNNLITE_1_0->WEIGHTSTREAMERBASEADDR;
  cfgDesc->srcXincrement = 1;
  cfgDesc->dstXincrement = 1;
  cfgDesc->xCount = NNLITE_DESC_0_LENGTH;
  cfgDesc->srcYincrement = 1;
  cfgDesc->dstYincrement = 1;
  cfgDesc->yCount = 1;
  cfgDesc->nextDescriptor = desc + 1;

  /* layer 1 desc config 1 */
  (cfgDesc + 1)->retrigger = CY_DMA_RETRIG_IM;
  (cfgDesc + 1)->interruptType = CY_DMA_DESCR_CHAIN;
  (cfgDesc + 1)->interruptType = CY_DMA_DESCR_CHAIN;
  (cfgDesc + 1)->triggerOutType = CY_DMA_DESCR;
  (cfgDesc + 1)->channelState = CY_DMA_CHANNEL_ENABLED;
  (cfgDesc + 1)->triggerInType = CY_DMA_DESCR;
  (cfgDesc + 1)->dataSize = CY_DMA_WORD;
  (cfgDesc + 1)->srcTransferSize = CY_DMA_TRANSFER_SIZE_WORD;
  (cfgDesc + 1)->dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD;
  (cfgDesc + 1)->descriptorType = CY_DMA_1D_TRANSFER;

  /* need to split xfer in 2 descriptors, due to interpolation
     lookup table which needs to be program twice for interpolation
     param
  */
  (cfgDesc + 1)->srcAddress = (void *)&nnliteMemio->INTERPOLATIONLUTADDR1;
  (cfgDesc + 1)->dstAddress = (void *)&MXNNLITE_1_0->INTERPOLATIONLUTADDR;
  (cfgDesc + 1)->srcXincrement = 1;
  (cfgDesc + 1)->dstXincrement = 1;
  (cfgDesc + 1)->xCount = NNLITE_DESC_1_LENGTH;
  (cfgDesc + 1)->srcYincrement = 1;
  (cfgDesc + 1)->dstYincrement = 1;
  (cfgDesc + 1)->yCount = 1;
  (cfgDesc + 1)->nextDescriptor = NULL;
  Cy_DMA_Descriptor_Init(desc, cfgDesc);
  Cy_DMA_Descriptor_Init((desc + 1),(cfgDesc + 1));
  Cy_NNLite_LinkDMADesc(nnliteDMAQ, desc, cfgDesc, 2);
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
#endif //CY_IP_MXNNLITE_VERSION
