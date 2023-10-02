#include "tim.h"

TIM_HandleTypeDef htim16;

void MX_TIM16_Init(void) {
	htim16.Instance = TIM16;
	htim16.Init.Prescaler = (4800-1); // 10Khz 100 us pr tick	
	htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim16.Init.Period = 65535;
	htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim16.Init.RepetitionCounter = 0;
	htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim16) != HAL_OK) {
		Error_Handler();
	}
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *tim_baseHandle) {

	if (tim_baseHandle->Instance == TIM16) {
		__HAL_RCC_TIM16_CLK_ENABLE();
	}
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *tim_baseHandle) {

	if (tim_baseHandle->Instance == TIM16) {
		__HAL_RCC_TIM16_CLK_DISABLE();
	}
}
