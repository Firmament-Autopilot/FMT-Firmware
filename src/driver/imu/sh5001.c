/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#include "board_device.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"

#define DRV_DBG(...)

/******************************************************************
 *	SH5001 Registers Macro Definitions
 ******************************************************************/
#define SH5001_ACC_XL               (0x00U)
#define SH5001_ACC_XH               (0x01U)
#define SH5001_ACC_YL               (0x02U)
#define SH5001_ACC_YH               (0x03U)
#define SH5001_ACC_ZL               (0x04U)
#define SH5001_ACC_ZH               (0x05U)
#define SH5001_GYRO_XL              (0x06U)
#define SH5001_GYRO_XH              (0x07U)
#define SH5001_GYRO_YL              (0x08U)
#define SH5001_GYRO_YH              (0x09U)
#define SH5001_GYRO_ZL              (0x0AU)
#define SH5001_GYRO_ZH              (0x0BU)
#define SH5001_TEMP_ZL              (0x0CU)
#define SH5001_TEMP_ZH              (0x0DU)
#define SH5001_TIMESTAMP_L          (0x0EU)
#define SH5001_TIMESTAMP_M          (0x0FU)
#define SH5001_TIMESTAMP_H          (0x10U)
#define SH5001_INT_STA0             (0x16U)
#define SH5001_INT_STA1             (0x17U)
#define SH5001_INT_STA2             (0x18U)
#define SH5001_INT_STA3             (0x19U)
#define SH5001_INT_STA4             (0x1AU)
#define SH5001_FIFO_STA0            (0x1BU)
#define SH5001_FIFO_STA1            (0x1CU)
#define SH5001_FIFO_DATA            (0x1DU)

#define SH5001_CHIP_ID              (0x1FU)

#define SH5001_ACC_CONF0            (0x20U)
#define SH5001_ACC_CONF1            (0x21U)
#define SH5001_ACC_CONF2            (0x22U)

#define SH5001_GYRO_CONF0           (0x23U)
#define SH5001_GYRO_CONF1           (0x24U)
#define SH5001_GYRO_CONF2           (0x25U)

#define SH5001_OIS_ACC_CONF         (0x26U)
#define SH5001_OIS_GYRO_CONF        (0x27U)

#define SH5001_TEMP_CONF0           (0x28U)
#define SH5001_ACC_DOWNSAMPLE       (0x28U)
#define SH5001_TEMP_CONF1           (0x29U)
#define SH5001_TEMP_CONF2           (0x2AU)
#define SH5001_TIMESTAMP_CONF       (0x2AU)

#define SH5001_POWER_MODE           (0x30U)
#define SH5001_POWER_MODE_PWM       (0x31U)

#define SH5001_I2C_CONF             (0x34U)
#define SH5001_SPI_CONF             (0x34U)
#define SH5001_I2C_READ_LOOP        (0x34U)
#define SH5001_OIS_SPI_CONF         (0x34U)

#define SH5001_FIFO_CONF0           (0x35U)
#define SH5001_FIFO_CONF1           (0x36U)
#define SH5001_FIFO_CONF2           (0x37U)
#define SH5001_FIFO_CONF3           (0x38U)
#define SH5001_FIFO_CONF4           (0x39U)

#define SH5001_MI2C_CONF0           (0x3AU)
#define SH5001_MI2C_CONF1           (0x3BU)
#define SH5001_MI2C_CMD0            (0x3CU)
#define SH5001_MI2C_CMD1            (0x3DU)
#define SH5001_MI2C_WR              (0x3EU)
#define SH5001_MI2C_RD              (0x3FU)

#define SH5001_INT_ENABLE0          (0x40U)
#define SH5001_INT_ENABLE1          (0x41U)
#define SH5001_INT_CONF             (0x42U)
#define SH5001_INT_LIMIT            (0x43U)
#define SH5001_ORIEN_INTCONF0       (0x44U)
#define SH5001_ORIEN_INTCONF1       (0x45U)
#define SH5001_ORIEN_INT_1G5_LOW    (0x46U)
#define SH5001_ORIEN_INT_1G5_HIGH   (0x47U)
#define SH5001_ORIEN_INT_SLOPE_LOW  (0x48U)
#define SH5001_ORIEN_INT_SLOPE_HIGH (0x49U)
#define SH5001_ORIEN_INT_HYST_LOW   (0x4AU)
#define SH5001_ORIEN_INT_HYST_HIGH  (0x4BU)

