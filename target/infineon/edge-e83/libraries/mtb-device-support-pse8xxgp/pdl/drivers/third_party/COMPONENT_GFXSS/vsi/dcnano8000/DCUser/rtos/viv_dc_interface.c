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


#include "viv_dc_type.h"
#include "viv_dc_util.h"
#include "viv_dc_interface.h"
#include "viv_dc_os.h"
#include "viv_dc_platform.h"

/* Open DC device.
 * This function should be called at the beginning of DC module.
 */
gctINT viv_dc_device_init(
    gctVOID
    )
{
    dev_init();
    viv_os_devmem_open();
    return vivSTATUS_OK;
}

/* Close DC device.
 * This function should be called at the end of DC module.
 */
gctVOID viv_dc_device_deinit(
    gctVOID
    )
{
    viv_os_devmem_close();
    dev_deinit();
    return;
}

gctINT viv_dc_device_call(
    gctPOINTER args
    )
{
    dev_ioctl(VIV_DC_INTERFACE, args);

    return vivSTATUS_OK;
}

/* Initialize other platform related functions.
 * This function should be called after initilizing DC related module.
 */
gctINT viv_dc_platform_init(
    gctPOINTER args
    )
{
    return vivSTATUS_OK;
}

/* Close other platform related functions.
 * This function should be called before close DC related module.
 */
gctVOID viv_dc_platform_deinit(
    gctPOINTER args
    )
{
    return;
}