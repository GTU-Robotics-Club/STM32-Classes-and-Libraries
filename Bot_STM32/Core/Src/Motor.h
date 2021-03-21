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

#ifndef MOTOR_H
#define MOTOR_H

#include <stm32f1xx.h>
#include <stm32f103xb.h>
#include <stm32f1xx_hal_tim.h>

class Motor {
public:
	Motor();
	Motor(GPIO_TypeDef* GPIOx_1, uint16_t GPIO_Pin_1, TIM_HandleTypeDef *htim, uint32_t Channel, TIM_TypeDef *tim);
	Motor(GPIO_TypeDef* GPIOx_1, uint16_t GPIO_Pin_1, GPIO_TypeDef* GPIOx_2, uint16_t GPIO_Pin_2, TIM_HandleTypeDef *htim, uint32_t Channel, TIM_TypeDef *tim);
	void clockwise(uint8_t pwm);
	void anti_clockwise(uint8_t pwm);
	void brake();
private:
	GPIO_TypeDef* GPIOx_1;
	GPIO_TypeDef* GPIOx_2;
	uint16_t GPIO_Pin_1, GPIO_Pin_2;
	TIM_HandleTypeDef *htim;
	uint32_t Channel;
	TIM_TypeDef *tim;
	bool cytron;
};

#endif
