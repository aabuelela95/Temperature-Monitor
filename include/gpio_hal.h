#ifndef GPIO_HAL_H
#define GPIO_HAL_H

#include <stdint.h>

typedef enum {
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET
} gpio_pin_state_t;

/**
 * @brief Logical IDs for each GPIO we care about.
 */
typedef enum {
    GPIO_PIN_LED_GREEN = 0,
    GPIO_PIN_LED_YELLOW,
    GPIO_PIN_LED_RED,
    // etc.
    GPIO_PIN_COUNT
} gpio_pin_id_t;

/**
 * @brief Initialize all relevant GPIO pins (clocks, directions, etc.).
 */
void gpio_init(void);

/**
 * @brief Write a state (SET or RESET) to a specific pin ID.
 */
void gpio_write_pin(gpio_pin_id_t pin_id, gpio_pin_state_t state);

#endif /* GPIO_HAL_H */