#define SH5001_FLAT_INT_CONF        (0x4CU)

#define SH5001_ACT_INACT_INT_CONF   (0x4DU)
#define SH5001_ACT_INACT_INT_LINK   (0x4EU)
#define SH5001_ACT_INT_THRESHOLDL   (0x54U)
#define SH5001_ACT_INT_THRESHOLDH   (0x55U)
#define SH5001_ACT_INT_TIME         (0x56U)

#define SH5001_INACT_INT_THRESHOLDL (0x57U)
#define SH5001_INACT_INT_THRESHOLDH (0x58U)
#define SH5001_INACT_INT_TIME       (0x59U)

#define SH5001_SMD_INT_THRESHOLDL   (0x5AU)
#define SH5001_SMD_INT_THRESHOLDH   (0x5BU)
#define SH5001_SMD_INT_TIME         (0x5CU)

#define SH5001_TAP_INT_CONF         (0x4EU)
#define SH5001_TAP_INT_THRESHOLDL   (0x4FU)
#define SH5001_TAP_INT_THRESHOLDH   (0x50U)
#define SH5001_TAP_INT_DURATION     (0x51U)
#define SH5001_TAP_INT_LATENCY      (0x52U)
#define SH5001_DTAP_INT_WINDOW      (0x53U)

#define SH5001_HIGHG_INT_CONF       (0x5DU)
#define SH5001_HIGHG_INT_THRESHOLDL (0x5EU)
#define SH5001_HIGHG_INT_THRESHOLDH (0x5FU)
#define SH5001_HIGHG_INT_TIME       (0x60U)

#define SH5001_LOWG_INT_CONF        (0x5DU)
#define SH5001_LOWG_INT_THRESHOLDL  (0x61U)
#define SH5001_LOWG_INT_THRESHOLDH  (0x62U)
#define SH5001_LOWG_INT_TIME        (0x63U)

#define SH5001_FREEFALL_INT_THRES   (0x64U)
#define SH5001_FREEFALL_INT_TIME    (0x65U)

#define SH5001_INT_PIN_MAP0         (0x66U)
#define SH5001_INT_PIN_MAP1         (0x67U)

#define SH5001_SPI_REG_ACCESS       (0x7FU)
#define SH5001_AUX_I2C_CONF         (0xFDU)

#define SH5001_PIN_PP_CONF0         (0xFDU)
#define SH5001_PIN_PP_CONF1         (0xFEU)

/******************************************************************
 *	ACC Config Macro Definitions
 ******************************************************************/
#define SH5001_ACC_ODR_1000HZ       (0x00U) // TODO need to set ref datasheet
#define SH5001_ACC_ODR_500HZ        (0x01U)
#define SH5001_ACC_ODR_250HZ        (0x02U)
#define SH5001_ACC_ODR_125HZ        (0x03U)

#define SH5001_ACC_ODR_2000HZ       (0x08U)
#define SH5001_ACC_ODR_4000HZ       (0x09U)
#define SH5001_ACC_ODR_8000HZ       (0x0AU)

#define SH5001_ACC_RANGE_4G         (0x10U)
#define SH5001_ACC_RANGE_8G         (0x20U)
#define SH5001_ACC_RANGE_16G        (0x30U)
// #define SH5001_ACC_RANGE_32G	(0x40U)

