/**
*
* Class for Encoder
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
#include "Encoder.h"

Encoder::Encoder(TIM_HandleTypeDef *htim) {
	this->htim = htim;
	HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
	this->htim->Instance->CNT = 0;
	this->direction = !(__HAL_TIM_IS_TIM_COUNTING_DOWN(htim));
	this->value = this->htim->Instance->CNT;
	this->prescaler_ = 65535;
}

Encoder::Encoder(TIM_HandleTypeDef *htim, uint32_t prescaler_) {
	this->htim = htim;
	HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
	this->htim->Instance->CNT = 0;
	this->direction = !(__HAL_TIM_IS_TIM_COUNTING_DOWN(htim));
	this->value = this->htim->Instance->CNT;
	this->prescaler_ = prescaler_;
}

void Encoder::write(long int value) {
	this->htim->Instance->CNT = 0;
}

long Encoder::read() {
	uint32_t prev_encoder_value = this->value;
	uint8_t prev_direction = this->direction;
	this->direction = !(__HAL_TIM_IS_TIM_COUNTING_DOWN(htim));
	this->value = this->htim->Instance->CNT;
	if(this->direction) {
		if(prev_encoder_value > value) {
			this->counter_s++;
		}
		this->counter = this->prescaler_ * this->counter_s + value;
	}  else if (!(this->direction) && (prev_direction == this->direction)) {
		if(prev_encoder_value < value) {
			this->counter_s--;
		}
		this->counter = this->prescaler_ * this->counter_s + value;
	}
	return counter;
}
