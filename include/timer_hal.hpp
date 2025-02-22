#ifndef TIMER_HAL_HPP
#define TIMER_HAL_HPP

#include <cstdint>

/**
 * @brief Timer HAL for bare-metal usage, set for 100µs,
 *        triggers the ADC externally in real hardware.
 */

class TimerHal
{
public:
    static void init(uint32_t periodUs) noexcept;
    static void start(void) noexcept;

private:
    TimerHal(void) noexcept;
    ~TimerHal(void) noexcept;
    TimerHal(const TimerHal&) = delete;
    TimerHal& operator=(const TimerHal&) = delete;
};

#endif // TIMER_HAL_HPP
