/*
 * SPDX-FileCopyrightText: Copyright 2019-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*****************************************************************************
 * Includes
 *****************************************************************************/

#include "ethosu_device.h"
#include "ethosu_driver.h"
#include "ethosu_interface.h"
#include "ethosu_log.h"
#include "pmu_ethosu.h"

#include <assert.h>
#include <inttypes.h>
#include <stddef.h>

/*****************************************************************************
 * Defines
 *****************************************************************************/

#define MASK_0_31_BITS (0xFFFFFFFF)
#define MASK_32_47_BITS (0xFFFF00000000)

#define COMMA ,
#define SEMICOLON ;

#define EVTYPE(A, name)                                                                                                \
    case PMU_EVENT_##name:                                                                                             \
        return ETHOSU_PMU_##name

#define EVID(A, name) (PMU_EVENT_##name)

/*****************************************************************************
 * Variables
 *****************************************************************************/

static const enum pmu_event eventbyid[] = {EXPAND_PMU_EVENT(EVID, COMMA)};

/*****************************************************************************
 * Static functions
 *****************************************************************************/

static enum ethosu_pmu_event_type pmu_event_type(uint32_t id)
{
    switch (id)
    {
        EXPAND_PMU_EVENT(EVTYPE, SEMICOLON);
    default:
        LOG_ERR("Unknown PMU event id: 0x%" PRIx32, id);
    }

    return ETHOSU_PMU_SENTINEL;
}

static uint32_t pmu_event_value(enum ethosu_pmu_event_type event)
{
    int a = event;
    if ((a < ETHOSU_PMU_SENTINEL) && (a >= ETHOSU_PMU_NO_EVENT))
    {
        return eventbyid[event];
    }

    return UINT32_MAX;
}

/*****************************************************************************
 * Functions
 *****************************************************************************/

void ETHOSU_PMU_Enable(struct ethosu_driver *drv)
{
    LOG_DEBUG("Enable PMU");
    struct pmcr_r pmcr = {0};
    pmcr.cnt_en        = 1;
    ethosu_request_power(drv);
    drv->dev->reg->PMCR.word = pmcr.word;
}

void ETHOSU_PMU_Disable(struct ethosu_driver *drv)
{
    LOG_DEBUG("Disable PMU");
    drv->dev->reg->PMCR.word = 0;
    ethosu_release_power(drv);
}

uint32_t ETHOSU_PMU_Get_NumEventCounters(void)
{
    return NPU_REG_PMEVCNTR_ARRLEN;
}

void ETHOSU_PMU_Set_EVTYPER(struct ethosu_driver *drv, uint32_t num, enum ethosu_pmu_event_type type)
{
    assert(num < ETHOSU_PMU_NCOUNTERS);
    uint32_t val = pmu_event_value(type);
    if (val == UINT32_MAX)
    {
        LOG_ERR("Invalid ethosu_pmu_event_type: %d", type);
        return;
    }

    LOG_DEBUG("num=%" PRIu32 ", type=%d, val=%" PRIu32, num, type, val);
    drv->dev->reg->PMEVTYPER[num].word = val;
}

enum ethosu_pmu_event_type ETHOSU_PMU_Get_EVTYPER(struct ethosu_driver *drv, uint32_t num)
{
    assert(num < ETHOSU_PMU_NCOUNTERS);
    uint32_t val                    = drv->dev->reg->PMEVTYPER[num].word;
    enum ethosu_pmu_event_type type = pmu_event_type(val);
    LOG_DEBUG("num=%" PRIu32 ", type=%d, val=%" PRIu32, num, type, val);
    return type;
}

void ETHOSU_PMU_CYCCNT_Reset(struct ethosu_driver *drv)
{
    LOG_DEBUG("Reset PMU cycle counter");
    struct pmcr_r pmcr;
    pmcr.word                = drv->dev->reg->PMCR.word;
    pmcr.cycle_cnt_rst       = 1;
    drv->dev->reg->PMCR.word = pmcr.word;
}