#define SH5001_ACC_ODRX040          (0x00U)
#define SH5001_ACC_ODRX036          (0x01U)
#define SH5001_ACC_ODRX032          (0x02U)
#define SH5001_ACC_ODRX028          (0x03U)
#define SH5001_ACC_ODRX024          (0x04U)
#define SH5001_ACC_ODRX020          (0x05U)
#define SH5001_ACC_ODRX016          (0x06U)
#define SH5001_ACC_ODRX014          (0x07U)
#define SH5001_ACC_ODRX012          (0x08U)
#define SH5001_ACC_ODRX010          (0x09U)
#define SH5001_ACC_ODRX008          (0x0aU)
#define SH5001_ACC_ODRX006          (0x0bU)
#define SH5001_ACC_ODRX004          (0x0cU)
#define SH5001_ACC_ODRX003          (0x0dU)
#define SH5001_ACC_ODRX002          (0x0eU)
#define SH5001_ACC_ODRX001          (0x0fU)

#define SH5001_ACC_FILTER_EN        (0x01U)
#define SH5001_ACC_FILTER_DIS       (0x00U)
#define SH5001_ACC_BYPASS_EN        (0x02U)
#define SH5001_ACC_BYPASS_DIS       (0x00U)

/******************************************************************
 *	GYRO Config Macro Definitions
 ******************************************************************/
#define SH5001_GYRO_ODR_1000HZ      (0x00U)
#define SH5001_GYRO_ODR_500HZ       (0x01U)
#define SH5001_GYRO_ODR_250HZ       (0x02U)
#define SH5001_GYRO_ODR_125HZ       (0x03U)
#define SH5001_GYRO_ODR_2000HZ      (0x08U)
#define SH5001_GYRO_ODR_4000HZ      (0x09U)
#define SH5001_GYRO_ODR_8000HZ      (0x0AU)
#define SH5001_GYRO_ODR_16000HZ     (0x0BU)

#define SH5001_GYRO_RANGE_31        (0x00U)
#define SH5001_GYRO_RANGE_62        (0x10U)
#define SH5001_GYRO_RANGE_125       (0x20U)
#define SH5001_GYRO_RANGE_250       (0x30U)
#define SH5001_GYRO_RANGE_500       (0x40U)
#define SH5001_GYRO_RANGE_1000      (0x50U)
#define SH5001_GYRO_RANGE_2000      (0x60U)
#define SH5001_GYRO_RANGE_4000      (0x70U)

#define SH5001_GYRO_ODRX040         (0x00U)
#define SH5001_GYRO_ODRX036         (0x01U)
#define SH5001_GYRO_ODRX032         (0x02U)
#define SH5001_GYRO_ODRX028         (0x03U)
#define SH5001_GYRO_ODRX024         (0x04U)
#define SH5001_GYRO_ODRX020         (0x05U)
#define SH5001_GYRO_ODRX016         (0x06U)
#define SH5001_GYRO_ODRX014         (0x07U)
#define SH5001_GYRO_ODRX012         (0x08U)
#define SH5001_GYRO_ODRX010         (0x09U)
#define SH5001_GYRO_ODRX008         (0x0aU)
#define SH5001_GYRO_ODRX006         (0x0bU)
#define SH5001_GYRO_ODRX004         (0x0cU)
#define SH5001_GYRO_ODRX003         (0x0dU)
#define SH5001_GYRO_ODRX002         (0x0eU)
#define SH5001_GYRO_ODRX001         (0x0fU)

#define SH5001_GYRO_FILTER_EN       (0x01U)
#define SH5001_GYRO_FILTER_DIS      (0x00U)
#define SH5001_GYRO_BYPASS_EN       (0x02U)
#define SH5001_GYRO_BYPASS_DIS      (0x00U)

#define SH5001_GYRO_OFF_INACT       (0x80U)
#define SH5001_GYRO_ON_INACT        (0x00U)

static rt_device_t imu_spi_dev;

/* Re-implement this function to define customized rotation */
RT_WEAK void sh5001_rotate_to_frd(float val[3])
{
    /* do nothing */
}

