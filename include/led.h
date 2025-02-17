#ifndef LED_H
#define LED_H

/**
 * @brief Initialize the LED hardware (GPIOs).
 */
void led_init(void);

/**
 * @brief Update LED states based on the current temperature (°C).
 *        - Red if < TEMP_THRESHOLD_LOW or >= TEMP_THRESHOLD_YELLOW
 *        - Green if [TEMP_THRESHOLD_LOW .. TEMP_THRESHOLD_GREEN)
 *        - Yellow if [TEMP_THRESHOLD_GREEN .. TEMP_THRESHOLD_YELLOW)
 */
void led_update(float *temperatureC);

#endif /* LED_H */
