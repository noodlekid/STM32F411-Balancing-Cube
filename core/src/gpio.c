#include "gpio.h"
#include "stm32f411xe.h"

void gpio_init()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}
