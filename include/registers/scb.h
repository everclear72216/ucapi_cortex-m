#ifndef UCAPI_CORTEX_M_REGISTERS_SCS_H_INCLUDED
#define UCAPI_CORTEX_M_REGISTERS_SCS_H_INCLUDED

struct cortex_m_scb_registers
{
    union {
        unsigned int reg;
        struct {
            unsigned int revision:4;
            unsigned int partno:12;
            unsigned int __reserved0:4;
            unsigned int variant:4;
            unsigned int implementer:8;
        };
    } cpuid;

    union {
        unsigned int reg;
        struct {
            unsigned int vectactive:9;
            unsigned int __reserved0:2;
            unsigned int rettobase:1;
            unsigned int vectpending:9;
            unsigned int __reserved1:1;
            unsigned int isrpending:1;
            unsigned int isrpreempt:1;
            unsigned int __reserved2:1;
            unsigned int pendstclr:1;
            unsigned int pendstset:1;
            unsigned int pendsvclr:1;
            unsigned int pendsvset:1;
            unsigned int __reserved3:2;
            unsigned int nmipendset:1;
        };
    } icsr;

    union {
        unsigned int reg;
        struct {
            unsigned int __reserved0:7;
            unsigned int tbloff:25;
        };
    } vtor;

    union {
        unsigned int reg;
        struct {
            unsigned short vectreset:1;
            unsigned short vectclractive:1;
            unsigned short sysresetreq:1;
            unsigned short __reserved0:5;
            unsigned short prigroup:3;
            unsigned short __reserved1:4;
            unsigned short endianness:1;

            union {
                unsigned short vectkey;
                unsigned short vectkeystat;
            };
        };
    } aircr;

    union {
        unsigned int reg;
        struct {
            unsigned int __reserved0:1;
            unsigned int sleeponexit:1;
            unsigned int sleepdeep:1;
            unsigned int __reserved1:1;
            unsigned int sevonpend:1;
            unsigned int __reserved2:27;
        };
    } scr;

    union {
        unsigned int reg;
        struct {
            unsigned int nonbasethrdena:1;
            unsigned int usersetmpend:1;
            unsigned int __reserved0:1;
            unsigned int unalign_trp:1;
            unsigned int div_0_trp:1;
            unsigned int __reserved1:3;
            unsigned int bfhfnmign:1;
            unsigned int stkalign:1;
            unsigned int __reserved2:6;
            unsigned int dc:1;
            unsigned int ic:1;
            unsigned int bp:1;
            unsigned int __reserved3:13;
        };
    } ccr;

    union {
        unsigned int reg;
        struct {
            unsigned int pri_4:8;
            unsigned int pri_5:8;
            unsigned int pri_6:8;
            unsigned int pri_7:8;
        };
    } shpr1;

    union {
        unsigned int reg;
        struct {
            unsigned int pri_8:8;
            unsigned int pri_9:8;
            unsigned int pri_10:8;
            unsigned int pri_11:8;
        };
    } shpr2;

    union {
        unsigned int reg;
        struct {
            unsigned int pri_12:8;
            unsigned int pri_13:8;
            unsigned int pri_14:8;
            unsigned int pri_15:8;
        };
    } shpr3;

    union {
        unsigned int reg;
        struct {
            unsigned int memfaultact:1;
            unsigned int busfaultact:1;
            unsigned int __reserved0:1;
            unsigned int usgfaultact:1;
            unsigned int __reserved1:3;
            unsigned int svcallact:1;
            unsigned int monitoract:1;
            unsigned int __reserved2:1;
            unsigned int pendsvact:1;
            unsigned int systickact:1;
            unsigned int usgfaultpended:1;
            unsigned int memfaultpended:1;
            unsigned int busfaultpended:1;
            unsigned int svcallpended:1;
            unsigned int memfaultena:1;
            unsigned int busfaultena:1;
            unsigned int usgfaultena:1;
            unsigned int __reserved3:13;
        };
    } shcsr;

    union {
        unsigned int reg;
        struct {
            union {
                unsigned char reg;
                struct {
                    unsigned char iaccviol:1;
                    unsigned char daccviol:1;
                    unsigned char __reserved0:1;
                    unsigned char munstkerr:1;
                    unsigned char mstkerr:1;
                    unsigned char mlsperr:1;
                    unsigned char __reserved1:1;
                    unsigned char mmarvalid:1;
                };
            } memmanage;

            union {
                unsigned char reg;
                struct {
                    unsigned char ubuserr:1;
                    unsigned char preciseerr:1;
                    unsigned char impreciserr:1;
                    unsigned char unstkerr:1;
                    unsigned char stkerr:1;
                    unsigned char lsperr:1;
                    unsigned char __reserved0:1;
                    unsigned char bfarvalid:1;
                };
            } busfault;

            union {
                unsigned short reg;
                struct {
                    unsigned short undefinstr:1;
                    unsigned short invstate:1;
                    unsigned short invps:1;
                    unsigned short nocp:1;
                    unsigned short __reserved0:4;
                    unsigned short unaligned:1;
                    unsigned short divbyzero:1;
                    unsigned short __reserved1:6;
                };
            } usagefault;
        };
    } cfsr;

    union {
        unsigned int reg;
        struct {
            unsigned int __reserved0:1;
            unsigned int vecttbl:1;
            unsigned int __reserved1:24;
            unsigned int forced:1;
            unsigned int debugevt:1;
        };
    } hfsr;

    union {
        unsigned int reg;
        struct {
            unsigned int halted:1;
            unsigned int bkpt:1;
            unsigned int dwttrap:1;
            unsigned int vcatch:1;
            unsigned int external:1;
            unsigned int __reserved0:27;
        };
    } dfsr;

    unsigned int mmfar;
    unsigned int bfar;
    unsigned int afsr;

    unsigned int __reserved0[0x48];

    union {
        unsigned int reg;
        struct {
            unsigned int cp0:2;
            unsigned int cp1:2;
            unsigned int cp2:2;
            unsigned int cp3:2;
            unsigned int cp4:2;
            unsigned int cp5:2;
            unsigned int cp6:2;
            unsigned int cp7:2;
            unsigned int __reserved0:4;
            unsigned int cp10:2;
            unsigned int cp11:2;
            unsigned int __reserved1:8;
        };
    } cpacr;

    unsigned int __reserved1;
};

#define scb ((volatile struct cortex_m_scb_registers*)SCB_BASE)

#endif /* UCAPI_CORTEX_M_REGISTERS_SCS_H_INCLUDED */
