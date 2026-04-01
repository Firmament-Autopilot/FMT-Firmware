#include <rtdevice.h>
#include <rtthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_FILE_PATH   "/test_file.bin"
#define TEST_FILE_SIZE   (5 * 1024 * 1024)
#define BUFFER_SIZE      (4 * 1024)
#define WRITE_ITERATIONS 100
#define READ_ITERATIONS  100

static rt_uint8_t write_buffer[BUFFER_SIZE];
static rt_uint8_t read_buffer[BUFFER_SIZE];

static float g_write_speed_kb = 0.0f;
static float g_read_speed_kb = 0.0f;

static void print_speed(const char* name, float speed_kb)
{
    int kb_int = (int)speed_kb;
    int kb_frac = (int)((speed_kb - kb_int) * 100);
    if (kb_frac < 0)
        kb_frac = -kb_frac;
    rt_kprintf("%s: %d.%02d KB/s (%d.%02d MB/s)\n",
               name,
               kb_int,
               kb_frac,
               kb_int / 1024,
               (kb_int % 1024 * 100 + kb_frac) / 1024);
}

static void fill_buffer(rt_uint8_t* buffer, rt_size_t size)
{
    rt_size_t i;
    for (i = 0; i < size; i++) {
        buffer[i] = (rt_uint8_t)(i & 0xFF);
    }
}

static void test_write_performance(void)
{
    FILE* fp;
    rt_size_t bytes_written;
    rt_size_t total_written = 0;
    rt_tick_t start_time, end_time;
    rt_uint32_t elapsed_time;

    rt_kprintf("\n========== 文件系统写入性能测试 ==========\n");
    rt_kprintf("测试文件: %s\n", TEST_FILE_PATH);
    rt_kprintf("缓冲区大小: %d 字节\n", BUFFER_SIZE);
    rt_kprintf("测试数据量: %d 字节 (%d MB)\n", TEST_FILE_SIZE, TEST_FILE_SIZE / (1024 * 1024));

    rt_kprintf("正在创建测试文件...\n");
    fp = fopen(TEST_FILE_PATH, "wb");
    if (fp == RT_NULL) {
        rt_kprintf("错误: 无法创建测试文件\n");
        return;
    }
    rt_kprintf("测试文件创建成功!\n");

    rt_kprintf("正在准备测试数据...\n");
    fill_buffer(write_buffer, BUFFER_SIZE);
    rt_kprintf("测试数据准备完成!\n");

    rt_kprintf("开始写入测试...\n");
    start_time = rt_tick_get();

    while (total_written < TEST_FILE_SIZE) {
        rt_size_t write_size = (TEST_FILE_SIZE - total_written) > BUFFER_SIZE
            ? BUFFER_SIZE
            : (TEST_FILE_SIZE - total_written);

        bytes_written = fwrite(write_buffer, 1, write_size, fp);
        if (bytes_written != write_size) {
            rt_kprintf("错误: 写入失败 (期望 %d 字节, 实际 %d 字节)\n",
                       write_size,
                       bytes_written);
            fclose(fp);
            return;
        }

        total_written += bytes_written;

        if ((total_written % (512 * 1024)) == 0) {
            rt_kprintf("进度: %d / %d 字节 (%d%%)\r",
                       total_written,
                       TEST_FILE_SIZE,
                       total_written * 100 / TEST_FILE_SIZE);
        }
    }
    rt_kprintf("\n");

    end_time = rt_tick_get();
    elapsed_time = end_time - start_time;
    fclose(fp);

    if (elapsed_time > 0) {
        g_write_speed_kb = (float)TEST_FILE_SIZE / elapsed_time * RT_TICK_PER_SECOND / 1024.0f;
        rt_kprintf("写入完成! 耗时: %d ticks (%d 秒)\n",
                   elapsed_time,
                   elapsed_time / RT_TICK_PER_SECOND);
        print_speed("写入速度", g_write_speed_kb);
        rt_kprintf("\n");
    } else {
        rt_kprintf("写入完成! 耗时: 0 ticks (速度过快无法测量)\n\n");
    }
}

static void test_read_performance(void)
{
    FILE* fp;
    rt_size_t bytes_read;
    rt_size_t total_read = 0;
    rt_tick_t start_time, end_time;
    rt_uint32_t elapsed_time;

    rt_kprintf("========== 文件系统读取性能测试 ==========\n");
    rt_kprintf("测试文件: %s\n", TEST_FILE_PATH);

    fp = fopen(TEST_FILE_PATH, "rb");
    if (fp == RT_NULL) {
        rt_kprintf("错误: 无法打开测试文件\n");
        return;
    }

    rt_kprintf("开始读取测试...\n");
    start_time = rt_tick_get();

    while (total_read < TEST_FILE_SIZE) {
        rt_size_t read_size = (TEST_FILE_SIZE - total_read) > BUFFER_SIZE
            ? BUFFER_SIZE
            : (TEST_FILE_SIZE - total_read);

        bytes_read = fread(read_buffer, 1, read_size, fp);
        if (bytes_read != read_size) {
            rt_kprintf("错误: 读取失败 (期望 %d 字节, 实际 %d 字节)\n",
                       read_size,
                       bytes_read);
            fclose(fp);
            return;
        }

        total_read += bytes_read;

        if ((total_read % (512 * 1024)) == 0) {
            rt_kprintf("进度: %d / %d 字节 (%d%%)\r",
                       total_read,
                       TEST_FILE_SIZE,
                       total_read * 100 / TEST_FILE_SIZE);
        }
    }
    rt_kprintf("\n");

    end_time = rt_tick_get();
    elapsed_time = end_time - start_time;
    fclose(fp);

    if (elapsed_time > 0) {
        g_read_speed_kb = (float)TEST_FILE_SIZE / elapsed_time * RT_TICK_PER_SECOND / 1024.0f;
        rt_kprintf("读取完成! 耗时: %d ticks (%d 秒)\n",
                   elapsed_time,
                   elapsed_time / RT_TICK_PER_SECOND);
        print_speed("读取速度", g_read_speed_kb);
        rt_kprintf("\n");
    } else {
        rt_kprintf("读取完成! 耗时: 0 ticks (速度过快无法测量)\n\n");
    }
}

