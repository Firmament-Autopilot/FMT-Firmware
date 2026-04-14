#include <rtthread.h>
#include <rtdevice.h>
#include "hal/serial/serial.h"

#define UART5_NAME           "serial5"
#define RX_BUF_SIZE          256
#define RX_TIMEOUT           20

static rt_device_t uart5_dev = RT_NULL;
static rt_uint8_t rx_buffer[RX_BUF_SIZE];
static struct rt_semaphore rx_sem;

/* 接收回调函数 - 当收到数据时被调用 */
static rt_err_t uart5_rx_ind(rt_device_t dev, rt_size_t size)
{
    if (size > 0)
    {
        rt_sem_release(&rx_sem);
    }
    return RT_EOK;
}

/* 中断模式接收线程 */
static void uart5_rx_thread(void *parameter)
{
    rt_err_t ret;
    rt_size_t read_len;

    rt_kprintf("\n========================================\n");
    rt_kprintf("  串口5中断接收测试\n");
    rt_kprintf("  设备: %s\n", UART5_NAME);
    rt_kprintf("========================================\n\n");

    /* 查找串口设备 */
    uart5_dev = rt_device_find(UART5_NAME);
    if (uart5_dev == RT_NULL)
    {
        rt_kprintf("[错误] 找不到设备: %s\n", UART5_NAME);
        return;
    }
    rt_kprintf("[OK] 找到设备: %s\n", UART5_NAME);

    /* 初始化信号量 */
    ret = rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);
    if (ret != RT_EOK)
    {
        rt_kprintf("[错误] 信号量初始化失败\n");
        return;
    }

    /* 打开串口设备 - 参考 console.c 的方式 */
    /* 使用 RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX 标志 */
    ret = rt_device_open(uart5_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
    if (ret != RT_EOK)
    {
        rt_kprintf("[错误] 打开设备失败: %d\n", ret);
        return;
    }
    rt_kprintf("[OK] 设备已打开 (中断接收模式)\n");

    /* 设置接收回调函数 - 必须在打开后设置 */
    rt_device_set_rx_indicate(uart5_dev, uart5_rx_ind);
    rt_kprintf("[OK] 接收回调已设置\n");
    rt_kprintf("[调试] 请检查：\n");
    rt_kprintf("       1. 硬件TX/RX是否正确连接\n");
    rt_kprintf("       2. 发送端波特率是否为 57600\n");
    rt_kprintf("       3. GPIO引脚配置: P17.0(RX), P17.1(TX)\n\n");
    rt_kprintf("[等待] 等待接收数据...\n\n");

    /* 接收循环 */
    while (1)
    {
        /* 等待接收信号量 */
        ret = rt_sem_take(&rx_sem, RX_TIMEOUT);
        if (ret == -RT_ETIMEOUT)
        {
            /* 超时，继续等待 */
            continue;
        }
        else if (ret != RT_EOK)
        {
            rt_kprintf("[错误] 信号量获取失败: %d\n", ret);
            break;
        }

        /* 读取接收到的数据 */
        rt_memset(rx_buffer, 0, RX_BUF_SIZE);
        read_len = rt_device_read(uart5_dev, 0, rx_buffer, RX_BUF_SIZE - 1);

        if (read_len > 0)
        {
            rt_kprintf("[RX] 接收 %d 字节: ", read_len);

            /* 以十六进制格式打印 */
            for (rt_size_t i = 0; i < read_len; i++)
            {
                rt_kprintf("%02X ", rx_buffer[i]);
            }
            rt_kprintf("\n");

            /* 如果是可打印字符，也以ASCII格式显示 */
            rt_bool_t printable = RT_TRUE;
            for (rt_size_t i = 0; i < read_len; i++)
            {
                if (rx_buffer[i] < 32 || rx_buffer[i] > 126)
                {
                    if (rx_buffer[i] != '\r' && rx_buffer[i] != '\n')
                    {
                        printable = RT_FALSE;
                        break;
                    }
                }
            }

            if (printable)
            {
                rt_kprintf("[RX] ASCII: %s\n", rx_buffer);
            }
            rt_kprintf("\n");
        }
    }

    rt_kprintf("[退出] 接收线程结束\n");

    /* 清理资源 */
    rt_device_close(uart5_dev);
    rt_sem_detach(&rx_sem);
}

/* 启动串口5中断接收测试 */
static void uart5_rx_test(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("uart5_rx",
                           uart5_rx_thread,
                           RT_NULL,
                           2048,
                           20,
                           10);
    if (tid != RT_NULL)
    {
        rt_thread_startup(tid);
    }
    else
    {
        rt_kprintf("[错误] 创建接收线程失败\n");
    }
}
MSH_CMD_EXPORT(uart5_rx_test, 串口5中断接收数据测试);
