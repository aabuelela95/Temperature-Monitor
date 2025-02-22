#include "../include/eeprom.hpp"
#include "../include/i2c_hal.hpp"

Eeprom::Eeprom(void) noexcept
{
    // Constructor
}
Eeprom::~Eeprom(void) noexcept
{
    // Destructor
}

void Eeprom::init(void) noexcept
{
    // Initialize I2C
    I2cHal::init();
}

uint8_t Eeprom::readHwRevision(void) noexcept
{
    // read from a known location in the EEPROM
    // For now, just a placeholder returning 0 => Rev-A
    return 0U;
}
