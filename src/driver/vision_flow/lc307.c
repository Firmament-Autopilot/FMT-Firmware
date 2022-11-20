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

#include "model/ins/ins_interface.h"
#include "module/sensor/sensor_hub.h"
#include "module/workqueue/workqueue_manager.h"

MCN_DECLARE(sensor_imu0);
MCN_DECLARE(ins_output);
MCN_DECLARE(sensor_rangefinder);

/////////////////////////////////////

// 50fps 配置初始化代码
const static uint8_t tab_focus[4] = { 0x96, 0x26, 0xbc, 0x50 };

const static uint8_t lc307_config_50fps[] = {
    //地址, 数据
    0x12,
    0x80,
    0x11,
    0x30,
    0x1b,
    0x06,
    0x6b,
    0x43,
    0x12,
    0x20,
    0x3a,
    0x00,
    0x15,
    0x02,
    0x62,
    0x81,
    0x08,
    0xa0,
    0x06,
    0x68,
    0x2b,
    0x20,
    0x92,
    0x25,
    0x27,
    0x97,
    0x17,
    0x01,
    0x18,
    0x79,
    0x19,
    0x00,
    0x1a,
    0xa0,
    0x03,
    0x00,
    0x13,
    0x00,
    0x01,
    0x13,
    0x02,
    0x20,
    0x87,
    0x16,
    0x8c,
    0x01,
    0x8d,
    0xcc,
    0x13,
    0x07,
    0x33,
    0x10,
    0x34,
    0x1d,
    0x35,
    0x46,
    0x36,
    0x40,
    0x37,
    0xa4,
    0x38,
    0x7c,
    0x65,
    0x46,
    0x66,
    0x46,
    0x6e,
    0x20,
    0x9b,
    0xa4,
    0x9c,
    0x7c,
    0xbc,
    0x0c,
    0xbd,
    0xa4,
    0xbe,
    0x7c,
    0x20,
    0x09,
    0x09,
    0x03,
    0x72,
    0x2f,
    0x73,
    0x2f,
    0x74,
    0xa7,
    0x75,
    0x12,
    0x79,
    0x8d,
    0x7a,
    0x00,
    0x7e,
    0xfa,
    0x70,
    0x0f,
    0x7c,
    0x84,
    0x7d,
    0xba,
    0x5b,
    0xc2,
    0x76,
    0x90,
    0x7b,
    0x55,
    0x71,
    0x46,
    0x77,
    0xdd,
    0x13,
    0x0f,
    0x8a,
    0x10,
    0x8b,
    0x20,
    0x8e,
    0x21,
    0x8f,
    0x40,
    0x94,
    0x41,
    0x95,
    0x7e,
    0x96,
    0x7f,
    0x97,
    0xf3,
    0x13,
    0x07,
    0x24,
    0x58,
    0x97,
    0x48,
    0x25,
    0x08,
    0x94,
    0xb5,
    0x95,
    0xc0,
    0x80,
    0xf4,
    0x81,
    0xe0,
    0x82,
    0x1b,
    0x83,
    0x37,
    0x84,
    0x39,
    0x85,
    0x58,
    0x86,
    0xff,
    0x89,
    0x15,
    0x8a,
    0xb8,
    0x8b,
    0x99,
    0x39,
    0x98,
    0x3f,
    0x98,
    0x90,
    0xa0,
    0x91,
    0xe0,
    0x40,
    0x20,
    0x41,
    0x28,
    0x42,
    0x26,
    0x43,
    0x25,
    0x44,
    0x1f,
    0x45,
    0x1a,
    0x46,
    0x16,
    0x47,
    0x12,
    0x48,
    0x0f,
    0x49,
    0x0d,
    0x4b,
    0x0b,
    0x4c,
    0x0a,
    0x4e,
    0x08,
    0x4f,
    0x06,
    0x50,
    0x06,
    0x5a,
    0x56,
    0x51,
    0x1b,
    0x52,
    0x04,
    0x53,
    0x4a,
    0x54,
    0x26,
    0x57,
    0x75,
    0x58,
    0x2b,
    0x5a,
    0xd6,
    0x51,
    0x28,
    0x52,
    0x1e,
    0x53,
    0x9e,
    0x54,
    0x70,
    0x57,
    0x50,
    0x58,
    0x07,
    0x5c,
    0x28,
    0xb0,
    0xe0,
    0xb1,
    0xc0,
    0xb2,
    0xb0,
    0xb3,
    0x4f,
    0xb4,
    0x63,
    0xb4,
    0xe3,
    0xb1,
    0xf0,
    0xb2,
    0xa0,
    0x55,
    0x00,
    0x56,
    0x40,
    0x96,
    0x50,
    0x9a,
    0x30,
    0x6a,
    0x81,
    0x23,
    0x33,
    0xa0,
    0xd0,
    0xa1,
    0x31,
    0xa6,
    0x04,
    0xa2,
    0x0f,
    0xa3,
    0x2b,
    0xa4,
    0x0f,
    0xa5,
    0x2b,
    0xa7,
    0x9a,
    0xa8,
    0x1c,
    0xa9,
    0x11,
    0xaa,
    0x16,
    0xab,
    0x16,
    0xac,
    0x3c,
    0xad,
    0xf0,
    0xae,
    0x57,
    0xc6,
    0xaa,
    0xd2,
    0x78,
    0xd0,
    0xb4,
    0xd1,
    0x00,
    0xc8,
    0x10,
    0xc9,
    0x12,
    0xd3,
    0x09,
    0xd4,
    0x2a,
    0xee,
    0x4c,
    0x7e,
    0xfa,
    0x74,
    0xa7,
    0x78,
    0x4e,
    0x60,
    0xe7,
    0x61,
    0xc8,
    0x6d,
    0x70,
    0x1e,
    0x39,
    0x98,
    0x1a
};

