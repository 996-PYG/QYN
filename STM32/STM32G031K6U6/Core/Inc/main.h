/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

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
#define MCU_SYS_LED_Pin GPIO_PIN_9
#define MCU_SYS_LED_GPIO_Port GPIOB
#define SPI_BOOT_CTRL_Pin GPIO_PIN_1
#define SPI_BOOT_CTRL_GPIO_Port GPIOA
#define M_BOOT_CTRL_Pin GPIO_PIN_4
#define M_BOOT_CTRL_GPIO_Port GPIOA
#define MCU_STB_LED_Pin GPIO_PIN_6
#define MCU_STB_LED_GPIO_Port GPIOA
#define CPU_RST_INT_Pin GPIO_PIN_7
#define CPU_RST_INT_GPIO_Port GPIOA
#define PMIC_VDC_Pin GPIO_PIN_0
#define PMIC_VDC_GPIO_Port GPIOB
#define MCU_NMI_Pin GPIO_PIN_1
#define MCU_NMI_GPIO_Port GPIOB
#define RTC_INT_L_Pin GPIO_PIN_2
#define RTC_INT_L_GPIO_Port GPIOB
#define FORCE_RST_Pin GPIO_PIN_8
#define FORCE_RST_GPIO_Port GPIOA
#define FAN_PWM_Pin GPIO_PIN_9
#define FAN_PWM_GPIO_Port GPIOA
#define MCU_IR_IN_Pin GPIO_PIN_6
#define MCU_IR_IN_GPIO_Port GPIOC
#define PMIC_EXT_EN_IN_Pin GPIO_PIN_15
#define PMIC_EXT_EN_IN_GPIO_Port GPIOA
#define MCU_FUNC_Pin GPIO_PIN_3
#define MCU_FUNC_GPIO_Port GPIOB
#define MCU_PWR_KEY_Pin GPIO_PIN_4
#define MCU_PWR_KEY_GPIO_Port GPIOB
#define MCU_PWR_LED_Pin GPIO_PIN_5
#define MCU_PWR_LED_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
