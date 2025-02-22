#include "../include/timer_hal.hpp"

TimerHal::TimerHal(void) noexcept
{
    // private
}

TimerHal::~TimerHal(void) noexcept
{
    // private
}

void TimerHal::init(uint32_t periodUs) noexcept
{
    // 1) Enable timer clock
    // 2) Configure prescaler & auto-reload for 'periodUs'
    // 3) Set trigger or compare match to auto-trigger ADC
    (void)periodUs;
}

void TimerHal::start(void) noexcept
{
    // e.g. enable the timer
}
