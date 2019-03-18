#ifndef UCAPI_CORTEX_M_INTERRUPTS_EXCEPTIONS_H_INCLUDED
#define UCAPI_CORTEX_M_INTERRUPTS_EXCEPTIONS_H_INCLUDED

extern void __busfault_isr(void) __attribute__ ((interrupt ("IRQ")));

extern void __hardfault_isr(void) __attribute__ ((interrupt ("IRQ")));

extern void __memmanage_isr(void) __attribute__ ((interrupt ("IRQ")));

extern void __usagefault_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* UCAPI_CORTEX_M_INTERRUPTS_EXCEPTIONS_H_INCLUDED */
