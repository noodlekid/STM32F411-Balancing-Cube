#ifndef LED_H
#define LED_H

#include "stm32f411xe.h"

#include <stdint.h>

#define LED_PIN  13
#define LED_PORT GPIOC

void led_init(void);
void led_blink(void);

#endif // !LED_H
