#include <rtthread.h>
#include <rthw.h>
#include <stdint.h>

#ifndef ETHOSU_SEMAPHORE_WAIT_FOREVER
#define ETHOSU_SEMAPHORE_WAIT_FOREVER UINT64_MAX
#endif

#ifndef RT_USING_SEMAPHORE
#error "Ethos-U RT-Thread semaphore override requires RT_USING_SEMAPHORE"
#endif

static rt_uint32_t g_ethosu_ipc_index;

static void ethosu_make_name(const char *prefix, char *name, rt_size_t size)
{
    rt_base_t level;
    rt_uint32_t index;

    level = rt_hw_interrupt_disable();
    index = g_ethosu_ipc_index++;
    rt_hw_interrupt_enable(level);

    rt_snprintf(name, size, "%s%u", prefix, (unsigned int)(index % 1000U));
}

static rt_int32_t ethosu_timeout_to_ticks(uint64_t timeout)
{
    uint64_t ticks;

    if (timeout == ETHOSU_SEMAPHORE_WAIT_FOREVER) {
        return RT_WAITING_FOREVER;
    }

    if (timeout == 0U) {
        return RT_WAITING_NO;
    }

    ticks = (timeout * (uint64_t)RT_TICK_PER_SECOND + 999ULL) / 1000ULL;
    if (ticks == 0U) {
        ticks = 1U;
    }

    if (ticks > 0x7fffffffULL) {
        return RT_WAITING_FOREVER;
    }

    return (rt_int32_t)ticks;
}

void *ethosu_mutex_create(void)
{
    char name[RT_NAME_MAX];

    ethosu_make_name("emu", name, sizeof(name));
    return (void *)rt_mutex_create(name, RT_IPC_FLAG_PRIO);
}

void ethosu_mutex_destroy(void *mutex)
{
    if (mutex != RT_NULL) {
        (void)rt_mutex_delete((rt_mutex_t)mutex);
    }
}

int ethosu_mutex_lock(void *mutex)
{
    if (mutex == RT_NULL) {
        return -1;
    }

    return (rt_mutex_take((rt_mutex_t)mutex, RT_WAITING_FOREVER) == RT_EOK) ? 0 : -1;
}

int ethosu_mutex_unlock(void *mutex)
{
    if (mutex == RT_NULL) {
        return -1;
    }

    return (rt_mutex_release((rt_mutex_t)mutex) == RT_EOK) ? 0 : -1;
}

void *ethosu_semaphore_create(void)
{
    char name[RT_NAME_MAX];

    ethosu_make_name("ese", name, sizeof(name));
    return (void *)rt_sem_create(name, 0, RT_IPC_FLAG_PRIO);
}

void ethosu_semaphore_destroy(void *sem)
{
    if (sem != RT_NULL) {
        (void)rt_sem_delete((rt_sem_t)sem);
    }
}

int ethosu_semaphore_take(void *sem, uint64_t timeout)
{
    rt_int32_t wait_ticks;

    if (sem == RT_NULL) {
        return -1;
    }

    wait_ticks = ethosu_timeout_to_ticks(timeout);
    return (rt_sem_take((rt_sem_t)sem, wait_ticks) == RT_EOK) ? 0 : -1;
}

int ethosu_semaphore_give(void *sem)
{
    rt_err_t ret;

    if (sem == RT_NULL) {
        return -1;
    }

    ret = rt_sem_release((rt_sem_t)sem);
    if ((ret == RT_EOK) || (ret == -RT_EFULL)) {
        return 0;
    }

    return -1;
}
