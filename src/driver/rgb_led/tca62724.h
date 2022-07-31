/*****************************************************************************
Copyright (c) 2018-2020, Firmament Autopilot Team. All rights reserved.

Author: J Zou: jiachi.zou@gmail.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of Firmament Autopilot nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef TCA62724_H__
#define TCA62724_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TCA62724_MAX_BRIGHT     15
#define TCA62724_CMD_SET_BRIGHT 0x20

enum {
    TCA62724_LED_RED = 0,
    TCA62724_LED_GREEN,
    TCA62724_LED_BLUE,
    TCA62724_LED_YELLOW,
    TCA62724_LED_WHITE,
    TCA62724_COLOR_NUM // don't remove this
};

rt_err_t tca62724_drv_init(const char* i2c_dev_name);

#ifdef __cplusplus
}
#endif

#endif
