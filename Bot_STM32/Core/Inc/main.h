/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PUSH_BUTTON_1_Pin GPIO_PIN_14
#define PUSH_BUTTON_1_GPIO_Port GPIOC
#define PUSH_BUTTON_2_Pin GPIO_PIN_15
#define PUSH_BUTTON_2_GPIO_Port GPIOC
#define EN_11_Pin GPIO_PIN_0
#define EN_11_GPIO_Port GPIOA
#define EN_12_Pin GPIO_PIN_1
#define EN_12_GPIO_Port GPIOA
#define EN_21_Pin GPIO_PIN_6
#define EN_21_GPIO_Port GPIOA
#define EN_22_Pin GPIO_PIN_7
#define EN_22_GPIO_Port GPIOA
#define C5_Pin GPIO_PIN_10
#define C5_GPIO_Port GPIOB
#define C1_Pin GPIO_PIN_8
#define C1_GPIO_Port GPIOA
#define C2_Pin GPIO_PIN_9
#define C2_GPIO_Port GPIOA
#define C3_Pin GPIO_PIN_10
#define C3_GPIO_Port GPIOA
#define C4_Pin GPIO_PIN_11
#define C4_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_13
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_14
#define LED_2_GPIO_Port GPIOA
#define LED_3_Pin GPIO_PIN_15
#define LED_3_GPIO_Port GPIOA
#define C8_Pin GPIO_PIN_3
#define C8_GPIO_Port GPIOB
#define C6_Pin GPIO_PIN_4
#define C6_GPIO_Port GPIOB
#define C7_Pin GPIO_PIN_5
#define C7_GPIO_Port GPIOB
#define SCL_MPU_Pin GPIO_PIN_8
#define SCL_MPU_GPIO_Port GPIOB
#define SDA_MPU_Pin GPIO_PIN_9
#define SDA_MPU_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
