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

#include <calibration.h>
#include <firmament.h>
#include <string.h>

#include "module/fs_manager/fs_manager.h"
#include "module/ftp/ftp_manager.h"
#include "module/mavproxy/mavcmd.h"
#include "module/sensor/sensor_manager.h"
#include "task/task_comm.h"
#include "task/task_vehicle.h"

#define TAG "MAVCMD"

MCN_DECLARE(sensor_imu);
MCN_DECLARE(sensor_mag);
MCN_DECLARE(INS_FLAG);

#define GYR_CALIBRATE_COUNT 500
#define ACC_CALIBRATE_COUNT 200
#define MAG_CALIBRATE_COUNT 500
#define ACC_MAX_THRESHOLD   8.8f
#define ACC_MIN_THRESHOLD   1.0f
#define GYR_ROTAT_THRESHOLD 1.0f
#define CALIB_TIME_INTERVAL 20

typedef enum {

    ACC_POS_UP = 0,
    ACC_POS_DOWN,
    ACC_POS_LEFT,
    ACC_POS_RIGHT,
    ACC_POS_FRONT,
    ACC_POS_BACK,
    ACC_POS_IDLE,
} acc_position;

typedef struct {
    uint8_t set;
    uint32_t cnt;
    float sum[3];
    float bias[3];
} MAVCMD_CALIB_GYR;

typedef struct {
    uint8_t set;
    uint8_t status; //0:start 1:calibrating 2:finish
    uint8_t done_flag[6];
    uint32_t cnt[6];
    acc_position acc_pos;
    double v[9];
    double next_v[9];
    double P[81];
    double next_P[81];
    double bias[3];
    double RotM[9];
} MAVCMD_CALIB_ACC;

typedef struct {
    uint8_t set;
    uint8_t status;
    uint8_t done_flag[3];
    uint32_t cnt;
    acc_position acc_pos;
    double v[9];
    double next_v[9];
    double P[81];
    double next_P[81];
    double bias[3];
    double RotM[9];
} MAVCMD_CALIB_MAG;

typedef struct {
    float gyr_hist[3];
    uint16_t cnt;
    uint16_t jitter_num;
    uint8_t jitter;
} JitterDetect;

static MAVCMD_CALIB_GYR mavcmd_calib_gyr = { 0 };
static MAVCMD_CALIB_ACC mavcmd_calib_acc = { 0 };
static MAVCMD_CALIB_MAG mavcmd_calib_mag = { 0 };
static JitterDetect jitter_detect;
static uint8_t _mavcmd_set[MAVCMD_ITEM_NUM] = { 0 };
static StreamSession* _ftp_stream_session = NULL;

#ifdef FMT_RECORD_CALIBRATION_DATA
static int _cfd = -1;

static void _create_calib_data_file(const char* name)
{
    if (_cfd != 0) {
        close(_cfd);
        _cfd = -1;
    }

    _cfd = open(name, O_CREAT | O_TRUNC | O_WRONLY);

    if (_cfd == -1) {
        ulog_e(TAG, "fail to create file:%s\n", name);
    }
}

#endif

static acc_position _acc_position_detect(void)
{
    IMU_Report imu_report;
    static acc_position prev_pos = ACC_POS_IDLE;
    acc_position cur_pos;
    static uint16_t still_cnt = 0;
    float acc[3];

    mcn_copy_from_hub(MCN_ID(sensor_imu), &imu_report);
    acc[0] = imu_report.acc_B_mDs2[0];
    acc[1] = imu_report.acc_B_mDs2[1];
    acc[2] = imu_report.acc_B_mDs2[2];

    if ((fabsf(acc[0]) > ACC_MAX_THRESHOLD) && (fabsf(acc[1]) < ACC_MIN_THRESHOLD) && (fabsf(acc[2]) < ACC_MIN_THRESHOLD)) {
        if (acc[0] < 0) {
            cur_pos = ACC_POS_FRONT;
        } else {
            cur_pos = ACC_POS_BACK;
        }
    } else if ((fabsf(acc[0]) < ACC_MIN_THRESHOLD) && (fabsf(acc[1]) > ACC_MAX_THRESHOLD) && (fabsf(acc[2]) < ACC_MIN_THRESHOLD)) {
        if (acc[1] < 0) {
            cur_pos = ACC_POS_RIGHT;
        } else {
            cur_pos = ACC_POS_LEFT;
        }
    } else if ((fabsf(acc[0]) < ACC_MIN_THRESHOLD) && (fabsf(acc[1]) < ACC_MIN_THRESHOLD) && (fabsf(acc[2]) > ACC_MAX_THRESHOLD)) {
        if (acc[2] > 0) {
            cur_pos = ACC_POS_UP;
        } else {
            cur_pos = ACC_POS_DOWN;
        }
    } else {
        cur_pos = ACC_POS_IDLE;
    }

    if (cur_pos == prev_pos && cur_pos != ACC_POS_IDLE) {
        still_cnt++;

        if (still_cnt >= 1000 / CALIB_TIME_INTERVAL) {

            still_cnt = 1000 / CALIB_TIME_INTERVAL;
            return cur_pos;
        } else {
            return ACC_POS_IDLE;
        }
    } else {
        still_cnt = 0;
        prev_pos = cur_pos;

        return ACC_POS_IDLE;
    }
}

