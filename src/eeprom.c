#include "../include/eeprom.h"
#include "../include/i2c_hal.h"  // Now we rely on the I2C HAL
#include <string.h>
#include <stdio.h>

#define EEPROM_REV_ADDR   0x0000  // Byte storing revision
#define EEPROM_SERIAL_ADDR 0x0001 // Start address for serial

// Mock storage
static hw_revision_t s_mock_revision = HW_REV_A;
static char s_mock_serial[EEPROM_SERIAL_MAX_LEN] = "ABC1234";

void eeprom_init(void)
{
    i2c_hal_init();  // Initialize I2C.
}

hw_revision_t eeprom_read_revision(void)
{
    
    uint8_t buf;
    int ret = i2c_hal_read(EEPROM_REV_ADDR, &buf, 1);

    // Simulation: just return s_mock_revision
    return s_mock_revision;
}

void eeprom_read_serial_number(char *dest, size_t len)
{
    // Simulation
    strncpy(dest, s_mock_serial, len);
    dest[len - 1] = '\0';

    
    // Real hardware: read from I2C
    // EEPROM_SERIAL_ADDR is start, length is up to EEPROM_SERIAL_MAX_LEN
    uint8_t buf[EEPROM_SERIAL_MAX_LEN];
    if (len > EEPROM_SERIAL_MAX_LEN) { 
        len = EEPROM_SERIAL_MAX_LEN; 
    }
    int ret = i2c_hal_read(EEPROM_SERIAL_ADDR, buf, len);
    //memcpy(dest, buf, len);
    //dest[len - 1] = '\0';
}

#ifdef CFG_MODE
void eeprom_set_revision(hw_revision_t rev)
{
    s_mock_revision = rev;

    // Real hardware: write 1 byte => 0 for REV_A, 1 for REV_B
    uint8_t val = (rev == HW_REV_B) ? 1 : 0;
    i2c_hal_write(EEPROM_REV_ADDR, &val, 1);
}
#else
void eeprom_set_revision(hw_revision_t rev)       { (void)rev; }
#endif
