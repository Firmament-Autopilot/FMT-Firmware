/*
 * linker script for STM32H753VIT6 with GNU ld
 */

/* Program Entry, set to mark it as "used" and avoid gc */
MEMORY
{
    itcm0 (rwx) 	  		: ORIGIN = 0x00000000, LENGTH = 512K

	dtcm0 (rwx) 	  		: ORIGIN = 0x20000000, LENGTH = 384K
	dtcm0_ekf2 (rwx) 		: ORIGIN = 0x20060000, LENGTH = 128K
	itcm1 (rwx) 	  		: ORIGIN = 0x44100000, LENGTH = 256K
	dtcm1 (rwx) 	  		: ORIGIN = 0x44180000, LENGTH = 256K


	lma_itcm0 (rwx) 	  	: ORIGIN = 0x00000000, LENGTH = 512K
	lma_dtcm0_ekf2 (rwx) 	: ORIGIN = 0x00080000, LENGTH = 128K
	lma_itcm1 (rwx) 	  	: ORIGIN = 0x000A0000, LENGTH = 256K
	lma_dtcm1 (rwx) 	  	: ORIGIN = 0x000E0000, LENGTH = 256K
}

ENTRY(Reset_Handler)
_system_stack_size = 0x800;

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

        /* section information for initial. */
        . = ALIGN(4);
        __rt_init_start = .;
        KEEP(*(SORT(.rti_fn*)))
        __rt_init_end = .;
        . = ALIGN(4);

        PROVIDE(__ctors_start__ = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE(__ctors_end__ = .);
        . = ALIGN(4);

        /* section information for parameters. */
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
		
		/* section information for utest */
        . = ALIGN(4);
        __rt_utest_tc_tab_start = .;
        KEEP(*(UtestTcTab))
        __rt_utest_tc_tab_end = .;
        . = ALIGN(4);

                /* section information for task. */
        . = ALIGN(4);
        __fmt_task_start = .;
        KEEP(*(TaskTab))
        __fmt_task_end = .;
        . = ALIGN(4);

        _etext = .;
	} > itcm0

    .dtcm0_ekf2 :
    {
        . = ALIGN(4);
        *(.cf_dtcm0_ekf2*)
        . = ALIGN(4);

        /* . = ALIGN(4); */

    } > dtcm0_ekf2 AT > lma_dtcm0_ekf2

	.itcm_ext1 :
    {   
        . = ALIGN(4);
        *(.rodata) 
        *(.rodata._*)
        *(.rodata.a*)
        *(.rodata.A*)
        *(.rodata.b*)
        *(.rodata.B*)
        *(.rodata.c*)
        *(.rodata.C*)
        *(.rodata.d*)
        *(.rodata.D*)
        *(.rodata.e*)
        *(.rodata.E*)
        *(.rodata.f*)
        *(.rodata.F*)
        *(.rodata.g*)
        *(.rodata.G*)
        *(.rodata.h*)
        *(.rodata.H*)
        *(.rodata.i*)
        *(.rodata.I*)
        *(.rodata.j*)
        *(.rodata.J*)
        *(.rodata.k*)
        *(.rodata.K*)
        *(.rodata.l*)
        *(.rodata.L*)
        *(.rodata.m*)
        *(.rodata.M*)
        *(.rodata.n*)
        *(.rodata.N*)
        *(.rodata.o*)
        *(.rodata.O*)
        *(.rodata.p*)
        *(.rodata.P*)
        *(.rodata.q*)
        *(.rodata.Q*)
        *(.rodata.r*)
        *(.rodata.R*)
        *(.rodata.s*)
        *(.rodata.S*)
        . = ALIGN(4);
        
        . = ALIGN(4);
        *(.cf_ext_itcm1*)
        . = ALIGN(4);

    } > itcm1 AT > lma_itcm1

	.dtcm_ext1 :
    {
        . = ALIGN(4);
        *(.dtcm1*)
        *(.dtcm1_rodata*)
        *(.dtcm1_bss*)
        . = ALIGN(4);

        . = ALIGN(4);
        *(.rodata.t*)
        *(.rodata.T*)
        *(.rodata.u*)
        *(.rodata.U*)
        *(.rodata.v*)
        *(.rodata.V*)
        *(.rodata.w*)
        *(.rodata.W*)
        *(.rodata.x*)
        *(.rodata.X*)
        *(.rodata.y*)
        *(.rodata.Y*)
        *(.rodata.z*)
        *(.rodata.Z*)
        . = ALIGN(4);
    } > dtcm1 AT > lma_dtcm1


    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > itcm0

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)

        /* This is used by the startup in order to initialize the .data secion */
        _sidata = .;
    } > itcm0
    __exidx_end = .;

    /* .data section which is used for initialized data */

    .data : AT (_sidata)
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _sdata = . ;

        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d*)

        PROVIDE(__dtors_start__ = .);
        KEEP(*(SORT(.dtors.*)))
        KEEP(*(.dtors))
        PROVIDE(__dtors_end__ = .);

        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _edata = . ;
    } > dtcm0

    .stack : 
    {
        _sstack = .;
        . = . + _system_stack_size;
        . = ALIGN(4);
        _estack = .;
    } > dtcm0

    __bss_start = .;
    .bss :
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _sbss = .;

        *(.bss)
        *(.bss.*)
        *(COMMON)

        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _ebss = . ;
        
        *(.bss.init)
    } > dtcm0
    __bss_end = .;

    _end = .;

    /* Stabs debugging sections.  */
    .stab          0 : { *(.stab) }
    .stabstr       0 : { *(.stabstr) }
    .stab.excl     0 : { *(.stab.excl) }
    .stab.exclstr  0 : { *(.stab.exclstr) }
    .stab.index    0 : { *(.stab.index) }
    .stab.indexstr 0 : { *(.stab.indexstr) }
    .comment       0 : { *(.comment) }
    /* DWARF debug sections.
     * Symbols in the DWARF debugging sections are relative to the beginning
     * of the section so we begin them at 0.  */
    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }
    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }
    /* SGI/MIPS DWARF 2 extensions */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }
}

