#include "USB.h"
#include <rtthread.h>

U32 USB_OS_GetTickCnt(void)
{
    return (U32)rt_tick_get_millisecond();
}
