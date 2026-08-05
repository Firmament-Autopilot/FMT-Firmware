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


#if vivENABLE_LAYER_SCALE
#include "viv_dc_tools.h"
#include "viv_dc_util.h"
#include "math.h"

#ifdef RTOS
#include "viv_dc_os.h"
#else
#include "viv_dc_platform.h"
#endif

/* Stretch factor.
 */
gctUINT32 get_stretch_factor(
    gctUINT32 src_size,
    gctUINT32 dest_size
    )
{
    gctUINT32 stretch_factor = 0;

    if ((src_size > 1) && (dest_size > 1))
    {
        stretch_factor = ((src_size - 1) << 16) / (dest_size - 1);
    }

    return stretch_factor;
}

gctFLOAT sinc_filter(
    gctFLOAT x,
    gctINT32 radius
    )
{
    gctFLOAT pit, pitd, f1, f2, result;
    gctFLOAT f_radius = vivMATH_Int2Float(radius);

    if (x == 0.0f)
    {
        result = 1.0f;
    }
    else if ((x < -f_radius) || (x > f_radius))
    {
        result = 0.0f;
    }
    else
    {
        pit  = vivMATH_Multiply(gcdPI, x);
        pitd = vivMATH_Divide(pit, f_radius);

        f1 = vivMATH_Divide(gcoMATH_Sine(pit),  pit);
        f2 = vivMATH_Divide(gcoMATH_Sine(pitd), pitd);

        result = vivMATH_Multiply(f1, f2);
    }

    return result;
}

/* Calculate weight array for sync filter.
 */
