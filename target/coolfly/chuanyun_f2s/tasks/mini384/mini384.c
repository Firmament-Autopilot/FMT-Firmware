#include "debuglog.h"
#include <stdlib.h>

#include "ar1002_chip.h"
#include "ar1002_hal.h"

#include "mini384.h"

#include "module/workqueue/workqueue_manager.h"

#define MINI384_DVP_CHANNEL 1
#define MINI384_RST         HAL_GPIO_NUM103
#define MINI384_I2C         HAL_I2C_COMPONENT_0

// #define MINI384_DVP_CHANNEL 0
// #define MINI384_RST         HAL_GPIO_NUM99
// #define MINI384_I2C         HAL_I2C_COMPONENT_1

#define MINI384_I2C_ADDR    0x3C

// uint8_t config1_640x512_30fps[10] = { 0x9D, 0x00, 0x0F, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08 };
// uint8_t config2_640x512_30fps[10] = { 0x1D, 0x08, 0x00, 0x00, 0x02, 0x80, 0x02, 0x00, 0x1E, 0x00 };

// uint8_t config1_384x288_30fps[10] = { 0x9D, 0x00, 0x0F, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08 };
// uint8_t config2_384x288_30fps[10] = { 0x1D, 0x08, 0x00, 0x00, 0x01, 0x80, 0x01, 0x20, 0x1E, 0x00 };

static volatile int is_Inited = 0;

