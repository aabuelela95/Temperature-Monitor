#ifndef I2C_HAL_H
#define I2C_HAL_H

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Initialize the I2C hardware.
 */
void i2c_hal_init(void);

/**
 * @brief Send data over I2c
 * @param 
 */
int i2c_hal_write(uint16_t mem_addr, const uint8_t *data, size_t length);

/**
 * @brief Read data over I2c
 * @param 
 */
int i2c_hal_read(uint16_t mem_addr, const uint8_t *data, size_t length);

#endif /* I2C_HAL_H */
