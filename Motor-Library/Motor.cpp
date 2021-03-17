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
#include "stm32f4xx.h"
#include <stdio.h>

Motor::Motor(GPIO_TypeDef *input_1_port, uint32_t input_1, TIM_HandleTypeDef *htim, TIM_TypeDef *TIM, uint32_t pwm_channel) {
	this->pwm_channel = pwm_channel;
	this->input_1_pin = input_1;
	this->input_1_port = input_1_port;
	this->cytron = true;
	this->TIM = TIM;
	HAL_GPIO_WritePin(input_1_port, input_1, GPIO_PIN_RESET);
	switch(pwm_channel) {
	case 1:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);
		TIM->CCR1 = 0;
		break;
	case 2:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_2);
		TIM->CCR2 = 0;
		break;
	case 3:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_3);
		TIM->CCR3 = 0;
		break;
	case 4:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_4);
		TIM->CCR4 = 0;
		break;
	default:
		printf("Error!\n");
	}
}

Motor::Motor(GPIO_TypeDef *input_1_port, uint32_t input_1, GPIO_TypeDef *input_2_port, uint32_t input_2, TIM_HandleTypeDef *htim, TIM_TypeDef *TIM, uint32_t pwm_channel) {
	this->pwm_channel = pwm_channel;
	this->input_1_pin = input_1;
	this->input_1_port = input_1_port;
	this->input_2_pin = input_2;
	this->input_2_port = input_2_port;
	this->cytron = false;
	HAL_GPIO_WritePin(input_1_port, input_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(input_2_port, input_2, GPIO_PIN_RESET);
	switch(pwm_channel) {
	case 1:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);
		TIM->CCR1 = 0;
		break;
	case 2:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_2);
		TIM->CCR2 = 0;
		break;
	case 3:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_3);
		TIM->CCR3 = 0;
		break;
	case 4:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_4);
		TIM->CCR4 = 0;
		break;
	default:
		printf("Error!\n");
	}
}

void Motor::clockwise(uint32_t pwm) {
	if(this->cytron == true) {
		HAL_GPIO_WritePin(input_1_port, input_1_pin, GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin(input_1_port, input_1_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(input_2_port, input_2_pin, GPIO_PIN_SET);
	}
	switch(pwm_channel) {
	case 1:
		TIM->CCR1 = pwm;
		break;
	case 2:
		TIM->CCR2 = pwm;
		break;
	case 3:
		TIM->CCR3 = pwm;
		break;
	case 4:
		TIM->CCR4 = pwm;
		break;
	default:
		printf("Error!\n");
	}
}

void Motor::anti_clockwise(uint32_t pwm) {
	if(this->cytron == true) {
		HAL_GPIO_WritePin(input_1_port, input_1_pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(input_1_port, input_1_pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(input_2_port, input_2_pin, GPIO_PIN_RESET);
	}
	switch(pwm_channel) {
	case 1:
		TIM->CCR1 = pwm;
		break;
	case 2:
		TIM->CCR2 = pwm;
		break;
	case 3:
		TIM->CCR3 = pwm;
		break;
	case 4:
		TIM->CCR4 = pwm;
		break;
	default:
		printf("Error!\n");
	}
}

void Motor::brake_motor() {
	if(this->cytron == true) {
		HAL_GPIO_WritePin(input_1_port, input_1_pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(input_1_port, input_1_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(input_2_port, input_2_pin, GPIO_PIN_RESET);
	}
	switch(pwm_channel) {
	case 1:
		TIM->CCR1 = 0;
		break;
	case 2:
		TIM->CCR2 = 0;
		break;
	case 3:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_3);
		TIM->CCR3 = 0;
		break;
	case 4:
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_4);
		TIM->CCR4 = 0;
		break;
	default:
		printf("Error!\n");
	}
}
