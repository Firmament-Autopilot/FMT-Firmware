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


#include "viv_dc_shell.h"

#if vivENABLE_MMU
#include "viv_dc_mmu.h"
#endif

#if vivENABLE_SEC
#include "viv_dc_hardware_sec.h"
#endif

typedef struct _dc_buffer_handle {
    gctPOINTER buffer_handle;
    gctUINT32 page_num;
    gctUINT32 gpuAddress;
} dc_buffer_handle;

/* It is outside the core part, but it is common for each platform. */
vivSTATUS viv_conf_ioctl(
    viv_dc_core ** Core,
    viv_interface *iface,
    gctUINT32 *touser
    )
{
    gctUINT code = iface->command;
    viv_dc_core * core = Core[0];
    dc_buffer_handle *handle;
    gctPOINTER logical;
    gctADDRESS physical;
    gctPOINTER pointer;
    vivSTATUS ret = vivSTATUS_OK;
#if vivENABLE_MMU
    gctUINT page_count = 0;
#endif

#if vivENABLE_DC_DEBUG
    viv_os_print("Ioctl command=%d, core=%p\n", code, core);
#endif

    switch (code) {
        case vivIFACE_MEMORY_MAP:
#if vivENABLE_MMU
            /* Map physical memory into dc mmu page table, and return virtual addr used in DC */
            iface->u.memory_map.dpu_addrress = iface->u.memory_map.physical;
            if (gcvPOOL_USER == iface->u.memory_map.pool)
                iface->u.memory_map.pool = gcvPOOL_CONTIGUOUS;
            page_count = viv_os_get_page_count(iface->u.memory_map.size, 0);
            dcMMU_MapMemory(
                core->mmu,
                iface->u.memory_map.physical,
                page_count,
                &iface->u.memory_map.dpu_addrress,
                iface->u.memory_map.security,
                iface->u.memory_map.pool
                );
            dcMMU_FlushTLB(core->hw_sec);

#endif
            *touser = 1;
            break;

        case vivIFACE_MEMORY_UNMAP:
            /* Unmap dc virtual address */
#if vivENABLE_MMU
#if vivENABLE_MMU_1KMODE
            /* By default 0~2G flat mapping. */
            if (iface->u.memory_unmap.dpu_addrress >= 0x80000000)
#endif
            {
                page_count = viv_os_get_page_count(iface->u.memory_unmap.size, 0);
                dcMMU_UnmapMemory(
                    core->mmu,
                    iface->u.memory_unmap.dpu_addrress,
                    page_count
                    );
                dcMMU_FlushTLB(core->hw_sec);
            }
#endif
            break;

        case vivIFACE_DISPLAY:
            switch (iface->u.display.cmd)
            {
                case vivDISPLAY_SET_SIZE:
                    viv_conf_display_set_size(
                        core,
                        iface->u.display.display_id,
                        iface->u.display.u.size.type
                        );
                    break;

                case vivDISPLAY_SET_CUSTOM_SIZE:
                    viv_conf_display_set_custom_size(
                        core,
                        iface->u.display.display_id,
                        iface->u.display.u.size.hactive,
                        iface->u.display.u.size.hsync_start,
                        iface->u.display.u.size.hsync_end,
                        iface->u.display.u.size.htotal,
                        iface->u.display.u.size.vactive,
                        iface->u.display.u.size.vsync_start,
                        iface->u.display.u.size.vsync_end,
                        iface->u.display.u.size.vtotal
                        );
                    break;

                case vivDISPLAY_SET_OUTPUT:
                    viv_display_conf_set_output(
                        core,
                        iface->u.display.display_id,
                        iface->u.display.u.output.enable,
                        iface->u.display.u.output.output
                        );
                    break;
#if vivENABLE_DISPLAY_R2Y
                case vivDISPLAY_SET_CSC:
                    viv_display_conf_set_output_csc(
                        core,
                        iface->u.display.display_id,
                        iface->u.display.u.output_csc.full_range,
                        iface->u.display.u.output_csc.mode,
                        iface->u.display.u.output_csc.coef,
                        iface->u.display.u.output_csc.num
                        );
                    break;
#endif
#if vivENABLE_WRITEBACK
                case vivDISPLAY_SET_DEST:
                    viv_display_conf_set_dest(
                        core,
                        iface->u.display.u.dest.enable,
                        iface->u.display.display_id,
                        &iface->u.display.u.dest.buffer,
                        iface->u.display.u.dest.type
                        );
                    break;
#endif
                case vivDISPLAY_RESET_DBI:
                    viv_display_conf_dbi_reset(
                        core
                        );
                    break;
                case vivDISPLAY_SET_DBI:
                    viv_display_conf_dbi_set_config(
                        core,
                        iface->u.display.display_id,
                        iface->u.display.u.output_dbi.type
                        );
                    break;
                default:
                    viv_os_print("Illegal command=%d\n", code);
                    break;
            }
            break;

        case vivIFACE_LAYER:
            switch (iface->u.layer.cmd)
            {
                case vivLAYER_ENABLE:
                    viv_conf_layer_enable(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.layer_enable.layer_enable
                        );
                    break;
#if vivENABLE_SEC
                case vivLAYER_SET_SECURITY:
                     viv_conf_layer_security(
                         core,
                         iface->u.layer.layer_id,
                         iface->u.layer.u.security.enable
                         );
                     break;
#endif
                case vivLAYER_CLEAR:
                    viv_layer_clear_enable(core, iface->u.layer.layer_id, iface->u.layer.u.clear.clear_color_enable);
                    viv_layer_clear_color(
                        core,
                        iface->u.layer.layer_id,
                        &iface->u.layer.u.clear.clear_color
                        );
                    break;
#if vivENABLE_LAYER_ROI
                 case vivLAYER_ROI_ENABLE:
                    viv_layer_conf_roi_enable(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.roi_enable.roi_enable
                        );
                    break;
                case vivLAYER_SET_RECT:
                    viv_layer_conf_roi_rect(
                        core,
                        iface->u.layer.layer_id,
                        &iface->u.layer.u.roi_rect.roi_rect
                        );
                    break;
#endif
                 case vivLAYER_CMD_BUFFER:
                    /* Sets the layer stride, size, and format for each planar */
                    viv_conf_layer_set_buffer(
                        core,
                        iface->u.layer.layer_id,
                        &iface->u.layer.u.buffer.buffer
                        );
                    break;
                case vivLAYER_SET_POSITION:
                    viv_layer_conf_set_position(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.position.x,
                        iface->u.layer.u.position.y
                        );
                    break;
                case vivLAYER_SET_COLORKEY:
                    /* Set colorkey related configuration for layer */
                    viv_conf_layer_set_colorkey(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.colorkey.colorkey,
                        iface->u.layer.u.colorkey.colorkey_high,
                        iface->u.layer.u.colorkey.transparency
                        );
                    break;
#if vivENABLE_LAYER_DEGAMMA
                case vivLAYER_ENABLE_DEGAMMA:
                    viv_layer_conf_enable_degamma(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.degamma.enable
                        );
                    break;
                case vivLAYER_SET_DEGAMMA:
                    viv_layer_conf_set_degamma(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.degamma.index,
                        iface->u.layer.u.degamma.item[0],
                        iface->u.layer.u.degamma.item[1],
                        iface->u.layer.u.degamma.item[2]
                        );
                    break;
#endif
#if vivENABLE_LAYER_ROI
                case vivLAYER_SET_ROTATION:
                    /* Set rotation related configuration for layer */
                    viv_conf_layer_set_rotation(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.rotation.rot
                        );
                    break;
#endif

                case vivLAYER_SET_SCALE:
                    /* Sets the layer scale */
#if vivENABLE_LAYER_SCALE
                    viv_conf_layer_set_scale(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.scale.filter,
                        iface->u.layer.u.scale.horkernel,
                        iface->u.layer.u.scale.verkernel,
                        iface->u.layer.u.scale.scale_factorx,
                        iface->u.layer.u.scale.scale_factory,
                        iface->u.layer.u.scale.scale_enable
                        );
#endif
                    viv_conf_layer_set_rect(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.scale.display_rect
                        );
                    break;

#if vivENABLE_LAYER_DECOMPRESS
                case vivLAYER_SET_DECOMPRESS:
                    /* Set decompress related configuration for layer */
                    viv_conf_layer_set_decompress(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.decompress.decompress_enable,
                        iface->u.layer.u.decompress.tilestatus_buffer
                        );
                    break;
                case vivLAYER_SET_CACHE_MODE:
                    /* Set cache mode of compression */
                    viv_conf_layer_set_cache_mode(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.decompress.cache_mode
                        );
                    break;
#endif
                case vivLAYER_SET_WATERMARK:
                    /* Set layer watermark value */
                    viv_conf_layer_set_watermark(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.watermark.watermark_value
                        );
                    break;
                case vivLAYER_SET_ALPHA:
                    /* Set source/dest alpha value and mode */
                    viv_conf_layer_set_alpha(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.alpha.alpha
                        );
                    break;
                case vivLAYER_SET_POTERBUFF_BLEND_MODE:
                    /* Set porter duff blending mode */
                    viv_conf_layer_set_poterbuff_blend_mode(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.poterduff_blend.enable,
                        iface->u.layer.u.poterduff_blend.mode
                        );
                    break;
                case vivLAYER_SET_ZORDER:
                    /* Set zorder for layer */
                    viv_conf_layer_set_zorder(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.zorder.zorder
                        );
                    break;
                case vivLAYER_SET_DISPLAY:
                    /* Set display for layer */
                    viv_conf_layer_set_display(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.display.display_id
                        );
                    break;
                case vivLAYER_SET_CSC_Y2R:
                    viv_layer_conf_y2r(
                        core,
                        iface->u.layer.layer_id,
                        iface->u.layer.u.y2r.yuvClamp,
                        iface->u.layer.u.y2r.mode,
                        iface->u.layer.u.y2r.coef,
                        iface->u.layer.u.y2r.num
                         );
                    break;
                case vivLAYER_SET_CSC_R2R:
                    ret = viv_layer_conf_r2r(
                            core,
                            iface->u.layer.layer_id,
                            iface->u.layer.u.r2r.enable,
                            iface->u.layer.u.r2r.mode,
                            iface->u.layer.u.r2r.coef,
                            iface->u.layer.u.r2r.num
                            );
                    break;

                default:
                    viv_os_print("Illegal command=%d\n", code);
                    break;
            }
            break;
       /* Set pure color or color bar background */
        case vivIFACE_BACKGROUND:
            switch (iface->u.background.cmd)
            {
                case vivBACKGROUND_SET_COLOR:
                    viv_layer_conf_set_background(
                    core,
                    iface->u.background.display_id,
                    &iface->u.background.iu.purecolor.color
                    );
                    break;
#if vivENABLE_DISPLAY_CLRBAR
                case vivBACKGROUND_SET_COLORBAR:
                    ret = viv_conf_set_color_bar(
                              core,
                              iface->u.background.display_id,
                              iface->u.background.iu.colorbar.enable,
                              iface->u.background.iu.colorbar.index,
                              &iface->u.background.iu.colorbar.range,
                              &iface->u.background.iu.colorbar.color
                              );
                    break;
#endif
                default:
                    viv_os_print("Illegal command=%d\n", code);
                    break;
            }
        case vivIFACE_CURSOR:
            switch (iface->u.cursor.cmd)
            {
                case vivCURSOR_HOTSPOT:
                    viv_cursor_conf_hotspot(
                        core,
                        iface->u.cursor.display_id,
                        iface->u.cursor.iu.hotspot.hsx,
                        iface->u.cursor.iu.hotspot.hsy
                    );
                    break;
                case vivCURSOR_MOVE:
                    viv_cursor_conf_move(
                        core,
                        iface->u.cursor.display_id,
                        iface->u.cursor.iu.move.x,
                        iface->u.cursor.iu.move.y
                    );
                    break;
                case vivCURSOR_SET:
                    viv_cursor_conf_enable(
                        core,
                        iface->u.cursor.display_id,
                        iface->u.cursor.iu.set.enable
                        );
                    if (iface->u.cursor.iu.set.enable)
                    {
                        viv_cursor_conf_set(
                            core,
                            iface->u.cursor.display_id,
                            &iface->u.cursor.iu.set.buffer,
                            &iface->u.cursor.iu.set.cursor
                            );
                    }
                    break;
#if vivENABLE_SEC
                case vivCURSOR_SECURITY:
                    viv_cursor_conf_security(
                        core,
                        iface->u.cursor.display_id,
                        iface->u.cursor.iu.security.enable
                        );
                    break;
#endif
                default:
                    break;
            }
            break;

        case vivIFACE_QOS:
            viv_dc_conf_qos(
                core,
                iface->u.qos.low,
                iface->u.qos.high
                );
            break;

        case vivIFACE_DITHER:
            /* Set dither */
            viv_conf_dither_enable(core, iface->u.dither.display_id, iface->u.dither.enable);
            if (iface->u.dither.enable) {
                viv_conf_dither_set_config(
                    core,
                    iface->u.dither.display_id,
                    iface->u.dither.table_low,
                    iface->u.dither.table_high
                    );
            }
            break;
#if vivENABLE_WRITEBACK
        case vivIFACE_WB_DITHER:
            /* Set write back dither */
            viv_conf_set_write_back_dither(core,
                iface->u.wb_dither.enable,
                iface->u.wb_dither.display_id,
                iface->u.wb_dither.table_low,
                iface->u.wb_dither.table_high
                );
            break;
#endif
        case vivIFACE_GAMMA_ENABLE:
            viv_conf_enable_gamma(core, iface->u.gamma.disp_id, iface->u.gamma.enable);
            break;

        case vivIFACE_GAMMA:
            viv_conf_gamma_set_config(
                core,
                iface->u.gamma.disp_id,
                iface->u.gamma.index,
                iface->u.gamma.item[0],
                iface->u.gamma.item[1],
                iface->u.gamma.item[2]
                );
            break;
#if vivENABLE_DISPLAY_3DLUT
        case vivIFACE_3D_LUT:
            /* Set 3d lut table */
            viv_conf_3d_lut_set_config(
                core,
                iface->u.threed_lut.display_id,
                iface->u.threed_lut.enable,
                iface->u.threed_lut.index,
                iface->u.threed_lut.lut
                );
            break;
        case vivIFACE_3D_LUT_ENLARGE:
            /* Set enlarge value for 3D LUT */
            viv_conf_3d_lut_set_enlarge(
                core,
                iface->u.threed_lut.display_id,
                iface->u.threed_lut.enlarge
                );
            break;
#endif

        case vivIFACE_COMMIT:
            /* Set commit. */
            viv_conf_set_display(core, iface->u.commit.display_mask);
            viv_conf_commit(core);

            /* ToDo */
            break;

        case vivIFACE_RESET:
            viv_conf_dc_reset(core);
            break;

        case vivIFACE_REGISTER:
            viv_os_write_reg(core->os, iface->u.registers.offset, iface->u.registers.write);
            if (iface->u.registers.read != 0xDEADDEAD)
            {
                iface->u.registers.read = viv_os_read_reg(core->os, iface->u.registers.offset);
                *touser = 1;
            }
            break;

        case vivIFACE_READ_REGISTER:
            if (iface->u.registers.read != 0xDEADDEAD)
            {
                iface->u.registers.read = viv_os_read_reg(core->os, iface->u.registers.offset);
                *touser = 1;
            }
            break;

        case vivIFACE_DBI_RESET:
            viv_conf_output_dbi_reset(core);
            break;

        case vivIFACE_ALLOC_BUFFER:
            viv_os_alloc_memory(
                core->os,
                sizeof(dc_buffer_handle),
                &pointer
                );

            handle = (dc_buffer_handle *)pointer;
#if vivENABLE_SEC
            if(iface->u.alloc.security)
            {
                /*allocate buffer from security pool, but there is no security pool in test environment,
                so the buffer allocation is same as non-security, we're just assuming it's a security pool.*/
                viv_os_alloc_buffer(
                    core->os,
                    iface->u.alloc.size,
                    &handle->buffer_handle,
                    &logical,
                    &physical,
                    &iface->u.alloc.pool
                    );
            }
            else
#endif
            {
                viv_os_alloc_buffer(
                    core->os,
                    iface->u.alloc.size,
                    &handle->buffer_handle,
                    &logical,
                    &physical,
                    &iface->u.alloc.pool
                    );
            }

#if USE_ARCH64
            iface->u.alloc.logical = (gctUINT64)logical;
#else
            iface->u.alloc.logical = (gctUINT32)logical;
#endif

            iface->u.alloc.hardwareAddress = physical;

            handle->page_num = viv_os_get_page_count(iface->u.alloc.size, 0);

#if vivENABLE_MMU
            dcMMU_MapMemory(
                core->mmu,
                physical,
                handle->page_num,
                &iface->u.alloc.hardwareAddress,
                iface->u.alloc.security,
                iface->u.alloc.pool
                );

            dcMMU_FlushTLB(core->hw_sec);
#endif
            handle->gpuAddress = iface->u.alloc.hardwareAddress;

#if USE_ARCH64
            iface->u.alloc.handle = (gctUINT64)handle;
#else
            iface->u.alloc.handle = (gctUINT32)handle;
#endif

            *touser = 1;
            break;

        case vivIFACE_FREE_BUFFER:
            handle = (dc_buffer_handle *)iface->u.free.handle;

#if vivENABLE_MMU
#if vivENABLE_MMU_1KMODE
            /* By default 0~2G flat mapping. */
            if (handle->gpuAddress >= 0x80000000)
#endif
            {
                dcMMU_UnmapMemory(
                    core->mmu,
                    handle->gpuAddress,
                    handle->page_num
                    );
                dcMMU_FlushTLB(core->hw_sec);
            }
#endif
            viv_os_free_buffer(
                core->os,
                handle->buffer_handle
                );

            viv_os_free_memory(core->os, handle);

            break;

        case vivIFACE_INIT_LCD:
            viv_init_lcd(core);
            break;
#if vivENABLE_DISPLAY_CRC
        case vivIFACE_CRC:
            switch (iface->u.crc.cmd)
            {
                case vivCRC_SET_RANGE:
                    viv_crc_set_range(
                        core,
                        iface->u.crc.index,
                        iface->u.crc.u.crc_range.enable,
                        &iface->u.crc.u.crc_range.range
                        );
                    break;
                case vivCRC_GET_VALUE:
                    viv_crc_get_value(
                        core,
                        iface->u.crc.index,
                        &iface->u.crc.u.crc_value.value
                    );

                    *touser = 1;
                    break;
                default:
                    break;
            }
            break;
#endif
        case vivIFACE_QUERY:
            switch (iface->u.query.cmd)
            {
                case vivQUERY_CHIP_IDENTITY:
                    dc_query_hardware_chip_identity(core->hardware, &iface->u.query.u.queryChipIdentity);
                    break;
                case vivQUERY_VBLANK_COUNT:
                    viv_conf_get_vblank(core, iface->u.query.u.vblank.disp_id, &iface->u.query.u.vblank.count);
                    break;
#if vivENABLE_DUALOS
                case vivQUERY_LAYER_STATUS:
                    viv_get_layer_status(core, iface->u.query.u.viv_query_layer_status.layer_id, &iface->u.query.u.viv_query_layer_status.queryLayerStatus);
                    break;
#endif
                default:
                    break;
            }
            *touser = 1;
            break;

#if vivENABLE_DUALOS
        case vivIFACE_OS_REQUEST_CONTROL:
            viv_request_control(core, &iface->u.request.result);
            *touser = 1;
            break;
#endif

        case vivIFACE_INTERRUPT_ENABLE:
            viv_interrupt_enable(core, &iface->u.interrupt.interrupt_enable);
            break;

        default:
            viv_os_print("Illegal command=%d\n", code);
            break;
    }
    return ret;
}
