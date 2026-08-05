/***************************************************************************//**
* \file mtb_ml.c
*
* \brief
* The file contains application programming interface to the ModusToolbox ML
* middleware module
*
*******************************************************************************
* (c) 2025-2026, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnity Cypress against all liability.
*******************************************************************************/
#include <inttypes.h>
#include "cy_pdl.h"
#include "mtb_ml.h"

/******************************************************************************
 * Public variables
******************************************************************************/
uint32_t mtb_ml_cpu_clk_freq;
#if defined(COMPONENT_U55) || \
    defined(COMPONENT_NNLITE2)
uint64_t mtb_ml_npu_cycles;
uint32_t mtb_ml_npu_clk_freq;
float mtb_ml_norm_clk_freq;
#endif

#if defined(COMPONENT_U55)
extern struct ethosu_driver ethosu_drv;
#endif

/******************************************************************************
 * Static variables
******************************************************************************/
static uint32_t mtb_ml_init_state = 0;

/*******************************************************************************
 * Public Functions
*******************************************************************************/
#if defined(COMPONENT_U55)
extern cy_rslt_t mtb_ml_ethosu_init(struct ethosu_driver *drv, uint32_t priority);
extern cy_rslt_t mtb_ml_ethosu_deinit(void);
#elif defined(COMPONENT_NNLITE2)
extern cy_rslt_t mtb_ml_nnlite_init(uint32_t priority);
extern cy_rslt_t mtb_ml_nnlite_deinit(void);
#endif

cy_rslt_t mtb_ml_init(uint32_t priority)
{
    cy_rslt_t result = MTB_ML_RESULT_SUCCESS;

    if (mtb_ml_init_state == 0)
    {
        mtb_ml_cpu_clk_freq = (uint32_t)SystemCoreClock;

#if defined(COMPONENT_U55)
        result = mtb_ml_ethosu_init(&ethosu_drv, priority);
#elif defined(COMPONENT_NNLITE2)
        result = mtb_ml_nnlite_init(priority);
#endif

#if defined(COMPONENT_U55) || \
        defined(COMPONENT_NNLITE2)
        mtb_ml_norm_clk_freq = ((float)mtb_ml_npu_clk_freq) / ((float)mtb_ml_cpu_clk_freq);
#endif
    }
    mtb_ml_init_state++;
    return result;
}

cy_rslt_t mtb_ml_deinit(void)
{
    cy_rslt_t result = MTB_ML_RESULT_SUCCESS;
    if (mtb_ml_init_state == 1)
    {
#if defined(COMPONENT_U55)
        result = mtb_ml_ethosu_deinit();
#elif defined(COMPONENT_NNLITE2)
        result = mtb_ml_nnlite_deinit();
#endif
    }
    if (mtb_ml_init_state > 0)
    {
        mtb_ml_init_state--;
    }
    return result;
}

uint32_t mtb_ml_get_init_state(void)
{
    return mtb_ml_init_state;
}
