target = 'ucapi_cortex-m'

sources = files(
    'nmi.c',
    'nvic.c',
    'reset.c',
    'debug.c',
    'systick.c',
    'core_init.c',
    'supervisor.c',
    'breakpoint.c',
    'exceptions.c',
    'vector_table.c'
)

ucapi_cortex_m_lib = static_library(
    target, sources,
    dependencies: [ devconf_dep, ucapi_dep ],
    include_directories: ucapi_cortex_m_include_dirs
)