void _detect_jitter(void)
{
    IMU_Report imu_report;

    mcn_copy_from_hub(MCN_ID(sensor_imu), &imu_report);

    if (jitter_detect.cnt++ < 20) {
        float gyr_jitter[3];

        gyr_jitter[0] = imu_report.gyr_B_radDs[0] - jitter_detect.gyr_hist[0];
        gyr_jitter[1] = imu_report.gyr_B_radDs[1] - jitter_detect.gyr_hist[1];
        gyr_jitter[2] = imu_report.gyr_B_radDs[2] - jitter_detect.gyr_hist[2];

        if (fabsf(gyr_jitter[0]) > 0.8 || fabsf(gyr_jitter[1]) > 0.8 || fabsf(gyr_jitter[2]) > 0.8) {
            jitter_detect.jitter_num++;
        }
    } else {
        if (jitter_detect.jitter_num >= 10) {
            jitter_detect.jitter = 1;
        } else {
            jitter_detect.jitter = 0;
        }

        jitter_detect.cnt = 0;
        jitter_detect.jitter_num = 0;
    }

    jitter_detect.gyr_hist[0] = imu_report.gyr_B_radDs[0];
    jitter_detect.gyr_hist[1] = imu_report.gyr_B_radDs[1];
    jitter_detect.gyr_hist[2] = imu_report.gyr_B_radDs[2];
}

static void _send_statustext_msg(mav_status_type status, mavlink_message_t* msg)
{
    mavlink_statustext_t statustext;
    mavlink_system_t mavlink_system;

    mavlink_system = mavproxy_get_system();

    memset(statustext.text, 0, sizeof(statustext.text));
    statustext.severity = mavlink_get_status_content(status).severity;
    memcpy(statustext.text, mavlink_get_status_content(status).string, strlen(mavlink_get_status_content(status).string));
    mavlink_msg_statustext_encode(mavlink_system.sysid, mavlink_system.compid, msg, &statustext);

    mavproxy_send_immediate_msg(msg, 1);
}

void _gyr_calibration_init(void)
{
    mavcmd_calib_gyr.cnt = 0;
    mavcmd_calib_gyr.sum[0] = 0.0f;
    mavcmd_calib_gyr.sum[1] = 0.0f;
    mavcmd_calib_gyr.sum[2] = 0.0f;
}

void _gyr_calibration_reset(void)
{
    mavcmd_calib_gyr.set = 0;

    mavcmd_clear(MAVCMD_CALIBRATION_GYR);
    _gyr_calibration_init();
}

