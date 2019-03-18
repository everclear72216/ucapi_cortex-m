
#include "interrupts/exceptions.h"

__attribute__ ((weak, interrupt ("IRQ"))) extern void __busfault_isr(void)
{
    while(~0) {}
}

__attribute__ ((weak, interrupt ("IRQ"))) extern void __hardfault_isr(void)
{
    while(~0) {}
}

__attribute__ ((weak, interrupt ("IRQ"))) extern void __memmanage_isr(void)
{
    while(~0) {}
}

__attribute__ ((weak, interrupt ("IRQ"))) extern void __usagefault_isr(void)
{
    while(~0) {}
}
