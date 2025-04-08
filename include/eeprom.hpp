#ifndef EEPROM_HPP
#define EEPROM_HPP

#include <cstdint>

/**
 * @brief Class that reads config data (like hardware revision) from external EEPROM
 *        via i2c_hal..
 */

class Eeprom
{
public:
    static void init(void) noexcept;
    static uint8_t readHwRevision(void) noexcept;

private:
    Eeprom(void) noexcept;
    ~Eeprom(void) noexcept;
    /* Prevent copying */
    Eeprom(const Eeprom&) = delete;
    Eeprom& operator=(const Eeprom&) = delete;
};

#endif // EEPROM_HPP
