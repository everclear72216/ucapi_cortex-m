#include <ucapi/breakpoint.h>

#include "instructions/bkpt.h"

extern void ucapi_breakpoint(void)
{
    bkpt(0);
}
