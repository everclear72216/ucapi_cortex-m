#include <ucapi/breakpoint.h>

#include "bkpt.h"

extern void ucapi_breakpoint(void)
{
    bkpt(0);
}
