#ifndef UCAPI_CORTEX_M_REGISTERS_SYSTICK_H_INCLUDED
#define UCAPI_CORTEX_M_REGISTERS_SYSTICK_H_INCLUDED

struct cortex_m_systick_registers
{
    union {
        unsigned int reg;
        struct {
            unsigned int enable:1;
            unsigned int tickint:1;
            unsigned int clksource:1;
            unsigned int __reserved0:13;
            unsigned int countflag:1;
            unsigned int __reserved1:15;
        };
    } syst_csr;

    union {
        unsigned int reg;
        struct {
            unsigned int reload:24;
            unsigned int __reserved0:8;
        };
    } syst_rvr;

    unsigned int syst_cvr;

    union {
        unsigned int reg;
        struct {
            unsigned int tenms:24;
            unsigned int __reserved0:6;
            unsigned int skew:1;
            unsigned int noref:1;
        };
    } syst_calib;

    unsigned int __reserved0[0xdc];
};

#define systick ((volatile struct cortex_m_systick_registers*)SYSTICK_BASE)

#endif /* UCAPI_CORTEX_M_REGISTERS_SYSTICK_H_INCLUDED */
