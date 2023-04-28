
#include <rtthread.h>


#ifdef RT_USING_DFS
#include <dfs_fs.h>
#include "dfs_romfs.h"

int mnt_init(void)
{
//  检测data目录是否存在，否则创建文件夹
    if(  access("/rom",0)!=0)
    {
        mkdir("/rom",0);
    }


    if (dfs_mount(RT_NULL, "/rom", "rom", 0, &(romfs_root)) == 0)
    {
        rt_kprintf("ROM file system initializated!\n");
    }
    else
    {
        rt_kprintf("ROM file system initializate failed!\n");
    }

    return 0;
}
// INIT_ENV_EXPORT(mnt_init);
// INIT_APP_EXPORT(mnt_init);
#endif
