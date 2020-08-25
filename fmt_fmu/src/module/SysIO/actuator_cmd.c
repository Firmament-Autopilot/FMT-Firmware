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

#include "hal/motor.h"
#include "module/controller/controller_model.h"
#include "task/task_comm.h"

MCN_DECLARE(control_output);

static McnNode_t _control_out_nod = NULL;
static rt_device_t _motor_dev = NULL;

fmt_err send_hil_actuator_cmd(void)
{
    fmt_err err = FMT_EOK;

    if (_control_out_nod == NULL) {
        _control_out_nod = mcn_subscribe(MCN_ID(control_output), NULL, NULL);
    }

    if (mcn_poll(_control_out_nod)) {
        Control_Out_Bus control_out;
        mavlink_hil_actuator_controls_t hil_actuator_ctrl;
        mavlink_message_t msg;
        mavlink_system_t mav_sys;

        mcn_copy(MCN_ID(control_output), _control_out_nod, &control_out);

        /* send command by mavlink */
        mav_sys = mavproxy_get_system();

        hil_actuator_ctrl.time_usec = systime_now_us();
        hil_actuator_ctrl.mode = MAV_MODE_FLAG_SAFETY_ARMED;
        hil_actuator_ctrl.controls[0] = (float)control_out.actuator_cmd[0] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[1] = (float)control_out.actuator_cmd[1] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[2] = (float)control_out.actuator_cmd[2] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[3] = (float)control_out.actuator_cmd[3] * 0.002f - 3.0f;
        mavlink_msg_hil_actuator_controls_encode(mav_sys.sysid, mav_sys.compid, &msg, &hil_actuator_ctrl);

        err = mavproxy_send_immediate_msg(&msg, 1) == 1 ? FMT_EOK : FMT_ERROR;
    }

    return err;
}

fmt_err send_actuator_cmd(void)
{
    /* send command to actuator */
    if (_motor_dev == NULL) {
        return FMT_ERROR;
    }

    if (mcn_poll(_control_out_nod)) {
        rt_size_t size;
        Control_Out_Bus control_out;

        mcn_copy(MCN_ID(control_output), _control_out_nod, &control_out);

        size = rt_device_write(_motor_dev, MOTOR_MASK_1_4, control_out.actuator_cmd, 8);

        return size == 8 ? FMT_EOK : FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err actuator_deinit(void)
{
    if (rt_device_close(_motor_dev) == RT_EOK) {
        _motor_dev = NULL;
        return FMT_EOK;
    }

    return FMT_ERROR;
}

fmt_err actuator_init(const char* device_name)
{
    _motor_dev = rt_device_find(device_name);

    if (_motor_dev == NULL) {
        boot_log_printf("Can not find motor device %s!\n", device_name);
        return FMT_ERROR;
    }

    if (rt_device_open(_motor_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        boot_log_printf("Fail to open motor device %s!\n", device_name);
        /* close the motor device */
        rt_device_close(_motor_dev);
        _motor_dev = NULL;

        return FMT_ERROR;
    }

    _control_out_nod = mcn_subscribe(MCN_ID(control_output), NULL, NULL);
    if (_control_out_nod == NULL) {
        boot_log_printf("Fail to subscribe control_output topic\n");
        return FMT_ERROR;
    }

    return FMT_EOK;
}