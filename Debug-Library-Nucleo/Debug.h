#ifndef DEBUG_H
#define DEBUG_H

#include <string.h>
#include "stm32f1xx.h"

class Debug {
public:
	Debug(UART_HandleTypeDef* huart) {
		this->huart = huart;
	}
	void uprintf(char *str) {
		HAL_UART_Transmit(huart, (uint8_t *)str, strlen(str), 100);
	}
private:
	UART_HandleTypeDef* huart;
};

#endif
