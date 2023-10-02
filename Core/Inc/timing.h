#ifndef INC_TIMING_H_
#define INC_TIMING_H_

#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include <stdio.h>

#define HUART huart2

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE {
	HAL_UART_Transmit(&HUART, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}

#define HTIM htim16
#define TIME_MEASURE_US(func)                                \
{                                                         \
    HAL_TIM_Base_Start(&HTIM);                            \
    uint16_t timer_val = __HAL_TIM_GET_COUNTER(&HTIM);    \
    func;                                                 \
    timer_val = __HAL_TIM_GET_COUNTER(&HTIM) - timer_val; \
    	HAL_TIM_Base_Stop(&HTIM);                         \
    printf(#func ": %ld us\r\n", (timer_val*100));               \
}



#endif /* INC_TIMING_H_ */
