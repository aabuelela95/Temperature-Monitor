#ifndef I2C_HAL_HPP
#define I2C_HAL_HPP

#include <cstdint>
#include <cstddef>

/**
 * @brief I2C HAL for external devices like EEPROM. 
 */

class I2cHal
{
public:
    static void init(void) noexcept;
    static bool write(uint16_t memAddr, const uint8_t* data, std::size_t length) noexcept;
    static bool read(uint16_t memAddr, uint8_t* data, std::size_t length) noexcept;

private:
    I2cHal(void) noexcept;
    ~I2cHal(void) noexcept;
    /* Prevent copying */
    I2cHal(const I2cHal&) = delete;
    I2cHal& operator=(const I2cHal&) = delete;
};

#endif // I2C_HAL_HPP
