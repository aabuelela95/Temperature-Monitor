#include "../include/i2c_hal.h"
#include <stdio.h>
#include <string.h>

void i2c_hal_init(void)
{
    // 1) Enable I2C clock
    // 2) Configure SCL/SDA pins
    // 3) Set bus speed
}

int i2c_hal_write(uint16_t mem_addr, const uint8_t *data, size_t length)
{
    // Write data from data buffer using I2C
    return 0;
}

int i2c_hal_read(uint16_t mem_addr, const uint8_t *data, size_t length)
{
    // read data using I2C
    return 0;
}
