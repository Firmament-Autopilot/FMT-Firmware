#include <firmament.h>
#include <stdlib.h>
#include <string.h>

#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/math/conversion.h"
#include "module/sensor/sensor_hub.h"
#include "module/system/systime.h"
#include "motor_fault_features.h"

#define MOTOR_FAULT_THREAD_STACK_SIZE 8192
#define MOTOR_FAULT_THREAD_PRIORITY   24
#define MOTOR_FAULT_THREAD_TICK       5
#define MOTOR_FAULT_PWM_HIGH_DEFAULT  1250.0f
#define MOTOR_FAULT_SOCMEM_DATA       __attribute__((section(".cy_socmem_data")))

MCN_DECLARE(control_output);
MCN_DECLARE(ins_output);
MCN_DECLARE(sensor_imu0);
MCN_DECLARE(pilot_cmd);

static rt_thread_t mf_thread;
static volatile uint8_t mf_running;
static volatile uint8_t mf_stop_request;

static McnNode_t mf_control_node;
static McnNode_t mf_ins_node;
static McnNode_t mf_imu_node;
static McnNode_t mf_pilot_node;

static MotorFaultFrame mf_window[MOTOR_FAULT_WINDOW_SIZE] MOTOR_FAULT_SOCMEM_DATA;
static MotorFaultFrame mf_ordered_window[MOTOR_FAULT_WINDOW_SIZE] MOTOR_FAULT_SOCMEM_DATA;
static float mf_input[MOTOR_FAULT_FEATURE_COUNT] MOTOR_FAULT_SOCMEM_DATA;
static unsigned mf_write_index;
static unsigned mf_sample_count;
static unsigned mf_feature_count;
static uint32_t mf_last_sample_ms;
static uint32_t mf_last_infer_ms;
static float mf_pwm_high_threshold = MOTOR_FAULT_PWM_HIGH_DEFAULT;

__attribute__((weak)) void motor_fault_on_features(const float* features, unsigned feature_count, uint32_t timestamp_ms)
{
    (void)features;
    (void)feature_count;
    (void)timestamp_ms;
}

static void mf_fill_frame(MotorFaultFrame* frame)
{
    Control_Out_Bus control_out;
    INS_Out_Bus ins_out;
    imu_data_t imu_data;
    Pilot_Cmd_Bus pilot_cmd;

    if (mcn_poll(mf_control_node)) {
        mcn_copy(MCN_HUB(control_output), mf_control_node, &control_out);
    } else if (mcn_copy_from_hub(MCN_HUB(control_output), &control_out) != FMT_EOK) {
        memset(&control_out, 0, sizeof(control_out));
    }

    if (mcn_poll(mf_ins_node)) {
        mcn_copy(MCN_HUB(ins_output), mf_ins_node, &ins_out);
    } else if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        memset(&ins_out, 0, sizeof(ins_out));
    }

    if (mcn_poll(mf_imu_node)) {
        mcn_copy(MCN_HUB(sensor_imu0), mf_imu_node, &imu_data);
    } else if (mcn_copy_from_hub(MCN_HUB(sensor_imu0), &imu_data) != FMT_EOK) {
        memset(&imu_data, 0, sizeof(imu_data));
    }

    if (mcn_poll(mf_pilot_node)) {
        mcn_copy(MCN_HUB(pilot_cmd), mf_pilot_node, &pilot_cmd);
    } else if (mcn_copy_from_hub(MCN_HUB(pilot_cmd), &pilot_cmd) != FMT_EOK) {
        memset(&pilot_cmd, 0, sizeof(pilot_cmd));
    }

    frame->signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD0] = (float)control_out.actuator_cmd[0];
    frame->signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD1] = (float)control_out.actuator_cmd[1];
    frame->signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD2] = (float)control_out.actuator_cmd[2];
    frame->signal[MOTOR_FAULT_SIGNAL_CONTROL_CMD3] = (float)control_out.actuator_cmd[3];
    frame->signal[MOTOR_FAULT_SIGNAL_INS_PHI] = RAD2DEG(ins_out.phi);
    frame->signal[MOTOR_FAULT_SIGNAL_INS_THETA] = RAD2DEG(ins_out.theta);
    frame->signal[MOTOR_FAULT_SIGNAL_INS_PSI] = RAD2DEG(ins_out.psi);
    frame->signal[MOTOR_FAULT_SIGNAL_INS_P] = ins_out.p;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_Q] = ins_out.q;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_R] = ins_out.r;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_AX] = ins_out.ax;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_AY] = ins_out.ay;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_AZ] = ins_out.az;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_VN] = ins_out.vn;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_VE] = ins_out.ve;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_VD] = ins_out.vd;
    frame->signal[MOTOR_FAULT_SIGNAL_INS_H_AGL] = ins_out.h_AGL;
    frame->signal[MOTOR_FAULT_SIGNAL_IMU_GYR_X] = imu_data.gyr_B_radDs[0];
    frame->signal[MOTOR_FAULT_SIGNAL_IMU_GYR_Y] = imu_data.gyr_B_radDs[1];
    frame->signal[MOTOR_FAULT_SIGNAL_IMU_GYR_Z] = imu_data.gyr_B_radDs[2];
    frame->signal[MOTOR_FAULT_SIGNAL_IMU_ACC_X] = imu_data.acc_B_mDs2[0];
    frame->signal[MOTOR_FAULT_SIGNAL_IMU_ACC_Y] = imu_data.acc_B_mDs2[1];
    frame->signal[MOTOR_FAULT_SIGNAL_IMU_ACC_Z] = imu_data.acc_B_mDs2[2];
    frame->signal[MOTOR_FAULT_SIGNAL_PILOT_STICK_YAW] = pilot_cmd.stick_yaw;
    frame->signal[MOTOR_FAULT_SIGNAL_PILOT_STICK_THROTTLE] = pilot_cmd.stick_throttle;
    frame->signal[MOTOR_FAULT_SIGNAL_PILOT_STICK_ROLL] = pilot_cmd.stick_roll;
    frame->signal[MOTOR_FAULT_SIGNAL_PILOT_STICK_PITCH] = pilot_cmd.stick_pitch;
}

