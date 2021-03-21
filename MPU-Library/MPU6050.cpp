/**
*
* Class for MPU6050
*
* CPP file
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

#include "MPU6050.h"

MPU6050::MPU6050(I2C_HandleTypeDef *hi2c) {
	this->hi2c = hi2c;
	HAL_I2C_Mem_Read(this->hi2c, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, 1000);
	if(this->check == 104) {
		/** Power management and waking up the sensor. */
		data = 0;
		HAL_I2C_Mem_Write(this->hi2c, MPU6050_ADDR, PWR_MGMT_1_REG, 1,&data, 1, 1000);
		/** Set DATA RATE of 1KHz */
		data = 0x07;
		HAL_I2C_Mem_Write(this->hi2c, MPU6050_ADDR, SMPLRT_DIV_REG, 1, &data, 1, 1000);
		/** Set accelerometer configuration */
		data = 0x02;
		HAL_I2C_Mem_Write(this->hi2c, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &data, 1, 1000);
		/** Set Gyroscopic configuration */
		data = 0x01;
		HAL_I2C_Mem_Write(this->hi2c, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &data, 1, 1000);
		this->is_init = true;
	} else {
		this->is_init = false;
	}
}

void MPU6050::MPU6050_Read_Accel() {
	HAL_I2C_Mem_Read (hi2c, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, this->Rec_Data, 6, 1000);

	this->Accel_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	this->Accel_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	this->Accel_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	this->Ax = Accel_X_RAW/4096.0;
	this->Ay = Accel_Y_RAW/4096.0;
	this->Az = Accel_Z_RAW/4096.0;
}

void MPU6050::MPU6050_Read_Gyro() {
	HAL_I2C_Mem_Read (this->hi2c, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, this->Rec_Data, 6, 1000);

	this->Gyro_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	this->Gyro_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	this->Gyro_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	this->Gx = Gyro_X_RAW/65.5;
	this->Gy = Gyro_Y_RAW/65.5;
	this->Gz = Gyro_Z_RAW/65.5;
}

float MPU6050::get_accel_x() {
	MPU6050_Read_Accel();
	return this->Ax;
}

float MPU6050::get_accel_y() {
	MPU6050_Read_Accel();
	return this->Ay;
}

float MPU6050::get_accel_z() {
	MPU6050_Read_Accel();
	return this->Az;
}

float MPU6050::get_gyro_x_angle() {
	MPU6050_Read_Gyro();
	return this->Gx;
}

float MPU6050::get_gyro_y_angle() {
	MPU6050_Read_Gyro();
	return this->Gy;
}

float MPU6050::get_gyro_z_angle() {
	MPU6050_Read_Gyro();
	return this->Gz;
}
