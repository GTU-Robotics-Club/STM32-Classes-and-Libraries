/**
*
* Class for MPU6050
*
* H file
*
* ##########    ##########     ##########
* ##########    ##########     ##########
* ###           ###    ###     ###
* ###           ##########     ###
* ###  #####    ###  ###       ###
* ###  #####    ###   ###      ###
* ###    ###    ###   ###      ###
* ##########    ###    ###     ##########
* ##########    ###     ###    ##########
*
*/

#ifndef MPU6050_H
#define MPU6050_H
#define RAD_TO_DEG 57.2957

#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_i2c.h"
#include <math.h>
/** Note the MPU6050_ADDR is 0xD0 / 0xD1 in 7 bits, if we do right shift, we get the desired address i.e. 0x68 / 0x69. */

#define MPU6050_ADDR 0xD0
#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75

class MPU6050 {
public:
	MPU6050(I2C_HandleTypeDef* hi2c);
	bool is_init = false;
	float get_accel_x();
	float get_accel_y();
	float get_accel_z();
	float get_gyro_x();
	float get_gyro_y();
	float get_gyro_z();
	float get_gyro_x_angle();
	float get_gyro_y_angle();
	float get_gyro_z_angle();
	void MPU6050_update();
private:
	I2C_HandleTypeDef* hi2c;
	float Ax, Ay, Az, Gx, Gy, Gz, angle_x = 0, angle_y = 0, angle_z = 0, interval;
	int16_t Accel_X_RAW = 0, Accel_Y_RAW = 0, Accel_Z_RAW = 0;
	int16_t Gyro_X_RAW = 0, Gyro_Y_RAW = 0, Gyro_Z_RAW = 0;
	uint8_t check, data;
	uint8_t Rec_Data[6];
	uint32_t init_time = 0;
	float error_Gx, error_Gy, error_Gz, error_Gz_min, error_Gz_max;
	float calculated_z_angle = 0;
	char buf[32];
	uint32_t previous_interval;
};

#endif
