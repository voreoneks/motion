/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for
  *                      the gpio
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
	 
#define LD_PORT GPIOE

#define LD3 LL_GPIO_PIN_9 //RED1

#define LD4 LL_GPIO_PIN_8 //BLUE1

#define LD5 LL_GPIO_PIN_10 //ORANGE1

#define LD6 LL_GPIO_PIN_15 //GREEN1

#define LD7 LL_GPIO_PIN_11 //GREEN2

#define LD8 LL_GPIO_PIN_14 //ORANGE2

#define LD9 LL_GPIO_PIN_12 //BLUE2

#define LD10 LL_GPIO_PIN_13 //RED2

#define LD3_ON LL_GPIO_(LD_PORT, LD3, GPIO_PIN_SET) //RED1

#define LD4_ON LL_GPIO_SetOutputPin(LD_PORT, LD4) //BLUE1

#define LD5_ON LL_GPIO_SetOutputPin(LD_PORT, LD5) //ORANGE1

#define LD6_ON LL_GPIO_SetOutputPin(LD_PORT, LD6) //GREEN1

#define LD7_ON LL_GPIO_SetOutputPin(LD_PORT, LD7) //GREEN2

#define LD8_ON LL_GPIO_SetOutputPin(LD_PORT, LD8) //ORANGE2

#define LD9_ON LL_GPIO_SetOutputPin(LD_PORT, LD9) //BLUE2

#define LD10_ON LL_GPIO_SetOutputPin(LD_PORT, LD10) //RED2

#define LD3_OFF LL_GPIO_ResetOutputPin(LD_PORT, LD3) //RED1

#define LD4_OFF LL_GPIO_ResetOutputPin(LD_PORT, LD4) //BLUE1

#define LD5_OFF LL_GPIO_ResetOutputPin(LD_PORT, LD5) //ORANGE1

#define LD6_OFF LL_GPIO_ResetOutputPin(LD_PORT, LD6) //GREEN1

#define LD7_OFF LL_GPIO_ResetOutputPin(LD_PORT, LD7) //GREEN2

#define LD8_OFF LL_GPIO_ResetOutputPinn(LD_PORT, LD8) //ORANGE2

#define LD9_OFF LL_GPIO_ResetOutputPin(LD_PORT, LD9) //BLUE2

#define LD10_OFF LL_GPIO_ResetOutputPin(LD_PORT, LD10) //RED2
	 
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
