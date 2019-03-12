#ifndef UCAPI_CORTEX_M_HANDLERS_H_INCLUDED
#define UCAPI_CORTEX_M_HANDLERS_H_INCLUDED

#include "registers/scb.h"

static inline void cortex_m_enable_usgfault(void)
{
    scb->shcsr.usgfaultena = 1;
}

static inline void cortex_m_enable_busfault(void)
{
    scb->shcsr.busfaultena = 1;
}

static inline void cortex_m_enable_memfault(void)
{
    scb->shcsr.memfaultena = 1;
}

static inline void cortex_m_disable_usgfault(void)
{
    scb->shcsr.usgfaultena = 0;
}

static inline void cortex_m_disable_busfault(void)
{
    scb->shcsr.busfaultena = 0;
}

static inline void cortex_m_disable_memfault(void)
{
    scb->shcsr.memfaultena = 0;
}

static inline int cortex_m_svcall_pending(void)
{
    return scb->shcsr.svcallpended;
}

static inline int cortex_m_busfault_pending(void)
{
    return scb->shcsr.busfaultpended;
}

static inline int cortex_m_memfault_pending(void)
{
    return scb->shcsr.memfaultpended;
}

static inline int cortex_m_usgfault_pending(void)
{
    return scb->shcsr.usgfaultpended;
}

static inline int cortex_m_pendsv_active(void)
{
    return scb->shcsr.pendsvact;
}

static inline int cortex_m_svcall_active(void)
{
    return scb->shcsr.svcallact;
}

static inline int cortex_m_systick_active(void)
{
    return scb->shcsr.systickact;
}

static inline int cortex_m_monitor_active(void)
{
    return scb->shcsr.monitoract;
}

static inline int cortex_m_memfault_active(void)
{
    return scb->shcsr.memfaultact;
}

static inline int cortex_m_busfault_active(void)
{
    return scb->shcsr.busfaultact;
}

static inline int cortex_m_usgfault_active(void)
{
    return scb->shcsr.usgfaultact;
}

#endif /* UCAPI_CORTEX_M_HANDLERS_H_INCLUDED */