void ETHOSU_PMU_EVCNTR_ALL_Reset(struct ethosu_driver *drv)
{
    LOG_DEBUG("Reset all events");
    struct pmcr_r pmcr;
    pmcr.word                = drv->dev->reg->PMCR.word;
    pmcr.event_cnt_rst       = 1;
    drv->dev->reg->PMCR.word = pmcr.word;
}

void ETHOSU_PMU_CNTR_Enable(struct ethosu_driver *drv, uint32_t mask)
{
    LOG_DEBUG("mask=0x%08" PRIx32, mask);
    drv->dev->reg->PMCNTENSET.word = mask;
}

void ETHOSU_PMU_CNTR_Disable(struct ethosu_driver *drv, uint32_t mask)
{
    LOG_DEBUG("mask=0x%08" PRIx32, mask);
    drv->dev->reg->PMCNTENCLR.word = mask;
}

uint32_t ETHOSU_PMU_CNTR_Status(struct ethosu_driver *drv)
{
    uint32_t pmcntenset = drv->dev->reg->PMCNTENSET.word;
    LOG_DEBUG("mask=0x%08" PRIx32, pmcntenset);
    return pmcntenset;
}

uint64_t ETHOSU_PMU_Get_CCNTR(struct ethosu_driver *drv)
{
    uint32_t val_lo = drv->dev->reg->PMCCNTR.CYCLE_CNT_LO;
    uint32_t val_hi = drv->dev->reg->PMCCNTR.CYCLE_CNT_HI;
    uint64_t val    = ((uint64_t)val_hi << 32) | val_lo;

    LOG_DEBUG("val=%" PRIu64, val);
    return val;
}

void ETHOSU_PMU_Set_CCNTR(struct ethosu_driver *drv, uint64_t val)
{
    uint32_t active = ETHOSU_PMU_CNTR_Status(drv) & ETHOSU_PMU_CCNT_Msk;

    LOG_DEBUG("val=%llu", val);

    if (active)
    {
        ETHOSU_PMU_CNTR_Disable(drv, ETHOSU_PMU_CCNT_Msk);
    }

    drv->dev->reg->PMCCNTR.CYCLE_CNT_LO = val & MASK_0_31_BITS;
    drv->dev->reg->PMCCNTR.CYCLE_CNT_HI = (val & MASK_32_47_BITS) >> 32;

    if (active)
    {
        ETHOSU_PMU_CNTR_Enable(drv, ETHOSU_PMU_CCNT_Msk);
    }
}

uint32_t ETHOSU_PMU_Get_EVCNTR(struct ethosu_driver *drv, uint32_t num)
{
    assert(num < ETHOSU_PMU_NCOUNTERS);
    uint32_t val = drv->dev->reg->PMEVCNTR[num].word;
    LOG_DEBUG("num=%" PRIu32 ", val=%" PRIu32, num, val);

    return val;
}

void ETHOSU_PMU_Set_EVCNTR(struct ethosu_driver *drv, uint32_t num, uint32_t val)
{
    assert(num < ETHOSU_PMU_NCOUNTERS);
    LOG_DEBUG("num=%" PRIu32 ", val=%" PRIu32, num, val);
    drv->dev->reg->PMEVCNTR[num].word = val;
}

uint32_t ETHOSU_PMU_Get_CNTR_OVS(struct ethosu_driver *drv)
{
    LOG_DEBUG("");
    return drv->dev->reg->PMOVSSET.word;
}

void ETHOSU_PMU_Set_CNTR_OVS(struct ethosu_driver *drv, uint32_t mask)
{
    LOG_DEBUG("");
    drv->dev->reg->PMOVSCLR.word = mask;
}

