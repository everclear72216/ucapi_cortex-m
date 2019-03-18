#include "systick.h"

#include "devconf.h"

#include "registers/systick.h"
#include "interrupts/systick.h"

__attribute__ ((weak, interrupt ("IRQ"))) extern void __systick_isr(void)
{
    while(1) {}
}

extern void cortex_m_systick_enable(void)
{
    systick->syst_csr.enable = 1;
}

extern void cortex_m_systick_disable(void)
{
    systick->syst_csr.enable = 0;
}

extern enum systick_enabled_state cortex_m_systick_is_enabled(void)
{
    return (systick->syst_csr.enable ? systick_enabled : systick_disabled);
}

extern int cortex_m_systick_has_expired(void)
{
    return (systick->syst_csr.countflag ? 1 : 0);
}

extern void cortex_m_systick_interrupt_enable(void)
{
    systick->syst_csr.tickint = 1;
}

extern void cortex_m_systick_interrupt_disable(void)
{
    systick->syst_csr.tickint = 0;
}

extern enum systick_interrupt_state cortex_m_systick_interrupt_is_enabled(void)
{
    return (systick->syst_csr.tickint ? systick_interrupt_enabled : systick_interrupt_disabled);
}

extern unsigned int cortex_m_systick_current_get(void)
{
    return systick->syst_cvr;
}

extern void cortex_m_systick_current_clear(void)
{
    systick->syst_cvr = 0;
}

extern int cortex_m_systick_has_external_reference(void)
{
    return (systick->syst_calib.noref ? 0 : 1);
}

extern unsigned int cortex_m_systick_ten_ms_reload_value_get(void)
{
    return systick->syst_calib.tenms;
}

extern int cortex_m_systick_has_exact_ten_ms_interval(void)
{
    return (systick->syst_calib.skew ? 0 : 1);
}

extern unsigned int cortex_m_systick_reload_value_get(void)
{
    return systick->syst_rvr.reload;
}

extern void cortex_m_systick_reload_value_set(unsigned int reload)
{
    systick->syst_rvr.reload = reload;
}

extern void cortex_m_systick_clock_source_set_internal(void)
{
    systick->syst_csr.clksource = 1;   
}

extern void cortex_m_systick_clock_source_set_external(void)
{
    systick->syst_csr.clksource = 0;
}

extern enum systick_clock_source cortex_m_sytick_clock_source_get(void)
{
    return (systick->syst_csr.clksource ? systick_clock_source_internal : systick_clock_source_external);
}
