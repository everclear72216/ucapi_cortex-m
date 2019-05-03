#ifndef UCAPI_CORTEX_M_REGISTERS_ICTR_H_INCLUDED
#define UCAPI_CORTEX_M_REGISTERS_ICTR_H_INCLUDED

struct cortex_m_ictr_registers
{
    union {
        unsigned int reg;
        struct {
            unsigned int intlinesnum:4;
            unsigned int __reserved0:28;
        };
    };
}

#define ictr ((volatile struct cortex_m_ictr_registers*)DC_CORTEX_M_BASES_ICTR)

#define /* UCAPI_CORTEX_M_REGISTERS_ICTR_H_INCLUDED */
