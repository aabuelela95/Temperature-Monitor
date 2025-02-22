#ifndef TEMP_MONITOR_APP_HPP
#define TEMP_MONITOR_APP_HPP

#include <cstdint>

/**
 * @brief High-level application. 
 *        Orchestrates init of all modules and runs the main loop (bare-metal).
 */

class TempMonitorApp
{
public:
    static void init(void) noexcept;
    static void run(void) noexcept;

private:
    TempMonitorApp(void) noexcept;
    ~TempMonitorApp(void) noexcept;
    TempMonitorApp(const TempMonitorApp&) = delete;
    TempMonitorApp& operator=(const TempMonitorApp&) = delete;
};

#endif // TEMP_MONITOR_APP_HPP
