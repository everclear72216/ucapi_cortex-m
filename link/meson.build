ucapi_cortex_m_link_dir = meson.current_source_dir()
ucapi_cortex_m_base_ld = '/cortex-m.ld'

ucapi_cortex_m_link_dep = declare_dependency(
    link_args: [ '-L' + ucapi_cortex_m_link_dir, '-T' + ucapi_cortex_m_base_ld ]
)