void _gyr_mavlink_calibration(void)
{
    mavlink_message_t msg;

    if (mavcmd_calib_gyr.cnt == 0) {

        jitter_detect.gyr_hist[0] = 0;
        jitter_detect.gyr_hist[1] = 0;
        jitter_detect.gyr_hist[2] = 0;
        jitter_detect.cnt = 0;
        jitter_detect.jitter_num = 0;
        jitter_detect.jitter = 0;

        _send_statustext_msg(CAL_START_GYRO, &msg);
    }

    IMU_Report imu_report;
    mcn_copy_from_hub(MCN_ID(sensor_imu), &imu_report);

    mavcmd_calib_gyr.sum[0] += imu_report.gyr_B_radDs[0];
    mavcmd_calib_gyr.sum[1] += imu_report.gyr_B_radDs[1];
    mavcmd_calib_gyr.sum[2] += imu_report.gyr_B_radDs[2];

#ifdef FMT_RECORD_CALIBRATION_DATA
    if (_cfd != -1) {
        fs_fprintf(_cfd, "%f %f %f\n", imu_report.gyr_B_radDs[0], imu_report.gyr_B_radDs[1], imu_report.gyr_B_radDs[2]);
    }
#endif

    mavcmd_calib_gyr.cnt++;

    if (!(mavcmd_calib_gyr.cnt % (GYR_CALIBRATE_COUNT / 10)) && (mavcmd_calib_gyr.cnt <= GYR_CALIBRATE_COUNT)) {
        // send progress

        _send_statustext_msg(CAL_PROGRESS_0 + (uint32_t)((float)mavcmd_calib_gyr.cnt / GYR_CALIBRATE_COUNT * 10), &msg);
    }

    if (mavcmd_calib_gyr.cnt >= GYR_CALIBRATE_COUNT) {

        mavcmd_calib_gyr.bias[0] = mavcmd_calib_gyr.sum[0] / GYR_CALIBRATE_COUNT;
        mavcmd_calib_gyr.bias[1] = mavcmd_calib_gyr.sum[1] / GYR_CALIBRATE_COUNT;
        mavcmd_calib_gyr.bias[2] = mavcmd_calib_gyr.sum[2] / GYR_CALIBRATE_COUNT;

        _send_statustext_msg(CAL_DONE, &msg);

        console_printf("gyr bias:%f %f %f\n", mavcmd_calib_gyr.bias[0], mavcmd_calib_gyr.bias[1], mavcmd_calib_gyr.bias[2]);

        PARAM_SET_FLOAT(CALIB, GYRO0_XOFF, mavcmd_calib_gyr.bias[0]);
        PARAM_SET_FLOAT(CALIB, GYRO0_YOFF, mavcmd_calib_gyr.bias[1]);
        PARAM_SET_FLOAT(CALIB, GYRO0_ZOFF, mavcmd_calib_gyr.bias[2]);

        _gyr_calibration_reset();
    }
}

void _acc_calibration_init(void)
{
    int i;

    mavcmd_calib_acc.status = 0;

    for (i = 0; i < 6; i++) {
        mavcmd_calib_acc.done_flag[i] = 0;
        mavcmd_calib_acc.cnt[i] = 0;
    }
}

void _acc_calibration_reset(void)
{
    mavcmd_calib_acc.set = 0;

    mavcmd_clear(MAVCMD_CALIBRATION_ACC);
    _acc_calibration_init();
}

