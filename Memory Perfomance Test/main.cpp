/*
	Memory Perfomance Test

	Meanings of result:
	In x31 must be median time in integer

*/

#define __RESULT    __attribute__((section (".result"))) __attribute__((aligned(8))) = {0}
# define N 10000

void test1();

//long unsigned int N = 10000;
long unsigned int s_pointer = 0x10400000;
//unsigned int result = 0;
//unsigned int res __RESULT;
int res ;//__RESULT;
//unsigned int res_mas[10] __RESULT;

extern "C"
{
	void setup_stack_pointer(long unsigned int);
	unsigned long int cycle(void);
	void write_result(int number);
	void cycle_clear(void);
}

int main()
{
	//setup_stack_pointer(s_pointer);
	//asm(" ld x2, s_pointer ");

	//Включение FPU
	asm("li x10, 0x2000");
	asm("CSRRS x0, mstatus, x10");//0x300

	test1();

	for(;;);

	return 0;
}

void test1()
{
	unsigned long int time1 = 0;
	unsigned long int time2 = 0;
	int i = 0;

	cycle_clear();

	long int memory[N];

	time1 = cycle();

	for (i=1; i <= N; i++)
	{
		memory[i] = i;
	}

	time2 = cycle();
	//N = 10000;
	res = (time2 - time1) / N;
	//res = result;


	for(;;);
}
