project('ucapi_cortex_m', 'c')

ucapi_dep = dependency('ucapi', fallback: ['ucapi', 'ucapi_dep'])

subdir('include')
subdir('source')

ucapi_cortex_m_dep = declare_dependency(
    include_directories: ucapi_cortex_m_include_dirs,
    link_with: ucapi_cortex_m_static,
)