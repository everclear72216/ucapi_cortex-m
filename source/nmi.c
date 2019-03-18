#include "interrupts/nmi.h"

__attribute__ ((weak, interrupt ("IRQ"))) extern void __nmi_isr(void)
{
    while(1) {}
}
