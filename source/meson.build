target = 'ucapi_cortex-m'

sources = files(
    'debug.c',
    'breakpoint.c'
)

ucapi_cortex_m_lib = static_library(
    target, sources,
    dependencies: [ devconf_dep, ucapi_dep ],
    include_directories: ucapi_cortex_m_include_dirs
)