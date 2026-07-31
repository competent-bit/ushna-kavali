MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}


ENTRY(Reset_Handler)


SECTIONS
{

    .text :
    {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)

    } > FLASH


    .data :
    {
        *(.data*)

    } > RAM


    .bss :
    {
        *(.bss*)
        *(COMMON)

    } > RAM

}