viv_status_type calculate_sync_table(
    gctUINT8 kernel_size,
    gctUINT32 src_size,
    gctUINT32 dst_size,
    gcsFILTER_BLIT_ARRAY_PTR kernel_info
    )
{
    do
    {
        gctUINT32 scale_factor;
        gctFLOAT f_scale;
        gctINT kernel_half;
        gctFLOAT f_subpixel_step;
        gctFLOAT f_subpixel_offset;
        gctUINT32 subpixel_pos;
        gctINT kernel_pos;
        gctINT padding;
        gctUINT16_PTR kernel_array;
        gctPOINTER pointer = vivNULL;

        /* Compute the scale factor. */
        scale_factor = get_stretch_factor(src_size, dst_size);

        /* Same kernel size and ratio as before? */
        if ((kernel_info->kernelSize  == kernel_size) &&
            (kernel_info->scaleFactor == kernel_size))
        {
            break;
        }

        /* Allocate the array if not allocated yet. */
        if (kernel_info->kernelStates == vivNULL)
        {
            /* Allocate the array. */
           pointer = viv_os_mem_alloc(gcvKERNELSTATES);

            kernel_info->kernelStates = pointer;
        }

        /* Store new parameters. */
        kernel_info->kernelSize  = kernel_size;
        kernel_info->scaleFactor = scale_factor;

        /* Compute the scale factor. */
        f_scale = vivMATH_DivideFromUInteger(dst_size, src_size);

        /* Adjust the factor for magnification. */
        if (f_scale > 1.0f)
        {
            f_scale = 1.0f;
        }

        /* Calculate the kernel half. */
        kernel_half = (gctINT) (kernel_info->kernelSize >> 1);

        /* Calculate the subpixel step. */
        f_subpixel_step = vivMATH_Divide(1.0f,
                                       vivMATH_Int2Float(gcvSUBPIXELCOUNT));

        /* Init the subpixel offset. */
        f_subpixel_offset = 0.5f;

        /* Determine kernel padding size. */
        padding = (gcvMAXKERNELSIZE - kernel_info->kernelSize) / 2;

        /* Set initial kernel array pointer. */
        kernel_array = (gctUINT16_PTR) (kernel_info->kernelStates + 1);

        /* Loop through each subpixel. */
        for (subpixel_pos = 0; subpixel_pos < gcvSUBPIXELLOADCOUNT; subpixel_pos++)
        {
            /* Define a temporary set of weights. */
            gctFLOAT fSubpixelSet[gcvMAXKERNELSIZE];

            /* Init the sum of all weights for the current subpixel. */
            gctFLOAT fWeightSum = 0.0f;
            gctUINT16 weightSum = 0;
            gctINT16 adjustCount, adjustFrom;
            gctINT16 adjustment;

            /* Compute weights. */
            for (kernel_pos = 0; kernel_pos < gcvMAXKERNELSIZE; kernel_pos++)
            {
                /* Determine the current index. */
                gctINT index = kernel_pos - padding;

                /* Pad with zeros. */
                if ((index < 0) || (index >= kernel_info->kernelSize))
                {
                    fSubpixelSet[kernel_pos] = 0.0f;
                }
                else
                {
                    if (kernel_info->kernelSize == 1)
                    {
                        fSubpixelSet[kernel_pos] = 1.0f;
                    }
                    else
                    {
                        /* Compute the x position for filter function. */
                        gctFLOAT fX =
                            vivMATH_Multiply(
                                vivMATH_Add(
                                    vivMATH_Int2Float(index - kernel_half),
                                    f_subpixel_offset),
                                f_scale);

                        /* Compute the weight. */
                        fSubpixelSet[kernel_pos] = sinc_filter(fX, kernel_half);
                    }

                    /* Update the sum of weights. */
                    fWeightSum = vivMATH_Add(fWeightSum,
                                             fSubpixelSet[kernel_pos]);
                }
            }

            /* Adjust weights so that the sum will be 1.0. */
            for (kernel_pos = 0; kernel_pos < gcvMAXKERNELSIZE; kernel_pos++)
            {
                /* Normalize the current weight. */
                gctFLOAT fWeight = vivMATH_Divide(fSubpixelSet[kernel_pos],
                                                  fWeightSum);

                /* Convert the weight to fixed point and store in the table. */
                if (fWeight == 0.0f)
                {
                    kernel_array[kernel_pos] = 0x0000;
                }
                else if (fWeight >= 1.0f)
                {
                    kernel_array[kernel_pos] = 0x4000;
                }
                else if (fWeight <= -1.0f)
                {
                    kernel_array[kernel_pos] = 0xC000;
                }
                else
                {
                    kernel_array[kernel_pos] = (gctINT16)
                        vivMATH_Multiply(fWeight, 16384.0f);
                }

                weightSum += kernel_array[kernel_pos];
            }

            /* Adjust the fixed point coefficients. */
            adjustCount = 0x4000 - weightSum;
            if (adjustCount < 0)
            {
                adjustCount = -adjustCount;
                adjustment = -1;
            }
            else
            {
                adjustment = 1;
            }

            adjustFrom = (gcvMAXKERNELSIZE - adjustCount) / 2;

            for (kernel_pos = 0; kernel_pos < adjustCount; kernel_pos++)
            {
                kernel_array[adjustFrom + kernel_pos] += adjustment;
            }

            kernel_array += gcvMAXKERNELSIZE;

            /* Advance to the next subpixel. */
            f_subpixel_offset = vivMATH_Add(f_subpixel_offset, -f_subpixel_step);
        }

    }
    while (vivFALSE);

    return vivSTATUS_OK;
}

/* Generate scsale factor.
 */
gctINT viv_generate_factor(
    gctUINT32* scale_factorx,
    gctUINT32* scale_factory,
    gctUINT32  src_width,
    gctUINT32  src_height,
    gctUINT32  dst_width,
    gctUINT32  dst_height
    )
{
    gctUINT32 factor_x, factor_y;

    if((scale_factorx == vivNULL) || (scale_factory == vivNULL))
    {
        viv_print("[viv_generate_factor] Invalid Argument: Null Pointer!\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    factor_x = get_stretch_factor(src_width, dst_width);
    factor_y = get_stretch_factor(src_height, dst_height);

    if (factor_y > (3 << 16))
    {
        factor_y = (3 << 16);
    }

    *scale_factorx = factor_x;
    *scale_factory = factor_y;

    return vivSTATUS_OK;
}
#endif