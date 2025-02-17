#ifndef ADC_HAL_H
#define ADC_HAL_H

#include <stdint.h>

/**
 * @brief Initialize the ADC driver (simulation or real).
 */
void adc_hal_init(void);

/**
 * @brief Trigger a conversion (if needed).
 *        In simulation, increments a mock value.
 *        In real hardware, might do a software start or rely on hardware triggers.
 */
void adc_hal_trigger_conversion(void);

/**
 * @brief Returns the most recent temprature ADC raw value.
 */
uint16_t adc_hal_get_temp_value_raw(void);

#endif /* ADC_HAL_H */
