#ifndef EEPROM_H
#define EEPROM_H

#include <stddef.h>
#include <stdint.h>

#define EEPROM_SERIAL_MAX_LEN 16

typedef enum {
    HW_REV_A = 0,
    HW_REV_B
} hw_revision_t;

void eeprom_init(void);
hw_revision_t eeprom_read_revision(void);
void eeprom_read_serial_number(char *dest, size_t len);

// This is only in cfg mode
void eeprom_set_revision(hw_revision_t rev);

#endif /* EEPROM_H */
