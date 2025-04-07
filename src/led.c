#include <stdio.h>
#include "led.h"
#include "gpio_hal.h"
#include "cfg.h"

void led_init(void)
{
    gpio_init();  // Ensure GPIO pins are set up
}

void led_update(float *temperature_c)
{
    gpio_pin_state_t green_state  = GPIO_PIN_RESET;
    gpio_pin_state_t yellow_state = GPIO_PIN_RESET;
    gpio_pin_state_t red_state    = GPIO_PIN_RESET;

    if (*temperature_c <  TEMP_THRESHOLD_LOW_C) {
        red_state = GPIO_PIN_SET;
    } else if (*temperature_c < TEMP_THRESHOLD_NORMAL_C) {
        green_state = GPIO_PIN_SET;
    } else if (*temperature_c < TEMP_THRESHOLD_HIGH_C) {
        yellow_state = GPIO_PIN_SET;
    } else {
        red_state = GPIO_PIN_SET;
    }

    gpio_write_pin(GPIO_PIN_LED_GREEN,  green_state);
    gpio_write_pin(GPIO_PIN_LED_YELLOW, yellow_state);
    gpio_write_pin(GPIO_PIN_LED_RED,    red_state);
}
