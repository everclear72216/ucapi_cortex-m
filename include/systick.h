#ifndef UCAPI_CORTEX_M_SYSTICK_H_INCLUDED
#define UCAPI_CORTEX_M_SYSTICK_H_INCLUDED

enum systick_enabled_state {
    systick_disabled,
    systick_enabled
};

enum systick_interrupt_state {
    systick_interrupt_disabled,
    systick_interrupt_enabled
};

enum systick_clock_source {
    systick_clock_source_external,
    systick_clock_source_internal
};

/**
 * @brief      Enables the systick timer.
 */
extern void cortex_m_systick_enable(void);

/**
 * @brief      Disables the systick timer.
 */
extern void cortex_m_systick_disable(void);

/**
 * @brief      Retrieves the systick timer enabled state.
 *
 * @retval     systick_enabled The systick timer is enabled.
 * @retval     systick_disabled The systick timer is disabled.
 */
extern enum systick_enabled_state cortex_m_systick_is_enabled(void);

/**
 * @brief      Checks whether the timer has counted down to zero.
 *
 * @retval     0 The timer has not counted down to zero.
 * @retval     1 The timer has counted down to zero.
 */
extern int cortex_m_systick_has_expired(void);

/**
 * @brief      Enables the systick exception.
 */
extern void cortex_m_systick_interrupt_enable(void);

/**
 * @brief      Disables the systick exception.
 */
extern void cortex_m_systick_interrupt_disable(void);

/**
 * @brief      Retrieves the systick exception state.
 *
 * @retval     systick_interrupt_enabled The systick exception is enabled.
 * @retval     systick_interrupt_disabled The systick exception is disabled.
 */
extern enum systick_interrupt_state cortex_m_systick_interrupt_is_enabled(void);

/**
 * @brief      Retrieves the systick timer's current value.
 *
 * @return     The systick timer's current value.
 */
extern unsigned int cortex_m_systick_current_get(void);

/**
 * @brief      Zeroes the systick timer's current value.
 */
extern void cortex_m_systick_current_clear(void);

/**
 * @brief      Checks whether there is an external reference clock implemented
 *             by the vendor.
 *
 * @retval     0 The external reference clock is not implemented.
 * @retval     1 The external reference clock is implemented.
 */
extern int cortex_m_systick_has_external_reference(void);

/**
 * @brief      Retrieves the 10 ms timer calibration value.
 *
 * @return     The 10 ms timer calibration value.
 */
extern unsigned int cortex_m_systick_ten_ms_reload_value_get(void);

/**
 * @brief      Checks whether the 10 ms timer calibration value is exact.
 *
 * @retval     0 The 10 ms timer calibration value is not exact.
 * @retval     1 The 10 ms timer calibration value is exact.
 */
extern int cortex_m_systick_has_exact_ten_ms_interval(void);

/**
 * @brief      Retrieves the current reload value.
 *
 * @return     The current reload value.
 */
extern unsigned int cortex_m_systick_reload_value_get(void);

/**
 * @brief      Sets the current reload value.
 * @note       Setting the reload value to zero is equivalent to disabling the
 *             timer.
 *
 * @param[in]  reload  The reload value.
 */
extern void cortex_m_systick_reload_value_set(unsigned int reload);

/**
 * @brief      Chooses the systick timer's internal clock source.
 */
extern void cortex_m_systick_clock_source_set_internal(void);

/**
 * @brief      Chooses the systick timer's external vendor provided clock
 *             source.
 */
extern void cortex_m_systick_clock_source_set_external(void);

/**
 * @brief      Retrieves the systick timer's clock source.
 *
 * @retval     systick_clock_source_external The systick timer is using a 
 *             vendor specific external clocu source.
 * @retval     systick_clock_source_internal The systick timer is using the
 *             system core clock.
 */
extern enum systick_clock_source cortex_m_sytick_clock_source_get(void);

#endif /* UCAPI_CORTEX_M_SYSTICK_H_INCLUDED */
