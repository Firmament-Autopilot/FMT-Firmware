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

#define DEFAULT_PWM_FREQ (400) // default pwm frequency in Hz

MCN_DECLARE(control_output);

static McnNode_t _control_out_nod = NULL;

fmt_err send_hil_actuator_cmd(void)
{
    fmt_err err = FMT_EOK;
    DEFINE_TIMETAG(hil_actuator_tt, 1000 / DEFAULT_PWM_FREQ);

    if (_control_out_nod == NULL) {
        _control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);
    }

    if (mcn_poll(_control_out_nod) && check_timetag(TIMETAG(hil_actuator_tt))) {
        Control_Out_Bus control_out;
        mavlink_hil_actuator_controls_t hil_actuator_ctrl;
        mavlink_message_t msg;
        mavlink_system_t mav_sys;

        mcn_copy(MCN_HUB(control_output), _control_out_nod, &control_out);

        /* send command by mavlink */
        mav_sys = mavproxy_get_system();

        hil_actuator_ctrl.time_usec = systime_now_us();
        hil_actuator_ctrl.mode = MAV_MODE_FLAG_SAFETY_ARMED;
        /* map to -1~1 */
        hil_actuator_ctrl.controls[0] = (float)control_out.actuator_cmd[0] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[1] = (float)control_out.actuator_cmd[1] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[2] = (float)control_out.actuator_cmd[2] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[3] = (float)control_out.actuator_cmd[3] * 0.002f - 3.0f;
        mavlink_msg_hil_actuator_controls_encode(mav_sys.sysid, mav_sys.compid, &msg, &hil_actuator_ctrl);

        err = mavproxy_send_immediate_msg(&msg, 1) == 1 ? FMT_EOK : FMT_ERROR;
    }

    return err;
}

fmt_err send_actuator_cmd(const rt_device_t dev)
{
    DEFINE_TIMETAG(actuator_tt, 1000 / DEFAULT_PWM_FREQ);

    RT_ASSERT(dev != NULL);

    if (mcn_poll(_control_out_nod) && check_timetag(TIMETAG(actuator_tt))) {
        rt_size_t size;
        Control_Out_Bus control_out;

        mcn_copy(MCN_HUB(control_output), _control_out_nod, &control_out);

        size = rt_device_write(dev, MOTOR_MASK_1_4, control_out.actuator_cmd, 8);

        return size == 8 ? FMT_EOK : FMT_ERROR;
    }

    return FMT_EOK;
}

// fmt_err actuator_suspend(const rt_device_t dev)
// {
//     FMS_Out_Bus fms_out;

//     if (_acturtor_suspend) {
//         return FMT_EOK;
//     }

//     mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out);

//     /* check if it's disram state */
//     if (fms_out.state != 0) {
//         /* not allowed to suspend the actuator in the air */
//         return FMT_ERROR;
//     }

//     if(actuator_deinit(dev) != FMT_EOK){
//         return FMT_ERROR;
//     }

//     _acturtor_suspend = 1;

//     return FMT_EOK;
// }

// fmt_err actuator_resume(const rt_device_t dev)
// {
//     if (_acturtor_suspend == 0) {
//         return FMT_EOK;
//     }

//     if(actuator_init(dev) != FMT_EOK){
//         return FMT_ERROR;
//     }

//     _acturtor_suspend = 0;

//     return FMT_EOK;
// }

fmt_err actuator_deinit(const rt_device_t dev)
{
    if (dev == NULL) {
        return FMT_ERROR;
    }

    if (rt_device_close(dev) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err actuator_init(const rt_device_t dev)
{
    uint16_t default_pwm_freq = DEFAULT_PWM_FREQ;

    if (dev == NULL) {
        return FMT_ERROR;
    }

    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        console_printf("Fail to open actuator!\n");
        rt_device_close(dev);
        return FMT_ERROR;
    }

    if (rt_device_control(dev, MOTOR_CMD_SET_FREQUENCY, &default_pwm_freq) != RT_EOK) {
        console_printf("Fail to set default pwm frequency!\n");
        rt_device_close(dev);
        return FMT_ERROR;
    }

    _control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);
    if (_control_out_nod == NULL) {
        console_printf("Fail to subscribe control_output topic\n");
        rt_device_close(dev);
        return FMT_ERROR;
    }

    return FMT_EOK;
}