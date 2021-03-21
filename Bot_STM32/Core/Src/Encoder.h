/**
*
* Class for Encoder
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
#ifndef ENCODER_H
#define ENCODER_H

/** Change it according to your board. */
#include <stm32f1xx.h>
#include <stm32f1xx_hal_tim.h>
/**
* This class contains two constructor, if the default value of Counter Period is 65535, just pass the timer's address
* Else use the second constructor, and pass the Counter Period.
* 
* Functions : 
* Read - Returns a long value, can be either positive or negative
* Write - To write a value to the encoder.
*/
class Encoder {
public:
	Encoder(TIM_HandleTypeDef *htim);
	Encoder(TIM_HandleTypeDef *htim, uint32_t prescaler_);
	void write(long value);
	long read();
private:
	uint8_t direction;
	long counter = 0;
	uint32_t value = 0;
	TIM_HandleTypeDef *htim;
	uint32_t prescaler_;
	int counter_s = 0;
	bool init = true;
};

#endif