static rt_err_t gyro_config(uint8_t gyroODR,
                            uint8_t gyroRange,
                            uint8_t gyroCutOffFreq,
                            uint8_t gyroFilter,
                            uint8_t gyroByPass)
{
    uint8_t regData = 0;

    // enable gyro digital filter
    // SH5001_read(SH5001_ADDRESS, SH5001_GYRO_CONF0, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_GYRO_CONF0, &regData));
    regData = (regData & 0x7CU) | gyroFilter | gyroByPass;
    // SH5001_write(SH5001_ADDRESS, SH5001_GYRO_CONF0, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_GYRO_CONF0, regData));

    // set gyro ODR Range
    // SH5001_read(SH5001_ADDRESS, SH5001_GYRO_CONF1, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_GYRO_CONF1, &regData));
    regData = (regData & 0x80U) | gyroODR | gyroRange;
    // SH5001_write(SH5001_ADDRESS, SH5001_GYRO_CONF1, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_GYRO_CONF1, regData));

    // set gyro low pass filter cut-off frequency
    // SH5001_read(SH5001_ADDRESS, SH5001_GYRO_CONF2, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_GYRO_CONF2, &regData));
    regData = (regData & 0xF0U) | gyroCutOffFreq;
    // SH5001_write(SH5001_ADDRESS, SH5001_GYRO_CONF2, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_GYRO_CONF2, regData));

    return RT_EOK;
}

static rt_err_t acc_config(uint8_t accODR,
                           uint8_t accRange,
                           uint8_t accCutOffFreq,
                           uint8_t accFilter,
                           uint8_t accByPass)
{
    uint8_t regData = 0;

    // enable acc digital filter and bypass or not
    // SH5001_read(SH5001_ADDRESS, SH5001_ACC_CONF0, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_ACC_CONF0, &regData));
    regData = (regData & 0xFCU) | accFilter | accByPass;
    // SH5001_write(SH5001_ADDRESS, SH5001_ACC_CONF0, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_ACC_CONF0, regData));

    // set acc ODR range
    // SH5001_read(SH5001_ADDRESS, SH5001_ACC_CONF1, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_ACC_CONF1, &regData));
    regData = (regData & 0x80U) | accODR | accRange;
    // regData = (regData & 0x80U)| accRange | accODR;
    // regData = (regData & 0x80U)| 0x38;
    // SH5001_write(SH5001_ADDRESS, SH5001_ACC_CONF1, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_ACC_CONF1, regData));

    // set acc low pass filter cut-off frequency
    // SH5001_read(SH5001_ADDRESS, SH5001_ACC_CONF2, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_ACC_CONF2, &regData));
    regData = (regData & 0xF0U) | accCutOffFreq;
    // SH5001_write(SH5001_ADDRESS, SH5001_ACC_CONF2, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_ACC_CONF2, regData));

    return RT_EOK;
}

static rt_err_t imu_data_stabilize(void)
{
    uint8_t regData = 0;

    // TODO Three times maybe
    // acc
    //  SH5001_read(SH5001_ADDRESS, SH5001_ACC_CONF0, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_ACC_CONF0, &regData));
    regData &= 0xFE;
    // SH5001_write(SH5001_ADDRESS, SH5001_ACC_CONF0, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_ACC_CONF0, regData));
    regData |= 0x1;
    // SH5001_write(SH5001_ADDRESS, SH5001_ACC_CONF0, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_ACC_CONF0, regData));

    // gyro
    //  SH5001_read(SH5001_ADDRESS, SH5001_GYRO_CONF0, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_GYRO_CONF0, &regData));
    regData &= 0xFE;
    // SH5001_write(SH5001_ADDRESS, SH5001_GYRO_CONF0, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_GYRO_CONF0, regData));
    regData |= 0x1;
    // SH5001_write(SH5001_ADDRESS, SH5001_GYRO_CONF0, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_GYRO_CONF0, regData));

    return RT_EOK;
}