#define SENSOR_IIC_ADDR 0xdc

#define LC307_VALID_VALUE 0xF5

/////////////////////////////////////

#define EVENT_LC307_UPDATE (1 << 0)

MCN_DECLARE(sensor_optflow);

typedef enum {
    LC307_HEADER_0XFE = 0,
    LC307_HEADER_0X0A,
    LC307_FLOW_X_L,
    LC307_FLOW_X_H,
    LC307_FLOW_Y_L,
    LC307_FLOW_Y_H,
    LC307_INTEGRATION_TIMESPAN_L,
    LC307_INTEGRATION_TIMESPAN_H,
    LC307_GROUND_DISTANCE_L,
    LC307_GROUND_DISTANCE_H,
    LC307_VALID,
    LC307_VERSION,
    LC307_XOR,
    LC307_END_0X55
} LC307_State;

typedef struct {
    uint32_t timestamp;           // ms
    int16_t flow_x_integral;      //
    int16_t flow_y_integral;      //
    int16_t integration_timespan; //
    int16_t ground_distance;
    uint8_t valid;
    uint8_t version;
} lc307_data;

static rt_device_t dev;
static rt_thread_t thread;
static struct rt_event event;
static lc307_data data;
static optflow_data_t optflow_report;

static void start_thread(void* parameter)
{
    RT_CHECK(rt_thread_startup(thread));
}

static rt_err_t rx_ind_cb(rt_device_t dev, rt_size_t size)
{
    return rt_event_send(&event, EVENT_LC307_UPDATE);
}

static bool parse_package(uint8_t c)
{
    static LC307_State state;
    static uint8_t recv_len;
    static uint8_t cs;
    bool cmplt = false;
    static uint8_t buf[10];

    switch (state) {
    case LC307_HEADER_0XFE:
        if (c == 0xFE) {
            state++;
        }
        break;
    case LC307_HEADER_0X0A:
        if (c == 0x0A) {
            cs = 0;
            state++;
        } else {
            state = LC307_HEADER_0XFE;
        }
        break;
    case LC307_FLOW_X_L:
    case LC307_FLOW_X_H:
    case LC307_FLOW_Y_L:
    case LC307_FLOW_Y_H:
    case LC307_INTEGRATION_TIMESPAN_L:
    case LC307_INTEGRATION_TIMESPAN_H:
    case LC307_GROUND_DISTANCE_L:
    case LC307_GROUND_DISTANCE_H:
    case LC307_VALID:
    case LC307_VERSION:
        buf[recv_len] = c;
        cs ^= c;
        state++;
        recv_len++;
        break;
    case LC307_XOR:
        if (cs == c) {
            state++;
        } else {
            printf("wrong cheksum:%x %x\n", cs, c);
            state = LC307_HEADER_0XFE;
        }
        break;
    case LC307_END_0X55:
        if (c == 0x55) {

            if (buf[8] == 0xF5) {
                cmplt = true;
                data.timestamp = systime_now_ms();
                data.flow_x_integral = (buf[1] << 8 | buf[0]);
                data.flow_y_integral = (buf[3] << 8 | buf[2]);
                data.integration_timespan = (buf[5] << 8 | buf[4]);
                data.ground_distance = (buf[7] << 8 | buf[6]);
                data.valid = buf[8];
                data.version = buf[9];
            } else {
                printf("debug=>>> LC307 not value  valid = %02x \n", buf[8]);
            }

        } else {
            printf("wrong LC307_END_0X55:%x %x\n", cs, c);
        }
        state = LC307_HEADER_0XFE;
    default:
        state = LC307_HEADER_0XFE;
        break;
    }

    return cmplt;
}

