/* flat_linker.ld */
OUTPUT_FORMAT(binary)   /* Output raw binary format */
ENTRY(_start)           /* Define the entry point as _start */
SECTIONS {
    . = 0x0;
    
    .text : {
        *(.text._start)
        *(.text)
    }

    .data : {
        *(.data)
    }
}

