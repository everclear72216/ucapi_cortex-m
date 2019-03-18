#ifndef UCAPI_CORTEX_M_INTERRUPTS_DEBUG_H_INCLUDED
#define UCAPI_CORTEX_M_INTERRUPTS_DEBUG_H_INCLUDED

extern void __debugmon_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* UCAPI_CORTEX_M_INTERRUPTS_DEBUG_H_INCLUDED */
