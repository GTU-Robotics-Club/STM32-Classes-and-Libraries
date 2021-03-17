/**
 *
 * Class for motors
 *
 * Header file
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

#ifndef Motor_h
#define Motor_h
#include "stm32f4xx.h"
#include "stm32f4xx_hal_tim.h"

class Motor {
public:
	// Constructors
	Motor();
	Motor(GPIO_TypeDef *input_1_port, uint32_t input_1, TIM_HandleTypeDef *htim, TIM_TypeDef *TIM, uint32_t pwm_channel);
	Motor(GPIO_TypeDef *input_1_port, uint32_t input_1, GPIO_TypeDef *input_2_port, uint32_t input_2, TIM_HandleTypeDef *htim, TIM_TypeDef *TIM, uint32_t pwm_channel);
	// Methods
	void clockwise(uint32_t pwm);
	void anti_clockwise(uint32_t pwm);
	void brake_motor();
private:
	GPIO_InitTypeDef GPIO_initStruct = {0};
	GPIO_TypeDef *input_1_port, *input_2_port;
	TIM_HandleTypeDef *htim;
	TIM_TypeDef *TIM;
	uint32_t input_1_pin, input_2_pin, pwm_channel;
	bool cytron;
};
#endif
