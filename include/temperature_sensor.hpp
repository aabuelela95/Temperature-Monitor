#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#include <cstdint>

/**
 * @brief logic for reading an ADC value and converting it to temperature.
 */

class TemperatureSensor
{
public:
    static void init(uint8_t hwRev) noexcept;
    static float readTemperature(void) noexcept;

private:
    TemperatureSensor(void) noexcept;
    ~TemperatureSensor(void) noexcept;
    TemperatureSensor(const TemperatureSensor&) = delete;
    TemperatureSensor& operator=(const TemperatureSensor&) = delete;

    static uint8_t s_hwRevision;
};

#endif // TEMPERATURE_SENSOR_HPP
