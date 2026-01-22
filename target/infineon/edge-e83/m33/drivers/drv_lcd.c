/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-01-06     yuanjie      first version
 */

#include <rtthread.h>
#include <board.h>

#ifdef BSP_USING_LCD

#include <rtdevice.h>
#include "cy_graphics.h"
#include <display_tl043wvv02.h>
#include <board.h>
#include "vg_lite.h"
#include "vg_lite_platform.h"
#ifdef PKG_USING_CPU_USAGE
    #include <cpu_usage.h>
#endif
#ifdef BSP_USING_LVGL
    #include "lv_port_disp.h"
#endif

#define DRV_DEBUG
#define LOG_TAG             "drv.lcd"
#include <drv_log.h>

/* 10.1" display pin configuration */
#define DISPLAY_RESET_PORT                  GPIO_PRT20
#define DISPLAY_RESET_PIN                   (7U)

#define LCD_WIDTH           512
#define LCD_HEIGHT          800
#define LCD_BITS_PER_PIXEL  16
#define LCD_BUF_SIZE        (LCD_WIDTH * LCD_HEIGHT * LCD_BITS_PER_PIXEL / 8)
#define LCD_PIXEL_FORMAT    RTGRAPHIC_PIXEL_FORMAT_RGB565
#define LCD_DEVICE(dev)     (struct drv_lcd_device*)(dev)
#define RESET_VAL                           0U
#define GPU_TESSELLATION_BUFFER_SIZE        ((LCD_WIDTH) * 128U)
#define APP_BUFFER_COUNT                    (2U)
#define DEFAULT_GPU_CMD_BUFFER_SIZE         ((64U) * (512))
#define VG_PARAMS_POS                       (0UL)
#define GPU_MEM_BASE                        (0x0U)
#define VGLITE_HEAP_SIZE        (((DEFAULT_GPU_CMD_BUFFER_SIZE) * \
                                 (APP_BUFFER_COUNT)) + \
                                 ((GPU_TESSELLATION_BUFFER_SIZE) * \
                                 (APP_BUFFER_COUNT)))
CY_SECTION(".cy_gpu_buf") uint8_t contiguous_mem[VGLITE_HEAP_SIZE] = { 0xFF };
volatile void *vglite_heap_base = &contiguous_mem;

struct drv_lcd_device _lcd;

GFXSS_Type *gfxbase = (GFXSS_Type*) GFXSS;
static cy_stc_gfx_context_t lcd_gfx_context;

CY_SECTION(".cy_gpu_buf")uint8_t graphics_buffer[LCD_BUF_SIZE] = {0xFF};

struct drv_lcd_device
{
    struct rt_device parent;

    struct rt_device_graphic_info lcd_info;

    struct rt_semaphore lcd_lock;

    /* 0:front_buf is being used 1: back_buf is being used*/
    rt_uint8_t cur_buf;
    rt_uint8_t *front_buf;
    rt_uint8_t *back_buf;
};

static rt_err_t drv_lcd_init(struct rt_device *device)
{
    struct drv_lcd_device *lcd = LCD_DEVICE(device);
    /* nothing, right now */
    lcd = lcd;
    return RT_EOK;
}

static rt_err_t drv_lcd_control(struct rt_device *device, int cmd, void *args)
{
    struct drv_lcd_device *lcd = LCD_DEVICE(device);
    volatile cy_en_gfx_status_t status;
    switch (cmd)
    {
    case RTGRAPHIC_CTRL_RECT_UPDATE:
    {
        /* update */
        /* Set the frame buffer with the image pointer to be displayed on LCD */
        status = Cy_GFXSS_Set_FrameBuffer(gfxbase, (uint32_t*)graphics_buffer, &lcd_gfx_context);

        /* Image rendering failed. Stop program execution */
        if (CY_GFX_SUCCESS != status)
        {
            LOG_E("[%s: %d] Image rendering failed. Error type: %u\r\n", __func__, __LINE__, status);
            CY_ASSERT(0);
        }
        rt_sem_take(&_lcd.lcd_lock, RT_TICK_PER_SECOND / 20);
    }
    break;

    case RTGRAPHIC_CTRL_GET_INFO:
    {
        struct rt_device_graphic_info *info = (struct rt_device_graphic_info *)args;

        RT_ASSERT(info != RT_NULL);
        info->pixel_format  = lcd->lcd_info.pixel_format;
        info->bits_per_pixel = 16;
        info->width         = lcd->lcd_info.width;
        info->height        = lcd->lcd_info.height;
        info->framebuffer   = lcd->lcd_info.framebuffer;
    }
    break;
    }

    return RT_EOK;
}

cy_stc_sysint_t dc_irq_cfg =
{
    .intrSrc = GFXSS_DC_IRQ,
    .intrPriority = 3U //DC_INT_PRIORITY
};
cy_stc_sysint_t gpu_irq_cfg =
{
    .intrSrc      = GFXSS_GPU_IRQ,
    .intrPriority = 3U //GPU_INT_PRIORITY
};

