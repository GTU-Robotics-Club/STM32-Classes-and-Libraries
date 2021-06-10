/*
 * Cytron.h
 *
 *  Created on: Jun 11, 2021
 *      Author: alpharomeo911
 *      This is the header file for cytron, this library is intended to use
 *      for operating cytron in serial packetized mode only.
 *
 *  To-Do:
 *  	1. Make this library compatible with Serial Simplified
 *  	2. Make this library compatible with Microcontroller Analog/PWM mode
 *
 *  ** Remember to configure the DIP switches! **
 */

#ifndef INC_CYTRON_H_
#define INC_CYTRON_H_

/*
 * The includes related to this class are below,
 * This library was created while testing STM32F4XX Series,
 * so, in order to make this library compatible with your board,
 * just change the #include "stm32fxxx" to your board.
 *
 * In case you find any difficulties, you can contact me :
 * https://github.com/alpharomeo911
 *
 * Also I've tried to explain the code thoroughly in the .cpp file.
 */

#include "stm32f4xx.h"
#include "stm32f4xx_hal_uart.h"

#define DUMMY_BIT 128
#define HEADER 85
#define INPUT_START 0
#define INPUT_END 255
#define ZERO_POINT 127
#define CLOCKWISE 255
#define ANTI_CLOCKWISE 0

class Cytron {
public:
	Cytron(UART_HandleTypeDef* huart, uint8_t address, uint8_t channel);

	void send_dummy_bit(void);
	void clockwise(uint8_t pwm);
	void anti_clockwise(uint8_t pwm);
	void brake();

private:
	UART_HandleTypeDef* huart;
	uint8_t address;
	uint8_t channel;
	uint8_t packet[4] = {HEADER, 0, 0, 0};
	uint8_t dummy_bit = DUMMY_BIT;
	void send_data(uint8_t pwm);
};





#endif /* INC_CYTRON_H_ */
