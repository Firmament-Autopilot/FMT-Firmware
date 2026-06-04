/******************************************************************************
 * Copyright 2024 The Firmament Authors. All Rights Reserved.
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

#include <rtthread.h>
#include <rtdevice.h>
#include <string.h>
#include "hal/serial/serial.h"

#define TEST_UART_DEVICE_NAME    "serial6"
#define TEST_UART_THREAD_STACK   2048
#define TEST_UART_THREAD_PRIORITY  5
#define TEST_UART_THREAD_TIMESLICE 10

static struct rt_semaphore test_uart_rx_sem;

static rt_err_t test_uart_rx_ind(rt_device_t dev, rt_size_t size)
{
    rt_sem_release(&test_uart_rx_sem);
    return RT_EOK;
}

static void test_uart_rx_thread_entry(void* parameter)
{
    rt_device_t serial;
    struct serial_configure config = SERIAL_DEFAULT_CONFIG;
    rt_size_t read_length;
    rt_uint8_t rx_buf[64];

    serial = rt_device_find(TEST_UART_DEVICE_NAME);
    if (serial == RT_NULL) {
        rt_kprintf("[UART] 未找到设备: %s\n", TEST_UART_DEVICE_NAME);
        return;
    }

    rt_sem_init(&test_uart_rx_sem, "test_uart_rx", 0, RT_IPC_FLAG_FIFO);

    if (rt_device_open(serial, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX) != RT_EOK) {
        rt_kprintf("[UART1] 打开设备失败\n");
        return;
    }

    config.baud_rate = 57600;
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config);
    rt_device_set_rx_indicate(serial, test_uart_rx_ind);

    rt_kprintf("[UART] 初始化完成，等待接收数据...\n");

    while (1) {
        if (rt_sem_take(&test_uart_rx_sem, RT_TICK_PER_SECOND / 100) == RT_EOK) {
            while (1) {
                read_length = rt_device_read(serial, 0, rx_buf, sizeof(rx_buf));
                if (read_length == 0) {
                    break;
                }

                rt_kprintf("[UART] 接收到 %d 字节: ", read_length);
                for (rt_size_t i = 0; i < read_length; i++) {
                    rt_kprintf("%02X ", rx_buf[i]);
                }
                rt_kprintf("\n");
                rt_device_write(serial, 0, rx_buf, read_length);
            }
        }
    }
}

rt_err_t uart_test_init(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("test_uart_rx",
                          test_uart_rx_thread_entry,
                          RT_NULL,
                          TEST_UART_THREAD_STACK,
                          TEST_UART_THREAD_PRIORITY,
                          TEST_UART_THREAD_TIMESLICE);
    if (tid == RT_NULL) {
        rt_kprintf("[UART] 创建接收线程失败\n");
        return -RT_ERROR;
    }
    rt_thread_startup(tid);

    return RT_EOK;
}
MSH_CMD_EXPORT(uart_test_init, 初始化UART功能);