static fmt_err_t _writ_reg(rt_device_t dev,
                           const void* buffer,
                           rt_size_t size)
{
    if (rt_device_write(dev, 0, (const void*)&buffer, sizeof(size)) != sizeof(size)) {
        return FMT_ERROR;
    }
    return FMT_EOK;
}

static int32_t lc307_cmd_AA_AB(void)
{
    // 1. send 0xAA => open the setting lc307
    uint8_t buf[6];
    uint8_t recv_buf[3];

    buf[0] = 0xAA;
    _writ_reg(dev, buf, 1);

    int32_t ret;
    /* flush read buffer */
    do {
        uint8_t c;
        ret = rt_device_read(dev, 0, &c, 1);
    } while (ret);

    printf("ret1 = %02x \n", ret);

    //3-0xAB指令	即 指令为：0xAB，0x96，0x26，0xbc，0x50， 0x5c
    // 成功后模组返回 0xAB 0x00 0xAB

    buf[0] = 0xAB;
    buf[1] = tab_focus[0];
    buf[2] = tab_focus[1];
    buf[3] = tab_focus[2];
    buf[4] = tab_focus[3];
    buf[5] = (tab_focus[0] ^ tab_focus[1] ^ tab_focus[2] ^ tab_focus[3]);
    ret = _writ_reg(dev, buf, 6);
    printf("ret2 = %02x \n", ret);

    // 设置timeout  100ms 没收到就return;
    uint32_t t = systime_now_ms();
    uint32_t t_start = t;
    uint8_t cnt = 0;
    do {
        uint8_t recv;
        ret = rt_device_read(dev, 0, &recv, 1);
        printf("ret3 = %02x \n", ret);
        if (ret == 1) {
            recv_buf[cnt] = recv;
            cnt++;
        } else {
            t = systime_now_ms();
            if (t - t_start > 100) {
                printf("CMD AB TIMEOUT!!!\r\n");
                return -1;
            }
        }
    } while (cnt < 3);

    if ((recv_buf[0] != 0xAB) || (recv_buf[1] != 0x00) || (recv_buf[2] != 0xAB)) {
        printf("=>>>>>>> lc307 0xAB RETURN ERROR!!! \r\n");
        return -2;
    }

    return 0;
}

static int32_t lc307_cmd_BB_DD(void)
{
    uint16_t len = sizeof(lc307_config_50fps);

    uint8_t buf[5];
    uint8_t recv_buf[3];

    //0xBB指令
    for (int i = 0; i < len; i += 2) {

        buf[0] = 0xBB;
        buf[1] = SENSOR_IIC_ADDR;
        buf[2] = lc307_config_50fps[i];
        buf[3] = lc307_config_50fps[i + 1];
        buf[4] = (SENSOR_IIC_ADDR ^ lc307_config_50fps[i] ^ lc307_config_50fps[i + 1]);
        _writ_reg(dev, buf, 5);

        // 设置timeout  100ms 没收到就return;
        uint32_t t = systime_now_ms();
        uint32_t t_start = t;
        uint8_t cnt = 0;
        do {
            uint8_t recv;
            int32_t ret = rt_device_read(dev, 0, &recv, 1);
            if (ret == 1) {
                recv_buf[cnt] = recv;
                cnt++;
            } else {
                t = systime_now_ms();
                if (t - t_start < 100) {
                    sys_msleep(1);
                } else {
                    printf("CMD BB TIMEOUT!!! \r\n");
                    return -1;
                }
            }
        } while (cnt < 3);

        if ((recv_buf[0] != 0xBB) || (recv_buf[1] != 0x00) || (recv_buf[2] != 0xBB)) {
            printf("CMD BB RETURN ERROR!!!\r\n");
            return -2;
        }
    }

    //0xDD
    buf[0] = 0xDD;
    _writ_reg(dev, buf, 1);

    printf("lc307 BB DD success\n");

    return 0;
}

#define LPF_1_(hz, t, in, out) ((out) += (1 / (1 + 1 / ((hz)*3.14f * (t)))) * ((in) - (out))) //一阶低通滤波

static void dcm_from_euler(const float rpy[3], float dcm[9])
{
    float cosPhi = arm_cos_f32(rpy[0]);
    float sinPhi = arm_sin_f32(rpy[0]);
    float cosThe = arm_cos_f32(rpy[1]);
    float sinThe = arm_sin_f32(rpy[1]);
    float cosPsi = arm_cos_f32(rpy[2]);
    float sinPsi = arm_sin_f32(rpy[2]);

    dcm[0] = cosThe * cosPsi;
    dcm[1] = -cosPhi * sinPsi + sinPhi * sinThe * cosPsi;
    dcm[2] = sinPhi * sinPsi + cosPhi * sinThe * cosPsi;

    dcm[3] = cosThe * sinPsi;
    dcm[4] = cosPhi * cosPsi + sinPhi * sinThe * sinPsi;
    dcm[5] = -sinPhi * cosPsi + cosPhi * sinThe * sinPsi;

    dcm[6] = -sinThe;
    dcm[7] = sinPhi * cosThe;
    dcm[8] = cosPhi * cosThe;
}

