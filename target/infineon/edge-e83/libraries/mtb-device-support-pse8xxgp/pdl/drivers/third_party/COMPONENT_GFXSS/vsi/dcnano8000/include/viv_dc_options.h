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


#ifndef _VIV_DC_OPTIONS_H_
#define _VIV_DC_OPTIONS_H_

/*DC Core num*/
#define MULTI_DC_NUM 1

/* Enable capture dump */
#define CAPTURE_DUMP 0

/*enable dump mmu page table*/
#define DUMP_MMU_PAGE_TABLE 0

/* Capture path */
#define CAPTURE_PATH "/root/dc_capture.log"

/* Video source capture path */
#define VIDEO_SOURCE_PATH "/root/video_source.txt"

/* Overlay source capture path */
#define OVERLAY_SOURCE_PATH "/root/overlay_source.txt"

/* For /dev/mem
 * define physical base address & available memory size
 * please change to the appropriate value according to the env
 */
#define MEM_BASE 0x00000000
#define MEM_SIZE 0x00000000

#define ALLOC_RESERVED_MEM_IN_KERNEL 1

#ifndef _BAREMETAL
#define _BAREMETAL 1
#endif

#endif
