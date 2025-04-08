#ifndef GPIO_HAL_HPP
#define GPIO_HAL_HPP

#include <cstdint>

/**
 * @brief GPIO HAL for LED pins. In real HW, config pins as output, set them, etc.
 */

class GpioHal
{
public:
    enum class PinState : uint8_t
    {
        Low = 0U,
        High = 1U
    };

    static void initLedPins(void) noexcept;
    static void setLedGreen(PinState state) noexcept;
    static void setLedYellow(PinState state) noexcept;
    static void setLedRed(PinState state) noexcept;

private:
    GpioHal(void) noexcept;
    ~GpioHal(void) noexcept;
    /* Prevent copying */
    GpioHal(const GpioHal&) = delete;
    GpioHal& operator=(const GpioHal&) = delete;
};

#endif // GPIO_HAL_HPP
