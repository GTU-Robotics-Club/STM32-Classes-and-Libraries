/**
*
* Class for TFMini
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

#ifndef TFMINI_H
#define TFMINI_H

#include "stm32f4xx.h"
#define TFMINI_HEADER 0x59

class TFMini {
public:
	TFMini(UART_HandleTypeDef* huart);
	uint16_t get_distance();
	int get_strength();
	void calculate();
private:
	int check;
	UART_HandleTypeDef* huart;
	uint8_t data[9];
	uint16_t distance;
	int strength;
	bool tfmini_alive = false;
};

#endif
