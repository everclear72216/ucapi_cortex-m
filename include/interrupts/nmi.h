#ifndef UCAPI_CORTEX_M_INTERRUPTS_NMI_H_INCLUDED
#define UCAPI_CORTEX_M_INTERRUPTS_NMI_H_INCLUDED

extern void __nmi_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* UCAPI_CORTEX_M_INTERRUPTS_NMI_H_INCLUDED */
