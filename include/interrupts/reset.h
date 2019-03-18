#ifndef UCAPI_CORTEX_M_INTERRUPTS_RESET_H_INCLUDED
#define UCAPI_CORTEX_M_INTERRUPTS_RESET_H_INCLUDED

extern void __reset_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* UCAPI_CORTEX_M_INTERRUPTS_RESET_H_INCLUDED */
