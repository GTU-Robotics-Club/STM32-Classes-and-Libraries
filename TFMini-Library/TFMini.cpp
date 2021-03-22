/**
*
* Class for TFMini
*
* cpp file
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

#include "TFMini.h"

TFMini::TFMini(UART_HandleTypeDef* huart) {
	this->huart = huart;
	HAL_UART_Receive(this->huart, data, 9, 1000);
	if(data[0] == TFMINI_HEADER) {
		this->tfmini_alive = true;
	} else {
		this->tfmini_alive = false;
	}
}

void TFMini::calculate() {
	HAL_UART_Receive(huart, data, 9, 1000);
	check = data[0] + data[1] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7];
	if(data[8] == (check & 0xff)) {
		this->distance = data[2] + data[3] * 256;
		this->strength = data[4] + data[5] * 256;
	}
}

uint16_t TFMini::get_distance() {
	this->calculate();
	return this->distance;
}

int TFMini::get_strength() {
	this->calculate();
	return this->strength;
}
