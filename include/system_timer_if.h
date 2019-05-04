#ifndef UCAPI_CORTEX_M_SYSTEM_TIMER_IF_H_INCLUDED
#define UCAPI_CORTEX_M_SYSTEM_TIMER_IF_H_INCLUDED

#include <ucapi/system_timer.h>

/**
 * @brief      An interface structure for timers on cortex-m based controllers.
 * @details    Cortex-M devices come with a systick peripheral. To provide a
 *             consistent interface across the systick peripheral and other
 *             vendor specific timer peripherals a run-time interface is
 *             required.
 */
struct cortex_m_system_timer_if
{
    void *context;
    void (*stop_func)(void*);
    void (*start_func)(void*);
    unsigned int (*ticks_func)(void*);
    unsigned int (*elapsed_func)(void*, unsigned int ticks);
    void (*(*set_callback_func)(void*, void (*)(void)))(void);
};

/**
 * @brief      The cortex-m specific structure for a system timer.
 */
struct ucapi_system_timer
{
    const struct cortex_m_system_timer_if interface;
};

#endif /* UCAPI_CORTEX_M_SYSTEM_TIMER_IF_H_INCLUDED */
