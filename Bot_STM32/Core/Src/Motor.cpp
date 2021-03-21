/**
*
* Class for motors
*
* CPP file
*
* Compatible with:
* 1. Cytron
* 2. Hercules
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
#include "Motor.h"
#include <stdio.h>
#include <stm32f1xx_hal_tim.h>

Motor::Motor() {

}

Motor::Motor(GPIO_TypeDef* GPIOx_1, uint16_t GPIO_Pin_1, TIM_HandleTypeDef *htim, uint32_t Channel, TIM_TypeDef *tim) {
	this->cytron = true;
	this->GPIOx_1 = GPIOx_1;
	this->GPIO_Pin_1 = GPIO_Pin_1;
	this->htim = htim;
	this->Channel = Channel;
	this->tim = tim;
	HAL_TIM_PWM_Start(htim, this->Channel);
	HAL_GPIO_WritePin(this->GPIOx_1, this->GPIO_Pin_1, GPIO_PIN_RESET);
}

Motor::Motor(GPIO_TypeDef* GPIOx_1, uint16_t GPIO_Pin_1, GPIO_TypeDef* GPIOx_2, uint16_t GPIO_Pin_2, TIM_HandleTypeDef *htim, uint32_t Channel, TIM_TypeDef *tim) {
	this->cytron = false;
	this->GPIOx_1 = GPIOx_1;
	this->GPIO_Pin_1 = GPIO_Pin_1;
	this->GPIOx_2 = GPIOx_2;
	this->GPIO_Pin_2 = GPIO_Pin_2;
	this->htim = htim;
	this->Channel = Channel;
	this->tim = tim;
	HAL_TIM_PWM_Start(htim, this->Channel);
	HAL_GPIO_WritePin(this->GPIOx_1, this->GPIO_Pin_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(this->GPIOx_2, this->GPIO_Pin_2, GPIO_PIN_RESET);
}

void Motor::clockwise(uint8_t pwm) {
	if(cytron) {
		HAL_GPIO_WritePin(this->GPIOx_1, this->GPIO_Pin_1, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(this->GPIOx_1, this->GPIO_Pin_1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(this->GPIOx_2, this->GPIO_Pin_2, GPIO_PIN_RESET);
	}
	switch(this->Channel) {
	case TIM_CHANNEL_1:
		this->tim->CCR1 = pwm;
		break;
	case TIM_CHANNEL_2:
		this->tim->CCR2 = pwm;
		break;
	case TIM_CHANNEL_3:
		this->tim->CCR3 = pwm;
		break;
	case TIM_CHANNEL_4:
		this->tim->CCR4 = pwm;
		break;
	default:
		printf("\nErr.\n");
	}
}

void Motor::anti_clockwise(uint8_t pwm) {
	if(cytron) {
		HAL_GPIO_WritePin(this->GPIOx_1, this->GPIO_Pin_1, GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin(this->GPIOx_1, this->GPIO_Pin_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(this->GPIOx_2, this->GPIO_Pin_2, GPIO_PIN_SET);
	}
	switch(this->Channel) {
	case TIM_CHANNEL_1:
		this->tim->CCR1 = pwm;
		break;
	case TIM_CHANNEL_2:
		this->tim->CCR2 = pwm;
		break;
	case TIM_CHANNEL_3:
		this->tim->CCR3 = pwm;
		break;
	case TIM_CHANNEL_4:
		this->tim->CCR4 = pwm;
		break;
	default:
		printf("\nErr.\n");
	}
}

void Motor::brake() {
	if(cytron) {
		HAL_GPIO_WritePin(this->GPIOx_1, this->GPIO_Pin_1, GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin(this->GPIOx_1, this->GPIO_Pin_1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(this->GPIOx_2, this->GPIO_Pin_2, GPIO_PIN_SET);
	}
	switch(this->Channel) {
	case TIM_CHANNEL_1:
		this->tim->CCR1 = 0;
		break;
	case TIM_CHANNEL_2:
		this->tim->CCR2 = 0;
		break;
	case TIM_CHANNEL_3:
		this->tim->CCR3 = 0;
		break;
	case TIM_CHANNEL_4:
		this->tim->CCR4 = 0;
		break;
	default:
		printf("\nErr.\n");
	}
}
