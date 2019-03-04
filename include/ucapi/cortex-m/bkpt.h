#ifndef UCAPI_CORTEX_M_BREAKPOINT_H_INCLUDED
#define UCAPI_CORTEX_M_BREAKPOINT_H_INCLUDED

#define bkpt(value) asm volatile ("bkpt %0" : : "I" (value));

#endif /* UCAPI_CORTEX_M_BREAKPOINT_H_INCLUDED */