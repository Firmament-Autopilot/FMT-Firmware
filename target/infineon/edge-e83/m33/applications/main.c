#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define LED_PIN_B                 GET_PIN(16, 5)

int main(void)
{
    rt_kprintf("Hello RT-Thread\r\n");
    rt_kprintf("This core is cortex-m33\n");
    rt_pin_mode(LED_PIN_B, PIN_MODE_OUTPUT);
    while (1)
    {
        rt_pin_write(LED_PIN_B, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN_B, PIN_LOW);
        rt_thread_mdelay(500);
    }
    return 0;
}