static void thread_entry(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_LC307_UPDATE;
    uint8_t c;

    /* open device */
    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY | RT_DEVICE_FLAG_INT_RX) != RT_EOK) {
        printf("lc307 fail to open device!\n");
        return;
    }

    /* init lc307 device */

    uint8_t retry_cnt = 0;
    while (1) {

        if (retry_cnt > 5) {
            printf("lc307 init failed! 5 times\n");
            return;
        }

        int32_t r = lc307_cmd_AA_AB();
        if (r != 0) {
            retry_cnt++;
            continue;
        }

        r = lc307_cmd_BB_DD();
        if (r != 0) {
            retry_cnt++;
            continue;
        }

        printf("lc307 init success retry_cnt = %d \n", retry_cnt);
        break;
    }

    McnNode_t imu_sub_node_t;
    McnNode_t ins_sub_node_t;
    McnNode_t rf_sub_node_t;

    imu_data_t imu_report;
    INS_Out_Bus INS_Out;
    rf_data_t rf_report;

    imu_sub_node_t = mcn_subscribe(MCN_HUB(sensor_imu0), NULL, NULL);
    ins_sub_node_t = mcn_subscribe(MCN_HUB(ins_output), NULL, NULL);
    rf_sub_node_t = mcn_subscribe(MCN_HUB(sensor_rangefinder), NULL, NULL);

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, 10, &recv_set);

        if ((res == RT_EOK && (recv_set & EVENT_LC307_UPDATE)) || res == -RT_ETIMEOUT) {
            while (rt_device_read(dev, 0, &c, 1) > 0) {
                if (parse_package(c) == true) {
                    uint32_t time_now = systime_now_ms();
                    optflow_report.timestamp_ms = time_now;

                    /* actual optical flow velocity = raw_vel * distance, we just publish raw data,
                           leave it to upper layer to handle it. */

                    /* get sensor data */
                    if (mcn_poll(imu_sub_node_t)) {
                        mcn_copy(MCN_HUB(sensor_imu0), imu_sub_node_t, &imu_report);
                    }

                    if (mcn_poll(ins_sub_node_t)) {
                        mcn_copy(MCN_HUB(ins_output), ins_sub_node_t, &INS_Out);
                    }

                    if (mcn_poll(rf_sub_node_t)) {
                        mcn_copy(MCN_HUB(sensor_rangefinder), rf_sub_node_t, &rf_report);
                    }

                    // check for sane pitch/roll
                    if (INS_Out.phi > 0.3f || INS_Out.theta > 0.3f) {
                        printf("sane is to big -- phi = %f  theta = %f \r\n", INS_Out.phi, INS_Out.theta);
                        continue;
                    }

                    if (rf_report.distance_m <= 0) {
                        printf("rf is zero dis =  %f  ts = %d \r\n", rf_report.distance_m, rf_report.timestamp_ms);
                        continue;
                    }

                    float d = rf_report.distance_m * cosf(INS_Out.phi) * cosf(INS_Out.theta); // 光流目标距离 单位米

                    float flow_gain_x = 1.0f;
                    float flow_gain_y = 1.0f;

                    float fx = data.flow_x_integral * flow_gain_x;
                    float fy = data.flow_y_integral * flow_gain_y;

                    float dT = (float)data.integration_timespan / 1000000; // us => s

                    optflow_report.vx_mPs = (d * fx / dT);
                    optflow_report.vy_mPs = (d * fy / dT);
                    optflow_report.quality = data.valid;

                    /* publish LC307 data */
                    mcn_publish(MCN_HUB(sensor_optflow), &optflow_report);
                }
            }
        }
    }
}

static struct WorkItem work_item = {
    .name = "lc307",
    .period = 0,
    .schedule_time = 1000,
    .run = start_thread
};

rt_err_t lc307_drv_init(const char* uart_dev_name)
{
    dev = rt_device_find(uart_dev_name);

    RT_ASSERT(dev != NULL);

    thread = rt_thread_create("lc307", thread_entry, RT_NULL, 4 * 1024, 7, 1);

    RT_ASSERT(thread != NULL);

    RT_CHECK(rt_event_init(&event, "lc307", RT_IPC_FLAG_FIFO));

    RT_CHECK(rt_device_set_rx_indicate(dev, rx_ind_cb));

    /* pospone start of thread */
    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");
    RT_ASSERT(lp_wq != NULL);
    FMT_CHECK(workqueue_schedule_work(lp_wq, &work_item));

    return RT_EOK;
}