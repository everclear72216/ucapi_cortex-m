#ifndef UCAPI_CORTEX_M_INTERRUPTS_SUPERVISOR_H_INCLUDED
#define UCAPI_CORTEX_M_INTERRUPTS_SUPERVISOR_H_INCLUDED

extern void __svcall_isr(void) __attribute__ ((interrupt ("IRQ")));

extern void __pendsv_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* UCAPI_CORTEX_M_INTERRUPTS_SUPERVISOR_H_INCLUDED */
