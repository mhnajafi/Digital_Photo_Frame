/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f4xx_hal.h"

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
#define RAM_CKE_Pin GPIO_PIN_13
#define RAM_CKE_GPIO_Port GPIOC
#define RAM_CLK_Pin GPIO_PIN_14
#define RAM_CLK_GPIO_Port GPIOC
#define RAM_CS_Pin GPIO_PIN_15
#define RAM_CS_GPIO_Port GPIOC
#define RAM_RAS_Pin GPIO_PIN_0
#define RAM_RAS_GPIO_Port GPIOC
#define RAM_CAS_Pin GPIO_PIN_1
#define RAM_CAS_GPIO_Port GPIOC
#define RAM_WE_Pin GPIO_PIN_2
#define RAM_WE_GPIO_Port GPIOC
#define IN_TR_Pin GPIO_PIN_3
#define IN_TR_GPIO_Port GPIOC
#define RAM_A0_Pin GPIO_PIN_0
#define RAM_A0_GPIO_Port GPIOA
#define RAM_A1_Pin GPIO_PIN_1
#define RAM_A1_GPIO_Port GPIOA
#define RAM_A2_Pin GPIO_PIN_2
#define RAM_A2_GPIO_Port GPIOA
#define RAM_A3_Pin GPIO_PIN_3
#define RAM_A3_GPIO_Port GPIOA
#define RAM_A4_Pin GPIO_PIN_4
#define RAM_A4_GPIO_Port GPIOA
#define RAM_A5_Pin GPIO_PIN_5
#define RAM_A5_GPIO_Port GPIOA
#define RAM_A6_Pin GPIO_PIN_6
#define RAM_A6_GPIO_Port GPIOA
#define RAM_A7_Pin GPIO_PIN_7
#define RAM_A7_GPIO_Port GPIOA
#define IN_PH_Pin GPIO_PIN_4
#define IN_PH_GPIO_Port GPIOC
#define IN_UP_Pin GPIO_PIN_5
#define IN_UP_GPIO_Port GPIOC
#define IN_DN_Pin GPIO_PIN_0
#define IN_DN_GPIO_Port GPIOB
#define IN_OVL_Pin GPIO_PIN_1
#define IN_OVL_GPIO_Port GPIOB
#define IN_DO_Pin GPIO_PIN_2
#define IN_DO_GPIO_Port GPIOB
#define RAM_A10_Pin GPIO_PIN_10
#define RAM_A10_GPIO_Port GPIOB
#define RAM_A11_Pin GPIO_PIN_11
#define RAM_A11_GPIO_Port GPIOB
#define RAM_A12_Pin GPIO_PIN_12
#define RAM_A12_GPIO_Port GPIOB
#define RAM_A13_Pin GPIO_PIN_13
#define RAM_A13_GPIO_Port GPIOB
#define RAM_A14_Pin GPIO_PIN_14
#define RAM_A14_GPIO_Port GPIOB
#define RAM_A15_Pin GPIO_PIN_15
#define RAM_A15_GPIO_Port GPIOB
#define IN_A_Pin GPIO_PIN_8
#define IN_A_GPIO_Port GPIOD
#define IN_B_Pin GPIO_PIN_9
#define IN_B_GPIO_Port GPIOD
#define IN_C_Pin GPIO_PIN_10
#define IN_C_GPIO_Port GPIOD
#define IN_D_Pin GPIO_PIN_11
#define IN_D_GPIO_Port GPIOD
#define IN_E_Pin GPIO_PIN_12
#define IN_E_GPIO_Port GPIOD
#define IN_F_Pin GPIO_PIN_13
#define IN_F_GPIO_Port GPIOD
#define IN_G_Pin GPIO_PIN_14
#define IN_G_GPIO_Port GPIOD
#define IN___Pin GPIO_PIN_15
#define IN___GPIO_Port GPIOD
#define LCD_DE_Pin GPIO_PIN_6
#define LCD_DE_GPIO_Port GPIOC
#define LCD_VSY_Pin GPIO_PIN_7
#define LCD_VSY_GPIO_Port GPIOC
#define LCD_HSY_Pin GPIO_PIN_8
#define LCD_HSY_GPIO_Port GPIOA
#define LCD_DIS_Pin GPIO_PIN_9
#define LCD_DIS_GPIO_Port GPIOA
#define LCD_CLK_Pin GPIO_PIN_10
#define LCD_CLK_GPIO_Port GPIOA
#define LCD_BLK_Pin GPIO_PIN_11
#define LCD_BLK_GPIO_Port GPIOA
#define SW1_Pin GPIO_PIN_0
#define SW1_GPIO_Port GPIOD
#define SW2_Pin GPIO_PIN_1
#define SW2_GPIO_Port GPIOD
#define IN_10_Pin GPIO_PIN_7
#define IN_10_GPIO_Port GPIOD
#define RAM_A8_Pin GPIO_PIN_8
#define RAM_A8_GPIO_Port GPIOB
#define RAM_A9_Pin GPIO_PIN_9
#define RAM_A9_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
