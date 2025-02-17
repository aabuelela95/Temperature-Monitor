#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

/**
 * @brief Initialize hardware timer for the given period in microseconds.
 */
void timer_init(uint32_t period_us);

/**
 * @brief In simulation, emulate the timer period event. 
 *        In real HW, we wouldn't do this; the timer triggers automatically.
 */
void timer_emulate_period_event(void);

#endif /* TIMER_H */
