#include <stdio.h>
#include "temperature_sensor.h"
#include "adc_hal.h"


// For demonstration, a mock incremental ADC value
static uint16_t s_mock_adc_val = 0;

void temperature_sensor_init(void)
{
    // If needed
}

uint16_t temperature_sensor_read_adc(void)
{
    uint16_t val = adc_hal_get_temp_value_raw();
    return val;
}

float temperature_sensor_to_celsius(uint16_t raw_adc, hw_revision_t rev)
{
    switch(rev) {
        case HW_REV_A: return (float)raw_adc;         // 1 °C per digit
        case HW_REV_B: return (float)raw_adc * 0.1f;  // 0.1 °C per digit
        default:       return 0.0f;
    }
}
