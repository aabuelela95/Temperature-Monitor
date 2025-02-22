#include "../include/temp_monitor_app.hpp"
#include "../include/eeprom.hpp"
#include "../include/adc_hal.hpp"
#include "../include/timer_hal.hpp"
#include "../include/temperature_sensor.hpp"
#include "../include/led.hpp"
#include "../include/cfg.hpp"

TempMonitorApp::TempMonitorApp(void) noexcept
{
    // Constructor
}
TempMonitorApp::~TempMonitorApp(void) noexcept
{
    // Destructor
}

void TempMonitorApp::init(void) noexcept
{
    // 1) EEPROM to get hw revision
    Eeprom::init();
    uint8_t hwRev = Eeprom::readHwRevision();

    // 2) Initialize ADC
    AdcHal::init();

    // 3) Setup Timer for 100µs
    TimerHal::init(TIMER_PERIOD_US);
    TimerHal::start();

    // 4) Setup Temperature Sensor logic
    TemperatureSensor::init(hwRev);

    // 5) Setup LED driver
    LedDriver::init();
}

void TempMonitorApp::run(void) noexcept
{
    // Infinite loop. Timer triggers ADC => ADC ISR updates reading
    // We poll temperature and update LED
    while (true)
    {
        float tempC = TemperatureSensor::readTemperature();
        LedDriver::update(tempC);

        // Basic busy-wait delay. In real code, you might use an RTOS or timer-based scheduling
        for (volatile uint32_t i = 0U; i < 100000U; i++) {
            // no-op
        }
    }
}
