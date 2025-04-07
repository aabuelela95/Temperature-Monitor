#include <stdio.h>
#include "timer.h"
#include "adc_hal.h"



void timer_init(uint32_t period_us)
{
    // In real hardware:
    //   1) Enable timer clock
    //   2) Configure prescaler & ARR for 100 µs.
    //   3) Enable HW trigger to ADC.
    //   4) Possibly enable interrupt if needed
    (void)period_us;
}

void timer_emulate_period_event(void)
{
    // In real hardware, we'd get an actual hardware update event
    // triggering the ADC. Here, we simulate by calling:
    adc_hal_trigger_conversion();
}
