#include "adc_hal.h"
#include <stdio.h>

// Store the last ADC reading in a static variable for easy retrieval.
static uint16_t s_adc_last_value = 0;

// If we are in simulation mode, define mock behavior. Otherwise, we do real hardware.
#ifdef USE_ADC_SIM

// For simulation, we just cycle a mock ADC value
static uint16_t s_mock_adc_val = 0;

void adc_hal_init(void)
{
    s_mock_adc_val = 0;
}

void adc_hal_trigger_conversion(void)
{
    // Simulation: pretend to read the sensor
    uint16_t val = s_mock_adc_val;
    s_mock_adc_val = (s_mock_adc_val + 1) % 201;
    
    // Store in s_adc_last_value
    s_adc_last_value = val;
}

uint16_t adc_hal_get_temp_value_raw(void)
{
    return s_adc_last_value;
}

#else  // USE_ADC_SIM not defined => REAL HARDWARE

/*
 * REAL HARDWARE EXAMPLE: Using an EOC Interrupt
 * 
 * 1) We configure the ADC for interrupt-driven mode (external trigger from Timer).
 * 2) When the ADC finishes conversion, it sets an EOC flag and calls an ISR.
 * 3) That ISR reads the data register and stores it in s_adc_last_value.
 */
void adc_hal_init(void)
{
    printf("[ADC_HAL] init in REAL HARDWARE mode.\n");
    // pseudo-code:
    /*
    // 1) Enable ADC clock
    // 2) Configure resolution, alignment
    // 3) Configure external trigger from Timer if desired
    // 4) Enable EOC interrupt ISR
    */
    
    s_adc_last_value = 0;
}

void adc_hal_trigger_conversion(void)
{
    // NOT NEEDED IN HW just to compile
}

// We read from our static variable (updated in the ISR).
uint16_t adc_hal_get_temp_value_raw(void)
{
    return s_adc_last_value;
}

/**
 * @brief The actual ISR that the hardware calls
 *        when the ADC finishes a conversion.
 *        The name should match that in the ISR vector table
 */
void ADC_IRQHandler(void)
{
    // 1) Check if EOC is set
    // 2) read the data from register into s_adc_last_value;
    // 3) clear the EOC flag
}
#endif // USE_ADC_SIM
 
