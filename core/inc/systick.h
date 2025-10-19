#ifndef SYSTICK_H
#define SYSTICK_H

#include "stm32f411xe.h"

#include <stdint.h>

extern uint32_t SystemCoreClock;

static inline void systick_init()
{
    SysTick->CTRL = 0;
    SysTick->LOAD = (SystemCoreClock / 1000) - 1;
    SysTick->VAL = 0;
    SysTick->CTRL = (1U << 0) | (1U << 2);
}

static inline void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++) {
        SysTick->CTRL;
        while (!(SysTick->CTRL & (1U << 16)))
            ;
    }
}

#endif /* !SYSTICK_H */
