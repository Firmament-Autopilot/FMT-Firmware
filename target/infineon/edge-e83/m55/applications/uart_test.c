#include <rtthread.h>
#include <rtdevice.h>
#include "hal/serial/serial.h"

#define TEST_UART_NAME      "serial1"
#define TEST_BAUD_RATE      57600
#define TEST_TX_TIMEOUT     1000

#define TEST_CASE_BASIC     (1 << 0)
#define TEST_CASE_LARGE     (1 << 1)
#define TEST_CASE_BAUD_SW   (1 << 2)
#define TEST_CASES          (TEST_CASE_BASIC | TEST_CASE_LARGE | TEST_CASE_BAUD_SW)

static rt_device_t  uart_dev   = RT_NULL;
static rt_bool_t    dma_mode   = RT_FALSE;

static rt_bool_t uart_set_baud(rt_uint32_t baud)
{
    struct serial_configure cfg = SERIAL_DEFAULT_CONFIG;
    rt_err_t ret;

    cfg.baud_rate = baud;
    ret = rt_device_control(uart_dev, RT_DEVICE_CTRL_CONFIG, &cfg);

    if (ret == RT_EOK) {
        rt_kprintf("[CFG] 波特率切换成功: %d\n", baud);
        return RT_TRUE;
    }

    rt_kprintf("[CFG] 波特率切换失败: %d, ret=%d\n", baud, ret);
    return RT_FALSE;
}

static rt_bool_t uart_test_send(const char *desc, const rt_uint8_t *data, rt_size_t len)
{
    rt_size_t written;

    rt_kprintf("\n[TEST] %s\n", desc);
    rt_kprintf("[TX]  发送 %d 字节: ", len);

    for (rt_size_t i = 0; i < len && i < 16; i++) {
        rt_kprintf("%02X ", data[i]);
    }
    if (len > 16) rt_kprintf("...");
    rt_kprintf("\n");

    written = rt_device_write(uart_dev, TEST_TX_TIMEOUT, data, len);

    if (written == len) {
        rt_kprintf("[TX]  发送成功，实际写入 %d 字节\n", written);
        return RT_TRUE;
    } else {
        rt_kprintf("[TX]  发送失败！期望 %d 字节，实际 %d 字节\n", len, written);
        return RT_FALSE;
    }
}

static void test_case_basic(void)
{
    const char *msg = "Hello, DMA UART!\r\n";
    uart_test_send("基础 DMA 发送", (const rt_uint8_t *)msg, rt_strlen(msg));
    rt_thread_mdelay(100);
}

static void test_case_large(void)
{
#define LARGE_SIZE 64
    static rt_uint8_t large_buf[LARGE_SIZE];

    for (int i = 0; i < LARGE_SIZE; i++) {
        large_buf[i] = (rt_uint8_t)(i & 0xFF);
    }

    uart_test_send("大数据量 DMA 发送", large_buf, LARGE_SIZE);
    rt_thread_mdelay(200);
#undef LARGE_SIZE
}

static void test_case_baud_switch(void)
{
    static const rt_uint32_t baud_list[] = { 115200, 57600, 38400, 230400 };
    char msg[80];

    rt_kprintf("\n[TEST] 动态修改波特率测试\n");

    for (rt_size_t i = 0; i < sizeof(baud_list) / sizeof(baud_list[0]); i++) {
        if (!uart_set_baud(baud_list[i])) {
            continue;
        }

        rt_snprintf(msg,
                    sizeof(msg),
                    "UART baud switch test: %d bps\r\n",
                    baud_list[i]);

        uart_test_send("波特率切换后发送", (const rt_uint8_t*)msg, rt_strlen(msg));
        rt_thread_mdelay(150);
    }

    /* 恢复默认值，避免影响后续测试或控制台使用。 */
    uart_set_baud(TEST_BAUD_RATE);
}

static void uart_dma_test_thread(void *param)
{
    rt_kprintf("\n========================================\n");
    rt_kprintf("  DMA UART 测试开始 [%s]\n", TEST_UART_NAME);
    rt_kprintf("========================================\n");

    uart_dev = rt_device_find(TEST_UART_NAME);
    if (uart_dev == RT_NULL) {
        rt_kprintf("[ERR] 找不到设备: %s\n", TEST_UART_NAME);
        return;
    }
    dma_mode = RT_FALSE;
    rt_kprintf("[OK]  找到设备: %s\n", TEST_UART_NAME);

    rt_err_t ret = rt_device_open(uart_dev,
                                  RT_DEVICE_FLAG_RDWR |
                                      RT_DEVICE_FLAG_DMA_TX);
    if (ret != RT_EOK) {
        rt_kprintf("[WARN] DMA 模式打开失败(%d)，回退普通模式\n", ret);
        ret = rt_device_open(uart_dev, RT_DEVICE_FLAG_RDWR);
        if (ret != RT_EOK) {
            rt_kprintf("[ERR] 打开设备失败: %d\n", ret);
            return;
        }
    } else {
        dma_mode = RT_TRUE;
    }
    rt_kprintf("[OK]  设备已打开 (%s)\n", dma_mode ? "DMA_TX" : "POLLING");

    if (!uart_set_baud(TEST_BAUD_RATE)) {
        rt_device_close(uart_dev);
        return;
    }

    rt_thread_mdelay(100);

    if (TEST_CASES & TEST_CASE_BASIC) {
        test_case_basic();
    }

    if (TEST_CASES & TEST_CASE_LARGE) {
        test_case_large();
    }

    if (TEST_CASES & TEST_CASE_BAUD_SW) {
        test_case_baud_switch();
    }

    rt_kprintf("\n========================================\n");
    rt_kprintf("  DMA UART 测试结束\n");
    rt_kprintf("========================================\n");

    rt_device_close(uart_dev);
}

static void uart_dma_test(void)
{
    rt_thread_t tid = rt_thread_create("uart_test",
                                       uart_dma_test_thread,
                                       RT_NULL,
                                       4096,
                                       15,
                                       20);
    if (tid != RT_NULL) {
        rt_thread_startup(tid);
    } else {
        rt_kprintf("[ERR] 创建测试线程失败\n");
    }
}
MSH_CMD_EXPORT(uart_dma_test, DMA UART test);
