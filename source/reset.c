#include "reset.h"

extern int main(void);

extern unsigned char __bss_vma;
extern unsigned char __bss_vma_end;

extern unsigned char __data_vma;
extern unsigned char __data_vma_end;
extern const unsigned char __data_lma;

__attribute__ ((interrupt ("IRQ"))) extern void __reset_isr(void)
{
    unsigned char* volatile dst;
    const unsigned char* volatile src;

    /* initialize data */
    src = &__data_lma;
    dst = &__data_vma;
    while(dst != &__data_vma_end)
    {
        *dst++ = *src++;
    }

    /* initialize static variables */
    dst = &__bss_vma;
    while(dst != &__bss_vma_end)
    {
        *dst++ = 0u;
    }

    main();

    while(~0) {}
}
