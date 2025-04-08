#include "i2c_hal.hpp"

I2cHal::I2cHal(void) noexcept
{
    // private
}
I2cHal::~I2cHal(void) noexcept
{
    // private
}

void I2cHal::init(void) noexcept
{
    // For real hardware, enable I2C clock, set SCL/SDA pins, etc.
}

bool I2cHal::write(uint16_t memAddr, const uint8_t* data, std::size_t length) noexcept
{ 
    (void)memAddr; 
    (void)data; 
    (void)length;
    // Real code: send start, memAddr, data bytes
    return true; 
}

bool I2cHal::read(uint16_t memAddr, uint8_t* data, std::size_t length) noexcept
{ 
    (void)memAddr; 
    (void)data; 
    (void)length;
    // Real code: start, memAddr, read
    return true;
}
