#ifndef UCAPI_CORTEX_M_NVIC_H_INCLUDED
#define UCAPI_CORTEX_M_NVIC_H_INCLUDED

enum nvic_enabled_state
{
    nvic_disabled,
    nvic_enabled
};

enum nvic_pending_state
{
    nvic_not_pending,
    nvic_pending
};

enum nvic_active_state
{
    nvic_not_active,
    nvic_active
};

/**
 * @brief      Enables the interrupt.
 *
 * @param[in]  interrupt  The interrupt
 */
extern void nvic_enable(int interrupt);

/**
 * @brief      Disables the interrupt.
 *
 * @param[in]  interrupt  The interrupt
 */
extern void nvic_disable(int interrupt);

/**
 * @brief      Checks whether the interrupt is enabled.
 *
 * @param[in]  interrupt  The interrupt
 *
 * @retval     nvic_disabled The interrupt is disabled
 * @retval     nvic_enabled The interrupt is enabled     
 */
extern enum nvic_enabled_state nvic_is_enabled(int interrupt);

/**
 * @brief      Puts the interrupt in pending state.
 *
 * @param[in]  interrupt  The interrupt
 */
extern void nvic_set_pending(int interrupt);

/**
 * @brief      Takes the interrupt out of pending state.
 *
 * @param[in]  interrupt  The interrupt
 */
extern void nvic_clear_pending(int interrupt);

/**
 * @brief      Checks whether the interrupt is pending.
 *
 * @param[in]  interrupt  The interrupt
 *
 * @retval     nvic_not_pending The interrupt is not pending.
 * @retval     nvic_pending The interrupt is pending.
 */
extern enum nvic_pending_state nvic_is_pending(int interrupt);

/**
 * @brief      Checks whether the interrupt is active.
 *
 * @param[in]  interrupt  The interrupt
 *
 * @retval     nvic_not_active The interrupt is not active.
 * @retval     nvic_active The interrupt is active.
 */
extern enum nvic_active_state nvic_is_active(int interrupt);

/**
 * @brief      Retrieves the interrupt's priority.
 *
 * @param[in]  interrupt  The interrupt
 *
 * @return     The interrupt's priority
 */
extern struct cortex_m_priority nvic_get_priority(int interrupt);

/**
 * @brief      Assigns a new priority for the interrupt.
 *
 * @param[in]  interrupt  The interrupt
 * @param[in]  priority   The priority
 */
extern void nvic_set_priority(int interrupt, struct cortex_m_priority priority);

#endif /* UCAPI_CORTEX_M_NVIC_H_INCLUDED */
