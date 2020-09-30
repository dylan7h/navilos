ENTRY(vector_start)

SECTIONS
{
    . = 0x0;

    .text :
    {
        *(vector_start)
        *(.text .rodata)
    }
    .data :
    {
        *(.data)
    }
    .bss :
    {
        _sbss = .;
        __bss_start__ = _sbss;

        *(.bss)

        _ebss = .;
        __bss_end__ = _ebss;
    }
}
