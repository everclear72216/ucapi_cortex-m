#ifndef UCAPI_CORTEX_M_INTERRUPTS_SYSTICK_H_INCLUDED
#define UCAPI_CORTEX_M_INTERRUPTS_SYSTICK_H_INCLUDED

extern void __systick_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* UCAPI_CORTEX_M_INTERRUPTS_SYSTICK_H_INCLUDED */
