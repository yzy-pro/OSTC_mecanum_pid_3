/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define D_ENCODER_1_Pin GPIO_PIN_0
#define D_ENCODER_1_GPIO_Port GPIOA
#define D_ENCODER_2_Pin GPIO_PIN_1
#define D_ENCODER_2_GPIO_Port GPIOA
#define B_ENCODER_1_Pin GPIO_PIN_6
#define B_ENCODER_1_GPIO_Port GPIOA
#define B_ENCODER_2_Pin GPIO_PIN_7
#define B_ENCODER_2_GPIO_Port GPIOA
#define A_MOTOR_1_Pin GPIO_PIN_9
#define A_MOTOR_1_GPIO_Port GPIOE
#define A_MOTOR_2_Pin GPIO_PIN_11
#define A_MOTOR_2_GPIO_Port GPIOE
#define B_MOTOR_1_Pin GPIO_PIN_13
#define B_MOTOR_1_GPIO_Port GPIOE
#define B_MOTOR_2_Pin GPIO_PIN_14
#define B_MOTOR_2_GPIO_Port GPIOE
#define C_ENCODER_1_Pin GPIO_PIN_12
#define C_ENCODER_1_GPIO_Port GPIOD
#define C_ENCODER_2_Pin GPIO_PIN_13
#define C_ENCODER_2_GPIO_Port GPIOD
#define C_MOTOR_1_Pin GPIO_PIN_6
#define C_MOTOR_1_GPIO_Port GPIOC
#define C_MOTOR_2_Pin GPIO_PIN_7
#define C_MOTOR_2_GPIO_Port GPIOC
#define D_MOTOR_1_Pin GPIO_PIN_8
#define D_MOTOR_1_GPIO_Port GPIOC
#define D_MOTOR_2_Pin GPIO_PIN_9
#define D_MOTOR_2_GPIO_Port GPIOC
#define A_ENCODER_1_Pin GPIO_PIN_15
#define A_ENCODER_1_GPIO_Port GPIOA
#define A_ENCODER_2_Pin GPIO_PIN_3
#define A_ENCODER_2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define A_B_MOTOR_TIM htim1
#define C_D_MOTOR_TIM htim8

#define A_ENCODER_TIM htim2
#define B_ENCODER_TIM htim3
#define C_ENCODER_TIM htim4
#define D_ENCODER_TIM htim5
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
