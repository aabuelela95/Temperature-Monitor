#ifndef LED_HPP
#define LED_HPP

#include <cstdint>

/**
 * @brief LED domain logic: deciding which LED to light based on temperature.
 */

class LedDriver
{
public:
    static void init(void) noexcept;
    static void update(float temperature) noexcept;

private:
    LedDriver(void) noexcept;
    ~LedDriver(void) noexcept;
    LedDriver(const LedDriver&) = delete;
    LedDriver& operator=(const LedDriver&) = delete;
};

#endif // LED_HPP