void _acc_mavlink_calibration(void)
{
    mavlink_message_t msg;

    if (mavcmd_calib_acc.status == 0) {

        calibration_initialize();

        for (uint8_t i = 0; i < 81; i++) {
            mavcmd_calib_acc.P[i] = 0.0;
        }

        mavcmd_calib_acc.P[0] = 10.0;
        mavcmd_calib_acc.P[1 + 9] = 10.0;
        mavcmd_calib_acc.P[2 + 18] = 10.0;
        mavcmd_calib_acc.P[3 + 27] = 0.0;
        mavcmd_calib_acc.P[4 + 36] = 0.0;
        mavcmd_calib_acc.P[5 + 45] = 0.0;
        mavcmd_calib_acc.P[6 + 54] = 1.0;
        mavcmd_calib_acc.P[7 + 63] = 1.0;
        mavcmd_calib_acc.P[8 + 72] = 1.0;

        for (uint8_t i = 0; i < 9; i++) {
            mavcmd_calib_acc.v[i] = 0.0;
        }

        mavcmd_calib_acc.acc_pos = ACC_POS_IDLE;
        mavcmd_calib_acc.status = 1;

        _send_statustext_msg(CAL_START_ACC, &msg);
    }

    _detect_jitter();
    acc_position temp_pos = _acc_position_detect();

    if (!jitter_detect.jitter && temp_pos != ACC_POS_IDLE) {

        if (mavcmd_calib_acc.acc_pos != temp_pos) {
            mavcmd_calib_acc.acc_pos = temp_pos;

            if (!mavcmd_calib_acc.done_flag[mavcmd_calib_acc.acc_pos]) {
                _send_statustext_msg(CAL_UP_DETECTED + mavcmd_calib_acc.acc_pos, &msg);
            }
        }

        if (mavcmd_calib_acc.cnt[mavcmd_calib_acc.acc_pos] < ACC_CALIBRATE_COUNT) {
            IMU_Report imu_report;
            mcn_copy_from_hub(MCN_ID(sensor_imu), &imu_report);

#ifdef FMT_RECORD_CALIBRATION_DATA
            if (_cfd != -1) {
                fs_fprintf(_cfd, "%f %f %f\n", imu_report.acc_B_mDs2[0], imu_report.acc_B_mDs2[1], imu_report.acc_B_mDs2[2]);
            }
#endif

            ellipsoid_fit_step(imu_report.acc_B_mDs2[0], imu_report.acc_B_mDs2[1], imu_report.acc_B_mDs2[2],
                mavcmd_calib_acc.v, mavcmd_calib_acc.P, 0.001,
                mavcmd_calib_acc.next_v, mavcmd_calib_acc.next_P);

            for (uint8_t i = 0; i < 9; i++) {
                mavcmd_calib_acc.v[i] = mavcmd_calib_acc.next_v[i];
            }

            for (uint8_t i = 0; i < 81; i++) {
                mavcmd_calib_acc.P[i] = mavcmd_calib_acc.next_P[i];
            }

            mavcmd_calib_acc.cnt[mavcmd_calib_acc.acc_pos] += 1;

            if (!(mavcmd_calib_acc.cnt[mavcmd_calib_acc.acc_pos] % (ACC_CALIBRATE_COUNT / 10))
                && (mavcmd_calib_acc.cnt[mavcmd_calib_acc.acc_pos] <= ACC_CALIBRATE_COUNT)) {

                _send_statustext_msg(CAL_PROGRESS_0 + (uint32_t)((float)mavcmd_calib_acc.cnt[mavcmd_calib_acc.acc_pos] / ACC_CALIBRATE_COUNT * 10), &msg);
            }
        } else {
            if (!mavcmd_calib_acc.done_flag[mavcmd_calib_acc.acc_pos]) {
                _send_statustext_msg(CAL_UP_DONE + mavcmd_calib_acc.acc_pos, &msg);
                mavcmd_calib_acc.done_flag[mavcmd_calib_acc.acc_pos] = 1;
            }
        }

        // check if finish
        uint8_t finish = 1;

        for (uint8_t i = 0; i < 6; i++) {
            if (!mavcmd_calib_acc.done_flag[i]) {
                finish = 0;
                break;
            }
        }

        if (finish) {
            creal_T mat[9];
            double u[9];
            creal_T radii[3];

            ellipsoid_fit_solve(mavcmd_calib_acc.v, mat, mavcmd_calib_acc.bias, u, radii);

            for (uint8_t i = 0; i < 9; i++) {
                mavcmd_calib_acc.RotM[i] = mat[i].re;
            }

            _send_statustext_msg(CAL_DONE, &msg);

            console_printf("bias:%f %f %f\n", mavcmd_calib_acc.bias[0], mavcmd_calib_acc.bias[1], mavcmd_calib_acc.bias[2]);
            console_printf("rotM:\n");
            console_printf("%f %f %f\n", mavcmd_calib_acc.RotM[0], mavcmd_calib_acc.RotM[3], mavcmd_calib_acc.RotM[6]);
            console_printf("%f %f %f\n", mavcmd_calib_acc.RotM[1], mavcmd_calib_acc.RotM[4], mavcmd_calib_acc.RotM[7]);
            console_printf("%f %f %f\n", mavcmd_calib_acc.RotM[2], mavcmd_calib_acc.RotM[5], mavcmd_calib_acc.RotM[8]);

            PARAM_SET_FLOAT(CALIB, ACC0_XOFF, mavcmd_calib_acc.bias[0]);
            PARAM_SET_FLOAT(CALIB, ACC0_YOFF, mavcmd_calib_acc.bias[1]);
            PARAM_SET_FLOAT(CALIB, ACC0_ZOFF, mavcmd_calib_acc.bias[2]);

            PARAM_SET_FLOAT(CALIB, ACC0_XXSCALE, mavcmd_calib_acc.RotM[0]);
            PARAM_SET_FLOAT(CALIB, ACC0_XYSCALE, mavcmd_calib_acc.RotM[3]);
            PARAM_SET_FLOAT(CALIB, ACC0_XZSCALE, mavcmd_calib_acc.RotM[6]);
            PARAM_SET_FLOAT(CALIB, ACC0_YYSCALE, mavcmd_calib_acc.RotM[4]);
            PARAM_SET_FLOAT(CALIB, ACC0_YZSCALE, mavcmd_calib_acc.RotM[7]);
            PARAM_SET_FLOAT(CALIB, ACC0_ZZSCALE, mavcmd_calib_acc.RotM[8]);

            _acc_calibration_reset();
        }
    }
}

