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


int cmd_run_init(void)
{
    char cmd[512];
    console_println("start run /init.sh\n");
    int  fd = open("/init.sh", O_RDONLY, 0);
    if (fd >= 0)
    {
        int size = read(fd,cmd,sizeof(cmd));
        close(fd);
        if(size > 0)
        {
            console_println("run init.sh ...\n");
            msh_exec(cmd, size);
        }
        else
        {
            console_println("read /init.sh error!\n");
        }
    }
    else
    {
        console_println("open /init.sh error!\n");
    }
    sys_msleep(10);
    return 0;
}


INIT_APP_EXPORT(cmd_run_init);
FINSH_FUNCTION_EXPORT_ALIAS(cmd_run_init, __cmd_run_init, run init.sh);