static void mf_copy_window_ordered(MotorFaultFrame* ordered)
{
    unsigned count = mf_sample_count < MOTOR_FAULT_WINDOW_SIZE ? mf_sample_count : MOTOR_FAULT_WINDOW_SIZE;
    unsigned start = mf_sample_count < MOTOR_FAULT_WINDOW_SIZE ? 0U : mf_write_index;

    for (unsigned i = 0; i < count; i++) {
        ordered[i] = mf_window[(start + i) % MOTOR_FAULT_WINDOW_SIZE];
    }
}

static void mf_sample_once(uint32_t now_ms)
{
    mf_fill_frame(&mf_window[mf_write_index]);

    mf_write_index = (mf_write_index + 1U) % MOTOR_FAULT_WINDOW_SIZE;
    if (mf_sample_count < MOTOR_FAULT_WINDOW_SIZE) {
        mf_sample_count++;
    }

    mf_last_sample_ms = now_ms;
}

static void mf_infer_once(uint32_t now_ms)
{
    if (mf_sample_count < MOTOR_FAULT_WINDOW_SIZE) {
        return;
    }

    mf_copy_window_ordered(mf_ordered_window);
    mf_feature_count = motor_fault_extract_features(mf_ordered_window,
                                                    MOTOR_FAULT_WINDOW_SIZE,
                                                    mf_pwm_high_threshold,
                                                    mf_input,
                                                    MOTOR_FAULT_FEATURE_COUNT);
    if (mf_feature_count == MOTOR_FAULT_FEATURE_COUNT) {
        motor_fault_preprocess_features(mf_input, mf_feature_count);
        motor_fault_on_features(mf_input, mf_feature_count, now_ms);
    }

    mf_last_infer_ms = now_ms;
}

static void mf_thread_entry(void* parameter)
{
    (void)parameter;

    while (!mf_stop_request) {
        uint32_t now_ms = systime_now_ms();

        if (now_ms - mf_last_sample_ms >= (1000U / MOTOR_FAULT_SAMPLE_HZ)) {
            mf_sample_once(now_ms);
        }

        if (now_ms - mf_last_infer_ms >= MOTOR_FAULT_INFER_INTERVAL_MS) {
            mf_infer_once(now_ms);
        }

        sys_msleep(1);
    }

    mf_running = 0U;
    mf_stop_request = 0U;
}