void _mag_calibration_init(void)
{
    mavcmd_calib_mag.status = 0;
    mavcmd_calib_mag.done_flag[0] = 0;
    mavcmd_calib_mag.done_flag[1] = 0;
    mavcmd_calib_mag.done_flag[2] = 0;
    mavcmd_calib_mag.cnt = 0;
}

void _mag_calibration_reset(void)
{
    mavcmd_calib_mag.set = 0;

    mavcmd_clear(MAVCMD_CALIBRATION_MAG);
    _mag_calibration_init();
}

void _mag_mavlink_calibration(void)
{
    mavlink_message_t msg;

    switch (mavcmd_calib_mag.status) {
    case 0: {
        calibration_initialize();

        for (uint8_t i = 0; i < 81; i++) {
            mavcmd_calib_mag.P[i] = 0.0;
        }

        mavcmd_calib_mag.P[0] = 10.0;
        mavcmd_calib_mag.P[1 + 9] = 10.0;
        mavcmd_calib_mag.P[2 + 18] = 10.0;
        mavcmd_calib_mag.P[3 + 27] = 1.0;
        mavcmd_calib_mag.P[4 + 36] = 1.0;
        mavcmd_calib_mag.P[5 + 45] = 1.0;
        mavcmd_calib_mag.P[6 + 54] = 1.0;
        mavcmd_calib_mag.P[7 + 63] = 1.0;
        mavcmd_calib_mag.P[8 + 72] = 1.0;

        for (uint8_t i = 0; i < 9; i++) {
            mavcmd_calib_mag.v[i] = 0.0;
        }

        _send_statustext_msg(CAL_START_MAG, &msg);

        mavcmd_calib_mag.status = 1;
    } break;

    case 1: {
        acc_position temp_pos = _acc_position_detect();

        if (temp_pos == ACC_POS_DOWN && !mavcmd_calib_mag.done_flag[0]) {
            mavcmd_calib_mag.acc_pos = temp_pos;
            mavcmd_calib_mag.cnt = 0;
            mavcmd_calib_mag.status = 2;

            _send_statustext_msg(CAL_DOWN_DETECTED, &msg);
        }

        if (temp_pos == ACC_POS_FRONT && !mavcmd_calib_mag.done_flag[1]) {
            mavcmd_calib_mag.acc_pos = temp_pos;
            mavcmd_calib_mag.cnt = 0;
            mavcmd_calib_mag.status = 2;

            _send_statustext_msg(CAL_FRONT_DETECTED, &msg);
        }

        if (temp_pos == ACC_POS_LEFT && !mavcmd_calib_mag.done_flag[2]) {
            mavcmd_calib_mag.acc_pos = temp_pos;
            mavcmd_calib_mag.cnt = 0;
            mavcmd_calib_mag.status = 2;

            _send_statustext_msg(CAL_LEFT_DETECTED, &msg);
        }
    } break;

    case 2: {
        IMU_Report imu_report;
        uint8_t rotat = 0;

        mcn_copy_from_hub(MCN_ID(sensor_imu), &imu_report);

        if (mavcmd_calib_mag.acc_pos == ACC_POS_DOWN) {
            if (fabs(imu_report.gyr_B_radDs[2]) >= GYR_ROTAT_THRESHOLD) {
                rotat = 1;
            }
        } else if (mavcmd_calib_mag.acc_pos == ACC_POS_FRONT) {
            if (fabs(imu_report.gyr_B_radDs[0]) >= GYR_ROTAT_THRESHOLD) {
                rotat = 1;
            }
        } else if (mavcmd_calib_mag.acc_pos == ACC_POS_LEFT) {
            if (fabs(imu_report.gyr_B_radDs[1]) >= GYR_ROTAT_THRESHOLD) {
                rotat = 1;
            }
        } else {
            mavcmd_calib_mag.status = 1;
            break;
        }

        if (rotat) {
            Mag_Report mag_report;

            mcn_copy_from_hub(MCN_ID(sensor_mag), &mag_report);

#ifdef FMT_RECORD_CALIBRATION_DATA
            if (_cfd != -1) {
                fs_fprintf(_cfd, "%f %f %f\n", mag_report.mag_B_gauss[0], mag_report.mag_B_gauss[1], mag_report.mag_B_gauss[2]);
            }
#endif

            ellipsoid_fit_step(mag_report.mag_B_gauss[0], mag_report.mag_B_gauss[1], mag_report.mag_B_gauss[2],
                mavcmd_calib_mag.v, mavcmd_calib_mag.P, 0.001,
                mavcmd_calib_mag.next_v, mavcmd_calib_mag.next_P);

            for (uint8_t i = 0; i < 9; i++) {
                mavcmd_calib_mag.v[i] = mavcmd_calib_mag.next_v[i];
            }

            for (uint8_t i = 0; i < 81; i++) {
                mavcmd_calib_mag.P[i] = mavcmd_calib_mag.next_P[i];
            }

            if (++mavcmd_calib_mag.cnt >= MAG_CALIBRATE_COUNT) {
                if (mavcmd_calib_mag.acc_pos == ACC_POS_DOWN) {
                    mavcmd_calib_mag.done_flag[0] = 1;

                    _send_statustext_msg(CAL_DOWN_DONE, &msg);
                } else if (mavcmd_calib_mag.acc_pos == ACC_POS_FRONT) {
                    mavcmd_calib_mag.done_flag[1] = 1;

                    _send_statustext_msg(CAL_FRONT_DONE, &msg);
                } else if (mavcmd_calib_mag.acc_pos == ACC_POS_LEFT) {
                    mavcmd_calib_mag.done_flag[2] = 1;

                    _send_statustext_msg(CAL_LEFT_DONE, &msg);
                }

                if (mavcmd_calib_mag.done_flag[0] && mavcmd_calib_mag.done_flag[1] && mavcmd_calib_mag.done_flag[2]) {
                    mavcmd_calib_mag.status = 3;
                } else {
                    mavcmd_calib_mag.status = 1;
                }
            }

            if (!(mavcmd_calib_mag.cnt % (MAG_CALIBRATE_COUNT / 10))
                && (mavcmd_calib_mag.cnt <= MAG_CALIBRATE_COUNT)) {

                _send_statustext_msg(CAL_PROGRESS_0 + (uint32_t)((float)mavcmd_calib_mag.cnt / MAG_CALIBRATE_COUNT * 10), &msg);
            }
        }
    } break;

    case 3: {
        creal_T mat[9];
        double u[9];
        creal_T radii[3];

        ellipsoid_fit_solve(mavcmd_calib_mag.v, mat, mavcmd_calib_mag.bias, u, radii);

        for (uint8_t i = 0; i < 9; i++) {
            mavcmd_calib_mag.RotM[i] = mat[i].re;
        }

        _send_statustext_msg(CAL_DONE, &msg);

        console_printf("bias:%f %f %f\n", mavcmd_calib_mag.bias[0], mavcmd_calib_mag.bias[1], mavcmd_calib_mag.bias[2]);
        console_printf("rotM:\n");
        console_printf("%f %f %f\n", mavcmd_calib_mag.RotM[0], mavcmd_calib_mag.RotM[3], mavcmd_calib_mag.RotM[6]);
        console_printf("%f %f %f\n", mavcmd_calib_mag.RotM[1], mavcmd_calib_mag.RotM[4], mavcmd_calib_mag.RotM[7]);
        console_printf("%f %f %f\n", mavcmd_calib_mag.RotM[2], mavcmd_calib_mag.RotM[5], mavcmd_calib_mag.RotM[8]);

        PARAM_SET_FLOAT(CALIB, MAG0_XOFF, mavcmd_calib_mag.bias[0]);
        PARAM_SET_FLOAT(CALIB, MAG0_YOFF, mavcmd_calib_mag.bias[1]);
        PARAM_SET_FLOAT(CALIB, MAG0_ZOFF, mavcmd_calib_mag.bias[2]);

        PARAM_SET_FLOAT(CALIB, MAG0_XXSCALE, mavcmd_calib_mag.RotM[0]);
        PARAM_SET_FLOAT(CALIB, MAG0_XYSCALE, mavcmd_calib_mag.RotM[3]);
        PARAM_SET_FLOAT(CALIB, MAG0_XZSCALE, mavcmd_calib_mag.RotM[6]);
        PARAM_SET_FLOAT(CALIB, MAG0_YYSCALE, mavcmd_calib_mag.RotM[4]);
        PARAM_SET_FLOAT(CALIB, MAG0_YZSCALE, mavcmd_calib_mag.RotM[7]);
        PARAM_SET_FLOAT(CALIB, MAG0_ZZSCALE, mavcmd_calib_mag.RotM[8]);

        _mag_calibration_reset();
    } break;

    default:
        break;
    }
}

