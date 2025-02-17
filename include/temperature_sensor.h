#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "eeprom.h"
#include <stdint.h>

/**
 * @brief Initialize the temperature sensor.
 */
void temperature_sensor_init(void);

/**
 * @brief Read a raw ADC value from the sensor.
 */
uint16_t temperature_sensor_read_adc(void);

/**
 * @brief Convert a raw ADC value to °C, factoring in hardware revision.
 */
float temperature_sensor_to_celsius(uint16_t raw_adc, hw_revision_t rev);

#endif /* TEMPERATURE_SENSOR_H */
