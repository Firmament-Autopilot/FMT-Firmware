/*
 * linker script for STM32H743 with GNU ld
 */

/* Program Entry, set to mark it as "used" and avoid gc */
MEMORY
{
	/* First 0x20000(128KB) area is reserved for bootloader */
    CODE (rx) : ORIGIN = 0x08020000, LENGTH = 1920k /* 2048KB - 128KB flash */

    ITCM_RAM (rwx) : ORIGIN = 0x00000000, LENGTH =   64K
    DTCM_RAM (rw) : ORIGIN = 0x20000000, LENGTH =  128K
    SRAMD1 (rw) : ORIGIN = 0x24000000, LENGTH =  512k /* D1 512K sram */
    SRAMD2 (rw) : ORIGIN = 0x30000000, LENGTH =  256K /* D2 domain AHB bus */
	SRAMD3 (rw) : ORIGIN = 0x38000000, LENGTH =   64K /* D3 domain */
	BKPRAM (rw) : ORIGIN = 0x38800000, LENGTH =    4K
    RxDecripSection (rw) : ORIGIN =0x30040000, LENGTH =32k
    TxDecripSection (rw) : ORIGIN =0x30040060, LENGTH =32k
    RxArraySection (rw) : ORIGIN =0x30040200, LENGTH =32k
}
ENTRY(Reset_Handler)
_system_stack_size = 0x2000;

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        _stext = .;
        KEEP(*(.isr_vector))            /* Startup code */
        . = ALIGN(4);
        *(.text)                        /* remaining code */
        *(.text.*)                      /* remaining code */
        *(.rodata)                      /* read-only data (constants) */
        *(.rodata*)
        *(.glue_7)
        *(.glue_7t)
        *(.gnu.linkonce.t*)

        /* section information for finsh shell */
        . = ALIGN(4);
        __fsymtab_start = .;
        KEEP(*(FSymTab))
        __fsymtab_end = .;
        . = ALIGN(4);
        __vsymtab_start = .;
        KEEP(*(VSymTab))
        __vsymtab_end = .;
        . = ALIGN(4);

        /* section information for modules */
        . = ALIGN(4);
        __rt_init_start = .;
        KEEP(*(SORT(.rti_fn*)))
        __rt_init_end = .;
        . = ALIGN(4);

        . = ALIGN(4);
        __fmt_module_start = .;
        KEEP(*(FmtModuleTbl))
        __fmt_module_end = .;
        . = ALIGN(4);

        . = ALIGN(4);
        __fmt_task_start = .;
        KEEP(*(TaskTab))
        __fmt_task_end = .;
        . = ALIGN(4);

        . = ALIGN(4);
        __fmt_param_start = .;
        KEEP(*(ParamTab))
        __fmt_param_end = .;
        . = ALIGN(4);

        /* section information for mlog. */
        . = ALIGN(4);
        __fmt_mlog_start = .;
        KEEP(*(MlogTab))
        __fmt_mlog_end = .;
        . = ALIGN(4);

        . = ALIGN(4);
        _etext = .;
    } > CODE

    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > CODE

    /* The .ARM.exidx section is used for C++ exception handling. */
    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > CODE

    .ctors :
    {
        __ctors_start__ = .;
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        __ctors_end__ = .;
    } > CODE

    .dtors :
    {
        __dtors_start__ = .;
        KEEP(*(SORT(.dtors.*)))
        KEEP(*(.dtors))
        __dtors_end__ = .;
    } > CODE

    /* Global data/variables (RAM1) */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        *(.gnu.linkonce.d*)
        . = ALIGN(4);
        _edata = .;
    } > SRAMD1 AT > CODE

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(.gnu.linkonce.b*)
        *(COMMON)
        . = ALIGN(8);
        _ebss = .;
        __bss_end = .;
        __bss_end__ = .;
    } > SRAMD1

    .stack :
    {
        . = ALIGN(4);
        _sstack = .;
        . = . + _system_stack_size;
        . = ALIGN(4);
        _estack = .;
    } > SRAMD1 /* DTCM_RAM */

    _sidata = LOADADDR(.data);

    /* Stacks for ISR (DTCM) */
    .stack_isr :
    {
        . = ALIGN(4);
        _stcm_ram = .;
        . = . + 2048; /* 2KB for ISR stack */
        . = ALIGN(4);
        _etcm_ram = .;
    } > DTCM_RAM

    /* lwIP Memory Pool (D2 Domain) */
    .lwip_sec (NOLOAD) :
    {
        . = ALIGN(4);
        *(.lwip_sec)
        . = ALIGN(4);
    } > SRAMD2

    /* Section to place static DMA buffers */
    .sram_dma (NOLOAD) :
    {
        . = ALIGN(4);
        *(.sram_dma*)
        . = ALIGN(4);
    } > SRAMD1

    /* Ethernet DMA Descriptors (D2 Domain) */
    .RxDecripSection (NOLOAD) : { *(.RxDecripSection) } > RxDecripSection
    .TxDecripSection (NOLOAD) : { *(.TxDecripSection) } > TxDecripSection
    .RxArraySection (NOLOAD)  : { *(.RxArraySection)  } > RxArraySection
}
