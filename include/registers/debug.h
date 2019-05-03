#ifndef UCAPI_CORTEX_M_REGISTERS_DEBUG_H_INCLUDED
#define UCAPI_CORTEX_M_REGISTERS_DEBUG_H_INCLUDED

struct cortex_m_debug_system_registers
{
    union {
        unsigned int reg;
        union {
            struct {
                unsigned int c_debugen:1;
                unsigned int c_halt:1;
                unsigned int c_step:1;
                unsigned int c_maskints:1;
                unsigned int __reserved0:1;
                unsigned int c_snapstall:1;
                unsigned int __reserved1:10;
                unsigned int s_regrdy:1;
                unsigned int s_halt:1;
                unsigned int s_sleep:1;
                unsigned int s_lockup:1;
                unsigned int __reserved2:4;
                unsigned int s_retire_st:1;
                unsigned int s_reset_st:1;
                unsigned int __reserved3:6;
            } read;
            struct {
                unsigned int c_debugen:1;
                unsigned int c_halt:1;
                unsigned int c_step:1;
                unsigned int c_maskints:1;
                unsigned int __reserved0:1;
                unsigned int c_snapstall:1;
                unsigned int __reserved1:10;
                unsigned int dbgkey:16;
            } write;
        };
    } dhcsr;

    union {
        unsigned int reg;
        struct {
            unsigned int regsel:7;
            unsigned int __reserved0:9;
            unsigned int regwnr:1;
            unsigned int __reserved1:15;
        };
    } dcrsr;

    union {
        unsigned int reg;
    } dbgtmp;

    union {
        unsigned int reg;
        struct {
            unsigned int vc_corereset:1;
            unsigned int __reserved0:3;
            unsigned int vc_mmerr:1;
            unsigned int vc_nocperr:1;
            unsigned int vc_chkerr:1;
            unsigned int vc_staterr:1;
            unsigned int vc_buserr:1;
            unsigned int vc_interr:1;
            unsigned int vc_harderr:1;
            unsigned int __reserved1:5;
            unsigned int mon_en:1;
            unsigned int mon_pend:1;
            unsigned int mon_step:1;
            unsigned int mon_req:1;
            unsigned int __reserved2:4;
            unsigned int trcena:1;
            unsigned int __reserved3:7;
        };
    } demcr;

    union {
        unsigned int reg;
    } __reserved0[0x100];
};

#define debug ((volatile struct cortex_m_debug_system_registers*)DC_CORTEX_M_BASES_DEBUG)

#endif /* UCAPI_CORTEX_M_REGISTERS_DEBUG_H_INCLUDED */