static fmt_err_t mf_subscribe_topics(void)
{
    if (mf_control_node == NULL) {
        mf_control_node = mcn_subscribe(MCN_HUB(control_output), NULL);
    }
    if (mf_ins_node == NULL) {
        mf_ins_node = mcn_subscribe(MCN_HUB(ins_output), NULL);
    }
    if (mf_imu_node == NULL) {
        mf_imu_node = mcn_subscribe(MCN_HUB(sensor_imu0), NULL);
    }
    if (mf_pilot_node == NULL) {
        mf_pilot_node = mcn_subscribe(MCN_HUB(pilot_cmd), NULL);
    }

    if (mf_control_node == NULL || mf_ins_node == NULL || mf_imu_node == NULL || mf_pilot_node == NULL) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

static void mf_reset_state(void)
{
    memset(mf_window, 0, sizeof(mf_window));
    memset(mf_ordered_window, 0, sizeof(mf_ordered_window));
    memset(mf_input, 0, sizeof(mf_input));
    mf_write_index = 0U;
    mf_sample_count = 0U;
    mf_feature_count = 0U;
    mf_last_sample_ms = 0U;
    mf_last_infer_ms = 0U;
}

static void mf_start(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    if (mf_running) {
        rt_kprintf("motor fault collector already running\n");
        return;
    }

    if (mf_subscribe_topics() != FMT_EOK) {
        rt_kprintf("motor fault collector failed to subscribe topics\n");
        return;
    }

    mf_reset_state();
    mf_stop_request = 0U;
    mf_running = 1U;

    mf_thread = rt_thread_create("mf_input",
                                 mf_thread_entry,
                                 RT_NULL,
                                 MOTOR_FAULT_THREAD_STACK_SIZE,
                                 MOTOR_FAULT_THREAD_PRIORITY,
                                 MOTOR_FAULT_THREAD_TICK);
    if (mf_thread == RT_NULL) {
        mf_running = 0U;
        rt_kprintf("motor fault collector failed to create thread\n");
        return;
    }

    rt_thread_startup(mf_thread);
    rt_kprintf("motor fault collector started: 100Hz sample, 500ms window, 100ms inference interval\n");
}
MSH_CMD_EXPORT(mf_start, start motor fault input collector);

static void mf_stop(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    if (!mf_running) {
        rt_kprintf("motor fault collector is not running\n");
        return;
    }

    mf_stop_request = 1U;
    rt_kprintf("motor fault collector stop requested\n");
}
MSH_CMD_EXPORT(mf_stop, stop motor fault input collector);

static void mf_status(int argc, char** argv)
{
    int threshold_int = (int)mf_pwm_high_threshold;
    int threshold_frac = (int)((mf_pwm_high_threshold - threshold_int) * 100.0f);

    (void)argc;
    (void)argv;

    if (threshold_frac < 0) {
        threshold_frac = -threshold_frac;
    }

    rt_kprintf("motor fault collector: %s\n", mf_running ? "running" : "stopped");
    rt_kprintf("samples: %u/%u write_index:%u feature_count:%u\n",
               mf_sample_count,
               MOTOR_FAULT_WINDOW_SIZE,
               mf_write_index,
               mf_feature_count);
    rt_kprintf("last_sample_ms:%u last_infer_ms:%u pwm_high_threshold:%d.%02d\n",
               mf_last_sample_ms,
               mf_last_infer_ms,
               threshold_int,
               threshold_frac);
}
MSH_CMD_EXPORT(mf_status, show motor fault input collector status);

static void mf_dump(int argc, char** argv)
{
    unsigned limit = 16U;

    if (argc > 1) {
        int arg_limit = atoi(argv[1]);
        if (arg_limit > 0 && arg_limit <= (int)MOTOR_FAULT_FEATURE_COUNT) {
            limit = (unsigned)arg_limit;
        }
    }

    rt_kprintf("motor fault input feature_count:%u\n", mf_feature_count);
    for (unsigned i = 0; i < limit && i < mf_feature_count; i++) {
        int value_int = (int)mf_input[i];
        int value_frac = (int)((mf_input[i] - value_int) * 1000000.0f);

        if (value_frac < 0) {
            value_frac = -value_frac;
        }

        rt_kprintf("[%u]=%d.%06d\n",
                   i,
                   value_int,
                   value_frac);
    }
}
MSH_CMD_EXPORT(mf_dump, dump motor fault input features);
