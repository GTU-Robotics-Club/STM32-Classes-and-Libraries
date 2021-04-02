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
		data = 0x00;
		HAL_I2C_Mem_Write(this->hi2c, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &data, 1, 1000);
		/** Set Gyroscopic configuration */
		data = 0x00;
		HAL_I2C_Mem_Write(this->hi2c, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &data, 1, 1000);
		this->is_init = true;
		this->init_time = HAL_GetTick();
		HAL_I2C_Mem_Read (this->hi2c, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, this->Rec_Data, 6, 1000);
		this->Gyro_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
		this->Gyro_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
		this->Gyro_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
		error_Gz_min = Gyro_Z_RAW / 131.0;
		error_Gz_max = Gyro_Z_RAW / 131.0;
		for(uint16_t i = 0; i < 3000; i++) {
			HAL_I2C_Mem_Read (this->hi2c, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, this->Rec_Data, 6, 1000);
			this->Gyro_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
			this->Gyro_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
			this->Gyro_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
			this->error_Gx += Gyro_X_RAW/131.0;
			this->error_Gy += Gyro_Y_RAW/131.0;
			this->error_Gz += Gyro_Z_RAW/131.0;
			// Modification
			if(error_Gz_max < (Gyro_Z_RAW / 131.0)) {
				error_Gz_max = Gyro_Z_RAW / 131.0;
			}
			if(error_Gz_min > (Gyro_Z_RAW / 131.0)) {
				error_Gz_min = Gyro_Z_RAW / 131.0;
			}
		}
		error_Gx /= 3000;
		error_Gy /= 3000;
		error_Gz /= 3000;
		this->previous_interval = HAL_GetTick();
	} else {
		this->is_init = false;
	}
}

void MPU6050::MPU6050_update() {
	HAL_I2C_Mem_Read (hi2c, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, this->Rec_Data, 6, 1000);
	this->Accel_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	this->Accel_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	this->Accel_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	this->Ax = Accel_X_RAW/16384.0;
	this->Ay = Accel_Y_RAW/16384.0;
	this->Az = Accel_Z_RAW/16384.0;

	HAL_I2C_Mem_Read (this->hi2c, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, this->Rec_Data, 6, 100);
	this->Gyro_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	this->Gyro_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	this->Gyro_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);
	this->Gx = Gyro_X_RAW/131.0;
	this->Gy = Gyro_Y_RAW/131.0;
	this->Gz = Gyro_Z_RAW/131.0;
	this->Gx -= error_Gx;
	this->Gy -= error_Gy;
	if(Gz > error_Gz_min && Gz < error_Gz_max) {
		this->Gz = 0;
	} else {
		this->Gz -= error_Gz;
	}
	interval = (HAL_GetTick() - previous_interval) * 0.001;
	angle_x = (atan2(-Ay,Az) * 180.0) / M_PI;
	angle_y = (atan2(Ax, sqrt(Ay * Ay + Az * Az)) * 180.0) / M_PI;
	angle_z += (Gz) * interval;

	previous_interval = HAL_GetTick();

}


float MPU6050::get_accel_x() {
	MPU6050_update();
	return this->Ax;
}

float MPU6050::get_accel_y() {
	MPU6050_update();
	return this->Ay;
}

float MPU6050::get_accel_z() {
	MPU6050_update();
	return this->Az;
}

float MPU6050::get_gyro_x() {
	MPU6050_update();
	return this->Gx;
}

float MPU6050::get_gyro_y() {
	MPU6050_update();
	return this->Gy;
}

float MPU6050::get_gyro_z() {
	MPU6050_update();
	return this->Gz;
}

float MPU6050::get_gyro_x_angle() {
	MPU6050_update();
	return this->angle_x;
}

float MPU6050::get_gyro_y_angle() {
	MPU6050_update();
	return this->angle_y;
}

float MPU6050::get_gyro_z_angle() {
	MPU6050_update();
	return this->angle_z;
}



