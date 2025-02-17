#include "../include/temp_monitor_app.h"
#include <stdio.h>
#include <unistd.h> // for usleep (simulation)

#include "../include/cfg.h"
#include "../include/eeprom.h"
#include "../include/temperature_sensor.h"
#include "../include/led.h"
#include "../include/timer.h"
#include "../include/adc_hal.h"

// maybe do a cfg module?? 
static hw_revision_t s_current_hw_rev = HW_REV_A;

void temp_monitor_app_init(void)
{
    // 1. EEPROM init
    eeprom_init();
    #ifdef CFG_MODE
    eeprom_set_revision(s_current_hw_rev);
    #endif

    // 2. read final config
    s_current_hw_rev = eeprom_read_revision();
    char serial_buf[EEPROM_SERIAL_MAX_LEN];
    eeprom_read_serial_number(serial_buf, sizeof(serial_buf));

    printf("[App] HW Revision: %s\n", (s_current_hw_rev == HW_REV_A) ? "Rev-A" : "Rev-B");
    printf("[App] Serial    : %s\n", serial_buf);

    // 3. init sensor, LED
    temperature_sensor_init();
    led_init();

    // 4. init ADC
    adc_hal_init();

    // 5. init timer
    timer_init(TIMER_PERIOD_US);

    printf("[App] Initialization complete.\n");
}

void temp_monitor_app_run(void)
{
    // This is just for simulation in the real HW
    // The timer would be free-running, ADC triggered automatically, 
    // Here, for demonstration, I simulate 10 cycles.

    for (int i = 0; i < 10; i++) {
        timer_emulate_period_event();
         // Now read the newly updated ADC
        uint16_t rawAdc = temperature_sensor_read_adc();
        float temperature_c = temperature_sensor_to_celsius(rawAdc, s_current_hw_rev);
        led_update(&temperature_c);
        printf("Temprature = %0.1f C\n",temperature_c);
        usleep(TIMER_PERIOD_US); // ~100 µs delay for simulation
    }
}
