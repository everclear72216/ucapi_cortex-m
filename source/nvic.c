
#include "devconf.h"

#include "priorities.h"

#include "registers/nvic.h"

#include "nvic.h"

static inline unsigned int interrupt_bit(int interrupt)
{
    return (interrupt % 32);
}

static inline unsigned int interrupt_index(int interrupt)
{
    return (interrupt >> 5);
}

static inline unsigned int interrupt_priority_index(int interrupt)
{
    return (interrupt >> 2);
}

static inline unsigned int interrupt_priority_shift(int interrupt)
{
    return ((interrupt % 4) * 8);
}

extern void nvic_enable(int interrupt)
{
    unsigned int bit;
    unsigned int index;
    unsigned int value;

    bit = interrupt_bit(interrupt);
    index = interrupt_index(interrupt);

    value = nvic->setena[index] | (1u << bit);
    nvic->setena[index] = value;
}

extern void nvic_disable(int interrupt)
{
    unsigned int bit;
    unsigned int index;
    unsigned int value;

    bit = interrupt_bit(interrupt);
    index = interrupt_index(interrupt);

    value = nvic->setena[index] & ~(1u << bit);
    nvic->setena[index] = value;
}

extern enum nvic_enabled_state nvic_is_enabled(int interrupt)
{
    unsigned int bit;
    unsigned int index;
    unsigned int value;

    bit = interrupt_bit(interrupt);
    index = interrupt_index(interrupt);

    value = nvic->setena[index] & (1u << bit);

    return (value ? nvic_enabled : nvic_disabled);
}

extern void nvic_set_pending(int interrupt)
{
    unsigned int bit;
    unsigned int index;

    bit = interrupt_bit(interrupt);
    index = interrupt_index(interrupt);

    nvic->setpend[index] = (1u << bit);
}

extern void nvic_clear_pending(int interrupt)
{
    unsigned int bit;
    unsigned int index;

    bit = interrupt_bit(interrupt);
    index = interrupt_index(interrupt);

    nvic->clrpend[index] = (1u << bit);
}

extern enum nvic_pending_state nvic_is_pending(int interrupt)
{
    unsigned int bit;
    unsigned int index;
    unsigned int value;

    bit = interrupt_bit(interrupt);
    index = interrupt_index(interrupt);

    value = nvic->setpend[index] & (1 << bit);

    return (value ? nvic_pending : nvic_not_pending);
}

extern enum nvic_active_state nvic_is_active(int interrupt)
{
    unsigned int bit;
    unsigned int index;
    unsigned int value;

    bit = interrupt_bit(interrupt);
    index = interrupt_index(interrupt);

    value = nvic->active[index] & (1u << bit);

    return (value ? nvic_active : nvic_not_active);
}

extern struct cortex_m_priority nvic_get_priority(int interrupt)
{
    unsigned int index;
    unsigned int shift;
    struct cortex_m_priority prio;

    index = interrupt_priority_index(interrupt);
    shift = interrupt_priority_shift(interrupt);

    prio.priority = (unsigned char)((nvic->ipr[index] >> shift) & 0xFFu);

    return prio;
}

extern void nvic_set_priority(int interrupt, struct cortex_m_priority priority)
{
    unsigned int prio;
    unsigned int index;
    unsigned int value;
    unsigned int shift;

    index = interrupt_priority_index(interrupt);
    shift = interrupt_priority_shift(interrupt);

    value = nvic->ipr[index] & ~(0xFFu << shift);

    prio = priority.priority;
    nvic->ipr[index] = value | (prio << shift);
}
