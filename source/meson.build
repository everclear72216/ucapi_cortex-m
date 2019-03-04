ucapi_cortex_m_sources = []
ucapi_cortex_m_sources += 'breakpoint.c'
ucapi_cortex_m_sources += 'debug_system.c'

ucapi_cortex_m_static = static_library('ucapi_cortex-m',
    ucapi_cortex_m_sources,
    include_directories: ucapi_cortex_m_include_dirs,
    dependencies: ucapi_dep,
)