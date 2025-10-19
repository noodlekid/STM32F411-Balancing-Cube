#include "led.h"
#include "systick.h"

void led_init(void)
{
    // output mode
    LED_PORT->MODER |= (1U << (LED_PIN * 2));

    // push-pull
    LED_PORT->OTYPER &= ~(1U << LED_PIN);

    // med Speed
    LED_PORT->OSPEEDR |= (1U << (LED_PIN * 2));

    // assert reset
    LED_PORT->BSRR |= (1U << LED_PIN);
}

void led_blink(void)
{
    LED_PORT->BSRR |= (1U << (LED_PIN + 16));
    delay_ms(500);
    LED_PORT->BSRR |= (1U << LED_PIN);
    delay_ms(500);
}
