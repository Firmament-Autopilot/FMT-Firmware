/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright (c) 2014 - 2023 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/


#include "viv_dc_version.h"
#include "viv_dc_os.h"
#include "viv_dc_core.h"
#include "viv_dc_interface.h"
#include "viv_dc_hardware.h"
#if !_BAREMETAL
#include "FreeRTOS.h"
#else
#include <stdlib.h>
#endif
#include "viv_dc_platform.h"
#include "cy_device_headers.h"

/* IFX - EXPEDITION specific */
static gctUINT dcIRQLine = gfxss_interrupt_dc_IRQn;
static gctUINT dcRegisterPhys = (gctUINT)(void *)GFXSS_GFXSS_DC_DCNANO;

viv_dc_os* dcOs = vivNULL;
viv_dc_hardware* dcHardware = vivNULL;
viv_dc_core* dcCore = vivNULL;

static viv_dc_device dcDevice = {0};
static viv_interface iface = {0};
static gctBOOL dcInitialized = vivFALSE;

static gctVOID viv_dc_irq(gctPOINTER p)
{

    if (viv_conf_interrupt_get((viv_dc_core*)p))
    {
    }

}

vivSTATUS register_dc_irq_handler(
    gctUINT irq,
    gctVOID(*handler)(gctPOINTER),
    gctPOINTER data)
{
    /*TODO: register irq handler*/
    return vivSTATUS_OK;
}

vivSTATUS unregister_dc_irq_handler(gctUINT irq)
{
    /*TODO: free irq*/
    return vivSTATUS_OK;
}

static gctVOID viv_dc_show_version(viv_dc_core *core)
{
    gctUINT info, revision, patch, id, product, eco, customer, date, time;

    viv_os_print("Vivante DC version %d.%d.%d\n",
        VIV_DC_VERSION_MAJOR, VIV_DC_VERSION_MINOR, VIV_DC_VERSION_PATCH);

    viv_conf_info_get(core, &id, &revision, &patch, &info, &product, &eco, &customer, &date, &time);

    viv_os_print(
           "Vivante DC hardware:\n"
           "chip id:             0x%08x\n"
           "chip revision:       0x%08x\n"
           "chip patch revision: 0x%08x\n"
           "chip info:           0x%08x\n"
           "product id:          0x%08x\n"
           "eco id:              0x%08x\n"
           "customer id:         0x%08x\n"
           "release date:        0x%08x\n"
           "release time:        0x%08x\n",
           id, revision, patch, info, product, eco, customer, date, time);
}


vivSTATUS dev_init()
{
    if(dcInitialized)
        return vivSTATUS_OK;

#if !_BAREMETAL
    dcOs = (viv_dc_os*)pvPortMalloc(sizeof(viv_dc_os));
    dcHardware = (viv_dc_hardware*)pvPortMalloc(sizeof(viv_dc_hardware));
    dcCore = (viv_dc_core*)pvPortMalloc(sizeof(viv_dc_core));
#else
    dcOs = (viv_dc_os*)malloc(sizeof(viv_dc_os));
    dcHardware = (viv_dc_hardware*)malloc(sizeof(viv_dc_hardware));
    dcCore = (viv_dc_core*)malloc(sizeof(viv_dc_core));
#endif

    if(!dcOs || !dcHardware || !dcCore)
    {
        viv_os_print("%s out of memory.\n", __FUNCTION__);
        /* Out of memory. */
        return vivSTATUS_OOM;
    }

    viv_os_memset(vivNULL, dcOs, 0, sizeof(viv_dc_os));
    viv_os_memset(vivNULL, dcHardware, 0, sizeof(viv_dc_hardware));
    viv_os_memset(vivNULL, dcCore, 0, sizeof(viv_dc_core));
    viv_os_memset(vivNULL, &dcDevice, 0, sizeof(viv_dc_device));

    dcOs->irq = dcIRQLine;
    dcOs->reg_phys_addr = dcRegisterPhys;

    dcHardware->os = dcOs;

    dcCore->os = dcOs;
    dcCore->hardware = dcHardware;

    dcDevice.core[0] = dcCore;

    viv_conf_dc_reset(dcCore);

    viv_dc_show_version(dcCore);

    /* Register irq handler. */
    register_dc_irq_handler(dcIRQLine,
                           viv_dc_irq,
                           (gctPOINTER)dcCore);

    viv_conf_interrupt_enable(dcCore, SET_ENABLE);

    dcInitialized = vivTRUE;

    return vivSTATUS_OK;
}

vivSTATUS dev_deinit()
{

    if(!dcOs || !dcHardware || !dcCore)
        return vivSTATUS_INVALID_ARGUMENTS;

    viv_conf_interrupt_enable(dcCore, SET_DISABLE);
    unregister_dc_irq_handler(dcIRQLine);
#if !_BAREMETAL
    vPortFree((void*)dcOs);
    vPortFree((void*)dcHardware);
    vPortFree((void*)dcCore);
#else
   free((void*)dcOs);
   free((void*)dcHardware);
   free((void*)dcCore);
#endif
    dcOs = vivNULL;
    dcHardware = vivNULL;
    dcCore = vivNULL;

    viv_os_memset(vivNULL, &dcDevice, 0, sizeof(viv_dc_device));
    dcInitialized = vivFALSE;
    return vivSTATUS_OK;
}

gctINT dev_ioctl(gctUINT cmd, gctPOINTER arg)
{
    viv_dc_core **core = dcDevice.core;
    gctUINT touser = 0;

    if (cmd != VIV_DC_INTERFACE) {
        viv_os_print("dev_ioctl: invalid interface\n");
        return -1;
    }

    viv_os_memset(vivNULL, &iface, 0, sizeof(viv_interface));

    viv_os_memcpy(&iface, arg, sizeof(viv_interface));

    viv_conf_ioctl(core, &iface, &touser);

    if (touser) {
        viv_os_memcpy(arg, &iface, sizeof(viv_interface));
    }

    return vivSTATUS_OK;
}