void mavcmd_set(MavCmd_ID cmd, void* data)
{
    if (cmd == MAVCMD_CALIBRATION_GYR) {

        memset(&mavcmd_calib_gyr, 0, sizeof(mavcmd_calib_gyr));

        mavcmd_calib_gyr.set = 1;

#ifdef FMT_RECORD_CALIBRATION_DATA
        _create_calib_data_file("/usr/gyr.txt");
#endif

        _gyr_calibration_init();
    } else if (cmd == MAVCMD_CALIBRATION_ACC) {

        memset(&mavcmd_calib_acc, 0, sizeof(mavcmd_calib_acc));

        mavcmd_calib_acc.set = 1;

#ifdef FMT_RECORD_CALIBRATION_DATA
        _create_calib_data_file("/usr/acc.txt");
#endif

        _acc_calibration_init();
    } else if (cmd == MAVCMD_CALIBRATION_MAG) {

        memset(&mavcmd_calib_mag, 0, sizeof(mavcmd_calib_mag));

        mavcmd_calib_mag.set = 1;

#ifdef FMT_RECORD_CALIBRATION_DATA
        _create_calib_data_file("/usr/mag.txt");
#endif

        _mag_calibration_init();
    } else if (cmd == MAVCMD_STREAM_SESSION) {

        if (data) {
            /* ftp stream session */
            _ftp_stream_session = (StreamSession*)data;
            _mavcmd_set[cmd] = 1;
        }
    } else {
        /* unknown command */
        return;
    }
}

