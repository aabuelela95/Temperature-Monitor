#ifndef CFG_HPP
#define CFG_HPP

#include <cstdint>

/**
 * @brief Configuration for the system: intervals, thresholds, etc.
 */

static constexpr uint32_t TIMER_PERIOD_US = 100U;

static constexpr float TEMP_THRESHOLD_LOW_C    = 5.0F;
static constexpr float TEMP_THRESHOLD_NORMAL_C = 85.0F;
static constexpr float TEMP_THRESHOLD_HIGH_C   = 105.0F;

// Example hardware revision IDs
static constexpr uint8_t HW_REV_A = 0U;
static constexpr uint8_t HW_REV_B = 1U;

#endif // CFG_HPP
