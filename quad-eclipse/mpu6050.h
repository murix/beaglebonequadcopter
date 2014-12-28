/*
 * mpu6050.h
 *
 *  Created on: 10/08/2014
 *      Author: root
 */

#ifndef MPU6050_H_
#define MPU6050_H_

//http://www.invensense.com/mems/gyro/mpu6050.html
//http://www.invensense.com/mems/gyro/documents/RM-MPU-6000A-00v4.2.pdf


//
#define MPU6050_REG_SELF_TEST_X   0x0d
#define MPU6050_REG_SELF_TEST_Y   0x0e
#define MPU6050_REG_SELF_TEST_Z   0x0f
#define MPU6050_REG_SELF_TEST_A   0x10

#define MPU6050_REG_SMPLRT_DIV     0x19
#define MPU6050_REG_CONFIG         0x1a
#define MPU6050_REG_GYRO_CONFIG    0x1b
#define MPU6050_REG_ACCEL_CONFIG   0x1c
#define MPU6050_REG_FIFO_EN        0x23

#define MPU6050_REG_I2C_MST_CTRL   0x24

#define MPU6050_REG_I2C_SLV0_ADDR  0x25
#define MPU6050_REG_I2C_SLV0_REG   0x26
#define MPU6050_REG_I2C_SLV0_CTRL  0x27

#define MPU6050_REG_I2C_SLV1_ADDR  0x28
#define MPU6050_REG_I2C_SLV1_REG   0x29
#define MPU6050_REG_I2C_SLV1_CTRL  0x2a

#define MPU6050_REG_I2C_SLV2_ADDR  0x2b
#define MPU6050_REG_I2C_SLV2_REG   0x2c
#define MPU6050_REG_I2C_SLV2_CTRL  0x2d

#define MPU6050_REG_I2C_SLV3_ADDR  0x2e
#define MPU6050_REG_I2C_SLV3_REG   0x2f
#define MPU6050_REG_I2C_SLV3_CTRL  0x30

#define MPU6050_REG_I2C_SLV4_ADDR  0x31
#define MPU6050_REG_I2C_SLV4_REG   0x32
#define MPU6050_REG_I2C_SLV4_DO    0x33
#define MPU6050_REG_I2C_SLV4_CTRL  0x34
#define MPU6050_REG_I2C_SLV4_DI    0x35

#define MPU6050_REG_I2C_MST_STATUS 0x36

#define MPU6050_REG_INT_PIN_CFG    0x37
#define MPU6050_REG_INT_ENABLE     0x38
#define MPU6050_REG_INT_STATUS     0x3A

#define MPU6050_REG_ACCEL_XOUT_H   0x3b
#define MPU6050_REG_ACCEL_XOUT_L   0x3c
#define MPU6050_REG_ACCEL_YOUT_H   0x3d
#define MPU6050_REG_ACCEL_YOUT_L   0x3e
#define MPU6050_REG_ACCEL_ZOUT_H   0x3f
#define MPU6050_REG_ACCEL_ZOUT_L   0x40

#define MPU6050_REG_TEMP_OUT_H     0x41
#define MPU6050_REG_TEMP_OUT_L     0x42

#define MPU6050_REG_GYRO_XOUT_H    0x43
#define MPU6050_REG_GYRO_XOUT_L    0x44
#define MPU6050_REG_GYRO_YOUT_H    0x45
#define MPU6050_REG_GYRO_YOUT_L    0x46
#define MPU6050_REG_GYRO_ZOUT_H    0x47
#define MPU6050_REG_GYRO_ZOUT_L    0x48

