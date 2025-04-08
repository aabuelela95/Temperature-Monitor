#include "led.hpp"
#include "gpio_hal.hpp"
#include "cfg.hpp"

LedDriver::LedDriver(void) noexcept
{
    // constructor
}
LedDriver::~LedDriver(void) noexcept
{
    // destructor
}

void LedDriver::init(void) noexcept
{
    GpioHal::initLedPins();
}

void LedDriver::update(float temperature) noexcept
{
    // threshold logic
    if (temperature < TEMP_THRESHOLD_LOW_C)
    {
        GpioHal::setLedGreen(GpioHal::PinState::Low);
        GpioHal::setLedYellow(GpioHal::PinState::Low);
        GpioHal::setLedRed(GpioHal::PinState::High);
    }
    else if (temperature < TEMP_THRESHOLD_NORMAL_C)
    {
        GpioHal::setLedGreen(GpioHal::PinState::High);
        GpioHal::setLedYellow(GpioHal::PinState::Low);
        GpioHal::setLedRed(GpioHal::PinState::Low);
    }
    else if (temperature < TEMP_THRESHOLD_HIGH_C)
    {
        GpioHal::setLedGreen(GpioHal::PinState::Low);
        GpioHal::setLedYellow(GpioHal::PinState::High);
        GpioHal::setLedRed(GpioHal::PinState::Low);
    }
    else
    {
        GpioHal::setLedGreen(GpioHal::PinState::Low);
        GpioHal::setLedYellow(GpioHal::PinState::Low);
        GpioHal::setLedRed(GpioHal::PinState::High);
    }
}
