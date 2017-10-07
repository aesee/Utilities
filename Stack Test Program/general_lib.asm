# extern "C"
# {
#	 void setup_stack_pointer(long unsigned int);
#	 unsigned long int timer(void);
#	 void write_result(int number);
# }


.global setup_stack_pointer
.global timer_clear
.global timer
.global write_result

setup_stack_pointer:
	mv x2, a0
	ret

timer_clear:
	#ld t0, 0xFFFFFFFFFFFFFFFF
	csrc mcycle, t0
	ret

timer:
	csrr a0, mcycle
	ret

write_result:
	mv x31, a0
	ret
