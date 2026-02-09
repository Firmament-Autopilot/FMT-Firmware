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


#include "viv_dc_hardware.h"
#include "viv_dc_os.h"

gctVOID viv_init_lcd(viv_dc_core *core)
{
    viv_display_format_type format;
    gctUINT data = 0x55;

    format = core->display.output[0].format;

    switch (format)
    {
        case vivD8R5G6B5:
            data = 0x05;
            break;
        case vivD8R6G6B6:
            data = 0x06;
            break;
        case vivD8R8G8B8:
            data = 0x07;
            break;
        case vivD1R5G6B5OP1:
        case vivD1R5G6B5OP3:
            data = 0x05;
            break;
        case vivD1R8G8B8OP1:
        case vivD1R8G8B8OP3:
            data = 0x06;
            break;
        default:
            data = 0x05;
            break;
    }

    viv_os_print("start to init LCD\n");

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x01);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0xB9);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0xFF);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x83);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x57);
    viv_os_sleep(250);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0xB3);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x80);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x06);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x06);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0xB6);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x25);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0xB0);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x68);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0xCC);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x05);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0xB1);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x15);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x1C);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x1C);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x83);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0xAA);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0xC0);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x50);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x50);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x01);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x3C);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x1E);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x08);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0xB4);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x02);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x40);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x2A);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x2A);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x0D);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x78);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x3A);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, data);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x36);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0xC0);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x35);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x44);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x02);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x11);
    viv_os_sleep(150);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x29);
    viv_os_sleep(1);

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x2A);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x01);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x3F);/* width 320 */

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x2B);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x00);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0x01);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_DATA, 0xDF);/* height 480 */

    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_ADDRESS, 0x2C);
    viv_hw_display_dbi_set_command(core->hardware, format, vivDBI_COMMAND_MEM, 0x0);/* enable DMA */

    viv_os_print("end init LCD\n");
}