void ETHOSU_PMU_Set_CNTR_IRQ_Enable(struct ethosu_driver *drv, uint32_t mask)
{
    LOG_DEBUG("mask=0x%08" PRIx32, mask);
    drv->dev->reg->PMINTSET.word = mask;
}

void ETHOSU_PMU_Set_CNTR_IRQ_Disable(struct ethosu_driver *drv, uint32_t mask)
{
    LOG_DEBUG("mask=0x%08" PRIx32, mask);
    drv->dev->reg->PMINTCLR.word = mask;
}

uint32_t ETHOSU_PMU_Get_IRQ_Enable(struct ethosu_driver *drv)
{
    uint32_t pmint = drv->dev->reg->PMINTSET.word;
    LOG_DEBUG("mask=0x%08" PRIx32, pmint);
    return pmint;
}

void ETHOSU_PMU_CNTR_Increment(struct ethosu_driver *drv, uint32_t mask)
{
    LOG_DEBUG("");
    uint32_t cntrs_active = ETHOSU_PMU_CNTR_Status(drv);

    // Disable counters
    ETHOSU_PMU_CNTR_Disable(drv, mask);

    // Increment cycle counter
    if (mask & ETHOSU_PMU_CCNT_Msk)
    {
        uint64_t val                        = ETHOSU_PMU_Get_CCNTR(drv) + 1;
        drv->dev->reg->PMCCNTR.CYCLE_CNT_LO = val & MASK_0_31_BITS;
        drv->dev->reg->PMCCNTR.CYCLE_CNT_HI = (val & MASK_32_47_BITS) >> 32;
    }

    for (int i = 0; i < ETHOSU_PMU_NCOUNTERS; i++)
    {
        if (mask & (1u << i))
        {
            uint32_t val                    = ETHOSU_PMU_Get_EVCNTR(drv, i);
            drv->dev->reg->PMEVCNTR[i].word = val + 1;
        }
    }

    // Reenable the active counters
    ETHOSU_PMU_CNTR_Enable(drv, cntrs_active);
}

void ETHOSU_PMU_PMCCNTR_CFG_Set_Start_Event(struct ethosu_driver *drv, enum ethosu_pmu_event_type start_event)
{
    LOG_DEBUG("start_event=%u", start_event);
    struct pmccntr_cfg_r cfg;
    uint32_t val = pmu_event_value(start_event);
    if (val == UINT32_MAX)
    {
        LOG_ERR("Invalid ethosu_pmu_event_type: %d", start_event);
        return;
    }

    cfg.word                        = drv->dev->reg->PMCCNTR_CFG.word;
    cfg.CYCLE_CNT_CFG_START         = val;
    drv->dev->reg->PMCCNTR_CFG.word = cfg.word;
}

void ETHOSU_PMU_PMCCNTR_CFG_Set_Stop_Event(struct ethosu_driver *drv, enum ethosu_pmu_event_type stop_event)
{
    LOG_DEBUG("stop_event=%u", stop_event);
    struct pmccntr_cfg_r cfg;
    uint32_t val = pmu_event_value(stop_event);
    if (val == UINT32_MAX)
    {
        LOG_ERR("Invalid ethosu_pmu_event_type: %d", stop_event);
        return;
    }

    cfg.word                        = drv->dev->reg->PMCCNTR_CFG.word;
    cfg.CYCLE_CNT_CFG_STOP          = val;
    drv->dev->reg->PMCCNTR_CFG.word = cfg.word;
}

uint32_t ETHOSU_PMU_Get_QREAD(struct ethosu_driver *drv)
{
    uint32_t val = drv->dev->reg->QREAD.word;
    LOG_DEBUG("qread=%" PRIu32, val);
    return val;
}

uint32_t ETHOSU_PMU_Get_STATUS(struct ethosu_driver *drv)
{
    uint32_t val = drv->dev->reg->STATUS.word;
    LOG_DEBUG("status=0x%" PRIx32, val);
    return val;
}