void mavcmd_clear(MavCmd_ID cmd)
{
    if (cmd < MAVCMD_ITEM_NUM) {
        _mavcmd_set[cmd] = 0;
    }

#ifdef FMT_RECORD_CALIBRATION_DATA
    if (cmd == MAVCMD_CALIBRATION_GYR || cmd == MAVCMD_CALIBRATION_ACC || cmd == MAVCMD_CALIBRATION_MAG) {
        if (_cfd != -1) {
            close(_cfd);
            _cfd = -1;
        }
    }
#endif
}

void mavcmd_process(void)
{
    if (mavcmd_calib_gyr.set) {
        TIMETAG_CHECK_EXECUTE(gyr_calib, CALIB_TIME_INTERVAL, _gyr_mavlink_calibration();)
    }

    if (mavcmd_calib_acc.set) {
        TIMETAG_CHECK_EXECUTE(gyr_calib, CALIB_TIME_INTERVAL, _acc_mavlink_calibration();)
    }

    if (mavcmd_calib_mag.set) {
        TIMETAG_CHECK_EXECUTE(gyr_calib, CALIB_TIME_INTERVAL, _mag_mavlink_calibration();)
    }

    if (_mavcmd_set[MAVCMD_STREAM_SESSION]) {
        ftp_stream_send(_ftp_stream_session);
    }
}