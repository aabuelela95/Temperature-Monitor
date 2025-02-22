#ifndef ADC_HAL_HPP
#define ADC_HAL_HPP

#include <cstdint>

/**
 * @brief ADC hardware abstraction layer 
 */
class AdcHal
{
public:
    static void init(void) noexcept;
    static void startConversion(void) noexcept;
    static uint16_t getValue(void) noexcept;

    /**
     * @brief Called by the actual ADC ISR to update the last reading.
     */
    static void isrUpdate(uint16_t newValue) noexcept;

private:
    AdcHal(void) noexcept;
    ~AdcHal(void) noexcept;
    AdcHal(const AdcHal&) = delete;
    AdcHal& operator=(const AdcHal&) = delete;

    static volatile uint16_t s_lastValue;
};

#endif // ADC_HAL_HPP
