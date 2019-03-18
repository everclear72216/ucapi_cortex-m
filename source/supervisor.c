#include "interrupts/supervisor.h"

__attribute__ ((weak, interrupt ("IRQ"))) extern void __svcall_isr(void)
{
    while(1) {}
}

__attribute__ ((weak, interrupt ("IRQ"))) extern void __pendsv_isr(void)
{
    while(1) {}
}
