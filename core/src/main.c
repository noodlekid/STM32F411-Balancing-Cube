#include "gpio.h"
#include "led.h"
#include "systick.h"

int main(void)
{
    systick_init();
    gpio_init();
    led_init();

    while (1) {
        led_blink();
    }

    return 0;
}
