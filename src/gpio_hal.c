#include "gpio_hal.h"
#include <stdio.h>


void gpio_init(void)
{
    /*
 * Initialize port and pin numbers needed.
 * Configure pins direction
 */

}

void gpio_write_pin(gpio_pin_id_t pin_id, gpio_pin_state_t state)
{
    /* Write the respective pin */
    const char *pin_name = "";
    switch(pin_id) {
    case GPIO_PIN_LED_GREEN:  pin_name = "LED_GREEN";  break;
    case GPIO_PIN_LED_YELLOW: pin_name = "LED_YELLOW"; break;
    case GPIO_PIN_LED_RED:    pin_name = "LED_RED";    break;
    default:                  pin_name = "UNKNOWN";    break;
    }

    printf("[GPIO_HAL] Write %s = %s\n", pin_name, (state == GPIO_PIN_SET) ? "SET" : "RESET");
}
