ENTRY(main)

MEMORY
{
    /*  program counter (PC) is initally set to 0x00000000  */
    rom (rx): ORIGIN = 0x00000000, LENGTH = 1K

    ram (rw): ORIGIN = 0x00001000, LENGTH = 1K
}

SECTIONS
{
    .text : {
        /*
            entry point is expected to be the first function here
            --> we are assuming there's only a single function in the .text.boot segment and by convention that is "main"
        */
        KEEP(*(.text.boot))

        /*
            all other code follows
        */
        *(.text*)
    } > rom

    .rodata : { *(.rodata*) } > rom

    .bss : { *(.bss*) } > ram
}
