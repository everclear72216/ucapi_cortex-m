#ifndef UCAPI_CORTEX_M_REGISTERS_STIR_H_INCLUDED
#define UCAPI_CORTEX_M_REGISTERS_STIR_H_INCLUDED

struct cortex_m_stir_registers
{
    union {
        unsigned int reg;
        struct {
            unsigned int intid:8;
            unsigned int __reserved0:24;
        };
    };
};

#define stir ((volatile struct cortex_m_stir_registers*)STIR_BASE)

#endif /* UCAPI_CORTEX_M_REGISTERS_STIR_H_INCLUDED */