#ifdef PKG_USING_CPU_USAGE
uint32_t calculate_idle_percentage(void)
{

    uint32_t load;
    cpu_usage_init();
    load = cpu_load_average();

    return 100 - load;
}
#endif

static void dc_irq_handler(void)
{
    rt_interrupt_enter();
    Cy_GFXSS_Clear_DC_Interrupt(gfxbase, &lcd_gfx_context);
    rt_interrupt_leave();
}

static void gpu_irq_handler(void)
{
    rt_interrupt_enter();
    Cy_GFXSS_Clear_GPU_Interrupt(gfxbase, &lcd_gfx_context);
    vg_lite_IRQHandler();
    rt_interrupt_leave();
}

rt_err_t psoc_lcd_init(struct drv_lcd_device *lcd)
{
    /* 10.1" display pin configuration */
    mtb_display_tl043wvv02_pin_config_t tl043wvv02_pin_cfg =
    {
        .reset_port = DISPLAY_RESET_PORT,
        .reset_pin  = DISPLAY_RESET_PIN,
    };

    static cy_en_gfx_status_t gfx_status;
    static cy_en_sysint_status_t status;
    volatile cy_en_mipidsi_status_t mipi_status;

    /* Graphics subsystem initialization failed. Stop program execution */
    gfx_status = Cy_GFXSS_Init(gfxbase, &GFXSS_config, &lcd_gfx_context);
    if (CY_GFX_SUCCESS != gfx_status)
    {
        LOG_E("[%s: %d] Gfxss initialization failed. Error type: %u\r\n", __func__, __LINE__, status);
        return -RT_ERROR;
    }

    /* Initialize GFXXs DC interrupt */
    status = Cy_SysInt_Init(&dc_irq_cfg, dc_irq_handler);
    if (CY_SYSINT_SUCCESS != status)
    {
        LOG_E("Error in registering DC interrupt: %d\r\n", status);
        return -RT_ERROR;
    }

    /* Enable interrupt in NVIC. */
    NVIC_EnableIRQ(GFXSS_DC_IRQ);

    status = Cy_SysInt_Init(&gpu_irq_cfg, gpu_irq_handler);
    if (CY_SYSINT_SUCCESS != status)
    {
        LOG_E("Error in registering GPU interrupt: %d\r\n", status);
        CY_ASSERT(0);
    }

    /* Enable GPU interrupt */
    Cy_GFXSS_Enable_GPU_Interrupt(GFXSS);

    /* Enable GFX GPU interrupt in NVIC. */
    NVIC_EnableIRQ(GFXSS_GPU_IRQ);

    mipi_status = mtb_display_tl043wvv02_init(GFXSS_GFXSS_MIPIDSI, &tl043wvv02_pin_cfg);

    /* Display initialization failed. Stop program execution */
    if (CY_MIPIDSI_SUCCESS != mipi_status)
    {
        LOG_E("[%s: %d] Display initialization failed. Error type: %u\r\n", __func__, __LINE__, status);
        return -RT_ERROR;
    }
    LOG_I("init screen success");
    return RT_EOK;
}

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops lcd_ops =
{
    drv_lcd_init,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    drv_lcd_control
};
#endif