#define MPU6050_REG_EXT_SENS_DATA_00 0x49
#define MPU6050_REG_EXT_SENS_DATA_01 0x4a
#define MPU6050_REG_EXT_SENS_DATA_02 0x4b
#define MPU6050_REG_EXT_SENS_DATA_03 0x4c
#define MPU6050_REG_EXT_SENS_DATA_04 0x4d
#define MPU6050_REG_EXT_SENS_DATA_05 0x4e
#define MPU6050_REG_EXT_SENS_DATA_06 0x4f
#define MPU6050_REG_EXT_SENS_DATA_07 0x50
#define MPU6050_REG_EXT_SENS_DATA_08 0x51
#define MPU6050_REG_EXT_SENS_DATA_09 0x52
#define MPU6050_REG_EXT_SENS_DATA_10 0x53
#define MPU6050_REG_EXT_SENS_DATA_11 0x54
#define MPU6050_REG_EXT_SENS_DATA_12 0x55
#define MPU6050_REG_EXT_SENS_DATA_13 0x56
#define MPU6050_REG_EXT_SENS_DATA_14 0x57
#define MPU6050_REG_EXT_SENS_DATA_15 0x58
#define MPU6050_REG_EXT_SENS_DATA_16 0x59
#define MPU6050_REG_EXT_SENS_DATA_17 0x5a
#define MPU6050_REG_EXT_SENS_DATA_18 0x5b
#define MPU6050_REG_EXT_SENS_DATA_19 0x5c
#define MPU6050_REG_EXT_SENS_DATA_20 0x5d
#define MPU6050_REG_EXT_SENS_DATA_21 0x5e
#define MPU6050_REG_EXT_SENS_DATA_22 0x5f
#define MPU6050_REG_EXT_SENS_DATA_23 0x60

#define MPU6050_REG_SLV_DO 0x63
#define MPU6050_REG_SLV_D1 0x64
#define MPU6050_REG_SLV_D2 0x65
#define MPU6050_REG_SLV_D3 0x66

#define MPU6050_REG_I2C_MST_DELAY_CTRL 0x67
#define MPU6050_REG_SIGNAL_PATH_RESET  0x68
#define MPU6050_REG_USER_CTRL          0x6a
#define MPU6050_REG_PWR_MGMT_1         0x6b
#define MPU6050_REG_PWR_MGMT_2         0x6c
#define MPU6050_REG_FIFO_COUNTH        0x72
#define MPU6050_REG_FIFOLCOUTNL        0x73
#define MPU6050_REG_FIFO_R_W           0x74
#define MPU6050_REG_WHO_AM_I           0x75

#define MPU6050_REG_WHO_AMI_I_REPLY    0x68
#define MPU6050_REG_PWR_MGMT_1_DEFAULT 0x40

#define MPU6050_DLPF_CFG_ACCEL_260HZ_DELAY_0_US_GYRO_256HZ_DELAY_980US_FS_8KHZ 0
#define MPU6050_DLPF_CFG_ACCEL_184HZ_DELAY_2000_US_GYRO_188HZ_DELAY_1900US_FS_1KHZ 1
#define MPU6050_DLPF_CFG_ACCEL_94HZ_DELAY_3000_US_GYRO_98HZ_DELAY_2800US_FS_1KHZ 2
#define MPU6050_DLPF_CFG_ACCEL_44HZ_DELAY_4900_US_GYRO_42HZ_DELAY_4800US_FS_1KHZ 3
#define MPU6050_DLPF_CFG_ACCEL_21HZ_DELAY_8500_US_GYRO_20HZ_DELAY_8300US_FS_1KHZ 4
#define MPU6050_DLPF_CFG_ACCEL_10HZ_DELAY_13800_US_GYRO_10HZ_DELAY_13400US_FS_1KHZ 5
#define MPU6050_DLPF_CFG_ACCEL_5HZ_DELAY_19000_US_GYRO_5HZ_DELAY_18600US_FS_1KHZ 6
#define MPU6050_DLPF_RESERVED                                                  7

class mpu6050 {
public:
	int fd;
	float acc[3];
	float accn;
	float gyro_raw[3];
	float gyro[3];
	float gyro_off[3];
	float tc;
	float acc_pitch;
	float acc_roll;
	float fusion_pitch;
	float fusion_roll;



	void gyro_calibration(int samples);

	void init();
	mpu6050(int fd);
	void update();

	double to_degrees(double radians);
	double to_radian(double degree);

	double t_back;
	double t_now;
	double t_diff;
	float gyro_step[3];
	float gyro_integrate[3];
	void gyro_integrate_reset();
};



#endif /* MPU6050_H_ */