static rt_err_t adjust_cf(void)
{
	uint8_t reg_addr[15] = { 0x8C, 0x8D, 0x8E, 0x8F, 0x98, 0x99, 0x9A, 0x9B, 0xA4, 0xA5, 0xA6, 0xA7, 0xC4, 0xC5, 0xC6};
	uint8_t regDataold[15];
	uint8_t regDatanew[15];
	short OldData[6];
	short NewData[6];
	int i = 0;

	// SH5001_read(SH5001_ADDRESS, reg_addr[12], 1, &regDataold[12]);
    RT_TRY(spi_read_reg8(imu_spi_dev, reg_addr[12], &regDataold[12]));
	if(regDataold[12] != 0x06)
		return RT_ERROR;

	for(i = 0; i < 15; i++)
	{
		// SH5001_read(SH5001_ADDRESS, reg_addr[i], 1, &regDataold[i]);
		RT_TRY(spi_read_reg8(imu_spi_dev, reg_addr[i], &regDataold[i]));
	}

	OldData[0] = (short)(regDataold[1] << 8 | regDataold[0]);
	OldData[1] = (short)(regDataold[3] << 8 | regDataold[2]);
	OldData[2] = (short)(regDataold[5] << 8 | regDataold[4]);
	OldData[3] = (short)(regDataold[7] << 8 | regDataold[6]);
	OldData[4] = (short)(regDataold[9] << 8 | regDataold[8]);
	OldData[5] = (short)(regDataold[11] << 8 | regDataold[10]);

	NewData[0] = OldData[0] * 1.693;
	NewData[1] = OldData[1] * 0.588 - 91;
	NewData[2] = OldData[2] * 1.693;
	NewData[3] = OldData[3] * 0.585 - 313;
	NewData[4] = OldData[4] * 1.679;
	NewData[5] = OldData[5] * 0.590 - 143;

	//printf("OldData %d %d %d %d %d %d \r\n",OldData[0], OldData[1], OldData[2], OldData[3], OldData[4], OldData[5]);
	//printf("NewData %d %d %d %d %d %d \r\n",NewData[0], NewData[1], NewData[2], NewData[3], NewData[4], NewData[5]);

	regDatanew[0] = NewData[0] & 0xFF;
	regDatanew[1] = (NewData[0] >> 8) & 0xFF;
	regDatanew[2] = NewData[1] & 0xFF;
	regDatanew[3] = (NewData[1] >> 8) & 0xFF;
	regDatanew[4] = NewData[2] & 0xFF;
	regDatanew[5] = (NewData[2] >> 8) & 0xFF;
	regDatanew[6] = NewData[3] & 0xFF;
	regDatanew[7] = (NewData[3] >> 8) & 0xFF;
	regDatanew[8] = NewData[4] & 0xFF;
	regDatanew[9] = (NewData[4] >> 8) & 0xFF;
	regDatanew[10] = NewData[5] & 0xFF;
	regDatanew[11] = (NewData[5] >> 8) & 0xFF;
	regDatanew[12] = 0x04;
	regDatanew[13] = 0x04;
	regDatanew[14] = 0x04;

	for(i = 0; i < 15; i++)
	{
		//printf("Adjust write = %x\r\n", regDatanew[i]);
		// SH5001_write(SH5001_ADDRESS, reg_addr[i], 1, &regDatanew[i]);
        RT_TRY(spi_write_reg8(imu_spi_dev, reg_addr[i], regDatanew[i]));
	}

    return RT_EOK;
}

