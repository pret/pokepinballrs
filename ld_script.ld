SECTIONS
{
    /* start of ewram */
    . = 0x02000000;
    ewram (NOLOAD) :
    ALIGN(4)
    {
        asm/ewram.o(ewram);
        . = 0x40000;
    }
    
    /* start of iwram */
    . = 0x03000000;
    iwram (NOLOAD) :
    ALIGN(4)
    {
        asm/iwram.o(iwram);
        . = 0x8000;
    }
    
    /* start of ROM */
    . = 0x08000000;
    .text :
    {
        asm/rom.o(.text);
    }=0xFF
}
