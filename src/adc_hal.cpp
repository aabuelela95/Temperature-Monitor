#include "adc_hal.hpp"

volatile uint16_t AdcHal::s_lastValue = 0U;

AdcHal::AdcHal(void) noexcept
{
    // Constructor
}

AdcHal::~AdcHal(void) noexcept
{
    // Destructor
}

void AdcHal::init(void) noexcept
{
    // Configure ADC hardware: resolution, alignment, external trigger
}

void AdcHal::startConversion(void) noexcept
{
    // If There is no Timer trigger this would be called by the Timer ISR, otherwise it will be empty
}

uint16_t AdcHal::getValue(void) noexcept
{
    return s_lastValue;
}

void AdcHal::isrUpdate(uint16_t newValue) noexcept
{
    // Called by the hardware ADC interrupt
    s_lastValue = newValue;
}

// The actual ISR, should it be in a separate C file?
extern "C"
{
    void ADC_IRQHandler(void)
    {
        // read ADC data register
        uint16_t raw = 1234U;
        AdcHal::isrUpdate(raw);
        // clear EOC flag, etc.
    }
}
