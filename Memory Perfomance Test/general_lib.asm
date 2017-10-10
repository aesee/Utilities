# extern "C"
# {
#	 void setup_stack_pointer(long unsigned int);
#	 unsigned long int cycle(void);
#	 void write_result(int number);
#	 void cycle_clear(void);
# }


.global setup_stack_pointer
.global cycle_clear
.global cycle
.global write_result

FF64:
.dword 0xffffffffffffffff

setup_stack_pointer:
	mv x2, a0
	ret

cycle_clear:
	ld t0, FF64
	csrrc x0, mcycle, t0
	ret

cycle:
	csrrs a0, mcycle, x0
	ret

write_result:
	mv x31, a0
	ret
