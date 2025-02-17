#include "../include/timer.h"
#include <stdio.h>

// We'll call adc_hal_trigger_conversion() on each "period" for simulation this to emulate a HW trigger
extern void adc_hal_trigger_conversion(void);

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
    // In real hardware, you'd get an actual hardware update event
    // triggering the ADC. Here, we simulate by calling:
    adc_hal_trigger_conversion();
}
