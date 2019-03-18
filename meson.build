subdir('include')
subdir('source')
subdir('link')

ucapi_cortex_m_dep = declare_dependency(
    # make sure the vector table appears in the binary
    link_args: ['-u__core_table_flash'],
    link_with: ucapi_cortex_m_lib,
    include_directories: ucapi_cortex_m_include_dirs,
    dependencies: [ devconf_dep, ucapi_cortex_m_link_dep ]
)
