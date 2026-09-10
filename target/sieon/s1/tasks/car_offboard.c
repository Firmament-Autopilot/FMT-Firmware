#include <firmament.h>

#include "FMS.h"
#include "INS.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/task_manager/task_manager.h"

MCN_DECLARE(auto_cmd);

#define RATE            20  // loop rate hz
#define RADIUS          5.0 // radius of figure 8 in meters
#define CYCLE_S         15  // time to complete one figure 8 cycle in seconds
#define STEPS           (CYCLE_S * RATE)

static fmt_err_t task_init(void)
{
    return FMT_EOK;
}

static void task_entry(void* parameter)
{
    /* This demo reders to: https://gitlab.com/voxl-public/voxl-sdk/services/voxl-vision-px4/-/blob/f8223eff0e2a935ce05aa395e2d44739b7b322b4/src/offboard_figure_eight.c */
    printf("Offboard figure eight demo!\n");

    const float dt = 1.0f / RATE;
    const float dadt = (2.0f * PI) / CYCLE_S; // first derivative of angle with respect to time
    const float r = RADIUS;
    uint32_t i = 0;

    /* Set mode to offboard */
    gcs_set_mode(PilotMode_Offboard);

    systime_msleep(1000);

    /* Arm the vehicle */
    gcs_set_cmd(FMS_Cmd_PreArm, (float[7]) { 0 }); /* Send PreArm command to arm vehicle */

    systime_msleep(1000);

    while (1) {
        float a = (-PI / 2.0f) + i * (2.0f * PI / STEPS);
        float c = cos(a);
        float s = sin(a);
        float cc = c * c;
        float ss = s * s;
        float sspo = (s * s) + 1.0; // sin squared plus one
        float ssmo = (s * s) - 1.0; // sin squared minus one
        float sspos = sspo * sspo;

        Auto_Cmd_Bus auto_cmd;

        float u =  dadt * r * (ss * ss + ss + (ssmo * cc)) / sspos;
        float v = -dadt * r * s * (ss + 2.0 * cc + 1.0) / sspos;

        auto_cmd.timestamp = systime_now_ms();
        auto_cmd.frame = FRAME_LOCAL_FRD;
        auto_cmd.x_cmd = -(r * c * s) / sspo + 10;
        auto_cmd.y_cmd = (r * c) / sspo + 10;
        auto_cmd.u_cmd = sqrtf(u*u + v*v);
        auto_cmd.cmd_mask = X_CMD_VALID | Y_CMD_VALID | U_CMD_VALID;

        mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);

        i = (i + 1) % STEPS;

        sys_msleep(dt * 1000);
    }
}

// TASK_EXPORT __fmt_task_desc = {
//     .name = "offboard",
//     .init = task_init,
//     .entry = task_entry,
//     .priority = 9,
//     .auto_start = false,
//     .stack_size = 4096,
//     .param = NULL,
//     .dependency = NULL
// };