#include <limits.h>

#include "devconf.h"

#include "systick.h"
#include "system_timer_if.h"

struct systick_system_timer
{
    unsigned int ticks;
    void (*callback)(void);
};

static void systick_system_timer_stop(void* timer);
static void systick_system_timer_start(void* timer);
static unsigned int systick_system_timer_ticks(void* timer);
static unsigned int systick_system_timer_elapsed(void* timer, unsigned int ticks);
static void (*systick_system_timer_set_callback(void* timer, void (*callback)(void)))(void);

static struct systick_system_timer systick_system_timer;

static const struct ucapi_system_timer ucapi_system_timer = {
    .interface = {
        .context = &systick_system_timer,
        .stop_func = systick_system_timer_stop,
        .start_func = systick_system_timer_start,
        .ticks_func = systick_system_timer_ticks,
        .elapsed_func = systick_system_timer_elapsed,
        .set_callback_func = systick_system_timer_set_callback
    }
};

const struct ucapi_system_timer* systick_system_timer_instance = &ucapi_system_timer;

static void systick_system_timer_stop(void* timer)
{
    cortex_m_systick_disable();
}

static void systick_system_timer_start(void* timer)
{
    cortex_m_systick_enable();
}

static unsigned int systick_system_timer_ticks(void* timer)
{
    struct systick_system_timer* t;

    t = timer;

    return t->ticks;
}

static unsigned int systick_system_timer_elapsed(void* timer, unsigned int ticks)
{
    unsigned int result;
    unsigned int current;
    struct systick_system_timer* t;

    t = timer;
    current = t->ticks;

    if (current >= ticks) {
        result = current - ticks;
    }
    else {
        result = (UINT_MAX - ticks) + current;
    }

    return result;
}

static void (*systick_system_timer_set_callback(void* timer, void (*callback)(void)))(void)
{
    void (*result)(void);

    result = systick_system_timer.callback;
    systick_system_timer.callback = callback;

    return result;
}

__attribute__ ((interrupt ("IRQ"))) extern void __systick_isr(void)
{
    if (systick_system_timer.callback) {
        systick_system_timer.callback();
    }

    if (systick_system_timer.ticks == UINT_MAX) {
        systick_system_timer.ticks = 0u;
    }
    else {
        systick_system_timer.ticks += 1u;
    }
}
