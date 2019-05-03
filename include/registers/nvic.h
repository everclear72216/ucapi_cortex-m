#ifndef UCAPI_CORTEX_M_REGISTERS_NVIC_H_INCLUDED
#define UCAPI_CORTEX_M_REGISTERS_NVIC_H_INCLUDED

struct cortex_m_nvic_registers
{
    unsigned int setena[16];
    unsigned int setpend[16];
    unsigned int clrpend[16];
    unsigned int active[16];
    unsigned int __reserved0[0xc0];
    unsigned int ipr[128];
};

#define nvic ((volatile struct cortex_m_nvic_registers*)DC_CORTEX_M_BASES_NVIC)

#endif /* UCAPI_CORTEX_M_REGISTERS_NVIC_H_INCLUDED */
