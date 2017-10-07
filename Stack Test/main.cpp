/*
	Meanings of result:
	0x01 - got interrupt
	0x11 - corruption of memory

*/

long unsigned int s_pointer = 0x10200000;
int N = 100;

int main();
void test1();
void error(int number);

extern "C"
{
	void setup_stack_pointer(long unsigned int);
	unsigned long int timer(void);
	void write_result(int number);
}

int main()
{

	setup_stack_pointer(s_pointer);

	test1();

	for (;;);

	return 0;
}

void test1()
{
	int stack[100];
	*(long unsigned int*)((stack)+100)  = 0xDEDDEDAA;

	for (int i = 0; i < N; i++)
	{
		stack[i] = i+1;
	}

	for (int i = 0; i < N; i++)
	{
		if (stack[i] != i+1)
			error(2);
	}

	error(1);

	for (;;);
}

void error(int number)
{
	switch(number)
	{
		case 1:
			write_result(0x01);			// test OK
			break;
		case 2:
			write_result(0x11);			// stack is corrupted
			break;
		case 3:
			write_result(0xDEAD);		// test not ok
			break;
		default:
			write_result(0x00);
	}
}
