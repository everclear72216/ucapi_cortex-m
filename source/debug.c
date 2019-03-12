#include <ucapi/debug.h>

#include "devconf.h"

#include "registers/debug.h"

extern enum ucapi_debug_states ucapi_get_debug_state(void)
{
    return debug->dhcsr.read.c_debugen ? ucapi_debug_enabled : ucapi_debug_disabled;
}