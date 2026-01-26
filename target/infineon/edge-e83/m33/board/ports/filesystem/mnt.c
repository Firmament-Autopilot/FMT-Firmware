#include <rtthread.h>

#ifdef RT_USING_DFS
#include <dfs_fs.h>
#ifdef BSP_USING_FLASH
#include <fal.h>
#endif
#include <drivers/mmcsd_core.h>
#include "dfs_romfs.h"

#define DBG_TAG "app.filesystem"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>
#ifndef BSP_USING_XiaoZhi
static const struct romfs_dirent _romfs_root[] =
{
#ifdef BSP_USING_FLASH
    {ROMFS_DIRENT_DIR, "flash", RT_NULL, 0},
#endif
#ifdef BSP_USING_SDCARD
    {ROMFS_DIRENT_DIR, "sdcard", RT_NULL, 0},
#endif
};

const struct romfs_dirent romfs_root =
{
    ROMFS_DIRENT_DIR, "/", (rt_uint8_t *)_romfs_root, sizeof(_romfs_root) / sizeof(_romfs_root[0])
};
#endif

static void _sdcard_mount(void)
{
#ifdef BSP_USING_SDCARD
    rt_device_t device;
    const char *sd_device_names[] = {"sd", "sd0", "sd1", "sd2"};
    int i;
    const char *device_name = RT_NULL;

    /* Try to find SD card device */
    for (i = 0; i < sizeof(sd_device_names) / sizeof(sd_device_names[0]); i++)
    {
        device = rt_device_find(sd_device_names[i]);
        if (device != RT_NULL)
        {
            device_name = sd_device_names[i];
            LOG_I("Found sd card device '%s'", device_name);
            break;
        }
    }

    if (device == RT_NULL)
    {
        /* Clear previous CD status and wait for SD card initialization */
        mmcsd_wait_cd_changed(0);
        /* Wait for SD card detection, timeout 5 seconds */
        if (mmcsd_wait_cd_changed(rt_tick_from_millisecond(5000)) == -RT_ETIMEOUT)
        {
            LOG_W("Wait for SD card timeout!");
            return;
        }

        /* Try again to find SD card device */
        for (i = 0; i < sizeof(sd_device_names) / sizeof(sd_device_names[0]); i++)
        {
            device = rt_device_find(sd_device_names[i]);
            if (device != RT_NULL)
            {
                device_name = sd_device_names[i];
                LOG_I("Found sd card device '%s'", device_name);
                break;
            }
        }
    }

    if (device == RT_NULL || device_name == RT_NULL)
    {
        LOG_W("sd card device not found!");
        return;
    }

    rt_thread_mdelay(200);

    /* Try to mount */
    if (dfs_mount(device_name, "/sdcard", "elm", 0, 0) == RT_EOK)
    {
        LOG_I("sd card mount to '/sdcard' success!");
        return;
    }

    /* Mount failed, try to format */
    LOG_W("sd card mount to '/sdcard' failed, try to mkfs...");
    if (dfs_mkfs("elm", device_name) == 0)
    {
        LOG_I("sd card mkfs success!");

        /* Try to mount again after formatting */
        if (dfs_mount(device_name, "/sdcard", "elm", 0, 0) == RT_EOK)
        {
            LOG_I("sd card mount to '/sdcard' success!");
        }
        else
        {
            LOG_E("sd card mount to '/sdcard' failed after mkfs!");
        }
    }
    else
    {
        LOG_E("sd card mkfs failed!");
    }
#endif /* BSP_USING_SDCARD */
}

#ifdef BSP_USING_FLASH
static void _fal_mount(void)
{
    struct rt_device *flash_dev = fal_mtd_nor_device_create("filesystem");
    if (flash_dev == NULL)
    {
        LOG_E("Can't create block device for filesystem");
        return;
    }
    else
    {
        LOG_I("Block device created for filesystem");

        /* Try to mount filesystem */
        if (dfs_mount("filesystem", "/flash", "lfs", 0, 0) != 0)
        {
            LOG_W("Mount filesystem failed, try to mkfs");

            /* Format filesystem */
            if (dfs_mkfs("lfs", "filesystem") != 0)
            {
                LOG_E("mkfs failed");
                return;
            }
            else
            {
                LOG_I("Filesystem formatted");

                /* Mount after format */
                if (dfs_mount("filesystem", "/flash", "lfs", 0, 0) != 0)
                {
                    LOG_E("Mount filesystem failed after mkfs");
                    return;
                }
                else
                {
                    LOG_I("Filesystem mounted successfully");
                }
            }
        }
        else
        {
            LOG_I("Filesystem mounted successfully");
        }
    }
}
#endif /* BSP_USING_FLASH */

static void sd_mount_thread(void *parameter)
{
    rt_thread_mdelay(200);
    _sdcard_mount();
}

int mnt_init(void)
{
    if (dfs_mount(RT_NULL, "/", "rom", 0, &(romfs_root)) != 0)
    {
        LOG_E("rom mount to '/' failed!");
        return -RT_ERROR;
    }

#ifdef BSP_USING_FLASH
    fal_init();
    /* Mount FAL filesystem to /flash */
    _fal_mount();
#endif

#ifdef BSP_USING_SDCARD
    rt_thread_t tid;

    /* Try SD card mount to /sdcard in a separate thread */
    tid = rt_thread_create("sd_mount", sd_mount_thread, RT_NULL,
                           2048, RT_THREAD_PRIORITY_MAX - 2, 20);
    if (tid != RT_NULL)
    {
        rt_thread_startup(tid);
    }
    else
    {
        LOG_E("create sd_mount thread err!");
    }
#endif

    return RT_EOK;
}
INIT_ENV_EXPORT(mnt_init);

#endif
