#include "../include/temperature_sensor.hpp"
#include "../include/adc_hal.hpp"
#include "../include/cfg.hpp"

uint8_t TemperatureSensor::s_hwRevision = 0U;

TemperatureSensor::TemperatureSensor(void) noexcept
{
    // constructor
}
TemperatureSensor::~TemperatureSensor(void) noexcept
{
    // destructor
}

void TemperatureSensor::init(uint8_t hwRev) noexcept
{
    s_hwRevision = hwRev;
}

float TemperatureSensor::readTemperature(void) noexcept
{
    uint16_t raw = AdcHal::getValue();
    float tempC = 0.0F;

    if (s_hwRevision == HW_REV_A)
    {
        // 1°C per digit
        tempC = static_cast<float>(raw);
    }
    else
    {
        // 0.1°C per digit
        tempC = static_cast<float>(raw) * 0.1F;
    }

    return tempC;
}