int drv_lcd_hw_init(void)
{
    rt_free(_lcd.lcd_info.framebuffer);
    rt_err_t result = RT_EOK;
    struct rt_device *device = &_lcd.parent;

    /* memset _lcd to zero */
    memset(&_lcd, 0x00, sizeof(_lcd));

    /* init lcd_lock semaphore */
    result = rt_sem_init(&_lcd.lcd_lock, "lcd_lock", 0, RT_IPC_FLAG_FIFO);
    if (result != RT_EOK)
    {
        LOG_E("init semaphore failed!\n");
        result = -RT_ENOMEM;
        goto __exit;
    }

    /* config LCD dev info */
    _lcd.lcd_info.height = LCD_HEIGHT;
    _lcd.lcd_info.width = LCD_WIDTH;
    _lcd.lcd_info.bits_per_pixel = LCD_BITS_PER_PIXEL;
    _lcd.lcd_info.pixel_format = LCD_PIXEL_FORMAT;

    /* malloc memory for Triple Buffering */
    // _lcd.front_buf=_lcd.lcd_info.framebuffer = rt_malloc_align(LCD_BUF_SIZE, 32);
    _lcd.front_buf = _lcd.lcd_info.framebuffer = graphics_buffer;


    if (_lcd.lcd_info.framebuffer == RT_NULL)
    {
        LOG_E("init frame buffer failed!\n");
        result = -RT_ENOMEM;
        goto __exit;
    }
    /* memset buff to 0xFF */
    memset(_lcd.lcd_info.framebuffer, 0xFF, LCD_BUF_SIZE);
    device->type    = RT_Device_Class_Graphic;
#ifdef RT_USING_DEVICE_OPS
    device->ops     = &lcd_ops;
#else
    device->init    = drv_lcd_init;
#ifndef ART_PI_TouchGFX_LIB
    device->control = drv_lcd_control;
#endif
#endif

    /* register lcd device */
    rt_device_register(device, "lcd", RT_DEVICE_FLAG_RDWR);
    /* init mipi display */
    if (psoc_lcd_init(&_lcd) != RT_EOK)
    {
        result = -RT_ERROR;
        goto __exit;
    }
__exit:
    if (result != RT_EOK)
    {
        rt_sem_delete(&_lcd.lcd_lock);

        if (_lcd.lcd_info.framebuffer)
        {
            rt_free(_lcd.lcd_info.framebuffer);
        }

        if (_lcd.back_buf)
        {
            rt_free(_lcd.back_buf);
        }

        if (_lcd.front_buf)
        {
            rt_free(_lcd.front_buf);
        }
    }
    _lcd.parent.control(&_lcd.parent, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);

#ifdef BSP_USING_LVGL
    //Allocate GPU memory for LVGL
    vg_lite_error_t vglite_status = VG_LITE_SUCCESS;
    vg_module_parameters_t vg_params;
    vg_params.register_mem_base = (uint32_t)GFXSS_GFXSS_GPU_GCNANO;
    vg_params.gpu_mem_base[VG_PARAMS_POS] = GPU_MEM_BASE;
    vg_params.contiguous_mem_base[VG_PARAMS_POS] = (volatile void *) vglite_heap_base;
    vg_params.contiguous_mem_size[VG_PARAMS_POS] = VGLITE_HEAP_SIZE;
    vg_lite_init_mem(&vg_params);

    vglite_status = vg_lite_init((MY_DISP_HOR_RES) / 4,
                                 (MY_DISP_VER_RES) / 4);
    if (vglite_status == VG_LITE_SUCCESS)
    {
        LOG_I("Allocate GPU memory success\n");
    }
#endif

    return result;
}
INIT_APP_EXPORT(drv_lcd_hw_init);


#ifdef DRV_DEBUG
#ifdef FINSH_USING_MSH
int lcd_test(void)
{
    struct drv_lcd_device *lcd;
    lcd = (struct drv_lcd_device *)rt_device_find("lcd");

    //while (1)
    {
        if (lcd->lcd_info.pixel_format == RTGRAPHIC_PIXEL_FORMAT_RGB565)
        {
            /* red */
            for (int i = 0; i < LCD_BUF_SIZE / 2; i++)
            {
                lcd->lcd_info.framebuffer[2 * i] = 0x00;
                lcd->lcd_info.framebuffer[2 * i + 1] = 0xF8;
            }
            lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);
            rt_thread_mdelay(1000);
            /* green */
            for (int i = 0; i < LCD_BUF_SIZE / 2; i++)
            {
                lcd->lcd_info.framebuffer[2 * i] = 0xE0;
                lcd->lcd_info.framebuffer[2 * i + 1] = 0x07;
            }
            lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);
            rt_thread_mdelay(1000);
            /* blue */
            for (int i = 0; i < LCD_BUF_SIZE / 2; i++)
            {
                lcd->lcd_info.framebuffer[2 * i] = 0x1F;
                lcd->lcd_info.framebuffer[2 * i + 1] = 0x00;
            }
            rt_thread_mdelay(1000);
            for (int i = 0; i < LCD_BUF_SIZE / 2; i++)
            {
                lcd->lcd_info.framebuffer[2 * i] = 0xFF;
                lcd->lcd_info.framebuffer[2 * i + 1] = 0xFF;
            }
        }
        else if (lcd->lcd_info.pixel_format == RTGRAPHIC_PIXEL_FORMAT_RGB888)
        {
            /* red */
            for (int i = 0; i < LCD_BUF_SIZE / 3; i++)
            {
                lcd->lcd_info.framebuffer[3 * i] = 0x00;
                lcd->lcd_info.framebuffer[3 * i + 1] = 0x00;
                lcd->lcd_info.framebuffer[3 * i + 2] = 0xff;
            }
            lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);
            rt_thread_mdelay(1000);
            /* green */
            for (int i = 0; i < LCD_BUF_SIZE / 3; i++)
            {
                lcd->lcd_info.framebuffer[3 * i] = 0x00;
                lcd->lcd_info.framebuffer[3 * i + 1] = 0xff;
                lcd->lcd_info.framebuffer[3 * i + 2] = 0x00;
            }
            lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);
            rt_thread_mdelay(1000);
            /* blue */
            for (int i = 0; i < LCD_BUF_SIZE / 3; i++)//LCD_BUF_SIZE
            {
                lcd->lcd_info.framebuffer[3 * i] = 0xff;
                lcd->lcd_info.framebuffer[3 * i + 1] = 0x00;
                lcd->lcd_info.framebuffer[3 * i + 2] = 0x00;
            }
        }
        rt_thread_mdelay(1000);
    }
    return 0;
}
MSH_CMD_EXPORT(lcd_test, lcd_test);
#endif /* FINSH_USING_MSH */
#endif /* DRV_DEBUG */
#endif


