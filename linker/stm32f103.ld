MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}
ENTRY(Reset_Handler)

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{

    .text :
    {
        . = ALIGN(4);

        KEEP(*(.isr_vector))

        . = ALIGN(4);

        *(.text.Reset_Handler)

        *(.text*)
        *(.rodata*)

    } > FLASH

    .data :
    {
        _sdata = .;
        *(.data*)
        _edata = .;

    } > RAM AT > FLASH

    _sidata = LOADADDR(.data);


    .bss :
    {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;

    } > RAM

}