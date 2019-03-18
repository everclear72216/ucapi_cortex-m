INCLUDE mem.ld

ENTRY(__reset_isr)

SECTIONS
{
    .text :
    {
        __vector_table_flash_start = .;
        KEEP(*(.core_table_flash))
        KEEP(*(.peri_table_flash))
        . = ALIGN(4);
        __vector_table_flash_end = .;

        INCLUDE impl_text.ld
        INCLUDE app_text.ld

        *(.text*)
        *(.rodata*)
    } >FLASH

    . = ORIGIN(SRAM);
    .ram.vectortable :
    {
        __vector_table_ram_start = .;
        KEEP(*(.core_table_ram))
        KEEP(*(.peri_table_ram))
        . = ALIGN(4);
        __vector_table_ram_end = .;
    } >SRAM

    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        . = ALIGN(4);
        __data_lma = LOADADDR(.data);
        __data_vma = .;

        INCLUDE impl_data.ld
        INCLUDE app_data.ld

        *(.data*)
        __data_vma_end = .;
    } >SRAM

    .bss :
    {
        . = ALIGN(4);
        __bss_vma = .;
        *(.bss*)
        __bss_vma_end = .;
    } >SRAM

    .stack :
    {
        *(.stack*)
    } >SRAM

    __stack_top = ORIGIN(SRAM) + LENGTH(SRAM);
    __stack_bot = __stack_top - SIZEOF(.stack);
    __stack = __stack_top;
}