static rt_err_t lowlevel_init(void)
{
    uint8_t chip_id;

    /* init spi bus */
    RT_TRY(rt_device_open(imu_spi_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(spi_read_reg8(imu_spi_dev, 0x1F, &chip_id));
    if (chip_id != 0xA1) {
        DRV_DBG("Incorrect SH5001 chip id: %02x\n", chip_id);
        return RT_ERROR;
    }

    /* software reset */
    RT_TRY(spi_write_reg8(imu_spi_dev, 0x2B, 0x01));
    RT_TRY(spi_write_reg8(imu_spi_dev, 0x00, 0x73));

    systime_mdelay(50);

    /* driver start */
    RT_TRY(spi_write_reg8(imu_spi_dev, 0x2B, 0x01));
    systime_mdelay(2);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0x2B, 0x00));
    systime_mdelay(1);

    /* reset adc */
    // RT_TRY(spi_write_reg8(imu_spi_dev, 0xD1, 0x6B));
    // RT_TRY(spi_write_reg8(imu_spi_dev, 0xD1, 0x68));
    RT_TRY(spi_write_reg8(imu_spi_dev, 0x30, 0x08));
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xD2, 0x00));
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xD1, 0x6B));
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xD5, 0x02));
    systime_mdelay(5);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xD1, 0x68));
    systime_mdelay(2);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xD5, 0x00));
    RT_TRY(spi_write_reg8(imu_spi_dev, 0x30, 0x00));
    systime_mdelay(50);

    // TODO: CVA reset?
    /* CVA reset */
    uint8_t regData = 0;
    uint8_t regDEData = 0;
    RT_TRY(spi_read_reg8(imu_spi_dev, 0xDE, &regDEData));
    regData = regDEData & 0xC7;
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xDE, regData));
    systime_mdelay(5);
    regData = regDEData | 0x38;
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xDE, regData));
    systime_mdelay(5);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xDE, regDEData));
    systime_mdelay(5);
    regData = 0x12;
    // SH5001_write(SH5001_ADDRESS, 0xCD, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xCD, regData));
    regData = 0x12;
    // SH5001_write(SH5001_ADDRESS, 0xCE, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xCE, regData));
    regData = 0x12;
    // SH5001_write(SH5001_ADDRESS, 0xCF, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xCF, regData));
    systime_mdelay(1);
    regData = 0x2;
    // SH5001_write(SH5001_ADDRESS, 0xCD, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xCD, regData));
    regData = 0x2;
    // SH5001_write(SH5001_ADDRESS, 0xCE, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xCE, regData));
    regData = 0x2;
    // SH5001_write(SH5001_ADDRESS, 0xCF, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xCF, regData));
    systime_mdelay(200);

    /* Acc reset */
    RT_TRY(spi_write_reg8(imu_spi_dev, 0x30, 0x08));
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xD8, 0xE0));
    systime_mdelay(5);
    RT_TRY(spi_write_reg8(imu_spi_dev, 0xD8, 0x00));
    RT_TRY(spi_write_reg8(imu_spi_dev, 0x30, 0x00));

    /* OSC freq */
    // SH5001_read(SH5001_ADDRESS, 0xDA, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, 0xDA, &regData));
    if ((regData & 0x07) != 0x07) {
        regData |= 0x07;
        RT_TRY(spi_write_reg8(imu_spi_dev, 0xDA, regData));
    }

    RT_TRY(gyro_config(SH5001_GYRO_ODR_1000HZ,
                       SH5001_GYRO_RANGE_2000,
                       SH5001_GYRO_ODRX040,
                       SH5001_GYRO_FILTER_DIS,
                       SH5001_GYRO_BYPASS_EN));

    RT_TRY(acc_config(SH5001_ACC_ODR_1000HZ,
                      SH5001_ACC_RANGE_16G,
                      SH5001_ACC_ODRX040,
                      SH5001_ACC_FILTER_DIS,
                      SH5001_ACC_BYPASS_EN));

    RT_TRY(imu_data_stabilize());

    /* temperature config */
	// enable temperature, set ODR
	// SH5001_read(SH5001_ADDRESS, SH5001_TEMP_CONF0, 1, &regData);
    RT_TRY(spi_read_reg8(imu_spi_dev, SH5001_TEMP_CONF0, &regData));
	regData = (regData & 0xF8U) | 0x06 | 0x01;
	// SH5001_write(SH5001_ADDRESS, SH5001_TEMP_CONF0, 1, &regData);
    RT_TRY(spi_write_reg8(imu_spi_dev, SH5001_TEMP_CONF0, regData));

    adjust_cf();

    return RT_EOK;
}

// void SH5001_GetImuData(float accData[3], float gyroData[3])
// {
//     unsigned char regData[12];
//     /* scale for range 2000dps and 16g */
//     static const float accScale = 9.806 / 2048.0;
//     static const float gyroScale = 0.0174532925 / 16.4;

//     // SH5001_read(SH5001_ADDRESS, SH5001_ACC_XL, 12, regData);
//     spi_read_multi_reg8(imu_spi_dev, SH5001_ACC_XL, regData, 12);

