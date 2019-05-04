#include <ucapi/system_timer.h>

#include "system_timer_if.h"

void ucapi_system_timer_stop(struct ucapi_system_timer* timer)
{
    timer->interface.stop_func(timer->interface.context);
}

void ucapi_system_timer_start(struct ucapi_system_timer* timer)
{
    timer->interface.start_func(timer->interface.context);
}

unsigned int ucapi_system_timer_ticks(struct ucapi_system_timer* timer)
{
    return timer->interface.ticks_func(timer->interface.context);
}

unsigned int ucapi_system_timer_elapsed(struct ucapi_system_timer* timer, unsigned int ticks)
{
    return timer->interface.elapsed_func(timer->interface.context, ticks);
}

void (*ucapi_system_timer_set_callback(struct ucapi_system_timer* timer, void (*callback)(void)))(void)
{
    return timer->interface.set_callback_func(timer->interface.context, callback);
}
