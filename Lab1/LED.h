#ifndef __STM32L476G_DISCOVERY_LED_H
#define __STM32L476G_DISCOVERY_LED_H

#include "stm32l476xx.h"

void LED_Init(void);

void PB2_Off(void);
void PB2_On(void);
void PB2_Toggle(void);

void PE8_On(void);
void PE8_Off(void);
void PE8_Toggle(void);

void PA0_On(void);
void PA0_Off(void);
void PA0_Toggle(void);

void PB3_On(void);
void PB3_Off(void);
void PB3_Toggle(void);

void PA5_On(void);
void PA5_Off(void);
void PA5_Toggle(void);

void PA1_On(void);
void PA1_Off(void);
void PA1_Toggle(void);

void PA2_On(void);
void PA2_Off(void);
void PA2_Toggle(void);

void PA3_On(void);
void PA3_Off(void);
void PA3_Toggle(void);

void PB6_On(void);
void PB6_Off(void);
void PB6_Toggle(void);

void PB7_On(void);
void PB7_Off(void);
void PB7_Toggle(void);
void Stream(uint32_t);
void Stream_1(uint32_t);
#endif /* __STM32L476G_DISCOVERY_LED_H */