//     accData[0] = ((short)(regData[1] << 8) | regData[0]) * accScale;
//     accData[1] = ((short)(regData[3] << 8) | regData[2]) * accScale;
//     accData[2] = ((short)(regData[5] << 8) | regData[4]) * accScale;

//     gyroData[0] = ((short)(regData[7] << 8) | regData[6]) * gyroScale;
//     gyroData[1] = ((short)(regData[9] << 8) | regData[8]) * gyroScale;
//     gyroData[2] = ((short)(regData[11] << 8) | regData[10]) * gyroScale;

//     printf("%.2f %.2f %.2f %.2f %.2f %.2f\r\n", accData[0], accData[1], accData[2], gyroData[0], gyroData[1], gyroData[2]);
// }

static rt_size_t gyro_read(gyro_dev_t dev, rt_off_t pos, void* data, rt_size_t size)
{
    uint8_t regData[6];
    float* pdata = data;
    /* scale for range 2000dps */
    static const float gyroScale = 0.0174532925 / 16.4;

    if (data == NULL) {
        return 0;
    }

    if (spi_read_multi_reg8(imu_spi_dev, SH5001_GYRO_XL, regData, 6) != RT_EOK) {
        return 0;
    }

    pdata[0] = ((short)(regData[1] << 8) | regData[0]) * gyroScale;
    pdata[1] = ((short)(regData[3] << 8) | regData[2]) * gyroScale;
    pdata[2] = ((short)(regData[5] << 8) | regData[4]) * gyroScale;

    sh5001_rotate_to_frd(pdata);

    return size;
}

static rt_size_t accel_read(accel_dev_t dev, rt_off_t pos, void* data, rt_size_t size)
{
    uint8_t regData[6];
    float* pdata = data;
    /* scale for range 16g */
    static const float accScale = 9.806 / 2048.0;

    if (data == NULL) {
        return 0;
    }

    if (spi_read_multi_reg8(imu_spi_dev, SH5001_ACC_XL, regData, 6) != RT_EOK) {
        return 0;
    }

    pdata[0] = ((short)(regData[1] << 8) | regData[0]) * accScale;
    pdata[1] = ((short)(regData[3] << 8) | regData[2]) * accScale;
    pdata[2] = ((short)(regData[5] << 8) | regData[4]) * accScale;

    sh5001_rotate_to_frd(pdata);

    return size;
}

const static struct gyro_ops __gyro_ops = {
    .gyro_config = NULL,
    .gyro_control = NULL,
    .gyro_read = gyro_read,
};

const static struct accel_ops __accel_ops = {
    .accel_config = NULL,
    .accel_control = NULL,
    .accel_read = accel_read,
};

#define GYRO_CONFIG                                  \
    {                                                \
        1000,                   /* 1K sample rate */ \
            40,                 /* 40Hz bandwidth */ \
            GYRO_RANGE_2000DPS, /* +-2000 deg/s */   \
    }

#define ACCEL_CONFIG                              \
    {                                             \
        1000,                /* 1K sample rate */ \
            40,              /* 40Hz bandwidth */ \
            ACCEL_RANGE_16G, /* +-16g */          \
    }

static struct gyro_device gyro_dev = {
    .ops = &__gyro_ops,
    .config = GYRO_CONFIG,
    .bus_type = GYRO_SPI_BUS_TYPE
};

static struct accel_device accel_dev = {
    .ops = &__accel_ops,
    .config = ACCEL_CONFIG,
    .bus_type = GYRO_SPI_BUS_TYPE
};

rt_err_t drv_sh5001_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name)
{
    /* Initialize gyroscope */

    imu_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(imu_spi_dev != NULL);
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 2500000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)imu_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    RT_TRY(lowlevel_init());

    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));
    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    // float accData[3];
    // float gyroData[3];
    // while (1) {
    //     gyro_read(NULL, 0, gyroData, 6);
    //     accel_read(NULL, 0, accData, 6);
    //     printf("%.2f %.2f %.2f %.2f %.2f %.2f\r\n", accData[0], accData[1], accData[2], gyroData[0], gyroData[1], gyroData[2]);
    //     systime_mdelay(500);
    // }

    return RT_EOK;
}
