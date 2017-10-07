OUTPUT_ARCH( "riscv" )
MEMORY
{
  mem (rwx) : ORIGIN = 0x10000000, LENGTH = 0x800000
}
SECTIONS
{  
  . = 0x10000000;
  .text : { *(.text) }
  .data : { *(.data) }
  .bss : { *(.bss) }
  _exit = exit;
  . = 0x10020000;
  .test : {*(.test)}
  . = 0x10030000;
  __stack_pointer$ = .;
  __global_pointer$ = .;
  _edata = .;
  _end = .;
}
