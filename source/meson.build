target = 'ucapi_cortex-m'

sources = files(
    'breakpoint.c',
    'debug_system.c'
)

ucapi_cortex_m_lib = static_library(
    target, sources,
    dependencies: [ ucapi_dep ],
    include_directories: ucapi_cortex_m_include_dirs
)