static void test_data_integrity(void)
{
    FILE* fp;
    rt_size_t bytes_read;
    rt_size_t total_read = 0;
    rt_size_t errors = 0;
    rt_bool_t verify_ok = RT_TRUE;

    rt_kprintf("========== 数据完整性测试 ==========\n");
    rt_kprintf("验证写入的数据是否正确...\n");

    fp = fopen(TEST_FILE_PATH, "rb");
    if (fp == RT_NULL) {
        rt_kprintf("错误: 无法打开测试文件\n");
        return;
    }

    while (total_read < TEST_FILE_SIZE) {
        rt_size_t read_size = (TEST_FILE_SIZE - total_read) > BUFFER_SIZE
            ? BUFFER_SIZE
            : (TEST_FILE_SIZE - total_read);

        bytes_read = fread(read_buffer, 1, read_size, fp);
        if (bytes_read != read_size) {
            rt_kprintf("错误: 读取失败\n");
            verify_ok = RT_FALSE;
            break;
        }

        for (bytes_read = 0; bytes_read < read_size; bytes_read++) {
            if (read_buffer[bytes_read] != (rt_uint8_t)((total_read + bytes_read) & 0xFF)) {
                errors++;
                if (errors > 10) {
                    rt_kprintf("错误太多，停止验证...\n");
                    verify_ok = RT_FALSE;
                    break;
                }
            }
        }

        total_read += read_size;

        if ((total_read % (1024 * 1024)) == 0) {
            rt_kprintf("验证进度: %d / %d 字节 (%d%%)\r",
                       total_read,
                       TEST_FILE_SIZE,
                       total_read * 100 / TEST_FILE_SIZE);
        }
    }
    rt_kprintf("\n");

    fclose(fp);

    if (verify_ok && errors == 0) {
        rt_kprintf("数据完整性测试通过! 所有数据正确\n\n");
    } else {
        rt_kprintf("数据完整性测试失败! 发现 %d 个错误\n\n", errors);
    }
}

static void test_random_io(void)
{
    FILE* fp;
    rt_tick_t start_time, end_time;
    rt_uint32_t elapsed_time;
    rt_size_t i, pos;
    const rt_size_t random_ops = 200;

    rt_kprintf("========== 随机读写性能测试 ==========\n");
    rt_kprintf("随机操作次数: %d\n", random_ops);

    fp = fopen(TEST_FILE_PATH, "r+b");
    if (fp == RT_NULL) {
        rt_kprintf("错误: 无法打开测试文件\n");
        return;
    }

    fill_buffer(write_buffer, BUFFER_SIZE);
    start_time = rt_tick_get();

    for (i = 0; i < random_ops; i++) {
        pos = (rt_size_t)rt_tick_get() % (TEST_FILE_SIZE - BUFFER_SIZE);
        fseek(fp, pos, SEEK_SET);

        fwrite(write_buffer, 1, BUFFER_SIZE, fp);
        fflush(fp);

        fseek(fp, pos, SEEK_SET);
        fread(read_buffer, 1, BUFFER_SIZE, fp);

        if ((i + 1) % 50 == 0) {
            rt_kprintf("进度: %d / %d 次操作\r", i + 1, random_ops);
        }
    }
    rt_kprintf("\n");

    end_time = rt_tick_get();
    elapsed_time = end_time - start_time;
    fclose(fp);

    if (elapsed_time > 0) {
        rt_kprintf("随机读写完成! 耗时: %d ticks (%d 秒)\n",
                   elapsed_time,
                   elapsed_time / RT_TICK_PER_SECOND);
        rt_kprintf("平均每次操作: %d ms\n\n",
                   elapsed_time / RT_TICK_PER_SECOND * 1000 / random_ops);
    } else {
        rt_kprintf("随机读写完成! 耗时: 0 ticks\n\n");
    }
}

static void fs_benchmark(int argc, char** argv)
{
    rt_kprintf("\n");
    rt_kprintf("**********************************************\n");
    rt_kprintf("*         文件系统性能基准测试               *\n");
    rt_kprintf("**********************************************\n");

    test_write_performance();
    test_read_performance();
    test_data_integrity();
    test_random_io();

    rt_kprintf("**********************************************\n");
    rt_kprintf("*            测试结果汇总                     *\n");
    rt_kprintf("**********************************************\n");
    print_speed("写入速度", g_write_speed_kb);
    print_speed("读取速度", g_read_speed_kb);
    rt_kprintf("**********************************************\n");
    rt_kprintf("*            测试完成!                       *\n");
    rt_kprintf("**********************************************\n\n");

    remove(TEST_FILE_PATH);
    rt_kprintf("测试文件已删除\n");
}
MSH_CMD_EXPORT(fs_benchmark, 文件系统性能基准测试);
