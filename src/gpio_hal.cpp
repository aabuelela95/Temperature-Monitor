#include "gpio_hal.hpp"

GpioHal::GpioHal(void) noexcept
{
    // constructor
}

GpioHal::~GpioHal(void) noexcept
{
    // destructor
}

void GpioHal::initLedPins(void) noexcept
{
    // Configure the LED pins as output in real hardware
}

void GpioHal::setLedGreen(PinState state) noexcept
{
    // Set or clear the green LED pin
    (void)state;
}

void GpioHal::setLedYellow(PinState state) noexcept
{
    // Yellow
    (void)state;
}

void GpioHal::setLedRed(PinState state) noexcept
{
    // Red
    (void)state;
}
