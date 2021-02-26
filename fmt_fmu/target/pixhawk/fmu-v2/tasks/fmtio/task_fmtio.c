/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <firmament.h>

#include "module/fmtio/fmtio.h"
#include "task_fmtio.h"

static fmt_err _handle_rx_package(const PackageStruct* pkg)
{
    switch (pkg->cmd) {
    case PROTO_DBG_TEXT: {
        console_printf("[IO]:", systime_now_ms());
        console_write((char*)pkg->content, pkg->len);
    } break;
    default:
        break;
    }

    return FMT_EOK;
}

/**************************** Public Function ********************************/
fmt_err task_fmtio_init(void)
{
    /* init fmtio */
    if (fmtio_init() != FMT_EOK) {
        return FMT_ERROR;
    }

    /* register rx handler to handle rx messages locally */
    if (fmtio_register_rx_handler(_handle_rx_package) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

void task_fmtio_entry(void* parameter)
{
    /* execute fmtio main loop */
    fmtio_loop();
}