_EXT_DTCM1
void mini384_loop_callback(void)
{
    uint8_t miDVPChannel = MINI384_DVP_CHANNEL;

    if (is_Inited == 0) {
        return;
    }

    if (miDVPChannel == 0) {
        if ((Reg_Read32(0xA0010000 + (0x3 << 2)) & 0x00FF0000) != 0x00010000) {
            // DLOG_Critical("DVP0 Call Patch Start!\n\n");

            // 要在配置这些配置之前，最好先把encoder 关掉，配置完在打开。
            // 关掉：
            // View0:0x10写0x00
            Reg_Write32_Mask(0xA0010000 + (0x00 << 2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
            // 开启8bit mode. & VS Positive Polarity & HS Negative Polarity
            //*(0x01)|0x24
            Reg_Write32_Mask(0xA0010000, (uint32_t)((1 << 21) | (4 << 16)), (uint32_t)((1 << 21) | (7 << 16)));
            // Porch:
            // View0:
            Reg_Write32(0xA0010000 + (0x3 << 2), 0x00010000);
            Reg_Write32_Mask(0xA0010000 + (0x4 << 2), 0, (((uint32_t)0xFFF << 16) | 0xFFF));
            // 关掉自动检测机制
            Reg_Write32_Mask(0xA0010000 + (0x0a << 2), (uint32_t)(0 << 5), (uint32_t)(3 << 5));
            // DE mode & valid data in low 8bit:
            Reg_Write32_Mask(0xA0010000 + (0x04 << 2), (uint32_t)(1 << 13), (uint32_t)(7 << 13));
#if 0
			//先把watch dog关掉， 因为现在帧率有点低。
			Reg_Write32_Mask(0xA0010000 + (0x04 << 2), (uint32_t)(0 << 28), (uint32_t)(0xf << 28));
			Reg_Write32_Mask(0xA0010000 + (0x33 << 2), (uint32_t)(0 << 4), (uint32_t)(0xf << 4));
#endif
            // 同时也把码流控制也关掉吧，因为帧率不正确码流也不正确。
            // Reg_Write32_Mask(0xA0010000+(0x05<<2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
            // 同时也把码流控制打开
            Reg_Write32_Mask(0xA0010000 + (0x05 << 2), (uint32_t)(1 << 24), (uint32_t)(1 << 24));
            // 打开：建议用工具手动打开，因为你现在还在调试阶段。
            // View0:
            Reg_Write32_Mask(0xA0010000 + (0x00 << 2), (uint32_t)(1 << 24), (uint32_t)(1 << 24));

            /*//View0:0x10写0x00
                        Reg_Write32_Mask(0xA0010000+(0x00<<2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
                        Reg_Write32(0xA0010000+(0x3<<2), 0x00010000);
                        //View0:
                        Reg_Write32_Mask(0xA0010000+(0x00<<2), (uint32_t)(1<<24), (uint32_t)(1<<24));*/

            // DLOG_Critical("DVP0 Call Patch End!\n\n");
        }

    } else {
        if ((Reg_Read32(0xA0010000 + (0x1c << 2)) & 0x00FF0000) != 0x00010000) {
            // DLOG_Critical("DVP1 Call Patch Start!\n\n");
            // 要在配置这些配置之前，最好先把encoder 关掉，配置完在打开。
            // 关掉：
            // View1:0x64写0x00
            Reg_Write32_Mask(0xA0010000 + (0x19 << 2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
            // 开启8bit mode. & VS Positive Polarity & HS Negative Polarity
            //*(0x65)|0x24
            Reg_Write32_Mask(0xA0010000 + (0x19 << 2), (uint32_t)((1 << 21) | (4 << 16)), (uint32_t)((1 << 21) | (7 << 16)));
            // Porch:
            // View1:
            Reg_Write32(0xA0010000 + (0x1c << 2), 0x00010000);
            Reg_Write32_Mask(0xA0010000 + (0x1d << 2), 0, (((uint32_t)0xFFF << 16) | 0xFFF));
            // 关掉自动检测机制
            Reg_Write32_Mask(0xA0010000 + (0x23 << 2), (uint32_t)(0 << 5), (uint32_t)(3 << 5));
            // DE mode & valid data in low 8bit:
            Reg_Write32_Mask(0xA0010000 + (0x1D << 2), (uint32_t)(1 << 13), (uint32_t)(7 << 13));

#if 0
			//先把watch dog关掉， 因为现在帧率有点低。
			Reg_Write32_Mask(0xA0010000 + (0x1D << 2), (uint32_t)(0 << 28), (uint32_t)(0xf << 28));
			Reg_Write32_Mask(0xA0010000 + (0x33 << 2), (uint32_t)(0 << 4), (uint32_t)(0xf << 4));
#endif
            // 同时也把码流控制也关掉吧，因为帧率不正确码流也不正确。
            // Reg_Write32_Mask(0xA0010000+(0x1e<<2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
            // 同时也把码流控制打开
            Reg_Write32_Mask(0xA0010000 + (0x1e << 2), (uint32_t)(1 << 24), (uint32_t)(1 << 24));
            // 打开：建议用工具手动打开，因为你现在还在调试阶段。
            // View1:
            Reg_Write32_Mask(0xA0010000 + (0x19 << 2), (uint32_t)(1 << 24), (uint32_t)(1 << 24));

            /*//View0:0x10写0x00
                        Reg_Write32_Mask(0xA0010000+(0x19<<2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
                        Reg_Write32(0xA0010000+(0x1c<<2), 0x00010000);
                        //View1:
                        Reg_Write32_Mask(0xA0010000+(0x19<<2), (uint32_t)(1<<24), (uint32_t)(1<<24));*/

            // DLOG_Critical("DVP1 Call Patch End!\n\n");
        }
    }
}

_EXT_DTCM1
int mini384_encode_config(void)
{
    uint8_t miDVPChannel = MINI384_DVP_CHANNEL;
    HAL_DVP_SendInfoToEncoder(MINI384_DVP_CHANNEL);

    sys_msleep(100); // 延时一段时间让CPU2操作完DVP

    /*//开启8bit mode.
        Reg_Write32_Mask(0xA0010000, (uint32_t)1 << 21, (uint32_t)1 << 21);
        Reg_Write32_Mask(0xA0010000+(0x19<<2), (uint32_t)1 << 21, (uint32_t)1 << 21);
        //Porch:
        //View0:
        Reg_Write32(0xA0010000+(0x3<<2), 0);
        Reg_Write32_Mask(0xA0010000+(0x4<<2), 0, (((uint32_t)0xFFF << 16) | 0xFFF));
        //View1:
        Reg_Write32(0xA0010000+(0x1c<<2), 0);
        Reg_Write32_Mask(0xA0010000+(0x1d<<2), 0, (((uint32_t)0xFFF << 16) | 0xFFF));*/
    if (miDVPChannel == 0) {
        // 要在配置这些配置之前，最好先把encoder 关掉，配置完在打开。
        // 关掉：
        // View0:0x10写0x00
        Reg_Write32_Mask(0xA0010000 + (0x00 << 2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
        // 开启8bit mode. & VS Positive Polarity & HS Negative Polarity
        //*(0x01)|0x24
        Reg_Write32_Mask(0xA0010000, (uint32_t)((1 << 21) | (4 << 16)), (uint32_t)((1 << 21) | (7 << 16)));
        // Porch:
        // View0:
        Reg_Write32(0xA0010000 + (0x3 << 2), 0x00010000);
        Reg_Write32_Mask(0xA0010000 + (0x4 << 2), 0, (((uint32_t)0xFFF << 16) | 0xFFF));
        // 关掉自动检测机制
        Reg_Write32_Mask(0xA0010000 + (0x0a << 2), (uint32_t)(0 << 5), (uint32_t)(3 << 5));
        // DE mode & valid data in low 8bit:
        Reg_Write32_Mask(0xA0010000 + (0x04 << 2), (uint32_t)(1 << 13), (uint32_t)(7 << 13));
#if 0
		//先把watch dog关掉， 因为现在帧率有点低。
		Reg_Write32_Mask(0xA0010000 + (0x04 << 2), (uint32_t)(0 << 28), (uint32_t)(0xf << 28));
		Reg_Write32_Mask(0xA0010000 + (0x33 << 2), (uint32_t)(0 << 4), (uint32_t)(0xf << 4));
#endif
        // 同时也把码流控制也关掉吧，因为帧率不正确码流也不正确。
        // Reg_Write32_Mask(0xA0010000+(0x05<<2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
        // 同时也把码流控制打开
        Reg_Write32_Mask(0xA0010000 + (0x05 << 2), (uint32_t)(1 << 24), (uint32_t)(1 << 24));
        // 打开：建议用工具手动打开，因为你现在还在调试阶段。
        // View0:
        Reg_Write32_Mask(0xA0010000 + (0x00 << 2), (uint32_t)(1 << 24), (uint32_t)(1 << 24));

    } else {
        // 要在配置这些配置之前，最好先把encoder 关掉，配置完在打开。
        // 关掉：
        // View1:0x64写0x00
        Reg_Write32_Mask(0xA0010000 + (0x19 << 2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
        // 开启8bit mode. & VS Positive Polarity & HS Negative Polarity
        //*(0x65)|0x24
        Reg_Write32_Mask(0xA0010000 + (0x19 << 2), (uint32_t)((1 << 21) | (4 << 16)), (uint32_t)((1 << 21) | (7 << 16)));
        // Porch:
        // View1:
        Reg_Write32(0xA0010000 + (0x1c << 2), 0x00010000);
        Reg_Write32_Mask(0xA0010000 + (0x1d << 2), 0, (((uint32_t)0xFFF << 16) | 0xFFF));
        // 关掉自动检测机制
        Reg_Write32_Mask(0xA0010000 + (0x23 << 2), (uint32_t)(0 << 5), (uint32_t)(3 << 5));
        // DE mode & valid data in low 8bit:
        Reg_Write32_Mask(0xA0010000 + (0x1D << 2), (uint32_t)(1 << 13), (uint32_t)(7 << 13));

#if 0
		//先把watch dog关掉， 因为现在帧率有点低。
		Reg_Write32_Mask(0xA0010000 + (0x1D << 2), (uint32_t)(0 << 28), (uint32_t)(0xf << 28));
		Reg_Write32_Mask(0xA0010000 + (0x33 << 2), (uint32_t)(0 << 4), (uint32_t)(0xf << 4));
#endif
        // 同时也把码流控制也关掉吧，因为帧率不正确码流也不正确。
        // Reg_Write32_Mask(0xA0010000+(0x1e<<2), (uint32_t)(0 << 24), (uint32_t)(1 << 24));
        // 同时也把码流控制打开
        Reg_Write32_Mask(0xA0010000 + (0x1e << 2), (uint32_t)(1 << 24), (uint32_t)(1 << 24));
        // 打开：建议用工具手动打开，因为你现在还在调试阶段。
        // View1:
        Reg_Write32_Mask(0xA0010000 + (0x19 << 2), (uint32_t)(1 << 24), (uint32_t)(1 << 24));
    }

    return 0;
}

_EXT_DTCM1
static void mini384_init(void)
{
    DLOG_Critical("mini384_init");

    // try to start device
    uint8_t tries = 5;

    HAL_I2C_MasterInit(MINI384_I2C, MINI384_I2C_ADDR, HAL_I2C_FAST_SPEED);
    HAL_Delay(1000);

    while (tries) {

        uint8_t value1 = 0xFF;
        uint8_t value2 = 0xFF;

        uint8_t reg1[2] = { 0x00, 0x00 };

        HAL_RET_T ret = HAL_I2C_MasterReadData(MINI384_I2C, MINI384_I2C_ADDR, reg1, 2, &value1, 1, 1000);

        if (ret != HAL_OK) {
            DLOG_Critical("ret =%08x !", ret);
        }

        uint8_t reg2[2] = { 0x00, 0x01 };
        ret             = HAL_I2C_MasterReadData(MINI384_I2C, MINI384_I2C_ADDR, reg2, 2, &value2, 1, 1000);

        if (ret != HAL_OK) {
            DLOG_Critical("ret =%08x !", ret);
        }

        DLOG_Critical("value1 =%02x value2 = %02x !", value1, value2);

        // read WHO_AM_I value
        if ((value1 == 0x53) && (value2 == 0x52)) {
            break;
        }

        HAL_Delay(10);
        tries--;
    }

    if (!tries) {
        DLOG_Critical("can't find mini384 !");
        return;
    }

    tries = 5;

    DLOG_Critical("mini384 init success~!");

    HAL_Delay(20);

    uint8_t config1_readid[10] = { 0x1d, 0x00, 0x05, 0x84, 0x04, 0x00, 0x00, 0x04, 0x00, 0x04 };
    uint8_t reg_readid[2]      = { 0x1d, 0x08 };
    uint8_t config2_readid[4];

    HAL_I2C_MasterWriteData(MINI384_I2C, MINI384_I2C_ADDR, config1_readid, 10, 1000);
    HAL_RET_T ret = HAL_I2C_MasterReadData(MINI384_I2C, MINI384_I2C_ADDR, reg_readid, 2, config2_readid, 4, 1000);

    if (ret != HAL_OK) {
        DLOG_Critical("ret =%08x !", ret);
    }

    DLOG_Critical("version = %02x %02x %02x %02x", config2_readid[0], config2_readid[1], config2_readid[2], config2_readid[3]);

    HAL_Delay(20);

    // uint8_t config1_640x512_30fps[10] = { 0x9D, 0x00, 0x0F, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08 };
    // uint8_t config2_640x512_30fps[10] = { 0x1D, 0x08, 0x00, 0x00, 0x02, 0x80, 0x02, 0x00, 0x1E, 0x00 };

    uint8_t config1_384x288_30fps[10] = { 0x9D, 0x00, 0x0F, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08 };
    uint8_t config2_384x288_30fps[10] = { 0x1D, 0x08, 0x00, 0x00, 0x01, 0x80, 0x01, 0x20, 0x1E, 0x00 };

    HAL_I2C_MasterWriteData(MINI384_I2C, MINI384_I2C_ADDR, config1_384x288_30fps, 10, 1000);
    HAL_Delay(20);
    HAL_I2C_MasterWriteData(MINI384_I2C, MINI384_I2C_ADDR, config2_384x288_30fps, 10, 1000);
    HAL_Delay(20);

    mini384_encode_config();

    is_Inited = 1;
}

_EXT_DTCM1
void mini384_reset(void)
{
    HAL_GPIO_OutPut(MINI384_RST);
    HAL_GPIO_SetPin(MINI384_RST, HAL_GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_SetPin(MINI384_RST, HAL_GPIO_PIN_SET);
    HAL_Delay(10000);
}

/////////////////////////////////////////////////////

_EXT_DTCM1
static void run_mini384(void* parameter)
{
    if (!is_Inited) {

        mini384_reset();
        mini384_init();
        is_Inited = 1; // just set once.
    } else {
        mini384_loop_callback();
    }
}

_EXT_DTCM1_BSS
static struct WorkItem mini384_item = {
    .name          = "mini384",
    .period        = 300,
    .schedule_time = 5000,
    .run           = run_mini384
};

_EXT_DTCM1
void mini384_start(void)
{

    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");

    RT_ASSERT(lp_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(lp_wq, &mini384_item));
}
