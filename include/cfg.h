#ifndef CFG_H
#define CFG_H

#include "eeprom.h" 

// Timer period for temperature sampling (in microseconds)
#define TIMER_PERIOD_US 100

// Default hardware configuration for development mode
#define DEFAULT_HW_REVISION HW_REV_B
#define DEFAULT_SERIAL_NUMBER "ABC1234"

// Temperature thresholds (in °C)
#define TEMP_THRESHOLD_LOW_C    5.0f
#define TEMP_THRESHOLD_NORMAL_C 85.0f
#define TEMP_THRESHOLD_HIGH_C   105.0f

#endif /* CFG_H */
