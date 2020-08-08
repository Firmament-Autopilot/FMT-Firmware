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

#include <Controller.h>
#include <firmament.h>

#define TAG "Controller"

/* controller input topic */
MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);

/* controller output topic */
MCN_DEFINE(control_output, sizeof(Control_Out_Bus));

static McnNode_t _fms_out_nod;
static McnNode_t _ins_out_nod;

void controller_model_step(void)
{
    static uint32_t start_time = 0;
    uint32_t time_now = systime_now_ms();

    if (start_time == 0) {
        /* record first execution time */
        start_time = time_now;
    }

    if (mcn_poll(_fms_out_nod)) {
        mcn_copy(MCN_ID(fms_output), _fms_out_nod, &Controller_U.FMS_Out);
    }

    if (mcn_poll(_ins_out_nod)) {
        mcn_copy(MCN_ID(ins_output), _ins_out_nod, &Controller_U.INS_Out);
    }

    Controller_step();

    mcn_publish(MCN_ID(control_output), &Controller_Y.Control_Out);

    DEFINE_TIMETAG(control_output, 100);
    /* Log Control output bus data */
    if (check_timetag(TIMETAG(control_output))) {
        /* rewrite timestmp */
        Controller_Y.Control_Out.timestamp = time_now - start_time;
        /* Log Control out data */
        blog_push_msg((uint8_t*)&Controller_Y.Control_Out, BLOG_CONTROL_OUT_ID, sizeof(Control_Out_Bus));
    }
}

void controller_model_init(void)
{
    mcn_advertise(MCN_ID(control_output), NULL);

    _fms_out_nod = mcn_subscribe(MCN_ID(fms_output), NULL, NULL);
    _ins_out_nod = mcn_subscribe(MCN_ID(ins_output), NULL, NULL);

    Controller_init();
}