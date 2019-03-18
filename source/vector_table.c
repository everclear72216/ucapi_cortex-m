#include "vector_table.h"

#include "devconf.h"

#include "registers/scb.h"

#include "interrupts/nmi.h"
#include "interrupts/reset.h"
#include "interrupts/debug.h"
#include "interrupts/systick.h"
#include "interrupts/supervisor.h"
#include "interrupts/exceptions.h"

#define CORE_VECTOR_TABLE_SIZE 16

extern void __stack(void);

#if VECTOR_TABLE_RELOCATE
#   define RAM_VECTOR_TABLE_SIZE VECTOR_TABLE_SIZE
#   define FLASH_VECTOR_TABLE_SIZE CORE_VECTOR_TABLE_SIZE
#else
#   define RAM_VECTOR_TABLE_SIZE 0
#   define FLASH_VECTOR_TABLE_SIZE VECTOR_TABLE_SIZE
#endif /* VECTOR_TABLE_RELOCATE */


#if VECTOR_TABLE_RELOCATE
__attribute__ ((section (".core_table_ram")))
void (* __core_table_ram[RAM_VECTOR_TABLE_SIZE]) (void);
#endif /* VECTOR_TABLE_RELOCATE */

__attribute__ ((section (".core_table_flash")))
void (*const __core_table_flash[FLASH_VECTOR_TABLE_SIZE]) (void) = {
    __stack,
    __reset_isr,
    __nmi_isr,
    __hardfault_isr,
    __memmanage_isr,
    __busfault_isr,
    __usagefault_isr,
    0,
    0,
    0,
    0,
    __svcall_isr,
    __debugmon_isr,
    0,
    __pendsv_isr,
    __systick_isr,
};


static void (*get_vector_table(void))(void)
{
    unsigned int table_offset;

    table_offset = scb->vtor.tbloff;

    return (void (*)(void))(table_offset << 7u);
}

#if VECTOR_TABLE_RELOCATE
extern void cortex_m_relocate_vector_table(void)
{
    unsigned char i;
    unsigned int* dst = (unsigned int*)__core_table_ram;
    unsigned int* const src = (unsigned int*)get_vector_table();

    /* copy core vectors */
    for (i = 0; i < CORE_VECTOR_TABLE_SIZE; i += 1) {
        dst[i] = src[i];
    }

    /* assign new address */
    unsigned int offset = (((unsigned int)__core_table_ram) >> 7u);
    scb->vtor.tbloff = offset;
}
#endif /* VECTOR_TABLE_RELOCATE */

extern void (*cortex_m_get_vector_table(void))(void)
{
    return get_vector_table();
}
