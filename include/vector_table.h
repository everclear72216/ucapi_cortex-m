#ifndef UCAPI_CORTEX_M_VECTOR_TABLE_H_INCLUDED
#define UCAPI_CORTEX_M_VECTOR_TABLE_H_INCLUDED

#if VECTOR_TABLE_RELOCATE

/**
 * @brief      Relocates the vector table to a new address.
 * @details    This function copies the core vectors from the old vector table
 *             to the new vector table and then sets the new vector table base
 *             address.
 *
 * @param[in]  address  The new address of the vector table.
 */
extern void cortex_m_relocate_vector_table(void);

/**
 * @brief      If the vector table is located in ram this function is used to register
 *             interrupt service routines.
 *
 * @param[in]  index  The index of the vector to be set.
 * @param[in]  isr    The interrupt service routine
 */
extern void (*cortex_m_vector_table_set_isr(unsigned int index, void (*isr)(void)))(void);
#endif /* VECTOR_TABLE_RELOCATE */

/**
 * @brief      Retrieves the current address of the vector table.
 *
 * @return     The current address of the vector table.
 */
extern void (*cortex_m_get_vector_table(void))(void);

#endif /* UCAPI_CORTEX_M_VECTOR_TABLE_H_INCLUDED */
