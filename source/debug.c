#include <ucapi/debug.h>

#include "devconf.h"

#include "registers/debug.h"
#include "interrupts/debug.h"


__attribute__ ((weak, interrupt ("IRQ"))) extern void __debugmon_isr(void)
{
    while(1) {}
}

extern enum ucapi_debug_states ucapi_get_debug_state(void)
{
    return debug->dhcsr.read.c_debugen ? ucapi_debug_enabled : ucapi_debug_disabled;
}