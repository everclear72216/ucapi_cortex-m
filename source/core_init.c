#include "devconf.h"

#include "core_init.h"

#include "priorities.h"

#if VECTOR_TABLE_RELOCATE
#   include "vector_table.h"
#endif /* VECTOR_TABLE_RELOCATE */

extern void cortex_m_core_init(void)
{
#if VECTOR_TABLE_RELOCATE
    cortex_m_relocate_vector_table();
#endif /* VECTOR_TABLE_RELOCATE */
}
