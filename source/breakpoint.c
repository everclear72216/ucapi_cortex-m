#include "ucapi/breakpoint.h"
#include "ucapi/cortex-m/bkpt.h"

extern void ucapi_breakpoint(void)
{
    bkpt(0);
}
